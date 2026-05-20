-- Frostforge starter gear, class spells and starter supplies
-- Dungeon reward packs are handled in 04_dungeon_rewards.inc

Frostforge = Frostforge or {}
Frostforge.StarterGear = Frostforge.StarterGear or {}

local C = Frostforge.Class
local T = Frostforge.Team
local S = Frostforge.Skill
local U = Frostforge.Utils

-- Basic supplies
local ITEM_TRAVELERS_BACKPACK = 4500
local ITEM_MINOR_HEALING_POTION = 118
local ITEM_LESSER_HEALING_POTION = 858
local ITEM_MINOR_MANA_POTION = 2455

local ITEM_LIGHT_QUIVER = 2101
local ITEM_ROUGH_ARROW = 2512
local ITEM_SHARP_ARROW = 2515
local ITEM_SMALL_AMMO_POUCH = 2102

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

local ITEM_SHAMAN_EARTH_TOTEM = 5175
local ITEM_SHAMAN_FIRE_TOTEM = 5176
local ITEM_SHAMAN_WATER_TOTEM = 5177
local ITEM_SHAMAN_AIR_TOTEM = 5178

-- Cloth starter gear
local CLOTH_CHEST = 9749
local CLOTH_BELT = 14113
local CLOTH_LEGS = 10047
local CLOTH_BOOTS = 6537
local CLOTH_BRACERS = 6543
local CLOTH_GLOVES = 4768
local CLOTH_CLOAK = 14365

-- Leather starter gear
local LEATHER_CHEST = 9757
local LEATHER_BELT = 6558
local LEATHER_LEGS = 4242
local LEATHER_BOOTS = 2309
local LEATHER_BRACERS = 6556
local LEATHER_GLOVES = 3314
local LEATHER_CLOAK = 1355

-- Mail starter gear
local MAIL_CHEST = 9765
local MAIL_BELT = 832
local MAIL_LEGS = 2978
local MAIL_BOOTS = 3302
local MAIL_BRACERS = 15495
local MAIL_GLOVES = 15491
local MAIL_CLOAK = 1355

local SPELLS = {
    [C.WARRIOR] = {
        2457, -- Battle Stance
        71,   -- Defensive Stance
        78,   -- Heroic Strike
        284,  -- Heroic Strike Rank 2
        100,  -- Charge
        772,  -- Rend
        6546, -- Rend Rank 2
        6343, -- Thunder Clap
        1715, -- Hamstring
        2687, -- Bloodrage
        7386, -- Sunder Armor
        355,  -- Taunt
        6673  -- Battle Shout
    },

    [C.PALADIN] = {
        635,   -- Holy Light
        21084, -- Seal of Righteousness
        465,   -- Devotion Aura
        19740, -- Blessing of Might
        20271  -- Judgement of Light
    },

    [C.HUNTER] = {
        75,    -- Auto Shot
        2973,  -- Raptor Strike
        1978,  -- Serpent Sting
        3044,  -- Arcane Shot
        1130,  -- Hunter's Mark
        13163, -- Aspect of the Monkey
        5116,  -- Concussive Shot
        883,   -- Call Pet
        982,   -- Revive Pet
        6991   -- Feed Pet
    },

    [C.ROGUE] = {
        1752, -- Sinister Strike
        2098, -- Eviscerate
        1784, -- Stealth
        921,  -- Pick Pocket
        1776, -- Gouge
        5277  -- Evasion
    },

    [C.PRIEST] = {
        585,  -- Smite
        2050, -- Lesser Heal
        2052, -- Lesser Heal Rank 2
        1243, -- Power Word: Fortitude
        589,  -- Shadow Word: Pain
        139,  -- Renew
        17,   -- Power Word: Shield
        586   -- Fade
    },

    [C.SHAMAN] = {
        403,  -- Lightning Bolt
        529,  -- Lightning Bolt Rank 2
        331,  -- Healing Wave
        332,  -- Healing Wave Rank 2
        8042, -- Earth Shock
        8017, -- Rockbiter Weapon
        8018, -- Rockbiter Weapon Rank 2
        2484, -- Earthbind Totem
        8075  -- Strength of Earth Totem
    },

    [C.MAGE] = {
        133,  -- Fireball
        143,  -- Fireball Rank 2
        168,  -- Frost Armor
        116,  -- Frostbolt
        205,  -- Frostbolt Rank 2
        1459, -- Arcane Intellect
        5504, -- Conjure Water
        587,  -- Conjure Food
        2136, -- Fire Blast
        118   -- Polymorph
    },

    [C.WARLOCK] = {
        686,  -- Shadow Bolt
        695,  -- Shadow Bolt Rank 2
        687,  -- Demon Skin
        348,  -- Immolate
        172,  -- Corruption
        702,  -- Curse of Weakness
        1454, -- Life Tap
        688,  -- Summon Imp
        6201, -- Create Healthstone
        1120, -- Drain Soul
        5782  -- Fear
    },

    [C.DRUID] = {
        5176, -- Wrath
        5177, -- Wrath Rank 2
        5185, -- Healing Touch
        5186, -- Healing Touch Rank 2
        8921, -- Moonfire
        8924, -- Moonfire Rank 2
        774,  -- Rejuvenation
        1126, -- Mark of the Wild
        467,  -- Thorns
        339,  -- Entangling Roots
        5487, -- Bear Form
        99,   -- Demoralizing Roar
        6807  -- Maul
    }
}

