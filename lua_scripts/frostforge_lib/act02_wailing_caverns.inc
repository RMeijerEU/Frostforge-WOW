-- Frostforge Act II — The Dream Turns Feral
-- Chapter 1 — Wailing Caverns

Frostforge = Frostforge or {}
Frostforge.Act02WC = Frostforge.Act02WC or {}

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local U = Frostforge.Utils
local Veil = Frostforge.CampaignVeil

local function IsAlliance(player)
    return player:GetTeam() == Frostforge.Team.ALLIANCE
end

local function ApplyBarrensVeilToGroup(player)
    -- For now we reuse the Orgrimmar/Horde-friendly witness faction.
    -- If Crossroads guards still attack Alliance, we will tune this faction later.
    Veil.ApplyOrgrimmarToGroup(player)
end

local function OnWCPlayerLogin(event, player)
    if player:HasQuest(Q.WC_ROAD) or player:HasQuest(Q.WC_INVESTIGATION) then
        Veil.ApplyOrgrimmar(player)
        U.SendPathMessage(player, "Your Campaign Veil has been restored for the Barrens chapter.")
    end
end

local function GetWCInvestigationText(entry)
    if entry == NPC.WC_CROSSROADS_SCOUT then
        return "The Barrens have always been dangerous, but this is different. Beasts move like something is driving them from below. Travelers vanish near the caverns, and the land itself feels restless."
    end

    if entry == NPC.WC_DRUIDIC_ADEPT then
        return "Naralex entered the Emerald Dream to heal the Barrens. But the Dream is not a simple thing. If corruption touches it, hope can become nightmare. The Druids of the Fang are proof of that."
    end

    if entry == NPC.WC_BARRENS_WATCHER then
        return "The trail ends at the Wailing Caverns. Below this cave, the dream has turned feral. Gather your allies before you enter. Whatever waits inside is more than a beast."
    end

    return "The Barrens grow restless."
end

local function OnWCInvestigationGossipHello(event, player, creature)
    player:GossipClearMenu()

    local entry = creature:GetEntry()

    if entry == NPC.WC_CROSSROADS_SCOUT
        and player:HasQuest(Q.WC_ROAD)
        and not player:GetQuestRewardStatus(Q.WC_ROAD) then

        player:GossipMenuAddItem(0, "I have reached the Crossroads.", 0, 10)

    elseif player:HasQuest(Q.WC_INVESTIGATION) and not player:GetQuestRewardStatus(Q.WC_INVESTIGATION) then

        player:GossipMenuAddItem(0, "Ask about the restless Barrens.", 0, 1)

    else
        player:GossipMenuAddItem(0, "Who are you?", 0, 2)
    end

    player:GossipSendMenu(1, creature)
end

local function OnWCInvestigationGossipSelect(event, player, creature, sender, intid, code, menu_id)
    player:GossipClearMenu()

    local entry = creature:GetEntry()

    if intid == 10 then
        local text = "You have reached the Crossroads. From here, follow the signs of the wounded Barrens westward. The road to the Wailing Caverns begins here."

        player:SendBroadcastMessage("|cff66ccff" .. creature:GetName() .. ":|r " .. text)

        if creature.SendUnitSay then
            creature:SendUnitSay(text, 0)
        end

        if player:HasQuest(Q.WC_ROAD) and not player:GetQuestRewardStatus(Q.WC_ROAD) then
            player:KilledMonsterCredit(NPC.WC_CROSSROADS_SCOUT)
            player:SendBroadcastMessage("|cff66ccffFrostforge:|r Crossroads arrival recorded.")
        end

        player:GossipComplete()
        return
    end

    if intid == 1 then
        local text = GetWCInvestigationText(entry)

        player:SendBroadcastMessage("|cff66ccff" .. creature:GetName() .. ":|r " .. text)

        if creature.SendUnitSay then
            creature:SendUnitSay(text, 0)
        end

        if player:HasQuest(Q.WC_INVESTIGATION) and not player:GetQuestRewardStatus(Q.WC_INVESTIGATION) then
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

local function OnWCEldrinGossipHello(event, player, creature)
    -- This function adds Act II-specific travel options.
    -- It runs alongside the Act I Eldrin gossip registration.
    player:GossipClearMenu()

    player:GossipAddQuests(creature)

    if player:HasQuest(Q.WC_ROAD) and not player:GetQuestRewardStatus(Q.WC_ROAD) then
        if IsAlliance(player) then
            player:GossipMenuAddItem(0, "Send me to the Crossroads under the Campaign Veil.", 0, 201)
        else
            player:GossipMenuAddItem(0, "I have reached the Crossroads.", 0, 202)
            player:GossipMenuAddItem(0, "Send me to the Crossroads.", 0, 203)
        end
    end

    if player:HasQuest(Q.WC_INVESTIGATION) and not player:GetQuestRewardStatus(Q.WC_INVESTIGATION) then
        player:GossipMenuAddItem(0, "Send me to the Crossroads.", 0, 203)
        player:GossipMenuAddItem(0, "Remind me where to investigate.", 0, 204)
    end

    if player:HasQuest(Q.WC_GROUP) and not player:GetQuestRewardStatus(Q.WC_GROUP) then
        player:GossipMenuAddItem(0, "The group is ready for the Wailing Caverns.", 0, 205)
    end

    player:GossipSendMenu(1, creature)
