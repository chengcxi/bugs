;/*=========== Generic Weapon Settings Begin ===========*/

(define "shell_fx"
	{"stuff weapon %tag"
		{on spawn
			{add_view "%shell" "shell" "fxshell"}
		}
	}
)

("shell_fx" tag(pistol_shell)		shell(shell_pistol))
("shell_fx" tag(pistol2_shell)		shell(shell_pistol2))
("shell_fx" tag(inter_shell)		shell(shell_inter))
("shell_fx" tag(rifle_shell)		shell(shell_rifles))
("shell_fx" tag(hmg_shell)			shell(shell_hmgun))
("shell_fx" tag(ptr_shell)			shell(shell_ptr))
("shell_fx" tag(mgun_shell)			shell(shell_mgun))
("shell_fx" tag(shotgun_shell)		shell(shell_shotgun))

(define "flash_fx"
	{"stuff weapon %tag"
		{on spawn
			{if not prop "silenced"
				{add_view "%flash" "flashbarrel" "foresight%foresight"}
			else
				{add_view "flash_gun_silencer" "flashbarrel" "foresight%foresight"}
			}
		}
	}
)

("flash_fx" tag(pistol)			flash(flash_gun_small)	foresight(3))
("flash_fx" tag(smg)			flash(flash_gun_small)	foresight(11))
("flash_fx" tag(rifle)			flash(flash_gun_rifle)	foresight(12))
("flash_fx" tag(mgun)			flash(flash_gun_big)	foresight(14))
("flash_fx" tag(at_rifle)		flash(flash_gun_atrifle)foresight(18))
("flash_fx" tag(shotgun)		flash(flash_shotgun)	foresight(3))
("flash_fx" tag(murata)		    flash(flash_mortar_nosound)	foresight(12));MACE MURATA

(define "ejectsmoke_fx"
	{"stuff weapon %tag"
		{on spawn
			{add_view "%ejectsmoke" "ejectsmoke" "fxshell"}
		}
	}
)

("ejectsmoke_fx" tag(smg)		ejectsmoke(ejectsmoke_small))
("ejectsmoke_fx" tag(rifle)		ejectsmoke(ejectsmoke_small))
("ejectsmoke_fx" tag(mgun)		ejectsmoke(ejectsmoke_big))

(define "holster_fx"
	{"stuff weapon %tag"
		{on spawn
			{link_sound "holster"	"human/holster/%sound"}
		}
	}
)

("holster_fx" tag(pistol)			sound(pistol))
("holster_fx" tag(smg)				sound(weapon))
("holster_fx" tag(rifle)			sound(weapon))
("holster_fx" tag(mgun)				sound(weapon))
("holster_fx" tag(shotgun)			sound(weapon))
("holster_fx" tag(ptr)				sound(big))
("holster_fx" tag(bazooka)			sound(big))
("holster_fx" tag(flame_thrower)	sound(flame))
("holster_fx" tag(melee)			sound(knife))

(define "sound_fx"
	{"stuff weapon %tag"
		{on spawn
			{if not prop "silenced"
			}
		}
	}
)

("sound_fx" tag(pistol)		sound(smg))
("sound_fx" tag(smg)		sound(smg))
("sound_fx" tag(rifle)		sound(rifle))
("sound_fx" tag(mgun)		sound(mg))
("sound_fx" tag(at_rifle)	sound(hmg))
("sound_fx" tag(shotgun)	sound(rifle))

{"stuff weapon"
	{on "drop_item"}			;// when item is not in hand and is dropped from inventory.
	
	{on "fire"
		{play_sound "mid"}
		{play_sound "far"}
		{play_sound "action_recoil"}
		{ani_play "recoil"}
		{view show "flashbarrel"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view hide	"flashbarrel"}
			{view pause	"flashbarrel"}
		}
	}
	{on "link_human"
		{play_sound "holster"}
		{delay 0.4
			{ani_play "prepare"}
		}
	}
	{on "unlink_human"
		{ani_play "prepare" -1}
	}
	{on "case_eject"
		{view start "shell"}
		{view show	"ejectsmoke"}
		{view start	"ejectsmoke"}
		{delay 0.1 "shell"
			{view pause "shell"}
			{view hide	"ejectsmoke"}
			{view pause	"ejectsmoke"}
		}
	}
	{on "weapon_reload"
		{kill_delay "bolt_action"}
		{ani_play "reload"}
		{call "magazine_delay"}
		{play_sound "eject_clip"}
		{delay 0.075
			{stop_sound "action_recoil"}
		}
	}
	(define "magazine"
		{on "magazine_delay" %override
			{delay %cut
				{view hide "bullet"}
				{tear "piece_tiny_steel" bone "magazine" copy
					%impulse
				}
				{delay 0
					{view hide "magazine"}
					{delay %show
						{view show "magazine"}
						{view show "bullet"}
					}
				}
			}
		}
	)
	("magazine" cut(0) show(1.8) override() impulse({impulse up -0.01 com}))

	(define "drop"
		{on ground_hit %override
			{if terrain_fx "road"
				{start_sound "weapon/drop/%material/rock"}
			
			else terrain_fx "rock"
				{start_sound "weapon/drop/%material/rock"}

			else terrain_fx "ice"
				{start_sound "weapon/drop/%material/rock"}
			
			else terrain_fx "snow"
				{start_sound "weapon/drop/%material/snow"}
			
			else terrain_fx "sand"
				{start_sound "weapon/drop/%material/snow"}
			
			else terrain_fx "bridge_wood"
				{start_sound  "weapon/drop/%material/wood"}
			
			else terrain_fx "shallow_water"

			else terrain_fx "water"

			else
				{start_sound "weapon/drop/%material/ground"}
			}
		}
	)
	("drop" material(metal) override())
}

{"stuff weapon wood_stock"
	("drop" material(wood) override(overload))
}

{"stuff weapon auto_eject"
	{on "fire"
		{call "instant_eject"}
	}
	{on "instant_eject"
		{call "case_eject"}
	}
}

{"stuff weapon auto_eject semi_auto"
	{on "instant_eject" overload
		{delay 0.065
			{call "case_eject"}
		}
	}
}

{"stuff weapon bolt_action"
	{on "fire"
		{tags add "fired"}
		{delay 0.35 "bolt_action"
			{ani_play "bolt_action" 1.5}
			{play_sound "open_bolt"}
			{delay 0.2 
				{call "case_eject"}
			}
		}
		{delay 0.4
			{tags remove "fired"}
		}
		{delay 0.7 "bolt_action1"
			{play_sound "close_bolt"}
		}
	}
	{on "weapon_reload" overload
		{kill_delay "bolt_action"}
		{kill_delay "bolt_action1"}
		{ani_play "reload"}
		{delay 0.35 
			{play_sound "open_bolt"}
		}
		{if tagged "fired"
			{delay 0.55
				{call "case_eject"}
			}
		else
		}
		{delay 5.5
			{play_sound "close_bolt"}
		}
	}
}

{"stuff weapon shotgun_double"
	{on "weapon_reload" overload
		{delay 0.5
			{ani_play "reload"}
		}
		(define "double_shot"
			{delay %0
				{tear "piece_tiny_steel" bone "shell%1" copy
					{impulse up -0.01}
				}
				{delay 0
					{view hide "shell%1"}
					{delay 2.0
						{view show "shell%1"}
					}
				}
			}
		)
		("double_shot" args 0.9 1)
		("double_shot" args 1.00 2)
	}
}

{"stuff weapon shotgun_pump"
	{on "fire"
		{tags add "fired"}
		{delay 0.35 "bolt_action"
			{ani_play "bolt_action" 1.0}
			{play_sound "open_bolt"}
			{delay 0.2 
				{call "case_eject"}
			}
		}
		{delay 0.4
			{tags remove "fired"}
		}
		{delay 0.6
			{play_sound "close_bolt"}
		}
	}
	{on "weapon_reload" overload
		{kill_delay "bolt_action"}
		{ani_play "reload"}
		{if tagged "fired"
			{delay 0.55
				{call "case_eject"}
			}
		else
		}
		{delay 5.5
			{play_sound "close_bolt"}
		}
	}
}

{"stuff weapon flare_gun"
	{on "weapon_reload" overload
		{delay 0.5
			{ani_play "reload"}
		}

		{delay 1
			{tear "piece_tiny_steel" bone "flare" copy
				{impulse up -0.01}
			}
			{delay 0
				{view hide "flare"}
				{delay 1.5
					{view show "flare"}
				}
			}
		}
	}
}


(define "flame_fx"
	{"stuff weapon flame_thrower %tag"
		{on spawn
			{add_view "flamer_fire"			"flame"	"foresight3"}
			;//{add_view "flamer_fire_barrel"	"fire"	"foresight3"} ;// does not hide in fow

			{link_sound "start"	"weapon/shot/flame/handheld/flamer_start"}
			{link_sound "loop"	"weapon/shot/flame/handheld/flamer_loop"}
			{link_sound "end"	"weapon/shot/flame/handheld/flamer_stop"}
		}
		{on "start_burst"
			{play_sound "start"}
			{delay 0.1 "loop"
				{play_sound "loop" 1}
			}
		}
		{on "end_burst"
			{kill_delay "loop"}
			{play_sound "end"}
			{stop_sound "loop"}
		}
		{on "link_human"
			;//{view show	"fire"}
			;//{view start	"fire"}
		}
		{on "unlink_human"
			;//{view pause	"fire"}
		}
		{on "fire" overload
			{spawn "%flame" "foresight3" x
				{impulse forward 30 rnd_dir 0.01 com}
				{gravity 0.65}
				{linear_damping 0}
			}
			{view start "flame"}
			{kill_delay "fire"}
			{delay 0.05
				{spawn "%flame" "foresight3" x
					{impulse forward 30 rnd_dir 0.01 com}
					{gravity 0.65}
					{linear_damping 0}
				}
			}
			{delay 0.1 "fire"
				{view pause "flame"}
			}
		}
	}
)

("flame_fx" tag(range_20)		flame(fx_piece_flame_20))
("flame_fx" tag(range_30)		flame(fx_piece_flame_30))
("flame_fx" tag(range_40)		flame(fx_piece_flame_40))


