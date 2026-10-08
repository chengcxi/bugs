(include "mace_defines.inc")
;/*=========== Generic SCRIPT MACE ===========*/
(define "repair_anm_script_v1" ;// break/repair anm for components
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "turret"
				{ani_play "turret_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
		}
		{call_synced "repair_anm_script_v1"}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
		}
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1 resume}
			}
		}
		{if component "body"
			{if work "turret"
				{ani_play "body_r" +1 resume}
			}
		}
		{call_synced "repair_anm_script_v1"}
	}
)
;/*=========== Generic SCRIPT MACE ===========*/

(define "handle_ik"
	{on ik begin "basis"				;// basis bone rotates
		{play_sound "basis_turret" 1}
	}
	{on ik end "basis"					;// basis stops rotation
		{stop_sound "basis_turret"}
	}
	{on ik begin "turret"				;// turret bone rotates (horizontal rotation)
		{if cannon_state "fire"
			{play_sound "rotate_turret" 1}
			{ani_play "aim_h" loop resume}
		}
	}
	{on ik end "turret"					;// turret stops rotation
		{stop_sound "rotate_turret"}
		{ani_stop "aim_h"}
	}
	{on ik begin "gun_rot"				;// gun bone rotates (vertical rotation)
		{if cannon_state "fire"
			{play_sound "rotate_gun" 1}
			{ani_play "aim_v" loop resume}
		}
	}
	{on ik end "gun_rot"				;// gun stops rotation
		{stop_sound "rotate_gun"}
		{ani_stop "aim_v"}
	}
)

;/*=========== Cannon Begin ===========*/

