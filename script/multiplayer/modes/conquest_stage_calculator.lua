-- File: conquest_stage_calculator.lua
-- Catalog: script\multiplayer\modes
-- Modify by Max Drechsler 
-- Created 01.09.2026
-- Edited 02.09.2026
-- Version 1.6
-- Description: 
-- - Вычисление стадии войны (war_stage$) на основе количества юнитов защитника
-- - Учитываются только юниты с тегом bot_veh (исключая player_veh)
-- - Стадия определяется по количественному преимуществу (late > mid и late > early → 3, mid > early → 2, иначе 1)
-- - Если юнитов нет – war_stage$ = 1, tier2$ = 0
-- - Очистка тегов early_stage/mid_stage/late_stage при завершении миссии (если включено в конфиге)
-- - Получение юнитов через отряды (Squads), т.к. GetEntities отсутствует

local M = {}
local Config = require([[/script/multiplayer/modes/config]])

local function log(msg)
    print("[ARm] (Stages): " .. msg)
end

-- ============================================================
-- ВСПОМОГАТЕЛЬНАЯ ФУНКЦИЯ: получить все ID юнитов на карте
-- ============================================================
local function getAllUnits()
    local allUnits = {}
    local squads = BotApi.Scene.Squads
    if not squads then
        log("getAllUnits - Squads is nil")
        return allUnits
    end

    for squadId, _ in pairs(squads) do
        local units = BotApi.Scene:GetSquadUnits(squadId)
        if units then
            for _, unitId in ipairs(units) do
                table.insert(allUnits, unitId)
            end
        end
    end
    return allUnits
end

-- ============================================================
-- ОСНОВНАЯ ФУНКЦИЯ: вычисление стадии войны
-- ============================================================
function M.calc_war_stage()
    -- Проверяем, включён ли модуль в конфиге
    if not Config.StageCalculator or not Config.StageCalculator.enabled then
        log("calc_war_stage - module disabled in config")
        return
    end

    local early = 0
    local mid = 0
    local late = 0

    local units = getAllUnits()
    if #units == 0 then
        log("calc_war_stage - no units found, setting war_stage$ = 1 (early)")
        BotApi.Scene:SetVar("war_stage$", 1)
        BotApi.Scene:SetVar("tier2$", 0)
        return
    end

    for _, unitId in ipairs(units) do
        -- Фильтр: только защитники (bot_veh), исключая технику игрока (player_veh) и неактивные
        local is_defender = BotApi.Scene:IsEntityTagged(unitId, "bot_veh")
        local is_player_vehicle = BotApi.Scene:IsEntityTagged(unitId, "player_veh")
        local is_inactive = BotApi.Scene:IsEntityTagged(unitId, "inactive") or false

        if is_defender and not is_player_vehicle and not is_inactive then
            if BotApi.Scene:IsEntityTagged(unitId, "early_stage") then
                early = early + 1
            elseif BotApi.Scene:IsEntityTagged(unitId, "mid_stage") then
                mid = mid + 1
            elseif BotApi.Scene:IsEntityTagged(unitId, "late_stage") then
                late = late + 1
            end
        end
    end

    -- Определяем стадию по количественному преимуществу
    local war_stage = 1
    local reason = "default (early)"

    if late > mid and late > early then
        war_stage = 3
        reason = string.format("late > mid (%d) and late > early (%d)", mid, early)
    elseif mid > early then
        war_stage = 2
        reason = string.format("mid > early (%d)", early)
    else
        war_stage = 1
        reason = string.format("no dominant stage (early=%d, mid=%d, late=%d)", early, mid, late)
    end

    -- Устанавливаем переменные в DSL
    BotApi.Scene:SetVar("war_stage$", war_stage)
    if war_stage > 1 then
        BotApi.Scene:SetVar("tier2$", 1)
    else
        BotApi.Scene:SetVar("tier2$", 0)
    end

    -- Отладка
    log(string.format("calculation - early=%d, mid=%d, late=%d", early, mid, late))
    log(string.format("calculation - war_stage$ set to %d (%s)", war_stage, reason))
end

-- ============================================================
-- ОЧИСТКА ТЕГОВ СТАДИЙ ПРИ ЗАВЕРШЕНИИ МИССИИ
-- ============================================================
function M.clear_stage_tags()
    -- Проверяем, включён ли модуль в конфиге
    if not Config.StageCalculator or not Config.StageCalculator.enabled then
        log("clear_stage_tags - module disabled in config")
        return
    end

    local count = 0
    local units = getAllUnits()
    if #units == 0 then
        log("clear_stage_tags - no units found")
        return
    end

    for _, unitId in ipairs(units) do
        local removed = false
        if BotApi.Scene:IsEntityTagged(unitId, "early_stage") then
            BotApi.Scene:RemoveTagFromEntity(unitId, "early_stage")
            removed = true
        end
        if BotApi.Scene:IsEntityTagged(unitId, "mid_stage") then
            BotApi.Scene:RemoveTagFromEntity(unitId, "mid_stage")
            removed = true
        end
        if BotApi.Scene:IsEntityTagged(unitId, "late_stage") then
            BotApi.Scene:RemoveTagFromEntity(unitId, "late_stage")
            removed = true
        end
        if removed then count = count + 1 end
    end

    log(string.format("clear_stage_tags - removed tags from %d units", count))
end

return M