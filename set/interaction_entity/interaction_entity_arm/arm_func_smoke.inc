

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
		{view hide "smoke1"}
		{view hide "smoke2"}
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
		{view hide "smoke1"}
		{view hide "smoke2"}
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
		{view hide "smoke1"}
		{view hide "smoke2"}
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
		{view hide "smoke1"}
		{view hide "smoke2"}
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