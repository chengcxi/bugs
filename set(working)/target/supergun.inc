{selector
	{type "supergun"}

	{group
		{ignore {class airborne}}
		{sort {class tank_heavy}}
		{sort {class tank_medium}}
		{sort {attacking}}
		;{sort distance}
		{sort time_to_aim}
	}
	{group
		{sort {class howitzer}}
		{sort {class cannon_big}}
		;{sort distance}
		{sort time_to_aim}
	}
	{group
		{select {class tank_light}}
		{select {class armoredcar}}
		{select {class armoredcar_l}}
		{sort {attacking}}
		{sort {threating}}
		;{sort distance}
		{sort time_to_aim}
	}
	{group
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort {class cannon_bullet}}
		{sort {class human} {weapon}}
		{sort {class human}}
		;{sort distance}
		{sort time_to_aim}
	}
	{group
		{sort {weapon "rocketlauncher"} {attacking}}
		{sort {weapon "rocketlauncher"} {threating}}
		;{sort distance}
		{sort time_to_aim}
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
	{group
		{select {class car}}
		;{sort distance}
		{sort time_to_aim}
	}
	{group
		{sort {attacking}}
		;{sort distance}
		{sort time_to_aim}
	}
}