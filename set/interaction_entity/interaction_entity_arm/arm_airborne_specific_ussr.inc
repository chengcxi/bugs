; File: 		arm_airborne_specific_rus.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm
; Created by: 	Max Drechsler
; Created:		x.xx.xxxx
; Modify by:	Max Drechsler
; Modify:		07.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		10.1
; Description: 

;;============================================== USSR BEGIN =======================================
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
		("SG43")
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

{"yak1_ser69_ai"
	("yak1_sound")
	{on spawn
		("tag_airborne_fighter_ai")
		("tag_airborne_rus")
	}
	{on "add_weapon_sound" overload
		("SG43")
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
		("SG43")
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

{"il2_mod41_ai"
	("il2_sound")
	{on spawn
		("tag_airborne_hvfighter_ai")
		("tag_airborne_rus")
		("SG43")
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


;;============================================== USSR AIR bomber ============================
{"il2_mod42"
	("il2_sound")
	{on spawn
		("tag_airborne_bomber")
		("tag_airborne_rus")
		("SG43")
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
		("SG43")
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