-- Frostforge Campaign Helpers
-- Shared helper functions for campaign act files.

Frostforge = Frostforge or {}
Frostforge.Campaign = Frostforge.Campaign or {}

local C = Frostforge.Campaign

function C.GetQuestId(quest)
    if Frostforge.Utils and Frostforge.Utils.GetQuestIdSafe then
        return Frostforge.Utils.GetQuestIdSafe(quest)
    end

    if quest and quest.GetId then
        return quest:GetId()
    end

    return nil
end

function C.SendMessage(player, message)
    if not player or not message then
        return
    end

    if Frostforge.Utils and Frostforge.Utils.SendEldrinMessage then
        Frostforge.Utils.SendEldrinMessage(player, message)
    else
        player:SendBroadcastMessage("|cff66ccffFrostforge:|r " .. message)
    end
end

function C.IsQuestIncomplete(player, questId)
    if not player or not questId then
        return false
    end

    return player:HasQuest(questId) and not player:CanCompleteQuest(questId)
end

function C.GiveNpcObjectiveCredit(player, questId, npcEntry, message)
    if not player or not questId or not npcEntry then
        return
    end

    if C.IsQuestIncomplete(player, questId) then
        player:KilledMonsterCredit(npcEntry)

        if message then
            C.SendMessage(player, message)
        end
    end
end

function C.TeleportToLocation(player, loc)
    if not player or not loc then
        return
    end

    player:Teleport(loc.map, loc.x, loc.y, loc.z, loc.o)
end

function C.SetLevelIfBelow(player, level)
    if not player or not level then
        return
    end

    if player:GetLevel() < level then
        player:SetLevel(level)
    end
end

function C.AutoTrain(player)
    if Frostforge.Training and Frostforge.Training.AutoTrain then
        Frostforge.Training.AutoTrain(player)
    end
end

function C.GiveReward(player, rewardFunctionName, chapterName)
    if not player then
        return
    end

    if Frostforge.Rewards and rewardFunctionName and Frostforge.Rewards[rewardFunctionName] then
        Frostforge.Rewards[rewardFunctionName](player)
        return
    end

    player:SendBroadcastMessage("|cff66ccffFrostforge:|r No reward pack configured yet for " .. (chapterName or "this chapter") .. ".")
end

function C.CompleteGossip(event, player, creature, sender, intid, code)
    if player then
        player:GossipComplete()
    end
end

function C.SimpleObjectiveGossipHello(player, creature, questId, npcEntry, message, optionText)
    C.GiveNpcObjectiveCredit(player, questId, npcEntry, message)

    player:GossipClearMenu()
    player:GossipMenuAddItem(0, optionText or "I understand.", 0, 1)
    player:GossipSendMenu(1, creature)
end

function C.HandleDungeonReward(player, level, rewardFunctionName, chapterName, message)
    C.GiveReward(player, rewardFunctionName, chapterName)
    C.SetLevelIfBelow(player, level)
    C.AutoTrain(player)

    if message then
        C.SendMessage(player, message)
    end
end

print("[Frostforge] Campaign helpers loaded.")
