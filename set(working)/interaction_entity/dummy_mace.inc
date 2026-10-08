
;(include "dummy.inc")
;/***=========== DUMMY MACE START ===========***/
{"bangalore_torpedo_dummy"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on spawn
		{delay 15
			{delay 0.1 {spawn "explosion_bangalore"} {spawn "shockwave_sphere"} {spawn "crater_massive" "basis" x terrain_texmod} {delete}}
		}
	}
	{on blast							;// blastwave hits specific volume
		{if min_energy 4
		{delay 0
			{delete}
			{spawn "shockwave_sphere"}
			{spawn "crater_massive" "basis" x terrain_texmod}
			{spawn "explosion_bangalore"}
		}					
		}
	}		
}

{"ussr_smoke_barrel1_is3"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on spawn
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{add_view "smoke_size3" "smoke1" "basis"}
		{add_view "smoke_grenade_launcher" "smoke2" "basis"}
		{add_view "smoke_cover_big" "smoke3" "basis"}

		{delay 5
			{view start "smoke2"}
		}
		{delay 10
			{view start "smoke1"}
			{spawn "smoke_volume_cylinder" {delay 145 {hide 1}}}
		}
		{delay 13
			("spawn_volume" args cylinder 110 0 130)
			("spawn_volume" args cylinder -110 0 130)
			("spawn_volume" args cylinder 0 110 130)
			("spawn_volume" args cylinder 0 -110 130)
			("spawn_volume" args cylinder 110 110 130)
			("spawn_volume" args cylinder -110 -110 130)
			("spawn_volume" args cylinder -110 110 130)
			("spawn_volume" args cylinder 110 -110 130)
		}
		{delay 15
			("spawn_volume" args cylinder_sm 220 0 127)
			("spawn_volume" args cylinder_sm -220 0 127)
			("spawn_volume" args cylinder_sm 0 220 127)
			("spawn_volume" args cylinder_sm 0 -220 127)
		}
		{delay 70
			{view stop "smoke2"}
		}	
		{delay 135
			{view stop "smoke1"}
			{view start "smoke3"}
		}
		{delay 150
			{view pause "smoke3"}
			{hide 1}
		}
	}
}

{"ussr_smoke_barrel2_is3"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on spawn
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{add_view "smoke_size3" "smoke1" "basis"}
		{add_view "smoke_grenade_launcher" "smoke2" "basis"}
		{add_view "smoke_cover_big" "smoke3" "basis"}

		{delay 5
			{view start "smoke2"}
		}
		{delay 10
			{view start "smoke1"}
			{spawn "smoke_volume_cylinder" {delay 145 {hide 1}}}
		}
		{delay 13
			("spawn_volume" args cylinder 110 0 130)
			("spawn_volume" args cylinder -110 0 130)
			("spawn_volume" args cylinder 0 110 130)
			("spawn_volume" args cylinder 0 -110 130)
			("spawn_volume" args cylinder 110 110 130)
			("spawn_volume" args cylinder -110 -110 130)
			("spawn_volume" args cylinder -110 110 130)
			("spawn_volume" args cylinder 110 -110 130)
		}
		{delay 15
			("spawn_volume" args cylinder_sm 220 0 127)
			("spawn_volume" args cylinder_sm -220 0 127)
			("spawn_volume" args cylinder_sm 0 220 127)
			("spawn_volume" args cylinder_sm 0 -220 127)
		}
		{delay 70
			{view stop "smoke2"}
		}	
		{delay 135
			{view stop "smoke1"}
			{view start "smoke3"}
		}
		{delay 150
			{view pause "smoke3"}
			{hide 1}
		}
	}
}

{"ussr_smoke_barrel1_t34_100"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on spawn
		{add_view "smoke_size2" "smoke1" "basis"}
		{add_view "smoke_grenade_launcher" "smoke2" "basis"}
		{add_view "smoke_cover_big" "smoke3" "basis"}
		{delay 5
			{view start "smoke2"}
		}
		{delay 10
			{view start "smoke1"}
			{spawn "smoke_volume_cylinder" {delay 145 {hide 1}}}
		}
		{delay 13
			("spawn_volume" args cylinder 110 0 130)
			("spawn_volume" args cylinder -110 0 130)
			("spawn_volume" args cylinder 0 110 130)
			("spawn_volume" args cylinder 0 -110 130)
			("spawn_volume" args cylinder 110 110 130)
			("spawn_volume" args cylinder -110 -110 130)
			("spawn_volume" args cylinder -110 110 130)
			("spawn_volume" args cylinder 110 -110 130)
		}
		{delay 70
			{view pause "smoke2"}
		}	
		{delay 135
			{view pause "smoke1"}
			{view start "smoke3"}
		}
		{delay 150
			{view pause "smoke3"}
			{hide 1}
		}
	}
}

