# SQL Apply Order

This folder contains Frostforge custom SQL scripts.

Apply SQL manually and carefully. Do not run every file blindly on production.

## Items

Starter item scripts:

- sql/items/frostforge_starter_t3_armor.sql
- sql/items/frostforge_starter_t3_extras.sql
- sql/items/frostforge_starter_t3_extras_looks.sql
- sql/items/frostforge_starter_unique_class_looks.sql

These scripts affect starter gear, item visuals or class-specific item setup.

## Campaign quests

Campaign and lore scripts:

- sql/quests/frostforge_act04_sfk.sql
- sql/quests/frostforge_act05_to_act11.sql
- sql/quests/frostforge_rfk_lore_polish.sql
- sql/quests/frostforge_sm_lore_polish.sql

These scripts affect campaign quest text, dungeon progression or lore polish.

## Website

Website/CMS related SQL:

- sql/website/frostforge_forum.sql

Review carefully before applying. Website SQL should not contain live users, password hashes, sessions or private account data.

## Example usage

Apply a script manually:

    sudo mysql acore_world < sql/quests/frostforge_act04_sfk.sql

For website SQL, use the correct FusionCMS database instead of acore_world.
