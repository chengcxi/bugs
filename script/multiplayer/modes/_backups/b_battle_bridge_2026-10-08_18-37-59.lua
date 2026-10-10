-- File: b_battle_bridge.lua
-- Catalog: script\multiplayer\modes
-- Created 2026-10-05
-- Version 1.0
-- Description: B-facing bridge. Publishes BotApi.Conquest.OperationDay
--              as scene var "b_operation_day" on every GameStart.
--              Read-only: does not modify anything else.
--              Requested by project B (DSL ARMCE) 2026-10-05.

local M = {}

local function log(msg)
	print("[ARM] (B bridge): " .. tostring(msg))
end

local function publish()
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

function M.init()
	if not BotApi or not BotApi.Events then
		log("BotApi.Events unavailable, bridge disabled")
		return
	end
	pcall(function()
		BotApi.Events:Subscribe(BotApi.Events.GameStart, publish)
	end)
	log("subscribed to GameStart")
end

return M