{"ussr_smoke_barrel2_t34_100"			;// causes flamer thrower fuel to burn up after delay (disables far shooting)
	{on spawn
		{add_view "smoke_size3" "smoke1" "basis"}
		{add_view "smoke_grenade_launcher" "smoke2" "basis"}
		{add_view "smoke_cover_big" "smoke3" "basis"}
		{delay 5
			{view start "smoke2"}
		}
		{delay 10
			{view start "smoke1"}
			{spawn "smoke_volume_cylinder" {delay 145 {hide 1}}}
		}
		{delay 13
			("spawn_volume" args cylinder 110 0 130)
			("spawn_volume" args cylinder -110 0 130)
			("spawn_volume" args cylinder 0 110 130)
			("spawn_volume" args cylinder 0 -110 130)
			("spawn_volume" args cylinder 110 110 130)
			("spawn_volume" args cylinder -110 -110 130)
			("spawn_volume" args cylinder -110 110 130)
			("spawn_volume" args cylinder 110 -110 130)
		}
		{delay 70
			{view pause "smoke2"}
		}	
		{delay 135
			{view pause "smoke1"}
			{view start "smoke3"}
		}
		{delay 150
			{view pause "smoke3"}
			{hide 1}
		}
	}
}

{"type_99_candle_logic"
	{on spawn
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
		{add_view "spark_grenade"				"sparks" "root"}
		{add_view "smoke_grenade_launcher_init"	"smoke0" "root"}
		{add_view "smoke_grenade_launcher"		"smoke1" "root"}
		{add_view "smoke_cover_norm"			"smoke2" "root"}
		{add_view "smoke_cover_big"				"smoke3" "root"}
		{delay 4.5
			{if not tagged "activated"
				{tags add "activated"}
				{call "activate"}
			}
		}
	}
	{on ground_hit
		{if tagged "activated"
			{if name "water"
				{hide 1}
				{kill_delay "smoke"}
			}
		}
	}
	(define "spawn_volume"
		{spawn "smoke_volume_%0" offset %1 %2 0
			{delay %3 {hide 1}}
		}
	)
	(define "smoke_time" 
		{on "activate" overload
			{volumes disable touch select}
			{play_sound "smoke_pop"}
			{play_sound "smoke_loop" 1}
			{view start "smoke1"}
			{view start "smoke2"}
			{view start "sparks"}
			{delay 1.5 "smoke"
				{view stop "sparks"}
				{delay 1 "smoke"
					{view start "smoke2"}
					("spawn_volume" args cylinder 0 110 %0)		;4
					("spawn_volume" args cylinder 0 0 %0)		;5
					("spawn_volume" args cylinder 0 -110 %0)	;6
					("spawn_volume" args cylinder 110 110 %0)	;1
					("spawn_volume" args cylinder 110 0 %0)		;2
					("spawn_volume" args cylinder 110 -110 %0)	;3
					("spawn_volume" args cylinder -110 110 %0)	;7
					("spawn_volume" args cylinder -110 0 %0)	;8
					("spawn_volume" args cylinder -110 -110 %0)	;9
				}
			}
			{delay 6 "smoke"
				{view start "smoke3"}
				("spawn_volume" args cylinder_sm 220 0 %1)
				("spawn_volume" args cylinder_sm -220 0 %1)
				("spawn_volume" args cylinder_sm 0 220 %1)
				("spawn_volume" args cylinder_sm 0 -220 %1)
			}
			{delay %0 "smoke"
				{call "delete_grenade"}
			}
		}
	)
	("smoke_time" args 84 82)
	{on "delete_grenade"
		{delay 0 "smoke"
			{view stop "smoke3"}
		}
		{delay 15 "smoke"
			{view stop "smoke2"}
		}
		{delay 20 "smoke"
			{view stop "smoke1"}
			{view start "smoke0"}
			{stop_sound "smoke_loop"}
			{play_sound "smoke_end"}
		}
		{delay 30 "smoke"
			{view stop "smoke0"}
		}
		{delay 35 "smoke"
			{hide 1}
		}
	}
}

