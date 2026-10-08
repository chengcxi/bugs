; File: 		arm_airborne_specific_ger.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm
; Created by: 	Max Drechsler
; Created:		x.xx.xxxx
; Modify by:	Max Drechsler
; Modify:		07.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		10.1
; Description: 

;;============================================== GER AIR ===================================
;;============================================== GER AIR recon =============================
{"ai_fi156"
	("fi156_sound")
	{on spawn
		("tag_airborne_recon_ai")
		("tag_airborne_ger")
	}
	{on "add_weapon_sound" overload
		("MG13")
	}
}

;;============================================== GER AIR fighter ===========================
{"bf109_e4b"
	("bf109_e4b_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_ger")
		("MG13")
	}
;//	{on "add_weapon_sound" overload
;//		("MG13")
;//	}
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
	{on "reload"		;// fillingVisible not working on single bomb weapons. Remove if ever fixed.
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
		("MG13")
	}
;//	{on "add_weapon_sound" overload
;//		("MG13")
;//	}
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
	{on "reload"		;// fillingVisible not working on single bomb weapons. Remove if ever fixed.
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
		("MG13")
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

{"bf109_f2_ai"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_ger")
		("MG13")
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
{"bf109_f4"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_ger")
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

{"bf109_f4_ai"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_ger")
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


{"bf109_g6"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter")
		("tag_airborne_ger")
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

{"bf109_g6_ai"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_ger")
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

{"bf109_g6_rocket_ai"
	("bf109_sound")
	{on spawn
		("tag_airborne_fighter_ai")
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
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
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
	}
}
{"me_262_rockets_210x2_ai"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_fighter_ai")
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
	}
}

{"me_262_rockets_250x2"
	("kikka_sound")
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

{"me_262_rockets_250x2_ai"
	("kikka_sound")
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





;//{"ju-52_para_plane"
;//	("ju-52_sound")
;//	
;//	{on spawn
;//		("tag_airborne_cargo")
;//		("tag_airborne_ger")
;//		{tags add "ger"}
;//	}
;//
;//}

;//{"c-47_skytrain_dakota"
;//	;("bf110_sound")
;//	("p47_sound")
;//	{on spawn
;//		{delay 0.2
;//			{tags add "allies"}
;//		}
;//	}
;//}

;//{"sm79_ai"
;//	("bf110_sound")
;//}
