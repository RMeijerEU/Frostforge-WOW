-- Frostforge Class Training
-- Class spell packs by campaign level.
-- Spell IDs are pulled from acore_world.trainer_spell using the world class trainers.

Frostforge = Frostforge or {}
Frostforge.ClassTraining = Frostforge.ClassTraining or {}

local C = Frostforge.Class
local U = Frostforge.Utils

-- Everything normally trainable up to level 15.
local LEVEL_15_SPELLS = {
    [C.WARRIOR] = {
        6673, 100, 772, 3127, 6343, 34428, 284, 1715, 2687, 6546, 72, 5242, 7384, 1160, 6572
    },

    [C.PALADIN] = {
        465, 10321, 19740, 498, 639, 853, 1152, 3127, 633, 1022, 10290, 19834, 53408, 647, 19742, 31789, 7328
    },

    [C.HUNTER] = {
        1494, 1978, 13163, 1130, 3044, 3127, 5116, 14260, 13165, 13549, 19883, 136, 2974, 14281, 20736, 1002, 1513, 6197
    },

    [C.ROGUE] = {
        1784, 53, 921, 1757, 1776, 5277, 6760, 674, 2983, 5171, 6770, 1766, 2589, 3127, 703, 1758, 8647
    },

    [C.PRIEST] = {
        1243, 589, 2052, 17, 591, 139, 586, 594, 2006, 2053, 8092, 588, 592, 1244, 528, 598, 6074, 8122
    },

    [C.SHAMAN] = {
        8017, 8042, 332, 2484, 324, 529, 5730, 8018, 8044, 8024, 8050, 8075, 370, 547, 1535, 2008, 548, 8045, 8154
    },

    [C.MAGE] = {
        1459, 116, 5504, 143, 587, 2136, 118, 205, 5143, 122, 5505, 7300, 130, 145, 597, 604, 837, 1449, 1460, 2137
    },

    [C.WARLOCK] = {
        688, 348, 172, 702, 695, 1454, 980, 5782, 696, 707, 1120, 6201, 705, 755, 1108, 689, 6222, 697
    },

    [C.DRUID] = {
        1126, 774, 8921, 467, 5177, 339, 5186, 99, 1058, 5232, 8924, 16689, 5229, 8936, 50769, 782, 5178, 5187, 5211
    }
}

-- Everything normally trainable from level 16 through 20.
local LEVEL_20_SPELLS = {
    [C.WARRIOR] = {
        285, 694, 2565, 676, 8198, 674, 845, 6547, 12678, 20230
    },

    [C.PALADIN] = {
        7294, 25780, 62124, 1044, 643, 879, 5502, 19750, 20217, 26573
    },

    [C.HUNTER] = {
        1495, 5118, 13795, 14261, 2643, 13550, 14318, 19884, 674, 781, 1499, 3111, 14282, 34074
    },

    [C.ROGUE] = {
        1804, 1966, 6761, 8676, 1943, 2590, 51722
    },

    [C.PRIEST] = {
        2054, 8102, 527, 600, 970, 453, 2061, 2944, 6075, 6346, 7128, 9484, 14914, 15237
    },

    [C.SHAMAN] = {
        325, 526, 2645, 8019, 57994, 913, 6390, 8027, 8052, 8143, 915, 6363, 8004, 8033, 8056, 52127
    },

    [C.MAGE] = {
        2120, 5144, 475, 1008, 3140, 10, 543, 1463, 1953, 5506, 7301, 7322, 12051, 12824
    },

    [C.WARLOCK] = {
        1455, 5697, 693, 1014, 5676, 698, 706, 1088, 1094, 1710, 3698, 5740
    },

    [C.DRUID] = {
        779, 783, 1066, 1430, 8925, 770, 1062, 2637, 6808, 8938, 16810, 16857, 768, 1079, 1082, 1735, 2912, 5188, 5215, 6756, 20484
    }
}

