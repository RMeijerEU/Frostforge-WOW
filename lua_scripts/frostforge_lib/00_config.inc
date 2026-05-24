-- Frostforge shared config

Frostforge = Frostforge or {}

Frostforge.NPC = {
    GUIDE = 900010,
    ELDRIN = 900011,

    ORG_GRUNT = 900020,
    ORG_SHAMAN = 900021,
    ORG_GUARD = 900022,

    WC_CROSSROADS_SCOUT = 900030,
    WC_DRUIDIC_ADEPT = 900031,
    WC_BARRENS_WATCHER = 900032,

    DEF_WESTFALL_FARMER = 900040,
    DEF_STORMWIND_MARSHAL = 900041,
    DEF_DEFIAS_INFORMANT = 900042,
    DEF_SI7_AGENT = 900043,

    -- Act III Part 2 — Stockades NPCs
    ST_STORMWIND_INFORMANT = 900044,
    ST_PRISON_WARDEN = 900045,
    ST_DEFIAS_PRISONER = 900046,

    -- Act IV — Shadowfang Keep NPCs
    FORSAKEN_SCOUT = 900047,
    GILNEAN_REFUGEE = 900048,

    -- Act V — Blackfathom Deeps NPCs
    BFD_TWILIGHT_ACOLYTE = 900049,
    BFD_ZORAM_SCOUT = 900050,

    -- Act VI — Gnomeregan NPCs
    GNOMER_GNOME_SURVIVOR = 900051,
    GNOMER_IRRADIATED_TECHNICIAN = 900052,

    -- Act VII — Razorfen Kraul NPCs
    RFK_BARRENS_MESSENGER = 900053,
    RFK_QUILBOAR_CAPTIVE = 900054,

    -- Act VIII-XI — Scarlet Monastery NPCs
    SM_SCARLET_DEFECTOR = 900055,
    SM_FORSAKEN_OBSERVER = 900056,
    SM_SOUTHSHORE_SCOUT = 900057,
    SM_TARREN_MILL_APOTHECARY = 900058,
    SM_HILLSBRAD_REFUGEE = 900059,

    -- Act XII — Uldaman
    ULDAMAN_RELIQUARY_EXPLORER = 900060,
    ULDAMAN_STONEWATCHER = 900061,
}

Frostforge.Quest = {
    WELCOME = 900100,
    STARTER_GEAR = 900101,
    ORGRIMMAR = 900102,
    GROUP = 900103,
    RFC = 900104,

    WC_INTRO = 900111,
    WC_ROAD = 900112,
    WC_INVESTIGATION = 900113,
    WC_GROUP = 900114,
    WC_DUNGEON = 900115,

    DM_INTRO = 900121,
    DM_INVESTIGATION = 900122,
    DM_SI7 = 900123,
    DM_GROUP = 900124,
    DM_DUNGEON = 900125,

    -- Act III Part 2 — Stockades
    ST_ASHES = 900126,
    ST_SI7_REPORT = 900127,
    ST_STORMWIND = 900128,
    ST_PRISON = 900129,
    ST_DUNGEON = 900130,

    -- Act IV — Shadowfang Keep
    SFK_TRAVEL = 900131,
    SFK_HOWLS = 900132,
    SFK_CURSE = 900133,
    SFK_GROUP = 900134,
    SFK_DUNGEON = 900135,

    -- Act V — Blackfathom Deeps
    BFD_TRAVEL = 900136,
    BFD_TWILIGHT = 900137,
    BFD_DEPTHS = 900138,
    BFD_GROUP = 900139,
    BFD_DUNGEON = 900140,

    -- Act VI — Gnomeregan
    GNOMER_TRAVEL = 900141,
    GNOMER_SURVIVOR = 900142,
    GNOMER_BETRAYAL = 900143,
    GNOMER_GROUP = 900144,
    GNOMER_DUNGEON = 900145,

    -- Act VII — Razorfen Kraul
    RFK_TRAVEL = 900146,
    RFK_THORNS = 900147,
    RFK_CAPTIVE = 900148,
    RFK_GROUP = 900149,
    RFK_DUNGEON = 900150,

    -- Act VIII-XI — Scarlet Monastery
    SM_RED_STANDARD = 900151,
    SM_FAITH_WITHOUT_MERCY = 900152,
    SM_ROAD = 900153,
    SM_GRAVEYARD = 900154,
    SM_LIBRARY = 900155,
    SM_ARCHIVES = 900156,
    SM_MONASTERY_MUST_FALL = 900157,
    SM_ARMORY = 900158,
    SM_CATHEDRAL = 900159,

    -- Act XII — Uldaman
    ULDAMAN_TITAN_ECHOES = 900160,
    ULDAMAN_DWARVEN_ORIGINS = 900161,
    ULDAMAN_TROGG_WARNING = 900162,
    ULDAMAN_GROUP = 900163,
    ULDAMAN_DUNGEON = 900164,
}

