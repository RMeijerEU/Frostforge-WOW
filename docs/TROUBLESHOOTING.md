# Frostforge Troubleshooting

## Lua scripts do not load

Check worldserver tmux output:

    tmux capture-pane -t worldserver -p -S -3000 | grep -i "frostforge\|lua\|error"

Common causes:

- File missing from `/home/wow/azeroth-server/lua_scripts/`
- Incorrect path in `frostforge_loader.lua`
- Syntax error in one of the `.inc` files
- Missing `frostforge_lib/` directory
- Wrong file permissions

## Eldrin gossip behaves strangely

Do not register multiple gossip handlers for NPC entry `900011`.

All Eldrin gossip must be handled in:

    03_eldrin_gossip.inc

## Quest completes at the wrong Eldrin

Because all Eldrins share entry `900011`, use location-credit NPC entries instead.

Current credit range:

    900071 - 900076

## Custom NPC has no model

This AzerothCore database uses:

    creature_template_model

For custom NPC displays, make sure a valid row exists in both:

    creature_template
    creature_template_model

## C++ Guide changes do not appear

The Frostforge Guide is C++.

After editing:

    frostforge_bot_group.cpp

You must rebuild AzerothCore and restart worldserver.

## SQL patch fails

Check:

- Correct database: `acore_world`
- Correct quest/NPC ID ranges
- Existing duplicate IDs
- Column names for this AzerothCore version
- Whether the patch was already applied

## worldserver logs are empty in journalctl

The live server uses tmux for worldserver logging.

Use:

    tmux capture-pane -t worldserver -p -S -3000 | grep -i "frostforge\|lua\|error"

instead of relying only on:

    journalctl
