{"animal"
	{inflammation_time 1.0}
	{on spawn 
		{link_sound "burn" "fire/loops/medium"}
		{able "burning" 0}
		(mod not "mp"
			{if tagged "burning"
				{call "add_burn_fx"}
				{view start "burn_fire"}
			}
		)
		{if tagged "dead"
			{ani_play "death" 10}
		}
	}

	{on blast sync
		{health_damage_blast
			{effects "" "" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}

	{on blow opponent sync
		{health_damage_blow
			{effects "hit" "hit" "die" "die" "explosion" "explosion" "explosion"}
		}
		{call "damage"}
	}

	{on bullet_hit
		{signal hit 5}
		{if stuff "shell fg"
			{bullet_detonate}
			{call "pierce_damage"}
		else stuff "rocketlauncher"
			{bullet_detonate}
			{call "pierce_damage"}
		else stuff "rifle_grenade_at"
			{bullet_detonate}
			{call "pierce_damage"}
		else stuff "bullet"
			{call "pierce_damage"}
		else stuff "shell"
			{call "pierce_damage"}
		else
			{call "pierce_damage"}
		}
	}

	{on "pierce_damage" sync
		{health_damage_pierce
			{effects "" "" "damage" "die" "explosion" "explosion" "explosion"}
		}
	}

	(define "animal_health"
		{health_damage_count %c
			{effects "" "hit" "damage" "die" "die"}
		}
	)

	{on "burn_volume"
		{call "_burn"}
	}

	{on "_burn"
		{if not burned
			{able "burning" 1}			;// causes unit to act uncontrolable
			{tags add "burning"}
			{call "add_burn_fx"}

			{if not dead
				{call_synced "start_burn_damage"}
			}

			{delay 20
				{call_synced "stop_burn_damage"}
			}
			{burn time 20}					;// Required! Without it, humans die instantly when on fire
		}
	}

	{on "start_burn_damage"
		(define "burn_damage"					;// causes increasing damage to human health over time
			{delay %t "burn_damage"
				{if not dead
					{if able "burning"
						("animal_health" c(%c))
						{fire radius 1 time 1 heating 0.75 follow}	;// adds heating to unit (potential to set other items on fire due to proximity)
					}
				}
			}
		)
		("burn_damage" t(0.4) c(10))
		("burn_damage" t(0.8) c(15))
		("burn_damage" t(1.2) c(20))
		("burn_damage" t(1.6) c(30))
		("burn_damage" t(2.0) c(35))
		("burn_damage" t(2.4) c(45))
		("burn_damage" t(2.8) c(50))
	}

	{on "stop_burn_damage"
		{view stop "burn_fire"}		;// stops burning fx
		{stop_sound "burn"}
		{able "burning" 0}			;// stops uncontrolable actions (keep incase friendly is set on fire and is not damaged/killed)
		{tags remove "burning"}
		{delay 1.0
			{call "stop_burn"}
		}
	}

	{on "add_burn_fx"
		{play_sound "burn" 1}
		{burn volume "body" fx "fire_dead" time 20}
	}

	{on contact
		{if effector "vehicle"
			{if not effector "bicycle"
				{if not effector "cannon_small"
					{if effector_velocity 1.0
						{health_damage_count 200 {effects "" "hit" "damage" "die" "die"}}
					}
				}
			}
		else effector "knife"
			{if contact_velocity 5
				{health_damage_count 110 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "axe"
			{if contact_velocity 5
				{health_damage_count 180 {effects "" "hit" "damage" "die" "die"}}
			}
		else effector "big part"
			{if contact_velocity 3
				{health_damage_count 60 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "medium part"
			{if contact_velocity 6
				{health_damage_count 40 {effects "" "hit" "damage" "die" "crush"}}
			}
		else effector "small part"
			{if contact_velocity 10
				{health_damage_count 20 {effects "" "hit" "damage" "die" "die"}}
			}
		}
	}

	{on "die"
		{volumes disable contact}
		{die}
		{delay 3
			{volumes enable contact}
			{update_visibility_patch}
		}
		{tags add "dead"}
	}

	{on "explosion"
		{delete}
	}

	{on "idle"
		{if name "enter"
			{call "idle_try"}
		else name "exit"
			{ani_stop "passive"}
			{ani_stop "eat"}
			{kill_delay "idle_try"}
			{kill_delay "idle_noanm"}
		}
	}

	{on "idle_try"
		{delay 0.2 0.1 "idle_try"
			{if rand 0.4
				{call_synced "ain_play_eat"}
			else rand 0.4
				{call_synced "ain_play_passive"}
			else
				{delay 5 3 "idle_noanm"
					{call_synced "idle_try"}
				}
			}
		}
	}

	{on "ain_play_eat"
		{ani_play "eat" callback}
	}
	{on "ain_play_passive"
		{ani_play "passive" callback}
	}

	{on animation_end "passive"
		{call "idle_try"}
	}

	{on animation_end "eat"
		{call "idle_try"}
	}
}

{"chicken"
	{on "damage"
		{spawn "pero_hit_small"}
		{start_sound "animal/chicken/cluck"}
	}
	{on "die"
		{call "explosion"}
	}
	{on "explosion"
		{start_sound "animal/chicken/die"}
		{spawn "pero_hit"}
		{spawn "blood_small"}
		{delete}
		{if tagged "drop_steak"
			{spawn "steak"}
		}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/chicken/cluck"}
		}
	}
	{on ground_hit
		{call "feather"}
	}
	{on contact
		{if velocity 4
			{call "feather"}
		}
	}
	{on "feather"
		{if not "feather"
			{set "feather" 1}
			{spawn "pero_hit_small"}
			{start_sound "animal/chicken/cluck"}
			{delay 0.2
				{set "feather" 0}
			}
		}
	}
}

(define "imp"
	{spawn %0 %1
		{impulse	up 1 0.5 dir 8 4
					cx 0 12 cy 0 12
					fx 0 60 fy 0 60 fz 80 40
		}
	}
)

{"dog"
	{on spawn
		{add_view	"drops_water_small3"	"on_water"	"leg1"}
		{add_view	"drops_water_small3"	"on_water"	"leg2"}
		{add_view	"drops_water_small3"	"on_water"	"leg3"}
		{add_view	"drops_water_small3"	"on_water"	"leg4"}
	}
	{on "damage"
		{spawn "blood_small"}
		{if not dead
			{start_sound "animal/dog/aw"}
		}
	}
	{on "_burn"
		{if not dead
			{start_sound "animal/dog/die"}
		}
	}
	{on "die" overload  ;// volumes not attached to correct bones for death animations
		{start_sound "animal/dog/die"}
		{spawn "blood_small"}
		{volumes disable all}
		{die}
		{delay 3
			{update_visibility_patch}
		}
		{tags add "dead"}
	}
	{on "explosion"
		{if prop "severable"
			{if rand 0.7	("imp" args "head"	"basis")}
			{if rand 0.7	("imp" args "head"	"basis")}
			{if rand 0.7	("imp" args "hand1"	"basis")}
			{if rand 0.7	("imp" args "hand2"	"basis")}
		}
		{if not dead
			{start_sound "animal/dog/die"}
		}
		{spawn "blood"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/dog/aw"}
		}
	}

	(define "terrain_fx_dog"
		{on terrain_fx %0 enter
			{view start "on_%1"}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx_dog" args "shallow_water" 	water)
	("terrain_fx_dog" args "puddle"			water)
}

{"rabbit"
	{on "damage"
		{spawn "blood_small"}
	}
	{on "die"
		{spawn "rabbit_hit"}
		{spawn "blood_small"}
		{delete}
	}
	{on "explosion"
		{if prop "severable"
			{if rand 0.7	("imp" args "head"	"basis")}
			{if rand 0.7	("imp" args "head"	"basis")}
		}
		{spawn "rabbit_hit"}
		{spawn "blood"}
;		{spawn "blood_small"}
		{delete}
	}
}

{"cow"
	{on spawn
		{if tagged "dead"
			{ani_play "death" 10}
		}
	}
	{on "pierce_damage" overload sync
		{health_damage_pierce
			{effects "" "" "damage" "die" "explosion"}
		}
	}
	{on "damage"
		{spawn "blood_small"}
		{if not dead
			{start_sound "animal/cow/moo"}
		}
	}
	{on "die"
		{start_sound "animal/cow/moo"}
		{spawn "blood_small"}
		{tags add "dead"}
	}
	{on "_burn"
		{if not dead
			{start_sound "animal/cow/moo"}
		}
	}
	{on "explosion"
		{if prop "severable"
			{if rand 0.7	("imp" args "head"	"basis")}
			{if rand 0.7	("imp" args "head"	"basis")}
			{if rand 0.7	("imp" args "hand1"	"basis")}
			{if rand 0.7	("imp" args "hand2"	"basis")}
		}
		{if not dead
			{start_sound "animal/cow/moo"}
		}
		{spawn "blood"}
		{delete}
	}
	{on "avoid"
		{if rand 0.3
			{start_sound "animal/cow/moo"}
		}
	}
}
{"butterfly"
	(define "rand_anim"
		{if rand 0.5
			{ani_play "fly%0" 0.7 loop}
			{tags add "flying"}
		}
	)
	{on spawn overload
		("rand_anim" args 1)
		("rand_anim" args 2)
		("rand_anim" args 3)
		("rand_anim" args 4)
		("rand_anim" args 5)
		{delay 0.1
			{if not tagged "flying"
				{ani_play "fly" 0.7 loop}
			else 
				{tags remove "flying"}
			}
		}
	}
}

{"pig"
	{on "die" overload  ;// volumes not attached to correct bones for death animations
		{volumes disable all}
		{die}
		{delay 3
			{update_visibility_patch}
		}
		{tags add "dead"}
	}
}

{"donkey"
	{on "die" overload  ;// volumes not attached to correct bones for death animations
		{volumes disable all}
		{die}
		{delay 3
			{update_visibility_patch}
		}
		{tags add "dead"}
	}
}

{"animal_demorale"}