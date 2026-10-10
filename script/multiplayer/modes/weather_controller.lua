-- File: 		weather_controller.lua
-- Catalog: 	script\multiplayer\modes
-- Created by: 	Max Drechsler
-- Created 		30.08.2026
-- Modify 		31.08.2026
-- Version 		6.9
-- Description: Автоматическая смена времени суток через триггер.
--              Первое применение немедленное, последующие с задержкой.

local M = {}

local config = nil
local currentLandscapeCode = 2
local availableTimes = {}
local currentIndex = 1
local cycleTimer = nil
local isRunning = false
local isInitialized = false
local delayStartTime = nil
local startDelayPassed = false
local initialTimeCode = nil
local controllerEntityId = nil
local pendingTriggerTimer = nil
local isFirstApply = true  -- флаг для первого применения

local function log(msg)
    if printDebug then
        print("[ARM] (Weather): " .. msg)
    end
end

-- Получение ID объекта weather_controller
local function getControllerEntity()
    if controllerEntityId and BotApi.Scene:IsEntityExists(controllerEntityId) then
        return controllerEntityId
    end
    local entities = BotApi.Scene.Entities
    for id, ent in pairs(entities) do
        if ent.name == "weather_controller" then
            controllerEntityId = id
            return id
        end
    end
    return nil
end

-- Отмена отложенного триггера
local function cancelPendingTrigger()
    if pendingTriggerTimer then
        BotApi.Events:KillQuantTimer(pendingTriggerTimer)
        pendingTriggerTimer = nil
    end
end

-- Активация триггера через тег (немедленно)
local function triggerWeatherCycleNow()
    local id = getControllerEntity()
    if not id then
        log("Объект 'weather_controller' не найден!")
        return false
    end
    if BotApi.Scene:IsEntityTagged(id, "weather_cycle_trigger") then
        BotApi.Scene:RemoveEntityTag(id, "weather_cycle_trigger")
    end
    BotApi.Scene:AddEntityTag(id, "weather_cycle_trigger")
    log("Добавлен тег weather_cycle_trigger (немедленно)")
    return true
end

-- Установка времени (если первый раз – немедленно, иначе с задержкой)
function M.setTimePeriod(code)
    BotApi.Scene:SetVar("current_time_period", code)
    local names = {[1]="morning", [2]="day", [3]="evening", [4]="night"}
    log("Установлено время: " .. (names[code] or "unknown") .. " (код " .. code .. ")")
    
    if isFirstApply then
        -- Первое применение – немедленно
        isFirstApply = false
        triggerWeatherCycleNow()
    else
        -- Последующие – с задержкой
        cancelPendingTrigger()
        local delayMs = (config.triggerDelay or 2.0) * 1000
        pendingTriggerTimer = BotApi.Events:SetQuantTimer(
            function()
                pendingTriggerTimer = nil
                triggerWeatherCycleNow()
            end,
            delayMs
        )
        log("Установлена задержка " .. (config.triggerDelay or 2.0) .. " сек для следующего переключения")
    end
end

-- Определение сезона (возвращает число 1..4)
local function determineLandscape()
    local fallbackCode = 2
    local sceneName = BotApi.Scene.Name or ""
    sceneName = string.lower(sceneName)
    local baseCode = fallbackCode
    if string.find(sceneName, "winter") or string.find(sceneName, "snow") then
        baseCode = 4
    elseif string.find(sceneName, "autumn") or string.find(sceneName, "fall") then
        baseCode = 3
    elseif string.find(sceneName, "spring") then
        baseCode = 1
    elseif string.find(sceneName, "desert") or string.find(sceneName, "steppe") then
        baseCode = 3
    end
    log("Базовый сезон по имени карты: код " .. baseCode)

    local raw = BotApi.Scene:GetVar("landscape")
    if raw == nil or raw == 0 then
        log("Переменная 'landscape' отсутствует или равна 0, используем базовый сезон")
        return baseCode
    end

    log("Найдена переменная 'landscape' = " .. tostring(raw))
    local landscapeStr = ""
    if type(raw) == "number" then
        if raw == 1 then landscapeStr = "wood"
        elseif raw == 2 then landscapeStr = "desert"
        elseif raw == 3 then landscapeStr = "winter"
        else landscapeStr = "summer"
        end
    elseif type(raw) == "string" then
        landscapeStr = string.lower(raw)
    else
        log("Неизвестный тип переменной landscape, используем базовый сезон")
        return baseCode
    end

    local resultCode = baseCode
    if landscapeStr == "wood" then
        local r = math.random(1,2)
        resultCode = (r == 1) and 1 or 2
        log("landscape = wood, случайный выбор: " .. (resultCode == 1 and "spring" or "summer"))
    elseif landscapeStr == "desert" then
        resultCode = 3
        log("landscape = desert -> autumn")
    elseif landscapeStr == "winter" then
        resultCode = 4
        log("landscape = winter -> winter")
    else
        log("landscape не распознан, оставляем базовый сезон")
    end

    return resultCode
