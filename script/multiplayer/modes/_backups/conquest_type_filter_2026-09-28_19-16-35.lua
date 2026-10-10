-- File: conquest_type_filter.lua
-- Catalog: script\multiplayer\modes
-- Modify by Max Drechsler 
-- Created 26.08.2026
-- Modify 26.08.2026
-- Version 1.1 


-- Фильтр юнитов для бота-защитника: запрещаем "Cannon" + Support/Artillery/AA
local M = {}

local blockedSubtypes = {
    "Support",
    "Artillery",
    "AA",
}

local function hasType(unit, wanted)
    if not unit or not unit.type then
        return false
    end
    for _, t in ipairs(unit.type) do
        if t == wanted then
            return true
        end
    end
    return false
end

local function isBlockedForDefender(unit)
    if not unit or not unit.type then
        return false
    end
    if not hasType(unit, "Cannon") then
        return false
    end
    for _, subtype in ipairs(blockedSubtypes) do
        if hasType(unit, subtype) then
            return true
        end
    end
    return false
end

function M.isUnitAllowed(unit, isDefender)
    if isDefender and isBlockedForDefender(unit) then
        if printDebug then
            print(string.format("[ARM] (UnitFilter): Blocked %s (Cannon + %s) for defender", 
                unit.unit or "unknown", table.concat(blockedSubtypes, "/")))
        end
        return false
    end
    return true
end

return M