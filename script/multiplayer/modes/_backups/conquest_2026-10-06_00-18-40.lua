print("[ARM] bootstrap: conquest.lua reached")
-- [ ROLLED BACK 2026-09-26 ] log_filter require removed: dev C++ log noise is not reachable from Lua print override (log remained 3545 Localization lines).
-- =========================================================
-- CONQUEST V2 - THIN WRAPPER
-- =========================================================
-- Requires all conquest/* modules and wires up events.
-- Replaces the monolithic conquest.lua (37495 b).
-- See KB sections: staging_prepared, migration_hooks, preflight_done.

require([[/script/multiplayer/modes/utility]])

-- [ ARM MODULES ]
local UnitFilter         = require([[/script/multiplayer/modes/conquest_type_filter]])
local UnitLimiter        = require([[/script/multiplayer/modes/conquest_limiter]])
local Doctrine           = require([[/script/multiplayer/modes/conquest_doctrine]])
local TankInfantryRatio  = require([[/script/multiplayer/modes/conquest_tank_infantry_ratio]])
local Multiplier         = require([[/script/multiplayer/modes/conquest_unit_multiplier]])
local StuckManager       = require([[/script/multiplayer/modes/conquest_stuck_manager]])
local Config             = require([[/script/multiplayer/modes/config]])

-- Patch modules (order matters: state/config first, then consumers)
require([[/script/multiplayer/modes/conquest/runtime_state]])
require([[/script/multiplayer/modes/conquest/runtime_config]])
require([[/script/multiplayer/modes/conquest/runtime_context]])
require([[/script/multiplayer/modes/conquest/scene]])
require([[/script/multiplayer/modes/conquest/scene_memory]])
require([[/script/multiplayer/modes/conquest/combat_pressure]])
require([[/script/multiplayer/modes/conquest/purchase_pressure]])
require([[/script/multiplayer/modes/conquest/purchase_scoring]])
require([[/script/multiplayer/modes/conquest/purchase_profiles]])
require([[/script/multiplayer/modes/conquest/orders_flags]])
require([[/script/multiplayer/modes/conquest/orders]])
require([[/script/multiplayer/modes/conquest/battle_result]])
require([[/script/multiplayer/modes/conquest/attacker_pressure]])
require([[/script/multiplayer/modes/conquest/attacker_wave_off]])
require([[/script/multiplayer/modes/conquest/attacker_failure]])
require([[/script/multiplayer/modes/conquest/defender_counterattack]])
require([[/script/multiplayer/modes/conquest/waves]])
require([[/script/multiplayer/modes/conquest/purchase]])

-- [ ARM PUBLISH ] Config overrides -> ConquestConfig (see config.PublishOverrides)
Config.PublishOverrides()

-- [ ARM BRIDGE B ] publish OperationDay to B via scene var b_operation_day
local BBridge = require([[/script/multiplayer/modes/b_battle_bridge]])
BBridge.init()

botDefender  = false   -- GLOBAL: conquest_stuck_manager.lua reads this (TRAP #20)
spawningUnit = false

local _patch_GetUnitToSpawn = GetUnitToSpawn   -- TRAP #21
-- ============================================================
-- [ ARM HOOK GetUnitToSpawn ]
-- ============================================================
local function HasType(unitInfo, wanted)
if not unitInfo or not unitInfo.type then return false end
for _, v in ipairs(unitInfo.type) do
if v == wanted then return true end
end
return false
end

local function CalculateUnitPriority(unit)
local priority = unit.priority or 1
if HasType(unit, "Squad")  then priority = priority * 1.75 end
if HasType(unit, "Cannon") then priority = priority * 0.80 end
if not botDefender and Doctrine.getPriorityModifier then
priority = priority * Doctrine.getPriorityModifier(unit)
end
return priority
end

function GetUnitToSpawn(units)
if not units then return nil end

local income = BotApi.Commands:Income(BotApi.Instance.playerId)
local filtered = {}

for _, unit in pairs(units) do
local min_team   = unit.min_team or 0
local min_income = unit.min_income or -1
local ok = BotApi.Commands:IsUnitAvailable(unit.unit)
and UnitLimiter.isUnitAvailable(unit)
and UnitFilter.isUnitAllowed(unit, botDefender)
and teamSize >= min_team
and income   >= min_income
and (botDefender or Doctrine.isUnitAllowed(unit, botDefender))
if ok then table.insert(filtered, unit) end
end

if #filtered == 0 then
if printDebug then print("[ARM] GetUnitToSpawn: no units after filters") end
return nil
end

if TankInfantryRatio.isInfantryPriority() then
local tiers = TankInfantryRatio.getInfantryTiers()
for _, tagSet in ipairs(tiers) do
local currentTagSet = tagSet
local tierUnits = {}
for _, u in ipairs(filtered) do
local match = true
for _, tag in ipairs(currentTagSet) do
if not HasType(u, tag) then match = false break end
end
if match then table.insert(tierUnits, u) end
end
if #tierUnits > 0 then
if printDebug then
print(string.format("[ARM] (Tank-Infantry Balancer): tier matched [%s], units=%d",
table.concat(currentTagSet, "+"), #tierUnits))
end
return GetRandomItem(tierUnits, CalculateUnitPriority)
end
end
end

return _patch_GetUnitToSpawn(filtered)
end
-- ============================================================
-- EVENT HANDLERS
-- ============================================================
function OnGameStart()
	ConquestState.battleStartTime = os.time()
if printDebug then print("[ARM] (Init): === conquest_v2 OnGameStart ===") end

if BotApi.Conquest and BotApi.Conquest.Attacking then
botDefender = false
else
botDefender = true
end
ConquestState.botDefender = botDefender
if printDebug then print("[ARM] (Init): botDefender = " .. tostring(botDefender)) end

UnitLimiter.init()
Multiplier.reset()

if not botDefender then
Doctrine.selectDoctrine()
if printDebug then
print("[ARM] (Init): Doctrine = " .. Doctrine.getDoctrineName())
end
else
if printDebug then print("[ARM] (Init): bot is defender, doctrine disabled") end
end

TankInfantryRatio.init()
StuckManager.init(Config.Stuck)

ConquestPurchaseProfiles.InitializeBattleForce()

ConquestContext.SetVarsInMissionScript()

OnGameStartUtility("conquest")

if printDebug then print("[ARM] (Init): === ALL MODULES INITIALIZED ===") end
  -- [ ARM ADDONS ] lair / np (optional, v2-adapted)
  if ARm_ReduceAircraft then ARm_ReduceAircraft() end
  if ARm_ZeroPrototypes  then ARm_ZeroPrototypes()  end
end

function OnGameStop()
KillSpawnCooldownTimer()
KillSpawnWaitTimer()
Multiplier.reset()
for squad, timer in pairs(Context.SquadTimers) do
if timer then BotApi.Events:KillQuantTimer(timer) end
end
StuckManager.init(Config.Stuck)
end
local _brLastCheck = 0
function OnGameQuant()
    -- ITEM 3: mission-side game-over polling (once per second, fallback to WinnerDecided)
    if ConquestBattleResult and ConquestBattleResult.CheckGameOverRequestVars then
        local _now = os.time()
        if _now ~= _brLastCheck then
            _brLastCheck = _now
            pcall(ConquestBattleResult.CheckGameOverRequestVars)
        end
    end
if not botDefender then
local ok, err = pcall(StuckManager.update)
if not ok and printDebug then
print("[ARM] Error in StuckManager.update: " .. tostring(err))
end
end

if ConquestDefenderCounterattack then
pcall(ConquestDefenderCounterattack.UpdateFlagOwnership)
end

if ConquestWaves.UpdateDefenderOpeningCutoff then
ConquestWaves.UpdateDefenderOpeningCutoff()
end

-- Spawn loop (utility.lua TrySpawnUnit is disabled)
if not Context.SpawnWait.CooldownTimer then
if not Context.SpawnWait.WaitTimer then
if BotApi.Commands:CanSpawn() then
if spawningUnit then
if OnUnitPurchased then OnUnitPurchased() end
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
                        -- [ FIX 2026-09-27 ] engine refused spawn; reset mult queue
                        -- so bot is not stuck in 5-min production cooldown
                        -- [ FIX 2026-10-03 ] aircraft: engine production cooldown, keep mult queue
						local _isAir = false
						local _src = Context.SpawnInfo
						if _src and _src.type then
							for _, _t in ipairs(_src.type) do
								if string.lower(_t) == "aircraft" then _isAir = true; break end
							end
						end
						if not _isAir and _src and _src.base then
							for _, _t in ipairs(_src.base) do
								if string.lower(_t) == "aircraft" then _isAir = true; break end
							end
						end
                        if not _isAir then
                            Multiplier.reset()
                        Context.SpawnInfo = nil  -- also drop pending unit, don't retry same
                        end
                        local waitTime = GetCurrentSpawnWaitTime()
local tts     = BotApi.Commands:TimeToSpawnUnit(unit)
local min_tts = GetUnitSelectionTTSLimit()
if tts > min_tts then
KillSpawnWaitTimer()
Context.SpawnInfo = nil
else
if retryPendingUnit then Context.SpawnInfo = nil end
if not Context.SpawnWait.WaitTimer then
Context.SpawnWait.WaitTimer = BotApi.Events:SetQuantTimer(
function()
Context.SpawnWait.WaitTimer = nil
Context.SpawnWait.RetryPendingUnit = Context.SpawnInfo ~= nil
end, waitTime + 1000)
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

-- Squad orders for waypoint maps
local waypoints = BotApi.Scene.Waypoints
if #waypoints == 0 then
local activeTimers = 0
for _, timer in pairs(Context.SquadTimers) do
if timer then activeTimers = activeTimers + 1 end
end
if activeTimers < 20 then
for _, squad in pairs(BotApi.Scene.Squads) do
if not Context.SquadTimers[squad] then
if not IsSquadInScript(squad) and not IsSquadToIgnore(squad) then
SetSquadOrder(CaptureFlag, squad, Config.OrderRotationPeriod)
end
end
end
end
end
end
function OnGameSpawn(args)
local squad = args.squadId
if not BotApi.Scene:IsSquadExists(squad) then return end
if IsSquadInScript(squad) or IsSquadToIgnore(squad) then return end

local waypoints = BotApi.Scene.Waypoints
if #waypoints == 0 then
SetSquadOrder(CaptureFlag, squad, Config.OrderRotationPeriod)
else
GotoNextWaypoint(squad)
StuckManager.unregisterSquad(squad)
end
end

function OnPrepTimeOver()
BotApi.Scene:SetVar("prep_inform", 1)
if printDebug then print("[ARM] prep_inform set to 1") end
end

BotApi.Events:Subscribe(BotApi.Events.GameStart,    OnGameStart)
BotApi.Events:Subscribe(BotApi.Events.GameEnd,      OnGameStop)
BotApi.Events:Subscribe(BotApi.Events.Quant,        OnGameQuant)
BotApi.Events:Subscribe(BotApi.Events.GameSpawn,    OnGameSpawn)
BotApi.Events:Subscribe(BotApi.Events.Waypoint,     OnWaypoint)
BotApi.Events:Subscribe(BotApi.Events.PrepTimeOver, OnPrepTimeOver)

-- ITEM 3: WinnerDecided subscription (with guard; polling fallback in OnGameQuant)
if BotApi.Events.WinnerDecided and ConquestBattleResult and ConquestBattleResult.OnWinnerDecided then
    BotApi.Events:Subscribe(BotApi.Events.WinnerDecided, ConquestBattleResult.OnWinnerDecided)
end
-- ============================================================
-- [ ARM HOOK OnUnitPurchased ] - TRAP #23
-- ============================================================
-- waves.lua определил OnUnitPurchased (только счётчик фазы).
-- Сохраняем его и оборачиваем, чтобы дёргать хуки ARM-модулей
-- (UnitLimiter / TankInfantryRatio / Multiplier), которые в
-- монолите conquest.lua вызывались вручную.
local _patch_OnUnitPurchased = OnUnitPurchased

function OnUnitPurchased()
local spawnInfo = Context and Context.SpawnInfo

if spawnInfo and spawnInfo.unit then
UnitLimiter.onUnitSpawned(spawnInfo)
TankInfantryRatio.onUnitSpawned(spawnInfo)
if TankInfantryRatio.isTank(spawnInfo) then
TankInfantryRatio.onTankSpawned()
end
Multiplier.onUnitSpawned(spawnInfo)
end

if _patch_OnUnitPurchased then
_patch_OnUnitPurchased()
end
end