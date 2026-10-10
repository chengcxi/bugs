-- File: conquest_para.lua
-- Catalog: script\multiplayer\modes
-- Modify by Max Drechsler 
-- Created 23.08.2026
-- Edited 24.08.2026
-- Version 2.5 (team assignment)

-- Функция для сохранения команды бота в глобальную переменную (для GEM-триггеров)
function setBotTeam()
    local teamId = BotApi.Instance.teamId
    if not teamId or teamId == 0 then
        print("[ARm] Lua: teamId invalid, cannot set enemy_team_id")
        return
    end
    BotApi.Scene:SetVar("enemy_team_id", teamId)
    print("[ARm] Lua: enemy_team_id set to " .. tostring(teamId))
end