-- =========================================================
-- RUNTIME CONFIG
-- =========================================================
-- Core Conquest timing, purchase-count, and order constants.

ConquestConfig = ConquestConfig or {}

ConquestConfig.CombatPressureWeights = {
	Infantry = 1.0,
	Armor = 20.0,
	HeavyArmor = 30.0,
	SuperHeavyArmor = 40.0,
	MachineGun = 8.0,
	AutoCannon = 14.0,
	LightAT = 10.0,
	ATGun = 20.0,
	Flame = 15.0,
	MediumHE = 18.0,
	LargeHE = 30.0,
}

-- Infantry-equivalents for how much a unit can still bring to bear on taking ground, which is not what CombatPressureWeights asks.
-- Indirect fire scores low because it cannot hold ground; armor scores high because it can drive onto an objective.
ConquestConfig.AssaultWeights = {
	Infantry = 1.0,
	Crew = 0.0, -- Can capture, but too rarely to count.

	LightArmor = 8.0,
	MediumArmor = 12.0,
	HeavyArmor = 18.0,
	SuperHeavyArmor = 22.0,

	MachineGun = 2.0,
	AutoCannon = 3.0,
	LightAT = 3.0,
	ATGun = 5.0,
	Flame = 4.0,
	MediumHE = 3.0,
	LargeHE = 4.0,

	Engineer = 1.0, -- Capture-capable body the scene query keeps out of Infantry.
	AmmoSupply = 0.0,
}

-- Infantry-equivalents for how much defense the attacker has to get through, used to scale the bar.
-- Support weapons cannot be zero here: scene query buckets an HE-gun tank into MediumHE and an AA truck into MachineGun.
ConquestConfig.PlayerDefenseWeights = {
	Infantry = 1.0,
	Crew = 0.0, -- Lets a crew-only defender read 0 so HasPlayerDefense still fires.

	LightArmor = 6.0,
	MediumArmor = 10.0,
	HeavyArmor = 15.0,
	SuperHeavyArmor = 20.0,

	MachineGun = 4.0,
	AutoCannon = 6.0,
	LightAT = 3.0,
	ATGun = 8.0,
	Flame = 4.0,
	MediumHE = 6.0,
	LargeHE = 8.0,

	Engineer = 1.0,
	AmmoSupply = 0.0,
}

-- Time from match start before the AI attempts its first purchase.
ConquestConfig.StartSpawnTime = {
	-- Bot is defender.
	DefenseMin = 5 * 1000,
	DefenseMax = 10 * 1000,

	-- Bot is attacker.
	AttackMin = 1 * 1000,
	AttackMax = 1 * 1000,
}

-- Time from last purchase before the AI attempts another purchase.
ConquestConfig.SpawnCooldownTime = {
	-- [ REMOVED 2026-09-28: DCGWaveOffMin/Max. Superseded by
	--   M.Balance.AttackerWaveOffBaseByDifficulty. ]

	-- Time between purchases inside an active wave/opening.
	DCGMin = 2 * 1000,
	DCGMax = 2 * 1000,
}

-- Baseline attacker wave count and size. Later pressure modifiers can adjust
-- these targets after the baseline is rolled.
ConquestConfig.AttackerWaves = {
	MaxWavesMin = 4,
	MaxWavesMax = 5,

	AttackerByDifficulty = {
		easy   = { Min = 15, Max = 18 },
		normal = { Min = 17, Max = 20 },
		hard   = { Min = 19, Max = 22 },
		heroic = { Min = 21, Max = 24 },
	},

	Pattern = "flat",
	MinWaveUnits = 1,
}

-- Wave-shape multipliers used by AttackerWaves.Pattern.
ConquestConfig.AttackerWavePatterns = {
	flat = {
		First = 1.00,
		Middle = 1.00,
		Final = 1.00,
	},

	-- [ REMOVED 2026-09-28: escalating/frontloaded/last_push.
	--   Pattern = "flat" is the only active variant. ]
}

