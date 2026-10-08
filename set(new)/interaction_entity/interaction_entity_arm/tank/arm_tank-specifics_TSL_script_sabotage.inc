;/===================== ARm SCRIPT INJECTOR BEGIN: VAR 1 NO_TROPHY SABOTAGE INJECTOR to tank_main.inc

{on operatable on																	;//ARM START
	{if user_control
		{delay 1.5
			{if tagged "radio_car"
				{view start "beacon_fx"}
			}
		}          
	}

	{if tagged "no_trophy"
	else tagged "_bot"
;//		{if tagged "sabotage_possible"
;//		{if tagged "not_selectable"	
		{if user_control
			{if rand 1.0
				 ("sabotage_abandoned_tank" delay(0.1))
			else 
				{tags remove "no_trophy"}
			}
		}
;//		}
;//		}
	}

	{if tagged "not_selectable"
			{if user_control
				{damage_report "sabotage" "<s(20)b+c(#FF0000)>ARm: Mined!"}
				{clear_inventory}
				{call_synced "explosion"}
			}
	}
	
	{delay 1
		{if tagged "radio_car"
			{call "show_radio_icon"}
		}
	}
}	

;/===================== ARm SCRIPT INJECTOR END: VAR 1 NO_TROPHY SABOTAGE INJECTOR to tank_main.inc

