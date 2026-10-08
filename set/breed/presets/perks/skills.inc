
; Presets for all melee, small arm weapons and avoidance skills

(include "/set/breed/presets/perks/health.inc")


;/* - Fortification Building Skills - */

;----------------------------------------------------------- ARM mod -----------------------------------------------------------
(define "fortification"
	{barricade
		{"fortifications" "foxhole"}
		{"fortifications" "medic_rally"}						;// ARM
		{"fortifications" "medic_hospital"}						;// ARM
		{"fortifications" "auto_medic_place_flag"}
;//		{"fortifications" "deploy_type_99_smoke_candle"};MACE Type99 candle
;//		{"fortifications" "deploy_10kg_naval_smoke_candle"};MACE Type99 candle
	}
	{"resources" "10%"}
)

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

(define "engineer"
	{fortification}
	{barricade
		{"fortifications" "barricade_sq"}
		{"fortifications" "earth_pillbox"} 			;// ARM
;//		{"fortifications" "mound_eng"}				;// ARM
		{"fortifications" "barbwire"}	
		{"fortifications" "hedgehog"}
		{"fortifications" "trench_modular"}
		{"fortifications" "foxhole_big"}
		{"fortifications" "mortar_pit"}
;//		{"fortifications" "tank_cover"}
		{"fortifications" "wired_obstacle4"}		;// ARM
		{"fortifications" "watch_tower"}			;// ARM
		{"fortifications" "guard_tower_small"}		;// ARM	
		{"fortifications" "big_foxhole_reg"}			;// ARM	

		{"fortifications" "heavy_mg_mg34"}
		{"fortifications" "heavy_mg_maxim"}
		{"fortifications" "heavy_mg_maxim_m1910_30"}
		{"fortifications" "heavy_mg_m1917_30cal"}	
;//------ TEST		
		{"fortifications" "heavy_mg_mg42"}
		{"fortifications" "heavy_mg_panzernest_krab_ger"}
		{"fortifications" "heavy_mg_20mm_flak30"}
		{"fortifications" "heavy_mg_20mm_flak38"}
		{"fortifications" "heavy_mg_37mm_flak37"}		
		{"fortifications" "heavy_mg_50mm_flak41"}
		{"fortifications" "heavy_mg_28mm_pzb41"}
		{"fortifications" "heavy_mg_37mm_pak36"}
		{"fortifications" "heavy_mg_47mm_pakt"}
		{"fortifications" "heavy_mg_50mm_pak38"}
		{"fortifications" "heavy_mg_50mm_pak38_late"}
		{"fortifications" "heavy_mg_75mm_lg40"}
		{"fortifications" "heavy_mg_75mm_pak9738"}
		{"fortifications" "heavy_mg_75mm_pak40"}
		{"fortifications" "heavy_mg_88mm_pak4341"}	
		{"fortifications" "heavy_mg_88mm_flak18"}
		{"fortifications" "heavy_mg_88mm_flak36"}
		{"fortifications" "heavy_mg_75mm_leig18"}
		{"fortifications" "heavy_mg_75mm_legebig18"}		
		{"fortifications" "heavy_mg_80mm_sgrw34"}
		{"fortifications" "heavy_mg_100mm_nbw35"}
		{"fortifications" "heavy_mg_120mm_sgrw42"}
		{"fortifications" "heavy_mg_105mm_lefh18"}
		{"fortifications" "heavy_mg_150mm_sig33"}
;//------ /TEST		
	}
	{"resources" "1000%"}
	{"resources_regeneration" "0%"}
	{mechanic factor 2.0}
)

;//--------------------------------- FIN FORTIFY I
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

;//--------------------------------- FIN FORTIFY II
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

;//--------------------------------- GER FORTIFY I
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

;//--------------------------------- GER FORTIFY II
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

;//--------------------------------- USSR FORTIFY I
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

;//--------------------------------- USSR FORTIFY II
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

;//--------------------------------- USA FORTIFY
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



;/* - Repair Skills - */

(define "skilled_repair"
	{mechanic factor 1.5}
)

(define "basic_repair"
	{mechanic factor 0.5}
)

;----------------------------------------------------------- / ARM mod -----------------------------------------------------------


;/* - Tank and Cannon Main Gun Weapon Skills - */

(define "elite_gun"
	{"tank_gun" lvl_6}
)

(define "expert_gun"
	{"tank_gun" lvl_4}
)

(define "skilled_gun"
	{"tank_gun" lvl_3}
)

(define "basic_gun"
	{"tank_gun" lvl_1}
)