local STARTER_GEAR = {
    [C.WARRIOR] = {
        common = {
            {MAIL_CHEST}, {MAIL_BELT}, {MAIL_LEGS}, {MAIL_BOOTS}, {MAIL_BRACERS}, {MAIL_GLOVES}, {MAIL_CLOAK}
        }
    },

    [C.PALADIN] = {
        common = {
            {ITEM_2H_SWORD},
            {MAIL_CHEST}, {MAIL_BELT}, {MAIL_LEGS}, {MAIL_BOOTS}, {MAIL_BRACERS}, {MAIL_GLOVES}, {MAIL_CLOAK}
        }
    },

    [C.HUNTER] = {
        common = {
            {ITEM_BOW}, {ITEM_2H_SWORD},
            {LEATHER_CHEST}, {LEATHER_BELT}, {LEATHER_LEGS}, {LEATHER_BOOTS}, {LEATHER_BRACERS}, {LEATHER_GLOVES}, {LEATHER_CLOAK}
        }
    },

    [C.ROGUE] = {
        common = {
            {ITEM_1H_SWORD}, {ITEM_DAGGER},
            {LEATHER_CHEST}, {LEATHER_BELT}, {LEATHER_LEGS}, {LEATHER_BOOTS}, {LEATHER_BRACERS}, {LEATHER_GLOVES}, {LEATHER_CLOAK}
        }
    },

    [C.PRIEST] = {
        common = {
            {ITEM_STAFF}, {ITEM_WAND},
            {CLOTH_CHEST}, {CLOTH_BELT}, {CLOTH_LEGS}, {CLOTH_BOOTS}, {CLOTH_BRACERS}, {CLOTH_GLOVES}, {CLOTH_CLOAK}
        }
    },

    [C.SHAMAN] = {
        common = {
            {ITEM_1H_MACE}, {ITEM_SHIELD},
            {ITEM_SHAMAN_EARTH_TOTEM},
            {ITEM_SHAMAN_FIRE_TOTEM},
            {ITEM_SHAMAN_WATER_TOTEM},
            {ITEM_SHAMAN_AIR_TOTEM},
            {LEATHER_CHEST}, {LEATHER_BELT}, {LEATHER_LEGS}, {LEATHER_BOOTS}, {LEATHER_BRACERS}, {LEATHER_GLOVES}, {LEATHER_CLOAK}
        }
    },

    [C.MAGE] = {
        common = {
            {ITEM_STAFF}, {ITEM_WAND},
            {CLOTH_CHEST}, {CLOTH_BELT}, {CLOTH_LEGS}, {CLOTH_BOOTS}, {CLOTH_BRACERS}, {CLOTH_GLOVES}, {CLOTH_CLOAK}
        }
    },

    [C.WARLOCK] = {
        common = {
            {ITEM_STAFF}, {ITEM_WAND},
            {CLOTH_CHEST}, {CLOTH_BELT}, {CLOTH_LEGS}, {CLOTH_BOOTS}, {CLOTH_BRACERS}, {CLOTH_GLOVES}, {CLOTH_CLOAK}
        }
    },

    [C.DRUID] = {
        common = {
            {ITEM_STAFF},
            {LEATHER_CHEST}, {LEATHER_BELT}, {LEATHER_LEGS}, {LEATHER_BOOTS}, {LEATHER_BRACERS}, {LEATHER_GLOVES}, {LEATHER_CLOAK}
        }
    }
}

