
; Presets for health and stamina levels

(include "/set/breed/presets/perks/vision.inc")

;/*=========== Standard Presets End ===========*/

(define "civilian"
; ======================================================================== ARM BEGIN
	{"health" "25%"}								;//ARM-50%			
	{"health_regeneration" "0%"}					;//ARM-10%
	{"stamina" "35%"}								;//ARM-25%
	{"stamina_regeneration" "25%"}					;//ARM-50%
	("standard_vision")
	{"speed" 0.75}									;//ARM-30%
; ======================================================================== ARM END
)


;// TIER I // 
; ======================================================================== ARM BEGIN
(define "tier0_standard"
	{"health" "50%"}
	{"health_regeneration" "0%"}
	{"stamina" "50%"}
	{"stamina_regeneration" "45%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 0.85}
)

; ======================================================================== ARM END


(define "tier1_standard"
	{"health" "100%"}															;//-50%
	{"health_regeneration" "10%"}
	{"stamina" "75%"}
	{"stamina_regeneration" "75%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 1.00}
)

(define "tier1_recon"															;//-100%
	{"health" "100%"}
	{"health_regeneration" "10%"}
	{"stamina" "150%"}
	{"stamina_regeneration" "75%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("recon_vision")
	{"speed" 1.15}
)

(define "tier1_defense"															;//-100%
	{"health" "100%"}
	{"health_regeneration" "75%"}
	{"stamina" "75%"}
	{"stamina_regeneration" "75%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 0.85}
)


;// TIER II // 

(define "tier2_standard"
	{"health" "100%"}															;//-100%
	{"health_regeneration" "10%"}
	{"stamina" "125%"}
	{"stamina_regeneration" "100%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 1.00}
)

(define "tier2_recon"
	{"health" "100%"}															;//-100%			
	{"health_regeneration" "10%"}
	{"stamina" "225%"}
	{"stamina_regeneration" "100%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("recon_vision")
	{"speed" 1.15}
)

(define "tier2_defense"
	{"health" "200%"}															;//-100%
	{"health_regeneration" "75%"}
	{"stamina" "125%"}
	{"stamina_regeneration" "100%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 0.85}
)

;// TIER III // 

(define "tier3_standard"
	{"health" "100%"}															;//-100%
	{"health_regeneration" "10%"}
	{"stamina" "200%"}
	{"stamina_regeneration" "150%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 1.00}
)

(define "tier3_recon"
	{"health" "100%"}															;//-100%
	{"health_regeneration" "10%"}
	{"stamina" "300%"}
	{"stamina_regeneration" "150%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("recon_vision")
	{"speed" 1.15}
)

(define "tier3_defense"
	{"health" "100%"}															;//-100%
	{"health_regeneration" "75%"}
	{"stamina" "200%"}
	{"stamina_regeneration" "150%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	("standard_vision")
	{"speed" 0.85}
)

;// TIER IV // 

(define "tier4_standard"
	{"health" "100%"}															;//-100%
	{"health_regeneration" "10%"}
	{"stamina" "300%"}
	{"stamina_regeneration" "250%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	;("elite_vision")
	("standard_vision")
	{"speed" 1.00}
)

(define "tier4_recon"
	{"health" "100%"}															;//-100%
	{"health_regeneration" "10%"}
	{"stamina" "400%"}
	{"stamina_regeneration" "250%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	;("elite_vision")
	("recon_vision")
	{"speed" 1.15}
)

(define "tier4_defense"
	{"health" "100%"}															;//-100%
	{"health_regeneration" "75%"}
	{"stamina" "300%"}
	{"stamina_regeneration" "250%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	;("elite_vision")
	("standard_vision")
	{"speed" 0.85}
)

;// TIER V // Reserved for special singleplayer hero breeds

(define "tier5_standard"
	{"health" "100%"}															;//-250%
	{"health_regeneration" "20%"}
	{"stamina" "300%"}
	{"stamina_regeneration" "250%"}
	{"personage" 0}			;// This means soldiers are revivable at veterancy 0
	;("elite_vision")
	("standard_vision")
	{"speed" 1.00}
)
