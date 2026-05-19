# Frostforge Deployment

## Lua Deployment

Copy Lua files to the live Eluna script directory:

    cp lua_scripts/frostforge_loader.lua /home/wow/azeroth-server/lua_scripts/
    cp lua_scripts/frostforge_lib/*.inc /home/wow/azeroth-server/lua_scripts/frostforge_lib/

Or deploy the full Lua directory with rsync:

    rsync -av lua_scripts/ /home/wow/azeroth-server/lua_scripts/

Restart worldserver after deployment.

## C++ Deployment

The Frostforge Guide is implemented in C++ and lives in the repository at:

    cpp/frostforge_bot_group.cpp

Deploy it to the AzerothCore custom scripts directory:

    cp cpp/frostforge_bot_group.cpp /home/wow/azerothcore/src/server/scripts/Custom/frostforge_bot_group.cpp

Then rebuild and install AzerothCore:

    cd /home/wow/azerothcore/build
    make -j$(nproc)
    make install

Restart worldserver:

    sudo systemctl restart acore-world.service

If the server is still managed through tmux instead of systemd, restart the worldserver through the existing tmux workflow instead.

### Lua Link Workaround

If the AzerothCore build still fails because of the Lua link issue, apply the known local Lua link workaround before rebuilding.

This workaround should be documented here because C++ changes require a rebuild, and the missing Lua link can otherwise be forgotten during future deployments.

Current reminder:

    cd /home/wow/azerothcore/build
    make -j$(nproc)

If the build fails with Lua linking errors, re-apply the local Lua link fix that links the build against the correct Lua library, then run:

    make -j$(nproc)
    make install

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
