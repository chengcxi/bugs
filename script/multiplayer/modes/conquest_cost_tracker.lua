-- File: conquest_cost_tracker.lua
-- Catalog: script\multiplayer\modes
-- Modify by Max Drechsler 
-- Created 27.08.2026
-- Edited 27.08.2026
-- Описание: отслеживает суммарные траты MP за миссию.
-- Версия 3.0 (с GetUnitCost как fallback)

local M = {}

local totalCost = 0
local startTime = 0
local costMap = {}  -- unitName -> cost
local hasGetUnitCost = false

-- Логирование с префиксом
local function logTracker(msg)
    if printDebug then
        print("[ARm] (CostTracker): " .. msg)
    end
end

-- Построение карты стоимости из Purchases
function M.prepare()
    local nation = BotApi.Instance.army
    local key = "conquest." .. nation
    local purchases = Purchases[key]
    if not purchases then
        logTracker("WARNING: Purchases for '" .. key .. "' not found, cost map empty")
        return
    end

    costMap = {}
    local count = 0
    for _, entry in ipairs(purchases) do
        local units = entry.Units
        if units then
            for _, unitData in ipairs(units) do
                if unitData.unit and unitData.cost and type(unitData.cost) == "number" then
                    costMap[unitData.unit] = unitData.cost
                    count = count + 1
                end
            end
        end
    end
    logTracker(string.format("Cost map built: %d entries", count))

    -- Проверяем наличие функции GetUnitCost
    if BotApi.Commands and BotApi.Commands.GetUnitCost then
        hasGetUnitCost = true
        logTracker("GetUnitCost available, will use as fallback")
    else
        hasGetUnitCost = false
        logTracker("GetUnitCost not available, using only Purchases map")
    end
end

-- Инициализация (запоминаем время старта)
function M.init()
    totalCost = 0
    local success, time = pcall(BotApi.Time, BotApi)
    if success then
        startTime = time
    else
        startTime = 0
        logTracker("WARNING: Could not get time at init")
    end
    logTracker("Started tracking at time " .. tostring(startTime))
end

-- Получение стоимости юнита (сначала из карты, затем через GetUnitCost)
local function getUnitCost(unitName)
    -- Сначала проверяем карту
    local cost = costMap[unitName]
    if cost then
        return cost
    end

    -- Если карта не дала результат, пробуем GetUnitCost (если доступен)
    if hasGetUnitCost then
        local success, result = pcall(BotApi.Commands.GetUnitCost, BotApi.Commands, unitName)
        if success and result and type(result) == "number" then
            return result
        else
            if printDebug then
                logTracker(string.format("GetUnitCost failed for %s", unitName))
            end
        end
    end

    return nil
end

-- Обработка спавна юнита
function M.onUnitSpawned(spawnInfo)
    if not spawnInfo or not spawnInfo.unit then
        logTracker("WARNING: onUnitSpawned called with nil unit or spawnInfo")
        return
    end

    local unitName = spawnInfo.unit
    local cost = getUnitCost(unitName)

    if cost then
        totalCost = totalCost + cost
    else
        logTracker(string.format("WARNING: unit has no cost in map and GetUnitCost failed: %s", unitName))
    end
end

-- Вывод статистики по окончании миссии
function M.finish()
    local success, time = pcall(BotApi.Time, BotApi)
    if not success then
        logTracker("WARNING: Could not get time for finish")
        logTracker(string.format("Total spent: %d MP (time unknown)", totalCost))
        return totalCost
    end

    local elapsed = (time - startTime) / 1000
    if elapsed < 0 then
        logTracker("WARNING: Negative elapsed time, ignoring")
        elapsed = 0
    end

    logTracker(string.format("Total spent: %d MP over %.0f seconds", totalCost, elapsed))
    if elapsed > 0 then
        logTracker(string.format("Average spending rate: %.0f MP/min", totalCost / (elapsed / 60)))
    else
        logTracker("Average spending rate: N/A (zero elapsed time)")
    end

    return totalCost
end

return M