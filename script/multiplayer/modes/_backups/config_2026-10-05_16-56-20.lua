-- File: config.lua
-- Catalog: script\multiplayer\modes
-- Created by Max Drechsler 
-- Created 28.08.2026
-- Modify 28.08.2026
-- Version 1.0 
-- Description: Центральный конфигурационный файл для всех модулей.
-- Все числовые параметры, таймауты, множители и флаги

local M = {}

-- ============================================================
-- ОБЩИЕ ПАРАМЕТРЫ
-- ============================================================

M.OrderRotationPeriod = 2.5 * 60000       -- 2.5 минуты – интервал обновления приказов отрядам


-- ============================================================
-- ПАРАМЕТРЫ МЕХАНИЗМА «ЗАСТРЕВАНИЯ» (переключение цели по таймауту)
-- ============================================================

M.Stuck = {
    enabled = true,                       -- включен ли модуль (можно временно отключить)
    minTimeout = 3 * 60 * 1000,           -- минимальный таймаут (3 минуты)
    maxTimeout = 7 * 60 * 1000,           -- максимальный таймаут (7 минут)
    checkInterval = 10 * 1000,            -- проверять состояние каждые 10 секунд
}

-- ============================================================
-- ПАРАМЕТРЫ TANKINFANTRYRATIO (балансир пехоты/танков)
-- ============================================================

M.TankInfantryRatio = {
    -- Сколько пехотных отрядов спавнить после каждого танка
    infantryPerTank = {
        ger = 2,
        rus = 3,
        fin = 3,
        usa = 2,
        eng = 2,
    },

    -- Уровни приоритетов пехоты. Проверяются по порядку.
    -- Первый уровень, где есть подходящий юнит, используется.
    priorityInfantryTags = {
        ger = {
            {"Infantry", "Squad", "PzGren"},     -- 1: панцергренадёры
            {"Infantry", "Squad", "Motorize"},   -- 2: мотопехота
            {"Infantry", "Squad", "Reg"},        -- 3: обычная пехота
            {"Infantry", "Squad"},               -- 4: любая пехота (fallback)
        },
        rus = {
            {"Infantry", "Squad", "Storm"},
            {"Infantry", "Squad", "Guards"},
            {"Infantry", "Squad", "Reg"},
            {"Infantry", "Squad"},
        },
        fin = {
            {"Infantry", "Squad", "Elite"},
            {"Infantry", "Squad", "Recon"},
            {"Infantry", "Squad"},
        },
        usa = {
            {"Infantry", "Squad", "Rang"},
        --  {"Infantry", "Squad", "Para"},
            {"Infantry", "Squad"},
        },
        eng = {
            {"Infantry", "Squad", "Glider"},
		--	{"Infantry", "Squad", "Para"},
            {"Infantry", "Squad"},
        },
    },
}


-- ============================================================
-- ПАРАМЕТРЫ МОДУЛЯ ВЫЧИСЛЕНИЯ СТАДИИ (StageCalculator)
-- ============================================================

M.StageCalculator = {
    enabled = false,
    updateInterval = 60000,   -- опционально, если используется в цикле
}

-- ============================================================
-- АВТОМАТИЧЕСКАЯ СМЕНА СУТОК (ВРЕМЕНИ СУТОК)
-- ============================================================

M.Weather = {
    enabled = false,                   -- включить автоматический цикл	; false / true
    cycleDuration = 25,               -- минут между переключениями
    variation = 0.1,                  -- случайное отклонение ±10%
    startTime = "day",                -- начальное время: "morning", "day", "evening", "night"
    triggerDelay = 2.0,               -- задержка перед активацией триггера (в секундах)
    -- Доступные времена суток для каждого сезона (пропускаются отсутствующие)
    landscapes = {
        spring = {"morning", "day", "evening", "night"},
        summer = {"morning", "day", "evening", "night"},
        autumn = {"morning", "day", "evening", "night"},
        winter = {"morning", "day", "evening", "night"},
        wood   = {"morning", "day", "evening", "night"},
    },
    sceneVarLandscape    = "current_landscape",
    sceneVarManualSwitch = "manual_weather_switch",
}

-- ============================================================
-- ПАРАМЕТРЫ УПРОЩЁННОГО АМБУША (SimpleAmbush)
-- ============================================================

