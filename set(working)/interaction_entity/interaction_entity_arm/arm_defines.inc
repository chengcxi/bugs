; File: 		arm_defines.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm
; Created by: 	Max Drechsler
; Created:		07.09.2026
; Modify by:	Max Drechsler
; Modify:		07.09.2026
; DSL:			GEM ENGINE 2 Gates of Hell
; Version:		x.x
; Description: 	DEFINES – макросы для присвоения тегов воздушным юнитам

; DEFINES

;//	("tag_airborne_recon")
;//	("tag_airborne_recon_ai")
;//	("tag_airborne_fighter")
;//	("tag_airborne_fighter_ai")
;//	("tag_airborne_jet_fighter")
;//	("tag_airborne_jet_fighter_ai")
;//	("tag_airborne_bomber")
;//	("tag_airborne_bomber_ai")
;//	("tag_airborne_jet_bomber")
;//	("tag_airborne_jet_bomber_ai")
;//	("tag_airborne_cargo")
;//	("tag_airborne_cargo_ai")
;//	("tag_airborne_ger")
;//	("tag_airborne_rus")
;//	("tag_airborne_fin")
;//	("tag_airborne_usa")
;//	("tag_airborne_eng")

; ==================== MAIN (игровые) ====================
; Логика сортировки:
;   {tagged "hidden"} — AI-клон (враг, из maceairstrike / dcg/ai_airstrike) → talk_*_ai
;   НЕ hidden         — юнит игрока → talk_*_player

; — recon
(define "tag_airborne_recon"
    {tags add "altitude_high"}
    {tags add "air_vehicle"}
)

; — fighter
(define "tag_airborne_fighter"
    {tags add "air_vehicle"}
    {if tagged "hidden"
    ;   {tags add "altitude_high"}
        {tags add "talk_fighter_ai"}
        {tags add "air_ai_vehicle"}
    else
        {tags add "talk_fighter_player"}
    }
; - ARM 110926 backup — старая логика на _user/_user_ally (не работала на on spawn)
;//	{if tagged "_user_ally"
;//		{tags add "talk_fighter_player"}
;//	else
;//		{tags add "talk_fighter_ai"}
;//	}
;//	{if tagged "_user"
;//		{tags add "talk_fighter_player"}
;//	else
;//		{tags add "talk_fighter_ai"}
;//		{tags add "air_ai_vehicle"}
;//	}
;//	{if tagged "hidden"
;//		{if not tagged "talk_fighter_ai"
;//			{tags add "talk_fighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_ger"
;//		{if not tagged "talk_fighter_ai"
;//			{tags add "talk_fighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_rus"
;//		{if not tagged "talk_fighter_ai"
;//			{tags add "talk_fighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_fin"
;//		{if not tagged "talk_fighter_ai"
;//			{tags add "talk_fighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_usa"
;//		{if not tagged "talk_fighter_ai"
;//			{tags add "talk_fighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_eng"
;//		{if not tagged "talk_fighter_ai"
;//			{tags add "talk_fighter_ai"}
;//		}
;//	}
)

; — heavy fighter
(define "tag_airborne_hvfighter"
    {tags add "air_vehicle"}
    {if tagged "hidden"
    ;   {tags add "altitude_high"}
        {tags add "talk_hvfighter_ai"}
        {tags add "air_ai_vehicle"}
    else
        {tags add "talk_hvfighter_player"}
    }
; - ARM 110926 backup — старая логика
;//	{if tagged "_user_ally"
;//		{tags add "talk_hvfighter_player"}
;//	else
;//		{tags add "talk_hvfighter_ai"}
;//	}
;//	{if tagged "_user"
;//		{tags add "talk_hvfighter_player"}
;//	else
;//		{tags add "talk_hvfighter_ai"}
;//		{tags add "air_ai_vehicle"}
;//	}
;//	{if tagged "hidden"
;//		{if not tagged "talk_hvfighter_ai"
;//			{tags add "talk_hvfighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_ger"
;//		{if not tagged "talk_hvfighter_ai"
;//			{tags add "talk_hvfighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_rus"
;//		{if not tagged "talk_hvfighter_ai"
;//			{tags add "talk_hvfighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_fin"
;//		{if not tagged "talk_hvfighter_ai"
;//			{tags add "talk_hvfighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_usa"
;//		{if not tagged "talk_hvfighter_ai"
;//			{tags add "talk_hvfighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_eng"
;//		{if not tagged "talk_hvfighter_ai"
;//			{tags add "talk_hvfighter_ai"}
;//		}
;//	}
)

