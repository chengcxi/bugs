;============================================== New Modded sounds presets ============================================

;============================================== New Modded ============================================
;============================================== New Modded USA ========================================
;;--------------------------------------------- New Modded USA tanks ----------------------------------

{"m2a4_stuart tank"
	("m3_stuart_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("M1919A4")
	}
	{on fire "mgun3" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}

;;---------------------------------------------- New Modded USA cars -----------------------------------


{"zis5_61k"
	("zis5_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1")
	}
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")

	{on fire "gun"
		{ani_play "recoil"}
		{view start "flashbarrel1"}
		{view start "flashbarrel1smoke"}
		{call "spawn_shell"}
	}
}

;;---------------------------------------------- New Modded GER tanks ------------------------------
;----------------------------------------------- Panther_F
{"panther_f tank"
("pz5_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("MG34")
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
                        {if component "turret"
				{ani_play "turret_b" +1 resume}
			}
                        {if component "engine"
				{ani_play "engine_b" +1 resume}
			}
		}
	}
	{on repair
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
                }
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1 resume}
			}
                }
                {if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1 resume}
			}
                }
                {if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
                        }
		}
	}
}

{"marder3h tank"
	("pz38_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.15 0.05)
	}
}

{"marder139 tank"
	("pz38_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.25)
	}
}

{"panther_ii-hd"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("MG42")
		("Cannon_75to76mm_HV")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 3.5)	;// weapon reload time
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on fire "mgun"
		{ani_play "fire_mgun"}
	}
	{on "engine_on" 			;// settings for engine when switched on
		{if work "body"
			{if work "engine"
				{ani_play "fan" loop}
				{ani_play "Exhaust"}
			}
		}
	}
	{on "engine_off"
		{delay 1
			{ani_play "Fan"}
		}
		{delay 5
			{ani_play "Exhaust" -1}
		}
	}
	{on operatable on
			{kill_delay "Night1"}
			{kill_delay "Night2"}
			{if not "radar_up"
				{ani_play "Night1"  1.0 loop}
				{set "radar_up"}
			}
			{if not "radar_up1"
				{ani_play "Night2"  1.0 loop}
				{set "radar_up1"}
			}
		}
	{on operatable off
			{delay 3 "Night1"
			      {if "radar_up"
				{set "radar_up" 0}
				{ani_stop "radar_loop"}
				{ani_stop "Night1"}
			     }
			}
			{delay 3 "Night2"
			      {if "radar_up1"
				{set "radar_up1" 0}
				{ani_stop "radar_loop"}
				{ani_stop "Night2"}
			     }
			}
		  }
}

{"t34_kwk37 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}

{"bergetiger tank"
	("pz6_sound")

	{on spawn
		{add_view	"repair"		"repair"	"hearing_bone"}

		{link_sound "screw_twist"		"human/anims/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anims/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anims/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anims/repair/toolbox_close/"}
		{link_sound "tool_equip"		"human/anims/repair/tool_equip/"}
	}	
	
	{on "recovery_repair"			
		("repair_sounds_1")
		{delay 12
			("repair_sounds_2")
		}
		{delay 24
			("repair_sounds_1")
		}
		{delay 36
			("repair_sounds_2")
		}
		{delay 48
			("repair_sounds_1")
		}
		{view start "repair"}
		{spawn "recovery_repair_start" "basis"}
		{delay 0.5
			{spawn "recovery_repair_remover_effect" "basis"}
		}
		{delay 1
			{spawn "recovery_repair_checker_effect" "basis"}
		}
		{chassis_work 0}
		{damage_report "recovery_message_start" "<c(f3ff00)>Starting Repairs"}
		{delay 1 ;//SafeSwitch To avoid self Repair
			{tags remove "recovery_repair"}
		}
		{delay 60
			{if not operatable
				{spawn "recovery_repair_remover_effect" "basis"}
				{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Failed"}
				{view pause "repair"} 
				{chassis_work 1}
				{call "engine_on"}
			else operatable
				{spawn "recovery_repair_area" "basis"}
				{spawn "recovery_repair_remover" "basis"}
				{delay 1
					{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
					{view pause "repair"} 
					{chassis_work 1}
					{call "engine_on"}
				}
			}
		}
	}	
	
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	
}

{"m4a4_firefly_ger tank"
	{on "add_weapon_sound" overload
	;//	("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_75to76mm_HV")
		("MG42")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/m4a4/start"}
		{link_sound "engine_stop"		"vehicle/engine/m4a4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/m4a4/idle"}
		{link_sound "engine_full"		"vehicle/engine/m4a4/full"}
		{link_sound "exhaust"			"vehicle/engine/m4a4/exhaust"}
		{link_sound "move"			"vehicle/tracks/m4"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
}

{"stug3a tank"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}

{"stug4g tank"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("MG34")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}

{"panzerjager1_b tank"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz1/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz1/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz1/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz1/full"}
		{link_sound "exhaust"			"vehicle/engine/pz1/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz1"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.15 0.05)
	}
	{on "reload_delay" overload
		("reload_time" args 3.5)		;// weapon reload time
	}
}

{"bison2 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz2/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz2/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz2/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz2/full"}
		{link_sound "exhaust"			"vehicle/engine/pz2/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz2/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
}

{"panzer_2j tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		("MG34")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
    	}
}

{"pzvd_pziv_turret tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}

{"pzvd_pziv_turret_bare tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}

{"tiger1h_early tank"
	("pz6_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}

{"vk3601h tank"
	("vk3601h_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("MG34")
	}
}

{"vk6501h tank"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
	}
	{on spawn
		{add_view "tank_fire_medium_dust_ground_rain"	"medium_ground_r_fx"	"basis"}
		{add_view "tank_fire_medium_dust_ground"		"medium_ground_fx"		"basis"}
		{add_view "tank_fire_medium_dust_sand_rain"		"medium_sand_r_fx"		"basis"}
		{add_view "tank_fire_medium_dust_sand"			"medium_sand_fx"		"basis"}
		{add_view "tank_fire_medium_dust_snow"			"medium_snow_fx"		"basis"}
		{add_view	"tank_canon_fire_75_76"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/MAYBACH_HL224/start"}
		{link_sound "engine_stop"		"vehicle/engine/MAYBACH_HL224/stop"}
		{link_sound "engine_idle"		"vehicle/engine/MAYBACH_HL224/idle"}
		{link_sound "engine_full"		"vehicle/engine/MAYBACH_HL224/full"}
		{link_sound "exhaust"			"vehicle/engine/MAYBACH_HL224/exhaust"}
		{link_sound "move"				"vehicle/tracks/vk6501h"}
		{link_sound "rotate_turret"		"vehicle/turret/hydraulic/hydraulic_heavy"}
	}
	{on fire "gun"
			{ani_play "fire"}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
		{call "medium_terrain_fx"}
	}
	
	{on fire "mgun" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
                                {ani_wind "open5" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
				{ani_play "open5" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
					{ani_wind "open5" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
					{ani_play "open5" -1.0 resume}
				}
		}
	)
	{on "update_hatch_on_spawn"
		("update_hatch" wind(true))
	}
	(define "update_hatch_event"
		{on %event
			("update_hatch" wind(false))
		}
	)
	("update_hatch_event" event(operatable on))
	("update_hatch_event" event(operatable off))
	("update_hatch_event" event(crew in))
	("update_hatch_event" event(crew out))
}

;//{"tiger_p tank"
;//	{on "add_movement_sound" overload
;//		{link_sound "engine_start"		"vehicle/engine/ferdinand/start"}
;//		{link_sound "engine_stop"		"vehicle/engine/ferdinand/stop"}
;//		{link_sound "engine_idle"		"vehicle/engine/ferdinand/idle"}
;//		{link_sound "engine_full"		"vehicle/engine/ferdinand/full"}
;//		{link_sound "exhaust"			"vehicle/engine/ferdinand/exhaust"}
;//		{link_sound "move"				"vehicle/tracks/ferdinand/"}
;//		{link_sound "rotate_turret"		"vehicle/turret/hydraulic/hydraulic_heavy"}
;//	}
;//	{on "add_weapon_sound" overload
;//		("Cannon_85to100mm")
;//		("MG34")
;//	}
;//}

{"tiger_p tank"
;//	("ferdinand_sound")

	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/ferdinand/start"}
		{link_sound "engine_stop"		"vehicle/engine/ferdinand/stop"}
		{link_sound "engine_idle"		"vehicle/engine/ferdinand/idle"}
		{link_sound "engine_full"		"vehicle/engine/ferdinand/full"}
		{link_sound "exhaust"			"vehicle/engine/ferdinand/exhaust"}
		{link_sound "move"				"vehicle/tracks/ferdinand/"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_heavy"}
	}

	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_85to100mm")
	}
}

{"pz6p_Panzerbefehiswagen tank"
;//	("ferdinand_sound")

	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/ferdinand/start"}
		{link_sound "engine_stop"		"vehicle/engine/ferdinand/stop"}
		{link_sound "engine_idle"		"vehicle/engine/ferdinand/idle"}
		{link_sound "engine_full"		"vehicle/engine/ferdinand/full"}
		{link_sound "exhaust"			"vehicle/engine/ferdinand/exhaust"}
		{link_sound "move"				"vehicle/tracks/ferdinand/"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_heavy"}
	}

	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_85to100mm")
	}
}

{"ba6_roa tank"
	("ba_sound")
}

{"PzKw747_76_41 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("DT")
	}
}

{"pzkw747_57_43 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("DT")
	}
}

{"pzkpfw_kw_la753r_ger tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("DT")
	}
}

{"PzKw747_85 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DT")
	}
}

{"88mm-raketenwerfer43"
	("cannon_small")
}

{"PzKw753_40 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("DT")
	}
}

