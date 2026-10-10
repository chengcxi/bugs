-- File: conquest_doctrine.lua
-- Catalog: script\multiplayer\modes
-- Modify by Max Drechsler 
-- Created 26.08.2026, modified 10.09.2026
-- Version 3.1 – приоритетные модификаторы по доктринам

local M = {}
local Config = require([[/script/multiplayer/modes/config]])

local function hasType(unit, wanted)
    if not unit or not unit.type then return false end
    for _, t in ipairs(unit.type) do
        if t == wanted then return true end
    end
    return false
end

-- ============================================================
-- Доктрина 1: Германия "Infanterie Division with Panzerjager-Abteilung"
-- Aircraft: ReconPlane, _Fighter, _HvFighter, _Bomber
-- ============================================================
local function infantryFilter(unit)
    if not unit or not unit.type then return false end
    for _, t in ipairs(unit.type) do
        if t == "LW" or t == "Gebirgs" or t == "SS" or t == "PzGren" then
            return false
        end
    end

    -- Aircraft check
    if hasType(unit, "Aircraft") then
        if hasType(unit, "ReconPlane") or hasType(unit, "_Fighter") or
           hasType(unit, "_HvFighter") or hasType(unit, "_Bomber") then
            return true
        end
        return false
    end

    -- [FIX] Запрет САУ-гаубиц на танковом шасси (wespe, grille_k, hummel, bison2).
    -- Артиллерия на лафетах (Cannon + Artillery) остаётся разрешённой.
    if hasType(unit, "Tank") and hasType(unit, "Artillery") then
        return false
    end

    local hasInfantry  = hasType(unit, "Infantry")
    local hasSquad     = hasType(unit, "Squad")
    local hasTeam      = hasType(unit, "Team")
    local hasCannon    = hasType(unit, "Cannon")
    local hasVehicle   = hasType(unit, "Vehicle")
    local hasArmored   = hasType(unit, "Armored")
    local hasTank      = hasType(unit, "Tank")
    local hasHalftrack = hasType(unit, "Halftrack")
    local hasTransport = hasType(unit, "Transport")
    local hasMotorize  = hasType(unit, "Motorize")
    local hasTruck     = hasType(unit, "Truck")
    local hasMG        = hasType(unit, "MG")
    local hasAA        = hasType(unit, "AA")
    local hasAT        = hasType(unit, "AT")
    local hasTD        = hasType(unit, "TD")
    local hasMortar    = hasType(unit, "Mortar")
    local hasSupport   = hasType(unit, "Support")
    local hasArtillery = hasType(unit, "Artillery")
    local hasHowitzer  = hasType(unit, "Howitzer")
    local hasMLRS      = hasType(unit, "MLRS")
    local hasHunter    = hasType(unit, "Hunter")
    local hasUnarmed   = hasType(unit, "Unarmed")
    local hasSignal    = hasType(unit, "Signal")
    local hasSuperweapon = hasType(unit, "Superweapon")
    local hasPrototype = hasType(unit, "Prototype")
    local hasMedium    = hasType(unit, "Medium")

    if hasInfantry and hasSquad then
        if hasMotorize and not hasTruck then return false end
        return true
    end
    if hasInfantry and hasTeam then return true end
    if hasInfantry and hasTeam and hasMG then return true end
    if hasInfantry and hasTeam and hasSignal then return true end
    if hasCannon then
        if hasAA then return true end
        if hasAT then return true end
        if hasSupport then return true end
        if hasArtillery and hasHowitzer then return true end
        if hasArtillery and hasMLRS then return true end
        if hasMortar and not hasArtillery and not hasSuperweapon then return true end
        if hasArtillery and hasMortar and hasSuperweapon then return true end
        return false
    end
    if hasVehicle and not hasHalftrack then
        if hasMG then return true end
        if hasAA then return true end
        if hasUnarmed then return true end
        return false
    end
    if hasArmored and not hasHalftrack and not hasTransport then
        if hasMG then return true end
        if hasAA then return true end
        if hasAT then return true end
        if hasSupport then return true end
        return false
    end
    if hasHalftrack then
        if hasArmored and hasAA and hasAT then return true end
        if hasVehicle and hasAT then return true end
        if hasArmored and hasArtillery and hasMLRS then return true end
        return false
    end
    if hasTank and hasAT and hasTD then return true end
    if hasTank and hasAT and hasHunter then return true end
    if hasTank and hasSupport then return true end     -- [NEW] САУ-поддержка (bison, stuh42)
    if hasCannon and hasMG then return true end
    if hasSquad and hasTank and hasMedium and hasAT and hasTD then return true end
    if hasSquad and hasTank and hasMedium and hasArtillery and hasPrototype then return true end

    return false
