; File: 		arm_airborne_specific_usa.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm
; Created by: 	Max Drechsler
; Created:		x.xx.xxxx
; Modify by:	Max Drechsler
; Modify:		07.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		10.1
; Description: 

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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("tag_airborne_bomber_ai")
		("tag_airborne_rus")	
	}
	{on "add_weapon_sound" overload
		("M2HB_M45_Mount")
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
		("tag_airborne_bomber_ai")
		("tag_airborne_rus")	
	}
	{on "add_weapon_sound" overload
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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


{"f80a_rockets_127x12_ai"
	("kikka_sound")
	{on spawn
		("tag_airborne_jet_fighter_ai")
		("tag_airborne_usa")
	}
	{on "add_weapon_sound" overload
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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
		("M2HB_M45_Mount")
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