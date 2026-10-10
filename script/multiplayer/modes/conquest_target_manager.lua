-- File: conquest_target_manager.lua
-- Catalog: script\multiplayer\modes
-- Modify by Max Drechsler 
-- Created 27.08.2026
-- Edited 28.08.2026
-- Description: Управление целями (флагами) для атакующего бота.
--              - Выбор только флагов с локацией Enemy или Center (не EnemyBase).
--              - Приоритет: вражеские > нейтральные, с учётом близости.
--              - Распределение отрядов по разным флагам (счётчик назначений).
--              - Индивидуальный таймаут для каждого отряда (4-8 минут).
--              - Если флаг атакуется (назначены отряды), таймаут игнорируется до захвата.
--              - Логи с префиксом [ARM] (Flag attack).

local M = {}

-- Состояние
local squadTargets = {}   -- key = squadId, value = { flagName, startTime, timeoutMs }
local flagAssignments = {} -- key = flagName, value = количество отрядов, назначенных на флаг
local acceptableFlags = {} -- кэш: список { name, priority, location, owner } допустимых флагов
local lastCacheUpdate = 0
local CACHE_UPDATE_INTERVAL = 10000 -- 10 секунд

-- Вспомогательная функция для времени (мс)
local function getTimeMs()
    if BotApi and BotApi.Time then
        return BotApi.Time()
    else
        return os.time() * 1000
    end
end

-- Безопасное получение флага по имени (через массив)
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

-- Получение списка допустимых флагов (все вражеские/нейтральные, без учёта локации)

