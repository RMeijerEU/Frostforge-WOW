-- Frostforge Dungeon Reward Packs
-- Iconic chapter rewards for completed dungeon lore chapters.

Frostforge = Frostforge or {}
Frostforge.Rewards = Frostforge.Rewards or {}

local C = {
    WARRIOR = 1,
    PALADIN = 2,
    HUNTER = 3,
    ROGUE = 4,
    PRIEST = 5,
    SHAMAN = 7,
    MAGE = 8,
    WARLOCK = 9,
    DRUID = 11
}

-- ============================================================
-- Act I — Ragefire Chasm rewards
-- ============================================================

local RFC_CURSED_FELBLADE = 14145
local RFC_SUBTERRANEAN_CAPE = 14149
local RFC_CAVEDWELLER_BRACERS = 14147
local RFC_CHANTING_BLADE = 14151
local RFC_ROBE_OF_EVOCATION = 14150

local RFC_CLASS_REWARDS = {
    [C.WARRIOR] = {
        RFC_CURSED_FELBLADE,
        RFC_SUBTERRANEAN_CAPE,
        RFC_CAVEDWELLER_BRACERS
    },

    [C.PALADIN] = {
        RFC_CURSED_FELBLADE,
        RFC_SUBTERRANEAN_CAPE,
        RFC_CAVEDWELLER_BRACERS
    },

    [C.HUNTER] = {
        RFC_CURSED_FELBLADE,
        RFC_SUBTERRANEAN_CAPE,
        RFC_CAVEDWELLER_BRACERS
    },

    [C.ROGUE] = {
        RFC_CURSED_FELBLADE,
        RFC_SUBTERRANEAN_CAPE,
        RFC_CAVEDWELLER_BRACERS
    },

    [C.PRIEST] = {
        RFC_CHANTING_BLADE,
        RFC_ROBE_OF_EVOCATION,
        RFC_SUBTERRANEAN_CAPE
    },

    [C.SHAMAN] = {
        RFC_CHANTING_BLADE,
        RFC_ROBE_OF_EVOCATION,
        RFC_SUBTERRANEAN_CAPE
    },

    [C.MAGE] = {
        RFC_CHANTING_BLADE,
        RFC_ROBE_OF_EVOCATION,
        RFC_SUBTERRANEAN_CAPE
    },

    [C.WARLOCK] = {
        RFC_CHANTING_BLADE,
        RFC_ROBE_OF_EVOCATION,
        RFC_SUBTERRANEAN_CAPE
    },

    [C.DRUID] = {
        RFC_CHANTING_BLADE,
        RFC_ROBE_OF_EVOCATION,
        RFC_SUBTERRANEAN_CAPE
    }
}

-- ============================================================
-- Act II — Wailing Caverns rewards
-- ============================================================

local WC_MUTANT_SCALE_BREASTPLATE = 6627
local WC_DEEP_FATHOM_RING = 6463
local WC_COBRAHNS_GRASP = 6460
local WC_CRESCENT_STAFF = 6505
local WC_STINGING_VIPER = 6472
local WC_VENOMSTRIKE = 6469
local WC_WINGBLADE = 6504
local WC_ARMOR_OF_THE_FANG = 6473
local WC_FOOTPADS_OF_THE_FANG = 10411
local WC_LEGGINGS_OF_THE_FANG = 10410
local WC_SERPENT_GLOVES = 5970
local WC_SERPENTS_SHOULDERS = 5404
local WC_BELT_OF_THE_FANG = 10412
local WC_GLOVES_OF_THE_FANG = 10413
local WC_KRESHS_BACK = 13245
local WC_WORN_TURTLE_SHELL_SHIELD = 6447
local WC_SNAKESKIN_BAG = 6446
local WC_ROBE_OF_THE_MOCCASIN = 6465
local WC_SAVAGE_TRODDERS = 6459
local WC_SLIME_ENCRUSTED_PADS = 6461
local WC_GLOWING_LIZARDSCALE_CLOAK = 6449
local WC_TAIL_SPIKE = 6448
local WC_LIVING_ROOT = 6631
local WC_SEEDCLOUD_BUCKLER = 6630
local WC_SPORID_CAPE = 6629