{"PzKw753_41 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("DT")
	}
}

{"PzKw754 tank"	     
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_150to210mm")
	}
}

{"PzKw755_S tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("DT")
	}
}

{"jagdtiger88 tank"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("MG34")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz6b/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6b/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6b/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6b/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6b/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz6b"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "charger2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "charger2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

;;---------------------------------------------- GER cannon -----------------------------------------------

{"105mm_flak38"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 23)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}
}

{"75mm_pak41"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 5.25)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

;-------------- 9cm_flak41i
{"9cm_flak41i"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}
}

;;---------------------------------------------- GER btr-----------------------------------------------

{"sdkfz6_supply"
	("hanomag_sound")
}

{"sdkfz6_weapon"
	("hanomag_sound")
}

{"sdkfz251d_2xgrw42 tank"
	("hanomag_sound")

	{on spawn
		{add_view "flash_cannon_small" "flashbarrel00" "shooter00"}
		{add_view "flash_cannon_small" "flashbarrel01" "shooter01"}
		{link_sound "whistle" "weapon/shot/mortar/whistle"}
		{link_sound "bkg_mortar" "weapon/shot/bkg/mortar/"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{play_sound "bkg_mortar"}
				{ani_play "fire%0"}
		)
		{if	("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
		{if name "00"
			{call "fire_gun_common"}
		}
		;{ani_play "recoil"}
	}

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

}

;;---------------------------------------------- GER car -----------------------------------------------


{"blitz3_6_raketenwerfer"
	("opel_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")

	("rocket_weapon" args gun)		;// defines weapon place that is disabled while vehicle is on move

	{on fire "rocket"
		{volumes "rocket" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
	}
	{on "reload"
		{if name "rocket"
			{delay 320										;// Delay set to match reload time of main weapon
				{volumes "rocket" enable bullet blast}
			}
		}
	}

	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "rocket"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
		}
	}
	{on "explosion_extra"
		{blastwave c4 9 r0 4 r1 15 offset 0 0 25}
		{blastwave c4 1.3 r0 15 r1 25 offset 0 0 25}
		{spawn "train_die" "basis"}
	}
}

;;----------------------------------------------- USSR guns -----------------------------------------------

{"160mm_mt_13_mortar"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	{on fire "gun"
		{delay 1
			{ani_play "reload_open"}
		}
		{delay 10
			{bone show "rocket00"}
		}
		{delay 15
			{ani_play "reload_close"}
		}
	}
	("repair_anm_script_v1")
}

{"82mm_bm37_ai"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

;;----------------------------------------------- USSR cars -----------------------------------------------

{"cckw_ussr"
	("cckw_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

{"94km car"
	("zis5_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

{"m72o"
	("r12_sound")
}

;;----------------------------------------------- USSR btr -----------------------------------------------

{"m2_halftrack_rus tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}

{"voroshilovets"
	("t34_sound")
}

{"ba64d"
	("ba_sound")
	{on "add_weapon_sound" overload
		("DShK38_int")
	}
}

{"ba11 tank"
	("ba_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("DT")
	}
}

{"m3_rus"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/us_halftrack/start"}
		{link_sound "engine_stop"		"vehicle/engine/us_halftrack/stop"}
		{link_sound "engine_idle"		"vehicle/engine/us_halftrack/idle"}
		{link_sound "engine_full"		"vehicle/engine/us_halftrack/full"}
		{link_sound "exhaust"			"vehicle/engine/us_halftrack/exhaust"}
		{link_sound "move"			"vehicle/tracks/m3a1"}
	}
	{on "add_weapon_sound" overload
		("M2HB")
	}
}

{"m17"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/us_halftrack/start"}
		{link_sound "engine_stop"		"vehicle/engine/us_halftrack/stop"}
		{link_sound "engine_idle"		"vehicle/engine/us_halftrack/idle"}
		{link_sound "engine_full"		"vehicle/engine/us_halftrack/full"}
		{link_sound "exhaust"			"vehicle/engine/us_halftrack/exhaust"}
		{link_sound "move"			"vehicle/tracks/m3a1"}
		{link_sound "rotate_turret"		"vehicle/turret/cannon/small"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/small"}
	}
	{on "add_weapon_sound" overload
		("M2HB_M45_Mount")
	}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_big"	"flashbarrel02"	"shooter02"}
		{add_view	"flash_gun_big"	"flashbarrel03"	"shooter03"}
	}
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
		{if  name "02"
			{view start "flashbarrel02"}
			{delay 0.2
				{view pause "flashbarrel02"}
			}
		else name "03"
			{view start "flashbarrel03"}
			{delay 0.2
				{view pause "flashbarrel03"}
			}
		}
	}
}

;;----------------------------------------------- USSR tanks-----------------------------------------------
;------------------------------------------------ t_42
{"t_42 tank"
	("su85_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_105to130mm_LV")
		{link_sound		"action_recoil_Cannon2"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound		"Cannon_Mid2"		"weapon/shot/cannon/s2/d2/Shared/Cannon_45to47mm/"}
		{link_sound		"Cannon_Far2"		"weapon/shot/cannon/s2/d3/Shared/Cannon_45to47mm/"}
		{link_sound		"action_recoil_Cannon3"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound		"Cannon_Mid3"		"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm/"}
		{link_sound		"Cannon_Far3"		"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm/"}
	}
	{on spawn
		{add_view	"flash_gun_big"		"flashbarrel3"			"foresight4"}
		{add_view "tank_canon_fire_75_76"			"flashbarrelmedium_b"	"Foresight1b"}
		{add_view "tank_canon_fire_75_76"			"flashbarrelmedium_c"	"Foresight1c"}
		{add_view "tank_canon_fire_37_47"			"flashbarrelminimum_d"	"Foresight1d"}
		{add_view "tank_canon_fire_37_47"			"flashbarrelminimum_e"	"Foresight1e"}
		{add_view "tank_fire_minimum_dust_ground"	"minimum_ground_fx"		"basis"}
		{add_view "tank_fire_minimum_dust_sand"		"minimum_sand_fx"		"basis"}
		{add_view "tank_fire_minimum_dust_snow"		"minimum_snow_fx"		"basis"}
		{add_view "tank_fire_medium_dust_ground_rain"	"medium_ground_r_fx"	"basis"}
		{add_view "tank_fire_medium_dust_ground"		"medium_ground_fx"		"basis"}
		{add_view "tank_fire_medium_dust_sand_rain"		"medium_sand_r_fx"		"basis"}
		{add_view "tank_fire_medium_dust_sand"			"medium_sand_fx"		"basis"}
		{add_view "tank_fire_medium_dust_snow"			"medium_snow_fx"		"basis"}
		{link_sound "bkg_cannon_small" "weapon/shot/bkg/cannon/small/"}
		{link_sound "bkg_cannon_medium" "weapon/shot/bkg/cannon/medium/"}
;//			{delay 0.2
;//				{tags add 
;//					"msg_superheavytank"
;//				}
;//			}
	}	
			
	{on fire "gun1"
		{play_sound "action_recoil_Cannon2"}
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"}
	}
	{on fire "gun2"
		{play_sound "action_recoil_Cannon3"}
		{play_sound "Cannon_Mid3"}
		{play_sound "Cannon_Far3"}
		{play_sound "bkg_cannon_medium"}
		{view start "flashbarrelmedium_b"}
		{call "medium_terrain_fx"}
	}
	{on fire "gun3"
		{play_sound "action_recoil_Cannon3"}
		{play_sound "Cannon_Mid3"}
		{play_sound "Cannon_Far3"}
		{play_sound "bkg_cannon_medium"}
		{view start "flashbarrelmedium_c"}
		{call "medium_terrain_fx"}
	}
	{on fire "gun4"
		{play_sound "action_recoil_Cannon2"}
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"}
		{play_sound "bkg_cannon_small"}
		{view start "flashbarrelminimum_d"}
		{call "minimum_terrain_fx"}
		{ani_play "fire4" +1 resume}
	}
	{on fire "gun5"
		{play_sound "action_recoil_Cannon2"}
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"}
		{play_sound "bkg_cannon_small"}
		{view start "flashbarrelminimum_e"}
		{call "minimum_terrain_fx"}
		{ani_play "fire5" +1 resume}
	}
	{on fire "mgun3"
		{view start "flashbarrel3"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{delay 0.2
			{view pause "flashbarrel3"}
		}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "turret"
				{ani_play "turret_b" +1 resume}
			}
			{if component "aux_turret1"
				{ani_play "aux_turret1_b" +1 resume}
			}
			{if component "aux_turret2"
				{ani_play "aux_turret2_b" +1 resume}
			}
			{if component "aux_turret3"
				{ani_play "aux_turret3_b" +1 resume}
			}
			{if component "aux_turret4"
				{ani_play "aux_turret4_b" +1 resume}
			}
			{if component "gun1"
				{ani_play "gun1_b" +1 resume}
			}
			{if component "gun2"
				{weapon_work "gun2" 0}
				{ani_play "gun2_b" +1 resume}
			}
			{if component "gun3"
				{weapon_work "gun3" 0}
				{ani_play "gun3_b" +1 resume}
			}
			{if component "gun4"
				{weapon_work "gun4" 0}
				{ani_play "gun4_b" +1 resume}
			}
			{if component "gun5"
				{weapon_work "gun5" 0}
				{ani_play "gun5_b" +1 resume}
			}
		}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
			}
		}
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1 resume}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
		}
		{if component "gun1"
			{if work "gun1"
				{ani_play "gun1_r" +1 resume}
			}
		}
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1 resume}
			}
		}
		{if component "aux_turret1"
			{if work "aux_turret1"
				{ani_play "aux_turret1_r" +1 resume}
			}
		}
		{if component "aux_turret2"
			{if work "aux_turret2"
				{ani_play "aux_turret2_r" +1 resume}
			}
		}
		{if component "aux_turret3"
			{if work "aux_turret3"
				{ani_play "aux_turret3_r" +1 resume}
			}
		}
		{if component "aux_turret4"
			{if work "aux_turret4"
				{ani_play "aux_turret4_r" +1 resume}
			}
		}
		{if component "gun2"
			{if work "gun2"
				{weapon_work "gun2" 1}
				{ani_play "gun2_r" +1 resume}
			}
		}
		{if component "gun3"
			{if work "gun3"
				{weapon_work "gun3" 1}
				{ani_play "gun3_r" +1 resume}
			}
		}
		{if component "gun4"
			{if work "gun4"
				{weapon_work "gun4" 1}
				{ani_play "gun4_r" +1 resume}
			}
		}
		{if component "gun5"
			{if work "gun5"
				{weapon_work "gun5" 1}
				{ani_play "gun5_r" +1 resume}
			}
		}
	}
	{on "__explosion"
		{tags add "exploded"}
		{blastwave c4 15 r0 5 r1 12 offset 0 0 75}
		{blastwave c4 3 r0 12 r1 30 offset 0 0 75}
		{spawn "ex_he_size7" "basis"}
		{spawn "tank_die_heavy" "basis"}
		{delay 0.1
			{call "_explosion"}
		}
		{delay_ex 0
			{set "no_burn_volumes" 1}
			{set_skeleton "_xx" sync}
			{call "impulse"}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}
	{on "explosion_blastwave" overload
		{blastwave c4 9 r0 5 r1 10 offset 0 0 75}
		{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
		{impulse up 0.1 0.1 dir 0.2 0.1}
		{spawn "ex_he_size7" "basis"}
		{spawn "tank_die_heavy" "basis"}
		{start_sound "detonation/explosion_vehicle/bkg/"}
		{if terrain_fx "snow"
			{spawn "ex_he_size7_snow" "basis"}
			{spawn "tank_die_heavy" "basis"}
		else terrain_fx "ice"
			{spawn "ex_he_size7_snow" "basis"}
			{spawn "tank_die_heavy" "basis"}
		else
			{spawn "ex_he_size7_dust" "basis"}
			{spawn "tank_die_heavy" "basis"}
		}
		{delay_ex 0
			{set "no_burn_volumes" 1}
			{set_skeleton "_xx" sync}
			{call "impulse"}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}
}

;------------------------------------------------ kv-3
{"kv-3 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_105to130mm")
	}
}

