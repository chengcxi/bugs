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

-- Throttle: same unit logged at most once per 60s (2026-09-28)
local logLastTime = {}
local LOG_THROTTLE_SEC = 60

function M.isUnitAllowed(unit, isDefender)
	-- [ AircraftFirstDelayMinutes 2026-10-03 ] delay first aircraft spawn
	local delayMin = ConquestConfig.AircraftFirstDelayMinutes
	if delayMin and delayMin > 0 and unit and unit.type then
		local hasAircraft = false
		for _, t in ipairs(unit.type) do if t == "Aircraft" then hasAircraft = true; break end end
		if hasAircraft then
			local startT = ConquestState and ConquestState.battleStartTime or nil
			if startT and (os.time() - startT) < (delayMin * 60) then
				return false
			end
		end
	end
	if isDefender and isBlockedForDefender(unit) then
		if printDebug then
			local key = unit.unit or "unknown"
			local now = os.time()
			if (logLastTime[key] or 0) + LOG_THROTTLE_SEC <= now then
				logLastTime[key] = now
				print(string.format("[ARM] (UnitFilter): Blocked %s (Cannon + %s) for defender",
					key, table.concat(blockedSubtypes, "/")))
			end
		end
		return false
	end
	return true
end

return M