local WC_CLASS_REWARDS = {
    [C.WARRIOR] = {
        WC_MUTANT_SCALE_BREASTPLATE,
        WC_STINGING_VIPER,
        WC_DEEP_FATHOM_RING,
        WC_KRESHS_BACK,
        WC_WORN_TURTLE_SHELL_SHIELD,
        WC_COBRAHNS_GRASP
    },

    [C.PALADIN] = {
        WC_MUTANT_SCALE_BREASTPLATE,
        WC_WINGBLADE,
        WC_DEEP_FATHOM_RING,
        WC_SEEDCLOUD_BUCKLER,
        WC_COBRAHNS_GRASP
    },

    [C.HUNTER] = {
        WC_VENOMSTRIKE,
        WC_GLOWING_LIZARDSCALE_CLOAK,
        WC_FOOTPADS_OF_THE_FANG,
        WC_BELT_OF_THE_FANG,
        WC_GLOVES_OF_THE_FANG,
        WC_SERPENTS_SHOULDERS,
        WC_DEEP_FATHOM_RING,
        WC_TAIL_SPIKE,
        WC_SNAKESKIN_BAG
    },

    [C.ROGUE] = {
        WC_STINGING_VIPER,
        WC_TAIL_SPIKE,
        WC_ARMOR_OF_THE_FANG,
        WC_LEGGINGS_OF_THE_FANG,
        WC_FOOTPADS_OF_THE_FANG,
        WC_BELT_OF_THE_FANG,
        WC_GLOVES_OF_THE_FANG,
        WC_SERPENTS_SHOULDERS,
        WC_DEEP_FATHOM_RING,
        WC_GLOWING_LIZARDSCALE_CLOAK,
        WC_SNAKESKIN_BAG
    },

    [C.PRIEST] = {
        WC_CRESCENT_STAFF,
        WC_DEEP_FATHOM_RING,
        WC_SERPENT_GLOVES,
        WC_ROBE_OF_THE_MOCCASIN,
        WC_SLIME_ENCRUSTED_PADS,
        WC_SPORID_CAPE,
        WC_LIVING_ROOT,
        WC_SNAKESKIN_BAG
    },

    [C.SHAMAN] = {
        WC_CRESCENT_STAFF,
        WC_DEEP_FATHOM_RING,
        WC_SERPENT_GLOVES,
        WC_SEEDCLOUD_BUCKLER,
        WC_COBRAHNS_GRASP,
        WC_LIVING_ROOT,
        WC_SPORID_CAPE,
        WC_SNAKESKIN_BAG
    },

    [C.MAGE] = {
        WC_CRESCENT_STAFF,
        WC_DEEP_FATHOM_RING,
        WC_SERPENT_GLOVES,
        WC_ROBE_OF_THE_MOCCASIN,
        WC_SLIME_ENCRUSTED_PADS,
        WC_SPORID_CAPE,
        WC_LIVING_ROOT,
        WC_SNAKESKIN_BAG
    },

    [C.WARLOCK] = {
        WC_CRESCENT_STAFF,
        WC_DEEP_FATHOM_RING,
        WC_SERPENT_GLOVES,
        WC_ROBE_OF_THE_MOCCASIN,
        WC_SLIME_ENCRUSTED_PADS,
        WC_SPORID_CAPE,
        WC_LIVING_ROOT,
        WC_SNAKESKIN_BAG
    },

    [C.DRUID] = {
        WC_ARMOR_OF_THE_FANG,
        WC_LEGGINGS_OF_THE_FANG,
        WC_FOOTPADS_OF_THE_FANG,
        WC_BELT_OF_THE_FANG,
        WC_GLOVES_OF_THE_FANG,
        WC_SERPENTS_SHOULDERS,
        WC_LIVING_ROOT,
        WC_DEEP_FATHOM_RING,
        WC_SPORID_CAPE,
        WC_SNAKESKIN_BAG
    }
}

-- ============================================================
-- Act III — Deadmines rewards
-- ============================================================

local DM_CAPE_OF_THE_BROTHERHOOD = 5193
local DM_BLACKENED_DEFIAS_ARMOR = 10399
local DM_CORSAIRS_OVERSHIRT = 5202
local DM_CRUEL_BARB = 5191
local DM_EMBERSTONE_STAFF = 5201
local DM_SMITES_MIGHTY_HAMMER = 7230
local DM_TASKMASTER_AXE = 5194
local DM_BLACKENED_DEFIAS_BELT = 10403
local DM_COOKIES_STIRRING_ROD = 5198
local DM_LAVISHLY_JEWELED_RING = 1156
local DM_COOKIES_TENDERIZER = 5197
local DM_RHAHKZORS_HAMMER = 5187
local DM_MINERS_CAPE = 5444
local DM_BLACKENED_DEFIAS_BOOTS = 10402
local DM_BLACKENED_DEFIAS_GLOVES = 10401
local DM_BLACKENED_DEFIAS_LEGGINGS = 10400
local DM_DEFIAS_RAPIER = 1925
local DM_RED_DEFIAS_MASK = 5106

local DM_IMPALING_HARPOON = 5200
local DM_SMELTING_PANTS = 5199
local DM_SMITES_REAVER = 5196
local DM_THIEFS_BLADE = 5192
local DM_ROCKSLICER = 872
local DM_GOLD_FLECKED_GLOVES = 5195
local DM_BUZZ_SAW = 1937
local DM_BUZZER_BLADE = 2169

-- Deadmines / Westfall quest rewards
local DM_CHAUSSES_OF_WESTFALL = 6087
local DM_TUNIC_OF_WESTFALL = 2041
local DM_STAFF_OF_WESTFALL = 2042

