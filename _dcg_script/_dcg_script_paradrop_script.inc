; DSL GEM ENGINE 2 Gates of Hell
; File: 		_dcg_script_paradrop_script.inc
; Catalog: 		map\multi\_dcg_script
; Created by: 	Max Drechsler
; Created:		31.08.2026
; Modify by:	Max Drechsler
; Modify:		31.08.2026
; Version:		1.0
; INC-injector
; Description: 

; =====================================================================
; НОВЫЙ ТРИГГЕР ДЛЯ ВЫЗОВА ДЕСАНТНЫХ САМОЛЁТОВ (по тегу enemy_paradrop_plane)
; Основан на dcg/ai_airstrike, адаптирован под три стадии войны.
; =====================================================================

{"dcg/ai_paradrop_chance"
    {condition
        {terms
            {"1.event"
                {id "airplane_set"}
            }
            {"2.cmp_i"
                {var "user_team$"}
                {op ">"}
                {value 0}
            }
            {"3.cmp_i"
                {var "prep_inform$"}
                {op ">"}
                {value 0}
            }
        }
    }
    {actions
        {"talk"
            {selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
            {text "[ARm] (Paradrop): ai_paradrop_chance triggered, prep_inform$ = %prep_inform$%"}
        }
        {"event"
            {event "ai_paradrop_possible"}
            {mode reset}
            {delay 0}
        }
        {"delay"
            {time 30}
        }
        ; ----- Оригинальные инклуды (оставлены без изменений) -----
        (include "/map/multi/_dcg_script/_dcg_script_ai_air_chance_switch.inc")
        {"delay"
            {time 1}
        }
        {"switch"
            {"case"
                {condition
                    {type entities}
                    {selector
                        {source advanced}
                        {group
                            {select
                                {tag
                                    {tag command_vehicle_aa}
                                }
                            }
                            {include
                                {prop
                                    {prop vehicle}
                                }
                                {state
                                    {state inhabited}
                                }
                            }
                            {exclude
                                {tag
                                    {tag destroyed}
                                }
                            }
                        }
                    }
                }
                {"event"
                    {event "talk_on"}
                    {mode set}
                    {delay 0}
                }
                {"delay"
                    {time 6}
                }
                {"talk"
                    {selector
                        {ignore_captured_by_user 0}
                        {amount 1}
                        {tag player}
                        {zone "gamezone"}
                        {type human}
                        {state "not dead"}
                    }
                    {text "mission/multi/enemy_planes_chance_reduced"}
                }
                {"delay"
                    {time 8}
                }
                {"event"
                    {event "talk_on"}
                    {mode reset}
                    {delay 0}
                }
                {"delay"
                    {time 20}
                }
                {"switch"
                    {"case"
                        {condition
                            {type rand}
                            {value 0.35}
                        }
                        {"event"
                            {event "talk_on"}
                            {mode set}
                            {delay 0}
                        }
                        {"delay"
                            {time 6}
                        }
                        {"talk"
                            {selector
                                {ignore_captured_by_user 0}
                                {amount 1}
                                {tag player}
                                {zone "gamezone"}
                                {type human}
                                {state "not dead"}
                            }
                            {text "mission/multi/enemy_planes_continue"}
							{"objective_progress" {set 0} {add 0} {title "Aviation threat level III"}}
                            {"sound"
                                {name "world/alarm/siren01_10"}
                            }
                        }
                        {"delay"
                            {time 8}
                        }
                        {"event"
                            {event "talk_on"}
                            {mode reset}
                            {delay 0}
                        }
                        {"delay"
                            {time 12.0}
                        }
                        {"event"
                            {event "ai_paradrop_possible"}
                            {mode set}
                            {delay 0}
                        }
                        {"trigger"
                            {name "dcg/ai_paradrop_on"}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"trigger"
                            {name "dcg/ai_paradrop"}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"trigger"
                            {name "dcg/ai_paradrop_chance"}
                        }
                    }
                    {"default"
                        {"event"
                            {event "talk_on"}
                            {mode set}
                            {delay 0}
                        }
                        {"delay"
                            {time 6}
                        }
                        {"talk"
                            {selector
                                {ignore_captured_by_user 0}
                                {amount 1}
                                {tag player}
                                {zone "gamezone"}
                                {type human}
                                {state "not dead"}
                            }
                            {text "mission/multi/enemy_planes_taken_out"}
							{"objective_progress" {set 0} {add 0} {title "Aviation threat level II"}}
                            {"sound"
                                {name "mission/task_fail"}
                            }
                        }
                        {"delay"
                            {time 8}
                        }
                        {"event"
                            {event "talk_on"}
                            {mode reset}
                            {delay 0}
                        }
                    }
                }
            }
            {"default"
                {"switch"
                    {"case"
                        (include "/map/multi/_dcg_script/_dcg_script_ai_air_reduce_chance.inc")
                        {"event"
                            {event "talk_on"}
                            {mode set}
                            {delay 0}
                        }
                        {"delay"
                            {time 6}
                        }
                        {"talk"
                            {selector
                                {ignore_captured_by_user 0}
                                {amount 1}
                                {tag player}
                                {zone "gamezone"}
                                {type human}
                                {state "not dead"}
                            }
                            {text "mission/multi/enemy_planes_continue"}
							{"objective_progress" {set 0} {add 0} {title "Aviation threat level III"}}
                        }
                        {"sound"
                            {name "world/alarm/siren01_10"}
                        }
                        {"delay"
                            {time 8}
                        }
                        {"event"
                            {event "talk_on"}
                            {mode reset}
                            {delay 0}
                        }
                        {"delay"
                            {time 12.0}
                        }
                        {"event"
                            {event "ai_paradrop_possible"}
                            {mode set}
                            {delay 0}
                        }
                        {"trigger"
                            {name "dcg/ai_paradrop_on"}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"trigger"
                            {name "dcg/ai_paradrop"}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"trigger"
                            {name "dcg/ai_paradrop_chance"}
                        }
                    }
                    {"default"
                        {"event"
                            {event "talk_on"}
                            {mode set}
                            {delay 0}
                        }
                        {"delay"
                            {time 6}
                        }
                        {"talk"
                            {selector
                                {ignore_captured_by_user 0}
                                {amount 1}
                                {tag player}
                                {zone "gamezone"}
                                {type human}
                                {state "not dead"}
                            }
                            {text "mission/multi/enemy_planes_taken_out"}
							{"objective_progress" {set 0} {add 0} {title "Aviation threat level II"}}
                        }
                        {"sound"
                            {name "world/alarm/siren01_10"}
                        }
                        {"delay"
                            {time 8}
                        }
                        {"event"
                            {event "talk_on"}
                            {mode reset}
                            {delay 0}
                        }
                    }
                }
            }
        }
    }
}

{"dcg/ai_paradrop"
    {condition
        {terms
            {"1.event"
                {id "ai_paradrop_on"}
            }
        }
    }
    {actions
		{"objective_progress" {set 0} {add 0} {title "[ARm] (Paradrop): Paradrop logic triggered"}}
		{"talk" {selector {ignore_captured_by_user 0} {amount 1} {tag _user} {zone "gamezone"} {type human} {state "not dead"}} {text "DEBUG: dcg/ai_paradrop executed"}}
        {"delay" {time 0.1}}
        {"entity_state" {selector {ignore_captured_by_user 0} {tag enemy_air}} {tag_remove enemy_air}}
        {"delay" {time 0.1}}

        {"switch"
            {"case"
                {condition {type cmp_i} {var "user_team$"} {op "=="} {value 1}}
                {"delay" {time 0.1}}
                {"switch"
                    ; ---------- РАННЯЯ (waypoint "6" -> spawn_b) ----------
                    {"case"
                        {condition {type cmp_i} {var "war_stage$"} {op "=="} {value 1}}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag early_war}}
                                    }
                                    {exclude}
                                }
                                {amount 2}
                            }
                            {waypoint "4"}
                            {clone}
                            {approach "safe teleport & rotate"}
                        }
                        ; ----- КОМАНДЫ ДЛЯ КЛОНОВ (spawn_b) -----
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag early_war}}
                                    }
                                    {exclude}
                                }
                                {amount 2}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag early_war}}
                                    }
                                    {exclude}
                                }
                                {amount 2}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag early_war}}
                                    }
                                    {exclude}
                                }
                                {amount 2}
                            }
                            {drop orders}
                            {action move}
                            {target
                                {ignore_captured_by_user 0}
                                {amount 1}
                                {tag spawn_b}      ; <-- ИСПРАВЛЕНО
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag early_war}}
                                    }
                                    {exclude}
                                }
                                {amount 2}
                            }
                            {effect takeoff_load}
                        }
                    }
                    ; ---------- СРЕДНЯЯ (waypoint "6" -> spawn_b) ----------
                    {"case"
                        {condition {type cmp_i} {var "war_stage$"} {op "=="} {value 2}}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag mid_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {waypoint "4"}
                            {clone}
                            {approach "safe teleport & rotate"}
                        }
                        ; ----- КОМАНДЫ ДЛЯ КЛОНОВ (spawn_b) -----
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag mid_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag mid_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag mid_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {drop orders}
                            {action move}
                            {target
                                {ignore_captured_by_user 0}
                                {amount 1}
                                {tag spawn_b}      ; <-- ИСПРАВЛЕНО
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag mid_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {effect takeoff_load}
                        }
                    }
                    ; ---------- ПОЗДНЯЯ (waypoint "6" -> spawn_b) ----------
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag late_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {waypoint "4"}
                            {clone}
                            {approach "safe teleport & rotate"}
                        }
                        ; ----- КОМАНДЫ ДЛЯ КЛОНОВ (spawn_b) -----
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag late_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag late_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag late_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {drop orders}
                            {action move}
                            {target
                                {ignore_captured_by_user 0}
                                {amount 1}
                                {tag spawn_b}      ; <-- ИСПРАВЛЕНО
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag late_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {effect takeoff_load}
                        }
                    }
                }
            }
            {"default"      ; вторая сторона (user_team$ != 1) – waypoint "0" -> spawn_a
                {"delay" {time 0.1}}
                {"switch"
                    ; ---------- РАННЯЯ (waypoint "0" -> spawn_a) ----------
                    {"case"
                        {condition {type cmp_i} {var "war_stage$"} {op "=="} {value 1}}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag early_war}}
                                    }
                                    {exclude}
                                }
                                {amount 2}
                            }
                            {waypoint "5"}
                            {clone}
                            {approach "safe teleport & rotate"}
                        }
                        ; ----- КОМАНДЫ ДЛЯ КЛОНОВ (spawn_a) -----
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag early_war}}
                                    }
                                    {exclude}
                                }
                                {amount 2}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag early_war}}
                                    }
                                    {exclude}
                                }
                                {amount 2}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag early_war}}
                                    }
                                    {exclude}
                                }
                                {amount 2}
                            }
                            {drop orders}
                            {action move}
                            {target
                                {ignore_captured_by_user 0}
                                {amount 1}
                                {tag spawn_a}      ; <-- ИСПРАВЛЕНО
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag early_war}}
                                    }
                                    {exclude}
                                }
                                {amount 2}
                            }
                            {effect takeoff_load}
                        }
                    }
                    ; ---------- СРЕДНЯЯ (waypoint "0" -> spawn_a) ----------
                    {"case"
                        {condition {type cmp_i} {var "war_stage$"} {op "=="} {value 2}}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag mid_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {waypoint "5"}
                            {clone}
                            {approach "safe teleport & rotate"}
                        }
                        ; ----- КОМАНДЫ ДЛЯ КЛОНОВ (spawn_a) -----
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag mid_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag mid_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag mid_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {drop orders}
                            {action move}
                            {target
                                {ignore_captured_by_user 0}
                                {amount 1}
                                {tag spawn_a}      ; <-- ИСПРАВЛЕНО
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag mid_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {effect takeoff_load}
                        }
                    }
                    ; ---------- ПОЗДНЯЯ (waypoint "0" -> spawn_a) ----------
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag late_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {waypoint "5"}
                            {clone}
                            {approach "safe teleport & rotate"}
                        }
                        ; ----- КОМАНДЫ ДЛЯ КЛОНОВ (spawn_a) -----
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag late_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag late_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag late_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {drop orders}
                            {action move}
                            {target
                                {ignore_captured_by_user 0}
                                {amount 1}
                                {tag spawn_a}      ; <-- ИСПРАВЛЕНО
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
                                        {tag {tag enemy_paradrop_plane}}
                                        {tag {tag late_war}}
                                    }
                                    {exclude}
                                }
                                {amount 3}
                            }
                            {effect takeoff_load}
                        }
                    }
                }
            }
        }
    }
}

