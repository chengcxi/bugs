{selector
	{type "airborne_bullet"}
	{group
		{select {class airborne}}
		{sort {class airborne}}
	}
	{group
		{select {class airborne}}
		{sort {class airborne}}
                                {sort {attacking}}                       
                                {sort {threating}}                     
	}
	{group															;150226+
		{select {class car}{in_range 200}}
		{select {class cannon}{in_range 200}}
		{sort {class car}{in_range 200}}
		{sort {class cannon}{in_range 200}}
	}																
	{group
		{select {class armoredcar}{in_range 200}}
		{select {class armoredcar_l}{in_range 200}}
		{select {class human}{in_range 200}}
		{sort {class armoredcar}{in_range 200}}
		{sort {class armoredcar_l}{in_range 200}}
		{sort {class human}{in_range 200}}
	}
	;{group
	;	{select {class human}{in_range 200}}
	;	{sort {class human}{in_range 200}}
	;}
	{group
		{select {class tank_bullet}{in_range 200}}
		{select {class tank_light}{in_range 200}}
		{select {class human}{in_range 200}}
		{sort {class tank_bullet}{in_range 200}}
		{sort {class tank_light}{in_range 200}}
		{sort {class human}{in_range 200}}
	}
;//	{group															;150226-
;//		{select {class car}{in_range 200}}
;//		{select {class cannon}{in_range 200}}
;//		{sort {class car}{in_range 200}}
;//		{sort {class cannon}{in_range 200}}
;//	}																
	{group
		{select {class tank_medium}{in_range 200}}
		{select {class tank_heavy}{in_range 200}}
		{select {class human}{in_range 200}}
		{sort {class tank_medium}{in_range 200}}
		{sort {class tank_heavy}{in_range 200}}
		{sort {class human}{in_range 200}}
	}
    {group
        {sort {attacking}}
        {sort distance}
    }
    {group
        {sort distance}                     
    }
}
