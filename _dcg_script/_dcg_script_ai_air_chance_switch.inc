; File: 		_dcg_script_ai_air_chance_switch.inc
; Catalog: 		map\multi\_dcg_script
; Created by: 	Max Drechsler
; Created:		10.07.2026
; Modify by:	Max Drechsler
; Modify:		13.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		1.1
; Description: 	INC-injector for dcg_script.inc block dcg/ai_air_chance : ITS STANDART SETTINGS

;// ARm LAir replacer START [-->
					{"switch"
						{"case"
							{condition
								{type rand}
								{value 0.0}			;//ARm edit 0.0 - 0.0 (test - 0.0)
							}
							{"delay"
								(include "/map/multi/mace_scripts.inc")
								{time 9000000}				;//ARm edit 520-130-60 - 40
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.0}			;//ARm edit 0.0 (test - 0.0)
							}
							{"delay"
								{time 9000000}				;//ARm edit 1200-300-120
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.0}			;//ARm edit 0.0 (test - 0.0)
							}
							{"delay"
								{time 900000}				;//ARm edit 735-200-60
							}
						}
						{"case"
							{condition
								{type rand}
								{value 0.0}			;//ARm edit 0.0 (test - 0.0)
							}
							{"delay"	
								{time 9000000}				;//ARm edit 890-222-180
							}
						}
						{"default"
							{"delay"
								{time 900000}				;//ARm edit 930-232-120
							}
						}
					}
;// ARm LAir replacer END <--]
