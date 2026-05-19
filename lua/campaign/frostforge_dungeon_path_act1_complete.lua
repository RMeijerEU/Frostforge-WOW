-- Frostforge Dungeon Path
-- Guide NPC:      900010 Frostforge Guide
-- Pathfinder NPC: 900011 Frostforge Pathfinder
--
-- Lua handles:
-- - Frostforge Guide gossip / quest flow
-- - starter gear
-- - class spells
-- - quest reward handling
-- - campaign veil
-- - Orgrimmar investigation NPCs
-- - teleport group to RFC entrance / inside RFC
--
-- C++ handles:
-- - Frostforge Pathfinder one-click bot group maker

local NPC_FROSTFORGE_GUIDE = 900010
local NPC_FROSTFORGE_PATHFINDER = 900011

local NPC_ORG_GRUNT = 900020
local NPC_ORG_SHAMAN = 900021
local NPC_ORG_GUARD = 900022

local QUEST_WELCOME = 900100
local QUEST_STARTER_GEAR = 900101
local QUEST_ORGRIMMAR = 900102
local QUEST_GROUP = 900103
local QUEST_RFC = 900104

local TARGET_LEVEL_RFC = 15

-- Maps
local MAP_KALIMDOR = 1
local MAP_RFC = 389

-- Orgrimmar entrance / chapter start
local ORG_X = 1497.5602
local ORG_Y = -4415.688
local ORG_Z = 22.751932
local ORG_O = 0.21601878

-- Ragefire Chasm entrance, outside the instance portal
local RFC_X = 1811.78
local RFC_Y = -4410.50
local RFC_Z = -18.47
local RFC_O = 5.20

-- Inside Ragefire Chasm, near entrance
local RFC_INSIDE_X = 5.835333
local RFC_INSIDE_Y = -25.63047
local RFC_INSIDE_Z = -20.681316
local RFC_INSIDE_O = 1.944269

-- Frostforge Guide location in Valley of Trials
local GUIDE_MAP = 1
local GUIDE_X = -610.5018
local GUIDE_Y = -4250.8335
local GUIDE_Z = 38.955524
local GUIDE_O = 3.213063

-- Class IDs
local CLASS_WARRIOR = 1
local CLASS_PALADIN = 2
local CLASS_HUNTER = 3
local CLASS_ROGUE = 4
local CLASS_PRIEST = 5
local CLASS_SHAMAN = 7
local CLASS_MAGE = 8
local CLASS_WARLOCK = 9
local CLASS_DRUID = 11

-- Team IDs
local TEAM_HORDE = 1

-- Campaign factions
local FROSTFORGE_FACTION_NEUTRAL = 35
local FROSTFORGE_FACTION_ORGRIMMAR_WITNESS = 29

-- Skill IDs
local SKILL_SWORDS = 43
local SKILL_AXES = 44
local SKILL_BOWS = 45
local SKILL_GUNS = 46
local SKILL_MACES = 54
local SKILL_TWO_HANDED_SWORDS = 55
local SKILL_DEFENSE = 95
local SKILL_STAVES = 136
local SKILL_TWO_HANDED_MACES = 160
local SKILL_TWO_HANDED_AXES = 172
local SKILL_DAGGERS = 173
local SKILL_WANDS = 228
local SKILL_SHIELDS = 433

-- Basic supplies
local ITEM_SMALL_BROWN_POUCH = 4496
local ITEM_MINOR_HEALING_POTION = 118

-- Starter weapons
local ITEM_2H_AXE_HORDE_WARRIOR = 3488       -- Copper Battle Axe
local ITEM_2H_SWORD_ALLIANCE_WARRIOR = 3188 -- Coral Claymore
local ITEM_2H_SWORD = 3188
local ITEM_BOW = 3036
local ITEM_1H_SWORD = 4765
local ITEM_DAGGER = 1287
local ITEM_STAFF = 1933
local ITEM_WAND = 5071
local ITEM_1H_MACE = 4569
local ITEM_SHIELD = 3653

