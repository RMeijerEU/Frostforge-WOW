# Frostforge

Frostforge is a World of Warcraft private server project that turns Classic Azeroth into a guided dungeon-based lore campaign.

Instead of treating dungeons as isolated instances, Frostforge connects them through short campaign questlines, iconic story moments, custom rewards and guided progression.

## Project goals

- Create a clear dungeon campaign path through Classic Azeroth
- Add short lore questlines between dungeons
- Support solo and small-group play with Playerbots
- Use custom Lua and SQL where needed
- Keep the server approachable for alpha testers and new players

## Repository structure

```
docs/       Project documentation and design notes
campaign/   Dungeon campaign drafts and questline planning
sql/        Custom database changes
lua/        Custom server scripts
website/    Website articles, changelogs and CMS content
addon/      Addon or launcher-related files
```

## Contribution workflow

- Pick a task from Discord or GitHub Issues.
- Create a branch or fork.
- Make a small focused change.
- Open a Pull Request.
- Changes are reviewed before being used on the server.

## Important

Do not commit:

- Passwords
- API keys
- Server configs with secrets
- Database dumps
- Backups
- SSL keys
- Real account data
