; File: 		_dcg_script_air_attack_script_ext.inc
; Catalog: 		map\multi\_dcg_script
; Created by: 	Max Drechsler
; Created:		01.09.2026
; Modify by:	Max Drechsler
; Modify:		13.09.2026
; DSL 			GEM ENGINE 2 Gates of Hell
; Version:		2.4 (упрощённая: только спавн, без команд движения и возврата)
; Description: 	Дополнительный механизм авиации (только спавн, тег enemy_air)

		{## "call_ai_airstrike_on_player_ext_no"			{disabled}					; its bad version with _ce
;//			{condition
;//				{terms
;//					{"1.entities"
;//						{selector
;//							{source advanced}
;//							{ignore_captured_by_user 0}
;//							{group
;//								{include
;//									{prop {prop vehicle}}
;//									{state {state user_control}}
;//									{state {state operatable}}
;//								}
;//								{exclude
;//									{state {state inactive}}
;//									{prop {prop airborne}}
;//								}
;//							}
;//						}
;//					}
;//				}
;//			}
;//			{actions
;//				(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_air_attack_script_bot_airstrike_timer.inc")
;//
;//				; ===== БОЕВЫЕ САМОЛЁТЫ (только спавн) =====
;//				{"switch"
;//					{"case"
;//						{condition {type cmp_i} {var "tier2$"} {op "=="} {value 0}}
;//						{"if"
;//							{condition {type rand} {value 0.0}}																			; 0.25 - (1.00 test)
;//							{"actor_to_waypoint"
;//								{selector
;//									{source advanced}
;//									{ignore_captured_by_user 0}
;//									{group
;//										{include
;//											{tag {tag air_vehicle}}
;//											{tag {tag hidden}}
;//										}
;//										{exclude
;//											{tag {tag late_war}}
;//											{tag {tag nk_disabled}}
;//											{tag {tag enemy_paradrop_plane}}
;//										}
;//									}
;//									(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_air_attack_script_amount.inc")
;//								}
;//								{waypoint "0"}
;//								{clone}
;//								{approach "safe teleport & rotate"}
;//							}
;//							{"entity_state"
;//								{selector
;//									{source advanced}
;//									{ignore_captured_by_user 0}
;//									{group
;//										{include
;//											{tag {tag air_vehicle}}
;//											{tag {tag hidden}}
;//										}
;//										{exclude
;//											{tag {tag late_war}}
;//											{tag {tag nk_disabled}}
;//											{tag {tag enemy_paradrop_plane}}
;//										}
;//									}
;//								}
;//								{tag_add enemy_air}
;//							}
;//							; + ARM 110926 — активация клонов как боевых AI-самолётов
;//							{"delay" {time 0.5}}
;//							{"entity_state"
;//								{selector
;//									{source advanced}
;//									{ignore_captured_by_user 0}
;//									{group
;//										{select {tag {tag enemy_air}}}
;//										{include {prop {prop vehicle}}}
;//										{exclude
;//											{tag {tag enemy_paradrop_plane}}
;//											{tag {tag bomber_ce}}
;//											{tag {tag fighter}}
;//										}
;//									}
;//								}
;//								{tag_remove hidden}
;//								{tag_add nk_cbt_plane}
;//							}
;//							; + ARM 110926 — jet → fighter
;//							{"entity_state"
;//								{selector
;//									{source advanced}
;//									{ignore_captured_by_user 0}
;//									{group
;//										{select {tag {tag nk_cbt_plane}}}
;//										{include {tag {tag jet}}}
;//										{exclude {tag {tag fighter}}}
;//									}
;//								}
;//								{tag_add fighter}
;//								{tag_add fighter_ready}
;//							}
;//							; + ARM 110926 — остальные → bomber_ce
;//							{"entity_state"
;//								{selector
;//									{source advanced}
;//									{ignore_captured_by_user 0}
;//									{group
;//										{select {tag {tag nk_cbt_plane}}}
;//										{exclude {tag {tag fighter}} {tag {tag bomber_ce}}}
;//									}
;//								}
;//								{tag_add bomber_ce}
;//								{tag_add bomber_ce_ready}
;//							}
;//						}
;//					}
;//					{"default" ; tier2 == 1
;//						{"if"
;//							{condition {type rand} {value 0.0}}
;//							{"actor_to_waypoint"
;//								{selector
;//									{source advanced}
;//									{ignore_captured_by_user 0}
;//									{group
;//										{include
;//											{tag {tag air_vehicle}}
;//											{tag {tag hidden}}
;//										}
;//										{exclude
;//											{tag {tag early_war}}
;//											{tag {tag nk_disabled}}
;//											{tag {tag enemy_paradrop_plane}}
;//										}
;//									}
;//									(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_air_attack_script_amount.inc")
;//								}
;//								{waypoint "6"}
;//								{clone}
;//								{approach "safe teleport & rotate"}
;//							}
;//							{"entity_state"
;//								{selector
;//									{source advanced}
;//									{ignore_captured_by_user 0}
;//									{group
;//										{include
;//											{tag {tag air_vehicle}}
;//											{tag {tag hidden}}
;//										}
;//										{exclude
;//											{tag {tag early_war}}
;//											{tag {tag nk_disabled}}
;//											{tag {tag enemy_paradrop_plane}}
;//										}
;//									}
;//								}
;//								{tag_add enemy_air}
;//							}
;//							; + ARM 110926 — активация клонов как боевых AI-самолётов
;//							{"delay" {time 0.5}}
;//							{"entity_state"
;//								{selector
;//									{source advanced}
;//									{ignore_captured_by_user 0}
;//									{group
;//										{select {tag {tag enemy_air}}}
;//										{include {prop {prop vehicle}}}
;//										{exclude
;//											{tag {tag enemy_paradrop_plane}}
;//											{tag {tag bomber_ce}}
;//											{tag {tag fighter}}
;//										}
;//									}
;//								}
;//								{tag_remove hidden}
;//								{tag_add nk_cbt_plane}
;//							}
;//							; + ARM 110926 — jet → fighter
;//							{"entity_state"
;//								{selector
;//									{source advanced}
;//									{ignore_captured_by_user 0}
;//									{group
;//										{select {tag {tag nk_cbt_plane}}}
;//										{include {tag {tag jet}}}
;//										{exclude {tag {tag fighter}}}
;//									}
;//								}
;//								{tag_add fighter}
;//								{tag_add fighter_ready}
;//							}
;//							; + ARM 110926 — остальные → bomber_ce
;//							{"entity_state"
;//								{selector
;//									{source advanced}
;//									{ignore_captured_by_user 0}
;//									{group
;//										{select {tag {tag nk_cbt_plane}}}
;//										{exclude {tag {tag fighter}} {tag {tag bomber_ce}}}
;//									}
;//								}
;//								{tag_add bomber_ce}
;//								{tag_add bomber_ce_ready}
;//							}
;//						}
;//					}
;//				}
;//
;//				; ===== ТРАНСПОРТНЫЕ/ДЕСАНТНЫЕ САМОЛЁТЫ (только спавн) =====
;//				{"if"
;//					{condition {type rand} {value 0.0}}																; 0.30 - (1.00 test)
;//					{"switch"
;//						{"case"
;//						;	{condition {type cmp_i} {var "user_team$"} {op "=="} {value 1}}				; - 110926
;//							{condition {type cmp_i} {var "tier2$"} {op "=="} {value 1}}					; + 110926
;//							; + ARM 130926 — waypoint 0/6 50/50, внутри — amount 1/2 50/50
;//							{"if"
;//								{condition {type rand} {value 0.0}}
;//								{"if"
;//									{condition {type rand} {value 0.0}}
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag early_war}}
;//												}
;//											}
;//											{amount 2}
;//										}
;//										{waypoint "0"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//									{"entity_state"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag early_war}}
;//												}
;//											}
;//											{amount 2}
;//										}
;//										{tag_add enemy_air}
;//									}
;//								else
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag early_war}}
;//												}
;//											}
;//											{amount 1}
;//										}
;//										{waypoint "0"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//									{"entity_state"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag early_war}}
;//												}
;//											}
;//											{amount 1}
;//										}
;//										{tag_add enemy_air}
;//									}
;//								}
;//							else
;//								{"if"
;//									{condition {type rand} {value 0.0}}
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag early_war}}
;//												}
;//											}
;//											{amount 2}
;//										}
;//										{waypoint "6"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//									{"entity_state"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag early_war}}
;//												}
;//											}
;//											{amount 2}
;//										}
;//										{tag_add enemy_air}
;//									}
;//								else
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag early_war}}
;//												}
;//											}
;//											{amount 1}
;//										}
;//										{waypoint "6"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//									{"entity_state"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag early_war}}
;//												}
;//											}
;//											{amount 1}
;//										}
;//										{tag_add enemy_air}
;//									}
;//								}
;//							}
;//						}
;//						{"default" ; tier2$ != 1
;//							{"if"
;//								{condition {type rand} {value 0.0}}
;//								{"if"
;//									{condition {type rand} {value 0.0}}
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag late_war}}
;//												}
;//											}
;//											{amount 2}
;//										}
;//										{waypoint "0"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//									{"entity_state"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag late_war}}
;//												}
;//											}
;//											{amount 2}
;//										}
;//										{tag_add enemy_air}
;//									}
;//								else
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag late_war}}
;//												}
;//											}
;//											{amount 1}
;//										}
;//										{waypoint "0"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//									{"entity_state"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag late_war}}
;//												}
;//											}
;//											{amount 1}
;//										}
;//										{tag_add enemy_air}
;//									}
;//								}
;//							else
;//								{"if"
;//									{condition {type rand} {value 0.0}}
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag late_war}}
;//												}
;//											}
;//											{amount 2}
;//										}
;//										{waypoint "6"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//									{"entity_state"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag late_war}}
;//												}
;//											}
;//											{amount 2}
;//										}
;//										{tag_add enemy_air}
;//									}
;//								else
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag late_war}}
;//												}
;//											}
;//											{amount 1}
;//										}
;//										{waypoint "6"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//									{"entity_state"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{include
;//													{tag {tag air_vehicle}}
;//													{tag {tag hidden}}
;//													{tag {tag enemy_paradrop_plane}}
;//												}
;//												{exclude
;//													{tag {tag nk_disabled}}
;//													{tag {tag late_war}}
;//												}
;//											}
;//											{amount 1}
;//										}
;//										{tag_add enemy_air}
;//									}
;//								}
;//							}
;//						}
;//					}
;//				}
;//
;//				{"delay" {time 0.1}}
;//				{"animate"
;//					{selector
;//						{source advanced}
;//						{ignore_captured_by_user 0}
;//						{group
;//							{include {tag {tag air_vehicle}}}
;//							{exclude {tag {tag hidden}}}
;//						}
;//					}
;//					{animation wheels}
;//					{speed 10}
;//				}
;//				{"delay" {time 5}}										; + ARm optimization core 070926
;//				{"trigger" {name "call_ai_airstrike_on_player_ext"}}
;//				{"sound" {name "world/alarm/sirene00"}}
;//				{"switch"
;//					{"case" {condition {type rand} {value 0.0}}
;//						{"talk"
;//							{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
;//							{text "mission/multi/nk_enemy_planes_attack_1"}
;//						}
;//					}
;//					{"case" {condition {type rand} {value 0.0}}
;//						{"talk"
;//							{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
;//							{text "mission/multi/nk_enemy_planes_attack_2"}
;//						}
;//					}
;//					{"default"
;//						{"talk"
;//							{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
;//							{text "mission/multi/nk_enemy_planes_attack_3"}
;//						}
;//					}
;//				}
;//				; ===== ВОЗВРАТ НА БАЗУ (удалён) =====
;//				; ===== УДАЛЕНИЕ (закомментировано) =====
;//				{## "delay" {time 30}}
;//				{## "delete"
;//					{selector
;//						{source advanced}
;//						{ignore_captured_by_user 0}
;//						{group
;//							{select {tag enemy_air}}
;//							{include {state {state operatable}}}
;//						}
;//					}
;//				}
;//			}
		}

		

		{"call_ai_airstrike_on_player_ext"
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
					; + ARM 130926 — гасим Ext после завершения миссии
					{"2.cmp_i"
						{var "dcg_on$"}
						{op ">"}
						{value 3}
					}
				}
			}
			{actions
				(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_air_attack_script_bot_airstrike_timer.inc")

				; - ARM 130926 backup — блок боевых самолётов отключён, оставлен только транспорт
				; ===== БОЕВЫЕ САМОЛЁТЫ (только спавн) =====
				;{"switch"
				;	{"case"
				;		{condition {type cmp_i} {var "tier2$"} {op "=="} {value 0}}
				;		{"if"
				;			{condition {type rand} {value 0.0}}
				;			{"actor_to_waypoint"
				;				{selector
				;					{source advanced}
				;					{ignore_captured_by_user 0}
				;					{group
				;						{include
				;							{tag {tag air_vehicle}}
				;							{tag {tag hidden}}
				;						}
				;						{exclude
				;							{tag {tag late_war}}
				;							{tag {tag nk_disabled}}
				;							{tag {tag enemy_paradrop_plane}}
				;						}
				;					}
				;					(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_air_attack_script_amount.inc")
				;				}
				;				{waypoint "0"}
				;				{clone}
				;				{approach "safe teleport & rotate"}
				;			}
				;			{"entity_state"
				;				{selector
				;					{source advanced}
				;					{ignore_captured_by_user 0}
				;					{group
				;						{include
				;							{tag {tag air_vehicle}}
				;							{tag {tag hidden}}
				;						}
				;						{exclude
				;							{tag {tag late_war}}
				;							{tag {tag nk_disabled}}
				;							{tag {tag enemy_paradrop_plane}}
				;						}
				;					}
				;				}
				;				{tag_add enemy_air}
				;			}
				;			; + ARM 110926 — активация клонов как боевых AI-самолётов
				;			{"delay" {time 0.5}}
				;			{"entity_state"
				;				{selector
				;					{source advanced}
				;					{ignore_captured_by_user 0}
				;					{group
				;						{select
				;							{tag {tag enemy_air}}
				;						}
				;						{include
				;							{prop {prop vehicle}}
				;						}
				;						{exclude
				;							{tag {tag enemy_paradrop_plane}}
				;							{tag {tag bomber_ce}}
				;							{tag {tag fighter}}
				;						}
				;					}
				;				}
				;				{tag_remove hidden}
				;				{tag_add nk_cbt_plane}
				;			}
				;			; + ARM 110926 — jet → fighter
				;			{"entity_state"
				;				{selector
				;					{source advanced}
				;					{ignore_captured_by_user 0}
				;					{group
				;						{select
				;							{tag {tag nk_cbt_plane}}
				;						}
				;						{include
				;							{tag {tag jet}}
				;						}
				;						{exclude
				;							{tag {tag fighter}}
				;						}
				;					}
				;				}
				;				{tag_add fighter}
				;				{tag_add fighter_ready}
				;			}
				;			; + ARM 110926 — остальные → bomber_ce
				;			{"entity_state"
				;				{selector
				;					{source advanced}
				;					{ignore_captured_by_user 0}
				;					{group
				;						{select
				;							{tag {tag nk_cbt_plane}}
				;						}
				;						{exclude
				;							{tag {tag fighter}}
				;							{tag {tag bomber_ce}}
				;						}
				;					}
				;				}
				;				{tag_add bomber_ce}
				;				{tag_add bomber_ce_ready}
				;			}
				;		}
				;	}
				;	{"default" ; tier2 == 1
				;		{"if"
				;			{condition {type rand} {value 0.0}}
				;			{"actor_to_waypoint"
				;				{selector
				;					{source advanced}
				;					{ignore_captured_by_user 0}
				;					{group
				;						{include
				;							{tag {tag air_vehicle}}
				;							{tag {tag hidden}}
				;						}
				;						{exclude
				;							{tag {tag early_war}}
				;							{tag {tag nk_disabled}}
				;							{tag {tag enemy_paradrop_plane}}
				;						}
				;					}
				;					(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_air_attack_script_amount.inc")
				;				}
				;				{waypoint "6"}
				;				{clone}
				;				{approach "safe teleport & rotate"}
				;			}
				;			{"entity_state"
				;				{selector
				;					{source advanced}
				;					{ignore_captured_by_user 0}
				;					{group
				;						{include
				;							{tag {tag air_vehicle}}
				;							{tag {tag hidden}}
				;						}
				;						{exclude
				;							{tag {tag early_war}}
				;							{tag {tag nk_disabled}}
				;							{tag {tag enemy_paradrop_plane}}
				;						}
				;					}
				;				}
				;				{tag_add enemy_air}
				;			}
				;			; + ARM 110926 — активация клонов как боевых AI-самолётов
				;			{"delay" {time 0.5}}
				;			{"entity_state"
				;				{selector
				;					{source advanced}
				;					{ignore_captured_by_user 0}
				;					{group
				;						{select
				;							{tag {tag enemy_air}}
				;						}
				;						{include
				;							{prop {prop vehicle}}
				;						}
				;						{exclude
				;							{tag {tag enemy_paradrop_plane}}
				;							{tag {tag bomber_ce}}
				;							{tag {tag fighter}}
				;						}
				;					}
				;				}
				;				{tag_remove hidden}
				;				{tag_add nk_cbt_plane}
				;			}
				;			; + ARM 110926 — jet → fighter
				;			{"entity_state"
				;				{selector
				;					{source advanced}
				;					{ignore_captured_by_user 0}
				;					{group
				;						{select
				;							{tag {tag nk_cbt_plane}}
				;						}
				;						{include
				;							{tag {tag jet}}
				;						}
				;						{exclude
				;							{tag {tag fighter}}
				;						}
				;					}
				;				}
				;				{tag_add fighter}
				;				{tag_add fighter_ready}
				;			}
				;			; + ARM 110926 — остальные → bomber_ce
				;			{"entity_state"
				;				{selector
				;					{source advanced}
				;					{ignore_captured_by_user 0}
				;					{group
				;						{select
				;							{tag {tag nk_cbt_plane}}
				;						}
				;						{exclude
				;							{tag {tag fighter}}
				;							{tag {tag bomber_ce}}
				;						}
				;					}
				;				}
				;				{tag_add bomber_ce}
				;				{tag_add bomber_ce_ready}
				;			}
				;		}
				;	}
				;}

				; ===== ТРАНСПОРТНЫЕ/ДЕСАНТНЫЕ САМОЛЁТЫ (только спавн) =====
				; + ARM 120926 — общий шанс 30%, внутри: 50/50 waypoint (0 или 6), 50/50 количество (1 или 2)
				{"if"
					{condition {type rand} 
						;	{value 0.0}																												; this is ; for inc replacer. its must be activated for tests only!
							(include "/map/multi/_dcg_script/_dcg_script_air_attack_script_ext/_dcg_script_air_attack_script_ext_chance.inc")		; inc replacer has 0.35 = {value 0.35}	; dont delete!
					}														; !!! 0.30
					{"switch"
						{"case"
							; + ARM 120926 — waypoint 0 (50%)
							{condition {type rand} {value 0.0}}
							{"switch"
								{"case"
									; + ARM 120926 — 2 planes (50%)
									{condition {type rand} {value 0.0}}
									{"switch"
										{"case" ; b_operation_day >= 29
											{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 57}}
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag late_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{waypoint "0"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag late_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{tag_add enemy_air}
											}
										}
										{"case"
											{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 29}}
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag mid_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{waypoint "0"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag mid_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{tag_add enemy_air}
											}
										}
										{"default"
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag early_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{waypoint "0"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag early_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{tag_add enemy_air}
											}
										}
									}
								}
								{"default"
									; + ARM 120926 — 1 plane (50%)
									{"switch"
										{"case" ; b_operation_day >= 29
											{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 57}}
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag late_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{waypoint "0"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag late_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{tag_add enemy_air}
											}
										}
										{"case"
											{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 29}}
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag mid_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{waypoint "0"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag mid_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{tag_add enemy_air}
											}
										}
										{"default"
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag early_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{waypoint "0"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag early_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{tag_add enemy_air}
											}
										}
									}
								}
							}
						}
						{"default"
							; + ARM 120926 — waypoint 6 (50%)
							{"switch"
								{"case"
									; + ARM 120926 — 2 planes (50%)
									{condition {type rand} {value 0.0}}
									{"switch"
										{"case" ; b_operation_day >= 29
											{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 57}}
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag late_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{waypoint "6"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag late_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{tag_add enemy_air}
											}
										}
										{"case"
											{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 29}}
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag mid_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{waypoint "6"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag mid_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{tag_add enemy_air}
											}
										}
										{"default"
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag early_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{waypoint "6"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag early_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 2}
												}
												{tag_add enemy_air}
											}
										}
									}
								}
								{"default"
									; + ARM 120926 — 1 plane (50%)
									{"switch"
										{"case" ; b_operation_day >= 29
											{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 57}}
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag late_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{waypoint "6"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag late_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{tag_add enemy_air}
											}
										}
										{"case"
											{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 29}}
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag mid_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{waypoint "6"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag mid_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{tag_add enemy_air}
											}
										}
										{"default"
											{"actor_to_waypoint"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag early_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{waypoint "6"}
												{clone}
												{approach "safe teleport & rotate"}
											}
											{"entity_state"
												{selector
													{source advanced}
													{ignore_captured_by_user 0}
													{group
														{include
															{tag {tag air_vehicle}}
															{tag {tag hidden}}
															{tag {tag early_war}}
															{tag {tag enemy_paradrop_plane}}
														}
														{exclude 
															{tag {tag nk_disabled}}
														}
													}
													{amount 1}
												}
												{tag_add enemy_air}
											}
										}
									}
								}
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
				{"delay" {time 5}}										; + ARm optimization core 070926
				{"trigger" {name "call_ai_airstrike_on_player_ext"}}
				{"sound" {name "world/alarm/sirene00"}}
				{"switch"
					{"case" {condition {type rand} {value 0.0}}
						{"talk"
							{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
							{text "mission/multi/nk_enemy_drop_planes_attack_1"}
						}
					}
					{"case" {condition {type rand} {value 0.0}}
						{"talk"
							{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
							{text "mission/multi/nk_enemy_drop_planes_attack_2"}
						}
					}
					{"default"
						{"talk"
							{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
							{text "mission/multi/nk_enemy_drop_planes_attack_3"}
						}
					}
				}
				; ===== ВОЗВРАТ НА БАЗУ (удалён) =====
				; ===== УДАЛЕНИЕ (закомментировано) =====
				{## "delay" {time 30}}
				{## "delete"
					{selector
						{source advanced}
						{ignore_captured_by_user 0}
						{group
							{select {tag enemy_air}}
							{include {state {state operatable}}}
						}
					}
				}
			}
		}