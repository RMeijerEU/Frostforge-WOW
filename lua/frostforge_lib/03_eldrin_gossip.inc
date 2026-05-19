-- Frostforge Central Eldrin Gossip
-- One gossip handler for Archivist Eldrin to prevent act-to-act gossip conflicts.

Frostforge = Frostforge or {}
Frostforge.EldrinGossip = Frostforge.EldrinGossip or {}

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local U = Frostforge.Utils
local Veil = Frostforge.CampaignVeil

local function IsHorde(player)
    return player:GetTeam() == Frostforge.Team.HORDE
end

local function IsAlliance(player)
    return player:GetTeam() == Frostforge.Team.ALLIANCE
end

local function ApplyWestfallVeilToGroup(player)
    Veil.Apply(player, Frostforge.Faction.NEUTRAL)

    local group = player:GetGroup()
    if not group then
        return
    end

    local members = group:GetMembers()
    for _, member in pairs(members) do
        if member and member:IsInWorld() then
            Veil.Apply(member, Frostforge.Faction.NEUTRAL)
        end
    end
end

local function AddPathExplanation(player)
    player:GossipMenuAddItem(0, "How does the Frostforge Path work?", 0, 30)
end

local function AddActIOptions(player)
    if player:HasQuest(Q.ORGRIMMAR) and not player:GetQuestRewardStatus(Q.ORGRIMMAR) then
        player:GossipMenuAddItem(0, "Send me to Orgrimmar. I am ready to investigate.", 0, 20)
        player:GossipMenuAddItem(0, "Restore my normal faction.", 0, 22)
    end
end

local function AddActIIOptions(player)
    -- 900112 Road to the Crossroads
    if player:HasQuest(Q.WC_ROAD) and not player:GetQuestRewardStatus(Q.WC_ROAD) then
        if IsAlliance(player) then
            player:GossipMenuAddItem(0, "Send me to the Crossroads under the Campaign Veil.", 0, 201)
        else
            player:GossipMenuAddItem(0, "Send me to the Crossroads.", 0, 203)
        end
    end

    -- 900113 The Barrens Grow Restless
    if player:HasQuest(Q.WC_INVESTIGATION) and not player:GetQuestRewardStatus(Q.WC_INVESTIGATION) then
        if IsAlliance(player) then
            player:GossipMenuAddItem(0, "Send me to the Crossroads under the Campaign Veil.", 0, 201)
        else
            player:GossipMenuAddItem(0, "Send me to the Crossroads.", 0, 203)
        end

        player:GossipMenuAddItem(0, "Remind me where to investigate in the Barrens.", 0, 204)
    end

    -- 900114 Gathering at the Wailing Caverns
    if player:HasQuest(Q.WC_GROUP) and not player:GetQuestRewardStatus(Q.WC_GROUP) then
        player:GossipMenuAddItem(0, "The group is ready for the Wailing Caverns.", 0, 205)
    end
end

local function AddActIIIOptions(player, creature)
    local deadminesNotDone = Q.DM_DUNGEON and not player:GetQuestRewardStatus(Q.DM_DUNGEON)
    local wcDone = Q.WC_DUNGEON and player:GetQuestRewardStatus(Q.WC_DUNGEON)

    local onDeadminesMap = creature and creature:GetMapId() == Frostforge.Map.DEADMINES

    local hasEarlyDefiasQuest =
        player:HasQuest(Q.DM_INTRO)
        or player:HasQuest(Q.DM_INVESTIGATION)

    local alreadyPastWestfallTravel =
        player:HasQuest(Q.DM_SI7)
        or player:HasQuest(Q.DM_GROUP)
        or player:HasQuest(Q.DM_DUNGEON)
        or player:GetQuestRewardStatus(Q.DM_SI7)
        or player:GetQuestRewardStatus(Q.DM_GROUP)

    -- Westfall travel helper.
    -- Only show before the player has moved into the Moonbrook/Deadmines phase.
    -- Never show inside Deadmines.
    if deadminesNotDone
        and not onDeadminesMap
        and not alreadyPastWestfallTravel
        and (wcDone or hasEarlyDefiasQuest) then

        if IsHorde(player) then
            player:GossipMenuAddItem(0, "Send me to Sentinel Hill under the Campaign Veil.", 0, 301)
        else
            player:GossipMenuAddItem(0, "Send me to Sentinel Hill.", 0, 302)
        end
    end

    if player:HasQuest(Q.DM_INVESTIGATION) and not player:GetQuestRewardStatus(Q.DM_INVESTIGATION) then
        player:GossipMenuAddItem(0, "Remind me where to investigate in Westfall.", 0, 303)
    end

    if player:HasQuest(Q.DM_SI7) and not player:GetQuestRewardStatus(Q.DM_SI7) then
        player:GossipMenuAddItem(0, "Remind me where the SI:7 agent is.", 0, 305)
    end

    if player:HasQuest(Q.DM_GROUP) and not player:GetQuestRewardStatus(Q.DM_GROUP) then
        player:GossipMenuAddItem(0, "The group is ready for the Deadmines.", 0, 304)
    end
