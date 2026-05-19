-- Frostforge Act III — The Defias Brotherhood
-- Chapter 1 — Westfall in Ruin / The Deadmines

Frostforge = Frostforge or {}
Frostforge.Act03Defias = Frostforge.Act03Defias or {}

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local U = Frostforge.Utils
local Veil = Frostforge.CampaignVeil

local function IsHorde(player)
    return player:GetTeam() == Frostforge.Team.HORDE
end

local function ApplyWestfallVeilToGroup(player)
    -- Westfall is Alliance territory.
    -- For campaign travel we use neutral witness faction.
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

local function GetDefiasInvestigationText(entry)
    if entry == NPC.DEF_WESTFALL_FARMER then
        return "You see fields. I see families abandoned by a kingdom that promised protection. The Defias find followers here because hunger listens better than loyalty."
    end

    if entry == NPC.DEF_STORMWIND_MARSHAL then
        return "Do not mistake the Defias for common thieves. They are organized, armed, and angry. Westfall has become the place where Stormwind's failures gather with blades in hand."
    end

    if entry == NPC.DEF_DEFIAS_INFORMANT then
        return "VanCleef was no simple bandit. The Brotherhood began with builders who rebuilt Stormwind and were cast aside. Now they build something else beneath Moonbrook. Something meant to make the kingdom listen."
    end

    if entry == NPC.DEF_SI7_AGENT then
        return "We have followed their coin, weapons, and messengers to Moonbrook. This is not a local gang anymore. VanCleef has built a command structure beneath the town, and the Brotherhood is preparing something far larger than raids on Westfall. From here on, do not travel alone. Speak with the Frostforge Guide nearby, gather your allies, then push through Moonbrook toward the Deadmines entrance. Archivist Eldrin is waiting near the portal."
    end

    return "Westfall has not forgotten what Stormwind chose to ignore."
end

local function OnDefiasInvestigationGossipHello(event, player, creature)
    player:GossipClearMenu()

    local entry = creature:GetEntry()

    -- 900121 arrival objective: reach Sentinel Hill and speak with Farmer
    if entry == NPC.DEF_WESTFALL_FARMER
        and player:HasQuest(Q.DM_INTRO)
        and not player:GetQuestRewardStatus(Q.DM_INTRO) then

        player:GossipMenuAddItem(0, "I have reached Sentinel Hill.", 0, 10)

    -- 900123 SI:7 objective has priority for SI:7 Agent
    elseif entry == NPC.DEF_SI7_AGENT
        and player:HasQuest(Q.ST_ASHES)
        and not player:GetQuestRewardStatus(Q.ST_ASHES) then

        player:GossipMenuAddItem(0, "Ask what SI:7 found after VanCleef's death.", 0, 6)

    elseif entry == NPC.DEF_SI7_AGENT
        and player:HasQuest(Q.DM_SI7)
        and not player:GetQuestRewardStatus(Q.DM_SI7) then

        player:GossipMenuAddItem(0, "Ask what SI:7 has discovered.", 0, 1)

    -- 900122 investigation objectives
    elseif player:HasQuest(Q.DM_INVESTIGATION)
        and not player:GetQuestRewardStatus(Q.DM_INVESTIGATION) then

        player:GossipMenuAddItem(0, "Ask about the Defias Brotherhood.", 0, 1)

    else
        player:GossipMenuAddItem(0, "Who are you?", 0, 2)
    end

    player:GossipSendMenu(1, creature)
end

