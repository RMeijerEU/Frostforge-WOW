-- Frostforge Act VI — Gnomeregan

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local LVL = Frostforge.Level
local C = Frostforge.Campaign

local function OnGnomerQuestAccept(event, player, quest)
    local questId = C.GetQuestId(quest)

    if questId == Q.GNOMER_TRAVEL then
        C.SendMessage(player, "Gnomeregan was once a marvel. Now it is a warning. Travel to the fallen city and learn how invention became catastrophe.")
        C.TeleportToLocation(player, L.GNOMEREGAN_STAGING)
        return
    end

    if questId == Q.GNOMER_SURVIVOR then
        C.SendMessage(player, "Speak with the Gnome Survivor. Disasters are measured in people, not machines.")
        return
    end

    if questId == Q.GNOMER_BETRAYAL then
        C.SendMessage(player, "Speak with the Irradiated Technician. Thermaplugg's betrayal is still remembered by those who escaped.")
        return
    end

    if questId == Q.GNOMER_GROUP then
        C.SendMessage(player, "Gather your party at Gnomeregan. The Frostforge Guide will send you into the poisoned city.")
        C.TeleportToLocation(player, L.GNOMEREGAN_STAGING)
        return
    end

    if questId == Q.GNOMER_DUNGEON then
        C.SendMessage(player, "Enter Gnomeregan and defeat Mekgineer Thermaplugg. Bring down the traitor beneath the city.")
        return
    end
end

local function OnGnomerQuestReward(event, player, quest, opt)
    local questId = C.GetQuestId(quest)

    if questId == Q.GNOMER_DUNGEON then
        C.HandleDungeonReward(
            player,
            LVL.GNOMER_REWARD,
            "GiveGnomerClassReward",
            "Gnomeregan",
            "Thermaplugg has fallen. Gnomeregan is not restored, but justice has entered its halls."
        )
        return
    end
end

local function OnGnomeSurvivorGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.GNOMER_SURVIVOR,
        NPC.GNOMER_GNOME_SURVIVOR,
        "The Gnome Survivor speaks of evacuation, radiation, and the loss of a city that was meant to be a miracle.",
        "Tell me what happened to Gnomeregan."
    )
end

local function OnIrradiatedTechnicianGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.GNOMER_BETRAYAL,
        NPC.GNOMER_IRRADIATED_TECHNICIAN,
        "The Irradiated Technician remembers Thermaplugg's betrayal and the disaster he used to seize power.",
        "Tell me about Thermaplugg."
    )
end

RegisterPlayerEvent(31, OnGnomerQuestAccept)
RegisterPlayerEvent(54, OnGnomerQuestReward)

RegisterCreatureGossipEvent(NPC.GNOMER_GNOME_SURVIVOR, 1, OnGnomeSurvivorGossipHello)
RegisterCreatureGossipEvent(NPC.GNOMER_GNOME_SURVIVOR, 2, C.CompleteGossip)

RegisterCreatureGossipEvent(NPC.GNOMER_IRRADIATED_TECHNICIAN, 1, OnIrradiatedTechnicianGossipHello)
RegisterCreatureGossipEvent(NPC.GNOMER_IRRADIATED_TECHNICIAN, 2, C.CompleteGossip)

print("[Frostforge] Act VI Gnomeregan loaded.")
