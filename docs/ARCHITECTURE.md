# Frostforge Architecture

Frostforge is structured as a custom layer on top of AzerothCore.

It is not a full AzerothCore fork. The repository only contains Frostforge-specific Lua scripts, SQL patches, C++ custom scripts and documentation.

## Main Components

### Lua Campaign Layer

Path on live server:

    /home/wow/azeroth-server/lua_scripts/

Only this file is loaded directly by Eluna:

    frostforge_loader.lua

The loader then loads all required `.inc` files from:

    frostforge_lib/

This keeps the system modular and prevents one large Lua file.

### Config

    00_config.inc

Contains shared constants:

- NPC IDs
- Quest IDs
- Map IDs
- Locations
- Factions
- Reward levels
- Campaign settings

### Utilities

    01_utils.inc
    07_campaign_helpers.inc

Contain reusable helper functions for quest logic, rewards, messages, checks and campaign flow.

### Dungeon Acts

Examples:

    act04_shadowfang_keep.inc
    act05_blackfathom_deeps.inc
    act06_gnomeregan.inc
    act07_razorfen_kraul.inc
    act08_scarlet_monastery.inc

Act files should only contain logic specific to that dungeon chapter.

They should not redefine shared systems or register duplicate gossip handlers for global NPCs.

## Eldrin Gossip System

Archivist Eldrin uses entry:

    900011

All gossip for this NPC is centralized in:

    03_eldrin_gossip.inc

Reason:

AzerothCore/Eluna can behave badly or unpredictably when multiple files register competing gossip handlers for the same creature entry.

Therefore, all Eldrin travel and campaign dialogue options should be added to the central handler.

## Location Credit NPCs

Because all Eldrins share the same entry, quest objective credit cannot rely on Eldrin entry `900011`.

Separate invisible or helper credit NPC entries are used instead:

    900071 - 900076

These allow specific quest objectives to complete at the correct location.

## Dungeon Rewards

Reward logic lives in:

    04_dungeon_rewards.inc

Current reward functions include:

    GiveSFKClassReward
    GiveBFDClassReward
    GiveGnomerClassReward
    GiveRFKClassReward
    GiveSMGraveyardClassReward
    GiveSMLibraryClassReward
    GiveSMArmoryClassReward
    GiveSMCathedralClassReward

Reward tables are class-based.

The reward helper supports:

    itemId
    { itemId, count }

## C++ Frostforge Guide

The Frostforge Guide is implemented in C++:

    cpp/frostforge_bot_group.cpp

Live source path:

    /home/wow/azerothcore/src/server/scripts/Custom/frostforge_bot_group.cpp

NPC entry:

    900010

Responsibilities:

- Playerbot group creation
- Playerbot explanations
- Vendor supplies
- Dungeon teleports
- Campaign convenience options

Because this is C++, changes require rebuilding AzerothCore.