local function OnDefiasInvestigationGossipSelect(event, player, creature, sender, intid, code, menu_id)
    player:GossipClearMenu()

    local entry = creature:GetEntry()

    if intid == 10 then
        local text = "You have reached Sentinel Hill. Look around you: broken farms, hungry people, and a kingdom too distant to hear them. Speak with Archivist Eldrin nearby, then listen to Westfall before you judge the Defias."

        player:SendBroadcastMessage("|cff66ccff" .. creature:GetName() .. ":|r " .. text)

        if creature.SendUnitSay then
            creature:SendUnitSay(text, 0)
        end

        if player:HasQuest(Q.DM_INTRO) and not player:GetQuestRewardStatus(Q.DM_INTRO) then
            player:KilledMonsterCredit(NPC.DEF_WESTFALL_FARMER)
            player:SendBroadcastMessage("|cff66ccffFrostforge:|r Sentinel Hill arrival recorded.")
        end

        player:GossipComplete()
        return
    end

    if intid == 1 then
        local text = GetDefiasInvestigationText(entry)

        player:SendBroadcastMessage("|cff66ccff" .. creature:GetName() .. ":|r " .. text)

        if creature.SendUnitSay then
            creature:SendUnitSay(text, 0)
        end

        -- 900122: Farmer / Marshal / Defias Informant credit
        if player:HasQuest(Q.DM_INVESTIGATION)
            and not player:GetQuestRewardStatus(Q.DM_INVESTIGATION)
            and (
                entry == NPC.DEF_WESTFALL_FARMER
                or entry == NPC.DEF_STORMWIND_MARSHAL
                or entry == NPC.DEF_DEFIAS_INFORMANT
            ) then

            player:KilledMonsterCredit(entry)
            player:SendBroadcastMessage("|cff66ccffFrostforge:|r Investigation progress recorded.")
        end

        -- 900123: SI:7 Agent credit
        if entry == NPC.DEF_SI7_AGENT
            and player:HasQuest(Q.DM_SI7)
            and not player:GetQuestRewardStatus(Q.DM_SI7) then

            player:KilledMonsterCredit(NPC.DEF_SI7_AGENT)
            player:SendBroadcastMessage("|cff66ccffFrostforge:|r SI:7 trail recorded.")
        end

        player:GossipComplete()
        return
    end

    if intid == 6 then
        local text = "VanCleef is dead, but the Brotherhood is not. SI:7 has taken prisoners, intercepted messages, and captured men who may know how far the rebellion reached. The next answers are in Stormwind's Stockades."

        player:SendBroadcastMessage("|cff66ccff" .. creature:GetName() .. ":|r " .. text)

        if creature.SendUnitSay then
            creature:SendUnitSay(text, 0)
        end

        if player:HasQuest(Q.ST_ASHES) and not player:GetQuestRewardStatus(Q.ST_ASHES) then
            player:KilledMonsterCredit(NPC.DEF_SI7_AGENT)
            player:SendBroadcastMessage("|cff66ccffFrostforge:|r SI:7 follow-up recorded.")
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

local function OnDefiasEldrinGossipHello(event, player, creature)
    player:GossipClearMenu()
    player:GossipAddQuests(creature)

    player:SendBroadcastMessage(
    "|cff66ccffFrostforge Debug ActIII:|r "
    .. "WC_DUNGEON=" .. tostring(Q.WC_DUNGEON)
    .. " WC_rewarded=" .. tostring(player:GetQuestRewardStatus(Q.WC_DUNGEON))
    .. " DM_DUNGEON=" .. tostring(Q.DM_DUNGEON)
    .. " DM_rewarded=" .. tostring(player:GetQuestRewardStatus(Q.DM_DUNGEON))
    )

    -- Robust Act III travel.
    -- If WC is completed and Deadmines is not completed yet, Eldrin can always send the player to Sentinel Hill.
    -- This prevents players getting stuck if they accepted/rewarded one of the travel quests in a weird state.
    -- Act III travel helper.
    -- Keep this broad so players cannot get stuck between WC and Deadmines.
    if not player:GetQuestRewardStatus(Q.DM_DUNGEON) then
        if IsHorde(player) then
            player:GossipMenuAddItem(0, "Send me to Sentinel Hill under the Campaign Veil.", 0, 301)
        else
            player:GossipMenuAddItem(0, "Send me to Sentinel Hill.", 0, 302)
        end
    end

    if player:HasQuest(Q.DM_INVESTIGATION)
        and not player:GetQuestRewardStatus(Q.DM_INVESTIGATION) then

        player:GossipMenuAddItem(0, "Remind me where to investigate.", 0, 303)
    end

    if player:HasQuest(Q.DM_SI7)
        and not player:GetQuestRewardStatus(Q.DM_SI7) then

        player:GossipMenuAddItem(0, "Remind me where the SI:7 agent is.", 0, 305)
    end

    if player:HasQuest(Q.DM_GROUP)
        and not player:GetQuestRewardStatus(Q.DM_GROUP) then

        player:GossipMenuAddItem(0, "The group is ready for the Deadmines.", 0, 304)
    end

    player:GossipSendMenu(1, creature)
end

local function OnDefiasEldrinGossipSelect(event, player, creature, sender, intid, code, menu_id)
    player:GossipClearMenu()

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

    player:GossipComplete()
end

local function OnDefiasQuestAccept(event, player, quest)
    local questId = U.GetQuestIdSafe(quest)

    if questId == Q.DM_INTRO then
        if IsHorde(player) then
            ApplyWestfallVeilToGroup(player)
            U.SendEldrinMessage(player, "The Campaign Veil will protect you during this chapter. Speak with me again when you are ready to travel to Westfall.")
        else
            U.SendEldrinMessage(player, "Travel to Westfall. The Defias story begins among those Stormwind forgot.")
        end
        return
    end
