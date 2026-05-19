# Lua

This folder contains custom Lua scripts for Frostforge.

## Structure

```text
campaign/    Dungeon campaign scripts
systems/     Shared campaign systems
playerbots/  Playerbot-related helper scripts
```

## Rules

- Keep scripts readable.
- Keep dungeon-specific code in lua/campaign.
- Put reusable helper functions in lua/systems.
- Avoid hardcoding secrets or private server paths.