-- Cloth starter gear
local CLOTH_CHEST = 9749
local CLOTH_BELT = 14113
local CLOTH_LEGS = 10047
local CLOTH_BOOTS = 6537
local CLOTH_BRACERS = 6543
local CLOTH_GLOVES = 4768
local CLOTH_CLOAK = 14365

-- Leather starter gear
local LEATHER_CHEST = 22987
local LEATHER_BELT = 6558
local LEATHER_LEGS = 4242
local LEATHER_BOOTS = 2309
local LEATHER_BRACERS = 6556
local LEATHER_GLOVES = 3314
local LEATHER_CLOAK = 15309

-- Mail starter gear
local MAIL_CHEST = 9765  -- Cadet Vest
local MAIL_BELT = 832
local MAIL_LEGS = 2978
local MAIL_BOOTS = 3302
local MAIL_BRACERS = 15495
local MAIL_GLOVES = 15491
local MAIL_CLOAK = 1355  -- Buckskin Cape

-- RFC completion rewards
local RFC_CURSED_FELBLADE = 14145
local RFC_SUBTERRANEAN_CAPE = 14149
local RFC_CAVEDWELLER_BRACERS = 14147
local RFC_CHANTING_BLADE = 14151
local RFC_ROBE_OF_EVOCATION = 14150

-- Level 10 class abilities
local WARRIOR_LEVEL10_SPELLS = {
    2457, 71, 78, 284, 100, 772, 6546, 6343, 1715, 2687, 7386, 355, 6673
}

local PALADIN_LEVEL10_SPELLS = {
    635, 21084, 465, 19740, 20271
}

local HUNTER_LEVEL10_SPELLS = {
    75, 2973, 1978, 3044, 1130, 13163, 5116, 883, 982, 6991
}

local ROGUE_LEVEL10_SPELLS = {
    1752, 2098, 1784, 921, 1776, 5277
}

local PRIEST_LEVEL10_SPELLS = {
    585, 2050, 2052, 1243, 589, 139, 17, 586
}

local SHAMAN_LEVEL10_SPELLS = {
    403, 529, 331, 332, 8042, 8017, 8018, 2484, 8075
}

local MAGE_LEVEL10_SPELLS = {
    133, 143, 168, 116, 205, 1459, 5504, 587, 2136, 118
}

local WARLOCK_LEVEL10_SPELLS = {
    686, 695, 687, 348, 172, 702, 1454, 688, 6201, 1120, 5782
}

local DRUID_LEVEL10_SPELLS = {
    5176, 5177, 5185, 5186, 8921, 8924, 774, 1126, 467, 339, 5487, 99, 6807
}

