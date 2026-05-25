-- Frostforge Campaign
-- Rename the generic Frostforge Guide into a named recurring support NPC.

UPDATE creature_template
SET name = 'Groupfinder Marric',
    subname = 'Party & Supplies'
WHERE entry = 900010;