;------------------------------------------------ zsu_37
{"zsu_37 tank"
	("t70_sound")
	{on "reload"
		{bone hide "clip_ammo"}
	{delay 1.5
		{bone show "clip_ammo"}
	}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{tags add "engine_brake"}
				{ani_play "engine_b" +1 resume}
			}
			{if component "gun"
				{tags add "gun_brake"}
				{ani_play "gun_b" +1 resume}
			}
		}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
			}
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
		}
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	{on ik begin "gun_rot" overload
		{kill_delay "rotate_gun"}
		{if not "rotate_gun"
			{play_sound "rotate_gun" 1}
			{set "rotate_gun" 1}
			{ani_play "aim_v" loop resume}
		}
	}
	{on ik end "gun_rot" overload
		{delay 0.25 "rotate_gun"
			{stop_sound "rotate_gun"}
			{set "rotate_gun" 0}
			{ani_stop "aim_v"}
		}
	}
	{on ik begin "turret" overload
		{kill_delay "rotate_turret"}
		{if not "rotate_turret"
			{play_sound "rotate_turret" 1}
			{set "rotate_turret" 1}
			{ani_play "aim_h" loop resume}
		}
	}
	{on ik end "turret" overload
		{delay 0.25 "rotate_turret"
			{stop_sound "rotate_turret"}
			{set "rotate_turret" 0}
			{ani_stop "aim_h"}
		}
	}
}

