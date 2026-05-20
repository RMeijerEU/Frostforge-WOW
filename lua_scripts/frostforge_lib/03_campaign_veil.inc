-- Frostforge Campaign Veil

Frostforge = Frostforge or {}
Frostforge.CampaignVeil = Frostforge.CampaignVeil or {}

local F = Frostforge.Faction

Frostforge.CampaignVeil.Active = Frostforge.CampaignVeil.Active or {}
Frostforge.CampaignVeil.TickRegistered = Frostforge.CampaignVeil.TickRegistered or {}

local VEIL_TICK_MS = 100

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

local function MaintainVeil(eventId, delay, repeats, player)
    if not player or not player:IsInWorld() then
        return
    end

    if not Frostforge.CampaignVeil.IsActive(player) then
        return
    end

    player:SetFaction(F.NEUTRAL)

    if player.SetPvP then
        player:SetPvP(false)
    end

    StopUnitCombat(player)
end

local function StartVeilTick(player)
    local guid = GetGuid(player)
    if not guid then
        return
    end

    if Frostforge.CampaignVeil.TickRegistered[guid] then
        return
    end

    if player.RegisterEvent then
        player:RegisterEvent(MaintainVeil, VEIL_TICK_MS, 0)
        Frostforge.CampaignVeil.TickRegistered[guid] = true
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
    StartVeilTick(player)

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
        Frostforge.CampaignVeil.TickRegistered[guid] = nil
    end

    if player.RemoveEvents then
        player:RemoveEvents()
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

print("[Frostforge] Campaign Veil loaded.")