end

-- Построение списка доступных кодов времён (1..4) из конфига
local function buildAvailableTimes(landscapeCode)
    local seasonName = ""
    if landscapeCode == 1 then seasonName = "spring"
    elseif landscapeCode == 2 then seasonName = "summer"
    elseif landscapeCode == 3 then seasonName = "autumn"
    elseif landscapeCode == 4 then seasonName = "winter"
    else seasonName = "summer"
    end

    local order = {1,2,3,4}
    local result = {}
    local avail = config.landscapes[seasonName]
    if not avail then
        log("Сезон '" .. seasonName .. "' не найден в конфиге, используем summer")
        avail = config.landscapes["summer"] or config.landscapes["wood"] or {}
    end
    if type(avail) ~= "table" or #avail == 0 then
        avail = {"morning", "day", "evening"}
    end
    local nameToCode = {morning=1, day=2, evening=3, night=4}
    for _, code in ipairs(order) do
        for _, name in ipairs(avail) do
            if nameToCode[name] == code then
                table.insert(result, code)
                break
            end
        end
    end
    if #result == 0 then
        result = {1,2,3}
    end
    return result
end

-- Переключение на следующее доступное время
function M.nextTimeOfDay()
    if #availableTimes == 0 then
        log("Нет доступных времён, цикл остановлен")
        M.stopCycle()
        return
    end
    currentIndex = currentIndex + 1
    if currentIndex > #availableTimes then
        currentIndex = 1
    end
    M.setTimePeriod(availableTimes[currentIndex])
end

-- Принудительное переключение (для ручной кнопки)
function M.forceNext()
    if not isRunning then
        log("Цикл не активен, forceNext игнорируется")
        return
    end
    M.nextTimeOfDay()
    scheduleNext()
end

-- Планирование следующего переключения
local function scheduleNext()
    if not config.enabled or not isRunning then return end
    local delay = config.cycleDuration * 60 * 1000
    if config.variation and config.variation > 0 then
        delay = delay * (1 + (math.random() - 0.5) * 2 * config.variation)
    end
    delay = math.max(delay, 60000)

    if cycleTimer then
        BotApi.Events:KillQuantTimer(cycleTimer)
        cycleTimer = nil
    end
    cycleTimer = BotApi.Events:SetQuantTimer(function()
        M.nextTimeOfDay()
        scheduleNext()
    end, delay)
end

-- Инициализация
function M.init(cfg)
    if cfg then
        config = cfg
    else
        if Config and Config.Weather then
            config = Config.Weather
        else
            log("Ошибка: конфиг Weather не найден")
            return
        end
    end

    if not config.enabled then
        log("Автоматическая смена суток отключена в конфиге")
        return
    end

    local code = determineLandscape()
    BotApi.Scene:SetVar("current_landscape", code)
    currentLandscapeCode = code
    log("Итоговый сезон: код " .. code)

    availableTimes = buildAvailableTimes(code)
    if #availableTimes == 0 then
        log("Нет доступных времён, автоматизация отключена")
        return
    end

    local startCode = 2
    local startIndex = nil
    for i, v in ipairs(availableTimes) do
        if v == startCode then
            startIndex = i
            break
        end
    end
    if not startIndex then
        startIndex = 1
    end
    currentIndex = startIndex
    initialTimeCode = availableTimes[currentIndex]

    isInitialized = true
    isRunning = false
    delayStartTime = nil
    startDelayPassed = false
    isFirstApply = true  -- сброс флага при инициализации
    log("Модуль инициализирован, ожидание prep_inform и задержки 65 сек (первое применение будет немедленным)")
end

-- Обновление
function M.update()
    if not config.enabled or not isInitialized then return end
    if isRunning then return end

    if BotApi.Scene:GetVar("prep_inform") ~= 1 then
        return
    end

    if not startDelayPassed then
        if not delayStartTime then
            delayStartTime = BotApi.Time()
        end
        if BotApi.Time() - delayStartTime < 65000 then
            return
        end
        startDelayPassed = true
        log("Задержка 65 сек прошла, применяем начальное окружение и запускаем цикл")
        if initialTimeCode then
            M.setTimePeriod(initialTimeCode)
        else
            M.setTimePeriod(2)
        end
        scheduleNext()
        isRunning = true
        return
    end

    if BotApi.Scene:GetVar("manual_weather_switch") == 1 then
        BotApi.Scene:SetVar("manual_weather_switch", 0)
        M.forceNext()
    end
end

-- Остановка цикла
function M.stopCycle()
    if cycleTimer then
        BotApi.Events:KillQuantTimer(cycleTimer)
        cycleTimer = nil
    end
    cancelPendingTrigger()
    isRunning = false
    log("Цикл остановлен")
end

return M