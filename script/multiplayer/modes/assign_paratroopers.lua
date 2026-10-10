-- \script\multiplayer\modes\conquest_lair.lua

function assign_paratroopers(enemy_id)
    print(">>> assign_paratroopers: enemy_id = " .. tostring(enemy_id))
    if enemy_id == nil or enemy_id == 0 then
        print(">>> assign_paratroopers: invalid enemy_id")
        return
    end

    local paratroopers = GetEntitiesWithTag("paratrooper")
    if not paratroopers then
        print(">>> assign_paratroopers: no paratroopers")
        return
    end

    local count = 0
    for _, unit in pairs(paratroopers) do
        if unit:IsAlive() and not unit:IsTagged("player_paratrooper") then
            unit:SetPlayer(enemy_id)
            unit:Tag("assigned_to_enemy")
            count = count + 1
            print(">>> assign_paratroopers: assigned player " .. enemy_id .. " to " .. unit:GetName())
        end
    end
    print(">>> assign_paratroopers: assigned " .. count .. " paratroopers")
end