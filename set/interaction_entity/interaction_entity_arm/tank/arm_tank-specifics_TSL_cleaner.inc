;/===================== ARm SCRIPT BEGIN: VAR 1 TSL_tag_cleaned

{tank
	{on "vehicle_destroyed"
		{if tagged "no_trophy"
		else tagged "_bot"
			{delay 0.3
				{tags remove 
					"no_trophy"
				} 
			}
		}
	}	
}

;/===================== ARm SCRIPT END: VAR 1 TSL_tag_cleaned