;------------------------------------------------ is1_43
{"is_100 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DT")
		("SG43")
	}
	
;//	{on fire "gun" overload
;//		{view start "flashbarrel1"}
;//		{view start "flashbarrel1smoke"}
;//		{ani_play "fire"}
;//	}
}

;------------------------------------------------ kv1_122
{"kv1_122 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("DT")
	}
	{on fire "gun"
		{ani_play "fire"}
		{ani_play "fire2"}
	}
}

{"smk tank"
	("t28_sound")
	{on "add_weapon_sound" overload
		("DT")
		("DShK38")
		("Cannon_75to76mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s2/d2/Shared/Cannon_45to47mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s2/d3/Shared/Cannon_45to47mm/"}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{if rand 0.5
					{call_synced "kill_gunner4"}
				else
					{call_synced "kill_charger3"}
				}
			}
		}
	}
}

{"marder139_rus tank"
	("pz38_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.25)
	}
}

{"kv220 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("DT")
	}
	("repair_anm_script_v1")
}

{"kv_220 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DT")
	}
	("repair_anm_script_v1") 
}

{"panther_5 tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_75to76mm_HV")
	}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
		{ani_wind "binocular" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
		{ani_wind "binocular" begin}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "turret"
				{ani_play "turret_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
		}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
		}
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1 resume}
			}
		}
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1 resume}
			}
		}
	}	
}


{"bt2_supply_rus tank"
	("bt_sound")
}
{"bt2_25mm_auto_rus tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1")
	}

}
{"bt2_25mm_rus tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		("DT")
	}
	{on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"foresight2"}
	}
	{on fire "mgun1" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "flashbarrel00"}
		{delay 0.2
			{view pause "flashbarrel00"}
		}
	}
}
{"bt2_da2_2gun_rus tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("DT")
	}

	{on spawn
		{add_view "flash_gun_big"	"flashbarrel00" "shooter00" }
		{add_view "flash_gun_big"	"flashbarrel01" "shooter01" }
		{add_view "flash_gun_big"	"flashbarrel02" "shooter02" }
		{add_view "flash_gun_big"	"flashbarrel03" "shooter03" }
	}

	{on fire "mgun2" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
	{on fire "mgun1" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel02"}
			{delay 0.2
				{view pause "flashbarrel02"}
			}
		else name "01"
			{view start "flashbarrel03"}
			{delay 0.2
				{view pause "flashbarrel03"}
			}
		}
	}
}
{"bt2_2gun_rus tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("DT")
	}
	{on spawn
	{add_view "tank_canon_fire_37_47" "fire_gun_1" "foresight2"}
	{link_sound		"Cannon_Mid"		"weapon/shot/cannon/s1/d2/Shared/Cannon_37to40mm/"}
	{link_sound		"Cannon_Far"		"weapon/shot/cannon/s1/d3/Shared/Cannon_37to40mm/"}
	}
	{on fire "gun_1" 
		{play_sound "Cannon_Mid"}
		{play_sound "Cannon_Far"}
		{view start "fire_gun_1"}
		{ani_play "fire2"}
	}
}
{"bt2 tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("DT")
	}
}
{"bt2_rus tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("DT")
	}
}
{"bt2_da2 tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun2" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
}
{"bt2_da2_rus tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun2" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
}
{"wolverine"
	("m10_gmc_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
}

{"object248 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("DT")
		("DShK38")
	}
	{on fire "mgun"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
	}
	{on "commander_hatch_open" overload
		{ani_play "com_open" 1}
		{ani_play "mgun_aa" 1}
	}
	{on "commander_hatch_close" overload
		{ani_play "com_open" -1}
		{ani_play "mgun_aa" -1}
	}
}