{"cannon"							;// master / base code for all cannons
	("handle_ik")

	{on animation_end "close"		;// stops rotation sound when cannon switches to closed state
		{tags add "test"} 			;//test (delete when working)
		{stop_sound "rotate_turret"}
		{ani_stop "aim_h"}
	}

	{on "gun_pebble_start"			;// special event called during mission script
		{add_view "gun_broken" "gun_broken" "foresight1"}
		{view start "gun_broken"}
	}

	{on "gun_pebble_stop"			;// special event called during mission script
		{view stop "gun_broken"}
	}

	{on spawn
		{set "engine_on" 0}
	}

	{on move on overload
		{play_sound "move" 1}
	}

	{on turn on overload
		{play_sound "move" 1}
	}

	{on turn off
		{stop_sound "move"}
	}

	{on move off
		{stop_sound "move"}
	}

	{on "add_movement_sound"
		{link_sound "move" "vehicle/cannon_roll"}
	}

	{on pierce sync
		{vehicle_health_damage_pierce}
	}

	(define "impluse_process_blast" 				;// {on blast_hit} blastwave hits any part of entity
		{if min_energy %blast_energy
			{if not linked			;// cannon linked to another vehicle (ex. being towed). Otherwise, impulse will break the link.
				{impulse up (/ %impulse 3) (/ %range 2) dir (/ %impulse 2) %range}
			}
			{if simulating			;// simulating: entity is being handled by physics right now. i.e. being thrown by impulse
				{attack_save}		;// saves attacker information (attacker entity/weapon)
				{delay_ex 0.1
					{attack_load}		;// loads attacker information (attacker entity/weapon)
					;//{crew_throw_off up 2 1 dir 5 1 turn 0 180 forward 1 force} ;// disabled as crew can be thrown of by direct blast to individuals
				}
			}
		}
	)

	{on blast_hit					;// any part of vehicle hit with blast energy
		{if min_mass 100000				;// if mass ≥ 6000 kg			;// Super Heavy Cannons
			; do nothing

		else min_mass 6000				;// if mass ≥ 6000 kg			;// Super Heavy Cannons
			("impluse_process_blast"	blast_energy(9)					;// 150 HE and Up, Dynamite, Air Bombs
				impulse(3.0)			;// impulse amount
				range(0.25)				;// ± to impulse amount
			)
			("impluse_process_blast"	blast_energy(7)					;// 100mm HE - 130mm HE
				impulse(2.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(5)					;// 85mm HE - 93mm HE, AT Mine, 12cm Mortar
				impulse(1.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(3.5)				;// 75mm HE - 77mm HE
				impulse(1.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(2)					;// 37mm HE - 65mm HE, 8cm Mortar, RPG's
				impulse(0.5)
				range(0.25)
			)

		else min_mass 2250	;// if mass ≥ 2,250 kg						;// Heavy Cannons
			("impluse_process_blast"	blast_energy(9)					;// 150 HE and Up, Dynamite, Air Bombs
				impulse(3.5)			;// impulse amount
				range(0.25)				;// ± to impulse amount
			)
			("impluse_process_blast"	blast_energy(7)					;// 100mm HE - 130mm HE
				impulse(2.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(5)					;// 85mm HE - 93mm HE, AT Mine, 12cm Mortar
				impulse(2.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(3.5)				;// 75mm HE - 77mm HE
				impulse(1.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(2)					;// 37mm HE - 65mm HE, 8cm Mortar, RPG's
				impulse(1.0)
				range(0.25)
			)

		else min_mass 800	;// if mass ≥ 800 kg						;// Small Medium Cannons
			("impluse_process_blast"	blast_energy(9)					;// 150 HE and Up, Dynamite, Air Bombs
				impulse(4.0)			;// impulse amount
				range(0.25)				;// ± to impulse amount
			)
			("impluse_process_blast"	blast_energy(7)					;// 100mm HE - 130mm HE
				impulse(3.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(5)					;// 85mm HE - 93mm HE, AT Mine, 12cm Mortar
				impulse(2.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(3.5)				;// 75mm HE - 77mm HE
				impulse(2.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(2)					;// 37mm HE - 65mm HE, 8cm Mortar, RPG's
				impulse(1.5)
				range(0.25)
			)

		else min_mass 300	;// if mass ≥ 300 kg						;// Light Cannons
			("impluse_process_blast"	blast_energy(9)					;// 150 HE and Up, Dynamite, Air Bombs
				impulse(4.5)			;// impulse amount
				range(0.25)				;// ± to impulse amount
			)
			("impluse_process_blast"	blast_energy(7)					;// 100mm HE - 130mm HE
				impulse(3.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(5)					;// 85mm HE - 93mm HE, AT Mine, 12cm Mortar
				impulse(3.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(3.5)				;// 75mm HE - 77mm HE
				impulse(2.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(2)					;// 37mm HE - 65mm HE, 8cm Mortar, RPG's
				impulse(2.0)
				range(0.25)
			)

		else				;// if mass less than 300 kg				;// Carried Cannons
			("impluse_process_blast"	blast_energy(9)					;// 150 HE and Up, Dynamite, Air Bombs
				impulse(5.0)			;// impulse amount
				range(0.25)				;// ± to impulse amount
			)
			("impluse_process_blast"	blast_energy(7)					;// 100mm HE - 130mm HE
				impulse(4.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(5)					;// 85mm HE - 93mm HE, AT Mine, 12cm Mortar
				impulse(3.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(3.5)				;// 75mm HE - 77mm HE
				impulse(3.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(2)					;// 37mm HE - 65mm HE, 8cm Mortar, RPG's
				impulse(2.5)
				range(0.25)
			)
		}
	}

	{on "cut_parts"
		{add_view "smoke_dead_norm" "deathfx" "fxfire1"}
		{view start "deathfx"}
		{if tagged "leave_unit"
			{call "self_destruct"}
		}
		(define "cut_part"
			{if rand %1
				{if "crush"
					{tear "piece_medium_steel" bone %0
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}
						{call "check_delete_part"}
					}
				else
					{tear "piece_medium_steel" bone %0
						{impulse up 4 1 dir 4 2 cx 2 1 cy 2 1 rnd_dir 4 no_position}
						{call "check_delete_part"}
					}
				}
			}
		)
		("cut_part" args "standL" 1)
		("cut_part" args "standL1" 1)
		("cut_part" args "standL2" 1)
		("cut_part" args "standR" 1)
		("cut_part" args "standR1" 1)
		("cut_part" args "standR2" 1)
		("cut_part" args "shield_lower" 1)
		("cut_part" args "wheelL" 0.6)
		("cut_part" args "wheelR" 0.6)
		("cut_part" args "wheelL1" 0.6)
		("cut_part" args "wheelR1" 0.6)
		("cut_part" args "wheelL2" 0.6)
		("cut_part" args "wheelR2" 0.6)
		("cut_part" args "wheelleft" 0.6)
		("cut_part" args "wheelleft1" 0.6)
		("cut_part" args "wheelleft2" 0.6)
		("cut_part" args "wheelright" 0.6)
		("cut_part" args "wheelright1" 0.6)
		("cut_part" args "wheelright2" 0.6)
		("cut_part" args "fragment1" 1)
		("cut_part" args "fragment2" 1)
		("cut_part" args "fragment3" 1)
		("cut_part" args "fragment4" 1)
		("cut_part" args "fragment5" 1)
		("cut_part" args "part1" 0.6)
		("cut_part" args "part2" 0.6)
		("cut_part" args "part3" 0.6)
		("cut_part" args "part4" 0.6)
		("cut_part" args "part5" 0.6)
		("cut_part" args "part6" 0.6)
		("cut_part" args "part7" 0.6)
		("cut_part" args "part8" 0.6)
		("cut_part" args "part9" 0.6)
		("cut_part" args "part10" 0.6)
		{delay 14 {view stop "deathfx"}}
	}

	{on fire "gun"
		{ani_play "recoil"}
		{view start "flashbarrel1"}
		{view start "flashbarrel1smoke"}
		{call "spawn_shell"}
	}

	{on "spawn_shell"
		{tags add "gun_fired"}
		{call "spawn_shell_delay"}
		(define "shell_eject_delay"
			{delay_ex %0
				{ani_play "shell_eject" 1.0}
				{play_sound "breech_open"}
				{delay_ex %1
					{add_view "smoke_breach" "smoke_shell" "fx_invers"}
					{view start "smoke_shell"}
					{delay 2.5 0.5
						{view stop "smoke_shell"}
					}
					{spawn "shell_cannon" "fx_invers" x scale 0.014
						{impulse forward 4 0.5 rnd_dir 0.1 0.1 cz 0.2 0.1 com}
						{add_view "smoke_empty_shell" "smoke_shell" "fx_shellsmoke"}
						{view start "smoke_shell"}
						{delay_effect 3 1 "stop"}
					}
				}
			}
		)
	}

	{on "spawn_shell_delay"
		("shell_eject_delay" args 0.15 0.05)
	}

	{on "reload"
		{call "reload_delay"}
		{call "crew_reload_ani"}
		(define "reload_time"
			{if tagged "gun_fired"
				{delay (- %0 0.5) "shell_eject" ;4.5
					{tags remove "gun_fired"}
					{call "cannon_reloaded"}
				}
			else ;//switching ammo
				{delay 0.75
					{ani_play "shell_eject" 1.0}
					{talk "reload"}
					{play_sound "breech_open"}
				}
				{delay (- %0 0.5)
					{call "cannon_reloaded"}
				}
			}
		)
		{delay 2
			{talk "reload"}
		}
	}

	{on "cannon_reloaded"
		{ani_play "shell_eject" -1.0}
		{play_sound "breech_close"}
		{delay 0.5
			{talk "reloaded"}
		}
	}

	{on "reload_delay"
		("reload_time" args 4.5)		;// weapon reload time
	}

	{on contact
		{if not impregnable
			{if not effector "bicycle"
				{if not effector "armored_car"
					{if effector "tank"
						{call "crush_damage_tank"}
					else effector "train" ;// or "railway"
						{call "crush_damage"}
					else effector "airborne"
						{call "crush_damage"}
					else effector "grenade"
						{if not effector "mine"
							{if not "talking_"
								{tags add "talking_"}
								{talk "grenade"}
								{crew_emit}
								{delay 0.5
									{tags remove "talking_"}
								}
							}
						}
					}
				}
				{if effector "vehicle"
					{if effector_velocity 2
						{call_synced "contact_fx_sync"}
					}
				}
			}
		}
	}

	{on "contact_fx_sync"
		{if not "fx_delay"
			{set "fx_delay" 1}
			{delay 2 "fx_delay"
				{set "fx_delay" 0}
			}
			{call "contact_fx"}
		}
	}

	{on "crush_damage_tank"
		{if effector_velocity 10
			{call_synced "crush_destroy_sync"}
;		else effector_velocity 5
;			{component break}
		}
	}
	{on "crush_destroy_sync"
		{crew_emit}
		{set "crush" 1}
		{call "explosion"}
		{call "stat_break"}
	}
	{on "crush_damage"
		{if effector_velocity 6
			{call_synced "crush_break_sync"}
		}
	}
	{on "crush_break_sync"
		{crew_emit}
		{set "crush" 1}
		{component break}
	}
	{on "contact_fx"
		{spawn "metal_crush" "root"}
	}

	{on "check_water_level" overload
		{if not linked
			{if water_level 1.3
				{able "sinking" 1}
				{tags add "no_scavenge"}		;// tag for conquest so that vehicle cannot be repaired/recovered
;//   			{mark_for_persistence}			;// Conquest map persistence
			else
				{able "sinking" 0}
			}
		}
	}

	{on "sandbag_cannon"
		{link_sound "deploy" "vehicle/deploy"}
		{play_sound "deploy"}
		{spawn "placement_sandbag_generic" "basis" x}
	}

	{on "tear_wheel" overload} ;// disables wheels from being torn on cannons

	{on "emit_crew"
		{crew_emit}
	}

	{on "self_destruct"
		{spawn "car_die" "basis"}
	}

	{on "at_grenade_blast"
		{if stuff "throwable at"
			{if not "already_blasted"
				{set "already_blasted" 1}
				{if component "body"
					{if work "body"
						{components "body" break}
					else
						{components "body" destroy}
					}
				else volume "shield"
					{component break}
					{if work "body"
						{components "body" break}
					else
						{components "body" destroy}
					}
				else
					{component break}
				}
				{delay 0.25
					{set "already_blasted" 0}
				}
			}
		}
	}

	{on break_armor
		{if name "blast"
			{call "at_grenade_blast"}
		}
	}

	{on break_armor_again
		{if name "blast"
			{call "at_grenade_blast"}
		}
	}

	{on destroy
		{if component "body"
			{if not "crush"
				{call "self_destruct"}
			}
		}
	}

	{on crew out				;// even happens when cannon changes from towed to fire state. Prevents unhitching underwater exploit.
		{if not tagged "water_check"
			{tags add "water_check"}
			{call "check_water_level"}
			{delay 2
				{tags remove "water_check"}
			}
		}
	}

	{on "disable_all_seats" overload} ;// stops code from vehicle main that disables seats on break
	{on "enable_all_seats" overload} ;// stops code from vehicle main that disables seats on repair. For cannons, causes mover and gunner seats to be crewable at the same time
}

;/*=========== Cannon End ===========*/

;/*=========== General Props Begin ===========*/

{"cannon no_shell"
	{on "spawn_shell" overload
		{tags add "gun_fired"}
		{call "no_spawn_shell_delay"}
		(define "no_shell_eject_delay"
			{delay_ex %0
				{ani_play "shell_eject" 1.0}
				{play_sound "breech_open"}
				{delay_ex %1
					{add_view "smoke_breach" "smoke_shell" "fx_invers"}
					{view start "smoke_shell"}
					{delay 2.5 0.5
						{view stop "smoke_shell"}
					}
				}
			}
		)
	}
	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 0.15 0.05)
	}
}


{"cannon wheeled"
	{on "check_work_mover" overload			;// overrides wheel settings in car interaction scripts
		{if tagged "wheel_teared"
			{chassis_work 0}
		else
			{if broken "wheel" 2			;// 2 broken wheels
				{movement_limit slow}
				{chassis_work 1}
			else broken "wheel" 1			;// 1 broken wheel
				{movement_limit normal}
				{chassis_work 1}
			else not broken "wheel"			;// 0 broken wheels
				{chassis_work 1}
				{movement_limit fast}
			}
		}
	}
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
}

{"cannon tracked"
	{on "check_work_mover" overload			;// overrides wheel settings in car interaction scripts
		{if work "mover"
			{if not tagged "wheel_destroyed"		;// Checks if wheel has been torn off
				{if not tagged "engine_turned_off"	;// Checks that player didn't turn off engine before repairs are made
					{chassis_work 1}
					{ik_enable "basis" 1}	;// allows motorized cannons to rotate when engine or track is broken
				}
			}
		else
			{chassis_work 0}
			{ik_enable "basis" 0}			;// stops motorized cannons from rotating when engine or track is broken
		}
	}
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
}

{"cannon wheeled invisible"			;// disables and enables wheel volumes for those cannons that hide their wheels when in "fire" state.
	{on spawn
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}
	{on animation_event "close"		;// event called on frame 0 of "close" animation
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}
	{on "show_wheels"				;// ables for all wheel volumes
		{volumes "invisible" enable visible bullet blast contact contact_ground select obstacle touch NoWoundDecal}
	}
	{on "hide_wheels"				;// removes ables for all wheel volumes
		{volumes "invisible" disable all}
		{volumes "invisible" enable contact_ground}
	}
	{on "cut_parts"					;// when cannon is destroyed and wheels/trailer are hidden
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}
}

{"cannon motorized"			;// disables and enables engine for those cannons that motorized and toggle when in "fire" state.
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on animation_event "close"		;// event called on frame 0 of "close" animation
		{if cannon_state "fire"
			{call "engine_off"}
			{tags remove "state_close"}
		else
			{tags add "state_close"}
			{if not "engine_on"
				{if not "toggle_delay"
					{call "engine_on"}
				}
			}
		}
	}

	{on "chassis_off" overload}			;// disables the chassis_work 0 so cannon can still be ordered to move when is fire state

	{on "repaired_engine_check" overload 	;// turns engine on when repaired if crewed and not tagged engine off
		{if not "engine_check" 				;// stops call from happening at spawn
			{if tagged "state_close"		;// check for motorized cannons
				{if operatable
					{if not tagged "engine_turned_off"
						{if not "engine_on"
							{call "engine_on"}
						}
					}
				}
			}
		}
	}
}

{"cannon ammo_crate"
	{##on animation_event "close"		;// event called on frame 0 of "close" animation
		{if cannon_state "fire"
			{crew_emit}
		}
	}
}


{"cannon bunker"
	{inflammation_time 30}
	{on spawn
		{link_sound "burn_small" "fire/loops/medium"}
	}

	{on blast_hit overload}
	{on "crush_damage" overload}
	{on "crush_damage_tank" overload}

	{on contact overload
		{if not impregnable
			{if not effector "bicycle"
				{if effector "vehicle"
					{if effector_velocity 2
						{if not "fx_delay"
							{set "fx_delay" 1}
							{delay 2 "fx_delay"
								{set "fx_delay" 0}
							}
							{spawn "metal_crush" "root"}
						}
					}
				}
			}
		}
	}
	{on break overload
		{if not tagged "exploded"
			{if component "body"
				{view stop "ammo"}
				{call "stat_break"}
				{call "kill_gunner"}
				{call "kill_commander"}
				{call "deactivate_vehicle"}
				{start_sound "crush/medium/metal"}
				{spawn "tank_die_particle" "body"}
				{crew_emit}
				{able select 0}			;// disables vehicle from being crewed until body is repaired
				{call "disable_all_seats"}
			}
			{if component "wheel"
				{if not linked
					{if not velocity 0.5
						{call "break_wheel_impulse"}
					}
				}
			}
		}
	}
	{on repair
		{if component "body"
			{able "select" 1}
		}
	}

	(define "kill_crew"			;// general code for killing crew on peirce and blast events
		{on "kill_%0"
			{if crew_in_place "%0"
					{kill_crew "%0"}
					{delay 0.2
						{damage_report "%0" "component/%0_die"}
						{talk "crew_die"}
					}
				}
			}
	)
	("kill_crew" args commander)
	("kill_crew" args gunner)

	{on "impulse" overload
		{if not cannon_state "fire"
			{physics_work 1}
			{impulse up 0.01}
		}
	}
	
	{on "show_wheels"				;// ables for all wheel volumes
		{physics_work 1}
	}
	{on "hide_wheels"
		{physics_work 0}
	}

	{on "_burn" overload
		{if not tagged "burned"
			{if not able "exploded"
				{talk "burning"}
				{call "check_burn_emit"}

				{if not tagged "burning"
					{burn volume fx "smoke_dead_tree1" time 20 fake even_law}
					{add_view "smoke_dead_norm" "burn_fire" "basis"}
					{add_view "smoke_engine" "burn_fire_smoke" "basis"}
					{view start "burn_fire"}
					{play_sound "burn_small" 1}
					{tags add "burning"}
					{fire radius 2 time 20 heating 2}
					{set "burn_fire" 1}
					{delay 6
						{components "body" break}
					}
				}
				{delay 20
					{view start "burn_fire_smoke"}
					{view stop "burn_fire"}
					{stop_sound "burn_small"}
					{tags remove "burning"}
					{set "burn_fire" 0}
					{able "burning" 0}
					{delay 30
						{view stop "burn_fire_smoke"}
					}
				}
			}
		}
	}

	{on "burn_volume"
		{if not burned
			{if volume "body"
				{call "_burn"}
			}
		else
			{tags add "already_burned"}
		}
	}

	{on "check_burn_emit"
		{call "burn_emit"}
	}
}

{"with_gun automatic"
	{on "spawn_shell" overload
		{call "spawn_shell_delay_auto"}
		(define "shell_eject_delay_auto"
			{delay_ex %0
				{spawn "shell_cannon_auto" "fx_invers" x scale 0.014
					{impulse forward 2.5 0.25 up 0.4 0.2 fx 0.7 0.2 cx -1 com}
				}
			}
		)
	}
	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0)
	}
	{on "reload" overload
		{call "magazine_delay"}
		{call "crew_reload_ani"}
	}
	(define "magazine"
		{on "magazine_delay" %override
			{ani_play "magazine" 1.0}
			{delay %cut
				{tear "piece_small_steel" bone "magazine" copy
					%impulse
				}
				{delay 0
					{view hide "magazine"}
					{delay %show
						{ani_play "magazine" -1.0}
						{view show "magazine"}
					}
				}
			}
		}
	)
	("magazine" cut(0) show(1.8) override() impulse({impulse up -0.01 com}))
}

{"cannon magazine"
	{on "reload"
		{call "magazine_delay"}
	}
	(define "magazine"
		{on "magazine_delay" %override
			{ani_play "magazine" 1.0}
			{delay %cut
				{tear "piece_small_steel" bone "magazine" copy
					%impulse
				}
				{delay 0
					{view hide "magazine"}
					{delay %show
						{ani_play "magazine" -1.0}
						{view show "magazine"}
						{delay 1
							{ani_play "bolt" 1.0}
						}
					}
				}
			}
		}
	)
	("magazine" cut(0) show(1.8) override() impulse({impulse up -0.01 com}))
}

{"cannon_small"					;// allows cannon to be crushed by armored cars, when normally they cannot.
	{on contact
		{if not impregnable
			{if effector "armored_car"
				{call "crush_damage"}
			else effector "truck"
				;// do nothing
			else effector "car"
				;// do nothing
			}
		}
	}
	{on "crush_damage" overload
		{if effector_velocity 10
			{call_synced "crush_destroy_sync"}
;		else effector_velocity 5
;			{component break}
		}
	}

	{on blast_hit
		{if min_energy 3.15
			{call "explosion"}
			{component destroy}
			{call "stat_break"}
		}
	}
}

{"carried"			;// applies footstep sounds instead of wheeled sounds to cannon movement
	{on "add_movement_sound" overload
		{link_sound "move" "human/move/run/ground"}
	}
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
}

{"cannon sled"		;// applies dragging sounds instead of wheeled sounds to cannon movement
	{on "add_movement_sound" overload
		{link_sound "move" ""}
	}
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
}

{"cannon fixed"
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
}

{"mg_stan"			;// assigned to properties/cannon_mgun.ext. Special code for machine gun class cannons.
	{on spawn
		{add_view "flash_gun_big" "flashbarrel" "foresight14"}
	}
	{on fire "mgun"
		;{view start "flashbarrel"}
		{ani_play "recoil"}
	}
	{on fire "mgun1"
		;{view start "flashbarrel"}
		{ani_play "recoil"}
	}
	{on "explosion_blastwave" overload}

	{on "self_destruct" overload
		{spawn "ex_air_small" "basis"}
	}

	{on "cut_parts" overload			;// Forces Mortars to cut all parts instead of using random chance.
		("cut_part" args "part1" 1)		;// Looks odd when legs cut but barrel floats in air.
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		("cut_part" args "part7" 1)
		("cut_part" args "part8" 1)
		("cut_part" args "part9" 1)
		("cut_part" args "part10" 1)
		{inherited}
		{call "delete_empty"}
	}
	{on "delete_empty"
		{hide 3}
		{delay 10 {delete}}
	}
	{on contact
		{if not impregnable
			{if  effector "truck"
				{call "crush_damage"}
			else effector "car"
				{call "crush_damage"}
			}
		}
	}
}

{"no_exp_blast"		;// disables blastwave damage and sound when vehicle is crushed or explodes.
	{on "explosion_blastwave" overload}
	{on "explosion_sound" overload}
	{on "self_destruct" overload
		{spawn "ex_air_small" "basis"}
	}
}

{"mortar"			;// code unique to mortar class cannons
	{on spawn
		{add_view "flash_cannon_small" "flashbarrel1" "foresight"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{view start "flashbarrel1"}
		{call "minimum_terrain_fx"}
		{play_sound "Recoil"}
		{play_sound "Cannon_Mid"}
		{play_sound "Cannon_Far"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		{call "crew_fire_ani"}
	}
}

{"mortar cannon"
	{on contact
		{if not impregnable
			{if effector "truck"
				{call "crush_damage"}
			else effector "car"
				{call "crush_damage"}
			}
		}
	}
	{on "cut_parts" overload			;// Forces Mortars to cut all parts instead of using random chance.
		("cut_part" args "part1" 1)		;// Looks odd when legs cut but barrel floats in air.
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}

	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_curved_heap" "sandbag")
	}

	{on "self_destruct" overload
		{spawn "ex_air_small" "basis"}
	}
}

{"flak"				;// base code for multi-barrel cannons and vehicles. To customize, add unique code to specific cannon name prop
	("handle_ik")
	{on "init_gun"
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel00"	"shooter00"}
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel01"	"shooter01"}
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel02"	"shooter02"}
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel03"	"shooter03"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "smoke_zenit"			"smoke02"		"shooter02"}
		{add_view "smoke_zenit"			"smoke03"		"shooter03"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{add_view "zenit_gilz"			"shell"			"FXshell2"}
		{add_view "zenit_gilz"			"shell"			"FXshell3"}
		{add_view "zenit_gilz"			"shell"			"FXshell4"}
		{call "update_gun"}
	}
	{on "add_movement_sound"
		{link_sound "rotate_turret" "vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_gun" "vehicle/turret/gun/gun_vertical"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{ani_play "fire%0"}
				{delay 0.12
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)
		{if	("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		}
		{if name "00"
			{call "fire_gun_common"}
		}
		{ani_play "recoil"}
		{call "spawn_shell"}
	}
	{on "fire_gun_common"
		{view start "flashbarrel"}
		;{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
		}
	}
}

{"nebelwerfer"			;// code for the nebelwerfer rocket vehicles
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"	"foresight"}
		{add_view	"dust_nebelfire"		"dust"			"turret"}
		{add_view	"dust_nebelfire_snow"	"snow"			"turret"}
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{play_sound "bkg_rocket"}
		{view start "flashbarrel1"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		(define "nebelwerfer_fire"
			{if terrain_fx "snow"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "ice"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "shallow_water"
				;nothing
			else
				{view start "dust"}
				{delay 0.3 {view pause "dust"}}
			}
		)
		{if name "00"
			("nebelwerfer_fire")
		else name "01"
			("nebelwerfer_fire")
		else name "02"
			("nebelwerfer_fire")
		else name "03"
			("nebelwerfer_fire")
		else name "04"
			("nebelwerfer_fire")
		else name "05"
			("nebelwerfer_fire")
		else name "06"
			("nebelwerfer_fire")
		else name "07"
			("nebelwerfer_fire")
		else name "08"
			("nebelwerfer_fire")
		else name "09"
			("nebelwerfer_fire")
		}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
}

{"recoilless"
	{on spawn
		{add_view   "recoilless_shot"			"flashbarrelsmall"	"fxshot"}
		{add_view	"recoilless_shot_forward"	"flashbarrel1"		"foresight1"}
		{add_view	"dust_recoilless"			"dust"				"turret"}
		{add_view	"dust_recoilless_snow"		"snow"				"turret"}
	}
	{on fire "gun"
		{view start "flashbarrelsmall"}
		{play_sound "action_recoil_Cannon"}
		{play_sound "Cannon_Mid"}
		{play_sound "Cannon_Far"}
		;{spawn "tank_canon_fire_50_57"	"fxshot" x}
		;{spawn "bazooka_shot"	"foresight1" x}
		{if terrain_fx "snow"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "ice"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "shallow_water"
			;nothing
		else
			{view start "dust"}
			{delay 0.3 {view pause "dust"}}
		}
	}
}

{"cannon searchlight"			;// code for searchlight cannons
	{on spawn
		{add_view "light_searchlight" "lights" "lamp_light_spot1"}
		{view hide "lights"}
	}

	{on "update_lights" overload
		{if operatable
			{if cannon_state "fire"
				{if work "gun"
					{call "lights_on"}
				else
					{call "lights_off"}
				}
			else
				{call "lights_off"}
			}
		else
			{call "lights_off"}
		}
	}

	{on animation_event "close"		;// event called on frame 0 of "close" animation
		{call "update_lights"}
	}

	{on break
		{if component "lamp"
			{call "break_lamp"}
		}
		{if component "gun"
			{call "update_lights"}
			{crew_emit}
			{crew_enable place "gunner" 0}
			{components "lamp" break}
			{call "break_lamp"}
		}
	}
	{on repair
		{if component "gun"
			{call "update_lights"}
			{crew_enable place "gunner" 1}
			{components "lamp" repair}
		}
		{if component "lamp"
			{restore_volume_states} ; restore volume ables from .def file
		}
	}

	{on ground_hit sync
		{call "explosion"}
	}
	{on "_explosion"
		{drop_orders}
	}
	{on operatable on
		{call "update_lights"}
	}
	{on operatable off
		{call "update_lights"}
	}
}

{"ammo_crate wood"
	{on break overload											;// {on break ... is for when components break.
		{crew_emit}
		{if component "body"
			{call "break"}
		}
	}

	{on contact
		{if not impregnable
			{if  effector "truck"
				{call "crush_damage"}
			else effector "car"
				{call "crush_damage"}
			}
		}
	}

	{on "crush_damage_tank" overload
		{if effector_velocity 5
			{call_synced "crush_break_sync"}
		}
	}

	{on "crush_damage" overload
		{if effector_velocity 1
			{call_synced "crush_break_sync"}
		}
	}

	{on "break"
		{call "stat_break"}
		{if not "crush"
			{call "explosion"}
		}
		{call "crush_fx"}
		{delay 0.05 {delete}}
	}

	{on "contact_fx" overload
		{spawn "wood_hit_piece" "root"}
	}

	{on "crush_fx"
		{spawn "wood_hit_br" "root"}							;// dust fx
		{call "destroyed_stamp"}
	}
	{on "destroyed_stamp" overload
		{spawn "crash_wood" no_position random_orientation}		;// stamp
	}
	{on "explosion_blastwave" overload
		{blastwave c4 10 r0 4 r1 10}
		{spawn "ammo_crate_die" "basis"}
	}
}

{"stretcher_vehicle"
	{on break overload											;// {on break ... is for when components break.
		{crew_emit}
		{if component "body"
			{call "break"}
		}
	}
	
	{on contact
		{if not impregnable
			{if  effector "truck"
				{call "crush_damage"}
			else effector "car"
				{call "crush_damage"}
			}
		}
	}

	{on "crush_damage_tank" overload
		{if effector_velocity 5
			{call_synced "crush_break_sync"}
		}
	}

	{on "crush_damage" overload
		{if effector_velocity 1
			{call_synced "crush_break_sync"}
		}
	}

	{on "break"
		{call "stat_break"}
		{if not "crush"
			{call "explosion"}
		}
		{call "crush_fx"}
		{delay 0.05 {delete}}
	}

	{on "contact_fx" overload
		{spawn "wood_hit_piece" "root"}
	}

	{on "crush_fx"
		{spawn "wood_hit_br" "root"}							;// dust fx
		{call "destroyed_stamp"}
	}
	{on "destroyed_stamp" overload
		{spawn "crash_wood" no_position random_orientation}		;// stamp
		{spawn "ground_blood_big" no_position random_orientation}		;// stamp
		{spawn "bloodstain" no_position random_orientation}		;// stamp
	}
}
;/*=========== General Props End ===========*/

;/*=========== Specific Cannons Begin ===========*/

;/*=========== Soviets Begin ===========*/

{"broneschitok"
	{on "check_water_level" overload
		{if not linked
			{if water_level 1.0
				{able "sinking" 1}
				{tags add "no_scavenge"}		;// tag for conquest so that vehicle cannot be repaired/recovered
;//   			{mark_for_persistence}			;// Conquest map persistence
			else
				{able "sinking" 0}
			}
		}
	}
}

{"mg_stan wheeled"
	{on "add_movement_sound" overload
		{link_sound "move" "vehicle/cannon_roll/metal_wood"}
	}
}

{"maxim_"
	{on "add_weapon_sound"
		{link_sound 		"action_recoil"			"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		("PM1910_30")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
	}
	{on "init_gun"
		{add_view "shell_mgun" "shell" "FXshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{play_sound "action_recoil"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view pause "flashbarrel"}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
}

{"maxim_stand"
	{on "break_wheel_impulse" overload}		;// Disables broken wheel impulse.

	{on "add_movement_sound" overload
		{link_sound "move" "vehicle/cannon_roll/metal_wood"}
	}
}

{"mg_x4"
	{on "init_gun" overload
		{add_view "shell_mgun" "shell1" "fxshell1"}
		{add_view "shell_mgun" "shell2" "fxshell2"}
		{add_view "shell_mgun" "shell3" "fxshell3"}
		{add_view "shell_mgun" "shell4" "fxshell4"}
		{add_view "ejectsmoke_big" "ejectsmoke1" "FXshell1"}
		{add_view "ejectsmoke_big" "ejectsmoke2" "FXshell2"}
		{add_view "ejectsmoke_big" "ejectsmoke3" "FXshell3"}
		{add_view "ejectsmoke_big" "ejectsmoke4" "FXshell4"}
		{add_view "flash_gun_big" "flashbarrel00" "shooter00"}
		{add_view "flash_gun_big" "flashbarrel01" "shooter01"}
		{add_view "flash_gun_big" "flashbarrel02" "shooter02"}
		{add_view "flash_gun_big" "flashbarrel03" "shooter03"}
	}
	{on fire "mgun1" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{delay 0.2 "fire"
					{view pause "flashbarrel%0"}
				}
				{play_sound "MG_Mid"}
				{play_sound "MG_Far"}
				{play_sound "action_recoil"}
				{kill_delay "shell_off%1"}
				{view start "shell%1"}
				{view start "ejectsmoke%1"}
				{delay 0.12 "shell_off%1"
					{view pause "shell%1"}
					{view pause "ejectsmoke%1"}
				}
		)
		{if	("fire_barrel" args 00 1)
		else ("fire_barrel" args 01 2)
		else ("fire_barrel" args 02 3)
		else ("fire_barrel" args 03 4)
		}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
}

{"maxim_x4"
	{on "init_gun" overload
		{add_view "shell_mgun" "shell1" "fxshell1"}
		{add_view "shell_mgun" "shell2" "fxshell2"}
		{add_view "shell_mgun" "shell3" "fxshell3"}
		{add_view "shell_mgun" "shell4" "fxshell4"}
		{add_view "ejectsmoke_big" "ejectsmoke1" "FXshell1"}
		{add_view "ejectsmoke_big" "ejectsmoke2" "FXshell2"}
		{add_view "ejectsmoke_big" "ejectsmoke3" "FXshell3"}
		{add_view "ejectsmoke_big" "ejectsmoke4" "FXshell4"}
		{add_view "flash_gun_big" "flashbarrel00" "shooter00"}
		{add_view "flash_gun_big" "flashbarrel01" "shooter01"}
		{add_view "flash_gun_big" "flashbarrel02" "shooter02"}
		{add_view "flash_gun_big" "flashbarrel03" "shooter03"}
	}
	{on fire "mgun1" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{delay 0.2 "fire"
					{view pause "flashbarrel%0"}
				}
				{play_sound "MG_Mid"}
				{play_sound "MG_Far"}
				{play_sound "action_recoil"}
				{kill_delay "shell_off%1"}
				{view start "shell%1"}
				{view start "ejectsmoke%1"}
				{delay 0.12 "shell_off%1"
					{view pause "shell%1"}
					{view pause "ejectsmoke%1"}
				}
		)
		{if	("fire_barrel" args 00 1)
		else ("fire_barrel" args 01 2)
		else ("fire_barrel" args 02 3)
		else ("fire_barrel" args 03 4)
		}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
}


{"ds39_stand"
	{on "add_weapon_sound" overload
		("DS39")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
	}
}
{"sg43_stand"
	{on "add_weapon_sound" overload
		("SG43")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
	}
}

{"dshk_aa"
	{on "init_gun" overload
		("DShK38")
		{add_view "shell_hmgun" "shell" "fxshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}

	{on fire "mgun1"
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{play_sound "action_recoil_HMG"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_straight_heap" "sandbag")
	}
}

{"dshk_stan"
	{on "init_gun" overload
		("DShK38")
		{add_view "shell_hmgun" "shell" "fxshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}

	{on fire "mgun1"
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{play_sound "action_recoil_HMG"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
}

{"25mm_72k"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.23) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_small")
}

{"37mm_61k"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.35) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}

	("cannon_small")
}

{"37mm_m30"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.05)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"45mm_m37"
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"45mm_m42"
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"45mm_21k_naval"
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.17 0.2)
	}
	{on "reload_delay" overload
		("reload_time" args 2.5)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_small")
}

{"57mm_zis2"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_small")
}

{"57mm_zis2_late"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_small")
}

{"76mm_bpk76"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.5)
	}

	("cannon_small")
}

{"76mm_m1902"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		{inherited}
	}

	("cannon_small")
}

{"76mm_m1927"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.5)
	}

	("cannon_small")
}

{"76mm_m43"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	("cannon_small")
}

{"76mm_m1933"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 8.5)
	}

	("cannon_small")
}

{"76mm_m1938"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

{"76mm_f22"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"76mm_zis3"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_small")
}

{"82mm_bm37"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

{"85mm_52k"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

{"100mm_bs3"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.9 0.15)
	}

	{on "reload_delay" overload
		("reload_time" args 6.1)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_big")
}

{"107mm_m1910_30"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}

{"120mm_pm38"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
}

{"122mm_m1910"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 20)
	}

	("cannon_big")
}

{"122mm_m30"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}
{"122mm_a19"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 18)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

{"152mm_ml20"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 23)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

{"d1"

}

{"152mm_br2"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 12)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_big")
}

{"203mm_b4"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 12)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_big")
}

{"280mm_br5"
	{on "add_weapon_sound" overload
		("Cannon_280mm+")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 12)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_big")
}

{"300mm_m30"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_curved_heap" "sandbag")
	}
}

{"300mm_m31"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_curved_heap" "sandbag")
	}
}

{"305mm_mb_2_12"
	{on "add_weapon_sound" overload
		("Cannon_280mm+")
		("Cannon_Breech")
	}
	{on spawn
		{add_view "tank_canon_fire_170_210"				"flashbarrel00"	"foresight1"}
		{add_view "tank_canon_fire_170_210"				"flashbarrel01"	"foresight2"}
		{add_view "tank_fire_maximum_dust_ground_rain"	"maximum_ground_r_fx"	"basis"}
		{add_view "tank_fire_maximum_dust_ground"		"maximum_ground_fx"		"basis"}
		{add_view "tank_fire_maximum_dust_sand_rain"	"maximum_sand_r_fx"		"basis"}
		{add_view "tank_fire_maximum_dust_sand"			"maximum_sand_fx"		"basis"}
		{add_view "tank_fire_maximum_dust_snow"			"maximum_snow_fx"		"basis"}
	}
	{on fire "gun1" overload
		{view start "flashbarrel00"}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "flashbarrel00"}
		{ani_play "fire00"}
		{start_sound "weapon/shot/tracer/"}
		{call "maximum_terrain_fx"}
	}
	{on fire "gun2" overload
		{view start "flashbarrel01"}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "flashbarrel01"}
		{ani_play "fire01"}
		{start_sound "weapon/shot/tracer/"}
		{call "maximum_terrain_fx"}
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		("cut_part" args "part7" 1)
		{spawn "vehicle_die" "basis"}
		{spawn "train_die" "basis"}
		{inherited}
	}
	
	{on break
		{if not tagged "exploded"
			{if component "gun1"
				{call "update_gun"}
				{tags add "gun1_brake"}
				{talk "broken_gun"}
			else component "gun2"
				{call "update_gun"}
				{tags add "gun2_brake"}
				{talk "broken_gun"}
			}
		}
	}
	{on repair
		{if component "gun1"
			{call "update_gun"}
			{tags remove "gun1_brake"}
		else component "gun2"
			{call "update_gun"}
			{tags remove "gun2_brake"}
		}
	}
	{on "update_gun"
		{if work "gun"
			{weapon_work "gun" 1}
		else
			{weapon_work "gun" 0}
		}
		{if work "gun1"
			{weapon_work "gun1" 1}
		else
			{weapon_work "gun1" 0}
		}
		{if work "gun2"
			{weapon_work "gun2" 1}
		else
			{weapon_work "gun2" 0}
		}
	}
}

{"ap2"
	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_big")
}

;/*=========== Soviets End ===========*/

;/*=========== Germans Begin ===========*/

{"mgun_ring"
	{on blast_hit overload}
	{on "gunner_hatch_open"
		{ani_play "mgun_aa" +1.0 resume}
	}
}

{"panzernest_krab"
	{on animation_event "close" overload		;// event called on frame 1 of "close" animation
		{if tagged "transition"
			{tags remove "transition"}
		else
			{tags add "transition"}
		}
		{call "body_check"}
	}

	{on animation_event "open"		;// event called on last frame of "close" animation
		{if tagged "transition"
			{tags remove "transition"}
		else
			{tags add "transition"}
		}
		{call "body_check"}
		
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}

	{on "body_check"				;// ables for all wheel volumes
		{if tagged "transition"
			{volumes "anim_no_contact" disable contact}
		else
			{volumes "anim_no_contact" enable contact}
		}
	}
	
	{on "cut_parts" overload
		("cut_part" args "wheelL" 1)
		("cut_part" args "wheelR" 1)
		{inherited}
	}
	{on "delete_empty" overload}
}

{"flak38"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
	}
	("cannon_small")
}

{"20mm_flak30"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("magazine" cut(0.4) show(1.8) override(overload) impulse({impulse up 0.3 forward 0.9 0.1}))

	("cannon_small")
}

{"20mm_flak38"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("magazine" cut(0.4) show(1.8) override(overload) impulse({impulse up 0.3 forward 0.9 0.1}))

	("cannon_small")
}

{"20mm_flakvierling38"
	{on "add_weapon_sound" overload
		("2cm_Flakvierling")
	}
	("multi_barrel_loop" flash(tank_canon_fire_20_25_auto) smoke(smoke_zenit) shell(zenit_gilz) weapon(gun) head(0.200))

	{on "reload"
		{ani_play "reload" 1.0}
	}
	{on "reload_delay" overload
		("reload_time" args 9)		;// weapon reload time
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 0.75)
		("cut_part" args "part2" 0.75)
		("cut_part" args "part3" 0.75)
		("cut_part" args "part4" 0.75)
		("cut_part" args "shield1" 0.6)
		("cut_part" args "shield2" 0.6)
		("cut_part" args "shield3" 0.6)
		("cut_part" args "shield4" 0.6)
		("cut_part" args "shield6" 0.6)
		("cut_part" args "turret" 0.6)
		{inherited}
	}

	("cannon_small")
}

{"multi_sight"
	{on spawn
		("rand_cut_else" args "aim_sight1" "aim_sight2")
		("rand_cut_else" args "seat_1" "seat_2")
	}
}

{"37mm_flak37"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		("cut_part" args "part7" 1)
		{inherited}
	}

	("cannon_small")
}

{"28mm_pzb41"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 2.5)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_small")
}

{"37mm_pak36"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.05)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"47mm_pakt"
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	("cannon_small")
}

{"50mm_flak41"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.32) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "standr" 1)
		("cut_part" args "standl" 1)
		("cut_part" args "trailer_front" 1)
		("cut_part" args "trailer_rear" 1)
		{inherited}
	}

	("cannon_big")
}