-- Everything normally trainable from level 21 through 22.
local LEVEL_22_SPELLS = {
    [C.WARRIOR] = {
        5246, 6192
    },

    [C.PALADIN] = {
        1026, 19746, 19835, 20164
    },

    [C.HUNTER] = {
        3043, 14323
    },

    [C.ROGUE] = {
        1725, 1759, 1856, 8631
    },

    [C.PRIEST] = {
        984, 2010, 2055, 2096, 8103
    },

    [C.SHAMAN] = {
        131, 8498
    },

    [C.MAGE] = {
        990, 2138, 2948, 6143, 8437
    },

    [C.WARLOCK] = {
        126, 699, 6202, 6205
    },

    [C.DRUID] = {
        2090, 2908, 5179, 5221, 8926
    }
}

-- Everything normally trainable from level 23 through 24.
local LEVEL_24_SPELLS = {
    [C.WARRIOR] = {
        1608, 5308, 6190, 6574
    },

    [C.PALADIN] = {
        5588, 5599, 10322, 10326, 19850
    },

    [C.HUNTER] = {
        1462, 14262, 19885
    },

    [C.ROGUE] = {
        2836, 6762
    },

    [C.PRIEST] = {
        1245, 3747, 8129, 15262
    },

    [C.SHAMAN] = {
        905, 939, 8046, 8155, 8160, 8181, 10399, 20609
    },

    [C.MAGE] = {
        2121, 2139, 5145, 8400, 8450, 12505
    },

    [C.WARLOCK] = {
        5138, 5500, 6223, 8288, 18867
    },

    [C.DRUID] = {
        780, 1075, 1822, 2782, 5217, 8939, 50768
    }
}

-- Core class-defining spells from level 25 through 30.
local LEVEL_30_SPELLS = {
    [C.WARRIOR] = {
        2458,  -- Berserker Stance
        20252, -- Intercept
        1464,  -- Slam
        7369   -- Cleave Rank 2
    },

    [C.PALADIN] = {
        20165, -- Seal of Light
        879,   -- Exorcism
        19742, -- Blessing of Wisdom
        20164  -- Seal of Justice
    },

    [C.HUNTER] = {
        1499,  -- Freezing Trap
        5384,  -- Feign Death
        1543,  -- Flare
        3043   -- Scorpid Sting
    },

    [C.ROGUE] = {
        408,   -- Kidney Shot
        2983,  -- Sprint
        1766,  -- Kick
        703    -- Garrote
    },

    [C.PRIEST] = {
        528,   -- Cure Disease
        8122,  -- Psychic Scream
        527,   -- Dispel Magic
        596    -- Prayer of Healing
    },

    [C.SHAMAN] = {
        8050,  -- Flame Shock
        1535,  -- Fire Nova
        3599,  -- Searing Totem
        5394,  -- Healing Stream Totem
        5675,  -- Mana Spring Totem
        8232   -- Windfury Weapon
    },

    [C.MAGE] = {
        1953,  -- Blink
        2139,  -- Counterspell
        475,   -- Remove Curse
        130,   -- Slow Fall
        759    -- Conjure Mana Gem
    },

    [C.WARLOCK] = {
        712,   -- Summon Succubus
        691,   -- Summon Felhunter
        5138,  -- Drain Mana
        1098,  -- Enslave Demon
        710    -- Banish
    },

    [C.DRUID] = {
        768,   -- Cat Form
        783,   -- Travel Form
        1066,  -- Aquatic Form
        2782,  -- Remove Curse
        2893   -- Abolish Poison
    }
}

