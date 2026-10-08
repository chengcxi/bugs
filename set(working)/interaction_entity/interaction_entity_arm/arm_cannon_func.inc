;/===================== SCRIPT ANOTHER

{"mortar cannon" 
	{on "construction_sandbag_cannon_standard" overload
		{call "random_small_sandbag_ring"}
	}

	{on "construction_sandbag_cannon_shallow" overload
		{call "random_small_sandbag_ring"}
	}
}

{"mortar_pit_emplacement"
    {on spawn
        {delay 5.1
            {spawn "trench_dirt_mortar_engineer" offset 50 0 0}
        }
    }
}

{"flak_ring_aa"
    {on spawn
        {delay 0.2
            {physics_work 0}
            {volumes disable contact}
            {delay 0.1
                {spawn "flak_ring" offset 0 0 -10} 
            }
        }
    }
}