-- Frostforge Act V — Blackfathom Deeps

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

local function OnBFDQuestAccept(event, player, quest)
    local questId = C.GetQuestId(quest)

    if questId == Q.BFD_TRAVEL then
        C.SendMessage(player, "The next wound lies on the Zoram Strand. Ancient ruins sink beneath the sea, and the Twilight's Hammer listens to what stirs below. Speak with me again when you are ready to travel.")
        return
    end

    if questId == Q.BFD_TWILIGHT then
        C.SendMessage(player, "Speak with the Zoram Scout. The shore has eyes, and those eyes have seen cultists moving near the ruins.")
        return
    end

    if questId == Q.BFD_DEPTHS then
        C.SendMessage(player, "The Twilight's Hammer does not seek conquest. It seeks ruin. Confront the acolyte near Blackfathom Deeps.")
        return
    end

    if questId == Q.BFD_GROUP then
        C.SendMessage(player, "Gather your allies at Blackfathom Deeps. Speak with me again when you are ready to travel to the entrance.")
        return
    end

    if questId == Q.BFD_DUNGEON then
        C.SendMessage(player, "Enter Blackfathom Deeps and defeat Aku'mai. Silence the creature at the heart of the ruins.")
        return
    end
end

local function OnBFDQuestReward(event, player, quest, opt)
    local questId = C.GetQuestId(quest)

    if questId == Q.BFD_DUNGEON then
        C.HandleDungeonReward(
            player,
            LVL.BFD_REWARD,
            "GiveBFDClassReward",
            "Blackfathom Deeps",
            "Aku'mai is defeated. The deep places are quieter now, but they are not empty."
        )
        return
    end
end

local function OnZoramScoutGossipHello(event, player, creature)
    C.GiveNpcObjectiveCredit(
        player,
        Q.BFD_TWILIGHT,
        NPC.BFD_ZORAM_SCOUT,
        nil
    )

    player:GossipClearMenu()
    player:GossipMenuAddItem(0, "What has the shore seen?", 0, 1)
    player:GossipSendMenu(1, creature)
end

local function OnZoramScoutGossipSelect(event, player, creature, sender, intid, code)
    player:GossipClearMenu()

    if intid == 1 then
        NpcSay(creature, "The tide has changed. Naga patrol closer to shore, and strangers in twilight robes walk the ruins as if they are answering a call.")
        player:GossipMenuAddItem(0, "Twilight robes?", 0, 2)
        player:GossipSendMenu(1, creature)
        return
    end

    if intid == 2 then
        NpcSay(creature, "Aye. The Twilight's Hammer. They do not come here for gold or land. They listen to the deep places. They believe something below listens back.")
        player:GossipMenuAddItem(0, "What is below Blackfathom Deeps?", 0, 3)
        player:GossipSendMenu(1, creature)
        return
    end

    if intid == 3 then
        NpcSay(creature, "Old ruins. Broken temples. Things the sea should have swallowed. And now Aku'mai stirs beneath them, worshipped like a sign from the darkness.")
        player:GossipMenuAddItem(0, "I will tell Eldrin.", 0, 4)
        player:GossipSendMenu(1, creature)
        return
    end

    if intid == 4 then
        NpcSay(creature, "Then go carefully. The shore is only the edge of it. Whatever waits below has had a long time to dream.")
        player:GossipComplete()
        return
    end

    player:GossipComplete()
end

local function OnTwilightAcolyteGossipHello(event, player, creature)
    C.GiveNpcObjectiveCredit(
        player,
        Q.BFD_DEPTHS,
        NPC.BFD_TWILIGHT_ACOLYTE,
        nil
    )

    player:GossipClearMenu()
    player:GossipMenuAddItem(0, "What do you hear below?", 0, 1)
    player:GossipSendMenu(1, creature)
end

local function OnTwilightAcolyteGossipSelect(event, player, creature, sender, intid, code)
    player:GossipClearMenu()

    if intid == 1 then
        NpcSay(creature, "You call it a dungeon. We call it a mouth. The stones below remember older masters than your kings and warchiefs.")
        player:GossipMenuAddItem(0, "You worship Aku'mai?", 0, 2)
        player:GossipSendMenu(1, creature)
        return
    end

    if intid == 2 then
        NpcSay(creature, "Aku'mai is not the end. It is a sign. A hunger with scales. A whisper made flesh. The deep places are waking, little hero.")
        player:GossipMenuAddItem(0, "This ends now.", 0, 3)
        player:GossipSendMenu(1, creature)
        return
    end

    if intid == 3 then
        NpcSay(creature, "Nothing ends. Everything sinks. Everything returns to the dark.")
        player:GossipComplete()
        return
    end

    player:GossipComplete()
end

RegisterPlayerEvent(31, OnBFDQuestAccept)
RegisterPlayerEvent(54, OnBFDQuestReward)

RegisterCreatureGossipEvent(NPC.BFD_ZORAM_SCOUT, 1, OnZoramScoutGossipHello)
RegisterCreatureGossipEvent(NPC.BFD_ZORAM_SCOUT, 2, OnZoramScoutGossipSelect)

RegisterCreatureGossipEvent(NPC.BFD_TWILIGHT_ACOLYTE, 1, OnTwilightAcolyteGossipHello)
RegisterCreatureGossipEvent(NPC.BFD_TWILIGHT_ACOLYTE, 2, OnTwilightAcolyteGossipSelect)

print("[Frostforge] Act V Blackfathom Deeps loaded.")
