# Frostforge SQL Apply Order

Apply Frostforge SQL patches to the `acore_world` database.

Do not apply these patches to `acore_auth` or `acore_characters` unless a specific patch explicitly says so.

## Recommended Order

Core NPCs and shared objects should be applied before dungeon-specific campaign patches.

Suggested structure:

    001_frostforge_core_npcs.sql
    002_frostforge_ragefire_chasm.sql
    003_frostforge_wailing_caverns.sql
    004_frostforge_deadmines.sql
    005_frostforge_shadowfang_keep.sql
    006_frostforge_blackfathom_deeps.sql
    007_frostforge_gnomeregan_expanded.sql
    008_frostforge_razorfen_kraul_expanded.sql
    009_frostforge_scarlet_monastery_expanded.sql
    010_frostforge_scarlet_missing_npcs.sql
    011_frostforge_custom_npc_models.sql

## Apply Example

    sudo mysql acore_world < sql/001_frostforge_core_npcs.sql
    sudo mysql acore_world < sql/002_frostforge_ragefire_chasm.sql

## Current Custom Ranges

    Quests: 900100 - 900155
    NPCs:   900010 - 900056
    Credits: 900071 - 900076

## Important Notes

Creature displays are handled through:

    creature_template_model

When adding custom NPCs, check both:

    creature_template
    creature_template_model

Quest starters and enders should be added through the correct quest relation tables for this AzerothCore version.

Avoid using real player/account data in SQL patches.

Never commit SQL dumps containing accounts, passwords, characters or private data.
