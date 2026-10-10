-- File: 			conquest_simple_ambush.lua
-- Catalog: 		script\multiplayer\modes
-- Created by:		Max Drechsler
-- Created: 		28.08.2026
-- Modify: 			30.08.2026
-- Version: 3.1 	раздельные переменные для сообщений
-- Description: 	Упрощённый амбуш – спавн пехоты на точке игрока или бота (выбирается в конфиге).
--              	Юниты берутся из config.M.SimpleAmbush.unitNames.
--              	Активируется только после завершения стадии подготовки (prep_inform = 1).
--             		Устанавливает переменные ambush_message_1_ready и ambush_message_2_ready для триггеров в миссии.

local M = {}

-- Настройки по умолчанию (будут переопределены из конфига)
local config = {
    enabled = true,
    chance = 0.3,
    minInterval = 8 * 60 * 1000,
    maxInterval = 12 * 60 * 1000,
    startDelay = 15 * 60 * 1000,
    maxSpawns = 3,
    countPerSpawn = 2,
    unitNames = {},
    spawnOnBotSpawn = false,   -- false = точка игрока, true = точка бота
}

unitCache = {} -- глобальная

local state = {
    nextAttemptTime = 0,
    spawnsDone = 0,
    initialized = false,
    processing = false,
}

local function getTimeMs() return os.time() * 1000 end

local function SceneVar(name, default)
    local v = BotApi.Scene:GetVar(name)
    if v ~= nil then return v end
    return default
end

local function SetSceneVar(name, value)
    BotApi.Scene:SetVar(name, value)
end

local function getPlayerSpawnIndex()
    local spawnName = BotApi.Conquest.PlayerSpawnPoint
    local map = {
        a1 = 1, a2 = 2, a3 = 3, a4 = 4,
        b1 = 5, b2 = 6, b3 = 7, b4 = 8,
    }
    return map[spawnName] or 0
end

