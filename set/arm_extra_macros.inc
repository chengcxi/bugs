; ARM-only gun macros.
; Loaded from ARM gun files so they still exist if MACE overwrites .presets.
; Kept outside set/stuff/gun/ so GEM does not treat this file as a gun entity.

(define "range_220_l"								;ARm 070326+
	("standard_firing_arc")
	; {range 220 220}
	{range 410 440}
	{parameters "he"
		{range 410 440}
	}
	("direct_settings")
)

(define "range_220_h"								;ARm 070326+
	("standard_firing_arc")
	; {range 220 220}
	{range 440 440}
	{parameters "he"
		{range 440 440}
	}
	("direct_settings")
)

(define "range_230"								;ARm 080326+						
	("standard_firing_arc")
	; {range 230 230}
	{range 450 460}									
	{parameters "he"
		{range 440 540}								; ARm 070926 ( 340 460 - 340 540 - 440 540 )
	}
	("direct_settings")
)

(define "range_230_l"								;ARm 070326+						
	("standard_firing_arc")
	; {range 230 230}
	{range 445 460}
	{parameters "he"
		{range 445 445}
	}
	("direct_settings")
)

(define "range_230_h"									;ARm 070326+					
	("standard_firing_arc")
	; {range 230 230}
	{range 460 460}
	{parameters "he"
		{range 460 460}
	}
	("direct_settings")
)

(define "range_250_l"									;ARm 070326+					
	("standard_firing_arc")
	; {range 250 250}
	{range 475 500}
	{parameters "he"
		{range 475 475}
	}
	("direct_settings")
)

(define "range_250_h"									;ARm 070326+					
	("standard_firing_arc")
	; {range 250 250}
	{range 500 500}
	{parameters "he"
		{range 500 500}
	}
	("direct_settings")
)

(define "range_autocannon_50-57"													;ARm 290126
	("standard_firing_arc")
	{range 325 440}						;//080326	(440 440) - (275 440) - (320 440)
	{automatic}
	{aimingTolerance 3}
	{SpreadTolerance 0}			;// Zeroing up to 0% needed before fire
	{spreading
		{BurstRecoveryTime 0.5}
		{BurstAccuracy 100 95 88 82 75 68 55 32}
		{SpreadXYRatio	0.5}
	}
	{burst
		{short 2 0.75}			;// short burst shots on long distance, rand (+-)shots
		{long 5 1}				;// long burst shots on short distance, rand (+-)shots
		{rangeKoef 0.85}		;// rangeKoef * aimRange = max long burst distance
	}
	{parameters "he"										; SPgGr.												;ARm 080226
		{range 360 460}							; (325 440) (360 460)
		(mod "mp" {unlimitedRangeTPC 1})		;// unrestricts range in TPC/FPC for shooting at aircraft
		(mod not "mp" {unlimitedRangeTPC 1})	;// unrestricts range in TPC/FPC for shooting at aircraft
		{FalloffStrength 0}
	}
	{SyncedProjectiles 0}		;// not for automatic weapons
)

(define "range_aircraft_gun_15-20-30"																;150226
	("standard_firing_arc")
	; {range 140 140}
	{range 280 320}																					;150226 (280 280) - (280 320)
	(mod not "mp"
		; {range 275 500}
		{range 280 500}
		{aimingTolerance 15}
		{spreading
			{SpreadPower 1}
			{BurstRecoveryTime 0.5}
			{BurstAccuracy 100 95 90}
			{SpreadXYRatio 5}
			{radiusTable {0 0.5} {200 2} {300 5} {350 12}}
		}
	)
	{automatic}
	{aimingTolerance 10}
	{SpreadTolerance 0}			;// Zeroing up to 0% needed before fire
	{spreading
		{SpreadPower 1}
		{BurstRecoveryTime 0.5}
		{BurstAccuracy 100 95 90}
		{SpreadXYRatio 5}
		{radiusTable {0 0} {80 2} {130 5} {200 10}}
	}
	{burst
		{short 20 5}			;// short burst shots on long distance, rand (+-)shots
		{long 50 10}			;// long burst shots on short distance, rand (+-)shots
		{rangeKoef 0.75}		;// rangeKoef * aimRange = max long burst distance
	}
	{SyncedProjectiles 0}		;// not for automatic weapons
)