local function getAcceptableFlags()
    local flags = BotApi.Scene.Flags
    if not flags then return {} end

    -- Эти две строки можно оставить (они не перегружают лог)
    if printDebug then
        print("[ARM] (Flag attack): === DEBUG: Scanning flags ===")
        print("[ARM] (Flag attack): team = " .. tostring(team) .. ", enemyTeam = " .. tostring(enemyTeam))
    end

    local result = {}
    for _, flag in pairs(flags) do
        local owner = GetFlagOwner(flag)
        local isOpponent = (owner == FlagOwnership.Opponent)
        local isNeutral = (owner == FlagOwnership.Neutral)
        local isAcceptable = isOpponent or isNeutral

        -- ЗАКОММЕНТИРОВАН детальный вывод по каждому флагу
        -- if printDebug then
        --     print(string.format("[ARM] (Flag attack): Flag '%s', owner=%s (opponent=%s, neutral=%s, acceptable=%s)",
        --         flag.name, tostring(owner), tostring(isOpponent), tostring(isNeutral), tostring(isAcceptable)))
        -- end

        if isAcceptable then
            local basePriority = (isOpponent and 2.0 or 1.0) * (0.9 + 0.2 * math.random())
            table.insert(result, {
                name = flag.name,
                priority = basePriority,
                location = "any",
                owner = owner,
            })
        end
    end

    if printDebug then
        print("[ARM] (Flag attack): Acceptable flags count = " .. tostring(#result))
    end

    return result
end

-- Обновление кэша допустимых флагов
local function updateCache()
    local newFlags = getAcceptableFlags()
    local newMap = {}
    for _, f in ipairs(newFlags) do
        newMap[f.name] = f
    end

    acceptableFlags = {}
    for name, data in pairs(newMap) do
        acceptableFlags[name] = data
    end

    -- Удаляем из flagAssignments те флаги, которые больше не допустимы
    for flagName, _ in pairs(flagAssignments) do
        if not acceptableFlags[flagName] then
            flagAssignments[flagName] = nil
        end
    end

    lastCacheUpdate = getTimeMs()
    if printDebug then
        print("[ARM] (Flag attack): Cache updated, flags count: " .. tostring(#newFlags))
    end
end

-- Освобождение отряда от цели
function M.releaseSquad(squadId)
    if squadTargets[squadId] then
        local flagName = squadTargets[squadId].flagName
        if flagName and flagAssignments[flagName] then
            flagAssignments[flagName] = flagAssignments[flagName] - 1
            if flagAssignments[flagName] <= 0 then
                flagAssignments[flagName] = nil
            end
            if printDebug then
                print("[ARM] (Flag attack): Squad " .. squadId .. " released from " .. flagName)
            end
        end
        squadTargets[squadId] = nil
    end
end

-- Проверка, жив ли отряд
local function isSquadAlive(squadId)
    return BotApi.Scene:IsSquadExists(squadId)
end

-- Выбор цели для конкретного отряда
function M.getTarget(squadId)

	if not squadId or squadId == 0 then
		return nil
	end

    if botDefender then
        return nil
    end

    local currentTime = getTimeMs()

    -- Если отряд уже имеет цель, проверяем её валидность
    if squadTargets[squadId] then
        local data = squadTargets[squadId]
        local flagName = data.flagName
        local flag = getFlagByName(flagName)
        if flag then
            local owner = GetFlagOwner(flag)
            if owner == FlagOwnership.Opponent or owner == FlagOwnership.Neutral then
                local timeoutExpired = (currentTime - data.startTime > data.timeoutMs)
                if timeoutExpired then
                    -- Если на флаге есть другие отряды, то этот отряд освобождаем, но остальные продолжают
                    if flagAssignments[flagName] and flagAssignments[flagName] <= 1 then
                        M.releaseSquad(squadId)
                        if printDebug then
                            print("[ARM] (Flag attack): Timeout for squad " .. squadId .. " on flag " .. flagName .. ", reassigning")
                        end
                    else
                        M.releaseSquad(squadId)
                        if printDebug then
                            print("[ARM] (Flag attack): Timeout for squad " .. squadId .. " on flag " .. flagName .. ", but others remain, reassigning")
                        end
                    end
                else
                    return flagName
                end
            else
                M.releaseSquad(squadId)
                if printDebug then
                    print("[ARM] (Flag attack): Flag " .. flagName .. " no longer enemy/neutral, releasing squad " .. squadId)
                end
            end
        else
            M.releaseSquad(squadId)
            if printDebug then
                print("[ARM] (Flag attack): Flag " .. flagName .. " disappeared, releasing squad " .. squadId)
            end
        end
    end

    -- Если дошли сюда, значит, у отряда нет цели или она невалидна – выбираем новую
    if currentTime - lastCacheUpdate > CACHE_UPDATE_INTERVAL then
        updateCache()
    end

    -- Собираем кандидатов из acceptableFlags, которые ещё не захвачены
    local candidates = {}
    for name, info in pairs(acceptableFlags) do
        local flag = getFlagByName(name)
        if flag then
            local owner = GetFlagOwner(flag)
            if owner == FlagOwnership.Opponent or owner == FlagOwnership.Neutral then
                local assignments = flagAssignments[name] or 0
                local weight = info.priority / (assignments + 1)
                weight = weight * (0.8 + 0.4 * math.random())
                table.insert(candidates, {
                    name = name,
                    weight = weight,
                    priority = info.priority,
                    assignments = assignments,
                })
            end
        end
    end

    if #candidates == 0 then
        if printDebug then
            print("[ARM] (Flag attack): No candidates for squad " .. squadId)
        end
        return nil
    end

    -- Выбираем случайным образом с учётом весов
    local totalWeight = 0
    for _, c in ipairs(candidates) do
        totalWeight = totalWeight + c.weight
    end
    local rnd = math.random() * totalWeight
    local accum = 0
    for _, c in ipairs(candidates) do
        accum = accum + c.weight
        if rnd <= accum then
            local flagName = c.name
            flagAssignments[flagName] = (flagAssignments[flagName] or 0) + 1
            squadTargets[squadId] = {
                flagName = flagName,
                startTime = currentTime,
                timeoutMs = math.random(4 * 60, 8 * 60) * 1000,
            }
            if printDebug then
                print("[ARM] (Flag attack): Squad " .. squadId .. " assigned to " .. flagName .. " (assignments=" .. flagAssignments[flagName] .. ")")
            end
            return flagName
        end
    end

    -- fallback
    local first = candidates[1]
    if first then
        local flagName = first.name
        flagAssignments[flagName] = (flagAssignments[flagName] or 0) + 1
        squadTargets[squadId] = {
            flagName = flagName,
            startTime = currentTime,
            timeoutMs = math.random(4 * 60, 8 * 60) * 1000,
        }
        if printDebug then
            print("[ARM] (Flag attack): Squad " .. squadId .. " assigned to fallback " .. flagName)
        end
        return flagName
    end

    return nil
end

-- Периодическое обновление (вызывается в OnGameQuant с интервалом)
function M.update()
    if botDefender then
        return
    end

    local currentTime = getTimeMs()
    if currentTime - lastCacheUpdate > CACHE_UPDATE_INTERVAL then
        updateCache()
    end

    -- Проверяем живые отряды, удаляем мёртвые
    for squadId, data in pairs(squadTargets) do
        if not isSquadAlive(squadId) then
            M.releaseSquad(squadId)
            if printDebug then
                print("[ARM] (Flag attack): Squad " .. squadId .. " is dead, released")
            end
        end
    end
end

-- Инициализация
function M.init()
    squadTargets = {}
    flagAssignments = {}
    acceptableFlags = {}
    lastCacheUpdate = 0
    if printDebug then
        print("[ARM] (Flag attack): TargetManager initialized")
    end
end

return M