{"dcg/ai_paradrop_on"
    {condition
        {terms
            {"1.event"
                {id "ai_paradrop_possible"}
            }
            {"2.cmp_i"
                {var "enemyid$"}
                {op ">"}
                {value 0}
            }
            {"3.entities"
                {selector
                    {ignore_captured_by_user 0}
                    {tag _user}
                    {zone "gamezone"}
                    {state operatable}
                }
            }
            ; Условие ai_air_on$ > 0 УБРАНО – теперь триггер срабатывает при любом значении ai_air_on$
            {"4.cmp_i"
                {var "dcg_on$"}
                {op ">"}
                {value 0}
            }
        }
    }
    {actions
        {"talk"
            {selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
            {text "[ARm] (Paradrop): dcg/ai_paradrop_on triggered"}
        }
        {"delay"
            {time 0.1}
        }
        {"event"
            {event "ai_paradrop_on"}
            {mode set}
            {delay 0}
        }
        {"delay"
            {time 1}
        }
        {"entity_state"
            {selector
                {ignore_captured_by_user 0}
                {tag ai_air_target}
            }
            {tag_remove ai_air_target}
        }
        {"delay"
            {time 5}
        }
        ; ----- ВЫБОР ЦЕЛЕЙ (полностью скопировано из dcg/ai_air_on) -----
        {"switch"
            {"case"
                {condition
                    {type entities}
                    {selector
                        {source advanced}
                        {ignore_captured_by_user 0}
                        {group
                            {select
                                {tag
                                    {tag _user}
                                }
                            }
                            {include
                                {zone
                                    {zone "combat"}
                                }
                                {prop
                                    {prop vehicle}
                                }
                                {state
                                    {state operatable}
                                }
                                {state
                                    {state user_control}
                                }
                            }
                            {exclude
                                {tag
                                    {tag destroyed}
                                }
                            }
                        }
                    }
                }
                {"delay"
                    {time 0.1}
                }
                {"switch"
                    {"case"
                        {condition
                            {type cmp_i}
                            {var "ai_air_on$"}
                            {op "=="}
                            {value 5}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"entity_state"
                            {selector
                                {source advanced}
                                {ignore_captured_by_user 0}
                                {group
                                    {select
                                        {tag
                                            {tag _user}
                                        }
                                    }
                                    {include
                                        {zone
                                            {zone "gamezone"}
                                        }
                                        {prop
                                            {prop vehicle}
                                        }
                                        {state
                                            {state operatable}
                                        }
                                        {state
                                            {state user_control}
                                        }
                                    }
                                    {exclude
                                        {tag
                                            {tag destroyed}
                                        }
                                    }
                                }
                                {sort
                                    {type waypoint}
                                    {wpid "5"}
                                }
                                {amount 1
                                }
                            }
                            {tag_add ai_air_target}
                        }
                    }
                    {"case"
                        {condition
                            {type cmp_i}
                            {var "ai_air_on$"}
                            {op "=="}
                            {value 2}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"entity_state"
                            {selector
                                {source advanced}
                                {ignore_captured_by_user 0}
                                {group
                                    {select
                                        {tag
                                            {tag _user}
                                        }
                                    }
                                    {include
                                        {zone
                                            {zone "gamezone"}
                                        }
                                        {prop
                                            {prop vehicle}
                                        }
                                        {state
                                            {state operatable}
                                        }
                                        {state
                                            {state user_control}
                                        }
                                    }
                                    {exclude
                                        {tag
                                            {tag destroyed}
                                        }
                                    }
                                }
                                {sort
                                    {type waypoint}
                                    {wpid "2"}
                                }
                                {amount 1
                                }
                            }
                            {tag_add ai_air_target}
                        }
                    }
                    {"case"
                        {condition
                            {type cmp_i}
                            {var "ai_air_on$"}
                            {op "=="}
                            {value 3}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"entity_state"
                            {selector
                                {source advanced}
                                {ignore_captured_by_user 0}
                                {group
                                    {select
                                        {tag
                                            {tag _user}
                                        }
                                    }
                                    {include
                                        {zone
                                            {zone "gamezone"}
                                        }
                                        {prop
                                            {prop vehicle}
                                        }
                                        {state
                                            {state operatable}
                                        }
                                        {state
                                            {state user_control}
                                        }
                                    }
                                    {exclude
                                        {tag
                                            {tag destroyed}
                                        }
                                    }
                                }
                                {sort
                                    {type waypoint}
                                    {wpid "3"}
                                }
                                {amount 1
                                }
                            }
                            {tag_add ai_air_target}
                        }
                    }
                    {"case"
                        {condition
                            {type cmp_i}
                            {var "ai_air_on$"}
                            {op "=="}
                            {value 4}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"entity_state"
                            {selector
                                {source advanced}
                                {ignore_captured_by_user 0}
                                {group
                                    {select
                                        {tag
                                            {tag _user}
                                        }
                                    }
                                    {include
                                        {zone
                                            {zone "gamezone"}
                                        }
                                        {prop
                                            {prop vehicle}
                                        }
                                        {state
                                            {state operatable}
                                        }
                                        {state
                                            {state user_control}
                                        }
                                    }
                                    {exclude
                                        {tag
                                            {tag destroyed}
                                        }
                                    }
                                }
                                {sort
                                    {type waypoint}
                                    {wpid "4"}
                                }
                                {amount 1
                                }
                            }
                            {tag_add ai_air_target}
                        }
                    }
                    {"default"
                        {"delay"
                            {time 0.1}
                        }
                        {"entity_state"
                            {selector
                                {source advanced}
                                {ignore_captured_by_user 0}
                                {group
                                    {select
                                        {tag
                                            {tag _user}
                                        }
                                    }
                                    {include
                                        {zone
                                            {zone "gamezone"}
                                        }
                                        {prop
                                            {prop vehicle}
                                        }
                                        {state
                                            {state operatable}
                                        }
                                        {state
                                            {state user_control}
                                        }
                                    }
                                    {exclude
                                        {tag
                                            {tag destroyed}
                                        }
                                    }
                                }
                                {sort
                                    {type waypoint}
                                    {wpid "1"}
                                }
                                {amount 1
                                }
                            }
                            {tag_add ai_air_target}
                        }
                    }
                }
            }
            {"default"      ; если цели не найдены в combat, берём из gamezone
                {"delay"
                    {time 0.1}
                }
                {"switch"
                    {"case"
                        {condition
                            {type cmp_i}
                            {var "ai_air_on$"}
                            {op "=="}
                            {value 5}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"entity_state"
                            {selector
                                {source advanced}
                                {ignore_captured_by_user 0}
                                {group
                                    {select
                                        {tag
                                            {tag _user}
                                        }
                                    }
                                    {include
                                        {zone
                                            {zone "gamezone"}
                                        }
                                        {state
                                            {state "operatable user_control"}
                                        }
                                    }
                                    {exclude
                                        {state
                                            {state inactive}
                                        }
                                    }
                                }
                                {sort
                                    {type waypoint}
                                    {wpid "5"}
                                }
                                {amount 1
                                }
                            }
                            {tag_add ai_air_target}
                        }
                    }
                    {"case"
                        {condition
                            {type cmp_i}
                            {var "ai_air_on$"}
                            {op "=="}
                            {value 2}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"entity_state"
                            {selector
                                {source advanced}
                                {ignore_captured_by_user 0}
                                {group
                                    {select
                                        {tag
                                            {tag _user}
                                        }
                                    }
                                    {include
                                        {zone
                                            {zone "gamezone"}
                                        }
                                        {state
                                            {state "operatable user_control"}
                                        }
                                    }
                                    {exclude
                                        {state
                                            {state inactive}
                                        }
                                    }
                                }
                                {sort
                                    {type waypoint}
                                    {wpid "2"}
                                }
                                {amount 1
                                }
                            }
                            {tag_add ai_air_target}
                        }
                    }
                    {"case"
                        {condition
                            {type cmp_i}
                            {var "ai_air_on$"}
                            {op "=="}
                            {value 3}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"entity_state"
                            {selector
                                {source advanced}
                                {ignore_captured_by_user 0}
                                {group
                                    {select
                                        {tag
                                            {tag _user}
                                        }
                                    }
                                    {include
                                        {zone
                                            {zone "gamezone"}
                                        }
                                        {state
                                            {state "operatable user_control"}
                                        }
                                    }
                                    {exclude
                                        {state
                                            {state inactive}
                                        }
                                    }
                                }
                                {sort
                                    {type waypoint}
                                    {wpid "3"}
                                }
                                {amount 1
                                }
                            }
                            {tag_add ai_air_target}
                        }
                    }
                    {"case"
                        {condition
                            {type cmp_i}
                            {var "ai_air_on$"}
                            {op "=="}
                            {value 4}
                        }
                        {"delay"
                            {time 0.1}
                        }
                        {"entity_state"
                            {selector
                                {source advanced}
                                {ignore_captured_by_user 0}
                                {group
                                    {select
                                        {tag
                                            {tag _user}
                                        }
                                    }
                                    {include
                                        {zone
                                            {zone "gamezone"}
                                        }
                                        {state
                                            {state "operatable user_control"}
                                        }
                                    }
                                    {exclude
                                        {state
                                            {state inactive}
                                        }
                                    }
                                }
                                {sort
                                    {type waypoint}
                                    {wpid "4"}
                                }
                                {amount 1
                                }
                            }
                            {tag_add ai_air_target}
                        }
                    }
                    {"default"
                        {"delay"
                            {time 0.1}
                        }
                        {"entity_state"
                            {selector
                                {source advanced}
                                {ignore_captured_by_user 0}
                                {group
                                    {select
                                        {tag
                                            {tag _user}
                                        }
                                    }
                                    {include
                                        {zone
                                            {zone "gamezone"}
                                        }
                                        {state
                                            {state "operatable user_control"}
                                        }
                                    }
                                    {exclude
                                        {state
                                            {state inactive}
                                        }
                                    }
                                }
                                {sort
                                    {type waypoint}
                                    {wpid "1"}
                                }
                                {amount 1
                                }
                            }
                            {tag_add ai_air_target}
                        }
                    }
                }
            }
        }
    }
}