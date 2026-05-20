-- Frostforge Act VI — Gnomeregan

local NPC = Frostforge.NPC
local Q = Frostforge.Quest
local L = Frostforge.Location
local LVL = Frostforge.Level
local C = Frostforge.Campaign

local function OnGnomerQuestAccept(event, player, quest)
    local questId = C.GetQuestIdSafe(quest)

    if questId == Q.GNOMER_TRAVEL then
        C.SendEldrinMessage(player, "Gnomeregan was not merely a city. It was proof of what gnomish genius could build. Now it is proof of what panic, betrayal, and poisoned machines can destroy. Travel to the fallen city and hear what remains.")
        C.TeleportToLocation(player, L.GNOMEREGAN_STAGING)
        return
    end

    if questId == Q.GNOMER_SURVIVOR then
        C.SendEldrinMessage(player, "Speak with the Gnome Survivor near Gnomeregan. Machines can be rebuilt. A lost home is harder to repair.")
        return
    end

    if questId == Q.GNOMER_BETRAYAL then
        C.SendEldrinMessage(player, "Speak with the Irradiated Technician. Thermaplugg did not simply fail his people. He used disaster as a ladder.")
        return
    end

    if questId == Q.GNOMER_GROUP then
        C.SendEldrinMessage(player, "Gather your party at Gnomeregan. Below us wait troggs, leper gnomes, malfunctioning machines, radiation, and the traitor who profited from it all.")
        C.TeleportToLocation(player, L.GNOMEREGAN_STAGING)
        return
    end

    if questId == Q.GNOMER_DUNGEON then
        C.SendEldrinMessage(player, "Enter Gnomeregan and defeat Mekgineer Thermaplugg. He cannot return the city to its people, but he can answer for what he did to it.")
        return
    end
end

local function OnGnomerQuestReward(event, player, quest, opt)
    local questId = C.GetQuestIdSafe(quest)

    if questId == Q.GNOMER_DUNGEON then
        C.HandleDungeonReward(
            player,
            LVL.GNOMER_REWARD,
            "GiveGnomerClassReward",
            "Gnomeregan",
            "Thermaplugg has fallen. Gnomeregan is not restored, but justice has entered its halls. The exiles still have a city to reclaim."
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
        "The Gnome Survivor says: We built Gnomeregan to be a miracle beneath the mountains. Then the troggs came, the alarms screamed, and the air itself turned against us. Some fled with tools in their hands. Some carried children. Some never reached the lifts. Exile is not just losing stone and steel. It is waking every day knowing your home still exists, poisoned and occupied, below your feet.",
        "What was lost when Gnomeregan fell?"
    )
end

local function OnIrradiatedTechnicianGossipHello(event, player, creature)
    C.SimpleObjectiveGossipHello(
        player,
        creature,
        Q.GNOMER_BETRAYAL,
        NPC.GNOMER_IRRADIATED_TECHNICIAN,
        "The Irradiated Technician says: Thermaplugg promised control. He said the radiation would stop the troggs. He said the machines would save us. But he understood the panic better than anyone. While Gelbin tried to save the city, Thermaplugg turned failure into a throne. The poison did not only twist bodies. It revealed ambition.",
        "Tell me about Thermaplugg's betrayal."
    )
end

RegisterPlayerEvent(31, OnGnomerQuestAccept)
RegisterPlayerEvent(54, OnGnomerQuestReward)

RegisterCreatureGossipEvent(NPC.GNOMER_GNOME_SURVIVOR, 1, OnGnomeSurvivorGossipHello)
RegisterCreatureGossipEvent(NPC.GNOMER_GNOME_SURVIVOR, 2, C.CompleteGossip)

RegisterCreatureGossipEvent(NPC.GNOMER_IRRADIATED_TECHNICIAN, 1, OnIrradiatedTechnicianGossipHello)
RegisterCreatureGossipEvent(NPC.GNOMER_IRRADIATED_TECHNICIAN, 2, C.CompleteGossip)

print("[Frostforge] Act VI Gnomeregan loaded.")