function Frostforge.StarterGear.LearnWeaponSkillsForStarterGear(player)
    local class = player:GetClass()
    local skillValue = player:GetLevel() * 5

    local function Set(skill)
        if skill then
            U.SetSkillSafe(player, skill, skillValue, skillValue)
        end
    end

    Set(S.DEFENSE)

    if class == C.WARRIOR then
        Set(S.AXES)
        Set(S.TWO_HANDED_AXES)
        Set(S.SWORDS)
        Set(S.TWO_HANDED_SWORDS)
        Set(S.MACES)
        Set(S.TWO_HANDED_MACES)
        Set(S.DAGGERS)
        Set(S.SHIELDS)
        Set(S.BOWS)
        Set(S.GUNS)
        Set(S.CROSSBOWS)
        Set(S.THROWN)
        Set(S.POLEARMS)
        Set(S.FIST_WEAPONS)
        return
    end

    if class == C.PALADIN then
        Set(S.SWORDS)
        Set(S.TWO_HANDED_SWORDS)
        Set(S.MACES)
        Set(S.TWO_HANDED_MACES)
        Set(S.AXES)
        Set(S.TWO_HANDED_AXES)
        Set(S.SHIELDS)
        Set(S.POLEARMS)
        return
    end

    if class == C.HUNTER then
        Set(S.BOWS)
        Set(S.GUNS)
        Set(S.CROSSBOWS)
        Set(S.SWORDS)
        Set(S.TWO_HANDED_SWORDS)
        Set(S.AXES)
        Set(S.TWO_HANDED_AXES)
        Set(S.DAGGERS)
        Set(S.POLEARMS)
        Set(S.STAVES)
        Set(S.FIST_WEAPONS)
        return
    end

    if class == C.ROGUE then
        Set(S.SWORDS)
        Set(S.DAGGERS)
        Set(S.MACES)
        Set(S.FIST_WEAPONS)
        Set(S.THROWN)
        Set(S.BOWS)
        Set(S.GUNS)
        Set(S.CROSSBOWS)
        return
    end

    if class == C.PRIEST then
        Set(S.STAVES)
        Set(S.WANDS)
        Set(S.MACES)
        Set(S.DAGGERS)
        return
    end

    if class == C.SHAMAN then
        Set(S.MACES)
        Set(S.TWO_HANDED_MACES)
        Set(S.AXES)
        Set(S.TWO_HANDED_AXES)
        Set(S.DAGGERS)
        Set(S.STAVES)
        Set(S.FIST_WEAPONS)
        Set(S.SHIELDS)
        return
    end

    if class == C.MAGE then
        Set(S.STAVES)
        Set(S.WANDS)
        Set(S.DAGGERS)
        Set(S.SWORDS)
        return
    end

    if class == C.WARLOCK then
        Set(S.STAVES)
        Set(S.WANDS)
        Set(S.DAGGERS)
        Set(S.SWORDS)
        return
    end

    if class == C.DRUID then
        Set(S.STAVES)
        Set(S.MACES)
        Set(S.TWO_HANDED_MACES)
        Set(S.DAGGERS)
        Set(S.FIST_WEAPONS)
        return
    end