-- Dynamic delay between completed attacker waves.
-- Campaign pressure defines the allowed wait window; scene snapshot pressure later decides where inside that window the next wave releases.
-- Attacker wave-off day-scale. Multiply pressure-based base by this
-- factor (operation day -> scale). Lookup: largest key <= OperationDay.
-- Key 1=1939(1-4), 5=1940(5-6), 7=1941(7-8), 9=1942(9-10),
-- 11=1943(11-12), 13=1944(13-14), 15=1945(15-16), 17=1946+(17-99).
-- Attacker wave-off base by difficulty (seconds between waves).
-- pressure mapping: degraded=Min, reduced=Mid, retained=Max.
ConquestConfig.AttackerWaveOffBaseByDifficulty = {
		easy   = { Min = 150, Mid = 165, Max = 180 },
		normal = { Min = 135, Mid = 150, Max = 165 },
		hard   = { Min = 120, Mid = 135, Max = 150 },
		heroic = { Min = 105, Mid = 120, Max = 135 },
}

ConquestConfig.AttackerWaveOffDayScale = {
    [1]  = 1.00,  -- 1939
    [5]  = 1.00,  -- 1940
    [7]  = 0.97,  -- 1941
    [9]  = 0.93,  -- 1942
    [11] = 0.90,  -- 1943
    [13] = 0.87,  -- 1944
    [15] = 0.83,  -- 1945
    [17] = 0.80,  -- 1946+
}

ConquestConfig.AttackerDynamicWaveOff = {
	FirstCheckSeconds = 120, -- Earliest time after a wave finishes where scene-query can start checking whether the next wave should release.
	RepeatPollIntervalSeconds = 30, --  How often the controller re-checks whether the next wave should release.
	ForceReleaseSeconds = 300, -- Hard maximum wait before the next wave releases even if scene pressure says to keep holding.
	QueryIntervalSeconds = 15, --  Scene-query interval used by the wave-off controller.
	RandomVarianceSeconds = 10, -- Small +/- timing variation added to the calculated wave-off target so releases are not perfectly predictable.

	RetainedRatio = 0.80, -- Clamped pressure ratio where the current attacker force still counts as retained.
	DegradedRatio = 0.40, -- Clamped pressure ratio where earlier next-wave release may be justified.


	-- Target wave-off time based on current attacker pressure compared to the latest wave-added baseline.
	-- Lower values release the next wave sooner; higher values give existing pressure more time to work.
-- -- [[ ARCHIVED 2026-09-26 ]] disabled; superseded by
-- -- AttackerWaveOffBaseByDifficulty (config.lua) + AttackerWaveOffDayScale
-- -- (above). Kept for reference only.
-- 	WaveOffSecondsByAttackerState = {
-- 		degraded = 135, -- Previous attacker wave is heavily reduced; next wave can arrive sooner.
-- 		reduced = 165, -- Previous attacker wave is partially reduced; use a moderate wave-off.
-- 		retained = 210, -- Previous attacker wave is mostly intact; delay longer before adding more pressure.
-- 	},

	-- Adds/subtracts time based on attacker objective progress.
	-- Negative values release sooner; positive values delay longer.
	ObjectiveProgressSecondsDelta = {
		no_objective_progress = -15, -- Attacker has made no flag progress; apply more pressure sooner.
		objective_contested = 0, -- Attacker has neutralized/contested a flag but not captured one; keep baseline timing.
		objective_progress = 20, -- Attacker has captured at least one flag; delay slightly to avoid over-stacking pressure.
		all_objectives_taken = 40, -- Attacker owns all flags; delay more because the battle is already near completion.
	},
}

ConquestConfig.CompletedPurchaseIdleTime = {
	Min = 60 * 1000,
	Max = 60 * 1000,
}