; — bomber
(define "tag_airborne_bomber"
    {tags add "air_vehicle"}
    {if tagged "hidden"
    ;    {tags add "altitude_high"}
        {tags add "talk_bomber_ai"}
        {tags add "air_ai_vehicle"}
    else
        {tags add "talk_bomber_player"}
    }
; - ARM 110926 backup — старая логика
;//	{if tagged "_user_ally"
;//		{tags add "talk_bomber_player"}
;//	else
;//		{tags add "talk_bomber_ai"}
;//		{tags add "air_ai_vehicle"}
;//	}
;//	{if tagged "_user"
;//		{tags add "talk_bomber_player"}
;//	else
;//		{tags add "talk_bomber_ai"}
;//		{tags add "air_ai_vehicle"}
;//	}
;//	{if tagged "hidden"
;//		{if not tagged "talk_bomber_ai"
;//			{tags add "talk_bomber_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_ger"
;//		{if not tagged "talk_bomber_ai"
;//			{tags add "talk_bomber_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_rus"
;//		{if not tagged "talk_bomber_ai"
;//			{tags add "talk_bomber_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_fin"
;//		{if not tagged "talk_bomber_ai"
;//			{tags add "talk_bomber_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_usa"
;//		{if not tagged "talk_bomber_ai"
;//			{tags add "talk_bomber_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_eng"
;//		{if not tagged "talk_bomber_ai"
;//			{tags add "talk_bomber_ai"}
;//		}
;//	}
)

; — cargo
(define "tag_airborne_cargo"
    {tags add "air_vehicle"}
    {if tagged "hidden"
        {tags add "talk_cargo_ai"}
        {tags add "air_ai_vehicle"}
    else
        {tags add "talk_cargo"}
    }
; - ARM 110926 backup — старая логика
;//	{if tagged "_user_ally"
;//		{tags add "talk_cargo"}
;//	else
;//		{tags add "talk_cargo_ai"}
;//		{tags add "air_ai_vehicle"}
;//	}
;//	{if tagged "_user"
;//		{tags add "talk_cargo"}
;//	else
;//		{tags add "talk_cargo_ai"}
;//		{tags add "air_ai_vehicle"}
;//	}
;//	{if tagged "hidden"
;//		{if not tagged "talk_cargo_ai"
;//			{tags add "talk_cargo_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_ger"
;//		{if not tagged "talk_cargo_ai"
;//			{tags add "talk_cargo_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_rus"
;//		{if not tagged "talk_cargo_ai"
;//			{tags add "talk_cargo_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_fin"
;//		{if not tagged "talk_cargo_ai"
;//			{tags add "talk_cargo_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_usa"
;//		{if not tagged "talk_cargo_ai"
;//			{tags add "talk_cargo_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_eng"
;//		{if not tagged "talk_cargo_ai"
;//			{tags add "talk_cargo_ai"}
;//		}
;//	}
)

; — jet fighter
(define "tag_airborne_jet_fighter"
    {tags add "air_vehicle"}
    {if tagged "hidden"
    ;   {tags add "altitude_high"}
        {tags add "talk_jetfighter_ai"}
        {tags add "air_ai_vehicle"}
    else
        {tags add "talk_jetfighter_player"}
    }
; - ARM 110926 backup — старая логика
;//	{if tagged "_user_ally"
;//		{tags add "talk_jetfighter_player"}
;//	else
;//		{tags add "talk_jetfighter_ai"}
;//	}
;//	{if tagged "_user"
;//		{tags add "talk_jetfighter_player"}
;//	else
;//		{tags add "talk_jetfighter_ai"}
;//		{tags add "air_ai_vehicle"}
;//	}
;//	{if tagged "hidden"
;//		{if not tagged "talk_jetfighter_ai"
;//			{tags add "talk_jetfighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_ger"
;//		{if not tagged "talk_jetfighter_ai"
;//			{tags add "talk_jetfighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_rus"
;//		{if not tagged "talk_jetfighter_ai"
;//			{tags add "talk_jetfighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_fin"
;//		{if not tagged "talk_jetfighter_ai"
;//			{tags add "talk_jetfighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_usa"
;//		{if not tagged "talk_jetfighter_ai"
;//			{tags add "talk_jetfighter_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_eng"
;//		{if not tagged "talk_jetfighter_ai"
;//			{tags add "talk_jetfighter_ai"}
;//		}
;//	}
)

