-- Frostforge Act IV — Shadowfang Keep

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local LVL = Frostforge.Level
local C = Frostforge.Campaign

local LANG_UNIVERSAL = 0

local function NpcSay(creature, text)
    if creature and text then
        creature:SendUnitSay(text, LANG_UNIVERSAL)
    end
end

local function OnSFKQuestAccept(event, player, quest)
    local questId = C.GetQuestId(quest)

    if questId == Q.SFK_TRAVEL then
        C.SendMessage(player, "Silverpine lies north, beneath a shadow older than Stormwind's politics. Speak with me again when you are ready to travel.")
        return
    end

    if questId == Q.SFK_HOWLS then
        C.SendMessage(player, "Speak with the Forsaken Scout nearby. The dead keep watch in Silverpine, but even they fear what stalks the woods.")
        return
    end

    if questId == Q.SFK_CURSE then
        C.SendMessage(player, "The scout knows the attacks. The refugee knows the cost. Listen to the warning before we go to the keep.")
        return
    end

    if questId == Q.SFK_GROUP then
        C.SendMessage(player, "Travel to Shadowfang Keep. Speak with me again when you are ready to go.")
        return
    end

    if questId == Q.SFK_DUNGEON then
        C.SendMessage(player, "Enter Shadowfang Keep and defeat Archmage Arugal. End his command over the beasts.")
        return
    end
end

local function OnSFKQuestReward(event, player, quest, opt)
    local questId = C.GetQuestId(quest)

    if questId == Q.SFK_DUNGEON then
        C.HandleDungeonReward(
            player,
            LVL.SFK_REWARD,
            "GiveSFKClassReward",
            "Shadowfang Keep",
            "Arugal is defeated, but the curse he unleashed will not vanish with him. Power called in desperation rarely leaves when the battle is over."
        )
        return
    end
end

local function OnForsakenScoutGossipHello(event, player, creature)
    C.GiveNpcObjectiveCredit(
        player,
        Q.SFK_HOWLS,
        NPC.FORSAKEN_SCOUT,
        nil
    )

    player:GossipClearMenu()
    player:GossipMenuAddItem(0, "What happened in these woods?", 0, 1)
    player:GossipSendMenu(1, creature)
end

local function OnForsakenScoutGossipSelect(event, player, creature, sender, intid, code)
    player:GossipClearMenu()

    if intid == 1 then
        NpcSay(creature, "The beasts came from the keep. At first we thought them wolves. Then we saw them stand like men.")
        player:GossipMenuAddItem(0, "Arugal summoned them?", 0, 2)
        player:GossipSendMenu(1, creature)
        return
    end

    if intid == 2 then
        NpcSay(creature, "Aye. Arugal called them as weapons, but no one controls a curse for long. Shadowfang Keep is not a fortress anymore. It is a den.")
        player:GossipMenuAddItem(0, "I will report this to Eldrin.", 0, 3)
        player:GossipSendMenu(1, creature)
        return
    end

    if intid == 3 then
        NpcSay(creature, "Then go. And keep your blade close. In Silverpine, the trees have learned to listen.")
        player:GossipComplete()
        return
    end

    player:GossipComplete()
end

local function OnGilneanRefugeeGossipHello(event, player, creature)
    C.GiveNpcObjectiveCredit(
        player,
        Q.SFK_CURSE,
        NPC.GILNEAN_REFUGEE,
        nil
    )

    player:GossipClearMenu()
    player:GossipMenuAddItem(0, "Tell me what happened.", 0, 1)
    player:GossipSendMenu(1, creature)
end

local function OnGilneanRefugeeGossipSelect(event, player, creature, sender, intid, code)
    player:GossipClearMenu()

    if intid == 1 then
        NpcSay(creature, "We thought walls would save us. We thought distance would save us. But curses do not respect borders.")
        player:GossipMenuAddItem(0, "So Arugal lost control?", 0, 2)
        player:GossipSendMenu(1, creature)
        return
    end

    if intid == 2 then
        NpcSay(creature, "Arugal opened a door in desperation. The Worgen came through it. Now men become beasts, and beasts remember enough of men to hate us.")
        player:GossipMenuAddItem(0, "I understand. I will go to the keep.", 0, 3)
        player:GossipSendMenu(1, creature)
        return
    end

    if intid == 3 then
        NpcSay(creature, "Then end what he began, if such a thing can be ended.")
        player:GossipComplete()
        return
    end

    player:GossipComplete()
end

RegisterPlayerEvent(31, OnSFKQuestAccept)
RegisterPlayerEvent(54, OnSFKQuestReward)

RegisterCreatureGossipEvent(NPC.FORSAKEN_SCOUT, 1, OnForsakenScoutGossipHello)
RegisterCreatureGossipEvent(NPC.FORSAKEN_SCOUT, 2, OnForsakenScoutGossipSelect)

RegisterCreatureGossipEvent(NPC.GILNEAN_REFUGEE, 1, OnGilneanRefugeeGossipHello)
RegisterCreatureGossipEvent(NPC.GILNEAN_REFUGEE, 2, OnGilneanRefugeeGossipSelect)

print("[Frostforge] Act IV Shadowfang Keep loaded.")
