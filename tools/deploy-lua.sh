#!/usr/bin/env bash
set -euo pipefail

REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TARGET_DIR="/home/wow/azeroth-server/lua_scripts"
LIB_DIR="$TARGET_DIR/frostforge_lib"

echo "Deploying Frostforge Lua scripts..."
echo "From: $REPO_DIR"
echo "To:   $TARGET_DIR"
echo

mkdir -p "$LIB_DIR"

install -m 0644 "$REPO_DIR/lua/systems/frostforge_loader.lua" "$TARGET_DIR/frostforge_loader.lua"
install -m 0644 "$REPO_DIR/lua/frostforge_lib/"*.inc "$LIB_DIR/"

echo
echo "Done. Restart worldserver if these scripts are not hot-reloaded."
