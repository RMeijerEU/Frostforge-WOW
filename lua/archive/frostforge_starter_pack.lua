--
-- Frostforge Level 70 Starter Boost
-- Retail-style character boost flow:
-- First login: bags + satchel
-- Satchel use: spells, skills, riding, mount, gear, consumables, teleport
--

local SATCHEL_ITEM = 900100
local START_LEVEL = 70

local NORTHREND_START_QUESTS = {
    ALLIANCE = 11672, -- Enlistment Day
    HORDE    = 11585, -- Hellscream's Vigil
}

local COMMON_FIRST_LOGIN_ITEMS = {
    {41599, 4},    -- Frostweave Bag
    {900100, 1},   -- Frostforge Boost Satchel
}

local COMMON_SATCHEL_ITEMS = {
    {27860, 20}, -- Purified Draenic Water
    {29451, 20}, -- Clefthoof Ribs
}

local RIDING_SPELLS = {
    33388, -- Apprentice Riding
    33391, -- Journeyman Riding
    34090, -- Expert Riding / basic flying
}

local EXTRA_CLASS_SPELLS = {
    [1] = { -- Warrior
        2457, -- Battle Stance
        71,   -- Defensive Stance
        2458, -- Berserker Stance
    },
}

-- Do NOT add:
-- 34091 = Artisan / Epic Flying
-- 54197 = Cold Weather Flying

local MOUNTS = {
    FLYING_ALLIANCE = 25470, -- Golden Gryphon
    FLYING_HORDE    = 25475, -- Blue Wind Rider

    GROUND_ALLIANCE = 18777, -- Swift Brown Steed
    GROUND_HORDE    = 18796, -- Horn of the Swift Brown Wolf
}

--
-- Gear lists are level 70 starter packs.
-- Supports both:
-- 12345          = give 1x item
-- {12345, 1000} = give amount
--

local GEAR = {
    [1] = { -- Warrior
        -- Armor
        990001, -- Head
        990002, -- Shoulders
        990003, -- Chest
        990004, -- Hands
        990005, -- Legs
        990006, -- Waist
        990007, -- Feet
        990008, -- Wrists
        990009, -- Back

        -- Neck / rings / trinkets
        990010,
        990011,
        990012,
        990013,
        990014,

        -- Arms
        990020, -- 2H axe

        -- Fury
        990021, -- 1H axe
        990022, -- 1H axe

        -- Protection
        990023, -- 1H mace
        990024, -- Shield

        -- Ranged / ammo
        990025, -- Bow
        {33803, 400}, -- Adamantite Stinger / arrows
    },

    [2] = { -- Paladin
        -- Armor
        990101,
        990102,
        990103,
        990104,
        990105,
        990106,
        990107,
        990108,
        990109,

        -- Neck / rings / trinkets
        990110,
        990111,
        990112,
        990113,
        990114,

        -- Retribution
        990120, -- 2H axe

        -- Protection
        990121, -- 1H mace
        990122, -- Shield

        -- Librams
        990125, -- Ret
        990126, -- Prot fallback
    },

    [3] = { -- Hunter
        -- Armor
        990201,
        990202,
        990203,
        990204,
        990205,
        990206,
        990207,
        990208,
        990209,

        -- Neck / rings / trinkets
        990210,
        990211,
        990212,
        990213,
        990214,

        -- Weapons / ammo
        990220, -- Bow
        990221, -- Polearm stat stick
        990222, -- Quiver
        {33803, 1000}, -- Adamantite Stinger / arrows
    },

    [4] = { -- Rogue
        -- Armor
        990301,
        990302,
        990303,
        990304,
        990305,
        990306,
        990307,
        990308,
        990309,

        -- Neck / rings / trinkets
        990310,
        990311,
        990312,
        990313,
        990314,

        -- Daggers
        990320,
        990321,

        -- Thrown
        990322,
    },

    [5] = { -- Priest
        -- Armor
        990401,
        990402,
        990403,
        990404,
        990405,
        990406,
        990407,
        990408,
        990409,

        -- Neck / rings / trinkets
        990410,
        990411,
        990412,
        990413,
        990414,

        -- Weapons
        990420, -- Staff
        990421, -- Dagger
        990422, -- Offhand
        990423, -- Wand
    },

    [6] = { -- Death Knight
        -- Armor
        990501,
        990502,
        990503,
        990504,
        990505,
        990506,
        990507,
        990508,
        990509,

        -- Neck / rings / trinkets
        990510,
        990511,
        990512,
        990513,
        990514,

        -- Weapons
        990520, -- 2H axe
        990521, -- 1H axe
        990522, -- 1H axe
        990523, -- 1H mace
    },

    [7] = { -- Shaman
        -- Armor
        990601,
        990602,
        990603,
        990604,
        990605,
        990606,
        990607,
        990608,
        990609,

        -- Neck / rings / trinkets
        990610,
        990611,
        990612,
        990613,
        990614,

        -- Elemental / Restoration
        990620, -- Staff
        990621, -- Dagger
        990622, -- Offhand
        990623, -- Shield

        -- Enhancement fallback
        990624, -- 1H axe
        990625, -- 1H axe

        -- Totems
        990626, -- Resto
        990627, -- Enhancement
        990628, -- Elemental
    },

    [8] = { -- Mage
        -- Armor
        990701,
        990702,
        990703,
        990704,
        990705,
        990706,
        990707,
        990708,
        990709,

        -- Neck / rings / trinkets
        990710,
        990711,
        990712,
        990713,
        990714,

        -- Weapons
        990720, -- Staff
        990721, -- Dagger
        990722, -- Offhand
        990723, -- Wand
    },

    [9] = { -- Warlock
        -- Armor
        990801,
        990802,
        990803,
        990804,
        990805,
        990806,
        990807,
        990808,
        990809,

        -- Neck / rings / trinkets
        990810,
        990811,
        990812,
        990813,
        990814,

        -- Weapons
        990820, -- Staff
        990821, -- Dagger
        990822, -- Offhand
        990823, -- Wand

        -- Soul shard bag
        990824,
    },

    [11] = { -- Druid
        -- Armor
        990901,
        990902,
        990903,
        990904,
        990905,
        990906,
        990907,
        990908,
        990909,

        -- Neck / rings / trinkets
        990910,
        990911,
        990912,
        990913,
        990914,

        -- Balance / Restoration
        990920, -- Staff
        990921, -- Dagger
        990922, -- Offhand

        -- Feral fallback
        990923, -- Polearm

        -- Idols
        990924, -- Feral
        990925, -- Restoration
        990926, -- Balance
    },
}