{"50mm_pak38"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 3.75)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part7" 1)
		{inherited}
	}

	("cannon_small")
}

{"50mm_kwk39_platform"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 3.75)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part7" 1)
		{inherited}
	}

	("cannon_small")
}

{"75mm_lg40"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.0 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	("cannon_small")
}

{"75mm_leig18"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.0)
	}

	("cannon_small")
}

{"75mm_legebig18"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_small")
}

{"75mm_legebig18_snow"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "wheelL" 1)
		{inherited}
	}

	("cannon_skis")
}


{"75mm_pak9738"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.0 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}

	("cannon_small")
}

{"75mm_pak40"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 5.25)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"80mm_sgrw34"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

{"88mm_flak18"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}
}

{"88mm_flak36"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")

	{on "cut_parts" overload
		("cut_part" args "part4" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}
}

{"88mm_pak4341"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.1 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 7.5)
	}

	("cannon_big")
}

{"100mm_nbw35"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
}

{"105mm_lefh18"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 0.8)
		("cut_part" args "part2" 0.8)
		("cut_part" args "part3" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}

	("cannon_big")
}

{"105mm_lefh18m"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}
	{on "cut_parts" overload
		("cut_part" args "wheelr" 0.8)
		("cut_part" args "wheell" 0.8)
		("cut_part" args "standl" 1)
		("cut_part" args "standr" 1)
		("cut_part" args "part1" 1)
		{inherited}
	}

	("cannon_big")
}

