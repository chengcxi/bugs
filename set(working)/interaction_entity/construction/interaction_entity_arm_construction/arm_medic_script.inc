;arm_medic_script.inc

;===================== ARm SCRIPT AUTO MEDIC AND MEDIC RALLY SWITCHER BEGIN: VAR 3 WORKING with MAIN script medic.inc

{"human"													;150226
	{on spawn
;//------- block 1
		{delay 1.5	
			{if tagged "medic_ignored" 						;// OFF medic on spawn
				{delay 0.3
					{view stop "auto_medic"}				;// OFF when ON to ON
				}
			}
		}	
;//------- block 1a		
		{delay 1.8	
			{if tagged "medic_ignored" 						;// ON medic on spawn
				{delay 0.3				
					{tags add "medic"}
					{tags remove "medic_ignored"}
					{view start ally neutral "auto_medic"}	;// ON when OFF
				}
			}
		}		
;//------- block 3: автоматическое включение режима Rally при спавне (с очисткой перед запуском)
;//		{delay 2.5
;//			{if tagged "medic"
;//				{tags remove "medic_rally_on"}     ; очистка на всякий случай
;//				{view stop "auto_medic_rally"}    ; останавливаем, если был запущен
;//				{delay 0.1}
;//				{tags add "medic_rally_on"}
;//				{view start ally neutral "auto_medic_rally"}
;//			}
;//		}
;//------- block 2	
		{delay 30.0 "loop"
			{delay 0.3
				{if tagged "medic"							;// step 1	OFF medic if ON
					{delay 0.3
						{tags add "medic_ignored"}
						{tags remove "medic"}
						{drop_orders}
						{view stop "auto_medic"}
					}	
				}		
			}

			{delay 0.6	
				{if tagged "medic_ignored" 					;// step 2 ON medic if OFF
					{delay 0.6				
						{tags add "medic"}
						{tags remove "medic_ignored"}
						{view start ally neutral "auto_medic"}
					}
				}	
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
	
	{on "medic_rally_switch"
		{if not tagged "medic_rally_on"
			{tags add "medic_rally_on"}
			{drop_orders}
			{view start ally neutral "auto_medic_rally"}
		else
			{tags remove "medic_rally_on"}
			{view stop "auto_medic_rally"}
		}
	}
}
	
;===================== ARm SCRIPT AUTO MEDIC AND MEDIC RALLY SWITCHER BEGIN: VAR 3 WORKING with MAIN 


;===================== ARm SCRIPT AUTO MEDIC AND MEDIC RALLY SWITCHER BEGIN: VAR 2 WORKING with MAIN script medic.inc
;//
;//{"human"													;150226
;//	{on spawn
;//;//------- block 1
;//		{delay 0.5	
;//			{if tagged "medic_ignored" 						;// OFF medic on spawn
;//				{delay 0.1
;//					{view stop "auto_medic"}				;// OFF when ON to ON
;//				}
;//			}
;//		}	
;//;//------- block 1a		
;//		{delay 1.8	
;//			{if tagged "medic_ignored" 						;// ON medic on spawn
;//				{delay 0.3				
;//					{tags add "medic"}
;//					{tags remove "medic_ignored"}
;//					{view start ally neutral "auto_medic"}	;// ON when OFF
;//				}
;//			}
;//		}		
;//;//------- block 2	
;//		{delay 30.0 "loop"
;//			{delay 0.3
;//				{if tagged "medic"							;// step 1	OFF medic if ON
;//					{delay 0.3
;//						{tags add "medic_ignored"}
;//						{tags remove "medic"}
;//						{drop_orders}
;//						{view stop "auto_medic"}
;//					}	
;//				}		
;//			}
;//
;//			{delay 0.6	
;//				{if tagged "medic_ignored" 					;// step 2 ON medic if OFF
;//					{delay 0.6				
;//						{tags add "medic"}
;//						{tags remove "medic_ignored"}
;//						{view start ally neutral "auto_medic"}
;//					}
;//				}	
;//			}			
;//		}
;//	}
;//	
;//	{on "medic_switch"
;//		{if tagged "medic"
;//			{tags add "medic_ignored"}
;//			{tags remove "medic"}
;//			{drop_orders}
;//		      	{view stop "auto_medic"}
;//		else tagged "medic_ignored"
;//			{tags add "medic"}
;//			{tags remove "medic_ignored"}
;//	           {view start ally neutral "auto_medic"}
;//		}
;//	}
;//	
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
;//}
;//	
;===================== ARm SCRIPT AUTO MEDIC AND MEDIC RALLY SWITCHER BEGIN: VAR 2 WORKING with MAIN script medic.inc



;===================== ARm SCRIPT AUTO MEDIC AND MEDIC RALLY SWITCHER BEGIN: VAR 1 WORKING with MAIN script medic.inc
;medic.inc replacer

;//	{"human"
;//	    {on spawn														;// Инициализация: устанавливаем активное состояние при спавне
;//	    {delay 1.0
;//	            {if tagged "medic_ignored"
;//	                {delay 0.5
;//	                    {tags add "medic"}
;//						{tags remove "medic_ignored"}
;//						{view start ally neutral "auto_medic"}
;//					}
;//				}
;//	
;//				{delay 15.0 "loop"											;// Основной цикл переключения каждые 30 секунд
;//					{delay 0.2												;// Шаг 1: отключение медика, если активен
;//						{if tagged "medic"
;//							{tags add "medic_ignored"}
;//							{tags remove "medic"}
;//							{drop_orders}
;//							{view stop "auto_medic"}
;//						}
;//					}
;//	
;//					{delay 0.6												;// Шаг 2: включение медика, если неактивен (через 0.4 с после отключения)
;//						{if tagged "medic_ignored"
;//							{tags add "medic"}
;//							{tags remove "medic_ignored"}
;//							{view start ally neutral "auto_medic"}
;//						}
;//					}
;//				}
;//			}
;//		}
;//	
;//		{on "medic_switch"
;//			{if tagged "medic"
;//				{tags add "medic_ignored"}
;//				{tags remove "medic"}
;//				{drop_orders}
;//			      	{view stop "auto_medic"}
;//			else tagged "medic_ignored"
;//				{tags add "medic"}
;//				{tags remove "medic_ignored"}
;//		           {view start ally neutral "auto_medic"}
;//			}
;//		}
;//		
;//		{on "medic_rally_switch"
;//			{if not tagged "medic_rally_on"
;//				{tags add "medic_rally_on"}
;//				{drop_orders}
;//				{view start ally neutral "auto_medic_rally"}
;//			else
;//				{tags remove "medic_rally_on"}
;//				{view stop "auto_medic_rally"}
;//			}
;//		}
;//	}

;===================== ARm SCRIPT AUTO MEDIC AND MEDIC RALLY SWITCHER BEGIN: VAR 1 WORKING with MAIN script medic.inc


;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 3 AUTO_MEDIC LOOP SWITCHER INJECTOR to medic.inc

;//	{"human"													;150226
;//		{on spawn
;//	;//------- block 1
;//			{delay 1.5	
;//				{if tagged "medic_ignored" 						;// OFF medic on spawn
;//					{delay 0.3
;//						{view stop "auto_medic"}				;// OFF when ON to ON
;//					}
;//				}
;//			}	
;//	;//------- block 1a		
;//			{delay 1.8	
;//				{if tagged "medic_ignored" 						;// ON medic on spawn
;//					{delay 0.3				
;//						{tags add "medic"}
;//						{tags remove "medic_ignored"}
;//						{view start ally neutral "auto_medic"}	;// ON when OFF
;//					}
;//				}
;//			}		
;//	;//------- block 2	
;//			{delay 30.0 "loop"
;//				{delay 0.3
;//					{if tagged "medic"							;// step 1	OFF medic if ON
;//						{delay 0.3
;//							{tags add "medic_ignored"}
;//							{tags remove "medic"}
;//							{drop_orders}
;//							{view stop "auto_medic"}
;//						}	
;//					}		
;//				}
;//	
;//				{delay 0.6	
;//					{if tagged "medic_ignored" 					;// step 2 ON medic if OFF
;//						{delay 0.6				
;//							{tags add "medic"}
;//							{tags remove "medic_ignored"}
;//							{view start ally neutral "auto_medic"}
;//						}
;//					}	
;//				}			
;//			}
;//		}
;//	}
	
;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 3 AUTO_MEDIC LOOP SWITCHER INJECTOR to medic.inc

;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 2 AUTO_MEDIC LOOP SWITCHER INJECTOR to medic.inc

;//	{"human"											;150226
;//		{on spawn
;//	;//------- block 1
;//			{delay 1.5	
;//				{if tagged "medic_ignored" ;// ON medic on spawn
;//					{delay 0.6				
;//						{tags add "medic"}
;//						{tags remove "medic_ignored"}
;//						{view start ally neutral "auto_medic"}
;//					}
;//				}
;//			}	
;//	;//------- block 2	
;//			{delay 30.0 "loop"
;//				{delay 0.3
;//					{if tagged "medic"			;//var1	OFF medic if ON
;//						{delay 0.3
;//							{tags add "medic_ignored"}
;//							{tags remove "medic"}
;//							{drop_orders}
;//							{view stop "auto_medic"}
;//						}	
;//					}		
;//				}
;//	
;//				{delay 0.6	
;//					{if tagged "medic_ignored" ;//var2 ON medic if OFF
;//						{delay 0.6				
;//							{tags add "medic"}
;//							{tags remove "medic_ignored"}
;//							{view start ally neutral "auto_medic"}
;//						}
;//					}	
;//				}			
;//			}
;//		}
;//	}
	
;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 2 AUTO_MEDIC LOOP SWITCHER INJECTOR to medic.inc



;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 1 AUTO_MEDIC LOOP SWITCHER INJECTOR to medic.inc

;//	{"human"											;150226
;//		{on spawn
;//			{delay 30 "loop"	
;//				{delay 0.3
;//					{if tagged "medic"
;//						{tags add "medic_ignored"}
;//						{tags remove "medic"}
;//						{drop_orders}
;//							{view stop "auto_medic"}
;//					}		
;//				}
;//				{delay 0.7			
;//					{if tagged "medic_ignored"
;//						{tags add "medic"}
;//						{tags remove "medic_ignored"}
;//							{view start ally neutral "auto_medic"}
;//					}
;//				}
;//			}
;//		}
;//	}
	
;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 1 AUTO_MEDIC LOOP SWITCHER INJECTOR to medic.inc
