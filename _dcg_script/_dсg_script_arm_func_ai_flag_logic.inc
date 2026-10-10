; dsg_script_arm_func_ai_flag_logic.inc
;

{"random_cycle_defenders"
    {condition
        {terms
            {"1.event"
                {id "init"}
            }
        }
    }
    {actions
        {"delay"
            {time 0.1}
        }
        {"set_i"
            {var "current_flag$"}
            {op "="}
            {value 1}
        }
        {"set_i"
            {var "max_flags$"}
            {op "="}
            {value 5}
        }
        {"trigger"
            {name "random_cycle_defenders_loop"}
        }
    }
}

{"random_cycle_defenders_loop"
    {condition
        {terms
            {"1.timer"
                {timer_name "change_position_timer"}
                {expired true}
            }
        }
    }
    {actions
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
                            {tag defender_group}
                        }
                    }
                }
            }
            {position_move_to
                {destination
                    {zone
                        {zone "flag_point_{current_flag$}"}
                    }
                }
            }
        }
        {"switch"
            {"case"
                {condition
                    {type rand}
                    {value 0.2} // Вероятность смены флага на каждый ход
                }
                {"set_i"
                    {var "next_random_flag$"}
                    {op "=rand"}
                    {min 1}
                    {max "max_flags$"}
                }
                {"while_equal"
                    {var "next_random_flag$"}
                    {value "current_flag$"}
                }
                {"set_i"
                    {var "current_flag$"}
                    {op "="}
                    {value "next_random_flag$"}
                }
            }
        }
        {"set_duration"
            {timer_name "change_position_timer"}
            {value "({rand 300 540})"} // Генерируем случайное время от 5 до 9 минут (300–540 секунд)
        }
        {"trigger"
            {name "random_cycle_defenders_loop"}
        }
    }
}