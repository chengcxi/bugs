; DSL GEM ENGINE 2 Gates of Hell
; File: 		_dcg_script_paradrop_chance.inc
; Catalog: 		map\multi\_dcg_script
; Created by: 	Max Drechsler
; Created:		31.08.2026
; Modify by:	Max Drechsler
; Modify:		31.08.2026
; Version:		1.0
; INC-injector
; Description: 

; =====================================================================
; ТАЙМЕР И ВЫБОР ЦЕЛЕЙ ДЛЯ ДЕСАНТНЫХ САМОЛЁТОВ
; Полная копия dcg/ai_air_chance и dcg/ai_air_on, адаптированная под десант
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
            {text "ARm DEBUG: ai_paradrop_chance triggered, prep_inform$ = %prep_inform$%"}
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

; =====================================================================
; ВЫБОР ЦЕЛЕЙ ДЛЯ ДЕСАНТА (аналог dcg/ai_air_on, но с paradrop)
; =====================================================================
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
            {"4.cmp_i"
                {var "ai_air_on$"}          ; используем ту же переменную для зон
                {op ">"}
                {value 0}
            }
            {"5.cmp_i"
                {var "dcg_on$"}
                {op ">"}
                {value 0}
            }
        }
    }
    {actions
        {"talk"
            {selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
            {text "DEBUG: dcg/ai_paradrop_on triggered"}
        }
        {"delay"
            {time 0.1}
        }
        {"event"
            {event "ai_paradrop_on"}        ; событие для вызова десантных самолётов
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
            {"default"
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