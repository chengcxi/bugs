;created by Nikral晓杉同学
;modify by MaxDrechsler

;===================== ARm SCRIPT AUTO MEDIC AND MEDIC RALLY SWITCHER BEGIN: VAR 1 WORKING with MAIN script medic.inc
;medic.inc

{"human"
	; 1. Инициализация при спавне
	{on spawn
		{delay 1.0
			; Включаем медика, если он был выключен
			{if tagged "medic_ignored"
				{delay 0.5
					{tags add "medic"}
					{tags remove "medic_ignored"}
					{view start ally neutral "auto_medic"}
				}
			}

			; 2. Автоматический цикл: каждые 30 секунд отключаем/включаем медика
			; Расположен ВНУТРИ {on spawn}, после инициализации
			{delay 30.0
				; Отключаем на 0.2 с
				{if tagged "medic"
					{tags add "medic_ignored"}
					{tags remove "medic"}
					{drop_orders}
					{view stop "auto_medic"}
				}
				{delay 0.2}

				; Включаем обратно
				{if tagged "medic_ignored"
					{tags add "medic"}
					{tags remove "medic_ignored"}
					{view start ally neutral "auto_medic"}
				}
				{delay 0.4}  ; Общая пауза ~30.6 с между циклами
			}
		}
	}

	{on "medic_switch"
		{if tagged "medic"
			{tags add "medic_ignored"}
			{tags remove "medic"}
			{drop_orders}
		      	{view stop "auto_medic"}
		else tagged "medic_ignored"
			{tags add "medic"}
			{tags remove "medic_ignored"}
	           {view start ally neutral "auto_medic"}
		}
	}
	
;//	{on "medic_rally_switch"
;//		{if not tagged "medic_rally_on"
;//			{tags add "medic_rally_on"}
;//			{drop_orders}
;//			{view start ally neutral "auto_medic_rally"}
;//		else
;//			{tags remove "medic_rally_on"}
;//			{view stop "auto_medic_rally"}
;//		}
;//	}

}

;===================== ARm SCRIPT AUTO MEDIC AND MEDIC RALLY SWITCHER END: VAR 1 WORKING with MAIN script medic.inc
