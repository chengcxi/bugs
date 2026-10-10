-- File: 		conquest.lua
-- Catalog: 	script\multiplayer\modes\
-- Created by: 	-
-- Created:		x.xx.xxxx
-- Modify by:	Max Drechsler
-- Modify:		12.09.2026
-- DSL:			GEM ENGINE 2 Gates of Hell
-- Version:		9.3
-- Description: 

-- < [ ADD ARM START ]:

-- 	local CostTracker = require([[/script/multiplayer/modes/conquest_cost_tracker]])
-- 	require([[/script/multiplayer/modes/log_filter]])
	require([[/script/multiplayer/modes/utility]])
	require([[/script/multiplayer/modes/conquest_lair]])
	require([[/script/multiplayer/modes/conquest_np]])
	local StageCalculator = require([[/script/multiplayer/modes/conquest_stage_calculator]])		--dev
	local WeatherController = require([[/script/multiplayer/modes/weather_controller]])				--dev
-- 	local SimpleAmbush = require([[/script/multiplayer/modes/conquest_simple_ambush]])
-- 	require([[/script/multiplayer/modes/conquest_para]])
	local UnitFilter = require([[/script/multiplayer/modes/conquest_type_filter]])
	local UnitLimiter = require([[/script/multiplayer/modes/conquest_limiter]])
-- 	local ResourcesDebug = require([[/script/multiplayer/modes/debug_resources]])
	local Doctrine = require([[/script/multiplayer/modes/conquest_doctrine]])
	local TankInfantryRatio = require([[/script/multiplayer/modes/conquest_tank_infantry_ratio]])
	local Multiplier = require([[/script/multiplayer/modes/conquest_unit_multiplier]])
-- 	local TargetManager = require([[/script/multiplayer/modes/conquest_target_manager]])
	local Config = require([[/script/multiplayer/modes/config]])
	local StuckManager = require([[/script/multiplayer/modes/conquest_stuck_manager]])

-- > [ ADD ARM END ]:

-- < [ ADD ARM START ]:
local botDefender = false
local currentBattleNumber = 1
local function isAttackerOrDefender()
	if BotApi.Conquest and BotApi.Conquest.Attacking then
		botDefender = false
	else
		botDefender = true
	end
	if printDebug then print("[ARM] Print: botDefender = " .. tostring(botDefender)) end
end
-- > [ ADD ARM END ]:

-- Используем параметры из конфига
local StartSpawnTime = Config.StartSpawnTime
local SpawnCooldownTimeByDifficulty = Config.SpawnCooldownTimeByDifficulty

local WaveUnitByRoleAndDifficulty = {
	easy = { defender = { Min = 7, Max = 11 }, attacker = { Min = 15, Max = 18 } },
	normal = { defender = { Min = 9, Max = 13 }, attacker = { Min = 17, Max = 20 } },
	hard = { defender = { Min = 11, Max = 15 }, attacker = { Min = 19, Max = 22 } },
	heroic = { defender = { Min = 13, Max = 17 }, attacker = { Min = 21, Max = 24 } },
}
local function getBattleMultiplier(battleNumber)
	if battleNumber <= 1 then return 1.0 elseif battleNumber <= 2 then return 1.0 else return 1.1 end
end
local function roundToInt(x) return math.floor(x + 0.5) end
local function GetBotDifficultyKey() return BotApi.Instance.difficulty or "normal" end
local function GetStartSpawnTime() return StartSpawnTime end
local function GetSpawnCooldownTime() return SpawnCooldownTimeByDifficulty[GetBotDifficultyKey()] or SpawnCooldownTimeByDifficulty.normal end
local function GetWaveUnit()
	local difficulty = GetBotDifficultyKey()
	local roleTable = WaveUnitByRoleAndDifficulty[difficulty] or WaveUnitByRoleAndDifficulty.normal
	local roleKey = botDefender and "defender" or "attacker"
	local base = roleTable[roleKey] or roleTable["defender"]
	local mult = getBattleMultiplier(currentBattleNumber)
	local adjustedMin = roundToInt(base.Min * mult)
	local adjustedMax = roundToInt(base.Max * mult)
	if adjustedMin > adjustedMax then adjustedMin, adjustedMax = adjustedMax, adjustedMin end
	if printDebug then
		print(string.format("[ARm] (WAve): Multiplier applied: %.2f (based on defense level %d)", mult, currentBattleNumber))
		print(string.format("[ARm] (WAve): Base: %d-%d -> Adjusted: %d-%d (role: %s, diff: %s)", base.Min, base.Max, adjustedMin, adjustedMax, roleKey, difficulty))
	end
	return { Min = adjustedMin, Max = adjustedMax }
end
local function RollWaveUnitTotal()
	local waveUnit = GetWaveUnit()
	if not waveUnit or not waveUnit.Min or not waveUnit.Max then
		if printDebug then print("[ARm] (WAve): ERROR: Invalid waveUnit, using fallback 10") end
		return 10
	end
	local total = math.random(waveUnit.Min, waveUnit.Max)
	if printDebug then print(string.format("[ARm] (WAve): Rolled %d units for this wave (multiplier: %.2f)", total, getBattleMultiplier(currentBattleNumber))) end
	return total
end