{"stuff weapon flare_gun signal"		;// for mission scripts to detect flare location
	{on spawn
		{tags add "osp30_signal_sp"}
	}
	{on "fire" overload
		{spawn "fx_flare_signal" "foresight3" x
			{impulse forward 15 rnd_dir 0.01 com}
			{gravity 0.3}
			{linear_damping 0}
		}
	}
}

{"stuff weapon rocketlauncher_fx"	;// tag
	{on "fire"
		{spawn "bazooka_shot"	"fxshot" x}
		{with_effector
			{if terrain_fx "water"
			else terrain_fx "shallow_water"
			else terrain_fx "mud"
			else terrain_fx "snow"
				{spawn "bazooka_snow"	"basis" x}
			else terrain_fx "ice"
				{spawn "bazooka_snow"	"basis" x}
			else
				{spawn "bazooka_dust"	"basis" x}
			}
		}
	}
	{on "link_human" overload
		{delay 1.3
			{ani_play "prepare"}
		}
	}
}

{"stuff weapon piat"
	{on spawn
		{link_sound "mid"			"weapon/shot/reactive/d2/ENG/PIAT/"}
	}
	{on "fire"
		{spawn "piat_shot_forward"	"fxshot" x}
		{play_sound "mid"}
	}
	{on "link_human" overload
		{delay 1.3
			{ani_play "prepare"}
		}
	}
}

{"stuff weapon bipod"			;// weapons with bipods
	{on spawn 
		{ani_wind "bipod_open" begin}
	}
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
	}
}
(define "Automatic"
	{tags add "firing"}			; Granular Head – played on EVERY shot
	{play_sound "action_recoil"}
	{play_sound "Head_Mid"}
	{play_sound "Head_Far"}

	{kill_delay "burst_end"}

	{delay 0.025 "burst_end"
		{tags remove "firing"}		; Tail – plays only when the burst is complete
		{play_sound "Tail_Close"}
		{play_sound "Tail_Mid"}
		{play_sound "Tail_Far"}
	}
)
;/*=========== Generic Weapon Settings End ===========*/


;/*=========== SPECIFIC WEAPONS BEGIN ===========*/
;/**=========== ENG WEAPONS Begin ===========**/
{"stuff weapon bren"				;// props added to bren gun
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/eng/bren_gun/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/eng/bren_gun/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/eng/bren_gun/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/bren_gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/bren_gun/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon Cup_Discharger"				;// props added to SMLE No.1 MK III and Rifle No.4 Mk I w/ No.1 Mk. I Cup Discharger
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/SMLE_No1_MkIII/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/SMLE_No1_MkIII/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/eng/SMLE_No1_MkIII/Cup_Discharger/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/eng/SMLE_No1_MkIII/Cup_Discharger/"}
	}
}
{"stuff weapon Delisle"					;// props added to  DeLisle Carbine
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "open_bolt"		"weapon/reload/open_bolt/SMLE_No1_MkIII/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/SMLE_No1_MkIII/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/shared/surpressed_pistol/"}
	}
}
{"stuff weapon Enfield"					;// props added to all Enfield No.2 Mk.I
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ENG/Enfield_No2_MkI/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s1/d3/ENG/Enfield_No2_MkI/"}
	}
}
{"stuff weapon Lanchester_MkI"				;// props added to Lanchester Mk. I Machine Carbine and Variants
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ENG/Lanchester_MkI/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ENG/Lanchester_MkI/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ENG/Lanchester_MkI/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ENG/Lanchester_MkI/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ENG/Lanchester_MkI/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon Lewis_Gun"				;// props added to Lewis Gun Mk.I
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/eng/Lewis_Gun/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon SMLE"					;// props added to SMLE No.1 MK III and Rifle No.4 Mk I 
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/SMLE_No1_MkIII/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/SMLE_No1_MkIII/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/eng/SMLE_No1_MkIII/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/eng/SMLE_No1_MkIII/"}
	}
}
{"stuff weapon STEN_Gun"				;// props added to STEN Gun and Variants
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ENG/STEN_Gun/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ENG/STEN_Gun/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ENG/STEN_Gun/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ENG/STEN_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ENG/STEN_Gun/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon STEN_Gun_Suppressed"			;// props added to Suppressed STEN Gun Variants
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ENG/STEN_Gun_Suppressed/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ENG/STEN_Gun_Suppressed/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ENG/STEN_Gun_Suppressed/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon PMC_MkI"					;// props added to Patchett Machine Carbine Mk. I
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ENG/PMC_MkI/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ENG/PMC_MkI/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ENG/PMC_MkI/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ENG/PMC_MkI/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ENG/PMC_MkI/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon Vickers_GO"				;// props added to Vickers GO Mk.I and II
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/eng/Vickers_GO/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/eng/Vickers_GO/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/eng/Vickers_GO/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Vickers_GO/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Vickers_GO/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon Webley"					;// props added to all Webley Revolver Variants
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ENG/Webley_MkIV/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/ENG/Webley_MkIV/"}
	}
}
{"stuff weapon Welrod"					;// props added to Welrod
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/shared/surpressed_pistol/"}
	}
}
;/**=========== ENG WEAPONS End ===========**/
;/**=========== FRA WEAPONS Begin ===========**/
{"stuff weapon berthier_m1916"		;// props added to berthier mle 1916
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/gevar_m96/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/gevar_m96/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/fin/gevar_m96/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/fin/gevar_m96/"}
	}
}
{"stuff weapon fm_24_29"			;// props added to fm 24-29
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/mg26t/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg26t/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg26t/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg26t/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg26t/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg26t/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
;/**=========== FRA WEAPONS End ===========**/
;/**=========== FIN WEAPONS BEGIN ===========**/
{"stuff weapon boys_mk1"					;// props added to 14 mm pst kiv37:
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/bolt_action/"}
		{link_sound 	"mid"				"weapon/shot/smallarms/s4/d2/rus/ptr/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s4/d3/rus/ptr/"}
	}
	{on "weapon_reload"
		{call "magazine_delay"}
	}
	("magazine" cut(1.00) show(2.75) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon bergmann_m20"				;// props added to 7,65 kp/bergmann
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon chauchat"					;// props added to 800 pk 15
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/shared/mac1931/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/shared/mac1931/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/shared/mac1931/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/shared/mac1931/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/shared/mac1931/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.00) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon pist_07"					;// props added to husqvarna m/1907
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/fin/husqvarna_m1907/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/fin/husqvarna_m1907/"}
	}
}
{"stuff weapon kiv_96"					;// props added to gevar m/96
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/gevar_m96/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/gevar_m96/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/fin/gevar_m96/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/fin/gevar_m96/"}
	}
}
{"stuff weapon lahti_l35"					;// props added to 900 pist 35
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/fin/l35/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/fin/l35/"}
	}
}
{"stuff weapon suomi_m31_drum"				;// props added to 900 kp 31 w/ drum magazine 
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/fin/kp31/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon suomi_m31_sjr_drum"			;// props added to 900 kp 31 w/ drum magazine 
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/fin/kp31/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon suomi_m31_stick"				;// props added to 900 kp 31 w/ stick magazine 
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/fin/kp31/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon suomi_m31_sjr_stick"			;// props added to 900 kp 31 w/ stick magazine 
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/fin/kp31/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/fin/kp31/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/fin/kp31/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon m26"							;// props added to 762 pk 26
	{on spawn 
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/fin/ls26/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/fin/ls26/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/fin/ls26/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/fin/ls26/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/fin/ls26/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon mosin_m27"					;// props added to 762 kiv 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/fin/m39/"}
	}
}
{"stuff weapon mosin_m39"					;// props added to 762 kiv 39
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/fin/m39/"}
	}
}
{"stuff weapon madsen"						;// props added to 762 pk 20
	{on spawn 
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/fin/ls26/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/fin/ls26/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/fin/ls26/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/fin/ls26/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/fin/ls26/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon pk_21"					;// props added to kg m/21
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/fin/kg_m21//tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/fin/kg_m21//head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/fin/kg_m21//tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/fin/kg_m21//head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/fin/kg_m21//tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.05) show(2.95) override(overload) impulse({impulse up -0.01}))
}
;/**=========== FIN WEAPONS END ===========**/
;/**=========== GER WEAPONS BEGIN ===========**/
{"stuff weapon mp28"						;// props added to mp 28
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp28/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mp40"						;// props added to mp 38, mp 40 variants and mp 41
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp40/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon stg44"						;// props added to stg 44 and mkb 42(h)
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/stg44/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s2/d1/ger/stg44/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s2/d2/ger/stg44/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s2/d2/ger/stg44/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s2/d3/ger/stg44/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s2/d3/ger/stg44/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon k98"							;// props added to all  k 98k variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/k98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/k98k/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/k98k/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/"}
	}
}
{"stuff weapon g41"							;// props added to g 41
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/g41/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/g41/"}
	}
}
{"stuff weapon g43"							;// props added to all g/k 43 variants
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/g43/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/g43/"}
	}
}
{"stuff weapon fg42"						;// props added to fg 42
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/fg42/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/fg42/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/fg42/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/fg42/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/fg42/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg13_no_bipod"				;// props added to mg 13
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg13/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg13/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg13/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg26t"						;// props added to mg 26(t)
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/mg26t/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg26t/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg26t/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg26t/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg26t/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg26t/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon mg34_doubledrum"				;// props added to mg 34 w/ patronentrommel 34
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg34/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1) show(2.25) override(overload) impulse({impulse up 0.5 forward 0.9 0.1}))
}

{"stuff weapon mg34_drum"					;// props added to mg 34 w/ gurttrommel 34
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg34/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1) show(1.95) override(overload) impulse({impulse up 0.4 forward 0.9 0.1}))
}