local STARTER_GEAR = {
    [CLASS_WARRIOR] = {
        common = {
            {MAIL_CHEST}, {MAIL_BELT}, {MAIL_LEGS}, {MAIL_BOOTS}, {MAIL_BRACERS}, {MAIL_GLOVES}, {MAIL_CLOAK}
        }
    },

    [CLASS_PALADIN] = {
        common = {
            {ITEM_2H_SWORD},
            {MAIL_CHEST}, {MAIL_BELT}, {MAIL_LEGS}, {MAIL_BOOTS}, {MAIL_BRACERS}, {MAIL_GLOVES}, {MAIL_CLOAK}
        }
    },

    [CLASS_HUNTER] = {
        common = {
            {ITEM_BOW}, {ITEM_1H_SWORD},
            {LEATHER_CHEST}, {LEATHER_BELT}, {LEATHER_LEGS}, {LEATHER_BOOTS}, {LEATHER_BRACERS}, {LEATHER_GLOVES}, {LEATHER_CLOAK}
        }
    },

    [CLASS_ROGUE] = {
        common = {
            {ITEM_1H_SWORD}, {ITEM_DAGGER},
            {LEATHER_CHEST}, {LEATHER_BELT}, {LEATHER_LEGS}, {LEATHER_BOOTS}, {LEATHER_BRACERS}, {LEATHER_GLOVES}, {LEATHER_CLOAK}
        }
    },

    [CLASS_PRIEST] = {
        common = {
            {ITEM_STAFF}, {ITEM_WAND},
            {CLOTH_CHEST}, {CLOTH_BELT}, {CLOTH_LEGS}, {CLOTH_BOOTS}, {CLOTH_BRACERS}, {CLOTH_GLOVES}, {CLOTH_CLOAK}
        }
    },

    [CLASS_SHAMAN] = {
        common = {
            {ITEM_1H_MACE}, {ITEM_SHIELD},
            {LEATHER_CHEST}, {LEATHER_BELT}, {LEATHER_LEGS}, {LEATHER_BOOTS}, {LEATHER_BRACERS}, {LEATHER_GLOVES}, {LEATHER_CLOAK}
        }
    },

    [CLASS_MAGE] = {
        common = {
            {ITEM_STAFF}, {ITEM_WAND},
            {CLOTH_CHEST}, {CLOTH_BELT}, {CLOTH_LEGS}, {CLOTH_BOOTS}, {CLOTH_BRACERS}, {CLOTH_GLOVES}, {CLOTH_CLOAK}
        }
    },

    [CLASS_WARLOCK] = {
        common = {
            {ITEM_STAFF}, {ITEM_WAND},
            {CLOTH_CHEST}, {CLOTH_BELT}, {CLOTH_LEGS}, {CLOTH_BOOTS}, {CLOTH_BRACERS}, {CLOTH_GLOVES}, {CLOTH_CLOAK}
        }
    },

    [CLASS_DRUID] = {
        common = {
            {ITEM_STAFF},
            {LEATHER_CHEST}, {LEATHER_BELT}, {LEATHER_LEGS}, {LEATHER_BOOTS}, {LEATHER_BRACERS}, {LEATHER_GLOVES}, {LEATHER_CLOAK}
        }
    }
}

local RFC_CLASS_REWARDS = {
    [CLASS_WARRIOR] = {
        {RFC_CURSED_FELBLADE}
    },

    [CLASS_PALADIN] = {
        {RFC_CURSED_FELBLADE}
    },

    [CLASS_HUNTER] = {
        {RFC_SUBTERRANEAN_CAPE}
    },

    [CLASS_ROGUE] = {
        {RFC_CURSED_FELBLADE}
    },

    [CLASS_PRIEST] = {
        {RFC_ROBE_OF_EVOCATION}
    },

    [CLASS_SHAMAN] = {
        {RFC_CHANTING_BLADE}
    },

    [CLASS_MAGE] = {
        {RFC_CHANTING_BLADE}
    },

    [CLASS_WARLOCK] = {
        {RFC_ROBE_OF_EVOCATION}
    },

    [CLASS_DRUID] = {
        {RFC_CAVEDWELLER_BRACERS}
    }
}

local function GiveItems(player, items)
    for _, item in ipairs(items) do
        player:AddItem(item[1], item[2] or 1)
    end
end

local function LearnSpells(player, spells)
    local learned = 0

    for _, spellId in ipairs(spells) do
        if not player:HasSpell(spellId) then
            player:LearnSpell(spellId)
            learned = learned + 1
        end
    end

    return learned
end

local function SetSkillSafe(player, skillId, value, maxValue)
    player:SetSkill(skillId, 0, value, maxValue)
end

local function ApplyCampaignVeil(player, factionId)
    factionId = factionId or FROSTFORGE_FACTION_NEUTRAL

    player:SetFaction(factionId)

    if player.SetPvP then
        player:SetPvP(false)
    end

    if player.CombatStop then
        player:CombatStop()
    end

    if player.ClearInCombat then
        player:ClearInCombat()
    end

    player:SendBroadcastMessage("|cff66ccffFrostforge:|r The Campaign Veil surrounds you. You may walk this chapter as a witness, not an invader.")