(define "range_aircraft_gun_15s-20s-30s"															;150226
	("standard_firing_arc")
	; {range 140 140}
	{range 280 280}																					;150226 (280 280)
	(mod not "mp"
		; {range 275 500}
		{range 280 500}
		{aimingTolerance 15}
		{spreading
			{SpreadPower 1}
			{BurstRecoveryTime 0.5}
			{BurstAccuracy 100 95 90}
			{SpreadXYRatio 5}
			{radiusTable {0 0.5} {200 2} {300 5} {350 12}}
		}
	)
	{automatic}
	{aimingTolerance 10}
	{SpreadTolerance 0}			;// Zeroing up to 0% needed before fire
	{spreading
		{SpreadPower 1}
		{BurstRecoveryTime 0.5}
		{BurstAccuracy 100 95 90}
		{SpreadXYRatio 5}
		{radiusTable {0 0} {80 2} {130 5} {200 10}}
	}
	{burst
		{short 20 5}			;// short burst shots on long distance, rand (+-)shots
		{long 50 10}			;// long burst shots on short distance, rand (+-)shots
		{rangeKoef 0.75}		;// rangeKoef * aimRange = max long burst distance
	}
	{SyncedProjectiles 0}		;// not for automatic weapons
)

(define "range_aircraft_gun_30-45"															;150226
	("standard_firing_arc")
	{range 420 420}
	(mod not "mp"
		; {range 275 500}
		{range 280 500}
		{aimingTolerance 15}
		{spreading
			{SpreadPower 1}
			{BurstRecoveryTime 0.5}
			{BurstAccuracy 100 95 90}
			{SpreadXYRatio 5}
			{radiusTable {0 0.5} {200 2} {300 5} {350 12}}
		}
	)
	{automatic}
	{aimingTolerance 10}
	{SpreadTolerance 0}			;// Zeroing up to 0% needed before fire
	{spreading
		{SpreadPower 1}
		{BurstRecoveryTime 0.5}
		{BurstAccuracy 100 95 90}
		{SpreadXYRatio 5}
		{radiusTable {0 0} {80 2} {130 5} {200 10}}
	}
	{burst
		{short 20 5}			;// short burst shots on long distance, rand (+-)shots
		{long 50 10}			;// long burst shots on short distance, rand (+-)shots
		{rangeKoef 0.75}		;// rangeKoef * aimRange = max long burst distance
	}
	{SyncedProjectiles 0}		;// not for automatic weapons
)

(define "range_170_howitzer_short"
	("curved_firing_arc")
	; {range 170 170}
	{range 250 340}
	("indirect_settings")
)

(define "range_210_howitzer_short"
	("curved_firing_arc")
	; {range 210 210}
	{range 320 420}
	("indirect_settings")
)

(define "range_230_howitzer_short"
	("curved_firing_arc")
	; {range 230 230}
	{range 360 460}
	("indirect_settings")
)

(define "range_260_howitzer_short"
	("curved_firing_arc")
	; {range 260 260}
	{range 420 520}
	("indirect_settings")
)

(define "range_430_howitzer_long"
	("curved_firing_arc")
	; {range 430 430}
	{range 860 860}
	("indirect_settings")
)

(define "range_520_howitzer_long"
	("curved_firing_arc")
	; {range 520 520}
	{range 1040 1040}
	("indirect_settings")
)

