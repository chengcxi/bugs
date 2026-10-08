
; Presets for health and stamina levels

(include "/set/breed/presets/perks/skills.inc")


;/*=========== Unique Presets Begin ===========*/

;//------------------------------ ARM

 (define "medic"
 	{"stealth"}
	{"medic" 10.0}
	{"speed" 1.20}
	{"stamina" "180%"}
	{barricade
		{"fortifications" "auto_medic_place_flag"}
	}
 )

;//------------------------------ /ARM

(define "stealth"
	{"stealth"}
	("recon_vision") 
	{"speed" 1.20}
)

(define "marksman"		;// elite sharpshooters (non sniper)
	{"rifle" lvl_8}
)

(define "tank_commander"	;// Tank Commander
	("tier2_standard")
	("loader_skill_smg_rank_2")
	("skilled_repair")
	{"health" "75%"}
	{"health_regeneration" "75%"}
	("expert_gun")
)

(define "tankman"			;// Tank Crew
	("tier2_standard")
	("loader_skill_smg_rank_2")
	("skilled_repair")
	{"health" "75%"}
	{"health_regeneration" "60%"}
	("skilled_gun")
)

;//------------------ ARM------------------
(define "penal"	
	("tier0_standard")
;//	{"health" "25%"}
;//	("skill_rank_0")
;//	("skilled_repair")
;//	{"stamina" "50%"}
;//	{"speed" 0.50}
)
;//------------------ /ARM------------------


;/*=========== Unique Presets End ===========*/