{"stuff weapon mg34_belt"					;// props added to mg 34
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg34/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mg34_belt_long"				;// props added to mg 34
	{on spawn
		{link_sound		"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg34/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg34/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg34/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mg42_drum"					;// props added to mg 42 w/ gurttrommel 34
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg42/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1) show(1.95) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}

{"stuff weapon mg42_belt"					;// props added to mg 42
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg42/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mg42_belt_long"				;// props added to mg 42
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg42/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}


{"stuff weapon luger"						;// props added to p 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ger/p08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/ger/p08/"}
	}
}
{"stuff weapon p38"							;// props added to p 38
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ger/p38/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/ger/p38/"}
	}
}
{"stuff weapon pzb_39"						;// props added to pzb 39
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/bolt_action/"}
		{link_sound 	"mid"				"weapon/shot/smallarms/s4/d2/rus/ptr/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s4/d3/rus/ptr/"}
	}
}
{"stuff weapon panzerfaust"					;// props added to all panzerfaust variants
	{on spawn
		{link_sound "mid"		"weapon/shot/reactive/d2/ger/panzerfaust/"}
		{link_sound "far"		"weapon/shot/reactive/d3/ger/panzerfaust/"}
	}
}
{"stuff weapon schiessbecher"				;// props added to all k 98k rifle grenade launchers
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/k98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/k98k/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/schiessbecher/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/schiessbecher/"}
	}
}
;/**=========== GER WEAPONS END ===========**/
;/**=========== RUS WEAPONS BEGIN ===========**/

{"stuff weapon dp_bipod"					;// props added to dp 27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/rus/dp27/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}
{"stuff weapon dt"							;// props added to dt 
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/rus/dp27/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}
{"stuff weapon dyakonov"					;// props added mosin-nagant 1891/30 rifle grenade launchers
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/mn9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/mn9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/rus/m9130/dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/rus/m9130/dyakonov/"}
	}
}
{"stuff weapon mosin"						;// props added to all  mosin-nagant 1891/30 variants and mosin carbine
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/rus/m9130/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/rus/m9130/"}
	}
}
{"stuff weapon mosin_silencer"				;// props added to all  mosin-nagant 1891/30 b
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/shared/surpressed_rifle/"}
	}
}
{"stuff weapon nagant_revolver"				;// props added to nagant 1895
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/rus/m1895/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/rus/m1895/"}
	}
}
{"stuff weapon nagant_silencer"				;// props added to nagant 1895 b
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/shared/surpressed_pistol/"}
	}
}
{"stuff weapon ppd40"						;// props added to ppd 40
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/ppsh41/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon ppsh41_drum"					;// props added to ppsh 41 w/ drum magazine
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/ppsh41/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon ppsh41_stick"				;// props added to ppsh 41 w/ stick magazine 
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/ppsh41/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon pps43"						;// props added to pps 43
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon ptrd"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/rus/ptr/"}
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/rus/ptr/"}
	}
	{on "weapon_reload" overload
		{delay 3.2
			{ani_play "reload"}
		}
	}
}
{"stuff weapon ptrs"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/at_rifle/semi_auto/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/rus/ptr/"}
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/rus/ptr/"}
	}
	{on "weapon_reload" overload
		{delay 0.5
			{kill_delay "bolt_action"}
			{ani_play "reload"}
			{view hide "bullet"}
			{call "magazine_delay"}
		}
	}
	("magazine" cut(0.1) show(2.9) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon svt"							;// props added to avt 40, svt 38, svt 40, and skt 40
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/rus/svt40/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/rus/svt40/"}
	}
	("magazine" cut(1.75) show(2.1) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon tt33"						;// props added to tt 33
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/rus/tt33/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/rus/tt33/"}
	}
}
;/**=========== RUS WEAPONS END ===========**/
;/**=========== USA WEAPONS Begin ===========**/
{"stuff weapon browning_m2"					;// props added to browning m2hb .50 cal
	("magazine" cut(0.1) show(5.85) override(overload) impulse({impulse up -0.01 com}))
}
{"stuff weapon m12_shotgun"
	{on spawn	
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m12/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m12/"}
	}
}
{"stuff weapon browning_m19a4"				;// props added to browning m1919a4 .30 cal
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_mg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/usa/m1919a4/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/usa/m1919a4/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/usa/m1919a4/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/usa/m1919a4/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/usa/m1919a4/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon bar"							;// props added to m1918a2 bar 
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1918a2_bar/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/usa/m1918a2_bar/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/usa/m1918a2_bar/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/usa/m1918a2_bar/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/usa/m1918a2_bar/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/usa/m1918a2_bar/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.05) show(2.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon garand"						;// props added to m1 garand
	{on spawn
		{add_view "shell_rifle_m1_garand"	"shell"		"fxshell"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1_garand/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/usa/m1_garand/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/usa/m1_garand/"}
		{link_sound "eject_clip"	"weapon/reload/m1_garand/clip_eject/"}
	}
	("magazine" cut(0.1) show(2.9) override(overload) impulse({impulse up 2}))
}
{"stuff weapon garand_grenade_launcher"		;// props added to m1 garand w/ m7 grenade launcher
	{on spawn
		{add_view "shell_rifle_m1_garand"	"shell"		"fxshell"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1_garand/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/usa/m1_garand/m7_grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/usa/m1_garand/m7_grenade_launcher/"}
	}
}
{"stuff weapon hdm"
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/usa/m1911a1/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/shared/surpressed_pistol/"}
	}
}
{"stuff weapon m3_grease"					;// props added to m3 grease gun
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/usa/m3_greasegun/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/usa/m3_greasegun/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/usa/m3_greasegun/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/usa/m3_greasegun/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/usa/m3_greasegun/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/usa/m3_greasegun/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon thompson"					;// props added to all thompson variants
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/usa/m1a1_thompson/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon thompson_drum"				;// props added to thompson with drum
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/usa/m1a1_thompson/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.05) show(2.15) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon m1_carbine"					;// props added to m1 and m1a1 carbines
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s2/recoil/usa/m1_carbine/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/usa/m1_carbine/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/usa/m1_carbine/"}
	}
	("magazine" cut(1.05) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon m1_carbine_grenade_launcher"	;// props added to m1 carbine w/ m8 grenade launcher
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s2/recoil/usa/m1_carbine/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/usa/m1_carbine/m8_grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/usa/m1_carbine/m8_grenade_launcher/"}
	}
}
{"stuff weapon m1a1_carbine_grenade_launcher"	;// props added to m1a1 carbine w/ m8 grenade launcher
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s2/recoil/usa/m1_carbine/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/usa/m1_carbine/m8_grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/usa/m1_carbine/m8_grenade_launcher/"}
	}
}
{"stuff weapon m1903"						;// props added to m1903a3 & m1903a4
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m1903a3/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m1903a3/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1903a3/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/usa/m1903a3/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/usa/m1903a3/"}
	}
}
{"stuff weapon m1903_grenade_launcher"		;// props added to m1903a3 w/ m1 grenade launcher
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m1903a3/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m1903a3/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1903a3/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/usa/m1903a3/m1_grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/usa/m1903a3/m1_grenade_launcher/"}
	}
}
{"stuff weapon m1911"						;// props added to m1911a1
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/usa/m1911a1/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/usa/m1911a1/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/usa/m1911a1/"}
	}
}
{"stuff weapon recoilless_m18"
	{on spawn
		{link_sound "mid"			"weapon/shot/reactive/d2/shared/rocket_launcher/"}
		{link_sound "far"			"weapon/shot/reactive/d3/shared/rocket_launcher/"}
	}
}
;/**=========== USA WEAPONS END ===========**/
;/**=========== SWE WEAPONS BEGIN ===========**/
{"stuff weapon m1907"						;// props added to husqvarna m/07
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/rus/tt33/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/rus/tt33/"}
	}
}
{"stuff weapon gevar_m96"					;// props added to gevar m/1896
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/k98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/k98k/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/k98k/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/"}
	}
}
{"stuff weapon kg_m21"						;// props added to kulsprutegevar m/21
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1918a2_bar/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/fin/KG_m21/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/fin/KG_m21/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/fin/KG_m21/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/fin/KG_m21/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/fin/KG_m21/tail/"}
	}
	{on "fire"
		("Automatic")
	}
	("magazine" cut(1.05) show(2.95) override(overload) impulse({impulse up -0.01}))
}
;/**=========== SWE WEAPONS END ===========**/
;/*=========== SPECIFIC WEAPONS END ===========*/
;/*=========== SHARED WEAPONS BEGIN ===========*/
{"stuff weapon hipower_1935"				;// props added to fn browning hi-power p35
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/shared/fn_browning_hipower_p35/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/shared/fn_browning_hipower_p35/"}
	}
}
{"stuff weapon rocket_launcher"				;// props added to all shoulder fired rocket launchers
	{on spawn
		{link_sound "mid"			"weapon/shot/reactive/d2/shared/rocket_launcher/"}
		{link_sound "far"			"weapon/shot/reactive/d3/shared/rocket_launcher/"}
	}
}
{"stuff weapon shotgun"						;// props added to
	{on spawn
		{link_sound "action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/shared/shotgun/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/shared/shotgun/"}
	}
}
;/***=========== SHARED WEAPONS END ===========***/
;/***=========== SHARED WEAPONS MACE START ===========***/

