; File: 		arm_airborne_specific.inc
; Catalog: 		resource\set\interaction_entity\interaction_entity_arm
; Created by: 	Max Drechsler
; Created:		x.xx.xxxx
; Modify by:	Max Drechsler
; Modify:		23.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		14.1
; Description: 


; ## GER
;;============================================== GER AIR ===================================
;;============================================== GER AIR recon =============================
{"ai_fi156"
	("fi156_sound")
	{on spawn
		("tag_airborne_recon_ai")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("MG15")
	}
	{on fire "mgun4" overload
		("Automatic_Weapon_Space" weapon(MG4))
	}
}

;;============================================== GER AIR fighter ===========================
{"bf109_e4b"
	("bf109_e4b_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG17")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(MG2))
	}
	{on "reload"
		{if name "bomb"
			{bone hide "bomb_00"}
		}
	}
	{on "die"
		{bone hide "bomb_00"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
}

{"bf109_e4b_ai"
	("bf109_e4b_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG17")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(MG2))
	}
	{on "reload"
		{if name "bomb"
			{bone hide "bomb_00"}
		}
	}
	{on "die"
		{bone hide "bomb_00"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
}

{"bf109_f2"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG17")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(MG2))
	}
	{on "air_attack"
		{play_sound "attack"}
	}	
}

{"bf109_f2_ai"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG17")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(MG2))
	}	
	{on "air_attack"
		{play_sound "attack"}
	}
}
{"bf109_f4"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG17")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(MG2))
	}
	{on "air_attack"
		{play_sound "attack"}
	}	
}

{"bf109_f4_ai"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG17")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(MG2))
	}
	{on "air_attack"
		{play_sound "attack"}
	}	
}


{"bf109_g6"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG131")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(HMG))
	}
	{on "air_attack"
		{play_sound "attack"}
	}	
}

{"bf109_g6_ai"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG131")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(HMG))
	}
	{on "air_attack"
		{play_sound "attack"}
	}	
}

{"bf109_g6_rocket_ai"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_ger")	
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG131")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on "die"
		{bone hide "bomb_00"}
		{bone hide "rocket_00"}
		{bone hide "rocket_01"}
		{bone hide "rocket_pylon_l"}
		{bone hide "rocket_pylon_r"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "rocket_00"}
			{bone hide "rocket_pylon_r"}
		else volume "wingl2"
			{bone hide "rocket_01"}
			{bone hide "rocket_pylon_l"}
		else volume "wingl1"
			{bone hide "rocket_01"}
			{bone hide "rocket_pylon_l"}
		else volume "wingr1"
			{bone hide "rocket_00"}
			{bone hide "rocket_pylon_r"}	
		}
	}
	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
		{if operatable
			{tags add "bomb_1"}
			{delay 1.5
				{if tagged "bomb_1"
					{spawn "sc_250" "bomb1_release"}
					{bone hide "bomb_00"}
				}		
			}	
		}
	}
}
;;============================================== GER AIR heavy fighter =====================
{"bf110_e2_rocket_ai"
	("bf110_sound")
	{on spawn
		("tag_airborne_hvfighter")
		("tag_airborne_ger")	
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG15")
		("MG17")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}

	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
		{if operatable
			{tags add "bomb_1"}
			{tags add "bomb_2"}
			{delay 0.5
				{if tagged "bomb_1"
					{spawn "sc_50" "bombl1_release"}
					{bone hide "bomb00"}
					{delay 0.5
						{spawn "sc_50" "bombl2_release"}
						{bone hide "bomb01"}
					}
				}
				{delay 0.5
					{if tagged "bomb_1"
						{spawn "sc_50" "bombr1_release"}
						{bone hide "bomb02"}
						{delay 0.5
							{spawn "sc_50" "bombr1_release"}
							{bone hide "bomb03"}
						}
					}
				}		
			}	
		}
	}	

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "air_attack"
		{play_sound "attack"}
	}

	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "rocket_pod"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb02"}
			{bone hide "bomb03"}
		else volume "wingl2"
			{bone hide "bomb00"}
			{bone hide "bomb01"}
		}
	}
}
{"bf110_e2_flam_500kg_ai"
	("bf110_sound")
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_ger")	
	}
	{on "add_weapon_sound" overload
		("MG15")
		("MG17")
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "air_attack"
		{play_sound "attack"}
	}

	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}
}
{"bf110_e2_1000kg_ai"
	("bf110_sound")
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_ger")	
	}
	{on "add_weapon_sound" overload
		("MG13")
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "air_attack"
		{play_sound "attack"}
	}

	{on "die"
		{bone hide "bomb_00"}
	}
}
{"bf110_f4"
	("bf110_sound")
	{on spawn
		("tag_airborne_hvfighter")
		("tag_airborne_ger")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG15")
		("MG17")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(MG2))
	}
	{on fire "mgun4" overload
		("Automatic_Weapon_Space" weapon(MG4))
	}
	
	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "air_attack"
		{play_sound "attack"}
	}

	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}

		{bone hide "rocket00"}
		{bone hide "rocket02"}
		{bone hide "rocket04"}
		{bone hide "rocket06"}
		{bone hide "rocket01"}
		{bone hide "rocket03"}
		{bone hide "rocket05"}
		{bone hide "rocket07"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb02"}
			{bone hide "bomb03"}
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
		else volume "wingl2"
			{bone hide "bomb00"}
			{bone hide "bomb01"}
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
		}
	}
}

{"bf110_f4_ai"
	("bf110_sound")
	{on spawn
		("tag_airborne_hvfighter_ai")
		("tag_airborne_ger")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG15")
		("MG17")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(MG2))
	}
	{on fire "mgun4" overload
		("Automatic_Weapon_Space" weapon(MG4))
	}
	
	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "air_attack"
		{play_sound "attack"}
	}

	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}

		{bone hide "rocket00"}
		{bone hide "rocket02"}
		{bone hide "rocket04"}
		{bone hide "rocket06"}
		{bone hide "rocket01"}
		{bone hide "rocket03"}
		{bone hide "rocket05"}
		{bone hide "rocket07"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb02"}
			{bone hide "bomb03"}
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
		else volume "wingl2"
			{bone hide "bomb00"}
			{bone hide "bomb01"}
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
		}
	}
}

;;============================================== GER AIR bomber ============================
{"ju-87"
	("ju87_sound")
	{on spawn
		("tag_airborne_bomber")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("MG13")
	}
	
	{on fire "gun" overload
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}

	{on "air_attack"
		{play_sound "attack"}
	}

	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "bomb_"}
	}
	
	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb02"}
			{bone hide "bomb03"}
		else volume "wingl2"
			{bone hide "bomb00"}
			{bone hide "bomb01"}
		else volume "wingr1"
			{bone hide "bomb02"}
			{bone hide "bomb03"}
		else volume "wingl1"
			{bone hide "bomb00"}
			{bone hide "bomb01"}
		}
	}
}

{"ju-87"	;backup
;//	{on "gear_disable" overload} ;// stops earlier code from disabling gear volumes. JU-87 gear does not retract.
;//
;//	{on "air_attack"
;//		{play_sound "attack"}
;//	}
;//
;//	{on "die"
;//		{bone hide "bomb00"}
;//		{bone hide "bomb01"}
;//		{bone hide "bomb02"}
;//		{bone hide "bomb03"}
;//		{bone hide "bomb_"}
;//	}
;//	{on "tear_part"
;//		{if volume "wingr2"
;//			{bone hide "bomb02"}
;//			{bone hide "bomb03"}
;//		else volume "wingl2"
;//			{bone hide "bomb00"}
;//			{bone hide "bomb01"}
;//		else volume "wingr1"
;//			{bone hide "bomb02"}
;//			{bone hide "bomb03"}
;//		else volume "wingl1"
;//			{bone hide "bomb00"}
;//			{bone hide "bomb01"}
;//		}
;//	}
;//
;//	{on "add_movement_sound" overload
;//		{link_sound "engine1_start"			"vehicle/airborne/ju87_engine_start"}
;//		{link_sound "engine1_idle"			"vehicle/airborne/ju87_engine_idle"}
;//		{link_sound "engine1_full"			"vehicle/airborne/ju87_engine_full"}
;//		{link_sound "engine_accelerate"		"vehicle/airborne/ju87_accelerate"}
;//		{link_sound "engine_decelerate"		"vehicle/airborne/ju87_decelerate"}
;//		{link_sound "engine_stop"			"vehicle/airborne/ju87_engine_stop"}
;//		{link_sound "attack"				"vehicle/airborne/ju87_dive"}
;//	}
}
{"ju-87_ai"
	("ju87_sound")
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("MG13")
	}
	
	{on fire "gun" overload
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}


	{on "air_attack"
		{play_sound "attack"}
	
	}

	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "bomb_"}
	}
	
	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb02"}
			{bone hide "bomb03"}
		else volume "wingl2"
			{bone hide "bomb00"}
			{bone hide "bomb01"}
		else volume "wingr1"
			{bone hide "bomb02"}
			{bone hide "bomb03"}
		else volume "wingl1"
			{bone hide "bomb00"}
			{bone hide "bomb01"}
		}
	}
}
{"ju87g2_ai"
	("ju87g_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	
	{on fire "gun" overload
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}

	{on "air_attack"
		{play_sound "attack"}
	
	}
}

{"bf110_e2"
	("bf110_sound")
	{on spawn
		("tag_airborne_bomber")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG15")
		("MG17")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(MG2))
	}
	{on fire "mgun4" overload
		("Automatic_Weapon_Space" weapon(MG4))
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "air_attack"
		{play_sound "attack"}
	}

	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb02"}
			{bone hide "bomb03"}
		else volume "wingl2"
			{bone hide "bomb00"}
			{bone hide "bomb01"}
		}
	}
}

