{"vehicle"
	{on "lights_switch"
		{if "engine_on"
			{if tagged "lightison"		
				{call "lights_off"}
				{tags remove "lightison"}
			else
				{call "lights_on"}
				{tags add "lightison"}
			}
		}
	}

;//	{on "wipers_switch"
;//		{if "engine_on"
;//			{if tagged "wiperison"
;//				{ani_stop "wipers"}
;//				{tags remove "wiperison"}
;//			else
;//				{ani_play "wipers" loop resume}
;//				{tags add "wiperison"}
;//			}
;//		}
;//	}
}