{"105mm_lefh18_40"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}
	{on "cut_parts" overload
		("cut_part" args "wheelr" 0.8)
		("cut_part" args "wheell" 0.8)
		("cut_part" args "standl" 1)
		("cut_part" args "standr" 1)
		("cut_part" args "part1" 1)
		{inherited}
	}

	("cannon_big")
}

{"105mm_sk18"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 23)
	}

	("cannon_big")
}

{"120mm_sgrw42"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
}

{"150mm_sig33"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.25)
	}

	{on "cut_parts" overload
		("cut_part" args "wheelr" 1)
		{inherited}
	}

	("cannon_big")
}

{"150mm_sfh18"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}

	("cannon_big")
}

{"150mm_nebelwerfer41"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	("cannon_small")

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "pa155mm_gpfrt6" 1)
		{inherited}
	}
}

{"155mm_gpf_platform"
	{on blast_hit overload}
}

{"170mm_k18"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 68)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_big")
}

{"200mm_ldgw40"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
}

{"210mm_k39"
	{on blast_hit overload}
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}

	("cannon_big")
}

{"210mm_morser18"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 68)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_big")
}

{"210mm_nebelwerfer42"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	("cannon_small")

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		{inherited}
	}
}

{"600mm_thor"
	{on "add_weapon_sound" overload
		("Cannon_280mm+")
	}
	{on spawn
		{volumes "shell2" disable bullet blast}
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload" overload
		{call "reload_delay"}
		{if tagged "gun_fired"
			{delay 12
				{tags remove "gun_fired"}
				{talk "reloaded"}
			}
		else ;//switching ammo
			{delay 4
				{ani_play "shell_eject" 1.0}
			}
			{delay 12
				{talk "reloaded"}
			}
		}
		{delay 1
			{talk "reload"}
		}
	}

	{on "reload_delay" overload}

	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/karl_gerat/MB507C/start"}
		{link_sound "engine_stop"		"vehicle/engine/karl_gerat/MB507C/stop"}
		{link_sound "engine_idle"		"vehicle/engine/karl_gerat/MB507C/idle"}
		{link_sound "engine_full"		"vehicle/engine/karl_gerat/MB507C/full"}
		{link_sound "exhaust"			"vehicle/engine/karl_gerat/MB507C/exhaust"}
		{link_sound "move"				"vehicle/tracks/karl_gerat/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}

	{on ik begin "basis"			;// gun bone rotates (vertical rotation)
		{if cannon_state "fire"
			{play_sound "rotate_gun" 1}
			{ani_play "aim_v" loop resume}
			{ani_play "aim_h" loop resume}
		}
	}

	{on ik end "basis"				;// gun stops rotation
		{stop_sound "rotate_gun"}
		{ani_stop "aim_v"}
		{ani_stop "aim_h"}
	}

	{on fire "gun"
		{volumes "shell1" disable bullet blast}		;// Disables shell volume after firing while reloading
		{delay 12									;// Ables shell volume after firing while reloading
			{volumes "shell2" enable bullet blast}
		}
		{delay 22									;// Delay set to match reload time of main weapon
			{volumes "shell1" enable bullet blast}	;// Aables shell volume after reloading
			{volumes "shell2" disable bullet blast}	;// Disables shell volume after reloading
		}
	}

	{on break_armor					;// volume breaks
		{if not tagged "exploded"
			{if volume "shell1"
				{call "stat_break"}
				{call "_explosion"}
			else volume "shell2"
				{call "stat_break"}
				{call "_explosion"}
			}
		}
	}

	{on "explosion_blastwave" overload
		{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
		{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
		{impulse up 0.1 0.1 dir 0.2 0.1}
		{spawn "tank_die_heavy" "basis"}
		{start_sound "detonation/explosion_vehicle/bkg/"}
		{if terrain_fx "snow"
			{spawn "tank_die_snow" "basis"}
		else terrain_fx "ice"
			{spawn "tank_die_snow" "basis"}
		else
			{spawn "tank_die_dust" "basis"}
		}
	}

	{on contact overload
		{if not impregnable
			{if not effector "bicycle"
				{if effector "vehicle"
					{if effector_velocity 2
						{if not "fx_delay"
							{set "fx_delay" 1}
							{delay 2 "fx_delay"
								{set "fx_delay" 0}
							}
							{spawn "metal_crush" "root"}
						}
					}
				}
			}
		}
	}
}

{"300mm_nebelwerfer42"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	("cannon_small")
}
{"200mm_leldgw"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	("cannon_small")
}

;/*=========== Germans End ===========*/

;/*=========== Finnish Begin ===========*/
{"mg08_fin"
	{on "add_weapon_sound"
		("MG08")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
	}
	{on "init_gun"
		{add_view "shell_mgun" "shell" "FXshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}
	{on fire "mgun"
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{play_sound "action_recoil"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view pause "flashbarrel"}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
}
{"maxim_m32_33"
	{on "add_weapon_sound"
		{link_sound 		"action_recoil"			"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		("PM1910_30")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
	}
	{on "init_gun"
		{add_view "shell_mgun" "shell" "FXshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}
	{on fire "mgun"
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{play_sound "action_recoil"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view pause "flashbarrel"}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
}
{"20mm_l39"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("magazine" cut(0.6) show(2.7) override(overload) impulse({impulse up 0.3 forward 1.9 0.2}))
}


{"20mm_itk35"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("magazine" cut(0.4) show(1.8) override(overload) impulse({impulse up 0.3 0.2 forward 1.9 0.2}))

	{on "cut_parts" overload
		("cut_part" args "wheell" 1)
		("cut_part" args "wheelr" 1)
		{inherited}
	}

	("cannon_small")
}

{"20mm_itk40"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}
	("cannon_small")
}

{"25mm_pstk37"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.17 0.2)
	}

	{on "reload_delay" overload
		("reload_time" args 2.5)
	}

	("cannon_small")
}

{"37mm_pstk36"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.20 0.35)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}


	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_small")
}

{"47mm_pstk39"
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_small")
}

{"40mm_itk38b"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.45) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_small")
}

{"45mm_pstk32"
	{on "add_weapon_sound" overload
		("Cannon_45to47mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"50mm_krh38"
	{on "add_weapon_sound" overload
		("Mortar_5-6cm")
	}
}

{"75mm_pstk9738"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.0 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}

	("cannon_small")
}

{"75mm_k44"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.55 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 4)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"75mm_itk37"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	("cannon_big")

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "wheell1" 1)
		("cut_part" args "wheelr1" 1)
		("cut_part" args "wheell2" 1)
		("cut_part" args "wheelr2" 1)
		{inherited}
	}
}

{"76mm_itk31"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part7" 1)
		("cut_part" args "part9" 1)
		("cut_part" args "wheelr" 1)
		("cut_part" args "wheell" 1)
		("cut_part" args "trailer" 1)
		{inherited}
	}

	("cannon_big")
}

{"76mm_lk13"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 3 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 6.0)
	}
	("cannon_small")
}

{"76mm_m1927_fin"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.5)
	}
	{on "reload_delay" overload
		("reload_time" args 6.0)
	}
	("cannon_small")
}

{"76mm_rk27_39"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.5)
	}
	{on "reload_delay" overload
		("reload_time" args 6.0)
	}
	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"76mm_k00"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 3 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10.0)
	}

	("cannon_big")
}

{"76mm_k02_30_40"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"81mm_krh36"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

{"84mm_k18"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.5)
	}	
	{on "reload_delay" overload
		("reload_time" args 5.5)
	}
	{on "cut_parts" overload
		("cut_part" args "wheelL" 1)
		("cut_part" args "wheelR" 1)
		{inherited}
	}
	("cannon_big")
}

{"105mm_k13"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}

	("cannon_big")
}

{"105mm_k34"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}

	("cannon_big")
}

{"107mm_k10"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}

	("cannon_big")
}

{"114mm_h18_how"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 20)
	}

	("cannon_big")
}

{"120mm_k78_31"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}

{"120mm_krh40"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
}

{"122mm_m1910_fin"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}

{"155mm_h17"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		{inherited}
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 30)
	}

	("cannon_big")
}

{"155mm_k17"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 60)
	}

	("cannon_big")
}

{"170mm_minewerfer"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	{on "self_destruct" overload
		{spawn "car_die" "basis"}
	}
}

{"203mm_h17"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 70)
	}

	("cannon_big")
}

