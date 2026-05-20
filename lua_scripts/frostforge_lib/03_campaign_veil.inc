-- Frostforge Campaign Veil

Frostforge = Frostforge or {}
Frostforge.CampaignVeil = Frostforge.CampaignVeil or {}

local F = Frostforge.Faction

function Frostforge.CampaignVeil.Apply(player, factionId)
    -- Frostforge Campaign Veil should make players neutral witnesses,
    -- regardless of their race, faction, or destination city.
    factionId = F.NEUTRAL

    player:SetFaction(factionId)

    if player.SetPvP then
        player:SetPvP(false)
    end

    if player.CombatStop then
        player:CombatStop()
    end

    if player.ClearInCombat then
        player:ClearInCombat()
    end

    player:SendBroadcastMessage("|cff66ccffFrostforge:|r The Campaign Veil surrounds you. You may walk this chapter as a witness, not an invader.")
end

function Frostforge.CampaignVeil.ApplyOrgrimmar(player)
    Frostforge.CampaignVeil.Apply(player, F.NEUTRAL)
end

function Frostforge.CampaignVeil.ApplyStormwind(player)
    Frostforge.CampaignVeil.Apply(player, F.NEUTRAL)
end

function Frostforge.CampaignVeil.Remove(player)
    if player.CombatStop then
        player:CombatStop()
    end

    if player.ClearInCombat then
        player:ClearInCombat()
    end

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