{"bf110_e2_ai"
	("bf110_sound")
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_ger")
;		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("MG15")
		("MG17")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun2" overload
		("Automatic_Weapon_Space" weapon(MG2))
	}
	{on fire "mgun4" overload
		("Automatic_Weapon_Space" weapon(MG4))
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "air_attack"
		{play_sound "attack"}
	}

	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb02"}
			{bone hide "bomb03"}
		else volume "wingl2"
			{bone hide "bomb00"}
			{bone hide "bomb01"}
		}
	}
}

;;============================================== GER AIR reactive ==========================
{"me-262_a1_new"
	("me262_sound")
	{on spawn
		("tag_airborne_jet_bomber")
		("tag_airborne_ger")
		("SG43")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel02"	"shooter02"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel03"	"shooter03"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}

	{on fire "gun" overload
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
		else name "02"
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

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}
	{on "die"
		{bone hide "rocket00"}
			{bone hide "rocket01"}
			{bone hide "rocket02"}
			{bone hide "rocket03"}
			{bone hide "rocket04"}
			{bone hide "rocket05"}
			{bone hide "rocket06"}
			{bone hide "rocket07"}
			{bone hide "rocket08"}
			{bone hide "rocket09"}
			{bone hide "rocket10"}
			{bone hide "rocket11"}
			{bone hide "rocket12"}
			{bone hide "rocket13"}
			{bone hide "rocket14"}
			{bone hide "rocket15"}
			{bone hide "rocket16"}
			{bone hide "rocket17"}
			{bone hide "rocket18"}
			{bone hide "rocket19"}
			{bone hide "rocket20"}
			{bone hide "rocket21"}
			{bone hide "rocket22"}
			{bone hide "rocket23"}
			{bone hide "rocket24"}
			{bone hide "rocket25"}
			{bone hide "rocket26"}
			{bone hide "rocket27"}
			{bone hide "rocket28"}
			{bone hide "rocket29"}
			{bone hide "rocket30"}
			{bone hide "rocket31"}
			{bone hide "rocket32"}
			{bone hide "rocket33"}
			{bone hide "rocket34"}
			{bone hide "rocket35"}
			{bone hide "rocket36"}
			{bone hide "rocket37"}
			{bone hide "rocket38"}
			{bone hide "rocket39"}
			{bone hide "rocket40"}
			{bone hide "rocket41"}
			{bone hide "rocket42"}
			{bone hide "rocket43"}
			{bone hide "rocket44"}
			{bone hide "rocket45"}
			{bone hide "rocket46"}
			{bone hide "rocket47"}
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}	
		{if volume "wingr2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
			{bone hide "rocket09"}
			{bone hide "rocket11"}
			{bone hide "rocket13"}
			{bone hide "rocket15"}
			{bone hide "rocket17"}
			{bone hide "rocket19"}
			{bone hide "rocket21"}
			{bone hide "rocket23"}
			{bone hide "rocket25"}
			{bone hide "rocket27"}
			{bone hide "rocket29"}
			{bone hide "rocket31"}
			{bone hide "rocket33"}
			{bone hide "rocket35"}
			{bone hide "rocket37"}
			{bone hide "rocket39"}
			{bone hide "rocket41"}
			{bone hide "rocket43"}
			{bone hide "rocket45"}
			{bone hide "rocket47"}
			{bone hide "pylon_left"}
		else volume "wingl2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
			{bone hide "rocket08"}
			{bone hide "rocket10"}
			{bone hide "rocket12"}
			{bone hide "rocket14"}
			{bone hide "rocket16"}
			{bone hide "rocket18"}
			{bone hide "rocket20"}
			{bone hide "rocket22"}
			{bone hide "rocket24"}
			{bone hide "rocket26"}
			{bone hide "rocket28"}
			{bone hide "rocket30"}
			{bone hide "rocket32"}
			{bone hide "rocket34"}
			{bone hide "rocket36"}
			{bone hide "rocket38"}
			{bone hide "rocket40"}
			{bone hide "rocket42"}
			{bone hide "rocket44"}
			{bone hide "rocket46"}
			{bone hide "pylon_right"}
		}
	}
}
{"me-262_a1_new_ai"
	("me262_sound")
	{on spawn
		("tag_airborne_jet_bomber_ai")
		("tag_airborne_ger")
		("SG43")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel02"	"shooter02"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel03"	"shooter03"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}

	{on fire "gun" overload
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
		else name "02"
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

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "die"
		{bone hide "rocket00"}
			{bone hide "rocket01"}
			{bone hide "rocket02"}
			{bone hide "rocket03"}
			{bone hide "rocket04"}
			{bone hide "rocket05"}
			{bone hide "rocket06"}
			{bone hide "rocket07"}
			{bone hide "rocket08"}
			{bone hide "rocket09"}
			{bone hide "rocket10"}
			{bone hide "rocket11"}
			{bone hide "rocket12"}
			{bone hide "rocket13"}
			{bone hide "rocket14"}
			{bone hide "rocket15"}
			{bone hide "rocket16"}
			{bone hide "rocket17"}
			{bone hide "rocket18"}
			{bone hide "rocket19"}
			{bone hide "rocket20"}
			{bone hide "rocket21"}
			{bone hide "rocket22"}
			{bone hide "rocket23"}
			{bone hide "rocket24"}
			{bone hide "rocket25"}
			{bone hide "rocket26"}
			{bone hide "rocket27"}
			{bone hide "rocket28"}
			{bone hide "rocket29"}
			{bone hide "rocket30"}
			{bone hide "rocket31"}
			{bone hide "rocket32"}
			{bone hide "rocket33"}
			{bone hide "rocket34"}
			{bone hide "rocket35"}
			{bone hide "rocket36"}
			{bone hide "rocket37"}
			{bone hide "rocket38"}
			{bone hide "rocket39"}
			{bone hide "rocket40"}
			{bone hide "rocket41"}
			{bone hide "rocket42"}
			{bone hide "rocket43"}
			{bone hide "rocket44"}
			{bone hide "rocket45"}
			{bone hide "rocket46"}
			{bone hide "rocket47"}
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}	
		{if volume "wingr2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
			{bone hide "rocket09"}
			{bone hide "rocket11"}
			{bone hide "rocket13"}
			{bone hide "rocket15"}
			{bone hide "rocket17"}
			{bone hide "rocket19"}
			{bone hide "rocket21"}
			{bone hide "rocket23"}
			{bone hide "rocket25"}
			{bone hide "rocket27"}
			{bone hide "rocket29"}
			{bone hide "rocket31"}
			{bone hide "rocket33"}
			{bone hide "rocket35"}
			{bone hide "rocket37"}
			{bone hide "rocket39"}
			{bone hide "rocket41"}
			{bone hide "rocket43"}
			{bone hide "rocket45"}
			{bone hide "rocket47"}
			{bone hide "pylon_left"}
		else volume "wingl2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
			{bone hide "rocket08"}
			{bone hide "rocket10"}
			{bone hide "rocket12"}
			{bone hide "rocket14"}
			{bone hide "rocket16"}
			{bone hide "rocket18"}
			{bone hide "rocket20"}
			{bone hide "rocket22"}
			{bone hide "rocket24"}
			{bone hide "rocket26"}
			{bone hide "rocket28"}
			{bone hide "rocket30"}
			{bone hide "rocket32"}
			{bone hide "rocket34"}
			{bone hide "rocket36"}
			{bone hide "rocket38"}
			{bone hide "rocket40"}
			{bone hide "rocket42"}
			{bone hide "rocket44"}
			{bone hide "rocket46"}
			{bone hide "pylon_right"}
		}
	}
	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
		{if operatable
			{tags add "bomb_1"}
			{tags add "bomb_2"}
			{delay 0.5
				{if tagged "bomb_1"
					{spawn "sc_ger_500" "pivot_front"}
					{bone hide "bomb_00"}
				}
				{delay 1
					{if tagged "bomb_2"
						{spawn "sc_ger_500" "pivot_front"}
						{bone hide "bomb_01"}
					}
				}		
			}	
		}
	}
}