end

local function OnDefiasQuestReward(event, player, quest, opt)
    local questId = U.GetQuestIdSafe(quest)

    if questId == Q.DM_INTRO then
        U.SendEldrinMessage(player, "Westfall is not merely a land of bandits. It is a warning.")
        return
    end

    if questId == Q.DM_INVESTIGATION then
        U.SendPathMessage(player, "Westfall in Ruin complete. The trail now leads toward Moonbrook.")
        return
    end

    if questId == Q.DM_SI7 then
        U.SendEldrinMessage(player, "SI:7 confirms what Westfall already knew: the Brotherhood is organized, armed, and preparing something beneath Moonbrook.")
        U.SendEldrinMessage(player, "The road to the Deadmines is no longer safe. Gather your allies and push through Moonbrook to the portal.")
        U.SendPathMessage(player, "The SI:7 Trail complete. Continue to the Deadmines entrance.")
        return
    end

    if questId == Q.DM_GROUP then
        if player:GetLevel() < Frostforge.Level.DM_REWARD then
	player:SetLevel(Frostforge.Level.DM_REWARD)

	if Frostforge.AutoTraining and Frostforge.AutoTraining.TrainPlayerForCurrentLevel then
	    Frostforge.AutoTraining.TrainPlayerForCurrentLevel(player, true)
	end

	U.SendPathMessage(player, "You have advanced to level 22.")
        end

        if Frostforge.StarterGear and Frostforge.StarterGear.LearnWeaponSkillsForStarterGear then
            Frostforge.StarterGear.LearnWeaponSkillsForStarterGear(player)
        end

        player:AddItem(858, 5)   -- Lesser Healing Potion
        player:AddItem(2455, 3)  -- Minor Mana Potion
        player:ModifyMoney(15000)

        U.SendEldrinMessage(player, "The Deadmines are not a simple hideout. Prepare carefully before entering.")
        U.SendGuideMessage(player, "Target an enemy and use /p attack to make your bots attack your target.")
        return
    end

    if questId == Q.DM_DUNGEON then
        if Frostforge.Rewards and Frostforge.Rewards.GiveDMClassReward then
            Frostforge.Rewards.GiveDMClassReward(player)
        end

        player:ModifyMoney(30000)

        U.SendEldrinMessage(player, "You have seen the truth beneath Westfall. Stormwind may call itself restored, but its forgotten workers built a rebellion in the dark.")
        U.SendEldrinMessage(player, "But rebellion does not end when one man falls. If Stormwind built this wound, then the next chapter waits inside Stormwind itself.")
        U.SendPathMessage(player, "The Deadmines complete. The Defias story is not over.")
        return
    end
end

local function OnDefiasPlayerLogin(event, player)
    if player:HasQuest(Q.DM_INTRO)
        or player:HasQuest(Q.DM_INVESTIGATION)
        or player:HasQuest(Q.DM_SI7)
        or player:HasQuest(Q.DM_GROUP) then

        if IsHorde(player) then
            ApplyWestfallVeilToGroup(player)
            U.SendPathMessage(player, "Your Campaign Veil has been restored for the Westfall chapter.")
        end
    end
end

-- RegisterCreatureGossipEvent(NPC.ELDRIN, 1, OnDefiasEldrinGossipHello)
-- RegisterCreatureGossipEvent(NPC.ELDRIN, 2, OnDefiasEldrinGossipSelect)

RegisterCreatureGossipEvent(NPC.DEF_WESTFALL_FARMER, 1, OnDefiasInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC.DEF_WESTFALL_FARMER, 2, OnDefiasInvestigationGossipSelect)

RegisterCreatureGossipEvent(NPC.DEF_STORMWIND_MARSHAL, 1, OnDefiasInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC.DEF_STORMWIND_MARSHAL, 2, OnDefiasInvestigationGossipSelect)

RegisterCreatureGossipEvent(NPC.DEF_DEFIAS_INFORMANT, 1, OnDefiasInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC.DEF_DEFIAS_INFORMANT, 2, OnDefiasInvestigationGossipSelect)

RegisterCreatureGossipEvent(NPC.DEF_SI7_AGENT, 1, OnDefiasInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC.DEF_SI7_AGENT, 2, OnDefiasInvestigationGossipSelect)

RegisterPlayerEvent(31, OnDefiasQuestAccept)
RegisterPlayerEvent(54, OnDefiasQuestReward)
RegisterPlayerEvent(3, OnDefiasPlayerLogin)

print("[Frostforge] Act III Defias loaded.")
