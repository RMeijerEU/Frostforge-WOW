-- Frostforge Act VIII-XI — Scarlet Monastery

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local LVL = Frostforge.Level
local C = Frostforge.Campaign

local function OnSMQuestAccept(event, player, quest)
    local questId = C.GetQuestId(quest)

    if questId == Q.SM_INTRO then
        C.SendMessage(player, "The Scarlet Monastery stands in the shadow of Lordaeron's fall. Before we enter, listen to both the Crusade's wound and the Forsaken memory of what remains.")
        C.TeleportToLocation(player, L.SM_STAGING)
        return
    end

    if questId == Q.SM_GRAVEYARD then
        C.SendMessage(player, "Begin in the Graveyard. The Crusade hates undeath, yet death fills its own halls.")
        return
    end

    if questId == Q.SM_LIBRARY then
        C.SendMessage(player, "Enter the Library. This is where grief becomes doctrine.")
        return
    end

    if questId == Q.SM_ARMORY then
        C.SendMessage(player, "Enter the Armory. This is where doctrine becomes violence.")
        return
    end

    if questId == Q.SM_CATHEDRAL then
        C.SendMessage(player, "Enter the Cathedral. At the heart of the Monastery, certainty has replaced mercy.")
        return
    end
end

local function OnSMQuestReward(event, player, quest, opt)
    local questId = C.GetQuestId(quest)

    if questId == Q.SM_GRAVEYARD then
        C.HandleDungeonReward(
            player,
            LVL.SM_GY_REWARD,
            "GiveSMGraveyardClassReward",
            "Scarlet Monastery: Graveyard",
            "Bloodmage Thalnos is defeated. Hatred of corruption does not protect anyone from becoming corrupted."
        )
        return
    end

    if questId == Q.SM_LIBRARY then
        C.HandleDungeonReward(
            player,
            LVL.SM_LIB_REWARD,
            "GiveSMLibraryClassReward",
            "Scarlet Monastery: Library",
            "Arcanist Doan is defeated. The words of zeal are quieter now, but their damage remains."
        )
        return
    end

    if questId == Q.SM_ARMORY then
        C.HandleDungeonReward(
            player,
            LVL.SM_ARMORY_REWARD,
            "GiveSMArmoryClassReward",
            "Scarlet Monastery: Armory",
            "Herod has fallen. The Crusade has lost one of its sharpened blades."
        )
        return
    end

    if questId == Q.SM_CATHEDRAL then
        C.HandleDungeonReward(
            player,
            LVL.SM_CATHEDRAL_REWARD,
            "GiveSMCathedralClassReward",
            "Scarlet Monastery: Cathedral",
            "Whitemane is defeated. Grief deserves compassion, but when grief becomes doctrine, it becomes dangerous."
        )
        return
    end
end

local function OnScarletDefectorGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.SM_INTRO,
        NPC.SM_SCARLET_DEFECTOR,
        "The Scarlet Defector says: I joined to avenge Lordaeron. I believed we were saving the living. But inside the Monastery, grief became doctrine, and soon everyone outside the Crusade was suspect.",
        "Why did you leave the Crusade?"
    )
end

local function OnForsakenObserverGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.SM_INTRO,
        NPC.SM_FORSAKEN_OBSERVER,
        "The Forsaken Observer says: They claim to fight for Lordaeron, but Lordaeron is dead, broken, and changed. They cannot accept what remains. To them, every Forsaken is a monster, and every living ally is a traitor.",
        "What does the Monastery mean to the Forsaken?"
    )
end

RegisterPlayerEvent(31, OnSMQuestAccept)
RegisterPlayerEvent(54, OnSMQuestReward)

RegisterCreatureGossipEvent(NPC.SM_SCARLET_DEFECTOR, 1, OnScarletDefectorGossipHello)
RegisterCreatureGossipEvent(NPC.SM_SCARLET_DEFECTOR, 2, C.CompleteGossip)

RegisterCreatureGossipEvent(NPC.SM_FORSAKEN_OBSERVER, 1, OnForsakenObserverGossipHello)
RegisterCreatureGossipEvent(NPC.SM_FORSAKEN_OBSERVER, 2, C.CompleteGossip)

print("[Frostforge] Act VIII-XI Scarlet Monastery loaded.")
