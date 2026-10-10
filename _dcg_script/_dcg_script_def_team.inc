; DSL GEM ENGINE 2 Gates of Hell
; File: 		_dcg_script_def_team.inc
; Catalog: 		map\multi\_dcg_script
; Created by: 	Max Drechsler
; Created:		30.08.2026
; Modify by:	Max Drechsler
; Modify:		01.09.2026
; Version:		1.7
; INC-injector
; Description: 
; - Определение защитника (def_team$)
; - Удаление мин (зависит от tier2$)
; - Логика war_stage$ вычисляется в скрипте на основе наличия техники

{"dcg/def_team"
    {condition
        {terms
            {"1.event" {id "dcg"}}
            {"2.cmp_i" {var "user_team$"} {op ">"} {value 0}}
            {"3.cmp_i" {var "enemyid$"} {op ">"} {value 0}}
        }
    }
    {actions
        ; ===== ОТЛАДКА =====
        {"objective_progress" {set 0} {add 0} {title "DEBUG: def_team"}}
        {"delay" {time 0.1}}
        ; ===================

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
                            {exclude {tag {tag def_team_2}} {state {state inactive}}}
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
                            {select {tag {tag mine_planted}} {tag {tag dcg_mine_sign}}}
                            {include {tag {tag cmp_def}} {state {state inactive}}}
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
                            {exclude {tag {tag def_team_1}} {state {state inactive}}}
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

        ; ---- УДАЛЕНИЕ МИН (зависит от tier2$) ----
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
                            {select {tag {tag mine_planted}} {tag {tag dcg_mine_sign}}}
                            {include {tag {tag cmp_def}} {state {state inactive}}}
                        }
                    }
                }
            }
        }

        ; ---- ВЫЧИСЛЕНИЕ war_stage$ (по тегам техники) ----
        {"set_i" {var "war_stage$"} {op "="} {value 1}}   ; по умолчанию ранняя

        ; Проверяем наличие поздней техники (late_war)
        {"if"
            {condition
                {type entities}
                {selector
                    {source advanced}
                    {ignore_captured_by_user 0}
                    {group
                        {select
                            {tag "1_a_3"} {tag "1_b_3"}
                            {tag "2_a_3"} {tag "2_b_3"}
                            {tag "3_a_3"} {tag "3_b_3"}
                            {tag "4_a_3"} {tag "4_b_3"}
                            {tag "5_a_3"} {tag "5_b_3"}
                        }
                        {include {zone {zone "combat"}}}
                        {exclude {state {state inactive}}}
                    }
                }
            }
            {"set_i" {var "war_stage$"} {op "="} {value 3}}
        }

        ; Проверяем наличие средней техники (mid_war), если ещё не поздняя
        {"if"
            {condition
                {type entities}
                {selector
                    {source advanced}
                    {ignore_captured_by_user 0}
                    {group
                        {select
                            {tag "1_a_2"} {tag "1_b_2"}
                            {tag "2_a_2"} {tag "2_b_2"}
                            {tag "3_a_2"} {tag "3_b_2"}
                            {tag "4_a_2"} {tag "4_b_2"}
                            {tag "5_a_2"} {tag "5_b_2"}
                        }
                        {include {zone {zone "combat"}}}
                        {exclude {state {state inactive}}}
                    }
                }
            }
            {"if"
                {condition {type cmp_i} {var "war_stage$"} {op "!="} {value 3}}
                {"set_i" {var "war_stage$"} {op "="} {value 2}}
            }
        }

        ; Если война поздняя или средняя – ставим tier2$ = 1 (для мин)
        {"if"
            {condition {type cmp_i} {var "war_stage$"} {op ">"} {value 1}}
            {"set_i" {var "tier2$"} {op "="} {value 1}}
            {"set_i" {var "tier2$"} {op "="} {value 0}}
        }

        ; ===== ОТЛАДКА =====
        {"objective_progress" {set 0} {add 0} {title "DEBUG: war_stage calc done"}}
        {"talk"
            {selector {ignore_captured_by_user 0} {amount 1} {tag player} {zone "gamezone"} {type human} {state "not dead"}}
            {text "DEBUG: war_stage$ = %war_stage$%"}
        }
        ; ===================

        {"delay" {time 1}}
        {"delete"
            {selector
                {source advanced}
                {ignore_captured_by_user 0}
                {group
                    {select {tag {tag def_team_1}} {tag {tag def_team_2}}}
                }
            }
        }
    }
}