M.SimpleAmbush = {
    enabled = false,
    chance = 1.0,						 	-- для теста, основной вариант 0.3
    minInterval = 0.1 * 60 * 1000,			-- для теста, основной вариант 8 
    maxInterval = 0.2 * 60 * 1000,			-- для теста, основной вариант 12
    startDelay = 1 * 60 * 1000,				-- для теста, основной вариант 19
    maxSpawns = 3,
    countPerSpawn = 3,                    -- сколько отрядов за раз

	-- Если true – спавн на точке бота (тыл врага), если false – на точке игрока (PlayerSpawnPoint)
    spawnOnBotSpawn = false,                -- false = точка игрока, true = точка бота

    -- Запрещённые теги (оставляем)
    forbiddenTags = {"Motorize", "Truck"},

    -- Явные списки юнитов для каждой нации
    unitNames = {
        ger = {
            "squad_recon_con(ger)",
            "squad_fallschirm_recon_late_con(ger)",
            "squad_fallschirmjaeger_con(ger)",
            "squad_ss_fallschirmjager_500_1943(ger)",
            "squad_arm_fallschirmjager_7d_1940(ger)",
        },
        rus = {
            "squad_partisan_con(rus)",
            "squad_spetsnaz(rus)",
            "squad_paras_con(rus)",
            "squad_mountainrifles_con(rus)",
            "squad_nkvd_mountain_con(rus)",
            "squad_rifleunit_elite(rus)",
        },
        fin = {
            "squad_civil_guard_early_con(fin)",
            "squad_scout_mid_con(fin)",
            "squad_vet_scout_mid_con(fin)",
            "squad_jag_scout_late_con(fin)",
            "squad_sissi_mid_con(fin)",
            "squad_elite_rifle_mid_con(fin)",
            "squad_elite_rifle_late_con(fin)",
        },
        usa = {
            "squad_1st_arm_recon_con(usa)",
            "squad_82nd_recon_con(usa)",
            "squad_ranger_assault_con(usa)",
            "squad_ranger_assault_mg_con(usa)",
            "squad_ranger_assault_late_con(usa)",
            "squad_ranger_assault_mg_late_con(usa)",
            "squad_ranger_special_late_con(usa)",
            "squad_82nd_eng_con(usa)",
            "squad_82nd_con(usa)",
            "squad_101st_eng_con(usa)",
            "squad_101st_con(usa)",
            "squad_82nd_eng_late_con(usa)",
            "squad_82nd_late_con(usa)",
            "squad_82nd_demo_late_con(usa)",
            "squad_82nd_glider_con(usa)",
            "squad_82nd_glider_pio_con(usa)",
            "squad_101st_glider_late_con(usa)",
            "squad_82nd_glider_late_con(usa)",
            "squad_82nd_glider_pio_late_con(usa)",
        },
        eng = {
            "squad_1st_airland_pio_mid_con(eng)",
            "squad_1st_airland_rifle_mid_con(eng)",
            "squad_6th_airland_recon_late_con(eng)",
            "squad_6th_airland_rifle_late_con(eng)",
            "squad_1st_airland_recon_late_con(eng)",
            "squad_1st_airland_rifle_late_con(eng)",
            "squad_1st_airland_support_late_con(eng)",
            "squad_1st_para_recce_mid_con(eng)",
            "squad_1st_para_rifle_mid_con(eng)",
            "squad_6th_para_eng_late_con(eng)",
            "squad_6th_para_rifle_late_con(eng)",
            "squad_1st_para_protect_late_con(can)",
            "squad_1st_para_rifle_late_con(can)",
            "squad_1st_para_eng_late_con(pol)",
            "squad_1st_para_eng_flame_late_con(pol)",
            "squad_1st_para_rifle_late_con(pol)",
            "squad_1st_para_eng_late_con(eng)",
            "squad_1st_para_rifle_late_con(eng)",
            "squad_1st_para_recce_late_con(eng)",
            "squad_sas_late_con(eng)",
            "squad_rec_mc_early_con(eng)",
        },
    },
}

-- M.SimpleAmbush = {
--     enabled = true,
--     chance = 0.9,						 	-- Заменить на 0.3
--     minInterval = 1 * 60 * 1000,			-- Заменить на 8
--     maxInterval = 3 * 60 * 1000,			-- Заменить на 12
--     startDelay = 2 * 60 * 1000,				-- Заменить на 15
--     maxSpawns = 3,
--     countPerSpawn = 3,                    -- сколько отрядов за раз
-- 
--     -- Глобальные запрещённые теги для всех наций
--     forbiddenTags = {"Motorize", "Truck"},
-- 	
--     -- Наборы тегов для выбора юнитов
-- 	unitDefinitions = {
-- 		ger = {
-- 			{"Infantry", "Squad", "Para", "SS"},
-- 			{"Infantry", "Squad", "Para", "LW"},
-- 			{"Infantry", "Squad", "Recon"},			
-- 		},
-- 		rus = {
-- 			{"Infantry", "Squad", "Partisan"},
-- 			{"Infantry", "Squad", "Spetz"},
-- 			{"Infantry", "Squad", "Para"},
-- 			{"Infantry", "Squad", "Elite"},			
-- 		},
-- 		fin = {
-- 			{"Infantry", "Squad", "Spetz"},
-- 			{"Infantry", "Squad", "Recon"},
-- 			{"Infantry", "Squad", "Partisan"},
-- 			{"Infantry", "Squad", "Elite"},			
-- 		},
-- 		usa = {
-- 			{"Infantry", "Squad", "Rang"},
-- 			{"Infantry", "Squad", "Para"},
-- 			{"Infantry", "Squad", "Glider"},	
-- 			{"Infantry", "Squad", "Recon"},			
-- 		},
-- 		eng = {
-- 			{"Infantry", "Squad", "Glider"},
-- 			{"Infantry", "Squad", "Para"},
-- 			{"Infantry", "Squad", "Spetz"},
-- 			{"Infantry", "Squad", "Recon"},				
-- 		},
-- 	},
-- }


