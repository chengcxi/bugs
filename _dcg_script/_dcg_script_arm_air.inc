; File: 		_dcg_script_arm_air.inc
; Catalog: 		map\multi\_dcg_script
; Created by: 	Max Drechsler
; Created:		13.09.2026
; Modify by:	Max Drechsler
; Modify:		06.09.2026
; DSL 			GEM ENGINE 2 Gates of Hell
; Version:		2.6 (сборка из исходной + правки)
; Description: Основной механизм авиации (боевые без команд, транспортные с шансом 40%)

;-----------
			{"dcg/def_team"
				{condition
					{terms
						{"1.event" {id "dcg"}}
						{"2.cmp_i" {var "user_team$"} {op ">"} {value 0}}
						{"3.cmp_i" {var "enemyid$"} {op ">"} {value 0}}
					}
				}
				{actions
					{"delay" {time 0.5}}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "user_is_defender$"} {op "=="} {value 1}}
							{"delay" {time 0.1}}
							{"delete"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag {tag mine_planted}}
											{tag {tag dcg_mine_sign}}
										}
										{include {tag {tag cmp_def}}}
									}
								}
							}
						}
						{"default"}
					}
					{"delay" {time 0.5}}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag def_team_1}}}
										{include {zone {zone "gamezone"}}}
										{exclude
											{tag {tag def_team_2}}
											{state {state inactive}}
										}
									}
								}
							}
							{"delay" {time 0.1}}
							{"set_i" {var "def_team$"} {op "="} {value 1}}
							{"delay" {time 0.1}}
							{"delete"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag {tag mine_planted}}
											{tag {tag dcg_mine_sign}}
										}
										{include
											{tag {tag cmp_def}}
											{state {state inactive}}
										}
									}
								}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag def_team_2}}}
										{include {zone {zone "gamezone"}}}
										{exclude
											{tag {tag def_team_1}}
											{state {state inactive}}
										}
									}
								}
							}
							{"delay" {time 0.1}}
							{"set_i" {var "def_team$"} {op "="} {value 2}}
						}
						{"default"
							{"delay" {time 0.1}}
							{"set_i" {var "def_team$"} {op "="} {value "user_team$"}}
						}
					}
					{"delay" {time 1}}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag {tag "1_a_2-3"}}
											{tag {tag "2_a_2-3"}}
											{tag {tag "3_a_2-3"}}
											{tag {tag "4_a_2-3"}}
											{tag {tag "5_a_2-3"}}
										}
										{include {zone {zone "combat"}}}
										{exclude
											{tag {tag hidden}}
											{state {state inactive}}
										}
									}
								}
							}
							{"delay" {time 0.1}}
							{"set_i" {var "tier2$"} {op "="} {value 1}}
						}
						{"default"}
					}
					{"delay" {time 0.5}}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "tier2$"} {op "=="} {value 0}}
							{"delay" {time 0.1}}
							{"switch"
								{"case"
									{condition
										{type entities}
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag {tag "1_b_2-3"}}
													{tag {tag "2_b_2-3"}}
													{tag {tag "3_b_2-3"}}
													{tag {tag "4_b_2-3"}}
													{tag {tag "5_b_2-3"}}
												}
												{include {zone {zone "combat"}}}
												{exclude
													{tag {tag hidden}}
													{state {state inactive}}
												}
											}
										}
									}
									{"delay" {time 0.1}}
									{"set_i" {var "tier2$"} {op "="} {value 1}}
								}
								{"default"}
							}
						}
						{"default"}
					}
					{"delay" {time 0.9}}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "tier2$"} {op "=="} {value 1}}
						}
						{"default"
							{"delay" {time 0.1}}
							{"delete"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select
											{tag {tag mine_planted}}
											{tag {tag dcg_mine_sign}}
										}
										{include
											{tag {tag cmp_def}}
											{state {state inactive}}
										}
									}
								}
							}
						}
					}
					{"delay" {time 1}}
					{"delete"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select
									{tag {tag def_team_1}}
									{tag {tag def_team_2}}
								}
							}
						}
					}
				}
			}

			{## "dcg/ai_airstrike_bak"				{disabled}					; its work but without filtration GOH air
;//				{condition
;//					{terms
;//						{"1.event" {id "ai_air_on"}}
;//					}
;//				}
;//				{actions
;//					{"delay" {time 0.1}}
;//					{"entity_state" {selector {ignore_captured_by_user 0} {tag enemy_air}} {tag_remove enemy_air}}
;//					{"delay" {time 0.1}}
;//
;//					; ===== БОЕВЫЕ САМОЛЁТЫ =====
;//					{"switch"
;//						{"case"
;//							{condition {type cmp_i} {var "user_team$"} {op "=="} {value 1}}
;//							{"delay" {time 0.1}}
;//							{"switch"
;//								{"case"
;//									{condition {type cmp_i} {var "tier2$"} {op "=="} {value 1}}
;//									{"delay" {time 0.1}}
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{select
;//													{tag {tag airstrike_ger}}
;//													{tag {tag airstrike_rus}}
;//													{tag {tag airstrike_fin}}
;//													{tag {tag airstrike_usa}}
;//													{tag {tag airstrike_eng}}
;//													{tag {tag airstrike_jap}}
;//												}
;//												{include {tag {tag hidden}}}
;//												{exclude {tag {tag early_war}} {tag {tag disabled}}	{tag {tag enemy_paradrop_plane}}}   ; <-- исправлено
;//											}
;//											{amount 4}
;//										}
;//										{waypoint "0"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//								}
;//								{"default"
;//									{"delay" {time 0.1}}
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{select
;//													{tag {tag airstrike_ger}}
;//													{tag {tag airstrike_rus}}
;//													{tag {tag airstrike_fin}}
;//													{tag {tag airstrike_usa}}
;//													{tag {tag airstrike_eng}}
;//													{tag {tag airstrike_jap}}
;//												}
;//												{include {tag {tag hidden}}}
;//												{exclude {tag {tag late_war}} {tag {tag disabled}}	{tag {tag enemy_paradrop_plane}}}   ; <-- исправлено
;//											}
;//											{amount 3}
;//										}
;//										{waypoint "0"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//								}
;//							}
;//						}
;//						{"default" ; user_team$ != 1
;//							{"delay" {time 0.1}}
;//							{"switch"
;//								{"case"
;//									{condition {type cmp_i} {var "tier2$"} {op "=="} {value 1}}
;//									{"delay" {time 0.1}}
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{select
;//													{tag {tag airstrike_ger}}
;//													{tag {tag airstrike_rus}}
;//													{tag {tag airstrike_fin}}
;//													{tag {tag airstrike_usa}}
;//													{tag {tag airstrike_eng}}
;//													{tag {tag airstrike_jap}}
;//												}
;//												{include {tag {tag hidden}}}
;//												{exclude {tag {tag early_war}} {tag {tag disabled}}	{tag {tag enemy_paradrop_plane}}}   ; <-- исправлено
;//											}
;//											{amount 4}
;//										}
;//										{waypoint "6"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//								}
;//								{"default"
;//									{"delay" {time 0.1}}
;//									{"actor_to_waypoint"
;//										{selector
;//											{source advanced}
;//											{ignore_captured_by_user 0}
;//											{group
;//												{select
;//													{tag {tag airstrike_ger}}
;//													{tag {tag airstrike_rus}}
;//													{tag {tag airstrike_fin}}
;//													{tag {tag airstrike_usa}}
;//													{tag {tag airstrike_eng}}
;//													{tag {tag airstrike_jap}}
;//												}
;//												{include {tag {tag hidden}}}
;//												{exclude {tag {tag late_war}} {tag {tag disabled}}	{tag {tag enemy_paradrop_plane}}}   ; <-- исправлено
;//											;	{exclude {tag {tag late_war}} {tag {tag disabled}}}   ; <-- исправлено
;//											}
;//											{amount 3}
;//										}
;//										{waypoint "6"}
;//										{clone}
;//										{approach "safe teleport & rotate"}
;//									}
;//								}
;//							}
;//						}
;//					}
;//					; + ARM 130926 — сирена и реплики при вылете боевых самолётов (ARMCE-канал)
;//					{"sound" {name "world/alarm/siren_alarm_10"}}
;//					{"switch"
;//						{"case" {condition {type rand} {value 0.33}}
;//							{"talk"
;//								{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
;//								{text "mission/multi/enemy_planes_attack_1"}
;//							}
;//						}
;//						{"case" {condition {type rand} {value 0.5}}
;//							{"talk"
;//								{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
;//								{text "mission/multi/enemy_planes_attack_2"}
;//							}
;//						}
;//						{"default"
;//							{"talk"
;//								{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
;//								{text "mission/multi/enemy_planes_attack_3"}
;//							}
;//						}
;//					}
;//
;//					; ===== ТРАНСПОРТНЫЕ/ДЕСАНТНЫЕ САМОЛЁТЫ (шанс 40%, только спавн) =====
;//										; ===== ТРАНСПОРТНЫЕ/ДЕСАНТНЫЕ САМОЛЁТЫ (шанс 50%, только спавн) =====
;//					{"if"
;//						{condition {type rand} {value 0.50}}								; !!! 0.50
;//						{"switch"
;//							{"case"
;//								{condition {type cmp_i} {var "user_team$"} {op "=="} {value 1}}
;//								{"switch"
;//									{"case"
;//										{condition {type cmp_i} {var "tier2$"} {op "=="} {value 1}}
;//										{"actor_to_waypoint"
;//											{selector
;//												{source advanced}
;//												{ignore_captured_by_user 0}
;//												{group
;//													{select
;//														{tag {tag airstrike_ger}}
;//														{tag {tag airstrike_rus}}
;//														{tag {tag airstrike_fin}}
;//														{tag {tag airstrike_usa}}
;//														{tag {tag airstrike_eng}}
;//														{tag {tag airstrike_jap}}
;//													}
;//													{include
;//														{tag {tag hidden}}
;//														{tag {tag enemy_paradrop_plane}}
;//													}
;//													{exclude
;//														{tag {tag early_war}}
;//														{tag {tag disabled}}
;//													}
;//												}
;//												{amount 2}
;//											}
;//											{waypoint "6"}   ; зеркально боевым
;//											{clone}
;//											{approach "safe teleport & rotate"}
;//										}
;//										{"entity_state"
;//											{selector
;//												{source advanced}
;//												{ignore_captured_by_user 0}
;//												{group
;//													{select
;//														{tag {tag airstrike_ger}}
;//														{tag {tag airstrike_rus}}
;//														{tag {tag airstrike_fin}}
;//														{tag {tag airstrike_usa}}
;//														{tag {tag airstrike_eng}}
;//														{tag {tag airstrike_jap}}
;//													}
;//													{include
;//														{tag {tag hidden}}
;//														{tag {tag enemy_paradrop_plane}}
;//													}
;//													{exclude
;//														{tag {tag early_war}}
;//														{tag {tag disabled}}
;//													}
;//												}
;//												{amount 2}
;//											}
;//											{tag_add enemy_air}
;//										}
;//									}
;//									{"default"
;//										{"actor_to_waypoint"
;//											{selector
;//												{source advanced}
;//												{ignore_captured_by_user 0}
;//												{group
;//													{select
;//														{tag {tag airstrike_ger}}
;//														{tag {tag airstrike_rus}}
;//														{tag {tag airstrike_fin}}
;//														{tag {tag airstrike_usa}}
;//														{tag {tag airstrike_eng}}
;//														{tag {tag airstrike_jap}}
;//													}
;//													{include
;//														{tag {tag hidden}}
;//														{tag {tag enemy_paradrop_plane}}
;//													}
;//													{exclude
;//														{tag {tag late_war}}
;//														{tag {tag disabled}}
;//													}
;//												}
;//												{amount 2}
;//											}
;//											{waypoint "6"}   ; зеркально боевым
;//											{clone}
;//											{approach "safe teleport & rotate"}
;//										}
;//										{"entity_state"
;//											{selector
;//												{source advanced}
;//												{ignore_captured_by_user 0}
;//												{group
;//													{select
;//														{tag {tag airstrike_ger}}
;//														{tag {tag airstrike_rus}}
;//														{tag {tag airstrike_fin}}
;//														{tag {tag airstrike_usa}}
;//														{tag {tag airstrike_eng}}
;//														{tag {tag airstrike_jap}}
;//													}
;//													{include
;//														{tag {tag hidden}}
;//														{tag {tag enemy_paradrop_plane}}
;//													}
;//													{exclude
;//														{tag {tag late_war}}
;//														{tag {tag disabled}}
;//													}
;//												}
;//												{amount 2}
;//											}
;//											{tag_add enemy_air}
;//										}
;//									}
;//								}
;//							}
;//							{"default" ; user_team$ != 1
;//								{"switch"
;//									{"case"
;//										{condition {type cmp_i} {var "tier2$"} {op "=="} {value 1}}
;//										{"actor_to_waypoint"
;//											{selector
;//												{source advanced}
;//												{ignore_captured_by_user 0}
;//												{group
;//													{select
;//														{tag {tag airstrike_ger}}
;//														{tag {tag airstrike_rus}}
;//														{tag {tag airstrike_fin}}
;//														{tag {tag airstrike_usa}}
;//														{tag {tag airstrike_eng}}
;//														{tag {tag airstrike_jap}}
;//													}
;//													{include
;//														{tag {tag hidden}}
;//														{tag {tag enemy_paradrop_plane}}
;//													}
;//													{exclude
;//														{tag {tag early_war}}
;//														{tag {tag disabled}}
;//													}
;//												}
;//												{amount 2}
;//											}
;//											{waypoint "0"}   ; зеркально боевым
;//											{clone}
;//											{approach "safe teleport & rotate"}
;//										}
;//										{"entity_state"
;//											{selector
;//												{source advanced}
;//												{ignore_captured_by_user 0}
;//												{group
;//													{select
;//														{tag {tag airstrike_ger}}
;//														{tag {tag airstrike_rus}}
;//														{tag {tag airstrike_fin}}
;//														{tag {tag airstrike_usa}}
;//														{tag {tag airstrike_eng}}
;//														{tag {tag airstrike_jap}}
;//													}
;//													{include
;//														{tag {tag hidden}}
;//														{tag {tag enemy_paradrop_plane}}
;//													}
;//													{exclude
;//														{tag {tag early_war}}
;//														{tag {tag disabled}}
;//													}
;//												}
;//												{amount 2}
;//											}
;//											{tag_add enemy_air}
;//										}
;//									}
;//									{"default"
;//										{"actor_to_waypoint"
;//											{selector
;//												{source advanced}
;//												{ignore_captured_by_user 0}
;//												{group
;//													{select
;//														{tag {tag airstrike_ger}}
;//														{tag {tag airstrike_rus}}
;//														{tag {tag airstrike_fin}}
;//														{tag {tag airstrike_usa}}
;//														{tag {tag airstrike_eng}}
;//														{tag {tag airstrike_jap}}
;//													}
;//													{include
;//														{tag {tag hidden}}
;//														{tag {tag enemy_paradrop_plane}}
;//													}
;//													{exclude
;//														{tag {tag late_war}}
;//														{tag {tag disabled}}
;//													}
;//												}
;//												{amount 2}
;//											}
;//											{waypoint "0"}   ; зеркально боевым
;//											{clone}
;//											{approach "safe teleport & rotate"}
;//										}
;//										{"entity_state"
;//											{selector
;//												{source advanced}
;//												{ignore_captured_by_user 0}
;//												{group
;//													{select
;//														{tag {tag airstrike_ger}}
;//														{tag {tag airstrike_rus}}
;//														{tag {tag airstrike_fin}}
;//														{tag {tag airstrike_usa}}
;//														{tag {tag airstrike_eng}}
;//														{tag {tag airstrike_jap}}
;//													}
;//													{include
;//														{tag {tag hidden}}
;//														{tag {tag enemy_paradrop_plane}}
;//													}
;//													{exclude
;//														{tag {tag late_war}}
;//														{tag {tag disabled}}
;//													}
;//												}
;//												{amount 2}
;//											}
;//											{tag_add enemy_air}
;//										}
;//									}
;//								}
;//							}
;//						}
;//						; + ARM 130926 — сирена и реплики при вылете транспортных самолётов (ARMCE-канал)
;//						{"sound" {name "world/alarm/siren_alarm_10"}}
;//						{"switch"
;//							{"case" {condition {type rand} {value 0.33}}
;//								{"talk"
;//									{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
;//									{text "mission/multi/enemy_planes_attack_3"}
;//								}
;//							}
;//							{"case" {condition {type rand} {value 0.5}}
;//								{"talk"
;//									{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
;//									{text "mission/multi/enemy_planes_attack_2"}
;//								}
;//							}
;//							{"default"
;//								{"talk"
;//									{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
;//									{text "mission/multi/enemy_planes_attack_1"}
;//								}
;//							}
;//						}
;//					}
;//				}
			}

			{"dcg/ai_airstrike"													; need test
				{condition
					{terms
						{"1.event" {id "ai_air_on"}}
					}
				}
				{actions
					{"delay" {time 0.1}}
					{"entity_state" {selector {ignore_captured_by_user 0} {tag enemy_air}} {tag_remove enemy_air}}
					{"delay" {time 0.1}}

					; ===== БОЕВЫЕ САМОЛЁТЫ =====
					{"switch"
						{"case"
							{condition {type cmp_i} {var "user_team$"} {op "=="} {value 1}}
							{"delay" {time 0.1}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 57}}
									{"delay" {time 0.1}}
									{"actor_to_waypoint"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag late_war}}
													{tag {tag hidden_fighter}}          ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag late_war}}
													{tag {tag hidden_bomber}}           ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{amount 5}
										}
										{waypoint "0"}
										{clone}
										{approach "safe teleport & rotate"}
									}
								}
								{"case"
									{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 29}}
									{"delay" {time 0.1}}
									{"actor_to_waypoint"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag mid_war}}
													{tag {tag hidden_fighter}}          ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag mid_war}}
													{tag {tag hidden_bomber}}           ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{amount 4}
										}
										{waypoint "0"}
										{clone}
										{approach "safe teleport & rotate"}
									}
								}
								{"default"
									{"delay" {time 0.1}}
									{"actor_to_waypoint"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag early_war}}
													{tag {tag hidden_fighter}}          ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag early_war}}
													{tag {tag hidden_bomber}}           ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{amount 3}
										}
										{waypoint "0"}
										{clone}
										{approach "safe teleport & rotate"}
									}
								}
							}
						}
						{"default" ; user_team$ != 1
							{"delay" {time 0.1}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 57}}
									{"delay" {time 0.1}}
									{"actor_to_waypoint"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag late_war}}
													{tag {tag hidden_fighter}}          ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag late_war}}
													{tag {tag hidden_bomber}}           ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{amount 5}
										}
										{waypoint "6"}
										{clone}
										{approach "safe teleport & rotate"}
									}
								}
								{"case"
									{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 29}}
									{"delay" {time 0.1}}
									{"actor_to_waypoint"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag mid_war}}
													{tag {tag hidden_fighter}}          ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag mid_war}}
													{tag {tag hidden_bomber}}           ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{amount 4}
										}
										{waypoint "6"}
										{clone}
										{approach "safe teleport & rotate"}
									}
								}
								{"default"
									{"delay" {time 0.1}}
									{"actor_to_waypoint"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag early_war}}
													{tag {tag hidden_fighter}}          ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{group
												{select
													{tag {tag airstrike_ger}}
													{tag {tag airstrike_rus}}
													{tag {tag airstrike_fin}}
													{tag {tag airstrike_usa}}
													{tag {tag airstrike_eng}}
													{tag {tag airstrike_jap}}
												}
												{include
													{tag {tag hidden}}
													{tag {tag early_war}}
													{tag {tag hidden_bomber}}           ; Arm added 130926
												}
												{exclude
													{tag {tag disabled}}
													{tag {tag enemy_paradrop_plane}}
												;	{tag {tag no_scavenge}}             ; Arm added 130926
												}
											}
											{amount 3}
										}
										{waypoint "6"}
										{clone}
										{approach "safe teleport & rotate"}
									}
								}
							}
						}
					}
					; + ARM 130926 — сирена и реплики при вылете боевых самолётов (ARMCE-канал)
					{"sound" {name "world/alarm/siren_alarm_10"}}
					{"switch"
						{"case" {condition {type rand} {value 0.33}}
							{"talk"
								{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
								{text "mission/multi/enemy_planes_attack_1"}
							}
						}
						{"case" {condition {type rand} {value 0.5}}
							{"talk"
								{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
								{text "mission/multi/enemy_planes_attack_2"}
							}
						}
						{"default"
							{"talk"
								{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
								{text "mission/multi/enemy_planes_attack_3"}
							}
						}
					}

					; ===== ТРАНСПОРТНЫЕ/ДЕСАНТНЫЕ САМОЛЁТЫ (шанс 50%, только спавн) =====
					{"if"
						{condition {type rand} {value 0.50}}
						{"switch"
							{"case"
								{condition {type cmp_i} {var "user_team$"} {op "=="} {value 1}}
								{"switch"
									{"case"
										{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 57}}
										{"actor_to_waypoint"
											{selector
												{source advanced}
												{ignore_captured_by_user 0}
												{group
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag late_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
													}
												}
												{amount 3}
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
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag late_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
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
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag mid_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
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
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag mid_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
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
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag early_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
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
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag early_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
													}
												}
												{amount 2}
											}
											{tag_add enemy_air}
										}
									}
								}
							}
							{"default" ; user_team$ != 1
								{"switch"
									{"case"
										{condition {type cmp_i} {var "b_operation_day$"} {op ">"} {value 57}}
										{"actor_to_waypoint"
											{selector
												{source advanced}
												{ignore_captured_by_user 0}
												{group
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag late_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
													}
												}
												{amount 3}
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
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag late_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
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
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag mid_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
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
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag mid_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
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
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag early_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
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
													{select
														{tag {tag airstrike_ger}}
														{tag {tag airstrike_rus}}
														{tag {tag airstrike_fin}}
														{tag {tag airstrike_usa}}
														{tag {tag airstrike_eng}}
														{tag {tag airstrike_jap}}
													}
													{include
														{tag {tag hidden}}
														{tag {tag early_war}}
														{tag {tag enemy_paradrop_plane}}
													}
													{exclude
														{tag {tag disabled}}
													}
												}
												{amount 2}
											}
											{tag_add enemy_air}
										}
									}
								}
							}
						}
						; + ARM 130926 — сирена и реплики при вылете транспортных самолётов (ARMCE-канал)
						{"sound" {name "world/alarm/siren_alarm_10"}}
						{"switch"
							{"case" {condition {type rand} {value 0.33}}
								{"talk"
									{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
									{text "mission/multi/enemy_planes_attack_3"}
								}
							}
							{"case" {condition {type rand} {value 0.5}}
								{"talk"
									{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
									{text "mission/multi/enemy_planes_attack_2"}
								}
							}
							{"default"
								{"talk"
									{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
									{text "mission/multi/enemy_planes_attack_1"}
								}
							}
						}
					}
				}
			}

			{## "dcg/ai_airstrike_do_mace"			{disabled}
				{condition
					{expression "1 & 2 & 3"}
					{terms
						{"1.event" {id "ai_air_on"}}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select {tag {tag enemy_air}}}
									{include
										{prop {prop vehicle}}
										{state {state operatable}}
									}
								}
							}
						}
						{"3.cmp_i"
							{var "bot_difficulty$"}
							{op ">="}
							{value 3}   ; из текущей версии
						}
					}
				}
				{actions
					{"delay" {time 0.3}}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag ai_air_target}
						}
						{tag_remove ai_air_target}
					}
					{"delay" {time 0.1}}
					{"switch"
						{"case"
							{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 5}}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag _user}}}
										{include
											{zone {zone "gamezone"}}
											{state {state "operatable user_control"}}
										}
										{exclude
											{state {state inactive}}
											{tag {tag destroyed}}
										}
									}
									{sort {type waypoint} {wpid "5"}}
									{amount 2}
								}
								{tag_add ai_air_target}
							}
						}
						{"case"
							{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 2}}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag _user}}}
										{include
											{zone {zone "gamezone"}}
											{state {state "operatable user_control"}}
										}
										{exclude
											{state {state inactive}}
											{tag {tag destroyed}}
										}
									}
									{sort {type waypoint} {wpid "2"}}
									{amount 1}
								}
								{tag_add ai_air_target}
							}
						}
						{"case"
							{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 3}}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag _user}}}
										{include
											{zone {zone "gamezone"}}
											{state {state "operatable user_control"}}
										}
										{exclude
											{state {state inactive}}
											{tag {tag destroyed}}
										}
									}
									{sort {type waypoint} {wpid "3"}}
									{amount 1}
								}
								{tag_add ai_air_target}
							}
						}
						{"case"
							{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 4}}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag _user}}}
										{include
											{zone {zone "gamezone"}}
											{state {state "operatable user_control"}}
										}
										{exclude
											{state {state inactive}}
											{tag {tag destroyed}}
										}
									}
									{sort {type waypoint} {wpid "4"}}
									{amount 3}
								}
								{tag_add ai_air_target}
							}
						}
						{"default"
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag _user}}}
										{include
											{zone {zone "gamezone"}}
											{state {state "operatable user_control"}}
										}
										{exclude
											{state {state inactive}}
											{tag {tag destroyed}}
										}
									}
									{sort {type waypoint} {wpid "1"}}
									{amount 2}
								}
								{tag_add ai_air_target}
							}
						}
					}
					{"delay" {time 0.1}}
					{"switch"
						{"case"
							{condition
								{terms
									{"1.entities"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select
													{tag {tag enemy_air}}
													{tag {tag cannon}}
												}
												{include
													{prop {prop vehicle}}
													{state {state inhabited}}
												}
											}
										}
									}
								}
							}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{tag cannon}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 5}
							}
						}
						{"default"
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 47}
							}
						}
					}
				}
			}

			{"dcg/ai_airstrike_do_vanilla"										; its work but with problems 130926 1910
				{condition
				;	{expression "1 & (5 | 6 | 7) & ((2 & 4) | (3 & !4))"}				;	1, 2, 3
				;	{expression "1 & (5 | 6) & ((2 & 4) | (3 & !4))"}					;	1, 2
					{expression "1 & (5 | 6 | 7 | 8) & ((2 & 4) | (3 & !4))"}			; 	1, 2, 3, 4
					{terms
						{"1.event" {id "ai_air_on"}}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{zone {zone "a_1"}}
										{zone {zone "a_2"}}
										{zone {zone "a_3"}}
										{zone {zone "a_4"}}
									}
									{include
										{tag {tag enemy_air}}
										{prop {prop vehicle}}
										{state {state operatable}}
									}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{zone {zone "b_1"}}
										{zone {zone "b_2"}}
										{zone {zone "b_3"}}
										{zone {zone "b_4"}}
									}
									{include
										{tag {tag enemy_air}}
										{prop {prop vehicle}}
										{state {state operatable}}
									}
								}
							}
						}
						{"4.cmp_i" {var "user_team$"} {op "=="} {value 1}}
						{"5.cmp_i" {var "bot_difficulty$"} {op "=="} {value 1}}		
						{"6.cmp_i" {var "bot_difficulty$"} {op "=="} {value 2}}
						{"7.cmp_i" {var "bot_difficulty$"} {op "=="} {value 3}}
						{"8.cmp_i" {var "bot_difficulty$"} {op "=="} {value 4}}   	; +4
					}
				}
				{actions
					{"delay" {time 4.5}}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag ai_air_target}
									{zone "gamezone"}
								}
							}
							{"delay" {time 0.1}}
						}
						{"default"
							{"delay" {time 0.1}}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag _user}}}
										{include
											{zone {zone "gamezone"}}
											{state {state "operatable user_control"}}
										}
										{exclude
											{state {state inactive}}
											{state {state linked}}
										}
									}
								}
								{tag_add ai_air_target}
							}
						}
					}
					{"delay" {time 1.1}}
					;----------------------- test
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag enemy_air}}}
										{include {tag {tag hidden_fighter}}}
									}
								}
							}
							{"delay" {time 0.1}}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{tag hidden_fighter}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 54}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag enemy_air}}}
										{include {tag {tag hidden_bomber}}}
									}
								}
							}
							{"delay" {time 0.1}}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{tag hidden_bomber}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 64}
							}
						}
						{"default"
							{"delay" {time 0.1}}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 47}
							}
						}
					}
					;--------------------- test
					; + ARM 130926 — возврат и удаление после отработки атаки
					{"delay" {time 90}}
					{"actor_to_waypoint"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select {tag {tag enemy_air}}}
								{include
									{prop {prop vehicle}}
									{state {state operatable}}
								}
								{exclude
									{tag {tag enemy_paradrop_plane}}
								}
							}
						}
						{waypoint "3000"}
						{approach "safe teleport & rotate"}
					}
					{"delay" {time 30}}
					{"delete"
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select {tag {tag enemy_air}}}
								{exclude
									{tag {tag enemy_paradrop_plane}}
								}
							}
						}
					}
					;--------------------- test
				}
				;----------------------- test
			}
			{## "dcg/ai_airstrike_do_vanilla_bak"	{disabled}					; its work but with problems 130926 1910
				{condition
				;	{expression "1 & (5 | 6 | 7) & ((2 & 4) | (3 & !4))"}				;	1, 2, 3
				;	{expression "1 & (5 | 6) & ((2 & 4) | (3 & !4))"}					;	1, 2
					{expression "1 & (5 | 6 | 7 | 8) & ((2 & 4) | (3 & !4))"}			; 	1, 2, 3, 4
					{terms
						{"1.event" {id "ai_air_on"}}
						{"2.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{zone {zone "a_1"}}
										{zone {zone "a_2"}}
										{zone {zone "a_3"}}
										{zone {zone "a_4"}}
									}
									{include
										{tag {tag enemy_air}}
										{prop {prop vehicle}}
										{state {state operatable}}
									}
								}
							}
						}
						{"3.entities"
							{selector
								{source advanced}
								{ignore_captured_by_user 0}
								{group
									{select
										{zone {zone "b_1"}}
										{zone {zone "b_2"}}
										{zone {zone "b_3"}}
										{zone {zone "b_4"}}
									}
									{include
										{tag {tag enemy_air}}
										{prop {prop vehicle}}
										{state {state operatable}}
									}
								}
							}
						}
						{"4.cmp_i" {var "user_team$"} {op "=="} {value 1}}
						{"5.cmp_i" {var "bot_difficulty$"} {op "=="} {value 1}}		
						{"6.cmp_i" {var "bot_difficulty$"} {op "=="} {value 2}}
						{"7.cmp_i" {var "bot_difficulty$"} {op "=="} {value 3}}
						{"8.cmp_i" {var "bot_difficulty$"} {op "=="} {value 4}}   	; +4
					}
				}
				{actions
					{"delay" {time 4.5}}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{ignore_captured_by_user 0}
									{tag ai_air_target}
									{zone "gamezone"}
								}
							}
							{"delay" {time 0.1}}
						}
						{"default"
							{"delay" {time 0.1}}
							{"entity_state"
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag _user}}}
										{include
											{zone {zone "gamezone"}}
											{state {state "operatable user_control"}}
										}
										{exclude
											{state {state inactive}}
											{state {state linked}}
										}
									}
								}
								{tag_add ai_air_target}
							}
						}
					}
					{"delay" {time 1.1}}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag enemy_air}}}
										{include {tag {tag jet}}}
									}
								}
							}
							{"delay" {time 0.1}}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 47}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag enemy_air}}}
										{include {tag {tag air_attack_fast}}}
									}
								}
							}
							{"delay" {time 0.1}}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 47}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag enemy_air}}}
										{include {tag {tag altitude_high}}}
									}
								}
							}
							{"delay" {time 0.1}}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 64}
							}
						}
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag enemy_air}}}
										{include {tag {tag altitude_low}}}
										{exclude {tag {tag altitude_high}}}
									}
								}
							}
							{"delay" {time 0.1}}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 30}
							}
						}
						{"default"
							{"delay" {time 0.1}}
							{"air_attack"
								{selector
									{ignore_captured_by_user 0}
									{tag enemy_air}
									{type vehicle}
									{state inhabited}
								}
								{drop "orders sensor senseless"}
								{enemies
									{ignore_captured_by_user 0}
									{tag ai_air_target}
								}
								{attack_altitude 47}
							}
						}
					}
				}
			}
			{## "dcg/ai_airstrike_do_vanilla_no"	{disabled}
;//				{condition
;//					{expression "1 & (5 | 6 | 7 | 8) & ((2 & 4) | (3 & !4))"}
;//					{terms
;//						{"1.event" {id "ai_air_on"}}
;//						{"2.entities"
;//							{selector
;//								{source advanced}
;//								{ignore_captured_by_user 0}
;//								{group
;//									{select
;//										{zone {zone "a_1"}}
;//										{zone {zone "a_2"}}
;//										{zone {zone "a_3"}}
;//										{zone {zone "a_4"}}
;//									}
;//									{include
;//										{tag {tag enemy_air}}
;//										{prop {prop vehicle}}
;//										{state {state operatable}}
;//									}
;//								}
;//							}
;//						}
;//						{"3.entities"
;//							{selector
;//								{source advanced}
;//								{ignore_captured_by_user 0}
;//								{group
;//									{select
;//										{zone {zone "b_1"}}
;//										{zone {zone "b_2"}}
;//										{zone {zone "b_3"}}
;//										{zone {zone "b_4"}}
;//									}
;//									{include
;//										{tag {tag enemy_air}}
;//										{prop {prop vehicle}}
;//										{state {state operatable}}
;//									}
;//								}
;//							}
;//						}
;//						{"4.cmp_i" {var "user_team$"} {op "=="} {value 1}}
;//						{"5.cmp_i" {var "bot_difficulty$"} {op "=="} {value 1}}
;//						{"6.cmp_i" {var "bot_difficulty$"} {op "=="} {value 2}}
;//						{"7.cmp_i" {var "bot_difficulty$"} {op "=="} {value 3}}
;//						{"8.cmp_i" {var "bot_difficulty$"} {op "=="} {value 4}}
;//					}
;//				}
;//				{actions
;//					{"delay" {time 4.5}}
;//
;//					; + ARM 110926 — активация клонов как боевых AI-самолётов
;//					{"entity_state"
;//						{selector
;//							{source advanced}
;//							{ignore_captured_by_user 0}
;//							{group
;//								{select
;//									{tag {tag enemy_air}}
;//								}
;//								{include
;//									{prop {prop vehicle}}
;//								}
;//								{exclude
;//									{tag {tag enemy_paradrop_plane}}
;//									{tag {tag bomber_ce}}
;//									{tag {tag fighter}}
;//								}
;//							}
;//						}
;//						{tag_remove hidden}
;//						{tag_add arm_cbt_plane}
;//					}
;//
;//					; + ARM 110926 — jet → fighter
;//					{"entity_state"
;//						{selector
;//							{source advanced}
;//							{ignore_captured_by_user 0}
;//							{group
;//								{select
;//									{tag {tag arm_cbt_plane}}
;//								}
;//								{include
;//									{tag {tag jet}}
;//								}
;//								{exclude
;//									{tag {tag fighter}}
;//								}
;//							}
;//						}
;//						{tag_add fighter}
;//						{tag_add fighter_ready}
;//					}
;//
;//					; + ARM 110926 — остальные → bomber_ce
;//					{"entity_state"
;//						{selector
;//							{source advanced}
;//							{ignore_captured_by_user 0}
;//							{group
;//								{select
;//									{tag {tag arm_cbt_plane}}
;//								}
;//								{exclude
;//									{tag {tag fighter}}
;//									{tag {tag bomber_ce}}
;//								}
;//							}
;//						}
;//						{tag_add bomber_ce}
;//						{tag_add bomber_ce_ready}
;//					}
;//
;//					; + ARM 110926 — пауза на отработку атаки (2 захода)
;//					{"delay" {time 90}}
;//
;//					; + ARM 110926 — возврат на waypoint 3000 (только те, кто уже отработал — combat_run)
;//					{"actor_to_waypoint"
;//						{selector
;//							{source advanced}
;//							{ignore_captured_by_user 0}
;//							{group
;//								{select
;//									{tag {tag enemy_air}}
;//									{tag {tag arm_cbt_plane}}
;//								}
;//								{include
;//									{state {state operatable}}
;//									{tag {tag combat_run}}
;//								}
;//								{exclude
;//									{tag {tag enemy_paradrop_plane}}
;//								}
;//							}
;//						}
;//						{waypoint "3000"}
;//						{approach "safe teleport & rotate"}
;//					}
;//
;//					; + ARM 110926 — пауза на уход и удаление
;//					{"delay" {time 30}}
;//					{"delete"
;//						{selector
;//							{source advanced}
;//							{ignore_captured_by_user 0}
;//							{group
;//								{select
;//									{tag {tag enemy_air}}
;//									{tag {tag arm_cbt_plane}}
;//								}
;//								{include
;//									{tag {tag combat_run}}
;//								}
;//								{exclude
;//									{tag {tag enemy_paradrop_plane}}
;//								}
;//							}
;//						}
;//					}
;//
;//					; + ARM 110926 — перезапуск
;//					{"delay" {time 5}}
;//					{"trigger" {name "dcg/ai_airstrike_do_vanilla"}}
;//				}
			}
			{"dcg/ai_air_safety_cleanup"										; need test
				{condition}
				{actions
					{"delay" {time 300}}								; Arm added 130926
					{"delete"											; Arm added 130926
						{selector
							{source advanced}
							{ignore_captured_by_user 0}
							{group
								{select {tag {tag enemy_air}}}
								{include {prop {prop vehicle}}}
								{exclude
									{tag {tag enemy_paradrop_plane}}
								}
							}
						}
					}
					{"trigger" {name "dcg/ai_air_safety_cleanup"}}		; Arm added 130926
				}
			}
			{"dcg/ai_air_chance"
				{condition
					{terms
						{"1.event" {id "airplane_set"}}
						{"2.cmp_i" {var "user_team$"} {op ">"} {value 0}}
						{"3.cmp_i" {var "prep_inform$"} {op ">"} {value 0}}
					}
				}
				{actions
					{"talk"
						{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
						{text "ARm DEBUG: ai_air_chance triggered, prep_inform$ = %prep_inform$%"}
					}
					; ===== ОТЛАДКА (из текущей версии) =====
				;	{"objective_progress" {set 0} {add 0} {title "DEBUG: ai_air_chance STARTED"}}
					{"event"
						{event "ai_air_possible"}
						{mode reset}
						{delay 0}
					}
					{"delay" {time 30}}
					; ===== ИНКЛУДЫ (из текущей) =====
				;	{"switch"																			; this is ; for inc replacer. its must be activated for tests only!		; NB!
				;		{"case"
				;			{condition
				;				{type rand}
				;				{value 1.00}
				;			}
				;			{"delay"
				;				(include "/map/multi/mace_scripts.inc")
				;				{time 20}				;//ARm edit 520-250
				;			}
				;		}
				;		{"case"
				;			{condition
				;				{type rand}
				;				{value 0.15}
				;			}
				;			{"delay"
				;				{time 120}				;//ARm edit 1200-600
				;			}
				;		}
				;		{"case"
				;			{condition
				;				{type rand}
				;				{value 0.30}
				;			}
				;			{"delay"
				;				{time 60}				;//ARm edit 735-350
				;			}
				;		}
				;		{"case"
				;			{condition
				;				{type rand}
				;				{value 0.15}
				;			}
				;			{"delay"	
				;				{time 180}				;//ARm edit 890-475
				;			}
				;		}
				;		{"default"
				;			{"delay"
				;				{time 120}				;//ARm edit 930-465
				;			}
				;		}
				;	}
		(include "/map/multi/_dcg_script/_dcg_script_ai_air_chance_switch.inc")				; inc replacer dont delete!
					{"delay" {time 1}}
					{"switch"
						{"case"						; Radio car																
							{condition
								{type entities}
								{selector
									{source advanced}
									{group
										{select {tag {tag command_vehicle_aa}}}
										{include
											{prop {prop vehicle}}
											{state {state inhabited}}
										}
										{exclude {tag {tag destroyed}}}
									}
								}
							}
							{"event" {event "talk_on"} {mode set} {delay 0}}
							{"delay" {time 6}}
							{"talk"
								{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
								{text "mission/multi/enemy_planes_chance_reduced"}
							}
							{"delay" {time 8}}
							{"event" {event "talk_on"} {mode reset} {delay 0}}
							{"delay" {time 20}}
							{"switch"
								{"case"
								;	{condition {type rand} {value 0.65}}																; Radio car save III chance
				(include "/map/multi/_dcg_script/_dcg_script_air_attack_script/_dcg_script_ai_air_chance_withradio.inc")													; inc replacer {condition {type rand} {value 0.65}} vs {condition {type rand} {value 0.50}}							
									{"event" {event "talk_on"} {mode set} {delay 0}}
									{"delay" {time 6}}
									{"talk"
										{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
										{text "mission/multi/enemy_planes_continue"}
										{"sound" {name "world/alarm/siren01_10"}}
									}
									{"objective_progress" {set 0} {add 0} {title "Aviation threat level III danger! Need radio-command vehicle"}}   
									{"delay" {time 8}}
									{"event" {event "talk_on"} {mode reset} {delay 0}}
									{"delay" {time 12.0}}
									{"event" {event "ai_air_possible"} {mode set} {delay 0}}
									{"trigger" {name "dcg/ai_air_on"}}
									{"delay" {time 0.1}}
									{"trigger" {name "dcg/ai_airstrike"}}
								;	{"delay" {time 0.1}}
								;	{"trigger" {name "dcg/ai_airstrike_do_mace"}}
									{"delay" {time 0.1}}
									{"trigger" {name "dcg/ai_airstrike_do_vanilla"}}
									{"delay" {time 0.1}}
									{"trigger" {name "dcg/warning_air"}}
									{"delay" {time 0.1}}
									{"trigger" {name "dcg/ai_air_chance"}}
								}
								{"default"
									{"event" {event "talk_on"} {mode set} {delay 0}}
									{"delay" {time 6}}
									{"talk"
										{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
										{text "mission/multi/enemy_planes_taken_out"}
										{"sound" {name "mission/task_fail"}}
									}
									{"objective_progress" {set 0} {add 0} {title "Aviation threat level II"}}   ; из текущей
									{"delay" {time 8}}
									{"event" {event "talk_on"} {mode reset} {delay 0}}
								}
							}
						}
						{"default"				; No Radio car	
							{"switch"
								{"case"
								;	{condition	{type rand}	{value 1.00}}												; this is ; for inc replacer. its must be activated for tests only! ; Чем выше шанс - тем выше вероятность сохранения III
			(include "/map/multi/_dcg_script/_dcg_script_ai_air_reduce_chance.inc")										; inc replacer has DEFAULT: {condition	{type rand}{value 0.75} } vs ADDON {condition	{type rand}{value 0.60} } - Чем выше шанс - тем выше вероятность сохранения III БЕЗ радиомашины
									{"event" {event "talk_on"} {mode set} {delay 0}}
									{"delay" {time 6}}
									{"talk"
										{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
										{text "mission/multi/enemy_planes_continue"}
									}
									{"objective_progress" {set 0} {add 0} {title "Aviation threat level III danger! Need radio-command vehicle"}}   ; из текущей
									{"sound" {name "world/alarm/siren01_10"}}
									{"delay" {time 8}}
									{"event" {event "talk_on"} {mode reset} {delay 0}}
									{"delay" {time 12.0}}
									{"event" {event "ai_air_possible"} {mode set} {delay 0}}
									{"trigger" {name "dcg/ai_air_on"}}
									{"delay" {time 0.1}}
									{"trigger" {name "dcg/ai_airstrike"}}
									{"delay" {time 0.1}}
								;	{"trigger" {name "dcg/ai_airstrike_do_mace"}}  ; из ИЗНАЧАЛЬНОЙ
								;	{"delay" {time 0.1}}
									{"trigger" {name "dcg/ai_airstrike_do_vanilla"}} ; из ИЗНАЧАЛЬНОЙ
									{"delay" {time 0.1}}
									{"trigger" {name "dcg/warning_air"}}
									{"delay" {time 0.1}}
									{"trigger" {name "dcg/ai_air_chance"}}
								}
								{"default"
									{"event" {event "talk_on"} {mode set} {delay 0}}
									{"delay" {time 6}}
									{"talk"
										{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
										{text "mission/multi/enemy_planes_taken_out"}
									}
									{"objective_progress" {set 0} {add 0} {title "Aviation threat level II"}}   ; из текущей
									{"sound" {name "world/alarm/siren01_10"}}
									{"delay" {time 8}}
									{"event" {event "talk_on"} {mode reset} {delay 0}}
								}
							}
						}
					}
				}
			}

			{"dcg/ai_air_on"
				{condition
					{terms
						{"1.event" {id "dcg"}}
						{"2.cmp_i" {var "enemyid$"} {op ">"} {value 0}}
						{"3.entities"
							{selector
								{ignore_captured_by_user 0}
								{tag _user}
								{zone "gamezone"}
								{state operatable}
							}
						}
						{"4.cmp_i" {var "ai_air_on$"} {op ">"} {value 0}}  ; из ИЗНАЧАЛЬНОЙ
						{"5.cmp_i" {var "dcg_on$"} {op ">"} {value 0}}
					}
				}
				{actions
					{"talk"
						{selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
					;	{text "DEBUG: ai_air_on triggered"}
					}
					{"delay" {time 0.1}}
					{"event" {event "ai_air_on"} {mode set} {delay 0}}
					{"delay" {time 1}}
					{"entity_state"
						{selector
							{ignore_captured_by_user 0}
							{tag ai_air_target}
						}
						{tag_remove ai_air_target}
					}
					{"delay" {time 5}}
					{"switch"
						{"case"
							{condition
								{type entities}
								{selector
									{source advanced}
									{ignore_captured_by_user 0}
									{group
										{select {tag {tag _user}}}
										{include
											{zone {zone "combat"}}
											{prop {prop vehicle}}
											{state {state operatable}}
											{state {state user_control}}
										}
										{exclude {tag {tag destroyed}}}
									}
								}
							}
							{"delay" {time 0.1}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 5}}
									{"delay" {time 0.1}}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select {tag {tag _user}}}
												{include
													{zone {zone "gamezone"}}
													{prop {prop vehicle}}
													{state {state operatable}}
													{state {state user_control}}
												}
												{exclude {tag {tag destroyed}}}
											}
											{sort {type waypoint} {wpid "5"}}
											{amount 1}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 2}}
									{"delay" {time 0.1}}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select {tag {tag _user}}}
												{include
													{zone {zone "gamezone"}}
													{prop {prop vehicle}}
													{state {state operatable}}
													{state {state user_control}}
												}
												{exclude {tag {tag destroyed}}}
											}
											{sort {type waypoint} {wpid "2"}}
											{amount 1}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 3}}
									{"delay" {time 0.1}}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select {tag {tag _user}}}
												{include
													{zone {zone "gamezone"}}
													{prop {prop vehicle}}
													{state {state operatable}}
													{state {state user_control}}
												}
												{exclude {tag {tag destroyed}}}
											}
											{sort {type waypoint} {wpid "3"}}
											{amount 1}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 4}}
									{"delay" {time 0.1}}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select {tag {tag _user}}}
												{include
													{zone {zone "gamezone"}}
													{prop {prop vehicle}}
													{state {state operatable}}
													{state {state user_control}}
												}
												{exclude {tag {tag destroyed}}}
											}
											{sort {type waypoint} {wpid "4"}}
											{amount 1}
										}
										{tag_add ai_air_target}
									}
								}
								{"default"
									{"delay" {time 0.1}}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select {tag {tag _user}}}
												{include
													{zone {zone "gamezone"}}
													{prop {prop vehicle}}
													{state {state operatable}}
													{state {state user_control}}
												}
												{exclude {tag {tag destroyed}}}
											}
											{sort {type waypoint} {wpid "1"}}
											{amount 1}
										}
										{tag_add ai_air_target}
									}
								}
							}
						}
						{"default"
							{"delay" {time 0.1}}
							{"switch"
								{"case"
									{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 5}}
									{"delay" {time 0.1}}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select {tag {tag _user}}}
												{include
													{zone {zone "gamezone"}}
													{state {state "operatable user_control"}}
												}
												{exclude {state {state inactive}}}
											}
											{sort {type waypoint} {wpid "5"}}
											{amount 1}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 2}}
									{"delay" {time 0.1}}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select {tag {tag _user}}}
												{include
													{zone {zone "gamezone"}}
													{state {state "operatable user_control"}}
												}
												{exclude {state {state inactive}}}
											}
											{sort {type waypoint} {wpid "2"}}
											{amount 1}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 3}}
									{"delay" {time 0.1}}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select {tag {tag _user}}}
												{include
													{zone {zone "gamezone"}}
													{state {state "operatable user_control"}}
												}
												{exclude {state {state inactive}}}
											}
											{sort {type waypoint} {wpid "3"}}
											{amount 1}
										}
										{tag_add ai_air_target}
									}
								}
								{"case"
									{condition {type cmp_i} {var "ai_air_on$"} {op "=="} {value 4}}
									{"delay" {time 0.1}}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select {tag {tag _user}}}
												{include
													{zone {zone "gamezone"}}
													{state {state "operatable user_control"}}
												}
												{exclude {state {state inactive}}}
											}
											{sort {type waypoint} {wpid "4"}}
											{amount 1}
										}
										{tag_add ai_air_target}
									}
								}
								{"default"
									{"delay" {time 0.1}}
									{"entity_state"
										{selector
											{source advanced}
											{ignore_captured_by_user 0}
											{group
												{select {tag {tag _user}}}
												{include
													{zone {zone "gamezone"}}
													{state {state "operatable user_control"}}
												}
												{exclude {state {state inactive}}}
											}
											{sort {type waypoint} {wpid "1"}}
											{amount 1}
										}
										{tag_add ai_air_target}
									}
								}
							}
						}
					}
				}
			}
;-----------			