{"su122p tank"
	("su85_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}
	{on move on 
		              {ani_play "fan" 1 loop}
	}
	{on fire "gun"
		{ani_play "fire"}
		{call "spawn_shell"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.3 0.22)
	}
;--	{on "reload_delay" overload
;--		("reload_delay" args 7.0 0.4 6.0)
;--	}
}


{"su5 tank"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t26/start"}
		{link_sound "engine_stop"		"vehicle/engine/t26/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t26/idle"}
		{link_sound "engine_full"		"vehicle/engine/t26/full"}
		{link_sound "exhaust"			"vehicle/engine/t26/exhaust"}
		{link_sound "move"				"vehicle/tracks/t26/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}

{"su14 tank"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz6/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6/exhaust"}
		{link_sound "move"			"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}

{"t34_44nohead tank"
	("t34_sound")
	{on move on 
		              {ani_play "fan" 1 loop}
	}
	{on "add_weapon_sound" overload
		("DT")
	}

}

{"a32_39 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("DT")
	}
}

{"t34_44supply tank"
	("t34_sound")
	{on move on 
		              {ani_play "fan" 1 loop}
	}
	{on "add_weapon_sound" overload
		("DT")
	}
	
	{on spawn
		{add_view	"repair"		"repair"	"hearing_bone"}

		{link_sound "screw_twist"		"human/anims/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anims/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anims/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anims/repair/toolbox_close/"}
		{link_sound "tool_equip"		"human/anims/repair/tool_equip/"}
	}	
	
	{on "recovery_repair"			
		("repair_sounds_1")
		{delay 12
			("repair_sounds_2")
		}
		{delay 24
			("repair_sounds_1")
		}
		{delay 36
			("repair_sounds_2")
		}
		{delay 48
			("repair_sounds_1")
		}
		{view start "repair"}
		{spawn "recovery_repair_start" "basis"}
		{delay 0.5
			{spawn "recovery_repair_remover_effect" "basis"}
		}
		{delay 1
			{spawn "recovery_repair_checker_effect" "basis"}
		}
		{chassis_work 0}
		{damage_report "recovery_message_start" "<c(f3ff00)>Starting Repairs"}
		{delay 1 ;//SafeSwitch To avoid self Repair
			{tags remove "recovery_repair"}
		}
		{delay 60
			{if not operatable
				{spawn "recovery_repair_remover_effect" "basis"}
				{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Failed"}
				{view pause "repair"} 
				{chassis_work 1}
				{call "engine_on"}
			else operatable
				{spawn "recovery_repair_area" "basis"}
				{spawn "recovery_repair_remover" "basis"}
				{delay 1
					{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
					{view pause "repair"} 
					{chassis_work 1}
					{call "engine_on"}
				}
			}
		}
	}
}

{"su122e tank"
	("su85_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
	}
	{on move on 
		              {ani_play "fan" 1 loop}
	}
}

{"t3485_43 tank"
	("t34_sound")
	{on move on 
		              {ani_play "fan" 1 loop}
	}
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DT")
	}
}

{"t4485 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DT")
	}
}

{"kv2_39 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("DT")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.2 0.22)
	}
}

{"kv2_zis6 tank"
	("kv_sound")
	
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("DT")
	}
	{on fire "mgun"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
	}
	{on "commander_hatch_open" overload
		{ani_play "com_open" 1}
	}
	{on "commander_hatch_close" overload
		{ani_play "com_open" -1}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.2 0.22)
	}
;--	{on "reload_delay" overload
;--		("reload_delay" args 7.0 0.5 6.0)
;--	}
}

;// {"kv2_zis6 tank"
;// 	("kv_sound")
;// 	{on "add_weapon_sound" overload
;// 		("Cannon_105to130mm")
;// 		("Cannon_Breech")
;// 		("DT")
;// 	}
;// 	{on spawn
;// 		{link_sound "pizza_time_music"		"music/pizza_time_320_kbps_mp3"}
;// 	}
;// 	{on "spawn_shell_delay" overload
;// 		("shell_eject_delay" args 1 0.05)
;// 	}
;// 	{on "add_weapon_sound" overload
;// 		("DT")
;// 	}
;// 	{on break				;// volume breaks
;// 		{if not tagged "exploded"
;// 			{if component "engine"
;// 				{tags add "engine_brake"}
;// 				{ani_play "engine_b" +1 resume}
;// 			}
;// 			{if component "gun"
;// 				{tags add "gun_brake"}
;// 				{ani_play "gun_b" +1 resume}
;// 			}
;// 		}
;// 	}
;// 	{on repair
;// 		{if component "engine"
;// 			{if work "engine"
;// 				{ani_play "engine_r" +1 resume}
;// 			}
;// 			{if work "gun"
;// 				{ani_play "gun_r" +1 resume}
;// 			}
;// 		}
;// 	}
;// 	{on "engine_off"
;// 		{delay 1
;// 			{if rand 0.01
;// 			{ani_play "pizza_time"}
;// 			{play_sound "pizza_time_music"}
;// 			}
;// 		}
;// 	}
;// 	{on "engine_on"
;// 		{delay 1
;// 			{ani_play "pizza_time" -1 resume}
;// 		}
;// 	}
;// }

{"kv122 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("DT")
	}
}

{"t34_100 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_85to100mm")
	}
	{on fire "flamer1"
		{volumes "smoke1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "piece_smoke_barrel1"}
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel1_t34_100" bone "smoke_barrel1_t34_100" copy
				{impulse forward -1 }
			}
		}
		{components "barrel1_ammo" break}
		{tags add "need_ammo1"}
		{delay 0.6
			{bone hide "smoke_barrel1_t34_100"}
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		}
		{call_synced "flamer1"}
	}
	{on fire "flamer2"
		{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "piece_smoke_barrel2"}
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel2_t34_100" bone "smoke_barrel2_t34_100" copy
				{impulse forward -1 }
			}
		}
		{components "barrel2_ammo" break}
		{tags add "need_ammo2"}
		{delay 0.6
			{bone hide "smoke_barrel2_t34_100"}
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		}
		{call_synced "flamer2"}
	}
	{on break                ;// volume breaks
        {if not tagged "exploded"
            {if component "engine"
                {tags add "engine_brake"}
                {ani_play "engine_b" +1 resume}
            }
	    {if component "body"
                {ani_play "body_b" +1 resume}
            }
       }
	{if not "flamer1"
		{call_synced "flamer1"}
	}
	{if not "flamer2"
		{call_synced "flamer2"}
	}
	{if component "smoke1"
		{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		{tags add "need_ammo1"}
		{spawn "ex_sm_size2" "fx_smoke1"}
		{volumes "smoke1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "smoke_barrel1_t34_100"}
		{bone hide "piece_smoke_barrel1"}
		{call_synced "smoke1"}
		{if not "smoke1"
			{call_synced "smoke1"}
		}
        }
	{if component "smoke2"
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
	    		{tags add "need_ammo2"}
	    		{spawn "ex_sm_size2" "fx_smoke2"}
	    		{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{bone hide "smoke_barrel2_t34_100"}
	    		{bone hide "piece_smoke_barrel2"}
			{call_synced "smoke2"}
			{if not "smoke2"
				{call_synced "smoke2"}
			}
       		}
       }
       {on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
			}
		}
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1 resume}
			}
		}
		{if component "barrel1_ammo"
			{bone show "smoke_barrel1_t34_100"}
			{bone show "piece_smoke_barrel1"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "barrel1_ammo"}
		}
		{if component "barrel2_ammo"
			{bone show "smoke_barrel2_t34_100"}
			{bone show "piece_smoke_barrel2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "barrel2_ammo"}
		}
		{if component "smoke1"
			{bone show "smoke_barrel2_t34_100"}
			{bone show "piece_smoke_barrel2"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "smoke1"}
		}
		{if component "smoke2"
			{bone show "smoke_barrel2_t34_100"}
			{bone show "piece_smoke_barrel2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "smoke2"}
		}
	}
}

{"t44100 tank"
	("t44_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DT")
		("DShK38")
	}
	{on fire "mgun"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" 1}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1}
	}
}

{"t44_122 tank"
	("t44_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("DT")
	}
           {on break                ;// volume breaks
        {if not tagged "exploded"
            {if component "engine"
                {tags add "engine_brake"}
                {ani_play "engine_b" +1 resume}
            }
            {if component "gun"
                {tags add "gun_brake"}
                {ani_play "gun_b" +1 resume}
                        }
                        {if component "body"
                {tags add "body_brake"}
                {ani_play "body_b" +1 resume}
                        }
                        {if component "turret"
                {tags add "turret_brake"}
                {ani_play "turret_b" +1 resume}
                        }
               }
       }
       {on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
			}
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
		}
	} 
}

{"t70_45 tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("DT")
	}
}

