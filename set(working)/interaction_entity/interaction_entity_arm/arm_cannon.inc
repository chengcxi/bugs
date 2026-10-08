;;============================================== GER ==================================================
;;============================================== GER cannons ==========================================

{"flak38_stand" 
	{on "add_weapon_sound" overload
		("2cm_Flakvierling")
	}
	("multi_barrel_loop" flash(tank_canon_fire_20_25_auto) smoke(smoke_zenit) shell(zenit_gilz) weapon(gun) head(0.200))

	{on "reload"
		{ani_play "reload" 1.0}
	}
	{on "reload_delay" overload
		("reload_time" args 9)		;// weapon reload time
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 0.75)
		("cut_part" args "part2" 0.75)
		("cut_part" args "part3" 0.75)
		("cut_part" args "part4" 0.75)
		("cut_part" args "shield1" 0.6)
		("cut_part" args "shield2" 0.6)
		("cut_part" args "shield3" 0.6)
		("cut_part" args "shield4" 0.6)
		("cut_part" args "shield6" 0.6)
		("cut_part" args "turret" 0.6)
		{inherited}
	}

	("cannon_small")
}

;----------------------------------------------- 105mm_flak38
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

;;----------------------------------------------- 75mm_pak41
{"76mm_pak36r"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}
	{on "reload_delay" overload
		("reload_time" args 4)
	}
	
	("cannon_small")
}

;;----------------------------------------------- 75mm_pak41
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

;;----------------------------------------------- 9cm_flak41i
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

;;----------------------------------------------- 28cm_wkspr_stan
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

;;----------------------------------------------- solothurn_s18_100
{"solothurn_s18_100"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	{on fire "gun" 
		{delay 0.1
			{spawn "shell_cannon" "fx_invers_custom" x scale 0.3
				{impulse forward 4 0.5 rnd_dir 0.1 0.1 cz 0.2 0.1 com}
				{add_view "smoke_empty_shell" "smoke_shell" "fx_shellsmoke"}
				{view start "smoke_shell"}
				{delay_effect 3 1 "stop"}
			}
		}
	}
	{on operatable off
		{ani_play "open" -1.0 }
	}
	{on operatable on
		{ani_play "open" 1.0 }
	}
	{on animation_event "close" overload		;// event called on frame 1 of "close" animation
		{if not tagged "transition"
			{tags add "transition"}
		else
			{tags remove "transition"}
			{ani_play "open" 1}
		}
		{call "body_check"}
	}
	{on "reload"
		{ani_play "reload" +0.5 resume}
		{view hide "ammo1"}
		{view hide "ammo2"}
		{delay 3.5
			{view show "ammo1"}
			{view show "ammo2"}
		}
	}
	("magazine" cut(0.6) show(2.7) override(overload) impulse({impulse up 0.3 forward 1.9 0.2}))
	("repair_anm_script_v1")
}

;;============================================== GER cannons STATIC ==================================================

{"mg34_tripod_stand"
	{on "add_weapon_sound"
		("M1919A4")
	}
}

{"mg42_tripod_stand"
	{on "add_weapon_sound"
		("M1919A4")
	}
}

{"panzernest_krab_stand"
	{on animation_event "close" overload		;// event called on frame 1 of "close" animation
		{if tagged "transition"
			{tags remove "transition"}
		else
			{tags add "transition"}
		}
		{call "body_check"}
	}

	{on animation_event "open"		;// event called on last frame of "close" animation
		{if tagged "transition"
			{tags remove "transition"}
		else
			{tags add "transition"}
		}
		{call "body_check"}
		
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}

	{on "body_check"				;// ables for all wheel volumes
		{if tagged "transition"
			{volumes "anim_no_contact" disable contact}
		else
			{volumes "anim_no_contact" enable contact}
		}
	}
	
	{on "cut_parts" overload
		("cut_part" args "wheelL" 1)
		("cut_part" args "wheelR" 1)
		{inherited}
	}
}


{"80mm_sgrw34_stand"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

{"120mm_sgrw42_stand"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
}

{"75mm_pak9738_late_stand"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}

	("cannon_small")
}

;;---------------------------------------------- 105mm_flak38_stat
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

;;---------------------------------------------- 50mm_flak41_bunker_stand
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

;;---------------------------------------------- 37mm_flak37_stand
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

;;---------------------------------------------- 50mm_flak41_stand
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

;;---------------------------------------------- 75mm_pak40_stand
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

;;---------------------------------------------- 88mm_flak18_stand
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

;;---------------------------------------------- 105mm_flak38_stand
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

;;---------------------------------------------- 105mm_lefh18_stand
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

;;============================================== GER cannons BOT ==================================================

;;---------------------------------------------- 88mm_flak18_bot
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

;;============================================== USSR =================================================
;;============================================== USSR cannons =========================================

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