local DM_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {DM_SMITES_MIGHTY_HAMMER},
        {DM_TASKMASTER_AXE},
        {DM_CAPE_OF_THE_BROTHERHOOD},
        {DM_CHAUSSES_OF_WESTFALL}
    },

    [C.PALADIN] = {
        {DM_SMITES_MIGHTY_HAMMER},
        {DM_TASKMASTER_AXE},
        {DM_TUNIC_OF_WESTFALL},
        {DM_CHAUSSES_OF_WESTFALL}
    },

    [C.HUNTER] = {
        {DM_CAPE_OF_THE_BROTHERHOOD},
        {DM_TASKMASTER_AXE},
        {DM_CRUEL_BARB},
        {DM_CHAUSSES_OF_WESTFALL}
    },

    [C.ROGUE] = {
        {DM_BLACKENED_DEFIAS_ARMOR},
        {DM_BLACKENED_DEFIAS_BELT},
        {DM_BLACKENED_DEFIAS_BOOTS},
        {DM_BLACKENED_DEFIAS_GLOVES},
        {DM_BLACKENED_DEFIAS_LEGGINGS},
        {DM_RED_DEFIAS_MASK},
        {DM_CRUEL_BARB}
    },

    [C.PRIEST] = {
        {DM_STAFF_OF_WESTFALL},
        {DM_EMBERSTONE_STAFF},
        {DM_LAVISHLY_JEWELED_RING},
        {DM_COOKIES_STIRRING_ROD},
        {DM_CORSAIRS_OVERSHIRT}
    },

    [C.SHAMAN] = {
        {DM_STAFF_OF_WESTFALL},
        {DM_EMBERSTONE_STAFF},
        {DM_LAVISHLY_JEWELED_RING},
        {DM_CHAUSSES_OF_WESTFALL}
    },

    [C.MAGE] = {
        {DM_STAFF_OF_WESTFALL},
        {DM_EMBERSTONE_STAFF},
        {DM_LAVISHLY_JEWELED_RING},
        {DM_COOKIES_STIRRING_ROD},
        {DM_CORSAIRS_OVERSHIRT}
    },

    [C.WARLOCK] = {
        {DM_STAFF_OF_WESTFALL},
        {DM_EMBERSTONE_STAFF},
        {DM_LAVISHLY_JEWELED_RING},
        {DM_COOKIES_STIRRING_ROD},
        {DM_CORSAIRS_OVERSHIRT}
    },

    [C.DRUID] = {
        {DM_STAFF_OF_WESTFALL},
        {DM_EMBERSTONE_STAFF},
        {DM_LAVISHLY_JEWELED_RING},
        {DM_TUNIC_OF_WESTFALL},
        {DM_CHAUSSES_OF_WESTFALL}
    }
}

-- Stockades rewards
local ST_AMBASSADORS_BOOTS = 2033
local ST_DARKSHIRE_MAIL_LEGGINGS = 2906
local ST_IRON_KNUCKLES = 2942
local ST_PRISON_SHANK = 2941
local ST_JIMMIED_HANDCUFFS = 3228
local ST_KAMS_WALKING_STICK = 2280

local STOCKADES_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {ST_DARKSHIRE_MAIL_LEGGINGS},
        {ST_JIMMIED_HANDCUFFS},
        {ST_IRON_KNUCKLES}
    },

    [C.PALADIN] = {
        {ST_DARKSHIRE_MAIL_LEGGINGS},
        {ST_JIMMIED_HANDCUFFS},
        {ST_IRON_KNUCKLES}
    },

    [C.HUNTER] = {
        {ST_AMBASSADORS_BOOTS},
        {ST_PRISON_SHANK},
        {ST_JIMMIED_HANDCUFFS}
    },

    [C.ROGUE] = {
        {ST_PRISON_SHANK},
        {ST_AMBASSADORS_BOOTS},
        {ST_IRON_KNUCKLES}
    },

    [C.PRIEST] = {
        {ST_KAMS_WALKING_STICK},
        {ST_AMBASSADORS_BOOTS}
    },

    [C.SHAMAN] = {
        {ST_KAMS_WALKING_STICK},
        {ST_JIMMIED_HANDCUFFS},
        {ST_DARKSHIRE_MAIL_LEGGINGS}
    },

    [C.MAGE] = {
        {ST_KAMS_WALKING_STICK},
        {ST_AMBASSADORS_BOOTS}
    },

    [C.WARLOCK] = {
        {ST_KAMS_WALKING_STICK},
        {ST_AMBASSADORS_BOOTS}
    },

    [C.DRUID] = {
        {ST_KAMS_WALKING_STICK},
        {ST_AMBASSADORS_BOOTS},
        {ST_PRISON_SHANK}
    }
}

-- ============================================================
-- Act IV — Shadowfang Keep rewards
-- ============================================================

local SFK_ASSASSINS_BLADE = 1935
local SFK_SHADOWFANG = 1482
local SFK_FACE_SMASHER = 1483
local SFK_GUILLOTINE_AXE = 2807
local SFK_FELINE_MANTLE = 3748
local SFK_WOLFMASTER_CAPE = 6314
local SFK_EERIE_STABLE_LANTERN = 6341
local SFK_SILVERLAINES_FAMILY_SEAL = 6321
local SFK_BARONS_SCEPTER = 6323
local SFK_ROBES_OF_ARUGAL = 6324
local SFK_BELT_OF_ARUGAL = 6392
local SFK_HAUNTING_BLADE = 6641

