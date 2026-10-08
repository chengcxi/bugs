; DSL GEM ENGINE 2 Gates of Hell
; File: 		arm_tank.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm\tank
; Created by: 	Max Drechsler
; Created:		30.08.2026
; Modify by:	Max Drechsler
; Modify:		30.08.2026
; Version:		1.0
; Description: 

; --------------- Отключение выделения вражеского танка
;//{"tank"
;//    {on spawn
;//        {if not tagged "_user"
;//            {if not user_control
;//;                {if tagged "_bot"    
;//                    {if not tagged "not_selectable" {tags add "not_selectable"}}
;//                    {able select 0}
;//;                }
;//            }    
;//        }
;//        ;; Если танк уже под управлением игрока при спавне — снимаем ограничения
;//        {if user_control
;//            {tags remove "not_selectable"}
;//            {able select 1}
;//        }
;//    }
;//
;//    ;; Если экипаж садится позже (или техника ремонтируется) — проверяем управление
;//    {on operatable on
;//        {if user_control
;//            {tags remove "not_selectable"}
;//            {able select 1}
;//        }
;//    }
;//}



;//{"tank"
;//	{on spawn
;//;//		{if tagged "_ai_defender"
;//		{if tagged "_bot"	
;//			{delay 0.1
;//				{if terrain_fx "ice"
;//					{tex_mod "winter"}
;//				else terrain_fx "snow"
;//					{tex_mod "winter"}
;//				else
;//					; do nothing
;//				}
;//				
;//;//				{set "engine_on" 0}
;//;//				{call "engine_off"}
;//;//				{tags add "immobile"}
;//;//				{tags add "no_scavenge"}
;//;//				{tags add "bunker"}	
;//			}
;//		}
;//	}
;//}