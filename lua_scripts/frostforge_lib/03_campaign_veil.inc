-- Frostforge Campaign Veil

Frostforge = Frostforge or {}
Frostforge.CampaignVeil = Frostforge.CampaignVeil or {}

local F = Frostforge.Faction

Frostforge.CampaignVeil.Active = Frostforge.CampaignVeil.Active or {}
Frostforge.CampaignVeil.TickRegistered = Frostforge.CampaignVeil.TickRegistered or {}
Frostforge.CampaignVeil.OriginalReputation = Frostforge.CampaignVeil.OriginalReputation or {}

-- Short interval because this is a fallback safety net for hostile city/open-world NPCs.
local VEIL_TICK_MS = 100

-- Unit field / flags for WotLK/AzerothCore.
-- These are extra protection. Reputation/faction diplomacy is the primary solution.
local UNIT_FIELD_FLAGS = 46
local UNIT_FLAG_NON_ATTACKABLE = 0x00000002
local UNIT_FLAG_IMMUNE_TO_NPC = 0x00000200
local UNIT_FLAG_PACIFIED = 0x00020000

local CAMPAIGN_VEIL_FLAGS =
    UNIT_FLAG_NON_ATTACKABLE +
    UNIT_FLAG_IMMUNE_TO_NPC +
    UNIT_FLAG_PACIFIED

-- Exalted-level value. Used temporarily while the Campaign Veil is active.
local CAMPAIGN_REPUTATION_VALUE = 42000

-- Major player city factions used by cross-faction Frostforge chapters.
local CAMPAIGN_REPUTATION_FACTIONS = {
    76,  -- Orgrimmar
    68,  -- Undercity
    81,  -- Thunder Bluff
    530, -- Darkspear Trolls
    911, -- Silvermoon City

    72,  -- Stormwind
    47,  -- Ironforge
    69,  -- Darnassus
    54,  -- Gnomeregan Exiles
    930  -- Exodar
}

-- Campaign Veil is only for open-world story travel.
-- It must never remain active inside dungeons, otherwise dungeon mobs reset.
local DUNGEON_MAPS = {
    [389] = true, -- Ragefire Chasm
    [43]  = true, -- Wailing Caverns
    [36]  = true, -- Deadmines
    [34]  = true, -- Stormwind Stockades
    [33]  = true, -- Shadowfang Keep
    [48]  = true, -- Blackfathom Deeps
    [90]  = true, -- Gnomeregan
    [47]  = true, -- Razorfen Kraul
    [189] = true, -- Scarlet Monastery

    -- Future chapters
    [70]  = true, -- Uldaman
    [209] = true, -- Zul'Farrak
    [349] = true, -- Maraudon
    [129] = true, -- Razorfen Downs
    [230] = true, -- Blackrock Depths
    [229] = true, -- Blackrock Spire
    [289] = true, -- Scholomance
    [329] = true, -- Stratholme
    [429] = true  -- Dire Maul
}

local function GetMapIdSafe(player)
    if not player then
        return nil
    end

    if player.GetMapId then
        return player:GetMapId()
    end

    if player.GetMap then
        local map = player:GetMap()
        if map and map.GetMapId then
            return map:GetMapId()
        end
    end

    return nil
end

local function IsDungeonMap(player)
    local mapId = GetMapIdSafe(player)
    return mapId and DUNGEON_MAPS[mapId] == true
end

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

local function ApplyVeilFlags(player)
    if not player then
        return
    end

    if player.SetFlag then
        player:SetFlag(UNIT_FIELD_FLAGS, CAMPAIGN_VEIL_FLAGS)
    end
end

local function RemoveVeilFlags(player)
    if not player then
        return
    end

    if player.RemoveFlag then
        player:RemoveFlag(UNIT_FIELD_FLAGS, CAMPAIGN_VEIL_FLAGS)
    end
end

local function ApplyCampaignReputation(player)
    if not player or not player.SetReputation or not player.GetReputation then
        return
    end

    local guid = GetGuid(player)
    if not guid then
        return
    end

    -- Only apply once per veil period. This prevents reputation level-up spam.
    if Frostforge.CampaignVeil.OriginalReputation[guid] then
        return
    end

    Frostforge.CampaignVeil.OriginalReputation[guid] = {}

    for _, factionId in ipairs(CAMPAIGN_REPUTATION_FACTIONS) do
        Frostforge.CampaignVeil.OriginalReputation[guid][factionId] = player:GetReputation(factionId)
        player:SetReputation(factionId, CAMPAIGN_REPUTATION_VALUE)
    end
end

local function RestoreCampaignReputation(player)
    if not player or not player.SetReputation then
        return
    end

    local guid = GetGuid(player)
    if not guid then
        return
    end

    local original = Frostforge.CampaignVeil.OriginalReputation[guid]
    if not original then
        return
    end

    for factionId, value in pairs(original) do
        player:SetReputation(factionId, value)
    end

    Frostforge.CampaignVeil.OriginalReputation[guid] = nil
end

local function MaintainVeil(eventId, delay, repeats, player)
    if not player or not player:IsInWorld() then
        return
    end

    if not Frostforge.CampaignVeil.IsActive(player) then
        return
    end

    if IsDungeonMap(player) then
        Frostforge.CampaignVeil.Remove(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge:|r The Campaign Veil fades as you enter the dungeon.")
        return
    end

    -- Do not call ApplyCampaignReputation here. It causes reputation spam.
    player:SetFaction(F.NEUTRAL)
    ApplyVeilFlags(player)

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
    ApplyCampaignReputation(player)
    ApplyVeilFlags(player)

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

    -- This removes the player-level maintain tick. Be careful if future scripts
    -- also use player:RegisterEvent for long-running player timers.
    if player.RemoveEvents then
        player:RemoveEvents()
    end

    StopUnitCombat(player)
    RemoveVeilFlags(player)
    RestoreCampaignReputation(player)

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