{"me_262_50mm"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_fighter")
		("tag_airborne_ger")
		("Cannon_50to57mm_HV")
		{add_view	"tank_canon_fire_50_57"	"flashbarrel00"	"foresight1"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}

	{on fire "gun" overload
		{ani_play "fire" 1}
		{view start "flashbarrel00"}
		{delay 0.2
			{view pause "flashbarrel00"}
		}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

{"me_262_50mm_ai"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_fighter_ai")
		("tag_airborne_ger")
		("Cannon_50to57mm_HV")
		{add_view	"tank_canon_fire_50_57"	"flashbarrel00"	"foresight1"}	
	}
	{on "air_attack"
		{play_sound "attack"}
	}

	{on fire "gun" overload
		{ani_play "fire" 1}
		{view start "flashbarrel00"}
		{delay 0.2
			{view pause "flashbarrel00"}
		}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

{"me_262_rockets_210x2"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_fighter")
		("tag_airborne_ger")
		("Autocannon_s1_Rapid")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel02"	"shooter02"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel03"	"shooter03"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}

	{on fire "gun" overload
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
		else name "02"
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

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
	}
}
{"me_262_rockets_210x2_ai"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_fighter_ai")
		("tag_airborne_ger")
		("Autocannon_s1_Rapid")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel02"	"shooter02"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel03"	"shooter03"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}

	{on fire "gun" overload
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
		else name "02"
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

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
	}
}

{"me_262_rockets_250x2"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_bomber")
		("tag_airborne_ger")
		("Autocannon_s1_Rapid")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel02"	"shooter02"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel03"	"shooter03"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}

	{on fire "gun" overload
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
		else name "02"
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

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}
	{on "die"
		{bone hide "rocket00"}
			{bone hide "rocket01"}
			{bone hide "rocket02"}
			{bone hide "rocket03"}
			{bone hide "rocket04"}
			{bone hide "rocket05"}
			{bone hide "rocket06"}
			{bone hide "rocket07"}
			{bone hide "rocket08"}
			{bone hide "rocket09"}
			{bone hide "rocket10"}
			{bone hide "rocket11"}
			{bone hide "rocket12"}
			{bone hide "rocket13"}
			{bone hide "rocket14"}
			{bone hide "rocket15"}
			{bone hide "rocket16"}
			{bone hide "rocket17"}
			{bone hide "rocket18"}
			{bone hide "rocket19"}
			{bone hide "rocket20"}
			{bone hide "rocket21"}
			{bone hide "rocket22"}
			{bone hide "rocket23"}
			{bone hide "rocket24"}
			{bone hide "rocket25"}
			{bone hide "rocket26"}
			{bone hide "rocket27"}
			{bone hide "rocket28"}
			{bone hide "rocket29"}
			{bone hide "rocket30"}
			{bone hide "rocket31"}
			{bone hide "rocket32"}
			{bone hide "rocket33"}
			{bone hide "rocket34"}
			{bone hide "rocket35"}
			{bone hide "rocket36"}
			{bone hide "rocket37"}
			{bone hide "rocket38"}
			{bone hide "rocket39"}
			{bone hide "rocket40"}
			{bone hide "rocket41"}
			{bone hide "rocket42"}
			{bone hide "rocket43"}
			{bone hide "rocket44"}
			{bone hide "rocket45"}
			{bone hide "rocket46"}
			{bone hide "rocket47"}
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}	
		{if volume "wingr2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
			{bone hide "rocket09"}
			{bone hide "rocket11"}
			{bone hide "rocket13"}
			{bone hide "rocket15"}
			{bone hide "rocket17"}
			{bone hide "rocket19"}
			{bone hide "rocket21"}
			{bone hide "rocket23"}
			{bone hide "rocket25"}
			{bone hide "rocket27"}
			{bone hide "rocket29"}
			{bone hide "rocket31"}
			{bone hide "rocket33"}
			{bone hide "rocket35"}
			{bone hide "rocket37"}
			{bone hide "rocket39"}
			{bone hide "rocket41"}
			{bone hide "rocket43"}
			{bone hide "rocket45"}
			{bone hide "rocket47"}
			{bone hide "pylon_left"}
		else volume "wingl2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
			{bone hide "rocket08"}
			{bone hide "rocket10"}
			{bone hide "rocket12"}
			{bone hide "rocket14"}
			{bone hide "rocket16"}
			{bone hide "rocket18"}
			{bone hide "rocket20"}
			{bone hide "rocket22"}
			{bone hide "rocket24"}
			{bone hide "rocket26"}
			{bone hide "rocket28"}
			{bone hide "rocket30"}
			{bone hide "rocket32"}
			{bone hide "rocket34"}
			{bone hide "rocket36"}
			{bone hide "rocket38"}
			{bone hide "rocket40"}
			{bone hide "rocket42"}
			{bone hide "rocket44"}
			{bone hide "rocket46"}
			{bone hide "pylon_right"}
		}
	}
}

{"me_262_rockets_250x2_ai"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_bomber_ai")
		("tag_airborne_ger")
		("Autocannon_s1_Rapid")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel01"	"shooter01"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel02"	"shooter02"}
		{add_view	"flash_gun_hmg_m2hb"	"flashbarrel03"	"shooter03"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}

	{on fire "gun" overload
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
		else name "02"
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

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "die"
		{bone hide "rocket00"}
			{bone hide "rocket01"}
			{bone hide "rocket02"}
			{bone hide "rocket03"}
			{bone hide "rocket04"}
			{bone hide "rocket05"}
			{bone hide "rocket06"}
			{bone hide "rocket07"}
			{bone hide "rocket08"}
			{bone hide "rocket09"}
			{bone hide "rocket10"}
			{bone hide "rocket11"}
			{bone hide "rocket12"}
			{bone hide "rocket13"}
			{bone hide "rocket14"}
			{bone hide "rocket15"}
			{bone hide "rocket16"}
			{bone hide "rocket17"}
			{bone hide "rocket18"}
			{bone hide "rocket19"}
			{bone hide "rocket20"}
			{bone hide "rocket21"}
			{bone hide "rocket22"}
			{bone hide "rocket23"}
			{bone hide "rocket24"}
			{bone hide "rocket25"}
			{bone hide "rocket26"}
			{bone hide "rocket27"}
			{bone hide "rocket28"}
			{bone hide "rocket29"}
			{bone hide "rocket30"}
			{bone hide "rocket31"}
			{bone hide "rocket32"}
			{bone hide "rocket33"}
			{bone hide "rocket34"}
			{bone hide "rocket35"}
			{bone hide "rocket36"}
			{bone hide "rocket37"}
			{bone hide "rocket38"}
			{bone hide "rocket39"}
			{bone hide "rocket40"}
			{bone hide "rocket41"}
			{bone hide "rocket42"}
			{bone hide "rocket43"}
			{bone hide "rocket44"}
			{bone hide "rocket45"}
			{bone hide "rocket46"}
			{bone hide "rocket47"}
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}	
		{if volume "wingr2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
			{bone hide "rocket09"}
			{bone hide "rocket11"}
			{bone hide "rocket13"}
			{bone hide "rocket15"}
			{bone hide "rocket17"}
			{bone hide "rocket19"}
			{bone hide "rocket21"}
			{bone hide "rocket23"}
			{bone hide "rocket25"}
			{bone hide "rocket27"}
			{bone hide "rocket29"}
			{bone hide "rocket31"}
			{bone hide "rocket33"}
			{bone hide "rocket35"}
			{bone hide "rocket37"}
			{bone hide "rocket39"}
			{bone hide "rocket41"}
			{bone hide "rocket43"}
			{bone hide "rocket45"}
			{bone hide "rocket47"}
			{bone hide "pylon_left"}
		else volume "wingl2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
			{bone hide "rocket08"}
			{bone hide "rocket10"}
			{bone hide "rocket12"}
			{bone hide "rocket14"}
			{bone hide "rocket16"}
			{bone hide "rocket18"}
			{bone hide "rocket20"}
			{bone hide "rocket22"}
			{bone hide "rocket24"}
			{bone hide "rocket26"}
			{bone hide "rocket28"}
			{bone hide "rocket30"}
			{bone hide "rocket32"}
			{bone hide "rocket34"}
			{bone hide "rocket36"}
			{bone hide "rocket38"}
			{bone hide "rocket40"}
			{bone hide "rocket42"}
			{bone hide "rocket44"}
			{bone hide "rocket46"}
			{bone hide "pylon_right"}
		}
	}
	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
		{if operatable
			{tags add "bomb_1"}
			{tags add "bomb_2"}
			{delay 0.5
				{if tagged "bomb_1"
					{spawn "sc_ger_500" "pivot_front"}
					{bone hide "bomb_00"}
				}
				{delay 1
					{if tagged "bomb_2"
						{spawn "sc_ger_500" "pivot_front"}
						{bone hide "bomb_01"}
					}
				}		
			}	
		}
	}
}

