
;/---------------------------------------------- me-262_a1_new
(define "me262_sound"
	{on "add_movement_sound" overload
		{link_sound "engine1_start"			"vehicle/airborne/me262/262_engine_start"}
		{link_sound "engine1_idle"			"vehicle/airborne/me262/262_engine_idle"}
		{link_sound "engine1_full"			"vehicle/airborne/me262/262_engine_full"}
		{link_sound "engine2_start"			"vehicle/airborne/me262/262_engine_start"}
		{link_sound "engine2_idle"			"vehicle/airborne/me262/262_engine_idle"}
		{link_sound "engine2_full"			"vehicle/airborne/me262/262_engine_full"}
		{link_sound "engine_accelerate"		"vehicle/airborne/me262/262_accelerate"}
		{link_sound "engine_decelerate"		"vehicle/airborne/me262/262_decelerate"}
		{link_sound "engine_stop"			"vehicle/airborne/me262/262_engine_stop"}
	}
)

(define "ju87_sound"
	{on "add_movement_sound" overload
		{link_sound "engine1_start"			"vehicle/airborne/P47/vehicle_airborne_P47_start"}
		{link_sound "engine1_idle"			"vehicle/airborne/P47/vehicle_airborne_P47_idle"}
		{link_sound "engine1_full"			"vehicle/airborne/P47/vehicle_airborne_P47_full"}
		{link_sound "engine_accelerate"		"vehicle/airborne/P47/vehicle_airborne_P47_accelerate"}
		{link_sound "engine_decelerate"		"vehicle/airborne/P47/vehicle_airborne_P47_decelerate"}
		{link_sound "engine_stop"			"vehicle/airborne/P47/vehicle_airborne_P47_stop"}
		{link_sound "gear_work"				"vehicle/airborne/bf109/109_landing_gear"}
;//		{link_sound "bkg_plane"				"vehicle/airborne/bkg/P47_bkg"}
		{link_sound "bkg_plane"				"vehicle/airborne/bkg/ju87_alarm"}
	}
)

(define "ju87g_sound"
	{on "add_movement_sound" overload
		{link_sound "engine1_start"			"vehicle/airborne/P47/vehicle_airborne_P47_start"}
		{link_sound "engine1_idle"			"vehicle/airborne/P47/vehicle_airborne_P47_idle"}
		{link_sound "engine1_full"			"vehicle/airborne/P47/vehicle_airborne_P47_full"}
		{link_sound "engine_accelerate"		"vehicle/airborne/P47/vehicle_airborne_P47_accelerate"}
		{link_sound "engine_decelerate"		"vehicle/airborne/P47/vehicle_airborne_P47_decelerate"}
		{link_sound "engine_stop"			"vehicle/airborne/P47/vehicle_airborne_P47_stop"}
		{link_sound "gear_work"				"vehicle/airborne/bf109/109_landing_gear"}
;//		{link_sound "bkg_plane"				"vehicle/airborne/bkg/P47_bkg"}
	}
)

(define "ju-52_sound"
;//	{on "add_movement_sound" overload
;//		{link_sound "engine1_start"			"vehicle/airborne/C47/vehicle_airborne_C47_start_01"}
;//		{link_sound "engine1_idle"			"vehicle/airborne/C47/vehicle_airborne_C47_idle_01"}
;//		{link_sound "engine1_full"			"vehicle/airborne/C47/vehicle_airborne_C47_full_01"}
;//		{link_sound "engine2_idle"			"vehicle/airborne/C47/vehicle_airborne_C47_idle_02"}
;//		{link_sound "engine2_start"			"vehicle/airborne/C47/vehicle_airborne_C47_start_02"}
;//		{link_sound "engine2_full"			"vehicle/airborne/C47/vehicle_airborne_C47_full_02"}
;//		{link_sound "engine_accelerate"			"vehicle/airborne/C47/vehicle_airborne_C47_accelerate"}
;//		{link_sound "engine_decelerate"			"vehicle/airborne/C47/vehicle_airborne_C47_decelerate"}
;//		{link_sound "engine_stop"			"vehicle/airborne/C47/vehicle_airborne_C47_stop"}
;//		{link_sound "gear_work"				"vehicle/airborne/bf109/109_landing_gear"}
;//		{link_sound "bkg_plane"				"vehicle/airborne/bkg/C47_bkg"}
;//	}
	
	{on "add_movement_sound" overload
		{link_sound "engine1_start"			"vehicle/airborne/bf109/109_engine_start"}
		{link_sound "engine1_idle"			"vehicle/airborne/bf109/109_engine_idle"}
		{link_sound "engine1_full"			"vehicle/airborne/bf109/109_engine_full"}
		{link_sound "engine2_start"			"vehicle/airborne/bf109/109_engine_start"}
		{link_sound "engine2_idle"			"vehicle/airborne/bf109/109_engine_idle"}
		{link_sound "engine2_full"			"vehicle/airborne/bf109/109_engine_full"}
		{link_sound "engine3_start"			"vehicle/airborne/bf109/109_engine_start"}
		{link_sound "engine3_idle"			"vehicle/airborne/bf109/109_engine_idle"}
		{link_sound "engine3_full"			"vehicle/airborne/bf109/109_engine_full"}
		{link_sound "engine_accelerate"		"vehicle/airborne/bf109/109_accelerate"}
		{link_sound "engine_decelerate"		"vehicle/airborne/bf109/109_decelerate"}
		{link_sound "engine_stop"			"vehicle/airborne/bf109/109_engine_stop"}
	}
	
)

(define "bf109_e4b_sound"
	{on "add_movement_sound" overload
		{link_sound "engine1_start"			"vehicle/airborne/Hawker_Hurricane/Hawker_Hurricane_Start"}
		{link_sound "engine1_idle"			"vehicle/airborne/Hawker_Hurricane/Hawker_Hurricane_Idle"}
		{link_sound "engine1_full"			"vehicle/airborne/Hawker_Hurricane/Hawker_Hurricane_Full"}
		{link_sound "engine_accelerate"		"vehicle/airborne/Hawker_Hurricane/Hawker_Hurricane_Accelerate"}
		{link_sound "engine_decelerate"		"vehicle/airborne/Hawker_Hurricane/Hawker_Hurricane_Decelerate"}
		{link_sound "engine_stop"			"vehicle/airborne/Hawker_Hurricane/Hawker_Hurricane_Stop"}
		{link_sound "gear_work"				"vehicle/airborne/bf109/109_landing_gear"}
		{link_sound "bkg_plane"				"vehicle/airborne/bkg/Hawker_Hurricane_bkg"}
	}
)