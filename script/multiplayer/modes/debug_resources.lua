-- debug_resources.lua
-- Модуль для периодического логирования ресурсов бота (MP и CP)
-- Версия 1.0

local M = {}
local lastLogTime = 0
local logInterval = 60 -- секунд

local function logResources()
    local playerId = BotApi.Instance.playerId

    -- Пытаемся получить реальный MP
    local mp = 0
    if BotApi.Commands.GetResource then
        mp = BotApi.Commands:GetResource(playerId, "mp") or 0
    elseif BotApi.Commands.GetBudget then
        mp = BotApi.Commands:GetBudget(playerId) or 0
    else
        mp = BotApi.Commands:Income(playerId) or 0  -- fallback (доход)
    end

    -- CP
    local cp = 0
    if BotApi.Commands.GetResource then
        cp = BotApi.Commands:GetResource(playerId, "cp") or 0
    elseif BotApi.Commands.GetCommandPoints then
        cp = BotApi.Commands:GetCommandPoints(playerId)
    end

    local timeSeconds = 0
    if BotApi.Time then
        timeSeconds = math.floor(BotApi.Time() / 1000)
    end

    print(string.format(
        "[ARM] (Resources): Player#%d | Time: %d s | MP: %.0f | CP: %d",
        playerId, timeSeconds, mp, cp
    ))
end

function M.onQuant()
    local currentTime = 0
    if BotApi.Time then
        currentTime = math.floor(BotApi.Time() / 1000)
    end

    if currentTime - lastLogTime >= logInterval then
        logResources()
        lastLogTime = currentTime
    end
end

function M.start()
    lastLogTime = 0
    logResources()
end

return M