;;============================================== GER AIR transport =========================
{"ju-52"
	("ju-52_sound")
	{on spawn
		{delay 0.2
			{tags add "ger"}
			{if not tagged "enemy_paradrop_plane"
				{tags add "enemy_paradrop_plane"}
			}	
		}
	}
	{##on "wheels_fx"
		{add_view "spheredust_big" "ground_dust" "support1"}
		{add_view "spheredust_big" "ground_dust" "support2"}
		{view start "ground_dust"}
		{delay 4
			{view stop "ground_dust"}
		}
	}
}

{"ju-52 drop_plane"
	("ju-52_sound")
	{on spawn
		("tag_airborne_cargo")
		("tag_airborne_ger")
	}
	{##on "wheels_fx"
		{add_view "spheredust_big" "ground_dust" "support1"}
		{add_view "spheredust_big" "ground_dust" "support2"}
		{view start "ground_dust"}
		{delay 4
			{view stop "ground_dust"}
		}
	}
}

{"ju-52_para_plane_player"
	("ju-52_sound")
	{on spawn
		("tag_airborne_cargo")
		("tag_airborne_ger")
		{tags add "ger"}
	}
	{##on "wheels_fx"
		{add_view "spheredust_big" "ground_dust" "support1"}
		{add_view "spheredust_big" "ground_dust" "support2"}
		{view start "ground_dust"}
		{delay 4
			{view stop "ground_dust"}
		}
	}
}