end

local function ApplyOrgrimmarCampaignVeil(player)
    ApplyCampaignVeil(player, FROSTFORGE_FACTION_ORGRIMMAR_WITNESS)
end

local function RemoveCampaignVeil(player)
    if player.CombatStop then
        player:CombatStop()
    end

    if player.ClearInCombat then
        player:ClearInCombat()
    end

    player:SetFactionForRace(player:GetRace())
    player:SendBroadcastMessage("|cff66ccffFrostforge:|r The Campaign Veil fades. Your normal faction has been restored.")
end

local function ApplyOrgrimmarCampaignVeilToGroup(player)
    ApplyOrgrimmarCampaignVeil(player)

    local group = player:GetGroup()
    if not group then
        return
    end

    local members = group:GetMembers()
    for _, member in pairs(members) do
        if member and member:IsInWorld() then
            ApplyOrgrimmarCampaignVeil(member)
        end
    end
end

local function RemoveCampaignVeilFromGroup(player)
    RemoveCampaignVeil(player)

    local group = player:GetGroup()
    if not group then
        return
    end

    local members = group:GetMembers()
    for _, member in pairs(members) do
        if member and member:IsInWorld() then
            RemoveCampaignVeil(member)
        end
    end
end

local function LearnWeaponSkillsForStarterGear(player)
    local class = player:GetClass()
    local skillValue = player:GetLevel() * 5

    SetSkillSafe(player, SKILL_DEFENSE, skillValue, skillValue)

    if class == CLASS_WARRIOR then
        if player:GetTeam() == TEAM_HORDE then
            SetSkillSafe(player, SKILL_AXES, skillValue, skillValue)
            SetSkillSafe(player, SKILL_TWO_HANDED_AXES, skillValue, skillValue)
        else
            SetSkillSafe(player, SKILL_SWORDS, skillValue, skillValue)
            SetSkillSafe(player, SKILL_TWO_HANDED_SWORDS, skillValue, skillValue)
        end
        return
    end

    if class == CLASS_PALADIN then
        SetSkillSafe(player, SKILL_SWORDS, skillValue, skillValue)
        SetSkillSafe(player, SKILL_TWO_HANDED_SWORDS, skillValue, skillValue)
        SetSkillSafe(player, SKILL_MACES, skillValue, skillValue)
        SetSkillSafe(player, SKILL_TWO_HANDED_MACES, skillValue, skillValue)
        return
    end

    if class == CLASS_HUNTER then
        SetSkillSafe(player, SKILL_BOWS, skillValue, skillValue)
        SetSkillSafe(player, SKILL_GUNS, skillValue, skillValue)
        SetSkillSafe(player, SKILL_SWORDS, skillValue, skillValue)
        return
    end

    if class == CLASS_ROGUE then
        SetSkillSafe(player, SKILL_SWORDS, skillValue, skillValue)
        SetSkillSafe(player, SKILL_DAGGERS, skillValue, skillValue)
        return
    end

    if class == CLASS_PRIEST or class == CLASS_MAGE or class == CLASS_WARLOCK then
        SetSkillSafe(player, SKILL_STAVES, skillValue, skillValue)
        SetSkillSafe(player, SKILL_WANDS, skillValue, skillValue)
        return
    end

    if class == CLASS_SHAMAN then
        SetSkillSafe(player, SKILL_MACES, skillValue, skillValue)
        SetSkillSafe(player, SKILL_SHIELDS, skillValue, skillValue)
        return
    end

    if class == CLASS_DRUID then
        SetSkillSafe(player, SKILL_STAVES, skillValue, skillValue)
        return
    end
end