ConquestConfig.DefenderOpeningByDifficulty = {
	easy   = { Min = 7,  Max = 11 },
	normal = { Min = 9,  Max = 13 },
	hard   = { Min = 11, Max = 15 },
	heroic = { Min = 13, Max = 17 },
}

ConquestConfig.DefenderOpening = {
	-- Defender opening purchase target is rolled per objective flag, then multiplied by flag count.
	-- Purchase-pressure deltas also apply per flag.
	MinUnitsPerFlag = 4,
	MaxUnitsPerFlag = 5,

	-- Floor on the per-flag result. Without it a weak player on easy and low risk drives the garrison to nothing.
	MinUnitsPerFlagFloor = 3,

	-- Defender opening units hold their spawn/mission-script positions instead of entering Lua movement rotation.
	UnitsHoldMovement = true,

	-- Time limit on the garrison purchases. Units still unbought when it expires are dropped to prevent them spawning in front of the player later
	MaxDuration = 300 * 1000,
}

ConquestConfig.DefenderCounterattackByDifficulty = {
	easy   = { Min = 7,  Max = 11 },
	normal = { Min = 9,  Max = 13 },
	hard   = { Min = 11, Max = 15 },
	heroic = { Min = 13, Max = 17 },
}

ConquestConfig.DefenderCounterattack = {
	MinUnits = 8,
	MaxUnits = 15,

	-- Flag ownership must remain changed for this long before the defender responds.
	ConfirmDelay = 30 * 1000,

	-- Delay after confirmation before the counterattack purchase burst starts.
	ResponseDelayMin = 5 * 1000,
	ResponseDelayMax = 15 * 1000,

	-- Delay between separate counterattack bursts that were already queued.
	ChainedResponseDelayMin = 60 * 1000,
	ChainedResponseDelayMax = 90 * 1000,

	-- Chance to respond after a confirmed flag loss. 1.0 = always.
	ResponseChance = 0.95,

	MaxTotal = 20,
	MaxPerFlag = 3,

}

-- Purchase-count deltas applied after baseline phase counts are rolled.
ConquestConfig.PurchasePressure = {
	-- Clamp on the summed delta, per phase. A guard against stacked modifiers
	-- defender_opening needs more room because its delta applies per flag and is then multiplied by flag count.
	DeltaClamp = {
		Default = { min = -2, max = 8 },
		attacker_wave = { min = -2, max = 8 },
		defender_opening = { min = -2, max = 2 },
		defender_counterattack = { min = -2, max = 8 },
	},

	DifficultyPurchaseCountDelta = {
		easy = {
			attacker_wave = -1,
			defender_opening = -1,
			defender_counterattack = 0,
		},
		normal = {
			attacker_wave = 0,
			defender_opening = 0,
			defender_counterattack = 0,
		},
		hard = {
			attacker_wave = 0,
			defender_opening = 1,
			defender_counterattack = 1,
		},
		heroic = {
			attacker_wave = 1,
			defender_opening = 2,
			defender_counterattack = 2,
		},
	},

	RiskPurchaseCountDelta = {
		low = {
			attacker_wave = 0,
			defender_opening = -1,
			defender_counterattack = -1,
		},
		standard = {
			attacker_wave = 0,
			defender_opening = 0,
			defender_counterattack = 0,
		},
		high = {
			attacker_wave = 0,
			defender_opening = 1,
			defender_counterattack = 1,
		},
	},

	CPLimitStages = {
		{ band = "Stage1", max = 60 },
		{ band = "Stage2", max = 140 }, -- +80
		{ band = "Stage3", max = 240 }, -- +100
		{ band = "Stage4", max = 360 }, -- +120
		{ band = "Stage5", max = nil }, -- open-ended. Any value > Stage4.
	},

	PlayerBattleScalePurchaseCountDelta = {
		Stage1 = {
			attacker_wave = -1,
			defender_opening = -3,
			defender_counterattack = 0,
		},
		Stage2 = {
			attacker_wave = 0,
			defender_opening = -3,
			defender_counterattack = 0,
		},
		Stage3 = {
			attacker_wave = 1,
			defender_opening = 1,
			defender_counterattack = 1,
		},
		Stage4 = {
			attacker_wave = 3,
			defender_opening = 2,
			defender_counterattack = 2,
		},
		Stage5 = {
			attacker_wave = 5,
			defender_opening = 3,
			defender_counterattack = 2,
		},
	},

	CommitmentThresholds = {
		{ band = "LowCommitment", max = 0.49 },
		{ band = "NormalCommitment", max = 0.84 },
		{ band = "FullCommitment", max = nil },
	},

	PlayerBattleCommitmentPurchaseCountDelta = {
		LowCommitment = {
			attacker_wave = -1,
			defender_opening = -1,
			defender_counterattack = 0,
		},
		NormalCommitment = {
			attacker_wave = 0,
			defender_opening = 0,
			defender_counterattack = 0,
		},
		FullCommitment = {
			attacker_wave = 0,
			defender_opening = 1,
			defender_counterattack = 0,
		},
	},
}