{"stuff weapon ruby"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/pistol/"}
        {link_sound "mid"        "weapon/shot/smallarms/s1/d2/Shared/FN_Browning_HiPower_P35/"}
        {link_sound "far"        "weapon/shot/smallarms/s1/d3/Shared/FN_Browning_HiPower_P35/"}
    }
}
{"stuff weapon sig_mkps"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/open_bolt_SMG/Type2/"}
        {link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPSh41/"}
        {link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPSh41/"}
    }
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon sig_mkms"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/open_bolt_SMG/Type2/"}
        {link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPSh41/"}
        {link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPSh41/"}
    }
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}

{"20mm_fliegerfaust"
	{on "link_human"
		{delay 0.6
			{ani_play "deploy" -1}
		}
	}
	{on "unlink_human"
		{ani_play "deploy" 1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "deploy" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "deploy" end}
	}
	{on "weapon_reload"
		{ani_play "reload"}
		{view hide "bullet1"}
		{view hide "bullet2"}
		{view hide "bullet3"}
		{view hide "bullet4"}
		{view hide "bullet5"}
		{view hide "bullet6"}
		{view hide "bullet7"}
		{view hide "bullet8"}
		{view hide "bullet9"}
	{delay 5
			{view show "bullet1"}
			{view show "bullet2"}
			{view show "bullet3"}
			{view show "bullet4"}
			{view show "bullet5"}
			{view show "bullet6"}
			{view show "bullet7"}
			{view show "bullet8"}
			{view show "bullet9"}
		}
	}
}

{"stuff weapon sturmpistole"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/bolt_action/"}
        {link_sound "mid"        "weapon/shot/smallarms/s3/d2/GER/K98k/Schiessbecher/"}
        {link_sound "far"        "weapon/shot/smallarms/s3/d3/GER/K98k/Schiessbecher/"}
    }
    {on "fire" 
        {delay 0.01
            {view hide "prop_flare"}
            {view hide "prop_rocket"}
        }
    }

    {on "weapon_reload"
        {delay 4
            {view show "prop_flare"}
            {delay 3
                {view show "prop_rocket"}
            }
        }
    }
}
{"stuff weapon mauser_m96"            
    {on spawn
        {link_sound "open_bolt"        "weapon/reload/open_bolt/K98k/"}
        {link_sound "close_bolt"    "weapon/reload/close_bolt/K98k/"}
        {link_sound "action_recoil"    "weapon/action/recoil/bolt_action/"}
        {link_sound "mid"        "weapon/shot/smallarms/s3/d2/GER/K98k/"}
        {link_sound "far"        "weapon/shot/smallarms/s3/d3/GER/K98k/"}
    }
}
{"stuff weapon ag_m42"            
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/closed_bolt/"}
        {link_sound "mid"        "weapon/shot/smallarms/s3/d2/GER/G43/"}
        {link_sound "far"        "weapon/shot/smallarms/s3/d3/GER/G43/"}
    }
}
{"stuff weapon carl_gustaf_m_45"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/open_bolt_SMG/Type2/"}
        {link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPS43/"}
        {link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPS43/"}
    }
}
{"stuff weapon beretta_m38a"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/open_bolt_SMG/Type2/"}
        {link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPS43/"}
        {link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPS43/"}
    }
}
{"stuff weapon rmn_50"
    {on spawn
        {link_sound "open_bolt"        "weapon/reload/open_bolt/MN9130/"}
        {link_sound "close_bolt"    "weapon/reload/close_bolt/MN9130/"}
        {link_sound "action_recoil"    "weapon/action/recoil/bolt_action/"}
        {link_sound "mid"        "weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
        {link_sound "far"        "weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
    }
    {on "weapon_reload" 
        {delay 0.01
            {view hide "grenade_prop01"}
        }
        {delay 4
            {view show "grenade_prop01"}
        }
    }
}
{"stuff weapon al_43"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/closed_bolt/StG44/"}
        {link_sound "mid"        "weapon/shot/smallarms/s2/d2/GER/StG44/"}
        {link_sound "far"        "weapon/shot/smallarms/s2/d3/GER/StG44/"}
    }
}
{"stuff weapon sig_mkps"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/open_bolt_SMG/Type2/"}
        {link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPSh41/"}
        {link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPSh41/"}
    }
}
{"stuff weapon fnab_43"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/open_bolt_SMG/Type2/"}
        {link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPSh41/"}
        {link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPSh41/"}
    }
}
{"stuff weapon ppk_42"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/open_bolt_SMG/Type2/"}
        {link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPSh41/"}
        {link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPSh41/"}
    }
}
{"stuff weapon ppt27"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/open_bolt_SMG/Type2/"}
        {link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPSh41/"}
        {link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPSh41/"}
    }
}
{"stuff weapon grb_39"
    {on spawn
        {link_sound "open_bolt"        "weapon/reload/open_bolt/K98k/"}
        {link_sound "close_bolt"    "weapon/reload/close_bolt/K98k/"}
        {link_sound "action_recoil"    "weapon/action/recoil/bolt_action/"}
        {link_sound "mid"        "weapon/shot/smallarms/s3/d2/GER/K98k/Schiessbecher/"}
        {link_sound "far"        "weapon/shot/smallarms/s3/d3/GER/K98k/Schiessbecher/"}
    }

    {on "weapon_reload"
        {delay 0.01
            {view hide "prop_bullet01"}
        }
        {delay 8
            {view show "prop_bullet01"}
        }
    }
}
{"stuff weapon wz35"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/AT_Rifle/bolt_action/"}
        {link_sound "mid"        "weapon/shot/smallarms/s4/d2/RUS/PTR/"}
        {link_sound "far"        "weapon/shot/smallarms/s4/d3/RUS/PTR/"}
    }

    {on "weapon_reload"
        {delay 0.01
            {view hide "prop_bullet01"}
            {view hide "prop_bullet02"}
        }
        {delay 1
            {view show "prop_bullet01"}
            {view show "prop_bullet02"}
        }
    }
}

{"stuff weapon carcano"					;// props added to all AT4 Variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/M39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/M39/"}
	}
}	
{"stuff weapon as44"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/SVT40/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/SVT40/"}
	}

	{on "weapon_reload"
		{delay 0.01
			{view hide "prop_bullet01"}
		}
        {delay 2.25
			{view show "prop_bullet01"}
		}
	}
}
{"stuff weapon rpd"						;// props added to StG 44 and MKb 42(H)
	{on spawn
		{ani_wind "bipod_open" begin}
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG13/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG13/"}
	}
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
	}

    {on "weapon_reload"
		{delay 0.01
			{view hide "prop_bullet01"}
			{view hide "prop_bullet02"}
			{view hide "prop_bullet03"}
			{view hide "prop_bullet04"}
			{view hide "prop_bullet05"}
			{view hide "prop_bullet06"}
			{view hide "prop_bullet07"}
			{view hide "prop_bullet08"}
			{view hide "prop_bullet09"}
			{view hide "prop_bullet10"}
			{view hide "prop_bullet11"}
			{view hide "prop_bullet12"}
            {view hide "prop_bullet13"}
			{view hide "prop_bullet14"}
			{view hide "prop_bullet15"}
			{view hide "prop_bullet16"}
			{view hide "prop_bullet17"}
            {view hide "prop_bullet18"}
		}
        {delay 2.25
			{view show "prop_bullet01"}
			{view show "prop_bullet02"}
			{view show "prop_bullet03"}
			{view show "prop_bullet04"}
			{view show "prop_bullet05"}
			{view show "prop_bullet06"}
			{view show "prop_bullet07"}
			{view show "prop_bullet08"}
			{view show "prop_bullet09"}
			{view show "prop_bullet10"}
			{view show "prop_bullet11"}
			{view show "prop_bullet12"}
            {view show "prop_bullet13"}
			{view show "prop_bullet14"}
			{view show "prop_bullet15"}
			{view show "prop_bullet16"}
			{view show "prop_bullet17"}
            {view show "prop_bullet18"}
		}
    }
}

{"stuff weapon m50_reising"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/Shared/FN_Browning_HiPower_P35/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/Shared/FN_Browning_HiPower_P35/"}
		{add_view	"shell_pistol"	"smg_eject1"	"fxshell"}
	}
	{on "fire"
			{ani_play "bolt_action"}
			{view start "smg_eject1"}
	}
	("magazine" cut(1) show(2.9) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon m50_reising_30"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/Shared/FN_Browning_HiPower_P35/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/Shared/FN_Browning_HiPower_P35/"}
		{add_view	"shell_pistol"	"smg_eject1"	"fxshell"}
	}
	{on "fire"
			{ani_play "bolt_action"}
			{view start "smg_eject1"}
	}
	("magazine" cut(1) show(2.9) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon johnson_rifle"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/SVT40/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/SVT40/"}
	}
	{on "fire"
		{ani_play "bolt_action"}
	}
	{on "weapon_reload" overload
		{ani_play "reload"}
		{view hide "bullet"}
		{view hide "bullet2"}
		{view hide "bullet3"}
		{view hide "bullet4"}
	{delay 4
			{view show "bullet"}
			{view show "bullet2"}
			{view show "bullet3"}
			{view show "bullet4"}
		}
	}
}

{"stuff weapon johnson_m1941_lmg"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/FG42/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/FG42/"}
		{add_view	"shell_mgun"	"mgun_eject1"	"fxshell"}
	}
	{on "weapon_reload" overload
		{delay 0.1
			{kill_delay "recoil"}
			{ani_play "reload"}
			{view hide "bullet"}
			{view hide "bullet2"}
			{view hide "bullet3"}
			{view hide "ammo"}
			{call "magazine_delay"}
		}
		{delay 3.5
			{view show "bullet"}
			{view show "bullet2"}
			{view show "bullet3"}
			{view show "ammo"}
		}
	}
	("magazine" cut(1) show(2.9) override(overload) impulse({impulse up -0.01}))
	{on "fire"
			{view start "mgun_eject1"}
	}
}

{"stuff weapon bazooka_m20_new"
	{on spawn
		{link_sound "mid"		"weapon/shot/reactive/d2/Shared/Rocket_Launcher/"}
		{link_sound "far"		"weapon/shot/reactive/d3/Shared/Rocket_Launcher/"}
	}
	{on "fire"
		{view hide "rocket"}
		{delay 3.5
				{view show	"rocket"}
		}
	}
}

{"stuff weapon KPVT_AA"
	{on spawn
		{link_sound 		"action_recoil_HMG"	"weapon/action/recoil/closed_bolt_HMG/"}
		{link_sound			"HMG_Mid"		"weapon/shot/smallarms/s4/d2/RUS/DShK38/"}
		{link_sound 		"HMG_Far"		"weapon/shot/smallarms/s4/d3/RUS/DShK38/"}
	}
	{on "fire"
		{ani_play "fire" 1}
	}	
	{on "weapon_reload" overload
			{view hide "bullet"}
			{call "magazine_delay"}
	}
	("magazine" cut(0.1) show(6) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon RPG1"
	{on spawn 
		{ani_wind "bipod_open" begin}
	}
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
	}
	{on "fire"
        	{view hide "rocket"}
    		{delay 4
        		{view show "rocket"}
        	}
	}
}

