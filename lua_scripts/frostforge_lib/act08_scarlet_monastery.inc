-- Frostforge Act VIII-XI — Scarlet Monastery

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local LVL = Frostforge.Level
local C = Frostforge.Campaign

local function OnSMQuestAccept(event, player, quest)
    local questId = C.GetQuestIdSafe(quest)

    if questId == Q.SM_RED_STANDARD then
        C.SendEldrinMessage(player, "The Scarlet Crusade marches beneath a red standard, but the banner no longer means protection. Begin in Hillsbrad and learn who they now call enemy.")
        return
    end

    if questId == Q.SM_FAITH_WITHOUT_MERCY then
        C.SendEldrinMessage(player, "The Crusade was born from fear of undeath. Now fear has become doctrine. Speak with those caught between Southshore, Tarren Mill, and the Scarlet patrols.")
        return
    end

    if questId == Q.SM_ROAD then
        C.SendEldrinMessage(player, "The road now leads to Scarlet Monastery. Hear the Scarlet Defector and the Forsaken Observer before entering those halls.")
        C.TeleportToLocation(player, L.SM_STAGING)
        return
    end

    if questId == Q.SM_GRAVEYARD then
        C.SendEldrinMessage(player, "Enter Scarlet Monastery Graveyard and defeat Bloodmage Thalnos. The Crusade claims purity, yet corruption has entered its own dead.")
        return
    end

    if questId == Q.SM_LIBRARY then
        C.SendEldrinMessage(player, "Enter Scarlet Monastery Library and defeat Arcanist Doan. In those halls, grief has been written into doctrine.")
        return
    end

    if questId == Q.SM_ARCHIVES then
        C.SendEldrinMessage(player, "The Library has fallen silent. Search what remains and understand how fear becomes law.")
        return
    end

    if questId == Q.SM_MONASTERY_MUST_FALL then
        C.SendEldrinMessage(player, "The Monastery's heart still beats. Herod sharpens its soldiers. Mograine and Whitemane sanctify its certainty. Prepare for the final assault.")
        return
    end

    if questId == Q.SM_ARMORY then
        C.SendEldrinMessage(player, "Enter Scarlet Monastery Armory and defeat Herod. Doctrine becomes violence in the hands of soldiers who no longer question.")
        return
    end

    if questId == Q.SM_CATHEDRAL then
        C.SendEldrinMessage(player, "Enter Scarlet Monastery Cathedral and defeat Scarlet Commander Mograine and High Inquisitor Whitemane. End the Crusade's certainty at its altar.")
        return
    end
end

local function OnSMQuestReward(event, player, quest, opt)
    local questId = C.GetQuestIdSafe(quest)

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
            "Mograine and Whitemane are defeated. Grief deserves compassion, but when grief becomes doctrine, it becomes dangerous."
        )
        return
    end
end

local function OnSouthshoreScoutGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.SM_RED_STANDARD,
        NPC.SM_SOUTHSHORE_SCOUT,
        "The Southshore Scout says: The Scarlet patrols used to pass as allies. Now they question everyone, threaten refugees, and call mercy a weakness. They say they defend Lordaeron, but they no longer know who Lordaeron's people are.",
        "What have the Scarlet patrols done here?"
    )
end

local function OnTarrenMillApothecaryGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.SM_RED_STANDARD,
        NPC.SM_TARREN_MILL_APOTHECARY,
        "The Tarren Mill Apothecary says: To the Crusade, undeath is not a condition. It is a verdict. Forsaken, sympathizer, neutral traveler — it makes no difference once their zealots decide you are contaminated.",
        "How does the Crusade see the Forsaken?"
    )
end

local function OnHillsbradRefugeeGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.SM_FAITH_WITHOUT_MERCY,
        NPC.SM_HILLSBRAD_REFUGEE,
        "The Hillsbrad Refugee says: I was not Scourge. I was not Forsaken. I was just afraid. But fear is not enough for the Scarlet Crusade. If you hesitate, question, or shelter the wrong person, they mark you as stained.",
        "Why did the Crusade turn on you?"
    )
end

local function OnScarletDefectorGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.SM_ROAD,
        NPC.SM_SCARLET_DEFECTOR,
        "The Scarlet Defector says: I joined to avenge Lordaeron. I believed we were saving the living. But inside the Monastery, grief became doctrine, and soon everyone outside the Crusade was suspect.",
        "Why did you leave the Crusade?"
    )
end

local function OnForsakenObserverGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.SM_ROAD,
        NPC.SM_FORSAKEN_OBSERVER,
        "The Forsaken Observer says: They claim to fight for Lordaeron, but Lordaeron is dead, broken, and changed. They cannot accept what remains. To them, every Forsaken is a monster, and every living ally is a traitor.",
        "What does the Monastery mean to the Forsaken?"
    )
end

RegisterPlayerEvent(31, OnSMQuestAccept)
RegisterPlayerEvent(54, OnSMQuestReward)

RegisterCreatureGossipEvent(NPC.SM_SOUTHSHORE_SCOUT, 1, OnSouthshoreScoutGossipHello)
RegisterCreatureGossipEvent(NPC.SM_SOUTHSHORE_SCOUT, 2, C.CompleteGossip)

RegisterCreatureGossipEvent(NPC.SM_TARREN_MILL_APOTHECARY, 1, OnTarrenMillApothecaryGossipHello)
RegisterCreatureGossipEvent(NPC.SM_TARREN_MILL_APOTHECARY, 2, C.CompleteGossip)

RegisterCreatureGossipEvent(NPC.SM_HILLSBRAD_REFUGEE, 1, OnHillsbradRefugeeGossipHello)
RegisterCreatureGossipEvent(NPC.SM_HILLSBRAD_REFUGEE, 2, C.CompleteGossip)

RegisterCreatureGossipEvent(NPC.SM_SCARLET_DEFECTOR, 1, OnScarletDefectorGossipHello)
RegisterCreatureGossipEvent(NPC.SM_SCARLET_DEFECTOR, 2, C.CompleteGossip)

RegisterCreatureGossipEvent(NPC.SM_FORSAKEN_OBSERVER, 1, OnForsakenObserverGossipHello)
RegisterCreatureGossipEvent(NPC.SM_FORSAKEN_OBSERVER, 2, C.CompleteGossip)

print("[Frostforge] Act VIII-XI Scarlet Monastery loaded.")
