#!/usr/bin/env bash
set -euo pipefail

REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TARGET_DIR="/home/wow/azeroth-server/lua_scripts"

echo "Deploying Frostforge Lua scripts..."
echo "From: $REPO_DIR"
echo "To:   $TARGET_DIR"
echo

install -m 0644 "$REPO_DIR/lua/systems/frostforge_loader.lua" "$TARGET_DIR/frostforge_loader.lua"
install -m 0644 "$REPO_DIR/lua/systems/frostforge_starter_pack.lua" "$TARGET_DIR/frostforge_starter_pack.lua"
install -m 0644 "$REPO_DIR/lua/campaign/frostforge_dungeon_path_act1_complete.lua" "$TARGET_DIR/frostforge_dungeon_path_act1_complete.lua"

echo
echo "Done. Restart worldserver if these scripts are not hot-reloaded."