{"bomber" ;Ju-52
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

; ## USSR
;;============================================== USSR =======================================
;;============================================== USSR AIR ===================================
;;============================================== USSR AIR recon =============================
{"po2"
	("po2_sound")
	{on spawn
		("tag_airborne_recon")
		("tag_airborne_rus")
	}
	{on "wing_tear" overload
		{if volume "wingl1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireL_ail")
				{tear "piece_big_airborne_wing" bone "wingl2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingl1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		else volume "wingr1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireR_ail")
				{tear "piece_big_airborne_wing" bone "wingr2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingr1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		}
	}
	{on "tear_part"
		{if volume "elevator1"
			("cut_part_delete" args "wireL_elev")
		}
		{if volume "elevator2"
			("cut_part_delete" args "wireR_elev")
		}
		{if volume "rudder1"
			("cut_part_delete" args "wire_rud")
		}

		;//Left Wings
		{if volume "aileron1"
			("cut_part_delete" args "wireL_top")
			("cut_part_delete" args "wireL_ail")
		}
		{if volume "aileron3"
			("cut_part_delete" args "wireL_bottom")
			("cut_part_delete" args "wireL_ail")
		}

		;//Right Wings
		{if volume "aileron2"
			("cut_part_delete" args "wireR_top")
			("cut_part_delete" args "wireR_ail")
		}
		{if volume "aileron4"
			("cut_part_delete" args "wireR_bottom")
			("cut_part_delete" args "wireR_ail")
		}
	}
}

{"ai_po2"
	("po2_sound")
	{on spawn
		("tag_airborne_recon_ai")
		("tag_airborne_rus")
	}
	{on "wing_tear" overload
		{if volume "wingl1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireL_ail")
				{tear "piece_big_airborne_wing" bone "wingl2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingl1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		else volume "wingr1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireR_ail")
				{tear "piece_big_airborne_wing" bone "wingr2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingr1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		}
	}
	{on "tear_part"
		{if volume "elevator1"
			("cut_part_delete" args "wireL_elev")
		}
		{if volume "elevator2"
			("cut_part_delete" args "wireR_elev")
		}
		{if volume "rudder1"
			("cut_part_delete" args "wire_rud")
		}

		;//Left Wings
		{if volume "aileron1"
			("cut_part_delete" args "wireL_top")
			("cut_part_delete" args "wireL_ail")
		}
		{if volume "aileron3"
			("cut_part_delete" args "wireL_bottom")
			("cut_part_delete" args "wireL_ail")
		}

		;//Right Wings
		{if volume "aileron2"
			("cut_part_delete" args "wireR_top")
			("cut_part_delete" args "wireR_ail")
		}
		{if volume "aileron4"
			("cut_part_delete" args "wireR_bottom")
			("cut_part_delete" args "wireR_ail")
		}
	}
}


;;============================================== USSR AIR fighter ===========================
{"yak1_ser69"
	("yak1_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_rus")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("ZPU_1931_4M")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun2" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{delay 0.2 "fire"
					{view pause "flashbarrel%0"}
				}
            			{play_sound "MultiBarrel_head_mid"}
            			{play_sound "MultiBarrel_head_far"}
				{tags add "firing"}
        			{kill_delay "burst_end"}
        			{delay 0.01 "burst_end"
            				{tags remove "firing"}
					{play_sound "MultiBarrel_tail_close"}
            				{play_sound "MultiBarrel_tail_mid"}
            				{play_sound "MultiBarrel_tail_far"}
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
	{on "air_attack"
		{play_sound "attack"}
	}
}

{"yak1_ser69_ai"
	("yak1_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_rus")
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1_Rapid")
		("ZPU_1931_4M")
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun2" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{delay 0.2 "fire"
					{view pause "flashbarrel%0"}
				}
            			{play_sound "MultiBarrel_head_mid"}
            			{play_sound "MultiBarrel_head_far"}
				{tags add "firing"}
        			{kill_delay "burst_end"}
        			{delay 0.01 "burst_end"
            				{tags remove "firing"}
					{play_sound "MultiBarrel_tail_close"}
            				{play_sound "MultiBarrel_tail_mid"}
            				{play_sound "MultiBarrel_tail_far"}
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
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

{"ussr-p-39"
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_rus")
		("SG43")
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrel03"	"shooter03"}
		{add_view "light_flash_zenit"	"flashbarrel04"	"shooter04"}
		{add_view "light_flash_zenit"	"flashbarrel05"	"shooter05"}
	}
	("bf109_sound")
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}
	{on animation_end "engine_start"
		{bone hide "propeller"}
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{bone show "propeller"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

{"ussr-p-39_ai"
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_rus")
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrel03"	"shooter03"}
		{add_view "light_flash_zenit"	"flashbarrel04"	"shooter04"}
		{add_view "light_flash_zenit"	"flashbarrel05"	"shooter05"}
	}
	("bf109_sound")
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}
	{on animation_end "engine_start"
		{bone hide "propeller"}
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{bone show "propeller"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

{"po2_rocket_ai"
	("po2_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_rus")	
	}
	{on "add_weapon_sound" overload
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on "wing_tear" overload
		{if volume "wingl1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireL_ail")
				{tear "piece_big_airborne_wing" bone "wingl2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingl1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		else volume "wingr1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireR_ail")
				{tear "piece_big_airborne_wing" bone "wingr2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingr1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		}
	}
	{on "tear_part"
		{if volume "elevator1"
			("cut_part_delete" args "wireL_elev")
		}
		{if volume "elevator2"
			("cut_part_delete" args "wireR_elev")
		}
		{if volume "rudder1"
			("cut_part_delete" args "wire_rud")
		}

		;//Left Wings
		{if volume "aileron1"
			("cut_part_delete" args "rocket00")
			("cut_part_delete" args "rocket02")
			("cut_part_delete" args "rocket04")
			("cut_part_delete" args "rocket06")
			("cut_part_delete" args "rocket_pylon_l")
			("cut_part_delete" args "bomb_pylon_l")
			("cut_part_delete" args "wireL_top")
			("cut_part_delete" args "wireL_ail")
		}
		{if volume "aileron3"
			("cut_part_delete" args "rocket00")
			("cut_part_delete" args "rocket02")
			("cut_part_delete" args "rocket04")
			("cut_part_delete" args "rocket06")
			("cut_part_delete" args "rocket_pylon_l")
			("cut_part_delete" args "bomb_pylon_l")
			("cut_part_delete" args "wireL_bottom")
			("cut_part_delete" args "wireL_ail")
		}

		;//Right Wings
		{if volume "aileron2"
			("cut_part_delete" args "rocket01")
			("cut_part_delete" args "rocket03")
			("cut_part_delete" args "rocket05")
			("cut_part_delete" args "rocket07")
			("cut_part_delete" args "rocket_pylon_r")
			("cut_part_delete" args "bomb_pylon_r")
			("cut_part_delete" args "wireR_top")
			("cut_part_delete" args "wireR_ail")
		}
		{if volume "aileron4"
			("cut_part_delete" args "rocket01")
			("cut_part_delete" args "rocket03")
			("cut_part_delete" args "rocket05")
			("cut_part_delete" args "rocket07")
			("cut_part_delete" args "rocket_pylon_r")
			("cut_part_delete" args "bomb_pylon_r")
			("cut_part_delete" args "wireR_bottom")
			("cut_part_delete" args "wireR_ail")
		}
	}
	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
		{if operatable
			{tags add "bomb_1"}
			{tags add "bomb_2"}
			{delay 4.7
				{if tagged "bomb_1"
					{spawn "fab_100" "bomb1_release"}
					{bone hide "bomb_00"}
				}
				{delay 0.3
					{if tagged "bomb_2"
						{spawn "fab_100" "bomb2_release"}
						{bone hide "bomb_01"}
					}
				}		
			}	
		}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
		{bone hide "rocket02"}
		{bone hide "rocket03"}
		{bone hide "rocket04"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "rocket_pylon_r"}
		{bone hide "rocket_pylon_l"}
		{bone hide "bomb_pylon_r"}
		{bone hide "bomb_pylon_l"}
	}
}

;;============================================== USSR AIR light bomber ======================
{"po2_flame_ai"
	("po2_sound")
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_rus")	
	}
	{on "wing_tear" overload
		{if volume "wingl1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireL_ail")
				{tear "piece_big_airborne_wing" bone "wingl2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingl1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		else volume "wingr1"
			{call "crash"}
			{delay_ex 0
				("cut_part_delete" args "wireR_ail")
				{tear "piece_big_airborne_wing" bone "wingr2"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
			{delay_ex 0
				{tear "piece_big_airborne_wing" bone "wingr1"
					{impulse up 2 1 forward 5 dir 2 1}
				}
			}
		}
	}
	{on "tear_part"
		{if volume "elevator1"
			("cut_part_delete" args "wireL_elev")
		}
		{if volume "elevator2"
			("cut_part_delete" args "wireR_elev")
		}
		{if volume "rudder1"
			("cut_part_delete" args "wire_rud")
		}

		;//Left Wings
		{if volume "aileron1"
			("cut_part_delete" args "bomb_00")
			("cut_part_delete" args "bomb_02")
			("cut_part_delete" args "bomb_pylon_l1")
			("cut_part_delete" args "wireL_top")
			("cut_part_delete" args "wireL_ail")
		}
		{if volume "aileron3"
			("cut_part_delete" args "bomb_00")
			("cut_part_delete" args "bomb_02")
			("cut_part_delete" args "bomb_pylon_l1")
			("cut_part_delete" args "wireL_bottom")
			("cut_part_delete" args "wireL_ail")
		}

		;//Right Wings
		{if volume "aileron2"
			("cut_part_delete" args "bomb_01")
			("cut_part_delete" args "bomb_03")
			("cut_part_delete" args "bomb_pylon_r1")
			("cut_part_delete" args "wireR_top")
			("cut_part_delete" args "wireR_ail")
		}
		{if volume "aileron4"
			("cut_part_delete" args "bomb_01")
			("cut_part_delete" args "bomb_03")
			("cut_part_delete" args "bomb_pylon_r1")
			("cut_part_delete" args "wireR_bottom")
			("cut_part_delete" args "wireR_ail")
		}
	}
	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "bomb_02"}
		{bone hide "bomb_03"}
		{bone hide "bomb_pylon_r1"}
		{bone hide "bomb_pylon_l1"}
	}
}


;;============================================== USSR AIR heavy fighter =====================
{"il2_mod41"
	("il2_sound")
	{on spawn
		("tag_airborne_hvfighter")
		("tag_airborne_rus")
		("Autocannon_s1_Rapid")
		("ZPU_1931_4M")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}

	{on fire "mgun2" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{delay 0.2 "fire"
					{view pause "flashbarrel%0"}
				}
            			{play_sound "MultiBarrel_head_mid"}
            			{play_sound "MultiBarrel_head_far"}
				{tags add "firing"}
        			{kill_delay "burst_end"}
        			{delay 0.01 "burst_end"
            				{tags remove "firing"}
					{play_sound "MultiBarrel_tail_close"}
            				{play_sound "MultiBarrel_tail_mid"}
            				{play_sound "MultiBarrel_tail_far"}
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

	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket02"}
		{bone hide "rocket04"}
		{bone hide "rocket06"}
		{bone hide "rocket01"}
		{bone hide "rocket03"}
		{bone hide "rocket05"}
		{bone hide "rocket07"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
		else volume "wingl2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}	
}

{"il2_mod41_ai"
	("il2_sound")
	{on spawn
		("tag_airborne_hvfighter_ai")
		("tag_airborne_rus")
		("Autocannon_s1_Rapid")
		("ZPU_1931_4M")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{play_sound "Cannon_tail_close"}
		{play_sound "Cannon_head_mid"}
		{play_sound "Cannon_tail_mid"}
		{play_sound "Cannon_head_far"}
		{play_sound "Cannon_tail_far"}
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}

	{on fire "mgun2" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{delay 0.2 "fire"
					{view pause "flashbarrel%0"}
				}
            			{play_sound "MultiBarrel_head_mid"}
            			{play_sound "MultiBarrel_head_far"}
				{tags add "firing"}
        			{kill_delay "burst_end"}
        			{delay 0.01 "burst_end"
            				{tags remove "firing"}
					{play_sound "MultiBarrel_tail_close"}
            				{play_sound "MultiBarrel_tail_mid"}
            				{play_sound "MultiBarrel_tail_far"}
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

	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket02"}
		{bone hide "rocket04"}
		{bone hide "rocket06"}
		{bone hide "rocket01"}
		{bone hide "rocket03"}
		{bone hide "rocket05"}
		{bone hide "rocket07"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
		else volume "wingl2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}	
}


;;============================================== USSR AIR bomber ============================
{"il2_mod42"
	("il2_sound")
	{on spawn
		("tag_airborne_bomber")
		("tag_airborne_rus")
		("Autocannon_s1_Rapid")
		("ZPU_1931_4M")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}

	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}

	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket02"}
		{bone hide "rocket04"}
		{bone hide "rocket06"}
		{bone hide "rocket01"}
		{bone hide "rocket03"}
		{bone hide "rocket05"}
		{bone hide "rocket07"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
		else volume "wingl2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
		}
	}
}

{"il2_mod42_ai"
	("il2_sound")
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_rus")
		("Autocannon_s1_Rapid")
		("ZPU_1931_4M")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)

		{if ("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		}
	}

	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket02"}
		{bone hide "rocket04"}
		{bone hide "rocket06"}
		{bone hide "rocket01"}
		{bone hide "rocket03"}
		{bone hide "rocket05"}
		{bone hide "rocket07"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
		else volume "wingl2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}	
}

{"rus-b25"
	{on spawn
		("tag_airborne_bomber")
		("tag_airborne_rus")
		{add_view "flash_zenit"	"flashbarrel1m00"	"shooter1m_00"}
		{add_view "flash_zenit"	"flashbarrel1m01"	"shooter1m_01"}
		{add_view "flash_zenit"	"flashbarrel1m02"	"shooter1m_02"}
		{add_view "flash_zenit"	"flashbarrel1m03"	"shooter1m_03"}
		{add_view "flash_zenit"	"flashbarrel2m00"	"shooter2m_00"}
		{add_view "flash_zenit"	"flashbarrel2m01"	"shooter2m_01"}
		{add_view "flash_zenit"	"flashbarrel3m00"	"shooter3m_00"}
		{add_view "flash_zenit"	"flashbarrel3m01"	"shooter3m_01"}
		{add_view "flash_zenit"	"flashbarrel4"	"foresight7"}
		{add_view "flash_zenit"	"flashbarrel5"	"foresight8"}
	}
	("bf110_sound")
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel1m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel1m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
                                      else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel2m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel2m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun3"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel3m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel3m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun4"
		{view start "flashbarrel4"}
		{delay 0.5
			{view pause "flashbarrel4"}
		}
	}
	{on fire "mgun5"
		{view start "flashbarrel5"}
		{delay 0.5
			{view pause "flashbarrel5"}
		}
	}
	{on "engine_count" overload
		{tags add "engine_count_2"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

{"rus-b25_ai"
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_rus")
		{add_view "flash_zenit"	"flashbarrel1m00"	"shooter1m_00"}
		{add_view "flash_zenit"	"flashbarrel1m01"	"shooter1m_01"}
		{add_view "flash_zenit"	"flashbarrel1m02"	"shooter1m_02"}
		{add_view "flash_zenit"	"flashbarrel1m03"	"shooter1m_03"}
		{add_view "flash_zenit"	"flashbarrel2m00"	"shooter2m_00"}
		{add_view "flash_zenit"	"flashbarrel2m01"	"shooter2m_01"}
		{add_view "flash_zenit"	"flashbarrel3m00"	"shooter3m_00"}
		{add_view "flash_zenit"	"flashbarrel3m01"	"shooter3m_01"}
		{add_view "flash_zenit"	"flashbarrel4"	"foresight7"}
		{add_view "flash_zenit"	"flashbarrel5"	"foresight8"}
	}
	("bf110_sound")
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel1m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel1m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
                                      else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel2m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel2m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun3"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel3m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel3m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun4"
		{view start "flashbarrel4"}
		{delay 0.5
			{view pause "flashbarrel4"}
		}
	}
	{on fire "mgun5"
		{view start "flashbarrel5"}
		{delay 0.5
			{view pause "flashbarrel5"}
		}
	}
	{on "engine_count" overload
		{tags add "engine_count_2"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}


;;============================================== USSR AIR reactive ==========================
; xxx
;;============================================== USSR AIR transport =========================
{"li-2"
	("bf110_sound")
	{on spawn
		("tag_airborne_cargo")
		("tag_airborne_rus")
	}
	{on "engine_count" overload
		{tags add "engine_count_2"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}
{"li-2_ai"
	("bf110_sound")
	{on spawn
		("tag_airborne_cargo_ai")
		("tag_airborne_rus")
	}
	{on "engine_count" overload
		{tags add "engine_count_2"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

; ## FIN
;;============================================== FIN =======================================
;;============================================== FIN AIR ===================================

;;============================================== FIN AIR recon =============================
;/---------------------------------------------- po2_fin
{"po2_fin"			;// See airborne.ext
	("po2_sound")
	{on spawn
		("tag_airborne_recon")
		("tag_airborne_fin")
	}
	{on "air_attack"
		{play_sound "attack"}
	}
}
{"po2_fin_ai"		;// See airborne.ext
	{on spawn
		("tag_airborne_recon_ai")
		("tag_airborne_fin")
	}
	{on "air_attack"
		{play_sound "attack"}
	}
}

;/---------------------------------------------- blenheim_mk1_recon
{"blenheim_mk1_recon"
	("bf110_sound")
	{on spawn
		("tag_airborne_recon_ai")
		("tag_airborne_fin")
	}
	{on "add_weapon_sound" overload
		{link_sound 		"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 		"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}

	}
	{on fire "mgun" overload
		{view start "flashbarrel_main"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid_1"}
		{play_sound "MG_Far_1"}
	}

	{on fire "bomb1"
		{ani_wind "bomb_open" end}
		{delay 3
			{ani_play "bomb_open" -1}
		}
	}

	{on "air_attack"
		{ani_play "bomb_open" 1}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}
	}
}

{"blenheim_mk1_recon_ai"
	("bf110_sound")
	{on spawn
		("tag_airborne_recon_ai")
		("tag_airborne_fin")
	}
	{on "add_weapon_sound" overload
		{link_sound 		"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 		"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}

	}
	{on fire "mgun" overload
		{view start "flashbarrel_main"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid_1"}
		{play_sound "MG_Far_1"}
	}

	{on fire "bomb1"
		{ani_wind "bomb_open" end}
		{delay 3
			{ani_play "bomb_open" -1}
		}
	}

	{on "air_attack"
		{ani_play "bomb_open" 1}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}
	}
}

;;============================================== FIN AIR fighter ===========================
;/---------------------------------------------- fokker_fin
{"fokker_fin"
	("hurricane_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_fin")
		{delay 0.1
			{if not tagged "airborne_fin"
				{tags add 
					"airborne_fin"
				}
			}
			{if not tagged "player_fighter"
				{tags add 
					"player_fighter"
				}
			}	
		}
	}		
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

{"fokker_fin_ai"
	("hurricane_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_fin")
	}
	{on "add_weapon_sound" overload
		("SG43")
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}

	{on "tear_part"
		{if not tagged "exploded"
			{if rand 0.3
				{spawn "aero_die_particle"}
			}
			{if tagged "mid_air_collision"
				{call "bail_out"}
				{tags remove "mid_air_collision"}
			}
			{volume disable contact contact_ground}
			{call "wing_tear"}
			{if volume "nothing"
				; do nothing
			else
				{delay_ex 0
					{tear "piece_big_airborne_wing" bone from_volume
						{impulse up 2 1 forward 5 dir 2 1}
					}
				}
			}

			{if volume "gear_r"
				{call "wrecked_gear"}
				{call "crash"}
			else volume "gear_l"
				{call "wrecked_gear"}
				{call "crash"}

			else volume "wingl2"
				{call "crash"}
				("cut_part_delete" args "wireL_ail")

			else volume "wingr2"
				{call "crash"}
				("cut_part_delete" args "wireR_ail")

			else volume "winglt1"
				{call "crash"}
				("cut_part_delete" args "wireL_ail")

			else volume "winglt2"
				{call "crash"}
				("cut_part_delete" args "wireL_ail")

			else volume "wingrt1"
				{call "crash"}
				("cut_part_delete" args "wireR_ail")
			else volume "wingrt2"
				{call "crash"}
				("cut_part_delete" args "wireR_ail")
			}
		}
	}
	
	{on "die"
		{bone hide "propeller_work"}
		{bone hide "propeller"}
		{bone hide "wheelback"}
		{bone hide "wheell"}
		{bone hide "wheelr"}
;//		{bone hide "elevator1"}		
;//		{bone hide "elevator2"}			
	}
	
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

;/---------------------------------------------- bf109_g6_fin
{"bf109_g6_fin"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_fin")
	}
	{on "add_weapon_sound" overload
		("MG13")
	}
	{on fire "gun" overload
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}	
}
{"bf109_g6_fin_ai"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_fin")
	}
	{on "add_weapon_sound" overload
		("MG13")
	}
	{on fire "gun" overload
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}	
}

;;============================================== FIN AIR heavy fighter =====================
;;============================================== FIN AIR bomber ============================
{"blenheim_mk1"
	("bf110_sound")
	{on spawn
		("tag_airborne_bomber")
		("tag_airborne_fin")
	}
	{on "add_weapon_sound" overload
		{link_sound 		"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 		"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}

	}
	{on fire "mgun" overload
		{view start "flashbarrel_main"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid_1"}
		{play_sound "MG_Far_1"}
	}

	{on fire "bomb1"
		{ani_wind "bomb_open" end}
		{delay 3
			{ani_play "bomb_open" -1}
		}
	}

	{on "air_attack"
		{ani_play "bomb_open" 1}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}
	}
}
{"blenheim_mk1_ai"
	("bf110_sound")
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_fin")
	}
	{on "add_weapon_sound" overload
		{link_sound 		"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 		"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}

	}
	{on fire "mgun" overload
		{view start "flashbarrel_main"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid_1"}
		{play_sound "MG_Far_1"}
	}

	{on fire "bomb1"
		{ani_wind "bomb_open" end}
		{delay 3
			{ani_play "bomb_open" -1}
		}
	}

	{on "air_attack"
		{ani_play "bomb_open" 1}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}
	}
}

;;============================================== FIN AIR reactive ==========================
;;============================================== FIN AIR transport =========================

; ## USA
;;============================================== USA BEGIN =================================
;;============================================== USA AIR ===================================
;;============================================== USA AIR recon =============================
{"us-piper_j-3"
	("fi156_sound")
	{on spawn
		("tag_airborne_recon")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("MG13")
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}


{"us-piper_j-3_ai"
	("fi156_sound")
	{on spawn
		("tag_airborne_recon_ai")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("MG13")
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

{"p47_d22_recon"
	("p47_sound")
	{on spawn
		("tag_airborne_recon")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}

	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
		else volume "wingl2"
			{bone hide "bomb_00"}
		}
	}
	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "bomb_02"}
	}

}


{"ai_recon_p47_d22"
	("p47_sound")
	{on spawn
		("tag_airborne_recon_ai")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}

	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
		else volume "wingl2"
			{bone hide "bomb_00"}
		}
	}
	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "bomb_02"}
	}

}

;;============================================== USA AIR fighter ===========================
{"us-p-39"
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_usa")
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrel03"	"shooter03"}
		{add_view "light_flash_zenit"	"flashbarrel04"	"shooter04"}
		{add_view "light_flash_zenit"	"flashbarrel05"	"shooter05"}
	}
	("hurricane_sound")
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}
	{on animation_end "engine_start"
		{bone hide "propeller"}
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{bone show "propeller"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	{on fire "gun" overload
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun_left"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun_right"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "die"
		{bone hide "rocket_rack_l"}
		{bone hide "rocket_rack_r"}
		{bone hide "propeller"}
		{bone hide "propeller_work"}
		{bone hide "retract_wheelf1"}
		{bone hide "retract_wheelf2"}		
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}


{"us-p-39_ai"
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_usa")
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrel03"	"shooter03"}
		{add_view "light_flash_zenit"	"flashbarrel04"	"shooter04"}
		{add_view "light_flash_zenit"	"flashbarrel05"	"shooter05"}
	}
	("hurricane_sound")
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}
	{on animation_end "engine_start"
		{bone hide "propeller"}
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{bone show "propeller"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	{on fire "gun" overload
		{view start "flashbarrel_main"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun_left"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun_right"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "die"
		{bone hide "rocket_rack_l"}
		{bone hide "rocket_rack_r"}
		{bone hide "propeller"}
		{bone hide "propeller_work"}
		{bone hide "retract_wheelf1"}
		{bone hide "retract_wheelf2"}		
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

{"us-p-40"
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_usa")
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"	"flashbarrel02"	"shooter_mg00"}
		{add_view "flash_zenit"	"flashbarrel03"	"shooter_mg01"}
		{add_view "flash_zenit"	"flashbarrel04"	"shooter_mg02"}
		{add_view "flash_zenit"	"flashbarrel05"	"shooter_mg03"}
	}
	("hurricane_sound")
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}
	{on fire "mgun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}


{"us-p-40_ai" 
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_usa")
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"	"flashbarrel02"	"shooter_mg00"}
		{add_view "flash_zenit"	"flashbarrel03"	"shooter_mg01"}
		{add_view "flash_zenit"	"flashbarrel04"	"shooter_mg02"}
		{add_view "flash_zenit"	"flashbarrel05"	"shooter_mg03"}
	}
	("hurricane_sound")
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}
	{on fire "mgun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

{"p-51mustang"
	("hurricane_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}

	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
		else volume "wingl2"
			{bone hide "bomb_00"}
		}
	}
	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "bomb_02"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}


{"p-51mustang_ai"
	("hurricane_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}

	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
		else volume "wingl2"
			{bone hide "bomb_00"}
		}
	}
	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "bomb_02"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

;;============================================== USA universal figher ======================
{"p47_d22_hvar_ai"
	("p47_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_usa")	
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}

	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
			{bone hide "rocket08"}
			{bone hide "rocket10"}
			{bone hide "rocket_pylon_r"}	
			{bone hide "bomb_01"}
		else volume "wingl2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
			{bone hide "rocket09"}
			{bone hide "rocket11"}
			{bone hide "rocket_pylon_l"}
			{bone hide "bomb_00"}
		else volume "wingl1"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
			{bone hide "rocket09"}
			{bone hide "rocket11"}
			{bone hide "rocket_pylon_l"}
		else volume "wingr1"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
			{bone hide "rocket08"}
			{bone hide "rocket10"}
			{bone hide "rocket_pylon_r"}	
		}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket02"}
		{bone hide "rocket04"}
		{bone hide "rocket06"}
		{bone hide "rocket01"}
		{bone hide "rocket03"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
		{bone hide "rocket08"}
		{bone hide "rocket09"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "bomb_02"}
		{bone hide "rocket_pylon_r"}
		{bone hide "rocket_pylon_l"}
	}
	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
		{if operatable
			{tags add "bomb_1"}
			{delay 2
				{if tagged "bomb_1"
					{spawn "m64_500lb" "pivot_front"}
					{bone hide "bomb_00"}
				}		
			}	
		}
	}
}

{"p47_d22_m8_ai"
	("p47_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_usa")	
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}

	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket_pylon_r"}	
			{bone hide "bomb_01"}
		else volume "wingl2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket_pylon_l"}
			{bone hide "bomb_00"}
		else volume "wingl1"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket_pylon_l"}
		else volume "wingr1"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket_pylon_r"}	
		}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
		{bone hide "rocket02"}
		{bone hide "rocket03"}
		{bone hide "rocket04"}
		{bone hide "rocket05"}
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "bomb_02"}
		{bone hide "rocket_pylon_r"}
		{bone hide "rocket_pylon_l"}
	}
	{on fire "rocket" overload
		{play_sound "bkg_rocket"}
		{if operatable
			{tags add "bomb_1"}
			{delay 3
				{if tagged "bomb_1"
					{spawn "m64_500lb" "pivot_front"}
					{bone hide "bomb_00"}
				}		
			}	
		}
	}
}
;;============================================== USA universal bomber ======================
{"p47_d22"
	("p47_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}

	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
		else volume "wingl2"
			{bone hide "bomb_00"}
		}
	}
	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "bomb_02"}
	}

}


{"p47_d22_ai"
	("p47_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}	

	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
		else volume "wingl2"
			{bone hide "bomb_00"}
		}
	}
	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "bomb_02"}
	}

}
{"p47_d22_250lb_ai"
	("p47_sound")
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_rus")	
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}

	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
		else volume "wingl2"
			{bone hide "bomb_00"}
		}
	}
	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
		{bone hide "bomb_02"}
	}

}
;;============================================== USA AIR bomber ============================
{"us-b25"
	{on spawn
		("tag_airborne_bomber")
		("tag_airborne_usa")
		{add_view "flash_zenit"	"flashbarrel1m00"	"shooter1m_00"}
		{add_view "flash_zenit"	"flashbarrel1m01"	"shooter1m_01"}
		{add_view "flash_zenit"	"flashbarrel1m02"	"shooter1m_02"}
		{add_view "flash_zenit"	"flashbarrel1m03"	"shooter1m_03"}
		{add_view "flash_zenit"	"flashbarrel2m00"	"shooter2m_00"}
		{add_view "flash_zenit"	"flashbarrel2m01"	"shooter2m_01"}
		{add_view "flash_zenit"	"flashbarrel3m00"	"shooter3m_00"}
		{add_view "flash_zenit"	"flashbarrel3m01"	"shooter3m_01"}
		{add_view "flash_zenit"	"flashbarrel4"	"foresight7"}
		{add_view "flash_zenit"	"flashbarrel5"	"foresight8"}
	}
	("bf110_sound")
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel1m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel1m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
                                      else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel2m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel2m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun3"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel3m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel3m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun4"
		{view start "flashbarrel4"}
		{delay 0.5
			{view pause "flashbarrel4"}
		}
	}
	{on fire "mgun5"
		{view start "flashbarrel5"}
		{delay 0.5
			{view pause "flashbarrel5"}
		}
	}
	{on "engine_count" overload
		{tags add "engine_count_2"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}


{"us-b25_ai"
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_usa")
		{add_view "flash_zenit"	"flashbarrel1m00"	"shooter1m_00"}
		{add_view "flash_zenit"	"flashbarrel1m01"	"shooter1m_01"}
		{add_view "flash_zenit"	"flashbarrel1m02"	"shooter1m_02"}
		{add_view "flash_zenit"	"flashbarrel1m03"	"shooter1m_03"}
		{add_view "flash_zenit"	"flashbarrel2m00"	"shooter2m_00"}
		{add_view "flash_zenit"	"flashbarrel2m01"	"shooter2m_01"}
		{add_view "flash_zenit"	"flashbarrel3m00"	"shooter3m_00"}
		{add_view "flash_zenit"	"flashbarrel3m01"	"shooter3m_01"}
		{add_view "flash_zenit"	"flashbarrel4"	"foresight7"}
		{add_view "flash_zenit"	"flashbarrel5"	"foresight8"}
	}
	("bf110_sound")
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel1m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel1m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
                                      else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel2m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel2m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun3"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel3m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel3m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun4"
		{view start "flashbarrel4"}
		{delay 0.5
			{view pause "flashbarrel4"}
		}
	}
	{on fire "mgun5"
		{view start "flashbarrel5"}
		{delay 0.5
			{view pause "flashbarrel5"}
		}
	}
	{on "engine_count" overload
		{tags add "engine_count_2"}
	}
	{on "air_attack"
		{play_sound "attack"}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}


