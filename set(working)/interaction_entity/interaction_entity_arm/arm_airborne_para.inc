;file: arm_airborne_para.inc
;catalog: resource\set\interaction_entity
;GEM ENGINE 2 - paratroop macros
;modify by Max Drechsler
;23.08.2026
;version v16.4

{"airborne"
	{on "spawn"
		{delay 0.2
			{tags add "ignore_spawn_logic"}
		}
	}
;//	{on "engine_full_para_fix"
;//		{delay 2.5 "engine_full"			;// delay for accelerate sound
;//			{if not destroyed "engine1"
;//				{play_sound "engine1_full" 1}
;//				{play_sound "bkg_plane" 1}
;//				{stop_sound "engine1_idle"}
;//			}
;//			{if not destroyed "engine2"
;//				{play_sound "engine2_full" 1}
;//				{play_sound "bkg_plane" 1}
;//				{stop_sound "engine2_idle"}
;//			}
;//		}
;//	}

;//	{on "select_for_sorty"
;//		{if operatable
;//			{if tagged "fighter"
;//				{tags add "fighter_select_sorty"}
;//			else tagged "bomber_ce"
;//				{tags add "bomber_ce_select_sorty"}
;//			else tagged "bot_recon"
;//				{tags add "recon_select_sorty"}
;//			}
;//
;//			{delay 5
;//				{tags remove "fighter_select_sorty"}
;//				{tags remove "bomber_ce_select_sorty"}
;//				{tags remove "recon_select_sorty"}
;//			}
;//		}
;//	}

	{on "select_plane_for_fly_by"
		{tags add "plane_select_fly_by"}
		{if tagged "fighter"
			{delay 40
				{tags add "plane_ready_for_sorty"}
			}
		else tagged "bomber_ce"
			{delay 50
				{tags add "plane_ready_for_sorty"}
			}
		}
		{tags remove "plane_ready"}
	}

	{on "move_plane_to_initial_waypoint" 
		{tags remove "move_to_start_waypoint"} 
		{tags remove "plane_selected_to_move_to_start"}
		{tags add "plane_ready"}
		{set "landing" 1}
		{call "takeoff_load"}
		{call "takeoff"}	
	}	

	{on "tag_squad_need_next_order"
        {tags add "_lua_need_next_order"}
        {tags remove "plane_select_fly_by"}
        {delay 10.1 
            {tags remove "_lua_need_next_order"}
        }
    }
}

{"airborne drop_plane"

	(define "drop_veh"
		{spawn %veh offset 0 0 -75
			{tags add %tag}
			{with_linked_entity "attach"
				{volumes disable contact}			;// stops humans from "colliding" with plane when ejecting.
				{volumes enable bullet}
				{delay 3 {volumes enable contact blast}}
				{if not linked "ce_vehicle_drop"
					{tags add "paradropped_veh"}
				}	
			}
		}
	)

	(define "drop_vehicle"
		{if rand 0.4	
			{delay %delay
				{if operatable
					{if tagged "rus"
						{if rand 0.25
							("drop_veh" veh("paradrop_emplacement_box") tag("rus"))
						else rand 0.25
							("drop_veh" veh("paradrop_76mm_m43") tag(""))	
						else rand 0.25
							("drop_veh" veh("paradrop_bpk") tag(""))
						else
							("drop_veh" veh("paradrop_maxim") tag(""))
						}
					else tagged "ger"
						{if rand 0.25
							("drop_veh" veh("paradrop_emplacement_box") tag("ger"))
						else rand 0.25
							("drop_veh" veh("paradrop_75mm_legebig18") tag(""))	
						else rand 0.25
							("drop_veh" veh("paradrop_75mm_lg40") tag(""))
						else
							("drop_veh" veh("paradrop_mg34_lafette") tag(""))
						}
					else tagged "usa"
						{if rand 0.33
							("drop_veh" veh("paradrop_emplacement_box") tag("usa"))
						else rand 0.33
							("drop_veh" veh("paradrop_75mm_m1a1") tag(""))	
						else
							("drop_veh" veh("paradrop_m2_50cal_tripod") tag(""))
						}
					}
				}
			}
		else user_control
			{delay %delay
				{if operatable
					{if tagged "rus"
						("drop_veh" veh("paradrop_emplacement_box") tag("rus_supply_box"))
					else tagged "ger"
						("drop_veh" veh("paradrop_emplacement_box") tag("ger_supply_box"))
					else tagged "usa"
						("drop_veh" veh("paradrop_emplacement_box") tag("usa_supply_box"))
					}
				}	
			}
		}
	)

	{on break				;// component breaks
		{if not tagged "exploded"
			{if chassis "airborne"
				{if component "body"
					{if not tagged "dropping_troopers"
						{if rand 0.5
							{call "drop_paratroopers"}
						}
					}
				}
			}
		}
	}

	{on destroy				;// component destroyed
		{if not tagged "exploded"
			{if chassis "airborne"
				{if not tagged "dropping_troopers"
					{call "drop_paratroopers"}
				}
			}
		}
	}
}