end

local function OnWCEldrinGossipSelect(event, player, creature, sender, intid, code, menu_id)
    player:GossipClearMenu()

    if intid == 201 then
        ApplyBarrensVeilToGroup(player)
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

    if intid == 202 then
        U.SendEldrinMessage(player, "Good. Begin at the Crossroads, then follow the road west toward the Wailing Caverns.")
        player:GossipComplete()
        return
    end

    if intid == 203 then
        U.SendEldrinMessage(player, "I will send you to the Crossroads. Horde travelers should normally use the flight path, but the Frostforge Path will guide you for testing.")
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

    player:GossipComplete()
end

local function OnWCQuestAccept(event, player, quest)
    local questId = U.GetQuestIdSafe(quest)

    if questId == Q.WC_ROAD then
        if IsAlliance(player) then
            ApplyBarrensVeilToGroup(player)
            U.SendEldrinMessage(player, "The Campaign Veil will protect you during this chapter. Speak with me again when you are ready to travel to the Crossroads.")
        else
            U.SendEldrinMessage(player, "Travel to the Orgrimmar flight master and take the flight path to the Crossroads. For testing, I can also send you there directly.")
        end

        return
    end
end

local function OnWCQuestReward(event, player, quest, opt)
    local questId = U.GetQuestIdSafe(quest)

    if questId == Q.WC_INTRO then
        U.SendEldrinMessage(player, "The next chapter begins at the Crossroads. The Barrens are calling.")
        return
    end

    if questId == Q.WC_ROAD then
        U.SendEldrinMessage(player, "You have reached the Barrens. Now listen to what the land is trying to tell you.")
        return
    end

    if questId == Q.WC_INVESTIGATION then
        Veil.RemoveFromGroup(player)
        U.SendPathMessage(player, "The Barrens Grow Restless complete. The trail now leads into the Wailing Caverns.")
        return
    end

   if questId == Q.WC_GROUP then
        if player:GetLevel() < Frostforge.Level.WC_REWARD then
	player:SetLevel(Frostforge.Level.WC_REWARD)

	if Frostforge.AutoTraining and Frostforge.AutoTraining.TrainPlayerForCurrentLevel then
	    Frostforge.AutoTraining.TrainPlayerForCurrentLevel(player, true)
	end

	U.SendPathMessage(player, "You have advanced to level 20.")
        end

        if Frostforge.StarterGear and Frostforge.StarterGear.LearnWeaponSkillsForStarterGear then
            Frostforge.StarterGear.LearnWeaponSkillsForStarterGear(player)
        end

        player:AddItem(858, 5)   -- Lesser Healing Potion
        player:AddItem(2455, 3)  -- Minor Mana Potion
        player:ModifyMoney(15000)

        U.SendEldrinMessage(player, "The Wailing Caverns are deeper and more dangerous than Ragefire Chasm. I have prepared you for the descent.")
        U.SendEldrinMessage(player, "Use the Frostforge Guide to prepare your group. Then enter the Wailing Caverns.")
        U.SendGuideMessage(player, "Target an enemy and use /p attack to make your bots attack your target.")
        return
    end

        if questId == Q.WC_DUNGEON then
        if Rewards.GiveWCClassReward then
            Rewards.GiveWCClassReward(player)
        end

        player:ModifyMoney(25000)

        U.SendEldrinMessage(player, "You have seen the dream turn feral. The Barrens were meant to be healed, but beneath the earth, hope became nightmare.")
        U.SendPathMessage(player, "Wailing Caverns complete. The next chapter of the Frostforge Path awaits.")
        return
    end
end

-- RegisterCreatureGossipEvent(NPC.ELDRIN, 1, OnWCEldrinGossipHello)
-- RegisterCreatureGossipEvent(NPC.ELDRIN, 2, OnWCEldrinGossipSelect)

RegisterCreatureGossipEvent(NPC.WC_CROSSROADS_SCOUT, 1, OnWCInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC.WC_CROSSROADS_SCOUT, 2, OnWCInvestigationGossipSelect)

RegisterCreatureGossipEvent(NPC.WC_DRUIDIC_ADEPT, 1, OnWCInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC.WC_DRUIDIC_ADEPT, 2, OnWCInvestigationGossipSelect)

RegisterCreatureGossipEvent(NPC.WC_BARRENS_WATCHER, 1, OnWCInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC.WC_BARRENS_WATCHER, 2, OnWCInvestigationGossipSelect)

RegisterPlayerEvent(3, OnWCPlayerLogin)
RegisterPlayerEvent(31, OnWCQuestAccept)
RegisterPlayerEvent(54, OnWCQuestReward)

print("[Frostforge] Act II Wailing Caverns loaded.")
