
;/*=========== Explosive Grenade Begin ===========*/

{"grenade"
	{on spawn
		{call "add_grenade_sound"}
	}
	{on "onThrow"
		{call "grenade_fx"}
		{volumes "body" disable contact}
	}
	{on "onThrowActivate"
		{volumes "body" enable contact}
	}
	{on contact
		{if stuff_activated
			{if effector "human"
				{call "fall_down"}
		 	else effector "cannon"
				;{link_grenade_to_nearest_human teleport}
			}
		}
	}
	{on "activate"
		{call "hide_marker"}
	}
	{on "in_hole"
		{break_window_in_hole}
		{link_grenade_to_nearest_human}
	}
	{on ground_hit
		{if not terrain_fx "water"
			{link_sound "grenadehit" "hit/ground/grenade/"}
			{play_sound "grenadehit"}
		}
	}
	{on "fall_down"
		{volumes disable contact}
		{fall_down}
	}

	{on "show_marker1"
		{view start "marker1"}
		{view start "marker3"}
	}

	{on "show_marker2"
		{view pause "marker1"}
		{view start "marker2"}
		{view pause "marker3"}
		{view start "marker4"}
	}

	{on "hide_marker"
		{view stop "marker1"}
		{view stop "marker2"}
		{view stop "marker3"}
		{view stop "marker4"}
	}

	{on bullet_hit
		{stuff_detonate}
	}
	{on blast_hit
		{if min_energy 0.8
			{stuff_detonate}
		}
	}
}

{"grenade fg"
	{on "onThrow"
		{delay 1.5
			{call "show_marker1"}
		}
		{delay 3.5
			{call "show_marker2"}
		}
	}
}

{"grenade dynamite"
	{on "undermine"
		{delay 7
			{call "show_marker1"}
		}
		{delay 9
			{call "show_marker2"}
		}
	}
	{on "onThrow"
		{call "undermine"}
	}
}

{"grenade contact"
	{on ground_hit
		{if stuff_activated
			{if not name "water"
				{call "ground_detonate"}
			}
		}
	}
	{on "in_hole" overload}
	{on contact
		{if stuff_activated
			{if not tagged "mine_planted"
				{if not tagged "grounded"
					{call "contact_detonate"}
				}
			}
		}
	}
	{on "ground_detonate"
		{call "detonate"}
	}
	{on "contact_detonate"
		{call "detonate"}
	}
	{on "detonate"
		{volumes disable all}
		{stuff_detonate}
	}
	{on "fall_down" overload}
}

{"grenade contact mine"
	{on "onThrow" overload
		{volumes "body" disable contact}
		{volumes "body1" disable contact}
	}
	{on "onThrowActivate" overload
		{volumes "body1" enable contact}
	}

	{on "ground_detonate" overload
		{volumes "body" enable contact}
		{tags add "grounded"}
	}
}

{"grenade fire"
	{on spawn
		{add_view "molotov_lit" "lit" "wick"}
		{view hide "lit"}
		{play_sound "equip"}
	}
	{on "grenade_fx"
		{view show "lit"}
		{view start "lit"}
		{play_sound "loop" 1}
	}
	{on "ground_detonate"
		{fire radius 2.5 time 7 heating 1.5}
		{fire radius 1.5 time 20 heating 0.5}
	}
	{on "contact_detonate" overload
		{volumes disable bullet contact blast}
		{fire radius 1.25 time 2 heating 15 effector follow}
		{fire radius 1 time 20 heating 0.5 effector follow}
		{delay 0
			{call "detonate"}
		}
	}
	{on "onThrow"
		{play_sound "throw"}
	}
}

{"grenade fire big"
	{on "ground_detonate" overload
		{call "detonate"}
		{fire radius 2.5 time 7 heating 2.5}
		{fire radius 2.5 time 20 heating 0.5}
	}
	{on "contact_detonate" overload
		{volumes disable bullet contact blast}
		{fire radius 2.00 time 2 heating 25 effector follow}
		{fire radius 1 time 20 heating 0.5 effector follow}
		{delay 0.01
			{call "detonate"}
		}
	}
}

{"grenade magnetic"
	{on contact 
		{if material "steel"
			{physics_work 0}
			{volumes disable contact}
			{call "position_checker"}
		}
	}
	{on "position_checker"
		{volumes "body" enable contact}
		{delay 0 {physics_work 1}}
		{impulse up -0.01 com}
		{delay 0.25 "position_checker"
			{call "position_checker"}
		}
	}
}

