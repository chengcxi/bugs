{selector
	{type "cannon_searchlight_zenite"}	;// "unit tag" or "unit type" + "current main weapon tag"

	{group
		{select {class airborne}}
		{sort distance}
	}

	{group	
		{select {class howitzer}}
		{sort distance}
	}
	
	{group	
		{select {class cannon_zenite}}
		{sort distance}
	}
	
	{group	
		{sort {class cannon_big}}
		{sort distance}
	}
	
	{group	
		{sort {class cannon_bullet}}
		{sort distance}
	}
	
	{group	
		{select {class cannon_small}}
		{sort distance}
	}
	
	{group	
		{select {class tank_heavy}}
		{sort distance}
	}

	{group	
		{select {class tank_medium}}
		{sort distance}
	}

	{group	
		{select {class tank_light}}
		{sort distance}
	}	
	
	{group
		{select {class armoredcar}}
		{select {class armoredcar_l}}
		{sort distance}
	}
	
	{group	
		{ignore {class human} {weapon}}
		{ignore {class human}}
		{sort distance}
	}
	
;//	{group
;//		{sort distance}
;//	}
}
