; ARM-only breed perk macros.
; Included from ARM breed files so they survive MACE overlaying skills.inc.

(define "tankman_allnations"
;//	{fortification}
	{barricade
		{"fortifications" "tank_cover_small_reg"}				;// ARM	
		{"fortifications" "tank_cover"}							;// ARM
	}
)

(define "mgunner_ussr"
;//	{fortification}
	{barricade
		{"fortifications" "ussr_mg_lafette_dp_reg"}	
	}
)

(define "mgunner_ger"
;//	{fortification}
	{barricade
		{"fortifications" "ger_mg_lafette_mg34_reg"}	
	}
)

(define "mgunner_ger42"
;//	{fortification}
	{barricade
		{"fortifications" "ger_mg_lafette_mg42_reg"}	
	}
)

(define "mgunner_fin_dt"
;//	{fortification}
	{barricade
		{"fortifications" "fin_mg_lafette_dt_reg"}	
	}
)

(define "mechanic_ger"
;//	{fortification}
	{barricade
		{"fortifications" "barricade_sq"}	
		{"fortifications" "barbwire"}	
		{"fortifications" "wired_obstacle4"}		;// ARM
		{"fortifications" "hedgehog"}
		
		{"fortifications" "inf_crate_ger"}						;// ARM
		{"fortifications" "all_searchlight_150mm_reg"} 			;// ARM
		{"fortifications" "regelbau_pole_freya_reg"} 			;// ARM
		{"fortifications" "f_28cm_wkspr_stan_reg"} 							;// ARM
	}

	
	{"speed" 1.20}
	{"stamina" "210%"}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 4.0}
)

(define "signaller_f"
;//	{fortification}
;//	{barricade
;//		{"fortifications" "all_searchlight_150mm_reg"} 			;// ARM
;//	}
	{"resources" "10%"}
	{"resources_regeneration" "0%"}
)

(define "engineer_heavy_fin"
	{fortification}
	{barricade
		{"fortifications" "foxhole"}

		{"fortifications" "supply_point_fin"}			;// ARM
		{"fortifications" "post_watchtower_reg"}		;// ARM
		{"fortifications" "mortar_foxhole"}				;// ARM
		{"fortifications" "fin_flak_gun_stand"}			;// ARM
		{"fortifications" "at_static_position"}			;// ARM
		{"fortifications" "arty_static_position"}		;// ARM	
		{"fortifications" "fin_panzernest_krab"}		;// ARM	
		{"fortifications" "inf_crate_fin"}				;// ARM
		{"fortifications" "fin_tower_mg"}				;// ARM
		{"fortifications" "fin_bunker_at_flak_reg"}		;// ARM		

;//		{"fortifications" "fin_bunker_flak_40mm"}		;// ARM	

	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 2.0}
)

(define "engineer_heavy_fin_late"
	{fortification}
	{barricade
		{"fortifications" "foxhole"}

		{"fortifications" "mg_casemate"}					;// ARM		
		{"fortifications" "fin_coastal_gun"}				;// ARM
		{"fortifications" "fin_150mm_rkh41_position_reg"}	;// ARM
		{"fortifications" "fin_concrete_bunker_reg"}		;// ARM			

;//		{"fortifications" "fin_bunker_flak_40mm"}			;// ARM	
;//		{"fortifications" "heavy_mg_mg34"}
;//		{"fortifications" "heavy_mg_maxim"}
;//		{"fortifications" "heavy_mg_maxim_m1910_30"}
;//		{"fortifications" "heavy_mg_m1917_30cal"}

	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 2.0}
)

(define "engineer_heavy_ger"
	{fortification}
	{barricade
		{"fortifications" "foxhole"}

		{"fortifications" "supply_point_ger"}			;// ARM
		{"fortifications" "ger_arty_static_position"}	;// ARM	
		{"fortifications" "ger_flak38_position"}		;// ARM
		{"fortifications" "ger_at_static_position"}		;// ARM		
		{"fortifications" "ger_bunker_reg"}				;// ARM	new	
		{"fortifications" "ger_mortar_foxhole"}			;// ARM
		{"fortifications" "ger_tower_mg"}				;// ARM
		{"fortifications" "ger_big_bunker"}				;// ARM				

;//		{"fortifications" "inf_crate_ger"}				;// ARM
;//		{"fortifications" "ger_mg_casemate"}			;// ARM		
;//		{"fortifications" "ger_bunker"}					;// ARM			
;//		{"fortifications" "ger_75at_static_position"}	;// ARM
;//		{"fortifications" "post_watchtower"}			;// ARM



	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 2.0}
)