;;============================================== USA AIR reactive ==========================
{"f80a_450x2"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_bomber")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}
	
	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "air_attack"
		{play_sound "attack"}
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
	{on "die"
		{bone hide "bomb_01"}
		{bone hide "bomb_00"}
		{bone hide "bomb_pylon_r"}
		{bone hide "bomb_pylon_l"}
	}
	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
			{bone hide "bomb_pylon_r"}
		else volume "wingl2"
			{bone hide "bomb_00"}
			{bone hide "bomb_pylon_l"}
		}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}


{"f80a_450x2_ai"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_bomber_ai")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}
	
	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "air_attack"
		{play_sound "attack"}
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
	{on "die"
		{bone hide "bomb_01"}
		{bone hide "bomb_00"}
		{bone hide "bomb_pylon_r"}
		{bone hide "bomb_pylon_l"}
	}
	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
			{bone hide "bomb_pylon_r"}
		else volume "wingl2"
			{bone hide "bomb_00"}
			{bone hide "bomb_pylon_l"}
		}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

{"f80a_rockets_127x12"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_fighter")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	
	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "air_attack"
		{play_sound "attack"}
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
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket02"}
		{bone hide "rocket04"}
		{bone hide "rocket01"}
		{bone hide "rocket03"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
		{bone hide "rocket08"}
		{bone hide "rocket09"}
		{bone hide "rocket10"}
		{bone hide "rocket11"}
		{bone hide "rocket_pylon_r"}
		{bone hide "rocket_pylon_l"}
	}
	{on "tear_part"
		{if volume "wingr2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
			{bone hide "rocket08"}
			{bone hide "rocket10"}
			{bone hide "rocket_pylon_r"}
		else volume "wingl2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
			{bone hide "rocket09"}
			{bone hide "rocket11"}
			{bone hide "rocket_pylon_l"}
		}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}


{"f80a_rockets_127x12_ai"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_fighter_ai")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	
	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "air_attack"
		{play_sound "attack"}
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
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket02"}
		{bone hide "rocket04"}
		{bone hide "rocket06"}
		{bone hide "rocket01"}
		{bone hide "rocket03"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
		{bone hide "rocket08"}
		{bone hide "rocket09"}
		{bone hide "rocket10"}
		{bone hide "rocket11"}
		{bone hide "rocket_pylon_r"}
		{bone hide "rocket_pylon_l"}
	}
	{on "tear_part"
		{if volume "wingr2"
			{bone hide "rocket00"}
			{bone hide "rocket02"}
			{bone hide "rocket04"}
			{bone hide "rocket06"}
			{bone hide "rocket08"}
			{bone hide "rocket10"}
			{bone hide "rocket_pylon_r"}
		else volume "wingl2"
			{bone hide "rocket01"}
			{bone hide "rocket03"}
			{bone hide "rocket05"}
			{bone hide "rocket07"}
			{bone hide "rocket09"}
			{bone hide "rocket11"}
			{bone hide "rocket_pylon_l"}
		}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

{"f80a_mk78x4"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_fighter")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}
	
	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "air_attack"
		{play_sound "attack"}
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
	{on "die"
		{bone hide "bomb_03"}
		{bone hide "bomb_02"}
		{bone hide "bomb_01"}
		{bone hide "bomb_00"}
		{bone hide "pylon_bomb_r"}
		{bone hide "pylon_bomb_l"}
	}
	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
			{bone hide "bomb_03"}
			{bone hide "pylon_bomb_r"}
		else volume "wingl2"
			{bone hide "bomb_00"}
			{bone hide "bomb_02"}
			{bone hide "pylon_bomb_l"}
		}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}



{"f80a_mk78x4_ai"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_fighter_ai")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}

	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "air_attack"
		{play_sound "attack"}
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
	{on "die"
		{bone hide "bomb_03"}
		{bone hide "bomb_02"}
		{bone hide "bomb_01"}
		{bone hide "bomb_00"}
		{bone hide "pylon_bomb_r"}
		{bone hide "pylon_bomb_l"}
	}
	{on "tear_part"
		{if volume "wingr2"
			{bone hide "bomb_01"}
			{bone hide "bomb_03"}
			{bone hide "pylon_bomb_r"}
		else volume "wingl2"
			{bone hide "bomb_00"}
			{bone hide "bomb_02"}
			{bone hide "pylon_bomb_l"}
		}
	}
	{on "ground_hit"
		{delay 600
			{delete}
		}
	}
}

;;============================================== USA AIR transport =========================
{"c47_d"
	("c47_sound")
	{on spawn
		("tag_airborne_cargo")
		("tag_airborne_usa")
		{tags add "usa"}
	}
	{on "add_weapon_sound" overload
		{link_sound 	"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 	"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}
	}
	
	{on "engine_count" overload
		{tags add "engine_count_2"}
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

{"c47_d_para_plane_player"
	("c47_sound")
	{on spawn
		("tag_airborne_cargo")
		("tag_airborne_usa")
		{tags add "usa"}
	}
	{on "add_weapon_sound" overload
		{link_sound 	"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 	"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}
	}
	
	{on "engine_count" overload
		{tags add "engine_count_2"}
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

; ## ENG
;;============================================== ENG BEGIN =======================================
;;============================================== ENG AIR ===================================
;;============================================== ENG AIR recon =============================
{"blenheim_mk1_eng_recon"
	{on spawn
		("tag_airborne_recon")
		("tag_airborne_eng")
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}		
	}
	("bf110_sound")
	{on "add_weapon_sound" overload
		{link_sound 		"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 		"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}

	}
	{on fire "mgun" overload
		{view start "flashbarrel_main"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid_1"}
		{play_sound "MG_Far_1"}
	}

	{on fire "bomb1"
		{ani_wind "bomb_open" end}
		{delay 3
			{ani_play "bomb_open" -1}
		}
	}

;//	{on "air_attack"
;//		{ani_play "bomb_open" 1}
;//	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

;//	{on "die"
;//		{bone hide "bomb_00"}
;//		{bone hide "bomb_01"}
;//	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}
	}
}

{"blenheim_mk1_eng_recon_ai"
	{on spawn
		("tag_airborne_recon_ai")
		("tag_airborne_eng")
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}
	("bf110_sound")
	{on "add_weapon_sound" overload
		{link_sound 		"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 		"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}

	}
	{on fire "mgun" overload
		{view start "flashbarrel_main"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid_1"}
		{play_sound "MG_Far_1"}
	}

	{on fire "bomb1"
		{ani_wind "bomb_open" end}
		{delay 3
			{ani_play "bomb_open" -1}
		}
	}

;//	{on "air_attack"
;//		{ani_play "bomb_open" 1}
;//	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

;//	{on "die"
;//		{bone hide "bomb_00"}
;//		{bone hide "bomb_01"}
;//	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}
	}
}

{"blenheim_mk1_eng_ai"
	("bf110_sound")
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_eng")	
	}
	{on "add_weapon_sound" overload
		{link_sound 		"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 		"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}

	}
	{on fire "mgun" overload
		{view start "flashbarrel_main"}
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{delay 0.42
			{view pause "flashbarrel_main"}
		}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid_1"}
		{play_sound "MG_Far_1"}
	}

	{on fire "bomb1"
		{ani_wind "bomb_open" end}
		{delay 3
			{ani_play "bomb_open" -1}
		}
	}

	{on "air_attack"
		{ani_play "bomb_open" 1}
	}

	{on "engine_count" overload
		{tags add "engine_count_2"}
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

	{on "die"
		{bone hide "bomb_00"}
		{bone hide "bomb_01"}
	}

	{on "tear_part"
		{if volume "body"
			{bone hide "bomb_00"}
			{bone hide "bomb_01"}
		}
	}
}

{"typhoon_mk1b_recon_ai"
	("hurricane_sound")
	{on spawn
		("tag_airborne_recon_ai")
		("tag_airborne_eng")
	}
	{on "add_weapon_sound" overload
		("2cm_Flakvierling")
	}
	("multi_barrel_loop" flash(tank_canon_fire_20_25_auto) smoke(smoke_zenit) shell(zenit_gilz) weapon(gun) head(0.200))
}

;;============================================== ENG AIR fighter ===========================
{"hurricane_mk1a_ai"
	("hurricane_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_eng")	
	}
	{on "add_weapon_sound" overload
		("Browning_303_x8")
	}

	("multi_barrel_loop" flash(flash_gun_big) smoke(ejectsmoke_big) shell(shell_mgun) weapon(mgun) head(0.070))
}

{"typhoon_mk1b_ai"
	("hurricane_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_eng")	
	}
	{on "add_weapon_sound" overload
		("2cm_Flakvierling")
	}
	("multi_barrel_loop" flash(tank_canon_fire_20_25_auto) smoke(smoke_zenit) shell(zenit_gilz) weapon(gun) head(0.200))
}
;;============================================== ENG AIR heavy fighter =====================

;;============================================== ENG AIR bomber ============================
{"hurribomber_mk2c_ai"
	("hurricane_sound")
	{on spawn
		("tag_airborne_bomber_ai")
		("tag_airborne_eng")	
	}
	{on "add_weapon_sound" overload
		("2cm_Flakvierling")
	}
	("multi_barrel_loop" flash(tank_canon_fire_20_25_auto) smoke(smoke_zenit) shell(zenit_gilz) weapon(gun) head(0.200))
}



;;============================================== ENG AIR reactive ==========================

;;============================================== ENG AIR transport =========================
{"c47_d_eng"
	("c47_sound")
	{on spawn
		("tag_airborne_cargo")
		("tag_airborne_eng")
		{tags add "eng"}
	}
	{on "add_weapon_sound" overload
		{link_sound 	"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 	"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}
	}
	
	{on "engine_count" overload
		{tags add "engine_count_2"}
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

{"c47_d_eng_player"
	("c47_sound")
	{on spawn
		("tag_airborne_cargo")
		("tag_airborne_eng")
		{tags add "eng"}
	}
	{on "add_weapon_sound" overload
		{link_sound 	"MG_Mid"		"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound 	"MG_Far"		"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
		{link_sound	 	"MG_Mid_1"		"weapon/shot/smallarms/s3/d2/Shared/Maxim_Gun/"}
		{link_sound	 	"MG_Far_1"		"weapon/shot/smallarms/s3/d3/Shared/Maxim_Gun/"}
	}
	
	{on "engine_count" overload
		{tags add "engine_count_2"}
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