-- Force identity and slot-planning configuration.
ConquestConfig.PurchaseForces = {
	PrimaryForceRoll = {
		"infantry_force",
		"armored_force",
	},

	SecondaryForceRoll = {
		infantry_force = {
			"none",
			"none",
			"armored_force",
			"anti_tank_force",
			"artillery_support_force",
			"aa_support_force",

		},

		armored_force = {
			"none",
			"none",
			"anti_tank_force",
			"artillery_support_force",
			"aa_support_force",

		},
	},

	SecondaryShare = 0.25,
	SecondaryShareByForce = {
		armored_force = 0.25,
		anti_tank_force = 0.20,
		artillery_support_force = {
			easy = 0.05,
			normal = 0.05,
			hard = 0.10,
			heroic = 0.15,
		},
		aa_support_force = 0.15,
		aircraft_force = 0.15,
	},
	SecondaryMinTarget = 3,

	SingleForceCost = 0.35,
	DefaultForceCost = 1.0,
}

-- ============================================================
-- PURCHASE MODE
-- ============================================================
-- "flat"  : one pool, v1-style. All units compete by weight.
--           Doctrine works on the entire pool. lane system bypassed.
-- "lanes" : dev lane architecture. Kept for reference.
ConquestConfig.PurchaseMode = "flat"

-- Aircraft lane budget per nation (flat mode only).
-- Guaranteed one aircraft lane per main_attack wave (non-probe).
-- Value = force-cost units (1 unit = 1.0). Derived from v1 .bak
-- aircraft share of pool: eng 4.2%, ger 9.2%, rus 5.1%, fin 4.5%, usa 12.3%.
ConquestConfig.AircraftLaneBudget = {
		-- Fractional coefficient per nation. Converted to integer slots in
		-- StartPurchasePhasePlan via stochastic rounding (see purchase_profiles).
		eng = 1.2,
		ger = 1.0,
		rus = 0.9,
		fin = 0.6,
		usa = 1.3,
}

-- Lane-budget tuning for force identity profiles.
-- purchase_profiles.lua applies this data; designers should adjust ratios here,
-- not inside profile-building code.
ConquestConfig.PurchaseProfiles = {
	PrimaryForce = {
		infantry_force = {
			OrganicSupportShare = 0.40,
		},

		armored_force = {
			BodyShare = 0.35,
			InfantrySupportShare = 0.50,
			-- Mobile support receives the remaining primary-force budget.
		},
	},

	Probe = {
		armored_force = {
			MobileShare = 0.20,
			InfantryShare = 0.60,
			-- Light armor receives the remaining probe budget.
		},
	},
}

