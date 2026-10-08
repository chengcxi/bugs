;;============================================== GER =======================================
;;============================================== GER CARs ==============================================





;;---------------------------------------------- volvo
{"volvo"
	("volvo_sound")
}

;;---------------------------------------------- volvo_art
{"volvo_art"
	("volvo_sound")
}

;;---------------------------------------------- blitz3_6_open
{"blitz3_6_open"
	("opel_sound")
}

;;---------------------------------------------- kubelwagen_open
{"kubelwagen_open"
	("kubel_sound")
}

;;============================================== GER cars STATIC =====================================

{"ammo_trailer_stand" 
	{on spawn
		{delay 0.1
			{spawn "building_smoke" "service_bone"}
			{link_sound "deploy" "vehicle/deploy"}
			{play_sound "deploy"}
			{if terrain_fx "ice"
				{tex_mod "winter"}
			else terrain_fx "snow"
				{tex_mod "winter"}
			else
				; do nothing
			}
		}
	}
}

;;---------------------------------------------- kettenkrad_stand
{"kettenkrad_stand" 
	{on spawn
		{delay 0.1
			{spawn "building_smoke" "service_bone"}
			{link_sound "deploy" "vehicle/deploy"}
			{play_sound "deploy"}
			{if terrain_fx "ice"
				{tex_mod "winter"}
			else terrain_fx "snow"
				{tex_mod "winter"}
			else
				; do nothing
			}
		}
	}
}

;;---------------------------------------------- blitz3_6_radio_stand
{"blitz3_6_radio_stand" 
	{on spawn
		{delay 0.1
			{spawn "building_smoke" "service_bone"}
			{link_sound "deploy" "vehicle/deploy"}
			{play_sound "deploy"}
			{if terrain_fx "ice"
				{tex_mod "winter"}
			else terrain_fx "snow"
				{tex_mod "winter"}
			else
				; do nothing
			}
		}
	}
}

;;---------------------------------------------- blitz3_6_engineering_stand
{"blitz3_6_engineering_stand"
	("opel_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
}

;;---------------------------------------------- blitz3_6_fuel_stand
{"blitz3_6_fuel_stand"
	("opel_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
}

;;---------------------------------------------- blitz3_6_radio_stand
{"blitz3_6_radio_stand"
	("opel_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
	("animation_sound" args "open_radio")
}

;;---------------------------------------------- opel_maultier_stand
{"opel_maultier_stand"
	("opel_maultier_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

;;---------------------------------------------- kettenkrad_stand
{"kettenkrad_stand"
	("kettenkrad_sound")

	{on "wheel_torn_logic" overload
		{tags add "wheel_destroyed"}
	}
}

;;============================================== USSR ==========================================
;;============================================== USSR cars ==========================================
;;---------------------------------------------- cckw_ussr
{"cckw_ussr"
	("cckw_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

;;---------------------------------------------- 94km
{"94km"
	("zis5_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

;;---------------------------------------------- m72o
{"m72o"
	("r12_sound")
}

;;---------------------------------------------- zis5_61k
{"zis5_61k"
	("zis5_sound")
	{on "add_weapon_sound" overload
		("Autocannon_s1")
	}
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")

	{on fire "gun"
		{ani_play "recoil"}
		{view start "flashbarrel1"}
		{view start "flashbarrel1smoke"}
		{call "spawn_shell"}
	}
}

;;---------------------------------------------- gaz_aaa_open
{"gaz_aaa_open"
	("gaz_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

;;---------------------------------------------- gaz67_open
{"gaz67_open"
	("gaz_sound")
}

;;---------------------------------------------- zis5_open
{"zis5_open"
	("zis5_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}

;;---------------------------------------------- gaz_su12
{"gaz_su12"
	("zis5_sound")
	{on "add_weapon_sound" overload
		("DT")
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on fire "gun"
		{ani_play "recoil" +1}
	}
}

;;============================================== USSR cars STATIC =====================================

{"zis5eng_stand"
	("zis5_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
}

{"gaz_aaa_supply_stand"
	("gaz_sound")
}

{"gaz_fuel_stand"
	("gaz_sound")
}

{"gaz_aaa_supply_stand"
	("gaz_sound")
}

;;============================================== FIN ======================================================
;;============================================== FIN cars =================================================

;;---------------------------------------------- volvo_weapon
{"volvo_weapon"
	("volvo_sound")
}

;;============================================== FIN cars STATIC ==========================================

;;---------------------------------------------- ford_3ton_ammo_stand
{"ford_3ton_ammo_stand"
	("opel_sound")
}

;;---------------------------------------------- ford_3ton_eng_stand
{"ford_3ton_eng_stand"
	("opel_sound")
}

;;---------------------------------------------- ford_3ton_fuel_stand
{"ford_3ton_fuel_stand"
	("opel_sound")
}

;;============================================== USA ======================================================
;;============================================== USA cars =================================================
;;============================================== USA cars STATIC ==========================================

;;---------------------------------------------- cckw_engineer_late_stand
{"cckw_engineer_late_stand"
	("cckw_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")

	{on "commander_hatch_open" overload
		{ani_wind "cabin_cover" end}
	}
	{on "commander_hatch_close" overload
		{ani_wind "cabin_cover" begin}
	}
}

;;---------------------------------------------- cckw_redball_stand
{"cckw_redball_stand"
	("cckw_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")

	{on "commander_hatch_open" overload
		{ani_wind "cabin_cover" end}
	}
	{on "commander_hatch_close" overload
		{ani_wind "cabin_cover" begin}
	}
	{on spawn
		("rand_cut_else" args "redball1" "redball2")
	}
}

;;---------------------------------------------- cckw_fuel_stand
{"cckw_fuel_stand"
	("cckw_sound")
	
	("animation_sound" args "open_rear")
	("animation_sound" args "close_rear")
}