{"stuff weapon mg131"
	{on spawn
		{link_sound 		"action_recoil_HMG"	"weapon/action/recoil/closed_bolt_HMG/"}
		{link_sound			"HMG_Mid"		"weapon/shot/smallarms/s4/d2/RUS/DShK38/"}
		{link_sound 		"HMG_Far"		"weapon/shot/smallarms/s4/d3/RUS/DShK38/"}
	}
	{on "weapon_reload" 
		{delay 0.2		
			{view hide "magazine"}
			{view hide "ammo2"}
			{delay 1.5
				{view hide "pin"}
			}
			{delay 6
				{view show "pin"}
			}
		}
	}
}

{"stuff weapon mg131_bipod"
	{on spawn
		{link_sound 		"action_recoil_HMG"	"weapon/action/recoil/closed_bolt_HMG/"}
		{link_sound			"HMG_Mid"		"weapon/shot/smallarms/s4/d2/RUS/DShK38/"}
		{link_sound 		"HMG_Far"		"weapon/shot/smallarms/s4/d3/RUS/DShK38/"}
	}
	{on "weapon_reload" 
		{delay 0.2		
			{view hide "magazine"}
			{view hide "ammo2"}
			{delay 1.5
				{view hide "pin"}
			}
			{delay 6
				{view show "pin"}
			}
		}
	}
}

{"stuff weapon winchester_1895"
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/K98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/K98k/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/USA/lee_enfield/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/USA/lee_enfield/"}
		{add_view	"shell_rifles"	"rifle_eject1"	"fxshell"}
	}
	{on "fire"
		{delay 0.1
			{view start "rifle_eject1"}
			{ani_play "bolt_action" 1}
		}
        }
}

{"bazooka_m20_new"
	("at_weapon_icon" icon(icon_m9bazooka))
}
{"bazooka_m20_new"
	("at_weapon_icon" icon(icon_m9bazooka))
	{on "fire"
		{delay 1
			{view stop "wp_view"}
		}
	}	
}

{"stuff weapon type93_fixed"					;// props added to 800 PK 15
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/13_2_HMG/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/13_2_HMG/"}
	}
}

{"stuff weapon ni_5_lunge_mine"
	{on spawn
		{volumes "body" enable select touch contact}
	}
	{on "fire"
		{stuff_detonate}
		{spawn "explosion_lunge_mine" "foresight14"}
	}
	{on contact
		{if not friendly_fire
			{if effector "tank"
				{stuff_detonate}
				{spawn "explosion_lunge_mine" "foresight14"}
			}
			{if effector "cannon"
				{stuff_detonate}
				{spawn "explosion_lunge_mine" "foresight14"}
			}
			{if effector "vehicle"
				{stuff_detonate}
				{spawn "explosion_lunge_mine" "foresight14"}
			}
		}
	}	
}

{"stuff weapon ni_5_lunge_mine_ai"
	{on spawn
		{volumes "body" enable select touch contact}
	}
	{on "fire"
		{stuff_detonate}
		{spawn "explosion_lunge_mine" "foresight14"}
	}
	{on blast
		{if min_energy 1	
			{set "blast" 0}
			{delete}
		}
	}			
}

{"stuff weapon type_hei_rifle_late"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/M39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/M39/"}
		{if rand 0.5
			{view hide "bayonet"}
		else
			;nothing
		}
	}
	{on "weapon_reload" overload
		{delay 0.5
			{kill_delay "bolt_action"}
			{ani_play "reload"}
			{view hide "bullet"}
			{call "magazine_delay"}
		}
	}
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_44"					;// props added to 800 PK 15
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type38/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type38/"}
	}
	{on "link_human"
		{delay 0.6
			{ani_play "bayonet_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bayonet_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bayonet_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bayonet_open" end}
	}
}

{"stuff weapon type_1_late_smg"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
        	{link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPS43/"}
        	{link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPS43/"}
	}
}

{"stuff weapon type_2_smg_1934"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
        	{link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPS43/"}
        	{link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPS43/"}
	}
}

{"stuff tokyo_arsenal_model_1927"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
        	{link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPS43/"}
        	{link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPS43/"}
	}
}

{"stuff weapon nambu_type_94"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon nambu_type_94_late"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon beretta_m38_42"						;// props added to MP 28
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/MP40/"}	; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/MP40/"}	; Placeholder
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_99_lmg_paratrooper"					;// props added to 800 PK 15
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/type_99_LMG/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/type_99_LMG/"}
	}
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
	}
	{on "weapon_reload" overload
		{delay 0.5
			{kill_delay "bolt_action"}
			{ani_play "reload"}
			{view hide "bullet"}
			{call "magazine_delay"}
		}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_99_lmg_paratrooper_unfold"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/type_99_LMG/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/type_99_LMG/"}
	}
	{on "link_human"
		{ani_play "deploy" -1}
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
		{ani_play "deploy" 1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
		{ani_wind "deploy" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
		{ani_wind "deploy" end}
	}
	{on "weapon_reload" overload
		{delay 0.5
			{kill_delay "bolt_action"}
			{ani_play "reload"}
			{view hide "bullet"}
			{call "magazine_delay"}
		}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon hotchkiss_m1922"							;// props added to StG 44 and MKb 42(H)
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG13/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG13/"}
		{link_sound "action_recoil" "weapon/action/recoil/open_bolt_MG/reciprocating/"}
	}
	("magazine" cut(0.1) show(3) override(overload) impulse({impulse up -0.01}))
	{on "weapon_reload"
		{view hide "bullet"}
		{delay 3
			{view show "bullet"}
		}
	}
}

{"stuff weapon an_m2_stinger"                ;// props added to Browning M1919A4 .30 Cal
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/open_bolt_MG/"}
        {link_sound "mid"            "weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
        {link_sound "far"            "weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
    }
    ("magazine" cut(0.1) show(4) override(overload) impulse({impulse up 0}))
}

{"stuff weapon type22_murata"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet"}
		else
			;nothing
		}
	}
}

{"stuff weapon tz_45"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/open_bolt_SMG/Type2/"}
        {link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPSh41/"}
        {link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPSh41/"}
    }
}

{"stuff weapon type13_murata"					;// props added to 762 KIV 91-27
	{on spawn	
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound 		"action_recoil_HMG"	"weapon/action/recoil/closed_bolt_HMG/"}
		{link_sound			"HMG_Mid"		"weapon/shot/smallarms/s4/d2/USA/M2HB/"}
		{link_sound 		"HMG_Far"		"weapon/shot/smallarms/s4/d3/RUS/DShK38/"}
		{if rand 0.90
			{view hide "bayonet"}
		else
			;nothing
		}																														
	}
}

{"stuff weapon type18_murata"					;// props added to 762 KIV 91-27
	{on spawn	
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound 		"action_recoil_HMG"	"weapon/action/recoil/closed_bolt_HMG/"}
		{link_sound			"HMG_Mid"		"weapon/shot/smallarms/s4/d2/USA/M2HB/"}
		{link_sound 		"HMG_Far"		"weapon/shot/smallarms/s4/d3/RUS/DShK38/"}
		{if rand 0.90
			{view hide "bayonet"}
		else
			;nothing
		}																														
	}
}

{"stuff weapon type_1_lmg"				;// props added to MG 34 w/ Patronentrommel 34
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG42/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG42/"}
	}
	("magazine" cut(1) show(2.25) override(overload) impulse({impulse up 0.5 forward 0.9 0.1}))
}

{"stuff weapon vg2"
    {on spawn
        {link_sound "open_bolt"        "weapon/reload/open_bolt/M9130/"}
        {link_sound "close_bolt"    "weapon/reload/close_bolt/M9130/"}
        {link_sound "action_recoil"    "weapon/action/recoil/bolt_action/"}
    }
}

{"stuff weapon vg1_5"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/closed_bolt/StG44/"}
        {link_sound "mid"        "weapon/shot/smallarms/s2/d2/GER/StG44/"}
        {link_sound "far"        "weapon/shot/smallarms/s2/d3/GER/StG44/"}
    }
    ("magazine" cut(1.20) show(2) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon stg45m"
    {on spawn
        {link_sound "action_recoil"    "weapon/action/recoil/closed_bolt/StG44/"}
        {link_sound "mid"        "weapon/shot/smallarms/s2/d2/GER/StG44/"}
        {link_sound "far"        "weapon/shot/smallarms/s2/d3/GER/StG44/"}
    }
    ("magazine" cut(1.20) show(2) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon krag_jorgensen"
        {on spawn
        {link_sound "open_bolt"        "weapon/reload/open_bolt/M9130/"}
        {link_sound "close_bolt"    "weapon/reload/close_bolt/M9130/"}
        {link_sound "action_recoil"    "weapon/action/recoil/bolt_action/"}
    }
}

{"stuff weapon type_26_revolver"				;// props added to Nagant 1895
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/RUS/M1895/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/RUS/M1895/"}
	}
	{on "weapon_reload"
		{delay 0.10
			{tear "piece_small_steel" bone "bullet1" copy 
				{impulse dir 1 fz 0 fx 0 }
			}
			{tear "piece_small_steel" bone "bullet2" copy 
				{impulse dir 1 fz 0 fx 0 }
			}
			{tear "piece_small_steel" bone "bullet3" copy 
				{impulse dir 1 fz 0 fx 0 }
			}
			{tear "piece_small_steel" bone "bullet4" copy 
				{impulse dir 1 fz 0 fx 0 }
			}
			{tear "piece_small_steel" bone "bullet5" copy 
				{impulse dir 1 fz 0 fx 0 }
			}
			{tear "piece_small_steel" bone "bullet6" copy 
				{impulse dir 1 fz 0 fx 0 }
			}
		}
	}
}

{"stuff weapon mannlicher_m1895_6mm"						;// props added to M1 Garand
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.70
			{view hide "bayonet_M1895"}
		else
			;nothing
		}
	}
}

{"stuff weapon mannlicher_m1895"						;// props added to M1 Garand
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon vz_24"						;// props added to M1 Garand
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/k98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/k98k/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/k98k/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/"}
	}
}

{"stuff weapon type_2_tera"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet_paratrooper"}
		else
			;nothing
		}
	}
	{on "link_human"
		{ani_play "deploy" -1}
	}
	{on "unlink_human"
		{ani_play "deploy" 1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "deploy" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "deploy" end}
	}
}

