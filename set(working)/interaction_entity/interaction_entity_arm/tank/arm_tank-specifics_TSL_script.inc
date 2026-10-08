;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 15 NO_TROPHY BEGIN INJECTOR to tank_main.inc (work)
;//инициализация
{if tagged "no_trophy" 																							; Техника в списке TSL
	{log "DEBUG: TSL 1: Start calculation..."}																	; Логирование TSL - флаг старта	
    {if not tagged "_user" 																						; Техника не связана с игроком
	    {if not user_control																					; Если не под управлением игрока
;//	else tagged "_bot"																							; Техника связана с ботом
			{log "DEBUG: TSL 2: Vehicle is not by user_control. Start processing..."}							; Логирование TSL - есть в списке TSL	

			;//проверка 1
            {if tagged "open_top"																				; Проверка для техники с открытой башней (open_top)
				{log "DEBUG 3: Vehicle has open turret (open_top)"}
				{if not tagged "pre_cookoff_open_top" 															; Проверка на отсутствие тега сценария пожара с открытой башней
					;//запуск 1
					{if rand 1.00																				; Рандомайзер 100%
						{call "pre_cookoff_open_top"} 															; END: Вызов скрипта горения для техники с открытой башней
							{log "DEBUG 4: TSL: Open-top Script DONE"}											; Логирование TSL - запуск ликвидиации
								{tags remove "no_trophy"}														; Удаление тега no_trophy
					}
				}

			;//проверка 2	
			else not tagged "open_top"
				{log "DEBUG 3: TSL: Vehicle has closed turret (not open_top)"}									; Проверка для техники с закрытой башней (не open_top)
				{if not tagged "pre_cookoff" 																	; Проверка на отсутствие тега сценария пожара
					;//запуск 2
					{if rand 1.00																				; Рандомайзер 100%
						{call "pre_cookoff"} 																	; END: Вызов скрипта горения для техники с закрытой башней
							{log "DEBUG 4: TSL: Close-top Script DONE"}											; Логирование TSL - запуск ликвидиации
								{tags remove "no_trophy"}														; Удаление тега no_trophy
					}
				}
			}
		else user_control																						; Если под управлением игрока
		{log "DEBUG: TSL 0: Vehicle by user control, skipping TSL-pre_cookoff processing"}						; Логирование TSL
		}		
	else tagged "_user"																							; Если связана с игроком
		{log "DEBUG: TSL 0: Vehicle is linked to a user, skipping TSL-pre_cookoff processing"}					; Логирование TSL
	}		
}

;/===================== ARm SCRIPT INJECTOR END: VAR 15 NO_TROPHY BEGIN INJECTOR to tank_main.inc


;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 14 NO_TROPHY BEGIN INJECTOR to tank_main.inc (test)
;//-;//инициализация
;//-{if tagged "no_trophy" 																							; Техника в списке TSL
;//-;//	{log "DEBUG: TSL 1: Start calculation..."}																	; Логирование TSL - флаг старта	
;//-    {if not tagged "_user" 																						; Техника не связана с игроком
;//-	else tagged "_bot"																							; Техника связана с ботом
;//-;//		{log "DEBUG: TSL 2: Vehicle is linked to a bot. Start processing..."}									; Логирование TSL - есть в списке TSL	
;//-
;//-			;//проверка 1
;//-            {if tagged "open_top"																				; Проверка для техники с открытой башней (open_top)
;//-;//				{log "DEBUG 3: Vehicle has open turret (open_top)"}
;//-				{if not tagged "pre_cookoff_open_top" 															; Проверка на отсутствие тега сценария пожара с открытой башней
;//-					;//запуск 1
;//-					{if rand 1.00																				; Рандомайзер 100%
;//-						{call "pre_cookoff_open_top"} 															; END: Вызов скрипта горения для техники с открытой башней
;//-							{log "DEBUG 4: TSL: Open-top Script DONE"}											; Логирование TSL - запуск ликвидиации
;//-					}
;//-				}
;//-
;//-			;//проверка 2	
;//-			else not tagged "open_top"
;//-;//				{log "DEBUG 3: TSL: Vehicle has closed turret (not open_top)"}									; Проверка для техники с закрытой башней (не open_top)
;//-				{if not tagged "pre_cookoff" 																	; Проверка на отсутствие тега сценария пожара
;//-					;//запуск 2
;//-					{if rand 1.00																				; Рандомайзер 100%
;//-						{call "pre_cookoff"} 																	; END: Вызов скрипта горения для техники с закрытой башней
;//-;//							{log "DEBUG 4: TSL: Close-top Script DONE"}											; Логирование TSL - запуск ликвидиации
;//-					}
;//-				}
;//-			}
;//-
;//-;//	else tagged "_user"
;//-;//		{log "DEBUG: TSL 0: Vehicle is linked to a user, skipping TSL-pre_cookoff processing"}
;//-;//	else not tagged "_bot"
;//-;//		{log "DEBUG: TSL 0: Vehicle is not linked to bot, skipping TSL-pre_cookoff processing"}	
;//-	}		
;//-}