-- Core class-defining spells from level 31 through 35.
local LEVEL_35_SPELLS = {
    [C.WARRIOR] = {
        18499, -- Berserker Rage
        6552,  -- Pummel
        7372   -- Hamstring Rank 2
    },

    [C.PALADIN] = {
        4987,  -- Cleanse
        1044,  -- Blessing of Freedom
        20216  -- Divine Favor fallback/core utility if available
    },

    [C.HUNTER] = {
        1510,  -- Volley
        14271, -- Mongoose Bite Rank 2
        14323  -- Hunter's Mark Rank 2
    },

    [C.ROGUE] = {
        2094,  -- Blind
        1856,  -- Vanish
        8647   -- Expose Armor
    },

    [C.PRIEST] = {
        1706,  -- Levitate
        9484,  -- Shackle Undead
        976    -- Shadow Protection
    },

    [C.SHAMAN] = {
        20608, -- Reincarnation
        421,   -- Chain Lightning
        8170,  -- Disease Cleansing Totem
        546    -- Water Walking
    },

    [C.MAGE] = {
        1463,  -- Mana Shield
        6143,  -- Frost Ward
        543    -- Fire Ward
    },

    [C.WARLOCK] = {
        126,   -- Eye of Kilrogg
        6229,  -- Shadow Ward
        1949   -- Hellfire
    },

    [C.DRUID] = {
        6795,  -- Growl
        5229,  -- Enrage
        5209   -- Challenging Roar
    }
}

-- Core class-defining spells from level 36 through 40.
local LEVEL_40_SPELLS = {
    [C.WARRIOR] = {
        1680,  -- Whirlwind
        871,   -- Shield Wall
        1161   -- Challenging Shout
    },

    [C.PALADIN] = {
        642,   -- Divine Shield
        750,   -- Plate Mail
        23214  -- Summon Charger fallback if available
    },

    [C.HUNTER] = {
        13161, -- Aspect of the Beast
        13813, -- Explosive Trap
        1515   -- Tame Beast fallback/core if missing
    },

    [C.ROGUE] = {
        1860,  -- Safe Fall
        1725,  -- Distract
        2836   -- Detect Traps
    },

    [C.PRIEST] = {
        2096,  -- Mind Vision
        552,   -- Abolish Disease
        1006   -- Inner Fire Rank 3
    },

    [C.SHAMAN] = {
        8177,  -- Grounding Totem
        131,   -- Water Breathing
        10595  -- Nature Resistance Totem
    },

    [C.MAGE] = {
        7302,  -- Ice Armor
        10,    -- Blizzard
        3561,  -- Teleport: Stormwind
        3562,  -- Teleport: Ironforge
        3563,  -- Teleport: Undercity
        3567   -- Teleport: Orgrimmar
    },

    [C.WARLOCK] = {
        5784,  -- Felsteed
        5484,  -- Howl of Terror
        2362   -- Create Spellstone
    },

    [C.DRUID] = {
        9634,  -- Dire Bear Form
        29166, -- Innervate
        20719  -- Feline Grace
    }
}

local function LearnSpellPack(player, spellTable, label)
    local class = player:GetClass()
    local spells = spellTable[class]

    if not spells then
        return 0
    end

    local learned = U.LearnSpells(player, spells)

    if learned > 0 then
        U.SendGuideMessage(player, "Learned " .. learned .. " " .. label .. " abilities.")
    end

    return learned
end

function Frostforge.ClassTraining.LearnLevel15ClassSpells(player)
    return LearnSpellPack(player, LEVEL_15_SPELLS, "level 15")
end

function Frostforge.ClassTraining.LearnLevel20ClassSpells(player)
    return LearnSpellPack(player, LEVEL_20_SPELLS, "level 20")
end

function Frostforge.ClassTraining.LearnLevel22ClassSpells(player)
    return LearnSpellPack(player, LEVEL_22_SPELLS, "level 22")
end

function Frostforge.ClassTraining.LearnLevel24ClassSpells(player)
    return LearnSpellPack(player, LEVEL_24_SPELLS, "level 24")
end

function Frostforge.ClassTraining.LearnLevel30ClassSpells(player)
    return LearnSpellPack(player, LEVEL_30_SPELLS, "level 30")
end

function Frostforge.ClassTraining.LearnLevel35ClassSpells(player)
    return LearnSpellPack(player, LEVEL_35_SPELLS, "level 35")
end

function Frostforge.ClassTraining.LearnLevel40ClassSpells(player)
    return LearnSpellPack(player, LEVEL_40_SPELLS, "level 40")
end

print("[Frostforge] Class training loaded.")