{"stuff weapon type99_mid"						;// props added to M1 Garand
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type38/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type38/"}
		{if rand 0.5
			{view hide "bayonet_mid"}
		else
			;nothing
		}
	}
}

{"stuff weapon type99_mid_flash_hider"						;// props added to M1 Garand
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type38/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type38/"}
		{if rand 0.5
			{view hide "bayonet_mid"}
		else
			;nothing
		}
	}
}

{"stuff weapon type99_long"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon type99_long_ija"					;// props added to 762 KIV 91-27
	{on spawn
		{ani_play "flag" loop}
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon type99_long_ijn"					;// props added to 762 KIV 91-27
	{on spawn
		{ani_play "flag" loop}
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon type99_long_jap"					;// props added to 762 KIV 91-27
	{on spawn
		{ani_play "flag" loop}
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon type99_long_scope"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
	}
}

{"stuff weapon type99_mid_scope"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
	}
}

{"stuff weapon type99_late_jinsen"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet_japanese_late"}
		else
			;nothing
		}
	}
}

{"stuff weapon type99_late"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet_japanese_late"}
		else
			;nothing
		}
	}
}

{"stuff weapon type99_late_ijn"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet"}
		else
			;nothing
		}
	}
}
{"stuff weapon type99_early_grenade_launcher"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
	{on "weapon_reload" 
        	{delay 0.01
           		{view hide "grenade"}
        	}
        	{delay 10
           		{view show "grenade"}
        	}
    	}
}

{"type99_early_grenade_launcher"
	("at_weapon_icon" icon(icon_type2_at))
}

{"stuff weapon type99_bouganville_launcher"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
	}
	{on "weapon_reload" 
        	{delay 0.01
           		{view hide "grenade"}
        	}
        	{delay 10
           		{view show "grenade"}
        	}
    	}
}

{"type99_bouganville_launcher"
	("at_weapon_icon" icon(icon_bouganville_at))
}

{"stuff weapon type99_early_grenade_3_launcher"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
	}
	{on "weapon_reload" 
        	{delay 0.01
           		{view hide "grenade"}
        	}
        	{delay 10
           		{view show "grenade"}
        	}
    	}
}

{"type99_early_grenade_3_launcher"
	("at_weapon_icon" icon(icon_type99_3_at))
}

{"stuff weapon type38_early_grenade_91_launcher"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
	}
	{on "weapon_reload" 
        	{delay 0.01
           		{view hide "grenade"}
        	}
        	{delay 10
           		{view show "grenade"}
        	}
    	}
}

{"type38_early_grenade_91_launcher"
	("at_weapon_icon" icon(icon_type99_3_at))
}

{"stuff weapon type99_mid_grenade_launcher"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
	}
	{on "weapon_reload" 
        	{delay 0.01
           		{view hide "grenade"}
        	}
        	{delay 10
           		{view show "grenade"}
        	}
    	}
}

{"type99_mid_grenade_launcher"
	("at_weapon_icon" icon(icon_type2_at))
}

{"stuff weapon type99_early"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon type99_early_scope"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon type38"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"	"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type38/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type38/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon type38_carbine"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type38/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type38/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon type38_carbine_flash_hider"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type38/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type38/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon type38_short"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type38/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type38/"}
		{if rand 0.5
			{view hide "bayonet"}
		else
			;nothing
		}
	}
}
{"stuff weapon type38_grenade_launcher"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
	{on "weapon_reload" 
        	{delay 0.01
           		{view hide "grenade"}
        	}
        	{delay 10
           		{view show "grenade"}
        	}
    	}
}

{"type38_grenade_launcher"
	("at_weapon_icon" icon(icon_type38_at))
}

{"stuff weapon type97_scope"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type38/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type38/"}
	}
}

{"stuff weapon type97_scope_silencer"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/Shared/Surpressed_Rifle/"}
	}
}

{"stuff weapon type97_scope_flash_hider"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/Shared/Surpressed_Rifle/"}
	}
}
{"stuff weapon type38_silencer"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/Shared/Surpressed_Rifle/"}
	}
}

{"stuff weapon type38_flash_hider"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/Shared/Surpressed_Rifle/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}
{"stuff weapon type38_carbine_silencer"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/Shared/Surpressed_Rifle/"}
	}
}

{"stuff weapon type99_long_silencer"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/Shared/Surpressed_Rifle/"}
	}
}

{"stuff weapon type99_long_flash_hider"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/Shared/Surpressed_Rifle/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon type99_mid_silencer"						;// props added to M1 Garand
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/Shared/Surpressed_Rifle/"}
	}
}

{"stuff weapon type_hei_automatic"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/M39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/M39/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
		{if rand 0.90
			{view hide "shield"}
			{volumes "shield1" disable bullet blast touch contact contact_ground}
		else
			;nothing
		}
	}
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
	}
	{on "weapon_reload"
		{view hide "bullet"}
		{delay 1.95
			{view show "bullet"}
		}
	}
}

{"stuff weapon type_hei_automatic_20"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/M39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/M39/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
		{if rand 0.90
			{view hide "shield"}
			{volumes "shield" disable bullet blast touch contact contact_ground}
		else
			;nothing
		}
	}
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
	}
	{on "weapon_reload"
		{view hide "bullet"}
		{delay 1.95
			{view show "bullet"}
		}
	}
}

{"stuff weapon type1_carcano"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type38/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type38/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon sig_1920_type"						;// props added to MP 28
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/MP40/"}	; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/MP40/"}	; Placeholder
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "weapon_reload" 
		{ani_play "reload"}
	}
}

{"stuff weapon sig_1920_type_ger"						;// props added to MP 28
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/MP40/"}	; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/MP40/"}	; Placeholder
		{view hide "bayonet_japanese_early"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "weapon_reload" 
		{ani_play "reload"}
	}
}

{"stuff weapon type_tsing_tao"						;// props added to MP 28
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/MP40/"}	; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/MP40/"}	; Placeholder
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "weapon_reload" 
		{ani_play "reload"}
	}
	{on "fire"
		{spawn "bazooka_shot"	"fxshot" x}
	}
}

{"stuff weapon mp_18"						;// props added to MP 28
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/MP40/"}	; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/MP40/"}	; Placeholder
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "weapon_reload" 
		{ani_play "reload"}
	}
}

{"stuff weapon 8cm_ijn_rocket_launcher"
	{on spawn
		{link_sound        "scraping_metal"    "weapon/shot/reactive/rocket_booster/"}
		{if rand 0.90
			{view hide "shield"}
			{volumes "shield" disable bullet blast touch contact contact_ground}
		else
			;nothing
		}
	}
	{on "fire"
		{play_sound "scraping_metal"}
		{spawn "bazooka_shot"	"fxshot" x}
		{view hide "rocket"}
		{delay 4
			{view show "rocket"}
		}
	}
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
	}
}

{"stuff weapon 10cm_ijn_rocket_launcher"
	{on spawn
		{link_sound        "scraping_metal"    "weapon/shot/reactive/rocket_booster/"}
		{if rand 0.90
			{view hide "shield"}
			{volumes "shield" disable bullet blast touch contact contact_ground}
		else
			;nothing
		}
	}
	{on "fire"
		{play_sound "scraping_metal"}
		{spawn "bazooka_shot"	"fxshot" x}
		{view hide "rocket"}
		{delay 4
			{view show "rocket"}
		}
	}
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
	}
}

{"stuff weapon type4_90mm"
	{on "fire"
		{spawn "bazooka_shot"	"fxshot" x}
		{view hide "rocket"}
		{view hide "cable"}
    		{delay 4
        		{view show "rocket"}
			{view show "cable"}
        	}
	}
	{on "weapon_reload" overload
		{delay 3
			{ani_play "gun_reload"}
		}
	}
}

{"stuff weapon type4_70mm"
	{on "fire"
		{spawn "bazooka_shot"	"fxshot" x}
		{view hide "rocket"}
		{view hide "cable"}
    		{delay 4
        		{view show "rocket"}
			{view show "cable"}
        	}
	}
	{on "weapon_reload" overload
		{delay 3
			{ani_play "gun_reload"}
		}
	}
}

{"tao_rocket_launcher"
	("at_weapon_icon" icon(icon_panzerfaust))
}

{"type4_70mm"
	("at_weapon_icon" icon(icon_type4_at))
}

{"type4_90mm"
	("at_weapon_icon" icon(icon_type4_at))
}

{"8cm_ijn_rocket_launcher"
	("at_weapon_icon" icon(icon_typenavy_at))
}

{"10cm_ijn_rocket_launcher"
	("at_weapon_icon" icon(icon_typenavy_at))
}

{"stuff weapon type_89_mortar"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
	}
	{on "weapon_reload" 
        	{delay 0.01
           		{view hide "grenade"}
        	}
        	{delay 10
           		{view show "grenade"}
        	}
    	}
}

{"stuff weapon type_27_mortar"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
	}
	{on "weapon_reload" 
        	{delay 0.01
           		{view hide "grenade"}
        	}
        	{delay 10
           		{view show "grenade"}
        	}
    	}
}
{"stuff weapon type_10_mortar"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
	}
	{on "weapon_reload" 
        	{delay 0.01
           		{view hide "grenade"}
        	}
        	{delay 10
           		{view show "grenade"}
        	}
    	}
}