-- ============================================================
-- [DISABLED] АМБУШ (ВРЕМЕННО ОТКЛЮЧЁН)
-- ============================================================
--[[
local AmbushUnitDefinitions = {
    ger = { {"Infantry", "Squad", "SS"}, {"Infantry", "Squad", "LW"} },
    rus = { {"Infantry", "Squad", "Partisan"}, {"Infantry", "Squad", "Spetz"}, {"Infantry", "Squad", "Para"} },
    fin = { {"Infantry", "Squad"}, {"Infantry", "Team", "AT"} },
    usa = { {"Infantry", "Squad"}, {"Infantry", "Team", "AT"} },
    eng = { {"Infantry", "Squad"}, {"Infantry", "Team", "AT"} },
}

local function isEligibleAmbushUnit(unit)
    if not unit or not unit.type then return false end
    local nation = BotApi.Instance.army
    local definitions = AmbushUnitDefinitions[nation]
    if not definitions then return false end
    for _, tagSet in ipairs(definitions) do
        local allMatch = true
        for _, tag in ipairs(tagSet) do
            if not HasType(unit, tag) then allMatch = false break end
        end
        if allMatch then return true end
    end
    return false
end

local function hasAmbushUnits()
    local nation = BotApi.Instance.army
    local key = "conquest." .. nation
    local purchases = Purchases[key]
    if not purchases then return false end
    for _, entry in ipairs(purchases) do
        local units = entry.Units
        if units then
            for _, unit in ipairs(units) do
                if isEligibleAmbushUnit(unit) then return true end
            end
        end
    end
    return false
end

local AmbushEventState = {
	active = false, warning = false, relocating = false, spawning = false, restoring = false,
	spawned = 0, target = 3, eventTimeoutTimer = nil,
}
local ambushEventTriggered = false
local ambushWarningTimer = nil
local AMBUSH_STALL_TIMEOUT = 30 * 1000
local ambushStallTimer = nil
local ambushNextAttemptTime = 0

local function CancelAmbushStallTimer()
	if ambushStallTimer then BotApi.Events:KillQuantTimer(ambushStallTimer) ambushStallTimer = nil end
end

local function BeginAmbushRestore(reason)
	if AmbushEventState.restoring then return end
	if AmbushEventState.eventTimeoutTimer then BotApi.Events:KillQuantTimer(AmbushEventState.eventTimeoutTimer) AmbushEventState.eventTimeoutTimer = nil end
	CancelAmbushStallTimer()
	AmbushEventState.spawning = false
	AmbushEventState.relocating = false
	AmbushEventState.restoring = true
	SetSceneVar("ai_ambush_active", 0)
	if type(KillSpawnWaitTimer) == "function" then KillSpawnWaitTimer() end
	if Context then Context.SpawnInfo = nil; if Context.SpawnWait then Context.SpawnWait.RetryPendingUnit = false end end
	SetSceneVar("ai_ambush_restore_done", 0)
	SetSceneVar("ai_ambush_restore_request", 1)
	print("[AMBUSH] RESTORE REQUESTED reason=" .. tostring(reason) .. " spawned=" .. tostring(AmbushEventState.spawned) .. "/" .. tostring(AmbushEventState.target))
	ambushRollDone = false
	ambushEventTriggered = false
	ambushNextAttemptTime = BotApi.Time() + math.random(5 * 60, 10 * 60) * 1000
	print("[AMBUSH] STATE RESET - NEXT ATTEMPT AT " .. tostring(ambushNextAttemptTime))
end

local function RestartAmbushStallTimer()
	CancelAmbushStallTimer()
	if not AmbushEventState.spawning then return end
	ambushStallTimer = BotApi.Events:SetQuantTimer(function()
		ambushStallTimer = nil
		if AmbushEventState.spawning then
			print("[AMBUSH] STALLED - NO SPAWN FOR " .. tostring(AMBUSH_STALL_TIMEOUT / 1000) .. " SECONDS")
			BeginAmbushRestore("SPAWN STALLED")
		end
	end, AMBUSH_STALL_TIMEOUT)
end

local function StartAmbushEvent()
	if AmbushEventState.active or ambushEventTriggered then return end
	local eventTimeout = BotApi.Events:SetQuantTimer(function()
		if AmbushEventState.active then print("[AMBUSH] EVENT TIMEOUT - FORCE RESTORE") BeginAmbushRestore("TIMEOUT") end
	end, 120 * 1000)
	ambushEventTriggered = true
	AmbushEventState.active = true
	AmbushEventState.warning = true
	AmbushEventState.relocating = false
	AmbushEventState.spawning = false
	AmbushEventState.restoring = false
	AmbushEventState.spawned = 0
	AmbushEventState.target = 3
	AmbushEventState.eventTimeoutTimer = eventTimeout
	SetSceneVar("ai_ambush_active", 0)
	SetSceneVar("ai_ambush_done", 0)
	SetSceneVar("ai_ambush_spawned", 0)
	SetSceneVar("ai_ambush_relocate_request", 0)
	SetSceneVar("ai_ambush_spawn_ready", 0)
	SetSceneVar("ai_ambush_restore_request", 0)
	SetSceneVar("ai_ambush_restore_done", 0)
	print("[AMBUSH] EVENT WARNING STARTED playerSpawn=" .. tostring(BotApi.Conquest.PlayerSpawnPoint))
	SetSceneVar("ai_ambush_warning_request", 1)
	ambushWarningTimer = BotApi.Events:SetQuantTimer(function()
		ambushWarningTimer = nil
		AmbushEventState.warning = false
		AmbushEventState.relocating = true
		SetSceneVar("ai_ambush_spawn_ready", 0)
		SetSceneVar("ai_ambush_relocate_request", 1)
		print("[AMBUSH] RELOCATION REQUESTED playerSpawn=" .. tostring(BotApi.Conquest.PlayerSpawnPoint))
	end, 25 * 1000)
end

local function UpdateAmbushRelocationState()
	if AmbushEventState.relocating and SceneVar("ai_ambush_spawn_ready", 0) == 1 then
		SetSceneVar("ai_ambush_spawn_ready", 0)
		AmbushEventState.relocating = false
		AmbushEventState.spawning = true
		SetSceneVar("ai_ambush_active", 1)
		if type(KillSpawnCooldownTimer) == "function" then KillSpawnCooldownTimer() end
		if type(KillSpawnWaitTimer) == "function" then KillSpawnWaitTimer() end
		if Context then Context.SpawnInfo = nil; if Context.SpawnWait then Context.SpawnWait.RetryPendingUnit = false end end
		if Context and Context.Purchase and type(UpdateUnitToSpawn) == "function" then UpdateUnitToSpawn(Context.Purchase) end
		print("[AMBUSH] SPAWN RELOCATION COMPLETE - SPAWNING STARTED")
		RestartAmbushStallTimer()
		return
	end
	if AmbushEventState.restoring and SceneVar("ai_ambush_restore_done", 0) == 1 then
		if AmbushEventState.eventTimeoutTimer then BotApi.Events:KillQuantTimer(AmbushEventState.eventTimeoutTimer) AmbushEventState.eventTimeoutTimer = nil end
		SetSceneVar("ai_ambush_restore_done", 0)
		AmbushEventState.restoring = false
		AmbushEventState.active = false
		SetSceneVar("ai_ambush_active", 0)
		SetSceneVar("ai_ambush_done", 1)
		if type(KillSpawnCooldownTimer) == "function" then KillSpawnCooldownTimer() end
		if type(SetSpawnCooldownTimer) == "function" then SetSpawnCooldownTimer() end
		print("[AMBUSH] SPAWN POINTS RESTORED - EVENT COMPLETE")
		ambushRollDone = false
		ambushEventTriggered = false
		ambushNextAttemptTime = BotApi.Time() + math.random(5 * 60, 10 * 60) * 1000
		print("[AMBUSH] STATE RESET - NEXT ATTEMPT AT " .. tostring(ambushNextAttemptTime))
		return
	end
end

local AMBUSH_CHANCE = 1.0
local ambushRollDone = false

local function IsAmbushTierAllowed() return SceneVar("tier2", 0) == 1 end

local function UpdateAmbushEventScheduler()
	if botDefender then return end
	if not hasAmbushUnits() then return end
	if SceneVar("prep_inform", 0) ~= 1 then return end
	if ambushEventTriggered then return end
	if ambushRollDone then return end
	if not IsAmbushTierAllowed() then return end

	local currentTime = BotApi.Time()
	if ambushNextAttemptTime == 0 then
		ambushNextAttemptTime = currentTime + math.random(5 * 60, 10 * 60) * 1000
		if printDebug then print("[AMBUSH] First attempt scheduled at " .. tostring(ambushNextAttemptTime)) end
		return
	end

	if currentTime < ambushNextAttemptTime then
		return
	end

	ambushRollDone = true
	local roll = math.random()
	print("[AMBUSH] CHANCE ROLL=" .. tostring(roll) .. " required<=" .. tostring(AMBUSH_CHANCE))
	if roll <= AMBUSH_CHANCE then
		print("[AMBUSH] CHANCE SUCCESS")
		StartAmbushEvent()
	else
		print("[AMBUSH] CHANCE FAILED - WILL RETRY AFTER DELAY")
		ambushRollDone = false
		ambushNextAttemptTime = currentTime + math.random(5 * 60, 10 * 60) * 1000
	end
end
--]] -- [DISABLED] Конец блока амбуша
-- ============================================================