;/===================== ARm SCRIPT INJECTOR END: VAR 13 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 14 NO_TROPHY BEGIN INJECTOR to tank_main.inc (not work)
;//-;//инициализация
;//-{if tagged "no_trophy" 																							; Техника в списке TSL
;//-    {if not tagged "_user" 																						; Техника не связана с игроком
;//-;//     {if tagged "_bot" 																						; Техника связана с ботом
;//-            {log "DEBUG: TSL: Vehicle is linked to a bot. Start processing..."}								; Логирование TSL - есть в списке TSL
;//-			;//проверка 1
;//-            {if not tagged "open_top"																			; Проверка для техники с закрытой башней (не open_top)
;//-                {log "DEBUG: TSL: Vehicle has closed turret (not open_top)"}									; Проверка для техники с закрытой башней (не open_top)
;//-                {if not tagged "tag_pre_cookoff" 																; Проверка на отсутствие тега сценария пожара
;//-                    {log "DEBUG: tag_pre_cookoff not found, proceeding to pre_cookoff"}
;//-					;//проверка 1
;//-                    {if rand 0.99 ; Рандомайзер 99%
;//-						{call "pre_cookoff"} 																	; END: Вызов скрипта горения для техники с закрытой башней
;//-							{log "DEBUG: TSL: Script DONE"}
;//-					}
;//-				}
;//-			}	
;//-			;//проверка 2
;//-            {if tagged "open_top"																				; Проверка для техники с открытой башней (open_top)
;//-                {log "DEBUG: Vehicle has open turret (open_top)"}
;//-                {if not tagged "tag_pre_cookoff_open_top" 														; Проверка на отсутствие тега сценария пожара с открытой башней
;//-                    {log "DEBUG: tag_pre_cookoff_open_top not found, proceeding to pre_cookoff_open_top"}		; Дополнительная проверка на отсутствие уже ранее запущенного скрипта
;//-					;//запуск 2
;//-					{if rand 0.99 																						; Рандомайзер 99%
;//-						{call "pre_cookoff_open_top"} 																	; END: Вызов скрипта горения для техники с открытой башней
;//-						{log "DEBUG: TSL: Open-top Script DONE"}
;//-					}
;//-				}
;//-			}
;//-;//	    else
;//-;//			{log "DEBUG: TSL: Vehicle is not linked to a bot, skipping TSL-pre_cookoff processing"}	
;//-;//		}
;//-	else
;//-        {log "DEBUG: TSL: Vehicle is linked to a user or not linked to bot, skipping TSL-pre_cookoff processing"}
;//-	}
;//-}

;/===================== ARm SCRIPT INJECTOR END: VAR 13 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 13 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;//-{if tagged "no_trophy"											; Техника в списке TSL
;//-	{if not tagged "_user"										; Техника не связана с игроком
;//-	else tagged "_bot"											; Техника связана с ботом
;//-		{if not tagged "open_top"								; Проверка на отсутствующий тип техники с открытой башней
;//-			{if not tagged "tag_pre_cookoff"					; Проверка на отсутствие тега сценария пожара
;//-;//				{if rand 0.99									; Рандомайзер 99%
;//-					{call 
;//-						"pre_cookoff"							; Вызов скрипта горения для техники с закрытой башней
;//-					}
;//-;//				}
;//-			}	
;//-		}
;//-		
;//-		{if tagged "open_top"								; Проверка на тип техники с открытой башней
;//-			{if not tagged "tag_pre_cookoff_open_top"		; Проверка на отсутствие тега сценария пожара с открытой башней
;//-;//				{if rand 0.99								; Рандомайзер 99%
;//-					{call 
;//-						"pre_cookoff_open_top"				; Вызов скрипта горения для техники с открытой башней
;//-					}
;//-;//				}
;//-			}	
;//-		}
;//-	}
;//-}