end

function Frostforge.StarterGear.LearnLevel10ClassSpells(player)
    local class = player:GetClass()
    local spells = SPELLS[class]

    if not spells then
        U.SendGuideMessage(player, "Automatic level 10 spell training is not configured for this class.")
        return
    end

    local learned = U.LearnSpells(player, spells)

    Frostforge.StarterGear.LearnWeaponSkillsForStarterGear(player)

    U.SendGuideMessage(player, "Learned " .. learned .. " class abilities for level 10.")
end

function Frostforge.StarterGear.GiveClassStarterGear(player)
    local class = player:GetClass()
    local set = STARTER_GEAR[class]

    if not set then
        U.SendGuideMessage(player, "No starter gear configured for your class yet.")
        return
    end

    if class == C.WARRIOR then
        if player:GetTeam() == T.HORDE then
            player:AddItem(ITEM_2H_AXE_HORDE_WARRIOR, 1)
            U.SendGuideMessage(player, "You received a two-handed axe.")
        else
            player:AddItem(ITEM_2H_SWORD_ALLIANCE_WARRIOR, 1)
            U.SendGuideMessage(player, "You received a two-handed sword.")
        end
    end

    U.GiveItems(player, set.common)
    U.SendGuideMessage(player, "You received your class starter gear.")
end

local function GiveAndEquipStarterBags(player)
    local class = player:GetClass()

    -- Bag slots are 19, 20, 21, 22 in 3.3.5.
    if player.EquipItem then
        -- Hunters receive 3 normal bags + 1 quiver, because they start with a bow.
        if class == C.HUNTER then
            -- Remove the default ammo pouch if present, because it only holds bullets.
            player:RemoveItem(ITEM_SMALL_AMMO_POUCH, 1)

            player:EquipItem(ITEM_TRAVELERS_BACKPACK, 19)
            player:EquipItem(ITEM_TRAVELERS_BACKPACK, 20)
            player:EquipItem(ITEM_TRAVELERS_BACKPACK, 21)
            player:EquipItem(ITEM_LIGHT_QUIVER, 22)

            -- Arrows for the starter bow.
            player:AddItem(ITEM_ROUGH_ARROW, 400)
            player:AddItem(ITEM_SHARP_ARROW, 400)

            return
        end

        player:EquipItem(ITEM_TRAVELERS_BACKPACK, 19)
        player:EquipItem(ITEM_TRAVELERS_BACKPACK, 20)
        player:EquipItem(ITEM_TRAVELERS_BACKPACK, 21)
        player:EquipItem(ITEM_TRAVELERS_BACKPACK, 22)
        return
    end

    -- Fallback if EquipItem is unavailable.
    if class == C.HUNTER then
        player:RemoveItem(ITEM_SMALL_AMMO_POUCH, 1)
        player:AddItem(ITEM_TRAVELERS_BACKPACK, 3)
        player:AddItem(ITEM_LIGHT_QUIVER, 1)
        player:AddItem(ITEM_ROUGH_ARROW, 400)
        player:AddItem(ITEM_SHARP_ARROW, 400)
    else
        player:AddItem(ITEM_TRAVELERS_BACKPACK, 4)
    end
end

function Frostforge.StarterGear.GiveStarterSupplies(player)
    -- Equip bags first so the rest of the rewards have room.
    GiveAndEquipStarterBags(player)

    -- Consumables
    player:AddItem(ITEM_MINOR_HEALING_POTION, 5)
    player:AddItem(ITEM_LESSER_HEALING_POTION, 5)
    player:AddItem(ITEM_MINOR_MANA_POTION, 5)

    -- Starting money: 1 gold
    player:ModifyMoney(10000)

    Frostforge.StarterGear.GiveClassStarterGear(player)

    U.SendGuideMessage(player, "Starter supplies added: 4 Traveler's Backpacks, potions, gold, and class gear.")
end

print("[Frostforge] Starter gear loaded.")