-- Артиллерия (отключена)
local ArtilleryOrderState = { bought = 0, target = 0, toSpawn = 0, lastResetState = 0 }
local function RollArtilleryCount() return 0 end
local PendingArtillerySpawnTag = false
local PendingArtillerySpawnUnit = nil
local ScriptedArtillerySquads = {}
local function IsReservedArtillerySquad(squad) return false end
local function IsArtilleryOrderEnabled() return false end
local function RefreshArtilleryOrderState() end
local function GetOrderedArtilleryUnit(units) return nil end
local function ShouldAllowArtilleryOrder() return false end
local function StartArtilleryOrder() end
local function StartArtilleryStartDelay() end
local function RollArtilleryDelayMs() return 0 end
local function StartArtilleryDelayTimer() end
local function UpdateArtilleryOrderScheduler() end

-- Используем параметры из конфига
local UnitSpawnWaitTime = Config.UnitSpawnWaitTime
local OrderRotationPeriod = Config.OrderRotationPeriod
searchDestroy = Config.searchDestroy

local enableWaveCounter = true
local waveSpawnPossible, waveSpawnActive = nil, true
local waveUnitCount, waveNumber, waveUnitTotal = 0, 0, 0
local firstPurchase = true
local conquestSpawnPointIndex = 0
local spawningUnit = false
local teamIsLosing = false

