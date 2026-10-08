{"shell_smoke" ;// props from shell_smoke service entity
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder" 
			{add_view "smoke_cover-up_big" "smoke1" "root"}
			{view start "smoke1"}
			{delay 85
				{view stop "smoke1"}
			}
			{delay 90
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 120 0 84)
			("spawn_volume" args cylinder -120 0 84)
			("spawn_volume" args cylinder 0 120 84)
			("spawn_volume" args cylinder 0 -120 84)
			("spawn_volume" args cylinder 83 83 84)
			("spawn_volume" args cylinder -83 -83 84)
			("spawn_volume" args cylinder -83 83 84)
			("spawn_volume" args cylinder 83 -83 84)
		}
		{delay 5
			("spawn_volume" args cylinder_sm 220 0 82)
			("spawn_volume" args cylinder_sm -220 0 82)
			("spawn_volume" args cylinder_sm 0 220 82)
			("spawn_volume" args cylinder_sm 0 -220 82)
		}
		{delay 90
			{hide 1}
		}
	}
}
{"shell_smoke_wp_size1" ;// props from shell_smoke service entity; light mortar, rifle grenade
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder" 
			{add_view "smoke_wp_size1" "smoke1" "root"}
			{view start "smoke1"}
			{delay 56
				{view stop "smoke1"}
			}
			{delay 60 
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 90 0 59)
			("spawn_volume" args cylinder -90 0 59)
			("spawn_volume" args cylinder 0 90 59)
			("spawn_volume" args cylinder 0 -90 59)
			("spawn_volume" args cylinder 62 62 59)
			("spawn_volume" args cylinder -62 -62 59)
			("spawn_volume" args cylinder -62 62 59)
			("spawn_volume" args cylinder 62 -62 59)
		}
		{delay 65
			{hide 1}
		}
	}
}
{"shell_smoke_wp_size2" ;// props from shell_smoke service entity; 75mm, 81mm mortar
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder"
			{add_view "smoke_wp_size2" "smoke1" "root"}
			{view start "smoke1"}
			{delay 71
				{view stop "smoke1"}
			}
			{delay 75 
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 100 0 74)
			("spawn_volume" args cylinder -100 0 74)
			("spawn_volume" args cylinder 0 100 74)
			("spawn_volume" args cylinder 0 -100 74)
			("spawn_volume" args cylinder 69 69 74)
			("spawn_volume" args cylinder -69 -69 74)
			("spawn_volume" args cylinder -69 69 74)
			("spawn_volume" args cylinder 69 -69 74)
		}
		{delay 80
			{hide 1}
		}
	}
}
{"shell_smoke_size2" ;// props from shell_smoke service entity; 75mm, 81mm mortar
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder"
			{add_view "smoke_size2" "smoke1" "root"}
			{view start "smoke1"}
			{delay 71
				{view stop "smoke1"}
			}
			{delay 75 
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 100 0 74)
			("spawn_volume" args cylinder -100 0 74)
			("spawn_volume" args cylinder 0 100 74)
			("spawn_volume" args cylinder 0 -100 74)
			("spawn_volume" args cylinder 69 69 74)
			("spawn_volume" args cylinder -69 -69 74)
			("spawn_volume" args cylinder -69 69 74)
			("spawn_volume" args cylinder 69 -69 74)
		}
		{delay 80
			{hide 1}
		}
	}
}
{"shell_smoke_wp_size3" ;// props from shell_smoke service entity; 105-122, 107-120mm mortar
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder" 
			{add_view "smoke_wp_size3" "smoke1" "root"}
			{view start "smoke1"}
			{delay 81
				{view stop "smoke1"}
			}
			{delay 85 
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 120 0 84)
			("spawn_volume" args cylinder -120 0 84)
			("spawn_volume" args cylinder 0 120 84)
			("spawn_volume" args cylinder 0 -120 84)
			("spawn_volume" args cylinder 83 83 84)
			("spawn_volume" args cylinder -83 -83 84)
			("spawn_volume" args cylinder -83 83 84)
			("spawn_volume" args cylinder 83 -83 84)
		}
		{delay 90
			{hide 1}
		}
	}
}
{"shell_smoke_size3" ;// props from shell_smoke service entity; 105-122, 107-120mm mortar
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder" 
			{add_view "smoke_size3" "smoke1" "root"}
			{view start "smoke1"}
			{delay 81
				{view stop "smoke1"}
			}
			{delay 85 
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 110 0 84)
			("spawn_volume" args cylinder -110 0 84)
			("spawn_volume" args cylinder 0 110 84)
			("spawn_volume" args cylinder 0 -110 84)
			("spawn_volume" args cylinder 76 76 84)
			("spawn_volume" args cylinder -76 -76 84)
			("spawn_volume" args cylinder -76 76 84)
			("spawn_volume" args cylinder 76 -76 84)
		}
		{delay 90
			{hide 1}
		}
	}
}
{"shell_smoke_wp_size4" ;// props from shell_smoke service entity; 150-155mm
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder" 
			{add_view "smoke_wp_size4" "smoke1" "root"}
			{view start "smoke1"}
			{delay 81
				{view stop "smoke1"}
			}
			{delay 85 
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 160 0 84)
			("spawn_volume" args cylinder -160 0 84)
			("spawn_volume" args cylinder 0 160 84)
			("spawn_volume" args cylinder 0 -160 84)
			("spawn_volume" args cylinder 110 110 84)
			("spawn_volume" args cylinder -110 -110 84)
			("spawn_volume" args cylinder -110 110 84)
			("spawn_volume" args cylinder 110 -110 84)

			("spawn_volume" args cylinder 60 60 84)
			("spawn_volume" args cylinder -60 -60 84)
			("spawn_volume" args cylinder -60 60 84)
			("spawn_volume" args cylinder 60 -60 84)
		}
		{delay 90
			{hide 1}
		}
	}
}

{"shell_smoke_size4" ;// props from shell_smoke service entity; 150-155mm
	{on spawn
		{call "activate"}
	}
	{on "activate" overload
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{spawn "smoke_volume_cylinder"
			{add_view "smoke_size4" "smoke1" "root"}
			{view start "smoke1"}
			{delay 81
				{view stop "smoke1"}
			}
			{delay 85
				{hide 1}
			}
		}
		{delay 2
			("spawn_volume" args cylinder 150 0 84)
			("spawn_volume" args cylinder -150 0 84)
			("spawn_volume" args cylinder 0 150 84)
			("spawn_volume" args cylinder 0 -150 84)
			("spawn_volume" args cylinder 104 104 84)
			("spawn_volume" args cylinder -104 -104 84)
			("spawn_volume" args cylinder -104 104 84)
			("spawn_volume" args cylinder 104 -104 84)

			("spawn_volume" args cylinder 50 50 84)
			("spawn_volume" args cylinder -50 -50 84)
			("spawn_volume" args cylinder -50 50 84)
			("spawn_volume" args cylinder 50 -50 84)
		}
		{delay 90
			{hide 1}
		}
	}
}