{"grenade timed"
	{on contact
		{if stuff_activated
			{if effector "vehicle"
				{volumes disable bullet contact blast} ;// keeps grenade from detonating multiple times (multiple blastwaves)
				{stuff_detonate}
			}
		}
	}
}

;/*=========== Explosive Grenade End ===========*/

;/*=========== Smoke Grenade Begin ===========*/

{"grenade smoke"
	{on spawn
		{call "add_smoke"}
	}
	{on "add_smoke"
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on ground_hit
		{if stuff_activated
			{if not name "water"
				{if not tagged "activated"
					{tags add "activated"}
					{delay 3
						{call "activate"}
					}
				}
			else
				{hide 1}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not tagged "activated"
				{tags add "activated"}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
	{on "activate"
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{play_sound "smoke_loop" 1}
		{view start "smoke1"}
		{view start "smoke2"}
		{spawn "smoke_volume_cylinder" {delay 85 {hide 1}}}
		{delay 3
			{view start "smoke3"}
			("spawn_volume" args cylinder 110 0 84)
			("spawn_volume" args cylinder -110 0 84)
			("spawn_volume" args cylinder 0 110 84)
			("spawn_volume" args cylinder 0 -110 84)
			("spawn_volume" args cylinder 110 110 84)
			("spawn_volume" args cylinder -110 -110 84)
			("spawn_volume" args cylinder -110 110 84)
			("spawn_volume" args cylinder 110 -110 84)
			{delay 2
				{view stop "smoke1"}
				{view stop "smoke2"}
			}
		}
		{delay 5
			("spawn_volume" args cylinder_sm 220 0 82)
			("spawn_volume" args cylinder_sm -220 0 82)
			("spawn_volume" args cylinder_sm 0 220 82)
			("spawn_volume" args cylinder_sm 0 -220 82)
		}
		{delay 85
			{view stop "smoke3"}
			{stop_sound "smoke_loop"}
			{play_sound "smoke_end"}
		}
		{delay 90
			{hide 1}
		}
	}
	{on blast_hit overload}			;// keeps smoke grenades from deleting by blast damage after being thrown
	{on bullet_hit overload}		;// keeps smoke grenades from deleting by bullet hit after being thrown
}

{"grenade smoke detonate wp"
	{on "activate" overload
		{if not tagged "activate"
			{tags add "activate"}
			{fire radius 1.25 time 1 heating 10}
			{play_sound "explode"}
			{delay 1
				{play_sound "burn_down"}
				{play_sound "smoke_loop"}
			}
			{spawn "ex_wp_grenade"}
			{spawn "shell_smoke_wp_size2"}
			{delay 60
				{stop_sound "smoke_loop"}
				{play_sound "smoke_end"}
				{delete}
			}
		}
	}
}

{"grenade smoke detonate sm"
	{on "activate" overload
		{if not tagged "activate"
			{tags add "activate"}
		{start_sound "detonation/he_size1/bkg/" use_position}
		{spawn "mortar_smoke"}
		{spawn "shell_smoke"}
		{delay 1
			{delete}
		}
	}
}
}

{"grenade smoke launcher"			;// Smoke grenades for vehicles
	{on "add_smoke" overload
		{add_view "spark_grenade"				"sparks" "fx_smoke"}
		{add_view "smoke_grenade_launcher_init"	"smoke0" "fx_smoke"}
		{add_view "smoke_grenade_launcher"		"smoke1" "fx_smoke"}
		{add_view "smoke_cover_norm"			"smoke2" "root"}
		{add_view "smoke_cover_big"				"smoke3" "root"}
	}
	{on "onThrow" overload
		{delay 0.2
			{if stuff_activated
				{if not tagged "activated"
					{tags add "activated"}
					{call "activate"}
				}
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
		{delay 5 "smoke"
			{view stop "smoke2"}
		}
		{delay 5 "smoke"
			{view stop "smoke1"}
			{view start "smoke0"}
			{stop_sound "smoke_loop"}
			{play_sound "smoke_end"}
		}
		{delay 10 "smoke"
			{view stop "smoke0"}
		}
		{delay 15 "smoke"
			{hide 1}
		}
	}
}

{"grenade smoke yellow"
	{on "add_smoke" overload
		{add_view "smoke_yellow_small"	"smoke1" "root"}
		{add_view "smoke_yellow_norm"	"smoke2" "root"}
		;{add_view "smoke_yellow_big"	"smoke3" "root"}
	}
}

{"grenade smoke paradrop_ammo"
	{on "activate" overload
		{volumes disable touch select}
		{play_sound "smoke_pop"}
		{play_sound "smoke_loop" 1}
		{view start "smoke1"}
		{delay 1.5 "smoke"
			{view start "smoke2"}
		}
		{delay 6 "smoke"
			;{view start "smoke3"}
		}
		{delay 9
			{start_sound "vehicle/airborne/cargo_plane_flyby.wav"}
		}
		{delay 17 "smoke"
			{call "spawn_ammo_crate"}
		}
		{delay 20 "smoke"
			;{view stop "smoke3"}
			{stop_sound "smoke_loop"}
			{play_sound "smoke_end"}
			{hide 1}
		}
	}
}

{"grenade smoke paradrop_ammo rus"
	{on "spawn_ammo_crate"
		{spawn "paradrop_ammo_rus" random_position 100 offset 0 0 1000}
	}
}
{"grenade smoke paradrop_ammo ger"
	{on "spawn_ammo_crate"
		{spawn "paradrop_ammo_ger" random_position 100 offset 0 0 1000}
	}
}
{"grenade smoke paradrop_ammo fin"
	{on "spawn_ammo_crate"
		{spawn "paradrop_ammo_fin" random_position 100 offset 0 0 1000}
	}
}
{"grenade smoke paradrop_ammo usa"
	{on "spawn_ammo_crate"
		{spawn "paradrop_ammo_usa" random_position 100 offset 0 0 1000}
	}
}
{"grenade smoke paradrop_ammo jap"
	{on "spawn_ammo_crate"
		{spawn "paradrop_ammo_jap" random_position 100 offset 0 0 1000}
	}
}
{"grenade smoke paradrop_ammo eng"
	{on "spawn_ammo_crate"
		{spawn "paradrop_ammo_eng" random_position 100 offset 0 0 1000}
	}
}

;/*=========== Smoke Grenade End ===========*/

;/*=========== Throw Sounds Begin ===========*/



{"m24"
}

{"m24_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}
{"m24_smoke_supplies"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"m24_geballteladung"
}

{"molotov_cocktail"
	{on "add_grenade_sound" overload
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
		{link_sound "loop" "weapon/equip/grenade/molotov_loop"}
	}
}

{"molotov_cocktail_fin"
	{on "add_grenade_sound" overload
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
		{link_sound "loop" "weapon/equip/grenade/molotov_loop"}
	}
}

{"molotov_bundle_fin"
	{on "add_grenade_sound" overload
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
		{link_sound "loop" "weapon/equip/grenade/molotov_loop"}
	}
}

{"rdg1_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	("smoke_time" args 114 112)
}

{"rdg1_smoke_supplies"
	{on "add_grenade_sound"
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"51mm_eng_mortar_sm"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"nbk39"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	("smoke_time" args 144 142)
}

{"no8_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"nbks"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	("smoke_time" args 60 58)
}

{"svkkr_pm"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	("smoke_time" args 60 58)
}

{"m42_wp"
	{on "add_grenade_sound"
		{link_sound "explode" 	"detonation/grenade_wp/explode/"}
		{link_sound "burn_down" "detonation/grenade_wp/burn_down/"}
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop" "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"m43_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"pwm_l"
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"rpg40"
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"rpg43"
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
}

{"anm8_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"m15_wp"
	{on "add_grenade_sound"
		{link_sound "explode" 	"detonation/grenade_wp/explode/"}
		{link_sound "burn_down" "detonation/grenade_wp/burn_down/"}
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop" "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"no74"
	{on "grenade_fx"
		{tear "piece_tiny_steel" bone "casing1" {impulse forward 1.01 0.25 dir 1 1 rnd_dir 1}}
		{tear "piece_tiny_steel" bone "casing2" {impulse forward -1.01 0.25  dir -1 1 rnd_dir -1}}
	}
}

{"no82"
}

{"no77_wp"
	{on "add_grenade_sound"
		{link_sound "explode" 	"detonation/grenade_wp/explode/"}
		{link_sound "burn_down" "detonation/grenade_wp/burn_down/"}
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop" "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	
	{on "detonate" overload
		{call "activate"}
	}
}

;=========== Throw Sounds End ===========*/
;/*=========== Explosive Grenade Begin MACE ===========*/

{"grenade wp1"
	{on spawn
		{add_view "flash_fuse_small" "lit1" "fx_start"};start
		{add_view "flare_tail_green" "lit2" "root"};start

		{add_view "smoke_after_pen" "lit3" "root"} ;end

		{add_view "smoke_tiny" "lit4" "root"};midle
		{add_view "fire_tiny" "lit5" "root"};midle
		{add_view "white_phos" "lit6" "fx_sun"};midle +
		{add_view "flare_tail_green" "lit7" "fx_sun"};midle +

		{view hide "lit2"}
		{view hide "lit3"}
		{view hide "lit4"}
	}
	{on "onThrow"
		{call "activate"}
	}
	{on "activate" overload
		{if not tagged "activate"
			{tags add "activate"}
			{delay 0.1
				{play_sound "smoke_pop"}
				{view start "lit1"}
			}
		}	
		{delay 3
			{start_sound "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop" root}
			{view start "lit2"}
			{view stop "lit1"}
		}
		{delay 5.5
			{fire radius 3.5 time 45 heating 10}
			{spawn "ex_wp_size1"}
			{view start "lit4"}
			{view start "lit5"}
			{view start "lit7"}
			{spawn "fire_cooking_explosion"}
		{delay 30
			{spawn "fire_cooking_explosion"}
			{spawn "ex_wp_size1"}
		}
		}
		{delay 50
			{view stop "lit6"}
			{view stop "lit5"}
			{view stop "lit7"}
		}
		{delay 60
			{stop_sound "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop" root}
			{play_sound "smoke_end"}
			{view stop "lit2"}
			{view start "lit3"}
			{view stop "lit4"}
		}
		{delay 90	
			{delete}
		}
	}
}	



{"us_incendiary"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"grenade s_mine"
	{on "onThrow"
		{call "activate"}
	}
	{on "activate" 
		{delay 0.3
			{stuff_detonate}
		}
	}
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"grenade smoke paradrop_ammo_david usa"
	{on "spawn_ammo_crate"
		{spawn "paradrop_ammo_little_david" random_position 100 offset 0 0 1000}
	}
	{on "activate"
		{delay 3.5
			{spawn "paradrop_ammo_little_david" random_position 100 offset 0 0 1000}
		}
	}
}

{"anm8_smoke_supplies"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"grenade smoke paradrop_M22 usa"
	{on "spawn_ammo_crate"
		{spawn "paradrop_m22" random_position 100 offset 0 0 1000}
		{start_sound "vehicle/airborne/cargo_plane_flyby.wav"}
	}
	{on "activate"
		{delay 3.5
			{spawn "paradrop_m22" random_position 100 offset 0 0 1000}
			{start_sound "vehicle/airborne/cargo_plane_flyby.wav"}
		}
	}
}

{"anm8_smoke_paradrop_M22"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"type94_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"type97"
	{on "onThrow"
		{view hide "fuze"}
		{if rand 0.12
			{delay 3
				{stuff_detonate}
				{call "detonate"}
			}
		}
	}
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"type99"
	{on "onThrow"
		{view hide "fuze"}
		{view hide "cap"}
	}
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"type91_wp"
	{on "add_grenade_sound"
		{link_sound "explode" 	"detonation/grenade_wp/explode/"}
		{link_sound "burn_down" "detonation/grenade_wp/burn_down/"}
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop" "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	{on "onThrow"
		{view hide "fuze"}
		{if rand 0.12
			{delay 3
				{stuff_detonate}
				{call "detonate"}
			}
		}
	}
}

{"type_4_grenade"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
	}
	{on "onThrow"
		{view hide "Type_4_Cap"}
		{play_sound "smoke_pop"}
		{tags add "activated"}
	}
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
	{on ground_hit
		{if tagged "activated"
			{if terrain_fx "ground"
				{if rand 0.5
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "rock"
				{if rand 0.7
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "sand"
				{if rand 0.3
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "puddle"
				{if rand 0.4
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "mud"
				{if rand 0.4
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "grass"
				{if rand 0.6
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "bridge"
				{if rand 0.7
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "bridge_wood"
				{if rand 0.7
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "road"
				{if rand 0.7
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "country_road"
				{if rand 0.7
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "ice"
				{if rand 0.7
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "bridge_steel"
				{if rand 0.7
					{stuff_detonate}
					{call "detonate"}
				}
			else terrain_fx "snow"
				{if rand 0.3
					{stuff_detonate}
					{call "detonate"}
				}
			}
		}
	}
}

{"type_98_grenade"
	{on "onThrow"
		{view hide "Type_98_Cap"}
	}
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"type_99_smoke_candle_grenade"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	{on "onThrow"
		{view hide "Type_99_cap_top"}
	}
}

{"10kg_naval_smoke_candle_grenade" 
	{on spawn overload
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
	}
	{on "onThrow" overload
		{delay 0.2
			{if stuff_activated
				{if not tagged "activated"
					{tags add "activated"}
					{call "activate"}
					{play_sound "smoke_loop" 1}
					{view start "sparks"}
					{delay 152
						{view stop "sparks"}
					}
				}
			}
		}
	}
	{on ground_hit overload
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
	{on "delete_grenade" overload
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

{"jap_incendiary"
	{on spawn 
			{link_sound "throw"	"weapon/shot/grenade/grenade_throw"}
	}
	{on "onThrow" 
			{play_sound "throw"}
			{view hide "cap"}
			{view hide "pin"}
			{view hide "rope"}
	}
	{on "contact_detonate" overload
		{volumes disable bullet contact blast}
		{fire radius 2.5 time 20 heating 25 effector follow}
		{fire radius 1.5 time 20 heating 0.5 effector follow}
		{delay 0.01
			{call "detonate"}
		}
	}
	{on "ground_detonate" overload
		{if terrain_fx "ground"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "rock"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "sand"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "puddle"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "mud"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "grass"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "bridge"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "bridge_wood"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "road"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "country_road"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "ice"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "bridge_steel"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else terrain_fx "snow"
				{volumes disable all}
				{spawn "ex_ic_120_ground" "root"}
				{spawn "ex_wp_grenade" "root"}
				{fire radius 3.5 time 20 heating 3.5}
				{fire radius 3.5 time 20 heating 0.5}
				{stuff_detonate}
			else
				{spawn "ex_glass_ic_air" "root"}
				{spawn "ex_ic_120_ground" "root"}
		}			
	}
}

{"type10"
	{on "onThrow"
		{if rand 0.12
			{delay 3
				{stuff_detonate}
				{call "detonate"}
			}
		}
	}			
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"molotov_jap"
	{on "add_grenade_sound" overload
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
		{link_sound "loop" "weapon/equip/grenade/molotov_loop"}
	}
}

{"type11_wp"
	{on "onThrow"
		{view hide "fuze"}
	}
	{on "add_grenade_sound"
		{link_sound "explode" 	"detonation/grenade_wp/explode/"}
		{link_sound "burn_down" "detonation/grenade_wp/burn_down/"}
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop" "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"type_23_grenade"
	{on "onThrow"
		{view hide "fuze"}
	}
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"eihandgranaat_no_1"
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}
{"glass_smoke"
	{on "add_grenade_sound" overload
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
		{link_sound "break" "hit/glass/bullet"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	{on spawn
		{call "add_smoke"}
		{play_sound "equip"}
	}
	{on "add_smoke"
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
	}
	{on "onThrow"
		{volumes disable touch select}
		{play_sound "throw"}
	}
	{on ground_hit
		{if stuff_activated
			{fire radius 1.25 time 1 heating 10}
			{play_sound "break"}
			{view hide "cap"}
			{view hide "liquid"}
			{view hide "fragible_smoke_grenade"}
			{delay 0.1
				{spawn "ex_wp_size1"}
			}
			{if not name "water"
				{if not tagged "activated"
					{tags add "activated"}
					{call "activate"}
				}
			else
				{hide 1}
			}
		}
	}
	{on contact
		{if stuff_activated
			{play_sound "break"}
			{view hide "cap"}
			{view hide "liquid"}
			{view hide "fragible_smoke_grenade"}
			{delay 0.1	
				{spawn "ex_wp_size1"}
			}
			{if not tagged "activated"
				{tags add "activated"}
				{call "activate"}
			}
		}
	}
	{on "activate"
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{play_sound "smoke_loop" 1}
		{view start "smoke1"}
		{view start "smoke2"}
		{spawn "smoke_volume_cylinder" {delay 85 {hide 1}}}
		{delay 3
			{view start "smoke3"}
			("spawn_volume" args cylinder 110 0 84)
			("spawn_volume" args cylinder -110 0 84)
			("spawn_volume" args cylinder 0 110 84)
			("spawn_volume" args cylinder 0 -110 84)
			("spawn_volume" args cylinder 110 110 84)
			("spawn_volume" args cylinder -110 -110 84)
			("spawn_volume" args cylinder -110 110 84)
			("spawn_volume" args cylinder 110 -110 84)
			{delay 2
				{view stop "smoke1"}
				{view stop "smoke2"}
			}
		}
		{delay 5
			("spawn_volume" args cylinder_sm 220 0 82)
			("spawn_volume" args cylinder_sm -220 0 82)
			("spawn_volume" args cylinder_sm 0 220 82)
			("spawn_volume" args cylinder_sm 0 -220 82)
		}
		{delay 85
			{view stop "smoke3"}
			{stop_sound "smoke_loop"}
			{play_sound "smoke_end"}
		}
		{delay 90
			{hide 1}
		}
	}
	{on blast_hit overload}			;// keeps smoke grenades from deleting by blast damage after being thrown
	{on bullet_hit overload}		;// keeps smoke grenades from deleting by bullet hit after being thrown
}

{"molotov_smoke_jap"
	{on "add_grenade_sound" overload
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
	}
	{on spawn
		{play_sound "equip"}
	}
	{on "onThrow"
		{volumes disable touch select}
		{play_sound "throw"}
	}
	{on ground_hit
		{start_sound "detonation/he_size1/bkg/" use_position}
		{spawn "mortar_smoke"}
		{spawn "shell_smoke"}
		{delay 0.1
			{delete}
		}
	}
	{on contact
		{start_sound "detonation/he_size1/bkg/" use_position}
		{spawn "mortar_smoke"}
		{spawn "shell_smoke"}
		{delay 0.1
			{delete}
		}
	}
	{on blast_hit overload}			;// keeps smoke grenades from deleting by blast damage after being thrown
	{on bullet_hit overload}		;// keeps smoke grenades from deleting by bullet hit after being thrown
}

{"type_99_smoke_candle_grenade_supplies"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	{on "onThrow"
		{view hide "Type_99_cap_top"}
	}
}

{"m24_smoke_supplies_fin"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"anm8_smoke_supplies_eng"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"mortarusa_60_wp"
	{on "add_grenade_sound"
		{link_sound "explode" 	"detonation/grenade_wp/explode/"}
		{link_sound "burn_down" "detonation/grenade_wp/burn_down/"}
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop" "detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	
	{on "detonate" overload
		{call "activate"}
	}
}

{"type_99_smoke_candle_grenade_tank"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
	("smoke_time" args 144 142)
}

{"gongxian_smoke"
	{on "add_grenade_sound"
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
	}
}

{"chi_pottery_ic"
	{on "add_grenade_sound" overload
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
		{link_sound "loop" "weapon/equip/grenade/molotov_loop"}
	}
}

{"chi_pottery_smoke"
	{on "add_grenade_sound" overload
		{link_sound "smoke_pop"	"detonation/grenade_smoke/generic/pop"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{link_sound "smoke_end"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_end_01"}
		{link_sound "equip" "weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" "weapon/shot/grenade/molotov_throw"}
	}
	{on spawn
		{play_sound "equip"}
	}
	{on "onThrow"
		{volumes disable touch select}
		{play_sound "throw"}
	}
	{on ground_hit
		{start_sound "detonation/he_size1/bkg/" use_position}
		{spawn "mortar_smoke"}
		{spawn "shell_smoke"}
		{delay 0.1
			{delete}
		}
	}
	{on contact
		{start_sound "detonation/he_size1/bkg/" use_position}
		{spawn "mortar_smoke"}
		{spawn "shell_smoke"}
		{delay 0.1
			{delete}
		}
	}
	{on blast_hit overload}			;// keeps smoke grenades from deleting by blast damage after being thrown
	{on bullet_hit overload}		;// keeps smoke grenades from deleting by bullet hit after being thrown
}
;=========== MACE End ===========*/