local SFK_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {SFK_FACE_SMASHER},
        {SFK_GUILLOTINE_AXE},
        {SFK_WOLFMASTER_CAPE},
        {SFK_SILVERLAINES_FAMILY_SEAL}
    },

    [C.PALADIN] = {
        {SFK_FACE_SMASHER},
        {SFK_GUILLOTINE_AXE},
        {SFK_WOLFMASTER_CAPE},
        {SFK_SILVERLAINES_FAMILY_SEAL}
    },

    [C.HUNTER] = {
        {SFK_GUILLOTINE_AXE},
        {SFK_WOLFMASTER_CAPE},
        {SFK_SILVERLAINES_FAMILY_SEAL}
    },

    [C.ROGUE] = {
        {SFK_ASSASSINS_BLADE},
        {SFK_SHADOWFANG},
        {SFK_HAUNTING_BLADE},
        {SFK_WOLFMASTER_CAPE}
    },

    [C.PRIEST] = {
        {SFK_ROBES_OF_ARUGAL},
        {SFK_BELT_OF_ARUGAL},
        {SFK_BARONS_SCEPTER},
        {SFK_EERIE_STABLE_LANTERN}
    },

    [C.SHAMAN] = {
        {SFK_FELINE_MANTLE},
        {SFK_WOLFMASTER_CAPE},
        {SFK_SILVERLAINES_FAMILY_SEAL},
        {SFK_BARONS_SCEPTER}
    },

    [C.MAGE] = {
        {SFK_ROBES_OF_ARUGAL},
        {SFK_BELT_OF_ARUGAL},
        {SFK_BARONS_SCEPTER},
        {SFK_EERIE_STABLE_LANTERN}
    },

    [C.WARLOCK] = {
        {SFK_ROBES_OF_ARUGAL},
        {SFK_BELT_OF_ARUGAL},
        {SFK_BARONS_SCEPTER},
        {SFK_EERIE_STABLE_LANTERN}
    },

    [C.DRUID] = {
        {SFK_FELINE_MANTLE},
        {SFK_WOLFMASTER_CAPE},
        {SFK_SILVERLAINES_FAMILY_SEAL},
        {SFK_BARONS_SCEPTER}
    }
}

-- ============================================================
-- Act V — Blackfathom Deeps rewards
-- ============================================================

local BFD_GRAVESTONE_SCEPTER = 7001
local BFD_OUTLAWS_SABRE = 16886
local BFD_SHIMMERING_CLOAK = 6564
local BFD_GRASSLAND_SASH = 6477
local BFD_BITE_OF_SERRA_KIS = 6904
local BFD_STRIKE_OF_THE_HYDRA = 6909
local BFD_ROD_OF_THE_SLEEPWALKER = 1155
local BFD_MOSS_CINCH = 6911
local BFD_REEF_AXE = 6905
local BFD_TORTOISE_ARMOR = 6907
local BFD_ALGAE_FISTS = 6906
local BFD_BLACK_WATER_HAMMER = 4511

local BFD_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {BFD_STRIKE_OF_THE_HYDRA},
        {BFD_REEF_AXE},
        {BFD_TORTOISE_ARMOR}
    },

    [C.PALADIN] = {
        {BFD_STRIKE_OF_THE_HYDRA},
        {BFD_BLACK_WATER_HAMMER},
        {BFD_TORTOISE_ARMOR}
    },

    [C.HUNTER] = {
        {BFD_REEF_AXE},
        {BFD_GRASSLAND_SASH},
        {BFD_MOSS_CINCH}
    },

    [C.ROGUE] = {
        {BFD_OUTLAWS_SABRE},
        {BFD_BITE_OF_SERRA_KIS},
        {BFD_GRASSLAND_SASH}
    },

    [C.PRIEST] = {
        {BFD_GRAVESTONE_SCEPTER},
        {BFD_ROD_OF_THE_SLEEPWALKER},
        {BFD_SHIMMERING_CLOAK}
    },

    [C.SHAMAN] = {
        {BFD_BLACK_WATER_HAMMER},
        {BFD_GRAVESTONE_SCEPTER},
        {BFD_ALGAE_FISTS}
    },

    [C.MAGE] = {
        {BFD_GRAVESTONE_SCEPTER},
        {BFD_ROD_OF_THE_SLEEPWALKER},
        {BFD_SHIMMERING_CLOAK}
    },

    [C.WARLOCK] = {
        {BFD_GRAVESTONE_SCEPTER},
        {BFD_ROD_OF_THE_SLEEPWALKER},
        {BFD_SHIMMERING_CLOAK}
    },

    [C.DRUID] = {
        {BFD_ROD_OF_THE_SLEEPWALKER},
        {BFD_GRASSLAND_SASH},
        {BFD_MOSS_CINCH}
    }
}

-- ============================================================
-- Act VI — Gnomeregan rewards
-- ============================================================

local GNOMER_TRIPRUNNER_DUNGAREES = 9624
local GNOMER_ELECTROMAGNETIC_GIGAFLOX_REACTIVATOR = 9492
local GNOMER_MANUAL_CROWD_PUMMELER = 9449
local GNOMER_THERMAPLUGGS_CENTRAL_CORE = 9458
local GNOMER_HYDROCANE = 9452
local GNOMER_GIZMOTRON_MEGA_CHOPPER = 9490
local GNOMER_PAPAHS_BRAND_NEW_BAG = 9587
local GNOMER_CIVINADS_WATERPROOF_BOOTIES = 9623
local GNOMER_ACIDIC_WALKERS = 9454
local GNOMER_TOXIC_REVENGER = 9453
local GNOMER_THE_JACKHAMMER = 9423
local GNOMER_GLASS_SHOOTER = 9456
local GNOMER_HI_TECH_SUPERGUN = 9487
local GNOMER_SUPERCHARGER_BATTLE_AXE = 9486
local GNOMER_GRIME_ENCRUSTED_RING = 9538