-- ============================================================
-- ПАРАМЕТРЫ ДОКТРИН
-- ============================================================
M.Doctrine = {
    enabled = true,

    nations = {
        -- < [ DOCTRINE MODIFIERS START ]: Германия
        ger = {
            doctrines = {
                { name = "Default", enabled = true },
                { name = "Infanterie Division with Panzerjager-Abteilung", enabled = true,
                    modifiers = {
                        Reg = 1.3,      -- Линейная пехота
                                        -- squad_regular_con, squad_jaeger_con, squad_pionier_con, squad_blau_con,
                                        -- squad_regular_vet_con, squad_fusilier_late_con, squad_brandenburger_con
                        PzGren = 0.8,   -- Панцергренадёры
                                        -- squad_pz_pio_con, squad_panzergrenadier_1943, squad_pz_pio_302_con
                        Motorize = 0.7, -- Мотопехота
                                        -- squad_regular_motor_con, squad_regular_armor_con, squad_gd_motor_con,
                                        -- squad_recon_motor_con, squad_gd_motor_arm
                        Light = 0.4,    -- Лёгкие танки
                                        -- panzer2c, panzer2f, pz38t_f, panzer_2j, marder2, marder3h, t26_pak9738_ger
                        Medium = 0.4,   -- Средние танки
                                        -- panzer3j, panzer3m, panzer4f2, panzer4g, panzer4h, nashorn, dicker_max
                        Heavy = 0.3,    -- Тяжёлые танки
                                        -- tiger1h, tiger1e, tiger2h, panzerb2, ferdinand, jagdpanther
                        AT = 1.6,       -- ПТ-пушки
                                        -- 37mm_pak36, 50mm_pak38, 75mm_pak40, 88mm_pak4341, 75mm_pak41, solothurn_s18_100
                        AA = 1.1,       -- Зенитные пушки
                                        -- 20mm_flak30, 88mm_flak18, 88mm_flak36, 105mm_flak38
                        TD = 1.6,       -- ПТ-САУ (штурмовые орудия)
                                        -- stug3a, stug3g, stug4g, hetzer, jagdpanzer4_l48, panzer4_70_v
                        Hunter = 2.1,   -- Panzerjager (мобильные ПТ)
                                        -- marder139, marder3h, nashorn, panzerjager1, geschutzwagen_39h, sturer_emil
                        Aircraft = 0.7, -- Авиация
                                        -- ai_fi156 (Recon), bf109_e4b_ai, bf109_f2_ai (Fighter),
                                        -- bf110_e2_ai (Bomber), ju-87_ai (Bomber)
                    }
                },
                { name = "Panzer Battalion (Light/Medium)", enabled = true,
                    modifiers = {
                        Reg = 0.7,      -- Линейная пехота
                                        -- squad_regular_con, squad_pionier_con, squad_jaeger_con
                        PzGren = 1.4,   -- Панцергренадёры
                                        -- squad_panzergrenadier_1943, squad_pz_pio_con
                        Motorize = 1.4, -- Мотопехота
                                        -- squad_regular_motor_con, squad_regular_armor_con, squad_gd_motor_con
                        Light = 1.4,    -- Лёгкие танки
                                        -- panzer1b, panzer2c, panzer2f, pz38t_f, pz38t_g, panzer_2j
                        Medium = 1.4,   -- Средние танки
                                        -- panzer3j, panzer3m, panzer4f2, panzer4g, panzer4h, panzer5d
                        Heavy = 0.4,    -- Тяжёлые танки
                                        -- tiger1h, tiger1e, tiger2h, panzer5a
                        TD = 0.9,       -- ПТ-САУ
                                        -- stug3g, hetzer, jagdpanzer4_l48
                        AT = 0.8,       -- ПТ-пушки
                                        -- 37mm_pak36, 50mm_pak38, 75mm_pak40
                        Aircraft = 0.5, -- Авиация (по фильтру только Recon и Fighter)
                                        -- ai_fi156 (Recon), bf109_e4b_ai, bf109_f2_ai (Fighter)
                    }
                },
                { name = "Heavy Panzer Battalion with PzGren (Motorized)", enabled = true,
                    modifiers = {
                        Reg = 0.4,      -- Линейная пехота
                                        -- squad_regular_con, squad_pionier_con
                        PzGren = 1.5,   -- Панцергренадёры
                                        -- squad_panzergrenadier_1943, squad_pz_pio_con, squad_pz_pio_302_con
                        Motorize = 1.5, -- Мотопехота
                                        -- squad_regular_armor_con, squad_gd_motor_con, squad_regular_motor_con
                        Light = 0.4,    -- Лёгкие танки
                                        -- panzer2c, panzer2l, pz38t_f
                        Medium = 1.1,   -- Средние танки
                                        -- panzer4g, panzer4h, panther_f, panzer5d
                        Heavy = 1.5,    -- Тяжёлые танки
                                        -- tiger1h, tiger1e, tiger2h, tiger1hunt, lowehd, e_100a
                        TD = 0.7,       -- ПТ-САУ
                                        -- stug3g, jagdpanzer4_l48
                        AT = 0.5,       -- ПТ-пушки
                                        -- 37mm_pak36, 50mm_pak38, 88mm_pak4341
                        -- Aircraft не указан: фильтр блокирует всю авиацию
                    }
                },
                { name = "Gebirgsjäger Light Tank Battalion", enabled = false,
                    modifiers = {
                        Gebirgs = 1.7,  -- Горные стрелки
                                        -- squad_gebirgsjaeger_con, squad_gebirgsjaeger_late_con, squad_gebirgssturm_extcq
                        Reg = 0.7,      -- Линейная пехота
                                        -- squad_regular_con, squad_jaeger_con
                        PzGren = 0.6,   -- Панцергренадёры
                                        -- squad_panzergrenadier_1943, squad_pz_pio_con
                        Light = 1.4,    -- Лёгкие танки
                                        -- panzer2c, pz38t_f, t26_pak9738_ger, panzerjager1
                        Medium = 0.5,   -- Средние танки
                                        -- panzer3j, panzer4g, stug3g
                        Heavy = 0.3,    -- Тяжёлые танки
                                        -- tiger1h, tiger2h
                        AT = 1.1,       -- ПТ-пушки
                                        -- 37mm_pak36, 50mm_pak38, 75mm_pak40
                        Hunter = 1.9,   -- Мобильные ПТ (Marder)
                                        -- marder139, marder2, marder3h, marder3m
                        Aircraft = 0.8, -- Авиация (по фильтру Recon, Fighter, HvFighter)
                                        -- ai_fi156 (Recon), bf109_e4b_ai, bf109_f2_ai, bf110_f4_ai
                    }
                },
                { name = "Luftwaffe Field Division with Fallschirmjäger", enabled = true,
                    modifiers = {
                        LW = 1.6,       -- Пехота Люфтваффе
                                        -- squad_luftwaffe_con, squad_lw_jaeger_con
                        Para = 1.5,     -- Парашютисты
                                        -- squad_fallschirmjaeger_con, squad_ss_fallschirmjager_500_1943,
                                        -- squad_fallschirm_recon_late_con, squad_arm_fallschirmjager_7d_1940
                        Reg = 0.7,      -- Линейная пехота
                                        -- squad_regular_con, squad_pionier_con
                        PzGren = 0.5,   -- Панцергренадёры
                                        -- squad_panzergrenadier_1943, squad_pz_pio_con
                        Light = 0.6,    -- Лёгкие танки
                                        -- panzer2c, pz38t_f
                        Medium = 0.6,   -- Средние танки
                                        -- panzer3j, panzer4g, stuh42
                        Heavy = 0.2,    -- Тяжёлые танки
                                        -- tiger1h, tiger2h
                        AA = 1.3,       -- Зенитные пушки
                                        -- 20mm_flak30, 88mm_flak18, 88mm_flak36, 105mm_flak38
                        Hunter = 1.3,   -- ПТ-поддержка
                                        -- marder3h, nashorn, panzerjager1
                        Aircraft = 1.1, -- Авиация (ключевая тема доктрины)
                                        -- ai_fi156 (Recon), bf109_g6_ai, me_262_50mm_ai,
                                        -- bf110_e2_ai (Bomber), ju-87_ai (Bomber)
                        _Fighter = 1.2, -- Истребители в приоритете
                                        -- bf109_e4b_ai, bf109_f2_ai, bf109_g6_ai, me_262_50mm_ai
                        _Bomber = 1.0,  -- Бомбардировщики базовые
                                        -- ju-87_ai, bf110_e2_ai, me-262_a1_new_ai
                    }
                },
            },
            probabilities = {
                Default = 0.2,
                ["Infanterie Division with Panzerjager-Abteilung"] = 0.2,
                ["Panzer Battalion (Light/Medium)"] = 0.2,
                ["Heavy Panzer Battalion with PzGren (Motorized)"] = 0.15,
                ["Gebirgsjäger Light Tank Battalion"] = 0.15,
                ["Luftwaffe Field Division with Fallschirmjäger"] = 0.1,
            },
        },
        -- > [ DOCTRINE MODIFIERS END ]

        -- < [ DOCTRINE MODIFIERS START ]: РККА
        rus = {
            doctrines = {
                { name = "Default", enabled = true },
                { name = "Infantry division RKKA with an artillery regiment", enabled = true,
                    modifiers = {
                        Reg = 1.3,       -- Линейная пехота
                                         -- squad_rifleunit_con(rus), squad_smg_con(rus), squad_sapper_con(rus),
                                         -- squad_conscripts_con(rus), squad_rifleunit_alt_con(rus)
                        Guards = 0.8,    -- Гвардейские отряды (отодвинуты на второй план)
                                         -- squad_guardsrifle_con(rus), squad_guards_smg_con(rus)
                        Storm = 0.9,     -- Штурмовые отряды
                                         -- squad_assaultsappers_con(rus), squad_assault_soldiers(rus)
                        NKVD = 0.8,      -- НКВД
                                         -- squad_nkvd_rifle_con(rus), squad_nkvd_at_rifle_con(rus)
                        Spetz = 0.7,     -- Спецназ и горные
                                         -- squad_spetsnaz(rus), squad_mountainrifles_con(rus), squad_nkvd_mountain_con(rus)
                        Light = 0.5,     -- Лёгкие танки
                                         -- t37a, t40, t30, t60, t26_31, t26_33, t26_39, bt5, bt7
                        Medium = 0.5,    -- Средние танки
                                         -- t3476_41, t3476_42, t3476_43, t3485_44, m4a2_75_late_rus
                        Heavy = 0.4,     -- Тяжёлые танки
                                         -- kv1_41, kv1_42, kv1s, kv85, is1_43, is2_43, is2_44
                        Artillery = 1.5, -- Артиллерия (гаубицы) — ядро доктрины
                                         -- 107mm_m1910_30, 122mm_m1910, 122mm_m30
                        Howitzer = 1.3,  -- Гаубицы
                                         -- 107mm_m1910_30, 122mm_m1910, 122mm_m30
                        MLRS = 1.2,      -- РСЗО
                                         -- 300mm_m30, 300mm_m31, zis6_bm8_48, zis6_bm13_16, bm13_studebaker
                        AT = 1.2,        -- ПТ-пушки
                                         -- 45mm_m37, 57mm_zis2, 76mm_zis3, 100mm_bs3
                        Aircraft = 1.0,  -- Авиация
                                         -- ai_po2 (Recon), yak1_ser69_ai (Fighter), ussr-p-39_ai,
                                         -- il2_mod41_ai, po2_rocket_ai (Bomber), rus-b25_ai
                    }
                },
                { name = "Tank battalion RKKA", enabled = true,
                    modifiers = {
                        Reg = 0.7,       -- Линейная пехота
                                         -- squad_rifleunit_con(rus), squad_smg_con(rus), squad_sapper_con(rus)
                        Guards = 1.1,    -- Гвардейские отряды
                                         -- squad_guardsrifle_con(rus), squad_guards_smg_con(rus)
                        Storm = 1.1,     -- Штурмовые отряды
                                         -- squad_assaultsappers_con(rus), squad_assault_soldiers(rus)
                        Motorize = 1.3,  -- Мотопехота
                                         -- squad_rifle_motorised_con, squad_guardsrifle_motorised_con
                        TankTeam = 1.5,  -- Танковый десант
                                         -- squad_1939_stormtroopers_t28(rus), squad_1940_stormtroopers_t3476(rus)
                        Light = 1.3,     -- Лёгкие танки
                                         -- t37a, t40, t50, t60, t70, t70m, bt5, bt7, t26_31, t26_33
                        Medium = 1.4,    -- Средние танки (ядро доктрины)
                                         -- t3476_40, t3476_41, t3476_42, t3476_43, t3457_41, t3457_43, t3485_44
                        Heavy = 1.3,     -- Тяжёлые танки
                                         -- kv1_41, kv1_42, kv1s, kv85, is1_43, is2_43, is2_44
                        TD = 0.9,        -- ПТ-САУ (второстепенно)
                                         -- su85, su85m, su100, isu122s
                        Artillery = 0.8, -- Артиллерия снижена
                                         -- 107mm_m1910_30, 122mm_m1910, 122mm_m30
                        Mortar = 0.7,    -- Миномёты снижены
                                         -- 82mm_bm37, 120mm_pm38, 160mm_mt_13_mortar
                        Aircraft = 0.5,  -- Авиация (только Recon и Fighter по фильтру)
                                         -- ai_po2 (Recon), yak1_ser69_ai, ussr-p-39_ai (Fighter)
                    }
                },
                { name = "Guards Rifle Division", enabled = true,
                    modifiers = {
                        Guards = 1.5,    -- Гвардейские отряды — ядро доктрины
                                         -- squad_guardsrifle_con(rus), squad_guards_smg_con(rus),
                                         -- squad_guardsrifle_44_con(rus), squad_guards_smg_mg_44_con(rus)
                        NKVD = 1.1,      -- НКВД
                                         -- squad_nkvd_rifle_con(rus), squad_nkvd_recon_con(rus)
                        Spetz = 1.2,     -- Спецназ
                                         -- squad_spetsnaz(rus), squad_mountainrifles_con(rus)
                        VMF = 1.1,       -- Морская пехота
                                         -- squad_marines_con(rus), squad_guards_marines_44_con(rus)
                        Para = 1.1,      -- Парашютисты
                                         -- squad_paras_con(rus), squad_guards_paras_con(rus)
                        Reg = 0.7,       -- Линейная пехота снижена
                                         -- squad_rifleunit_con(rus), squad_smg_con(rus)
                        Storm = 0.6,     -- Штурмовые отряды снижены
                                         -- squad_assaultsappers_con(rus), squad_assault_soldiers(rus)
                        Light = 0.7,     -- Лёгкие танки
                                         -- t37a, t40, t50, t60, t70
                        Medium = 1.3,    -- Средние танки
                                         -- t3476_41, t3476_42, t3476_43, t3485_44, t4485
                        Heavy = 1.3,     -- Тяжёлые танки
                                         -- kv85, is1_43, is2_43, is2_44, is_3
                        Artillery = 1.0, -- Артиллерия базовая
                                         -- 107mm_m1910_30, 122mm_m1910, 122mm_m30
                        Aircraft = 0.8,  -- Авиация (по фильтру Recon, HvFighter, Bomber)
                                         -- ai_po2 (Recon), il2_mod42_ai (HvFighter),
                                         -- po2_rocket_ai, po2_flame_ai (Bomber)
                    }
                },
            },
            probabilities = {
                Default = 0.2,
                ["Infantry division RKKA with an artillery regiment"] = 0.3,
                ["Tank battalion RKKA"] = 0.3,
                ["Guards Rifle Division"] = 0.2,
            },
        },
        -- > [ DOCTRINE MODIFIERS END ]
    },

    globalAllowedTags = {},
    globalForbiddenTags = {"Prototype", "Paper"},
}

