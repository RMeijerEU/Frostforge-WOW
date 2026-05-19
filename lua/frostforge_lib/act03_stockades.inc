-- Frostforge Act III — The Defias Brotherhood
-- Part 2 — SI:7 / The Stockades

Frostforge = Frostforge or {}
Frostforge.Act03Stockades = Frostforge.Act03Stockades or {}

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local U = Frostforge.Utils
local Veil = Frostforge.CampaignVeil

local function IsHorde(player)
    return player:GetTeam() == Frostforge.Team.HORDE
end

local function ApplyStormwindVeilToGroup(player)
    -- Stormwind is Alliance territory. The campaign veil keeps Horde players safe for the story chapter.
    if not Veil then
        return
    end

    Veil.Apply(player, Frostforge.Faction.STORMWIND_WITNESS)

    local group = player:GetGroup()
    if not group then
        return
    end

    local members = group:GetMembers()
    for _, member in pairs(members) do
        if member and member:IsInWorld() then
            Veil.Apply(member, Frostforge.Faction.STORMWIND_WITNESS)
        end
    end
end

local function GetStockadesWitnessText(entry)
    if entry == NPC.DEF_SI7_AGENT then
        return "VanCleef is dead, but the Brotherhood is not. SI:7 has taken prisoners, intercepted messages, and captured men who may know how far the rebellion reached. The next answers are in Stormwind."
    end

    if entry == NPC.ST_STORMWIND_INFORMANT then
        return "The prisoners were brought beneath Stormwind under heavy guard. Officially, this is justice. SI:7 is less certain. We need to know whether the Brotherhood acted alone, and what Stormwind may have missed."
    end

    if entry == NPC.ST_PRISON_WARDEN then
        return "You have reached the Stockades. Down below are thieves, murderers, rebels, and men who chose the wrong banner when Westfall began to starve. Speak with the prisoner nearby before you enter. You should understand what Stormwind has locked away."
    end

    if entry == NPC.ST_DEFIAS_PRISONER then
        return "You killed VanCleef and call it victory? The masons built Stormwind with their hands and were paid with silence. The prison will not hold that truth forever."
    end

    return "The Stockades hold more than prisoners. They hold consequences."
end

local function OnStockadesWitnessGossipHello(event, player, creature)
    player:GossipClearMenu()

    local entry = creature:GetEntry()

    if entry == NPC.DEF_SI7_AGENT
        and player:HasQuest(Q.ST_ASHES)
        and not player:GetQuestRewardStatus(Q.ST_ASHES) then

        player:GossipMenuAddItem(0, "Ask what SI:7 found after VanCleef's death.", 0, 1)

    elseif entry == NPC.ST_STORMWIND_INFORMANT
        and (
            (player:HasQuest(Q.ST_SI7_REPORT) and not player:GetQuestRewardStatus(Q.ST_SI7_REPORT))
            or (player:HasQuest(Q.ST_STORMWIND) and not player:GetQuestRewardStatus(Q.ST_STORMWIND))
        ) then

        player:GossipMenuAddItem(0, "Ask about the Stockades report.", 0, 1)

    elseif entry == NPC.ST_PRISON_WARDEN
        and player:HasQuest(Q.ST_STORMWIND)
        and not player:GetQuestRewardStatus(Q.ST_STORMWIND) then

        player:GossipMenuAddItem(0, "Report to the Stockades entrance.", 0, 1)

    elseif entry == NPC.ST_DEFIAS_PRISONER
        and player:HasQuest(Q.ST_PRISON)
        and not player:GetQuestRewardStatus(Q.ST_PRISON) then

        player:GossipMenuAddItem(0, "Ask why the Defias still fight.", 0, 1)

    else
        player:GossipMenuAddItem(0, "Who are you?", 0, 2)
    end

    player:GossipSendMenu(1, creature)
end