{"stuff weapon type_100_smg_early"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
        	{link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPS43/"}
        	{link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPS43/"}
		{if rand 0.5
			{view hide "bayonet_mid"}
		else
			;nothing
		}
	}
}

{"stuff weapon type_100_smg_early_bipod"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
        	{link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPS43/"}
        	{link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPS43/"}
		{if rand 0.5
			{view hide "bayonet_mid"}
		else
			;nothing
		}
	}
}

{"stuff weapon type_100_smg_late"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
        	{link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPS43/"}
        	{link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPS43/"}
		{if rand 0.5
			{view hide "bayonet_japanese_late"}
		else
			;nothing
		}
	}
}

{"stuff weapon type_100_smg_para"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
        	{link_sound "mid"        "weapon/shot/smallarms/s1/d2/RUS/PPS43/"}
        	{link_sound "far"        "weapon/shot/smallarms/s1/d3/RUS/PPS43/"}
		{if rand 0.5
			{view hide "bayonet_paratrooper"}
		else
			;nothing
		}
		;{ani_wind "bipod_open" begin}
	}
	{on "link_human"
		;{ani_play "bipod_open"}
		{ani_play "deploy" -1}
	}
	{on "unlink_human"
		;{ani_play "bipod_open" -1}
		{ani_play "deploy" 1}
	}
	{on "link"					;// linked to vehicle
		;{ani_wind "bipod_open" begin}
		{ani_wind "deploy" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		;{ani_wind "bipod_open" end}
		{ani_wind "deploy" end}
	}
}

{"stuff weapon type4_rifle"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Arisaka_bolt/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Arisaka_bolt/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/Arisaka_type99/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/Arisaka_type99/"}
		{link_sound "eject_clip"	"weapon/reload/M1_Garand/clip_eject/"}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
}

{"stuff weapon zh_29_rifle_10"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/G43/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/G43/"}
	}
	("magazine" cut(1.20) show(3.5) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon zh_29_rifle"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/G43/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/G43/"}
	}
	("magazine" cut(1.20) show(3.5) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_5_recoiless"
	{on "fire"
		{spawn "bazooka_shot"	"fxshot" x}
		{ani_play "reload" 1 resume}
		{view hide "rocket"}
    		{delay 4
        		{view show "rocket"}
        	}
	}
}

{"type_5_recoiless"
	("at_weapon_icon" icon(icon_type5_at))
}

{"70mm_type_4_ai_kung"
	("at_weapon_icon" icon(icon_type5_at))
}

{"stuff weapon mauser_c96_carbine_10"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon mauser_c96_carbine_20"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon mauser_c96_carbine_30"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon mauser_c96_carbine_40"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon mauser_c96_m1932_nostock"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon mauser_c96_m1932_stock"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon mauser_c96_chi_nostock"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon mauser_c96_nostock"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon mauser_c96_stock"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon type_11_lmg"					;// props added to 800 PK 15
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/type_96_LMG/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/type_96_LMG/"}
		{if rand 0.10
			{tags add "shield"}
			{ani_wind "deploy" end}
		else
			{volumes "shield1" disable bullet blast touch contact contact_ground}
			{volumes "shield2" disable bullet blast touch contact contact_ground}
			{volumes "shield3" disable bullet blast touch contact contact_ground}
			{volumes "shield4" disable bullet blast touch contact contact_ground}
			{view hide "shield_monopod"}
			{view hide "shield"}
		}
	}
	{on "weapon_reload" overload
		{if rand 0.2
			{delay 0.1
				{kill_delay "recoil"}
				{ani_play "reload"}
				{tear "piece_small_steel" bone "magazine" copy 
					{impulse up -0.01}
				}
				{delay 0.1
					{view hide "magazine"}
				}
				{delay 2.5
					{view show "magazine"}
					{view show "bullet"}
				}
			}
		else
			{kill_delay "recoil"}
			{ani_play "reload"}
		}
	}
	{on "link_human" overload
		{if tagged "shield"

		else
			{ani_play "deploy"}
		}
	}
	{on "unlink_human" overload
		{if tagged "shield"

		else
			{ani_play "deploy" -1}
		}
	}
	{on "link" overload ;// linked to vehicle
		{if tagged "shield"

		else
			{ani_wind "deploy" begin}
		}					
	}
	{on "link_open"	 overload			;// linked to vehicle opened
		{if tagged "shield"

		else
			{ani_wind "deploy" end}

		}
	}
	("magazine" cut(1) show(2.5) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_17_lmg"					;// props added to 800 PK 15
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/type_96_LMG/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/type_96_LMG/"}
		{if rand 0.10
			{tags add "shield"}
			{ani_wind "deploy" end}
		else
			{volumes "shield1" disable bullet blast touch contact contact_ground}
			{volumes "shield2" disable bullet blast touch contact contact_ground}
			{volumes "shield3" disable bullet blast touch contact contact_ground}
			{volumes "shield4" disable bullet blast touch contact contact_ground}
			{view hide "shield_monopod"}
			{view hide "shield"}
		}
	}
	{on "weapon_reload" overload
		{if rand 0.2
			{delay 0.1
				{kill_delay "recoil"}
				{ani_play "reload"}
				{tear "piece_small_steel" bone "magazine" copy 
					{impulse up -0.01}
				}
				{delay 0.1
					{view hide "magazine"}
				}
				{delay 2.5
					{view show "magazine"}
					{view show "bullet"}
				}
			}
		else
			{kill_delay "recoil"}
			{ani_play "reload"}
		}
	}
	{on "link_human" overload
		{if tagged "shield"

		else
			{ani_play "deploy"}
		}
	}
	{on "unlink_human" overload
		{if tagged "shield"

		else
			{ani_play "deploy" -1}
		}
	}
	{on "link" overload ;// linked to vehicle
		{if tagged "shield"

		else
			{ani_wind "deploy" begin}
		}					
	}
	{on "link_open"	 overload			;// linked to vehicle opened
		{if tagged "shield"

		else
			{ani_wind "deploy" end}

		}
	}
	("magazine" cut(1) show(2.5) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_96_lmg"					;// props added to 800 PK 15
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/type_96_LMG/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/type_96_LMG/"}
		{if rand 0.10
			{tags add "shield"}
			{ani_wind "deploy" end}
		else
			{volumes "shield1" disable bullet blast touch contact contact_ground}
			{volumes "shield2" disable bullet blast touch contact contact_ground}
			{volumes "shield3" disable bullet blast touch contact contact_ground}
			{volumes "shield4" disable bullet blast touch contact contact_ground}
			{view hide "shield_monopod"}
			{view hide "shield"}
		}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
	{on "link_human" overload
		{if tagged "shield"

		else
			{ani_play "deploy"}
		}
	}
	{on "unlink_human" overload
		{if tagged "shield"

		else
			{ani_play "deploy" -1}
		}
	}
	{on "link" overload ;// linked to vehicle
		{if tagged "shield"

		else
			{ani_wind "deploy" begin}
		}					
	}
	{on "link_open"	 overload			;// linked to vehicle opened
		{if tagged "shield"

		else
			{ani_wind "deploy" end}

		}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_99_lmg"					;// props added to 800 PK 15
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/type_99_LMG/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/type_99_LMG/"}
		{if rand 0.10
			{tags add "shield"}
			{ani_wind "deploy" end}
		else
			{volumes "shield1" disable bullet blast touch contact contact_ground}
			{volumes "shield2" disable bullet blast touch contact contact_ground}
			{volumes "shield3" disable bullet blast touch contact contact_ground}
			{volumes "shield4" disable bullet blast touch contact contact_ground}
			{view hide "shield_monopod"}
			{view hide "shield"}
		}
		{if rand 0.5
			{view hide "bayonet_japanese_early"}
		else
			;nothing
		}
	}
	{on "link_human" overload
		{if tagged "shield"

		else
			{ani_play "deploy"}
		}
	}
	{on "unlink_human" overload
		{if tagged "shield"

		else
			{ani_play "deploy" -1}
		}
	}
	{on "link" overload ;// linked to vehicle
		{if tagged "shield"

		else
			{ani_wind "deploy" begin}
		}					
	}
	{on "link_open"	 overload			;// linked to vehicle opened
		{if tagged "shield"

		else
			{ani_wind "deploy" end}

		}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon hanyang_rifle"					;// props added to all AT4 Variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/M39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/M39/"}
		{if rand 0.5
			{view hide "bayonet"}
		else
			;nothing
		}
	}
}

{"stuff weapon type_24"							;// props added to all  k 98k variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/k98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/k98k/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/k98k/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/"}
		{if rand 0.5
			{view hide "bayonet"}
		else
			;nothing
		}
	}
}

{"stuff weapon hanyang_carbine"					;// props added to all AT4 Variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/M39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/M39/"}
	}
}

{"stuff weapon type_92_aa"					;// props added to DP 27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/DP27/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/DP27/"}
	}
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}

{"stuff weapon Hanyang_rifle"					;// props added to 762 kiv 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/fin/m39/"}
	}
}

;/***=========== PROPS WEAPONS MACE START ===========***/

{"jp_konbaku_backpack"
	{on blast
		{if min_energy 1	
			{set "blast" 0}
			{delay 0.1
				{spawn "explosion" "med_backpack"}
				{delete}
			}
		else
			{set "blast" 0}
			{delay 0.1
				{spawn "explosion" "med_backpack"}
				{delete}
			}
		}
	}	
}

{"kamikaze_bomb"
	{on blast
		{if min_energy 1	
			{set "blast" 0}
			{delay 0.1
				{spawn "explosion" "bomb"}
				{delete}
			}
		else
			{set "blast" 0}
			{delay 0.1
				{spawn "explosion" "bomb"}
				{delete}
			}
		}
	}	
}

{"japanese_radio"
	{on spawn
		{if rand 0.5
			{view hide "hatch"}
		else
			;nothing
		}
	}
}

{"stuff weapon pvg_m42"
    {on spawn
        {link_sound "mid"			"weapon/shot/reactive/d2/Shared/Rocket_Launcher/"}
		{link_sound "far"			"weapon/shot/reactive/d3/Shared/Rocket_Launcher/"}
        {if rand 0.5
           {view hide "detail1"}
        else
          ;nothing
        }
    }
	("magazine" cut(1.5) show(2.9) override(overload) impulse({impulse forward -1}))
}

{"stuff weapon madsen_belt"						;// props added to 762 PK 20
	{on spawn 
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/LS26/"}	; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/LS26/"}	; Placeholder
	}
}

{"stuff weapon madsen_tank"						;// props added to 762 PK 20
	{on spawn 
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/LS26/"}	; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/LS26/"}	; Placeholder
	}
}

{"stuff weapon pansarskott_m46"					;// props added to all Panzerfaust Variants
	{on "fire"
		{view hide	"charge"}
		{view hide	"safety"}
	}
}

;{"pansarskott_m46"
;	("at_weapon_icon" icon(icon_panzerfaust))
;	{on "fire"
;		{delay 1
;			{view stop "wp_view"}
;		}
;	}	
;}

{"stuff weapon browning_m19a4_nomag"				;// props added to Browning M1919A4 .30 Cal
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
	}
}

