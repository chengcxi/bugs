{selector
	{type "rocket"}

	{group
		{ignore {class airborne}}
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		; {sort distance}
		{sort time_to_aim}
	}
	{group
		{select {class armoredcar}}
		{select {class armoredcar_l}}
		{sort {attacking}}
		;{sort distance}
		{sort time_to_aim}
	}
	{group
		{sort {class tank_light}}
		{sort {class tank_medium}}
		{sort {class tank_heavy}}
		{sort {class cannon_bullet}}
		{sort {class car}}
		{sort {attacking}}
		{sort {threating}}
		;{sort distance}
		{sort time_to_aim}
	}
	{group
		{sort {attacking}}
		;{sort distance}
		{sort time_to_aim}
	}
}
