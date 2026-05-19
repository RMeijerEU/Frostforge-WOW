-- Frostforge Act I — Broken Kingdoms
-- Chapter 1 — Ragefire Chasm

Frostforge = Frostforge or {}
Frostforge.Act01RFC = Frostforge.Act01RFC or {}

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local M = Frostforge.Map
local L = Frostforge.Location
local U = Frostforge.Utils
local Veil = Frostforge.CampaignVeil
local Starter = Frostforge.StarterGear
local Rewards = Frostforge.Rewards

local function OnEldrinGossipHello(event, player, creature)
    player:GossipClearMenu()

    player:GossipAddQuests(creature)

    player:GossipMenuAddItem(0, "How does the Frostforge Path work?", 0, 30)

    if Frostforge
        and Frostforge.Quest
        and Frostforge.Quest.DM_DUNGEON
        and not player:GetQuestRewardStatus(Frostforge.Quest.DM_DUNGEON) then

        if player:GetTeam() == Frostforge.Team.HORDE then
            player:GossipMenuAddItem(0, "Send me to Sentinel Hill under the Campaign Veil.", 0, 301)
        else
            player:GossipMenuAddItem(0, "Send me to Sentinel Hill.", 0, 302)
        end
    end

    if player:HasQuest(Q.ORGRIMMAR) and not player:GetQuestRewardStatus(Q.ORGRIMMAR) then
        player:GossipMenuAddItem(0, "Send me to Orgrimmar. I am ready to investigate.", 0, 20)
        player:GossipMenuAddItem(0, "Restore my normal faction.", 0, 22)
    end

    player:GossipSendMenu(1, creature)
end

local function OnEldrinGossipSelect(event, player, creature, sender, intid, code, menu_id)
    player:GossipClearMenu()

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

    if intid == 30 then
        U.SendEldrinMessage(player, "The Frostforge Path is a Classic Lore Campaign. You will walk through the stories that shaped Azeroth, one dungeon chapter at a time.")
        U.SendEldrinMessage(player, "Some chapters belong to your people. Some belong to your enemies. All of them matter.")
        player:GossipComplete()
        return
    end

    if intid == 301 then
        if Frostforge.CampaignVeil then
            Frostforge.CampaignVeil.Apply(player, Frostforge.Faction.NEUTRAL)

            local group = player:GetGroup()
            if group then
                for _, member in pairs(group:GetMembers()) do
                    if member and member:IsInWorld() then
                        Frostforge.CampaignVeil.Apply(member, Frostforge.Faction.NEUTRAL)
                    end
                end
            end
        end

        Frostforge.Utils.SendEldrinMessage(player, "The Campaign Veil surrounds you. Walk through Westfall as a witness, not an invader.")
        player:GossipComplete()

        Frostforge.Utils.TeleportPlayerGroup(
            player,
            Frostforge.Location.WESTFALL_SENTINEL_HILL.map,
            Frostforge.Location.WESTFALL_SENTINEL_HILL.x,
            Frostforge.Location.WESTFALL_SENTINEL_HILL.y,
            Frostforge.Location.WESTFALL_SENTINEL_HILL.z,
            Frostforge.Location.WESTFALL_SENTINEL_HILL.o
        )
        return
    end

    if intid == 302 then
        Frostforge.Utils.SendEldrinMessage(player, "I will send you to Westfall. Listen before you judge.")
        player:GossipComplete()

        Frostforge.Utils.TeleportPlayerGroup(
            player,
            Frostforge.Location.WESTFALL_SENTINEL_HILL.map,
            Frostforge.Location.WESTFALL_SENTINEL_HILL.x,
            Frostforge.Location.WESTFALL_SENTINEL_HILL.y,
            Frostforge.Location.WESTFALL_SENTINEL_HILL.z,
            Frostforge.Location.WESTFALL_SENTINEL_HILL.o
        )
        return
    end

    player:GossipComplete()
end

local function GetInvestigationText(entry)
    if entry == NPC.ORG_GRUNT then
        return "You hear it too, don't you? The city is young, but the stones beneath it are not quiet. Smoke rises from the Cleft of Shadow, and some of the grunts swear they hear chanting below. Thrall built Orgrimmar to be a new beginning, but something old is still burning under our feet."
    end

    if entry == NPC.ORG_SHAMAN then
        return "The elements beneath Orgrimmar are restless. Fire answers fire. Rage answers rage. This is not merely a cave beneath the city; it is a wound where old corruption still gathers. If the Horde wishes to be free of its past, it must first face what still lives below."
    end

    if entry == NPC.ORG_GUARD then
        return "The reports all point to Ragefire Chasm. Cultists, beasts, and worse have been seen below the city. Do not go alone. Gather allies before entering. If Taragaman still feeds in the depths, then this is more than a disturbance — it is a warning."
    end

    return "There is trouble beneath Orgrimmar."
end

