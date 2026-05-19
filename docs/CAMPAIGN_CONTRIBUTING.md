# Frostforge Campaign Contributing Guide

This guide explains how to contribute a new Frostforge dungeon campaign chapter.

Frostforge is not a full AzerothCore fork. The repository contains the custom Frostforge layer:

- Lua campaign scripts
- SQL patches
- C++ custom scripts
- Documentation

All changes should go through GitHub branches and pull requests. Do not edit the live server directly.

## Campaign Design Goal

Each dungeon chapter should feel like a Warcraft campaign mission.

The goal is not traditional zone leveling.

The intended loop is:

    story setup
    -> lore-based preparation
    -> dungeon chapter
    -> reward / level / gear progression
    -> bridge to the next campaign arc

The dungeon is the main content. Custom quests act as story glue.

## Expected Scope Per Dungeon

Keep chapters focused.

A normal dungeon arc should usually include around 3 to 5 quests:

1. Introduce the threat
2. Explain why the dungeon matters
3. Prepare or send the player to the dungeon
4. Complete the dungeon objective
5. Reward the player and bridge to the next chapter

Avoid turning one dungeon into a full zone rewrite.

## New Dungeon Arc Checklist

When adding a new dungeon chapter:

- Create a new Lua act file
- Add the act file to `frostforge_loader.lua`
- Add constants to `00_config.inc` if needed
- Add SQL patch in `sql/`
- Update `sql/APPLY_ORDER.md`
- Use the reserved ID range from `docs/ID_RANGES.md`
- Add rewards in `04_dungeon_rewards.inc` if needed
- Do not add duplicate Eldrin gossip handlers
- Test Lua loading
- Test quest start and completion
- Test dungeon completion
- Test rewards
- Test Horde/Alliance behavior if relevant
- Test with Playerbots if relevant

## Suggested File Pattern

For a new chapter, use this pattern:

    lua_scripts/frostforge_lib/actXX_dungeon_name.inc
    sql/0XX_frostforge_dungeon_name.sql

Example:

    lua_scripts/frostforge_lib/act09_uldaman.inc
    sql/010_frostforge_uldaman.sql

## Lua Structure

Dungeon act files should only contain logic specific to that dungeon chapter.

Good examples of act-file content:

- Quest accept/completion hooks
- Dungeon boss kill handling
- Chapter-specific messages
- Reward trigger logic
- Chapter-specific helper functions

Avoid putting global systems in act files.

Shared systems should live in shared library files, such as:

    00_config.inc
    01_utils.inc
    04_dungeon_rewards.inc
    07_campaign_helpers.inc

## Loader Rule

Only this file is loaded directly by Eluna:

    lua_scripts/frostforge_loader.lua

Every new act file must be added to the loader.

If the act file is not added to the loader, it will not run in-game.

## Archivist Eldrin Rule

Archivist Eldrin uses NPC entry:

    900011

All Eldrin gossip is centralized in:

    lua_scripts/frostforge_lib/03_eldrin_gossip.inc

Do not register separate `RegisterCreatureGossipEvent` handlers for Eldrin in dungeon act files.

This prevents conflicts caused by multiple gossip handlers for the same NPC entry.

## Location Credit NPCs

Because all Archivist Eldrin spawns share entry `900011`, do not use Eldrin directly for location-specific quest credit.

Use separate location/credit NPC entries instead.

Check:

    docs/ID_RANGES.md

for reserved credit NPC ranges.

## SQL Patch Rules

SQL patches should be:

- Clear
- Chapter-specific
- Safe to review
- Free of account/player/private data

Use one SQL patch per campaign chapter where possible.

Example:

    sql/010_frostforge_uldaman.sql

A campaign SQL patch may include:

- Custom quest templates
- Custom creature templates
- Creature display rows in `creature_template_model`
- Spawns
- Quest starters
- Quest enders
- Quest objectives
- Conditions if needed

## Creature Model Rule

This AzerothCore database uses:

    creature_template_model

When creating custom NPCs, make sure display data exists in both relevant places:

    creature_template
    creature_template_model

If this is skipped, NPCs may spawn with missing or incorrect models.

## Reward Rules

Dungeon reward logic lives in:

    lua_scripts/frostforge_lib/04_dungeon_rewards.inc

Reward functions should be class-aware when possible.

The reward helper supports:

    itemId
    { itemId, count }

Do not give every class the same weapon or armor type if it does not make sense.

## Branch Workflow

Create a branch for each campaign chapter.

Example:

    git checkout -b feature/uldaman-campaign

Commit your work:

    git add -A
    git commit -m "Add Uldaman campaign chapter"

Push your branch:

    git push -u origin feature/uldaman-campaign

Then open a pull request into `main`.

## Pull Request Expectations

A pull request should explain:

- Which dungeon chapter was added or changed
- Which quests were added
- Which ID ranges were used
- Which SQL patch should be applied
- Whether Lua was tested
- Whether the dungeon flow was tested in-game

## Review Checklist

Before merging, check:

- IDs are unique
- SQL applies to `acore_world`
- Lua loads without errors
- Loader includes the new act file
- Eldrin gossip is not duplicated
- Quest flow makes sense
- Rewards are class-appropriate
- No secrets, logs, dumps or private data are committed
- The chapter bridges cleanly to the next arc

## Deployment Reminder

After merging to `main`, deploy from the repository to the live server.

Lua deployment:

    rsync -av lua_scripts/ /home/wow/azeroth-server/lua_scripts/

SQL deployment example:

    sudo mysql acore_world < sql/010_frostforge_uldaman.sql

Check logs:

    tmux capture-pane -t worldserver -p -S -3000 | grep -i "frostforge\|lua\|error"

## Important Principle

The GitHub repository is the source of truth.

Do not make permanent changes directly in the live Lua directory without also committing them to GitHub.
