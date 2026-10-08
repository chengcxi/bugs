{selector
	{unit "human" "rocketlauncher"}	;// "unit tag" or "unit type" + "current main weapon tag"

	{group	;// priority of vehicles to attack assuming more than one is in weapon's range
		{ignore {class airborne}}		;290126
		{sort {class tank_heavy}}
		{sort {class tank_medium}}
		{sort {class tank_light}}
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		{sort {class car_cannon}}
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort {class tank_bullet}}
		{sort {class car_bullet}}
		{sort {class cannon_bullet}}
;//		{sort {class airborne}}			;290126
		{sort {class car}}
		{sort {attacking}}
		{sort {class human} {in_range 35}}		;// humans that are vehicle crew are in this category
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort	{threating}}
		{sort	distance}
	}
}

{selector
	{unit "human" "at_rifle"}	;// (at_rifle = at rifles)

	{group																					;ARm 240226 +
		{select {class airborne}}															;ARm 240226 +
		{sort distance}
	}

	{group	;// priority of vehicles to attack assuming more than one is in weapon's range	
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		{sort {class car_cannon}}
		
		{sort {class tank_heavy}}
		{sort {class tank_medium}}
		{sort {class tank_light}}
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort {class tank_bullet}}
		{sort {class car_bullet}}
		{sort {class cannon_bullet}}
		{sort {class airborne}}
		{sort {class car}}
		{sort {attacking}}
		{sort {class human} {in_range 35}}		;// humans that are vehicle crew are in this category
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort	{threating}}
		{sort	distance}
	}
}

{selector
	{unit "human" "at_gr_rifle"}	;// (at_rifle = rifle grenades)

	{group	;// priority of vehicles to attack assuming more than one is in weapon's range	
		{ignore {class airborne}}
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		{sort {class car_cannon}}
		
		{sort {class tank_heavy}}
		{sort {class tank_medium}}
		{sort {class tank_light}}
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort {class tank_bullet}}
		{sort {class car_bullet}}
		{sort {class cannon_bullet}}
;//		{sort {class airborne}}
		{sort {class car}}
		{sort {attacking}}
		{sort {class human} {in_range 35}}		;// humans that are vehicle crew are in this category
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort	{threating}}
		{sort	distance}
	}
}

{selector
	{unit "human" "ap"}	;// (ap = molotov grenades, AT grenade launchers, Rocketlaunchers, AT rifles)

	{group	;// priority of vehicles to attack assuming more than one is in weapon's range
		{sort {class tank_heavy}}
		{sort {class tank_medium}}
		{sort {class tank_light}}
		{sort {class armoredcar}}
		{sort {class armoredcar_l}}
		{sort {class car_cannon}}
		{sort {class howitzer}}
		{sort {class cannon_big}}
		{sort {class cannon_small}}
		{sort {class cannon_zenite}}
		{sort {class tank_bullet}}
		{sort {class car_bullet}}
		{sort {class cannon_bullet}}
;//		{sort {class airborne}}
		{sort {class car}}
		{sort {attacking}}
		{sort {class human} {in_range 35}}		;// humans that are vehicle crew are in this category
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort	{threating}}
		{sort	distance}
	}
}