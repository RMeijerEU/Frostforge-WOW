# Current Frostforge State

This document summarizes the current state of the Frostforge project repository.

## Repository purpose

This repository stores the source files, documentation and helper scripts for the Frostforge WoW server project.

GitHub is used as the safe collaboration layer. Contributors should work through issues, branches and pull requests. Direct access to the live server is not required.

## Current project focus

Frostforge turns Classic Azeroth into a guided dungeon-based lore campaign.

Players follow short lore questlines between dungeons. Each dungeon acts as a campaign chapter instead of an isolated instance.

## Current campaign status

Implemented or actively worked on:

- Starter flow
- Ragefire Chasm
- Wailing Caverns
- Deadmines
- Stockades
- Shadowfang Keep
- Blackfathom Deeps
- Gnomeregan
- Razorfen Kraul
- Scarlet Monastery

Planned or later:

- Razorfen Downs
- Uldaman
- Zul'Farrak
- Maraudon
- Sunken Temple
- Blackrock Depths
- Scholomance
- Stratholme
- Lower Blackrock Spire
- Upper Blackrock Spire

## Lua structure

Active Lua structure:

- lua/systems/frostforge_loader.lua
- lua/frostforge_lib/*.inc

The loader includes the modular Frostforge library files from frostforge_lib.

Legacy monolithic scripts are stored in:

- lua/archive/

These are kept for reference and should not be treated as the active live structure.

## Lua deployment

Lua deployment helper:

- tools/deploy-lua.sh

Usage:

./tools/deploy-lua.sh

This copies the repo Lua loader and frostforge_lib files to:

- /home/wow/azeroth-server/lua_scripts
- /home/wow/azeroth-server/lua_scripts/frostforge_lib

Restart worldserver if the scripts are not hot-reloaded.

## SQL structure

SQL scripts are stored in:

- sql/items/
- sql/quests/
- sql/website/

SQL apply notes are documented in:

- sql/APPLY_ORDER.md

SQL should be applied manually and carefully. Do not blindly run every script on production.

## Documentation

Important documentation files:

- docs/campaign-overview.md
- docs/dungeon-path.md
- docs/reward-philosophy.md
- docs/testing-guide.md
- sql/APPLY_ORDER.md

## Campaign drafts

Campaign planning files:

- campaign/01-ragefire-chasm.md
- campaign/02-wailing-caverns.md
- campaign/02-deadmines.md
- campaign/03-shadowfang-keep.md

## GitHub collaboration

The repository includes issue templates for:

- Bug reports
- Campaign tasks
- Testing tasks

Suggested workflow:

1. Pick or create a GitHub issue.
2. Create a branch.
3. Make a small focused change.
4. Open a pull request.
5. Review before using changes on the live server.

## Do not commit

Never commit:

- Passwords
- API keys
- Server configs with secrets
- Full database dumps
- Backups
- SSL keys
- Real account data
- Forum users, hashes or sessions
