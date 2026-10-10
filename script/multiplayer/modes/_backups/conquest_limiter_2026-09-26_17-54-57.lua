-- File: conquest_limiter.lua
-- Catalog: script\multiplayer\modes
-- Modify by Max Drechsler 
-- Created 25.08.2026
-- Edited 27.08.2026
-- Version 1.1 (поддержка cooldown без maxCount)

-- Модуль для ограничения количества спавнов юнитов (maxCount) и таймера восстановления (cooldown в минутах)

local M = {}

-- Хранилище состояния: key = unitName, value = { count = number, cooldownEnd = nil или timestamp (мс) }
M.state = {}

-- Вспомогательная функция получения текущего времени в миллисекундах
local function getCurrentTimeMs()
    if BotApi and BotApi.Time then
        return BotApi.Time()
    else
        return os.time() * 1000
    end
end

-- Логирование с префиксами
local function logLimit(message)
    if printDebug then
        print("[ARM] (Lua-Limiter): " .. message)
    end
end

local function logCooldown(message)
    if printDebug then
        print("[ARM] (Cooldown): " .. message)
    end
end

local function logBoth(message)
    if printDebug then
        print("[ARM] (Lua-Limiter) + (Cooldown): " .. message)
    end
end

-- Инициализация (сброс состояния) – вызывается при старте новой игры
function M.init()
    M.state = {}
    logLimit("State initialized (reset)")
end

-- Проверка, доступен ли юнит для спавна с учётом maxCount и cooldown
-- unit: таблица с полями unit, maxCount (опционально), cooldown (опционально, в минутах)
function M.isUnitAvailable(unit)
    if not unit then
        return true
    end

    local unitName = unit.unit
    local state = M.state[unitName]

    if not state then
        state = { count = 0, cooldownEnd = nil }
        M.state[unitName] = state
    end

    -- ---- Случай: есть maxCount (работаем по старой логике) ----
    if unit.maxCount then
        -- Проверяем кулдаун
        if state.cooldownEnd and state.cooldownEnd > getCurrentTimeMs() then
            local remaining = math.ceil((state.cooldownEnd - getCurrentTimeMs()) / 60000)
            logBoth(string.format("Unit '%s' is on cooldown (remaining ~%d min), not available", unitName, remaining))
            return false
        end

        -- Если кулдаун прошёл, сбрасываем счётчик
        if state.cooldownEnd and state.cooldownEnd <= getCurrentTimeMs() then
            state.count = 0
            state.cooldownEnd = nil
            logCooldown(string.format("Cooldown expired for '%s', count reset to 0", unitName))
        end

        -- Проверяем лимит
        if state.count >= unit.maxCount then
            logLimit(string.format("Unit '%s' reached limit (%d/%d), not available", unitName, state.count, unit.maxCount))
            return false
        end

        return true
    end

    -- ---- Случай: maxCount отсутствует ----
    if unit.cooldown then
        -- Проверяем только кулдаун (без ограничения по количеству)
        if state.cooldownEnd and state.cooldownEnd > getCurrentTimeMs() then
            local remaining = math.ceil((state.cooldownEnd - getCurrentTimeMs()) / 60000)
            logCooldown(string.format("Unit '%s' on cooldown (remaining ~%d min), not available", unitName, remaining))
            return false
        end
        -- Кулдаун истёк – разрешаем спавн (счётчик не трогаем)
        if state.cooldownEnd and state.cooldownEnd <= getCurrentTimeMs() then
            state.cooldownEnd = nil
            logCooldown(string.format("Cooldown expired for '%s', unit available again", unitName))
        end
        return true
    end

    -- Нет ни maxCount, ни cooldown – всегда доступен
    return true
end

-- Обработка успешного спавна юнита
-- unit: таблица с полями unit, maxCount (опционально), cooldown (опционально)
function M.onUnitSpawned(unit)
    if not unit then
        return
    end

    local unitName = unit.unit
    local state = M.state[unitName]

    if not state then
        state = { count = 0, cooldownEnd = nil }
        M.state[unitName] = state
    end

    -- ---- Случай: есть maxCount ----
    if unit.maxCount then
        state.count = state.count + 1
        local msg = string.format("Unit '%s' spawned, count=%d/%d", unitName, state.count, unit.maxCount)

        if state.count >= unit.maxCount and unit.cooldown then
            -- Достигнут лимит, устанавливаем кулдаун
            local cooldownMs = unit.cooldown * 60000
            state.cooldownEnd = getCurrentTimeMs() + cooldownMs
            logBoth(string.format("%s, limit reached, cooldown of %d min started", msg, unit.cooldown))
        elseif state.count >= unit.maxCount then
            -- Достигнут лимит без кулдауна – навсегда
            logLimit(string.format("%s, limit reached permanently", msg))
        else
            logLimit(msg)
        end
        return
    end

    -- ---- Случай: maxCount отсутствует, но есть cooldown ----
    if unit.cooldown then
        -- Устанавливаем кулдаун после спавна (счётчик не используем)
        local cooldownMs = unit.cooldown * 60000
        state.cooldownEnd = getCurrentTimeMs() + cooldownMs
        logCooldown(string.format("Unit '%s' spawned, cooldown of %d min started (no maxCount)", unitName, unit.cooldown))
    end
    -- Если нет ни maxCount, ни cooldown – ничего не делаем
end

return M