local function buildUnitCache()
    unitCache = {}
    local nation = BotApi.Instance.army
    local unitList = config.unitNames[nation]
    if not unitList or #unitList == 0 then
        if printDebug then print("[ARM] SimpleAmbush: No unit names for " .. nation) end
        return
    end
    local cached = {}
    for _, unitName in ipairs(unitList) do
        table.insert(cached, { unit = unitName, priority = 1 })
    end
    if #cached > 0 then
        unitCache[nation] = cached
        if printDebug then print("[ARM] SimpleAmbush: Unit list for " .. nation .. " contains " .. #cached .. " units") end
    else
        if printDebug then print("[ARM] SimpleAmbush: No units found for " .. nation) end
    end
end

local function spawnAmbushUnits()
    if not unitCache then
        buildUnitCache()
        if not unitCache then return end
    end

    local nation = BotApi.Instance.army
    local cached = unitCache[nation]
    if not cached or #cached == 0 then return end

    local targetCount = config.countPerSpawn or 2
    local spawned = 0
    local anySpawned = false

    -- Перемешиваем кэш для разнообразия
    for i = #cached, 2, -1 do
        local j = math.random(i)
        cached[i], cached[j] = cached[j], cached[i]
    end

    -- Определяем, где спавнить
    local spawnIdx = 0
    if config.spawnOnBotSpawn then
        spawnIdx = conquestSpawnPointIndex
        if printDebug then print("[ARM] SimpleAmbush: spawnOnBotSpawn = true, using conquestSpawnPointIndex = " .. tostring(spawnIdx)) end
    else
        spawnIdx = getPlayerSpawnIndex()
        if printDebug then print("[ARM] SimpleAmbush: spawnOnBotSpawn = false, using PlayerSpawnPoint index = " .. tostring(spawnIdx)) end
    end

    if spawnIdx == 0 then
        if printDebug then print("[ARM] SimpleAmbush: spawnIdx is 0, aborting") end
        return
    end

    for _, entry in ipairs(cached) do
        if spawned >= targetCount then break end
        local unit = entry.unit

        if BotApi.Commands:SpawnAt(unit, 0, spawnIdx) then
            spawned = spawned + 1
            anySpawned = true
            if printDebug then print("[ARM] SimpleAmbush: Spawned " .. unit .. " at index " .. spawnIdx) end
        else
            if printDebug then print("[ARM] SimpleAmbush: Failed to spawn " .. unit .. " at index " .. spawnIdx) end
        end
    end

    -- Если удалось заспавнить хотя бы один отряд, устанавливаем переменные для триггеров
    if anySpawned then
        -- Устанавливаем первую переменную сразу
        SetSceneVar("ambush_message_1_ready", 1)
        if printDebug then print("[ARM] SimpleAmbush: Set ambush_message_1_ready = 1") end

        -- Устанавливаем вторую переменную через 5 секунд (для второго сообщения)
        BotApi.Events:SetQuantTimer(
            function()
                SetSceneVar("ambush_message_2_ready", 1)
                if printDebug then print("[ARM] SimpleAmbush: Set ambush_message_2_ready = 1") end
            end,
            5000
        )
    end

    if printDebug then print("[ARM] SimpleAmbush: Spawned " .. spawned .. " units (target " .. targetCount .. ")") end
end

function M.init(cfg)
    if cfg then
        config.enabled = (cfg.enabled ~= nil) and cfg.enabled or config.enabled
        config.chance = cfg.chance or config.chance
        config.minInterval = cfg.minInterval or config.minInterval
        config.maxInterval = cfg.maxInterval or config.maxInterval
        config.startDelay = cfg.startDelay or config.startDelay
        config.maxSpawns = cfg.maxSpawns or config.maxSpawns
        config.countPerSpawn = cfg.countPerSpawn or config.countPerSpawn
        config.unitNames = cfg.unitNames or config.unitNames
        config.spawnOnBotSpawn = (cfg.spawnOnBotSpawn ~= nil) and cfg.spawnOnBotSpawn or config.spawnOnBotSpawn
    end

    buildUnitCache()
    state.nextAttemptTime = getTimeMs() + config.startDelay
    state.spawnsDone = 0
    state.initialized = true
    state.processing = false

    -- Сбрасываем переменные для триггеров
    SetSceneVar("ambush_message_1_ready", 0)
    SetSceneVar("ambush_message_2_ready", 0)

    if printDebug then
        print("[ARM] SimpleAmbush: Initialized, first attempt at " .. tostring(config.startDelay / 1000) .. "s")
        print("[ARM] SimpleAmbush: Chance=" .. tostring(config.chance * 100) .. "%, Interval=" .. tostring(config.minInterval / 60000) .. "-" .. tostring(config.maxInterval / 60000) .. "min, Max spawns=" .. tostring(config.maxSpawns))
        print("[ARM] SimpleAmbush: spawnOnBotSpawn = " .. tostring(config.spawnOnBotSpawn))
        print("[ARM] SimpleAmbush: Reset ambush_message_1_ready and ambush_message_2_ready to 0")
    end
end

function M.update()
    if not config.enabled then return end
    if not state.initialized then return end
    if state.spawnsDone >= config.maxSpawns then return end
    if state.processing then return end

    -- Жёсткая проверка завершения подготовки
    if SceneVar("prep_inform", 0) ~= 1 then
        return
    end

    local currentTime = getTimeMs()
    if currentTime < state.nextAttemptTime then return end

    state.processing = true

    if math.random() <= config.chance then
        if printDebug then print("[ARM] SimpleAmbush: SUCCESS! Spawning ambush.") end
        spawnAmbushUnits()
        state.spawnsDone = state.spawnsDone + 1
    else
        if printDebug then print("[ARM] SimpleAmbush: CHANCE FAILED.") end
    end

    state.nextAttemptTime = currentTime + math.random(config.minInterval, config.maxInterval)
    state.processing = false
end

return M