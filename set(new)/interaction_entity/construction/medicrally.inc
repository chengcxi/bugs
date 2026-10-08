{"human"
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