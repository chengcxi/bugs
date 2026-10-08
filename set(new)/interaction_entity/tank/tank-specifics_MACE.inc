(include "../mace_defines.inc")
;(include "tank-specifics.inc")
;/*===========Command/AA Vehicles TAGS Begin ===========*/
{"sdkfz250a_3 tank"	
	{on spawn ; MACE AIR SCRIPT TAG ADD
		{tags add "command_vehicle_aa"}
	}
}
{"ba20_command"
	{on spawn ; MACE AIR SCRIPT TAG ADD
		{tags add "command_vehicle_aa"}
	}
}		
{"sdkfz251d_1_stuka tank"
	{on spawn
		{tags add "i_see_you"}
	}
}
{"t19_hmc tank"
	{on spawn
		{tags add "i_see_you"}
	}
}
{"m4a3_calliope tank"		
	{on spawn
		{tags add "i_see_you"}
	}
}
{"m7_hmc tank"
	{on spawn
		{tags add "i_see_you"}
	}
}
{"m7b1_hmc tank"
	{on spawn
		{tags add "i_see_you"}
	}
}
{"m12_gmc tank"
	{on spawn
		{tags add "i_see_you"}
	}
}
{"sexton_mk2 tank"
	{on spawn
		{tags add "i_see_you"}
	}
}

;/*=========== Sweden/Finland Vehicles Begin ===========*/

{"ba20_command_fin"
	("ba_sound")
	{on spawn ; MACE AIR SCRIPT TAG ADD
		{tags add "command_vehicle_aa"}
	}
	{on "add_weapon_sound" overload
		("DT")
	}
	{on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}

{"sav_m43_1946 tank"
("pz38_sound")
	{on spawn
		{tags add "i_see_you"}
	}
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
	}
	("repair_anm_script_v1")
}

{"sav_m43_1944 tank"
("pz38_sound")
	{on spawn
		{tags add "i_see_you"}
	}
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
	}
	("repair_anm_script_v1")
}

{"stormpjas_fm_43 tank"
	("t70_sound")
	{on spawn
		{add_view "recoilless_shot" "fire_gun2" "fx_smoke_barrel"}
	}
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on fire "gun" 
        	{view start "fire_gun2"}
		{delay 0.1
			{view pause "fire_gun2"}
		}
    	}
	("repair_anm_script_v1")
}

{"pbil_m40 tank"
	("ba_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Autocannon_s1_Rapid")
		("MG34")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("repair_anm_script_v1")
}

{"lvtdgb_m40 tank"
	("opel_sound")
	{on operatable on
		{if rain
			{delay 10
				{ani_play "windows_up"}
			}
		}
	}
	{on break
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b"}
				{ani_play "fan_spin"}
			}
			{if component "body"
				{ani_play "body_b"}
			}
			{if component "turret"
				{ani_play "turret_b"}
			}
			{if component "gun"
				{ani_play "gun_b"}
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
	{on "engine_on"
		{delay 2.5
			{ani_play "fan_spin" loop}
		}
	}
	{on "engine_off"
		{ani_play "fan_spin"}
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG34")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
}
;/*=========== German Vehicles Begin ===========*/

{"sdkfz234_luchs tank"
	("sdkfz234_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG34")
	}
	{on spawn
		{ani_wind "open" end}
	}
}

{"jagdpanther_ii tank"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("MG42")
	}
	{on fire "gun"
		{ani_play "fire2" 0.6 resume}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz5/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz5/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz5/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz5/full"}
		{link_sound "exhaust"			"vehicle/engine/pz5/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz5"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	("repair_anm_script_jag_ii")
}

{"sherman5c_ger tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/steel/"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open_right" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_right" -1.0 resume}
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

{"wanze tank"
	("sdkfz303_sound")
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
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
	}
}

{"wanze_ammo tank"
	("sdkfz303_sound")
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
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
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1 resume}
			}
		}
	}
}