end

-- ============================================================
-- Доктрина 2: Германия "Panzer Battalion (Light/Medium)"
-- Aircraft: ReconPlane, _Fighter
-- ============================================================
local function panzerFilter(unit)
    if not unit or not unit.type then return false end
    for _, t in ipairs(unit.type) do
        if t == "LW" or t == "Gebirgs" then
            return false
        end
    end

    -- Aircraft check
    if hasType(unit, "Aircraft") then
        if hasType(unit, "ReconPlane") or hasType(unit, "_Fighter") then
            return true
        end
        return false
    end

    local hasInfantry  = hasType(unit, "Infantry")
    local hasSquad     = hasType(unit, "Squad")
    local hasTeam      = hasType(unit, "Team")
    local hasCannon    = hasType(unit, "Cannon")
    local hasVehicle   = hasType(unit, "Vehicle")
    local hasTank      = hasType(unit, "Tank")
    local hasLight     = hasType(unit, "Light")
    local hasMedium    = hasType(unit, "Medium")
    local hasMotorize  = hasType(unit, "Motorize")
    local hasMortar    = hasType(unit, "Mortar")
    local hasUnarmed   = hasType(unit, "Unarmed")
    local hasSupply    = hasType(unit, "Supply")
    local hasAT        = hasType(unit, "AT")
    local hasTD        = hasType(unit, "TD")
    local hasArtillery = hasType(unit, "Artillery")
    local hasMLRS      = hasType(unit, "MLRS")
    local hasPzGren    = hasType(unit, "PzGren")
    local hasSS        = hasType(unit, "SS")
    local hasMG        = hasType(unit, "MG")
    local hasSignal    = hasType(unit, "Signal")
    local hasSuperweapon = hasType(unit, "Superweapon")
    local hasPrototype = hasType(unit, "Prototype")

    if hasInfantry and hasSquad and hasMotorize then return true end
    if hasInfantry and hasSquad and hasPzGren then return true end
    if hasInfantry and hasSquad and hasSS then return true end
    if hasInfantry and hasTeam and hasMG then return true end
    if hasInfantry and hasTeam and hasSignal then return true end
    if hasTank and (hasLight or hasMedium) then
        if hasAT or hasTD then return false end
        return true
    end
    if hasCannon and hasMortar and not hasArtillery and not hasSuperweapon then return true end
    if hasCannon and hasArtillery and hasMLRS then return true end

    if hasSquad and hasTank and hasLight then return true end
    if hasSquad and hasTank and hasMedium then return true end
    if hasSquad and hasTank and hasMedium and hasArtillery and hasPrototype then return true end

    return false
end

-- ============================================================
-- Доктрина 3: Германия "Heavy Panzer Battalion with PzGren (Motorized)"
-- Aircraft: полностью запрещён
-- ============================================================
local function heavyPanzerFilter(unit)
    if not unit or not unit.type then return false end
    for _, t in ipairs(unit.type) do
        if t == "LW" or t == "Gebirgs" or t == "Aircraft" then
            return false
        end
    end

    local hasInfantry  = hasType(unit, "Infantry")
    local hasSquad     = hasType(unit, "Squad")
    local hasTeam      = hasType(unit, "Team")
    local hasVehicle   = hasType(unit, "Vehicle")
    local hasTank      = hasType(unit, "Tank")
    local hasHeavy     = hasType(unit, "Heavy")
    local hasMedium    = hasType(unit, "Medium")
    local hasMotorize  = hasType(unit, "Motorize")
    local hasUnarmed   = hasType(unit, "Unarmed")
    local hasSupply    = hasType(unit, "Supply")
    local hasReg       = hasType(unit, "Reg")
    local hasCannon    = hasType(unit, "Cannon")
    local hasMortar    = hasType(unit, "Mortar")
    local hasArtillery = hasType(unit, "Artillery")
    local hasMLRS      = hasType(unit, "MLRS")
    local hasMG        = hasType(unit, "MG")
    local hasSignal    = hasType(unit, "Signal")
    local hasSuperweapon = hasType(unit, "Superweapon")
    local hasArmored   = hasType(unit, "Armored")
    local hasHalftrack = hasType(unit, "Halftrack")
    local hasTransport = hasType(unit, "Transport")
    local hasAA        = hasType(unit, "AA")
    local hasSS        = hasType(unit, "SS")
    local hasAT        = hasType(unit, "AT")
    local hasTD        = hasType(unit, "TD")
    local hasHunter    = hasType(unit, "Hunter")
    local hasSupport   = hasType(unit, "Support")
    local hasLight     = hasType(unit, "Light")
    local hasPrototype = hasType(unit, "Prototype")

    if hasInfantry and hasSquad and hasMotorize then return true end
    if hasInfantry and hasSquad and hasReg then return true end
    if hasInfantry and hasTeam and hasMG then return true end
    if hasInfantry and hasTeam and hasSignal then return true end
    if hasTank and hasHeavy then return true end
    if hasTank and hasMedium then return true end
    if hasCannon and hasMortar and not hasArtillery and not hasSuperweapon then return true end
    if hasCannon and hasArtillery and hasMLRS then return true end

    if hasArmored and hasMG and hasTransport then return true end
    if hasHalftrack and hasAA and hasSS then return true end
    if hasSquad and hasTank and hasHeavy then return true end
    if hasSquad and hasTank and hasHeavy and hasSS then return true end

    return false