{"su57b tank"
	("valentine_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("DT")
	}
}

{"isu_152_2"
	("is_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
	}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
		{ani_play "mgun_open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
		{ani_play "mgun_open" -1.0 resume}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
                        {if component "engine"
				{ani_play "engine_b" +1 resume}
			}
		}
	}
	{on repair
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
                }
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1 resume}
			}
                }
                {if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
                        }
		}
	}
}

;;----------------------------------------------- USA tanks-----------------------------------------------

;------------------------------------------------ us_t95
{"us_t95_gen2 tank"
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("Cannon_105to130mm")
	}
	{on spawn
		{bone hide "trackr_broken"}
		{bone hide "trackl_broken"}
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight4"}
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
;//			{delay 0.2
;//				{tags add 
;//					"msg_superheavytank"
;//				}
;//			}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/kv/start"}
		{link_sound "engine_stop"		"vehicle/engine/kv/stop"}
		{link_sound "engine_idle"		"vehicle/engine/kv/idle"}
		{link_sound "engine_full"		"vehicle/engine/kv/full"}
		{link_sound "exhaust"			"vehicle/engine/kv/exhaust"}
		{link_sound "move"				"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "com_open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "com_open" -1.0 resume}
	}
	{on fire "mgun3" 
	{play_sound "action_recoil_HMG"}
	{play_sound "HMG_Mid"}
	{play_sound "HMG_Far"}
        {view start "fire_gun2"}
	{view start "mgun_eject2"}
	{delay 0.2
		{view pause "fire_gun2"}
		{view pause "mgun_eject2"}
		}
    	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "trackleft"
				{bone show "trackl_broken"}
				{bone hide "trackl"}
			}
			{if component "trackright"
				{bone show "trackr_broken"}
				{bone hide "trackr"}
			}
		}
	}
	{on repair
		{if not tagged "exploded"
			{if component "trackleft"
			 	{bone hide "trackl_broken"}
			 	{bone show "trackl"}
			}	
			{if component "trackright"
			 	{bone hide "trackr_broken"}
			 	{bone show "trackr"}
			}
		}
	}
}

;------------------------------------------------ us_t95
{"us_t95 tank"
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("Cannon_105to130mm")
	}
	{on spawn
		{bone hide "trackr_broken"}
		{bone hide "trackl_broken"}
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight4"}
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
;//			{delay 0.2
;//				{tags add 
;//					"msg_superheavytank"
;//				}
;//			}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/kv/start"}
		{link_sound "engine_stop"		"vehicle/engine/kv/stop"}
		{link_sound "engine_idle"		"vehicle/engine/kv/idle"}
		{link_sound "engine_full"		"vehicle/engine/kv/full"}
		{link_sound "exhaust"			"vehicle/engine/kv/exhaust"}
		{link_sound "move"				"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "com_open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "com_open" -1.0 resume}
	}
	{on fire "mgun3" 
	{play_sound "action_recoil_HMG"}
	{play_sound "HMG_Mid"}
	{play_sound "HMG_Far"}
        {view start "fire_gun2"}
	{view start "mgun_eject2"}
	{delay 0.2
		{view pause "fire_gun2"}
		{view pause "mgun_eject2"}
		}
    	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "trackleft"
				{bone show "trackl_broken"}
				{bone hide "trackl"}
			}
			{if component "trackright"
				{bone show "trackr_broken"}
				{bone hide "trackr"}
			}
		}
	}
	{on repair
		{if not tagged "exploded"
			{if component "trackleft"
			 	{bone hide "trackl_broken"}
			 	{bone show "trackl"}
			}	
			{if component "trackright"
			 	{bone hide "trackr_broken"}
			 	{bone show "trackr"}
			}
		}
	}
}


;=============================================== New Modded cars ============================================

;;---------------------------------------------- Germany AT-guns -----------------------------------------------
{"28cm_wkspr_stan"

	("cannon_small")
	{on fire "gun"
		{play_sound "bkg_rocket"}
		{spawn "nebelwerfer_fire"}
		{volumes "rocket" disable bullet blast}		;// Disables rocket volume after firing while reloading
	}
	{on "cut_parts" overload
		("cut_part" args "stand" 1)
		{inherited}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "rocket"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
		}
	}
	{on "explosion_extra"
		{blastwave c4 9 r0 4 r1 15 offset 0 0 25}
		{blastwave c4 1.3 r0 15 r1 25 offset 0 0 25}
		{spawn "train_die" "basis"}
	}
}
;;---------------------------------------------- Germany btrs --------------------------------------------

{"sdkfz251c_tarp tank"
	("hanomag_sound")

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner4_hatch_open" overload
		{ani_play "mgun_aa_2" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun_aa_2" -1.0 resume}
	}
}

;;---------------------------------------------- Germany cars -----------------------------------------------

{"opel_blitz_omnibus"
	("zis5_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
;//	("opel_sound")
;//	("animation_sound" args "open_left")
;//	("animation_sound" args "open_right")
;//	("animation_sound" args "open_rear")
;//	("animation_sound" args "close_rear")
}

;//{"blitz3_6_medic car"
;//	("opel_sound")
;//}

{"volvo car"
	("volvo_sound")
}

{"volvo_art car"
	("volvo_sound")
}

{"blitz3_6_open car"
	("opel_sound")
}

{"kubelwagen_open car"
	("kubel_sound")
}

;;----------------------------------------------- GER tanks -----------------------------------------------

;;---------------------------------------- e_100a
{"e_100a tank"
    {on "add_weapon_sound" overload
		("MG34")
		("Cannon_105to130mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm/"}
    }
    {on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz6b/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6b/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6b/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6b/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6b/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz6b"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
    {on spawn
		{add_view "tank_canon_fire_75_76" "fire_gun2"	"foresight1a"}
		{delay 0.2
			{tags add 
				"msg_superheavytank"
			}
		}
    }
    {on fire "gun2" 
	{play_sound "action_recoil_Cannon2"}
	{play_sound "Cannon_Mid2"}
	{play_sound "Cannon_Far2"}
        {view start "fire_gun2"}
        {ani_play "fire1"}
    }
    {on "explosion_blastwave" overload
		{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
		{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
		{impulse up 0.1 0.1 dir 0.2 0.1}
		{spawn "tank_die_heavy" "basis"}
		{spawn "fuel_die" "basis"}
		{start_sound "detonation/explosion_vehicle/bkg/"}
		;{call "cut_parts"}
		{if terrain_fx "snow"
			{spawn "tank_die_snow" "basis"}
		else terrain_fx "ice"
			{spawn "tank_die_snow" "basis"}
		else
			{spawn "tank_die_dust" "basis"}
		}
		{spawn "shellhole_dead_tank2" "basis" terrain_texmod}
            	{spawn "crater_massive" "basis"}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "turret"
				{ani_play "turret_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "gun1"
				{ani_play "gun1_b" +1 resume}
			}
		}
	}
	{on repair
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
		}
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1 resume}
			}
		}
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1 resume}
			}
		}
		{if component "engine"
			{if work "engine"
				{ani_play "turret_r" +1 resume}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" 1 resume}
			}
		}
		{if component "gun1"
			{if work "gun1"
				{ani_play "gun1_r" +1 resume}
			}
		}
	}
}