;/* - Anti-Tank Weapon Skills - */

(define "at_rank_1"
	{"rocketlauncher" lvl_1}
	{"rifle" lvl_1}
)

(define "at_rank_2"
	{"rocketlauncher" lvl_2}
	{"rifle" lvl_2}
)

(define "at_rank_3"
	{"rocketlauncher" lvl_3}
	{"rifle" lvl_3}
)

(define "at_rank_4"
	{"rocketlauncher" lvl_4}
	{"rifle" lvl_4}
)

(define "at_rank_5"
	{"rocketlauncher" lvl_5}
	{"rifle" lvl_5}
)

(define "at_rank_6"
	{"rocketlauncher" lvl_6}
	{"rifle" lvl_6}
)

;/* - Skill zero, civilians or useless sods like volkssturm */

(define "skill_rank_0"
	("at_rank_1")
	{"pistol" lvl_1}
	{"smg" lvl_1}
	{"mgun" lvl_1}
	{"mgun_light" lvl_1}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	("fortification")
	("basic_repair")
	("basic_gun")
)

;/* - Sub-Machine Gunner Levels - ; Soldiers with an sub-machine gun their for primary weapon */


(define "smg_skill_rank_1"
	("at_rank_1")
	{"pistol" lvl_2}
	{"smg" lvl_2}
	{"mgun" lvl_1}
	{"mgun_light" lvl_1}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "smg_skill_rank_2"
	("at_rank_2")
	{"pistol" lvl_3}
	{"smg" lvl_3}
	{"mgun" lvl_2}
	{"mgun_light" lvl_2}
	{"rifle" lvl_2}
	{"melee" lvl_2}
	{"avoidance" lvl_2}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "smg_skill_rank_3"
	("at_rank_3")
	{"pistol" lvl_4}
	{"smg" lvl_4}
	{"mgun" lvl_3}
	{"mgun_light" lvl_3}
	{"rifle" lvl_3}
	{"melee" lvl_3}
	{"avoidance" lvl_3}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "smg_skill_rank_4"
	("at_rank_4")
	{"pistol" lvl_5}
	{"smg" lvl_5}
	{"mgun" lvl_4}
	{"mgun_light" lvl_4}
	{"rifle" lvl_4}
	{"melee" lvl_4}
	{"avoidance" lvl_4}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "smg_skill_rank_5"
	("at_rank_5")
	{"pistol" lvl_6}
	{"smg" lvl_6}
	{"mgun" lvl_5}
	{"mgun_light" lvl_5}
	{"rifle" lvl_5}
	{"melee" lvl_5}
	{"avoidance" lvl_5}
	("fortification")
	("basic_repair")
	("basic_gun")
)

;/* - Rifleman Levels - ; Soldiers with an rifle for their primary weapon */

(define "rifle_skill_rank_1"
	("at_rank_1")
	{"pistol" lvl_2}
	{"smg" lvl_1}
	{"mgun" lvl_1}
	{"mgun_light" lvl_1}
	{"rifle" lvl_2}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_2"
	("at_rank_2")
	{"pistol" lvl_3}
	{"smg" lvl_2}
	{"mgun" lvl_2}
	{"mgun_light" lvl_2}
	{"rifle" lvl_3}
	{"melee" lvl_2}
	{"avoidance" lvl_2}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_3"
	("at_rank_3")
	{"pistol" lvl_4}
	{"smg" lvl_3}
	{"mgun" lvl_3}
	{"mgun_light" lvl_3}
	{"rifle" lvl_4}
	{"melee" lvl_3}
	{"avoidance" lvl_3}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_4"
	("at_rank_4")
	{"pistol" lvl_5}
	{"smg" lvl_4}
	{"mgun" lvl_4}
	{"mgun_light" lvl_4}
	{"rifle" lvl_5}
	{"melee" lvl_4}
	{"avoidance" lvl_4}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "rifle_skill_rank_5"
	("at_rank_5")
	{"pistol" lvl_6}
	{"smg" lvl_5}
	{"mgun" lvl_5}
	{"mgun_light" lvl_5}
	{"rifle" lvl_6}
	{"melee" lvl_5}
	{"avoidance" lvl_5}
	("fortification")
	("basic_repair")
	("basic_gun")
)


;/* - MG Loaders/assistant Levels - ; Soldiers with an rifle/pistol for their primary weapon, but are also trained for MG use */

