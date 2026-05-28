-- Frostforge Central Eldrin Gossip
-- One gossip handler for Archivist Eldrin to prevent act-to-act gossip conflicts.

Frostforge = Frostforge or {}
Frostforge.EldrinGossip = Frostforge.EldrinGossip or {}

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local U = Frostforge.Utils
local Veil = Frostforge.CampaignVeil

local DUNGEON_HOME_BIND_BLOCKLIST = {
    [389] = true, -- Ragefire Chasm
    [43]  = true, -- Wailing Caverns
    [36]  = true, -- Deadmines
    [34]  = true, -- Stockades
    [33]  = true, -- Shadowfang Keep
    [48]  = true, -- Blackfathom Deeps
    [90]  = true, -- Gnomeregan
    [47]  = true, -- Razorfen Kraul
    [189] = true, -- Scarlet Monastery
    [70]  = true, -- Uldaman
    [209] = true  -- Zul'Farrak
}

local function IsQuestActive(player, questId)
    if not player or not questId then
        return false
    end

    return player:HasQuest(questId) and not player:GetQuestRewardStatus(questId)
end

local function HasOrgrimmarInvestigation(player)
    return IsQuestActive(player, Q.ORGRIMMAR) or IsQuestActive(player, 900102)
end

local function BindHearthstoneToEldrin(player, creature)
    if not player or not creature then
        return
    end

    local mapId = creature:GetMapId()

    -- Do not bind Hearthstone to dungeon/instance maps.
    if DUNGEON_HOME_BIND_BLOCKLIST[mapId] then
        return
    end

    local zoneId = creature:GetZoneId() or 0

    player:SetBindPoint(
        creature:GetX(),
        creature:GetY(),
        creature:GetZ(),
        mapId,
        zoneId
    )
end

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
    if HasOrgrimmarInvestigation(player) then
        player:GossipMenuAddItem(0, "Send me to Orgrimmar. I am ready to investigate.", 0, 20)
        player:GossipMenuAddItem(0, "Restore my normal faction.", 0, 22)
    end
end

local function AddActIIOptions(player)
    if IsQuestActive(player, Q.WC_ROAD) then
        if IsAlliance(player) then
            player:GossipMenuAddItem(0, "Send me to the Crossroads under the Campaign Veil.", 0, 201)
        else
            player:GossipMenuAddItem(0, "Send me to the Crossroads.", 0, 203)
        end
    end

    if IsQuestActive(player, Q.WC_INVESTIGATION) then
        if IsAlliance(player) then
            player:GossipMenuAddItem(0, "Send me to the Crossroads under the Campaign Veil.", 0, 201)
        else
            player:GossipMenuAddItem(0, "Send me to the Crossroads.", 0, 203)
        end

        player:GossipMenuAddItem(0, "Remind me where to investigate in the Barrens.", 0, 204)
    end

    if IsQuestActive(player, Q.WC_GROUP) then
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

    if IsQuestActive(player, Q.DM_INVESTIGATION) then
        player:GossipMenuAddItem(0, "Remind me where to investigate in Westfall.", 0, 303)
    end

    if IsQuestActive(player, Q.DM_SI7) then
        player:GossipMenuAddItem(0, "Remind me where the SI:7 agent is.", 0, 305)
    end

    if IsQuestActive(player, Q.DM_GROUP) then
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

    if IsQuestActive(player, Q.ST_DUNGEON) then
        player:GossipMenuAddItem(0, "Remind me what waits inside the Stockades.", 0, 404)
    end
end

