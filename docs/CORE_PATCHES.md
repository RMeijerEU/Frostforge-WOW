# Frostforge Core / Module Patches

## Eluna SetBindPoint client update

File:

`modules/mod-eluna/src/LuaEngine/methods/PlayerMethods.h`

Reason:

Frostforge uses `player:SetBindPoint(x, y, z, mapId, areaId)` from Lua to bind Hearthstone to the current Archivist Eldrin camp. By default, the homebind was saved, but the active client/session did not update the Hearthstone tooltip until relog.

Patch:

After `player->SetHomebind(loc, areaId);`, send `SMSG_BINDPOINTUPDATE` to the player session.

Validation:

- Frostforge Eldrin bind updates Hearthstone tooltip immediately.
- Normal innkeeper binding still works.