{"210mm_h17"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 70)
	}

	("cannon_big")
}

{"300mm_krh42_animation"
	{on spawn
		{if cannon_state "move"
			{call "lower_gun"}
		else cannon_state "trailing"
			{ani_wind "shell_eject" end}
		else
			{call "raise_gun"}
		}
	}
}

{"300mm_krh42"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
	}

	{on animation_event "close"		;// event called on frame 0 of "close" animation
		{if cannon_state "fire"
			{if not tagged "gun_fired"
			{call "raise_gun"}
			}
		else
			{call "lower_gun"}
		}
	}

	{on "lower_gun"
		{if not tagged "gun_fired"
			{ani_play "shell_eject" 1.0}
		}
	}

	{on "cannon_reloaded" overload
		{if cannon_state "move"
			;// do nothing
		else cannon_state "trailing"
			;// do nothing
		else
			{call "raise_gun"}
		}
		{play_sound "breech_close"}
		{delay 0.5
			{talk "reloaded"}
		}
	}

	{on "raise_gun"
		{ani_play "shell_eject" -1.0}
	}

	{on "cut_parts" overload
		("cut_part" args "wheelL" 0.6)
		("cut_part" args "wheelR" 0.6)
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 3.75 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 55)
	}

	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_curved_heap" "sandbag")
	}

	("cannon_big")
}

;/*=========== Finnish End ===========*/

;/*=========== USA Begin ===========*/


{"m1917_30cal"
	{on "add_weapon_sound"
		("M1919A4")
	}
	{on "init_gun"
		{add_view "shell_mgun" "shell" "FXshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}
	{on fire "mgun"
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{play_sound "action_recoil"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view pause "flashbarrel"}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
}
{"m2_30cal_tripod"
	{on "add_weapon_sound"
		("M1919A4")
	}
}
{"m2_50cal_tripod"
	{on "add_weapon_sound"
		("M2HB")
	}
}

{"50cal_quad_m45"				;// base code for multi-barrel cannons and vehicles. To customize, add unique code to specific cannon name prop
	("handle_ik")
	{on "add_weapon_sound" overload
		("M45_QuadMount")
	}

	("multi_barrel_loop" flash(flash_gun_big) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "reload"
		{ani_play "reload_mgun" 1.0}
	}
	{on "reload_delay" overload
		("reload_time" args 30)		;// weapon reload time
	}

	("cannon_small")
}

{"37mm_m3"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.25 0.2)
	}

	{on "reload_delay" overload
		("reload_time" args 3)
	}

	("cannon_small")
}

{"40mm_m1"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.45) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_small")
}

{"50mm_rocket_projector"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "cut_parts" overload			;// Forces Mortars to cut all parts instead of using random chance.
		("cut_part" args "part1" 1)		;// Looks odd when legs cut but barrel floats in air.
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}
}

{"57mm_m1"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	("cannon_small")
}

{"60mm_m2"
	{on "add_weapon_sound" overload
		("Mortar_5-6cm")
	}
}

{"75mm_m1897"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.9 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.5)
	}

	("cannon_small")
}


{"75mm_m1a1"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_shallow" overload
		("cannon_sandbag" args "sandbag_cannon_shallow" "sandbag")
	}
	
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_small")
}

{"75mm_m3a3"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_shallow" overload
		("cannon_sandbag" args "sandbag_cannon_shallow" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_small")
}

{"76mm_m5_m1"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.40 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 5.25)
	}

	("cannon_small")
}

{"76mm_m5_m6"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.40 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 5.25)
	}

	("cannon_small")
}

{"81mm_m1"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

{"90mm_m1a1"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "standf" 1)
		;("cut_part" args "pivot_front" 1)
		{inherited}
	}
}

{"105mm_m2a1"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}

	("cannon_big")
}

{"105mm_m3"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}

	("cannon_small")
}

{"107mm_m2"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
}

{"114mm_m1"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 20)
	}

	("cannon_big")
}

{"155mm_gpf"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}

	("cannon_big")
}

{"155mm_m1"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}

	("cannon_big")
}

{"155mm_m1a1_longtom"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}

	{on "cut_parts" overload
		("cut_part" args "gun" 0.6)
		("cut_part" args "gun_rot" 0.6)
		("cut_part" args "turret_mesh" 0.6)
		{inherited}
	}

	("cannon_big")
}

{"155mm_schneider_us"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 30)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		{inherited}
	}

	("cannon_big")
}

{"203mm_m1"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 70)
	}

	{on "cut_parts" overload
		("cut_part" args "gun" 0.6)
		("cut_part" args "gun_rot" 0.6)
		("cut_part" args "turret_mesh" 0.6)
		{inherited}
	}

	("cannon_big")
}

;/*=========== USA End ===========*/

;/*=========== ENG Begin ===========*/

{"vickers_mg"
	{on "add_weapon_sound"
		("Vickers")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
	}
	{on "init_gun"
		{add_view "shell_mgun" "shell" "FXshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}
	{on fire "mgun"
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{play_sound "action_recoil"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view pause "flashbarrel"}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
}

{"20mm_oerlikon"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("magazine" cut(0.75) show(4.25) override(overload) impulse({impulse up 0.3 forward 0.9 0.1}))

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "wheell" 1)
		("cut_part" args "wheelr" 1)
		{inherited}
	}

	("cannon_small")
}

{"20mm_polsten"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("magazine" cut(0.75) show(4.25) override(overload) impulse({impulse up 0.3 forward 0.9 0.1}))

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "wheell" 1)
		("cut_part" args "wheelr" 1)
		{inherited}
	}

	("cannon_small")
}

{"37mm_qf_mk1"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.20 0.35)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_small")
}

{"40mm_qf2"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.05)
	}
	{on "reload_delay" overload
		("reload_time" args 3)
	}

	{on "cut_parts" overload
		("cut_part" args "wheelL" 1)
		("cut_part" args "wheelR" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_small")
}

{"40mm_qf40"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.45) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_small")
}

{"57mm_qf6"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	("cannon_small")
}

{"57mm_qf6_mk4"
	{on "add_weapon_sound" overload
		("Cannon_50to57mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	("cannon_small")
}

{"76mm_qf17"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.2 0.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6.5)
	}
	{on "cut_parts" overload
		("cut_part" args "shield" 0.6)
		{inherited}
	}
	("cannon_big")
}

{"76mm_qf17_25"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.2 0.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6.5)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "shield" 0.6)
		{inherited}
	}
	("cannon_big")
}

{"76mm_land_mattress_animation"
	{on spawn
		{if cannon_state "move"
			; do nothing
		else cannon_state "trailing"
			; do nothing
		else
			{ani_wind "close" begin}
		}
	}
	{on "add_weapon_sound" overload
		{link_sound "bkg_rocket" "weapon/shot/reactive/d2/ENG/Land_Mattress/"}
	}
	{on fire "gun" overload
		{play_sound "bkg_rocket"}
	}
}

{"76mm_land_mattress"
	{on "add_weapon_sound" overload
		{link_sound "bkg_rocket" "weapon/shot/reactive/d2/ENG/Land_Mattress/"}
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		{inherited}
	}
	{on fire "gun" overload
		{play_sound "bkg_rocket"}
	}
	("cannon_small")
}

{"81mm_ml3"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

{"84mm_qf18_2pa"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.5)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}
	("cannon_big")
}

{"84mm_qf18_25_5p"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.5)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}
	("cannon_big")
}

{"88mm_qf18_25_4p"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.5)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}
	{on "cut_parts" overload
		("cut_part" args "gun" 0.6)
		("cut_part" args "gun_rot" 0.6)
		{inherited}
	}
	("cannon_big")
}

{"88mm_qf25_mk2"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.5)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "shield" 0.6)
		{inherited}
	}
	("cannon_big")
}

{"94mm_qf_3_7_aa"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
}

{"94mm_qf_how"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 7)
	}
	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}
	("cannon_small")
}

{"107mm_m2"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
}

{"107mm_ml4_2"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
}
{"114mm_bl_4_5"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 2.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 20)
	}
	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}
	("cannon_big")
}

{"114mm_bl_4_5_mk1"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 2.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 20)
	}
	("cannon_big")
}
{"114mm_qf_how"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 20)
	}
	("cannon_big")
}

{"140mm_bl_5_5"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 2.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}
	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}
	("cannon_big")
}

{"152mm_bl_6"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 2.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 40)
	}
	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}
	{on "show_wheels" overload			;// ables for all wheel volumes
		{volumes "invisible" enable visible bullet blast contact_ground select obstacle touch NoWoundDecal}
	}
	("cannon_big")
}

{"152mm_bl_6_mk19"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 2.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}

	("cannon_big")
}

{"183mm_bl_7_2"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 2.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 70)
	}
	("cannon_big")
}

{"183mm_bl_7_2_mk6"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 2.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 70)
	}
	{on "cut_parts" overload
		("cut_part" args "gun" 0.6)
		("cut_part" args "gun_rot" 0.6)
		("cut_part" args "turret_mesh" 0.6)
		{inherited}
	}
	("cannon_big")
}

{"203mm_bl_8"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 70)
	}
	{on "cut_parts" overload
		("cut_part" args "part6" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part1" 1)
		{inherited}
	}
	("cannon_big")
}

;/*=========== Specific Cannons End ===========*/
;/*=========== Specific SCRIPT MACE ===========*/

(define "repair_anm_script_v1" ;// break/repair anm for components
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "engine"
				{ani_play "engine_b" +1 resume}
			}
			{if component "gun"
				{ani_play "gun_b" +1 resume}
			}
			{if component "turret"
				{ani_play "turret_b" +1 resume}
			}
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
		}
	}
	{on repair
		{if component "engine"
			{if work "engine"
				{ani_play "engine_r" +1 resume}
			}
		}
		{if component "gun"
			{if work "gun"
				{ani_play "gun_r" +1 resume}
			}
		}
		{if component "turret"
			{if work "turret"
				{ani_play "turret_r" +1 resume}
			}
		}
		{if component "body"
			{if work "turret"
				{ani_play "body_r" +1 resume}
			}
		}
	}
)

;/*=========== Specific Cannons MACE ===========*/

{"25mm_type_96"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}

	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.12) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	("cannon_small")

	{on animation_event "close"		;// event called on frame 0 of "close" animation
		{if cannon_state "fire"
			{call "show_magazine"}
		else
			{call "hide_magazine"}
		}
	}
	{on "show_magazine"				;// ables for all wheel volumes
		{volumes "magazine" enable visible bullet blast contact contact_ground select obstacle touch NoWoundDecal}
	}
	{on "hide_magazine"				;// removes ables for all wheel volumes
		{volumes "magazine" disable all}
		{volumes "magazine" enable contact_ground}
		{volumes "magazine" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
	}
}

{"25mm_type_96_mid"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}

	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.12) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	("cannon_small")

	{on animation_event "close"		;// event called on frame 0 of "close" animation
		{if cannon_state "fire"
			{call "show_magazine"}
		else
			{call "hide_magazine"}
		}
	}
	{on "show_magazine"				;// ables for all wheel volumes
		{volumes "magazine" enable visible bullet blast contact contact_ground select obstacle touch NoWoundDecal}
	}
	{on "hide_magazine"				;// removes ables for all wheel volumes
		{volumes "magazine" disable all}
		{volumes "magazine" enable contact_ground}
		{volumes "magazine" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
	}
}

{"25mm_type_96_early"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}

	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.12) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	("cannon_small")

	{on animation_event "close"		;// event called on frame 0 of "close" animation
		{if cannon_state "fire"
			{call "show_magazine"}
		else
			{call "hide_magazine"}
		}
	}
	{on "show_magazine"				;// ables for all wheel volumes
		{volumes "magazine" enable visible bullet blast contact contact_ground select obstacle touch NoWoundDecal}
	}
	{on "hide_magazine"				;// removes ables for all wheel volumes
		{volumes "magazine" disable all}
		{volumes "magazine" enable contact_ground}
		{volumes "magazine" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
	}
}

{"swe_12cm_bofors"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}

	{on "reload_delay" overload
		("reload_time" args 15)
	}
	
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	("cannon_big")
	
	{on break                ;// volume breaks
        {if not tagged "exploded"
            {if component "gun"
                {ani_play "gun_b" +1 resume}
            }
            {if component "body"
                {ani_play "body_b" +1 resume}
            }
			
			{if not tagged "ammo_broken"
				{if component "ammo1"
					{tags add "ammo_broken"}
					{call "stat_break"}
					{spawn "tank_die_light" "basis"}
					{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
					{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
					{components "body" destroy}
				}
				{if component "ammo2"
					{tags add "ammo_broken"}
					{spawn "tank_die_light" "basis"}
					{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
					{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
					{components "body" destroy}
				}
			}
        }
    }
    {on repair
        {if component "gun"
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
        }
        {if component "body"
            {if work "turret"
                {ani_play "body_r" +1 resume}
            }
        }
    }
}

{"type_92_10cm"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	("cannon_small")
	("repair_anm_script_v1")
}

{"150mm_type_96"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	("cannon_small")
	("repair_anm_script_v1")
}

{"100mm_type91"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	("cannon_small")
	("repair_anm_script_v1")
}


{"75mm_type_90"
	("cannon_big")
}

{"70mm_type11_mortar"
	{on "add_weapon_sound" overload
	 	("Mortar_5-6cm")
	 }
	 ("repair_anm_script_v1")
}

{"70mm_type92_late"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.0)
	}
	("repair_anm_script_v1")
}

{"70mm_type92_late"
	("cannon_small")
}

{"70mm_type92_early"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_LV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.0)
	}
	("repair_anm_script_v1")
}

{"70mm_type92_early"
	("cannon_small")
}


{"105mm_type_38_jap"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	("cannon_small")
	("repair_anm_script_v1")
	{on "reload"
		{delay 2.0
			{ani_play "reload_open" +1}
		}
		{delay 6.0
			{ani_play "reload_close" +1}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.1)
	}
}