{"stuff weapon type_mo"							;// props added to all  k 98k variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/k98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/k98k/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/k98k/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/"}
	}
}

;/***=========== PROPS SCRIPT MACE START ===========***/

(define "3x3_barrage_mace"		;// custom barrage.
	{on spawn
		{if not tagged "fired"
			{tags add "fired"}

			("rnd_art_bomb" delay(0.5) shell(%shell) postion(%postion))
			("rnd_art_bomb" delay(1.0) shell(%shell) postion(%postion))
			("rnd_art_bomb" delay(1.5) shell(%shell) postion(%postion))

			("rnd_art_bomb" delay(16.5) shell(%shell) postion(%postion))
			("rnd_art_bomb" delay(17.0) shell(%shell) postion(%postion))
			("rnd_art_bomb" delay(17.5) shell(%shell) postion(%postion))

			("rnd_art_bomb" delay(32.5) shell(%shell) postion(%postion))
			("rnd_art_bomb" delay(33.0) shell(%shell) postion(%postion))
			("rnd_art_bomb" delay(33.5) shell(%shell) postion(%postion))

			{hide 40}
			{delay 41 {delete}}
		}
	}
)

{"offmap_dummy 460"
	("offmap" args "artillery_single_460")
}

{"artillery_barrage_460"		;// 1 battalion, 9 guns firing 1 shells each
	("3x3_barrage_mace" shell(artillery_single_460_dummy) postion(1000))
}

{"artillery_barrage_460_yamato"		;// 1 battalion, 9 guns firing 1 shells each
	("3x3_barrage_mace" shell(artillery_single_460_dummy) postion(1000))
}

{"flare_artillery_460"				;// Flare that spawns shells that fall to ground. Off-map artillery
	{on spawn
		{add_view "smoke_flare_red" "smoke" "root"}
		{view start "smoke"}
		{delay 15 {spawn "artillery_barrage_460"}}
		{delay 45 {view stop "smoke"}}
		{delay 45 {delete}}
	}
}

{"stuff weapon type_17_smg"						;// props added to mp 28
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ger/mp40/"}	; placeholder
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/ger/mp40/"}	; placeholder
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon national_defence_rifle"					;// props added to all Webley Revolver Variants
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/ENG/Webley_MkIV/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/ENG/Webley_MkIV/"}
	}
	{on "fire"
		{ani_play "bolt_action"}
	}	
}

{"stuff weapon type_ru_large"                ;// props added to Lewis Gun Mk.I
    {on spawn
        {link_sound "action_recoil"    "weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
        {link_sound "mid"        "weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/"}
        {link_sound "far"        "weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/"}
    }
    ("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_ru"                ;// props added to Lewis Gun Mk.I
    {on spawn
        {link_sound "action_recoil"    "weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
        {link_sound "mid"        "weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/"}
        {link_sound "far"        "weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/"}
    }
    ("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_92"                ;// props added to Lewis Gun Mk.I
    {on spawn
        {link_sound "action_recoil"    "weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
        {link_sound "mid"        "weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/"}
        {link_sound "far"        "weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/"}
    }
    ("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}

;//---------------------HELP ME GOD


{"sortie"			;Sorties used to include 4 different animations to randomize direction of bombing run, now just uses flyin_1
	{on spawn
		{spawn "crosshair" {delay 10 {hide 1}}}
		{delay 5
			{if rand 0.45			
				{tags add "spawn1"}
				else rand 0.45	
				{tags add "spawn2"}
				else rand 0.45
				{tags add "spawn3"}
				else 
				{tags add "spawn4"}
			}
		}
		{delay 10
			{if tagged "spawn1"
				{call "rocket_launch1"}
				{delay 10
					{delete}
				}	
			else tagged "spawn2"
				{call "rocket_launch2"}
				{delay 10
					{delete}
				}
			else tagged "spawn3"
				{call "rocket_launch3"}
				{delay 10
					{delete}
				}
			else tagged "spawn4"
				{call "rocket_launch4"}
				{delay 10
					{delete}
				}
			}			
		}	
	}
;;;;;;;;;;;;;;;;;;;;// ROCKET STRIKES


	{on "rocket_launch1"
		{delay 0.01 
			{spawn "ki_148_ammo" "bone1" x dir_velocity
				{impulse forward 55 rnd_dir 0 com}
				{gravity 0.6}
				{linear_damping 0}
			}
		}
	}
	{on "rocket_launch2"
		{delay 0.01 
			{spawn "ki_148_ammo" "bone2" x dir_velocity
				{impulse forward 55 rnd_dir 0 com}
				{gravity 0.6}
				{linear_damping 0}
			}
		}
	}
	{on "rocket_launch3"
		{delay 0.01 
			{spawn "ki_148_ammo" "bone3" x dir_velocity
				{impulse forward 55 rnd_dir 0 com}
				{gravity 0.6}
				{linear_damping 0}
			}
		}
	}
	{on "rocket_launch4"
		{delay 0.01 
			{spawn "ki_148_ammo" "bone4" x dir_velocity
				{impulse forward 55 rnd_dir 0 com}
				{gravity 0.6}
				{linear_damping 0}
			}
		}
	}
	{on ground_hit
		{call "explosion"}
		{stop_sound "rocket_launch"}
	}
	{on contact
		{call "explosion"}
		{stop_sound "rocket_launch"}
	}
	{on "explosion"
		{stuff_detonate}
		{stop_sound "rocket_launch"}
	}
}

;;;;;;;;;;;;;;;;;;;;;// ROCKET STRIKES

{"rocket_single"			;// Settings for all ROCKETS that are launched by script	
	{on spawn
		{add_view	"rocket_smoke_bm13"			"rockettrail"				"tail"}
		{link_sound "rocket_launch"				"vehicle/airborne/rocket_launch/"}
		{play_sound "rocket_launch"}
		{delay 0.2
			{view start "rockettrail"}
		}
		{delay 0.4
			{view start "rockettrail"}
		}
		{delay 0.6
			{view start "rockettrail"}
		}
		{delay 0.8
			{view start "rockettrail"}
		}
		{delay 1.0
			{view start "rockettrail"}
		}
		{delay 1.2
			{view start "rockettrail"}
		}
		{delay 1.4
			{view start "rockettrail"}
		}
		{delay 1.6
			{view start "rockettrail"}
		}
		{delay 1.8
			{view start "rockettrail"}
		}
		{delay 2.0
			{view start "rockettrail"}
		}
		{delay 2.2
			{view start "rockettrail"}
		}
		{delay 2.4
			{view start "rockettrail"}
		}
		{delay 2.6
			{view start "rockettrail"}
		}
	}
	{on ground_hit
		{call "explosion"}
		{stop_sound "rocket_launch"}
	}
	{on contact
		{call "explosion"}
		{stop_sound "rocket_launch"}
	}
	{on "explosion"
		{stuff_detonate}
		{stop_sound "rocket_launch"}
	}
}

{"ki_148_plane_sound"			;Sorties used to include 8 different animations to randomize direction of bombing run, now just uses flyin_1
	{on spawn
		{link_sound "plane_launch"				"vehicle/airborne/plane_launch/"}
		{link_sound "plane_siren"				"world/alarm/sirene01"}
		{play_sound "plane_siren"}
		{play_sound "plane_launch"}
		{delay 160
			{delete}
		}
	}
}

{"type_99_entity"
	{on spawn 
		{link_sound "shot"        "weapon/shot/grenade_launcher/"}
		{link_sound "smoke_loop"	"detonation/grenade_smoke/generic/detonation_misc_s1_smoke_generic_loop"}
		{play_sound "smoke_loop" 1}
		{delay 2.5
			{play_sound "shot"}
			{stop_sound "smoke_loop"}
			{tear "piece_tiny_steel_type_99_candle" bone "Type_99_shell" 
				{impulse forward 30 rnd_dir 0 com}
				{gravity 1}
				{linear_damping 0}
			}
		}
		{delay 135
			{delete}
		}
	}
}

{"delete_instant"		;// This prop makes entities delete themselves after 10 miliseconds
	{on spawn	
		{delay 0.1 {delete}}
	}
}

{"stuff weapon garand_mortar_launcher"		;// props added to m1 garand w/ m7 grenade launcher
	{on spawn
		{add_view "shell_rifle_m1_garand"	"shell"		"fxshell"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/usa/m1_garand/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/usa/m1_garand/m7_grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/usa/m1_garand/m7_grenade_launcher/"}
	}
}
{"carpet_bombing"			;Sorties used to include 4 different animations to randomize direction of bombing run, now just uses flyin_1
	{on spawn
		{delay 5 
			{spawn "sc_250" "bombA4" x dir_velocity
				{impulse forward 1 rnd_dir 0 com}
				{gravity 1}
				{linear_damping 0}
			}
			{spawn "sc_250" "bombA3" x dir_velocity
				{impulse forward 1 rnd_dir 0 com}
				{gravity 1}
				{linear_damping 0}
			}
			{spawn "sc_250" "bombA2" x dir_velocity
				{impulse forward 1 rnd_dir 0 com}
				{gravity 1}
				{linear_damping 0}
			}
			{spawn "sc_250" "bombA1" x dir_velocity
				{impulse forward 1 rnd_dir 0 com}
				{gravity 1}
				{linear_damping 0}
			}
			{spawn "sc_250" "bomb00" x dir_velocity
				{impulse forward 1 rnd_dir 0 com}
				{gravity 1}
				{linear_damping 0}
			}
			{spawn "sc_250" "bombB1" x dir_velocity
				{impulse forward 1 rnd_dir 0 com}
				{gravity 1}
				{linear_damping 0}
			}
			{spawn "sc_250" "bombB2" x dir_velocity
				{impulse forward 1 rnd_dir 0 com}
				{gravity 1}
				{linear_damping 0}
			}
			{spawn "sc_250" "bombB3" x dir_velocity
				{impulse forward 1 rnd_dir 0 com}
				{gravity 1}
				{linear_damping 0}
			}
			{spawn "sc_250" "bombB4" x dir_velocity
				{impulse forward 1 rnd_dir 0 com}
				{gravity 1}
				{linear_damping 0}
			}
		}
	}	
}
