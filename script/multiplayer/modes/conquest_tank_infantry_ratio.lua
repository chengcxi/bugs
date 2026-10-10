-- File: 		conquest_tank_infantry_ratio.lua
-- Catalog: 	script\multiplayer\modes
-- Format:		LUA
-- Description: Проактивный балансир пехоты/танков. Все параметры берутся из config.lua.
-- Created by:	Max Drechsler
-- Created: 	27.08.2026
-- Modified: 	12.09.2026
-- Version 5.1 (параметры из конфига)

local M = {}

local Config = require([[/script/multiplayer/modes/config]])

-- < [ TIERS START ]: параметры из конфига
local infantryPerTank = {}
local priorityInfantryTags = {}

local function loadConfig()
    local cfg = Config.TankInfantryRatio or {}
    infantryPerTank = cfg.infantryPerTank or {}
    priorityInfantryTags = cfg.priorityInfantryTags or {}
end
-- > [ TIERS END ]

local pendingInfantrySpawns = 0

local function logBalancer(msg)
    if printDebug then
        print("[ARm] (Tank-Infantry Balancer): " .. msg)
    end
end

local function hasType(unit, typeName)
    if not unit or not unit.type then return false end
    for _, t in ipairs(unit.type) do
        if t == typeName then return true end
    end
    return false
end

function M.isTank(unit)
    if not unit or not unit.type then return false end
    -- Игнорируем амбушные юниты
    for _, t in ipairs(unit.type) do
        if t == "Ambush" then
            return false
        end
    end
    -- Если есть "Squad" или "TankTeam" - это не танк
    for _, t in ipairs(unit.type) do
        if t == "Squad" or t == "TankTeam" then
            return false
        end
    end
    local hasTank = false
    for _, t in ipairs(unit.type) do
        if t == "Tank" then hasTank = true break end
    end
    if not hasTank then return false end

    local hasMedium, hasHeavy, hasMain, hasTD = false, false, false, false
    for _, t in ipairs(unit.type) do
        if t == "Medium" then hasMedium = true end
        if t == "Heavy" then hasHeavy = true end
        if t == "Main" then hasMain = true end
        if t == "TD" then hasTD = true end
    end
    return (hasMedium and hasMain) or (hasHeavy and hasMain) or hasTD
end

function M.isInfantry(unit)
    return hasType(unit, "Squad") or hasType(unit, "Infantry")
end

-- < [ TIERS START ]: возвращает список уровней тегов для текущей нации
function M.getInfantryTiers()
    local nation = BotApi.Instance.army
    return priorityInfantryTags[nation] or {}
end
-- > [ TIERS END ]

function M.onTankSpawned()
    local nation = BotApi.Instance.army
    local count = infantryPerTank[nation] or 0
    if count > 0 then
        pendingInfantrySpawns = pendingInfantrySpawns + count
        logBalancer(string.format("Tank spawned, pending infantry +%d (total: %d)", count, pendingInfantrySpawns))
    else
        logBalancer(string.format("Tank spawned, nation '%s' has no infantryPerTank, ignoring", nation))
    end
end

function M.onUnitSpawned(unit)
    if not unit or not unit.unit then return end
    if not M.isInfantry(unit) then return end
    if pendingInfantrySpawns > 0 then
        pendingInfantrySpawns = pendingInfantrySpawns - 1
        logBalancer(string.format("Infantry spawned (%s), remaining: %d", unit.unit, pendingInfantrySpawns))
    end
end

function M.isInfantryPriority()
    return pendingInfantrySpawns > 0
end

function M.init()
    loadConfig()
    pendingInfantrySpawns = 0
    logBalancer("Module initialized (multi-tier infantry spawning, config loaded)")
end

function M.onQuant()
    -- не используется
end

return M