end

-- ============================================================
-- Доктрина 4: Германия "Gebirgsjäger Light Tank Battalion"
-- Aircraft: ReconPlane, _Fighter, _HvFighter
-- ============================================================
local function gebirgsLightTankFilter(unit)
    if not unit or not unit.type then return false end
    for _, t in ipairs(unit.type) do
        if t == "LW" or t == "SS" or t == "PzGren" then
            return false
        end
    end

    -- Aircraft check
    if hasType(unit, "Aircraft") then
        if hasType(unit, "ReconPlane") or hasType(unit, "_Fighter") or
           hasType(unit, "_HvFighter") then
            return true
        end
        return false
    end

    local hasInfantry   = hasType(unit, "Infantry")
    local hasSquad      = hasType(unit, "Squad")
    local hasTeam       = hasType(unit, "Team")
    local hasGebirgs    = hasType(unit, "Gebirgs")
    local hasMotorize   = hasType(unit, "Motorize")
    local hasRecon      = hasType(unit, "Recon")
    local hasSniper     = hasType(unit, "Sniper")
    local hasSturmJager = hasType(unit, "SturmJager")
    local hasTank       = hasType(unit, "Tank")
    local hasLight      = hasType(unit, "Light")
    local hasMedium     = hasType(unit, "Medium")
    local hasAT         = hasType(unit, "AT")
    local hasTD         = hasType(unit, "TD")
    local hasArtillery  = hasType(unit, "Artillery")
    local hasSupport    = hasType(unit, "Support")
    local hasHunter     = hasType(unit, "Hunter")
    local hasAA         = hasType(unit, "AA")
    local hasMortar     = hasType(unit, "Mortar")
    local hasMLRS       = hasType(unit, "MLRS")
    local hasCannon     = hasType(unit, "Cannon")
    local hasArmored    = hasType(unit, "Armored")
    local hasVehicle    = hasType(unit, "Vehicle")
    local hasUnarmed    = hasType(unit, "Unarmed")
    local hasSupply     = hasType(unit, "Supply")
    local hasMG         = hasType(unit, "MG")
    local hasSignal     = hasType(unit, "Signal")
    local hasSuperweapon = hasType(unit, "Superweapon")
    local hasPrototype  = hasType(unit, "Prototype")

    -- Пехота
    if hasInfantry and (hasSquad or hasTeam) and hasGebirgs then return true end
    if hasInfantry and hasSquad and hasMotorize and hasGebirgs then return true end
    if hasInfantry and hasSquad and hasRecon then return true end
    if hasInfantry and hasTeam and hasSniper then return true end
    if hasInfantry and hasTeam and hasAT then return true end
    if hasInfantry and hasSquad and hasSturmJager then return true end
    if hasInfantry and hasTeam and hasMG then return true end
    if hasInfantry and hasTeam and hasSignal then return true end

    -- Танки
    if hasTank and hasLight and hasAT and hasHunter then return true end
    if hasTank and hasLight and hasArtillery then return true end
    if hasTank and hasMedium and hasAA then return true end
    if hasTank and hasMedium and hasSupport then return true end
    if hasTank and hasLight then
        if hasAT or hasTD or hasArtillery or hasSupport or hasHunter then return false end
        return true
    end

    -- Пушки
    if hasCannon and hasMortar and not hasArtillery and not hasSuperweapon then return true end
    if hasCannon and hasSupport then return true end
    if hasCannon and hasAT then return true end
    if hasCannon and hasArtillery and hasMLRS then return true end
    if hasArmored and hasAA then return true end
    if hasCannon and hasArtillery and hasMortar and hasSuperweapon then return true end

    if hasSquad and hasTank and hasLight then return true end
    if hasSquad and hasTank and hasMedium and hasPrototype then return true end

    return false