(define "long_howitser"
	{spreading {SpreadXYRatio 0.4}}
	{parameters "he"
		{spreading 1
			{SpreadPower 1.00}    ;// Shot has en equal chance of landing anywhere on the aiming circle, no center-bias
			{SpreadXYRatio 0.75}  ;// Shots land more longitudinally than transversely.
		} 
	}
	{parameters "he2"
		{spreading 1
			{SpreadPower 1.00}    ;// Shot has en equal chance of landing anywhere on the aiming circle, no center-bias
			{SpreadXYRatio 0.75}  ;// Shots land more longitudinally than transversely.
		} 
	}
	;//MACE
	{parameters "he3"
		{spreading 1
			{SpreadPower 1.00}    ;// Shot has en equal chance of landing anywhere on the aiming circle, no center-bias
			{SpreadXYRatio 0.75}  ;// Shots land more longitudinally than transversely.
		} 
	}
;//	{ZeroingAccuracy 0.80 0.65 0.55 0.45 0.40}																					;120226-
	{ZeroingAccuracy 0.80 0.75 0.70 0.65 0.50}																					;120226+
	("artillery_firing_arc")
	{SpreadTolerance 0.85}		;// Zeroing up to 85% needed before fire
	{DisableRicochet}
	{traceFreq 0}
	{unlimitedRangeTPC 0}	;// restrict range in TPC/FPC
)

(define "very_long_howitser"
	{spreading {SpreadXYRatio 0.4}}
	{parameters "he"
		{spreading 1.1
			{SpreadPower 1.00}    ;// Shot has en equal chance of landing anywhere on the aiming circle, no center-bias
			{SpreadXYRatio 0.75}  ;// Shots land more longitudinally than transversely.
		} 
	}
	{parameters "he2"
		{spreading 1.1
			{SpreadPower 1.00}    ;// Shot has en equal chance of landing anywhere on the aiming circle, no center-bias
			{SpreadXYRatio 0.75}  ;// Shots land more longitudinally than transversely.
		} 
	}
	;//MACE
	{parameters "he3"
		{spreading 1.1
			{SpreadPower 1.00}    ;// Shot has en equal chance of landing anywhere on the aiming circle, no center-bias
			{SpreadXYRatio 0.75}  ;// Shots land more longitudinally than transversely.
		} 
	}
;//	{ZeroingAccuracy 0.80 0.65 0.55 0.45 0.40}																					;120226-
	{ZeroingAccuracy 0.80 0.80 0.75 0.70 0.60}																					;120226+
	("artillery_firing_arc")
	{SpreadTolerance 0.85}		;// Zeroing up to 85% needed before fire
	{DisableRicochet}
	{traceFreq 0}
	{unlimitedRangeTPC 0}	;// restrict range in TPC/FPC
)

(define "counter_battery_howitser"
	{spreading {SpreadXYRatio 0.4}}
	{parameters "he"
		{spreading 1.2			;//	Skews the distribution of shells more biased toward the centre (>1) or away (<1)
			{SpreadPower 1.00}    ;// Shot has en equal chance of landing anywhere on the aiming circle, no center-bias
			{SpreadXYRatio 0.75}  ;// Shots land more longitudinally than transversely.
		} 
	}
	{parameters "he2"
		{spreading 1.2
			{SpreadPower 1.00}    ;// Shot has en equal chance of landing anywhere on the aiming circle, no center-bias
			{SpreadXYRatio 0.75}  ;// Shots land more longitudinally than transversely.
		} 
	}
	;//MACE
	{parameters "he3"
		{spreading 1.2
			{SpreadPower 1.00}    ;// Shot has en equal chance of landing anywhere on the aiming circle, no center-bias
			{SpreadXYRatio 0.75}  ;// Shots land more longitudinally than transversely.
		} 
	}
;//	{ZeroingAccuracy 0.80 0.65 0.55 0.45 0.40}																					;120226-
	{ZeroingAccuracy 0.85 0.85 0.80 0.70 0.65}																					;120226+

	("artillery_firing_arc")
	{SpreadTolerance 0.85}		;// Zeroing up to 85% needed before fire
	{DisableRicochet}
	{traceFreq 0}
	{unlimitedRangeTPC 0}	;// restrict range in TPC/FPC
)