{"105mm_type_38_fin"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	("cannon_small")
	("repair_anm_script_v1")
	{on "reload"
		{delay 2.0
			{ani_play "reload_open" +1}
		}
		{delay 6.0
			{ani_play "reload_close" +1}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.1)
	}
}

{"75mm_type_90"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	("cannon_small")
	("repair_anm_script_v1")
	{on "reload"
		{ani_play "breech_open" +1}
		{delay 6.0
			{ani_play "breech_close" +1}
		}
	}
}

{"15cm_type_89"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on fire "gun"
		{delay 1.5
			{ani_play "open_breech" +1 }	
		}
		{delay 23
			{ani_play "open_breech" -1 }
		}
	} 
	{on "reload_delay" overload
		("reload_time" args 23)
	}
	("repair_anm_script_v1")

	("cannon_big")

}


{"75mm_type_38"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	("repair_anm_script_v1")

	("cannon_small")

}

{"75mm_type_38_late"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	("repair_anm_script_v1")

	("cannon_small")

}

{"75mm_type_38_kai"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	("repair_anm_script_v1")

	("cannon_small")

}

{"75mm_type_38_mid"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	("repair_anm_script_v1")

	("cannon_small")

}

{"120mm_type_38_late"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	("cannon_small")
	("repair_anm_script_v1")
}

{"120mm_type_38_early"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	("cannon_small")
	 {on break                ;// volume breaks
            {if component "gun"
                {ani_play "gun_b" +1 resume}
            }
	    {if component "body"
                {ani_play "body_b" +1 resume}
            }
       }
       {on repair
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
	    {if work "body"
                {ani_play "body_r" -1 resume}
            }
	}
}

{"75mm_m_37_jap"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.0)
	}

	("cannon_big")
}

{"125mm_t25_mortar"
	{on "add_weapon_sound" overload
	 	("Mortar_12cm")
	 }
	 ("repair_anm_script_v1")
}

{"88mm-raketenwerfer43 tank"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on fire "gun"  
	{delay 5.2
		{ani_play "fire" +1.5 resume}
	}
	}
}

{"tri-polsten_20mm"
	{on "explosion_blastwave" overload
		{delay_ex 0
            	{set "no_burn_volumes" 1}
          	{set_skeleton "_xx"}
           	{ani_play "death"}
		{call "tear_turret"}
		}
	}
	{on "_explosion"
		{delay_ex 0
            	{set "no_burn_volumes" 1}
          	{set_skeleton "_xx"}
           	{ani_play "death"}
           	{call "tear_turret"}
       		}	
	}
	{on "add_weapon_sound" overload
		("2cm_Flakvierling")
	}
}

{"solothurn_s18_100"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	{on fire "gun" 
		{delay 0.1
			{spawn "shell_cannon" "fx_invers_custom" x scale 0.3
				{impulse forward 4 0.5 rnd_dir 0.1 0.1 cz 0.2 0.1 com}
				{add_view "smoke_empty_shell" "smoke_shell" "fx_shellsmoke"}
				{view start "smoke_shell"}
				{delay_effect 3 1 "stop"}
			}
		}
	}
	{on operatable off
		{ani_play "open" -1.0 }
	}
	{on operatable on
		{ani_play "open" 1.0 }
	}
	{on animation_event "close" overload		;// event called on frame 1 of "close" animation
		{if not tagged "transition"
			{tags add "transition"}
		else
			{tags remove "transition"}
			{ani_play "open" 1}
		}
		{call "body_check"}
	}
	{on "reload"
		{ani_play "reload" +0.5 resume}
		{view hide "ammo1"}
		{view hide "ammo2"}
		{delay 3.5
			{view show "ammo1"}
			{view show "ammo2"}
		}
	}
	("magazine" cut(0.6) show(2.7) override(overload) impulse({impulse up 0.3 forward 1.9 0.2}))
	("repair_anm_script_v1")
}

{"pak_44"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}
	{on "add_movement_sound" overload ;// split add movements into separate define and nest this one into it. separate so different turret/gun rotate sounds can be added.
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
	}
	{on spawn
		{link_sound "wheel_ground"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_grass"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_water"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_puddle"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_mud"			"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_snow"		"vehicle/cannon_roll/overlays/cannon_overlay_snow"}
		{link_sound "wheel_road"		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_rock"		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_wood"		"vehicle/cannon_roll/overlays/cannon_overlay_wood"}
		
	}
	{on animation_event "close" overload		;// event called on frame 1 of "close" animation
		{if not tagged "transition"
			{tags add "transition"}
			{ani_play "towing_cable" 1}
		else
			{tags remove "transition"}
			{ani_play "towing_cable" -1}
		}
		{call "body_check"}
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		("cut_part" args "part7" 1)
		("cut_part" args "part8" 1)
		("cut_part" args "part10" 1)
		("cut_part" args "part12" 1)
		("cut_part" args "part13" 1)
		{inherited}
	}
	{on break                ;// volume breaks
            {if component "gun"
                {ani_play "gun_b" +1 resume}
            }
	    {if component "body"
                {ani_play "turret_b" +1 resume}
            }
       }
       {on repair
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
	    {if work "body"
                {ani_play "turret_r" +1 resume}
            }
	}
}

{"morser_16"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on spawn
		{bone hide "shell"}
	}
	{on "reload"
		{delay 3
			{bone show "shell"}
			{ani_play "reload" 1}
		}
		{delay 10
			{bone hide "shell"}
		}
	}
	("repair_anm_script_v1")
}

{"morser_16"
	("cannon_big")
}

{"88mm-raketenwerfer43"
	("cannon_small")
}

{"300mm_krh42"
	("cannon_big")
}

{"t8_105mm_at_gun"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}
	("cannon_small")
	 {on break                ;// volume breaks
            {if component "gun"
                {ani_play "gun_b" +1 resume}
            }
	    {if component "body"
                {ani_play "turret_b" +1 resume}
            }
       }
       {on repair
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
	    {if work "body"
                {ani_play "turret_r" -1 resume}
            }
	}
}


{"tri-polsten_20mm"
	("cannon_small")
}

{"t8_105mm_at_gun"
	("cannon_big")
}

{"moser16"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}
	("cannon_big")
	{on break                ;// volume breaks
            {if component "gun"
                {ani_play "gun_b" +1 resume}
            }
	    {if component "body"
                {ani_play "turret_b" +1 resume}
            }
       }
       {on repair
            {if work "gun"
                {ani_play "gun_r" +1 resume}
            }
	    {if work "body"
                {ani_play "turret_r" +1 resume}
            }
	}
}

{"20_itk_30"
	("cannon_small")
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
}

{"20_itk_38"
	("cannon_small")
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
}

{"280mm_rakh43"
	("cannon_small")
}

{"37_itk_37"
	("cannon_big")
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
}

{"88_itk_37"
	("cannon_big")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
}

{"d-44"
	("cannon_big")
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
}

{"d1"
	("cannon_big")
	{on "add_weapon_sound" overload
		("Cannon_75to76mm")
		("Cannon_Breech")
	}
}

{"37mm_m1915_trench_gun"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.5)
	}
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		("cut_part" args "part7" 1)
		("cut_part" args "part8" 1)
		("cut_part" args "part9" 1)
		("cut_part" args "part10" 1)
		("cut_part" args "part11" 1)
		("cut_part" args "part12" 1)
		("cut_part" args "part13" 1)
		("cut_part" args "part14" 1)
		("cut_part" args "part15" 1)
		("cut_part" args "part16" 1)
		("cut_part" args "part17" 1)
		("cut_part" args "part18" 1)
		("cut_part" args "part19" 1)
		("cut_part" args "part20" 1)
		("cut_part" args "part21" 1)
		("cut_part" args "part22" 1)
		("cut_part" args "part23" 1)
		("cut_part" args "part24" 1)
		{inherited}
	}

	("cannon_small")
}

{"37mm_m1915_trench_gun_fin"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.5)
	}
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		("cut_part" args "part7" 1)
		("cut_part" args "part8" 1)
		("cut_part" args "part9" 1)
		("cut_part" args "part10" 1)
		("cut_part" args "part11" 1)
		("cut_part" args "part12" 1)
		("cut_part" args "part13" 1)
		("cut_part" args "part14" 1)
		("cut_part" args "part15" 1)
		("cut_part" args "part16" 1)
		("cut_part" args "part17" 1)
		("cut_part" args "part18" 1)
		("cut_part" args "part19" 1)
		("cut_part" args "part20" 1)
		("cut_part" args "part21" 1)
		("cut_part" args "part22" 1)
		("cut_part" args "part23" 1)
		("cut_part" args "part24" 1)
		{inherited}
	}

	("cannon_small")
}

{"300mm_krh42"
	{on spawn
		{add_view	"tank_fire_maximum_dust_ground"		"dust"			"basis"}
		{add_view	"tank_fire_maximum_dust_snow"		"snow"			"basis"}
		{link_sound "whistle" "weapon/shot/mortar/whistle"}
		;{link_sound "whistle_heavy" "weapon/shot/reactive/rocket_deep.wav"}
	}
	{on fire "gun" overload
		(define "300mm_krh42_fire"
			{if terrain_fx "snow"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "ice"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "shallow_water"
				;nothing
			else
				{view start "dust"}
				{delay 0.3 {view pause "dust"}}
			}
		)
		("300mm_krh42_fire")
		{delay 1.5
			{play_sound "whistle"}
			{start_sound "weapon/shot/reactive/rocket_deep.wav"}
		}
	}
	{on "explosion_blastwave"
		{spawn "vehicle_die" "basis"}
	}
	{on "reload"
		{ani_play "reload" +0.3 resume}
			{delay 45.5									;// Delay set to match reload time of main weapon
			{ani_play "reload" -0.3 resume}
		}
	}
	("repair_anm_script_v1")
}

{"280mm_rakh43"
	{on spawn
		{add_view	"tank_fire_maximum_dust_ground"		"dust"			"basis"}
		{add_view	"tank_fire_maximum_dust_snow"		"snow"			"basis"}
		{tags add "i_see_you"}
	}
	{on fire "gun"
		(define "280mm_krh43_fire"
			{if terrain_fx "snow"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "ice"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "shallow_water"
				;nothing
			else
				{view start "dust"}
				{delay 0.3 {view pause "dust"}}
			}
		)
		("280mm_krh43_fire")
	}
	{on break                ;// volume breaks
		{if not tagged "exploded"
            		{if component "gun"
               			 {ani_play "gun_b" +1 resume}
            		}
	    		{if component "body"
				{tags add "body_brake"}
                		{ani_play "body_b" +1 resume}
            		}
			{if component "rocket00"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
			{if component "rocket01"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
			{if component "rocket02"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
			{if component "rocket03"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
		}
	}
	{on "explosion_extra"
		{blastwave c4 12 r0 4 r1 20 offset 0 0 25}
		{blastwave c4 1.3 r0 15 r1 25 offset 0 0 25}
		{spawn "aero_die_fire" "basis"}
		{spawn "crater_big" "basis"}
	}
    {on repair
        {if work "gun"
            {ani_play "gun_r" +1 resume}
        }
		{if work "body"
		   {tags remove "body_brake"}
           {ani_play "body_r" +1 resume}
        }
	}
	{on "reload"
		{ani_play "reload" +0.3 resume}
		{if not tagged "body_brake"
			{delay 130						
				{ani_play "reload" -0.3 resume}
			}
		}
	}
}

{"25mm_apx_model38"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on animation_event "close"		;// event called on frame 0 of "close" animation
		;{if cannon_state "fire"
			{if not tagged "closed"
				{bone hide "rotator"}
				{bone hide "aim_h"}
				{tags add "closed"}		
		else
				{bone show "rotator"}
				{bone show "aim_h"}
				{tags remove "closed"}
			}
		;}	
	}
	("repair_anm_script_v1")
	("cannon_small")
}

{"stationary_type_93_hmg"
	("repair_anm_script_v1")
	{on "_explosion"
		{spawn "tank_die_peaceful_light"}
		{tear "piece_small_steel" bone "leg_left" 
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse up 2.5 rnd_dir 2}
		}
		{tear "piece_small_steel" bone "leg_rear" 
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse up 2.5 rnd_dir 2}
		}
		{tear "piece_small_steel" bone "turret" 
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse up 2.5 rnd_dir 2}
		}
	}
}

{"heavy_mg_stationary_type_93_hmg"
	("repair_anm_script_v1")
	{on "_explosion"
		{spawn "tank_die_peaceful_light"}
		{tear "piece_small_steel" bone "leg_left" 
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse up 2.5 rnd_dir 2}
		}
		{tear "piece_small_steel" bone "leg_rear" 
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse up 2.5 rnd_dir 2}
		}
		{tear "piece_small_steel" bone "turret" 
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse up 2.5 rnd_dir 2}
		}
	}
}

{"type_3_rocket_booster"
	{on "add_weapon_sound" overload
        {link_sound        "scraping_metal"    "weapon/shot/reactive/rocket_booster/"}
    }
    {on fire "gun"
         {play_sound "scraping_metal"}
    }
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "body"
				{ani_play "body_b" +1 resume}
				{bone hide "cables"}
				{delay 0.25
					{tear "piece_large_steel_booster" bone "rocket" copy
						{impulse forward 10 }
					}
				}
				{delay 0.26
					{bone hide "bomb"}
					{bone hide "rocket"}
					{volumes "booster1" disable bullet blast contact}
					{volumes "bomb1" disable bullet blast contact}
					{volumes "booster" disable bullet blast contact}
					{volumes "bomb" disable bullet blast contact}
				}
			}
		}
	}
	{on pierce sync
		{if component "bomb1"
			{spawn "explosion_booster" "basis"}
		}
		{if component "booster1"
			{spawn "explosion_booster" "basis"}
		}
		{if component "bomb"
			{spawn "explosion_booster" "basis"}
		}
		{if component "booster"
			{spawn "explosion_booster" "basis"}
		}
	}
	{on repair
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1 resume}
				{delay 0.3
					{bone show "bomb"}
					{bone show "rocket"}
					{bone show "cables"}
					{volumes "booster" enable bullet blast contact}
					{volumes "bomb" enable bullet blast contact}
					{volumes "booster1" enable bullet blast contact}
					{volumes "bomb1" enable bullet blast contact}
				}
			}
        }
	}
}