;/===================== ARm SCRIPT INJECTOR END: VAR 13 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 13 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;//	{if tagged "no_trophy"											; Техника в списке TSL
;//		{if not tagged "_user"										; Техника не связана с игроком
;//		else tagged "_bot"											; Техника связана с ботом
;//			{if not tagged "tag_pre_cookoff"						; Проверка на отсутствие тега сценария пожара
;//				{if not tagged "open_top"							; Проверка на отсутствующий тип техники с открытой башней
;//					{if rand 0.9									; Рандомайзер 90%
;//						{call 
;//							"pre_cookoff"							; Вызов скрипта горения для техники с закрытой башней
;//						}
;//					}
;//				else
;//					{if not tagged "tag_pre_cookoff_open_top"		; Проверка на отсутствие тега сценария пожара с открытой башней
;//						{if rand 0.9								; Рандомайзер 90%
;//							{call 
;//								"pre_cookoff_open_top"				; Вызов скрипта горения для техники с открытой башней
;//							}
;//						}
;//					}	
;//				}
;//			}
;//		}
;//	}

;/===================== ARm SCRIPT INJECTOR END: VAR 13 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 13 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;//	{if tagged "no_trophy"									; Транспортное средство в списке TSL
;//		{if not tagged "_user"								; Транспортное средство связано с ботом
;//		else tagged "_bot"	
;//			{if rand 0.9									; Рандомайзер 90%
;//				{call 
;//					"pre_cookoff"							; Вызов скрипта горения
;//				}
;//			}
;//		}
;//	}

;/===================== ARm SCRIPT INJECTOR END: VAR 13 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 12 NO_TROPHY BEGIN INJECTOR to tank_main.inc
; not work
;//	{if tagged "no_trophy"									; Транспортное средство в списке TSL
;//		{if tagged "_bot"									; Транспортное средство связано с ботом
;//			{if rand 0.9									; Рандомайзер 90%
;//				{call 
;//					"pre_cookoff"							; Вызов скрипта горения
;//				}
;//			}
;//		}
;//	}

;/===================== ARm SCRIPT INJECTOR END: VAR 12 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 11 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;//	{if tagged "no_trophy"
;//	else tagged "_bot"	
;//		{if rand 0.9									;//TSU logic replacer
;//			{call 
;//				"pre_cookoff"
;//			}
;//		}	
;//	}

;/===================== ARm SCRIPT INJECTOR END: VAR 11 NO_TROPHY BEGIN INJECTOR to tank_main.inc

;/===================== VAR NO_TROPHY 10 BEGIN

;//	{if tagged "no_trophy"
;//	else tagged "_bot"	
;//		{if rand 0.9									;//TSU logic replacer
;//			{call 
;//				"pre_cookoff"
;//			}
;//					
;//		{delay 30.00
;//			{tags remove 
;//				"no_trophy"
;//			} 
;//		}	
;//		}	
;//	
;//		{tags add 										;//TSU logic replacer
;//			"no_scavenge"
;//		}	
;//		
;//		else tagged "_abandoned"						
;//			{tags add 										;//TSU logic replacer
;//				"no_scavenge"
;//			}
;//	}

;/===================== VAR NO_TROPHY 10 END

;/===================== VAR NO_TROPHY 9 BEGIN

;//	{if tagged "no_trophy"
;//	;// else not tagged "_user"	
;//	;//	else tagged "bot"
;//		else tagged "_bot"
;//		;	{if not user_control
;//			;	{tags add 										;//addon replacer
;//			;		"no_scavenge"
;//			;	}	
;//						
;//				{if rand 0.6									;//addon replacer
;//					{call 
;//						"pre_cookoff"
;//					}
;//						
;//					{delay 20.00
;//						{call 
;//							"explosion_extra"
;//						}
;//					}
;//				}
;//			;	{tags remove "no_scavenge"} 
;//				{tags remove "no_trophy"} 
;//		;	}	
;//	}

;/===================== VAR NO_TROPHY 9 END

;/===================== VAR NO_TROPHY 8 BEGIN

;//	{if tagged "no_trophy"
;//		else not tagged "_user"		
;//			{if rand 1.0									;//addon replacer
;//				{call "pre_cookoff"}
;//					{delay 20.00
;//						{call "explosion_extra"}
;//					}
;//			}
;//	}

;/===================== VAR NO_TROPHY 7 BEGIN Test
;//{"no_trophy"
;//	{on rand_break_body
;//		{if tagged "no_trophy"
;//			{if tagged "body_brake"
;//			else not tagged "exploded"
;//;//			else not tagged "burned"
;//				{if not tagged "_user"		
;//					{if rand 1.0									;//addon replacer
;//						{call "pre_cookoff"}
;//							{delay 20.00
;//								{call "explosion_extra"}
;//							}
;//						}
;//					}
;//				}
;//			}		
;//		}
;//	}
;//}

;/===================== VAR NO_TROPHY 7 END Test