Frostforge.Map = {
    EASTERN_KINGDOMS = 0,
    KALIMDOR = 1,
    OUTLAND = 530,
    RFC = 389,
    WAILING_CAVERNS = 43,
    DEADMINES = 36,
    STOCKADES = 34,
    SHADOWFANG_KEEP = 33,
    BLACKFATHOM_DEEPS = 48,
    GNOMEREGAN = 90,
    RAZORFEN_KRAUL = 47,
    SCARLET_MONASTERY = 189,
    ULDAMAN = 70,
}

Frostforge.Class = {
    WARRIOR = 1,
    PALADIN = 2,
    HUNTER = 3,
    ROGUE = 4,
    PRIEST = 5,
    DEATH_KNIGHT = 6,
    SHAMAN = 7,
    MAGE = 8,
    WARLOCK = 9,
    DRUID = 11
}

Frostforge.Team = {
    ALLIANCE = 0,
    HORDE = 1
}

Frostforge.Skill = {
    SWORDS = 43,
    AXES = 44,
    BOWS = 45,
    GUNS = 46,
    MACES = 54,
    TWO_HANDED_SWORDS = 55,
    DEFENSE = 95,
    STAVES = 136,
    TWO_HANDED_MACES = 160,
    TWO_HANDED_AXES = 172,
    DAGGERS = 173,
    WANDS = 228,
    SHIELDS = 433
}

Frostforge.Faction = {
    NEUTRAL = 35,
    ORGRIMMAR_WITNESS = 29,
    STORMWIND_WITNESS = 11
}