local function OnStockadesWitnessGossipSelect(event, player, creature, sender, intid, code, menu_id)
    player:GossipClearMenu()

    local entry = creature:GetEntry()

    if intid == 1 then
        local text = GetStockadesWitnessText(entry)

        player:SendBroadcastMessage("|cff66ccff" .. creature:GetName() .. ":|r " .. text)

        if creature.SendUnitSay then
            creature:SendUnitSay(text, 0)
        end

        if entry == NPC.DEF_SI7_AGENT
            and player:HasQuest(Q.ST_ASHES)
            and not player:GetQuestRewardStatus(Q.ST_ASHES) then

            player:KilledMonsterCredit(NPC.DEF_SI7_AGENT)
            player:SendBroadcastMessage("|cff66ccffFrostforge:|r SI:7 follow-up recorded.")
        end

        if entry == NPC.ST_STORMWIND_INFORMANT then
            if player:HasQuest(Q.ST_SI7_REPORT)
                and not player:GetQuestRewardStatus(Q.ST_SI7_REPORT) then

                player:KilledMonsterCredit(NPC.ST_STORMWIND_INFORMANT)
                player:SendBroadcastMessage("|cff66ccffFrostforge:|r SI:7 report recorded.")
            end

            if player:HasQuest(Q.ST_STORMWIND)
                and not player:GetQuestRewardStatus(Q.ST_STORMWIND) then

                player:KilledMonsterCredit(NPC.ST_STORMWIND_INFORMANT)
                player:SendBroadcastMessage("|cff66ccffFrostforge:|r Stormwind arrival recorded.")
            end
        end

	if entry == NPC.ST_PRISON_WARDEN then
	    if player:HasQuest(Q.ST_STORMWIND)
	        and not player:GetQuestRewardStatus(Q.ST_STORMWIND) then

	        player:KilledMonsterCredit(NPC.ST_PRISON_WARDEN)
	        player:SendBroadcastMessage("|cff66ccffFrostforge:|r Stockades arrival recorded.")
	    end
	end

        if entry == NPC.ST_DEFIAS_PRISONER
            and player:HasQuest(Q.ST_PRISON)
            and not player:GetQuestRewardStatus(Q.ST_PRISON) then

            player:KilledMonsterCredit(NPC.ST_DEFIAS_PRISONER)
            player:SendBroadcastMessage("|cff66ccffFrostforge:|r Prisoner testimony recorded.")
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

local function OnStockadesPlayerLogin(event, player)
    if player:HasQuest(Q.ST_ASHES)
        or player:HasQuest(Q.ST_SI7_REPORT)
        or player:HasQuest(Q.ST_STORMWIND)
        or player:HasQuest(Q.ST_PRISON)
        or player:HasQuest(Q.ST_DUNGEON) then

        if IsHorde(player) then
            ApplyStormwindVeilToGroup(player)
            U.SendPathMessage(player, "Your Campaign Veil has been restored for the Stormwind chapter.")
        end
    end
end

local function OnStockadesQuestAccept(event, player, quest)
    local questId = U.GetQuestIdSafe(quest)

    if questId == Q.ST_ASHES then
        U.SendEldrinMessage(player, "VanCleef is dead, but the Brotherhood's trail continues. Speak with SI:7 and learn what Stormwind has taken from the Deadmines.")
        return
    end

    if questId == Q.ST_STORMWIND then
        if IsHorde(player) then
            ApplyStormwindVeilToGroup(player)
            U.SendEldrinMessage(player, "The Campaign Veil will protect you within Stormwind. Walk as a witness, not an invader.")
        else
            U.SendEldrinMessage(player, "Travel to Stormwind. The next answers lie beneath its streets.")
        end
        return
    end

    if questId == Q.ST_DUNGEON then
        U.SendEldrinMessage(player, "Enter the Stockades and defeat Bazil Thredd. Stormwind's prison has become another battlefield.")
        return
    end
end

