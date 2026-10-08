;/*=========== Generic SCRIPT MACE ===========*/

{"flak_skink_mace_1"				;// base code for multi-barrel cannons and vehicles. To customize, add unique code to specific cannon name prop
	{on "init_gun"
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel00"	"shooter00"}
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel01"	"shooter01"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{call "update_gun"}
	}
	{on fire "gun1" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{ani_play "fire%0"}
				{delay 0.12
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)
		{if	("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}
}

{"flak_skink_mace_2"				;// base code for multi-barrel cannons and vehicles. To customize, add unique code to specific cannon name prop
	{on "init_gun"
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel_b00"	"shooterb00"}
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel_b01"	"shooterb01"}
		{add_view "smoke_zenit"			"smoke_b00"		"shooterb00"}
		{add_view "smoke_zenit"			"smoke_b01"		"shooterb01"}
		{call "update_gun"}
	}
	{on fire "gun2" overload
		(define "fire_barrel_b"
			name "%0"
				{call "fire_barrel_b%0"}
				{view start "flashbarrel_b%0"}
				{ani_play "fire_b%0"}
				{delay 0.12
					{view start "smoke_b%0"}
					{delay 5
						{view pause "smoke_b%0"}
					}
				}
		)
		{if	("fire_barrel_b" args 00)
		else ("fire_barrel_b" args 01)
		}
	}
}

(define "tag_ai_arty_mace"
	{on spawn
		{tags add "i_see_you"}
	}
)

(define "tag_ai_arty_mace_cannon_big"
	{on "add_movement_sound" overload ;// split add movements into separate define and nest this one into it. separate so different turret/gun rotate sounds can be added.
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
	}

	{on spawn
		{link_sound "wheel_ground"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_grass"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_water"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_puddle"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_mud"			"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_snow"		"vehicle/cannon_roll/overlays/cannon_overlay_snow"}
		{link_sound "wheel_road"		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_rock"		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_wood"		"vehicle/cannon_roll/overlays/cannon_overlay_wood"}

		{tags add "i_see_you"}
	}
)

(define "tag_ai_arty_mace_cannon_small"
	{on "add_movement_sound" overload ;// split add movements into separate define and nest this one into it. separate so different turret/gun rotate sounds can be added.
		{link_sound "rotate_turret"		"vehicle/turret/cannon/small"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/small"}
	}

	{on spawn
		{link_sound "wheel_ground"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_grass"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_water"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_puddle"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_mud"			"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_snow"		"vehicle/cannon_roll/overlays/cannon_overlay_snow"}
		{link_sound "wheel_road"		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_rock"		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_wood"		"vehicle/cannon_roll/overlays/cannon_overlay_wood"}

		{tags add "i_see_you"}
	}
)

{"tag_apply_anti_air"				;// base code for multi-barrel cannons and vehicles. To customize, add unique code to specific cannon name prop
	{on spawn
		{tags add "dio_cane"}
	}
}

{"flak_mace"				;// base code for multi-barrel cannons and vehicles. To customize, add unique code to specific cannon name prop
	{on "init_gun"
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel00"	"shooter00"}
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel01"	"shooter01"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{call "update_gun"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{ani_play "fire%0"}
				{delay 0.12
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)
		{if	("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
		{ani_play "recoil"}
	}
}

(define "repair_sounds_1" ;// Define Sound for Repair animation on Recovery vehicles
	{delay 0.6
		{play_sound "toolbox_open"}
	}
	{delay 1.2
		{play_sound "tool_equip"}
	}
	{delay 1.8
		{play_sound "wrench_turn"}
	}
	{delay 2.4
		{play_sound "wrench_turn"}
	}
	{delay 3
		{play_sound "wrench_turn"}
	}
	{delay 3.6
		{play_sound "wrench_turn"}
	}
	{delay 4.2
		{play_sound "wrench_turn"}
	}
	{delay 5.4
		{play_sound "toolbox_close"}
	}
	{delay 6		
		{play_sound "toolbox_open"}
	}
	{delay 6.6
		{play_sound "tool_equip"}
	}
	{delay 7.2
		{play_sound "screw_twist"}
	}
	{delay 7.8
		{play_sound "screw_twist"}
	}
	{delay 8.4
		{play_sound "screw_twist"}
	}	
	{delay 9
		{play_sound "screw_twist"}
	}	
	{delay 9.6
		{play_sound "screw_twist"}
	}	
	{delay 10.2
		{play_sound "screw_twist"}
	}	
	{delay 10.8
		{play_sound "screw_twist"}
	}		
	{delay 12	
		{play_sound "toolbox_close"}
	}
)
(define "repair_sounds_2" ;// Define Sound for Repair animation on Recovery vehicles
	{delay 0.6
		{play_sound "toolbox_open"}
	}
	{delay 1.2
		{play_sound "tool_equip"}
	}
	{delay 1.8
		{play_sound "screw_twist"}
	}
	{delay 2.4
		{play_sound "screw_twist"}
	}
	{delay 3
		{play_sound "screw_twist"}
	}
	{delay 3.6
		{play_sound "screw_twist"}
	}
	{delay 4.2
		{play_sound "screw_twist"}
	}
	{delay 5.4
		{play_sound "toolbox_close"}
	}
	{delay 6		
		{play_sound "toolbox_open"}
	}
	{delay 6.6
		{play_sound "tool_equip"}
	}
	{delay 7.2
		{play_sound "wrench_turn"}
	}
	{delay 7.8
		{play_sound "wrench_turn"}
	}
	{delay 8.4
		{play_sound "wrench_turn"}
	}	
	{delay 9
		{play_sound "wrench_turn"}
	}	
	{delay 9.6
		{play_sound "wrench_turn"}
	}	
	{delay 10.2
		{play_sound "wrench_turn"}
	}	
	{delay 10.8
		{play_sound "wrench_turn"}
	}	
	{delay 12	
		{play_sound "toolbox_close"}
	}
)
(define "repair_sounds_stop" ;// Define that Stops Sound for Repair animation on Recovery vehicles
		{stop_sound "toolbox_open"}
		{stop_sound "toolbox_close"}
		{stop_sound "wrench_turn"}
		{stop_sound  "screw_twist"}
		{stop_sound "tool_equip"}
)	

(define "repair_anm_script_panther_f" ;// break/repair anm for components
	{on break
		{if not tagged "exploded"
			{if component "shieldl1"
				{call "lights_off"}
				{tags remove "lights_on"}
			}
			{if component "engine"
				{ani_play "engine_b" +1}
			}
			{if component "gun"
				{ani_play "gun_b" +1}
			}
			{if component "turret"
				{ani_play "turret_b" +1}
			}
			{if component "body"
				{ani_play "body_b" +1}
			}
		}
		{call_synced "repair_anm_script_panther_f"}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1}
			}
		}
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1}
			}
		}
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1}
			}
		}
		{call_synced "repair_anm_script_panther_f"}
	}
)

(define "repair_anm_script_v1" ;// break/repair anm for components
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1}
			}
			{if component "gun"
				{ani_play "gun_b" +1}
			}
			{if component "turret"
				{ani_play "turret_b" +1}
			}
			{if component "body"
				{ani_play "body_b" +1}
			}
			{if component "bodyback"
				{ani_play "bodyback_b" +1}
			}
			{if component "gun1"
				{ani_play "gun1_b" +1}
			}
		}
		{call_synced "repair_anm_script_v1"}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1}
			}
		}
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1}
			}
		}
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1}
			}
		}
		{if component "bodyback"
			{if work "bodyback"
				{ani_play "bodyback_r" +1}
			}
		}
		{if component "gun1"
			{if work "gun1"
				{ani_play "gun1_r" +1}
			}
		}
		{call_synced "repair_anm_script_v1"}
	}
)