local function AddActIVAndBeyondOptions(player, creature)
    if IsQuestActive(player, Q.SFK_TRAVEL) then
        player:GossipMenuAddItem(0, "Send me to Silverpine.", 0, 501)
    end

    if IsQuestActive(player, Q.SFK_GROUP) then
        player:GossipMenuAddItem(0, "Send me to Shadowfang Keep.", 0, 502)
    end

    if IsQuestActive(player, Q.BFD_TRAVEL) then
        player:GossipMenuAddItem(0, "Send me to the Zoram Strand.", 0, 503)
    end

    if IsQuestActive(player, Q.BFD_GROUP) then
        player:GossipMenuAddItem(0, "Send me to Blackfathom Deeps.", 0, 504)
    end

    if IsQuestActive(player, Q.GNOMER_TRAVEL) then
        player:GossipMenuAddItem(0, "Send me to Gnomeregan.", 0, 505)
    end

    if IsQuestActive(player, Q.GNOMER_GROUP) then
        player:GossipMenuAddItem(0, "Send me back to Gnomeregan.", 0, 506)
    end

    if IsQuestActive(player, Q.RFK_TRAVEL) then
        player:GossipMenuAddItem(0, "Send me to Razorfen Kraul.", 0, 507)
    end

    if IsQuestActive(player, Q.RFK_GROUP) then
        player:GossipMenuAddItem(0, "Send me back to Razorfen Kraul.", 0, 508)
    end

    local needsScarletTravel =
        IsQuestActive(player, Q.SM_RED_STANDARD)
        or IsQuestActive(player, Q.SM_FAITH_WITHOUT_MERCY)
        or IsQuestActive(player, Q.SM_ROAD)

    if needsScarletTravel then
        player:GossipMenuAddItem(0, "Send me to Scarlet Monastery.", 0, 509)
    end

    local needsUldamanTravel =
        IsQuestActive(player, Q.ULDAMAN_TITAN_ECHOES)
        or IsQuestActive(player, Q.ULDAMAN_DWARVEN_ORIGINS)
        or IsQuestActive(player, Q.ULDAMAN_TROGG_WARNING)
        or IsQuestActive(player, Q.ULDAMAN_GROUP)

    if needsUldamanTravel then
        player:GossipMenuAddItem(0, "Send me to Uldaman.", 0, 510)
    end

    local needsTanarisTravel =
        IsQuestActive(player, Q.ZF_SANDS_OF_TANARIS)

    if needsTanarisTravel then
        player:GossipMenuAddItem(0, "Send me to Gadgetzan.", 0, 511)
    end
end

local function CreditEldrinTravelObjectives(player, creature)
    if not player or not creature then
        return
    end

    local creditRules = {
        {
            quest = Q.SFK_TRAVEL,
            credit = 900071,
            map = 0,
            x = 506.0,
            y = 1613.0,
            z = 125.0,
            distance = 250
        },
        {
            quest = Q.SFK_GROUP,
            credit = 900072,
            map = L.SFK_STAGING.map,
            x = L.SFK_STAGING.x,
            y = L.SFK_STAGING.y,
            z = L.SFK_STAGING.z,
            distance = 100
        },
        {
            quest = Q.BFD_TRAVEL,
            credit = 900073,
            map = L.ZORAM_STRAND.map,
            x = L.ZORAM_STRAND.x,
            y = L.ZORAM_STRAND.y,
            z = L.ZORAM_STRAND.z,
            distance = 120
        },
        {
            quest = Q.BFD_GROUP,
            credit = 900074,
            map = L.BFD_INSIDE.map,
            x = L.BFD_INSIDE.x,
            y = L.BFD_INSIDE.y,
            z = L.BFD_INSIDE.z,
            distance = 150
        },
        {
            quest = Q.GNOMER_TRAVEL,
            credit = 900075,
            map = L.GNOMEREGAN_STAGING.map,
            x = L.GNOMEREGAN_STAGING.x,
            y = L.GNOMEREGAN_STAGING.y,
            z = L.GNOMEREGAN_STAGING.z,
            distance = 150
        },
        {
            quest = Q.GNOMER_GROUP,
            credit = 900075,
            map = L.GNOMEREGAN_STAGING.map,
            x = L.GNOMEREGAN_STAGING.x,
            y = L.GNOMEREGAN_STAGING.y,
            z = L.GNOMEREGAN_STAGING.z,
            distance = 150
        },
        {
            quest = Q.RFK_TRAVEL,
            credit = 900076,
            map = L.RFK_STAGING.map,
            x = L.RFK_STAGING.x,
            y = L.RFK_STAGING.y,
            z = L.RFK_STAGING.z,
            distance = 150
        },
        {
            quest = Q.RFK_GROUP,
            credit = 900076,
            map = L.RFK_STAGING.map,
            x = L.RFK_STAGING.x,
            y = L.RFK_STAGING.y,
            z = L.RFK_STAGING.z,
            distance = 150
        }
    }

    for _, rule in ipairs(creditRules) do
        if rule.quest
            and player:HasQuest(rule.quest)
            and not player:CanCompleteQuest(rule.quest)
            and creature:GetMapId() == rule.map
            and creature:GetDistance(rule.x, rule.y, rule.z) <= rule.distance then

            player:KilledMonsterCredit(rule.credit)

            -- Fallback for travel/event-style objectives.
            if not player:CanCompleteQuest(rule.quest) then
                player:AreaExploredOrEventHappens(rule.quest)
            end
        end
    end
end

