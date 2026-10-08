{selector
	{type "tank_heavy"}	;// "unit tag" or "unit type" + "current main weapon tag"

	{group
		{ignore {class airborne}}                                    ;//ARM+
		{sort {class tank_heavy}}
		{sort {class tank_medium}}
		{sort {class tank_light}}
		{sort {attacking}}
		{sort {threating}}
		{sort distance}
	}
	{group
		{select {class armoredcar}}
		{select {class armoredcar_l}}
		{sort {attacking}}
		{sort distance}
	}
	{group
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort distance}
	}
	{group
		{sort {weapon "rocketlauncher"} {attacking}}
		{sort {weapon "rocketlauncher"} {threating}}
		;{sort distance}
		{sort time_to_aim}
	}
	{group
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort distance}
	}
	{group
		{sort {weapon "at_rifle"} {attacking}}
		{sort {weapon "at_rifle"} {threating}}
		;{sort distance}
		{sort time_to_aim}
	}
	{group
		{sort {weapon "at_gr_rifle"} {attacking}}
		{sort {weapon "at_gr_rifle"} {threating}}
		;{sort distance}
		{sort time_to_aim}
	}
	;{group ; Added this                                                  ;//ARM-
	;	{select {class airborne}}
	;	{select {class cannon_bullet}}
	;	;{sort distance}
	;	{sort time_to_aim}
	;}
	{group
		{select {class car}}
		;{sort distance}
		{sort time_to_aim}
	}
	; {group
	; 	{sort {class cannon_bullet}}
	; 	{sort {class human} {weapon}}
	; 	{sort {class human}}
	; 	{sort distance}
	; }
	{group
		{sort {attacking}}
		;{sort distance}
		{sort time_to_aim}
	}
}