local GNOMER_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {GNOMER_MANUAL_CROWD_PUMMELER},
        {GNOMER_SUPERCHARGER_BATTLE_AXE},
        {GNOMER_GRIME_ENCRUSTED_RING}
    },

    [C.PALADIN] = {
        {GNOMER_MANUAL_CROWD_PUMMELER},
        {GNOMER_THERMAPLUGGS_CENTRAL_CORE},
        {GNOMER_GRIME_ENCRUSTED_RING}
    },

    [C.HUNTER] = {
        {GNOMER_HI_TECH_SUPERGUN},
        {GNOMER_GLASS_SHOOTER},
        {GNOMER_TRIPRUNNER_DUNGAREES}
    },

    [C.ROGUE] = {
        {GNOMER_TOXIC_REVENGER},
        {GNOMER_GIZMOTRON_MEGA_CHOPPER},
        {GNOMER_TRIPRUNNER_DUNGAREES}
    },

    [C.PRIEST] = {
        {GNOMER_ELECTROMAGNETIC_GIGAFLOX_REACTIVATOR},
        {GNOMER_HYDROCANE},
        {GNOMER_CIVINADS_WATERPROOF_BOOTIES}
    },

    [C.SHAMAN] = {
        {GNOMER_MANUAL_CROWD_PUMMELER},
        {GNOMER_THERMAPLUGGS_CENTRAL_CORE},
        {GNOMER_ACIDIC_WALKERS}
    },

    [C.MAGE] = {
        {GNOMER_ELECTROMAGNETIC_GIGAFLOX_REACTIVATOR},
        {GNOMER_HYDROCANE},
        {GNOMER_CIVINADS_WATERPROOF_BOOTIES}
    },

    [C.WARLOCK] = {
        {GNOMER_ELECTROMAGNETIC_GIGAFLOX_REACTIVATOR},
        {GNOMER_HYDROCANE},
        {GNOMER_CIVINADS_WATERPROOF_BOOTIES}
    },

    [C.DRUID] = {
        {GNOMER_MANUAL_CROWD_PUMMELER},
        {GNOMER_TRIPRUNNER_DUNGAREES},
        {GNOMER_ACIDIC_WALKERS}
    }
}

-- ============================================================
-- Act VII — Razorfen Kraul rewards
-- ============================================================

local RFK_CORPSEMAKER = 6687
local RFK_PRONGED_REAVER = 6692
local RFK_RAGING_BERSERKERS_HELM = 7719
local RFK_SWINE_FISTS = 6697
local RFK_TUSKEN_HELM = 6686
local RFK_AGAMAGGANS_CLUTCH = 6693
local RFK_HEART_OF_AGAMAGGAN = 6694
local RFK_DEATHS_HEAD_VESTMENT = 6682
local RFK_STYGIAN_BONE_AMULET = 6695
local RFK_NIGHTSTALKER_BOW = 6696
local RFK_BATWING_MANTLE = 6697
local RFK_THORN_SPIKE = 6681

local RFK_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {RFK_CORPSEMAKER},
        {RFK_TUSKEN_HELM},
        {RFK_HEART_OF_AGAMAGGAN}
    },

    [C.PALADIN] = {
        {RFK_CORPSEMAKER},
        {RFK_TUSKEN_HELM},
        {RFK_HEART_OF_AGAMAGGAN}
    },

    [C.HUNTER] = {
        {RFK_PRONGED_REAVER},
        {RFK_AGAMAGGANS_CLUTCH},
        {RFK_NIGHTSTALKER_BOW}
    },

    [C.ROGUE] = {
        {RFK_SWINE_FISTS},
        {RFK_AGAMAGGANS_CLUTCH},
        {RFK_THORN_SPIKE}
    },

    [C.PRIEST] = {
        {RFK_DEATHS_HEAD_VESTMENT},
        {RFK_BATWING_MANTLE},
        {RFK_STYGIAN_BONE_AMULET}
    },

    [C.SHAMAN] = {
        {RFK_CORPSEMAKER},
        {RFK_HEART_OF_AGAMAGGAN},
        {RFK_STYGIAN_BONE_AMULET}
    },

    [C.MAGE] = {
        {RFK_DEATHS_HEAD_VESTMENT},
        {RFK_BATWING_MANTLE},
        {RFK_STYGIAN_BONE_AMULET}
    },

    [C.WARLOCK] = {
        {RFK_DEATHS_HEAD_VESTMENT},
        {RFK_BATWING_MANTLE},
        {RFK_STYGIAN_BONE_AMULET}
    },

    [C.DRUID] = {
        {RFK_DEATHS_HEAD_VESTMENT},
        {RFK_AGAMAGGANS_CLUTCH},
        {RFK_HEART_OF_AGAMAGGAN}
    }
}