{"wanze_charge_ammo_radio"
	{on spawn	
		{able minimap 0}
		{if not season "winter"
		else season "winter"
			{tex_mod "winter"}
		else season "spring"
			{tex_mod "camo"}
		else season "autumn"
			{tex_mod "camo"}
		}
	}
	{on fire "explosive"
		{delay 0.1 {spawn "explosion_wanze"} {delete}}
	}
	{on blast							;// blastwave hits specific volume
		{if volume "mine"
			{if min_energy 4
				{spawn "shockwave_sphere"}
				{spawn "crater_massive" "basis" x terrain_texmod}
				{spawn "explosion_wanze" {delete}}	
			else min_energy 12.1 ;//150mm HE
				{if rand 1 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}	
			else min_energy 7.1 ;//105mm HE
				{if rand 0.5 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			else min_energy 3.1 ;//75mm HE
				{if rand 0.5 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			}
		}
		{if volume "body1"
			{if min_energy 4
				{spawn "shockwave_sphere"}
				{spawn "crater_massive" "basis" x terrain_texmod}
				{spawn "explosion_wanze" {delete}}	
			else min_energy 12.1 ;//150mm HE
				{if rand 1 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}	
			else min_energy 7.1 ;//105mm HE
				{if rand 0.5 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			else min_energy 3.1 ;//75mm HE
				{if rand 0.5 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			}
		}
	}
	{on pierce sync
		{if volume "mine"
			{if stuff "auto"
				{if rand 0.5 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			else stuff "shell size1"
				{if rand 0.6 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			else stuff "shell size2"  ;//75mm
				{if rand 0.7 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			else stuff "shell size3"  ;//105mm
				{if rand 0.8 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			else stuff "shell"  ;//150mm and up
				{if rand 1 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			}
		}
		{if volume "body1"
			{if stuff "auto"
				{if rand 0.5 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			else stuff "shell size1"
				{if rand 0.6 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			else stuff "shell size2"  ;//75mm
				{if rand 0.7 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			else stuff "shell size3"  ;//105mm
				{if rand 0.8 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			else stuff "shell"  ;//150mm and up
				{if rand 1 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			}
		}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "ammo"
				{delay 0.1 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
			}
		}
	}
	{on "vehicle_destroyed" overload
		{delay 0.1 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
	}
	{on "explosion"
		{delay 0.1 {delete}}
	}
	{on "crush_damage_tank" overload
		{if effector_velocity 10
			{delay 0.1 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
		}
	}
	{on "detonate_wanze_charge"				;// when vehicle flips over and crew is forced to emit, applies every tick so can't make a proper warning message
		{delay 0.1 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
	}
	;{on "upside_down"				;// when vehicle flips over and crew is forced to emit, applies every tick so can't make a proper warning message
	;	{call "upside_down_script"}
	;}
	;{on "upside_down_script"
	;	{delay 0.1
	;		{tags add "upside_down_charge"}
	;	}
	;	{if not tagged "upside_down_charge"
	;		{damage_report "upside_down_charge" "<c(f3ff00)>Charge is Upside Down and will detonate in 15 seconds!"}	
	;		{delay 15
	;			{delay 0.1 {spawn "explosion_wanze"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
	;		}
	;	}
	;}
}	

{"wanze_demo_radio tank"
	("sdkfz303_sound")
	{on spawn	
		{volumes "mine" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
	}
	{on fire "explosive"
		{weapon_work "explosive" 0}
		(mod "mp"
			{delay 0.5
				{spawn "wanze_charge_ammo_radio" "body1" x 
					{impulse forward 1.5 up -0.5 rnd_dir 0 no_position}
					{gravity 1.0}
				}
			}	
		)
		(mod not "mp"
			{delay 0.5
				{tear "wanze_charge_ammo_radio" bone "body1" copy
					{impulse forward 1.5 up -0.5 rnd_dir 0 no_position}
					{gravity 1.0}
				}
			}
		)
		{delay 0.6
			{bone hide "body1"}
			{volumes "body3" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{volumes "ammo1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
		{components "mine" break}
		{tags add "need_ammo1"}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "ammo"
				{spawn "shockwave_sphere"}
				{spawn "crater_massive" "basis" x terrain_texmod}
				{spawn "explosion_wanze"}
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
		{if component "mine"
			{weapon_work "explosive" 1}
			{bone show "body1"}
			{volumes "body3" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{volumes "ammo1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{tags remove "need_ammo1"}
		}
	}
	{on "pre_cookoff"
		{spawn "explosion_wanze"}
		{spawn "shockwave_sphere"}
		{spawn "crater_massive" "basis" x terrain_texmod}
	}
}
	
{"strumpanzer5g tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("MG34")
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
    	{spawn "crater_massive" "basis" terrain_texmod}
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
        {spawn "crater_massive" "basis" terrain_texmod}
	}
	("repair_anm_script_v1")
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
	}
}

{"daf_39 tank"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("PM1910_30")
	}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
	}
	("repair_anm_script_v1")
}

{"daf_39_com tank"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
	}
	("repair_anm_script_v1")
}

{"pzspwg_204"
	("sdkfz234_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.45 0.35)
	}
	("repair_anm_script_v1")
}

{"vk_3002 tank"
("pz5_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("MG34")
	}
	("repair_anm_script_v1")
}

{"waffletractor tank"
("pz4_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.45 0.35)
	}
	("repair_anm_script_v1")
}

{"Panther_F tank"
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

{"Panther_II_turm tank"
("pz5_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("MG34")
	}
	("repair_anm_script_panther_f")
}

{"Panther_II tank"
("pz5_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("MG34")
	}
	("repair_anm_script_panther_f")
}


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

{"sdkfz_251_9 tank"
	("hanomag_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
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

{"sdkfz221_spzb41 tank"
	("sdkfz222_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
}

{"bergepanther tank"
	("pz5_sound")
	{on spawn
		{add_view	"repair"		"repair"	"hearing_bone"}
		{tags add "ai_engineer_vehicle"}
		{link_sound "screw_twist"		"human/anims/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anims/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anims/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anims/repair/toolbox_close/"}
		{link_sound "tool_equip"		"human/anims/repair/tool_equip/"}
	}
	{on break
		{if not tagged "exploded"
			{if component "trackright"
				{tags add "major_broken1"}
				{tags add "major_broken"}
			else component "trackleft"
				{tags add "major_broken2"}
				{tags add "major_broken"}
			else component "engine"
				{tags add "major_broken3"}
				{tags add "major_broken"}
			}
		}
    }
	{on repair
		{if not tagged "exploded"
			{if component "trackleft"
			 	{tags remove "major_broken2"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken3"
					{tags remove "major_broken"}
				}
			}	
			{if component "trackright"
			 	{tags remove "major_broken1"}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken3"
					{tags remove "major_broken"}
				}
			}
			{if component "engine"
			 	{tags remove "major_broken3"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
			}
		}
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
		{delay 40
			{if operatable
				{if not tagged "major_broken"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{chassis_work 1}
						{call "engine_on"}
					}
				}	
				{if tagged "major_broken1"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}
				}	
				{if tagged "major_broken2"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}
				}	
				{if tagged "major_broken3"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}	
				}
				{if not operatable
					{spawn "recovery_repair_remover_effect" "basis"}
					{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Failed"}
					{view pause "repair"} 
					{chassis_work 1}
					{call "engine_on"}
				}		
			}	
		}	
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
		("Cannon_85to100mm_HV")
		("MG34")
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
        {spawn "crater_massive" "basis" terrain_texmod}
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

{"jagdpanzer_iv_a_armor"
	("pz4_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_75to76mm")
	}
}
{"jagdpanzer_iv_a"
	("pz4_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_75to76mm")
	}
}

{"ezart tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_75to76mm_HV")
	}
	("repair_anm_script_v1")
}


{"sturer_emil"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
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
    ("repair_anm_script_v1")
	{on "reload"
	    {delay 2
            	{ani_play "open_breech" +2 resume}
	    }
	    {delay 4									
			{ani_play "close_breech" +2 resume}
	    }
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}
}

;/*=========== Begin USA Vehicle ===========*/

{"us_t69 tank"
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}

	("multi_barrel_loop" flash(flash_gun_big) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	("m8_greyhound_sound")
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


{"t90_mmc tank"
	("m4_105_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("M2HB")
		("M1919A4")
		("Mortar_5-6cm")
		{link_sound "fire1"				"cannon/s3/d1/Shared/Mortar/"}
		{link_sound "fire2"				"cannon/s3/d1/Shared/Mortar/"}
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on fire "gun"
		{play_sound "fire1"}
		{play_sound "fire2"}
	}
}

{"staghound_howitzer"
	("staghound_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
		("M2HB")
		("M1919A4")
	}
	{on fire "gun"
		{ani_play "recoil"}
	}
}

{"staghound_mk3_prot"
	("staghound_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("ZB37")
	}
}

{"m3_lee_late tank"
	("m3_lee_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm/"}
		("M1919A4")
	}
	{on spawn
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on break_armor					;// volume breaks
		{if volume "aux_turret2"
			{call "kill_commander"}
		}
	}
	{on break_armor_again			;// volume is broken again before related component is repaired
		{if volume "aux_turret2"
			{call "kill_commander"}
		}
	}
	{on break 
		{if component "aux_turret2"
			{weapon_work "mgun3" 0}
		}
	}
	{on repair
		{if component "aux_turret2"
			{weapon_work "mgun3" 1}
		}
	}
	(define "multi_turret_rotate"
		{on ik begin "%0" overload
			{kill_delay "rotate_turret%1"}
			{if not "rotate_turret%1"
				{play_sound "rotate_turret%1" 1}
				{set "rotate_turret%1" 1}
			}
		}
		{on ik end "%0" overload
			{delay 0.25 "rotate_turret%1"
				{stop_sound "rotate_turret%1"}
				{set "rotate_turret%1" 0}
			}
		}
	)
	("multi_turret_rotate" args aux_turret1 1)
	("multi_turret_rotate" args aux_turret2 2)
	("multi_gun_rotate" args gun1_rot)
}

{"m4a1_76w_e4_5 tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
		{add_view "flamer_fire_tank" "flamer1" "foresight4"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on "charger_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	("flame_weapon" args flamer1 40 4 40)
	
}

{"m4a3_75w_poa_h1 tank"
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{add_view "flamer_fire" "gun" "foresight1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 80 1 40)
	
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}

{"m4a3e2_105"
	("m4a3_105_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}

{"US_M19 tank"
	("m24_chaffee_sound")
    {on "add_weapon_sound" overload
		("Cannon_37to40mm")
    }
    {on spawn
	{add_view "tank_fire_minimum_dust_ground"		"minimum_ground_fx"		"basis"}
   	{add_view "tank_fire_minimum_dust_sand"		"minimum_sand_fx"		"basis"}
   	{add_view "tank_fire_minimum_dust_snow"		"minimum_snow_fx"		"basis"}
	{add_view	"tank_canon_fire_37_40_auto"	"flashbarrel00"	"shooter00"}
	{add_view	"tank_canon_fire_37_40_auto"	"flashbarrel01"	"shooter01"}
	{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
    }
    {on fire "gun" overload
		{call "minimum_terrain_fx"}
		{if  name "00"
				{view start "flashbarrel00"}
				{ani_play "fire00" 1.0 resume}
				{delay 0.2
					{view pause "flashbarrel00"}
				}
			else name "01"
				{view start "flashbarrel01"}
				{ani_play "fire01" 1.0 resume}
				{delay 0.2
					{view pause "flashbarrel01"}
				}
		}
    }	
}

{"us_m3_recovery tank"
	("m3_lee_sound")
	{on "commander_hatch_open" overload
		{ani_wind "com_open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "com_open" -1.0 resume}
	}
	{on spawn
		{add_view	"repair"		"repair"	"hearing_bone"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
		{tags add "ai_engineer_vehicle"}
		{link_sound "screw_twist"		"human/anims/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anims/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anims/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anims/repair/toolbox_close/"}
		{link_sound "tool_equip"		"human/anims/repair/tool_equip/"}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1}
			}
			{if component "turret"
				{ani_play "turret_b" +1}
			}
			{if component "body"
				{ani_play "body_b" +1}
			}
		}
	}	
	{on repair
		{if not tagged "exploded"
			{if component "trackleft"
			 	{tags remove "major_broken2"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken3"
					{tags remove "major_broken"}
				}
			}	
			{if component "trackright"
			 	{tags remove "major_broken1"}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken3"
					{tags remove "major_broken"}
				}
			}
			{if component "engine"
			 	{tags remove "major_broken3"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
				{ani_play "engine_r" +1}
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
		}
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
		{delay 40
			{if operatable
				{if not tagged "major_broken"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{chassis_work 1}
						{call "engine_on"}
					}
				}	
				{if tagged "major_broken1"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}
				}	
				{if tagged "major_broken2"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}
				}	
				{if tagged "major_broken3"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}	
				}
				{if not operatable
					{spawn "recovery_repair_remover_effect" "basis"}
					{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Failed"}
					{view pause "repair"} 
					{chassis_work 1}
					{call "engine_on"}
				}		
			}	
		}	
	}
}

{"US_M4_improved tank"
	("m4_sherman_sound")
	{on spawn
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
		("Cannon_75to76mm")
	}
	{on fire "mgun"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
	}
}

{"US_m4a3e8_FURY tank"
	("m4a3_sherman_sound")
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell2"}
		{add_view	"shell_mgun"	"mgun_eject1"	"fxshell1"}
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
			
		{ani_wind "com_open" end}
		{ani_wind "binocular" end}
	}
	{on "commander_hatch_close" overload
		
		{ani_wind "open_commander" end}
		{ani_wind "binocular" begin}
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
		{view start "mgun_eject1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
	}
}

{"us_m4a3e8_thundervii tank"
	("m4a3_sherman_sound")
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell2"}
		{add_view	"shell_mgun"	"mgun_eject1"	"fxshell1"}
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	;{on "commander_hatch_open" overload
	;	{ani_wind "open" end}
	;	{ani_play "mgun_aa" +1.0 resume}
	;	{ani_wind "binocular" end}
	;}
	;{on "commander_hatch_close" overload
	;	{ani_play "open" -1.0 resume}
	;	{ani_wind "binocular" begin}
	;}
	{on "charger_hatch_open" overload
		{ani_wind "gunner_outside" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "gunner_outside" -1.0 resume}
		
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
		{view start "mgun_eject1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
	}
}

{"m4_90 tank"
	("m4_105_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("M2HB")
		("M1919A4")
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
}

{"us_m4a3r3_zippo tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
		{add_view "flamer_fire_tank" "flamer1" "foresight4"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 4 40)
}

{"t9e2_mmc tank"
	("m22_locust_sound")
	{on "add_weapon_sound" overload
		("Mortar_8cm")
		("M1919A4")
	}
}

{"us_m10a1 tank"
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

{"us_m18_90 tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 8)		;// weapon reload time
	}
}

{"us_m18_blackcat tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
}

{"us_m36b2 tank"
	("m4a3_sherman_sound")
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on fire "mgun1"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{view start "mgun_eject2"}
		{delay 0.2
			{view pause "mgun_eject2"}
		}
	}
	{on fire "gun"
		{delay 0.5
			{ani_play "open_eject_shell" +1}
		}
	}
}


{"m26_t99_pershing tank"
	("m26_pershing_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("M1919A4")
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
		{tags add "i_see_you"}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	("rocket_weapon" args rocket)		;// defines weapon place that is disabled while vehicle is on move
}

{"m26_pershing_concrete tank"
	("m26_pershing_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("M1919A4")
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"m26e1_pershing tank"
	("m26_pershing_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("M1919A4")
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"m2_medium tank"
	("m3_stuart_sound")
    {on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("M1919A4")
    }
    {on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel_big1"	"foresight8"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel_big2"	"foresight9"}
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
    }
    {on fire "mgun6" overload
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
		{ani_play "mgun1_fire" 1}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "flashbarrel_big1"}
		{delay 0.2
			{view pause "flashbarrel_big1"}
		}
	}
	{on fire "mgun5" overload
		{ani_play "mgun1_fire" 1}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "flashbarrel_big2"}
		{delay 0.2
			{view pause "flashbarrel_big2"}
		}
	}
	("repair_anm_script_v1")
}

{"m2a1_medium tank"
	("m3_stuart_sound")
    {on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("M1919A4")
    }
    {on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel_big1"	"foresight8"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel_big2"	"foresight9"}
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
    }
    {on fire "mgun6" overload
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
		{ani_play "mgun1_fire" 1}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "flashbarrel_big1"}
		{delay 0.2
			{view pause "flashbarrel_big1"}
		}
	}
	{on fire "mgun5" overload
		{ani_play "mgun1_fire" 1}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "flashbarrel_big2"}
		{delay 0.2
			{view pause "flashbarrel_big2"}
		}
	}
	("repair_anm_script_v1")
}

{"m2e1_medium_flamm tank"
	("m3_stuart_sound")
    {on "add_weapon_sound" overload
		("M1919A4")
    }
    {on spawn
		{link_sound "flame1"						"fire/metal"}
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel_big1"	"foresight8"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel_big2"	"foresight9"}
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
		{add_view "flamer_fire_tank" "gun" "foresight1"}
    }
    {on fire "mgun6" overload
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
		{ani_play "mgun1_fire" 1}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "flashbarrel_big1"}
		{delay 0.2
			{view pause "flashbarrel_big1"}
		}
	}
	{on fire "mgun5" overload
		{ani_play "mgun1_fire" 1}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{view start "flashbarrel_big2"}
		{delay 0.2
			{view pause "flashbarrel_big2"}
		}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 60 1 40)
	("repair_anm_script_v1")
}


{"m5_stuart tank"
	("m5a1_stuart_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("M1919A4")
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m5_stuart_auto tank"
	("m5a1_stuart_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("M1919A4")
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}

{"m4a3_firefly tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
		("Cannon_75to76mm_HV")
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on fire "gun"  
		{ani_play "fire2"}
	}
}

{"t26e4_prod tank"
	("m26_pershing_sound")
	{on spawn
		{tex_mod ""}
	}
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("M1919A4")
		("M2HB")
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"m18_hellcat_105mm tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
	{on fire "gun"  
		{ani_play "recoil" +0.7}
	}
	("repair_anm_script_v1")
}

{"t77_spaa tank"
	("m24_chaffee_sound")
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}
	("repair_anm_script_v1")
	("multi_barrel_loop" flash(flash_gun_big) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(gun) head(0.070))
}

{"m4a1_t40"
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
		{tags add "i_see_you"}
	}
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("M1919A4")
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
			{if component "gun1"
				{ani_play "gun2_b" +1 resume}
				{call_synced "gun1"}
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
		{if component "gun1"
			{if work "gun1"
				{ani_play "gun2_r" +1 resume}
				{call_synced "gun1"}
                        }
		}
	}
	{on operatable off
		{delay 2
			{ani_play "close_launcher" +1.0 }
		}
	}
	{on operatable on
		{delay 2
			{ani_play "close_launcher" -1.0 }
		}
	}
	("rocket_weapon" args rocket)		;// defines weapon place that is disabled while vehicle is on move
}

{"m4a1_m17"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("M1919A4")
	}
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
		{tags add "i_see_you"}
	}
	("m4a3_sherman_sound")
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
			{if component "gun1"
				{call_synced "gun1"}
				{ani_play "gun2_v2_b" +1 resume}
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
		{if component "gun1"
			{if work "gun1"
				{call_synced "gun1"}
				{ani_play "gun2_v2_r" +1 resume}
                        }
		}
	}
	("rocket_weapon" args rocket)		;// defines weapon place that is disabled while vehicle is on move
}


{"us_m6a2e1 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("M1919A4")
	}
	{on spawn
		{if rand 0.5
			{bone show "flag"}
			{bone hide "mgun_extra"}
		else
			{bone hide "flag"}
			{bone show "mgun_extra"}
		}
	}
	("repair_anm_script_v1")
	{on "cut_parts"
		("cut_part" args "shield1" 1)
		("cut_part" args "shield2" 1)
	}
}

{"t_14 tank"
	("m4a2_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_50to57mm_HV")
	}
	{on spawn
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
		{add_view	"shell_hmgun"	"mgun_eject1"	"mgun_shell_eject"}
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
			{if component "shieldl10"
            				{tear "piece_medium_steel" bone "shieldl10"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl11"
            				{tear "piece_medium_steel" bone "shieldl11"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldr10"
            				{tear "piece_medium_steel" bone "shieldr10"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldr11"
            				{tear "piece_medium_steel" bone "shieldr11"
                			{impulse up 1.5 rnd_dir 2}
            			}
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
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
		{ani_play "open_mgun" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
		{ani_play "open_mgun" -1.0 resume}
	}
	{on fire "mgun3"
		{ani_play "fire_mgun" +1.5}
		{view start "mgun_eject1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
    	}	
}

{"t_14_uk tank"
	("m4a2_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_75to76mm")
	}
	{on spawn
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
		{add_view	"shell_hmgun"	"mgun_eject1"	"mgun_shell_eject"}
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
			{if component "shieldl10"
            				{tear "piece_medium_steel" bone "shieldl10"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl11"
            				{tear "piece_medium_steel" bone "shieldl11"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldr10"
            				{tear "piece_medium_steel" bone "shieldr10"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldr11"
            				{tear "piece_medium_steel" bone "shieldr11"
                			{impulse up 1.5 rnd_dir 2}
            			}
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
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
		{ani_play "open_mgun" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
		{ani_play "open_mgun" -1.0 resume}
	}
	{on fire "mgun3"
		{ani_play "fire_mgun" +1.5}
		{view start "mgun_eject1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
    	}	
}


{"m4a4_croc tank"
	("m4a4_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/steel/"}
		{add_view "flamer_fire_tank"	"flamer1"	"foresight3"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	("flame_weapon_1x_shot" args flamer1 80 3 45)
}
{"m4a3_105_hvss_h5 tank"
	("m4a3_105_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{add_view "flamer_fire" "flamer1" "foresight3"}
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 1 40)
	
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"m3a1_halftrack tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}
{"t21e1_mortar_carrier tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")

	{on "add_weapon_sound" overload
		("Mortar_12cm")
		("M2HB")
	}
}

{"us_t30 tank"
	("m26_pershing_sound")
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_105to130mm")
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

{"m3a1_halftrack_commander tank"
	("m3_halftrack_sound")
	{on spawn ; MACE AIR SCRIPT TAG ADD
		{tags add "command_vehicle_aa"}
	}
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}

{"m5a1_halftrack_commander tank"
	{on spawn ; MACE AIR SCRIPT TAG ADD
		{tags add "command_vehicle_aa"}
	}
}

{"us_t34 tank"
	("m26_pershing_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_105to130mm")
	}
	{on spawn
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "shooter00"}
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
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
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	
}


{"m4a3_76w_hvss_x2coax tank"
    ("m4a3_sherman_sound")
    {on "add_weapon_sound" overload
        ("Cannon_75to76mm_HV")
        ("M2HB")
        ("M1919A4")
    }
    {on spawn
        ("rand_cut_else" args "bench1" "bench2")
        {link_sound "move"                "vehicle/tracks/M4_Sherman/Steel/"}
    }
    {on "gunner2_hatch_open" overload}
    {on "gunner2_hatch_close" overload}
}

{"m4_t40"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
		{tags add "i_see_you"}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "gun1"
				{ani_play "gun2_b" +1 resume}
				{call_synced "gun1"}
			}
		}
	}
	{on repair
		{if component "gun1"
			{if work "gun1"
				{ani_play "gun2_r" +1 resume}
				{call_synced "gun1"}
            }
		}
	}
	{on move off
		{delay 2
			{ani_play "close_launcher" -1.0 }
		}
	}
	{on move on
		{delay 2
			{ani_play "close_launcher" +1.0 }
		}
	}
	("rocket_weapon" args rocket)		;// defines weapon place that is disabled while vehicle is on move
}

{"m6_mac"
	("staghound_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("M1919A4")
	}
}

{"us_t29 tank"
	("m26_pershing_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_105to130mm")
	}
	{on spawn
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "shooter00"}
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
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
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	{on fire "mgun1"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"} 
     	{view start "fire_gun2"}
		{delay 0.5
			{view pause "fire_gun2"}
		}
    }
}

{"us_t32e1 tank"
	("m26_pershing_sound")
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject2"	"fxshell"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_105to130mm")
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

{"us_m8a1 tank"
	("m3_stuart_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
}


{"t92_hmc tank"
	("m4_sherman_sound")
	{on fire "gun"
		{ani_play "breech_open" 1.0 resume}
		{delay 80
			{ani_play "breech_close" 1.0 resume}
		}
	}
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
		{ani_wind "support_open" end}
		{tags add "i_see_you"}
	}
	{on engine on
		{kill_delay "move_off"}
		{ani_play "weight_back_open" -1.0 resume}
	}
	{on engine off
		{delay 1 "move_off"
			{ani_play "weight_back_open" 1.0 resume}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}
	("repair_anm_script_v1")
}

{"t93_hmc tank"
	("m4_sherman_sound")
	{on fire "gun"
		{ani_play "breech_open" 1.0 resume}
		{delay 80
			{ani_play "breech_close" 1.0 resume}
		}
	}
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
		{ani_wind "support_open" end}
		{tags add "i_see_you"}
	}
	{on engine on
		{kill_delay "move_off"}
		{ani_play "weight_back_open" -1.0 resume}
	}
	{on engine off
		{delay 1 "move_off"
			{ani_play "weight_back_open" 1.0 resume}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}
	("repair_anm_script_v1")
}


{"US_LVTA4 tank"
	("m3_stuart_sound")
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject1"	"fxshell"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on fire "mgun1"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{view start "mgun_eject1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
	}
}

{"us_lvtm24 tank"
	("m3_stuart_sound")
	{on spawn
		{add_view	"shell_hmgun"	"mgun_eject1"	"fxshell"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on fire "mgun1"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{view start "mgun_eject1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
	}
}

{"tiz_am600"
	("r12_sound")
	{on spawn
		{volumes "wheelleft1" disable contact bullet blast}
	}	
	("repair_anm_script_v1")
}

{"US_M2a2 tank"
	("m3_stuart_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
		("Cannon_37to40mm")
	}
	{on fire "mgun3"
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
	}	
}

{"us_m6a1 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("Cannon_75to76mm")
		{link_sound		"action_recoil_Cannon2"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound		"Cannon_Mid2"		"weapon/shot/cannon/s1/d2/Shared/Cannon_37to40mm/"}
		{link_sound		"Cannon_Far2"		"weapon/shot/cannon/s1/d3/Shared/Cannon_37to40mm/"}
	}
	{on fire "gun2"
		{play_sound "action_recoil_Cannon2"}
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"}
	}
	{on spawn
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight3"}
		{add_view "flash_gun_hmg_m2hb" "fire_gun3" "foresight4"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "close_commander" +1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on fire "mgun1" overload
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
        {view start "fire_gun2"}
		{delay 0.2
			{view pause "fire_gun2"}
		}
    }
	{on fire "mgun2"
		{play_sound "action_recoil_HMG"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
        {view start "fire_gun3"}
		{delay 0.2
			{view pause "fire_gun3"}
		}
    }
	("repair_anm_script_v1")
}

;/*=========== Ussr Vehicles Begin ===========*/

{"is4m tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("DT")
		("DShK38")
		("Cannon_105to130mm")
	}
	{on fire "mgun"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
	}
	{on "commander_hatch_open" overload
		{ani_play "open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	{on "engine_on" 			;// settings for engine when switched on
		{if work "body"
			{if work "engine"
				{ani_play "fen" loop}
			}
		}
	}
	{on "engine_off"
		{delay 1
			{ani_play "Fen"}
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
{"kv4b tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_105to130mm")
		{link_sound		"action_recoil_Cannon2"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound		"Cannon_Mid2"		"weapon/shot/cannon/s2/d2/Shared/Cannon_45to47mm/"}
		{link_sound		"Cannon_Far2"		"weapon/shot/cannon/s2/d3/Shared/Cannon_45to47mm/"}
	}
	{on spawn
		{add_view "tank_canon_fire_37_47"			"flashbarrelminimum_b"	"Foresight2"}
		{add_view "tank_fire_minimum_dust_ground"	"minimum_ground_fx"		"basis"}
		{add_view "tank_fire_minimum_dust_sand"		"minimum_sand_fx"		"basis"}
		{add_view "tank_fire_minimum_dust_snow"		"minimum_snow_fx"		"basis"}
		{link_sound "bkg_cannon_small" "weapon/shot/bkg/cannon/small/"}
	}
	{on fire "gun2"
		{play_sound "bkg_cannon_medium"}
		{view start "flashbarrelmedium_b"}
		{call "medium_terrain_fx"}
	}
}

{"t50e tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_45to47mm")
	}
}
{"t70_45 tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_75to76mm")
	}
}
{"t29 tank"
	("t28_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_75to76mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s2/d2/Shared/Cannon_45to47mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s2/d3/Shared/Cannon_45to47mm/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret2"
				{call "kill_gunner3"}
			else component "aux_turret1"
				{call "kill_charger2"}
			}
		}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun1" 1}
		else
			{weapon_work "mgun1" 0}
		}
		{if work "aux_turret2"
			{weapon_work "mgun2" 1}
		else
			{weapon_work "mgun2" 0}
		}
		{inherited}
	}
}
{"t28_40 tank"
	("t28_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_75to76mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s2/d2/Shared/Cannon_45to47mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s2/d3/Shared/Cannon_45to47mm/"}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret2"
				{call "kill_gunner3"}
			else component "aux_turret1"
				{call "kill_charger2"}
			}
		}
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
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun1" 1}
		else
			{weapon_work "mgun1" 0}
		}
		{if work "aux_turret2"
			{weapon_work "mgun2" 1}
		else
			{weapon_work "mgun2" 0}
		}
		{inherited}
	}
}
{"t28_85 tank"
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_50to57mm_HV")
	}
	("t28_sound")
	{on break
		{if not tagged "exploded"
			{if component "aux_turret2"
				{call "kill_gunner3"}
			else component "aux_turret1"
				{call "kill_charger2"}
			}
		}
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
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun1" 1}
		else
			{weapon_work "mgun1" 0}
		}
		{if work "aux_turret2"
			{weapon_work "mgun2" 1}
		else
			{weapon_work "mgun2" 0}
		}
		{inherited}
	}
}
{"t5 tank"
	("pz5_sound")
}
{"su14_2 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_150to210mm")
	}
	{on spawn
		{tags add "i_see_you"}
	}
}

{"is_6 tank"
	{on "add_weapon_sound" overload
		("DT")
		("DShK38")
		("Cannon_105to130mm")
	}
	{on fire "mgun"
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
	}
	{on spawn
   		{add_view "aircraft_damage_small"	"fire_smoke"	"smoke_fx"}
	}
	{on fire "gun"
		{view start "fire_smoke"}
		{delay 1
			{view pause "fire_smoke"}
		}
	}
	("is_sound")
	{on "commander_hatch_open" overload
		{ani_play "open_charger" -1.0}
	}
	{on "commander_hatch_close" overload
		{ani_play "close_charger" +1.0 resume}
	}
	{on "engine_on" 			;// settings for engine when switched on
		{if work "body"
			{if work "engine"
				{delay 1
					{ani_play "fan_spin" loop}
				}
			}
		}
	}
	{on "engine_off"
		{delay 1
			{ani_play "fan_spin"}
		}
	}
	("repair_anm_script_v1")
}

{"is_7 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("RP_46")
		("KPVT")
		("KPVT_AA")
		("Cannon_105to130mm")
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

{"kv2_zis6 tank"
	("kv_sound")
	{on spawn
		{link_sound "pizza_time_music"		"vehicle/pizza_time_320_kbps_mp3"}
	}
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
		("Autocannon_s1_Rapid")
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

{"kv_220 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DT")
	}
	("repair_anm_script_v1") 
}

{"kv220 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("DT")
	}
}

{"is_4m tank"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("DT")
		("DShK38")
	}
	("is_sound")
	{on "engine_on"
		{ani_play "fan_spin" loop}
	}
	{on "engine_off"
		{ani_play "fan_spin"}
	}
	{on "commander_hatch_open" overload
		{ani_play "open_gunner_ring" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_gunner_ring" -1.0 resume}
	}
	{on fire "flamer1"
		{volumes "smoke1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "holding_barrel1"}
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel1_is3" bone "smoke_barrel1" copy
				{impulse forward -0.1 }
			}
		}
		{components "barrel1_ammo" break}
		{tags add "need_ammo1"}
		{delay 0.6
			{bone hide "smoke_barrel1"}
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		}
		{call_synced "flamer1"}
		{if not "flamer1"
			{call_synced "flamer1"}
		}
	}
	{on fire "flamer2"
		{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "holding_barrel2"}
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel2_is3" bone "smoke_barrel2" copy
				{impulse forward -0.1 }
			}
		}
		{components "barrel2_ammo" break}
		{tags add "need_ammo2"}
		{delay 0.6
			{bone hide "smoke_barrel2"}
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		}
		{call_synced "flamer2"}
		{if not "flamer2"
			{call_synced "flamer2"}
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
		{if not "flamer1"
			{call_synced "flamer1"}
		}
		{if not "flamer2"
			{call_synced "flamer2"}
		}
		{if component "barrel1_ammo"
			{bone show "smoke_barrel1"}
			{bone show "holding_barrel1"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
		{if component "barrel2_ammo"
			{bone show "smoke_barrel2"}
			{bone show "holding_barrel2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
		{if component "smoke1"
			{bone show "smoke_barrel1"}
			{bone show "holding_barrel1"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
		{if component "smoke2"
			{bone show "smoke_barrel2"}
			{bone show "holding_barrel2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
	}
	{on break
	{if component "smoke1"
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
			{tags add "need_ammo1"}
			{spawn "ex_sm_size2" "fx_smoke1"}
			{volumes "smoke1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{bone hide "smoke_barrel1"}
			{bone hide "holding_barrel1"}
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
			{bone hide "smoke_barrel2"}
			{bone hide "holding_barrel2"}
			{call_synced "flamer2"}
			{if not "smoke1"
				{call_synced "smoke1"}
			}
    	}
	{if component "engine"
		{tags add "engine_brake"}
		{ani_play "engine_b" +1 resume}
	}
	{if component "body"
                {ani_play "body_b" +1 resume}
        }
    }
    {on "reload"
	{if tagged "need_ammo"
		{tags remove "need_ammo"}
		{able repaired 1}
	}
    }
}

{"is_4 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("DShK38")
	}
	{on "engine_on"
		{ani_play "fan_spin" loop}
	}
	{on "engine_off"
		{ani_play "fan_spin"}
	}
	{on fire "flamer1"
		{volumes "smoke1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "holding_barrel1"}
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel1_is3" bone "smoke_barrel1" copy
				{impulse forward -0.1 }
			}
		}
		{components "barrel1_ammo" break}
		{tags add "need_ammo1"}
		{delay 0.6
			{bone hide "smoke_barrel1"}
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		}
		{if not "flamer1"
			{call_synced "flamer1"}
		}
		{call_synced "flamer1"}
	}
	{on fire "flamer2"
		{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "holding_barrel2"}
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel2_is3" bone "smoke_barrel2" copy
				{impulse forward -0.1 }
			}
		}
		{components "barrel2_ammo" break}
		{tags add "need_ammo2"}
		{delay 0.6
			{bone hide "smoke_barrel2"}
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		}
		{if not "flamer2"
			{call_synced "flamer2"}
		}
		{call_synced "flamer2"}
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
			{bone show "smoke_barrel1"}
			{bone show "holding_barrel1"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
		{if component "barrel2_ammo"
			{bone show "smoke_barrel2"}
			{bone show "holding_barrel2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
		{if component "smoke1"
			{bone show "smoke_barrel1"}
			{bone show "holding_barrel1"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
		{if component "smoke2"
			{bone show "smoke_barrel2"}
			{bone show "holding_barrel2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
	}
	{on break
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
			{bone hide "smoke_barrel1"}
			{bone hide "holding_barrel1"}
			{if not "smoke1"
				{call_synced "smoke1"}
			}
			{call_synced "smoke1"}
    	}
		{if component "smoke2"
		{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
	    	{tags add "need_ammo2"}
	    	{spawn "ex_sm_size2" "fx_smoke2"}
	    	{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "smoke_barrel2"}
		{bone hide "holding_barrel2"}
		{if not "smoke2"
			{call_synced "smoke2"}
		}
			{call_synced "smoke2"}
    		}
	{if component "engine"
		{tags add "engine_brake"}
		{ani_play "engine_b" +1 resume}
	}
	{if component "body"
                {ani_play "body_b" +1 resume}
        }
    }
}

{"t44 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DT")
	}
}

{"t44a tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DT")
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
{"matilda_f96 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("DT")
	}
    ("repair_anm_script_v1")
}

{"zut_37 tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
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
    ("repair_anm_script_v1")
}

{"is_3 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("DT")
		("DShK38")
	}
	{on fire "flamer1"
		{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel1_is3" bone "smoke_barrel1" copy
				{impulse forward 2 }
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
		{volumes "smoke1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel2_is3" bone "smoke_barrel2" copy
				{impulse forward 2 }
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
	{on "commander_hatch_open" overload
		{ani_play "gunner_open" +1.0 resume}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "gunner_open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
    {on break
	{if not "flamer1"
		{call_synced "flamer1"}
	}
	{if not "flamer2"
		{call_synced "flamer2"}
	}
        {if component "shieldl14"
            {tear "piece_medium_steel" bone "shieldl14"
                {impulse up 1.5 rnd_dir 2}
            }
        }

		{if component "shieldl13"
            {tear "piece_medium_steel" bone "shieldl13"
                {impulse up 1.5 rnd_dir 2}
            }
        }
         {if component "shieldl16"
            {tear "piece_medium_steel" bone "shieldl16"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldr10"
            {tear "piece_medium_steel" bone "shieldr10"
                {impulse up 1.5 rnd_dir 2}
            }
        }
         {if component "shieldr12"
            {tear "piece_medium_steel" bone "shieldr12"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldr14"
            {tear "piece_medium_steel" bone "shieldr14"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldr15"
            {tear "piece_medium_steel" bone "shieldr15"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldl10"
            {tear "piece_medium_steel" bone "shieldl10"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldr11"
            {tear "piece_medium_steel" bone "shieldr11"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldl11"
            {tear "piece_medium_steel" bone "shieldl11"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldl12"
            {tear "piece_medium_steel" bone "shieldl12"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldr13"
            {tear "piece_medium_steel" bone "shieldr13"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldl15"
            {tear "piece_medium_steel" bone "shieldl15"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldl16"
            {tear "piece_medium_steel" bone "shieldl16"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldr16"
            {tear "piece_medium_steel" bone "shieldr16"
                {impulse up 1.5 rnd_dir 2}
            }
        }
                {if component "shieldr0"
            {tear "piece_medium_steel" bone "shieldr0"
                {impulse up 1.5 rnd_dir 2}
            }
        }
         {if component "shieldl0"
            {tear "piece_medium_steel" bone "shieldl0"
                {impulse up 1.5 rnd_dir 2}
            }
        }
		{if component "smoke1"
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
			{tags add "need_ammo2"}
			{spawn "ex_sm_size2" "fx_smoke2"}
			{volumes "smoke1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{bone hide "smoke_barrel2"}
			{call_synced "smoke1"}
			{if not "smoke1"
				{call_synced "smoke1"}
			}
    	}
		{if component "smoke2"
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
	    	{tags add "need_ammo1"}
	    	{spawn "ex_sm_size2" "fx_smoke1"}
	    	{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{bone hide "smoke_barrel1"}
		{call_synced "smoke2"}
		{if not "smoke2"
			{call_synced "smoke2"}
		}
    	}
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
		{if component "barrel1_ammo"
			{bone show "smoke_barrel1"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "barrel1_ammo"}
		}
		{if component "barrel2_ammo"
			{bone show "smoke_barrel2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "barrel2_ammo"}
		}
		{if component "smoke2"
			{bone show "smoke_barrel1"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "smoke2"}
		}
		{if component "smoke1"
			{bone show "smoke_barrel2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call_synced "smoke1"}
		}
        {if component "engine"
            {if work "engine"
                {ani_play "engine_r" +1 resume}
            }
		 {if component "engine"	
            	{if work "gun"
                	{ani_play "gun_r" +1 resume}
				}
		}
		 {if component "engine"		
                {if work "body"
                	{ani_play "body_r" +1 resume}
                }
		 {if component "engine"	
                {if work "turret"
                	{ani_play "turret_r" +1 resume}
				}
            }
        }
	}
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

{"rbt_5 tank"
	("bt_sound")
	("tag_ai_arty_mace")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		;("DT")
	}
	{on fire "rocket"
		{volumes "rocket01" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{volumes "rocket00" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
     	}
	{on "reload"
		{if name "rocket01"
			{delay 125									;// Delay set to match reload time of main weapon
				{volumes "rocket01" enable bullet blast}
			}
		}
		{if name "rocket00"
			{delay 125									;// Delay set to match reload time of main weapon
				{volumes "rocket00" enable bullet blast}
			}
		}
	}
	{on break			;// volume breaks
		{if not tagged "exploded"
			{if component "turret"
				{weapon_work "rocket" 0}
				{ani_play "turret_b" +0.70 resume}
			}
			{if component "rocket01"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
			{if component "rocket00"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
			{if component "engine"
				{ani_play "engine_b" +0.70 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +0.70 resume}
			}
			{if component "body"
				{ani_play "body_b" +0.70 resume}
			}	
		}
	}
	{on "explosion_extra"
		{blastwave c4 12 r0 4 r1 20 offset 0 0 25}
		{blastwave c4 1.3 r0 15 r1 25 offset 0 0 25}
		{spawn "tank_die_heavy" "basis"}
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
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1 resume}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
		}
	}
}

{"T_V tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_75to76mm_HV")
	}
	{on "commander_hatch_open" overload
		{ani_play "open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}	
}

{"T_V_85 tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_85to100mm")
	}
	{on "commander_hatch_open" overload
		{ani_play "open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}	
}

{"smk_dshk tank"
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

{"t_vi_100_ussr"
	("pz6_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_85to100mm")
	}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
	}
	{on "smine_decoy"
		("smine_shot" args "mine_s_tank" smine_shot1 -17 0.5 0 25)
		("smine_shot" args "mine_s_tank" smine_shot4 -17 0.5 0.1 25)
		("smine_shot" args "mine_s_tank" smine_shot2 -17 0.5 0.2 25)
		("smine_shot" args "mine_s_tank" smine_shot5 -17 0.5 0.3 25)
		("smine_shot" args "mine_s_tank" smine_shot3 -17 0.5 0.4 25)
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
			{if component "shieldl8"
            			{tear "piece_medium_steel" bone "shieldl8"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl9"
            			{tear "piece_medium_steel" bone "shieldl9"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl10"
            			{tear "piece_medium_steel" bone "shieldl10"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl11"
            			{tear "piece_medium_steel" bone "shieldl11"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl12"
            			{tear "piece_medium_steel" bone "shieldl12"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldr8"
            			{tear "piece_medium_steel" bone "shieldr8"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl9"
            			{tear "piece_medium_steel" bone "shieldr9"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldr10"
            			{tear "piece_medium_steel" bone "shieldr10"
                			{impulse up 1.5 rnd_dir 2}
            			}
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

{"t_vi_100 tank"
	("pz6_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_85to100mm")
	}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
	}
	{on "smine_decoy"
		("smine_shot" args "mine_s_tank" smine_shot1 -17 0.5 0 25)
		("smine_shot" args "mine_s_tank" smine_shot4 -17 0.5 0.1 25)
		("smine_shot" args "mine_s_tank" smine_shot2 -17 0.5 0.2 25)
		("smine_shot" args "mine_s_tank" smine_shot5 -17 0.5 0.3 25)
		("smine_shot" args "mine_s_tank" smine_shot3 -17 0.5 0.4 25)
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
			{if component "shieldl8"
            			{tear "piece_medium_steel" bone "shieldl8"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl9"
            			{tear "piece_medium_steel" bone "shieldl9"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl10"
            			{tear "piece_medium_steel" bone "shieldl10"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl11"
            			{tear "piece_medium_steel" bone "shieldl11"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl12"
            			{tear "piece_medium_steel" bone "shieldl12"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldr8"
            			{tear "piece_medium_steel" bone "shieldr8"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldl9"
            			{tear "piece_medium_steel" bone "shieldr9"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shieldr10"
            			{tear "piece_medium_steel" bone "shieldr10"
                			{impulse up 1.5 rnd_dir 2}
            			}
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

{"ksp_76 tank"
("zis5_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	("repair_anm_script_v1")
}

{"ISU_152_2"
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
	("repair_anm_script_v1")
}

{"t3476_41_stz tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_75to76mm")
	}
	{on "cut_parts" overload
		("cut_part" args "part8" 1)
		("cut_part" args "part15" 1)
		{inherited}
	}
}

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

{"t_26e tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_45to47mm")
	}
	("repair_anm_script_v1")
}

;/*=========== Japanese Vehicles Begin ===========*/

{"ta_se tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s2")
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
		{call_synced "turret"}
	}
	{on ik end "turret" overload
		{delay 0.25 "rotate_turret"
			{stop_sound "rotate_turret"}
			{set "rotate_turret" 0}
			{ani_stop "aim_h"}
		}
		{call_synced "turret"}
	}
	{on "reload"
		{tear "piece_small_steel" bone "magazine" copy
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse dir 2 fz -5 fx 5.5 }
		}
		{delay 0.1
			{bone hide "magazine"}
		}
		{delay 2.5
			{bone show "magazine"}
			{volumes enable bullet blast}				;// prevent destroing at spawn moment
		}
	}
	("repair_anm_script_v1")
}

{"ke_ni"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"so_ki tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s2")
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
	{on "reload"
		{tear "piece_small_steel" bone "magazine1" copy
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse dir 2 fz -5 fx 5.5 }
		}
		{delay 0.1
			{bone hide "magazine1"}
		}
		{delay 4.5
			{bone show "magazine1"}
			{volumes enable bullet blast}				;// prevent destroing at spawn moment
		}
		{delay 1.0
			{tear "piece_small_steel" bone "magazine2" copy
				{volumes disable bullet blast}				;// prevent destroing at spawn moment
				{impulse dir 2 fz -5 fx 5.5 }
			}
		}
		{delay 1.1
			{bone hide "magazine2"}
		}
		{delay 4.5
			{bone show "magazine2"}
			{volumes enable bullet blast}				;// prevent destroing at spawn moment
		}
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
}

{"ho_ro"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on fire "gun"
		{delay 3.0
			{ani_play "open_breech" +1}
		}
		{delay 24.0
			{ani_play "open_breech" -1}
		}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	("repair_anm_script_ho_ro")
}

{"ho_ri_production"
	("ferdinand_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
	}
	("repair_anm_script_v1")
	{on animation_event "hinge"
		{ani_play "hinge_movement" +1}
	}
}

{"ho_ri_prototype"
	("ferdinand_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
	}
	("repair_anm_script_v1")
	{on animation_event "hinge"
		{ani_play "hinge_movement" +1}
	}
}

{"type_94_rocket"
	("yag10_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "bodyback"
				{ani_play "bodyback_b" +1 resume}
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
		{if component "bodyback"
			{if work "body"
				{ani_play "bodyback_r" +1 resume}
				{ani_play "turret_r" +1 resume}
			}
                }
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
			}
                }
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.25 0.2)
	}
	{on spawn
		{ani_wind "support_open" end}
		{tags add "i_see_you"}
	}
	{on move on
		{kill_delay "move_off"}
		{ani_play "support_open" -1.0 resume}
	}
	{on move off
		{delay 1 "move_off"
			{ani_play "support_open" 1.0 resume}
		}
	}
}

{"type_94_aa"
	("yag10_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
	}
	{on fire "gun"
		{ani_play "recoil"}
		{view start "flashbarrel1"}
		{view start "flashbarrel1smoke"}
	}
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
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
			{if component "bodyback"
				{ani_play "bodyback_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
			{if component "extra_wheel1"
            			{tear "piece_medium_steel" bone "extra_wheel1"
                			{impulse up 1.5 rnd_dir 2}
				}
            		}
			{if component "extra_wheel2"
            			{tear "piece_medium_steel" bone "extra_wheel2"
                			{impulse up 1.5 rnd_dir 2}
				}
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
		{if component "bodyback"
			{if work "body"
				{ani_play "bodyback_r" +1 resume}
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
	{on "reload"
		{tear "piece_small_steel" bone "magazine" copy
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse dir 2 fz -5 fx 5.5 }
		}
		{delay 0.1
			{bone hide "magazine"}
		}
		{delay 2.5
			{bone show "magazine"}
			{volumes enable bullet blast}				;// prevent destroing at spawn moment
		}
	}
	{on "cut_parts"
		("cut_part" args "extra_wheel1" 1)
		("cut_part" args "extra_wheel2" 1)
	}
}

{"type_94_fuel"
	("yag10_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("repair_anm_script_v1")
}

{"type_94_transport"
	("yag10_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "bodyback"
				{ani_play "bodyback_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
		}
	}
	{on repair
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
		{if component "bodyback"
			{if work "bodyback"
				{ani_play "bodyback_r" +1 resume}
			}
                }
	}
}

{"type_94_ammo"
	("yag10_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("repair_anm_script_v1")
	{on animation_event "shell"
		{ani_play "shells_move" +0.9}
	}
}

{"type_94_eng"
	("yag10_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("repair_anm_script_v1")
}

{"ka_chi_without"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"ka_chi_pontoons"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"te_ke tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	("repair_anm_script_v1")	
}

{"te_ke_mg tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	("repair_anm_script_v1")	
}

{"te_ke_mg_prototype tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	("repair_anm_script_v1")	
}

{"ka_mi_pontoon tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	("repair_anm_script_v1")	
}

{"ka_mi tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	("repair_anm_script_v1")	
}

{"chi_nu2 tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("ZB37")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
	}
	{on fire "mgun2"
		{view start "mgun_eject2"}
		{view start "fire_gun2"}
		{delay 0.2
			{view pause "mgun_eject2"}
			{view pause "fire_gun2"}
		}
	}
	{on spawn
		{add_view	"shell_mgun"	"mgun_eject2"	"fx_shell"}
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight3"}
    	}
	{on "commander_hatch_open" overload
		{ani_play "open_gunner" +1.0 resume}
		{ani_play "mgun_open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_gunner" -1.0 resume}
		{ani_play "mgun_open" -1.0 resume}
	}
	("repair_anm_script_v1")	
}

{"chi_nu tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("ZB37")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
	}
	{on fire "mgun2"
		{view start "mgun_eject2"}
		{view start "fire_gun2"}
		{delay 0.2
			{view pause "mgun_eject2"}
			{view pause "fire_gun2"}
		}
	}
	{on spawn
		{add_view	"shell_mgun"	"mgun_eject2"	"fx_shell"}
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight3"}
    	}
	{on "commander_hatch_open" overload
		{ani_play "open_gunner" +1.0 resume}
		{ani_play "mgun_open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_gunner" -1.0 resume}
		{ani_play "mgun_open" -1.0 resume}
	}
	("repair_anm_script_v1")	
}

{"ho_i tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("ZB37")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
	}
	{on fire "mgun2"
		{view start "mgun_eject2"}
		{view start "fire_gun2"}
		{delay 0.2
			{view pause "mgun_eject2"}
			{view pause "fire_gun2"}
		}
	}
	{on spawn
		{add_view	"shell_mgun"	"mgun_eject2"	"fx_shell"}
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight3"}
    	}
	{on "commander_hatch_open" overload
		{ani_play "open_gunner" +1.0 resume}
		{ani_play "mgun_open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_gunner" -1.0 resume}
		{ani_play "mgun_open" -1.0 resume}
	}
	("repair_anm_script_v1")	
}

{"chi_he tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
	}
	{on fire "mgun2"
		{view start "mgun_eject2"}
		{view start "fire_gun2"}
		{delay 0.2
			{view pause "mgun_eject2"}
			{view pause "fire_gun2"}
		}
	}
	{on spawn
		{add_view	"shell_mgun"	"mgun_eject2"	"fx_shell"}
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight3"}
    	}
	{on "commander_hatch_open" overload
		{ani_play "open_gunner" +1.0 resume}
		{ani_play "mgun_open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_gunner" -1.0 resume}
		{ani_play "mgun_open" -1.0 resume}
	}
	("repair_anm_script_v1")	
}

{"chi_nu_kai tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
	}
	{on fire "mgun2"
		{view start "mgun_eject2"}
		{view start "fire_gun2"}
		{delay 0.2
			{view pause "mgun_eject2"}
			{view pause "fire_gun2"}
		}
	}
	{on spawn
		{add_view	"shell_mgun"	"mgun_eject2"	"fx_shell"}
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight3"}
    	}
	{on "commander_hatch_open" overload
		{ani_play "open_gunner" +1.0 resume}
		{ani_play "mgun_open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_gunner" -1.0 resume}
		{ani_play "mgun_open" -1.0 resume}
	}
	("repair_anm_script_v1")	
}

{"type_95_car_open"
	("kubel_sound")
	{on "engine_on" 			;// settings for engine when switched on
		{if work "body"
			{if work "engine"
				{ani_play "fan" loop}
			}
		}
	}
	{on "engine_off"
		{delay 1
			{ani_play "Fan"}
		}
	}
	("repair_anm_script_v1")
}

{"type_95_car_close"
	("kubel_sound")
	{on "engine_on" 			;// settings for engine when switched on
		{if work "body"
			{if work "engine"
				{ani_play "fan" loop}
			}
		}
	}
	{on "engine_off"
		{delay 1
			{ani_play "Fan"}
		}
	}
	("repair_anm_script_v1")
}

{"tiger1e_jap tank"
	("pz6_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("MG34")
	}
}

{"is_4_100 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("DShK38")
	}
	{on "engine_on"
		{ani_play "fan_spin" loop}
	}
	{on "engine_off"
		{ani_play "fan_spin"}
	}
	{on fire "flamer1"
		{volumes "smoke1" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "holding_barrel1"}
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel1_is3" bone "smoke_barrel1" copy
				{impulse forward -0.1 }
			}
		}
		{components "barrel1_ammo" break}
		{tags add "need_ammo1"}
		{delay 0.6
			{bone hide "smoke_barrel1"}
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		}
		{if not "flamer1"
			{call_synced "flamer1"}
		}
		{call_synced "flamer1"}
	}
	{on fire "flamer2"
		{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "holding_barrel2"}
		{delay 0.5
			{tear "piece_large_steel_smoke_barrel2_is3" bone "smoke_barrel2" copy
				{impulse forward -0.1 }
			}
		}
		{components "barrel2_ammo" break}
		{tags add "need_ammo2"}
		{delay 0.6
			{bone hide "smoke_barrel2"}
			{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
		}
		{if not "flamer2"
			{call_synced "flamer2"}
		}
		{call_synced "flamer2"}
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
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1 resume}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
		}
		{if component "barrel1_ammo"
			{bone show "smoke_barrel1"}
			{bone show "holding_barrel1"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
		{if component "barrel2_ammo"
			{bone show "smoke_barrel2"}
			{bone show "holding_barrel2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
		{if component "smoke1"
			{bone show "smoke_barrel1"}
			{bone show "holding_barrel1"}
			{volumes "smoke1" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
		{if component "smoke2"
			{bone show "smoke_barrel2"}
			{bone show "holding_barrel2"}
			{volumes "smoke2" enable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
	}
	{on break
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
			{bone hide "smoke_barrel1"}
			{bone hide "holding_barrel1"}
			{if not "smoke1"
				{call_synced "smoke1"}
			}
			{call_synced "smoke1"}
    	}
		{if component "smoke2"
		{damage_report "barrel_reload" "<c(f3ff00)>To reload the smoke barrel repair and resupply the vehicle"}
	    	{tags add "need_ammo2"}
	    	{spawn "ex_sm_size2" "fx_smoke2"}
	    	{volumes "smoke2" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		{bone hide "smoke_barrel2"}
		{bone hide "holding_barrel2"}
		{if not "smoke2"
			{call_synced "smoke2"}
		}
			{call_synced "smoke2"}
    		}
	{if component "engine"
		{tags add "engine_brake"}
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
    }
}

{"o_i tank"
	("t28_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{add_view	"tank_canon_fire_50_57"	"flashbarrel03"	"foresight1a"}
		{add_view	"tank_canon_fire_50_57"	"flashbarrel04"	"foresight1b"}
	}
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm/"}
		("ZB37")
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret3"
				{ani_play "turret3_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner5"}
				else
					{call_synced "kill_charger5"}
				}
			else component "aux_turret2"
				{ani_play "turret2_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner4"}
				else
					{call_synced "kill_charger4"}
				}
			else component "aux_turret1"
				{ani_play "turret1_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner3"}
				else
					{call_synced "kill_charger3"}
				}
			}
			{if  component "turret"
				{ani_play "turret_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner"}
				else
					{call_synced "kill_charger"}
				else
					{call_synced "kill_charger6"}
				else
					{call_synced "kill_commander"}
				}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "gun1"
				{ani_play "gun1_b" +1 resume}
			}
			{if component "gun2"
				{ani_play "gun2_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
		}	
	}
	{on repair
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
 	    {if work "gun1"
                {ani_play "gun1_r" +1 resume}
            }
	    {if work "gun2"
                {ani_play "gun2_r" +1 resume}
            }
	    {if work "body"
                {ani_play "body_r" +1 resume}
            }
	    {if work "turret"
                {ani_play "turret_r" +1 resume}
            }
	    {if work "engine"
                {ani_play "engine_r" +1 resume}
            }
            {if work "aux_turret1"
                {ani_play "turret1_r" +1 resume}
            }
	    {if work "aux_turret2"
                {ani_play "turret2_r" +1 resume}
            }
	    {if work "aux_turret3"
                {ani_play "turret3_r" +1 resume}
            }
        }
	{on "update_multi_turret"
		{if work "aux_turret3"
			{weapon_work "mgun" 1}
		else
			{weapon_work "mgun" 0}
		}
		{inherited}
	}
	{on fire "mgun" overload
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
	{on fire "gun1"
		{play_sound "action_recoil_Cannon2"}
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"} 
		{view start "flashbarrel03"}
			{delay 0.2
				{view pause "flashbarrel03"}
		}
	}
	{on fire "gun2" 
		{play_sound "action_recoil_Cannon2"}
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"}
		{view start "flashbarrel04"}
			{delay 0.2
				{view pause "flashbarrel04"}
		}
	}
}

{"o_i_150 tank"
	("t28_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{add_view	"tank_canon_fire_50_57"	"flashbarrel03"	"foresight1a"}
		{add_view	"tank_canon_fire_50_57"	"flashbarrel04"	"foresight1b"}
	}
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm/"}
		("ZB37")
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret3"
				{ani_play "turret3_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner5"}
				else
					{call_synced "kill_charger5"}
				}
			else component "aux_turret2"
				{ani_play "turret2_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner4"}
				else
					{call_synced "kill_charger4"}
				}
			else component "aux_turret1"
				{ani_play "turret1_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner3"}
				else
					{call_synced "kill_charger3"}
				}
			}
			{if  component "turret"
				{ani_play "turret_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner"}
				else
					{call_synced "kill_charger"}
				else
					{call_synced "kill_charger6"}
				else
					{call_synced "kill_commander"}
				}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "gun1"
				{ani_play "gun1_b" +1 resume}
			}
			{if component "gun2"
				{ani_play "gun2_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
		}
	}
	{on repair
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
 	    {if work "gun1"
                {ani_play "gun1_r" +1 resume}
            }
	    {if work "gun2"
                {ani_play "gun2_r" +1 resume}
            }
	    {if work "body"
                {ani_play "body_r" +1 resume}
            }
	    {if work "turret"
                {ani_play "turret_r" +1 resume}
            }
	    {if work "engine"
                {ani_play "engine_r" +1 resume}
            }
            {if work "aux_turret1"
                {ani_play "turret1_r" +1 resume}
            }
	    {if work "aux_turret2"
                {ani_play "turret2_r" +1 resume}
            }
	    {if work "aux_turret3"
                {ani_play "turret3_r" +1 resume}
            }
        }
	{on "update_multi_turret"
		{if work "aux_turret3"
			{weapon_work "mgun" 1}
		else
			{weapon_work "mgun" 0}
		}
		{inherited}
	}
	{on fire "mgun" overload
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
	{on fire "gun1" 
		{play_sound "action_recoil_Cannon2"}
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"}
		{view start "flashbarrel03"}
			{delay 0.2
				{view pause "flashbarrel03"}
		}
	}
	{on fire "gun2" 
		{play_sound "action_recoil_Cannon2"}
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"}
		{view start "flashbarrel04"}
			{delay 0.2
				{view pause "flashbarrel04"}
		}
	}
}

{"ho_ri_2_aa tank"
	{on spawn
		{add_view	"tank_canon_fire_37_47"	"flashbarrel03"	"foresight1a"}
		{add_view	"tank_canon_fire_20_25_auto"	"flashbarrel04"	"foresight1b"}
	}
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		{link_sound		"Cannon_Mid2"		"weapon/shot/cannon/s1/d2/Shared/Autocannon_20to30mm/"}
		{link_sound		"Cannon_Far2"		"weapon/shot/cannon/s1/d3/Shared/Autocannon_20to30mm/"}
		{link_sound		"action_recoil_Cannon3"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound		"Cannon_Mid3"		"weapon/shot/cannon/s1/d2/Shared/Cannon_37to40mm/"}
		{link_sound		"Cannon_Far3"		"weapon/shot/cannon/s1/d3/Shared/Cannon_37to40mm/"}
		("ZB37")
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
		{ani_play "mgun_deploy" +1.0 resume}
	}
	{on "charger2_hatch_close" overload
		{ani_play "mgun_deploy" -1.0 resume}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun" 1}
		else
			{weapon_work "mgun" 0}
		}
		{inherited}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{ani_play "gun1_b" +1 resume}
			}
			{if component "aux_turret2"
				{ani_play "gun2_b" +1 resume}
			}
			{if  component "turret"
				{ani_play "turret_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "gun1"
				{ani_play "gun1_b" +1 resume}
			}
			{if component "gun2"
				{ani_play "gun2_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
		}
	}
	{on repair
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
 	    {if work "gun1"
                {ani_play "gun1_r" +1 resume}
            }
	    {if work "gun2"
                {ani_play "gun2_r" +1 resume}
            }
	    {if work "body"
                {ani_play "body_r" +1 resume}
            }
	    {if work "engine"
                {ani_play "engine_r" +1 resume}
            }
            {if work "aux_turret1"
                {ani_play "gun1_r" +1 resume}
            }
	    {if work "aux_turret2"
                {ani_play "gun2_r" +1 resume}
            }
        }
	{on fire "gun2"
		{play_sound "action_recoil_Cannon3"}
		{play_sound "Cannon_Mid3"}
		{play_sound "Cannon_Far3"} 
		{view start "flashbarrel03"}
			{delay 0.2
				{view pause "flashbarrel03"}
		}
	}
	{on fire "mgun"
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"} 
		{view start "flashbarrel04"}
		{ani_play "fire1" +1}
		{delay 0.2
			{view pause "flashbarrel04"}
		}
	}
}

{"type_97_motorcycle"
	("r12_sound")
	("repair_anm_script_v1")
}

{"type_97_motorcycle_shield"
	("r12_sound")
	("repair_anm_script_v1")
}
{"type_97_motorcycle_late"
	("r12_sound")
	("repair_anm_script_v1")
}

{"type_97_motorcycle_shield_late"
	("r12_sound")
	("repair_anm_script_v1")
}
	
{"ha_go"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"ha_go_ijn"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
	}
	("repair_anm_script_v1")
	{on spawn
        {tex_mod "ijn"}
    }
}

{"ha_go_late"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"ha_go_late_ijn"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
	}
	("repair_anm_script_v1")
	{on spawn
        {tex_mod "ijn"}
    }
}

{"ha_go_flamm"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
	}
	{on spawn
		{add_view "flamer_fire_tank" "gun" "foresight1"}
		{tex_mod "camo2"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 60 1 40)
}

{"ke_nu"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"ro_go_early tank"
	("t28_sound")
	{on spawn
		{add_view	"tank_canon_fire_50_57"	"flashbarrel03"	"foresight1a"}
		{add_view	"flash_gun_big"	"flashbarrel04"	"foresight8"}
	}
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm/"}
		("ZB37")
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret2"
				{ani_play "turret2_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner4"}
				}
			else component "aux_turret1"
				{ani_play "turret1_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner3"}
				else
					{call_synced "kill_charger"}
				}
			}
			{if  component "turret"
				{ani_play "turret_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner"}
				else
					{call_synced "kill_commander"}
				}
			}
			{if  component "body4"
				{if rand 0.5
					{call_synced "kill_gunner4"}
				else
					;nothing
				}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "gun1"
				{ani_play "gun1_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
		}	
	}
	{on repair
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
 	    {if work "gun1"
                {ani_play "gun1_r" +1 resume}
            }
	    {if work "gun2"
                {ani_play "gun2_r" +1 resume}
            }
	    {if work "body"
                {ani_play "body_r" +1 resume}
            }
	    {if work "turret"
                {ani_play "turret_r" +1 resume}
            }
	    {if work "engine"
                {ani_play "engine_r" +1 resume}
            }
            {if work "aux_turret1"
                {ani_play "turret1_r" +1 resume}
            }
	    {if work "aux_turret2"
                {ani_play "turret2_r" +1 resume}
            }
        }
	{on "update_multi_turret"
		{if work "aux_turret2"
			{weapon_work "mgun" 1}
		else
			{weapon_work "mgun" 0}
		}
		{inherited}
	}
	{on fire "gun1"
		{play_sound "action_recoil_Cannon2"}
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"} 
		{view start "flashbarrel03"}
			{delay 0.2
				{view pause "flashbarrel03"}
		}
	}
	{on fire "mgun1" 	
		{view start "flashbarrel04"}
		{delay 0.2
			{view pause "flashbarrel04"}
		}
	}
}

{"ro_go_late tank"
	("t28_sound")
	{on spawn
		{add_view	"tank_canon_fire_50_57"	"flashbarrel03"	"foresight1a"}
		{add_view	"flash_gun_big"	"flashbarrel04"	"foresight8"}
	}
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid2"		"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm/"}
		{link_sound 		"Cannon_Far2"		"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm/"}
		("ZB37")
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret2"
				{ani_play "turret2_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner4"}
				}
			else component "aux_turret1"
				{ani_play "turret1_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner3"}
				else
					{call_synced "kill_charger"}
				}
			}
			{if  component "turret"
				{ani_play "turret_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner"}
				else
					{call_synced "kill_commander"}
				}
			}
			{if  component "body4"
				{if rand 0.5
					{call_synced "kill_gunner4"}
				else
					;nothing
				}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "gun1"
				{ani_play "gun1_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
		}	
	}
	{on repair
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
 	    {if work "gun1"
                {ani_play "gun1_r" +1 resume}
            }
	    {if work "gun2"
                {ani_play "gun2_r" +1 resume}
            }
	    {if work "body"
                {ani_play "body_r" +1 resume}
            }
	    {if work "turret"
                {ani_play "turret_r" +1 resume}
            }
	    {if work "engine"
                {ani_play "engine_r" +1 resume}
            }
            {if work "aux_turret1"
                {ani_play "turret1_r" +1 resume}
            }
	    {if work "aux_turret2"
                {ani_play "turret2_r" +1 resume}
            }
        }
	{on "update_multi_turret"
		{if work "aux_turret2"
			{weapon_work "mgun" 1}
		else
			{weapon_work "mgun" 0}
		}
		{inherited}
	}
	{on fire "gun1" 
		{play_sound "action_recoil_Cannon2"}
		{play_sound "Cannon_Mid2"}
		{play_sound "Cannon_Far2"}
		{view start "flashbarrel03"}
			{delay 0.2
				{view pause "flashbarrel03"}
		}
	}
	{on fire "mgun1" 	
		{view start "flashbarrel04"}
		{delay 0.2
			{view pause "flashbarrel04"}
		}
	}
}

{"ro_go_exp tank"
	("t28_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel03"	"foresight4"}
	}
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("ZB37")
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{ani_play "turret1_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner4"}
				}
			}
			{if  component "turret"
				{ani_play "turret_b" +1 resume}
				{if rand 0.5
					{call_synced "kill_gunner"}
				else
					{call_synced "kill_commander"}
				}
			}
			{if  component "body4"
				{if rand 0.5
					{call_synced "kill_gunner4"}
				else
					;nothing
				}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
		}	
	}
	{on repair
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
	    {if work "body"
                {ani_play "body_r" +1 resume}
            }
	    {if work "turret"
                {ani_play "turret_r" +1 resume}
            }
	    {if work "engine"
                {ani_play "engine_r" +1 resume}
            }
            {if work "aux_turret1"
                {ani_play "turret1_r" +1 resume}
            }
        }
	{on fire "gun"
		{ani_play "recoil"}
		{delay 2
			{ani_play "breech_open"}
		}
		{delay 12
			{ani_play "breech_close"}
		}
	}
	{on fire "mgun" 	
		{view start "flashbarrel03"}
		{delay 0.2
			{view pause "flashbarrel03"}
		}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun" 1}
		else
			{weapon_work "mgun" 0}
		}
		{inherited}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.5 0.3)
	}
}

{"chi_to tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("ZB37")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
	}
	{on fire "mgun"
		{view start "mgun_eject2"}
		{view start "fire_gun3"}
		{delay 0.2
			{view pause "mgun_eject2"}
			{view pause "fire_gun3"}
		}
	}
	{on spawn
		{add_view	"shell_mgun"	"mgun_eject2"	"fx_shell"}
		{add_view "flash_gun_hmg_m2hb" "fire_gun3" "foresight7"}
    	}
	{on "commander_hatch_open" overload
		{ani_play "gunner_open" +1.0 resume}
		{ani_play "mgun_open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "gunner_open" -1.0 resume}
		{ani_play "mgun_open" -1.0 resume}
	}
	("repair_anm_script_v1")	
}

{"overvalwagen_aa tank"
	("opel_maultier_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun1_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun1_aa" -1.0 resume}
	}
	{on "gunner_hatch_open" overload
		{ani_play "mgun2_aa" +1.0 resume}
	}
	{on "gunner_hatch_close" overload
		{ani_play "mgun2_aa" -1.0 resume}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun3_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun3_aa" -1.0 resume}
	}
	{on "gunner4_hatch_open" overload
		{ani_play "mgun4_aa" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun4_aa" -1.0 resume}
	}
	{on spawn
		{if tagged "door_open_driver"
			{ani_wind "open_driver" end}
		}
		{add_view	"shell_mgun"	"mgun_eject"	"fx_shell"}
		{add_view	"shell_mgun"	"mgun_eject1"	"fx_shell1"}
		{add_view	"shell_mgun"	"mgun_eject2"	"fx_shell2"}
		{add_view "flash_gun_hmg_m2hb"  "fire_gun4"    "foresight6"}
	}
	{on animation_event "board_driver"
		{if tagged "door_open_driver"
			{kill_delay "boarding"}
			{delay 5 "boarding"
				{if operatable
					{tags remove "door_open_driver"}
					{ani_play "close_driver" 1}
					{call "close"}
				}
			}
		else
			{ani_play "open_driver" 1}
			{tags add "door_open_driver"}
			{call "open"}
			{delay 5 "boarding"
				{if operatable
					{tags remove "door_open_driver"}
					{ani_play "close_driver" 1}
					{call "close"}
				}
			}
		}
	}
	{on "lights_on"
		{ani_play "lights_open"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "lights_open" -1}
			{tags remove "lights_on"}
		}
	}
	{on fire "mgun"
		{view start "mgun_eject"}
		{ani_play "mgun_fire"}
		{delay 0.2
			{view pause "mgun_eject"}
		}
	}
	{on fire "mgun4"
		{view start "mgun_eject2"}
		{view start "fire_gun4"}
		{ani_play "mgun_fire2"}
		{delay 0.2
			{view pause "mgun_eject2"}
			{view pause "fire_gun4"}
		}
	}
	{on fire "mgun2"
		{view start "mgun_eject1"}
		{ani_play "mgun_fire1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
	}
	{on "reload"
		{ani_play "reload_mgun"}
	}
	("repair_anm_script_v1")
}

{"overvalwagen_apc tank"
	("opel_maultier_sound")
	{on spawn
		{if tagged "door_open_driver"
			{ani_wind "open_driver" end}
		}
	}
	{on "lights_on"
		{ani_play "lights_open"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "lights_open" -1}
			{tags remove "lights_on"}
		}
	}
	("repair_anm_script_v1")
}

{"overvalwagen_gun tank"
	("opel_maultier_sound")
	{on spawn
		{if tagged "door_open_driver"
			{ani_wind "open_driver" end}
		}
		{add_view	"shell_mgun"	"mgun_eject1"	"fx_shell1"}
		{add_view	"shell_mgun"	"mgun_eject2"	"fx_shell2"}
		{add_view "flash_gun_hmg_m2hb"  "fire_gun4"    "foresight6"}
	}
	{on "lights_on"
		{ani_play "lights_open"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "lights_open" -1}
			{tags remove "lights_on"}
		}
	}
	{on repair
		{if component "body"
			{if work "turret"
				{ani_play "body_r" +1 resume}
			}
		}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
		}
	}
	{on fire "mgun4"
		{view start "mgun_eject2"}
		{view start "fire_gun4"}
		{ani_play "mgun_fire2"}
		{delay 0.2
			{view pause "mgun_eject2"}
			{view pause "fire_gun4"}
		}
	}
	{on fire "mgun2"
		{view start "mgun_eject1"}
		{ani_play "mgun_fire1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
	}
	{on fire "gun"
		{if tagged "ammo_shot1"
			;nothing
		else tagged "ammo_shot2"
			{bone hide "ammo_holder6"}
			{tags remove "ammo_shot2"}
			{tags add    "ammo_shot3"}
		else tagged "ammo_shot3"
			{bone hide "ammo_holder5"}
			{tags remove "ammo_shot3"}
			{tags add    "ammo_shot4"}
		else tagged "ammo_shot4"
			{bone hide "ammo_holder4"}
			{tags remove "ammo_shot4"}
			{tags add    "ammo_shot5"}
		else tagged "ammo_shot5"
			{bone hide "ammo_holder3"}
			{tags remove "ammo_shot5"}
			{tags add    "ammo_shot6"}
		else tagged "ammo_shot6"
			{bone hide "ammo_holder2"}
			{tags remove "ammo_shot6"}
			{tags add    "ammo_shot7"}
		else tagged "ammo_shot7"
			{bone hide "ammo_holder1"}
		else
			{bone hide "ammo_holder7"}
			{tags remove "ammo_shot1"}
			{tags add    "ammo_shot2"}
		}
	}
	{on "reload"
		{ani_play "reload_gun"}
		{bone show "ammo1"}
		{bone show "ammo2"}
		{bone show "ammo3"}
		{bone show "ammo4"}
		{bone show "ammo5"}
		{bone show "ammo6"}
		{bone show "ammo7"}
		{tags remove "ammo_shot1"}
		{tags remove "ammo_shot2"}
		{tags remove "ammo_shot3"}
		{tags remove "ammo_shot4"}
		{tags remove "ammo_shot5"}
		{tags remove "ammo_shot6"}
		{tags remove "ammo_shot7"}
		{bone hide "ammo_holder1"}
		{bone hide "ammo_holder2"}
		{bone hide "ammo_holder3"}
		{bone hide "ammo_holder4"}
		{bone hide "ammo_holder5"}
		{bone hide "ammo_holder6"}
		{bone hide "ammo_holder7"}
		{delay 1.5
			{bone show "ammo_holder1"}
			{bone show "ammo_holder2"}
			{bone show "ammo_holder3"}
			{bone show "ammo_holder4"}
			{bone show "ammo_holder5"}
			{bone show "ammo_holder6"}
			{bone show "ammo_holder7"}
			{bone hide "ammo1"}
			{bone hide "ammo2"}
			{bone hide "ammo3"}
			{bone hide "ammo4"}
			{bone hide "ammo5"}
			{bone hide "ammo6"}
			{bone hide "ammo7"}
		}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun3_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun3_aa" -1.0 resume}
	}
	{on "gunner4_hatch_open" overload
		{ani_play "mgun4_aa" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun4_aa" -1.0 resume}
	}
}

{"chi_ri_2 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		{link_sound		"action_recoil_Cannon2"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound		"Cannon_Mid2"		"weapon/shot/cannon/s1/d2/Shared/Cannon_37to40mm/"}
		{link_sound		"Cannon_Far2"		"weapon/shot/cannon/s1/d3/Shared/Cannon_37to40mm/"}
		("ZB37")
	}
	("repair_anm_script_v1")
	{on fire "gun"
		{tags add "reload"}
		{if tagged "reload"
			{delay 1.0
				{ani_play "reload" +1 }
			}
			{delay 2.5
				{ani_play "reload" -1 }
				{tags add "remove"}
			}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.0 0.3)
	}	
}

{"chi_se tank"
	("ferdinand_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"ho_to"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 3 0.1)
	}
	{on "reload"
		{delay 3.0
			{ani_play "reload_open" +1}
		}
		{delay 24.0
			{ani_play "reload_close" +1}
		}
	}
	("repair_anm_script_ho_to")
}

{"na_to"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	("repair_anm_script_v1")
}

{"ha_to"
	{on "add_weapon_sound" overload
		("Cannon_280mm+")
	}

	("tag_ai_arty_mace")

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

	{on engine on				;// any vehicle moves forward, reverse or preforming neutral turn
		{if "hidden"
			{call "engine_on"}					;// added call to fix vehicles spawned through mission scripts not having sounds in Coop mode
		}
		{if "engine_on"							;// checks that engine is on and not toggled off while moving
			{kill_delay "engine_stopped"}
			{kill_delay "engine_steam_stopped"}
			{stop_sound "engine_stop"}
			{play_sound "exhaust"}				;// exhaust/accelerate sound
			{play_sound "engine_full" 1}
			{view start "engine_steam"}			;// used for train steam fx, and vehicle engines in rain
			{if "hidden"
				{call "engine_idle"}
				{call "play_trace_engine"}		;// plays dust fx for aero vehicles
				{call "update_lights"}
				{set "hidden" 0}
			}
		}
	}

	{on engine off				;// any vehicle not moving at all
		{if not "engine_on"
			{stop_sound "engine_full"}
			{play_sound "brake"}
			{view pause "exhaust"}
			{view pause "exhaust2"}
		}
		{if "engine_on"
			{play_sound "exhaust"}
			{delay 0.5 "engine_stopped"
				{if work "engine"
					{if work "body"
						{if "engine_on"
							{play_sound "engine_idle" 1}
							{stop_sound "engine_full"}
						}
					}
				}
			}
			{delay 0.5 "engine_steam_stopped"
				{if work "engine"
					{if work "body"
						{if "engine_on"
							{if work "mover"
								{view start "exhaust2"}
							}
						}
					}
				}
			}
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

	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"				"vehicle/tracks/t34/"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}

	{on "explosion_blastwave" overload
		{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
		{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
		{impulse up 0.1 0.1 dir 0.2 0.1}
		{spawn "tank_die_heavy" "basis"}
		{start_sound "detonation/explosion_vehicle/bkg/"}
		{if terrain_fx "snow"
			{spawn "tank_die_snow" "basis"}
		else terrain_fx "ice"
			{spawn "tank_die_snow" "basis"}
		else
			{spawn "tank_die_dust" "basis"}
		}
	}

	{on contact overload
		{if not impregnable
			{if not effector "bicycle"
				{if effector "vehicle"
					{if effector_velocity 2
						{if not "fx_delay"
							{set "fx_delay" 1}
							{delay 2 "fx_delay"
								{set "fx_delay" 0}
							}
							{spawn "metal_crush" "root"}
						}
					}
				}
			}
		}
	}
	("repair_anm_script_v1")
}

{"chi_so"
	("t34_sound")
	("repair_anm_script_v1")
}

{"type_92_hac_early tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"type_92_hac_late tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	("repair_anm_script_v1")	
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_open" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_open" -1.0 resume}
	}
}

{"to_ku_pontoons tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
		("Cannon_45to47mm")
		("ZB37")
	}
	{on fire "gun1"
		{ani_play "fire1" +1 }
	}
	("repair_anm_script_v1")	
}

{"to_ku tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
		("Cannon_45to47mm")
		("ZB37")
	}
	{on fire "gun1"
		{ani_play "fire1" +1 }
	}
	("repair_anm_script_v1")
}

{"ho_ha tank"
	("hanomag_sound")
	{on spawn
		{if rand 0.5
			{bone hide "rolled_tent"}
		else
			{bone hide "tent"}
		}		
	}
	{on "add_weapon_sound" overload
		("ZB37")
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	("repair_anm_script_v1")
}

{"so_da tank"
	("t27_sound")
	{on "commander_hatch_open" overload
		{ani_play "commander_open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "commander_open" -1.0 resume}
	}
	("repair_anm_script_v1")
}

{"so_da_ammo tank"
	("t27_sound")
	{on "commander_hatch_open" overload
		{ani_play "commander_open" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "commander_open" -1.0 resume}
	}
	("repair_anm_script_v1")
}

{"m3_stuart_jap tank"
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

{"m2_halftrack_jap tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}
{"m3_gmc_jap tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.9 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.5)
	}
}

{"ss_ki"
	("t26_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	{on spawn
		{add_view "flamer_fire_tank" "gun"     "foresight6"}
		{add_view "flamer_fire_tank" "gun2"    "foresight7"}
		{add_view "flamer_fire_tank" "gun3"    "foresight8"}
		{add_view "flamer_fire_tank" "gun4"    "foresight9"}
		{add_view "flamer_fire_tank" "gun5"    "foresight10"}
		{if rand 0.50
			{bone hide "bridge1"}
			{bone hide "bridge2"}
			{volumes "bridge1" disable bullet blast touch}
			{volumes "bridge2" disable bullet blast touch}
		}
	}
	("flame_weapon" args gun  60 6 40)
	("flame_weapon" args gun2 60 7 40)
	("flame_weapon" args gun3 60 8 40)
	("flame_weapon" args gun4 60 9 40)
	("flame_weapon" args gun5 60 10 40)
	("repair_anm_script_v1")
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
}

{"i_go_late"
	("t28_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"i_go_late_ijn"
	("t28_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	("repair_anm_script_v1")
	{on spawn
        {tex_mod "ijn"}
    }
}

{"i_go_ijn"
	("t28_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	("repair_anm_script_v1")
	{on spawn
        {tex_mod "ijn"}
    }
}

{"i_go"
	("t28_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"ho_ni_i tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.15 0.95)
	}
	{on "reload_delay" overload
		("reload_time" args 5.25)	;// weapon reload time
	}
	{on "reload"
		{delay 1.5
			{ani_play "open_breech" +1}
		}
		{delay 2.5
			{ani_play "open_breech" -1}
		}
	}
	("repair_anm_script_v1")
}

{"ho_ni_ii tank"
	("t26_sound")
	("tag_ai_arty_mace")
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.15 0.95)
	}
	{on "reload_delay" overload
		("reload_time" args 5.25)	;// weapon reload time
	}
	{on "reload"
		{delay 1.5
			{ani_play "open_breech" +1}
		}
		{delay 8.5
			{ani_play "open_breech" -1}
		}
	}
	("repair_anm_script_ho_ni_ii")
}

{"ho_ni_iii tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.15 0.95)
	}
	{on "reload_delay" overload
		("reload_time" args 5.25)	;// weapon reload time
	}
	{on "reload"
		{delay 1.5
			{ani_play "open_breech" +1}
		}
	}
	("repair_anm_script_v1")
}

{"vk_4501_p tank"
	("ferdinand_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_85to100mm")
	}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
	}
	{on repair
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
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "turret"
				{ani_play "turret_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
      			{if component "shield_tracks1"
            			{tear "piece_medium_steel" bone "shield_tracks1"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
			{if component "shield_tracks2"
            			{tear "piece_medium_steel" bone "shield_tracks2"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
		}
	}
}

{"pzbefwgvi_p tank"
	("ferdinand_sound")
	{on "add_weapon_sound" overload
		("MG34")
		("Cannon_85to100mm")
	}
	{on "commander_hatch_open" overload
		{ani_play "open_commander" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
	}
	{on repair
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
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
			}
                }
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
			{if component "turret"
				{ani_play "turret_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
      			{if component "shield_tracks1"
            			{tear "piece_medium_steel" bone "shield_tracks1"
                			{impulse up 1.5 rnd_dir 2}
            			}
        		}
		}
	}
}

{"type_93_kokusan tank"
	("ba_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	{on "engine_on" 			;// settings for engine when switched on
		{if work "body"
			{if work "engine"
				{ani_play "fan" loop}
			}
		}
	}
	{on "engine_off"
		{delay 1
			{ani_play "fan"}
		}
	}
	("repair_anm_script_v1")
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
}

{"t60_fin tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("DT")
	}
}

{"type_94_tk_late tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
	}
	("repair_anm_script_v1")	
}

{"type_94_tk_mg_late tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	("repair_anm_script_v1")	
}

{"type_94_tk_mg_early tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	("repair_anm_script_v1")	
}

{"ft17_jap tank"
	("pz1_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
	}
	{on fire "gun"  
		{ani_play "fire2" 1.0}
	}
}

{"ft17_mg_jap tank"
	("pz1_sound")
	{on "add_weapon_sound" overload
		("PM1910_30")
	}
}

{"150mm_type_94_mortar"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	("yag10_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
	("repair_anm_script_v1")
	{on "cut_parts"
		("cut_part" args "part1" 0.6)
		("cut_part" args "part2" 0.6)
		("cut_part" args "part3" 0.6)
	}
}

{"chi_ha"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"chi_ha_bamboo"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	("repair_anm_script_v1")
}

{"chi_ha_late"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	("repair_anm_script_v1")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_yu tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/steel/"}
		{link_sound "flail_start"			"vehicle/tracks/Crab_Flail/Flail_Begin"}
		{link_sound "flail_loop"			"vehicle/tracks/Crab_Flail/Flail_Loop"}
		{link_sound "flail_end"				"vehicle/tracks/Crab_Flail/Flail_End"}
	}
	("repair_anm_script_v1")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_ha_late_bamboo"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	("repair_anm_script_v1")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_ha_late_ijn"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	{on spawn
        {tex_mod "ijn"}
    }
	("repair_anm_script_v1")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_ha_ijn"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	{on spawn
        {tex_mod "ijn"}
    }
	("repair_anm_script_v1")
}

{"chi_ha_kai"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	("repair_anm_script_v1")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_ha_kai_bamboo"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	("repair_anm_script_v1")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_ha_kai_ijn"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	{on spawn
        {tex_mod "ijn"}
    }
	("repair_anm_script_v1")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_ha_kai_late"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	("repair_anm_script_v1")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_ha_kai_late_bamboo"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	("repair_anm_script_v1")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_ha_kai_late_ijn"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("ZB37")
	}
	{on spawn
        {tex_mod "ijn"}
    }
	("repair_anm_script_v1")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_ha_sg"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("ZB37")
	}
	("repair_anm_script_chi_ha_sg")
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

{"chi_ha_lg"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
	}
	("repair_anm_script_chi_ha_sg")
	{on "charger_hatch_open" overload
		{ani_play "shell_show" +1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "shell_hide" +1.0 resume}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.50 0.2)
	}
	{on "reload_delay" overload
		("reload_time" args 20)	;// weapon reload time
	}
}

{"shi_ki"
	("t26_sound")
	{on spawn ; MACE AIR SCRIPT TAG ADD
		{tags add "command_vehicle_aa"}
	}
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	("repair_anm_script_shi_ki")
	{on "commander_hatch_open" overload
		{ani_wind "open_mg" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_mg" -1.0 resume}
	}
}

{"ka_ho"
	("t26_sound")
		{on spawn
		{add_view "flamer_fire_tank" "flamer" "foresight2"}
		{add_view "flamer_fire_tank" "flamer1" "foresight3"}
	}
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("ZB37")
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	("flame_weapon" args flamer 60 2 40)
	("flame_weapon" args flamer1 60 3 40)
	("repair_anm_script_v1")
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
}

{"se_ri tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on spawn
		{add_view	"repair"		"repair"	"hearing_bone"}
		{tags add "ai_engineer_vehicle"}
		{link_sound "screw_twist"		"human/anims/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anims/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anims/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anims/repair/toolbox_close/"}
		{link_sound "tool_equip"		"human/anims/repair/tool_equip/"}
	}
	{on break
		{if not tagged "exploded"
			{if component "trackright"
				{tags add "major_broken1"}
				{tags add "major_broken"}
			else component "trackleft"
				{tags add "major_broken2"}
				{tags add "major_broken"}
			else component "engine"
				{tags add "major_broken3"}
				{tags add "major_broken"}
				{ani_play "engine_b" 1.0}
			}
			{if component "body"
				{ani_play "body_b" 1.0}
			}
			{if component "turret"
				{ani_play "turret_b" 1.0}
			}
		}
    }
	{on repair
		{if not tagged "exploded"
			{if component "trackleft"
			 	{tags remove "major_broken2"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken3"
					{tags remove "major_broken"}
				}
			}	
			{if component "trackright"
			 	{tags remove "major_broken1"}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken3"
					{tags remove "major_broken"}
				}
			}
			{if component "engine"
			 	{tags remove "major_broken3"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
				{ani_play "engine_r" 1.0}
			}
			{if component "turret"
			 	{tags remove "major_broken3"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
				{ani_play "turret_r" 1.0}
			}
			{if component "body"
				{ani_play "body_r" 1.0}
			}
		}
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
		{delay 40
			{if operatable
				{if not tagged "major_broken"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{chassis_work 1}
						{call "engine_on"}
					}
				}	
				{if tagged "major_broken1"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}
				}	
				{if tagged "major_broken2"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}
				}	
				{if tagged "major_broken3"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}	
				}
				{if tagged "major_broken4"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}	
				}
				{if not operatable
					{spawn "recovery_repair_remover_effect" "basis"}
					{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Failed"}
					{view pause "repair"} 
					{chassis_work 1}
					{call "engine_on"}
				}		
			}	
		}	
	}
}

;/*=========== French Vehicles Begin ===========*/

{"char_2c tank"
	("char_b1_sound")
	{on spawn
		{link_sound "flame1"						"fire/metal"}
		{link_sound 		"action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid"		"weapon/shot/cannon/s1/d2/Shared/Cannon_37to40mm/"}
		{link_sound 		"Cannon_Far"		"weapon/shot/cannon/s1/d3/Shared/Cannon_37to40mm/"}
		{link_sound		"MG_Mid"		"weapon/shot/smallarms/s3/d2/Shared/MAC1931/"}
		{link_sound		"MG_Far"		"weapon/shot/smallarms/s3/d3/Shared/MAC1931/"}
		{volumes "aux_turret1_xx" disable bullet blast}
		{volumes "towing_xx" disable bullet blast}
		{delay 1.5
			{if "engine_on"
				{delay 2.5
					{ani_play "spin_hatch" loop}
					{ani_play "fan_spin" loop}
				}
			}
		}
	}
	{on "_explosion" overload
		{add_view "fire_vehicle_death" "fire" "fxfire4"}
		{add_view "smoke_dead_turret" "smoke" "fxfire4"}
		{spawn "tank_die_heavy"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 8 heating 10}
		{able minimap 0}
		{able select 0}
		{able repaired 0}
		{tags add "ammo_cooked"}
		{tags add "no_scavenge"}
		{call "engine_off"}
		{clear_inventory}
		{view start "fire"}
		{stop_sound "flame1"}
		{stop_sound "flame2"}
		{stop_sound "flame3"}
		{stop_sound "flame4"}
		{stop_sound "flame5"}
		{stop_sound "flame6"}
		{stop_sound "flame7"}
		{set_skeleton "_xx"}
           	{ani_play "death"}
          	{call "cut_parts"}
		{bone hide "towing"}
		{bone hide "aux_turret1"}
		{bone hide "gunner_cupola"}
		{bone hide "mgun4_rot1"}
		{bone hide "mgun3"}
		{tear "piece_medium_steel" bone "turret" id "turret"
			{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			{delay_effect 20 5 "stop"}			;// calls {on "stop"} in dummy.inc
			{delay 0.1
				{volumes "gun" disable obstacle}
			}
		}
		{spawn "crater_massive" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
		{delay 500 60
			{view pause "fire"}
			{view start "smoke"}
			{stop_sound "flame1"}
			{view pause "sparks1"}
			{view pause "sparks2"}
			{view pause "smoke_ex1"}
			{view pause "smoke_ex2"}
		}
	}
	{on "explosion_blastwave" overload
		{start_sound "detonation/he_size5/bkg/"}
		{blastwave c4 45 r0 2.6 r1 5.2}
		{blastwave c4 15.85 r0 5.85 r1 18.85}
		{blastwave c4 1.538 r0 18.72 r1 30.08}
		{set_skeleton "_xx"}
           	{ani_play "death"}
          	{call "cut_parts"}
		{spawn "shockwave_sphere"}
		{spawn "ex_he_size6"}

		{spawn "crater_massive" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
		{view pause "sparks1"}
		{view pause "sparks2"}
		{view pause "smoke_ex1"}
		{view pause "smoke_ex2"}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{call "kill_gunner5"}
				{ani_play "turret_aux_b"}
			}
			{if component "engine"
				{ani_play "engine_b"}
			}
			{if component "body"
				{ani_play "body_b"}
			}
			{if component "turret"
				{ani_play "turret_b"}
			}
			{if component "gun"
				{ani_play "gun_b"}
			}
		}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun4" 1}
		else
			{weapon_work "mgun4" 0}
		}
		{inherited}
	}
	{on "engine_on"
		{delay 2.5
			{ani_play "spin_hatch" loop}
			{ani_play "fan_spin" loop}
		}
	}
	{on "engine_off"
		{ani_play "spin_hatch"}
		{ani_play "fan_spin"}
	}
	{on repair
		{if work "fuel_tank1"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank2"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank3"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank4"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank5"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank6"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank7"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "gun"
			{ani_play "gun_r"}
		}
		{if work "turret"
			{ani_play "turret_r"}
		}
		{if work "body"
			{ani_play "body_r"}
		}
		{if work "engine"
			{ani_play "engine_r"}
		}
		{if work "engine"
			{ani_play "turret_aux_r"}
		}
	}
	{on operatable off
		{ani_play "spin_hatch" +1.0 resume}
	}
	{on operatable on
		{if "engine_on"
			{delay 2.5
				{ani_play "spin_hatch" loop}
			}
		}
	}
}

{"char_2c_bis tank"
	("char_b1_sound")
	{on spawn
		{link_sound "flame1"						"fire/metal"}
		{link_sound 		"action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid"		"weapon/shot/cannon/s1/d2/Shared/Cannon_37to40mm/"}
		{link_sound 		"Cannon_Far"		"weapon/shot/cannon/s1/d3/Shared/Cannon_37to40mm/"}
		{link_sound		"MG_Mid"		"weapon/shot/smallarms/s3/d2/Shared/MAC1931/"}
		{link_sound		"MG_Far"		"weapon/shot/smallarms/s3/d3/Shared/MAC1931/"}
		{volumes "aux_turret1_xx" disable bullet blast}
		{volumes "towing_xx" disable bullet blast}
		{delay 1.5
			{if "engine_on"
				{delay 2.5
					{ani_play "spin_hatch" loop}
					{ani_play "fan_spin" loop}
				}
			}
		}
	}
	{on "_explosion" overload
		{add_view "fire_vehicle_death" "fire" "fxfire4"}
		{add_view "smoke_dead_turret" "smoke" "fxfire4"}
		{spawn "tank_die_heavy"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 8 heating 10}
		{able minimap 0}
		{able select 0}
		{able repaired 0}
		{tags add "ammo_cooked"}
		{tags add "no_scavenge"}
		{call "engine_off"}
		{clear_inventory}
		{view start "fire"}
		{stop_sound "flame1"}
		{stop_sound "flame2"}
		{stop_sound "flame3"}
		{stop_sound "flame4"}
		{stop_sound "flame5"}
		{stop_sound "flame6"}
		{stop_sound "flame7"}
		{set_skeleton "_xx"}
           	{ani_play "death"}
          	{call "cut_parts"}
		{bone hide "towing"}
		{bone hide "aux_turret1"}
		{bone hide "gunner_cupola"}
		{bone hide "mgun4_rot1"}
		{bone hide "mgun3"}
		{tear "piece_medium_steel" bone "turret" id "turret"
			{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			{delay_effect 20 5 "stop"}			;// calls {on "stop"} in dummy.inc
			{delay 0.1
				{volumes "gun" disable obstacle}
			}
		}
		{spawn "crater_massive" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
		{delay 500 60
			{view pause "fire"}
			{view start "smoke"}
			{stop_sound "flame1"}
			{view pause "sparks1"}
			{view pause "sparks2"}
			{view pause "smoke_ex1"}
			{view pause "smoke_ex2"}
		}
	}
	{on "explosion_blastwave" overload
		{start_sound "detonation/he_size5/bkg/"}
		{blastwave c4 45 r0 2.6 r1 5.2}
		{blastwave c4 15.85 r0 5.85 r1 18.85}
		{blastwave c4 1.538 r0 18.72 r1 30.08}
		{set_skeleton "_xx"}
           	{ani_play "death"}
          	{call "cut_parts"}
		{spawn "shockwave_sphere"}
		{spawn "ex_he_size6"}

		{spawn "crater_massive" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
		{view pause "sparks1"}
		{view pause "sparks2"}
		{view pause "smoke_ex1"}
		{view pause "smoke_ex2"}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{call "kill_gunner5"}
				{ani_play "turret_aux_b"}
			}
			{if component "engine"
				{ani_play "engine_b"}
			}
			{if component "body"
				{ani_play "body_b"}
			}
			{if component "turret"
				{ani_play "turret_b"}
			}
			{if component "gun"
				{ani_play "gun_b"}
			}
		}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun4" 1}
		else
			{weapon_work "mgun4" 0}
		}
		{inherited}
	}
	{on "engine_on"
		{delay 2.5
			{ani_play "spin_hatch" loop}
			{ani_play "fan_spin" loop}
		}
	}
	{on "engine_off"
		{ani_play "spin_hatch"}
		{ani_play "fan_spin"}
	}
	{on repair
		{if work "fuel_tank1"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank2"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank3"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank4"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank5"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank6"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank7"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "gun"
			{ani_play "gun_r"}
		}
		{if work "turret"
			{ani_play "turret_r"}
		}
		{if work "body"
			{ani_play "body_r"}
		}
		{if work "engine"
			{ani_play "engine_r"}
		}
		{if work "engine"
			{ani_play "turret_aux_r"}
		}
	}
	{on operatable off
		{ani_play "spin_hatch" +1.0 resume}
	}
	{on operatable on
		{if "engine_on"
			{delay 2.5
				{ani_play "spin_hatch" loop}
			}
		}
	}
	{on pierce
		{if volume "shield_commander"
			{if rand 0.5
				{call "kill_commander"}
			}
		}
	}
}

{"char_2c_armored tank"
	("char_b1_sound")
	{on spawn
		{link_sound "flame1"						"fire/metal"}
		{link_sound 		"action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid"		"weapon/shot/cannon/s1/d2/Shared/Cannon_37to40mm/"}
		{link_sound 		"Cannon_Far"		"weapon/shot/cannon/s1/d3/Shared/Cannon_37to40mm/"}
		{link_sound		"MG_Mid"		"weapon/shot/smallarms/s3/d2/Shared/MAC1931/"}
		{link_sound		"MG_Far"		"weapon/shot/smallarms/s3/d3/Shared/MAC1931/"}
		{volumes "aux_turret1_xx" disable bullet blast}
		{volumes "towing_xx" disable bullet blast}
		{delay 1.5
			{if "engine_on"
				{delay 2.5
					{ani_play "spin_hatch" loop}
					{ani_play "fan_spin" loop}
				}
			}
		}
	}
	{on "_explosion" overload
		{add_view "fire_vehicle_death" "fire" "fxfire4"}
		{add_view "smoke_dead_turret" "smoke" "fxfire4"}
		{spawn "tank_die_heavy"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 8 heating 10}
		{able minimap 0}
		{able select 0}
		{able repaired 0}
		{tags add "ammo_cooked"}
		{tags add "no_scavenge"}
		{call "engine_off"}
		{clear_inventory}
		{view start "fire"}
		{stop_sound "flame1"}
		{stop_sound "flame2"}
		{stop_sound "flame3"}
		{stop_sound "flame4"}
		{stop_sound "flame5"}
		{stop_sound "flame6"}
		{stop_sound "flame7"}
		{set_skeleton "_xx"}
           	{ani_play "death"}
          	{call "cut_parts"}
		{bone hide "towing"}
		{bone hide "aux_turret1"}
		{bone hide "gunner_cupola"}
		{bone hide "mgun4_rot1"}
		{bone hide "mgun3"}
		{tear "piece_medium_steel" bone "turret" id "turret"
			{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			{delay_effect 20 5 "stop"}			;// calls {on "stop"} in dummy.inc
			{delay 0.1
				{volumes "gun" disable obstacle}
			}
		}
		{spawn "crater_massive" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
		{delay 500 60
			{view pause "fire"}
			{view start "smoke"}
			{stop_sound "flame1"}
			{view pause "sparks1"}
			{view pause "sparks2"}
			{view pause "smoke_ex1"}
			{view pause "smoke_ex2"}
		}
	}
	{on "explosion_blastwave" overload
		{start_sound "detonation/he_size5/bkg/"}
		{blastwave c4 45 r0 2.6 r1 5.2}
		{blastwave c4 15.85 r0 5.85 r1 18.85}
		{blastwave c4 1.538 r0 18.72 r1 30.08}
		{set_skeleton "_xx"}
           	{ani_play "death"}
          	{call "cut_parts"}
		{spawn "shockwave_sphere"}
		{spawn "ex_he_size6"}

		{spawn "crater_massive" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
		{view pause "sparks1"}
		{view pause "sparks2"}
		{view pause "smoke_ex1"}
		{view pause "smoke_ex2"}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{call "kill_gunner5"}
				{ani_play "turret_aux_b"}
			}
			{if component "engine"
				{ani_play "engine_b"}
			}
			{if component "body"
				{ani_play "body_b"}
			}
			{if component "turret"
				{ani_play "turret_b"}
			}
			{if component "gun"
				{ani_play "gun_b"}
			}
		}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun4" 1}
		else
			{weapon_work "mgun4" 0}
		}
		{inherited}
	}
	{on "engine_on"
		{delay 2.5
			{ani_play "spin_hatch" loop}
			{ani_play "fan_spin" loop}
		}
	}
	{on "engine_off"
		{ani_play "spin_hatch"}
		{ani_play "fan_spin"}
	}
	{on repair
		{if work "fuel_tank1"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank2"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank3"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank4"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank5"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank6"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank7"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "gun"
			{ani_play "gun_r"}
		}
		{if work "turret"
			{ani_play "turret_r"}
		}
		{if work "body"
			{ani_play "body_r"}
		}
		{if work "engine"
			{ani_play "engine_r"}
		}
		{if work "aux_turret1"
			{ani_play "turret_aux_r"}
		}
	}
	{on operatable off
		{ani_play "spin_hatch" +1.0 resume}
	}
	{on operatable on
		{if "engine_on"
			{delay 2.5
				{ani_play "spin_hatch" loop}
			}
		}
	}
}

{"char_2c_bis_armored tank"
	("char_b1_sound")
	{on spawn
		{link_sound "flame1"						"fire/metal"}
		{link_sound 		"action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Cannon/"}
		{link_sound	 	"Cannon_Mid"		"weapon/shot/cannon/s1/d2/Shared/Cannon_37to40mm/"}
		{link_sound 		"Cannon_Far"		"weapon/shot/cannon/s1/d3/Shared/Cannon_37to40mm/"}
		{link_sound		"MG_Mid"		"weapon/shot/smallarms/s3/d2/Shared/MAC1931/"}
		{link_sound		"MG_Far"		"weapon/shot/smallarms/s3/d3/Shared/MAC1931/"}
		{volumes "aux_turret1_xx" disable bullet blast}
		{volumes "towing_xx" disable bullet blast}
		{delay 1.5
			{if "engine_on"
				{delay 2.5
					{ani_play "spin_hatch" loop}
					{ani_play "fan_spin" loop}
				}
			}
		}
	}
	{on "_explosion" overload
		{add_view "fire_vehicle_death" "fire" "fxfire4"}
		{add_view "smoke_dead_turret" "smoke" "fxfire4"}
		{spawn "tank_die_heavy"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 8 heating 10}
		{able minimap 0}
		{able select 0}
		{able repaired 0}
		{tags add "ammo_cooked"}
		{tags add "no_scavenge"}
		{call "engine_off"}
		{clear_inventory}
		{view start "fire"}
		{stop_sound "flame1"}
		{stop_sound "flame2"}
		{stop_sound "flame3"}
		{stop_sound "flame4"}
		{stop_sound "flame5"}
		{stop_sound "flame6"}
		{stop_sound "flame7"}
		{set_skeleton "_xx"}
           	{ani_play "death"}
          	{call "cut_parts"}
		{bone hide "towing"}
		{bone hide "aux_turret1"}
		{bone hide "gunner_cupola"}
		{bone hide "mgun4_rot1"}
		{bone hide "mgun3"}
		{tear "piece_medium_steel" bone "turret" id "turret"
			{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			{delay_effect 20 5 "stop"}			;// calls {on "stop"} in dummy.inc
			{delay 0.1
				{volumes "gun" disable obstacle}
			}
		}
		{spawn "crater_massive" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
		{delay 500 60
			{view pause "fire"}
			{view start "smoke"}
			{stop_sound "flame1"}
			{view pause "sparks1"}
			{view pause "sparks2"}
			{view pause "smoke_ex1"}
			{view pause "smoke_ex2"}
		}
	}
	{on "explosion_blastwave" overload
		{start_sound "detonation/he_size5/bkg/"}
		{blastwave c4 45 r0 2.6 r1 5.2}
		{blastwave c4 15.85 r0 5.85 r1 18.85}
		{blastwave c4 1.538 r0 18.72 r1 30.08}
		{set_skeleton "_xx"}
           	{ani_play "death"}
          	{call "cut_parts"}
		{spawn "shockwave_sphere"}
		{spawn "ex_he_size6"}

		{spawn "crater_massive" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
		{view pause "sparks1"}
		{view pause "sparks2"}
		{view pause "smoke_ex1"}
		{view pause "smoke_ex2"}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{call "kill_gunner5"}
				{ani_play "turret_aux_b"}
			}
			{if component "engine"
				{ani_play "engine_b"}
			}
			{if component "body"
				{ani_play "body_b"}
			}
			{if component "turret"
				{ani_play "turret_b"}
			}
			{if component "gun"
				{ani_play "gun_b"}
			}
		}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun4" 1}
		else
			{weapon_work "mgun4" 0}
		}
		{inherited}
	}
	{on "engine_on"
		{delay 2.5
			{ani_play "spin_hatch" loop}
			{ani_play "fan_spin" loop}
		}
	}
	{on "engine_off"
		{ani_play "spin_hatch"}
		{ani_play "fan_spin"}
	}
	{on repair
		{if work "fuel_tank1"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank2"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank3"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank4"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank5"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank6"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "fuel_tank7"
			{if tagged "fueltank_fire_count1"
        		{tags remove "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count2"
                	{tags remove "fueltank_fire_count2"}
			{tags add "fueltank_fire_count1"}
        	else tagged "fueltank_fire_count3"
                	{tags remove "fueltank_fire_count3"}
			{tags add "fueltank_fire_count2"}
        	else tagged "fueltank_fire_count4"
			{tags remove "fueltank_fire_count4"}
			{tags add "fueltank_fire_count3"}
		else tagged "fueltank_fire_count5"
			{tags remove "fueltank_fire_count5"}
			{tags add "fueltank_fire_count4"}
			}
			{tags remove "fueltank_fire1"}
			{tags remove "fueltank_fire2"}
			{tags remove "fueltank_fire3"}
			{tags remove "fueltank_fire4"}
			{tags remove "fueltank_fire5"}
			{tags remove "fueltank_fire6"}
			{tags remove "fueltank_fire7"}
		}
		{if work "gun"
			{ani_play "gun_r"}
		}
		{if work "turret"
			{ani_play "turret_r"}
		}
		{if work "body"
			{ani_play "body_r"}
		}
		{if work "engine"
			{ani_play "engine_r"}
		}
		{if work "aux_turret1"
			{ani_play "turret_aux_r"}
		}
	}
	{on operatable off
		{ani_play "spin_hatch" +1.0 resume}
	}
	{on operatable on
		{if "engine_on"
			{delay 2.5
				{ani_play "spin_hatch" loop}
			}
		}
	}
	{on pierce
		{if volume "shield_commander"
			{if rand 0.5
				{call "kill_commander"}
			}
		}
	}
}

{"b1_ter tank"
("char_b1_sound")
	{on "add_weapon_sound" overload
		("MAC31")
		("Cannon_45to47mm")
	}
	("repair_anm_script_v1")
	{on "pre_cookoff"
		{tear "piece_medium_steel" bone "turret_top"
                		{impulse up 5.5 rnd_dir 2}
            	}
	}
}
	

{"amd35_sa35"
	("sdkfz234_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("DT")
	}
	("repair_anm_script_v1")
}

{"lorraine_37l"
	("sdkfz234_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.45 0.35)
	}
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("Cannon_Breech")
	}
	("repair_anm_script_v1")
}

{"amc34_yr"
	("somua_s35_sound")
	{on "add_weapon_sound" overload
		("MAC31")
		("Cannon_37to40mm")
	}
	("repair_anm_script_v1")
	{on "pre_cookoff"
		{tear "piece_medium_steel" bone "kaboom"
                		{impulse up 5.5 rnd_dir 2}
            	}
	} 
}	

{"d2 tank"
	("somua_s35_sound")
	{on "add_weapon_sound" overload
		("MAC31")
		("Cannon_37to40mm")
	}
	{on spawn
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight5"}
	}
	("repair_anm_script_v1")
	{on "pre_cookoff"
		{tear "piece_medium_steel" bone "cupola"
                		{impulse up 5.5 rnd_dir 2}
            	}
	}
	{on "update_lights"
		{if not sunlight					;// checks if night time to show headlight fx
			{if "engine_on"
				{ani_play "open_lights" +1 resume}
			}
		}
	}
	{on fire "mgun" 
        	{view start "fire_gun2"}
		{delay 0.2
			{view pause "fire_gun2"}
		}
    	} 
}

{"arl_44 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("MAC31")
		("Cannon_85to100mm")
	}
	{on spawn
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight4"}
    	}
	{on fire "mgun3" 
        {view start "fire_gun2"}
	{delay 0.5
		{view pause "fire_gun2"}
	}
	}
	{on "cut_parts"
		("cut_part" args "ex_armor_01_5" 1)
		("cut_part" args "ex_armor_02_6" 1)
		("cut_part" args "shieldr5" 1)
	}
}

{"arl_44_acl1"
	("is_sound")
	{on spawn
		{add_view "flash_gun_hmg_m2hb" "fire_gun2" "foresight4"}
    	}
	{on "add_weapon_sound" overload
		("MAC31")
		("Cannon_75to76mm")
	}
	{on fire "mgun3" 
        {view start "fire_gun2"}
	{delay 0.5
		{view pause "fire_gun2"}
	}
	}
	("repair_anm_script_v1")
}

{"panzerb2_fra tank"
	("char_b1_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		{link_sound		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound		"Cannon_Mid2"			"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm_LV/"}
		{link_sound		"Cannon_Far2"			"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm_LV/"}
		("MAC31")
	}
}

{"panzer35s_fra tank"
	("somua_s35_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("MAC31")
	}
}

{"p204_f_fra tank"
	("sdkfz234_sound") ;Placeholder
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MAC31")
	}
}

{"panzer5g_fra tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("MG34")
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

;/*=========== ENG Vehicles Begin ===========*/

{"humber_command"
	("humber_sound")
}

{"humber_scout_command"
	("humber_sound")
}

{"sherman2_skink tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	("repair_anm_script_skink")
}

{"comet1_a34_shield tank"
	("cromwell_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("ZB37")
	}
	{on "cut_parts" 
		("cut_part" args "shield_front" 0.5)
		{inherited}
	}
}

{"ram_kangaroo_mk2_badger tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
		{add_view "flamer_fire_tank" "gun" "foresight1"}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun1" 1}
		else
			{weapon_work "mgun1" 0}
		}
		{inherited}
	}
	{on "spawn_no_crew" overload
		{ani_wind "open_driver" end}
	}
	;{on "spawn_with_crew" overload}

	{on "driver_hatch_open" overload
		{ani_play "open_driver" -1.0 resume}
	}
	{on operatable off
		{ani_play "open_driver" resume}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 80 1 40)
}

{"matilda2_mk2_frog tank"
	("matilda_mk2_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	{on spawn
		{add_view "flamer_fire_tank" "gun" "foresight1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 60 1 40)
}

{"churchill_na75 tank"
	("churchill_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("ZB37")
		("M1919A4")
	}
}

{"ram_mki tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun1" 1}
		else
			{weapon_work "mgun1" 0}
		}
		{inherited}
	}
	{on "spawn_no_crew" overload
		{ani_wind "open_driver" end}
	}
	;{on "spawn_with_crew" overload}

	{on "driver_hatch_open" overload
		{ani_play "open_driver" -1.0 resume}
	}
	{on operatable off
		{ani_play "open_driver" resume}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{call "kill_gunner3"}
			}
		}
	}
}

{"ram_mkii tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun1" 1}
		else
			{weapon_work "mgun1" 0}
		}
		{inherited}
	}
	{on "spawn_no_crew" overload
		{ani_wind "open_driver" end}
	}
	;{on "spawn_with_crew" overload}

	{on "driver_hatch_open" overload
		{ani_play "open_driver" -1.0 resume}
	}
	{on operatable off
		{ani_play "open_driver" resume}
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{call "kill_gunner3"}
			}
		}
	}
}

{"m7_kangaroo tank"
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/M4_Sherman/start"}
		{link_sound "engine_stop"		"vehicle/engine/M4_Sherman/stop"}
		{link_sound "engine_idle"		"vehicle/engine/M4_Sherman/idle"}
		{link_sound "engine_full"		"vehicle/engine/M4_Sherman/full"}
		{link_sound "exhaust"			"vehicle/engine/M4_Sherman/exhaust"}
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
}

{"universal_carrier_mkii_m2hb tank"
	("universal_carrier_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}

{"t_14_105 tank"
	("m4a2_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_50to57mm_HV")
	}
	{on spawn
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
		{add_view	"shell_hmgun"	"mgun_eject1"	"mgun_shell_eject"}
   	}
	("repair_anm_script_v1")
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
		{ani_play "open_mgun" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
		{ani_play "open_mgun" -1.0 resume}
	}
	{on fire "gun"
		{ani_play "fire_105" +1}
		{ani_play "recoil_105" +0.7}
    }
	{on fire "mgun3"
		{ani_play "fire_mgun" +1.5}
		{view start "mgun_eject1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
    }	
	{on fire "mgun2"
		{ani_play "fire_mgun_h" +1.5}
    }	
}

{"t_14_17pdr tank"
	("m4a2_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
		("M1919A4")
		("Cannon_75to76mm_HV")
	}
	{on spawn
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
		{add_view	"shell_hmgun"	"mgun_eject1"	"mgun_shell_eject"}
   	}
	("repair_anm_script_v1")
	{on "commander_hatch_open" overload
		{ani_play "open_commander" +1.0 resume}
		{ani_play "open_mgun" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_commander" -1.0 resume}
		{ani_play "open_mgun" -1.0 resume}
	}
	{on fire "gun"
		{ani_play "fire_105" +1}
		{ani_play "recoil_17" +0.7}
    }
	{on fire "mgun3"
		{ani_play "fire_mgun" +1.5}
		{view start "mgun_eject1"}
		{delay 0.2
			{view pause "mgun_eject1"}
		}
    }	
}

{"churchill_mk4_7_avre_croc tank"
	("churchill_sound")
	{on "add_weapon_sound" overload
		{link_sound	 		"Cannon_Mid"			"weapon/shot/reactive/d2/ENG/230mm_Petard/"}
		("ZB37")
	}
	{on spawn
		{add_view "flamer_fire_croc" "flamer1" "foresight4"}
	}
	{on fire "gun"
		{volumes "shell" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
	}
	{on "reload"
		{if name "gun"
			{delay 7.7
				{ani_play "reload" 1.0}
			}
			{delay 15										;// Delay set to match reload time of main weapon
				{volumes "shell" enable bullet blast}
			}
		}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "rocket"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
			}
		}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon_1x_shot" args flamer1 80 4 45)
}

{"churchill_mk4_avre_snake tank"
	("54mm_bangalore_script")
	("churchill_sound")
	{on "add_weapon_sound" overload
		{link_sound 		"Cannon_Far2"			"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm_LV/"}
		{link_sound	 		"Cannon_Mid"			"weapon/shot/reactive/d2/ENG/230mm_Petard/"}
		("ZB37")
	}
	{on spawn
		{link_sound 		"bangalore_reload"		"weapon/reload/tank/bangalore_reload"}
		{tags add "ammo0"}
		{add_view	"recoilless_shot_forward"	"flashrocket0"			"flashbarrel_end0"}
		{add_view	"recoilless_shot_forward"	"flashrocket1"			"flashbarrel_end1"}
		{add_view	"recoilless_shot_forward"	"flashrocket2"			"flashbarrel_end2"}
		{add_view	"recoilless_shot_forward"	"flashrocket3"			"flashbarrel_end3"}
		{add_view	"recoilless_shot_forward"	"flashrocket4"			"flashbarrel_end4"}
		{add_view	"recoilless_shot_forward"	"flashrocket5"			"flashbarrel_end5"}
		{add_view	"recoilless_shot_forward"	"flashrocket7"			"flashbarrel_end6"}
		{add_view	"recoilless_shot_forward"	"flashrocket7"			"flashbarrel_end7"}
		{add_view	"recoilless_shot_forward"	"flashrocket8"			"flashbarrel_end8"}
		{add_view	"recoilless_shot_forward"	"flashrocket9"			"flashbarrel_end9"}
		{add_view	"recoilless_shot_forward"	"flashrocket10"			"flashbarrel_end10"}
		{add_view	"recoilless_shot_forward"	"flashrocket11"			"flashbarrel_end11"}
		{add_view	"recoilless_shot_forward"	"flashrocket12"			"flashbarrel_end12"}
		{add_view	"recoilless_shot_forward"	"flashrocket13"			"flashbarrel_end13"}
		{add_view	"recoilless_shot_forward"	"flashrocket14"			"flashbarrel_end14"}
		{add_view	"recoilless_shot_forward"	"flashrocket15"			"flashbarrel_end15"}

		{add_view	"recoilless_shot_forward"	"flashrocketrear0"			"flashbarrel_start0"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear1"			"flashbarrel_start1"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear2"			"flashbarrel_start2"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear3"			"flashbarrel_start3"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear4"			"flashbarrel_start4"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear5"			"flashbarrel_start5"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear7"			"flashbarrel_start6"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear7"			"flashbarrel_start7"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear8"			"flashbarrel_start8"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear9"			"flashbarrel_start9"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear10"			"flashbarrel_start10"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear11"			"flashbarrel_start11"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear12"			"flashbarrel_start12"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear13"			"flashbarrel_start13"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear14"			"flashbarrel_start14"}
		{add_view	"recoilless_shot_forward"	"flashrocketrear15"			"flashbarrel_start15"}
	}
	{on fire "gun"
		{volumes "shell" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
	}
	{on "reload" 
		{if name "gun"
			{delay 7.7
				{ani_play "reload" 1.0}
			}
			{delay 15										;// Delay set to match reload time of main weapon
				{volumes "shell" enable bullet blast}
			}
		}
		{if name "explosive"
			{play_sound "bangalore_reload"}
			("reset_ammo_tags")
			{delay 179.5
				("all_rocket" state(show))
			}
		}	
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "rocket"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
			}
		}
	}
}

{"churchill_mk1_fm tank"
	("churchill_sound")
	{on spawn
		("rand_cut" args "basket2")
		{add_view "tank_canon_fire_75_76"                "flashbarrelmedium_2"        "Foresight1a"}
	}
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound	 		"Cannon_Mid2"			"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm_LV/"}
		{link_sound 		"Cannon_Far2"			"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm_LV/"}
		("ZB37")
	}
	{on fire "gun"
        {view start "flashbarrelmedium_2"}
        {play_sound "action_recoil_Cannon"}
        {play_sound "Cannon_Mid"}
        {play_sound "Cannon_Far"}
        {call "medium_terrain_fx"}
    }
	{on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	("multi_gun_rotate" args gun1_rot)
}

{"valentine_mk1_flame tank"
	("valentine_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
	}
	{on spawn
		{add_view "flamer_fire_tank"	"flamer1"	"foresight4"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 4 45)
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "flamer1" 1}
		else
			{weapon_work "flamer1" 0}
		}
		{inherited}
	}
	{on "cut_parts" 
		("cut_part" args "aux_turret1_xx" 1)
		{inherited}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "aux_turret1"
				{ani_play "turret1_b" +1}
			}
		}
	}	
	{on repair
		{if not tagged "exploded"
			{if component "aux_turret1"
				{ani_play "turret1_r" +1}
			}	
		}
	}	
}
{"staghound_mk1_tulip"
	("staghound_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("M1919A4")
		{link_sound		"bkg_rocket"		"weapon/reactive/d2/ENG/Land_Mattress/"}
	}
	{on fire "rocket"
		{play_sound "bkg_rocket"}
	}
}
{"valentine_mk10_mortar tank"
	("valentine_sound")
	{on spawn
		{add_view	"tank_canon_fire_spigot"	"flashbarrel00"	"foresight"}
		{link_sound "bkg_cannon_huge"	"weapon/shot/bkg/cannon/huge/"}
	}
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "gun"
				{ani_play "gun_b" +1}
			}
		}
	}	
	{on repair
		{if not tagged "exploded"
			{if component "gun"
				{ani_play "gun_r" +1}
			}	
		}
	}
	{on fire "gun" 
		{play_sound "bkg_cannon_huge"}
		{view start "flashbarrel00"}
		{delay 0.2
			{view pause "flashbarrel00"}
		}
	}
}
{"churchill_mk1_arv tank"
	("churchill_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{add_view	"repair"		"repair"	"hearing_bone"}
		{tags add "ai_engineer_vehicle"}
		{link_sound "screw_twist"		"human/anims/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anims/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anims/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anims/repair/toolbox_close/"}
		{link_sound "tool_equip"		"human/anims/repair/tool_equip/"}
	}
	{on "add_weapon_sound" overload
		("ZB37")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open_gunner" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_gunner" -1.0 resume}
	}
	{on "reload"
		{delay 1
			{tear "piece_small_steel" bone "magazine1" copy
				{volumes disable bullet blast}				;// prevent destroing at spawn moment
				{impulse dir 2 fz -5 fx 5.5 }
			}
			{delay 0.1
				{bone hide "magazine1"}
			}
		}
		{delay 3.5
			{tear "piece_small_steel" bone "magazine2" copy
				{volumes disable bullet blast}				;// prevent destroing at spawn moment
				{impulse dir 2 fz -5 fx 5.5 }
			}
			{delay 0.1
				{bone hide "magazine2"}
			}
		}		
		{delay 5.5
			{bone show "magazine1"}
			{volumes enable bullet blast}				;// prevent destroing at spawn moment
		}
		{delay 7.5
			{bone show "magazine2"}
			{volumes enable bullet blast}				;// prevent destroing at spawn moment
		}
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
	{on break
		{if not tagged "exploded"
			{if component "trackright"
				{tags add "major_broken1"}
				{tags add "major_broken"}
			else component "trackleft"
				{tags add "major_broken2"}
				{tags add "major_broken"}
			else component "engine"
				{tags add "major_broken3"}
				{tags add "major_broken"}
			}
		}
    }
	{on repair
		{if not tagged "exploded"
			{if component "trackleft"
			 	{tags remove "major_broken2"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken3"
					{tags remove "major_broken"}
				}
			}	
			{if component "trackright"
			 	{tags remove "major_broken1"}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken3"
					{tags remove "major_broken"}
				}
			}
			{if component "engine"
			 	{tags remove "major_broken3"}
				{if not tagged "major_broken1"
					{tags remove "major_broken"}
				}
				{if not tagged "major_broken2"
					{tags remove "major_broken"}
				}
			}
		}
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
		{delay 40
			{if operatable
				{if not tagged "major_broken"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{chassis_work 1}
						{call "engine_on"}
					}
				}	
				{if tagged "major_broken1"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}
				}	
				{if tagged "major_broken2"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}
				}	
				{if tagged "major_broken3"
					{spawn "recovery_repair_area" "basis"}
					{spawn "recovery_repair_remover" "basis"}
					{delay 1
						{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Complete"}
						{view pause "repair"} 
						{call "engine_on"}
					}
					{delay 1.5
						{chassis_work 0}
					}	
				}
				{if not operatable
					{spawn "recovery_repair_remover_effect" "basis"}
					{damage_report "recovery_message_stop" "<c(f3ff00)>Repairs Failed"}
					{view pause "repair"} 
					{chassis_work 1}
					{call "engine_on"}
				}		
			}	
		}	
	}
}
{"churchill_mk3_aggie tank"
	("churchill_sound")
	{on "add_weapon_sound" overload
		{link_sound	 		"Cannon_Mid"			"weapon/shot/reactive/d2/ENG/230mm_Petard/"}
		("ZB37")
	}

	{on fire "gun"
		{tear "piece_large_steel" bone "cork" copy
			{impulse forward -30 }
		}
		{delay 0.1
			{bone hide "cork"}
			{volumes "shell" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
		}
	}
	{on "reload"
		{if name "gun"
			{delay 2.5
				{ani_play "reload" 1.0}
			}
			{delay 24										;// Delay set to match reload time of main weapon
				{volumes "shell" enable bullet blast contact}
				{bone show "cork"}
			}
		}
	}

	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "rocket"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
			}
		}
	}
}
{"churchill_3inch tank"
	("churchill_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
	}
}
{"churchill_mk2_oke tank"
	("churchill_sound")
	{on spawn
		("rand_cut" args "basket2")
		{add_view "flamer_fire_tank" "flamer1" "foresight7"}
		{add_view	"smoke_vehicle_death"	"smoke_vehicle_death_beetle"			"fueltank"}
	}
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound	 		"Cannon_Mid2"			"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm_LV/"}
		{link_sound 		"Cannon_Far2"			"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm_LV/"}
		("ZB37")
	}
	("multi_gun_rotate" args gun1_rot)
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 7 45)
}
{"churchill_mk3_company tank"
	("churchill_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("ZB37")
	}
}
{"churchill_mk7_avr tank"
	("churchill_sound")
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("ZB37")
	}
}
{"alecto"
	("tetrarch_sound")
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
		("Cannon_Breech")
	}
}
{"alecto_95mm"
	("tetrarch_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
}
{"alecto_25pdr"
	("tetrarch_sound")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
}

{"vickers_mk6a"
	("light_mk_sound")
	{on "add_weapon_sound" overload
		("Vickers")
	}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun" overload
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

{"tetrarch_mk7_cs"
	("tetrarch_sound")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("ZB37")
	}
}

{"churchill_mk2_cs tank"
	("churchill_sound")
	{on spawn
		("rand_cut" args "basket2")
	}
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		{link_sound 		"action_recoil_Cannon2"	"weapon/shot/cannon/s2/recoil/Shared/Cannon/"}
		{link_sound	 		"Cannon_Mid2"			"weapon/shot/cannon/s3/d2/Shared/Cannon_75to76mm_LV/"}
		{link_sound 		"Cannon_Far2"			"weapon/shot/cannon/s3/d3/Shared/Cannon_75to76mm_LV/"}
		("ZB37")
	}
	("multi_gun_rotate" args gun1_rot)
}

{"matilda2_mk3_hedgehog tank"
	("matilda_mk2_sound")
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("ZB37")
	}
	("multi_barrel_loop_hedgehog" smoke(tank_canon_fire_75_76))
}