; — jet bomber
(define "tag_airborne_jet_bomber"
    {tags add "air_vehicle"}
    {if tagged "hidden"
    ;   {tags add "altitude_high"}
        {tags add "talk_jetbomber_ai"}
        {tags add "air_ai_vehicle"}
    else
        {tags add "talk_jetbomber_player"}
    }
; - ARM 110926 backup — старая логика
;//	{if tagged "_user_ally"
;//		{tags add "talk_jetbomber_player"}
;//	else
;//		{tags add "talk_jetbomber_ai"}
;//		{tags add "air_ai_vehicle"}
;//	}
;//	{if tagged "_user"
;//		{tags add "talk_jetbomber_player"}
;//	else
;//		{tags add "talk_jetbomber_ai"}
;//		{tags add "air_ai_vehicle"}
;//	}
;//	{if tagged "hidden"
;//		{if not tagged "talk_jetbomber_ai"
;//			{tags add "talk_jetbomber_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_ger"
;//		{if not tagged "talk_jetbomber_ai"
;//			{tags add "talk_jetbomber_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_rus"
;//		{if not tagged "talk_jetbomber_ai"
;//			{tags add "talk_jetbomber_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_fin"
;//		{if not tagged "talk_jetbomber_ai"
;//			{tags add "talk_jetbomber_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_usa"
;//		{if not tagged "talk_jetbomber_ai"
;//			{tags add "talk_jetbomber_ai"}
;//		}
;//	}
;//	{if tagged "airstrike_eng"
;//		{if not tagged "talk_jetbomber_ai"
;//			{tags add "talk_jetbomber_ai"}
;//		}
;//	}
)

; ==================== AI (бот) ====================
; Используются для entity с суффиксом _ai — всегда AI, независимо от hidden.

; — recon ai
(define "tag_airborne_recon_ai"
    {tags add "altitude_high"}
    {tags add "air_vehicle"}
;	{tags add "air_ai_vehicle"}
)

; — fighter ai
(define "tag_airborne_fighter_ai"
    {tags add "altitude_high"}
    {tags add "air_vehicle"}
    {tags add "talk_fighter_ai"}
    {tags add "air_ai_vehicle"}
)

; — heavy fighter ai
(define "tag_airborne_hvfighter_ai"
    {tags add "altitude_high"}
    {tags add "air_vehicle"}
    {tags add "talk_hvfighter_ai"}
    {tags add "air_ai_vehicle"}
)

; — bomber ai
(define "tag_airborne_bomber_ai"
    {tags add "altitude_high"}
    {tags add "air_vehicle"}
    {tags add "talk_bomber_ai"}
    {tags add "air_ai_vehicle"}
)

; — cargo ai
(define "tag_airborne_cargo_ai"
    {tags add "talk_cargo_ai"}
)

; — jet fighter ai
(define "tag_airborne_jet_fighter_ai"
    {tags add "altitude_high"}
    {tags add "air_vehicle"}
    {tags add "talk_jetfighter_ai"}
    {tags add "air_ai_vehicle"}
)

; — jet bomber ai
(define "tag_airborne_jet_bomber_ai"
    {tags add "altitude_high"}
    {tags add "air_vehicle"}
    {tags add "talk_jetbomber_ai"}
    {tags add "air_ai_vehicle"}
)

; ==================== NATIONALITY TAGS ====================
; — Германия
(define "tag_airborne_ger"
    {tags add "airborne_ger"}
; - ARM 110926 backup — старый блок
;//	{if tagged "air_ai_vehicle"
;//	;	{tags add "airstrike_ger"}
;//	}
)

; — Россия
(define "tag_airborne_rus"
    {tags add "airborne_rus"}
; - ARM 110926 backup — старый блок
;//	{if tagged "air_ai_vehicle"
;//	;	{tags add "airstrike_rus"}
;//	}
)

; — Финляндия
(define "tag_airborne_fin"
    {tags add "airborne_fin"}
; - ARM 110926 backup — старый блок
;//	{if tagged "air_ai_vehicle"
;//	;	{tags add "airstrike_fin"}
;//	}
)

; — США
(define "tag_airborne_usa"
    {tags add "airborne_usa"}
; - ARM 110926 backup — старый блок
;//	{if tagged "air_ai_vehicle"
;//	;	{tags add "airstrike_usa"}
;//	}
)

; — Англия
(define "tag_airborne_eng"
    {tags add "airborne_eng"}
; - ARM 110926 backup — старый блок
;//	{if tagged "air_ai_vehicle"
;//	;	{tags add "airstrike_eng"}
;//	}
)