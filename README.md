# Frostforge WOW

Frostforge is a custom AzerothCore / Wrath of the Lich King 3.3.5a project.

The project adds a guided Warcraft campaign layer on top of AzerothCore, using custom Lua scripts, SQL patches and a small C++ custom script.

Players progress through dungeon and raid story chapters instead of following a traditional leveling route. Completing campaign chapters and dungeons grants the levels, gear and rewards needed for the next chapter.

## Stack

- AzerothCore WotLK 3.3.5a
- Eluna Lua Engine
- Custom Lua campaign scripts
- Custom SQL patches for quests, NPCs, spawns and rewards
- Custom C++ script for the Frostforge Guide / Playerbot group helper

## Repository Structure

    lua_scripts/
      frostforge_loader.lua
      frostforge_lib/

    cpp/
      frostforge_bot_group.cpp

    sql/
      SQL patches and apply order

    docs/
      Documentation

## Lua System

Only `frostforge_loader.lua` is loaded directly by Eluna.

The loader then loads modular `.inc` files from:

    lua_scripts/frostforge_lib/

Important files:

- `00_config.inc`  
  Central IDs and settings for NPCs, quests, maps, locations, factions and reward levels.

- `01_utils.inc`  
  Shared utility functions.

- `03_eldrin_gossip.inc`  
  Central gossip handler for Archivist Eldrin.

- `04_dungeon_rewards.inc`  
  Class-based dungeon reward logic.

- `07_campaign_helpers.inc`  
  Shared campaign helper functions.

- `actXX_*.inc`  
  Individual dungeon/campaign chapter logic.

## Archivist Eldrin

Archivist Eldrin uses NPC entry `900011`.

All Eldrin gossip options are handled centrally in:

    lua_scripts/frostforge_lib/03_eldrin_gossip.inc

Do not register separate `RegisterCreatureGossipEvent` handlers for Eldrin in individual act files. This avoids handler conflicts.

Because all Eldrins use the same creature entry, separate location-credit NPC entries are used for quest objective credit, such as:

    900071 - 900076

## Frostforge Guide

The Frostforge Guide is a custom C++ script:

    cpp/frostforge_bot_group.cpp

Live AzerothCore source path:

    /home/wow/azerothcore/src/server/scripts/Custom/frostforge_bot_group.cpp

The Guide uses NPC entry:

    900010

It handles:

- Playerbot group setup
- Vendor supplies
- Bot control explanation
- Dungeon teleports
- Campaign support options

Changes to this file require an AzerothCore rebuild.

## SQL

Custom quests, NPC templates, spawns, quest starters, quest enders and quest objective data are added through SQL patches for `acore_world`.

Current custom ranges:

    Quests: 900100 - 900155
    NPCs:   900010 - 900056
    Credits: 900071 - 900076

Creature displays are managed through `creature_template_model`, not only through `creature_template`.

When adding a custom NPC, make sure both tables are updated when needed:

    creature_template
    creature_template_model

## Deployment

Lua scripts should be deployed to:

    /home/wow/azeroth-server/lua_scripts/

The C++ script should be copied to:

    /home/wow/azerothcore/src/server/scripts/Custom/

SQL patches should be applied to:

    acore_world

See:

    sql/APPLY_ORDER.md

## Logging

The live server runs worldserver inside tmux.

Check recent Frostforge/Lua output with:

    tmux capture-pane -t worldserver -p -S -3000 | grep -i "frostforge\|lua\|error"

A healthy Lua load should show:

- Frostforge loader starting
- Frostforge modules loading
- Act files loading
- Central Eldrin gossip loading
- Lua loader finished