end

-- ============================================================
-- Доктрина 5: Германия "Luftwaffe Field Division with Fallschirmjäger"
-- Aircraft: ReconPlane, _Fighter, _HvFighter, _Bomber, _HvBomber
-- ============================================================
local function luftwaffeFilter(unit)
    -- [FIX] Запрет САУ-гаубиц (hummel), средние танки остаются
    if hasType(unit, "Tank") and hasType(unit, "Artillery") then
        return false
    end
    if not unit or not unit.type then return false end
    for _, t in ipairs(unit.type) do
        if t == "SS" or t == "PzGren" or t == "TD" then
            return false
        end
    end

    -- Aircraft check
    if hasType(unit, "Aircraft") then
        if hasType(unit, "ReconPlane") or hasType(unit, "_Fighter") or
           hasType(unit, "_HvFighter") or hasType(unit, "_Bomber") or
           hasType(unit, "_HvBomber") then
            return true
        end
        return false
    end

    -- [FIX] Запрет САУ-гаубиц (hummel, wespe). Обычные средние танки остаются.
    if hasType(unit, "Tank") and hasType(unit, "Artillery") then
        return false
    end

    local hasInfantry  = hasType(unit, "Infantry")
    local hasSquad     = hasType(unit, "Squad")
    local hasTeam      = hasType(unit, "Team")
    local hasLW        = hasType(unit, "LW")
    local hasTank      = hasType(unit, "Tank")
    local hasMedium    = hasType(unit, "Medium")
    local hasCannon    = hasType(unit, "Cannon")
    local hasAA        = hasType(unit, "AA")
    local hasMortar    = hasType(unit, "Mortar")
    local hasArmored   = hasType(unit, "Armored")
    local hasHalftrack = hasType(unit, "Halftrack")
    local hasVehicle   = hasType(unit, "Vehicle")
    local hasUnarmed   = hasType(unit, "Unarmed")
    local hasSupply    = hasType(unit, "Supply")
    local hasHunter    = hasType(unit, "Hunter")
    local hasArtillery = hasType(unit, "Artillery")
    local hasMLRS      = hasType(unit, "MLRS")
    local hasAT        = hasType(unit, "AT")
    local hasSupport   = hasType(unit, "Support")
    local hasMG        = hasType(unit, "MG")
    local hasSignal    = hasType(unit, "Signal")
    local hasSuperweapon = hasType(unit, "Superweapon")
    local hasPrototype = hasType(unit, "Prototype")

    if hasInfantry and hasSquad and hasLW then return true end
    if hasInfantry and hasTeam and hasMG then return true end
    if hasInfantry and hasTeam and hasSignal then return true end
    if hasInfantry then return false end
    if hasTank and hasMedium then return true end
    if hasCannon and (hasAA or (hasMortar and not hasArtillery and not hasSuperweapon)) then return true end
    if hasCannon and hasSupport then return true end
    if hasCannon and hasAT then return true end
    if hasCannon and hasArtillery and hasMLRS then return true end
    if hasArmored and hasAA and hasHalftrack then return true end
    if hasVehicle and hasUnarmed and hasSupply then return true end
    if hasHunter then return true end

    if hasVehicle and hasAA and hasHalftrack then return true end
    if hasTank and hasSupport then return true end     -- [FIX] САУ-поддержка (bison, stuh42)
    if hasCannon and hasMG then return true end
    if hasSquad and hasTank and hasMedium and hasAT and hasTD then return true end
    if hasSquad and hasTank and hasMedium and hasArtillery and hasPrototype then return true end

    return false
end

