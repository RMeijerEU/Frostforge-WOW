-- Frostforge Act V — Blackfathom Deeps

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local LVL = Frostforge.Level
local C = Frostforge.Campaign

local function OnBFDQuestAccept(event, player, quest)
    local questId = C.GetQuestId(quest)

    if questId == Q.BFD_TRAVEL then
        C.SendMessage(player, "The next wound lies on the Zoram Strand. Ancient ruins sink beneath the sea, and the Twilight's Hammer listens to what stirs below.")
        C.TeleportToLocation(player, L.ZORAM_STRAND)
        return
    end

    if questId == Q.BFD_TWILIGHT then
        C.SendMessage(player, "Speak with the Zoram Scout. The shore has eyes, and those eyes have seen cultists moving near the ruins.")
        return
    end

    if questId == Q.BFD_DEPTHS then
        C.SendMessage(player, "The Twilight's Hammer does not seek conquest. It seeks ruin. Confront the acolyte near Blackfathom Deeps.")
        C.TeleportToLocation(player, L.BFD_STAGING)
        return
    end

    if questId == Q.BFD_GROUP then
        C.SendMessage(player, "Gather your allies at Blackfathom Deeps. The Frostforge Guide will prepare your party.")
        C.TeleportToLocation(player, L.BFD_STAGING)
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
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.BFD_TWILIGHT,
        NPC.BFD_ZORAM_SCOUT,
        "The Zoram Scout reports naga movements, Twilight cultists, and strange sounds from the submerged ruins.",
        "What has the shore seen?"
    )
end

local function OnTwilightAcolyteGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.BFD_DEPTHS,
        NPC.BFD_TWILIGHT_ACOLYTE,
        "The Twilight Acolyte speaks of old things beneath the waves, and of Aku'mai as a sign from the depths.",
        "What do you hear below?"
    )
end

RegisterPlayerEvent(31, OnBFDQuestAccept)
RegisterPlayerEvent(54, OnBFDQuestReward)

RegisterCreatureGossipEvent(NPC.BFD_ZORAM_SCOUT, 1, OnZoramScoutGossipHello)
RegisterCreatureGossipEvent(NPC.BFD_ZORAM_SCOUT, 2, C.CompleteGossip)

RegisterCreatureGossipEvent(NPC.BFD_TWILIGHT_ACOLYTE, 1, OnTwilightAcolyteGossipHello)
RegisterCreatureGossipEvent(NPC.BFD_TWILIGHT_ACOLYTE, 2, C.CompleteGossip)

print("[Frostforge] Act V Blackfathom Deeps loaded.")
