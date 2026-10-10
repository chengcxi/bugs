-- File: b_battle_bridge.lua
-- Catalog: script\multiplayer\modes
-- Created 2026-10-05
-- Version 2.0 (2026-10-08): Subscribe removed - GoH single-
--              subscriber limit. M.publish() exposed; called
--              from conquest.lua OnGameStart.
-- Description: B-facing bridge. Publishes BotApi.Conquest.OperationDay
--              as scene var b_operation_day once per GameStart.
--              Read-only. Peer agreement variant (a), 2026-10-08.

local M = {}

local function log(msg)
	print("[ARM] (B bridge): " .. tostring(msg))
end

function M.publish()
	local ok, value = pcall(function()
		return (BotApi and BotApi.Conquest and BotApi.Conquest.OperationDay) or 0
	end)
	if not ok then
		log("OperationDay read failed (pcall): " .. tostring(value))
		value = 0
	end

	local ok2, err = pcall(function()
		BotApi.Scene:SetVar("b_operation_day", value)
	end)
	if not ok2 then
		log("SetVar failed: " .. tostring(err))
		return
	end

	log("b_operation_day = " .. tostring(value))
end

return M