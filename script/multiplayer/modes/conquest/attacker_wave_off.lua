-- =========================================================
-- ATTACKER WAVE-OFF CONTROLLER
-- =========================================================
-- Controls dynamic delay between completed attacker waves.
-- Attacker pressure measurement lives in attacker_pressure.lua.

ConquestAttackerWaveOff = ConquestAttackerWaveOff or {}

-- Stores the bot-force snapshot taken before an attacker wave starts buying.
function ConquestAttackerWaveOff.CapturePreWaveSnapshot()
	ConquestAttackerPressure.CapturePreWaveSnapshot()
end

-- Stores the bot-force snapshot taken after an attacker wave finishes buying.
function ConquestAttackerWaveOff.CapturePostWaveSnapshot()
	ConquestAttackerPressure.CapturePostWaveSnapshot()
end

-- Builds current-vs-post-wave pressure details for attacker wave-off decisions.
function ConquestAttackerWaveOff.GetCurrentPressureDetails()
	return ConquestAttackerPressure.GetCurrentSnapshot()
end

-- Rolls small +/- timing variance so wave release timing is not perfectly predictable.
local function RollRandomVarianceSeconds()
	local variance = ConquestConfig.AttackerDynamicWaveOff.RandomVarianceSeconds or 0

	if variance <= 0 then
		return 0
	end

	return math.random(-variance, variance)
end

-- Returns the one random variance roll assigned to the current wave-off window.
local function GetWaveOffVarianceSeconds()
	if not ConquestState.attackerWaveOffVarianceSeconds then
		ConquestState.attackerWaveOffVarianceSeconds = 0
	end

	return ConquestState.attackerWaveOffVarianceSeconds
end

-- Returns day-scale factor for the current operation day.
-- Picks the largest key <= OperationDay from AttackerWaveOffDayScale.
local function GetDayScale()
	local tbl = ConquestConfig.AttackerWaveOffDayScale
	if not tbl then
		return 1.0
	end

	local day = (BotApi.Conquest and BotApi.Conquest.OperationDay) or 1
	local bestKey = -1
	local scale = 1.0

	for k, v in pairs(tbl) do
		if day >= k and k > bestKey then
			bestKey = k
			scale = v
		end
	end

	return scale
end

-- Calculates the target wave-off time from current pressure details.
function ConquestAttackerWaveOff.GetTargetWaveOffSeconds(details)
	local config = ConquestConfig.AttackerDynamicWaveOff

	if not details then
		return config.ForceReleaseSeconds
	end

	local attacker = details.attacker
	local objective = details.objective

	local difficultyKey = (BotApi.Instance and BotApi.Instance.difficulty) or "hard"
	local baseByDiff = ConquestConfig.AttackerWaveOffBaseByDifficulty or {}
	local row = baseByDiff[difficultyKey] or baseByDiff.hard or { Min = 135, Mid = 150, Max = 165 }

	local pressureBase
	if attacker.pressureLevel == "degraded" then
		pressureBase = row.Min
	elseif attacker.pressureLevel == "retained" then
		pressureBase = row.Max
	else
		pressureBase = row.Mid
	end

	local objectiveDelta =
		config.ObjectiveProgressSecondsDelta[objective.progressTag]
		or 0

	local dayScale = GetDayScale()
	local varianceSeconds = GetWaveOffVarianceSeconds()
	local scaledBase = math.floor((pressureBase + objectiveDelta) * dayScale + 0.5)
	local total = scaledBase + varianceSeconds

	if printDebug then
		print("[ARm] (Waves): components",
			"difficulty=", difficultyKey,
			"pressure=", attacker.pressureLevel,
			"objective=", objective.progressTag,
			"pressureBase=", pressureBase,
			"objectiveDelta=", objectiveDelta,
			"day=", (BotApi.Conquest and BotApi.Conquest.OperationDay) or 1,
			"dayScale=", dayScale,
			"variance=", varianceSeconds,
			"targetTotal=", total,
			"forceRelease=", config.ForceReleaseSeconds)
	end

	return total
end

local function GetFixedCooldown(seconds, shouldHoldWave)
	local milliseconds = seconds * 1000

	return milliseconds, milliseconds, shouldHoldWave
end

local function IsFirstWaveOffCheck()
	return ConquestState.attackerWaveOffElapsedSeconds <= 0
end

local function ScheduleFirstWaveOffCheck()
	local config = ConquestConfig.AttackerDynamicWaveOff

	ConquestState.attackerWaveOffElapsedSeconds = config.FirstCheckSeconds
	ConquestState.attackerWaveOffVarianceSeconds = RollRandomVarianceSeconds()

	if printDebug then
		print(
			"Print: attacker wave-off first check scheduled",
			"elapsed=", ConquestState.attackerWaveOffElapsedSeconds,
			"variance=", ConquestState.attackerWaveOffVarianceSeconds
		)
	end

	return GetFixedCooldown(config.FirstCheckSeconds, true)
end

local function BuildWaveOffContext()
	local config = ConquestConfig.AttackerDynamicWaveOff
	local details = ConquestAttackerWaveOff.GetCurrentPressureDetails()
	local targetWaveOffSeconds = ConquestAttackerWaveOff.GetTargetWaveOffSeconds(details)

	ConquestState.attackerWaveOffTargetSeconds = targetWaveOffSeconds
	ConquestAttackerWaveOff.PrintCurrentPressureDetails(details, targetWaveOffSeconds)

	return {
		config = config,
		details = details,
		targetWaveOffSeconds = targetWaveOffSeconds,
	}