local function OnInvestigationGossipHello(event, player, creature)
    player:GossipClearMenu()

    if player:HasQuest(Q.ORGRIMMAR) and not player:GetQuestRewardStatus(Q.ORGRIMMAR) then
        player:GossipMenuAddItem(0, "Ask about the trouble beneath Orgrimmar.", 0, 1)
    else
        player:GossipMenuAddItem(0, "Who are you?", 0, 2)
    end

    player:GossipSendMenu(1, creature)
end

local function OnInvestigationGossipSelect(event, player, creature, sender, intid, code, menu_id)
    player:GossipClearMenu()

    local entry = creature:GetEntry()

    if intid == 1 then
        local text = GetInvestigationText(entry)

        player:SendBroadcastMessage("|cff66ccff" .. creature:GetName() .. ":|r " .. text)

        if creature.SendUnitSay then
            creature:SendUnitSay(text, 0)
        end

        if player:HasQuest(Q.ORGRIMMAR) and not player:GetQuestRewardStatus(Q.ORGRIMMAR) then
            player:KilledMonsterCredit(entry)
            player:SendBroadcastMessage("|cff66ccffFrostforge:|r Investigation progress recorded.")
        end

        player:GossipComplete()
        return
    end

    if intid == 2 then
        local text = "I am a witness along the Frostforge Path."

        player:SendBroadcastMessage("|cff66ccff" .. creature:GetName() .. ":|r " .. text)

        if creature.SendUnitSay then
            creature:SendUnitSay(text, 0)
        end

        player:GossipComplete()
        return
    end

    player:GossipComplete()
end

local function OnQuestAccept(event, player, quest)
    local questId = U.GetQuestIdSafe(quest)

    if questId == Q.ORGRIMMAR then
        Veil.ApplyOrgrimmarToGroup(player)
        U.SendEldrinMessage(player, "The Campaign Veil will protect you during this chapter.")
        U.SendEldrinMessage(player, "Speak with me again when you are ready to travel to Orgrimmar.")
        return
    end
end

local function OnQuestReward(event, player, quest, opt)
    local questId = U.GetQuestIdSafe(quest)

    if questId == Q.WELCOME then
        U.SendEldrinMessage(player, "Next, claim your starter gear.")
        return
    end

    if questId == Q.STARTER_GEAR then
        Starter.LearnLevel10ClassSpells(player)
        Starter.GiveStarterSupplies(player)

        U.SendEldrinMessage(player, "Your starter supplies have been added.")
        U.SendEldrinMessage(player, "Equip your items, then begin the first lore chapter.")
        return
    end

    if questId == Q.ORGRIMMAR then
        Veil.RemoveFromGroup(player)
        U.SendPathMessage(player, "Trouble Beneath Orgrimmar complete. The trail now leads into Ragefire Chasm.")
        return
    end

    if questId == Q.GROUP then
        U.SendEldrinMessage(player, "Good. Use the Frostforge Guide to create a group, then prepare to enter Ragefire Chasm.")
        U.SendGuideMessage(player, "In dungeons, target an enemy and use /p attack to make your bots attack your target.")
        return
    end

    if questId == Q.RFC then
        Rewards.GiveRFCClassReward(player)

        if player:GetLevel() < Frostforge.Level.RFC_REWARD then
	    player:SetLevel(Frostforge.Level.RFC_REWARD)

	    if Frostforge.AutoTraining and Frostforge.AutoTraining.TrainPlayerForCurrentLevel then
	    Frostforge.AutoTraining.TrainPlayerForCurrentLevel(player, true)
	end

	U.SendPathMessage(player, "You have advanced to level 15.")
        end

        player:ModifyMoney(20000)

        U.SendEldrinMessage(player, "You have seen the truth beneath Orgrimmar. The Horde may be building a new future, but the past still burns below its feet.")
        U.SendPathMessage(player, "Ragefire Chasm complete. Your next dungeon trial awaits.")
        return
    end
end

local function OnPlayerLogout(event, player)
    Veil.Remove(player)
end

-- RegisterCreatureGossipEvent(NPC.ELDRIN, 1, OnEldrinGossipHello)
-- RegisterCreatureGossipEvent(NPC.ELDRIN, 2, OnEldrinGossipSelect)

RegisterCreatureGossipEvent(NPC.ORG_GRUNT, 1, OnInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC.ORG_GRUNT, 2, OnInvestigationGossipSelect)

RegisterCreatureGossipEvent(NPC.ORG_SHAMAN, 1, OnInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC.ORG_SHAMAN, 2, OnInvestigationGossipSelect)

RegisterCreatureGossipEvent(NPC.ORG_GUARD, 1, OnInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC.ORG_GUARD, 2, OnInvestigationGossipSelect)

RegisterPlayerEvent(31, OnQuestAccept)
RegisterPlayerEvent(54, OnQuestReward)
RegisterPlayerEvent(4, OnPlayerLogout)

print("[Frostforge] Act I RFC loaded.")
