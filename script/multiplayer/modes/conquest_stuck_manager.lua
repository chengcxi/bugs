-- File: conquest_stuck_manager.lua
-- Catalog: script\multiplayer\modes
-- Created by Max Drechsler 
-- Created 28.08.2026
-- Modify 28.08.2026
-- Version 1.0 
-- Description: 

-- File: conquest_stuck_manager.lua
-- Catalog: script\multiplayer\modes
-- Description: Механизм «застревания» – переключение цели, если флаг не захвачен за таймаут.
-- Работает независимо от TargetManager. Требует, чтобы при выдаче команды на захват флага
-- вызывался StuckManager.registerSquad(squad, flagName).

local M = {}

-- ============================================================
-- НАСТРОЙКИ (берутся из конфига при инициализации)
-- ============================================================
local config = {
    enabled = true,
    minTimeout = 3 * 60 * 1000,
    maxTimeout = 7 * 60 * 1000,
    checkInterval = 10 * 1000,
}

-- ============================================================
-- СОСТОЯНИЕ
-- ============================================================
local squadData = {}  -- key = squadId, value = { flagName, startTime, timeoutMs, lastCheckTime }

local lastUpdateTime = 0

-- ============================================================
-- ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
-- ============================================================
local function getTimeMs()
    return os.time() * 1000
end

local function getFlagByName(name)
    local flags = BotApi.Scene.Flags
    if not flags then return nil end
    for _, flag in pairs(flags) do
        if flag.name == name then
            return flag
        end
    end
    return nil
end

local function getFlagOwner(flag)
    if not flag then return nil end
    if flag.occupant == team then
        return FlagOwnership.Allied
    elseif flag.occupant == enemyTeam then
        return FlagOwnership.Opponent
    else
        return FlagOwnership.Neutral
    end
end

-- ============================================================
-- ПУБЛИЧНЫЕ ФУНКЦИИ
-- ============================================================

-- Инициализация (вызывать в OnGameStart)
function M.init(cfg)
    if cfg then
        config.enabled = (cfg.enabled ~= nil) and cfg.enabled or config.enabled
        config.minTimeout = cfg.minTimeout or config.minTimeout
        config.maxTimeout = cfg.maxTimeout or config.maxTimeout
        config.checkInterval = cfg.checkInterval or config.checkInterval
    end
    squadData = {}
    lastUpdateTime = 0
    if printDebug then
        print("[ARM] (StuckManager): Initialized (enabled=" .. tostring(config.enabled) .. ")")
    end
end

-- Зарегистрировать отряд с целью (флагом)
function M.registerSquad(squad, flagName)
    if not config.enabled then return end
    if not squad or not flagName then return end
    if not BotApi.Scene:IsSquadExists(squad) then return end

    local currentTime = getTimeMs()
    local timeoutMs = math.random(config.minTimeout, config.maxTimeout)
    squadData[squad] = {
        flagName = flagName,
        startTime = currentTime,
        timeoutMs = timeoutMs,
        lastCheckTime = currentTime,
    }
    if printDebug then
        print(string.format("[ARM] (StuckManager): Squad %d registered for flag '%s' (timeout %.1f min)",
            squad, flagName, timeoutMs / 60000))
    end
end

-- Снять регистрацию (отряд сменил цель, погиб или флаг захвачен)
function M.unregisterSquad(squad)
    if squadData[squad] then
        squadData[squad] = nil
        if printDebug then
            print("[ARM] (StuckManager): Squad " .. squad .. " unregistered")
        end
    end
end

-- Обновление состояния (вызывать в OnGameQuant)
function M.update()
    if not config.enabled then return end
    if not squadData or next(squadData) == nil then return end

    local currentTime = getTimeMs()
    if currentTime - lastUpdateTime < config.checkInterval then
        return
    end
    lastUpdateTime = currentTime

    -- Проходим по всем зарегистрированным отрядам
    for squad, data in pairs(squadData) do
        -- Проверяем, жив ли отряд
        if not BotApi.Scene:IsSquadExists(squad) then
            squadData[squad] = nil
            if printDebug then
                print("[ARM] (StuckManager): Squad " .. squad .. " is dead, removed")
            end
            goto continue
        end

        -- Проверяем, существует ли флаг
        local flag = getFlagByName(data.flagName)
        if not flag then
            -- Флаг исчез – снимаем цель
            squadData[squad] = nil
            if printDebug then
                print("[ARM] (StuckManager): Flag '" .. data.flagName .. "' no longer exists, unregistering squad " .. squad)
            end
            goto continue
        end

        -- Проверяем, не захвачен ли флаг
        local owner = getFlagOwner(flag)
        if owner == FlagOwnership.Allied then
            -- Флаг стал нашим – цель достигнута
            squadData[squad] = nil
            if printDebug then
                print("[ARM] (StuckManager): Flag '" .. data.flagName .. "' captured, unregistering squad " .. squad)
            end
            goto continue
        end

        -- Проверяем таймаут
        if currentTime - data.startTime > data.timeoutMs then
            -- Таймаут истёк – отряд «застрял» на этом флаге
            if printDebug then
                print(string.format("[ARM] (StuckManager): Squad %d stuck on flag '%s' (timeout %.1f min), reassigning",
                    squad, data.flagName, data.timeoutMs / 60000))
            end

            -- Удаляем запись, чтобы не проверять повторно
            squadData[squad] = nil

            -- Даём новую команду
            -- Если TargetManager доступен и включён, можно использовать его.
            -- Пока используем существующую логику: для атакующего – SeekAndDestroy, для защитника – CaptureFlag.
            if botDefender then
                -- Для защитника – стандартная логика (выбор флага через GetFlagToCapture)
                CaptureFlag(squad)  -- предполагаем, что CaptureFlag доступна глобально
            else
                -- Для атакующего – пока просто SeekAndDestroy (позже заменим на выбор флага)
                if printDebug then
                    print("[ARM] (StuckManager): Sending squad " .. squad .. " to SeekAndDestroy")
                end
                BotApi.Commands:SeekAndDestroy(squad)
            end
        end

        ::continue::
    end
end

-- Получить текущее состояние (для отладки)
function M.getState()
    return squadData
end

return M