local CAPITALS = {
    [1]  = {0, -8833.38, 628.63, 94.00, 1.06},       -- Human: Stormwind
    [2]  = {1, 1601.08, -4378.69, 9.98, 2.14},       -- Orc: Orgrimmar
    [3]  = {0, -4981.25, -881.54, 501.66, 5.40},     -- Dwarf: Ironforge
    [4]  = {1, 9951.52, 2280.32, 1341.39, 1.59},     -- Night Elf: Darnassus
    [5]  = {0, 1633.75, 240.17, -43.10, 6.26},       -- Undead: Undercity
    [6]  = {1, -1277.37, 124.80, 131.29, 5.22},      -- Tauren: Thunder Bluff
    [7]  = {0, -4981.25, -881.54, 501.66, 5.40},     -- Gnome: Ironforge
    [8]  = {1, 1601.08, -4378.69, 9.98, 2.14},       -- Troll: Orgrimmar
    [10] = {530, 9487.69, -7279.20, 14.29, 6.16},    -- Blood Elf: Silvermoon
    [11] = {530, -3965.70, -11653.60, -138.84, 0.85} -- Draenei: Exodar
}

local function GiveItemList(player, items)
    for _, item in ipairs(items) do
        if type(item) == "table" then
            player:AddItem(item[1], item[2] or 1)
        else
            player:AddItem(item, 1)
        end
    end
end

local function GiveSpellList(player, spells)
    for _, spell in ipairs(spells) do
        player:LearnSpell(spell)
    end
end

local function LearnExtraClassSpells(player)
    local class = player:GetClass()
    local spells = EXTRA_CLASS_SPELLS[class]

    if not spells then
        return
    end

    for _, spellId in ipairs(spells) do
        player:LearnSpell(spellId)
    end

    player:SendBroadcastMessage("Frostforge: extra class abilities learned.")
end