(define "engineer_heavy_ger_late"
	{fortification}
	{barricade
		{"fortifications" "foxhole"}

		{"fortifications" "ger_mg_bunker"}					;// ARM	
		{"fortifications" "ger_coastal_gun"}				;// ARM
		{"fortifications" "ger_kwk39_position_reg"}			;// ARM		
		{"fortifications" "ger_regelbau_pak_reg"}			;// ARM
		{"fortifications" "ger_regelbau_arty_bunker"}		;// ARM		
		{"fortifications" "flak_gun_stand"}					;// ARM	
		{"fortifications" "ger_concrete_bunker_reg"}		;// ARM			

;//		{"fortifications" "ger_bunker"}						;// ARM			
;//		{"fortifications" "ger_75at_static_position"}		;// ARM
;//		{"fortifications" "flak_gun_stand"}					;// ARM
;//		{"fortifications" "ger_tower_mg"}					;// ARM
;//		{"fortifications" "post_watchtower"}				;// ARM

	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 2.0}
)

(define "engineer_heavy_usa"
	{fortification}
;//	{barricade
;//		{"fortifications" "littledavid"}
;//	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 1.0}
)

(define "engineer_heavy_swe"
	{fortification}
;//	{barricade
;//		{"fortifications" "swe_gun_buildable"}
;//	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 1.0}
)

(define "engineer_heavy_jap"
	{fortification}
	{barricade
		{"fortifications" "jap_type21_buildable"}
	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 1.0}
)

(define "soviet_fortifier"
	{fortification}
	{barricade
		{"fortifications" "foxhole"}

		{"fortifications" "supply_point_rus"}					;// ARM
		{"fortifications" "ussr_mg_casemate"}					;// ARM
		{"fortifications" "ussr_4x_maxima_foxhole"}				;// ARM
		{"fortifications" "ussr_at_static_position"}			;// ARM
		{"fortifications" "ussr_arty_static_position"}			;// ARM
		{"fortifications" "inf_crate_rus"}						;// ARM
		{"fortifications" "ussr_tower_mg"}						;// ARM	
		{"fortifications" "ussr_mortar_foxhole"}				;// ARM
		{"fortifications" "reg_ussr_naval_45mm_cannon"}			;// ARM		
		
		
				
	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 2.0}
)

(define "soviet_fortifier_late"
	{fortification}
	{barricade
		{"fortifications" "foxhole"}

		{"fortifications" "ussr_heavy_arty_static_position"}	;// ARM
		{"fortifications" "ussr_at_heavy_emplacement_reg"}		;// ARM
		{"fortifications" "ussr_trench_pillbox"}				;// ARM
		{"fortifications" "ussr_300mm_m30_position_reg"}		;// ARM	
		{"fortifications" "ussr_concrete_bunker_reg"}	;// ARM			
		
	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 2.0}
)

(define "usa_fortifier"
	{fortification}
	{barricade
		{"fortifications" "foxhole"}

		{"fortifications" "usa_arty_static_position_reg"}			;// ARM
		{"fortifications" "usa_mortar_foxhole_reg"}					;// ARM
		{"fortifications" "usa_heavy_arty_static_position_reg"}		;// ARM	
		{"fortifications" "usa_tower_mg_reg"}						;// ARM	
		{"fortifications" "inf_crate_usa_stand_reg"}				;// ARM
		{"fortifications" "usa_trench_pillbox_reg"}					;// ARM
		{"fortifications" "usa_flak_ring_reg"}						;// ARM
		{"fortifications" "supply_point_usa_reg"}					;// ARM		
		{"fortifications" "usa_concrete_bunker_reg"}	;// ARM			
	
		
	}

	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 2.0}
)

