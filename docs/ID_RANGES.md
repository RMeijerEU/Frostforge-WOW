# Frostforge ID Ranges

This document tracks Frostforge custom ID ranges.

Before adding new quests, NPCs, credit NPCs, items or other custom database objects, check this file first.

## Why This Matters

Frostforge uses custom SQL patches on top of AzerothCore.

If two contributors use the same custom ID, quests or NPCs can overwrite each other, break objectives, or cause confusing in-game behavior.

## Current Known Ranges

### Quests

Currently used:

    900100 - 900155

### NPCs / Creatures

Currently used:

    900010 - 900056

Important entries:

    900010 - Frostforge Guide
    900011 - Archivist Eldrin

### Location / Credit NPCs

Currently used:

    900071 - 900076

These are used because all Archivist Eldrin spawns share the same creature entry. Location-specific quest credit should use separate credit NPC entries instead of Eldrin entry `900011`.

## Reserved Future Campaign Ranges

Use these ranges unless they are changed in a later update.

| Campaign Chapter | Quest Range | NPC Range | Credit NPC Range |
| --- | --- | --- | --- |
| Uldaman | 900160 - 900179 | 900060 - 900069 | 900080 - 900089 |
| Zul'Farrak | 900180 - 900199 | 900070 - 900079 | 900090 - 900099 |
| Maraudon | 900200 - 900219 | 900080 - 900089 | 900100 - 900109 |
| Sunken Temple | 900220 - 900239 | 900090 - 900099 | 900110 - 900119 |
| Blackrock Depths | 900240 - 900269 | 900100 - 900109 | 900120 - 900129 |
| Lower Blackrock Spire | 900270 - 900289 | 900110 - 900119 | 900130 - 900139 |
| Upper Blackrock Spire | 900290 - 900309 | 900120 - 900129 | 900140 - 900149 |
| Scholomance | 900310 - 900329 | 900130 - 900139 | 900150 - 900159 |
| Stratholme | 900330 - 900359 | 900140 - 900149 | 900160 - 900169 |
| Dire Maul | 900360 - 900389 | 900150 - 900159 | 900170 - 900179 |

## Rules for Contributors

1. Do not invent new custom ranges without checking this document.
2. Do not reuse IDs from earlier campaign chapters.
3. Add new ranges here before creating SQL patches.
4. Keep custom SQL patches readable and grouped by campaign chapter.
5. Do not use real player, account or password data in SQL patches.
6. Do not commit database dumps.
7. For custom creature displays, check both:
   - `creature_template`
   - `creature_template_model`

## Adding a New Campaign Chapter

When adding a new chapter, reserve:

- Quest IDs
- NPC IDs
- Location/Credit NPC IDs
- Item IDs, if custom items are needed

Then update this file in the same pull request as the new campaign chapter.

## Notes About Creature Models

This AzerothCore database uses `creature_template_model` for creature displays.

When adding a custom NPC, make sure a valid display row exists in:

    creature_template_model

Otherwise the NPC may spawn with the wrong model or no visible model.