{"killzone_veh_gas_600"
	{on spawn
		{delay 2 {delete}}
	}
}

{"killzone_inf_gas_600"
	{on spawn
		{delay 2 {delete}}
	}
}

{"killzone_veh_gas_light_600"
	{on spawn
		{delay 2 {delete}}
	}
}

{"killzone_inf_gas_light_600"
	{on spawn
		{delay 2 {delete}}
	}
}

{"killzone_wanze_charger_1200"
	{on spawn
		{delay 2 {delete}}
	}
}

{"empty_bomb" ;//MACE USED FOR PLANES THAT DON'T HAVE BOMBS
	{on spawn
		{delay 0.5 {delete}}
	}	
}

{"booster_explosion"
	{on blast							;// blastwave hits specific volume
		{if volume "bomb"
			{if stuff "mine"
				{if min_energy 4
					{spawn "explosion_booster" {delete}}
				}
			else min_energy 12.1 ;//150mm HE
				{if rand 1 {spawn "explosion_booster"} {delete}}
				
			else min_energy 7.1 ;//105mm HE
				{if rand 0.5 {spawn "explosion_booster"} {delete}}
			else min_energy 3.1 ;//75mm HE
				{if rand 0.5 {spawn "explosion_booster"} {delete}}
			}
		}
		{if volume "booster"
			{if stuff "mine"
				{if min_energy 4
					{spawn "explosion_booster" {delete}}
				}
			else min_energy 12.1 ;//150mm HE
				{if rand 1 {spawn "explosion_booster"} {delete}}
				
			else min_energy 7.1 ;//105mm HE
				{if rand 0.5 {spawn "explosion_booster"} {delete}}
			else min_energy 3.1 ;//75mm HE
				{if rand 0.5 {spawn "explosion_booster"} {delete}}
			}
		}
	}
	{on pierce sync
		{if volume "bomb"
			{if stuff "bullet"
				{if rand 0.25 {spawn "explosion_booster"} {delete}}
			else stuff "ptr"
				{if rand 0.25 {spawn "explosion_booster"} {delete}}	
			else stuff "shell size1"
				{if rand 0.5 {spawn "explosion_booster"} {delete}}
			else stuff "shell size2"  ;//75mm
				{if rand 0.5 {spawn "explosion_booster"} {delete}}
			else stuff "shell size3"  ;//105mm
				{if rand 0.5 {spawn "explosion_booster"} {delete}}
			else stuff "shell"  ;//150mm and up
				{if rand 1 {spawn "explosion_booster"} {delete}}
			}
		}
		{if volume "booster"
			{if stuff "bullet"
				{if rand 0.25 {spawn "explosion_booster"} {delete}}
			else stuff "ptr"
				{if rand 0.25 {spawn "explosion_booster"} {delete}}	
			else stuff "shell size1"
				{if rand 0.5 {spawn "explosion_booster"} {delete}}
			else stuff "shell size2"  ;//75mm
				{if rand 0.5 {spawn "explosion_booster"} {delete}}
			else stuff "shell size3"  ;//105mm
				{if rand 0.5 {spawn "explosion_booster"} {delete}}
			else stuff "shell"  ;//150mm and up
				{if rand 1 {spawn "explosion_booster"} {delete}}
			}
		}
	}
}