(define "repair_anm_script_jag_ii" ;// break/repair anm for components
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1}
			}
			{if component "gun"
				{ani_play "gun_b" +1}
			}
			{if component "body"
				{ani_play "body_b" +1}
			}
			{if component "trackleft"
				{ani_play "trackl_b" +1}
			}
			{if component "trackright"
				{ani_play "trackr_b" +1}
			}
		}
		{call_synced "repair_anm_script_jag_ii"}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1}
			}
		}
		{if component "body"
			{if work "turret"
				{ani_play "body_r" +1}
			}
		}
		{if component "trackleft"
			{if work "trackleft"
				{ani_play "trackl_r" +1}
			}
		}
		{if component "trackright"
			{if work "trackright"
				{ani_play "trackr_r" +1}
			}
		}
		{call_synced "repair_anm_script_jag_ii"}
	}
)

(define "repair_anm_script_chi_ha_sg" ;// break/repair anm for components
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1}
			}
			{if component "gun"
				{ani_play "gun_b" +1}
			}
			{if component "turret"
				{ani_play "turret_b" +1}
			}
			{if component "body"
				{ani_play "body_b" +1}
			}
			{if component "box_ammo"
				{if rand 0.5
					{spawn "explosion_ammo" "box_turret"}
					{components "box_ammo" destroy}
					{volumes "box_ammo1" disable bullet blast contact}
				else
					{components "body" destroy}
				}	
			}
		}
		{call_synced "repair_anm_script_chi_ha_sg"}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1}
			}
		}
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1}
			}
		}
		{if component "body"
			{if work "turret"
				{ani_play "body_r" +1}
			}
		}
		{call_synced "repair_anm_script_chi_ha_sg"}
	}
)

(define "repair_anm_script_ho_to" ;// break/repair anm for components
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1}
			}
			{if component "gun"
				{ani_play "gun_b" +1}
			}
			{if component "body"
				{ani_play "body_b" +1}
			}
			{if component "box_ammo"
				{if rand 0.5
					{spawn "explosion_ammo" "ammo_box"}
					{components "box_ammo" destroy}
					{volumes "box_ammo1" disable bullet blast contact}
					{bone hide "body_hatch2"}
					{bone hide "body_hatch1"}
				else
					{components "body" destroy}
				}		
			}
		}
		{call_synced "repair_anm_script_ho_to"}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1}
			}
		}
		{if component "body"
			{if work "turret"
				{ani_play "body_r" +1}
			}
		}
		{call_synced "repair_anm_script_ho_to"}
	}
)

(define "repair_anm_script_ho_ni_ii" ;// break/repair anm for components
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1}
			}
			{if component "gun"
				{ani_play "gun_b" +1}
			}
			{if component "body"
				{ani_play "body_b" +1}
			}
			{if component "box_ammo"
				{if rand 0.5
					{spawn "explosion_ammo" "box_turret1"}
					{components "box_ammo" destroy}
					{volumes "box_ammo1" disable bullet blast contact}
					{volumes "box_ammo" disable bullet blast contact}
					{bone hide "box_turret1"}
					{bone hide "box_turret2"}
				else
					{components "body" destroy}
				}
			}
		}
		{call_synced "repair_anm_script_ho_ni_ii"}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1}
			}
		}
		{if component "body"
			{if work "turret"
				{ani_play "body_r" +1}
			}
		}
		{call_synced "repair_anm_script_ho_ni_ii"}
	}
)

(define "repair_anm_script_ho_ro" ;// break/repair anm for components
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1}
			}
			{if component "gun"
				{ani_play "gun_b" +1}
			}
			{if component "body"
				{ani_play "body_b" +1}
			}
			{if component "box_ammo"
				{if rand 0.5
					{spawn "explosion_ammo" "box_turret"}
					{components "box_ammo" destroy}
					{volumes "box_ammo1" disable bullet blast contact}
				else
					{components "body" destroy}
				}	
			}
		}
		{call_synced "repair_anm_script_ho_ro"}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1}
			}
		}
		{if component "body"
			{if work "turret"
				{ani_play "body_r" +1}
			}
		}
		{call_synced "repair_anm_script_ho_ro"}
	}
)

(define "repair_anm_script_shi_ki" ;// break/repair anm for components
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1}
			}
			{if component "gun"
				{ani_play "gun_b" +1}
			}
			{if component "body"
				{ani_play "body_b" +1}
			}
			{if component "aux_turret1"
				{ani_play "aux_turret1_b" +1}
			}
		}
		{call_synced "repair_anm_script_shi_ki"}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1}
			}
		}
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1}
			}
		}
		{if component "aux_turret1"
			{if work "aux_turret1"
				{ani_play "aux_turret1_r" +1}
			}
		}
		{call_synced "repair_anm_script_shi_ki"}
	}
)

(define "repair_anm_script_skink" ;// break/repair anm for components
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "gun"
				{ani_play "gun_b" +1}
			}
			{if component "gun1"
				{weapon_work "gun2" 0}
				{ani_play "gun1_b" +1}
			}
		}
		{call_synced "repair_anm_script_skink"}
	}
	{on repair
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1}
			}
		}
		{if component "gun1"
			{if work "gun1"
				{weapon_work "gun2" 1}
				{ani_play "gun1_r" +1}
			}
		}
		{call_synced "repair_anm_script_skink"}
	}
)

{"wanze_radio_death" ;//
	{on "vehicle_destroyed" overload
		{if not tagged "vehicle_destroyed"
			{if not tagged "ammo_cooked2"
				{if not tagged "need_ammo1"
					{tags add "vehicle_destroyed"}
					{ani_wind "open" end}
					{ani_wind "open1" end}
					{tags add "no_scavenge"}		;// tag for conquest so that vehicle cannot be repaired/recovered
					{mark_for_persistence}			;// Conquest map persistence
					{if not tagged "body_break"
						{components "body" break}
					}
					;//{damage_report "body" "component/body_destroyed"}
					{able select 0}
					{able repaired 0}
					{able minimap 0}
					{delay 2
						{kick_entity_manager}
						{tags add "destroyed"}
					}
					{if not tagged "exploded"
						;//{view pause "cooking_presmoke_1"}
						{view start "fire_vehicle_death"}
						{play_sound "flame_1" 1}
						{clear_inventory}
						{delay 500 60
							{if not tagged "exploded"
								{view pause "fire_vehicle_death"}
								{view start "smoke_vehicle_death"}
								{stop_sound "flame_1"}
							}
						}
					}
					{delay 600
						{tags add "tele_rory_1"}
						{if rand 0.5
							{components "ammo" break}
						}
						{if not tagged "vehicle_destroyed"
							{delay 300	
								{tags add "tele_rory_2"}
								{if rand 0.25
									{components "ammo" break}
								}
								{if not tagged "vehicle_destroyed"
									{delay 150
										{tags add "tele_rory_3"}
										{if rand 0.1
											{components "ammo" break}
										}
									}
								}
							}
						}
					}
				else
					{delay 0.1
						{if not tagged "vehicle_destroyed"
							{if not tagged "ammo_cooked2"
								{tags add "vehicle_destroyed"}
								{ani_wind "open" end}
								{ani_wind "open1" end}
								{tags add "no_scavenge"}		;// tag for conquest so that vehicle cannot be repaired/recovered
								{mark_for_persistence}			;// Conquest map persistence
								{if not tagged "body_break"
									{components "body" break}
								}
								;//{damage_report "body" "component/body_destroyed"}
								{able select 0}
								{able repaired 0}
								{able minimap 0}
								{delay 2
									{kick_entity_manager}
									{tags add "destroyed"}
								}
								{if not tagged "exploded"
									;//{view pause "cooking_presmoke_1"}
									{view start "fire_vehicle_death"}
									{play_sound "flame_1" 1}
									{clear_inventory}
									{delay 500 60
										{if not tagged "exploded"
											{view pause "fire_vehicle_death"}
											{view start "smoke_vehicle_death"}
											{stop_sound "flame_1"}
										}
									}
								}
								{delay 200 200
									{if rand 0.3
										{call_synced "rand_break_body"}
									}
								}
							}
						}	
					}	
				}					
			}
		}
	}
}