-- ============================================================
-- БАЛАНСИРОВЩИКИ (перенесены из runtime_config.lua, 2026-09-26)
-- Значения публикуются в ConquestConfig через M.PublishOverrides()
-- (вызывается один раз из conquest.lua после всех requires).
-- ============================================================

M.Balance = {
	-- Режим покупки: "flat" (один пул, v1-style) | "lanes" (v2 lane-based)
	PurchaseMode = "flat",

	-- V1-множители приоритета (были в монолите CalculateUnitPriority):
	--   Squad  x1.75 - пехота чаще
	--   Tank   x1.20 - танки чаще
	--   Cannon x0.65 - пушки реже
	v1Penalties = {
		Squad  = 1.75,
		Tank   = 1.20,
		Cannon = 0.65,
		Aircraft = 1.10,		
	},

	-- [ REMOVED 2026-09-28: AircraftLaneBudget. Aircraft lane disabled
	--   in session_20260927_code_changes. Aircraft competes in the general
	--   pool via M.Balance.v1Penalties.Aircraft. ]

	-- ============================================================
	-- Wave sizes (attacker/defender, per difficulty)
	-- v1 WaveUnitByRoleAndDifficulty: Min/Max юнитов за волну/фазу.
	-- ============================================================
	AttackerByDifficulty = {
		easy   = { Min = 15, Max = 18 },
		normal = { Min = 17, Max = 20 },
		hard   = { Min = 19, Max = 22 },
		heroic = { Min = 23, Max = 26 },
	},
	DefenderOpeningByDifficulty = {
		easy   = { Min = 7,  Max = 11 },
		normal = { Min = 9,  Max = 13 },
		hard   = { Min = 11, Max = 15 },
		heroic = { Min = 14, Max = 18 },
	},
	DefenderCounterattackByDifficulty = {
		easy   = { Min = 8,  Max = 12 },
		normal = { Min = 10,  Max = 14 },
		hard   = { Min = 12, Max = 16 },
		heroic = { Min = 16, Max = 20 },
	},

	-- ============================================================
	-- Wave intervals (attacker wave-off)
	-- ИНВЕРТИРОВАНО 2026-09-27: higher difficulty -> shorter interval.
	-- ============================================================
	AttackerWaveOffBaseByDifficulty = {
		easy   = { Min = 150, Mid = 165, Max = 180 },
		normal = { Min = 135, Mid = 150, Max = 165 },
		hard   = { Min = 120, Mid = 135, Max = 150 },
		heroic = { Min = 95, Mid = 110, Max = 125 },
	},
	AttackerWaveOffDayScale = {
		[1]=1.00, [5]=1.00, [7]=0.97, [9]=0.93,
		[11]=0.90, [13]=0.87, [15]=0.83, [17]=0.80,
	},
	-- (120)-(60)
	FirstCheckSeconds   = 75,					
	ForceReleaseSeconds = 300,

	-- ============================================================
	-- Spawn timings
	-- ============================================================
	StartSpawnTime = {
		DefenseMin = 5 * 1000,
		DefenseMax = 10 * 1000,
		AttackMin  = 1 * 1000,
		AttackMax  = 1 * 1000,
	},
	SpawnCooldownTime = {
		DCGMin = 2 * 1000,
		DCGMax = 2 * 1000,
	},
	CompletedPurchaseIdleTime = {
		Min = 60 * 1000,
		Max = 60 * 1000,
	},
	-- (15) - (5)
	UnitSpawnWaitTime = 5 * 1000,
		-- ARm added 031026
		AircraftFirstDelayMinutes = 3,
	OrderRotationPeriod = 2.5 * 60000,
	AttackerWavePatterns = {
		flat = {
			First = 1.00,
			Middle = 1.00,
			Final = 1.00,
		},
	},

	-- ============================================================
	-- Defender (synced with runtime_config 2026-09-28)
	-- ============================================================
	DefenderOpening = {
		MaxDuration = 600 * 1000,
	},
	DefenderCounterattack = {
		ChainedResponseDelayMin = 60 * 1000,
		ChainedResponseDelayMax = 90 * 1000,
		ResponseChance          = 0.95,
		MaxTotal                = 20,
		MaxPerFlag              = 3,
	},
}

