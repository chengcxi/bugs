; File: 		arm_airborne_specific_eng.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm
; Created by: 	Max Drechsler
; Created:		x.xx.xxxx
; Modify by:	Max Drechsler
; Modify:		07.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		10.1
; Description: 

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