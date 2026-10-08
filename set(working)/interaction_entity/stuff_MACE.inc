;(include "stuff.inc") don't comment in otherwise it will cause the double casing bug for small arms for some reason
;/***=========== VIEW MACE START ===========***/

;{"pansarskott_m46"
;	("at_weapon_icon" icon(icon_panzerfaust))
;	{on "fire"
;		{delay 1
;			{view stop "wp_view"}
;		}
;	}	
;}

{"type_5_recoiless"
	("at_weapon_icon" icon(icon_type5_at))
}

{"70mm_type_4_ai_kung"
	("at_weapon_icon" icon(icon_type5_at))
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

{"type38_grenade_launcher"
	("at_weapon_icon" icon(icon_type38_at))
}

{"type99_mid_grenade_launcher"
	("at_weapon_icon" icon(icon_type2_at))
}

{"type38_early_grenade_91_launcher"
	("at_weapon_icon" icon(icon_type99_3_at))
}

{"type99_early_grenade_3_launcher"
	("at_weapon_icon" icon(icon_type99_3_at))
}

{"type99_bouganville_launcher"
	("at_weapon_icon" icon(icon_bouganville_at))
}

{"type99_early_grenade_launcher"
	("at_weapon_icon" icon(icon_type2_at))
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

;/*=========== Generic Weapon Settings Begin ===========*/
("flash_fx" tag(murata)		    flash(flash_mortar_nosound)	foresight(12));MACE MURATA
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
        {link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/ppsh41/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/tail/"}
    }
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon sig_mkms"
    {on spawn
        {link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/ppsh41/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/tail/"}
    }
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "fire"
		("Automatic")
	}
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
        {link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
    }
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon beretta_m38a"
    {on spawn
        {link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
    }
	{on "fire"
		("Automatic")
	}
}
{"stuff weapon al_43"
    {on spawn
        {link_sound 	"action_recoil"		"weapon/action/recoil/closed_bolt/stg44/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s2/d1/ger/stg44/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s2/d2/ger/stg44/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s2/d2/ger/stg44/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s2/d3/ger/stg44/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s2/d3/ger/stg44/tail/"}
    }
	{on "fire"
		("Automatic")
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound 	"mid"				"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s3/d3/fin/m39/"}
	}
}	

{"stuff weapon carcano_1891"					;// props added to all AT4 Variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M9130/"}
		{link_sound 	"action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound 	"mid"				"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s3/d3/fin/m39/"}
	}
	{on "weapon_reload"
		{delay 0.1
			{tear "piece_small_steel" bone "magazine" copy 
				{impulse up -0.01}
			}
		}
		{delay 0.15
			{view hide "magazine"}
			{delay 3.4
				{view show "magazine"}
			}
		}
	}		
}	

{"stuff weapon as44"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s2/d1/ger/stg44/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/SVT40/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/SVT40/"}
	}
	{on "fire"
		("Automatic")
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/closed_bolt/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg13/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg13/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg13/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg13/tail/"}
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
		("Automatic")
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
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s1/recoil/usa/m1a1_thompson/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/tail/"}
		{add_view	"shell_pistol"	"smg_eject1"	"fxshell"}
	}
	{on "fire"
			("Automatic")
			{ani_play "bolt_action"}
			{view start "smg_eject1"}
	}
	("magazine" cut(1) show(2.9) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon m50_reising_30"
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s1/recoil/usa/m1a1_thompson/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s1/d1/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s1/d2/usa/m1a1_thompson/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s1/d3/usa/m1a1_thompson/tail/"}
		{add_view	"shell_pistol"	"smg_eject1"	"fxshell"}
	}
	{on "fire"
			("Automatic")
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/closed_bolt/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/fg42/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/fg42/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/fg42/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/fg42/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/fg42/tail/"}
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
		("Automatic")
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
		{link_sound			"HMG_action_recoil"		"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound			"HMG_tail_close" 		"weapon/shot/smallarms/s4/d1/USA/M2HB/Tail/"}
		{link_sound			"HMG_head_mid" 			"weapon/shot/smallarms/s4/d2/USA/M2HB/Head/"}
		{link_sound			"HMG_tail_mid" 			"weapon/shot/smallarms/s4/d2/USA/M2HB/Tail/"}
		{link_sound			"HMG_head_far" 			"weapon/shot/smallarms/s4/d3/RUS/DShK38/Head/"}
		{link_sound			"HMG_tail_far" 			"weapon/shot/smallarms/s4/d3/RUS/DShK38/Tail/"}
	}
	{on "fire"
		("Automatic")
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
		{link_sound			"HMG_action_recoil"		"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound			"HMG_tail_close" 		"weapon/shot/smallarms/s4/d1/USA/M2HB/Tail/"}
		{link_sound			"HMG_head_mid" 			"weapon/shot/smallarms/s4/d2/USA/M2HB/Head/"}
		{link_sound			"HMG_tail_mid" 			"weapon/shot/smallarms/s4/d2/USA/M2HB/Tail/"}
		{link_sound			"HMG_head_far" 			"weapon/shot/smallarms/s4/d3/RUS/DShK38/Head/"}
		{link_sound			"HMG_tail_far" 			"weapon/shot/smallarms/s4/d3/RUS/DShK38/Tail/"}
	}
	{on "fire"
		("Automatic")
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
		{link_sound			"HMG_action_recoil"		"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound			"HMG_tail_close" 		"weapon/shot/smallarms/s4/d1/USA/M2HB/Tail/"}
		{link_sound			"HMG_head_mid" 			"weapon/shot/smallarms/s4/d2/USA/M2HB/Head/"}
		{link_sound			"HMG_tail_mid" 			"weapon/shot/smallarms/s4/d2/USA/M2HB/Tail/"}
		{link_sound			"HMG_head_far" 			"weapon/shot/smallarms/s4/d3/RUS/DShK38/Head/"}
		{link_sound			"HMG_tail_far" 			"weapon/shot/smallarms/s4/d3/RUS/DShK38/Tail/"}
	}
	{on "fire"
		("Automatic")
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

{"stuff weapon type93_fixed"					;// props added to 800 PK 15
	{on spawn
		{link_sound			"HMG_action_recoil"		"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound			"HMG_tail_close" 		"weapon/shot/smallarms/s4/d1/USA/M2HB/Tail/"}
		{link_sound			"HMG_head_mid" 			"weapon/shot/smallarms/s4/d2/USA/M2HB/Head/"}
		{link_sound			"HMG_tail_mid" 			"weapon/shot/smallarms/s4/d2/USA/M2HB/Tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/13_2_HMG/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/13_2_HMG/"}
	}
	{on "fire"
		("Automatic")
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound 	"mid"				"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s3/d3/fin/m39/"}
		{if rand 0.5
			{view hide "bayonet"}
		else
			;nothing
		}
	}
	{on "fire"
		("Automatic")
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon type_2_smg_1934"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff tokyo_arsenal_model_1927"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
	}
	{on "fire"
		("Automatic")
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp40/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon type_99_lmg_paratrooper"					;// props added to 800 PK 15
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/JAP/type_99_LMG/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/type_99_LMG/"}
	}
	{on "fire"
		("Automatic")
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
	("magazine" cut(0.5) show(2.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_99_lmg_paratrooper_unfold"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/type_99_LMG/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/JAP/type_99_LMG/"}
	}
	{on "fire"
		("Automatic")
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
	("magazine" cut(0.5) show(2.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon an_m2_stinger"                ;// props added to Browning M1919A4 .30 Cal
    {on spawn
        {link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_mg/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/usa/m1919a4/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/usa/m1919a4/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/usa/m1919a4/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/usa/m1919a4/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/usa/m1919a4/tail/"}
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
        {link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/ppsh41/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/ppsh41/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/ppsh41/tail/"}
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
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/ger/mg42/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/ger/mg42/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/ger/mg42/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/ger/mg42/tail/"}
	}
	("magazine" cut(1) show(2.25) override(overload) impulse({impulse up 0.5 forward 0.9 0.1}))
	{on "fire"
		("Automatic")
	}
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
        {link_sound 	"action_recoil"		"weapon/action/recoil/closed_bolt/stg44/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s2/d1/ger/stg44/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s2/d2/ger/stg44/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s2/d2/ger/stg44/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s2/d3/ger/stg44/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s2/d3/ger/stg44/tail/"}
    }
    ("magazine" cut(1.20) show(2) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon stg45m"
    {on spawn
        {link_sound 	"action_recoil"		"weapon/action/recoil/closed_bolt/stg44/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s2/d1/ger/stg44/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s2/d2/ger/stg44/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s2/d2/ger/stg44/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s2/d3/ger/stg44/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s2/d3/ger/stg44/tail/"}
    }
    ("magazine" cut(1.20) show(2) override(overload) impulse({impulse up -0.01}))
	{on "fire"
		("Automatic")
	}
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound 	"mid"				"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s3/d3/fin/m39/"}
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
	{on "fire"
		("Automatic")
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound 	"mid"				"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s3/d3/fin/m39/"}
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
	{on "fire"
		("Automatic")
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp40/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
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
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon sig_1920_type_ger"						;// props added to MP 28
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp40/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
		{view hide "bayonet_japanese_early"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "weapon_reload" 
		{ani_play "reload"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon type_tsing_tao"						;// props added to MP 28
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp40/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "weapon_reload" 
		{ani_play "reload"}
	}
	{on "fire"
		("Automatic")
		{spawn "bazooka_shot"	"fxshot" x}
	}
}

{"stuff weapon mp_18"						;// props added to MP 28
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp40/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
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
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mp34_jap"						;// props added to MP 28
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp40/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
	}
	("magazine" cut(0.75) show(3) override(overload) impulse({impulse up -0.01}))
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mp34"						;// props added to MP 28
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp40/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
	}
	("magazine" cut(0.75) show(3) override(overload) impulse({impulse up -0.01}))
	{on "fire"
		("Automatic")
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

{"stuff weapon 2inch_mortar_mkii"					;// props added to 762 KIV 91-27
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
	{on "link_human"
		{ani_play "close" -1}
	}
	{on "unlink_human"
		{ani_play "close" 1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "close" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "close" end}
	}
}

{"stuff weapon 2inch_mortar_mkiii"					;// props added to 762 KIV 91-27
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

{"stuff weapon 2inch_mortar_mkvii"					;// props added to 762 KIV 91-27
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
		{if rand 0.5
			{view hide "bayonet_mid"}
		else
			;nothing
		}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon type_100_smg_early_bipod"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
		{if rand 0.5
			{view hide "bayonet_mid"}
		else
			;nothing
		}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon type_100_smg_late"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
		{if rand 0.5
			{view hide "bayonet_japanese_late"}
		else
			;nothing
		}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon type_100_smg_para"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/type2/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/rus/pps43/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/rus/pps43/tail/"}
		{if rand 0.5
			{view hide "bayonet_paratrooper"}
		else
			;nothing
		}
		;{ani_wind "bipod_open" begin}
	}
	{on "fire"
		("Automatic")
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

{"stuff weapon mauser_c96_carbine_10"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mauser_c96_carbine_20"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mauser_c96_carbine_30"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mauser_c96_carbine_40"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mauser_c96_m1932_nostock"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mauser_c96_m1932_stock"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mauser_c96_chi_nostock"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon mauser_c96_nostock"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}

{"stuff weapon mauser_c96_stock"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/rus/pps43/tail/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon type_11_lmg"					;// props added to 800 PK 15
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
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
	{on "fire"
		("Automatic")
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
	{on "fire"
		("Automatic")
	}
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
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
	("magazine" cut(0.5) show(2.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_96_lmg"					;// props added to 800 PK 15
	{on "fire"
		("Automatic")
	}
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
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
	("magazine" cut(0.5) show(2.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_99_lmg"					;// props added to 800 PK 15
	{on "fire"
		("Automatic")
	}
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
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
	("magazine" cut(0.5) show(2.0) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon hanyang_rifle"					;// props added to all AT4 Variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M9130/"}
		{link_sound 	"action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound 	"mid"				"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s3/d3/fin/m39/"}
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
		{link_sound 	"action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound 	"mid"				"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s3/d3/fin/m39/"}
	}
}

{"stuff weapon type_92_aa"					;// props added to DP 27
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/rus/dp27/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/tail/"}
	}
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon Hanyang_rifle"					;// props added to 762 kiv 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/m9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/m9130/"}
		{link_sound 	"action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound 	"mid"				"weapon/shot/smallarms/s3/d2/fin/m39/"}
		{link_sound 	"far"				"weapon/shot/smallarms/s3/d3/fin/m39/"}
	}
}

{"stuff weapon type_17_smg"						;// props added to mp 28
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ger/mp40/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ger/mp40/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ger/mp40/tail/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "fire"
		("Automatic")
	}
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

{"stuff weapon enfield_no5_mk1"					;// props added to 762 KIV 91-27
	{on spawn
		{if rand 0.5
			{view hide "bayonet_carbine"}
		else
			;nothing
		}
	}
}

{"stuff weapon austen_smg"				;// props added to STEN Gun and Variants
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_smg/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s1/d1/ENG/STEN_Gun/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s1/d2/ENG/STEN_Gun/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s1/d2/ENG/STEN_Gun/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s1/d3/ENG/STEN_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s1/d3/ENG/STEN_Gun/tail/"}
		{ani_wind "deploy" end}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "link_human" overload
		{ani_play "deploy" -1}
	}
	{on "unlink_human" overload
		{ani_play "deploy" 1}
	}
	{on "link" overload ;// linked to vehicle
		{ani_wind "deploy" begin}					
	}
	{on "link_open"	 overload			;// linked to vehicle opened
		{ani_wind "deploy" end}
	}
	{on "fire"
		("Automatic")
	}	
}

{"stuff weapon hotchkiss_mk1"					;// props added to DP 27
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		{link_sound 	"Tail_Close"		"weapon/shot/smallarms/s3/d1/rus/dp27/tail/"}
		{link_sound 	"Head_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/head/"}
		{link_sound 	"Tail_Mid"			"weapon/shot/smallarms/s3/d2/rus/dp27/tail/"}
		{link_sound 	"Head_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/head/"}
		{link_sound 	"Tail_Far"			"weapon/shot/smallarms/s3/d3/rus/dp27/tail/"}
		{tags add "slide0"}
	}

	(define "reset_bullet_tags"
		{tags remove "slide1"}
		{tags remove "slide2"}
		{tags remove "slide3"}
		{tags remove "slide4"}
		{tags remove "slide5"}
		{tags remove "slide6"}
		{tags remove "slide7"}
		{tags remove "slide8"}
		{tags remove "slide9"}
		{tags remove "slide10"}
		{tags remove "slide11"}
		{tags remove "slide12"}
		{tags remove "slide13"}
		{tags remove "slide14"}
		{tags remove "slide15"}
		{tags remove "slide16"}
		{tags remove "slide17"}
		{tags remove "slide18"}
		{tags remove "slide19"}
		{tags remove "slide20"}
		{tags remove "slide21"}
		{tags remove "slide22"}
		{tags remove "slide23"}
		{tags remove "slide24"}
		{tags remove "slide25"}
		{tags remove "slide26"}
		{tags remove "slide27"}
		{tags remove "slide28"}
		{tags remove "slide29"}
		{tags remove "slide30"}
		{tags add "slide0"}
	)

	(define "all_bullets"
		{bone %state "bullets0"}
		{bone %state "bullets1"}
		{bone %state "bullets2"}
		{bone %state "bullets3"}
		{bone %state "bullets4"}
		{bone %state "bullets5"}
		{bone %state "bullets6"}
		{bone %state "bullets7"}
		{bone %state "bullets8"}
		{bone %state "bullets9"}
		{bone %state "bullets10"}
		{bone %state "bullets11"}
		{bone %state "bullets12"}
		{bone %state "bullets13"}
		{bone %state "bullets14"}
		{bone %state "bullets15"}
		{bone %state "bullets16"}
		{bone %state "bullets17"}
		{bone %state "bullets18"}
		{bone %state "bullets19"}
		{bone %state "bullets20"}
		{bone %state "bullets21"}
		{bone %state "bullets22"}
		{bone %state "bullets23"}
		{bone %state "bullets24"}
		{bone %state "bullets25"}
		{bone %state "bullets26"}
		{bone %state "bullets27"}
		{bone %state "bullets28"}
		{bone %state "bullets29"}
		{bone %state "bullets30"}
	)

	(define "magazine_multiple_bullets"
		{on "magazine_delay" %override
			{delay %cut
				("all_bullets" state(hide))
				{tear "piece_tiny_steel" bone "magazine" copy 
					%impulse
				}
				{delay 0
					{view hide "magazine"}
					{delay %show
						{view show "magazine"}
						("all_bullets" state(show))
						("reset_bullet_tags")
					}
				}
			}
		}
	)

	(define "advance_slide"
		{if tagged "slide%current"
			{tags remove "slide%current"}
			{delay 0.01
				{tags add "slide%next"}
			}	
			{ani_play "slide_%next"}
			{bone hide "bullets%current"}
		}
	)

	("magazine_multiple_bullets" cut(0) show(2.5) override(overload) impulse({impulse forward 2}))

	{on "fire"
		("advance_slide" current(29) next(30))
		("advance_slide" current(28) next(29))
		("advance_slide" current(27) next(28))
		("advance_slide" current(26) next(27))
		("advance_slide" current(25) next(26))
		("advance_slide" current(24) next(25))
		("advance_slide" current(23) next(24))
		("advance_slide" current(22) next(23))
		("advance_slide" current(21) next(22))
		("advance_slide" current(20) next(21))
		("advance_slide" current(19) next(20))
		("advance_slide" current(18) next(19))
		("advance_slide" current(17) next(18))
		("advance_slide" current(16) next(17))
		("advance_slide" current(15) next(16))
		("advance_slide" current(14) next(15))
		("advance_slide" current(13) next(14))
		("advance_slide" current(12) next(13))
		("advance_slide" current(11) next(12))
		("advance_slide" current(10) next(11))
		("advance_slide" current(9) next(10))
		("advance_slide" current(8) next(9))
		("advance_slide" current(7) next(8))
		("advance_slide" current(6) next(7))
		("advance_slide" current(5) next(6))
		("advance_slide" current(4) next(5))
		("advance_slide" current(3) next(4))
		("advance_slide" current(2) next(3))
		("advance_slide" current(1) next(2))
		("advance_slide" current(0) next(1))
		("Automatic")
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

{"stuff weapon madsen_tank"						;// props added to 762 PK 20
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

{"stuff weapon pansarskott_m46"					;// props added to all Panzerfaust Variants
	{on "fire"
		{view hide	"charge"}
		{view hide	"safety"}
	}
}

{"stuff weapon browning_m19a4_nomag"				;// props added to Browning M1919A4 .30 Cal
	{on spawn
		{link_sound 	"action_recoil"		"weapon/action/recoil/open_bolt_mg/"}
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

{"stuff weapon type_mo"							;// props added to all  k 98k variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/k98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/k98k/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ger/k98k/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ger/k98k/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ger/k98k/"}
	}
}

{"stuff weapon type_ru_large"				;// props added to Lewis Gun Mk.I
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/eng/Lewis_Gun/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon type_ru"				;// props added to Lewis Gun Mk.I
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/eng/Lewis_Gun/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
	{on "fire"
		("Automatic")
	}
}

{"stuff weapon type_92"				;// props added to Lewis Gun Mk.I
	{on spawn
		{link_sound 	"action_recoil"		"weapon/shot/smallarms/s3/recoil/eng/bren_gun/"}
		{link_sound		"Tail_Close"		"weapon/shot/smallarms/s3/d1/eng/Lewis_Gun/tail/"}
		{link_sound		"Head_Mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Mid"			"weapon/shot/smallarms/s3/d2/eng/Lewis_Gun/tail/"}
		{link_sound		"Head_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/head/"}
		{link_sound		"Tail_Far"			"weapon/shot/smallarms/s3/d3/eng/Lewis_Gun/tail/"}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
	{on "fire"
		("Automatic")
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

{"stuff weapon windchetser_1907"					;// props added to m1 and m1a1 carbines
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s2/recoil/usa/m1_carbine/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/usa/m1_carbine/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/usa/m1_carbine/"}
	}
	("magazine" cut(1.05) show(1.95) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon type_97_inf"				;// props added to Lewis Gun Mk.I
	{on spawn
		{link_sound			"Tail_Close"			"weapon/shot/smallarms/s3/d1/Shared/ZB37/tail/"}
		{link_sound			"Head_Mid"				"weapon/shot/smallarms/s3/d2/Shared/ZB37/head/"}
		{link_sound			"Tail_Mid"				"weapon/shot/smallarms/s3/d2/Shared/ZB37/tail/"}
		{link_sound			"Head_Far"				"weapon/shot/smallarms/s3/d3/Shared/ZB37/head/"}
		{link_sound			"Tail_Far"				"weapon/shot/smallarms/s3/d3/Shared/ZB37/tail/"}
	}
	("magazine" cut(0.45) show(1.6) override(overload) impulse({impulse up -0.01}))
	{on "fire"
		("Automatic")
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

{"jap_satchel"
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

;/***=========== SORTIE/OFF MAP SCRIPTS MACE START ===========***/

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

{"delete_instant"		;// This prop makes entities delete themselves after 10 miliseconds
	{on spawn	
		{delay 0.1 {delete}}
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