{"type_10_rocket_booster"
	{on "add_weapon_sound" overload
        {link_sound        "scraping_metal"    "weapon/shot/reactive/rocket_booster/"}
    }
    {on fire "gun"
         {play_sound "scraping_metal"}
    }
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "body"
				{ani_play "body_b" +1 resume}
				{bone hide "cables"}
				{delay 0.25
					{tear "piece_large_steel_booster" bone "rocket" copy
						{impulse forward 10 }
					}
				}
				{delay 0.26
					{bone hide "bomb"}
					{bone hide "rocket"}
					{volumes "booster1" disable bullet blast contact}
					{volumes "bomb1" disable bullet blast contact}
					{volumes "booster" disable bullet blast contact}
					{volumes "bomb" disable bullet blast contact}
				}
			}
		}
	}
	{on pierce sync
		{if component "bomb1"
			{spawn "explosion_booster" "basis"}
		}
		{if component "booster1"
			{spawn "explosion_booster" "basis"}
		}
		{if component "bomb"
			{spawn "explosion_booster" "basis"}
		}
		{if component "booster"
			{spawn "explosion_booster" "basis"}
		}
	}
	{on repair
		{if component "body"
			{if work "body"
				{ani_play "body_r" +1 resume}
				{delay 0.3
					{bone show "bomb"}
					{bone show "rocket2"}
					{bone show "cables"}
					{volumes "booster2" enable bullet blast contact}
					{volumes "bomb" enable bullet blast contact}
					{volumes "booster1" enable bullet blast contact}
					{volumes "bomb1" enable bullet blast contact}
				}
			}
        }
	}
}

{"stationary_type_92_hmg_short"
	{on "add_weapon_sound"
		{link_sound 		"action_recoil"			"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		("PM1910_30")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
	}
	{on "init_gun"
		{add_view "shell_mgun" "shell" "FXshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{play_sound "action_recoil"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view pause "flashbarrel"}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
	{on "reload"						
		{ani_play "reload" 1.5 resume}
	}
	("repair_anm_script_v1")
}

{"stationary_type_92_hmg_tall"
	{on "add_weapon_sound"
		{link_sound 		"action_recoil"			"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		("PM1910_30")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
	}
	{on "init_gun"
		{add_view "shell_mgun" "shell" "FXshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{play_sound "action_recoil"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view pause "flashbarrel"}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
	{on "reload"						
		{ani_play "reload" 1.5 resume}
	}
	("repair_anm_script_v1")
}

{"heavy_mg_stationary_type_92_hmg_tall"
	{on "add_weapon_sound"
		{link_sound 		"action_recoil"			"weapon/action/recoil/open_bolt_mg/reciprocating/"}
		("PM1910_30")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
	}
	{on "init_gun"
		{add_view "shell_mgun" "shell" "FXshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{play_sound "action_recoil"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view pause "flashbarrel"}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
	{on "construction_sandbag_cannon_shallow" overload
		("cannon_sandbag" args "sandbag_cannon_shallow" "sandbag")
	}
	{on "reload"						
		{ani_play "reload" 1.5 resume}
	}
	("repair_anm_script_v1")
}

{"47mm_type1_at"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.05)
	}
	{on "reload"						
		{ani_play "reload" 1.5 resume}
	}
	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}
	("repair_anm_script_v1")

	("cannon_small")
}

{"47mm_type1_at_noshield"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.05)
	}
	{on "reload"						
		{ani_play "reload" 1.5 resume}
	}
	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}
	("repair_anm_script_v1")

	("cannon_small")
}
{"type_97_at_rifle"
	{on spawn
		{tags add "normal_ammo"}
		{weapon_work "gun1" 0}
		{view hide "heat_shell"}
		{add_view "tank_fire_minimum_dust_ground"	"minimum_ground_fx"		"basis"}
	}
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	{on "reload"
		{ani_play "reload" +1.1 resume}
		{view hide "bullet"}
		{delay 3.5
			{view show "bullet"}
		}
	}
	("magazine" cut(0.6) show(2.7) override(overload) impulse({impulse up 0.3 forward 1.9 0.2}))
	("repair_anm_script_v1")
	{on fire "gun1"
		{view hide "heat_shell"}
		;{call "minimum_terrain_fx"}
		{delay 5
			{view show "heat_shell"}
		}
	}
	{on "ammo_switch_normal"					;// UI button to switch ammo to ap/he
		{if operatable
			{if work "body"
				{tags add "normal_ammo"}
				{tags remove "heat_ammo"}
				{delay 0.5
					{if tagged "normal_ammo"
						{damage_report "barrel_reload" "<c(f3ff00)>The weapon is using AP/HE"}
						{weapon_work "gun1" 0}
						{weapon_work "gun" 1}
						{view hide "heat_shell"}
					}
				}
			}
		}
	}
	{on "ammo_switch_heat"					;// UI button to switch ammo to heat
		{if operatable
			{if work "body"
				{tags add "heat_ammo"}
				{tags remove "normal_ammo"}
				{delay 0.5
					{if tagged "heat_ammo"
						{damage_report "ammo_switch_heat" "<c(f3ff00)>The weapon is using HEAT"}
						{weapon_work "gun" 0}
						{weapon_work "gun1" 1}
						{view show "heat_shell"}
					}
				}
			}
		}
	}
}

{"75mm_type_88_aa"
	{on "add_weapon_sound" overload
		("Cannon_75to76mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		{inherited}
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}
	("repair_anm_script_v1")
	{on "show_wheels"				;// ables for all wheel volumes
		{volumes "invisible" enable visible bullet blast contact contact_ground select obstacle touch NoWoundDecal}
	}
	{on "hide_wheels"				;// removes ables for all wheel volumes
		{volumes "invisible" disable all}
		{volumes "invisible" enable contact_ground}
	}
}

{"20cm_type_4_mortar"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	{on fire "gun"
		{tags add "breech_open"}
		{bone hide "rocket"}
	}
	{on "reload"
		{if tagged "breech_open"
			{ani_play "reload_open" +1 resume}
		}
		{delay 14
			{if tagged "breech_open"
				{ani_play "reload_close" +1 resume}
			}
			{tags remove "breech_open"}
			{bone show "rocket"}
		}
	}
	{on animation_event "close"		;// event called on last frame of "close" animation
		{if tagged "breech_open"
			{ani_play "reload_close" +1 resume}
			{tags remove "breech_open"}
		}
	}
	("repair_anm_script_v1")
}


{"105mm_type_14_aa"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.8 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		{inherited}
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}
	("repair_anm_script_v1")
	{on animation_event "close" 		;// event called on frame 1 of "close" animation
		{if not tagged "transition"
			{tags add "transition"}
			{volumes "invisible" enable visible bullet blast contact contact_ground select obstacle touch NoWoundDecal}

			{volumes "invisible2" disable all}
			{volumes "invisible2" enable contact_ground}
		else
			{tags remove "transition"}
			{volumes "invisible" disable all}
			{volumes "invisible" enable contact_ground}

			{volumes "invisible2" enable visible bullet blast contact contact_ground select obstacle touch NoWoundDecal}
		}
		{call "body_check"}
	}
}

{"105mm_type_4_recoilless"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm_LV")
		("Cannon_Breech")
	}
	("repair_anm_script_v1")
	("cannon_small")
}

{"20mm_type_98_aa"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
	}
	("repair_anm_script_v1")
	{on "reload"
		{tear "piece_small_steel" bone "magazine2" copy
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse dir 2 fz -5 fx 5.5 }
		}
		{delay 0.1
			{bone hide "magazine2"}
		}
		{delay 2.5
			{bone show "magazine2"}
			{volumes enable bullet blast}				;// prevent destroing at spawn moment
		}
	}
	("cannon_small")
}

{"100mm_type99"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.8 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")

	("repair_anm_script_v1")
	{on "reload"
		{ani_play "breech_open" +1 }
		{delay 5
			{ani_play "breech_close" +1 }
		}
	}
}

{"45cm_japan_rocket"
	{on spawn
		{add_view	"dust_nebelfire"		"dust"			"basis"}
		{add_view	"dust_nebelfire_snow"	"snow"			"basis"}
		{tags add "i_see_you"}
	}
	{on fire "gun"
		{if terrain_fx "snow"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "ice"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "shallow_water"
			;nothing
		else
			{view start "dust"}
			{delay 0.3 {view pause "dust"}}
		}
		{delay 0.1
			{volumes "rocket" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
			{call "emit_crew"}
			{tear "piece_small_steel" bone "wheell1" 
				{volumes disable bullet blast}				;// prevent destroing at spawn moment
				{impulse dir 2 fz -5 fx 5.5 }
			}
			{tear "piece_small_steel" bone "Brakes_left" 
				{volumes disable bullet blast}				;// prevent destroing at spawn moment
				{impulse dir 2 fz -5 fx 5.5 }
			}
			{tear "piece_small_steel" bone "bipod" 
				{volumes disable bullet blast}				;// prevent destroing at spawn moment
				{impulse dir 5 fz -5 fx 5.5 }
			}
			{delay_ex 0
				{tags add "ammo_broken"}
				{able minimap 0}
				{able select 0}
				{able repaired 0}
				{set "no_burn_volumes" 1}
				{set_skeleton "_xx" sync}
				{call "impulse"}
				{ani_play "death"}
				{call "cut_parts"}
			}
		}
	}
	{on "reload"
		{if name "rocket"
			{delay 105									;// Delay set to match reload time of main weapon
				{volumes "rocket" enable bullet blast}
			}
		}
	}
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "body"
				{ani_play "body_b" +1 resume}
			}
		}	
	}
	{on repair
        {if work "body"
        	{ani_play "body_r" +1 resume}
        }
	}
	{on pierce sync overload
		{if component "rocket"
			{tags add "ammo_broken"}
			{call "explosion_extra"}
		}
	}
	{on "explosion_extra"
		{blastwave c4 12 r0 4 r1 20 offset 0 0 25}
		{blastwave c4 1.3 r0 15 r1 25 offset 0 0 25}
		{spawn "train_die" "basis"}
	}
}

{"120mm_type2_mortar"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	("repair_anm_script_v1")
}

{"120mm_type2_mortar"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	("repair_anm_script_v1")
}

{"150mm_type97_mortar_short"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	("repair_anm_script_v1")
}

{"150mm_type97_mortar_long"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	("repair_anm_script_v1")
}

{"90mm_type97_mortar"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

{"81mm_type97_mortar"
	{on "add_weapon_sound" overload
		("Mortar_8cm")
	}
}

{"155mm_t25_mortar"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	("repair_anm_script_v1")
}

{"160mm_mt_13_mortar"
	{on "add_weapon_sound" overload
		("Mortar_12cm")
	}
	{on fire "gun"
		{delay 1
			{ani_play "reload_open"}
			{bone hide "shell00"}
		}
		{delay 10
			{bone show "shell00"}
		}
	}
	("repair_anm_script_v1")
}

{"37mm_type_11"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.05)
	}
	("repair_anm_script_v1")
	("cannon_small")
}

{"m2_50cal_tripod_ai"
	{on "add_weapon_sound"
		("M2HB")
	}
}

{"heavy_mg_mg131_tripod"
	{on "construction_sandbag_cannon_shallow_ai" overload}			;// used by AI defense mg's in conquest. removes persistence from their sandbags
	{on "construction_sandbag_cannon_standard_ai" overload}			;// used by AI defense mg's in conquest. removes persistence from their sandbags
	{on "construction_sandbag_cannon_shallow" overload}
	{on "construction_sandbag_cannon_standard" overload}
}	

{"heavy_mg_m2_50cal_tripod"
	{on "add_weapon_sound"
		("M2HB")
	}
	{on "construction_sandbag_cannon_shallow_ai" overload}			;// used by AI defense mg's in conquest. removes persistence from their sandbags
	{on "construction_sandbag_cannon_standard_ai" overload}			;// used by AI defense mg's in conquest. removes persistence from their sandbags
	{on "construction_sandbag_cannon_shallow" overload}
	{on "construction_sandbag_cannon_standard" overload}
}

