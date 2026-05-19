# Frostforge Deployment

## Lua Deployment

Copy Lua files to the live Eluna script directory:

    cp lua_scripts/frostforge_loader.lua /home/wow/azeroth-server/lua_scripts/
    cp lua_scripts/frostforge_lib/*.inc /home/wow/azeroth-server/lua_scripts/frostforge_lib/

Or deploy the full Lua directory with rsync:

    rsync -av lua_scripts/ /home/wow/azeroth-server/lua_scripts/

Restart worldserver after deployment.

## C++ Deployment

Copy the custom script into AzerothCore source:

    cp cpp/frostforge_bot_group.cpp /home/wow/azerothcore/src/server/scripts/Custom/

Then rebuild AzerothCore:

    cd /home/wow/azerothcore/build
    make -j$(nproc)

Then restart worldserver.

## SQL Deployment

Apply SQL patches to `acore_world` in the order documented in:

    sql/APPLY_ORDER.md

Example:

    sudo mysql acore_world < sql/001_frostforge_core_npcs.sql

## Verify Lua Load

The live server runs worldserver inside tmux.

Check the recent Frostforge/Lua output with:

    tmux capture-pane -t worldserver -p -S -3000 | grep -i "frostforge\|lua\|error"

Expected healthy output:

    Frostforge loader starting
    Loaded Frostforge module ...
    Loaded Frostforge act ...
    Central Eldrin gossip loaded
    Lua loader finished