local function OnStockadesQuestReward(event, player, quest, opt)
    local questId = U.GetQuestIdSafe(quest)

    if questId == Q.ST_ASHES then
        U.SendEldrinMessage(player, "SI:7 confirms it: VanCleef's death did not end the story.")
        U.SendPathMessage(player, "Ashes of the Brotherhood complete.")
        return
    end

    if questId == Q.ST_SI7_REPORT then
        U.SendEldrinMessage(player, "The report points to Stormwind itself. The Defias prisoners were taken below the city, into the Stockades.")
        U.SendPathMessage(player, "The SI:7 Report complete.")
        return
    end

    if questId == Q.ST_STORMWIND then
        U.SendEldrinMessage(player, "Stormwind stands rebuilt, but its old debts still echo beneath stone and iron.")
        U.SendPathMessage(player, "Into Stormwind complete.")
        return
    end

    if questId == Q.ST_PRISON then
        if player:GetLevel() < Frostforge.Level.STOCKADES_PREP then
            player:SetLevel(Frostforge.Level.STOCKADES_PREP)

            if Frostforge.AutoTraining and Frostforge.AutoTraining.TrainPlayerForCurrentLevel then
                Frostforge.AutoTraining.TrainPlayerForCurrentLevel(player, true)
            end

            U.SendPathMessage(player, "You have advanced to level 24.")
        end

        player:AddItem(858, 5)   -- Lesser Healing Potion
        player:AddItem(929, 5)   -- Healing Potion
        player:AddItem(2455, 5)  -- Minor Mana Potion
        player:AddItem(3385, 5)  -- Lesser Mana Potion
        player:ModifyMoney(20000)

        U.SendEldrinMessage(player, "You have heard the law. You have heard the prisoner. Now enter the Stockades and see what Stormwind has locked away.")
        U.SendGuideMessage(player, "Use the Frostforge Guide at the entrance to prepare your group.")
        U.SendPathMessage(player, "The Prison Below complete.")
        return
    end

    if questId == Q.ST_DUNGEON then

	if Frostforge.Rewards and Frostforge.Rewards.GiveStockadesClassReward then
	    Frostforge.Rewards.GiveStockadesClassReward(player)
	end

        if player:GetLevel() < Frostforge.Level.STOCKADES_REWARD then
            player:SetLevel(Frostforge.Level.STOCKADES_REWARD)

            if Frostforge.AutoTraining and Frostforge.AutoTraining.TrainPlayerForCurrentLevel then
                Frostforge.AutoTraining.TrainPlayerForCurrentLevel(player, true)
            end

            U.SendPathMessage(player, "You have advanced to level 26.")
        end

        player:ModifyMoney(40000)

        if Veil then
            Veil.RemoveFromGroup(player)
        end

        U.SendEldrinMessage(player, "Bazil Thredd is defeated, but the lesson remains: the Defias were never only a gang. They were the sound of a kingdom failing to listen.")
        U.SendPathMessage(player, "The Stockades complete. Act III now turns from rebellion to consequence.")
        return
    end
end

-- 900043 is already handled by act03_defias.inc.
-- Do not register it here, or the SI:7 gossip menu conflicts.
-- RegisterCreatureGossipEvent(NPC.DEF_SI7_AGENT, 1, OnStockadesWitnessGossipHello)
-- RegisterCreatureGossipEvent(NPC.DEF_SI7_AGENT, 2, OnStockadesWitnessGossipSelect)

RegisterCreatureGossipEvent(NPC.ST_STORMWIND_INFORMANT, 1, OnStockadesWitnessGossipHello)
RegisterCreatureGossipEvent(NPC.ST_STORMWIND_INFORMANT, 2, OnStockadesWitnessGossipSelect)

RegisterCreatureGossipEvent(NPC.ST_PRISON_WARDEN, 1, OnStockadesWitnessGossipHello)
RegisterCreatureGossipEvent(NPC.ST_PRISON_WARDEN, 2, OnStockadesWitnessGossipSelect)

RegisterCreatureGossipEvent(NPC.ST_DEFIAS_PRISONER, 1, OnStockadesWitnessGossipHello)
RegisterCreatureGossipEvent(NPC.ST_DEFIAS_PRISONER, 2, OnStockadesWitnessGossipSelect)

RegisterPlayerEvent(31, OnStockadesQuestAccept)
RegisterPlayerEvent(54, OnStockadesQuestReward)
RegisterPlayerEvent(3, OnStockadesPlayerLogin)

print("[Frostforge] Act III Stockades loaded.")