;;============================================== USSR cannons STATIC ==================================

{"dt_tripod_stand"
	{on "add_weapon_sound"
		("M1919A4")
	}
}

{"120mm_pm38_stand"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
}

{"maxim_x4_stand"
	{on "init_gun" overload
		{add_view "shell_mgun" "shell1" "fxshell1"}
		{add_view "shell_mgun" "shell2" "fxshell2"}
		{add_view "shell_mgun" "shell3" "fxshell3"}
		{add_view "shell_mgun" "shell4" "fxshell4"}
		{add_view "ejectsmoke_big" "ejectsmoke1" "FXshell1"}
		{add_view "ejectsmoke_big" "ejectsmoke2" "FXshell2"}
		{add_view "ejectsmoke_big" "ejectsmoke3" "FXshell3"}
		{add_view "ejectsmoke_big" "ejectsmoke4" "FXshell4"}
		{add_view "flash_gun_big" "flashbarrel00" "shooter00"}
		{add_view "flash_gun_big" "flashbarrel01" "shooter01"}
		{add_view "flash_gun_big" "flashbarrel02" "shooter02"}
		{add_view "flash_gun_big" "flashbarrel03" "shooter03"}
	}
	{on fire "mgun1" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{delay 0.2 "fire"
					{view pause "flashbarrel%0"}
				}
				{play_sound "MG_Mid"}
				{play_sound "MG_Far"}
				{play_sound "action_recoil"}
				{kill_delay "shell_off%1"}
				{view start "shell%1"}
				{view start "ejectsmoke%1"}
				{delay 0.12 "shell_off%1"
					{view pause "shell%1"}
					{view pause "ejectsmoke%1"}
				}
		)
		{if	("fire_barrel" args 00 1)
		else ("fire_barrel" args 01 2)
		else ("fire_barrel" args 02 3)
		else ("fire_barrel" args 03 4)
		}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
}

;;---------------------------------------------- 300mm_m30_stand
{"300mm_m30_stand"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_curved_heap" "sandbag")
	}
}

;;---------------------------------------------- 37mm_61k_stand
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

;;---------------------------------------------- 85mm_52k_stand
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

;;---------------------------------------------- 107mm_m1910_30_stand
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

;;---------------------------------------------- 122mm_m30_stand
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

;;---------------------------------------------- 122mm_m1910_stand
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

;;---------------------------------------------- 203mm_b4_stand
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

;;---------------------------------------------- dshk_aa_stand
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

;;---------------------------------------------- 100mm_bs3_stand
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
 
;;---------------------------------------------- 76mm_m1938_stand
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

;;============================================== USSR cannons BOT ==================================================

;;---------------------------------------------- 85mm_52k_bot
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

;;---------------------------------------------- 82mm_bm37_ai
{"82mm_bm37_ai"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

;;============================================== FIN ===============================================================
;;============================================== FIN cannons =======================================================
;;============================================== FIN cannons STATIC ================================================

{"ds39_fin_stand"
	{on "add_weapon_sound" overload
		("DS39")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
	}
}

;;---------------------------------------------- 20mm_itk40_stand
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

;;---------------------------------------------- 20mm_itk35_stand
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

;;---------------------------------------------- 40mm_itk38b_stand
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

{"50mm_krh38_stand"
	{on "add_weapon_sound" overload
		("Mortar_5-6cm")
	}
}

;;---------------------------------------------- 75mm_itk37_stand
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

;;---------------------------------------------- 75mm_itk44_stand
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

{"76mm_itk31_stand"
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
		("cut_part" args "part7" 1)
		("cut_part" args "part9" 1)
		("cut_part" args "wheelr" 1)
		("cut_part" args "wheell" 1)
		("cut_part" args "trailer" 1)
		{inherited}
	}

	("cannon_big")
}

;;---------------------------------------------- 105mm_k34_stand
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

{"150mm_rkh41_stand"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	("cannon_small")

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "pa155mm_gpfrt6" 1)
		{inherited}
	}
}

;;---------------------------------------------- 155mm_h17_stand
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



;;============================================== FIN cannons BOT ================================================
;;---------------------------------------------- 75mm_itk37_bot
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

;;============================================== USA ==========================================================
;;============================================== USA cannons ==================================================
;;============================================== USA cannons STATIC ===========================================

{"50calM2_lafette_stand"
	{on "add_weapon_sound"
		("M2HB")
	}
}

{"57mm_m1_stand"
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


{"81mm_m1_stand"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

;;---------------------------------------------- 40mm_m1_stand
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

;;---------------------------------------------- 57mm_m1_late_stand
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

;;---------------------------------------------- 90mm_m1a1_stand
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

;;---------------------------------------------- 105mm_m2a1_stand
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

;;---------------------------------------------- 203mm_m1_stand
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



;;============================================== USA cannon BOT ===============================================

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