Frostforge.Location = {
    ORGRIMMAR_START = {
        map = 1,
        x = 1497.5602,
        y = -4415.688,
        z = 22.751932,
        o = 0.21601878
    },

    RFC_ENTRANCE = {
        map = 1,
        x = 1811.78,
        y = -4410.50,
        z = -18.47,
        o = 5.20
    },

    RFC_INSIDE = {
        map = 389,
        x = 5.835333,
        y = -25.63047,
        z = -20.681316,
        o = 1.944269
    },

    CROSSROADS = {
        map = 1,
        x = -509.78,
        y = -2666.94,
        z = 96.9204,
        o = 0.486741
    },

    WC_CAVE_ENTRANCE = {
        map = 1,
        x = -835.445,
        y = -2028.39,
        z = 81.3605,
        o = 3.86239
    },

    WC_PORTAL_AREA = {
        map = 1,
        x = -739.416,
        y = -2226.96,
        z = 19.6249,
        o = 6.16757
    },

    WESTFALL_SENTINEL_HILL = {
        map = 0,
        x = -10588.553,
        y = 1032.2521,
        z = 32.577464,
        o = 3.0552
    },

    WESTFALL_MOONBROOK = {
        map = 0,
        x = -11018.4,
        y = 1513.7,
        z = 43.0,
        o = 0.0
    },

    DEADMINES_INSIDE = {
        map = 36,
        x = -16.4,
        y = -383.07,
        z = 61.78,
        o = 1.86
    },

    STORMWIND_OLD_TOWN = {
        map = 0,
        x = -8842.57,
        y = 623.926,
        z = 94.1263,
        o = 0.223617
    },

    STOCKADES_ENTRANCE = {
        map = 0,
        x = -8776.03,
        y = 842.575,
        z = 91.6065,
        o = 3.98569
    },

    STOCKADES_STAGING = {
        map = 0,
        x = -8776.03,
        y = 842.575,
        z = 91.6065,
        o = 3.98569
    },

    STOCKADES_INSIDE_END = {
        map = 34,
        x = 54.238277,
        y = 0.63690406,
        z = -18.344336,
        o = 6.26
    },

    -- Act IV — Shadowfang Keep

    SILVERPINE_SEPULCHER = {
        map = 0,
        x = 506.0,
        y = 1613.0,
        z = 125.0,
        o = 3.1
    },

    SFK_ENTRANCE = {
        map = 0,
        x = -233.0,
        y = 1567.0,
        z = 76.9,
        o = 1.2
    },

    SFK_STAGING = {
        map = 0,
        x = -233.0,
        y = 1567.0,
        z = 76.9,
        o = 1.2
    },

    SFK_INSIDE = {
        map = 33,
        x = -229.135,
        y = 2110.56,
        z = 76.8898,
        o = 1.267
    },

    -- Act V — Blackfathom Deeps

    ZORAM_STRAND = {
        map = 1,
        x = 3648.166,
        y = 932.2607,
        z = 6.2454495,
        o = 5.447026
    },

    BFD_ENTRANCE = {
        map = 1,
        x = 4247.74,
        y = 745.879,
        z = -24.5299,
        o = 1.35
    },

    BFD_STAGING = {
        map = 1,
        x = 4247.74,
        y = 745.879,
        z = -24.5299,
        o = 1.35
    },

    BFD_INSIDE = {
        map = 48,
        x = -150.234,
        y = 106.594,
        z = -40.095,
        o = 4.45
    },

    -- Act VI — Gnomeregan

    GNOMEREGAN_STAGING = {
        map = 0,
        x = -5163.54,
        y = 925.423,
        z = 257.181,
        o = 2.77
    },

    GNOMEREGAN_INSIDE = {
        map = 90,
        x = -332.22,
        y = -2.28,
        z = -150.86,
        o = 2.77
    },

    -- Act VII — Razorfen Kraul

    RFK_STAGING = {
        map = 1,
        x = -4464.92,
        y = -1666.24,
        z = 81.8928,
        o = 1.15
    },

    RFK_INSIDE = {
        map = 47,
        x = 1943.0,
        y = 1544.63,
        z = 82.56,
        o = 1.38
    },

    -- Act VIII-XI — Scarlet Monastery

    SM_STAGING = {
        map = 0,
        x = 2871.0,
        y = -819.0,
        z = 160.0,
        o = 5.0
    },

    SM_GY_INSIDE = {
        map = 189,
        x = 1688.99,
        y = 1053.48,
        z = 18.68,
        o = 0.0
    },

    SM_LIB_INSIDE = {
        map = 189,
        x = 255.346,
        y = -209.09,
        z = 18.68,
        o = 6.28
    },

    SM_ARM_INSIDE = {
        map = 189,
        x = 1608.10,
        y = -318.92,
        z = 18.67,
        o = 6.28
    },

    SM_CATH_INSIDE = {
        map = 189,
        x = 855.68,
        y = 1321.50,
        z = 18.67,
        o = 0.0
    },

    ULDAMAN_STAGING = {
        map = 0,
        x = -6065.0,
        y = -2955.0,
        z = 209.0,
        o = 0.7
    },

    ULDAMAN_INSIDE = {
        map = 70,
        x = -228.19,
        y = 46.16,
        z = -46.02,
        o = 1.57
    },
}

Frostforge.Level = {
    RFC_REWARD = 15,
    WC_REWARD = 20,
    DM_REWARD = 22,
    STOCKADES_PREP = 24,
    STOCKADES_REWARD = 26,

    -- Act IV — Shadowfang Keep
    SFK_REWARD = 27,

    BFD_REWARD = 29,
    GNOMER_REWARD = 31,
    RFK_REWARD = 33,

    SM_GY_REWARD = 35,
    SM_LIB_REWARD = 37,
    SM_ARMORY_REWARD = 39,
    SM_CATHEDRAL_REWARD = 40,

    ULDAMAN_REWARD = 45,
}