-- ============================================================
-- Доктрина 6: РККА "Infantry division RKKA with an artillery regiment"
-- Aircraft: ReconPlane, _Fighter, _HvFighter, _Bomber, _HvBomber
-- ============================================================
local function infantryRusFilter(unit)
    if not unit or not unit.type then return false end
    for _, t in ipairs(unit.type) do
        if t == "Motorize" or t == "Guards" or t == "Storm" or t == "NKVD" or t == "Spetz" then
            return false
        end
    end

    -- Aircraft check
    if hasType(unit, "Aircraft") then
        if hasType(unit, "ReconPlane") or hasType(unit, "_Fighter") or
           hasType(unit, "_HvFighter") or hasType(unit, "_Bomber") or
           hasType(unit, "_HvBomber") then
            return true
        end
        return false
    end

    local hasInfantry  = hasType(unit, "Infantry")
    local hasSquad     = hasType(unit, "Squad")
    local hasTeam      = hasType(unit, "Team")
    local hasTank      = hasType(unit, "Tank")
    local hasLight     = hasType(unit, "Light")
    local hasMedium    = hasType(unit, "Medium")
    local hasHeavy     = hasType(unit, "Heavy")
    local hasCannon    = hasType(unit, "Cannon")
    local hasVehicle   = hasType(unit, "Vehicle")
    local hasArmored   = hasType(unit, "Armored")
    local hasMG        = hasType(unit, "MG")
    local hasAA        = hasType(unit, "AA")
    local hasAT        = hasType(unit, "AT")
    local hasTD        = hasType(unit, "TD")
    local hasMortar    = hasType(unit, "Mortar")
    local hasSupport   = hasType(unit, "Support")
    local hasArtillery = hasType(unit, "Artillery")
    local hasHowitzer  = hasType(unit, "Howitzer")
    local hasMLRS      = hasType(unit, "MLRS")
    local hasUnarmed   = hasType(unit, "Unarmed")
    local hasSupply    = hasType(unit, "Supply")
    local hasHunter    = hasType(unit, "Hunter")
    local hasSuperweapon = hasType(unit, "Superweapon")
    local hasPrototype = hasType(unit, "Prototype")

    if hasInfantry and (hasSquad or hasTeam) then return true end
    if hasInfantry and hasTeam and hasMG then return true end
    if hasVehicle and hasMG then return true end
    if hasVehicle and hasAA then return true end
    if hasTank and hasAA then return true end
    if hasTank and hasAT and hasTD then return true end
    if hasTank and hasArtillery then return true end
    if hasTank and hasMedium then return true end
    if hasCannon and hasArtillery and hasMLRS then return true end
    if hasCannon and hasMortar then return true end
    if hasCannon then
        if hasAA then return true end
        if hasAT then return true end
        if hasSupport then return true end
        if hasArtillery and hasHowitzer then return true end
        return false
    end
    if hasTank and hasLight then
        if hasAT or hasTD or hasArtillery or hasSupport or hasHunter then return false end
        return true
    end
    if hasVehicle and not hasTank then
        if hasMG then return true end
        if hasAA then return true end
        if hasUnarmed and hasSupply then return true end
        return false
    end
    if hasArmored and not hasTank then
        if hasMG then return true end
        if hasAA then return true end
        return false
    end

    if hasSquad and hasTank and hasMedium then return true end

    return false
end

