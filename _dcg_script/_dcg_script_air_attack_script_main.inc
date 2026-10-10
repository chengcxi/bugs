; DSL GEM ENGINE 2 Gates of Hell
; File: 		_dcg_script_air_attack_script_main.inc
; Catalog: 		map\multi\_dcg_script
; Created by: 	Max Drechsler
; Created:		30.08.2026
; Modify by:	Max Drechsler
; Modify:		31.08.2026
; Version:		1.5
; INC-injector
; Description: 

; =====================================================================
; ЗАМЕНА ОРИГИНАЛЬНЫХ ТРИГГЕРОВ АВИАУДАРА НА ВЕРСИЮ С ТРЕМЯ СТАДИЯМИ ВОЙНЫ
; Добавлены команды движения для клонов (чтобы не кружили на краю карты)
; =====================================================================

{"dcg/ai_airstrike"
	{condition
		{terms
			{"1.event"
				{id "ai_air_on"}
			}
		}
	}
	{actions
		{"objective_progress" {set 0} {add 0} {title "!!! dcg/ai_airstrike STARTED !!!"}}
		{"delay"
			{time 0.1}
		}
		{"entity_state"
			{selector
				{ignore_captured_by_user 0}
				{tag enemy_air}
			}
			{tag_remove enemy_air}
		}
		{"delay"
			{time 0.1}
		}
		; ---- Исключаем самолёты без тегов стадии ----
	;	{"entity_state"
	;		{selector
	;			{source advanced}
	;			{ignore_captured_by_user 0}
	;			{group
	;				{include
	;					{tag {tag air_vehicle}}
	;					{tag {tag hidden}}
	;				}
	;				{exclude
	;					{tag {tag early_war}}
	;					{tag {tag mid_war}}
	;					{tag {tag late_war}}
	;				}
	;			}
	;		}
	;	;	{tag_add no_stage}
	;	}
		{"switch"
			{"case"
				{condition
					{type cmp_i}
					{var "user_team$"}
					{op "=="}
					{value 1}
				}
				{"delay"
					{time 0.1}
				}
				{"switch"
					; ---------- РАННЯЯ СТАДИЯ (war_stage$ == 1) ----------
					{"case"
						{condition
							{type cmp_i}
							{var "war_stage$"}
							{op "=="}
							{value 1}
						}
						{"delay"
							{time 0.1}
						}
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{waypoint "6"}
							{clone}
							{approach "safe teleport & rotate"}
						}
						; ---- КОМАНДЫ ДЛЯ КЛОНОВ ----
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{tag_add enemy_air}
						}
						{"delay" {time 0.2}}
						{"actor_state"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{fire_mode return}
							{movement {speed fast}}
						}
						{"delay" {time 0.2}}
						{"action"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{drop orders}
							{action move}
							{target
								{ignore_captured_by_user 0}
								{amount 0}
								{tag ai_air_target}
							}
						}
						{"delay" {time 0.1}}
						{"effect"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{effect takeoff_load}
						}
					}
					; ---------- СРЕДНЯЯ СТАДИЯ (war_stage$ == 2) ----------
					{"case"
						{condition
							{type cmp_i}
							{var "war_stage$"}
							{op "=="}
							{value 2}
						}
						{"delay"
							{time 0.1}
						}
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{waypoint "6"}
							{clone}
							{approach "safe teleport & rotate"}
						}
						; ---- КОМАНДЫ ДЛЯ КЛОНОВ ----
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{tag_add enemy_air}
						}
						{"delay" {time 0.2}}
						{"actor_state"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{fire_mode return}
							{movement {speed fast}}
						}
						{"delay" {time 0.2}}
						{"action"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{drop orders}
							{action move}
							{target
								{ignore_captured_by_user 0}
								{amount 0}
								{tag ai_air_target}
							}
						}
						{"delay" {time 0.1}}
						{"effect"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{effect takeoff_load}
						}
					}
					; ---------- ПОЗДНЯЯ СТАДИЯ (war_stage$ == 3 или default) ----------
					{"default"
						{"delay"
							{time 0.1}
						}
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
									}
									{exclude
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{waypoint "6"}
							{clone}
							{approach "safe teleport & rotate"}
						}
						; ---- КОМАНДЫ ДЛЯ КЛОНОВ ----
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
									}
									{exclude
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{tag_add enemy_air}
						}
						{"delay" {time 0.2}}
						{"actor_state"
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
									}
									{exclude
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{fire_mode return}
							{movement {speed fast}}
						}
						{"delay" {time 0.2}}
						{"action"
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
									}
									{exclude
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{drop orders}
							{action move}
							{target
								{ignore_captured_by_user 0}
								{amount 0}
								{tag ai_air_target}
							}
						}
						{"delay" {time 0.1}}
						{"effect"
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
									}
									{exclude
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{effect takeoff_load}
						}
					}
				}
			}
			{"default"
				{"delay"
					{time 0.1}
				}
				{"switch"
					; ---------- РАННЯЯ СТАДИЯ (war_stage$ == 1) ----------
					{"case"
						{condition
							{type cmp_i}
							{var "war_stage$"}
							{op "=="}
							{value 1}
						}
						{"delay"
							{time 0.1}
						}
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{waypoint "0"}
							{clone}
							{approach "safe teleport & rotate"}
						}
						; ---- КОМАНДЫ ДЛЯ КЛОНОВ ----
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{tag_add enemy_air}
						}
						{"delay" {time 0.2}}
						{"actor_state"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{fire_mode return}
							{movement {speed fast}}
						}
						{"delay" {time 0.2}}
						{"action"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{drop orders}
							{action move}
							{target
								{ignore_captured_by_user 0}
								{amount 0}
								{tag ai_air_target}
							}
						}
						{"delay" {time 0.1}}
						{"effect"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{effect takeoff_load}
						}
					}
					; ---------- СРЕДНЯЯ СТАДИЯ (war_stage$ == 2) ----------
					{"case"
						{condition
							{type cmp_i}
							{var "war_stage$"}
							{op "=="}
							{value 2}
						}
						{"delay"
							{time 0.1}
						}
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{waypoint "0"}
							{clone}
							{approach "safe teleport & rotate"}
						}
						; ---- КОМАНДЫ ДЛЯ КЛОНОВ ----
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{tag_add enemy_air}
						}
						{"delay" {time 0.2}}
						{"actor_state"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{fire_mode return}
							{movement {speed fast}}
						}
						{"delay" {time 0.2}}
						{"action"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{drop orders}
							{action move}
							{target
								{ignore_captured_by_user 0}
								{amount 0}
								{tag ai_air_target}
							}
						}
						{"delay" {time 0.1}}
						{"effect"
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
									}
									{exclude
										{tag {tag jet}}
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{effect takeoff_load}
						}
					}
					; ---------- ПОЗДНЯЯ СТАДИЯ (war_stage$ == 3 или default) ----------
					{"default"
						{"delay"
							{time 0.1}
						}
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
									}
									{exclude
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{waypoint "0"}
							{clone}
							{approach "safe teleport & rotate"}
						}
						; ---- КОМАНДЫ ДЛЯ КЛОНОВ ----
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
									}
									{exclude
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{tag_add enemy_air}
						}
						{"delay" {time 0.2}}
						{"actor_state"
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
									}
									{exclude
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{fire_mode return}
							{movement {speed fast}}
						}
						{"delay" {time 0.2}}
						{"action"
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
									}
									{exclude
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{drop orders}
							{action move}
							{target
								{ignore_captured_by_user 0}
								{amount 0}
								{tag ai_air_target}
							}
						}
						{"delay" {time 0.1}}
						{"effect"
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
									}
									{exclude
										{tag {tag enemy_paradrop_plane}}
									;	{tag {tag no_stage}}
									}
								}
								{amount 0}
							}
							{effect takeoff_load}
						}
					}
				}
			}
		}
	}
}