; ------------------------------------------ player paradrop

;//{"drop_plane"
;//
;//	{on spawn
;//		{tags add "move_to_start_waypoint"}
;//		{tags add "user_plane"}	
;//		{tags remove "moving_to_drop_zone"}	
;//		{tags remove "ready_to_move"}	
;//		{tags remove "on_mission"}	
;//		{tags remove "nocrew"}
;//		{tags remove "out"}
;//		{tags remove "dropping_troopers"}
;//		{delay 0.2
;//			{if work "body"
;//				{tags add "drop_plane"}
;//				{tags add "move_to_start_waypoint"}
;//			}
;//		}
;//		;{delay 2
;//		;	{call "prep_drop_plane_to_move_fast_drop"}
;//		;}
;//	}

;//	(define "eject_troopers"
;//		{set "is_enemy" 0}
;//		{if tagged "enemy_paradrop_plane"
;//			{set "is_enemy" 1}
;//		}
;//		; Устанавливаем теги до задержки
;//		{with_linked_entity %seat
;//			{if "is_enemy"
;//				{tags add "enemy_paratrooper"}
;//			else
;//				{tags add "player_paratrooper"}
;//			}
;//			{tags add "ignore_spawn_logic"}
;//		}
;//		; Даём движку время обработать теги (0.1 сек)
;//		{delay 0.1
;//			; Затем через исходную задержку выполняем unlink
;//			{delay %delay
;//				{with_linked_entity %seat
;//					{unlink}
;//				}
;//			}
;//		}
;//	)

	
;//	(define "eject_troopers"
;//		{set "is_enemy" 0}
;//		{if tagged "enemy_paradrop_plane"
;//			{set "is_enemy" 1}
;//		}
;//		; Устанавливаем теги ДО задержки и unlink
;//		{with_linked_entity %seat
;//			{if "is_enemy"
;//				{tags add "enemy_paratrooper"}
;//			else
;//				{tags add "player_paratrooper"}
;//			}
;//			{tags add "ignore_spawn_logic"}
;//		}
;//		; Даём движку время обработать теги (0.1 сек)
;//		{delay 0.1
;//			; Затем через исходную задержку выполняем unlink
;//			{delay %delay
;//				{with_linked_entity %seat
;//					{delay 0.5
;//						{if not destroyed "body"
;//							{unlink}
;//						else
;//						;	{spawn "parachute" offset 0 0 -75}
;//							{unlink}
;//						}
;//					}
;//				}
;//			}
;//		}
;//	)
;//
;//
;//	{on "drop_test"
;//			{tags add "deploying_paratroopers"}
;//			{tags remove "drop_plane_selected"}
;//		("eject_troopers" delay(1) 		seat("seat1"))
;//		("eject_troopers" delay(1.5)  	seat("seat2"))
;//		("eject_troopers" delay(2)		seat("seat3"))
;//		("eject_troopers" delay(2.5)  	seat("seat4"))
;//		("eject_troopers" delay(3)		seat("seat5"))
;//		("eject_troopers" delay(3.5)  	seat("seat6"))
;//		("eject_troopers" delay(4)		seat("seat7"))
;//		("eject_troopers" delay(5)  	seat("seat8"))
;//		("eject_troopers" delay(5.5)	seat("seat9"))
;//		("eject_troopers" delay(6)  	seat("seat10"))
;//		("eject_troopers" delay(6.5)	seat("seat11"))
;//		("eject_troopers" delay(7)  	seat("seat12"))
;//		("eject_troopers" delay(7.5)	seat("seat13"))
;//		("eject_troopers" delay(8)  	seat("seat14"))
;//		("eject_troopers" delay(8.5)  	seat("seat15"))
;//		("eject_troopers" delay(9)		seat("seat16"))
;//		("eject_troopers" delay(9.5)  	seat("seat17"))
;//		("eject_troopers" delay(10)		seat("seat18"))
;//		("eject_troopers" delay(10.5)  	seat("seat19"))
;//		("eject_troopers" delay(11)  	seat("seat20"))
;//		
;//			{delay 11.5 ;//SAFESWITCH TO FLUSH OUT THIS FUCKERS
;//				("eject_troopers" delay(0.3) 	seat("seat20"))
;//				("eject_troopers" delay(0.6)  	seat("seat19"))
;//				("eject_troopers" delay(0.9)	seat("seat18"))
;//				("eject_troopers" delay(1.2)  	seat("seat17"))
;//				("eject_troopers" delay(1.5)	seat("seat16"))
;//				("eject_troopers" delay(1.8)  	seat("seat15"))
;//				("eject_troopers" delay(2.1)	seat("seat14"))
;//				("eject_troopers" delay(2.4)  	seat("seat13"))
;//				("eject_troopers" delay(2.7)	seat("seat12"))
;//				("eject_troopers" delay(3)  	seat("seat11"))
;//				("eject_troopers" delay(3.3)	seat("seat10"))
;//				("eject_troopers" delay(3.6)  	seat("seat9"))
;//				("eject_troopers" delay(3.9)	seat("seat8"))
;//				("eject_troopers" delay(3.2)  	seat("seat7"))
;//				("eject_troopers" delay(3.5)  	seat("seat6"))
;//				("eject_troopers" delay(3.8)	seat("seat5"))
;//				("eject_troopers" delay(4.1)  	seat("seat4"))
;//				("eject_troopers" delay(4.3)	seat("seat3"))
;//				("eject_troopers" delay(4.6)  	seat("seat2"))
;//				("eject_troopers" delay(4.9)  	seat("seat1"))
;//			}
;//			; Снимаем защитный тег после завершения сброса
;//			{delay 30
;//				{tags remove "dropping_troopers"}
;//			}
;//	;//    {delay 25 
;//	;//        {hide 5}
;//	;//    }
;//		}
;//
;//	
;//    {on break
;//        {if not tagged "exploded"
;//            {if chassis "airborne"
;//                {if component "body"
;//                    {if not tagged "dropping_troopers"
;//                        {if rand 0.5
;//                            {call "drop_test"}
;//                        }
;//                    }
;//                }
;//            }
;//        }
;//    }
;//
;//    {on destroy
;//        {if not tagged "exploded"
;//            {if chassis "airborne"
;//                {if not tagged "dropping_troopers"
;//                    {call "drop_test"}
;//                }
;//            }
;//        }
;//    }	
;//}