end

local function AddActIIIStockadesOptions(player, creature)
    local stockadesNotDone = Q.ST_DUNGEON and not player:GetQuestRewardStatus(Q.ST_DUNGEON)

    local hasStockadesQuest =
        player:HasQuest(Q.ST_ASHES)
        or player:HasQuest(Q.ST_SI7_REPORT)
        or player:HasQuest(Q.ST_STORMWIND)
        or player:HasQuest(Q.ST_PRISON)
        or player:HasQuest(Q.ST_DUNGEON)

    local deadminesDone = Q.DM_DUNGEON and player:GetQuestRewardStatus(Q.DM_DUNGEON)
    local onStockadesMap = creature and creature:GetMapId() == Frostforge.Map.STOCKADES

    -- Stormwind travel helper after Deadmines.
    -- Never show inside Stockades.
    if stockadesNotDone
    and deadminesDone
    and not onStockadesMap
    and (
        player:HasQuest(Q.ST_ASHES)
        or player:HasQuest(Q.ST_SI7_REPORT)
        or player:HasQuest(Q.ST_STORMWIND)
        or player:HasQuest(Q.ST_PRISON)
        or player:GetQuestRewardStatus(Q.ST_ASHES)
    ) then

        if player:GetTeam() == Frostforge.Team.HORDE then
            player:GossipMenuAddItem(0, "Send me to Stormwind under the Campaign Veil.", 0, 401)
        else
            player:GossipMenuAddItem(0, "Send me to Stormwind.", 0, 402)
        end
    end

    if hasStockadesQuest and not onStockadesMap then
        player:GossipMenuAddItem(0, "Remind me where the Stockades trail leads.", 0, 403)
    end

    if player:HasQuest(Q.ST_DUNGEON) and not player:GetQuestRewardStatus(Q.ST_DUNGEON) then
        player:GossipMenuAddItem(0, "Remind me what waits inside the Stockades.", 0, 404)
    end
end

local function OnEldrinGossipHello(event, player, creature)
    player:GossipClearMenu()

    player:GossipAddQuests(creature)

    AddPathExplanation(player)
    AddActIOptions(player)
    AddActIIOptions(player)
    AddActIIIOptions(player, creature)
    AddActIIIStockadesOptions(player, creature)

    player:GossipSendMenu(1, creature)
end