;;---------------------------------------- e_100b
{"e_100b tank"
    {on "add_weapon_sound" overload
		("MG42")
		("Cannon_105to130mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm/"}
    }
    {on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz6b/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6b/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6b/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6b/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6b/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz6b"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
    {on spawn
	{add_view "tank_canon_fire_75_76" "fire_gun2"	"foresight1a"}
		{if rand 0.65
			{bone hide "net_camo"}
			{bone hide "net1"}
			{bone hide "net2"}
			{bone hide "net3"}
			{bone hide "net4"}
			{bone hide "net5"}
			{bone hide "net6"}
			{bone hide "cable"}
			{bone hide "cable1"}
			{bone hide "cable2"}
			{bone hide "cable3"}
			{bone hide "cable4"}
			{bone hide "cable5"}
			{bone hide "cable6"}
		}		
		{delay 0.2
			{tags add 
				"msg_superheavytank"
			}
		}
    }
    {on fire "gun2" 
	{play_sound "action_recoil_Cannon2"}
	{play_sound "Cannon_Mid2"}
	{play_sound "Cannon_Far2"}
        {view start "fire_gun2"}
        {ani_play "fire1"}
    }
    {on "explosion_blastwave" overload
		{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
		{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
		{impulse up 0.1 0.1 dir 0.2 0.1}
		{spawn "tank_die_heavy" "basis"}
		{spawn "fuel_die" "basis"}
		{start_sound "detonation/explosion_vehicle/bkg/"}
		;{call "cut_parts"}
		{if terrain_fx "snow"
			{spawn "tank_die_snow" "basis"}
		else terrain_fx "ice"
			{spawn "tank_die_snow" "basis"}
		else
			{spawn "tank_die_dust" "basis"}
		}
		{spawn "shellhole_dead_tank2" "basis" terrain_texmod}
            	{spawn "crater_massive" "basis"}
	}
	("repair_anm_script_v1")
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
	}
}

;;---------------------------------------- e_100ñ
{"e_100c tank"
	("pz6b_sound")
	{on "add_weapon_sound" overload
		("MG34")	
		("Cannon_105to130mm")
	}
	{on "explosion_blastwave" overload
		{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
		{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
		{impulse up 0.1 0.1 dir 0.2 0.1}
		{spawn "tank_die_heavy" "basis"}
		{spawn "fuel_die" "basis"}
		{start_sound "detonation/explosion_vehicle/bkg/"}
		{call "cut_parts"}
		{if terrain_fx "snow"
			{spawn "tank_die_snow" "basis"}
		else terrain_fx "ice"
			{spawn "tank_die_snow" "basis"}
		else
			{spawn "tank_die_dust" "basis"}
		}
		{spawn "shellhole_dead_tank2" "basis" terrain_texmod}
            	{spawn "crater_massive" "basis"}
	}
}

;;---------------------------------------- lowehd
{"lowehd tank"
	("pz6b_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("MG42")
	}
	
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
	
	{on fire "mgun"
		{ani_play "fire_mgun"}
	}
	
	{on "engine_on" 			;// settings for engine when switched on
		{if work "body"
			{if work "engine"
				{ani_play "fan" loop}
				{ani_play "Exhaust"}
			}
		}
	}
	
	{on "engine_off"
		{delay 1
			{ani_play "Fan"}
		}
		{delay 5
			{ani_play "Exhaust" -1}
		}
	}
}

;;---------------------------------------- t26_pak9738
{"t26_pak9738 tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.9 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 3.2)
	}
}
{"t26_pak9738_ger tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.9 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 3.2)
	}
}

;;---------------------------------------- flakpanzer1a
{"flakpanzer1a tank"
	{on "zenite_terrain_fx" overload}
	("pz1_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		("MG34")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
		{link_sound "action_recoil"		"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
	}
}

;;---------------------------------------- coelian_i
{"coelian_i tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		("MG34")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
		{link_sound "action_recoil"		"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
	}
	{on spawn
		{add_view "tank_fire_minimum_dust_ground"		"minimum_ground_fx"		"basis"}
   		{add_view "tank_fire_minimum_dust_sand"		"minimum_sand_fx"		"basis"}
   		{add_view "tank_fire_minimum_dust_snow"		"minimum_snow_fx"		"basis"}
   	}
	{on fire "gun"  
		{call "minimum_terrain_fx"}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "turret"
				{ani_play "turret_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
		}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
		}
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1 resume}
			}
		}
		{if component "body"
			{if work "turret"
				{ani_play "body_r" +1 resume}
			}
		}
	}	
}

;;---------------------------------------- coelian_ii
{"coelian_ii tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s2")
		("MG34")
		{link_sound		"action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound "action_recoil"		"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
	}
	{on spawn
		{add_view "tank_fire_minimum_dust_ground"		"minimum_ground_fx"		"basis"}
   		{add_view "tank_fire_minimum_dust_sand"		"minimum_sand_fx"		"basis"}
   		{add_view "tank_fire_minimum_dust_snow"		"minimum_snow_fx"		"basis"}
   	}
	{on fire "gun"  
		{call "minimum_terrain_fx"}
	}
	("repair_anm_script_v1")
	{on "commander_hatch_open" overload
		{ani_play "mgun_open" 1.0 resume}
		{ani_play "mgun_aa" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_wind "mgun_open" begin}
	}	
}


;;----------------------------------------------- USSR cars -----------------------------------------------

{"gaz_aaa_open"
	("gaz_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

{"gaz67_open"
	("gaz_sound")
}

{"zis5_open car"
	("zis5_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

{"gaz_su12 car"
	("zis5_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on fire "gun"
		{ani_play "recoil" +1}
	}
}

;;----------------------------------------------- FIN artillery -----------------------------------------------



;;----------------------------------------------- FIN SPG -----------------------------------------------


;;----------------------------------------------- FIN cars -----------------------------------------------

{"volvo_weapon"
	("volvo_sound")
}

;;----------------------------------------------- New Modded FIN tanks -----------------------------------------------

{"smk_fin tank"
	("t28_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Maxim_Gun")
		("KP31")
		("Cannon_75to76mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s2/d2/Shared/Cannon_45to47mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s2/d3/Shared/Cannon_45to47mm/"}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{if rand 0.5
					{call_synced "kill_gunner4"}
				else
					{call_synced "kill_charger3"}
				}
			}
		}
	}
}

;=============================================== New Modded btr ============================================
;;---------------------------------------------- Germany btr -----------------------------------------------

{"sdkfz10_open"
	("hanomag_sound")
}

{"sdkfz251_20 tank"
	("hanomag_sound")
}

{"zgkw303f tank"
	("hanomag_sound")
}

{"sdkfz251_22 tank"
	("hanomag_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on fire "gun"
		{if rand 0.01
			{tear "piece_large_steel" bone "turret"
				{impulse dir -0.5 fx -1 }
			}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.05)
	}
	{on operatable off
		{delay 2
			{ani_play "open" +1.0 resume}
		}
	}
	{on operatable on
		{delay 2
			{ani_play "open" -1.0 resume}
		}
	}
	("repair_anm_script_v1")
}

;;----------------------------------------------- USSR btr -----------------------------------------------


;=============================================== New Modded static ============================================
;;---------------------------------------------- Germany static -----------------------------------------------
{"blitz3_6_engineering_stand car"
	("opel_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
}

{"blitz3_6_fuel_stand car"
	("opel_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
}

{"blitz3_6_radio_stand car"
	("opel_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
	("animation_sound" args "open_radio")
}

{"opel_maultier_stand car"
	("opel_maultier_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

{"kettenkrad_stand car"
	("kettenkrad_sound")

	{on "wheel_torn_logic" overload
		{tags add "wheel_destroyed"}
	}
}

{"105mm_flak38_stat"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	("cannon_big")

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "wheell1" 1)
		("cut_part" args "wheelr1" 1)
		("cut_part" args "wheell2" 1)
		("cut_part" args "wheelr2" 1)
		{inherited}
	}
}

{"50mm_flak41_bunker_stand"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.32) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "standr" 1)
		("cut_part" args "standl" 1)
		("cut_part" args "trailer_front" 1)
		("cut_part" args "trailer_rear" 1)
		{inherited}
	}

	("cannon_big")
}

{"37mm_flak37_stand"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		("cut_part" args "part7" 1)
		{inherited}
	}

	("cannon_small")
}