-- ============================================================
-- Act VIII-XI — Scarlet Monastery rewards
-- ============================================================

local SM_BLOODMAGE_MANTLE = 7684
local SM_MORBID_DAWN = 7689
local SM_IRONSPINE_EYE = 7686
local SM_EBON_VISE = 7690
local SM_DOANS_ROBE = 7711
local SM_DOANS_MANTLE = 7712
local SM_ILLUSIONARY_ROD = 7713
local SM_HYPNOTIC_BLADE = 7714
local SM_RAVAGER = 7717
local SM_HERODS_SHOULDER = 7718
local SM_SCARLET_LEGGINGS = 10330
local SM_AEGIS_OF_THE_SCARLET_COMMANDER = 7726
local SM_MOGRaines_MIGHT = 7723
local SM_WHITEMANES_CHAPEAU = 7720
local SM_HAND_OF_RIGHTEOUSNESS = 7721
local SM_TRIUNE_AMULET = 7722
local SM_BEGUILER_ROBES = 7728
local SM_SCARLET_CHESTPIECE = 10328
local SM_SCARLET_BELT = 10329
local SM_SCARLET_BOOTS = 10332
local SM_SCARLET_WRISTGUARDS = 10333
local SM_SCARLET_GAUNTLETS = 10331

local SM_GY_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {SM_MORBID_DAWN},
        {SM_IRONSPINE_EYE}
    },

    [C.PALADIN] = {
        {SM_MORBID_DAWN},
        {SM_IRONSPINE_EYE}
    },

    [C.HUNTER] = {
        {SM_EBON_VISE},
        {SM_IRONSPINE_EYE}
    },

    [C.ROGUE] = {
        {SM_EBON_VISE},
        {SM_IRONSPINE_EYE}
    },

    [C.PRIEST] = {
        {SM_BLOODMAGE_MANTLE},
        {SM_IRONSPINE_EYE}
    },

    [C.SHAMAN] = {
        {SM_MORBID_DAWN},
        {SM_BLOODMAGE_MANTLE}
    },

    [C.MAGE] = {
        {SM_BLOODMAGE_MANTLE},
        {SM_IRONSPINE_EYE}
    },

    [C.WARLOCK] = {
        {SM_BLOODMAGE_MANTLE},
        {SM_IRONSPINE_EYE}
    },

    [C.DRUID] = {
        {SM_BLOODMAGE_MANTLE},
        {SM_EBON_VISE}
    }
}

local SM_LIB_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {SM_HYPNOTIC_BLADE},
        {SM_DOANS_MANTLE}
    },

    [C.PALADIN] = {
        {SM_HYPNOTIC_BLADE},
        {SM_DOANS_MANTLE}
    },

    [C.HUNTER] = {
        {SM_HYPNOTIC_BLADE},
        {SM_DOANS_MANTLE}
    },

    [C.ROGUE] = {
        {SM_HYPNOTIC_BLADE},
        {SM_DOANS_MANTLE}
    },

    [C.PRIEST] = {
        {SM_ILLUSIONARY_ROD},
        {SM_DOANS_ROBE},
        {SM_DOANS_MANTLE}
    },

    [C.SHAMAN] = {
        {SM_ILLUSIONARY_ROD},
        {SM_DOANS_MANTLE}
    },

    [C.MAGE] = {
        {SM_ILLUSIONARY_ROD},
        {SM_DOANS_ROBE},
        {SM_DOANS_MANTLE}
    },

    [C.WARLOCK] = {
        {SM_ILLUSIONARY_ROD},
        {SM_DOANS_ROBE},
        {SM_DOANS_MANTLE}
    },

    [C.DRUID] = {
        {SM_ILLUSIONARY_ROD},
        {SM_DOANS_MANTLE}
    }
}

local SM_ARMORY_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {SM_RAVAGER},
        {SM_HERODS_SHOULDER},
        {SM_SCARLET_LEGGINGS}
    },

    [C.PALADIN] = {
        {SM_RAVAGER},
        {SM_HERODS_SHOULDER},
        {SM_SCARLET_LEGGINGS}
    },

    [C.HUNTER] = {
        {SM_RAVAGER},
        {SM_HERODS_SHOULDER},
        {SM_SCARLET_LEGGINGS}
    },

    [C.ROGUE] = {
        {SM_HERODS_SHOULDER},
        {SM_SCARLET_LEGGINGS}
    },

    [C.PRIEST] = {
        {SM_HERODS_SHOULDER}
    },

    [C.SHAMAN] = {
        {SM_RAVAGER},
        {SM_HERODS_SHOULDER}
    },

    [C.MAGE] = {
        {SM_HERODS_SHOULDER}
    },

    [C.WARLOCK] = {
        {SM_HERODS_SHOULDER}
    },

    [C.DRUID] = {
        {SM_HERODS_SHOULDER},
        {SM_SCARLET_LEGGINGS}
    }
}