-- ============================================================
-- Доктрина 7: РККА "Tank battalion RKKA"
-- Aircraft: ReconPlane, _Fighter
-- ============================================================
local function tankRusFilter(unit)
    if not unit or not unit.type then return false end
    for _, t in ipairs(unit.type) do
        if t == "Superweapon" then
            return false
        end
    end
    if hasType(unit, "Cannon") and hasType(unit, "Artillery") and hasType(unit, "MLRS") then
        return false
    end

    -- Aircraft check
    if hasType(unit, "Aircraft") then
        if hasType(unit, "ReconPlane") or hasType(unit, "_Fighter") then
            return true
        end
        return false
    end

    local hasInfantry  = hasType(unit, "Infantry")
    local hasSquad     = hasType(unit, "Squad")
    local hasTeam      = hasType(unit, "Team")
    local hasMotorize  = hasType(unit, "Motorize")
    local hasReg       = hasType(unit, "Reg")
    local hasStorm     = hasType(unit, "Storm")
    local hasFull      = hasType(unit, "Full")
    local hasTank      = hasType(unit, "Tank")
    local hasTankTeam  = hasType(unit, "TankTeam")
    local hasVehicle   = hasType(unit, "Vehicle")
    local hasArtillery = hasType(unit, "Artillery")
    local hasMLRS      = hasType(unit, "MLRS")
    local hasAT        = hasType(unit, "AT")
    local hasTD        = hasType(unit, "TD")
    local hasSupport   = hasType(unit, "Support")
    local hasAA        = hasType(unit, "AA")
    local hasMG        = hasType(unit, "MG")
    local hasUnarmed   = hasType(unit, "Unarmed")
    local hasSupply    = hasType(unit, "Supply")
    local hasMortar    = hasType(unit, "Mortar")
    local hasCannon    = hasType(unit, "Cannon")
    local hasLight     = hasType(unit, "Light")
    local hasMedium    = hasType(unit, "Medium")
    local hasHeavy     = hasType(unit, "Heavy")

    if hasInfantry and hasSquad and (hasMotorize or hasTankTeam) then return true end
    if hasInfantry and hasSquad and hasReg then return true end
    if hasInfantry and hasSquad and hasReg and hasFull then return true end
    if hasInfantry and hasSquad and hasStorm then return true end
    if hasInfantry and hasTeam and hasMG then return true end
    if hasVehicle and hasMG then return true end
    if hasVehicle and hasAA then return true end
    if hasTank and hasAA then return true end
    if hasVehicle and hasArtillery and hasMLRS then return true end
    if hasTank and hasUnarmed and hasSupply then return true end
    if hasTank and hasArtillery then return true end
    if hasTank then return true end
    if hasVehicle then
        if hasArtillery and hasMLRS then return true end
        if hasAT and hasTD then return true end
        if hasSupport then return true end
        if hasAA then return true end
        if hasUnarmed and hasSupply then return true end
        return false
    end
    if hasCannon and hasMortar then return false end

    if hasSquad and hasTank and hasLight then return true end
    if hasSquad and hasTank and hasMedium then return true end
    if hasSquad and hasTank and hasHeavy then return true end

    return false
end

-- ============================================================
-- Доктрина 8: РККА "Guards Rifle Division"
-- Aircraft: ReconPlane, _HvFighter, _Bomber
-- ============================================================
local function guardsRusFilter(unit)
    if not unit or not unit.type then return false end
    for _, t in ipairs(unit.type) do
        if t == "Superweapon" then
            return false
        end
    end
    if hasType(unit, "Cannon") and hasType(unit, "Artillery") and hasType(unit, "MLRS") then
        return false
    end
    if hasType(unit, "Infantry") and hasType(unit, "Squad") and hasType(unit, "Storm") then
        return false
    end

    -- Aircraft check
    if hasType(unit, "Aircraft") then
        if hasType(unit, "ReconPlane") or hasType(unit, "_HvFighter") or
           hasType(unit, "_Bomber") then
            return true
        end
        return false
    end

    local hasInfantry  = hasType(unit, "Infantry")
    local hasSquad     = hasType(unit, "Squad")
    local hasTeam      = hasType(unit, "Team")
    local hasGuards    = hasType(unit, "Guards")
    local hasNKVD      = hasType(unit, "NKVD")
    local hasSpetz     = hasType(unit, "Spetz")
    local hasVMF       = hasType(unit, "VMF")
    local hasPara      = hasType(unit, "Para")
    local hasBorder    = hasType(unit, "Border")
    local hasReg       = hasType(unit, "Reg")
    local hasFull      = hasType(unit, "Full")
    local hasTank      = hasType(unit, "Tank")
    local hasHeavy     = hasType(unit, "Heavy")
    local hasMedium    = hasType(unit, "Medium")
    local hasLight     = hasType(unit, "Light")
    local hasVehicle   = hasType(unit, "Vehicle")
    local hasArmored   = hasType(unit, "Armored")
    local hasTransport = hasType(unit, "Transport")
    local hasArtillery = hasType(unit, "Artillery")
    local hasMLRS      = hasType(unit, "MLRS")
    local hasAT        = hasType(unit, "AT")
    local hasTD        = hasType(unit, "TD")
    local hasSupport   = hasType(unit, "Support")
    local hasAA        = hasType(unit, "AA")
    local hasMG        = hasType(unit, "MG")
    local hasUnarmed   = hasType(unit, "Unarmed")
    local hasSupply    = hasType(unit, "Supply")
    local hasMortar    = hasType(unit, "Mortar")
    local hasCannon    = hasType(unit, "Cannon")
    local hasMotorize  = hasType(unit, "Motorize")

    if hasInfantry and hasSquad then
        if hasGuards or hasNKVD or hasSpetz or hasVMF or hasPara then return true end
        if hasGuards and hasMotorize then return true end
    end
    if hasSquad and hasBorder then return true end
    if hasInfantry and hasSquad and hasReg and hasFull then return true end
    if hasInfantry and hasTeam and hasMG then return true end
    if hasVehicle and hasMG then return true end
    if hasVehicle and hasAA then return true end
    if hasTank and hasAA then return true end
    if hasArmored and hasMG and hasTransport then return true end
    if hasVehicle and hasArtillery and hasMLRS then return true end
    if hasTank and hasUnarmed and hasSupply then return true end
    if hasTank and hasArtillery then return true end
    if hasTank and (hasMedium or hasHeavy) then return true end
    if hasVehicle then
        if hasAT and hasTD then return true end
        if hasArtillery and hasMLRS then return true end
        if hasSupport then return true end
        if hasAA then return true end
        if hasUnarmed and hasSupply then return true end
        return false
    end
    if hasCannon and hasMortar then return true end

    if hasSquad and hasTank and hasMedium then return true end
    if hasSquad and hasTank and hasHeavy then return true end

    return false