{"50mm_flak41_stand"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.32) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "standr" 1)
		("cut_part" args "standl" 1)
		("cut_part" args "trailer_front" 1)
		("cut_part" args "trailer_rear" 1)
		{inherited}
	}

	("cannon_big")
}

{"75mm_pak40_stand"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 5.25)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"88mm_flak18_stand"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}
}

{"105mm_flak38_stand"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 23)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}
}

{"105mm_lefh18_stand"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 0.8)
		("cut_part" args "part2" 0.8)
		("cut_part" args "part3" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}

	("cannon_big")
}
;;---------------------------------------------- /Germany static -----------------------------------------------

;;----------------------------------------------- USSR static -----------------------------------------------

{"zis5eng_stand car"
	("zis5_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
}

{"gaz_aaa_supply_stand car"
	("gaz_sound")
}

{"gaz_fuel_stand car"
	("gaz_sound")
}

{"gaz_aaa_supply_stand car"
	("gaz_sound")
}

{"stalinetz60_stand"
	("s60_sound")
}

{"300mm_m30_stand"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_curved_heap" "sandbag")
	}
}

{"37mm_61k_stand"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.35) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}

	("cannon_small")
}

{"85mm_52k_stand"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

{"107mm_m1910_30_stand"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}

{"122mm_m30_stand"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}

{"122mm_m1910_stand"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}

{"203mm_b4_stand"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 12)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_big")
}

{"dshk_aa_stand"
	{on "init_gun" overload
		("DShK38")
		{add_view "shell_hmgun" "shell" "fxshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}

	{on fire "mgun1"
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{play_sound "action_recoil_HMG"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_straight_heap" "sandbag")
	}
}

{"100mm_bs3_stand"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.9 0.15)
	}

	{on "reload_delay" overload
		("reload_time" args 6.1)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_big")
}

{"76mm_m1938_stand"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}


;;----------------------------------------------- /USSR static -----------------------------------------------

;;----------------------------------------------- Finland static -----------------------------------------------

{"ford_3ton_ammo_stand car"
	("opel_sound")
}

{"ford_3ton_eng_stand car"
	("opel_sound")
}

{"ford_3ton_fuel_stand car"
	("opel_sound")
}

{"20mm_itk40_stand"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}
	("cannon_small")
}

{"20mm_itk35_stand"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("magazine" cut(0.4) show(1.8) override(overload) impulse({impulse up 0.3 0.2 forward 1.9 0.2}))

	{on "cut_parts" overload
		("cut_part" args "wheell" 1)
		("cut_part" args "wheelr" 1)
		{inherited}
	}

	("cannon_small")
}

{"40mm_itk38b_stand"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.45) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_small")
}

{"75mm_itk37_stand"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	("cannon_big")

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "wheell1" 1)
		("cut_part" args "wheelr1" 1)
		("cut_part" args "wheell2" 1)
		("cut_part" args "wheelr2" 1)
		{inherited}
	}
}

{"75mm_itk44_stand"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	("cannon_big")

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "wheell1" 1)
		("cut_part" args "wheelr1" 1)
		("cut_part" args "wheell2" 1)
		("cut_part" args "wheelr2" 1)
		{inherited}
	}
}

{"105mm_k34_stand"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}

	("cannon_big")
}

{"155mm_h17_stand"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		{inherited}
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 30)
	}

	("cannon_big")
}
;;-------------------------------------------- /Finland static ---------------------------------------------

;;----------------------------------------------- USA static -----------------------------------------------

{"cckw_engineer_late_stand"
	("cckw_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")

	{on "commander_hatch_open" overload
		{ani_wind "cabin_cover" end}
	}
	{on "commander_hatch_close" overload
		{ani_wind "cabin_cover" begin}
	}
}

{"cckw_redball_stand"
	("cckw_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")

	{on "commander_hatch_open" overload
		{ani_wind "cabin_cover" end}
	}
	{on "commander_hatch_close" overload
		{ani_wind "cabin_cover" begin}
	}
	{on spawn
		("rand_cut_else" args "redball1" "redball2")
	}
}

{"cckw_fuel_stand"
	("cckw_sound")
	
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

{"40mm_m1_stand"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.45) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_small")
}

{"57mm_m1_late_stand"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	("cannon_small")
}

{"90mm_m1a1_stand"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "standf" 1)
		;("cut_part" args "pivot_front" 1)
		{inherited}
	}
}

{"105mm_m2a1_stand"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}

	("cannon_big")
}

{"203mm_m1_stand"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 70)
	}

	{on "cut_parts" overload
		("cut_part" args "gun" 0.6)
		("cut_part" args "gun_rot" 0.6)
		("cut_part" args "turret_mesh" 0.6)
		{inherited}
	}

	("cannon_big")
}

;;----------------------------------------------- /USA static -----------------------------------------------


;=============================================== New Modded bot ============================================
;;-------------------------------------------- Finland bot ---------------------------------------------


{"75mm_itk37_bot"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	("cannon_big")

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "wheell1" 1)
		("cut_part" args "wheelr1" 1)
		("cut_part" args "wheell2" 1)
		("cut_part" args "wheelr2" 1)
		{inherited}
	}
}

;;------------------------------------------ / Finland bot ---------------------------------------------

;;-------------------------------------------- Germany bot ---------------------------------------------

{"88mm_flak18_bot"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}
}

;;-------------------------------------------- /Germany bot ---------------------------------------------

;;-------------------------------------------- USSR bot ---------------------------------------------

{"85mm_52k_bot"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

;;-------------------------------------------- /USSR bot ---------------------------------------------

;;-------------------------------------------- USA bot ---------------------------------------------

{"57mm_m1_bot"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	("cannon_small")
}

;;-------------------------------------------- /USA bot ---------------------------------------------

;//-------------------------------------------------------------------------- ARm tag-cleaner
{"tank"

	{on "die"
		{delay 0.9	
			{if tagged "msg_superheavytank"
				{tags remove "msg_superheavytank"}
			}
		}
	}
	
}	