local function OnEldrinGossipSelect(event, player, creature, sender, intid, code, menu_id)
    player:GossipClearMenu()

    -- General explanation
    if intid == 30 then
        U.SendEldrinMessage(player, "The Frostforge Path is a Classic Lore Campaign. You will walk through the stories that shaped Azeroth, one dungeon chapter at a time.")
        U.SendEldrinMessage(player, "Some chapters belong to your people. Some belong to your enemies. All of them matter.")
        player:GossipComplete()
        return
    end

    -- Act I: Orgrimmar
    if intid == 20 then
        if player:HasQuest(Q.ORGRIMMAR) and not player:GetQuestRewardStatus(Q.ORGRIMMAR) then
            Veil.ApplyOrgrimmarToGroup(player)
            U.SendEldrinMessage(player, "Walk through Orgrimmar and speak with the Grunt, Shaman, and Guard. Follow the trail toward Ragefire Chasm.")
            player:GossipComplete()

            U.TeleportPlayerGroup(
                player,
                L.ORGRIMMAR_START.map,
                L.ORGRIMMAR_START.x,
                L.ORGRIMMAR_START.y,
                L.ORGRIMMAR_START.z,
                L.ORGRIMMAR_START.o
            )
        else
            U.SendEldrinMessage(player, "You are not currently investigating Orgrimmar.")
            player:GossipComplete()
        end

        return
    end

    if intid == 22 then
        Veil.RemoveFromGroup(player)
        player:GossipComplete()
        return
    end

    -- Act II: Crossroads / Barrens
    if intid == 201 then
        Veil.ApplyOrgrimmarToGroup(player)
        U.SendEldrinMessage(player, "The Campaign Veil surrounds you. Travel as a witness through the Barrens.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.CROSSROADS.map,
            L.CROSSROADS.x,
            L.CROSSROADS.y,
            L.CROSSROADS.z,
            L.CROSSROADS.o
        )
        return
    end

    if intid == 203 then
        U.SendEldrinMessage(player, "I will send you to the Crossroads. From there, follow the road west toward the Wailing Caverns.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.CROSSROADS.map,
            L.CROSSROADS.x,
            L.CROSSROADS.y,
            L.CROSSROADS.z,
            L.CROSSROADS.o
        )
        return
    end

    if intid == 204 then
        U.SendEldrinMessage(player, "Speak with the Crossroads Scout, then the Druidic Adept on the road, and finally the Barrens Watcher near the Wailing Caverns.")
        player:GossipComplete()
        return
    end

    if intid == 205 then
        U.SendEldrinMessage(player, "Then enter the Wailing Caverns. Below the Barrens, Naralex's dream has become a nightmare.")
        player:GossipComplete()
        return
    end

    -- Act III: Westfall / Deadmines
    if intid == 301 then
        ApplyWestfallVeilToGroup(player)
        U.SendEldrinMessage(player, "The Campaign Veil surrounds you. Walk through Westfall as a witness, not an invader.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.WESTFALL_SENTINEL_HILL.map,
            L.WESTFALL_SENTINEL_HILL.x,
            L.WESTFALL_SENTINEL_HILL.y,
            L.WESTFALL_SENTINEL_HILL.z,
            L.WESTFALL_SENTINEL_HILL.o
        )
        return
    end

    if intid == 302 then
        U.SendEldrinMessage(player, "I will send you to Westfall. Listen before you judge.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.WESTFALL_SENTINEL_HILL.map,
            L.WESTFALL_SENTINEL_HILL.x,
            L.WESTFALL_SENTINEL_HILL.y,
            L.WESTFALL_SENTINEL_HILL.z,
            L.WESTFALL_SENTINEL_HILL.o
        )
        return
    end

    if intid == 303 then
        U.SendEldrinMessage(player, "At Sentinel Hill, speak with the Westfall Farmer, the Stormwind Marshal, and the Defias Informant. Each carries part of the truth.")
        player:GossipComplete()
        return
    end

    if intid == 304 then
        U.SendEldrinMessage(player, "Then enter the Deadmines. Beneath Moonbrook, the Brotherhood has turned betrayal into rebellion.")
        player:GossipComplete()
        return
    end

    if intid == 305 then
        U.SendEldrinMessage(player, "The SI:7 agent is watching Moonbrook from the shadows. Speak with the agent, then gather your allies and push toward the Deadmines entrance.")
        player:GossipComplete()
        return
    end

    -- Act III Part 2: Stormwind / Stockades
    if intid == 401 then
        if Frostforge.CampaignVeil then
            Frostforge.CampaignVeil.Apply(player, Frostforge.Faction.STORMWIND_WITNESS)

            local group = player:GetGroup()
            if group then
                for _, member in pairs(group:GetMembers()) do
                    if member and member:IsInWorld() then
                        Frostforge.CampaignVeil.Apply(member, Frostforge.Faction.STORMWIND_WITNESS)
                    end
                end
            end
        end

        U.SendEldrinMessage(player, "The Campaign Veil surrounds you. Walk through Stormwind as a witness, not an invader.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.STORMWIND_OLD_TOWN.map,
            L.STORMWIND_OLD_TOWN.x,
            L.STORMWIND_OLD_TOWN.y,
            L.STORMWIND_OLD_TOWN.z,
            L.STORMWIND_OLD_TOWN.o
        )
        return
    end

    if intid == 402 then
        U.SendEldrinMessage(player, "I will send you to Stormwind. The next answers lie beneath the city.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.STORMWIND_OLD_TOWN.map,
            L.STORMWIND_OLD_TOWN.x,
            L.STORMWIND_OLD_TOWN.y,
            L.STORMWIND_OLD_TOWN.z,
            L.STORMWIND_OLD_TOWN.o
        )
        return
    end

    if intid == 403 then
        U.SendEldrinMessage(player, "Follow the SI:7 report to Stormwind, then speak with the Informant, the Prison Warden, and the Defias Prisoner near the Stockades.")
        player:GossipComplete()
        return
    end

    if intid == 404 then
        U.SendEldrinMessage(player, "Enter the Stockades and defeat Bazil Thredd. The Defias wound did not die with VanCleef.")
        player:GossipComplete()
        return
    end


    player:GossipComplete()
end

RegisterCreatureGossipEvent(NPC.ELDRIN, 1, OnEldrinGossipHello)
RegisterCreatureGossipEvent(NPC.ELDRIN, 2, OnEldrinGossipSelect)

print("[Frostforge] Central Eldrin gossip loaded.")
