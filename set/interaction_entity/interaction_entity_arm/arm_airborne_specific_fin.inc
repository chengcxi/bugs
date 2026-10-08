; File: 		arm_airborne_specific_fin.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm
; Created by: 	Max Drechsler
; Created:		x.xx.xxxx
; Modify by:	Max Drechsler
; Modify:		07.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		10.1
; Description: 

;;============================================== FIN BEGIN =======================================
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