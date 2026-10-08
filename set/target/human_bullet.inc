{selector
	{unit "human" "bullet"}	;// "unit tag" or "unit type" + "current main weapon tag"

    ;//================ I
    ;// Первоочередная задача: угроза возникновения чрезвычайной ситуации на близком расстоянии
    {group
;//     {ignore {class airborne}}
        {sort {threating}{in_range 19}}                       
        {sort {attacking}{in_range 19}}                        

        {sort distance}
    }

    ;//================ II
    ;// Второй приоритет: угроза применения бронетехники ближнего радиуса действия
    {group
;//     {ignore {class airborne}}
        {sort {class tank_heavy} {in_range 60}} 
        {sort {class tank_medium} {in_range 60}}  
        {sort {class tank_light} {in_range 60}}   
        {sort {class armoredcar} {in_range 60}}   
        {sort {class armoredcar_l} {in_range 60}} 
        {sort {class car} {in_range 60}}          
    }

    ;//================ III
    ;// Третий приоритет: угроза для пехоты средней дальности
    {group
;//     {ignore {class airborne}}
        {sort {class human} {in_range 55}}      
        {sort {class human} {weapon "bullet"}}  
        {sort {class human} {weapon}}          
    }
    
    ;//================ IV
    ;// Четвертый приоритет: пехота и обычные цели
    {group
;//     {ignore {class airborne}}
        {sort {class human}}                    
        {sort {threating}}                       
        {sort distance}                          
    }

    ;//================ V
    ; Пятый приоритет: Воздушная цель (обычно игнорируется, но возможны варианты)
	{group
		{select {class airborne}{in_range 200}}
		{sort {class airborne}{in_range 200}}
	}

    ;//================ VI
    ;// Шестой приоритет: Остальные цели
    {group
        {sort {attacking}}                       
        {sort {threating}}                       
        {sort distance}                      
    }
    {group
        {sort distance}
    }
}






   ; Предыдущие настройки приоритетов
;//	{group ;// humans
;//		;{ignore	{class airborne}}
;//		{sort {class airborne}}
		
;//		;// prioritize vehicles instead of humans if both are within 50m
;//		{sort {class tank_heavy} {in_range 50}}
;//		{sort {class tank_medium} {in_range 50}}
;//		{sort {class tank_light} {in_range 50}}
;//		{sort {class armoredcar} {in_range 50}}
;//		{sort {class armoredcar_l} {in_range 50}}
;//		{sort {class car_cannon} {in_range 50}}
;//		{sort {class tank_bullet} {in_range 50}}
;//		{sort {class car_bullet} {in_range 50}}

;//		{sort	{in_range 10}}
;//		{sort	{attacking}}
;//		{sort	{class human} {weapon "grenade"} {in_range 40}}
;//		{sort	{class human} {in_range 35}}		;// humans that are vehicle crew are in this category

;//		{sort	{class human} {weapon "bullet"}}
;//		{sort	{class human} {weapon}}
;//		{sort	{class human}}

;//		{sort {class howitzer}}
;//		{sort {class cannon_big}}
;//		{sort {class cannon_small}}
;//		{sort {class cannon_zenite}}
;//		{sort {class cannon_bullet}}
;//		{sort {class car}}

;//		{sort	{threating}}
;//		{sort	distance}
;//	}
;//}