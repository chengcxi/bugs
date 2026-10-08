; File: 		arm_airborne_func.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm
; Created by: 	Max Drechsler
; Created:		xx.xx.2026
; Modify by:	Max Drechsler
; Modify:		07.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		x.x
; Description: 

;===================== AI AIR MACROS LOGIC
;-----------
			{"bomber"
				{on "init_gun" overload
					{add_view "flash_gun_big_vehicle" "shooter1_00" "shooter1_00"}
					{add_view "flash_gun_big_vehicle" "shooter1_01" "shooter1_01"}
					{add_view "flash_gun_big_vehicle" "shooter2_00" "shooter2_00"}
					{add_view "flash_gun_big_vehicle" "shooter2_01" "shooter2_01"}
					{add_view "flash_gun_big_vehicle" "shooter3_00" "shooter3_00"}
					{add_view "flash_gun_big_vehicle" "shooter3_01" "shooter3_01"}
					{add_view "flash_gun_big_vehicle" "shooter4_00" "shooter4_00"}
					{add_view "flash_gun_big_vehicle" "shooter4_01" "shooter4_01"}
				}
				(define "link_flash"
					{if name "mgun_linked%0"
						{if stuff "mgun"
							{add_view "flash_gun_big_vehicle" "flashbarrel%1" "Foresight%1"}
						}
					}
				)
				{on "link_weapon" overload
					("link_flash" args 1 5)
					("link_flash" args 2 6)
					("link_flash" args 3 7)
					("link_flash" args 4 8)
				}
				{on fire "mgun_linked1" {view start "flashbarrel5"}}
				{on fire "mgun_linked2" {view start "flashbarrel6"}}
				{on fire "mgun_linked3" {view start "flashbarrel7"}}
				{on fire "mgun_linked4" {view start "flashbarrel8"}}

				(define "start_shooter_flash"
					{on fire "mgun_own%0"
						{if name "00"
							{view start "shooter%0_00"}
						}
						{if name "01"
							{view start "shooter%0_01"}
						}
					}
				)
				("start_shooter_flash" args 1)
				("start_shooter_flash" args 2)
				("start_shooter_flash" args 3)
				("start_shooter_flash" args 4)

				{on "_explosion" overload}

				{on "break_part"
					{if work
						{component break}
						{burn fx "smoke_aero_small" fake}
					else broken
						{component destroy}
						{spawn "aero_die_particle"}
						{if volume "engine"
							{tear "piece_medium_steel" bone from_volume
								{impulse up 1 0.5 dir 5 2 rnd_dir 3 no_position}
								{add_view "smoke_dead_wheel" "smoke" "basis"}
								{view start "smoke"}
								{delay_effect 20 5 "stop"}
								{delay 15 {if under_water {delete}}}
							}
						}
						{if volume "engine1"
							{tear "piece_medium_steel" bone from_volume
								{impulse up 1 0.5 dir 5 2 rnd_dir 3 no_position}
								{add_view "smoke_dead_wheel" "smoke" "basis"}
								{view start "smoke"}
								{delay_effect 20 5 "stop"}
							}
						}
						{if volume "engine2"
							{tear "piece_medium_steel" bone from_volume
								{impulse up 1 0.5 dir 5 2 rnd_dir 3 no_position}
								{add_view "smoke_dead_wheel" "smoke" "basis"}
								{view start "smoke"}
								{delay_effect 20 5 "stop"}
							}
						}
					else destroyed
						{spawn "aero_die_particle"}
					}
				}
			}


			{"airborne fighter ai"	
				{on "set_static"							;// map/mission helper for static neutral vehicles
					{able select 0}
					{able ammo_out_indicator 0}
					{able ally_crew 0}
					{able repaired 0}
					{able talk 0}
					{able unmask 0}
					{able emit_passangers_on_enemy 0}
					{able minimap 0}
					{able neutral 1}
					{clear_inventory}
				}

				{on spawn
					{delay 0.2
						{if work "body"
							{tags add "fighter"}
						;	{tags add "bot_recon"}				
							{tags add "move_to_start_waypoint"}
						}
					}
				}
			}

			{"airborne bomber_ce ai"
				{on "set_static"							;// map/mission helper for static neutral vehicles
					{able select 0}
					{able ammo_out_indicator 0}
					{able ally_crew 0}
					{able repaired 0}
					{able talk 0}
					{able unmask 0}
					{able emit_passangers_on_enemy 0}
					{able minimap 0}
					{able neutral 1}
					{clear_inventory}
				}

				{on spawn
					{delay 0.2
						{if work "body"
							{tags add "bomber_ce"}
						;	{tags add "bot_recon"}			
							{tags add "move_to_start_waypoint"}
						}
					}
				}
			}

			{## "airborne ai_recon_plane_x"
			;//	{on "set_static"							;// map/mission helper for static neutral vehicles
			;//		{able select 0}
			;//		{able ammo_out_indicator 0}
			;//		{able ally_crew 0}
			;//		{able repaired 0}
			;//		{able talk 0}
			;//		{able unmask 0}
			;//		{able emit_passangers_on_enemy 0}
			;//		{able minimap 0}
			;//		{able neutral 1}
			;//		{clear_inventory}
			;//	}
			;//	
			;//	{on spawn
			;//		{delay 0.2
			;//			{if work "body"
			;//				{tags add "bot_recon"}
			;//				{tags add "move_to_start_waypoint"}
			;//			}
			;//		}
			;//	}
			;//
			;//	;{on "move_plane_to_initial_waypoint" 
			;//	;	("move_plane_to_start_waypoint")
			;//	;}
			}

			{"airborne ai_recon_plane"
			;//	{on "set_static"
			;//		{able select 0}
			;//		{able ammo_out_indicator 0}
			;//		{able ally_crew 0}
			;//		{able repaired 0}
			;//		{able talk 0}
			;//		{able unmask 0}
			;//		{able emit_passangers_on_enemy 0}
			;//		{able minimap 0}
			;//		{able neutral 1}
			;//		{clear_inventory}
			;//	}
				
				{on spawn
					{inherited}									; + ARm 100926 Ч базовый spawn от "airborne": ignore_spawn_logic
					{delay 0.2
						{if work "body"
							{tags add "bot_recon"}
							{tags add "move_to_start_waypoint"}
							{delay 1.0
								{call "move_plane_to_initial_waypoint"}		; + ARm 100926 Ч ставит ai_recon_ready
							}
						}
					}
				}

				{on "move_plane_to_initial_waypoint" 
				;	{call "takeoff_load"}   
					("move_plane_to_start_waypoint" args "ai_recon_ready")		; + ARm 100926 Ч раскомментировать и добавить args
				}
			}

			{"airborne lua_enemy_air_fighter"
			;//	{on "set_static"
			;//		{able select 0}
			;//		{able ammo_out_indicator 0}
			;//		{able ally_crew 0}
			;//		{able repaired 0}
			;//		{able talk 0}
			;//		{able unmask 0}
			;//		{able emit_passangers_on_enemy 0}
			;//		{able minimap 0}
			;//		{able neutral 1}
			;//		{clear_inventory}
			;//	}

				{on spawn
					{inherited}											; + ARm 100926 Ч базовый spawn от "airborne": ignore_spawn_logic
					{delay 0.2
						{if work "body"
							{tags add "fighter"}						; + ARm 100926 Ч боевой
							{tags add "move_to_start_waypoint"}
							{delay 1.0
								{call "move_plane_to_initial_waypoint"}
							}
						}
					}	
				}
				
				{on "move_plane_to_initial_waypoint" 
					("move_plane_to_start_waypoint" args "fighter_ready")	; + ARm 100926 Ч ставит fighter_ready
				}
			}

			{"airborne lua_enemy_air_bomber"
			;//	{on "set_static"
			;//		{able select 0}
			;//		{able ammo_out_indicator 0}
			;//		{able ally_crew 0}
			;//		{able repaired 0}
			;//		{able talk 0}
			;//		{able unmask 0}
			;//		{able emit_passangers_on_enemy 0}
			;//		{able minimap 0}
			;//		{able neutral 1}
			;//		{clear_inventory}
			;//	}

				{on spawn
					{inherited}											; + ARm 100926 Ч базовый spawn от "airborne": ignore_spawn_logic
					{delay 0.2
						{if work "body"
							{tags add "bomber_ce"}						; + ARm 100926 Ч бомбардировщик
							{tags add "move_to_start_waypoint"}
							{delay 1.0
								{call "move_plane_to_initial_waypoint"}
							}
						}
					}	
				}
				
				{on "move_plane_to_initial_waypoint" 
					("move_plane_to_start_waypoint" args "bomber_ce_ready")	; + ARm 100926 Ч ставит bomber_ce_ready
				}
			}