function GameModeSpawnUnit(unit, maxSquadSize)
	if BotApi.Commands:SpawnAt(unit, maxSquadSize, conquestSpawnPointIndex) then
		conquestSpawnPointIndex = conquestSpawnPointIndex + 1
		return true
	end
	return false
end

local function setVarsInMissionScript()
	BotApi.Scene:SetVar("user_is_defender", botDefender and 0 or 1)
	local nationMap = { rus = 1, ger = 2, fin = 3, usa = 4, eng = 5, jap = 11 }
	local difficultyMap = { easy = 1, normal = 2, hard = 3, heroic = 4 }
	local spawnMap = { a = 1, b = 2 }
	local playerSpawnNameMap = { a1 = 1, a2 = 2, a3 = 3, a4 = 4, b1 = 5, b2 = 6, b3 = 7, b4 = 8 }
	BotApi.Scene:SetVar("bot_army", nationMap[BotApi.Instance.army] or 0)
	BotApi.Scene:SetVar("bot_difficulty", difficultyMap[BotApi.Instance.difficulty] or 0)
	BotApi.Scene:SetVar("bots_spawnside", spawnMap[spawnSide] or 0)
	BotApi.Scene:SetVar("player_spawn_name", playerSpawnNameMap[BotApi.Conquest.PlayerSpawnPoint] or 0)
	BotApi.Scene:SetVar("enemyid", BotApi.Instance.playerId)
	BotApi.Scene:SetVar("id_1st_enemy", BotApi.Conquest.FirstEnemyId)
	BotApi.Scene:SetVar("id_defenderbot", BotApi.Conquest.DefenderBotId)
	BotApi.Scene:SetVar("id_1st_player", BotApi.Conquest.FirstPlayerId)
end

function WaveAttack()
	waveSpawnPossible = true
	if waveUnitCount >= waveUnitTotal then
		waveUnitTotal = RollWaveUnitTotal()
		if printDebug then print("[ARM] Print: waveUnitTotal", waveUnitTotal) end
		waveSpawnActive = false
		waveUnitCount = 0
		waveNumber = waveNumber + 1
		if printDebug then print("[ARM] Print: waveNumber", waveNumber) end
	else
		waveSpawnActive = true
	end
end

function WaveUnitCounter()
	if waveSpawnPossible then
		waveUnitCount = waveUnitCount + 1
		if printDebug then print("[ARM] Print: waveUnitCount =", waveUnitCount) end
	end
end

function table.shuffle(tbl)
	local rand = math.random
	for i = #tbl, 2, -1 do
		local j = rand(i)
		tbl[i], tbl[j] = tbl[j], tbl[i]
	end
	return tbl
end

local function shuffleFlags(flags)
	if waveNumber <= 1 then table.sort(flags, function(a, b) return a.name < b.name end) else table.shuffle(flags) end
end

local function calculateAttackerPriority(f, enemyTeam, team, firstEnemyFlagEncountered)
	if f.owner == enemyTeam and not firstEnemyFlagEncountered then
		firstEnemyFlagEncountered = true
		return f.priority, firstEnemyFlagEncountered
	elseif f.owner == enemyTeam or f.owner == team then
		return 0, firstEnemyFlagEncountered
	end
	return f.priority, firstEnemyFlagEncountered
end

local function calculateDefenderPriority(f, enemyTeam, team)
	if f.owner == enemyTeam then return f.priority * 2
	elseif f.owner == team then return f.priority * 0.5
	else return f.priority end
end

function GetFlagToCapture(flagPoints, getPriority, flags)
	local alliedFlags, opponentFlags, neutralFlags, totalFlags = CalculateFlagStatistics(BotApi.Scene.Flags)
	local capturableFlags = CalculateCapturableFlags(totalFlags, alliedFlags)
	PrintFlagDebugInfo(alliedFlags, opponentFlags, neutralFlags, totalFlags, capturableFlags, teamIsLosing)
	searchDestroy = CalculateSearchDestroyValue(capturableFlags, alliedFlags, opponentFlags)
	if waveNumber <= 1 then shuffleFlags(flags) end
	local firstEnemyFlagEncountered = false
	return GetRandomItem(flags, function(f)
		if not botDefender then
			local priority; priority, firstEnemyFlagEncountered = calculateAttackerPriority(f, enemyTeam, team, firstEnemyFlagEncountered)
			return priority
		else
			return calculateDefenderPriority(f, enemyTeam, team)
		end
	end)
end

