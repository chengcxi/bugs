;;============================================== GER =======================================
;;============================================== GER CARs ==============================================
{"v1"
	("opel_sound")
	;	("tag_ai_arty_mace")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	
	("rocket_weapon" args gun)		;// defines weapon place that is disabled while vehicle is on move

	{on break
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

{"blitz3_6_raketenwerfer"
	("opel_sound")
	;	("tag_ai_arty_mace")	
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

;;---------------------------------------------- opel_blitz_omnibus
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

;----------------------------------------------- 88mm-raketenwerfer43 	-non
{"88mm-raketenwerfer43"
	("cannon_small")
	;	("tag_ai_arty_mace")
}

;;---------------------------------------------- sdkfz6_supply
{"sdkfz6_supply"
	("hanomag_sound")
}

;;---------------------------------------------- sdkfz6_weapon
{"sdkfz6_weapon"
	("hanomag_sound")
}

;;---------------------------------------------- sdkfz10_open
{"sdkfz10_open"
	("hanomag_sound")
}

;;---------------------------------------------- sdkfz251_20
{"sdkfz251_20 tank"
	("hanomag_sound")
}

;------------------------------------------------ [non] [checked]
{"zgkw303f"
	("hanomag_sound")
}

;----------------------------------------------- ba6_roa
{"ba6_roa"
	("ba_sound")
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("DT")
	}	
}