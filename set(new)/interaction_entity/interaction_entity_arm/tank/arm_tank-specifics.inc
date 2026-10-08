; File: 		arm_tank-specifics.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm\tank
; Created by: 	Max Drechsler
; Created:		22.08.2025
; Modify by:	Max Drechsler
; Modify:		17.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		x.x
; Description: 

;;============================================== GER =============================================================
;;============================================== GER tanks =======================================================
{"vespa moto"
    {on spawn
	{add_view "tank_canon_fire_100_105" "fire_gun2" "foresight3"}
    }
    {on fire "gun" 
        {view start "fire_gun2"}
    }
}
;;============================================== GER tanks light =================================================
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
{"panzer_2j tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG34")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
    }	
}
{"flakpanzer1a tank"
	{on "zenite_terrain_fx" overload}
	("pz1_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG34")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
		{link_sound "action_recoil"		"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
	}
}
{"marder_1fcm_36 tank"
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	("pz3_sound")
}
{"pz38tna_b tank"
    ("pz38_sound")          ;----------> change sound
    {on "add_weapon_sound" overload
		("MG34")
		("Cannon_37to40mm")
    } 
}
{"pzkpfw_2hvk903 tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("Cannon_Breech")
	}
}
{"pz2j tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG34")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
    	}
}
{"sdkfz221_spzb41 tank"
	("sdkfz222_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
}
{"sdkfz301wanze tank"
	("hanomag_sound")
}	

;;============================================== GER tanks medium ================================================
{"Panther_f tank"
("pz5_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("MG34")
	}
	("repair_anm_script_panther_f")
}
{"Panther_II_88 tank"
("pz5_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("MG34")
	}
	("repair_anm_script_panther_f")
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
{"stug3a tank"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
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
		("Cannon_Breech")
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
{"coelian_i tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
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
	("repair_anm_script_v1")
	{on "commander_hatch_open" overload
		{ani_play "mgun_open" 1.0 resume}
		{ani_play "mgun_aa" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_wind "mgun_open" begin}
	}
	{on "pre_cookoff"
		{ani_play "open_commander" 1.0 resume}
	}	
}
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
{"pz_sfl_ivc tank"
	("pz4_sound")
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
	("repair_anm_script_v1")
}
{"beutepanzer_m4a2"
	("m4a2_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("M2HB")
		("M1919A4")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.3 0.1)
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
	}
	{on operatable on
		{kill_delay "roll"}
		{if not "radar_up"
			{ani_play "viewport" loop}
			{set "radar_up"}
		}
		{if not work "turret"
			{set "radar_up" 0}
			{ani_wind "viewport" end}
		}
		{if work "turret"
			{set "radar_up"}
			{ani_play "viewport" loop}
		}
	}
	{on operatable off
		{delay 3 "roll"
			 {if "radar_up"
				{set "radar_up" 0}
				{ani_stop "radar_loop"}
				{ani_stop "viewport"}
			  }
		}
	}
}
{"dicker_max tank"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.5 0.3)
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
	}
	{on "reload"
		{ani_play "reload" +1 resume}
	}
	("repair_anm_script_v1")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
}
{"geschuetzwagen_ivb tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}		;--------------- need different classSelector because it does the wrong explosion
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_heavy"}
	}
	("tag_ai_arty_mace")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
}
{"jagdpanzer_iv_a_armor"
	("pz4_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
}
{"jagdpanzer_iv_a"
	("pz4_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
}
{"ezart tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	("repair_anm_script_v1")
}
;;============================================== GER tanks heavy =================================================
{"bergetiger tank"
	("pz6_sound")

	{on spawn
		{add_view	"repair"		"repair"	"hearing_bone"}
		{tags add 	"ai_engineer_vehicle"}
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
{"tiger_p tank"

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
{"jagdtiger88 tank"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
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
{"e_100b tank"
    {on "add_weapon_sound" overload
		("MG42")
		("Cannon_105to130mm")
;//		("Cannon_150to210mm")		
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
{"e_100c tank"
	("pz6b_sound")
	{on "add_weapon_sound" overload
		("MG34")	
		("Cannon_150to210mm")
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
{"pzkpfw_8_maus tank"
    {on "add_weapon_sound" overload
		("MG34")
		("Cannon_105to130mm")
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
	{if rand 0.01
		{tex_mod "house"}
	}
    }
    {on fire "gun2"
	{play_sound "action_recoil_Cannon2"}
	{play_sound "Cannon_Mid2"}
	{play_sound "Cannon_Far2"} 
        {view start "fire_gun2"}
        {ani_play "fire2"}
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
{"kv2_754r tank"
	("kv_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_150to210mm")
	}
}
{"elefant tank"
	("ferdinand_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
}
{"pz6bh_105mm tank"
	("pz6b_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_105to130mm")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
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
}
{"pzkpfw_6_ausf_b_tiger_sla16 tank"
	("ferdinand_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_85to100mm_HV")
	}
}
{"nbfz tank"
	("pz38_sound")          ;----------> change sound
    {on "add_weapon_sound" overload
		("MG34")
		("Cannon_75to76mm_LV")
		{link_sound		"action_recoil_Cannon2"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound		"Cannon_Mid2"		"weapon/shot/cannon/s1/d2/Shared/Cannon_37to40mm/"}
		{link_sound		"Cannon_Far2"		"weapon/shot/cannon/s1/d3/Shared/Cannon_37to40mm/"}
    } 
    {on spawn
	{add_view "tank_canon_fire_37_47" "fire_gun2"	"foresight2"}
    }
    {on fire "gun2"
	{play_sound "action_recoil_Cannon2"}
	{play_sound "Cannon_Mid2"}
	{play_sound "Cannon_Far2"} 
        {view start "fire_gun2"}
    }
    {on break
		{if not tagged "exploded"
			{if component "aux_turret2"
				{call "kill_commander"}
			else component "aux_turret1"
				{call "kill_charger2"}
			}
		}
    }
    {on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun2" 1}
		else
			{weapon_work "mgun2" 0}
		}
		{if work "aux_turret2"
			{weapon_work "mgun3" 1}
		else
			{weapon_work "mgun3" 0}
		}
		{inherited}
    }
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
	("repair_anm_script_v1")	
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
{"kv5 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_105to130mm")
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret2"
				{call "kill_commander"}
			else component "aux_turret1"
				{call "kill_charger2"}
			}
			{if component "aux_turret1"
				{call "kill_commander"}
			else component "aux_turret1"
				{call "kill_commander"}
			}
			{if component "aux_turret3"
				{call "kill_driver"}
			else component "aux_turret1"
				{call "kill_driver"}
			}
		}
    }
    {on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun" 1}
		else
			{weapon_work "mgun" 0}
		}
		{if work "aux_turret2"
			{weapon_work "mgun2" 1}
		else
			{weapon_work "mgun2" 0}
		}
		{inherited}
    }
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
{"sdkfz_251_10 tank"
	("hanomag_sound")
	{on "add_weapon_sound" overload
		("MG151_15_Drilling")
	}
	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(gun) head(0.081))

	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
	;{on spawn
	;	{add_view	"flash_gun_big"	"flashbarrel00"	"fx_smoke00"}
	;	{add_view	"flash_gun_big"	"flashbarrel01"	"fx_smoke01"}
	;	{add_view	"flash_gun_big"	"flashbarrel02"	"fx_smoke02"}
	;}
	{on "reload"
		{bone hide "ammo_chain1"}
		{bone hide "ammo_chain2"}
		{bone hide "ammo_chain3"}
	{delay 15
		{bone show "ammo_chain1"}
		{bone show "ammo_chain2"}
		{bone show "ammo_chain3"}
	}
	}
	;{on fire "gun" overload
	;	{if  name "00"
	;		{ani_play "fire2" +1 resume}
	;		{view start "flashbarrel00"}
	;		{delay 0.2
	;			{view pause "flashbarrel00"}
	;		}
	;	else name "01"
	;		{ani_play "fire3" +1 resume}
	;		{view start "flashbarrel01"}
	;		{delay 0.2
	;			{view pause "flashbarrel01"}
	;		}
	;	else name "02"
	;		{ani_play "fire1" +1 resume}
	;		{view start "flashbarrel02"}
	;		{delay 0.2
	;			{view pause "flashbarrel02"}
	;		}
	;	}
	;}
	("repair_anm_script_v1")
}

;;============================================== GER tank STATIC ==========================================================
{"panzer1f_stand tank"
	{on spawn
        {delay 0.3
			{call "engine_off"}
        }
    }
	
	{on "add_weapon_sound" overload
		("MG34")
	}
}

;;============================================== GER btr ==========================================================
{"sdkfz_251_21 tank"
	("hanomag_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
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
{"sdkfz251c_stuka tank"
	{on "add_weapon_sound" overload
		("MG34")
	}
	("hanomag_sound")

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner4_hatch_open" overload
		{ani_wind "binocular" end}
	}
	{on "gunner4_hatch_close" overload
		{ani_wind "binocular" begin}
	}

	{on fire "rocket"
		{volumes "rocket" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{chassis_work 0}
        {delay 3
        {chassis_work 1}
        }
	}
	{on "reload"
		{if name "rocket"
			{delay 105									;// Delay set to match reload time of main weapon
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
		{blastwave c4 12 r0 4 r1 20 offset 0 0 25}
		{blastwave c4 1.3 r0 15 r1 25 offset 0 0 25}
		{spawn "train_die" "basis"}
	}
}
;;============================================== USSR ============================================================
;;============================================== USSR tanks ======================================================
;;============================================== USSR tanks light ================================================
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

;;============================================== USSR tanks medium ===============================================
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
{"zsu_37 tank"
	("t70_sound")
	{on "reload"
		{bone hide "clip_ammo"}
	{delay 1.5
		{bone show "clip_ammo"}
	}
	}
	("repair_anm_script_v1")
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
	("repair_anm_script_v1")
}
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
	("repair_anm_script_v1")	
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
}
{"kv_220 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DT")
	}
	("repair_anm_script_v1") 
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
	("tag_ai_arty_mace")
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
	("tag_ai_arty_mace")
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
		{tags add 	"ai_engineer_vehicle"}
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
		("Cannon_Breech")
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
{"kv2_zis6 tank"
	("kv_sound")

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.05)
	}
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_105to130mm")
	}
	("repair_anm_script_v1")
	{on "engine_off"
		{delay 1
			{if rand 0.1
			{ani_play "pizza_time"}
			{play_sound "pizza_time_music"}
			}
		}
	}
	{on "engine_on"
		{delay 1
			{ani_play "pizza_time" -1 resume}
		}
	}
}
{"kv122 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_105to130mm")
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
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("DT")
	}
    ("repair_anm_script_v1")
}
{"t70_45 tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_75to76mm")
	}
}
{"su57b tank"
	("valentine_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("DT")
	}
}

;;============================================== USSR tanks heavy ===============================================
{"kv-3 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_105to130mm")
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
{"ISU_152_2"
	("is_sound")
	{on "add_weapon_sound" overload
;//		("Cannon_85to100mm_HV")
		("Cannon_150to210mm")
		("Cannon_Breech")
		("DShK38")
	}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
		{ani_play "mgun_open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
		{ani_play "mgun_open" -1.0 resume}
	}
	("repair_anm_script_v1")
}
{"su100y tank"
	{on "add_weapon_sound" overload
;//		("Cannon_105to130mm")
		("Cannon_150to210mm")
		("Cannon_Breech")
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
}
{"is_7 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("RP_46")
		("KPVT")
		("KPVT_AA")
;//		("Cannon_105to130mm")
		("Cannon_150to210mm")
	}
	{on fire "mgun"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
	}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}

		{add_view	"flash_gun_big"	"flashbarrel02"	"shootero00"}
		{add_view	"flash_gun_big"	"flashbarrel03"	"shootero01"}
		{add_view	"flash_gun_big"	"flashbarrel04"	"shooterm00"}
		{add_view	"flash_gun_big"	"flashbarrel05"	"shooterm01"}

		{add_view	"flash_gun_big"	"flashbarrel_big1"	"foresight3"}

		{add_view	"shell_mgun"	"mgun_eject1"	"shell_eject3"}
		{add_view	"shell_mgun"	"mgun_eject2"	"shell_eject2"}

		{add_view "aircraft_damage_small"	"fire_smoke"	"smoke_eject"}
	}
	{on fire "flamer1"
		{volumes "smoke1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "smoke_holder1"}
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel1_is3" bone "smoke_barrel1" copy
				{impulse forward -1 }
			}
		}
		{components "barrel1_ammo" break}
		{tags add "need_ammo1"}
		{delay 0.6
			{bone hide "smoke_barrel1"}
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		}
		{call_synced "flamer1"}
	}
	{on fire "flamer2"
		{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "smoke_holder2"}
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel2_is3" bone "smoke_barrel2" copy
				{impulse forward -1 }
			}
		}
		{components "barrel2_ammo" break}
		{tags add "need_ammo2"}
		{delay 0.6
			{bone hide "smoke_barrel2"}
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		}
		{call_synced "flamer2"}
	}
	{on fire "mgun1" overload
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
	{on fire "mgun2" overload
		{ani_play "mgun1_fire" 1}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{view start "flashbarrel_big1"}
		{delay 0.2
			{view pause "flashbarrel_big1"}
		}
	}
	{on fire "mgun3" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel02"}
			{view start "mgun_eject2"}
			{delay 0.2
				{view pause "flashbarrel02"}
				{view pause "mgun_eject2"}
			}
		else name "01"
			{view start "flashbarrel03"}
			{view start "mgun_eject1"}
			{delay 0.2
				{view pause "flashbarrel03"}
				{view pause "mgun_eject1"}
			}
		}
	}
	{on fire "mgun4" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel04"}
			{delay 0.2
				{view pause "flashbarrel04"}
			}
		else name "01"
			{view start "flashbarrel05"}
			{view start "mgun_eject1"}
			{delay 0.2
				{view pause "flashbarrel05"}
				{view pause "mgun_eject1"}
			}
		}
	}
	{on fire "mgun6" overload
		{ani_play "mgun1_fire" 1}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{view start "flashbarrel_big1"}
		{delay 0.2
			{view pause "flashbarrel_big1"}
		}
	}
	{on repair
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1 resume}
			}
		}
		{if component "barrel1_ammo"
			{bone show "smoke_barrel1"}
			{bone show "smoke_holder1"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "barrel1_ammo"}
		}
		{if component "barrel2_ammo"
			{bone show "smoke_barrel2"}
			{bone show "smoke_holder2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "barrel2_ammo"}
		}
		{if component "smoke1"
			{bone show "smoke_barrel1"}
			{bone show "smoke_holder1"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "smoke1"}
		}
		{if component "smoke2"
			{bone show "smoke_barrel2"}
			{bone show "smoke_holder2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "smoke2"}
		}
	}
	{on break
	{if component "smoke1"
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
			{tags add "need_ammo1"}
			{spawn "ex_sm_size2" "fx_smoke1"}
			{volumes "smoke1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{bone hide "smoke_barrel1"}
			{bone hide "smoke_holder1"}
			{call_synced "smoke1"}
    	}
		{if component "smoke2"
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
	    	{tags add "need_ammo2"}
	    	{spawn "ex_sm_size2" "fx_smoke2"}
	    	{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{bone hide "smoke_barrel2"}
			{bone hide "smoke_holder2"}
		{call_synced "smoke2"}
    	}
        {if component "body"
                {ani_play "body_b" +1 resume}
        }
    }
}

;;============================================== USSR btr ======================================================
{"voroshilovets"
	("t34_sound")
}
{"m2_halftrack_rus tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}
{"ba64d"
	("ba_sound")
	{on "add_weapon_sound" overload
		("DShK38")
	}
}
{"ba11"
	("ba_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("DT")
	}
}

;;============================================== USSR car ======================================================
{"zsu_29k car"
	("zis5_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.5 0.3)
	}
	{on spawn
		
		{call "wheel_torn_check"}
	}
	{on move on
		{ani_play "start" 1.0 callback}
		{set "animated" 1}
	}
	{on "update_lights"
		{if not sunlight					;// checks if night time to show headlight fx
			{if "engine_on"
				{call "lights_on"}
			else
				{call "lights_off"}
			}
		else
			{call "lights_off"}
		}
		{if rain							;// checks if raining to play windshield wipers
			{if "engine_on"
				{ani_play "wipers" loop resume}
			else
				{ani_stop "wipers"}
			}
		else
			{ani_stop "wipers"}
		}
	}
	{on "engine_toggle" 		;// UI button to toggle engine on/off
		{if operatable
			{if work "engine"
				{if work "body"
					{if not "engine_on"
						{if not "toggle_delay"
							{call "engine_on"}
						}
					else not "toggle_delay"
						{call "engine_off"}
					}
				}
			else
				{tags add "engine_turned_off"}	;// allows engine to be set to off state when damaged. Cancels auto engine start on repair
			}
		}
		{set "toggle_delay" 1}			;// stops accidental double click of UI button
		{delay 1 {set "toggle_delay" 0}}
	}
	{on "engine_check" 		;// turns engine on at spawn if crewed and not tagged engine off
		{set "engine_check" 1}
		{delay 0.1
			{if tagged "engine_turned_off"
				{chassis_work 0}
				{set "engine_on" 0}
			else
				{if operatable
					{if tagged "hidden" 	;// mission script that hides unit
						{set "hidden" 1}
					else
						{call "engine_idle"}
						{call "play_trace_engine"} 		;// plays dust fx for aero vehicles
						{call "update_lights"}
					}
				}
			}
			{set "engine_check" 0}
		}
	}
	{on "repaired_engine_check" 		;// turns engine on when repaired if crewed and not tagged engine off
		{if not "engine_check" 			;// stops call from happening at spawn
			{if operatable
				{if not tagged "engine_turned_off"
					{if not "engine_on"
						{call "engine_on"}
					}
				}
			}
		}
	}
	{on "engine_on" 			;// settings for engine when switched on
		{if work "body"
			{if work "engine"
				{tags remove "engine_turned_off"}
				{view show "stop_signal"}
				{view start "stop_signal"}
				{play_sound "engine_start"}
				{ani_play "engine_work" loop}
				{ani_play "fan_spin" loop}
				{set "engine_on" 1}
				{call "update_lights"}
				{add_view	"exhaust_dark_big_startup"	"exhaust_start"	"FXsmoke1"}
				{add_view	"exhaust_dark_big_startup"	"exhaust_start"	"FXsmoke2"}
				{delay 1.5 "engine_startup"
					{view start "exhaust_start"}
					{delay 0.5
						{view pause "exhaust_start"}
					}
					{delay 1.25 "engine_startup2"
						{play_sound "exhaust"}
					}
					{delay 1.5 "engine_startup3"
						;{play_sound "exhaust"}
						{call "engine_idle"}
					}
				}
			}
		}
	}

	{on "engine_off" 						;// settings for engine when switched off
		{kill_delay "engine_startup"}		;// stops engine startup sequence
		{kill_delay "engine_startup2"}		;// stops engine startup sequence
		{kill_delay "engine_startup3"}		;// stops engine startup sequence
		{set "engine_on" 0}
		{call "update_lights"}
		{ani_play "fan_spin"}
		{stop_sound "engine_idle"}
		{stop_sound "move"}
		{stop_sound "engine_full"}
		{stop_sound "engine_start"}
		{play_sound "engine_stop"}
		{tags add "engine_turned_off"}		;// tracks engine on/off status for mission save/load
		{chassis_work 0}
		{delay 1
			{view pause "exhaust2"}
			{ani_stop "engine_work"}
			{view hide "stop_signal"}
		}
	}

	{on "engine_idle"					;// settings for engine while idle
		{if work "engine"
			{if work "trackleft"
				{if work "trackright"
					{if not tagged "wheel_destroyed"		;// Checks if wheel has been torn off
						{chassis_work 1}
					}
				}
			}
			{set "engine_on" 1}
			{view pause "exhaust_start"}
			{stop_sound "engine_start"}
			{play_sound "engine_idle" 1}
			{ani_play "engine_work" loop}
			{view start "exhaust2"}
			{view hide "stop_signal"}
		}
	}

	{on "engine stop view"				;// called on engine and body break
		{set "engine_on" 0}
		{call "update_lights"}
		{kill_delay "engine_startup"}		;// stops engine startup sequence
		{kill_delay "engine_startup2"}		;// stops engine startup sequence
		{kill_delay "engine_startup3"}		;// stops engine startup sequence
		{view pause "exhaust"}
		{stop_sound "engine_idle"}
		{stop_sound "engine_full"}
		{stop_sound "engine_start"}
		{ani_stop "engine_work"}
		{view pause "exhaust2"}
	}

	{on "engine fullstop"					;// called on explosion
		{set "engine_on" 0}
		{kill_delay "engine_startup"}		;// stops engine startup sequence
		{kill_delay "engine_startup2"}		;// stops engine startup sequence
		{kill_delay "engine_startup3"}		;// stops engine startup sequence
		{view pause "exhaust"}
		{ani_stop "engine_work"}
		{delay 0 "engine_stopped"
			{stop_sound "engine_idle"}
			{stop_sound "engine_start"}
			{stop_sound "engine_stop"}
		}
		{delay 0 "engine_steam_stopped"
			{view pause "exhaust2"}
		}
	}

	{on "update_moveable"
		{if work "engine"
			{call "check_work_mover"}
		else
			{chassis_work 0}
			{ik_enable "basis" 0}			;// stops motorized cannons from rotating when engine or track is broken
		}
	}

	{on "check_work_mover"
		{if work "mover"
			{if not tagged "wheel_destroyed"		;// Checks if wheel has been torn off
				{if not tagged "engine_turned_off"	;// Checks that player didn't turn off engine before repairs are made
					{chassis_work 1}
					{ik_enable "basis" 1}	;// allows motorized cannons to rotate when engine or track is broken
				}
			}
		else
			{chassis_work 0}
			{ik_enable "basis" 0}			;// stops motorized cannons from rotating when engine or track is broken
		}
		{if tagged "wheel_destroyed"
			{chassis_work 0}
		else
			{if not work "mover"
				{chassis_work 0}
			else broken "wheel" 4
				{chassis_work 0}
			else broken "wheel" 3
				{chassis_work 1}
				{movement_limit slow}
			else broken "wheel" 2
				{chassis_work 1}
				{movement_limit slow}
			else broken "wheel" 1
				{chassis_work 1}
				{movement_limit normal}
			else tagged "engine_turned_off"
				{chassis_work 0}
				{movement_limit fast}
			else
				{chassis_work 1}
				{movement_limit fast}
			}
		}
	}

	{on "stop_on"
		{if work "body"						;// Prevents animations from reseting body break animations if vehicle is moving on break
			{if not "animated"				;// Prevents animation from playing when "start" animation is currently playing
				;{ani_stop "start"}
				{ani_play "stop" 1.0 callback}
				{set "animated" 1}
			}
		}
	}

	{on "exhaust_on"
		{if "engine_on"						;// Prevents sounds from playing if called after engine is off/broken
			{view start "exhaust"}
			{play_sound "exhaust"}
		}
	}

	{on "exhaust_off"
;//		{stop_sound "exhaust"}
		{view pause "exhaust"}
		{view start "exhaust2"}				;// idle exhaust
	}
	(define "hide_wheel_spawn"
		{if tagged "%component_torn"
			{bone hide "%bone"}
			{bone hide "%component"}
			{volumes "%component" disable visible bullet blast contact contact_ground}
		}
	)

	{on "wheel_torn_check"
		("hide_wheel_spawn" component(wheelleft1) bone(wheell1))
		("hide_wheel_spawn" component(wheelleft2) bone(wheell2))
		("hide_wheel_spawn" component(wheelleft3) bone(wheell3))
		("hide_wheel_spawn" component(wheelleft4) bone(wheell4))
		("hide_wheel_spawn" component(wheelleft5) bone(wheell5))
		("hide_wheel_spawn" component(wheelleft6) bone(wheell6))
		("hide_wheel_spawn" component(wheelleft7) bone(wheell7))
		("hide_wheel_spawn" component(wheelleft8) bone(wheell8))
		("hide_wheel_spawn" component(wheelright1) bone(wheelr1))
		("hide_wheel_spawn" component(wheelright2) bone(wheelr2))
		("hide_wheel_spawn" component(wheelright3) bone(wheelr3))
		("hide_wheel_spawn" component(wheelright4) bone(wheelr4))
		("hide_wheel_spawn" component(wheelright5) bone(wheelr5))
		("hide_wheel_spawn" component(wheelright6) bone(wheelr6))
		("hide_wheel_spawn" component(wheelright7) bone(wheelr7))
		("hide_wheel_spawn" component(wheelright8) bone(wheelr8))
		("hide_wheel_spawn" component(wheelfront) bone(wheelfront))
	}

	{on blast							;// blastwave hits specific volume
		{if volume "wheel"
			{if stuff "mine"
				{if min_energy 4
					{call "tear_wheel"}
				}
			else min_energy 12.1 ;//150mm HE
				{if rand 1 {call_synced "tear_wheel"}}
			else min_energy 7.1 ;//105mm HE
				{if rand 0.5 {call_synced "tear_wheel"}}
			else min_energy 3.1 ;//75mm HE
				{if rand 0.25 {call_synced "tear_wheel"}}
			}
		}
	}

	{on pierce sync
		{if volume "wheel"
			{if stuff "auto"
				; do nothing
			else stuff "shell size1"
				; do nothing
			else stuff "shell size2"  ;//75mm
				{if rand 0.25 {call_synced "tear_wheel"}}
			else stuff "shell size3"  ;//105mm
				{if rand 0.5 {call_synced "tear_wheel"}}
			else stuff "shell"  ;//150mm and up
				{if rand 1 {call_synced "tear_wheel"}}
			}
		}
	}

	(define "check_wheel"
		{if tagged "%component_torn"
			{tags add "wheel_destroyed"}
		}
	)

	(define "check_wheel_x2"
		{if tagged "%component_torn"
			{if tagged "wheel_teared"			;// 2nd wheel torn
				{tags add "wheel_destroyed"}	;// disables movement
				{tags remove "wheel_teared"}
			else
				{tags add "wheel_teared"}		;// 1st wheel torn
				{movement_limit slow}
			}
		}
	)

	{on "check_wheel_torn"
		("check_wheel" component(wheelleft1))
		("check_wheel" component(wheelleft2))
		("check_wheel" component(wheelleft3))
		("check_wheel" component(wheelleft4))
		("check_wheel" component(wheelleft5))
		("check_wheel" component(wheelleft6))
		("check_wheel" component(wheelleft7))
		("check_wheel" component(wheelleft8))
		("check_wheel" component(wheelright1))
		("check_wheel" component(wheelright2))
		("check_wheel" component(wheelright3))
		("check_wheel" component(wheelright4))
		("check_wheel" component(wheelright5))
		("check_wheel" component(wheelright6))
		("check_wheel" component(wheelright7))
		("check_wheel" component(wheelright8))
		("check_wheel" component(wheelfront))
		{call "check_work_mover"}
	}

	(define "hide_wheel"
		{if component "%component"
			{delay 0
				{bone hide "%bone"}
				{bone hide "%component"}
				{volumes "%component" disable visible bullet blast contact contact_ground}
				{tags add "%component_torn"}
			}
		}
	)

	(define "show_wheel"
		{if component "%component"
			{bone show "%bone"}
			{bone show "%component"}
			{volumes "%component" enable visible bullet blast contact contact_ground}
			{tags remove "%component_torn"}
			{tags remove "wheel_destroyed"}
			{tags remove "wheel_teared"}
			{call "check_wheel_torn"}
		}
	)

	{on "dont_move"
		{tags add "wheel_destroyed"}
		{call "check_work_mover"}
		{crew_enable place "driver" 0}
	}

	{on "tear_wheel"
		{call "wheel_torn_logic"}
		{spawn "spheredust_small"}
		{component break}
		{tear "piece_medium_steel" bone from_volume id "wheel" copy
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse up 6 1 forward -2 2 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1}
			{add_view "smoke_dead_wheel" "smoke" "basis"}
			{view start "smoke"}
			{delay_effect 10 5 "pause"}
		}
		("hide_wheel" component(wheelleft1) bone(wheell1))
		("hide_wheel" component(wheelleft2) bone(wheell2))
		("hide_wheel" component(wheelleft3) bone(wheell3))
		("hide_wheel" component(wheelleft4) bone(wheell4))
		("hide_wheel" component(wheelleft5) bone(wheell5))
		("hide_wheel" component(wheelleft6) bone(wheell6))
		("hide_wheel" component(wheelleft7) bone(wheell7))
		("hide_wheel" component(wheelleft8) bone(wheell8))
		("hide_wheel" component(wheelright1) bone(wheelr1))
		("hide_wheel" component(wheelright2) bone(wheelr2))
		("hide_wheel" component(wheelright3) bone(wheelr3))
		("hide_wheel" component(wheelright4) bone(wheelr4))
		("hide_wheel" component(wheelright5) bone(wheelr5))
		("hide_wheel" component(wheelright6) bone(wheelr6))
		("hide_wheel" component(wheelright7) bone(wheelr7))
		("hide_wheel" component(wheelright8) bone(wheelr8))
		("hide_wheel" component(wheelfront) bone(wheelfront))		;// kettenkrad
		{if not tagged "impluse"
			{impulse up 0.3}
			{tags add "impluse"}
			{delay 0.5
				{tags remove "impluse"}
			}
		}
		{call "check_work_mover"}
	}

	{on "wheel_torn_logic"
		{tags add "wheel_destroyed"}	;// disables movement
	}

	{on break
		{if not tagged "exploded"
			{if component "wheel"
				{if not linked
					{if not velocity 0.5
						{call "break_wheel_impulse"}
					}
				}
			}
			{if component "ammo1"
				{blastwave c4 20 r0 10 r1 25}
				{spawn "tank_die_light" "basis"}
				{set "big_explosion" 1}
			}
			{if component "ammo2"
				{blastwave c4 20 r0 10 r1 25}
				{spawn "tank_die_light" "basis"}
				{set "big_explosion" 1}
			}
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
		("show_wheel" component(wheelleft1) bone(wheell1))
		("show_wheel" component(wheelleft2) bone(wheell2))
		("show_wheel" component(wheelleft3) bone(wheell3))
		("show_wheel" component(wheelleft4) bone(wheell4))
		("show_wheel" component(wheelleft5) bone(wheell5))
		("show_wheel" component(wheelleft6) bone(wheell6))
		("show_wheel" component(wheelleft7) bone(wheell7))
		("show_wheel" component(wheelleft8) bone(wheell8))
		("show_wheel" component(wheelright1) bone(wheelr1))
		("show_wheel" component(wheelright2) bone(wheelr2))
		("show_wheel" component(wheelright3) bone(wheelr3))
		("show_wheel" component(wheelright4) bone(wheelr4))
		("show_wheel" component(wheelright5) bone(wheelr5))
		("show_wheel" component(wheelright6) bone(wheelr6))
		("show_wheel" component(wheelright7) bone(wheelr7))
		("show_wheel" component(wheelright8) bone(wheelr8))
		("show_wheel" component(wheelfront) bone(wheelfront))		;// kettenkrad
		{if component "engine"
				{ani_play "engine_r" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_r" +1 resume}
			}
			{if component "turret"
				{ani_play "turret_r" +1 resume}
			}
			{if component "body"
				{ani_play "body_r" +1 resume}
			}
	}

	{on "break_wheel_impulse"  ;// Allows to be overridden in certain vehicles
		{if not tagged "impluse"
			{impulse up 0.001}
		}
	}
}

;;============================================== USSR STATIC ===============================================
{"stalinetz60_stand"
	("s60_sound")
}

;=============================================== FIN ============================================================
;=============================================== FIN tanks ======================================================
{"comet tank"
	("valentine_sound")
	{on "add_weapon_sound" overload
		("MAC31")
		("Cannon_75to76mm")
	}
	("repair_anm_script_v1")
}
{"smk_fin tank"
	("t28_sound")
	{on "add_weapon_sound" overload
		("DT")
		("DShK38")
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
;=============================================== USA ============================================================
;=============================================== USA tanks ======================================================
;;============================================== USA tanks light ==============================================
{"US_LVTA1 tank"
	("m3_stuart_sound")
	{on spawn
		{add_view	"shell_mgun"	"mgun_eject1"	"fxshell1"}
		{add_view	"shell_mgun"	"mgun_eject2"	"fxshell2"}
	}
	{on "add_weapon_sound" overload
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
		("M1919A4")
		("Cannon_37to40mm")
	}
	{on fire "mgun2"
		{play_sound "action_recoil_HMG"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "mgun_eject1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
	}
	{on fire "mgun3"
		{play_sound "action_recoil_HMG"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "mgun_eject2"}
		{delay 0.2
			{view pause "mgun_eject2"}
		}
	}
}
{"US_M5A1 tank"
	("m3_stuart_sound")
	{on spawn
		{add_view	"shell_mgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_close" overload
		{ani_play "com_open" -1.0 resume}
		{ani_wind "binocular" begin}
	}	
	{on "commander_hatch_open" overload
		{ani_wind "com_open" end}
		{ani_wind "binocular" end}
	}
	{on "add_weapon_sound" overload
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_37to40mm")
	}
	{on fire "mgun3"
		{play_sound "action_recoil_HMG"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "mgun_eject2"}
		{delay 0.2
			{view pause "mgun_eject2"}
		}
	}
}
{"t7_combat_car tank"
	("m3_stuart_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
	}
	{on fire "mgun"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
	}
	{on spawn
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
}
{"t18_hmc tank"
	("m3_stuart_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
		("Cannon_75to76mm_LV")
	}
	{on spawn
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
}
{"us_t18e2 tank"
	("m8_greyhound_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
		("Cannon_37to40mm")
	}
}
{"us_t55e1 tank"
	("m8_greyhound_sound")
	{on "add_weapon_sound" overload
		("Cannon_Breech")
		("Cannon_37to40mm")
	}
	("repair_anm_script_v1")
}

;;============================================== USA tanks medium =============================================
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
{"US_M4A3E2_CobraKing tank"
	("m4a3_sherman_sound")
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "com_open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "com_open" -1.0 resume}
	}
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_75to76mm_HV")
	}
	{on fire "mgun4"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{view start "mgun_eject2"}
		{delay 0.2
			{view pause "mgun_eject2"}
		}
	}
	{on fire "mgun3"
		{play_sound "action_recoil_HMG"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
	}
}
{"us_m26e1 tank"	
	("m26_pershing_sound")
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_85to100mm_HV")
	}
	{on fire "mgun"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{view start "mgun_eject2"}
		{delay 0.2
			{view pause "mgun_eject2"}
		}
	}
}

;;============================================== USA tanks heavy ==============================================
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

;=============================================== USA btr ========================================================
{"us_t69 tank"
	{on "add_weapon_sound" overload
		("M2HB")
	}

	("multi_barrel_loop" flash(flash_gun_big) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	("m8_greyhound_sound")
}

;=============================================== USA car ========================================================
{"willys_jeep_medical car"
	("willys_mb_sound")
}
{"willys_jeep_shield_rocket car"
	("willys_mb_sound")
}

;=============================================== ENG ============================================================
;=============================================== ENG tanks ======================================================
;=============================================== ENG btr ========================================================

;=============================================== Other ==========================================================
{"tank"  
    {on operatable on
        {if user_control
			{delay 1
				{if tagged "radio_car"
					{call "show_radio_icon"}
				}
			}
            {delay 1.5
                {if tagged "radio_car"
                    {view start "beacon_fx"}
                }
            }
        }
	}
	{on operatable off
        {delay 1
            {if tagged "_abandoned"
                {tags remove "_user_ally"}
            }
        }
        {view stop "beacon_fx"}
    }
}
{"tank"
	{on "die"
		{delay 0.9	
			{if tagged "msg_superheavytank"
				{tags remove "msg_superheavytank"}
			}
			{if tagged "radio_car"
				{tags remove "radio_car"}
			}
		}
	}
}