; File: 		arm_airborne.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm
; Created by: 	Max Drechsler
; Created:		x.xx.xxxx
; Modify by:	Max Drechsler
; Modify:		12.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		1.2
; Description: 

;--------
{"ju-52 drop_plane"

	{on spawn
		{tags add "move_to_start_waypoint"}
		{tags add "user_plane"}	
		{tags remove "moving_to_drop_zone"}	
		{tags remove "ready_to_move"}	
		{tags remove "on_mission"}	
		{tags remove "nocrew"}
		{tags remove "out"}
		{tags remove "dropping_troopers"}
		{delay 0.2
			{if work "body"
				{tags add "drop_plane"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}

	(define "eject_troopers"
		{delay %delay
			{with_linked_entity %seat
				{unlink}
				{if not user_control
					{tags add "paratrooper"}	
					{tags add "ignore_spawn_logic"}	
				else 
					{tags add "player_paratrooper"}	
				}
			}
		}	
	)

	{on "drop_test"
		{tags add "deploying_paratroopers"}	
		{tags remove "drop_plane_selected"}
		; + ARM 120926 — БАТЧ 1: близкие к двери → дальние
		("eject_troopers" delay(1.0)	seat("seat11"))
		("eject_troopers" delay(1.5)	seat("seat12"))
		("eject_troopers" delay(2.0)	seat("seat13"))
		("eject_troopers" delay(2.5)	seat("seat14"))
		("eject_troopers" delay(3.0)	seat("seat15"))
		("eject_troopers" delay(3.5)	seat("seat16"))
		("eject_troopers" delay(4.0)	seat("seat17"))
		("eject_troopers" delay(4.5)	seat("seat18"))
		("eject_troopers" delay(5.0)	seat("seat19"))
		("eject_troopers" delay(5.5)	seat("seat20"))
		("eject_troopers" delay(6.0)	seat("seat10"))
		("eject_troopers" delay(6.5)	seat("seat09"))
		("eject_troopers" delay(7.0)	seat("seat08"))
		("eject_troopers" delay(7.5)	seat("seat07"))
		("eject_troopers" delay(8.0)	seat("seat06"))
		("eject_troopers" delay(8.5)	seat("seat05"))
		("eject_troopers" delay(9.0)	seat("seat04"))
		("eject_troopers" delay(9.5)	seat("seat03"))
		("eject_troopers" delay(10.0)	seat("seat02"))
		("eject_troopers" delay(10.5)	seat("seat01"))
		{delay 11.5 ;//SAFESWITCH TO FLUSH OUT THIS FUCKERS
			; + ARM 120926 — БАТЧ 2: зеркально, дальние → близкие
			("eject_troopers" delay(0.3)	seat("seat01"))
			("eject_troopers" delay(0.6)	seat("seat02"))
			("eject_troopers" delay(0.9)	seat("seat03"))
			("eject_troopers" delay(1.2)	seat("seat04"))
			("eject_troopers" delay(1.5)	seat("seat05"))
			("eject_troopers" delay(1.8)	seat("seat06"))
			("eject_troopers" delay(2.1)	seat("seat07"))
			("eject_troopers" delay(2.4)	seat("seat08"))
			("eject_troopers" delay(2.7)	seat("seat09"))
			("eject_troopers" delay(3.0)	seat("seat10"))
			("eject_troopers" delay(3.3)	seat("seat20"))
			("eject_troopers" delay(3.6)	seat("seat19"))
			("eject_troopers" delay(3.9)	seat("seat18"))
			("eject_troopers" delay(4.2)	seat("seat17"))
			("eject_troopers" delay(4.5)	seat("seat16"))
			("eject_troopers" delay(4.8)	seat("seat15"))
			("eject_troopers" delay(5.1)	seat("seat14"))
			("eject_troopers" delay(5.4)	seat("seat13"))
			("eject_troopers" delay(5.7)	seat("seat12"))
			("eject_troopers" delay(6.0)	seat("seat11"))
		}
		{delay 60
			{hide 5}
		}
	}
}

{"ju-52 drop_plane_enemy"

	{on spawn
		{tags add "move_to_start_waypoint"}
		{tags add "drop_plane_enemy"}	
		{tags remove "moving_to_drop_zone"}	
		{tags remove "ready_to_move"}	
		{tags remove "on_mission"}	
		{tags remove "nocrew"}
		{tags remove "out"}
		{tags remove "dropping_troopers"}
		{delay 0.2
			{if work "body"
				{tags add "drop_plane_enemy"}
				{tags add "move_to_start_waypoint"}
			}
		}
		; + ARM 130926 — вернуть тег, который запускает send_enemy_drop_plane
		{delay 0.5
			{tags add "ready_to_move"}
		}
	}

	(define "eject_troopers_enemy"
		{delay %delay
			{with_linked_entity %seat
				{unlink}
				{if not user_control
					{tags add "enemy_paratrooper"}	
					{tags add "ignore_spawn_logic"}	
					{tags add "paradrop_taunt_active"}					; ARm added 130926
				else 
					{tags add "enemy_paratrooper"}	
				}
			}
		}	
	)
	
	{on "drop_troopers_enemy"
		{tags add "deploying_paratroopers"}	
		{tags remove "drop_plane_selected"}
		; + ARM 120926 — БАТЧ 1: близкие к двери → дальние
		("eject_troopers_enemy" delay(1.0)	seat("seat11"))
		("eject_troopers_enemy" delay(1.5)	seat("seat12"))
		("eject_troopers_enemy" delay(2.0)	seat("seat13"))
		("eject_troopers_enemy" delay(2.5)	seat("seat14"))
		("eject_troopers_enemy" delay(3.0)	seat("seat15"))
		("eject_troopers_enemy" delay(3.5)	seat("seat16"))
		("eject_troopers_enemy" delay(4.0)	seat("seat17"))
		("eject_troopers_enemy" delay(4.5)	seat("seat18"))
		("eject_troopers_enemy" delay(5.0)	seat("seat19"))
		("eject_troopers_enemy" delay(5.5)	seat("seat20"))
		("eject_troopers_enemy" delay(6.0)	seat("seat10"))
		("eject_troopers_enemy" delay(6.5)	seat("seat09"))
		("eject_troopers_enemy" delay(7.0)	seat("seat08"))
		("eject_troopers_enemy" delay(7.5)	seat("seat07"))
		("eject_troopers_enemy" delay(8.0)	seat("seat06"))
		("eject_troopers_enemy" delay(8.5)	seat("seat05"))
		("eject_troopers_enemy" delay(9.0)	seat("seat04"))
		("eject_troopers_enemy" delay(9.5)	seat("seat03"))
		("eject_troopers_enemy" delay(10.0)	seat("seat02"))
		("eject_troopers_enemy" delay(10.5)	seat("seat01"))
		{delay 11.5 ;//SAFESWITCH TO FLUSH OUT THIS FUCKERS
			; + ARM 120926 — БАТЧ 2: зеркально, дальние → близкие
			("eject_troopers_enemy" delay(0.3)	seat("seat01"))
			("eject_troopers_enemy" delay(0.6)	seat("seat02"))
			("eject_troopers_enemy" delay(0.9)	seat("seat03"))
			("eject_troopers_enemy" delay(1.2)	seat("seat04"))
			("eject_troopers_enemy" delay(1.5)	seat("seat05"))
			("eject_troopers_enemy" delay(1.8)	seat("seat06"))
			("eject_troopers_enemy" delay(2.1)	seat("seat07"))
			("eject_troopers_enemy" delay(2.4)	seat("seat08"))
			("eject_troopers_enemy" delay(2.7)	seat("seat09"))
			("eject_troopers_enemy" delay(3.0)	seat("seat10"))
			("eject_troopers_enemy" delay(3.3)	seat("seat20"))
			("eject_troopers_enemy" delay(3.6)	seat("seat19"))
			("eject_troopers_enemy" delay(3.9)	seat("seat18"))
			("eject_troopers_enemy" delay(4.2)	seat("seat17"))
			("eject_troopers_enemy" delay(4.5)	seat("seat16"))
			("eject_troopers_enemy" delay(4.8)	seat("seat15"))
			("eject_troopers_enemy" delay(5.1)	seat("seat14"))
			("eject_troopers_enemy" delay(5.4)	seat("seat13"))
			("eject_troopers_enemy" delay(5.7)	seat("seat12"))
			("eject_troopers_enemy" delay(6.0)	seat("seat11"))
		}
		{delay 45
			{hide 5}
		}
	}
}

{"c47_d drop_plane"

	{on spawn
		{tags add "move_to_start_waypoint"}
		{tags add "user_plane"}	
		{tags remove "moving_to_drop_zone"}	
		{tags remove "ready_to_move"}	
		{tags remove "on_mission"}	
		{tags remove "nocrew"}
		{tags remove "out"}
		{tags remove "dropping_troopers"}
		{delay 0.2
			{if work "body"
				{tags add "drop_plane"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}

	(define "eject_troopers"
		{delay %delay
			{with_linked_entity %seat
				{unlink}
				{if not user_control
					{tags add "paratrooper"}	
					{tags add "ignore_spawn_logic"}	
				else 
					{tags add "player_paratrooper"}	
				}
			}
		}	
	)

	{on "drop_test"
		{tags add "deploying_paratroopers"}	
		{tags remove "drop_plane_selected"}
		; + ARM 120926 — БАТЧ 1: близкие к двери → дальние
		("eject_troopers" delay(1.0)	seat("seat1"))
		("eject_troopers" delay(1.5)	seat("seat17"))
		("eject_troopers" delay(2.0)	seat("seat18"))
		("eject_troopers" delay(2.5)	seat("seat13"))
		("eject_troopers" delay(3.0)	seat("seat14"))
		("eject_troopers" delay(3.5)	seat("seat16"))
		("eject_troopers" delay(4.0)	seat("seat19"))
		("eject_troopers" delay(4.5)	seat("seat15"))
		("eject_troopers" delay(5.0)	seat("seat20"))
		("eject_troopers" delay(5.5)	seat("seat9"))
		("eject_troopers" delay(6.0)	seat("seat10"))
		("eject_troopers" delay(6.5)	seat("seat5"))
		("eject_troopers" delay(7.0)	seat("seat6"))
		("eject_troopers" delay(7.5)	seat("seat11"))
		("eject_troopers" delay(8.0)	seat("seat12"))
		("eject_troopers" delay(8.5)	seat("seat3"))
		("eject_troopers" delay(9.0)	seat("seat4"))
		("eject_troopers" delay(9.5)	seat("seat7"))
		("eject_troopers" delay(10.0)	seat("seat8"))
		("eject_troopers" delay(10.5)	seat("seat2"))
		{delay 11.5 ;//SAFESWITCH TO FLUSH OUT THIS FUCKERS
			; + ARM 120926 — БАТЧ 2: зеркально, дальние → близкие
			("eject_troopers" delay(0.3)	seat("seat2"))
			("eject_troopers" delay(0.6)	seat("seat8"))
			("eject_troopers" delay(0.9)	seat("seat7"))
			("eject_troopers" delay(1.2)	seat("seat4"))
			("eject_troopers" delay(1.5)	seat("seat3"))
			("eject_troopers" delay(1.8)	seat("seat12"))
			("eject_troopers" delay(2.1)	seat("seat11"))
			("eject_troopers" delay(2.4)	seat("seat6"))
			("eject_troopers" delay(2.7)	seat("seat5"))
			("eject_troopers" delay(3.0)	seat("seat10"))
			("eject_troopers" delay(3.3)	seat("seat9"))
			("eject_troopers" delay(3.6)	seat("seat20"))
			("eject_troopers" delay(3.9)	seat("seat15"))
			("eject_troopers" delay(4.2)	seat("seat19"))
			("eject_troopers" delay(4.5)	seat("seat16"))
			("eject_troopers" delay(4.8)	seat("seat14"))
			("eject_troopers" delay(5.1)	seat("seat13"))
			("eject_troopers" delay(5.4)	seat("seat18"))
			("eject_troopers" delay(5.7)	seat("seat17"))
			("eject_troopers" delay(6.0)	seat("seat1"))
		}
		{delay 60
			{hide 5}
		}
	}
}

{"c47_d drop_plane_enemy"

	{on spawn
		{tags add "move_to_start_waypoint"}
		{tags add "drop_plane_enemy"}	
		{tags remove "moving_to_drop_zone"}	
		{tags remove "ready_to_move"}	
		{tags remove "on_mission"}	
		{tags remove "nocrew"}
		{tags remove "out"}
		{tags remove "dropping_troopers"}
		{delay 0.2
			{if work "body"
				{tags add "drop_plane_enemy"}
				{tags add "move_to_start_waypoint"}
			}
		}
		; + ARM 130926 — вернуть тег, который запускает send_enemy_drop_plane
		{delay 0.5
			{tags add "ready_to_move"}
		}
	}

	(define "eject_troopers_enemy"
		{delay %delay
			{with_linked_entity %seat
				{unlink}
				{if not user_control
					{tags add "enemy_paratrooper"}	
					{tags add "ignore_spawn_logic"}	
					{tags add "paradrop_taunt_active"}					; ARm added 130926
				else 
					{tags add "enemy_paratrooper"}	
				}
			}
		}	
	)

	{on "drop_troopers_enemy"
		{tags add "deploying_paratroopers"}	
		{tags remove "drop_plane_selected"}
		; + ARM 120926 — БАТЧ 1: близкие к двери → дальние
		("eject_troopers_enemy" delay(1.0)	seat("seat1"))
		("eject_troopers_enemy" delay(1.5)	seat("seat17"))
		("eject_troopers_enemy" delay(2.0)	seat("seat18"))
		("eject_troopers_enemy" delay(2.5)	seat("seat13"))
		("eject_troopers_enemy" delay(3.0)	seat("seat14"))
		("eject_troopers_enemy" delay(3.5)	seat("seat16"))
		("eject_troopers_enemy" delay(4.0)	seat("seat19"))
		("eject_troopers_enemy" delay(4.5)	seat("seat15"))
		("eject_troopers_enemy" delay(5.0)	seat("seat20"))
		("eject_troopers_enemy" delay(5.5)	seat("seat9"))
		("eject_troopers_enemy" delay(6.0)	seat("seat10"))
		("eject_troopers_enemy" delay(6.5)	seat("seat5"))
		("eject_troopers_enemy" delay(7.0)	seat("seat6"))
		("eject_troopers_enemy" delay(7.5)	seat("seat11"))
		("eject_troopers_enemy" delay(8.0)	seat("seat12"))
		("eject_troopers_enemy" delay(8.5)	seat("seat3"))
		("eject_troopers_enemy" delay(9.0)	seat("seat4"))
		("eject_troopers_enemy" delay(9.5)	seat("seat7"))
		("eject_troopers_enemy" delay(10.0)	seat("seat8"))
		("eject_troopers_enemy" delay(10.5)	seat("seat2"))
		{delay 11.5 ;//SAFESWITCH TO FLUSH OUT THIS FUCKERS
			; + ARM 120926 — БАТЧ 2: зеркально, дальние → близкие
			("eject_troopers_enemy" delay(0.3)	seat("seat2"))
			("eject_troopers_enemy" delay(0.6)	seat("seat8"))
			("eject_troopers_enemy" delay(0.9)	seat("seat7"))
			("eject_troopers_enemy" delay(1.2)	seat("seat4"))
			("eject_troopers_enemy" delay(1.5)	seat("seat3"))
			("eject_troopers_enemy" delay(1.8)	seat("seat12"))
			("eject_troopers_enemy" delay(2.1)	seat("seat11"))
			("eject_troopers_enemy" delay(2.4)	seat("seat6"))
			("eject_troopers_enemy" delay(2.7)	seat("seat5"))
			("eject_troopers_enemy" delay(3.0)	seat("seat10"))
			("eject_troopers_enemy" delay(3.3)	seat("seat9"))
			("eject_troopers_enemy" delay(3.6)	seat("seat20"))
			("eject_troopers_enemy" delay(3.9)	seat("seat15"))
			("eject_troopers_enemy" delay(4.2)	seat("seat19"))
			("eject_troopers_enemy" delay(4.5)	seat("seat16"))
			("eject_troopers_enemy" delay(4.8)	seat("seat14"))
			("eject_troopers_enemy" delay(5.1)	seat("seat13"))
			("eject_troopers_enemy" delay(5.4)	seat("seat18"))
			("eject_troopers_enemy" delay(5.7)	seat("seat17"))
			("eject_troopers_enemy" delay(6.0)	seat("seat1"))
		}
		{delay 45
			{hide 5}
		}
	}
}

{"c47_d_eng drop_plane"

	{on spawn
		{tags add "move_to_start_waypoint"}
		{tags add "user_plane"}	
		{tags remove "moving_to_drop_zone"}	
		{tags remove "ready_to_move"}	
		{tags remove "on_mission"}	
		{tags remove "nocrew"}
		{tags remove "out"}
		{tags remove "dropping_troopers"}
		{delay 0.2
			{if work "body"
				{tags add "drop_plane"}
				{tags add "move_to_start_waypoint"}
			}
		}
	}

	(define "eject_troopers"
		{delay %delay
			{with_linked_entity %seat
				{unlink}
				{if not user_control
					{tags add "paratrooper"}	
					{tags add "ignore_spawn_logic"}	
				else 
					{tags add "player_paratrooper"}	
				}
			}
		}	
	)

	{on "drop_test"
		{tags add "deploying_paratroopers"}	
		{tags remove "drop_plane_selected"}
		; + ARM 120926 — БАТЧ 1: близкие к двери → дальние
		("eject_troopers" delay(1.0)	seat("seat1"))
		("eject_troopers" delay(1.5)	seat("seat17"))
		("eject_troopers" delay(2.0)	seat("seat18"))
		("eject_troopers" delay(2.5)	seat("seat13"))
		("eject_troopers" delay(3.0)	seat("seat14"))
		("eject_troopers" delay(3.5)	seat("seat16"))
		("eject_troopers" delay(4.0)	seat("seat19"))
		("eject_troopers" delay(4.5)	seat("seat15"))
		("eject_troopers" delay(5.0)	seat("seat20"))
		("eject_troopers" delay(5.5)	seat("seat9"))
		("eject_troopers" delay(6.0)	seat("seat10"))
		("eject_troopers" delay(6.5)	seat("seat5"))
		("eject_troopers" delay(7.0)	seat("seat6"))
		("eject_troopers" delay(7.5)	seat("seat11"))
		("eject_troopers" delay(8.0)	seat("seat12"))
		("eject_troopers" delay(8.5)	seat("seat3"))
		("eject_troopers" delay(9.0)	seat("seat4"))
		("eject_troopers" delay(9.5)	seat("seat7"))
		("eject_troopers" delay(10.0)	seat("seat8"))
		("eject_troopers" delay(10.5)	seat("seat2"))
		{delay 11.5 ;//SAFESWITCH TO FLUSH OUT THIS FUCKERS
			; + ARM 120926 — БАТЧ 2: зеркально, дальние → близкие
			("eject_troopers" delay(0.3)	seat("seat2"))
			("eject_troopers" delay(0.6)	seat("seat8"))
			("eject_troopers" delay(0.9)	seat("seat7"))
			("eject_troopers" delay(1.2)	seat("seat4"))
			("eject_troopers" delay(1.5)	seat("seat3"))
			("eject_troopers" delay(1.8)	seat("seat12"))
			("eject_troopers" delay(2.1)	seat("seat11"))
			("eject_troopers" delay(2.4)	seat("seat6"))
			("eject_troopers" delay(2.7)	seat("seat5"))
			("eject_troopers" delay(3.0)	seat("seat10"))
			("eject_troopers" delay(3.3)	seat("seat9"))
			("eject_troopers" delay(3.6)	seat("seat20"))
			("eject_troopers" delay(3.9)	seat("seat15"))
			("eject_troopers" delay(4.2)	seat("seat19"))
			("eject_troopers" delay(4.5)	seat("seat16"))
			("eject_troopers" delay(4.8)	seat("seat14"))
			("eject_troopers" delay(5.1)	seat("seat13"))
			("eject_troopers" delay(5.4)	seat("seat18"))
			("eject_troopers" delay(5.7)	seat("seat17"))
			("eject_troopers" delay(6.0)	seat("seat1"))
		}
		{delay 60
			{hide 5}
		}
	}
}

{"c47_d_eng drop_plane_enemy"

	{on spawn
		{tags add "move_to_start_waypoint"}
		{tags add "drop_plane_enemy"}	
		{tags remove "moving_to_drop_zone"}	
		{tags remove "ready_to_move"}	
		{tags remove "on_mission"}	
		{tags remove "nocrew"}
		{tags remove "out"}
		{tags remove "dropping_troopers"}
		{delay 0.2
			{if work "body"
				{tags add "drop_plane_enemy"}
				{tags add "move_to_start_waypoint"}
			}
		}
		; + ARM 130926 — вернуть тег, который запускает send_enemy_drop_plane
		{delay 0.5
			{tags add "ready_to_move"}
		}
	}

	(define "eject_troopers_enemy"
		{delay %delay
			{with_linked_entity %seat
				{unlink}
				{if not user_control
					{tags add "enemy_paratrooper"}	
					{tags add "ignore_spawn_logic"}	
					{tags add "paradrop_taunt_active"}					; ARm added 130926
				else 
					{tags add "enemy_paratrooper"}	
				}
			}
		}	
	)

	{on "drop_troopers_enemy"
		{tags add "deploying_paratroopers"}	
		{tags remove "drop_plane_selected"}
		; + ARM 120926 — БАТЧ 1: близкие к двери → дальние
		("eject_troopers_enemy" delay(1.0)	seat("seat1"))
		("eject_troopers_enemy" delay(1.5)	seat("seat17"))
		("eject_troopers_enemy" delay(2.0)	seat("seat18"))
		("eject_troopers_enemy" delay(2.5)	seat("seat13"))
		("eject_troopers_enemy" delay(3.0)	seat("seat14"))
		("eject_troopers_enemy" delay(3.5)	seat("seat16"))
		("eject_troopers_enemy" delay(4.0)	seat("seat19"))
		("eject_troopers_enemy" delay(4.5)	seat("seat15"))
		("eject_troopers_enemy" delay(5.0)	seat("seat20"))
		("eject_troopers_enemy" delay(5.5)	seat("seat9"))
		("eject_troopers_enemy" delay(6.0)	seat("seat10"))
		("eject_troopers_enemy" delay(6.5)	seat("seat5"))
		("eject_troopers_enemy" delay(7.0)	seat("seat6"))
		("eject_troopers_enemy" delay(7.5)	seat("seat11"))
		("eject_troopers_enemy" delay(8.0)	seat("seat12"))
		("eject_troopers_enemy" delay(8.5)	seat("seat3"))
		("eject_troopers_enemy" delay(9.0)	seat("seat4"))
		("eject_troopers_enemy" delay(9.5)	seat("seat7"))
		("eject_troopers_enemy" delay(10.0)	seat("seat8"))
		("eject_troopers_enemy" delay(10.5)	seat("seat2"))
		{delay 11.5 ;//SAFESWITCH TO FLUSH OUT THIS FUCKERS
			; + ARM 120926 — БАТЧ 2: зеркально, дальние → близкие
			("eject_troopers_enemy" delay(0.3)	seat("seat2"))
			("eject_troopers_enemy" delay(0.6)	seat("seat8"))
			("eject_troopers_enemy" delay(0.9)	seat("seat7"))
			("eject_troopers_enemy" delay(1.2)	seat("seat4"))
			("eject_troopers_enemy" delay(1.5)	seat("seat3"))
			("eject_troopers_enemy" delay(1.8)	seat("seat12"))
			("eject_troopers_enemy" delay(2.1)	seat("seat11"))
			("eject_troopers_enemy" delay(2.4)	seat("seat6"))
			("eject_troopers_enemy" delay(2.7)	seat("seat5"))
			("eject_troopers_enemy" delay(3.0)	seat("seat10"))
			("eject_troopers_enemy" delay(3.3)	seat("seat9"))
			("eject_troopers_enemy" delay(3.6)	seat("seat20"))
			("eject_troopers_enemy" delay(3.9)	seat("seat15"))
			("eject_troopers_enemy" delay(4.2)	seat("seat19"))
			("eject_troopers_enemy" delay(4.5)	seat("seat16"))
			("eject_troopers_enemy" delay(4.8)	seat("seat14"))
			("eject_troopers_enemy" delay(5.1)	seat("seat13"))
			("eject_troopers_enemy" delay(5.4)	seat("seat18"))
			("eject_troopers_enemy" delay(5.7)	seat("seat17"))
			("eject_troopers_enemy" delay(6.0)	seat("seat1"))
		}
		{delay 45
			{hide 5}
		}
	}
}



;--------