;/===================== VAR NO_TROPHY 6 BEGIN Not work
;//{"no_trophy"
;//	{on "vehicle_destroyed"
;//		{if tagged "no_trophy"
;//			{if tagged "vehicle_destroyed"
;//;//			else not tagged "exploded"
;//;//			else not tagged "burned"
;//			else tagged "_user"		
;//				{if rand 1.0									;//addon replacer
;//					{call "pre_cookoff"}
;//					{delay 20.00
;//			;//			{call "explosion"}	
;//						{call "explosion_extra"}
;//					}
;//				}
;//			}	
;//		}
;//	}
;//}

;/===================== VAR NO_TROPHY 6 END Not work

;/===================== VAR NO_TROPHY 5 BEGIN

;//{"tank"
;//	{on break
;//		{if not tagged "burned"
;//			{if tagged "no_trophy"
;//				else tagged "body_brake"
;//				else not tagged "_user"			
;//					{if rand 1.0									;//addon replacer
;//						{call "pre_cookoff"}
;//							{delay 20.00
;//;//								{call "explosion"}	
;//								{call "explosion_extra"}
;//							}
;//					}							
;//			}
;//		}
;//	}
;//}

;/===================== VAR NO_TROPHY 5 END

;/===================== VAR no_trophy 4 BEGIN Not work CTD

;//	{"no_trophy"
;//		{on break
;//			{if not tagged "burned"
;//				{if tagged "no_trophy"
;//					else not tagged "_user"			
;//						{if rand 0.4
;//							{call "explosion"}					
;//						else rand 0.6	
;//							{if not tagged "explosion"
;//								else not tagged "explosion_extra"
;//									{call "pre_cookoff"}
;//							}
;//						else rand 0.9	
;//							{if not tagged "pre_cookoff"
;//								else not tagged "explosion"
;//									{call "explosion_extra"}
;//							}
;//						}
;//				}
;//			}
;//		}
;//	}

;/===================== VAR no_trophy 4 END Not work CTD

;/===================== VAR no_trophy 3 BEGIN

;//{"no_trophy"
;//	{on break
;//		{if not tagged "burned"
;//			{if tagged "no_trophy"
;//				else not tagged "_user"			
;//					{if rand 1.00
;//						{call "pre_cookoff"}
;//						{call "explosion"}
;//						{call "explosion_extra"}
;//					}
;//			}
;//		}
;//	}
;//}

;/===================== VAR no_trophy 3 END

;/===================== VAR no_trophy 2 BEGIN

;//{"no_trophy"
;//	{on break
;//		{if not tagged "burned"
;//			{if tagged "no_trophy"
;//				else not tagged "_user"			
;//	;//				{call "stat_break"}
;//					{call "pre_cookoff"}	
;//			}
;//		}	
;//	}
;//}

;/===================== VAR no_trophy 2 END

;/===================== VAR no_trophy 1 BEGIN 100% Not work

;//{"no_trophy"
;//	{on break
;//		{if not tagged "burned"
;//			{if tagged "no_trophy"
;//				else not tagged "_user"				
;//						;#1
;//						{if rand 0.33
;//							{if not tagged "explosion"
;//								else not tagged "explosion_extra"
;//									{call "pre_cookoff"}
;//							}
;//						}
;//						;#2
;//						else
;//						{if rand 0.33
;//							{if not tagged "pre_cookoff"
;//								else not tagged "explosion_extra"
;//									{call "explosion"}
;//							}
;//						}
;//						;#3
;//						else
;//						{if rand 0.33	
;//							{if not tagged "pre_cookoff"
;//								else not tagged "explosion"							
;//									{call "explosion_extra"}
;//							}
;//						}
;//			}
;//		}
;//	}
;//}

;/===================== VAR no_trophy 1 END

;/===================== VAR no_trophy 0 BEGIN
;//	{"no_trophy"
;//		{on "no_trophy"
;//			{if tagged "no_trophy"
;//				else tagged "bot"
;//				else tagged "_bot"			
;//	;//			else tagged "hull_destroyed"
;//	;//			else not tagged "exploded"		
;//	;//				{call "explosion"}
;//	;//				{tags add "vehicle_destroyed"}
;//				{tags add "no_scavenge"}			
;//	;//			{able select 0}
;//	;//			{able repaired 0}
;//	;//			{able minimap 0}
;//		}
;//}	

;/===================== VAR no_trophy 0 END

;/===================== VAR no_trophy -1 BEGIN

;//	{"no_trophy"
;//		{on break
;//			{if not tagged "exploded"
;//				{if tagged "no_trophy"
;//					else tagged "bot"
;//					or else tagged "_bot"						
;//						{tags add "ammo_broken"}
;//						{call "stat_break"}
;//						{call "explosion"}
;//						{call "explosion_extra"}
;//				}
;//			}
;//		}
;//	}

;/===================== VAR no_trophy -1 END


