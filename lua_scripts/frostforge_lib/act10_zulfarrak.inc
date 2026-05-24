-- Frostforge Act XIII — Zul'Farrak

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local LVL = Frostforge.Level
local C = Frostforge.Campaign

local function SayToPlayer(creature, player, text)
    if creature and creature.SendUnitSay then
        creature:SendUnitSay(text, 0)
        return
    end

    if creature and creature.SendUnitWhisper and player then
        creature:SendUnitWhisper(text, player)
        return
    end

    if player then
        player:SendBroadcastMessage(text)
    end
end

local function GiveObjectiveCredit(player, questId, creditNpc)
    if not player then
        return
    end

    if player:HasQuest(questId) and not player:CanCompleteQuest(questId) then
        player:KilledMonsterCredit(creditNpc)

        -- Fallback for event-style objective behavior.
        if not player:CanCompleteQuest(questId) then
            player:AreaExploredOrEventHappens(questId)
        end
    end
end

local function OnZulFarrakQuestAccept(event, player, quest)
    local questId = C.GetQuestId(quest)

    if questId == Q.ZF_SANDS_OF_TANARIS then
        C.SendEldrinMessage(player, "Tanaris is not empty. Beneath the heat and dust lie old roads, old wars, and the ruins of powers older than the kingdoms now fighting over Azeroth.")
        C.TeleportToLocation(player, L.ZF_GADGETZAN)
        return
    end

    if questId == Q.ZF_SANDFURY_EMPIRE then
        C.SendEldrinMessage(player, "The Sandfury are not merely raiders. They are the broken edge of an ancient troll legacy, proud enough to endure and violent enough to make the desert bleed.")
        C.TeleportToLocation(player, L.ZF_STAGING)
        return
    end

    if questId == Q.ZF_RELICS_IN_THE_SAND then
        C.SendEldrinMessage(player, "Troll empires left more than ruins behind. Their relics remember rites, grudges, old gods, and names that should not be spoken lightly.")
        return
    end

    if questId == Q.ZF_GROUP then
        C.SendEldrinMessage(player, "Gather your party at the gates of Zul'Farrak. When your group is ready, speak with the Frostforge Guide near the entrance.")
        return
    end

    if questId == Q.ZF_DUNGEON then
        C.SendEldrinMessage(player, "Enter Zul'Farrak and defeat Chief Ukorz Sandscalp. The Sandfury hold the desert through blood, memory, and fear. Break their hold.")
        return
    end
end

local function OnZulFarrakQuestReward(event, player, quest, opt)
    local questId = C.GetQuestId(quest)

    if questId == Q.ZF_DUNGEON then
        C.HandleDungeonReward(
            player,
            LVL.ZF_REWARD,
            "GiveZFClassReward",
            "Zul'Farrak",
            "Chief Ukorz Sandscalp is defeated. The Sandfury threat is broken, but the campaign has now touched something older: the long shadow of the troll empires."
        )
        return
    end
end

local function OnTanarisChroniclerGossipHello(event, player, creature)
    SayToPlayer(
        creature,
        player,
        "Tanaris looks empty to strangers, but the desert remembers. Caravan tracks, buried bones, troll stones, goblin greed — all of it points toward Zul'Farrak."
    )

    GiveObjectiveCredit(
        player,
        Q.ZF_SANDS_OF_TANARIS,
        NPC.ZF_TANARIS_CHRONICLER
    )

    player:GossipComplete()
end

local function OnSandfuryExileGossipHello(event, player, creature)
    SayToPlayer(
        creature,
        player,
        "You call them Sandfury as if that explains them. They are children of old troll pride, trapped in dust and anger. Zul'Farrak is not a camp. It is a wound that built walls."
    )

    GiveObjectiveCredit(
        player,
        Q.ZF_SANDFURY_EMPIRE,
        NPC.ZF_SANDFURY_EXILE
    )

    player:GossipComplete()
end

local function OnRelicSeekerGossipHello(event, player, creature)
    SayToPlayer(
        creature,
        player,
        "These relics are not decoration. Troll empires carved belief into stone, blood into ritual, and memory into places like Zul'Farrak. Step inside carelessly and the past will answer."
    )

    GiveObjectiveCredit(
        player,
        Q.ZF_RELICS_IN_THE_SAND,
        NPC.ZF_RELIC_SEEKER
    )

    player:GossipComplete()
end

RegisterPlayerEvent(31, OnZulFarrakQuestAccept)
RegisterPlayerEvent(54, OnZulFarrakQuestReward)

RegisterCreatureGossipEvent(NPC.ZF_TANARIS_CHRONICLER, 1, OnTanarisChroniclerGossipHello)
RegisterCreatureGossipEvent(NPC.ZF_SANDFURY_EXILE, 1, OnSandfuryExileGossipHello)
RegisterCreatureGossipEvent(NPC.ZF_RELIC_SEEKER, 1, OnRelicSeekerGossipHello)

print("[Frostforge] Act XIII Zul'Farrak loaded.")