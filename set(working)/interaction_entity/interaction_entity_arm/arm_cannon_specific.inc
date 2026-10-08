;;============================================== Cannons SPECIFIC ================================================

{"300mm_krh42" 
	{on spawn
        {delay 1
            {tags remove "artillery"}
            {tags remove "heavy_artillery"}
        }
    }
}

{"37mm_pstk36"
	{on "construction_sandbag_cannon_standard" overload}
	{on "construction_sandbag_cannon_shallow" overload}
}


{"37mm_flak37"
	{on "construction_sandbag_cannon_standard" overload
		{call "sandbag_ring_heap_straight_short_no_piles"}
	}
}

{"40mm_m1"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"40mm_itk38b"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"50mm_kwk39_platform"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_small_sandbag_ring"}
	}
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

{"75mm_itk37_bot"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"76mm_m1938"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"76mm_itk31"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"85mm_52k"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"88mm_flak18"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"88mm_flak18_bot"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"85mm_52k_bot"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"88mm_flak36"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"105mm_flak38"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}

{"90mm_m1a1"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}		
	}
}



;//{"mg34_lafette"
;//	{on "construction_sandbag_cannon_small" overload
;//		{call "soldier_foxhole_deep"}		
;//	}
;//}

;//{"mg42_lafette"
;//	{on "construction_sandbag_cannon_small" overload
;//		{call "soldier_foxhole_deep"}		
;//	}
;//}

;//{"mg131_lafette"
;//	{on "construction_sandbag_cannon_small" overload
;//		{call "soldier_foxhole_deep"}		
;//	}
;//}

;//{"kpv_1944"
;//	{on "construction_sandbag_cannon_small" overload
;//		{call "soldier_foxhole_deep"}		
;//	}
;//	
;//	{on "construction_sandbag_cannon_shallow" overload
;//		{call "soldier_foxhole_deep"}
;//	}
;//}

{"dshk_aa" 
	{on "construction_sandbag_cannon_standard" overload
		{call "random_small_sandbag_ring"}
	}

	{on "construction_sandbag_cannon_shallow" overload
		{call "random_small_sandbag_ring"}
	}
}

{"150mm_sw34" 
	{on "construction_sandbag_cannon_standard" overload
		{call "random_small_sandbag_ring"}
	}
	
	{on "construction_sandbag_cannon_shallow" overload
		{call "random_small_sandbag_ring"}
	}
}

{"150mm_sw34_ger" 
	{on "construction_sandbag_cannon_standard" overload
		{call "random_small_sandbag_ring"}
	}
	
	{on "construction_sandbag_cannon_shallow" overload
		{call "random_small_sandbag_ring"}
	}
}

{"150mm_sw34_stand" 
	{on "construction_sandbag_cannon_standard" overload
		{call "random_small_sandbag_ring"}
	}
	
	{on "construction_sandbag_cannon_shallow" overload
		{call "random_small_sandbag_ring"}
	}
}

{"150mm_sw34" 
	{on "construction_sandbag_cannon_standard" overload
		{call "random_small_sandbag_ring"}
	}
	
	{on "construction_sandbag_cannon_shallow" overload
		{call "random_small_sandbag_ring"}
	}
}

{"ZP_3154B" 
	{on "construction_sandbag_cannon_standard" overload
		{call "random_small_sandbag_ring"}
	}
	
	{on "construction_sandbag_cannon_shallow" overload
		{call "random_small_sandbag_ring"}
	}
}

{"pak_44"
	{on "construction_sandbag_cannon_standard" overload
		{call "random_medium_sandbag_ring"}
	}
}

{"flak38_stand" 
	{on "construction_sandbag_cannon_small" overload
		{call "random_small_sandbag_ring"}
	}

	{on "construction_sandbag_cannon_shallow" overload
		{call "random_small_sandbag_ring"}
	}
}

{"50cal_quad_m45" 
	{on "construction_sandbag_cannon_small" overload
		{call "random_small_sandbag_ring"}
	}

	{on "construction_sandbag_cannon_shallow" overload
		{call "random_small_sandbag_ring"}
	}
}

{"v2_a4"
	{on break
		{if not tagged "exploded"
			{if component "rocket"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
		}
	}
	
	{on "explosion_extra"
		{blastwave c4 9 r0 4 r1 15 offset 0 0 25}
		{blastwave c4 1.3 r0 15 r1 25 offset 0 0 25}
		{spawn "train_die" "basis"}
	}

	{on "construction_sandbag_cannon_standard" overload
		{call "random_heavy_sandbag_ring"}
	}
	
	{on "construction_sandbag_cannon_shallow" overload
		{call "random_heavy_sandbag_ring"}
	}
}

{"heavy_mg_mg131_tripod"
	{on "construction_sandbag_cannon_shallow_ai" overload}			;// used by AI defense mg's in conquest. removes persistence from their sandbags
	{on "construction_sandbag_cannon_standard_ai" overload}			;// used by AI defense mg's in conquest. removes persistence from their sandbags
	{on "construction_sandbag_cannon_shallow" overload}
	{on "construction_sandbag_cannon_standard" overload}
}