end

-- ============================================================
-- КАРТА ФИЛЬТРОВ ПО ИМЕНИ ДОКТРИНЫ
-- ============================================================
local filters = {
    ger = {
        ["Infanterie Division with Panzerjager-Abteilung"] = infantryFilter,
        ["Panzer Battalion (Light/Medium)"] = panzerFilter,
        ["Heavy Panzer Battalion with PzGren (Motorized)"] = heavyPanzerFilter,
        ["Gebirgsjäger Light Tank Battalion"] = gebirgsLightTankFilter,
        ["Luftwaffe Field Division with Fallschirmjäger"] = luftwaffeFilter,
    },
    rus = {
        ["Infantry division RKKA with an artillery regiment"] = infantryRusFilter,
        ["Tank battalion RKKA"] = tankRusFilter,
        ["Guards Rifle Division"] = guardsRusFilter,
    },
}

local selectedDoctrine = nil

-- ============================================================
-- ВЫБОР ДОКТРИНЫ С УЧЁТОМ enabled ИЗ КОНФИГА
-- ============================================================
function M.selectDoctrine()
    local nation = BotApi.Instance.army
    if not nation then
        if printDebug then print("[ARM] (Doctrine): Nation is nil, using Default") end
        selectedDoctrine = { name = "Default", filter = nil, modifiers = nil }
        return
    end

    if not Config.Doctrine or not Config.Doctrine.enabled then
        selectedDoctrine = { name = "Default", filter = nil, modifiers = nil }
        if printDebug then print("[ARM] (Doctrine): System disabled in config") end
        return
    end

    local nationConfig = Config.Doctrine.nations and Config.Doctrine.nations[nation]
    if not nationConfig then
        if printDebug then print("[ARM] (Doctrine): No doctrines defined for " .. nation .. ", using Default") end
        selectedDoctrine = { name = "Default", filter = nil, modifiers = nil }
        return
    end

    -- Собираем включённые доктрины
    local available = {}
    local probabilities = nationConfig.probabilities or {}
    for _, item in ipairs(nationConfig.doctrines or {}) do
        local name, enabled
        if type(item) == "table" then
            name = item.name
            enabled = (item.enabled ~= false)
        else
            name = item
            enabled = true
        end
        if enabled then
            table.insert(available, name)
        end
    end

    if #available == 0 then
        if printDebug then print("[ARM] (Doctrine): No enabled doctrines, using Default") end
        selectedDoctrine = { name = "Default", filter = nil, modifiers = nil }
        return
    end

    -- Выбираем с учётом вероятностей
    local totalWeight = 0
    local weighted = {}
    for _, name in ipairs(available) do
        local weight = probabilities[name] or 1.0
        totalWeight = totalWeight + weight
        table.insert(weighted, { name = name, weight = weight })
    end

    local rnd = math.random() * totalWeight
    local cum = 0
    local chosen = "Default"
    for _, opt in ipairs(weighted) do
        cum = cum + opt.weight
        if rnd <= cum then
            chosen = opt.name
            break
        end
    end

    -- Находим фильтр
    local filter = nil
    if filters[nation] and filters[nation][chosen] then
        filter = filters[nation][chosen]
    elseif chosen ~= "Default" then
        if printDebug then print("[ARM] (Doctrine): Warning: no filter for " .. chosen .. ", using Default") end
        chosen = "Default"
    end

    -- < [ DOCTRINE MODIFIERS START ]: находим модификаторы для выбранной доктрины
    local doctrineModifiers = nil
    for _, item in ipairs(nationConfig.doctrines or {}) do
        if type(item) == "table" and item.name == chosen then
            doctrineModifiers = item.modifiers
            break
        end
    end
    -- > [ DOCTRINE MODIFIERS END ]

    selectedDoctrine = { name = chosen, filter = filter, modifiers = doctrineModifiers }
    if printDebug then
        print("[ARM] (Doctrine): Selected " .. chosen .. " for nation " .. nation)
    end

    -- ===== БЛОК УСТАНОВКИ ПЕРЕМЕННЫХ СЦЕНЫ (только числовые) =====
    if printDebug then print("[DEBUG] Entering trigger setup block") end

    if chosen ~= "Default" then
        if printDebug then print("[DEBUG] chosen is not Default, setting variables") end
        if BotApi.Scene and BotApi.Scene.SetVar then
            local doctrineCode = 0
            if chosen == "Infanterie Division with Panzerjager-Abteilung" then
                doctrineCode = 1
            elseif chosen == "Panzer Battalion (Light/Medium)" then
                doctrineCode = 2
            elseif chosen == "Heavy Panzer Battalion with PzGren (Motorized)" then
                doctrineCode = 3
            elseif chosen == "Gebirgsjäger Light Tank Battalion" then
                doctrineCode = 4
            elseif chosen == "Luftwaffe Field Division with Fallschirmjäger" then
                doctrineCode = 5
            elseif chosen == "Infantry division RKKA with an artillery regiment" then
                doctrineCode = 6
            elseif chosen == "Tank battalion RKKA" then
                doctrineCode = 7
            elseif chosen == "Guards Rifle Division" then
                doctrineCode = 8
            end

            pcall(function() BotApi.Scene:SetVar("ai_doctrine_code", doctrineCode) end)
            pcall(function() BotApi.Scene:SetVar("ai_doctrine_trigger", 1) end)

            -- < [ DOCTRINE MODIFIERS START ]: сообщение об активации приоритетов
            if doctrineModifiers then
                print("[ARM] (Doctrine): Priority modifiers ACTIVATED for doctrine #" .. doctrineCode)
            end
            -- > [ DOCTRINE MODIFIERS END ]

            if printDebug then
                print("[ARM] (Doctrine): Set ai_doctrine_code = " .. doctrineCode)
                print("[ARM] (Doctrine): Set ai_doctrine_trigger = 1")
            end
        end
    else
        if printDebug then print("[DEBUG] chosen is Default, clearing variables") end
        if BotApi.Scene and BotApi.Scene.SetVar then
            pcall(function() BotApi.Scene:SetVar("ai_doctrine_code", 0) end)
            pcall(function() BotApi.Scene:SetVar("ai_doctrine_trigger", 0) end)
            if printDebug then print("[ARM] (Doctrine): Doctrine is Default, trigger not set") end
        end
    end

    if printDebug then print("[DEBUG] Exiting trigger setup block") end
end

function M.isUnitAllowed(unit, isDefender)
    if isDefender then return true end
    if not selectedDoctrine or selectedDoctrine.name == "Default" then return true end
    if not unit then return false end
    if selectedDoctrine.filter then
        return selectedDoctrine.filter(unit)
    end
    return true
end

-- < [ DOCTRINE MODIFIERS START ]: приоритетный модификатор по доктрине
-- Возвращает произведение модификаторов для всех совпавших тегов юнита.
-- Если доктрина Default или у неё нет modifiers – возвращает 1.0.
function M.getPriorityModifier(unit)
    if not selectedDoctrine or not selectedDoctrine.modifiers then return 1.0 end
    if not unit or not unit.type then return 1.0 end
    local modifier = 1.0
    for _, t in ipairs(unit.type) do
        local m = selectedDoctrine.modifiers[t]
        if m then
            modifier = modifier * m
        end
    end
    return modifier
end
-- > [ DOCTRINE MODIFIERS END ]

function M.getDoctrineName()
    return selectedDoctrine and selectedDoctrine.name or "None"
end

return M