-- Unit-selection weights and phase policy.
-- Purchase scoring applies this data; the design/tuning values live here.
ConquestConfig.PurchaseScoring = {
		-- [ ARCHIVED 2026-09-26 ] Old AvailabilityWeight table removed.
		-- It was dev-shaped (higher avail -> RARER: 0.9->2.00, 1.7->0.10),
		-- but migration set availability = v1 priority 1:1 (higher = MORE
		-- common). Direction was inverted for our data. Now weight = avail
		-- directly in purchase_scoring.GetAvailabilityWeight (identity).
		-- See KB block avail_weight_identity.

	DifficultyGradeWeight = {
		easy = {
			Grade1 = 1.15,
			Grade2 = 1.05,
			Grade3 = 0.95,
			Grade4 = 0.85,
		},

		normal = {
			Grade1 = 1.05,
			Grade2 = 1.00,
			Grade3 = 1.00,
			Grade4 = 0.95,
		},

		hard = {
			Grade1 = 0.95,
			Grade2 = 1.00,
			Grade3 = 1.05,
			Grade4 = 1.10,
		},

		heroic = {
			Grade1 = 0.85,
			Grade2 = 0.95,
			Grade3 = 1.05,
			Grade4 = 1.15,
		},
	},

	-- Class-tier gate (parallel to DifficultyGradeWeight)
	DifficultyClassWeight = {
		Curve = {
			easy   = { Light = 1.0, Medium = 1.0, Heavy = 1.0 },
			normal = { Light = 1.0, Medium = 1.0, Heavy = 1.0 },
			hard   = { Light = 1.0, Medium = 1.0, Heavy = 1.0 },
			heroic = { Light = 1.0, Medium = 1.0, Heavy = 1.0 },
		},

		-- Per-base-category gate strength (0 = no gating, 1 = full curve).
		ClassGateStrength = {
			Tank = 1.00,
			SPG = 0.80,
			Vehicle = 0.50,
			Cannon = 0.45,
		},
	},

	-- Controls the split between heavy mortars (not medium mortars) and artillery
	DifficultyIndirectWeight = {
		easy = {
			HeavyMortar = 1.60,
			Artillery = 0.05,
		},

		normal = {
			HeavyMortar = 1.55,
			Artillery = 0.10,
		},

		hard = {
			HeavyMortar = 0.95,
			Artillery = 0.85,
		},

		heroic = {
			HeavyMortar = 0.70,
			Artillery = 1.30,
		},
	},

	-- Global reduction for single infantry so purchase selection prefers squads when lane fit is otherwise equal.
	SingleInfantryWeight = 0.70,

	PhaseFit = {
		attacker_wave = {
			OffensiveOrFlexible = 1.15,
			Defensive = 0.70,
		},

		defender_counterattack = {
			OffensiveOrFlexible = 1.15,
			Defensive = 0.70,
		},

		defender_opening = {
			DefensiveOrFlexible = 1.15,
			MountedInfantry = 0.0,
			OffensiveVehicleSupport = 0.0,
		},
	},

	LaneFit = {
		infantry_body = {
			InfantryLine = 1.00,
			ReconInfantrySquad = 0.65,
			ReconInfantrySingle = 0.35,
			AssaultInfantrySquad = 0.65,
		},

		infantry_organic_support = {
			CannonMachineGun = 1.00,
			LightCannonMortar = 1.00,
			CannonInfantryGun = 1.00,
			FieldGun = 0.90,
			LightCannonAntiArmor = 0.90,
			InfantryAT = 0.65,
			MobileInfantryGun = 0.40,
		},

		armored_body = {
			ArmorTank = 1.00,
			ReconVehicleOrTank = 0.80,
		},

		armored_infantry_support = {
			InfantryLine = 1.15,
			ReconInfantrySquad = 0.45,
			AssaultInfantrySquad = 0.45,
			InfantryAT = 0.35,
		},

		armored_mobile_support = {
			VehicleMachineGun = 1.00,
			MobileInfantryGun = 1.00,
			AssaultVehicleOrTank = 0.90,
			CannonMachineGun = 0.45,
			VehicleMortar = 0.45,
			VehicleRecon = 0.45,
		},

		secondary_armored_force = {
			ArmorTank = 1.00,
			ReconVehicleOrTank = 0.85,
			AssaultVehicleOrTank = 0.65,
		},

		anti_tank_force = {
			InfantryAT = 0.45,
			FieldGun = 0.85,
			AntiArmor = 1.00,
		},

		artillery_support_force = {
			Artillery = 1.00,
			HeavyMortar = 0.80,
		},

		aa_support_force = {
			AirDefense = 1.00,
		},

		aircraft_force = {
			_Fighter    = 1.00,
			_HvFighter  = 0.85,
			_Bomber     = 0.90,
			_HvBomber   = 0.75,
			ReconPlane  = 0.80,
			Aircraft    = 1.00,
		},

		probe_mobile = {
			ReconVehicleOrTank = 1.25,
			VehicleMachineGun = 1.15,
			LightArmorTank = 0.75,
		},

		probe_infantry = {
			InfantryLine = 0.50,
			ReconInfantrySquad = 1.20,
			ReconInfantrySingle = 0.35,
		},

		probe_light_armor = {
			LightArmorTank = 1.00,
			ReconVehicleOrTank = 0.90,
			VehicleMachineGun = 0.65,
			NonHeavyArmorTank = 0.25,
		},
	},

	ArmoredInfantrySupportPhaseFit = {
		attacker_wave = {
			MountedInfantry = 1.25,
		},
	},

	SupportLanePhaseFit = {
		PhaseRules = {
			attacker_wave = {
				MobilePlatform = 1.15,
				Cannon = 0.70,
				HeavyIndirectSupport = 0.70,
				MobileAirDefense = 1.10,

				LaneRules = {
					infantry_organic_support = { InfantryAT = 1.15 },
					anti_tank_force = { InfantryAT = 1.15 },
				},
			},

			defender_counterattack = {
				MobilePlatform = 1.15,
				Cannon = 0.55,
				HeavyIndirectSupport = 0.55,
				MobileAirDefense = 1.10,

				LaneRules = {
					infantry_organic_support = { InfantryAT = 1.15 },
					anti_tank_force = { InfantryAT = 1.15 },
				},
			},
		},
	},
}

