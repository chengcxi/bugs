; DSL GEM ENGINE 2 Gates of Hell
; File: 		_dcg_script_air_attack_script_ext.inc
; Catalog: 		map\multi\_dcg_script
; Created by: 	nikral
; Created:		15.08.2026
; Modify by:	Max Drechsler
; Modify:		31.08.2026
; Version:		6.4
; Description: 

;---------------------------------------------------------------------
; Модернизирован под war_stage$ (1 – ранняя, 2 – средняя, 3 – поздняя)
; Добавлено исключение enemy_paradrop_plane, чтобы десантные самолёты не участвовали
;---------------------------------------------------------------------

{"[nikral] call ai airstrike on player"
	{condition
		{terms
			{"1.entities"
				{selector
					{source advanced}
					{ignore_captured_by_user 0}
					{group
						{include
							{prop {prop vehicle}}
							{state {state user_control}}
							{state {state operatable}}
						}
						{exclude
							{state {state inactive}}
							{prop {prop airborne}}
						}
					}
				}
			}
		}
	}
	{actions
		{"objective_progress" {set 0} {add 0} {title "DEBUG: Extended airstrike II triggered"}}
		(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_air_attack_script_bot_airstrike_timer.inc")

		; ---- Исключаем самолёты без тегов стадии ----
;//		{"entity_state"
;//			{selector
;//				{source advanced}
;//				{ignore_captured_by_user 0}
;//				{group
;//					{include
;//						{tag {tag air_vehicle}}
;//						{tag {tag hidden}}
;//					}
;//					{exclude
;//						{tag {tag early_war}}
;//						{tag {tag mid_war}}
;//						{tag {tag late_war}}
;//					}
;//				}
;//			}
;//			{tag_add no_stage}
;//		}

		; ----- ВЫБОР САМОЛЁТОВ ПО СТАДИИ (war_stage$) -----
		{"switch"
			{"case"
				{condition {type cmp_i} {var "war_stage$"} {op "=="} {value 1}}
				{"if"
					{condition {type rand} {value 0.25}}
					{"air_attack"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{include
									{tag {tag air_vehicle}}
									{tag {tag hidden}}
									{tag {tag early_war}}
								}
								{exclude 
								;	{tag {tag nk_disabled}}
								;	{tag {tag jet}}
								;	{tag {tag no_stage}}
								;	{tag {tag enemy_paradrop_plane}}   ; <-- добавлено
								}
							}
							(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_air_attack_script_amount.inc")
						}
						{enemies
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{include
									{prop {prop vehicle}}
									{state {state operatable}}
									{state {state user_control}}
								}
								{exclude
									{state {state inactive}}
									{prop {prop airborne}}
								}
							}
							{amount 0}
							{sort {type shuffle}}
						}
						{clone}
						{attack_altitude 20}
					}
				}
			}
			{"case"
				{condition {type cmp_i} {var "war_stage$"} {op "=="} {value 2}}
				{"if"
					{condition {type rand} {value 0.25}}
					{"air_attack"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{include
									{tag {tag air_vehicle}}
									{tag {tag hidden}}
									{tag {tag mid_war}}
								}
								{exclude 
								;	{tag {tag nk_disabled}}
								;	{tag {tag jet}}
								;	{tag {tag no_stage}}
								;	{tag {tag enemy_paradrop_plane}}   ; <-- добавлено
								}
							}
							(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_air_attack_script_amount.inc")
						}
						{enemies
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{include
									{prop {prop vehicle}}
									{state {state operatable}}
									{state {state user_control}}
								}
								{exclude
									{state {state inactive}}
									{prop {prop airborne}}
								}
							}
							{amount 0}
							{sort {type shuffle}}
						}
						{clone}
						{attack_altitude 20}
					}
				}
			}
			{"default"   ; поздняя (war_stage$ == 3)
				{"if"
					{condition {type rand} {value 0.25}}
					{"air_attack"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{include
									{tag {tag air_vehicle}}
									{tag {tag hidden}}
									{tag {tag late_war}}
								}
								{exclude 
								;	{tag {tag nk_disabled}}
								;	{tag {tag no_stage}}
								;	{tag {tag enemy_paradrop_plane}}   ; <-- добавлено
								}
							}
							(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_air_attack_script_amount.inc")
						}
						{enemies
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{include
									{prop {prop vehicle}}
									{state {state operatable}}
									{state {state user_control}}
								}
								{exclude
									{state {state inactive}}
									{prop {prop airborne}}
								}
							}
							{amount 0}
							{sort {type shuffle}}
						}
						{clone}
						{attack_altitude 20}
					}
				}
			}
		}

		{"delay" {time 0.1}}
		{"animate"
			{selector
				{source advanced}
				{ignore_captured_by_user 0}
				{group
					{include {tag {tag air_vehicle}}}
					{exclude {tag {tag hidden}}}
				}
			}
			{animation wheels}
			{speed 10}
		}
		{"trigger"
			{name "[nikral] call ai airstrike on player"}
		}
		{"sound"
			{name "world/alarm/sirene00"}
		}
		{"switch"
			{"case"
				{condition {type rand} {value 0.33}}
				{"talk"
					{selector
						{ignore_captured_by_user 0}
						{amount 0}
						{tag player}
						{zone "combat"}
						{type human}
						{state "not dead"}
					}
					{text "mission/multi/nk_enemy_planes_attack_1"}
				}
			}
			{"case"
				{condition {type rand} {value 0.5}}
				{"talk"
					{selector
						{ignore_captured_by_user 0}
						{amount 0}
						{tag player}
						{zone "combat"}
						{type human}
						{state "not dead"}
					}
					{text "mission/multi/nk_enemy_planes_attack_2"}
				}
			}
			{"default"
				{"talk"
					{selector
						{ignore_captured_by_user 0}
						{amount 0}
						{tag player}
						{zone "combat"}
						{type human}
						{state "not dead"}
					}
					{text "mission/multi/nk_enemy_planes_attack_3"}
				}
			}
		}
	}
}