;created by Nikral晓杉同学
;modify by MaxDrechsler
{"human"
	{on "ai_control_switch"
		{if user_control
			{tags add "switch_to_ai"}
			{damage_report "ai_control_switch" "<s(10)b+c(00FF00)>ARm: AI ON"}
		else
			{tags add "switch_to_user"}
			{damage_report "ai_control_switch" "<s(10)b>ARm: AI OFF"}
		}
	}
	{on "weather_switch"
		{tags add "weather_switch"}
	}
}


{"vehicle"
	{on "ai_control_switch"
		{if user_control
			{tags add "switch_to_ai"}
			{damage_report "ai_control_switch" "<s(10)b+c(00FF00)>ARm: AI ON"}
		else
			{tags add "switch_to_user"}
			{damage_report "ai_control_switch" "<s(10)b>ARm: AI OFF"}
		}
	}
	{on "weather_switch"
		{tags add "weather_switch"}
	}
}

{"local"
	{on "weather_switch"
		{tags add "weather_switch"}
	}
}