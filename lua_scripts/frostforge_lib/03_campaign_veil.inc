-- Frostforge Campaign Veil

Frostforge = Frostforge or {}
Frostforge.CampaignVeil = Frostforge.CampaignVeil or {}

local F = Frostforge.Faction

Frostforge.CampaignVeil.Active = Frostforge.CampaignVeil.Active or {}

local function GetGuid(player)
    if not player then
        return nil
    end

    return player:GetGUIDLow()
end

function Frostforge.CampaignVeil.IsActive(player)
    local guid = GetGuid(player)
    if not guid then
        return false
    end

    return Frostforge.CampaignVeil.Active[guid] == true
end

local function StopUnitCombat(unit)
    if not unit then
        return
    end

    if unit.AttackStop then
        unit:AttackStop()
    end

    if unit.CombatStop then
        unit:CombatStop()
    end

    if unit.ClearInCombat then
        unit:ClearInCombat()
    end
end

function Frostforge.CampaignVeil.Apply(player, factionId)
    -- Frostforge Campaign Veil should make players neutral witnesses,
    -- regardless of their race, faction, or destination city.
    factionId = F.NEUTRAL

    player:SetFaction(factionId)

    local guid = GetGuid(player)
    if guid then
        Frostforge.CampaignVeil.Active[guid] = true
    end

    if player.SetPvP then
        player:SetPvP(false)
    end

    StopUnitCombat(player)

    player:SendBroadcastMessage("|cff66ccffFrostforge:|r The Campaign Veil surrounds you. You may walk this chapter as a witness, not an invader.")
end

function Frostforge.CampaignVeil.ApplyOrgrimmar(player)
    Frostforge.CampaignVeil.Apply(player, F.NEUTRAL)
end

function Frostforge.CampaignVeil.ApplyStormwind(player)
    Frostforge.CampaignVeil.Apply(player, F.NEUTRAL)
end

function Frostforge.CampaignVeil.Remove(player)
    local guid = GetGuid(player)
    if guid then
        Frostforge.CampaignVeil.Active[guid] = nil
    end

    StopUnitCombat(player)

    player:SetFactionForRace(player:GetRace())
    player:SendBroadcastMessage("|cff66ccffFrostforge:|r The Campaign Veil fades. Your normal faction has been restored.")
end

function Frostforge.CampaignVeil.ApplyOrgrimmarToGroup(player)
    Frostforge.CampaignVeil.ApplyOrgrimmar(player)

    local group = player:GetGroup()
    if not group then
        return
    end

    local members = group:GetMembers()
    for _, member in pairs(members) do
        if member and member:IsInWorld() then
            Frostforge.CampaignVeil.ApplyOrgrimmar(member)
        end
    end
end

function Frostforge.CampaignVeil.ApplyStormwindToGroup(player)
    Frostforge.CampaignVeil.ApplyStormwind(player)

    local group = player:GetGroup()
    if not group then
        return
    end

    local members = group:GetMembers()
    for _, member in pairs(members) do
        if member and member:IsInWorld() then
            Frostforge.CampaignVeil.ApplyStormwind(member)
        end
    end
end

function Frostforge.CampaignVeil.RemoveFromGroup(player)
    Frostforge.CampaignVeil.Remove(player)

    local group = player:GetGroup()
    if not group then
        return
    end

    local members = group:GetMembers()
    for _, member in pairs(members) do
        if member and member:IsInWorld() then
            Frostforge.CampaignVeil.Remove(member)
        end
    end
end

local function OnVeiledPlayerEnterCombat(event, player, enemy)
    if not Frostforge.CampaignVeil.IsActive(player) then
        return
    end

    StopUnitCombat(player)
    StopUnitCombat(enemy)
end

RegisterPlayerEvent(33, OnVeiledPlayerEnterCombat)

print("[Frostforge] Campaign Veil loaded.")