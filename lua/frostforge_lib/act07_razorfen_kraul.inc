-- Frostforge Act VII — Razorfen Kraul

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local LVL = Frostforge.Level
local C = Frostforge.Campaign

local function OnRFKQuestAccept(event, player, quest)
    local questId = C.GetQuestId(quest)

    if questId == Q.RFK_TRAVEL then
        C.SendMessage(player, "The Barrens hides more than dust and bones. Razorfen Kraul is a thorn-walled remnant of an older story: Agamaggan, sacred thorns, and a people driven into violence.")
        C.TeleportToLocation(player, L.RFK_STAGING)
        return
    end

    if questId == Q.RFK_THORNS then
        C.SendMessage(player, "Speak with the Barrens Messenger. The roads carry warnings from those who live in the shadow of the thorns.")
        return
    end

    if questId == Q.RFK_CAPTIVE then
        C.SendMessage(player, "Speak with the Quilboar Captive. Sacred traditions can protect a people, but they can also be used to control them.")
        return
    end

    if questId == Q.RFK_GROUP then
        C.SendMessage(player, "Gather your party at Razorfen Kraul. The Frostforge Guide will send you into the maze of thorn, faith, and fear.")
        C.TeleportToLocation(player, L.RFK_STAGING)
        return
    end

    if questId == Q.RFK_DUNGEON then
        C.SendMessage(player, "Enter Razorfen Kraul and defeat Charlga Razorflank. End her hold over the Kraul.")
        return
    end
end

local function OnRFKQuestReward(event, player, quest, opt)
    local questId = C.GetQuestId(quest)

    if questId == Q.RFK_DUNGEON then
        C.HandleDungeonReward(
            player,
            LVL.RFK_REWARD,
            "GiveRFKClassReward",
            "Razorfen Kraul",
            "Charlga Razorflank is defeated. The Kraul remains, and so does the old pain beneath it. Not every wound in Azeroth can be solved by killing its ruler."
        )
        return
    end
end

local function OnBarrensMessengerGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.RFK_THORNS,
        NPC.RFK_BARRENS_MESSENGER,
        "The Barrens Messenger says: The quilboar strike from the thorns because they believe the land is theirs by blood and sacrifice. To the caravans, they are raiders. To themselves, they are defending what remains.",
        "What have the roads seen?"
    )
end

local function OnQuilboarCaptiveGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.RFK_CAPTIVE,
        NPC.RFK_QUILBOAR_CAPTIVE,
        "The Quilboar Captive says: Agamaggan's thorns were once a memory of sacrifice. Charlga has made them chains. She wraps fear in ritual and calls it survival.",
        "What does Charlga control?"
    )
end

RegisterPlayerEvent(31, OnRFKQuestAccept)
RegisterPlayerEvent(54, OnRFKQuestReward)

RegisterCreatureGossipEvent(NPC.RFK_BARRENS_MESSENGER, 1, OnBarrensMessengerGossipHello)
RegisterCreatureGossipEvent(NPC.RFK_BARRENS_MESSENGER, 2, C.CompleteGossip)

RegisterCreatureGossipEvent(NPC.RFK_QUILBOAR_CAPTIVE, 1, OnQuilboarCaptiveGossipHello)
RegisterCreatureGossipEvent(NPC.RFK_QUILBOAR_CAPTIVE, 2, C.CompleteGossip)

print("[Frostforge] Act VII Razorfen Kraul loaded.")