;-----------
;===================== AI AIR MACROS LOGIC TEXMOD
;-----------
			{"airborne"
				{on spawn
			;//		{if tagged "_ai_defender"
			;//		else not tagged "_lua_mi"						;140226 test! not work
			;//		{if not tagged "_user"							; ќрудие не св€зано с игроком
			;//		else tagged "_bot"								; ¬ противном случае св€зано с ботом
			;//			{delay 0.1
							{if terrain_fx "ice"
								{tex_mod "winter"}
							else terrain_fx "snow"
								{tex_mod "winter"}
							else
								; do nothing
							}
							{delay 1
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}	
							{delay 2
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}				
							{delay 3
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}
							{delay 4
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}
							{delay 5
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}
							{delay 6
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}	
							{delay 7
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}		
							{delay 8
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}	
							{delay 9
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}	
							{delay 10
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}	
							{delay 11
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}
							{delay 12
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}
							{delay 13
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}
							{delay 14
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}	
							{delay 15
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}	
							{delay 16
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}	
							{delay 17
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}	
							{delay 18
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}
							{delay 19
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}	
							{delay 20
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}				
							{delay 30
								{if terrain_fx "ice"
									{tex_mod "winter"}
								else terrain_fx "snow"
									{tex_mod "winter"}
								else
									; do nothing
								}
							}				
			;//			}
			;//		}	
				}
			}	




