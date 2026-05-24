-- Frostforge Lua Loader
-- Only this file should be loaded directly by Eluna.
-- Shared files use .inc extension to avoid accidental double-loading.

print("[Frostforge] Lua loader starting...")

Frostforge = Frostforge or {}

local base = "../lua_scripts/frostforge_lib/"

dofile(base .. "00_config.inc")
dofile(base .. "01_utils.inc")
dofile(base .. "02_starter_gear.inc")
dofile(base .. "03_campaign_veil.inc")
dofile(base .. "04_dungeon_rewards.inc")
dofile(base .. "06_class_training.inc")
dofile(base .. "05_auto_training.inc")
dofile(base .. "07_campaign_helpers.inc")

dofile(base .. "act01_rfc.inc")
dofile(base .. "act02_wailing_caverns.inc")
dofile(base .. "act03_defias.inc")
dofile(base .. "act03_stockades.inc")
dofile(base .. "act04_shadowfang_keep.inc")
dofile(base .. "act05_blackfathom_deeps.inc")
dofile(base .. "act06_gnomeregan.inc")
dofile(base .. "act07_razorfen_kraul.inc")
dofile(base .. "act08_scarlet_monastery.inc")
dofile(base .. "act09_uldaman.inc")

dofile(base .. "03_eldrin_gossip.inc")

print("[Frostforge] Lua loader finished.")