; --------------------------------- enemy paradrop

;//{"drop_plane_enemy"
;//
;//    {on spawn
;//        {tags add "move_to_start_waypoint"}
;//		{tags add "drop_plane_enemy"}
;//        ; {tags add "user_plane"}   ; убираем
;//        {tags remove "moving_to_drop_zone"}    
;//        {tags remove "ready_to_move"}    
;//        {tags remove "on_mission"}    
;//        {tags remove "nocrew"}
;//        {tags remove "out"}
;//        {tags remove "dropping_troopers"}
;//        {delay 0.2
;//            {if work "body"
;//                {tags add "drop_plane_enemy"}
;//                {tags add "move_to_start_waypoint"}
;//            }
;//        }
;//		{delay 0.5
;//			{tags add "ready_to_move"}            ; <-- добавляем тег для триггера send_enemy_drop_plane
;//		}
;//    }
;//
;//	(define "eject_troopers_enemy"
;//		{delay %delay
;//			{with_linked_entity %seat
;//				{delay 0.5
;//					{tags add "enemy_paratrooper"}
;//					{tags add "ignore_spawn_logic"}
;//					{tags add "paradrop_taunt_active"}
;//					{tags add "debug_forced_enemy"}
;//					{if not destroyed "body"
;//						{unlink}
;//					else
;//					;	{spawn "parachute" offset 0 0 -75}
;//						{unlink}
;//					}
;//				}
;//			}
;//		}	
;//	)
;//
;//	{on "drop_troopers_enemy"
;//		{if not tagged "dropping_troopers"
;//			{tags add "dropping_troopers"}
;//			
;//			{tags add "deploying_paratroopers"}
;//			{tags remove "drop_plane_selected"}
;//
;//		
;//			; Первая волна – шаг 0.75 сек
;//			("eject_troopers_enemy" delay(1.0)   seat("seat1"))
;//			("eject_troopers_enemy" delay(1.75)  seat("seat2"))
;//			("eject_troopers_enemy" delay(2.5)   seat("seat3"))
;//			("eject_troopers_enemy" delay(3.25)  seat("seat4"))
;//			("eject_troopers_enemy" delay(4.0)   seat("seat5"))
;//			("eject_troopers_enemy" delay(4.75)  seat("seat6"))
;//			("eject_troopers_enemy" delay(5.5)   seat("seat7"))
;//			("eject_troopers_enemy" delay(6.25)  seat("seat8"))
;//			("eject_troopers_enemy" delay(7.0)   seat("seat9"))
;//			("eject_troopers_enemy" delay(7.75)  seat("seat10"))
;//			("eject_troopers_enemy" delay(8.5)   seat("seat11"))
;//			("eject_troopers_enemy" delay(9.25)  seat("seat12"))
;//			("eject_troopers_enemy" delay(10.0)  seat("seat13"))
;//			("eject_troopers_enemy" delay(10.75) seat("seat14"))
;//			("eject_troopers_enemy" delay(11.5)  seat("seat15"))
;//			("eject_troopers_enemy" delay(12.25) seat("seat16"))
;//			("eject_troopers_enemy" delay(13.0)  seat("seat17"))
;//			("eject_troopers_enemy" delay(13.75) seat("seat18"))
;//			("eject_troopers_enemy" delay(14.5)  seat("seat19"))
;//			("eject_troopers_enemy" delay(15.25) seat("seat20"))
;//			
;//			; Вторая волна (safe switch) – шаг 0.5 сек
;//			{delay 16.0
;//				("eject_troopers_enemy" delay(0.5) seat("seat20"))
;//				("eject_troopers_enemy" delay(1.0) seat("seat19"))
;//				("eject_troopers_enemy" delay(1.5) seat("seat18"))
;//				("eject_troopers_enemy" delay(2.0) seat("seat17"))
;//				("eject_troopers_enemy" delay(2.5) seat("seat16"))
;//				("eject_troopers_enemy" delay(3.0) seat("seat15"))
;//				("eject_troopers_enemy" delay(3.5) seat("seat14"))
;//				("eject_troopers_enemy" delay(4.0) seat("seat13"))
;//				("eject_troopers_enemy" delay(4.5) seat("seat12"))
;//				("eject_troopers_enemy" delay(5.0) seat("seat11"))
;//				("eject_troopers_enemy" delay(5.5) seat("seat10"))
;//				("eject_troopers_enemy" delay(6.0) seat("seat9"))
;//				("eject_troopers_enemy" delay(6.5) seat("seat8"))
;//				("eject_troopers_enemy" delay(7.0) seat("seat7"))
;//				("eject_troopers_enemy" delay(7.5) seat("seat6"))
;//				("eject_troopers_enemy" delay(8.0) seat("seat5"))
;//				("eject_troopers_enemy" delay(8.5) seat("seat4"))
;//				("eject_troopers_enemy" delay(9.0) seat("seat3"))
;//				("eject_troopers_enemy" delay(9.5) seat("seat2"))
;//				("eject_troopers_enemy" delay(10.0) seat("seat1"))
;//			}
;//			
;//			; Снимаем защитный тег после завершения сброса
;//			{delay 30
;//				{hide 5}
;//				{tags remove "dropping_troopers"}
;//			}
;//		}
;//	}
;//
;//    {on break
;//        {if not tagged "exploded"
;//            {if chassis "airborne"
;//                {if component "body"
;//                    {if not tagged "dropping_troopers"
;//                        {if rand 0.5
;//                            {call "drop_troopers_enemy"}
;//                        }
;//                    }
;//                }
;//            }
;//        }
;//    }
;//
;//    {on destroy
;//        {if not tagged "exploded"
;//            {if chassis "airborne"
;//                {if not tagged "dropping_troopers"
;//                    {call "drop_troopers_enemy"}
;//                }
;//            }
;//        }
;//    }    
;//}