local SM_CATHEDRAL_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {SM_AEGIS_OF_THE_SCARLET_COMMANDER},
        {SM_MOGRaines_MIGHT},
        {SM_SCARLET_CHESTPIECE},
        {SM_SCARLET_BELT},
        {SM_SCARLET_BOOTS},
        {SM_SCARLET_WRISTGUARDS},
        {SM_SCARLET_GAUNTLETS}
    },

    [C.PALADIN] = {
        {SM_AEGIS_OF_THE_SCARLET_COMMANDER},
        {SM_MOGRaines_MIGHT},
        {SM_HAND_OF_RIGHTEOUSNESS},
        {SM_SCARLET_CHESTPIECE},
        {SM_SCARLET_BELT},
        {SM_SCARLET_BOOTS},
        {SM_SCARLET_WRISTGUARDS},
        {SM_SCARLET_GAUNTLETS}
    },

    [C.HUNTER] = {
        {SM_MOGRaines_MIGHT},
        {SM_TRIUNE_AMULET},
        {SM_SCARLET_CHESTPIECE},
        {SM_SCARLET_BELT},
        {SM_SCARLET_BOOTS},
        {SM_SCARLET_WRISTGUARDS},
        {SM_SCARLET_GAUNTLETS}
    },

    [C.ROGUE] = {
        {SM_HYPNOTIC_BLADE},
        {SM_TRIUNE_AMULET},
        {SM_SCARLET_BELT},
        {SM_SCARLET_BOOTS},
        {SM_SCARLET_WRISTGUARDS},
        {SM_SCARLET_GAUNTLETS}
    },

    [C.PRIEST] = {
        {SM_WHITEMANES_CHAPEAU},
        {SM_HAND_OF_RIGHTEOUSNESS},
        {SM_TRIUNE_AMULET},
        {SM_BEGUILER_ROBES}
    },

    [C.SHAMAN] = {
        {SM_HAND_OF_RIGHTEOUSNESS},
        {SM_TRIUNE_AMULET},
        {SM_AEGIS_OF_THE_SCARLET_COMMANDER}
    },

    [C.MAGE] = {
        {SM_WHITEMANES_CHAPEAU},
        {SM_HAND_OF_RIGHTEOUSNESS},
        {SM_TRIUNE_AMULET},
        {SM_BEGUILER_ROBES}
    },

    [C.WARLOCK] = {
        {SM_WHITEMANES_CHAPEAU},
        {SM_HAND_OF_RIGHTEOUSNESS},
        {SM_TRIUNE_AMULET},
        {SM_BEGUILER_ROBES}
    },

    [C.DRUID] = {
        {SM_WHITEMANES_CHAPEAU},
        {SM_HAND_OF_RIGHTEOUSNESS},
        {SM_TRIUNE_AMULET},
        {SM_BEGUILER_ROBES}
    }
}

-- ============================================================
-- Act XII — Uldaman rewards
-- ============================================================

local ULD_ARCHAEDIC_SHARD = 9417
local ULD_ARCHAEDIC_STONE = 11118
local ULD_STONESLAYER = 9418
local ULD_ROCKPOUNDER = 9413
local ULD_GRIMLOKS_CHARGE = 9416
local ULD_GALGANNS_FIREBLASTER = 9412
local ULD_GALGANNS_FIREHAMMER = 9419
local ULD_GRIMLOKS_TRIBAL_VESTMENTS = 9415
local ULD_OILSKIN_LEGGINGS = 9414
local ULD_ROCKSHARD_PAULDRONS = 9411
local ULD_CRAGFISTS = 9410
local ULD_MINERS_HAT_OF_THE_DEEP = 9429
local ULD_SPAULDERS_OF_A_LOST_AGE = 9430
local ULD_FORGOTTEN_WRAPS = 9433
local ULD_THE_JACKHAMMER = 9423
local ULD_PENDULUM_OF_DOOM = 9425

local ULDAMAN_CLASS_REWARDS = {
    [C.WARRIOR] = {
        {ULD_PENDULUM_OF_DOOM},
        {ULD_STONESLAYER},
        {ULD_ROCKPOUNDER},
        {ULD_CRAGFISTS},
        {ULD_ARCHAEDIC_STONE}
    },

    [C.PALADIN] = {
        {ULD_STONESLAYER},
        {ULD_ROCKPOUNDER},
        {ULD_CRAGFISTS},
        {ULD_ARCHAEDIC_STONE}
    },

    [C.HUNTER] = {
        {ULD_GALGANNS_FIREBLASTER},
        {ULD_GRIMLOKS_CHARGE},
        {ULD_ROCKSHARD_PAULDRONS},
        {ULD_ARCHAEDIC_STONE}
    },

    [C.ROGUE] = {
        {ULD_ARCHAEDIC_SHARD},
        {ULD_OILSKIN_LEGGINGS},
        {ULD_FORGOTTEN_WRAPS},
        {ULD_ARCHAEDIC_STONE}
    },

    [C.PRIEST] = {
        {ULD_GRIMLOKS_TRIBAL_VESTMENTS},
        {ULD_ARCHAEDIC_SHARD},
        {ULD_MINERS_HAT_OF_THE_DEEP},
        {ULD_ARCHAEDIC_STONE}
    },

    [C.SHAMAN] = {
        {ULD_GALGANNS_FIREHAMMER},
        {ULD_GRIMLOKS_TRIBAL_VESTMENTS},
        {ULD_ROCKSHARD_PAULDRONS},
        {ULD_ARCHAEDIC_STONE}
    },

    [C.MAGE] = {
        {ULD_GRIMLOKS_TRIBAL_VESTMENTS},
        {ULD_ARCHAEDIC_SHARD},
        {ULD_MINERS_HAT_OF_THE_DEEP},
        {ULD_ARCHAEDIC_STONE}
    },

    [C.WARLOCK] = {
        {ULD_GRIMLOKS_TRIBAL_VESTMENTS},
        {ULD_ARCHAEDIC_SHARD},
        {ULD_MINERS_HAT_OF_THE_DEEP},
        {ULD_ARCHAEDIC_STONE}
    },

    [C.DRUID] = {
        {ULD_GRIMLOKS_TRIBAL_VESTMENTS},
        {ULD_OILSKIN_LEGGINGS},
        {ULD_SPAULDERS_OF_A_LOST_AGE},
        {ULD_ARCHAEDIC_STONE}
    }
}