function GotoNextWaypoint(squad)
	local waypoints = BotApi.Scene.Waypoints
	BotApi.Commands:CaptureFlag(squad, waypoints[math.random(#waypoints)])
end

function OnWaypoint(args)
	if IsReservedArtillerySquad(args.squadId) then return end
	GotoNextWaypoint(args.squadId)
end

local function SceneVar(name, default)
	local v = BotApi.Scene:GetVar(name)
	if v ~= nil then return v end
	return default
end

local function SetSceneVar(name, value)
	BotApi.Scene:SetVar(name, value)
end

function GameModeSpawnCooldown()
	WaveAttack()
	local spawnTime
	local startSpawnTime = GetStartSpawnTime()
	local spawnCooldownTime = GetSpawnCooldownTime()
	if botDefender and firstPurchase then
		spawnTime = { Min = startSpawnTime.DefenseMin, Max = startSpawnTime.DefenseMax }
	elseif firstPurchase then
		spawnTime = { Min = startSpawnTime.AttackMin, Max = startSpawnTime.AttackMax }
	elseif not waveSpawnActive then
		spawnTime = { Min = spawnCooldownTime.DCGWaveOffMin, Max = spawnCooldownTime.DCGWaveOffMax }
	else
		spawnTime = { Min = spawnCooldownTime.DCGMin, Max = spawnCooldownTime.DCGMax }
	end
	local cooldown = math.random(spawnTime.Min, spawnTime.Max)
	firstPurchase = false
	return cooldown
end

local function HasType(unitInfo, wanted)
	if not unitInfo or not unitInfo.type then return false end
	for _, v in ipairs(unitInfo.type) do if v == wanted then return true end end
	return false
end

local function TypeList(unitInfo)
	if not unitInfo or not unitInfo.type then return "nil" end
	local out = {}
	for _, v in ipairs(unitInfo.type) do table.insert(out, tostring(v)) end
	return table.concat(out, ",")
end

function GetModeSpecificUnitToSpawn(purchase, units)
	-- [DISABLED] Ранее использовался для амбуша и артиллерии. Сейчас заглушка.
	return nil
end

function OnUnitPurchased()
	local spawnInfo = Context and Context.SpawnInfo
	if spawnInfo and spawnInfo.ordered_artillery then
		OnModeSpecificUnitSpawned(spawnInfo)
		return
	end
	if spawnInfo and spawnInfo.unit then
		UnitLimiter.onUnitSpawned(spawnInfo)
		TankInfantryRatio.onUnitSpawned(spawnInfo)
		if TankInfantryRatio.isTank(spawnInfo) then TankInfantryRatio.onTankSpawned() end
		Multiplier.onUnitSpawned(spawnInfo)
	end
	if enableWaveCounter then WaveUnitCounter() end
end

function OnModeSpecificUnitSpawned(spawnInfo)
	-- [DISABLED] Ранее для артиллерии и амбуша. Сейчас заглушка.
end

function OnGameQuant()
	-- [DISABLED] Артиллерия и амбуш отключены
	-- UpdateArtilleryOrderScheduler() -- отключено
	-- UpdateAmbushEventScheduler() -- [DISABLED] Амбуш временно отключён
	-- UpdateAmbushRelocationState() -- [DISABLED] Амбуш временно отключён

	-- < [ STUCK MANAGER START ]: Обновление механизма «застревания» (только для атакующего)
	if not botDefender then
		local status, err = pcall(StuckManager.update)
		if not status and printDebug then
			print("[ARM] Error in StuckManager.update: " .. tostring(err))
		end
	end
	-- > [ STUCK MANAGER END ]

-- < [ ADD SIMPLE AMBUSH START ]: Обновление упрощённого амбуша (только для атакующего)
--	if not botDefender then
--		local status, err = pcall(SimpleAmbush.update)
--		if not status and printDebug then
--			print("[ARM] Error in SimpleAmbush.update: " .. tostring(err))
--		end
--	end
-- > [ ADD SIMPLE AMBUSH END ]:

	if not Context.SpawnWait.CooldownTimer then
		if not Context.SpawnWait.WaitTimer then
			if BotApi.Commands:CanSpawn() then
				if spawningUnit then
					if OnUnitPurchased then OnUnitPurchased() elseif enableWaveCounter then WaveUnitCounter() end
					KillSpawnWaitTimer()
					Context.SpawnInfo = nil
					SetSpawnCooldownTimer()
					spawningUnit = nil
				else
					local retryPendingUnit = Context.SpawnWait.RetryPendingUnit
					Context.SpawnWait.RetryPendingUnit = false
					if not retryPendingUnit or not Context.SpawnInfo then
						UpdateUnitToSpawn(Context.Purchase)
					end
					if Context.SpawnInfo then
						local unit = Context.SpawnInfo.unit
						if BotApi.Commands:IsUnitAvailable(unit) then
							if GameModeSpawnUnit(unit, MaxSquadSize) then
								spawningUnit = true
							else
								local currentUnitSpawnWaitTime = GetCurrentSpawnWaitTime()
								local tts = BotApi.Commands:TimeToSpawnUnit(unit)
								local min_tts = GetUnitSelectionTTSLimit()
								if tts > min_tts then
									KillSpawnWaitTimer()
									Context.SpawnInfo = nil
								else
									if retryPendingUnit then Context.SpawnInfo = nil end
									if not Context.SpawnWait.WaitTimer then
										if printDebug then
											print("Print: player#".. BotApi.Instance.playerId .." tried to purchase: ".. unit .." Not enough MP, DP, CP, or the unit timer is not unlocked")
											print("Print: player#".. BotApi.Instance.playerId .." will wait a maximum of ".. (currentUnitSpawnWaitTime / 1000 + 1) .."s for resources or unit timer before it attempts a new unit purchase")
										end
										Context.SpawnWait.WaitTimer = BotApi.Events:SetQuantTimer(
											function()
												Context.SpawnWait.WaitTimer = nil
												Context.SpawnWait.RetryPendingUnit = Context.SpawnInfo ~= nil
											end, currentUnitSpawnWaitTime + 1000)
									end
								end
							end
						else
							KillSpawnWaitTimer()
							Context.SpawnInfo = nil
						end
					end
				end
			end
		end
	end

	local waypoints = BotApi.Scene.Waypoints
	if #waypoints == 0 then
		local activeTimers = 0
		for _, timer in pairs(Context.SquadTimers) do
			if timer then activeTimers = activeTimers + 1 end
		end
		if activeTimers < 20 then
			for i, squad in pairs(BotApi.Scene.Squads) do
				if not IsReservedArtillerySquad(squad) and not Context.SquadTimers[squad] then
					-- Пропускаем отряды, которые должны игнорироваться скриптом
					if not IsSquadInScript(squad) and not IsSquadToIgnore(squad) then
						SetSquadOrder(CaptureFlag, squad, OrderRotationPeriod)
					end
				end
			end
		end
	end
	
-- < [ ARm WEATHER CONTROLLER UPDATE ]:
	WeatherController.update()
-- > [ ARm WEATHER CONTROLLER UPDATE ]
	
end

function IsSquadInScript(squad)
	if IsReservedArtillerySquad(squad) then return true end
	if BotApi.Scene:IsSquadTagged(squad, "turret_brake") or
	   BotApi.Scene:IsSquadTagged(squad, "gun_brake") or
	   BotApi.Scene:IsSquadTagged(squad, "ai_lunge_mine_busy") or
	   BotApi.Scene:IsSquadTagged(squad, "i_see_you") then
		if printDebug then print("[ARM] Print: SQUADinSCRIPT thus no action squad", squad, "Player#", BotApi.Instance.playerId, "Team", team) end
		return true
	end
	if BotApi.Scene:IsSquadTagged(squad, "_lua_mi") or BotApi.Scene:IsSquadTagged(squad, "repairing") then
		if printDebug then print("[ARM] Print: SQUADinSCRIPT thus no action squad", squad, "Player#",BotApi.Instance.playerId, "Team", team) end
		return true
	elseif BotApi.Scene:IsSquadTagged(squad, "_lua_alert") then
	--  spam off
	--	if printDebug then print("[ARM] Print: SQUADinALERT thus seek by squad", squad, "Player#",BotApi.Instance.playerId, "Team", team) end
		BotApi.Commands:SeekAndDestroy(squad)
		return true
	end
	return false
end

function IsSquadToIgnore(squad)
	if BotApi.Scene:IsSquadTagged(squad, "_lua_ignore") then return true end
end

function CaptureFlag(squad)
	if not BotApi.Scene:IsSquadExists(squad) then
		if printDebug then print("[ARM] CaptureFlag: Squad " .. squad .. " does not exist, skipping") end
		return
	end
	if IsSquadInScript(squad) then return end
	if IsSquadToIgnore(squad) then
		local rndAI = math.random()
		if searchDestroy and searchDestroy > rndAI then
			if printDebug then print("[ARM] Print: [see_enemy] seek by squad ", squad, "Player#", BotApi.Instance.playerId) end
			BotApi.Commands:SeekAndDestroy(squad)
			return
		else
			if printDebug then print("[ARM] Print: [see_enemy] donothing by squad ", squad, "Player#", BotApi.Instance.playerId) end
			return
		end
	end
	if botDefender then
		local flags = {}
		for i, flag in pairs(BotApi.Scene.Flags) do
			table.insert(flags, {id = i, name = flag.name, priority = getDefaultFlagPriority(flag), owner = flag.occupant})
		end
		local flag = GetFlagToCapture(BotApi.Scene.Flags, getDefaultFlagPriority, flags)
		if not flag then
			if printDebug then print("[ARM] Print: No Flags so SeekAndDestroy by squad ", squad, "Player#", BotApi.Instance.playerId) end
			BotApi.Commands:SeekAndDestroy(squad)
			StuckManager.unregisterSquad(squad)
			return
		end
		if printDebug then print("[ARM] Print: [notags] ctf by squad", squad, "Player#", BotApi.Instance.playerId, "Flag name: ", flag.name) end
		BotApi.Commands:CaptureFlag(squad, flag.name)
		StuckManager.registerSquad(squad, flag.name)
		return
	else
		-- Атакующий без TargetManager – временно SeekAndDestroy (позже заменим на TargetManager)
		if printDebug then print("[ARM] (Flag attack): TargetManager disabled, SeekAndDestroy for squad " .. squad) end
		BotApi.Commands:SeekAndDestroy(squad)
		StuckManager.unregisterSquad(squad)
	end
end

-- < [ DOCTRINE MODIFIERS START ]: общий расчёт приоритета юнита
-- Учитывает базовый priority, множители Squad/Cannon и доктринные модификаторы.
local function CalculateUnitPriority(unit)
	local priority = unit.priority or 1
	local function UnitType(val)
		if not unit.type then return false end
		for _, v in ipairs(unit.type) do
			if v == val then return true end
		end
		return false
	end
	if UnitType("Squad") then priority = priority * 1.75 end
	if UnitType("Cannon") then priority = priority * 0.80 end
	if not botDefender and Doctrine and Doctrine.getPriorityModifier then
		priority = priority * Doctrine.getPriorityModifier(unit)
	end
	return priority
end
-- > [ DOCTRINE MODIFIERS END ]

function GetUnitToSpawn(units)
	-- [DISABLED] Проверка состояния амбуша (AmbushEventState) временно отключена
	-- if AmbushEventState.relocating or AmbushEventState.spawning or AmbushEventState.restoring then return nil end
	if not units then return nil end
	local income = BotApi.Commands:Income(BotApi.Instance.playerId)
	local function collectUnits(additionalFilter)
		local result = {}
		for _, unit in pairs(units) do
			local min_team = unit.min_team or 0
			local min_income = unit.min_income or -1
			local available = BotApi.Commands:IsUnitAvailable(unit.unit)
			local allowed = UnitLimiter.isUnitAvailable(unit) and
							UnitFilter.isUnitAllowed(unit, botDefender) and
							teamSize >= min_team and income >= min_income and available and
							(botDefender or Doctrine.isUnitAllowed(unit, botDefender))
			if allowed and (additionalFilter == nil or additionalFilter(unit)) then
				table.insert(result, unit)
			end
		end
		return result
	end

	if TankInfantryRatio.isInfantryPriority() then
		-- < [ TIERS START ]: перебор уровней пехоты сверху вниз
		local tiers = TankInfantryRatio.getInfantryTiers()
		for _, tagSet in ipairs(tiers) do
			-- [FIX] Локальный алиас для надёжности в Lua 5.1
			local currentTagSet = tagSet
			local tierUnits = collectUnits(function(u)
				for _, tag in ipairs(currentTagSet) do
					if not HasType(u, tag) then return false end
				end
				return true
			end)
			if #tierUnits > 0 then
				if printDebug then
					print(string.format("[ARM] (Tank-Infantry Balancer): tier matched [%s], units=%d",
						table.concat(currentTagSet, "+"), #tierUnits))
				end
				return GetRandomItem(tierUnits, CalculateUnitPriority)
			end
		end
		-- Fallback: если ни один уровень не дал результата
		local fallbackUnits = collectUnits(nil)
		if #fallbackUnits > 0 then
			if printDebug then
				print(string.format("[ARM] (Tank-Infantry Balancer): no tier matched, using fallback, units=%d", #fallbackUnits))
			end
			return GetRandomItem(fallbackUnits, CalculateUnitPriority)
		else
			if printDebug then print("[ARM] No units available for spawn after all filters") end
			return nil
		end
		-- > [ TIERS END ]
	end

	local allUnits = collectUnits(nil)
	if #allUnits == 0 then
		if printDebug then print("[ARM] No units available for spawn after filters") end
		return nil
	end
	return GetRandomItem(allUnits, CalculateUnitPriority)
end

function GetCurrentSpawnWaitTime()
	-- [DISABLED] Проверка амбуша (AmbushEventState.spawning) временно отключена
	-- if AmbushEventState.spawning then return 5 * 1000 end
	return UnitSpawnWaitTime
end

function OnGameStart()
    -- < [ FIX ]: Принудительный сброс переменных для триггера амбуша
    SetSceneVar("simple_ambush_triggered", 0)
    SetSceneVar("simple_ambush_spawned", 0)
    if printDebug then print("[ARM] (Modules Init): Reset simple_ambush_triggered and simple_ambush_spawned to 0") end
    -- > [ FIX ]
	
    if printDebug then print("[ARm] (Modules Init): === STARTING MODULE INITIALIZATION ===") end

    -- < [ MODULES INIT LOG ]: UnitLimiter
    UnitLimiter.init()
    if printDebug then print("[ARm] (Modules Init): UnitLimiter initialized") end

    -- < [ MODULES INIT LOG ]: Multiplier
    Multiplier.reset()
    if printDebug then print("[ARm] (Modules Init): Multiplier reset") end

    -- < [ MODULES INIT LOG ]: botDefender + Doctrine
    isAttackerOrDefender()
    if not botDefender then
        Doctrine.selectDoctrine()
        if printDebug then
            print("[ARm] (Modules Init): Doctrine selected: " .. Doctrine.getDoctrineName())
        end
    else
        if printDebug then print("[ARm] (Modules Init): Bot is defender, doctrine disabled") end
    end
    if printDebug then print("[ARm] (Modules Init): botDefender = " .. tostring(botDefender)) end

    -- < [ MODULES INIT LOG ]: Defense level
    local defenseLevel = BotApi.Scene:GetVar("defense_level") or 1
    if defenseLevel < 1 then defenseLevel = 1 end
    if defenseLevel > 3 then defenseLevel = 3 end
    currentBattleNumber = defenseLevel
    if printDebug then
        print("[ARm] (WAve): Defense level obtained: " .. defenseLevel)
        print(string.format("[ARm] (WAve): Using defenseLevel as battle proxy: %d", currentBattleNumber))
    end

    PendingArtillerySpawnTag = false
    PendingArtillerySpawnUnit = nil
    SetSceneVar("prep_inform", 0)
    SetSceneVar("ai_artillery_engaged", 0)
    SetSceneVar("ai_artillery_tag_request", 0)
    SetSceneVar("ai_artillery_tag_busy", 0)
    SetSceneVar("ai_artillery_on", 0)
    SetSceneVar("ai_artillery_loop_busy", 0)
    -- [DISABLED] Переменные амбуша (временно закомментированы)
    -- SetSceneVar("ai_ambush_warning_request", 0)
    -- SetSceneVar("ai_ambush_active", 0)
    -- SetSceneVar("ai_ambush_done", 0)
    -- SetSceneVar("ai_ambush_spawned", 0)
    -- SetSceneVar("ai_ambush_relocate_request", 0)
    -- SetSceneVar("ai_ambush_spawn_ready", 0)
    -- SetSceneVar("ai_ambush_restore_request", 0)
    -- SetSceneVar("ai_ambush_restore_done", 0)
    setVarsInMissionScript()
    
    -- < [ WEATHER CONTROLLER INIT ]:
    local status, err = pcall(WeatherController.init, Config.Weather)
    if not status then
        if printDebug then print("[ARM] WeatherController init error: " .. tostring(err)) end
    else
        if printDebug then print("[ARM] WeatherController initialized") end
    end
    -- > [ WEATHER CONTROLLER INIT ]

    waveUnitTotal = RollWaveUnitTotal()
    if printDebug then
        print("[ARM] Print: difficulty =", tostring(GetBotDifficultyKey()))
        print("[ARM] Print: waveUnitTotal", waveUnitTotal)
    end
    BotApi.Events:SetQuantTimer(function()
        if ARm_ReduceAircraft then ARm_ReduceAircraft() end
        if ARm_ZeroPrototypes then ARm_ZeroPrototypes() end
    end, 2000)
    
    -- [ MODULES INIT LOG ]: Загрузка покупок и OnGameStartUtility
    OnGameStartUtility("conquest")
    if printDebug then print("[ARm] (Modules Init): OnGameStartUtility completed, purchases loaded") end

    -- [ MODULES INIT LOG ]: TankInfantryRatio
    TankInfantryRatio.init()
    if printDebug then print("[ARm] (Modules Init): TankInfantryRatio initialized") end

    -- [ MODULES INIT LOG ]: TargetManager (отключён)
    -- TargetManager.init() – отключено
    if printDebug then print("[ARm] (Modules Init): TargetManager is disabled") end

    -- [ MODULES INIT LOG ]: StuckManager
    StuckManager.init(Config.Stuck)
    if printDebug then print("[ARm] (Modules Init): StuckManager initialized (enabled=" .. tostring(Config.Stuck.enabled) .. ")") end

    -- [ MODULES INIT LOG ]: SimpleAmbush
--	local status, err = pcall(SimpleAmbush.init, Config.SimpleAmbush)
--	if not status then
--		if printDebug then print("[ARM] Error in SimpleAmbush.init: " .. tostring(err)) end
--	else
--		if printDebug then print("[ARm] (Modules Init): SimpleAmbush initialized (enabled=" .. tostring(Config.SimpleAmbush.enabled) .. ")") end
--	end

    -- < [ ARm STAGE CALCULATOR ]:
    local status, err = pcall(StageCalculator.calc_war_stage)
    if not status then
        if printDebug then print("[ARM] StageCalculator error: " .. tostring(err)) end
    else
        if printDebug then print("[ARm] (Stages): war_stage$ calculated at game start") end
    end
    -- > [ ARm STAGE CALCULATOR ]

    -- [FIX] Перенесено: печатается после всех модулей, включая StageCalculator
    if printDebug then print("[ARm] (Modules Init): === ALL MODULES INITIALIZED ===") end
end

function OnGameStop()
	KillSpawnCooldownTimer()
	KillSpawnWaitTimer()
	Multiplier.reset()
	for squad, timer in pairs(Context.SquadTimers) do
		if timer then BotApi.Events:KillQuantTimer(timer) end
	end
	-- < [ STUCK MANAGER START ]: Сброс состояния при остановке игры
	StuckManager.init(Config.Stuck)  -- сбрасывает хранилище
	-- > [ STUCK MANAGER END ]

	-- < [ ARm CLEAR STAGE TAGS ]:
	pcall(StageCalculator.clear_stage_tags)
	-- > [ ARm CLEAR STAGE TAGS ]
	
	-- < [ WEATHER CONTROLLER STOP ]:
	pcall(WeatherController.stopCycle)
	-- > [ WEATHER CONTROLLER STOP ]
end

function OnGameSpawn(args)
    local squad = args.squadId
    if not BotApi.Scene:IsSquadExists(squad) then return end

    -- Пропускаем отряды, которые должны игнорироваться скриптом
    if IsSquadInScript(squad) or IsSquadToIgnore(squad) then
        return
    end

    local waypoints = BotApi.Scene.Waypoints
    if #waypoints == 0 then
        SetSquadOrder(CaptureFlag, squad, OrderRotationPeriod)
        -- Регистрация произойдёт внутри CaptureFlag при выдаче команды
    else
        GotoNextWaypoint(squad)
        StuckManager.unregisterSquad(squad)
    end
end

function OnPrepTimeOver()
	BotApi.Scene:SetVar("prep_inform", 1)
	if printDebug then print("[ARM] Print: prep_inform set to 1, Player defense prep is over.") end
end

BotApi.Events:Subscribe(BotApi.Events.GameStart, OnGameStart)
BotApi.Events:Subscribe(BotApi.Events.GameEnd, OnGameStop)
BotApi.Events:Subscribe(BotApi.Events.Quant, OnGameQuant)
BotApi.Events:Subscribe(BotApi.Events.GameSpawn, OnGameSpawn)
BotApi.Events:Subscribe(BotApi.Events.Waypoint, OnWaypoint)
BotApi.Events:Subscribe(BotApi.Events.PrepTimeOver, OnPrepTimeOver)