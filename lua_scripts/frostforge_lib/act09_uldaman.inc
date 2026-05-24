-- Frostforge Act XII — Uldaman

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local LVL = Frostforge.Level
local C = Frostforge.Campaign

local function OnUldamanQuestAccept(event, player, quest)
    local questId = C.GetQuestId(quest)

    if questId == Q.ULDAMAN_TITAN_ECHOES then
        C.SendEldrinMessage(player, "The Scarlet Monastery showed what fear can do to the living. Uldaman is older than fear, older than kingdoms, and older than the wars of Horde and Alliance. The next path leads into Titan history.")
        return
    end

    if questId == Q.ULDAMAN_DWARVEN_ORIGINS then
        C.SendEldrinMessage(player, "The dwarves search Uldaman for the truth of their beginning. What they find there may change how Azeroth understands itself.")
        return
    end

    if questId == Q.ULDAMAN_TROGG_WARNING then
        C.SendEldrinMessage(player, "The troggs are not simply cave beasts. They are a warning from an older age: creation without balance, stone without wisdom, life twisted before it ever had a name.")
        return
    end

    if questId == Q.ULDAMAN_GROUP then
        C.SendEldrinMessage(player, "Travel to the Badlands and prepare for Uldaman. The vault is guarded by stone, memory, and the failed children of forgotten experiments.")
        C.TeleportToLocation(player, L.ULDAMAN_STAGING)
        return
    end

    if questId == Q.ULDAMAN_DUNGEON then
        C.SendEldrinMessage(player, "Enter Uldaman and defeat Archaedas. The Titans did not build vaults to be understood by the careless.")
        return
    end
end

local function OnUldamanQuestReward(event, player, quest, opt)
    local questId = C.GetQuestId(quest)

    if questId == Q.ULDAMAN_DUNGEON then
        C.HandleDungeonReward(
            player,
            LVL.ULDAMAN_REWARD,
            "GiveUldamanClassReward",
            "Uldaman",
            "Archaedas is defeated. Beneath the stone, Azeroth's history has become larger, older, and far more dangerous than mortal wars alone."
        )
        return
    end
end

local function OnReliquaryExplorerGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.ULDAMAN_DWARVEN_ORIGINS,
        NPC.ULDAMAN_RELIQUARY_EXPLORER,
        "The Reliquary Explorer says: The deeper we dig, the less this looks like a dwarven ruin. Uldaman is Titan work. The earthen came before the dwarves, shaped from stone and purpose. Somewhere between then and now, flesh entered the story.",
        "What did the dwarves find here?"
    )
end

local function OnStonewatcherGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.ULDAMAN_TROGG_WARNING,
        NPC.ULDAMAN_STONEWATCHER,
        "The Stonewatcher says: The troggs are not an accident to ignore. They are a broken echo of creation. If the Titans shaped this world, then Uldaman proves even their works could fracture.",
        "What do the troggs mean?"
    )
end

RegisterPlayerEvent(31, OnUldamanQuestAccept)
RegisterPlayerEvent(54, OnUldamanQuestReward)

RegisterCreatureGossipEvent(NPC.ULDAMAN_RELIQUARY_EXPLORER, 1, OnReliquaryExplorerGossipHello)
RegisterCreatureGossipEvent(NPC.ULDAMAN_RELIQUARY_EXPLORER, 2, C.CompleteGossip)

RegisterCreatureGossipEvent(NPC.ULDAMAN_STONEWATCHER, 1, OnStonewatcherGossipHello)
RegisterCreatureGossipEvent(NPC.ULDAMAN_STONEWATCHER, 2, C.CompleteGossip)

print("[Frostforge] Act XII Uldaman loaded.")