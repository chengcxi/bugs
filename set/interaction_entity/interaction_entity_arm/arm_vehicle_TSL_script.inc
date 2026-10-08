;/===================== ARm SCRIPT BEGIN: VAR 3 TSL_NO_SCAVENGE / its work fine
{"vehicle"
	{on "leave_unit"																; Транспортное средство покинуто
;//		{if work "body"																; Кузов в рабочем состоянии					;откл
;//			{if operatable															; Транспортное средство работоспособно							
				{if tagged "no_trophy"												; Транспортное средство в списке TSL
;//					{if not tagged "_user"											; Транспортное средство не связано с игроком
;//					else tagged "_bot"
						{if not tagged "no_scavenge"								; Не помочен в дальнейшую утилизацию
							{tags add 												;//TSU logic replacer
								"no_scavenge"										; Пометка в дальнейшую утилизацию
							}
						}
;//					}		
				}
;//			}
;//		}
	}
}

;/===================== ARm SCRIPT END: VAR 3 TSL_NO_SCAVENGE / its work fine