local function LearnBoostSpells(player)
    local class = player:GetClass()

    local query = WorldDBQuery(string.format(
        "SELECT spell FROM frostforge_boost_spells WHERE class = %d ORDER BY spell",
        class
    ))

    if not query then
        player:SendBroadcastMessage("Frostforge: no boost spells found for your class.")
        return
    end

    local learned = 0

    repeat
        local spellId = query:GetUInt32(0)

        if spellId and spellId > 0 then
            player:LearnSpell(spellId)
            learned = learned + 1
        end
    until not query:NextRow()

    player:SendBroadcastMessage("Frostforge: learned " .. learned .. " class spells up to level 70.")
end

local function MaxBoostSkills(player)
    local level = player:GetLevel()
    local maxSkill = level * 5

    if maxSkill > 350 then
        maxSkill = 350
    end

    local skills = {
        43,  -- Swords
        44,  -- Axes
        45,  -- Bows
        46,  -- Guns
        54,  -- Maces
        55,  -- Two-Handed Swords
        95,  -- Defense
        118, -- Dual Wield
        136, -- Staves
        160, -- Two-Handed Maces
        162, -- Unarmed
        172, -- Two-Handed Axes
        173, -- Daggers
        176, -- Thrown
        226, -- Crossbows
        228, -- Wands
        229, -- Polearms
        473, -- Fist Weapons
    }

    for _, skill in ipairs(skills) do
        pcall(function()
            player:SetSkill(skill, maxSkill, maxSkill, maxSkill)
        end)
    end

    -- Riding skill: Expert Riding/basic flying is 225.
    pcall(function()
        player:SetSkill(762, 225, 225, 225)
    end)

    player:SendBroadcastMessage("Frostforge: weapon, defense and riding skills boosted.")
end

local function TeleportToCapital(player)
    local race = player:GetRace()
    local capital = CAPITALS[race]

    if capital then
        player:Teleport(capital[1], capital[2], capital[3], capital[4], capital[5])
    else
        if player:IsAlliance() then
            player:Teleport(0, -8833.38, 628.63, 94.00, 1.06)
        else
            player:Teleport(1, 1601.08, -4378.69, 9.98, 2.14)
        end
    end
end

local function OnFirstLogin(event, player)
    if player:GetLevel() < START_LEVEL then
        player:SetLevel(START_LEVEL)
    end

    GiveItemList(player, COMMON_FIRST_LOGIN_ITEMS)

    player:SendBroadcastMessage("Welcome to Frostforge! Equip your bags, then open your Frostforge Boost Satchel.")
end

local function GiveNorthrendStartQuest(player)
    local questId

    if player:IsAlliance() then
        questId = NORTHREND_START_QUESTS.ALLIANCE
    else
        questId = NORTHREND_START_QUESTS.HORDE
    end

    if not questId then
        return
    end

    if player:HasQuest(questId) then
        return
    end

    pcall(function()
        player:AddQuest(questId)
    end)

    player:SendBroadcastMessage("Frostforge: a Northrend starter quest has been added to your quest log.")
end

local function OnSatchelUse(event, player, item, target)
    local class = player:GetClass()
    local classGear = GEAR[class]

    if not classGear then
        player:SendBroadcastMessage("Frostforge: no starter gear configured for this class.")
        return true
    end

    -- Remove satchel first so it cannot be reused.
    player:RemoveItem(SATCHEL_ITEM, 1)

    -- Basic riding/flying, class spells, and skills.
    GiveSpellList(player, RIDING_SPELLS)
    LearnBoostSpells(player)
    LearnExtraClassSpells(player)
    MaxBoostSkills(player)
    GiveNorthrendStartQuest(player)

    -- Common consumables.
    GiveItemList(player, COMMON_SATCHEL_ITEMS)

    -- Faction ground + flying mounts.
    if player:IsAlliance() then
        player:AddItem(MOUNTS.GROUND_ALLIANCE, 1)
        player:AddItem(MOUNTS.FLYING_ALLIANCE, 1)
    else
        player:AddItem(MOUNTS.GROUND_HORDE, 1)
        player:AddItem(MOUNTS.FLYING_HORDE, 1)
    end

    -- Class gear.
    GiveItemList(player, classGear)

    player:SendBroadcastMessage("Your Frostforge level 70 starter gear has been unpacked. Welcome to Azeroth!")

    -- Teleport after giving items/spells.
    TeleportToCapital(player)

    -- Stop default item handling/loot from the underlying item.
    return true
end

RegisterPlayerEvent(30, OnFirstLogin)
RegisterItemEvent(SATCHEL_ITEM, 2, OnSatchelUse)

print("[Frostforge] Starter boost satchel script loaded.")