{"heavy_mg_dshk_aa"
	{on "init_gun" overload
		("DShK38")
		{add_view "shell_hmgun" "shell" "fxshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}

	{on fire "mgun1"
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{play_sound "action_recoil_HMG"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_straight_heap" "sandbag")
	}
}

{"dshk_aa_ai"
	{on "init_gun" overload
		("DShK38")
		{add_view "shell_hmgun" "shell" "fxshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}

	{on fire "mgun1"
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{play_sound "action_recoil_HMG"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_straight_heap" "sandbag")
	}
}
{"88mm_pak434_late"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.1 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 7.5)
	}

	("cannon_big")
}

{"85mm_52k_late"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

{"88mm_flak36_late"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")

	{on "cut_parts" overload
		("cut_part" args "part4" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}
}

{"88mm_pak4341_late"
	{on "add_weapon_sound" overload
		("Cannon_85to100mm_HV")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.1 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 7.5)
	}

	("cannon_big")
}

{"183mm_t88_launcher"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	("cannon_small")
	("repair_anm_script_v1")
}

{"114mm_t66_launcher"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	("cannon_small")
	("repair_anm_script_v1")
}

{"183mm_t91_launcher"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	("repair_anm_script_v1")
}

{"114mm_m12a1_launcher"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	("repair_anm_script_v1")
}

{"114mm_t27_launcher"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	("repair_anm_script_v1")
}

{"273mm_t59_trailer"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz6b"}
	}
	{on "_explosion" 
		{blastwave c4 12 r0 4 r1 20 offset 0 0 25}
		{blastwave c4 1.3 r0 15 r1 25 offset 0 0 25}
		{spawn "tank_die_heavy" "basis"}
		
	}
	("repair_anm_script_v1")
}

;//GENERIC USA ROCKET DEFINES

{"273mm_t59"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"	"foresight"}
		{add_view	"dust_nebelfire"		"dust"			"basis"}
		{add_view	"dust_nebelfire_snow"	"snow"			"basis"}
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{play_sound "bkg_rocket"}
		{view start "flashbarrel1"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		(define "nebelwerfer_fire"
			{if terrain_fx "snow"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "ice"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "shallow_water"
				;nothing
			else
				{view start "dust"}
				{delay 0.3 {view pause "dust"}}
			}
		)
		{if name "00"
			("nebelwerfer_fire")
		else name "01"
			("nebelwerfer_fire")
		else name "02"
			("nebelwerfer_fire")
		else name "03"
			("nebelwerfer_fire")
		else name "04"
			("nebelwerfer_fire")
		else name "05"
			("nebelwerfer_fire")
		else name "06"
			("nebelwerfer_fire")
		else name "07"
			("nebelwerfer_fire")
		else name "08"
			("nebelwerfer_fire")
		else name "09"
			("nebelwerfer_fire")
		else name "10"
			("nebelwerfer_fire")
		else name "11"
			("nebelwerfer_fire")
		else name "12"
			("nebelwerfer_fire")
		else name "13"
			("nebelwerfer_fire")
		else name "14"
			("nebelwerfer_fire")
		else name "15"
			("nebelwerfer_fire")
		else name "16"
			("nebelwerfer_fire")
		else name "17"
			("nebelwerfer_fire")
		else name "18"
			("nebelwerfer_fire")						
		}
	}
}

{"114mm_t27"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"	"foresight"}
		{add_view	"dust_nebelfire"		"dust"			"basis"}
		{add_view	"dust_nebelfire_snow"	"snow"			"basis"}
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{play_sound "bkg_rocket"}
		{view start "flashbarrel1"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		(define "nebelwerfer_fire"
			{if terrain_fx "snow"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "ice"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "shallow_water"
				;nothing
			else
				{view start "dust"}
				{delay 0.3 {view pause "dust"}}
			}
		)
		{if name "00"
			("nebelwerfer_fire")
		else name "01"
			("nebelwerfer_fire")
		else name "02"
			("nebelwerfer_fire")
		else name "03"
			("nebelwerfer_fire")
		else name "04"
			("nebelwerfer_fire")
		else name "05"
			("nebelwerfer_fire")
		else name "06"
			("nebelwerfer_fire")
		else name "07"
			("nebelwerfer_fire")
		else name "08"
			("nebelwerfer_fire")
		}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
}

{"114mm_m12a1"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"	"foresight"}
		{add_view	"dust_nebelfire"		"dust"			"basis"}
		{add_view	"dust_nebelfire_snow"	"snow"			"basis"}
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{play_sound "bkg_rocket"}
		{view start "flashbarrel1"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		{if terrain_fx "snow"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "ice"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "shallow_water"
			;nothing
		else
			{view start "dust"}
			{delay 0.3 {view pause "dust"}}
		}
	}
}

{"183mm_t91"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"	"foresight"}
		{add_view	"dust_nebelfire"		"dust"			"basis"}
		{add_view	"dust_nebelfire_snow"	"snow"			"basis"}
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{play_sound "bkg_rocket"}
		{view start "flashbarrel1"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		{if terrain_fx "snow"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "ice"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "shallow_water"
			;nothing
		else
			{view start "dust"}
			{delay 0.3 {view pause "dust"}}
		}
	}
}

{"114mm_t66"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"	"foresight"}
		{add_view	"dust_nebelfire"		"dust"			"turret"}
		{add_view	"dust_nebelfire_snow"	"snow"			"turret"}
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{play_sound "bkg_rocket"}
		{view start "flashbarrel1"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		(define "nebelwerfer_fire"
			{if terrain_fx "snow"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "ice"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "shallow_water"
				;nothing
			else
				{view start "dust"}
				{delay 0.3 {view pause "dust"}}
			}
		)
		{if name "00"
			("nebelwerfer_fire")
		else name "01"
			("nebelwerfer_fire")
		else name "02"
			("nebelwerfer_fire")
		else name "03"
			("nebelwerfer_fire")
		else name "04"
			("nebelwerfer_fire")
		else name "05"
			("nebelwerfer_fire")
		else name "06"
			("nebelwerfer_fire")
		else name "07"
			("nebelwerfer_fire")
		else name "08"
			("nebelwerfer_fire")
		else name "09"
			("nebelwerfer_fire")
		else name "10"
			("nebelwerfer_fire")
		else name "11"
			("nebelwerfer_fire")
		else name "12"
			("nebelwerfer_fire")
		else name "13"
			("nebelwerfer_fire")
		else name "14"
			("nebelwerfer_fire")
		else name "15"
			("nebelwerfer_fire")
		else name "16"
			("nebelwerfer_fire")
		else name "17"
			("nebelwerfer_fire")
		else name "18"
			("nebelwerfer_fire")
		else name "19"
			("nebelwerfer_fire")
		else name "20"
			("nebelwerfer_fire")
		else name "21"
			("nebelwerfer_fire")						
		else name "22"
			("nebelwerfer_fire")
		else name "23"
			("nebelwerfer_fire")
		else name "24"
			("nebelwerfer_fire")
		}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
}

{"183mm_t88"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"	"foresight"}
		{add_view	"dust_nebelfire"		"dust"			"turret"}
		{add_view	"dust_nebelfire_snow"	"snow"			"turret"}
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{play_sound "bkg_rocket"}
		{view start "flashbarrel1"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		(define "nebelwerfer_fire"
			{if terrain_fx "snow"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "ice"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "shallow_water"
				;nothing
			else
				{view start "dust"}
				{delay 0.3 {view pause "dust"}}
			}
		)
		{if name "00"
			("nebelwerfer_fire")
		else name "01"
			("nebelwerfer_fire")
		else name "02"
			("nebelwerfer_fire")
		else name "03"
			("nebelwerfer_fire")
		else name "04"
			("nebelwerfer_fire")
		else name "05"
			("nebelwerfer_fire")
		else name "06"
			("nebelwerfer_fire")
		else name "07"
			("nebelwerfer_fire")
		else name "08"
			("nebelwerfer_fire")
		else name "09"
			("nebelwerfer_fire")
		else name "10"
			("nebelwerfer_fire")
		else name "11"
			("nebelwerfer_fire")
		else name "12"
			("nebelwerfer_fire")
		else name "13"
			("nebelwerfer_fire")
		else name "14"
			("nebelwerfer_fire")
		else name "15"
			("nebelwerfer_fire")
		}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
}

;//GENERIC JAPAN ROCKET DEFINES

{"type_10"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"	"foresight"}
		{add_view	"dust_nebelfire"		"dust"			"basis"}
		{add_view	"dust_nebelfire_snow"	"snow"			"basis"}
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" 
		{ani_play "recoil"}
		{play_sound "bkg_rocket"}
		{view start "flashbarrel1"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		{if terrain_fx "snow"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "ice"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "shallow_water"
			;nothing
		else
			{view start "dust"}
			{delay 0.3 {view pause "dust"}}
		}
	}
}

{"20cm_type_4"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"	"foresight"}
		{add_view	"dust_nebelfire"		"dust"			"basis"}
		{add_view	"dust_nebelfire_snow"	"snow"			"basis"}
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" 
		{ani_play "recoil"}
		{play_sound "bkg_rocket"}
		{view start "flashbarrel1"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		{if terrain_fx "snow"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "ice"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "shallow_water"
			;nothing
		else
			{view start "dust"}
			{delay 0.3 {view pause "dust"}}
		}
	}
}
{"150mm_sfh18_jap"
	{on "add_weapon_sound" overload
		("Cannon_150to210mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}

	("cannon_big")
}
{"50mm_type98_mortar"
	{on "add_weapon_sound" overload
		("Mortar_5-6cm")
	}
}

{"heavy_mg_20mm_oerlikon"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("magazine" cut(0.75) show(4.25) override(overload) impulse({impulse up 0.3 forward 0.9 0.1}))

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "wheell" 1)
		("cut_part" args "wheelr" 1)
		{inherited}
	}
	{on "construction_sandbag_cannon_shallow_ai" overload}			;// used by AI defense mg's in conquest. removes persistence from their sandbags
	{on "construction_sandbag_cannon_standard_ai" overload}			;// used by AI defense mg's in conquest. removes persistence from their sandbags
	{on "construction_sandbag_cannon_shallow" overload}
	{on "construction_sandbag_cannon_standard" overload}
	("cannon_small")
}

{"heavy_mg_20mm_flak30"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("magazine" cut(0.4) show(1.8) override(overload) impulse({impulse up 0.3 forward 0.9 0.1}))

	("cannon_small")
}

{"heavy_mg_20mm_itk35"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	("magazine" cut(0.4) show(1.8) override(overload) impulse({impulse up 0.3 0.2 forward 1.9 0.2}))

	{on "cut_parts" overload
		("cut_part" args "wheell" 1)
		("cut_part" args "wheelr" 1)
		{inherited}
	}

	("cannon_small")
}

{"heavy_mg_20mm_type_98_aa"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
	}
	("repair_anm_script_v1")
	{on "reload"
		{tear "piece_small_steel" bone "magazine2" copy
			{volumes disable bullet blast}				;// prevent destroing at spawn moment
			{impulse dir 2 fz -5 fx 5.5 }
		}
		{delay 0.1
			{bone hide "magazine2"}
		}
		{delay 2.5
			{bone show "magazine2"}
			{volumes enable bullet blast}				;// prevent destroing at spawn moment
		}
	}
	("cannon_small")
}

{"heavy_mg_25mm_72k"
	{on "add_weapon_sound" overload
		("Autocannon_s1")
		{link_sound "action_recoil_Cannon"	"weapon/shot/cannon/s1/recoil/Shared/Autocannon_20to30mm/"}
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.23) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_small")
}

{"heavy_mg_40mm_m1"
	{on "add_weapon_sound" overload
		("Autocannon_s2")
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.45) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_small")
}
{"37mm_type94_at"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.25 0.2)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}
	("repair_anm_script_v1")
	("cannon_small")
}

{"37mm_type1_at"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.25 0.2)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}
	("repair_anm_script_v1")
	("cannon_small")
}

{"37mm_type94_at_noshield"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.25 0.2)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}
	("repair_anm_script_v1")
	("cannon_small")
}

{"37mm_type1_at_noshield"
	{on "add_weapon_sound" overload
		("Cannon_37to40mm")
		("Cannon_Breech")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.25 0.2)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}
	("repair_anm_script_v1")
	("cannon_small")
}

{"105mm_experimental_at_gun"
	{on "add_weapon_sound" overload
		("Cannon_105to130mm")
		("Cannon_Breech")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.9 0.15)
	}

	{on "reload_delay" overload
		("reload_time" args 6.1)
	}

	("repair_anm_script_v1")
	("cannon_big")
}

{"type_94_tk_trailer"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t26/"}
	}
	("repair_anm_script_v1")
}

{"type_94_tk_trailer_gas"
	(define "spawn_zone"
			{spawn "killzone_inf_gas_600"}
			{spawn "killzone_veh_gas_600"}
	)
	(define "spawn_zone_light"
		{spawn "killzone_inf_gas_light_600"}
		{spawn "killzone_veh_gas_light_600"}
	)
	{on spawn
		{add_view "smoke_gas_launcher"			"escape" 	"fx_gas_smoke"}
		{add_view "smoke_gas_light"					"cloud1" 	"root"}
		{add_view "smoke_gas_light_big"				"cloud2" 	"root"}
		{add_view "fog_gas"							"cloud3" 	"root"}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t26/"}
		{link_sound "gas_release"       "vehicle/gas_flow"}
	}
	("repair_anm_script_v1")
	{on "deploy_gas"
		("gas_start")
	}	
	{on "_explosion" overload
		{set "no_burn_volumes" 1}
		{set_skeleton "_xx" sync}
		{tags add "exploded"}
		{call "break_all"}
		{call "impulse"}
		{ani_play "death"}
		{mark_for_persistence}			;// Conquest map persistence
		{add_view "smoke_gas_light_big"				"cloud2" 	"root"}
		{add_view "fog_gas"							"cloud3" 	"root"}
		{view start "cloud2"}
		{view start "cloud3"}
		{spawn "car_die_particle"}
		{delay 5
			("spawn_zone")
			("spawn_zone_light")
		}		
		{delay 10
			("spawn_zone")
			("spawn_zone_light")
			{stop_sound "flame"}
		}
		{delay 15
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 20
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 25
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 30
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 35
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 40
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 45
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 50
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 55
			("spawn_zone")
			("spawn_zone_light")
		}
		{delay 60
			("spawn_zone")
			{view pause "cloud2"}
			{view pause "cloud3"}
		}
		{delay 65
			("spawn_zone")
		}
	}
}

{"northover_projector"
	{on "add_weapon_sound" overload
		("Cannon_Breech")
	}

	{on fire "gun"
		{delay 1
			{ani_play "open_breech"}
			{delay 2
				{ani_play "close_breech"}
			}
		}
	}

	{on "reload"
		{delay 1
			{ani_play "open_breech"}
			{delay 2
				{ani_play "close_breech"}
			}
		}
	}

	("repair_anm_script_v1")
}