-- Maximum time the AI waits for resources or unit timer before choosing again.
ConquestConfig.UnitSpawnWaitTime = 15 * 1000 -- 15 sec (FIX 2026-09-27: было 90s, бот залипал 3 мин на отказе движка)

-- Time delay before a squad receives a refreshed order. Loops while squad exists.
ConquestConfig.OrderRotationPeriod = 2.5 * 60000 -- 2:30 min (ms)


-- Post-final-wave attacker failure watcher.
-- Runs after the final attacker wave completes and requests attacker retreat when the
-- attacker's assault strength has fallen to the bar set by the player's remaining defense.
-- Mission script should react by ordering attacker retreat, then set gameover_request_player_win when ready to end.
ConquestConfig.AttackerFailure = {
	InitialCheckDelaySeconds = 60,
	RepeatCheckIntervalSeconds = 15,

	-- bar = clamp(playerDefense * PlayerDefenseRatio, MinBar, MaxBar)
	-- The ratio carries the per-group tightening; the closer to winning, the weaker the attacker may get before it is judged finished.
	-- MaxBar is a stall guard, not a difficulty lever. Set below a plausible surviving force it would only hold a lost battle open.

	-- Attacker owns no objectives and has not neutralized/captured one.
	NoProgress = {
		PlayerDefenseRatio = 0.30,
		MinBar = 12,
		MaxBar = 40,
	},

	-- Attacker owns or has neutralized/captured at least one objective.
	PartialProgress = {
		PlayerDefenseRatio = 0.22,
		MinBar = 8,
		MaxBar = 40,
	},

	-- Attacker owns all but one objective.
	NearVictory = {
		PlayerDefenseRatio = 0.15,
		MinBar = 6,
		MaxBar = 40,
	},
}