;-----------

;//{"airborne lua_enemy_air"
;//	{on spawn
;//	;	{delay 0.2
;//			{if work "body"
;//				{tags add "bomber_ce"}
;//				{tags add "move_to_start_waypoint"}
;//			}
;//	;	}	
;//	}
;//	
;//	{on "move_plane_to_initial_waypoint" 
;//		("move_plane_to_start_waypoint" args "bomber_ce_ready")
;//	}
;//}

;------------------- ITS worked
;//{"airborne lua_enemy_air"
;//;//	{on "set_static"							;// map/mission helper for static neutral vehicles
;//;//		{able select 0}
;//;//		{able ammo_out_indicator 0}
;//;//		{able ally_crew 0}
;//;//		{able repaired 0}
;//;//		{able talk 0}
;//;//		{able unmask 0}
;//;//		{able emit_passangers_on_enemy 0}
;//;//		{able minimap 0}
;//;//		{able neutral 1}
;//;//		{clear_inventory}
;//;//	}
;//
;//	{on spawn
;//	;	{delay 0.2
;//			{if work "body"
;//				{tags add "bomber_ce"}
;//			;	{tags add "enemy_air"}
;//			;	{tags add "airstrike_usa"}
;//			;	{tags add "airstrike_ger"}
;//			;	{tags add "airstrike_fin"}
;//			;	{tags add "airstrike_rus"}
;//			;	{tags add "airstrike_eng"}
;//			;	{tags add "air_vehicle"}
;//			;	{tags add "hidden"}
;//				{tags add "move_to_start_waypoint"}
;//			}
;//	;	}	
;//	}
;//	
;//	{on "move_plane_to_initial_waypoint" 
;//		("move_plane_to_start_waypoint" args "bomber_ce_ready")
;//	}
;//}

;===================== SCRIPT AIR tag-clener BEGIN
;//{"airborne"
;//	{on "die"
;//	
;//;//--------------------- *				
;//
;//			{if tagged "arm_airborne_tag_all"
;//				{tags remove "arm_airborne_tag_all"}
;//			}			
;//;//--------------------- airstrike_*
;//			{if tagged "tag_airborne_ger"
;//				{tags remove "tag_airborne_ger"}
;//			}
;//			{if tagged "tag_airborne_rus"
;//				{tags remove "tag_airborne_rus"}
;//			}
;//			{if tagged "tag_airborne_fin"
;//				{tags remove "tag_airborne_fin"}
;//			}
;//			{if tagged "tag_airborne_usa"
;//				{tags remove "tag_airborne_usa"}
;//			}
;//			{if tagged "tag_airborne_eng"
;//				{tags remove "tag_airborne_eng"}
;//			}
;//;//--------------------- *		
;//			{if tagged "ger"
;//				{tags remove "ger"}
;//			}
;//			{if tagged "usa"
;//				{tags remove "usa"}
;//			}
;//;//--------------------- airborne_*			
;//;//			{if tagged "airborne_ger"
;//;//				{tags remove "airborne_ger"}
;//;//			}	
;//;//			{if tagged "airborne_ussr"
;//;//				{tags remove "airborne_ussr"}
;//;//			}
;//;//			{if tagged "airborne_fin"
;//;//				{tags remove "airborne_fin"}
;//;//			}	
;//;//			{if tagged "airborne_usa"
;//;//				{tags remove "airborne_usa"}
;//;//			}	
;//;//			{if tagged "airborne_eng"
;//;//				{tags remove "airborne_eng"}
;//;//			}
;//	}	
;//}

;===================== SCRIPT AIR airdrop tagging BEGIN



;===================== HIDE ALL ENEMY AIRBORNE
;//{"airborne"
;//	{on spawn
;//		{delay 0.4}
;//		{if tagged "airstrike_ger"
;//			{delay 45 
;//				{hide 5}
;//			}
;//		}
;//		
;//		{if tagged "airstrike_rus"
;//			{delay 45 
;//				{hide 5}
;//			}
;//		}
;//
;//		{if tagged "airstrike_fin"
;//			{delay 45 
;//				{hide 5}
;//			}
;//		}
;//
;//
;//		{if tagged "airstrike_usa"
;//			{delay 45 
;//				{hide 5}
;//			}
;//		}			
;//
;//
;//		{if tagged "airstrike_eng"
;//			{delay 45 
;//				{hide 5}
;//			}
;//		}
;//
;//
;//		{if tagged "airstrike_jap"
;//			{delay 45 
;//				{hide 5}
;//			}
;//		}	
;//	}
;//}

;===================== TAGGING ALL AIRBORNE
;//{"airborne"
;//	{on spawn
;//;//		{delay 0.4	
;//			{if not tagged "arm_airborne_tag_all"
;//				{tags add "arm_airborne_tag_all"}
;//			}
;//;//		}	
;//	}	
;//}