(define "loader_skill_rank_1"
	("at_rank_1")
	{"pistol" lvl_2}
	{"smg" lvl_1}
	{"mgun" lvl_2}
	{"mgun_light" lvl_2}
	{"rifle" lvl_2}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_rank_2"
	("at_rank_2")
	{"pistol" lvl_3}
	{"smg" lvl_2}
	{"mgun" lvl_3}
	{"mgun_light" lvl_3}
	{"rifle" lvl_3}
	{"melee" lvl_2}
	{"avoidance" lvl_2}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_rank_3"
	("at_rank_3")
	{"pistol" lvl_4}
	{"smg" lvl_3}
	{"mgun" lvl_4}
	{"mgun_light" lvl_4}
	{"rifle" lvl_4}
	{"melee" lvl_3}
	{"avoidance" lvl_3}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_rank_4"
	("at_rank_4")
	{"pistol" lvl_5}
	{"smg" lvl_4}
	{"mgun" lvl_5}
	{"mgun_light" lvl_5}
	{"rifle" lvl_5}
	{"melee" lvl_4}
	{"avoidance" lvl_4}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_rank_5"
	("at_rank_5")
	{"pistol" lvl_6}
	{"smg" lvl_5}
	{"mgun" lvl_6}
	{"mgun_light" lvl_6}
	{"rifle" lvl_6}
	{"melee" lvl_5}
	{"avoidance" lvl_5}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_smg_rank_1"
	("at_rank_1")
	{"pistol" lvl_2}
	{"smg" lvl_2}
	{"mgun" lvl_2}
	{"mgun_light" lvl_2}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_smg_rank_2"
	("at_rank_2")
	{"pistol" lvl_3}
	{"smg" lvl_3}
	{"mgun" lvl_3}
	{"mgun_light" lvl_3}
	{"rifle" lvl_2}
	{"melee" lvl_2}
	{"avoidance" lvl_2}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_smg_rank_3"
	("at_rank_3")
	{"pistol" lvl_4}
	{"smg" lvl_4}
	{"mgun" lvl_4}
	{"mgun_light" lvl_4}
	{"rifle" lvl_3}
	{"melee" lvl_3}
	{"avoidance" lvl_3}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_smg_rank_4"
	("at_rank_4")
	{"pistol" lvl_5}
	{"smg" lvl_5}
	{"mgun" lvl_5}
	{"mgun_light" lvl_5}
	{"rifle" lvl_4}
	{"melee" lvl_4}
	{"avoidance" lvl_4}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "loader_skill_smg_rank_5"
	("at_rank_5")
	{"pistol" lvl_6}
	{"smg" lvl_6}
	{"mgun" lvl_6}
	{"mgun_light" lvl_6}
	{"rifle" lvl_5}
	{"melee" lvl_5}
	{"avoidance" lvl_5}
	("fortification")
	("basic_repair")
	("basic_gun")
)

;/* - Machine Gunner Levels - ; Soldiers with an machine gun for their primary weapon */

(define "mg_skill_rank_1"
	("at_rank_1")
	{"pistol" lvl_2}
	{"smg" lvl_1}
	{"mgun" lvl_2}
	{"mgun_light" lvl_2}
	{"rifle" lvl_1}
	{"melee" lvl_1}
	{"avoidance" lvl_1}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "mg_skill_rank_2"
	("at_rank_2")
	{"pistol" lvl_3}
	{"smg" lvl_2}
	{"mgun" lvl_3}
	{"mgun_light" lvl_3}
	{"rifle" lvl_2}
	{"melee" lvl_2}
	{"avoidance" lvl_2}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "mg_skill_rank_3"
	("at_rank_3")
	{"pistol" lvl_4}
	{"smg" lvl_3}
	{"mgun" lvl_4}
	{"mgun_light" lvl_4}
	{"rifle" lvl_3}
	{"melee" lvl_3}
	{"avoidance" lvl_3}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "mg_skill_rank_4"
	("at_rank_4")
	{"pistol" lvl_5}
	{"smg" lvl_4}
	{"mgun" lvl_5}
	{"mgun_light" lvl_5}
	{"rifle" lvl_4}
	{"melee" lvl_4}
	{"avoidance" lvl_4}
	("fortification")
	("basic_repair")
	("basic_gun")
)

(define "mg_skill_rank_5"
	("at_rank_5")
	{"pistol" lvl_6}
	{"smg" lvl_5}
	{"mgun" lvl_6}
	{"mgun_light" lvl_6}
	{"rifle" lvl_5}
	{"melee" lvl_5}
	{"avoidance" lvl_5}
	("fortification")
	("basic_repair")
	("basic_gun")
)

;____________________MACE
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