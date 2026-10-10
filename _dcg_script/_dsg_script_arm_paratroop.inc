;file: _dsg_script_arm_paratroop.inc
;catalog: multi\_dcg_script
;GEM ENGINE 2 - paratroop macros
;modify by Max Drechsler
;23.08.2026
;version v3.0


;//{"airborne/lua_assign_paratroopers"
;//    {condition
;//        {terms
;//            {"1.cmp_i"
;//                {var "ARm_enemy_id"}
;//                {op ">"}
;//                {value 0}
;//            }
;//        }
;//    }
;//    {actions
;//        {"lua"
;//            {script "assign_paratroopers_from_global()"}
;//        }
;//    }
;//}

;//{"airborne/assign_enemy"
;//    {condition
;//        {terms
;//            {"1.cmp_i" {var "enemyid$"} {op ">"} {value 0}}
;//            {"2.entities"
;//                {selector
;//                    {ignore_captured_by_user 0}
;//                    {tag paratrooper}
;//                    {state "not dead"}
;//                    {exclude {tag assigned_to_enemy}}
;//                    {exclude {tag player_paratrooper}}
;//                }
;//            }
;//        }
;//    }
;//    {actions
;//        {"switch"
;//            {"case" {condition {type cmp_i} {var "enemyid$"} {op "=="} {value 1}}
;//                {"player"
;//                    {selector
;//                        {ignore_captured_by_user 0}
;//                        {tag paratrooper}
;//                        {state "not dead"}
;//                        {exclude {tag assigned_to_enemy}}
;//                        {exclude {tag player_paratrooper}}
;//                    }
;//                    {operation set} {player 1}
;//                }
;//            }
;//            {"case" {condition {type cmp_i} {var "enemyid$"} {op "=="} {value 2}}
;//                {"player"
;//                    {selector
;//                        {ignore_captured_by_user 0}
;//                        {tag paratrooper}
;//                        {state "not dead"}
;//                        {exclude {tag assigned_to_enemy}}
;//                        {exclude {tag player_paratrooper}}
;//                    }
;//                    {operation set} {player 2}
;//                }
;//            }
;//            {"case" {condition {type cmp_i} {var "enemyid$"} {op "=="} {value 3}}
;//                {"player"
;//                    {selector
;//                        {ignore_captured_by_user 0}
;//                        {tag paratrooper}
;//                        {state "not dead"}
;//                        {exclude {tag assigned_to_enemy}}
;//                        {exclude {tag player_paratrooper}}
;//                    }
;//                    {operation set} {player 3}
;//                }
;//            }
;//            {"case" {condition {type cmp_i} {var "enemyid$"} {op "=="} {value 4}}
;//                {"player"
;//                    {selector
;//                        {ignore_captured_by_user 0}
;//                        {tag paratrooper}
;//                        {state "not dead"}
;//                        {exclude {tag assigned_to_enemy}}
;//                        {exclude {tag player_paratrooper}}
;//                    }
;//                    {operation set} {player 4}
;//                }
;//            }
;//            {"case" {condition {type cmp_i} {var "enemyid$"} {op "=="} {value 5}}
;//                {"player"
;//                    {selector
;//                        {ignore_captured_by_user 0}
;//                        {tag paratrooper}
;//                        {state "not dead"}
;//                        {exclude {tag assigned_to_enemy}}
;//                        {exclude {tag player_paratrooper}}
;//                    }
;//                    {operation set} {player 5}
;//                }
;//            }
;//            {"case" {condition {type cmp_i} {var "enemyid$"} {op "=="} {value 11}}
;//                {"player"
;//                    {selector
;//                        {ignore_captured_by_user 0}
;//                        {tag paratrooper}
;//                        {state "not dead"}
;//                        {exclude {tag assigned_to_enemy}}
;//                        {exclude {tag player_paratrooper}}
;//                    }
;//                    {operation set} {player 11}
;//                }
;//            }
;//            {"default"
;//                {"player"
;//                    {selector
;//                        {ignore_captured_by_user 0}
;//                        {tag paratrooper}
;//                        {state "not dead"}
;//                        {exclude {tag assigned_to_enemy}}
;//                        {exclude {tag player_paratrooper}}
;//                    }
;//                    {operation set} {player 1}
;//                }
;//            }
;//        }
;//
;//        ; ===== Поведение для ботов =====
;//        {"actor_state"
;//            {selector
;//                {ignore_captured_by_user 0}
;//                {tag paratrooper}
;//                {state "not dead"}
;//                {exclude {tag assigned_to_enemy}}
;//                {exclude {tag player_paratrooper}}
;//            }
;//            {move_mode free}
;//            {fire_mode open}
;//            {ai_move {mode enable}}
;//        }
;//
;//        ; ===== Поведение для игрока (если вдруг попадут) =====
;//        {"actor_state"
;//            {selector
;//                {ignore_captured_by_user 0}
;//                {tag player_paratrooper}
;//                {state "not dead"}
;//            }
;//            {move_mode free}
;//            {fire_mode open}
;//            {ai_move {mode enable}}
;//        }
;//
;//        ; ===== Маркировка обработанных =====
;//        {"entity_state"
;//            {selector
;//                {ignore_captured_by_user 0}
;//                {tag paratrooper}
;//                {state "not dead"}
;//                {exclude {tag assigned_to_enemy}}
;//                {exclude {tag player_paratrooper}}
;//            }
;//            {tag_add assigned_to_enemy}
;//        }
;//
;//        {"delay" {time 0.02}}
;//        {"trigger" {name "airborne/assign_enemy"}}
;//    }
;//}