local function OnEldrinGossipHello(event, player, creature)
    BindHearthstoneToEldrin(player, creature)
    CreditEldrinTravelObjectives(player, creature)

    player:GossipClearMenu()
    player:GossipAddQuests(creature)

    AddPathExplanation(player)
    AddActIOptions(player)
    AddActIIOptions(player)
    AddActIIIOptions(player, creature)
    AddActIIIStockadesOptions(player, creature)
    AddActIVAndBeyondOptions(player, creature)

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
        if HasOrgrimmarInvestigation(player) then
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

    -- Act IV+ travel helpers
    if intid == 501 then
        if IsAlliance(player) and Frostforge.CampaignVeil then
            Frostforge.CampaignVeil.Apply(player, Frostforge.Faction.NEUTRAL)

            local group = player:GetGroup()
            if group then
                for _, member in pairs(group:GetMembers()) do
                    if member and member:IsInWorld() then
                        Frostforge.CampaignVeil.Apply(member, Frostforge.Faction.NEUTRAL)
                    end
                end
            end

            U.SendEldrinMessage(player, "The Campaign Veil surrounds you. Walk through Silverpine as a witness, not an invader.")
        else
            U.SendEldrinMessage(player, "I will send you to Silverpine. Seek me near The Sepulcher, where the road turns cold and the howls begin.")
        end

        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.SILVERPINE_SEPULCHER.map,
            L.SILVERPINE_SEPULCHER.x,
            L.SILVERPINE_SEPULCHER.y,
            L.SILVERPINE_SEPULCHER.z,
            L.SILVERPINE_SEPULCHER.o
        )
        return
    end

    if intid == 502 then
        U.SendEldrinMessage(player, "I will send you to Shadowfang Keep. Gather your allies at its gates.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.SFK_STAGING.map,
            L.SFK_STAGING.x,
            L.SFK_STAGING.y,
            L.SFK_STAGING.z,
            L.SFK_STAGING.o
        )
        return
    end

    if intid == 503 then
        U.SendEldrinMessage(player, "I will send you to the Zoram Strand. Listen to the shore before you descend into the ruins.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.ZORAM_STRAND.map,
            L.ZORAM_STRAND.x,
            L.ZORAM_STRAND.y,
            L.ZORAM_STRAND.z,
            L.ZORAM_STRAND.o
        )
        return
    end

    if intid == 504 then
        U.SendEldrinMessage(player, "I will send you to Blackfathom Deeps. The ruins wait below.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.BFD_STAGING.map,
            L.BFD_STAGING.x,
            L.BFD_STAGING.y,
            L.BFD_STAGING.z,
            L.BFD_STAGING.o
        )
        return
    end

    if intid == 505 or intid == 506 then
        U.SendEldrinMessage(player, "I will send you to Gnomeregan. The fallen city still remembers its betrayal.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.GNOMEREGAN_STAGING.map,
            L.GNOMEREGAN_STAGING.x,
            L.GNOMEREGAN_STAGING.y,
            L.GNOMEREGAN_STAGING.z,
            L.GNOMEREGAN_STAGING.o
        )
        return
    end

    if intid == 507 or intid == 508 then
        U.SendEldrinMessage(player, "I will send you to Razorfen Kraul. The thorns remember older blood.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.RFK_STAGING.map,
            L.RFK_STAGING.x,
            L.RFK_STAGING.y,
            L.RFK_STAGING.z,
            L.RFK_STAGING.o
        )
        return
    end

    if intid == 509 then
        U.SendEldrinMessage(player, "I will send you to Scarlet Monastery. Listen carefully there: grief and righteousness often wear the same colors.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.SM_STAGING.map,
            L.SM_STAGING.x,
            L.SM_STAGING.y,
            L.SM_STAGING.z,
            L.SM_STAGING.o
        )
        return
    end

    if intid == 510 then
        U.SendEldrinMessage(player, "I will send you to Uldaman. The Badlands remember older truths than any kingdom.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.ULDAMAN_STAGING.map,
            L.ULDAMAN_STAGING.x,
            L.ULDAMAN_STAGING.y,
            L.ULDAMAN_STAGING.z,
            L.ULDAMAN_STAGING.o
        )
        return
    end

    if intid == 511 then
        U.SendEldrinMessage(player, "I will send you to Gadgetzan. From there, follow the desert road south toward Zul'Farrak.")
        player:GossipComplete()

        U.TeleportPlayerGroup(
            player,
            L.ZF_GADGETZAN.map,
            L.ZF_GADGETZAN.x,
            L.ZF_GADGETZAN.y,
            L.ZF_GADGETZAN.z,
            L.ZF_GADGETZAN.o
        )
        return
    end

    player:GossipComplete()
end

RegisterCreatureGossipEvent(NPC.ELDRIN, 1, OnEldrinGossipHello)
RegisterCreatureGossipEvent(NPC.ELDRIN, 2, OnEldrinGossipSelect)

print("[Frostforge] Central Eldrin gossip loaded.")