function Frostforge.Rewards.GiveUldamanClassReward(player)
    Frostforge.Rewards.GiveDungeonClassReward(player, ULDAMAN_CLASS_REWARDS, "Uldaman")
end

-- ============================================================
-- Reward helpers
-- ============================================================

local function GiveItemSafe(player, itemId, count)
    if not itemId then
        return
    end

    if type(itemId) == "table" then
        local nestedItemId = itemId[1]
        local nestedCount = itemId[2] or count or 1

        if nestedItemId and nestedItemId > 0 then
            player:AddItem(nestedItemId, nestedCount)
        end

        return
    end

    if itemId <= 0 then
        return
    end

    player:AddItem(itemId, count or 1)
end

function Frostforge.Rewards.GiveDungeonRewardPack(player, rewardTable, chapterName)
    if not player or not rewardTable then
        return
    end

    local class = player:GetClass()
    local rewards = rewardTable[class]

    if not rewards then
        player:SendBroadcastMessage("|cff66ccffFrostforge:|r No reward pack configured for your class for " .. chapterName .. ".")
        return
    end

    for _, itemData in ipairs(rewards) do
        GiveItemSafe(player, itemData, 1)
    end

    player:SendBroadcastMessage("|cff66ccffFrostforge:|r " .. chapterName .. " reward pack added.")
end

function Frostforge.Rewards.GiveDungeonClassReward(player, rewardTable, chapterName)
    Frostforge.Rewards.GiveDungeonRewardPack(player, rewardTable, chapterName)
end

function Frostforge.Rewards.GiveRFCClassReward(player)
    Frostforge.Rewards.GiveDungeonRewardPack(player, RFC_CLASS_REWARDS, "Ragefire Chasm")
end

function Frostforge.Rewards.GiveWCClassReward(player)
    Frostforge.Rewards.GiveDungeonRewardPack(player, WC_CLASS_REWARDS, "Wailing Caverns")
end

function Frostforge.Rewards.GiveDMClassReward(player)
    Frostforge.Rewards.GiveDungeonRewardPack(player, DM_CLASS_REWARDS, "The Deadmines")
end

function Frostforge.Rewards.GiveStockadesClassReward(player)
    Frostforge.Rewards.GiveDungeonClassReward(player, STOCKADES_CLASS_REWARDS, "The Stockades")
end

function Frostforge.Rewards.GiveSFKClassReward(player)
    Frostforge.Rewards.GiveDungeonClassReward(player, SFK_CLASS_REWARDS, "Shadowfang Keep")
end

function Frostforge.Rewards.GiveBFDClassReward(player)
    Frostforge.Rewards.GiveDungeonClassReward(player, BFD_CLASS_REWARDS, "Blackfathom Deeps")
end

function Frostforge.Rewards.GiveGnomerClassReward(player)
    Frostforge.Rewards.GiveDungeonClassReward(player, GNOMER_CLASS_REWARDS, "Gnomeregan")
end

function Frostforge.Rewards.GiveRFKClassReward(player)
    Frostforge.Rewards.GiveDungeonClassReward(player, RFK_CLASS_REWARDS, "Razorfen Kraul")
end

function Frostforge.Rewards.GiveSMGraveyardClassReward(player)
    Frostforge.Rewards.GiveDungeonClassReward(player, SM_GY_CLASS_REWARDS, "Scarlet Monastery: Graveyard")
end

function Frostforge.Rewards.GiveSMLibraryClassReward(player)
    Frostforge.Rewards.GiveDungeonClassReward(player, SM_LIB_CLASS_REWARDS, "Scarlet Monastery: Library")
end

function Frostforge.Rewards.GiveSMArmoryClassReward(player)
    Frostforge.Rewards.GiveDungeonClassReward(player, SM_ARMORY_CLASS_REWARDS, "Scarlet Monastery: Armory")
end

function Frostforge.Rewards.GiveSMCathedralClassReward(player)
    Frostforge.Rewards.GiveDungeonClassReward(player, SM_CATHEDRAL_CLASS_REWARDS, "Scarlet Monastery: Cathedral")
end

print("[Frostforge] Dungeon rewards loaded.")