local function LearnLevel10ClassSpells(player)
    local class = player:GetClass()
    local learned = 0

    if class == CLASS_WARRIOR then
        learned = LearnSpells(player, WARRIOR_LEVEL10_SPELLS)
        LearnWeaponSkillsForStarterGear(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Learned " .. learned .. " warrior abilities for level 10.")
        return
    end

    if class == CLASS_PALADIN then
        learned = LearnSpells(player, PALADIN_LEVEL10_SPELLS)
        LearnWeaponSkillsForStarterGear(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Learned " .. learned .. " paladin abilities for level 10.")
        return
    end

    if class == CLASS_HUNTER then
        learned = LearnSpells(player, HUNTER_LEVEL10_SPELLS)
        LearnWeaponSkillsForStarterGear(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Learned " .. learned .. " hunter abilities for level 10.")
        return
    end

    if class == CLASS_ROGUE then
        learned = LearnSpells(player, ROGUE_LEVEL10_SPELLS)
        LearnWeaponSkillsForStarterGear(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Learned " .. learned .. " rogue abilities for level 10.")
        return
    end

    if class == CLASS_PRIEST then
        learned = LearnSpells(player, PRIEST_LEVEL10_SPELLS)
        LearnWeaponSkillsForStarterGear(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Learned " .. learned .. " priest abilities for level 10.")
        return
    end

    if class == CLASS_SHAMAN then
        learned = LearnSpells(player, SHAMAN_LEVEL10_SPELLS)
        LearnWeaponSkillsForStarterGear(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Learned " .. learned .. " shaman abilities for level 10.")
        return
    end

    if class == CLASS_MAGE then
        learned = LearnSpells(player, MAGE_LEVEL10_SPELLS)
        LearnWeaponSkillsForStarterGear(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Learned " .. learned .. " mage abilities for level 10.")
        return
    end

    if class == CLASS_WARLOCK then
        learned = LearnSpells(player, WARLOCK_LEVEL10_SPELLS)
        LearnWeaponSkillsForStarterGear(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Learned " .. learned .. " warlock abilities for level 10.")
        return
    end

    if class == CLASS_DRUID then
        learned = LearnSpells(player, DRUID_LEVEL10_SPELLS)
        LearnWeaponSkillsForStarterGear(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Learned " .. learned .. " druid abilities for level 10.")
        return
    end

    player:SendBroadcastMessage("|cffffcc00Frostforge Guide:|r Automatic level 10 spell training is not configured for this class.")
end

local function GiveClassStarterGear(player)
    local class = player:GetClass()
    local set = STARTER_GEAR[class]

    if not set then
        player:SendBroadcastMessage("|cffffcc00Frostforge Guide:|r No starter gear configured for your class yet.")
        return
    end

    if class == CLASS_WARRIOR then
        if player:GetTeam() == TEAM_HORDE then
            player:AddItem(ITEM_2H_AXE_HORDE_WARRIOR, 1)
            player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r You received a two-handed axe.")
        else
            player:AddItem(ITEM_2H_SWORD_ALLIANCE_WARRIOR, 1)
            player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r You received a two-handed sword.")
        end
    end

    GiveItems(player, set.common)
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r You received your class starter gear.")
end

local function GiveStarterSupplies(player)
    player:AddItem(ITEM_SMALL_BROWN_POUCH, 2)
    player:AddItem(ITEM_MINOR_HEALING_POTION, 2)
    player:ModifyMoney(10000)

    GiveClassStarterGear(player)
end

local function GiveDungeonClassReward(player, rewardTable, dungeonName)
    local class = player:GetClass()
    local rewards = rewardTable[class]

    if not rewards then
        player:SendBroadcastMessage("|cffffcc00Frostforge Path:|r No class reward configured for " .. dungeonName .. ".")
        return
    end

    GiveItems(player, rewards)
    player:SendBroadcastMessage("|cff66ccffFrostforge Path:|r You received your " .. dungeonName .. " class reward.")
end

local function TeleportPlayerGroup(player, map, x, y, z, o)
    local group = player:GetGroup()

    if not group then
        player:Teleport(map, x, y, z, o)
        return
    end

    local members = group:GetMembers()

    for _, member in pairs(members) do
        if member and member:IsInWorld() then
            member:SendBroadcastMessage("|cff66ccffFrostforge:|r Your group is being moved together.")
            member:Teleport(map, x, y, z, o)
        end
    end
end

local function SendBotInviteHelp(player)
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Use the Frostforge Pathfinder to create a Playerbot group automatically.")
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Manual command example: .playerbots bot addclass priest")
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r A balanced dungeon group has 1 tank, 1 healer, and 3 damage dealers.")
end

local function SendTankHelp(player)
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Tank setup: keep enemies focused on you while your bots heal and deal damage.")
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Recommended bots: priest, mage, hunter, rogue.")
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r The Pathfinder can create this group automatically.")
end

local function SendDamageHelp(player)
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Damage setup: bring a tank, a healer, and two other damage bots.")
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Recommended bots: warrior, priest, mage, hunter.")
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r The Pathfinder can create this group automatically.")
end

local function SendHealerHelp(player)
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Healer setup: bring a tank and three damage bots.")
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Recommended bots: warrior, mage, hunter, rogue.")
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r The Pathfinder can create this group automatically.")
end

local function OnGuideGossipHello(event, player, creature)
    player:GossipClearMenu()

    player:GossipAddQuests(creature)

    player:GossipMenuAddItem(0, "How does the Frostforge Path work?", 0, 30)
--    player:GossipMenuAddItem(0, "How do I form a Playerbot dungeon group?", 0, 1)
--    player:GossipMenuAddItem(0, "Recommended group: I want to tank.", 0, 3)
--    player:GossipMenuAddItem(0, "Recommended group: I want to deal damage.", 0, 4)
--    player:GossipMenuAddItem(0, "Recommended group: I want to heal.", 0, 5)

    if player:HasQuest(QUEST_ORGRIMMAR) and not player:GetQuestRewardStatus(QUEST_ORGRIMMAR) then
        player:GossipMenuAddItem(0, "Send me to Orgrimmar. I am ready to investigate.", 0, 20)
        player:GossipMenuAddItem(0, "Restore my normal faction.", 0, 22)
    end

    if player:HasQuest(QUEST_RFC) and not player:GetQuestRewardStatus(QUEST_RFC) then
        player:GossipMenuAddItem(0, "Send my group to the Ragefire Chasm entrance.", 0, 2)
        player:GossipMenuAddItem(0, "Send my group inside Ragefire Chasm.", 0, 6)
    end

    player:GossipSendMenu(1, creature)
end

local function OnGuideGossipSelect(event, player, creature, sender, intid, code, menu_id)
    player:GossipClearMenu()

    if intid == 1 then
        SendBotInviteHelp(player)
        player:GossipComplete()
        return
    end

    if intid == 2 then
        if player:HasQuest(QUEST_RFC) and not player:GetQuestRewardStatus(QUEST_RFC) then
            player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Sending your group to the Ragefire Chasm entrance.")
            player:GossipComplete()
            TeleportPlayerGroup(player, MAP_KALIMDOR, RFC_X, RFC_Y, RFC_Z, RFC_O)
        else
            player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r You are not currently on the Ragefire Chasm trial.")
            player:GossipComplete()
        end
        return
    end

    if intid == 3 then
        SendTankHelp(player)
        player:GossipComplete()
        return
    end

    if intid == 4 then
        SendDamageHelp(player)
        player:GossipComplete()
        return
    end

    if intid == 5 then
        SendHealerHelp(player)
        player:GossipComplete()
        return
    end

    if intid == 6 then
        if player:HasQuest(QUEST_RFC) and not player:GetQuestRewardStatus(QUEST_RFC) then
            player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Ragefire Chasm.")
            player:GossipComplete()
            TeleportPlayerGroup(player, MAP_RFC, RFC_INSIDE_X, RFC_INSIDE_Y, RFC_INSIDE_Z, RFC_INSIDE_O)
        else
            player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r You are not currently on the Ragefire Chasm trial.")
            player:GossipComplete()
        end
        return
    end

    if intid == 20 then
        if player:HasQuest(QUEST_ORGRIMMAR) and not player:GetQuestRewardStatus(QUEST_ORGRIMMAR) then
            ApplyOrgrimmarCampaignVeilToGroup(player)
            player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Walk through Orgrimmar and speak with the Grunt, Shaman, and Guard. Follow the trail toward Ragefire Chasm.")
            player:GossipComplete()
            TeleportPlayerGroup(player, MAP_KALIMDOR, ORG_X, ORG_Y, ORG_Z, ORG_O)
        else
            player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r You are not currently investigating Orgrimmar.")
            player:GossipComplete()
        end
        return
    end

    if intid == 22 then
        RemoveCampaignVeilFromGroup(player)
        player:GossipComplete()
        return
    end

    if intid == 30 then
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Frostforge is a Classic Lore Campaign. You will walk through the stories that shaped Azeroth, one dungeon chapter at a time.")
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Some chapters belong to your people. Some belong to your enemies. All of them matter.")
        player:GossipComplete()
        return
    end

    player:GossipComplete()
end

local function GetInvestigationText(entry)
    if entry == NPC_ORG_GRUNT then
        return "You hear it too, don't you? The city is young, but the stones beneath it are not quiet. Smoke rises from the Cleft of Shadow, and some of the grunts swear they hear chanting below. Thrall built Orgrimmar to be a new beginning, but something old is still burning under our feet."
    end

    if entry == NPC_ORG_SHAMAN then
        return "The elements beneath Orgrimmar are restless. Fire answers fire. Rage answers rage. This is not merely a cave beneath the city; it is a wound where old corruption still gathers. If the Horde wishes to be free of its past, it must first face what still lives below."
    end

    if entry == NPC_ORG_GUARD then
        return "The reports all point to Ragefire Chasm. Cultists, beasts, and worse have been seen below the city. Do not go alone. Gather allies before entering. If Taragaman still feeds in the depths, then this is more than a disturbance — it is a warning."
    end

    return "There is trouble beneath Orgrimmar."
end

local function OnInvestigationGossipHello(event, player, creature)
    player:GossipClearMenu()

    if player:HasQuest(QUEST_ORGRIMMAR) and not player:GetQuestRewardStatus(QUEST_ORGRIMMAR) then
        player:GossipMenuAddItem(0, "Ask about the trouble beneath Orgrimmar.", 0, 1)
    else
        player:GossipMenuAddItem(0, "Who are you?", 0, 2)
    end

    player:GossipSendMenu(1, creature)
end

local function OnInvestigationGossipSelect(event, player, creature, sender, intid, code, menu_id)
    player:GossipClearMenu()

    local entry = creature:GetEntry()

    if intid == 1 then
        local text = GetInvestigationText(entry)

        player:SendBroadcastMessage("|cff66ccff" .. creature:GetName() .. ":|r " .. text)

        if creature.SendUnitSay then
            creature:SendUnitSay(text, 0)
        end

        if player:HasQuest(QUEST_ORGRIMMAR) and not player:GetQuestRewardStatus(QUEST_ORGRIMMAR) then
            player:KilledMonsterCredit(entry)
            player:SendBroadcastMessage("|cff66ccffFrostforge:|r Investigation progress recorded.")
        end

        player:GossipComplete()
        return
    end

    if intid == 2 then
        local text = "I am a witness along the Frostforge Path."
        player:SendBroadcastMessage("|cff66ccff" .. creature:GetName() .. ":|r " .. text)

        if creature.SendUnitSay then
            creature:SendUnitSay(text, 0)
        end

        player:GossipComplete()
        return
    end

    player:GossipComplete()
end

local function GetQuestIdSafe(quest)
    if type(quest) == "userdata" and quest.GetId then
        return quest:GetId()
    end

    return quest
end

local function OnQuestAccept(event, player, quest)
    local questId = GetQuestIdSafe(quest)

    if questId == QUEST_ORGRIMMAR then
        ApplyOrgrimmarCampaignVeilToGroup(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r The Campaign Veil will protect you during this chapter.")
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Speak with me again when you are ready to travel to Orgrimmar.")
        return
    end
end

local function OnQuestReward(event, player, quest, opt)
    local questId = GetQuestIdSafe(quest)

    if questId == QUEST_WELCOME then
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Next, claim your starter gear.")
        return
    end

    if questId == QUEST_STARTER_GEAR then
        LearnLevel10ClassSpells(player)
        GiveStarterSupplies(player)

        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Your starter supplies have been added.")
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Equip your items, then begin the first lore chapter.")
        return
    end

    if questId == QUEST_ORGRIMMAR then
        RemoveCampaignVeilFromGroup(player)
        player:SendBroadcastMessage("|cff66ccffFrostforge Path:|r Trouble Beneath Orgrimmar complete. The trail now leads into Ragefire Chasm.")
        return
    end

    if questId == QUEST_GROUP then
        player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r Good. Use the Frostforge Pathfinder to create a group, then prepare to enter Ragefire Chasm.")
        return
    end

    if questId == QUEST_RFC then
        GiveDungeonClassReward(player, RFC_CLASS_REWARDS, "Ragefire Chasm")

        if player:GetLevel() < TARGET_LEVEL_RFC then
            player:SetLevel(TARGET_LEVEL_RFC)
            player:SendBroadcastMessage("|cff66ccffFrostforge Path:|r You have advanced to level 15.")
        end

        player:ModifyMoney(20000)
	player:SendBroadcastMessage("|cff66ccffArchivist Eldrin:|r You have seen the truth beneath Orgrimmar. The Horde may be building a new future, but the past still burns below its feet.")
        player:SendBroadcastMessage("|cff66ccffFrostforge Path:|r Ragefire Chasm complete. Your next dungeon trial awaits.")
        return
    end
end

local function OnPlayerLogout(event, player)
    RemoveCampaignVeil(player)
end

-- Pathfinder handles the story, quests, travel and campaign flow.
RegisterCreatureGossipEvent(NPC_FROSTFORGE_PATHFINDER, 1, OnGuideGossipHello)
RegisterCreatureGossipEvent(NPC_FROSTFORGE_PATHFINDER, 2, OnGuideGossipSelect)

RegisterCreatureGossipEvent(NPC_ORG_GRUNT, 1, OnInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC_ORG_GRUNT, 2, OnInvestigationGossipSelect)

RegisterCreatureGossipEvent(NPC_ORG_SHAMAN, 1, OnInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC_ORG_SHAMAN, 2, OnInvestigationGossipSelect)

RegisterCreatureGossipEvent(NPC_ORG_GUARD, 1, OnInvestigationGossipHello)
RegisterCreatureGossipEvent(NPC_ORG_GUARD, 2, OnInvestigationGossipSelect)

-- Guide gossip is handled by the C++ Frostforge bot group script.
-- Pathfinder gossip is handled here in Lua.
-- Keep these disabled to prevent gossip conflicts.
-- RegisterCreatureGossipEvent(NPC_FROSTFORGE_PATHFINDER, 1, OnPathfinderGossipHello)
-- RegisterCreatureGossipEvent(NPC_FROSTFORGE_PATHFINDER, 2, OnPathfinderGossipSelect)

RegisterPlayerEvent(31, OnQuestAccept)
RegisterPlayerEvent(54, OnQuestReward)
RegisterPlayerEvent(4, OnPlayerLogout)