{"m2a2_fuel_tank"
	(define "m2_fuel_explode"
		{delay 0.1
			{delay 10
				{spawn "ex_fuel_tank" "fxfire1"} 
			}
			{play_sound "flame1" 1}
			{burn volume "m2_fuel" fx "fire_fueltank_small" time 15 fake even_law}
			{delay 10
				{burn volume "m2_fuel" fx "fire_fueltank" time 30 fake even_law}
				{components "engine" destroy}
				{stop_sound "flame1" 1}
			}
		}
		{call_synced "m2_fuel_explode"}
	)
	{on pierce sync
		{vehicle_health_damage_pierce}
		{if component "m2_fuel"
			{if not work "m2_fuel"
				{if stuff "ptr"						;// at rifles goes first then bullet
					{delay 5 5
						("m2_fuel_explode") 
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "auto"
					{delay 5 5
						("m2_fuel_explode") 
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "bullet"
					{delay 5 5
						("m2_fuel_explode") 
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "shell"
						("m2_fuel_explode") 
					{burn fx "fire_fueltank_pierce_big" time 15 fake}
				}
			}
		}
	}
	{on break_armor
		{if component "m2_fuel"
			{if not able "exploded"
				{if name "pierce"
					{if stuff "auto"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "bullet"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "shell"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
				}
				{if name "blast"
					{if min_energy 20
						{call "m2_fuel_explode"}
					else min_energy 10
						{if rand 1
							{call "m2_fuel_explode"}
						}
					}
				}
			}
		}
	}
}	

{"smoke 12shot"					;// Nebelwurfgerät - German smoke grenade launcher
	{on "smoke_screen"
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot1 -17 0.5 0 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot4 -17 0.5 0.1 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot2 -17 0.5 0.2 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot5 -17 0.5 0.3 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot3 -17 0.5 0.4 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot6 -17 0.5 0.5 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot7 -17 0.5 0.5 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot8 -17 0.5 0.5 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot9 -17 0.5 0.5 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot10 -17 0.5 0.5 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot11 -17 0.5 0.5 20)
		("smoke_shot" args "51mm_eng_mortar_wp" smoke_shot12 -17 0.5 0.5 20)
	}
}

{"tank"
	(define "smine_shot"				;// spawns smoke grenade on vehicle and gives impulse instructions
		{delay %4
			{spawn %0 "%1" x
				{impulse forward %2 %3 rnd_dir %3 %3}
				{call "activate"}
			}
			{spawn "flash_grenade_launcher" "fx%1" x}	;// plays flash at grenade spawn/launch
			{bone hide "%1_cap_mine"}
		}
		{delay %5
			{bone show "%1_cap_mine"}
		}
	)
	{on "deploy_smine"					;// UI button to deploy vehicle smoke screen
		{if operatable
			{if work "body"
				{call "smine_screen"}
			}
		}
	}
	{on contact	
		{if tagged "_user" ;// MACE LUNGE MINE AI
			{if not tagged "body_break"
				{if not "broken"
					{if effector "ni_5_lunge_mine_ai"
						{spawn "explosion_lunge_mine"}	
					}
				}	
			}	
		}
	}	
}

{"cannon"
	{on contact	
		{if tagged "_user" ;// MACE LUNGE MINE AI
			{if not tagged "body_break"
				{if not "broken"
					{if effector "ni_5_lunge_mine_ai"
						{spawn "explosion_lunge_mine"}	
					}
				}	
			}
		}
	}
}	

{"car"
	{on contact	
		{if tagged "_user" ;// MACE LUNGE MINE AI
			{if not tagged "body_break"
				{if not "broken"
					{if effector "ni_5_lunge_mine_ai"
						{spawn "explosion_lunge_mine"}	
					}
				}	
			}
		}
	}
}	

{"gas"
	(define "gas_start" ;// GAS SCRIPT START	
		(define "spawn_zone"
			{spawn "killzone_inf_gas_600"}
			{spawn "killzone_veh_gas_600"}
		)
		(define "spawn_zone_light"
			{spawn "killzone_inf_gas_light_600"}
			{spawn "killzone_veh_gas_light_600"}
		)
		{view start "escape"}
		{play_sound "gas_release" 1}
		{delay 4
			{view start "cloud1"}
		}		
		{delay 15
			{view pause "cloud1"}
			{view start "cloud2"}
			{view start "cloud3"}
			("spawn_zone")
		}
		{delay 20
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 25
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 30
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 35
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 40
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 45
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 50
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 55
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 60
			("spawn_zone")
			("spawn_zone_light")
			{view pause "escape"}
			{stop_sound "gas_release"}
		}
		{delay 65
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 75
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 80
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 85
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 90
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 95
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 100
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 105
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 110
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 115
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 125
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 135
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 145
			{view pause "cloud2"}
			{view pause "cloud3"}
			{view start "cloud1"}
			("spawn_zone")
		}
		{delay 155
			("spawn_zone")
		}
		{delay 165
			("spawn_zone")
		}
		{delay 175
			("spawn_zone")
		}
		{delay 180
			{view pause "cloud1"}
		}
		{call_synced "gas"}		
	)
	{on "deploy_gas"					;// UI button to deploy vehicle smoke screen
		{if operatable
			{if work "body"
				("gas_start")
			}
		}
	}		
}

{"trailer_gas_destroyed"
	(define "gas_explode" ;// GAS SCRIPT EXPLODE
		(define "spawn_zone"
			{spawn "killzone_inf_gas_600"}
			{spawn "killzone_veh_gas_600"}
		)
		(define "spawn_zone_light"
			{spawn "killzone_inf_gas_light_600"}
			{spawn "killzone_veh_gas_light_600"}
		)
		{delay 5
			("spawn_zone")
			("spawn_zone_light")
		}		
		{delay 10
			("spawn_zone")
			("spawn_zone_light")
			{stop_sound "flame"}
		}
		{delay 15
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 20
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 25
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 30
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 35
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 40
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 45
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 50
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 55
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 60
			("spawn_zone")
			{view pause "cloud2"}
			{view pause "cloud3"}
		}
		{delay 65
			("spawn_zone")
		}
	)	
}

{"char2c"	;// alternate fuel type
	{on spawn
		{tags add "add_exhaustview"}
	}
	{on "add_exhaustview" overload
				{add_view	"exhaust_dark_big"				"exhaust"			   "FXsmoke4"} ;// engine exhaust
				{add_view	"exhaust_dark_big"				"exhaust"			   "FXsmoke5"} ;// engine exhaust
				{add_view	"exhaust_dark_small2"			"exhaust2"			   "FXsmoke1"} ;// idle exhaust
				{add_view	"exhaust_dark_small2"			"exhaust2"			   "FXsmoke2"} ;// idle exhaust
				{add_view	"exhaust_dark_small2"			"exhaust2"			   "FXsmoke3"} ;// idle exhaust
				{add_view	"exhaust_dark_small2"			"exhaust2"			   "FXsmoke4"} ;// idle exhaust		
				{add_view	"exhaust_dark_small2"			"exhaust2"			   "FXsmoke5"} ;// idle exhaust
	}
}
{"fuel_char2c"
	(define "fueltank_fire1"
			{if not tagged "fueltank_fire1"
			{tags add "fueltank_fire1"}
			{if tagged "fueltank_fire_count1"
					; do nothing
			else tagged "fueltank_fire_count2"
					; do nothing
			else tagged "fueltank_fire_count3"
					; do nothing
			else tagged "fueltank_fire_count4"
					; do nothing
			else tagged "fueltank_fire_count5"
					; do nothing
			else tagged "fueltank_fire_count6"
					; do nothing
			else tagged "fueltank_fire_count7"
					; do nothing
			else
					{tags add "fueltank_fire_count1"}
			}
			{play_sound "flame1" 1}
			{burn volume "fuel_tank1" fx "fire_fueltank_small" time 15 fake even_law}
			{delay 10 5
				{burn volume "fuel_tank1" fx "fire_fueltank" time 30 fake even_law}
				{delay 20 10
					("explosion_fuel1") ;{call "explosion_fuel1"}
				}
			}
		}
	)
	(define "explosion_fuel1"
		{delay 0.1
			{burn volume "fuel_tank1" fx "fire_fueltank" time 120 fake even_law}
			{delay 120
				{stop_sound "flame1"}
				{burn volume "fuel_tank1" fx "smoke_vehicle_death" time 120 fake even_law}
			}
		}
		{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
                	{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
                	{tags add "fueltank_fire_count3"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
                	{tags add "fueltank_fire_count4"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
                	{tags add "fueltank_fire_count5"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
                	("fueltank_fire_count_final") ;{call "fueltank_fire_count_final"}
		}
	)
	(define "fueltank_fire2"
		{if not tagged "fueltank_fire2"
			{tags add "fueltank_fire2"}
			{if tagged "fueltank_fire_count1"
					; do nothing
			else tagged "fueltank_fire_count2"
					; do nothing
			else tagged "fueltank_fire_count3"
					; do nothing
			else tagged "fueltank_fire_count4"
					; do nothing
			else tagged "fueltank_fire_count5"
					; do nothing
			else tagged "fueltank_fire_count6"
					; do nothing
			else tagged "fueltank_fire_count7"
					; do nothing
			else
					{tags add "fueltank_fire_count1"}
			}
			{play_sound "flame2" 1}
			{burn volume "fuel_tank2" fx "fire_fueltank_small" time 15 fake even_law}
			{delay 10 5
				{burn volume "fuel_tank2" fx "fire_fueltank" time 30 fake even_law}
				{delay 20 10
					("explosion_fuel2") ;{call "explosion_fuel2"}
				}
			}
		}
	)
	(define "explosion_fuel2"
		{delay 0.1
			{burn volume "fuel_tank2" fx "fire_fueltank" time 120 fake even_law}
			{delay 120
				{stop_sound "flame2"}
				{burn volume "fuel_tank2" fx "smoke_vehicle_death" time 120 fake even_law}
			}
		}
		{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
                	{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
                	{tags add "fueltank_fire_count3"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
                	{tags add "fueltank_fire_count4"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
                	{tags add "fueltank_fire_count5"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
                	("fueltank_fire_count_final") ;{call "fueltank_fire_count_final"}
		}
	)
	(define "fueltank_fire3"
		{if not tagged "fueltank_fire3"
			{tags add "fueltank_fire3"}
			{if tagged "fueltank_fire_count1"
					; do nothing
			else tagged "fueltank_fire_count2"
					; do nothing
			else tagged "fueltank_fire_count3"
					; do nothing
			else tagged "fueltank_fire_count4"
					; do nothing
			else tagged "fueltank_fire_count5"
					; do nothing
			else tagged "fueltank_fire_count6"
					; do nothing
			else tagged "fueltank_fire_count7"
					; do nothing
			else
					{tags add "fueltank_fire_count1"}
			}
			{play_sound "flame3" 1}
			{burn volume "fuel_tank3" fx "fire_fueltank_small" time 15 fake even_law}
			{delay 10 5
				{burn volume "fuel_tank3" fx "fire_fueltank" time 30 fake even_law}
				{delay 20 10
					("explosion_fuel3") ;{call "explosion_fuel3"}
				}
			}
		}
	)
	(define "explosion_fuel3"
		{delay 0.1
			{burn volume "fuel_tank3" fx "fire_fueltank" time 120 fake even_law}
			{delay 120
				{stop_sound "flame3"}
				{burn volume "fuel_tank3" fx "smoke_vehicle_death" time 120 fake even_law}
			}
		}
		{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
                	{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
                	{tags add "fueltank_fire_count3"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
                	{tags add "fueltank_fire_count4"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
                	{tags add "fueltank_fire_count5"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
                	("fueltank_fire_count_final") ;{call "fueltank_fire_count_final"}
		}
	)
	(define "fueltank_fire4"
		{if not tagged "fueltank_fire4"
			{tags add "fueltank_fire4"}
			{if tagged "fueltank_fire_count1"
					; do nothing
			else tagged "fueltank_fire_count2"
					; do nothing
			else tagged "fueltank_fire_count3"
					; do nothing
			else tagged "fueltank_fire_count4"
					; do nothing
			else tagged "fueltank_fire_count5"
					; do nothing
			else tagged "fueltank_fire_count6"
					; do nothing
			else tagged "fueltank_fire_count7"
					; do nothing
			else
					{tags add "fueltank_fire_count1"}
			}
			{play_sound "flame4" 1}
			{burn volume "fuel_tank4" fx "fire_fueltank_small" time 15 fake even_law}
			{delay 10 5
				{burn volume "fuel_tank4" fx "fire_fueltank" time 30 fake even_law}
				{delay 20 10
					("explosion_fuel4") ;{call "explosion_fuel4"}
				}
			}
		}
	)
	(define "explosion_fuel4"
		{delay 0.1
			{burn volume "fuel_tank4" fx "fire_fueltank" time 120 fake even_law}
			{delay 120
				{stop_sound "flame4"}
				{burn volume "fuel_tank4" fx "smoke_vehicle_death" time 120 fake even_law}
			}
		}
		{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
                	{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
                	{tags add "fueltank_fire_count3"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
                	{tags add "fueltank_fire_count4"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
                	{tags add "fueltank_fire_count5"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
                	("fueltank_fire_count_final") ;{call "fueltank_fire_count_final"}
		}
	)
	(define "fueltank_fire5"
		{if not tagged "fueltank_fire7"
			{tags add "fueltank_fire5"}
			{if tagged "fueltank_fire_count1"
					; do nothing
			else tagged "fueltank_fire_count2"
					; do nothing
			else tagged "fueltank_fire_count3"
					; do nothing
			else tagged "fueltank_fire_count4"
					; do nothing
			else tagged "fueltank_fire_count5"
					; do nothing
			else tagged "fueltank_fire_count6"
					; do nothing
			else tagged "fueltank_fire_count7"
					; do nothing
			else
					{tags add "fueltank_fire_count1"}
			}
			{play_sound "flame5" 1}
			{burn volume "fuel_tank5" fx "fire_fueltank_small" time 15 fake even_law}
			{delay 10 5
				{burn volume "fuel_tank5" fx "fire_fueltank" time 30 fake even_law}
				{delay 20 10
					("explosion_fuel5") ;{call "explosion_fuel5"}
				}
			}
		}
	)
	(define "explosion_fuel5"
		{delay 0.1
			{burn volume "fuel_tank5" fx "fire_fueltank" time 120 fake even_law}
			{delay 120
				{stop_sound "flame5"}
				{burn volume "fuel_tank5" fx "smoke_vehicle_death" time 120 fake even_law}
			}
		}
		{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
                	{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
                	{tags add "fueltank_fire_count3"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
                	{tags add "fueltank_fire_count4"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
                	{tags add "fueltank_fire_count5"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
                	("fueltank_fire_count_final") ;{call "fueltank_fire_count_final"}
		}
	)
	(define "fueltank_fire6"
		{if not tagged "fueltank_fire6"
			{tags add "fueltank_fire6"}
			{if tagged "fueltank_fire_count1"
					; do nothing
			else tagged "fueltank_fire_count2"
					; do nothing
			else tagged "fueltank_fire_count3"
					; do nothing
			else tagged "fueltank_fire_count4"
					; do nothing
			else tagged "fueltank_fire_count5"
					; do nothing
			else tagged "fueltank_fire_count6"
					; do nothing
			else tagged "fueltank_fire_count7"
					; do nothing
			else
					{tags add "fueltank_fire_count1"}
			}
			{play_sound "flame6" 1}
			{burn volume "fuel_tank6" fx "fire_fueltank_small" time 15 fake even_law}
			{delay 10 5
				{burn volume "fuel_tank6" fx "fire_fueltank" time 30 fake even_law}
				{delay 20 10
					("explosion_fuel6") ;{call "explosion_fuel6"}
				}
			}
		}
	)
	(define "explosion_fuel6"
		{delay 0.1
			{burn volume "fuel_tank6" fx "fire_fueltank" time 120 fake even_law}
			{delay 120
				{stop_sound "flame6"}
				{burn volume "fuel_tank6" fx "smoke_vehicle_death" time 120 fake even_law}
			}
		}
		{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
                	{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
                	{tags add "fueltank_fire_count3"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
                	{tags add "fueltank_fire_count4"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
                	{tags add "fueltank_fire_count5"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
                	("fueltank_fire_count_final") ;{call "fueltank_fire_count_final"}
		}
	)
	(define "fueltank_fire7"
		{if not tagged "fueltank_fire7"
			{tags add "fueltank_fire7"}
			{if tagged "fueltank_fire_count1"
					; do nothing
			else tagged "fueltank_fire_count2"
					; do nothing
			else tagged "fueltank_fire_count3"
					; do nothing
			else tagged "fueltank_fire_count4"
					; do nothing
			else tagged "fueltank_fire_count5"
					; do nothing
			else tagged "fueltank_fire_count6"
					; do nothing
			else tagged "fueltank_fire_count7"
					; do nothing
			else
					{tags add "fueltank_fire_count1"}
			}
			{play_sound "flame7" 1}
			{burn volume "fuel_tank7" fx "fire_fueltank_small" time 15 fake even_law}
			{delay 10 5
				{burn volume "fuel_tank7" fx "fire_fueltank" time 30 fake even_law}
				{delay 20 10
					("explosion_fuel7") ;{call "explosion_fuel7"}
				}
			}
		}
	)
	(define "explosion_fuel7"
		{delay 0.1
			{burn volume "fuel_tank7" fx "fire_fueltank" time 120 fake even_law}
			{delay 120
				{stop_sound "flame7"}
				{burn volume "fuel_tank7" fx "smoke_vehicle_death" time 120 fake even_law}
			}
		}
		{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
                	{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
                	{tags add "fueltank_fire_count3"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
                	{tags add "fueltank_fire_count4"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
                	{tags add "fueltank_fire_count5"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			("fueltank_fire_count_final") ;{call "fueltank_fire_count_final"}
		}
	)
	(define "fueltank_fire_count_final"
		{add_view	"fire_dead_turret"			"fire_explosion1"			   "fuel_explosion_fire1"} ;// idle exhaust
		{add_view	"fire_dead_tank"			"fire_explosion2"			   "fuel_explosion_fire2"} ;// idle exhaust
		{add_view	"smoke_fire_fuel"			"fire_engine1"			   "fuel_engine_fire2"} ;// idle exhaust
		{add_view	"fire_dead_vehicle_low"			"fire_engine2"			   "fuel_engine_fire1"} ;// idle exhaust
		{delay 8.5
			{start_sound "detonation/explosion_vehicle"}	;//explosion sound
			{spawn "tank_die_peaceful_light" "fuel_explosion1"}
			{view start "fire_explosion1"}
			{tear "piece_large_steel" bone "engine_hatch4"
				{impulse up 1.5 rnd_dir 2}
			}
			{tear "piece_large_steel" bone "engine_hatch3"
				{impulse up 1.5 rnd_dir 2}
			}
		}
		{delay 13
			{start_sound "detonation/explosion_vehicle"}	;//explosion sound
			{view start "fire_engine1"}
			{spawn "tank_die_peaceful_light" "fuel_explosion3"}
			{bone hide "towing"}
			{bone Show "towing_xx"}
			{tear "piece_large_steel" bone "towing_xx"
				{impulse up 1.5 rnd_dir 2}
			}
			{delay 0.5
				{volumes "towing_xx" enable bullet blast}
				{volumes "towing" disable bullet blast}
			}
		}
		{delay 16.5
			{start_sound "detonation/explosion_vehicle"}	;//explosion sound
			{spawn "tank_die_peaceful_light" "ammo_crate_die"}
			{view start "fire_explosion2"}
			{tear "piece_large_steel" bone "engine_hatch6"
				{impulse up 1.5 rnd_dir 2}
			}
		}
		{delay 19.5
			{view start "fire_engine2"}
			{components "engine" break}
		}
		{delay 25
			{start_sound "detonation/explosion_vehicle"}	;//explosion sound
			{bone hide "aux_turret1"}
			{bone hide "gunner_cupola"}
			{bone Show "aux_turret1_xx"}
			{bone Show "gunner_cupola_xx"}
			{spawn "aero_die" "aux_turret1"}
			{tear "piece_large_steel" bone "aux_turret1_xx"
				{impulse up 10 rnd_dir 2}
			}
		{delay 0.5
			{volumes "aux_turret1_xx" enable bullet blast}
			{volumes "aux_turret1" disable bullet blast}
		}
		}
		{delay 29
			{call "explosion"}
		}
		{delay 160
			{view stop "fire_explosion1"}
			{view stop "fire_explosion2"}
			{view stop "fire_engine2"}
			{view stop "fire_engine1"}
		}
			
	)
	{on spawn
		{link_sound "flame1"						"fire/metal"}
		{link_sound "flame2"						"fire/metal"}
		{link_sound "flame3"						"fire/metal"}
		{link_sound "flame4"						"fire/metal"}
		{link_sound "flame5"						"fire/metal"}
		{link_sound "flame6"						"fire/metal"}
		{link_sound "flame7"						"fire/metal"}
	}
	{on pierce sync
		{vehicle_health_damage_pierce}
		{if component "fuel_tank1"
			{if not work "fuel_tank1"
				{if stuff "ptr"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire1") ;{call "fueltank_fire1"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "auto"
					{delay 5 5
						("fueltank_fire1") ;{call "fueltank_fire1"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "bullet"
					{delay 5 5
						("fueltank_fire1") ;{call "fueltank_fire1"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "shell"
						("fueltank_fire1") ;{call "fueltank_fire1"}
					{burn fx "fire_fueltank_pierce_big" time 15 fake}
				}
			}
		}
		{if component "fuel_tank2"
			{if not work "fuel_tank2"
				{if stuff "ptr"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire2") ;{call "fueltank_fire2"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "auto"
					{delay 5 5
						("fueltank_fire2") ;{call "fueltank_fire2"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "bullet"
					{delay 5 5
						("fueltank_fire2") ;{call "fueltank_fire2"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "shell"
						("fueltank_fire2") ;{call "fueltank_fire2"}
					{burn fx "fire_fueltank_pierce_big" time 15 fake}
				}
			}
		}
		{if component "fuel_tank3"
			{if not work "fuel_tank3"
				{if stuff "ptr"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire3") ;{call "fueltank_fire3"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "auto"
					{delay 5 5
						("fueltank_fire3") ;{call "fueltank_fire3"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "bullet"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire3") ;{call "fueltank_fire3"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "shell"
						("fueltank_fire3") ;{call "fueltank_fire3"}
					{burn fx "fire_fueltank_pierce_big" time 15 fake}
				}
			}
		}
		{if component "fuel_tank4"
			{if not work "fuel_tank4"
				{if stuff "ptr"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire4") ;{call "fueltank_fire4"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "bullet"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire4") ;{call "fueltank_fire4"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "auto"
					{delay 5 5
						("fueltank_fire4") ;{call "fueltank_fire4"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "shell"
						("fueltank_fire4") ;{call "fueltank_fire4"}
					{burn fx "fire_fueltank_pierce_big" time 15 fake}
				}
			}
		}
		{if component "fuel_tank5"
			{if not work "fuel_tank5"
				{if stuff "ptr"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire5") ;{call "fueltank_fire5"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "bullet"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire5") ;{call "fueltank_fire5"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "auto"
					{delay 5 5
						("fueltank_fire5") ;{call "fueltank_fire5"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "shell"
						("fueltank_fire5") ;{call "fueltank_fire5"}
					{burn fx "fire_fueltank_pierce_big" time 15 fake}
				}
			}
		}
		{if component "fuel_tank6"
			{if not work "fuel_tank6"
				{if stuff "ptr"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire6") ;{call "fueltank_fire6"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "bullet"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire6") ;{call "fueltank_fire6"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "auto"
					{delay 5 5
						("fueltank_fire6") ;{call "fueltank_fire6"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "shell"
						("fueltank_fire6") ;{call "fueltank_fire6"}
					{burn fx "fire_fueltank_pierce_big" time 15 fake}
				}
			}
		}
		{if component "fuel_tank7"
			{if not work "fuel_tank7"
				{if stuff "ptr"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire7") ;{call "fueltank_fire7"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "bullet"						;// at rifles goes first then bullet
					{delay 5 5
						("fueltank_fire7") ;{call "fueltank_fire7"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "auto"
					{delay 5 5
						("fueltank_fire7") ;{call "fueltank_fire7"}
					}
					{burn fx "fire_fueltank_pierce_medium" time 15 fake}
				else stuff "shell"
						("fueltank_fire7") ;{call "fueltank_fire7"}
					{burn fx "fire_fueltank_pierce_big" time 15 fake}
				}
			}
		}
	}
	{on blast
		{if component "fuel_tank1"
			{if min_energy 40
				{component destroy}
				("explosion_fuel1") ;{call "explosion_fuel1"}
			}
			{delay 0.1
				{if not work "fuel_tank1"
					("fueltank_fire1") ;{call "fueltank_fire1"}
				}
			}
		}
		{if component "fuel_tank2"
			{if min_energy 40
				{component destroy}
				("explosion_fuel2") ;{call "explosion_fuel2"}
			}
			{delay 0.1
				{if not work "fuel_tank2"
					("fueltank_fire2") ;{call "fueltank_fire2"}
				}
			}
		}
		{if component "fuel_tank3"
			{if min_energy 40
				{component destroy}
				("explosion_fuel3") ;{call "explosion_fuel3"}
			}
			{delay 0.1
				{if not work "fuel_tank3"
					("fueltank_fire3") ;{call "fueltank_fire3"}
				}
			}
		}
		{if component "fuel_tank4"
			{if min_energy 40
				{component destroy}
				("explosion_fuel4") ;{call "explosion_fuel4"}
			}
			{delay 0.1
				{if not work "fuel_tank4"
					("fueltank_fire4") ;{call "fueltank_fire4"}
				}
			}
		}
		{if component "fuel_tank5"
			{if min_energy 40
				{component destroy}
				("explosion_fuel5") ;{call "explosion_fuel5"}
			}
			{delay 0.1
				{if not work "fuel_tank5"
					("fueltank_fire5") ;{call "fueltank_fire5"}
				}
			}
		}
		{if component "fuel_tank6"
			{if min_energy 40
				{component destroy}
				("explosion_fuel6") ;{call "explosion_fuel6"}
			}
			{delay 0.1
				{if not work "fuel_tank6"
					("fueltank_fire6") ;{call "fueltank_fire6"}
				}
			}
		}
		{if component "fuel_tank7"
			{if min_energy 40
				{component destroy}
				("explosion_fuel7") ;{call "explosion_fuel7"}
			}
			{delay 0.1
				{if not work "fuel_tank7"
					("fueltank_fire7") ;{call "fueltank_fire7"}
				}
			}
		}
	}
	{on break_armor
		{if component "fuel_tank1"
			{if not able "exploded"
				{if name "pierce"
					{if stuff "auto"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "bullet"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "shell"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
				}
				{if name "blast"
					{if min_energy 20
						{call "explosion_fuel1"}
					else min_energy 10
						{if rand 1
							{call "explosion_fuel1"}
						}
					}
				}
			}
		}
		{if component "fuel_tank2"
			{if not able "exploded"
				{if name "pierce"
					{if stuff "auto"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "bullet"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "shell"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
				}
				{if name "blast"
					{if min_energy 20
						("explosion_fuel2") ;{call "explosion_fuel2"}
					else min_energy 10
						{if rand 1
							("explosion_fuel2") ;{call "explosion_fuel2"}
						}
					}
				}
			}
		}
		{if component "fuel_tank3"
			{if not able "exploded"
				{if name "pierce"
					{if stuff "auto"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "bullet"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "shell"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
				}
				{if name "blast"
					{if min_energy 20
						("explosion_fuel3") ;{call "explosion_fuel3"}
					else min_energy 10
						{if rand 1
							("explosion_fuel3") ;{call "explosion_fuel3"}
						}
					}
				}
			}
		}
		{if component "fuel_tank4"
			{if not able "exploded"
				{if name "pierce"
					{if stuff "auto"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "bullet"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "shell"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
				}
				{if name "blast"
					{if min_energy 20
						("explosion_fuel4") ;{call "explosion_fuel4"}
					else min_energy 10
						{if rand 1
							("explosion_fuel4") ;{call "explosion_fuel4"}
						}
					}
				}
			}
		}
		{if component "fuel_tank5"
			{if not able "exploded"
				{if name "pierce"
					{if stuff "auto"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "bullet"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "shell"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
				}
				{if name "blast"
					{if min_energy 20
						("explosion_fuel5") ;{call "explosion_fuel5"}
					else min_energy 10
						{if rand 1
							("explosion_fuel5") ;{call "explosion_fuel5"}
						}
					}
				}
			}
		}
		{if component "fuel_tank6"
			{if not able "exploded"
				{if name "pierce"
					{if stuff "auto"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "bullet"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "shell"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
				}
				{if name "blast"
					{if min_energy 20
						("explosion_fuel6") ;{call "explosion_fuel6"}
					else min_energy 10
						{if rand 1
							("explosion_fuel6") ;{call "explosion_fuel6"}
						}
					}
				}
			}
		}
		{if component "fuel_tank7"
			{if not able "exploded"
				{if name "pierce"
					{if stuff "auto"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "bullet"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
					{if stuff "shell"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
				}
				{if name "blast"
					{if min_energy 20
						("explosion_fuel7") ;{call "explosion_fuel7"}
					else min_energy 10
						{if rand 1
							("explosion_fuel7") ;{call "explosion_fuel7"}
						}
					}
				}
			}
		}
	}
}
{"exaust_char2c"
	{on spawn
		{add_view	"flash_fuse_small"	"sparks1"	"exhaust_sparks_big"}
		{add_view	"spark_grenade"	"sparks2"	"exhaust_sparks_small"}
		{add_view	"smoke_dead_vehicle"	"smoke_ex1"	"exhaust_smoke1"}
		{add_view	"smoke_tank_hull_dead_engine"	"smoke_ex2"	"exhaust_smoke2"}
	}
	{on break	
		{if component "exhaust_body"					;// {on break} is for when components break
			{if not tagged "exploded"
				{bone hide "bodytop"}
				{bone hide "antenna"}
				{bone hide "fan1"}
				{bone hide "fan2"}
				{bone hide "fan3"}
				{bone hide "fan4"}
				{bone hide "exaust"}
				{bone hide "grid"}
				{bone show "upper_body_xx"}
				{bone Show "antenna_xx"}
				{bone show "fan1_xx"}
				{bone show "fan2_xx"}
				{bone show "fan3_xx"}
				{bone show "fan4_xx"}
				{bone show "exaust_xx"}
				{bone show "exaust2_xx"}
				{bone show "grid_xx"}
				{spawn "spark_wire_break" "exhaust_explosion_spark"}
				{tags add "exhaust_fucked"}
				{delay 0.5
					{view start "sparks1"}
					{view start "sparks2"}
				}
				{delay 2.5
					{view start "smoke_ex1"}
					{view start "smoke_ex2"}
				}
			}
		}
	}
	{on "stop_on"
		{if  tagged "exhaust_fucked"
			{if rand 0.3
				{components "transmission" break}
			}	
			{if rand 0.1
				{components "engine" break}
			}
		}
	}	
	{on move on
		{if  tagged "exhaust_fucked"
			{if rand 0.5
				{components "transmission" break}
			}
		}
	}
	{on repair
		{if component "exhaust_body"
			{tags remove "exhaust_fucked"}
			{view pause "sparks1"}
			{view pause "sparks2"}
			{view pause "smoke_ex1"}
			{view pause "smoke_ex2"}
			{bone show "bodytop"}
			{bone show "antenna"}
			{bone show "fan1"}
			{bone show "fan2"}
			{bone show "fan3"}
			{bone show "fan4"}
			{bone show "exaust"}
			{bone show "grid"}
			{bone hide "upper_body_xx"}
			{bone hide "antenna_xx"}
			{bone hide "fan1_xx"}
			{bone hide "fan2_xx"}
			{bone hide "fan3_xx"}
			{bone hide "fan4_xx"}
			{bone hide "exaust_xx"}
			{bone hide "exaust2_xx"}
			{bone hide "grid_xx"}
		}
	}
}

;/*=========== Vehicles MACE End ===========*/
;/*=========== MODERN USA Vehicles Begin MACE (WILL NOT BE ADDED IN SKIRMISH OR CONQUEST) ===========*/

{"m1a2_test"
	("m4a2_sherman_sound")
	{on spawn
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight3"}
		{add_view "flash_gun_hmg_m2hb" "fire_gun1" "foresight2"}
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell3"}
		{add_view	"shell_mgun"	"mgun_eject1"	"fxshell1"}
		{link_sound "cook_off" "detonation/cook_off/cook"}
		{link_sound "burnup_ammo" "detonation/cook_off/burn_ammo"}
		{link_sound "hatch_fire" "fire/loops/big"}
   		{add_view "tank_die_peaceful_light"	"effect1"	"stage1"}
		{add_view "aero_die"	"effect2"	"stage2"}
		{add_view "ex_fuel_tank"	"effect3"	"stage3"}
		{add_view "cooking_presmoke_2"	"effect3"	"stage4"}
		{add_view "cooking_presmoke_3"	"effect5"	"stage4"}
		{add_view "fire_cooking_explosion"	"effect6"	"stage4"}
		{add_view "cooking_high"	"effect7"	"stage4"}
		{add_view "cooking_turret_ring"	"effect8"	"stage5"}
		{add_view "tank_die_peaceful_light"	"effect9"	"stage4"}
		{add_view "fire_dead_turret"	"effect10"	"stage4"}
		{add_view "cooking_turret_smoke"	"effect11"	"stage4"}		

		{view hide "effect1"}
		{view hide "effect2"}
		{view hide "effect3"}
		{view hide "effect4"}
		{view hide "effect6"}
		{view hide "effect7"}
		{view hide "effect8"}
		{view hide "effect9"}
		{view hide "effect10"}
		{view hide "effect11"}
		
   	}
	{on repair
			{if component "gun"
				{if work "gun"
					{ani_play "gun_r" +0.80 resume}
				}
			}	
			{if component "turret"
				{if work "gun"
					{ani_play "turret_r" +0.80 resume}
				}
			}
			{if component "body"
				{if work "body"
					{ani_play "body_r" +0.80 resume}
				}
			}
			{if component "engine"
				{if work "engine"
					{ani_play "engine_r" +0.80 resume}
				}
			}
		}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "close_commander" +1.0 resume}
	}
	{on "charger_hatch_open" overload
		{ani_play "open_gunner" +1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "close_gunner" +1.0 resume}	
	}
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on fire "mgun2"
		{ani_play "fire_mgun2" 1 resume}
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{view start "mgun_eject2"}
		{delay 0.2
			{view pause "mgun_eject2"}

		}
	}
	{on fire "mgun3"
		{ani_play "fire_mgun1" 1 resume}
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{view start "mgun_eject1"}
		{view start "fire_gun2"}
		{delay 0.2
			{view pause "mgun_eject1"}
			{view pause "fire_gun2"}
		}
	}
	{on fire "mgun4"
		{play_sound "action_recoil_HMG"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "fire_gun1"}
		{delay 0.2
			{view pause "fire_gun1"}
		}
	}
		{on break
			{if not tagged "exploded"
				{if component "gun"
					{ani_play "gun_b" +0.80 resume}
				}
				{if component "engine"
					{ani_play "engine_b" +0.80 resume}
				}
				{if component "turret"
					{ani_play "turret_b" +0.80 resume}
				}
				{if component "body"
					{ani_play "body_b" +0.80 resume}
				}
			}
		{if component "shieldr10"
			{tear "piece_medium_steel" bone "shieldr10"
				{impulse up 1.5 rnd_dir 2}
			}
		}
		{if component "shieldl10"
			{tear "piece_medium_steel" bone "shieldl10"
				{impulse up 1.5 rnd_dir 2}
			}
		}		    
		{if component "ammo_rack_turret"
			{tear "piece_medium_steel" bone "ammo_hatch1"
				{impulse up 8 rnd_dir 2}
			}
			{tear "piece_medium_steel" bone "ammo_hatch2"
				{impulse up 8 rnd_dir 2}
			}
			{start_sound "detonation/explosion_fiery/"}
			{call "crew_stunned"}
			{view start "effect1"}	
			{view start "effect2"}
			{view start "effect3"}
			{delay 0.5
				{view start "effect4"}
			}
			{delay 4
				{start_sound "detonation/cook_off/internal_explosions"}
				{view pause "effect4"}
				{view start "effect5"}
			}
			{delay 10
				{start_sound "detonation/cook_off/transition"}
				{damage_report "ammo" "ammo_fire"}
			}
			{delay 11
				{play_sound "cook_off" 1}
				{fire radius 2 time 39 heating 0.35 follow}
				{clear_inventory}
				{view pause "effect5"}
				{view start "effect6"}
				{view start "effect7"}
				{view start "effect8"}
			}
			{delay 20
				{view start "effect9"}
				{start_sound "detonation/explosion_fiery/"}
			}
			{delay 40
				{call "crew_revive"}
				{stop_sound "cook_off"}
				{start_sound "detonation/cook_off/transition"}
				{play_sound "burnup_ammo" 1}
				{view pause "effect7"}
				{view pause "effect8"}
				{view start "effect10"}
			}
			{delay 65
				{start_sound "detonation/cook_off/transition"}
				{stop_sound "burnup_ammo" 1}
				{play_sound "hatch_fire"}
				{view pause "effect10"}
				{view start "effect11"}
			{delay 135
				{stop_sound "hatch_fire"}
			}
			}
			{delay 200
				{view pause "effect11"}
			}
		}
	}
}

(define "320mm_type98_mortar_scripts"

	{on spawn
		{link_sound "screw_twist"		"human/anims/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anims/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anims/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anims/repair/toolbox_close/"}
		{add_view	"tank_fire_maximum_dust_ground"		"dust"			"basis"}
		{add_view	"tank_fire_maximum_dust_snow"		"snow"			"basis"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/usa/m1903a3/m1_grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/usa/m1903a3/m1_grenade_launcher/"}
	}

	{on animation_event "close" overload		;// event called on frame 1 of "close" animation
		{if tagged "transition"
			{tags remove "transition"}
			{volumes "body1" enable bullet blast}
			{volumes "body2" enable bullet blast}
			{volumes "body3" enable bullet blast}
			{volumes "body6" enable bullet blast}
		else
			{tags add "transition"}
			{volumes "body1" disable bullet blast}
			{volumes "body2" disable bullet blast}
			{volumes "body3" disable bullet blast}
			{volumes "body6" enable bullet blast}
		}
		{call "body_check"}
	}

	{on fire "gun"
		{play_sound "mid"}
		{play_sound "far"}
		{if terrain_fx "snow"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "ice"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "shallow_water"
			;nothing
		else
			{view start "dust"}
			{delay 0.3 {view pause "dust"}}
		}
		{bone hide "rocket_head"}
		{bone hide "rocket_frame"}
		{bone hide "rocket_base"}
		{volumes "rocket1" disable bullet blast}
		{volumes "rocket2" disable bullet blast}
		{volumes "rocket3" disable bullet blast}
	}	

	{on "cannon_reloaded" overload
		{if cannon_state "move"
			;// do nothing
		else cannon_state "trailing"
			;// do nothing
		else
			{ani_play "reload" 1.0}
		}
		{ani_play "reload" 0.5}
		{delay 0.4
			{bone show "rocket_head"}
			{bone show "rocket_frame"}
			{bone show "rocket_base"}
			{volumes "rocket1" enable bullet blast}
			{volumes "rocket2" enable bullet blast}
			{volumes "rocket3" enable bullet blast}
		}
		{delay 1.15
			{play_sound "toolbox_open"}
			{delay 1.15
				{play_sound "wrench_turn"}
				{delay 1.15
					{play_sound "wrench_turn"}
					{delay 1.15
						{play_sound "screw_twist"}
						{delay 1.15
							{play_sound "wrench_turn"}
							{delay 1.15
								{play_sound "wrench_turn"}
								{delay 1.15
									{play_sound "screw_twist"}
									{delay 1.15
										{play_sound "wrench_turn"}
										{delay 1.15
											{play_sound "wrench_turn"}
											{delay 1.15
												{play_sound "screw_twist"}
												{delay 1.15
													{play_sound "toolbox_close"}
												}
											}
										}
									}
								}
							}
						}
					}
				}	
			}
		}
		{delay 0.5
			{talk "reloaded"}
		}
	}
	{on repair
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1}
				{volumes "rocket3" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
				{volumes "rocket2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
				{bone show "rocket_head"}
				{bone show "rocket_frame"}
			}
		}
		{call_synced "320mm_type98_mortar_scripts"}
	}
	{on break                ;// volume breaks
		{if component "body"
			{ani_play "body_b" +1}
			{delay 0.5
				{tear "piece_medium_steel" bone "rocket_head" copy
						{impulse forward 3 }
				}
				{delay 0.01
					{volumes "rocket3" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
					{bone hide "rocket_head"}
				}	
				{delay 0.1
					{tear "piece_medium_steel" bone "rocket_frame" copy
						{impulse forward 1.5 }
					}
					{delay 0.01
						{volumes "rocket2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
						{bone hide "rocket_frame"}
					}
				}
			}
		}
		{if not tagged "ammo_broken"
			{if component "rocket1"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{spawn "tank_die_heavy" "basis"}
				{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
				{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
				{components "body" destroy}
			}
			{if component "rocket2"
				{tags add "ammo_broken"}
				{spawn "tank_die_heavy" "basis"}
				{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
				{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
				{components "body" destroy}
			}
			{if component "rocket3"
				{tags add "ammo_broken"}
				{spawn "tank_die_heavy" "basis"}
				{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
				{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
				{components "body" destroy}
			}
		}
	}	
)

(define "repair_anm_script_type21_booster" ;// break/repair anm for components
	{on break
		{if not tagged "exploded"
			{if component "body"
				{ani_play "body_b" +1}
			}
		}
		{if not tagged "ammo_broken"
			{if component "rocket1"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{spawn "tank_die_heavy" "basis"}
				{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
				{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
				{components "body" destroy}
			}
		}
		{call_synced "repair_anm_script_type21_booster"}
	}
	{on repair
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1}
			}
		}
		{call_synced "repair_anm_script_type21_booster"}
	}

	{on "cannon_reloaded" overload
		{if cannon_state "move"
			{delay 80
				{volumes "rocket1" enable bullet blast}
			}
		}
	}	

	{on contact
		{if effector "killzone_75_type21"
			{components "body" destroy}
		}
	}			
)


(define "54mm_bangalore_script"	

	(define "reset_ammo_tags"
		{tags remove "ammo1"}
		{tags remove "ammo2"}
		{tags remove "ammo3"}
		{tags remove "ammo4"}
		{tags remove "ammo5"}
		{tags remove "ammo6"}
		{tags remove "ammo7"}
		{tags remove "ammo8"}
		{tags remove "ammo9"}
		{tags remove "ammo10"}
		{tags remove "ammo11"}
		{tags remove "ammo12"}
		{tags remove "ammo13"}
		{tags remove "ammo14"}
		{tags remove "ammo15"}
		{tags remove "ammo16"}
	)

	(define "all_rocket"
		{bone %state "rocket0"}
		{bone %state "rocket1"}
		{bone %state "rocket2"}
		{bone %state "rocket3"}
		{bone %state "rocket4"}
		{bone %state "rocket5"}
		{bone %state "rocket6"}
		{bone %state "rocket7"}
		{bone %state "rocket8"}
		{bone %state "rocket9"}
		{bone %state "rocket10"}
		{bone %state "rocket11"}
		{bone %state "rocket12"}
		{bone %state "rocket13"}
		{bone %state "rocket14"}
		{bone %state "rocket15"}
	)

	(define "advance_ammo"
		{if tagged "ammo%current"
			{tags remove "ammo%current"}
			{delay 0.1
				{tags add "ammo%next"}
			}
			{spawn "bangalore_torpedo_dummy" "shooter%current" x 
				{impulse forward 25.5 up -0.5 rnd_dir 0 no_position}
				{gravity 0.5}
			}
			{delay 0.1
				{bone hide "rocket%current"}
			}
			{view start "flashrocket%current"}
			{view start "flashrocketrear%current"}
		}
	)

	{on fire "explosive"
		("advance_ammo" current(15) next(0))
		("advance_ammo" current(14) next(15))
		("advance_ammo" current(13) next(14))
		("advance_ammo" current(12) next(13))
		("advance_ammo" current(11) next(12))
		("advance_ammo" current(10) next(11))
		("advance_ammo" current(9) next(10))
		("advance_ammo" current(8) next(9))
		("advance_ammo" current(7) next(8))
		("advance_ammo" current(6) next(7))
		("advance_ammo" current(5) next(6))
		("advance_ammo" current(4) next(5))
		("advance_ammo" current(3) next(4))
		("advance_ammo" current(2) next(3))
		("advance_ammo" current(1) next(2))
		("advance_ammo" current(0) next(1))
	}

)

{"fuel_tank_beetle"
	{on pierce sync
		{if component "beetle_fuel"
			{if not work "beetle_fuel"
				{if not tagged "fueltank_fire"
					{if stuff "ptr"						;// at rifles goes first then bullet
						{delay 5 5
							{call_synced "fueltank_fire"}
						}
						{burn fx "fire_fueltank_pierce_medium" time 15 fake}
					else stuff "bullet"
						{delay 5 5
							{call_synced "fueltank_fire"}
						}
						{burn fx "fire_fueltank_pierce" time 15 fake} 
					else stuff "auto"
						{delay 5 5
							{call_synced "fueltank_fire"}
						}
						{burn fx "fire_fueltank_pierce_medium" time 15 fake}
					else stuff "shell"
						{call "fueltank_fire"}
						{burn fx "fire_fueltank_pierce_big" time 15 fake}
					}
				}
			}
		}
	}
	{on break_armor
		{if component "beetle_fuel"
			{if not able "exploded"
				{if name "pierce"
					{if stuff "bullet"
						{burn fx "drops_fuel_small_short" time 10 fake}
					}
				}
				{if name "blast"
					{if min_energy 2
						{call "fueltank_fire"}
					else min_energy 1
						{if rand 1
							{call "fueltank_fire"}
						}
					}
				}
			}
		}
	}
	{on "fueltank_fire"
		{if not tagged "fueltank_fire"
			{tags add "fueltank_fire"}
			{play_sound "flame" 1}
			{burn volume "beetle_fuel" fx "fire_fueltank_small" time 15 fake even_law}
			{delay 10 5
				{burn volume "beetle_fuel" fx "fire_fueltank" time 30 fake even_law}
				{spawn "fuel_die_beetle" "fueltank"}
				{weapon_work "flamer1" 0}
				{delay 20 10
					{components "beetle_fuel" break}
					{play_sound "flame" 0}
					{view start "smoke_vehicle_death_beetle"}
					{delay 120
						{view stop "smoke_vehicle_death_beetle"}
					}
				}
			}
		}
	}
	{on repair
		{if component "beetle_fuel"
			{if work "beetle_fuel"
				{weapon_work "flamer1" 1}
				{view stop "smoke_vehicle_death_beetle"}
				{tags remove "fueltank_fire"}
			}
		}
	}	
}

(define "multi_barrel_loop_hedgehog"
	{on "init_gun"
		{add_view "%smoke"		"smoke00"	"shooter00"}
		{add_view "%smoke"		"smoke01"	"shooter01"}
		{add_view "%smoke"		"smoke02"	"shooter02"}
		{add_view "%smoke"		"smoke03"	"shooter03"}
		{add_view "%smoke"		"smoke04"	"shooter04"}
		{add_view "%smoke"		"smoke05"	"shooter05"}
		{add_view "%smoke"		"smoke06"	"shooter06"}

		{call "update_gun"}
	}

	{on fire "rocket" overload
		{tags add "firing"}
		{delay 0.001
			{tags remove "firing"}
		}
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "smoke%0"}
				{delay 0.12 "shell_off"
					{view pause "smoke%0"}
				}
		)
		{if	("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		else ("fire_barrel" args 04)
		else ("fire_barrel" args 05)
		else ("fire_barrel" args 06)
		else ("fire_barrel" args 07)
		}
	}
)