end

local function ShouldForceRelease(context)
	return ConquestState.attackerWaveOffElapsedSeconds >= context.config.ForceReleaseSeconds
end

local function ShouldReleaseByTarget(context)
	return ConquestState.attackerWaveOffElapsedSeconds >= context.targetWaveOffSeconds
end

local function ReleaseWaveOff(reason, context)
	ConquestState.attackerWaveOffReleaseReady = true

	if printDebug then
		if reason == "force release" then
			print(
				"Print: attacker wave-off force release",
				"elapsed=", ConquestState.attackerWaveOffElapsedSeconds,
				"forceRelease=", context.config.ForceReleaseSeconds
			)
		else
			print(
				"Print: attacker wave-off target reached",
				"elapsed=", ConquestState.attackerWaveOffElapsedSeconds,
				"target=", context.targetWaveOffSeconds
			)
		end
	end

	return GetFixedCooldown(1, false)
end

local function HoldWaveOff(context)
	local elapsedBeforeHold = ConquestState.attackerWaveOffElapsedSeconds
	local remainingSeconds = context.targetWaveOffSeconds - elapsedBeforeHold
	local nextCheckSeconds = math.min(context.config.RepeatPollIntervalSeconds, remainingSeconds)

	ConquestState.attackerWaveOffElapsedSeconds =
		ConquestState.attackerWaveOffElapsedSeconds + nextCheckSeconds

	if printDebug then
		print(
			"Print: attacker wave-off holding",
			"elapsed=", elapsedBeforeHold,
			"nextElapsed=", ConquestState.attackerWaveOffElapsedSeconds,
			"target=", context.targetWaveOffSeconds,
			"nextCheck=", nextCheckSeconds
		)
	end

	return GetFixedCooldown(nextCheckSeconds, true)
end

-- Returns the next attacker wave-off cooldown range and whether the next wave should stay held.
function ConquestAttackerWaveOff.GetNextCooldown()
	if IsFirstWaveOffCheck() then
		if printDebug then print("[ARm] (Waves): branch=first_check") end
		return ScheduleFirstWaveOffCheck()
	end

	local context = BuildWaveOffContext()

	if ShouldForceRelease(context) then
		if printDebug then print("[ARm] (Waves): branch=force_release") end
		return ReleaseWaveOff("force release", context)
	end

	if ShouldReleaseByTarget(context) then
		if printDebug then print("[ARm] (Waves): branch=target_reached") end
		return ReleaseWaveOff("target reached", context)
	end

	if printDebug then print("[ARm] (Waves): branch=hold") end
	return HoldWaveOff(context)
end

-- Returns true when unit selection should defer to the wave-off controller instead of selecting a unit.
function ConquestAttackerWaveOff.ShouldDeferPurchaseForWaveOff()
	return not ConquestState.botDefender
		and not ConquestState.attackerWavesFinished
		and not ConquestState.waveSpawnActive
		and not ConquestState.purchasePhase
end

-- Resets attacker wave-off timing state before the next attacker wave starts.
function ConquestAttackerWaveOff.ResetCooldown()
	ConquestState.attackerWaveOffElapsedSeconds = 0
	ConquestState.attackerWaveOffTargetSeconds = 0
	ConquestState.attackerWaveOffVarianceSeconds = 0
	ConquestState.attackerWaveOffPlayerPeakComposition = nil
	ConquestState.attackerWaveOffReleaseReady = false
end

-- Prints current wave-off pressure details when printDebug is enabled.
function ConquestAttackerWaveOff.PrintCurrentPressureDetails(details, targetWaveOffSeconds)
	if not printDebug or not details then
		return
	end

	local attacker = details.attacker
	local player = details.player
	local objective = details.objective

	targetWaveOffSeconds = targetWaveOffSeconds or ConquestAttackerWaveOff.GetTargetWaveOffSeconds(details)

	print(
		"Print: attacker wave-off pressure",
		"attackerPressure=", attacker.pressureLevel,
		"objective=", objective.progressTag,
		"targetWaveOffSeconds=", targetWaveOffSeconds,
		"baseline=", attacker.baselineSource,
		"waveInfantryRatioRaw=", attacker.waveInfantryRatioRaw,
		"waveInfantryRatio=", attacker.waveInfantryRatio,
		"wavePressureScore=", attacker.wavePressureScore,
		"wavePressureBaselineScore=", attacker.wavePressureBaselineScore,
		"wavePressureRatioRaw=", attacker.wavePressureRatioRaw,
		"wavePressureRatio=", attacker.wavePressureRatio,
		"componentLossTags=", ConquestAttackerPressure.FormatTags(attacker.componentLossTags),
		"playerDefenseTags=", ConquestAttackerPressure.FormatTags(player.defenseTags),
		"playerInfantryRetention=", player.infantryRetention,
		"playerPressureScore=", player.pressureScore,
		"playerPeakPressureScore=", player.peakPressureScore,
		"playerPressureRetention=", player.pressureRetention
	)
end
