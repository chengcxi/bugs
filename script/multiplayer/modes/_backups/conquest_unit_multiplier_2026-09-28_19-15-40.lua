-- File: conquest_unit_multiplier.lua
-- Catalog: script\multiplayer\modes
-- Modify by Max Drechsler 
-- Created 25.08.2026
-- Edited 27.08.2026
-- Version 1.4 (задержка между копиями mult не превышает SPAWN_DELAY)
-- Description: Модуль для многократного спавна одного юнита (mult) с учётом maxCount
--              и ограничением по времени между копиями.

local M = {}

local UnitLimiter = require([[/script/multiplayer/modes/conquest_limiter]])

-- Максимальный интервал между копиями (в миллисекундах)
local SPAWN_DELAY = 1500  -- 1.5 секунды

local state = {
    unit = nil,
    remaining = 0,
    lastSpawnTime = 0,  -- время последнего успешного спавна копии
}

local function logMultiplier(msg)
    if printDebug then
        print("[ARm] (Multiplier): " .. msg)
    end
end

local function getTimeMs()
    return os.time() * 1000
end

local function isUnitAvailable(unit, ignoreCooldown)
    if not unit then return false end
    if ignoreCooldown then
        return BotApi.Commands:IsUnitAvailable(unit.unit)
    else
        if not UnitLimiter.isUnitAvailable(unit) then
            return false
        end
        return BotApi.Commands:IsUnitAvailable(unit.unit)
    end
end

function M.getNextUnit(purchase, getUnitToSpawn)
    if state.unit and state.remaining > 0 then
        -- Проверяем, прошло ли достаточно времени с последнего спавна копии
        local currentTime = getTimeMs()
        if currentTime - state.lastSpawnTime < SPAWN_DELAY then
            -- Ещё рано, ждём
            return nil
        end

        if isUnitAvailable(state.unit, true) then
            logMultiplier(string.format("Returning queued unit: %s (remaining: %d)", state.unit.unit or "unknown", state.remaining))
            return state.unit
        else
            logMultiplier(string.format("Unit %s is no longer available, resetting multiplier", state.unit.unit or "unknown"))
            state.unit = nil
            state.remaining = 0
            state.lastSpawnTime = 0
            purchase:moveNext()
        end
    end

    if state.unit then
        state.unit = nil
        state.remaining = 0
        state.lastSpawnTime = 0
        logMultiplier("Multiplier finished, moving to next unit")
    end

    local units = purchase:current()
    if not units then
        return nil
    end

    local unit = getUnitToSpawn(units)
    if not unit then
        return nil
    end

    if unit.mult and type(unit.mult) == "number" and unit.mult > 1 then
        local limiterState = UnitLimiter.state[unit.unit]
        local maxCount = unit.maxCount or 0
        local currentCount = limiterState and limiterState.count or 0

        local effectiveMult = unit.mult
        if maxCount > 0 then
            local remainingLimit = math.max(0, maxCount - currentCount)
            if remainingLimit == 0 then
                logMultiplier(string.format("Unit %s has no remaining maxCount, skipping multiplier", unit.unit))
                purchase:moveNext()
                return unit
            end
            effectiveMult = math.min(unit.mult, remainingLimit)
        end

        if effectiveMult > 1 then
            state.unit = unit
            state.remaining = effectiveMult
            state.lastSpawnTime = 0  -- сбросим, установится в onUnitSpawned
            logMultiplier(string.format("Unit %s: mult=%d, maxCount=%d, effective mult=%d, will spawn %d more times", 
                unit.unit, unit.mult, maxCount, effectiveMult, state.remaining))
        else
            purchase:moveNext()
            state.unit = nil
            state.remaining = 0
            state.lastSpawnTime = 0
        end
    else
        purchase:moveNext()
        state.unit = nil
        state.remaining = 0
        state.lastSpawnTime = 0
    end

    return unit
end

function M.onUnitSpawned(unit)
    if not unit then
        return
    end

    if state.unit and state.remaining > 0 then
        if state.unit.unit == unit.unit then
            state.remaining = state.remaining - 1
            state.lastSpawnTime = getTimeMs()  -- фиксируем время последнего спавна
            logMultiplier(string.format("Spawned unit %s, remaining: %d", unit.unit, state.remaining))
            if state.remaining == 0 then
                state.unit = nil
                state.lastSpawnTime = 0
                logMultiplier("Multiplier completed for unit " .. unit.unit)
            end
        else
            logMultiplier(string.format("Warning: spawned unit %s does not match queued unit %s, resetting multiplier", unit.unit, state.unit.unit))
            state.unit = nil
            state.remaining = 0
            state.lastSpawnTime = 0
        end
    end
end

function M.reset()
    state.unit = nil
    state.remaining = 0
    state.lastSpawnTime = 0
    logMultiplier("State reset")
end

function M.getState()
    return state
end

return M