{"10kg_naval_smoke_candle_entity"
	{on spawn
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
		{add_view "spark_grenade"				"sparks" "fx_smoke"}
		{add_view "smoke_grenade_launcher_init"	"smoke0" "fx_smoke"}
		{add_view "smoke_grenade_launcher"		"smoke1" "fx_smoke"}
		{add_view "smoke_cover_norm"			"smoke2" "fx_smoke"}
		{add_view "smoke_cover_norm"			"smoke_extra1" "fx_smoke_extra1"}
		{add_view "smoke_cover_norm"			"smoke_extra2" "fx_smoke_extra2"}
		{add_view "smoke_cover_norm"			"smoke_extra3" "fx_smoke_extra3"}
		{add_view "smoke_cover_norm"			"smoke_extra4" "fx_smoke_extra4"}
		{add_view "smoke_cover_norm"			"smoke_extra5" "fx_smoke_extra5"}
		{add_view "smoke_cover_norm"			"smoke_extra6" "fx_smoke_extra6"}
		{add_view "smoke_cover_norm"			"smoke_extra7" "fx_smoke_extra7"}
		{add_view "smoke_cover_norm"			"smoke_extra8" "fx_smoke_extra8"}
		{add_view "smoke_cover_big"			"smoke3" "fx_smoke"}
		{add_view "smoke_size4"				"smoke4" "fx_smoke"}
		{call "activate"}
		{delay 0.5
			{if not tagged "activated"
				{tags add "activated"}
				{play_sound "smoke_loop" 1}
				{view start "sparks"}
				{delay 152
					{view stop "sparks"}
				}
				{call "activate"}
			}
		}
	}
	{on ground_hit
		{if tagged "activated"
			{if name "water"
				{hide 1}
				{kill_delay "smoke"}
			}
		}
	}
	(define "spawn_volume"
		{spawn "smoke_volume_%0" offset %1 %2 0
			{delay %3 {hide 1}}
		}
	)
	(define "smoke_time" 
		{on "activate" overload
			{volumes disable touch select}
			{play_sound "smoke_pop"}
			{view start "smoke1"}
			{view start "smoke2"}
			{view start "smoke4"}
			{delay 1.5 "smoke"
				{delay 1 "smoke"
					{view start "smoke2"}
					("spawn_volume" args cylinder 0 110 %0)		;4
					("spawn_volume" args cylinder 0 0 %0)		;5
					("spawn_volume" args cylinder 0 -110 %0)	;6
					("spawn_volume" args cylinder 110 110 %0)	;1
					("spawn_volume" args cylinder 110 0 %0)		;2
					("spawn_volume" args cylinder 110 -110 %0)	;3
					("spawn_volume" args cylinder -110 110 %0)	;7
					("spawn_volume" args cylinder -110 0 %0)	;8
					("spawn_volume" args cylinder -110 -110 %0)	;9

					
				}
			}
			{delay 3.5 "smoke"
					("spawn_volume" args cylinder -210 110 %0)	;7
					("spawn_volume" args cylinder -210 0 %0)	;8
					("spawn_volume" args cylinder -210 -110 %0)	;9
					("spawn_volume" args cylinder  210 110 %0)	;1
					("spawn_volume" args cylinder  210 0 %0)	;2
					("spawn_volume" args cylinder  210 -110 %0)	;3

					("spawn_volume" args cylinder  110   210 %0)	;1
					("spawn_volume" args cylinder  0     210 %0)	;2
					("spawn_volume" args cylinder  -110  210 %0)	;1
					("spawn_volume" args cylinder  -110 -210 %0)	;3
					("spawn_volume" args cylinder  0    -210 %0)	;3
					("spawn_volume" args cylinder  110  -210 %0)	;3

					{view start "smoke_extra1"}
					{view start "smoke_extra2"}
					{view start "smoke_extra3"}
					{view start "smoke_extra4"}

					{view start "smoke_extra5"}
					{view start "smoke_extra6"}
					{view start "smoke_extra7"}
					{view start "smoke_extra8"}
			}
			{delay 6 "smoke"
				{view start "smoke3"}
				("spawn_volume" args cylinder_sm 320 0 %1)
				("spawn_volume" args cylinder_sm -320 0 %1)
				("spawn_volume" args cylinder_sm 0 320 %1)
				("spawn_volume" args cylinder_sm 0 -320 %1)
			}
			{delay %0 "smoke"
				{call "delete_grenade"}
			}
		}
	)
	("smoke_time" args 164 162);84 82
	{on "delete_grenade"
		{delay 0 "smoke"
			{view stop "smoke3"}
			{view stop "smoke4"}
			{view stop "smoke_extra1"}
			{view stop "smoke_extra2"}
			{view stop "smoke_extra3"}
			{view stop "smoke_extra4"}

			{view stop "smoke_extra5"}
			{view stop "smoke_extra6"}
			{view stop "smoke_extra7"}
			{view stop "smoke_extra8"}
		}
		{delay 15 "smoke"
			{view stop "smoke2"}
		}
		{delay 20 "smoke"
			{view stop "smoke1"}
			{view start "smoke0"}
			{stop_sound "smoke_loop"}
			{play_sound "smoke_end"}
		}
		{delay 30 "smoke"
			{view stop "smoke0"}
		}
		{delay 35 "smoke"
			{hide 1}
		}
	}
}