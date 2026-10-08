{selector
	{type "cannon_zenite"}
	
	{group
		{select {class airborne}}
		{sort distance}
	}
	{group
		{select {class armoredcar}}
		{select {class armoredcar_l}}
		{sort {threating}}
	}
	{group
		{select {class tank_light}}
		{sort {threating}}
	}
	{group
		{sort {class howitzer}}
		{sort {class cannon_zenite}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {threating}}
	}
	{group
		{sort {class tank_medium}}
		{sort {class tank_heavy}}
		{sort {class tank_bullet}}
		{sort {threating}}
	}
	{group
		{select {class car_bullet}}
		{sort {threating}}
	}
	{group
		{sort {class cannon_bullet}}
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort {threating}}
	}
	{group
		{select {class car}}
		{sort {threating}}
	}
}