M.AttackerFailure = {
	-- false: watcher не арм-ится, retreat не запрашивается;
	-- attackerWavesFinished продолжает работать штатно (большие кулдауны).
	-- true:  штатное поведение v2 (post-final-wave watcher).
	Enabled = false,

	-- Первая проверка после финальной волны (сек), потом каждые N сек.
	InitialCheckDelaySeconds = 60,
	RepeatCheckIntervalSeconds = 15,

	-- Пороги watcher: bar = clamp(playerDefense * ratio, MinBar, MaxBar).
	-- Группы по прогрессу атакующего:
	--   NoProgress      = 0 своих флагов
	--   PartialProgress = >=1 свой/нейтрал
	--   NearVictory     = все кроме 1
	NoProgress      = { PlayerDefenseRatio = 0.30, MinBar = 12, MaxBar = 40 },
	PartialProgress = { PlayerDefenseRatio = 0.22, MinBar =  8, MaxBar = 40 },
	NearVictory     = { PlayerDefenseRatio = 0.15, MinBar =  6, MaxBar = 40 },
}

-- Публикация значений в _G.ConquestConfig (runtime_config.lua).
-- Мост Config -> ConquestConfig односторонний, поэтому нужен явный publish.
function M.PublishOverrides()
	local cc = _G.ConquestConfig
	if not cc then return end

	-- Publish all M.Balance tunables to ConquestConfig
	if M.Balance then
		local b = M.Balance
		local function pub(name, path)
			print("[ARm] (config): publish " .. name .. " -> ConquestConfig." .. path)
		end
		if b.PurchaseMode then
			cc.PurchaseMode = b.PurchaseMode
			pub("PurchaseMode", "PurchaseMode")
		end
		if b.v1Penalties then
			cc.Balance = cc.Balance or {}
			cc.Balance.v1Penalties = b.v1Penalties
			pub("v1Penalties", "Balance.v1Penalties")
		end
		if b.AttackerByDifficulty then
			cc.AttackerWaves = cc.AttackerWaves or {}
			cc.AttackerWaves.AttackerByDifficulty = b.AttackerByDifficulty
			pub("AttackerByDifficulty", "AttackerWaves.AttackerByDifficulty")
		end
		if b.DefenderOpeningByDifficulty then
			cc.DefenderOpeningByDifficulty = b.DefenderOpeningByDifficulty
			pub("DefenderOpeningByDifficulty", "DefenderOpeningByDifficulty")
		end
		if b.DefenderCounterattackByDifficulty then
			cc.DefenderCounterattackByDifficulty = b.DefenderCounterattackByDifficulty
			pub("DefenderCounterattackByDifficulty", "DefenderCounterattackByDifficulty")
		end
		if b.AttackerWaveOffBaseByDifficulty then
			cc.AttackerWaveOffBaseByDifficulty = b.AttackerWaveOffBaseByDifficulty
			pub("AttackerWaveOffBaseByDifficulty", "AttackerWaveOffBaseByDifficulty")
		end
		if b.AttackerWaveOffDayScale then
			cc.AttackerWaveOffDayScale = b.AttackerWaveOffDayScale
			pub("AttackerWaveOffDayScale", "AttackerWaveOffDayScale")
		end
		if b.FirstCheckSeconds or b.ForceReleaseSeconds then
			cc.AttackerDynamicWaveOff = cc.AttackerDynamicWaveOff or {}
			if b.FirstCheckSeconds then
				cc.AttackerDynamicWaveOff.FirstCheckSeconds = b.FirstCheckSeconds
				pub("FirstCheckSeconds", "AttackerDynamicWaveOff.FirstCheckSeconds")
			end
			if b.ForceReleaseSeconds then
				cc.AttackerDynamicWaveOff.ForceReleaseSeconds = b.ForceReleaseSeconds
				pub("ForceReleaseSeconds", "AttackerDynamicWaveOff.ForceReleaseSeconds")
			end
		end
		if b.StartSpawnTime then
			cc.StartSpawnTime = b.StartSpawnTime
			pub("StartSpawnTime", "StartSpawnTime")
		end
		if b.CompletedPurchaseIdleTime then
			cc.CompletedPurchaseIdleTime = b.CompletedPurchaseIdleTime
			pub("CompletedPurchaseIdleTime", "CompletedPurchaseIdleTime")
		end
		if b.UnitSpawnWaitTime then
			cc.UnitSpawnWaitTime = b.UnitSpawnWaitTime
			pub("UnitSpawnWaitTime", "UnitSpawnWaitTime")
		end
		if b.AircraftFirstDelayMinutes then
			cc.AircraftFirstDelayMinutes = b.AircraftFirstDelayMinutes
			pub("AircraftFirstDelayMinutes", "AircraftFirstDelayMinutes")
		end
		if b.AttackerWavePatterns then
			cc.AttackerWavePatterns = b.AttackerWavePatterns
			pub("AttackerWavePatterns", "AttackerWavePatterns")
		if b.OrderRotationPeriod then
			cc.OrderRotationPeriod = b.OrderRotationPeriod
			pub("OrderRotationPeriod", "OrderRotationPeriod")
		end
		end
		if b.SpawnCooldownTime then
			cc.SpawnCooldownTime = cc.SpawnCooldownTime or {}
			if b.SpawnCooldownTime.DCGMin then cc.SpawnCooldownTime.DCGMin = b.SpawnCooldownTime.DCGMin end
			if b.SpawnCooldownTime.DCGMax then cc.SpawnCooldownTime.DCGMax = b.SpawnCooldownTime.DCGMax end
			pub("SpawnCooldownTime", "SpawnCooldownTime.DCGMin/DCGMax")
		end
		if b.DefenderOpening and b.DefenderOpening.MaxDuration then
			cc.DefenderOpening = cc.DefenderOpening or {}
			cc.DefenderOpening.MaxDuration = b.DefenderOpening.MaxDuration
			pub("DefenderOpening.MaxDuration", "DefenderOpening.MaxDuration")
		end
		if b.DefenderCounterattack then
			cc.DefenderCounterattack = cc.DefenderCounterattack or {}
			for k, v in pairs(b.DefenderCounterattack) do cc.DefenderCounterattack[k] = v end
			pub("DefenderCounterattack", "DefenderCounterattack.*")
		end
		print("[ARm] (config): published M.Balance overrides to ConquestConfig")
	end

	if M.AttackerFailure then
		local af = cc.AttackerFailure or {}
		af.Enabled = M.AttackerFailure.Enabled
		af.InitialCheckDelaySeconds = M.AttackerFailure.InitialCheckDelaySeconds
		af.RepeatCheckIntervalSeconds = M.AttackerFailure.RepeatCheckIntervalSeconds
		for _, k in ipairs({ "NoProgress", "PartialProgress", "NearVictory" }) do
			if M.AttackerFailure[k] then af[k] = M.AttackerFailure[k] end
		end
		cc.AttackerFailure = af
	end
end

-- < [ CONFIG BRIDGE START ]: мост к патчной ConquestConfig
-- Если ключ не найден в нашем Config — читаем из ConquestConfig (runtime_config.lua).
-- Динамический __index: работает, даже если ConquestConfig загрузится позже.
setmetatable(M, {
    __index = function(_, key)
        local pat = _G.ConquestConfig
        if pat then return pat[key] end
        return nil
    end
})
-- > [ CONFIG BRIDGE END ]

return M
