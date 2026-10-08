;ARm edit
;08.12.2025

{selector
	{unit "human"}	;// "unit tag" or "unit type" + "current main weapon tag"

    ;//================ I
    ;// Первоочередная задача: угроза возникновения чрезвычайной ситуации на близком расстоянии
    {group
        {ignore {class airborne}}
        {sort {threating}{in_range 19}}                       
        {sort {attacking}{in_range 19}}                        
        {sort distance}
    }

    ;//================ II
    ;// Второй приоритет: Бронированные средства на средних и ближних дистанциях
    {group
        {sort {class tank_heavy} {in_range 60}}  ; ????
        {sort {class tank_medium} {in_range 60}} ; ????  
        {sort {class tank_light} {in_range 60}}  ; ????
        {sort {class armoredcar} {in_range 60}}   ; ???
        {sort {class armoredcar_l} {in_range 60}} ; ?????
        {sort {attacking}}                        ; ???????
        {sort {threating}}                        ; ???????
        {sort distance}
    }

    ;//================ III
    ;// Третий приоритет: транспортные средства средней дальности и тяжелое вооружение
    {group
        {sort {class tank_bullet} {in_range 80}} ; ??
        {sort {class car_bullet} {in_range 80}}  ; ????
        {sort {class car} {in_range 80}}         ; ????
        {sort {attacking}}                        ; ???????
        {sort {threating}}                        ; ???????
        {sort distance}
    }

    ;//================ IV
    ;//  Четвертый приоритет: пехота и обычные цели
    {group
        {sort {class human} {weapon "bullet"} {in_range 80}} ; ????
        {sort {class human} {weapon} {in_range 60}}         ; ???????
        {sort {class human} {in_range 50}}                  ; ????
        {sort {attacking}}                                  ; ???????
        {sort {threating}}                        ; ???????
        {sort distance}
    }

    ;//================ V
    ;// Пятый приоритет: Воздушная цель (обычно игнорируется, но возможны варианты)
	{group
		{select {class airborne}{in_range 100}}
;//			{sort {class airborne}{in_range 100}}			;290126	
			{sort {class airborne}}							;290126	
			{sort distance}
	}

    ;//================ VI
    ;// Шестой приоритет: Остальные цели

    {group
        {sort {attacking}}
        {sort {threating}}                        ; ???????
        {sort distance}
    }

    {group
        {sort distance}
    }
}
   ; Предыдущие настройки приоритетов
;//	{group
;//		{sort {in_range 12}}
;//		{sort {attacking}}
;//		
;//		{sort {class tank_heavy}}
;//		{sort {class tank_medium}}
;//		{sort {class tank_light}}
;//		{sort {class armoredcar}}
;//		{sort {class armoredcar_l}}
;//		{sort {class car_cannon}}
;//		{sort {class tank_bullet}}
;//		{sort {class car_bullet}}
;//		{sort {class car}}
;//		{sort {class airborne}}
;//
;//		{sort {class human} {weapon "bullet"}}
;//		{sort {class human} {weapon}}
;//		{sort {weapon}}
;//		{sort {class human}}
;//
;//		{sort {class howitzer}}
;//		{sort {class cannon_big}}
;//		{sort {class cannon_small}}
;//		{sort {class cannon_zenite}}
;//		{sort {class cannon_bullet}}
;//		
;//		{sort distance}
;//	}
;//	{group
;//		{sort distance}
;//	}
;//}