{"airborne drop_plane ai"
	{on spawn
		{delay 0.2
			{if work "body"
				{tags add "drop_plane"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}	
}

{"airborne 3_engine"
	{on "engine_count" overload
		{tags add "engine_count_3"}
	}

	{on "engine_start_sequence" overload
		{inherited}
		{if work "engine1"
			{delay 4.5 0.5
				{call_synced "engine2_start_sequence"}
			}
		else
			{call "engine2_start_sequence"}
		}
	}

	{on "engine1_stop_sequence" overload
		{inherited}
		{if not "engine_on"
			{call "engine2_stop_sequence"}
		}
	}
}

;//{"airborne fighter ai"	
;//	{on spawn
;//		{delay 0.2
;//			{if work "body"
;//				{tags add "fighter"}
;//				{tags add "move_to_start_waypoint"}
;//			}
;//		}
;//	}
;//
;//	{on "move_plane_to_initial_waypoint" 
;//		("move_plane_to_start_waypoint" args "fighter_ready")
;//	}
;//}

;//{"airborne bomber_ce ai"
;//	{on spawn
;//		{delay 0.2
;//			{if work "body"
;//				{tags add "bomber_ce"}
;//				{tags add "move_to_start_waypoint"}
;//			}
;//		}
;//	}
;//
;//	{on "move_plane_to_initial_waypoint" 
;//		("move_plane_to_start_waypoint" args "bomber_ce_ready")
;//	}
;//}
;//
;//{"airborne ai_recon_plane"
;//	{on spawn
;//		{delay 0.2
;//			{if work "body"
;//				{tags add "bot_recon"}
;//				{tags add "move_to_start_waypoint"}
;//			}
;//		}
;//	}
;//
;//	{on "move_plane_to_initial_waypoint" 
;//		("move_plane_to_start_waypoint" args "ai_recon_ready")
;//	}
;//}

{"player_plane"
    {on spawn
        {delay 10
            {able "select" 1}
        }
    }
}


;/*=========== Plane Specifics Begin  ===========*/

