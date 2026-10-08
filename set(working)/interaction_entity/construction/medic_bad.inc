;/===================== ARm SCRIPT SWITCHER BEGIN: VAR 2 AUTO_MEDIC SWITCHER with arm_medic_script.inc

{"human"
    ; 0. Инициализация при спавне
    {on spawn
        {delay 1.0
            ; При спавне включаем медика, если он был выключен
            {if tagged "medic_ignored"
                {tags add "medic"}
                {tags remove "medic_ignored"}
            }
        }
    }

    ; 1. ПЕРЕКЛЮЧАТЕЛЬ medic_switch — СТАВИМ СЛУЖЕБНЫЙ ТЕГ
    {on "medic_switch"
        ; Вместо прямого изменения тегов — ставим служебный тег для основного скрипта
        {tags add "medic_switch_activate"}
    }

    ; 2. Переключатель medic_rally_switch
    {on "medic_rally_switch"
        ; ВЕТКА 1: АКТИВАЦИЯ (если не tagged "medic_rally_on")
        {if not tagged "medic_rally_on"
            ; Проверяем, что медик активен (не ignored) и не занят лечением
            {if not tagged "medic_ignored"
                {if not tagged "medic_working"
                    {tags add "medic_rally_on"}

            ; Проверяем движение к точке
            {if not tagged "moving_to_rally"
                {drop_orders}
            }

            ; Только устанавливаем тег — перемещение обработает основной скрипт
            {tags add "moving_to_rally"}
            {view start ally neutral "auto_medic_rally"}
        }
        }

        ; ВЕТКА 2: ДЕАКТИВАЦИЯ (если tagged "medic_rally_on")
        {if tagged "medic_rally_on"
            {tags remove "medic_rally_on"}
            {tags remove "moving_to_rally"}  ; снимаем тег движения при деактивации
            {view stop "auto_medic_rally"}
        }
    }
}

;/===================== ARm SCRIPT SWITCHER BEGIN: VAR 2 AUTO_MEDIC SWITCHER with arm_medic_script.inc

;/===================== ARm SCRIPT SWITCHER BEGIN: VAR 1 AUTO_MEDIC SWITCHER with arm_medic_script.inc

;//	{"human"											;150226
;//		{on "medic_switch"
;//			{if tagged "medic"
;//				{tags add "medic_ignored"}
;//				{tags remove "medic"}
;//				{drop_orders}
;//			      	{view stop "auto_medic"}
;//	;//		       {damage_report "medic_mode" "<s(10)b>OFF"}
;//			else tagged "medic_ignored"
;//				{tags add "medic"}
;//				{tags remove "medic_ignored"}
;//	            {view start ally neutral "auto_medic"}
;//	;//		       {damage_report "medic_mode" "<s(10)b+c(00FF00)>ON"}
;//			}
;//		}
;//	}

;//	{"human"
;//		{on "medic_rally_switch"
;//			{if not tagged "medic_rally_on"
;//				{tags add "medic_rally_on"}
;//				{if not tagged "moving_to_rally"}  ; проверка состояния				;240226
;//				{drop_orders}
;//				{view start ally neutral "auto_medic_rally"}
;//			else
;//				{tags remove "medic_rally_on"}
;//				{view stop "auto_medic_rally"}
;//			}
;//		}
};//	 

;//		(include "/set/interaction_entity/construction/interaction_entity_arm_construction/arm_medic_script.inc")				;// ARm SCRIPT INJECTOR BEGIN: VAR 1 AUTO_MEDIC LOOP SWITCHER INJECTOR

;/===================== ARm SCRIPT SWITCHER BEGIN: VAR 1 AUTO_MEDIC SWITCHER with arm_medic_script.inc