USE acore_world;

-- Gnomeregan story NPC positions
UPDATE creature
SET
  map = 0,
  zoneId = 721,
  areaId = 721,
  position_x = -5165.3306,
  position_y = 927.4327,
  position_z = 257.1785,
  orientation = 0.04977166,
  phaseMask = 1,
  spawnMask = 1
WHERE guid = 5300802;

UPDATE creature
SET
  map = 0,
  zoneId = 721,
  areaId = 721,
  position_x = -5162.5176,
  position_y = 928.75446,
  position_z = 257.18134,
  orientation = 4.298782,
  phaseMask = 1,
  spawnMask = 1
WHERE guid = 5300803;
-- Scarlet Monastery / Hillsbrad bridge story NPC positions
UPDATE creature
SET
  map = 0,
  position_x = 2879.0762,
  position_y = -822.2531,
  position_z = 160,
  orientation = 2.2961,
  phaseMask = 1,
  spawnMask = 1
WHERE guid = 5300840;

UPDATE creature
SET
  map = 0,
  position_x = 2881.2068,
  position_y = -818.7175,
  position_z = 160,
  orientation = 3.0713,
  phaseMask = 1,
  spawnMask = 1
WHERE guid = 5300841;

UPDATE creature
SET
  map = 0,
  position_x = 2874.6587,
  position_y = -822.8465,
  position_z = 160,
  orientation = 1.3057,
  phaseMask = 1,
  spawnMask = 1
WHERE guid = 5300842;

-- Scarlet Road story NPC positions
UPDATE creature
SET
  map = 0,
  position_x = 2876.50,
  position_y = -818.90,
  position_z = 160,
  orientation = 2.60,
  phaseMask = 1,
  spawnMask = 1
WHERE guid = 5300822;

UPDATE creature
SET
  map = 0,
  position_x = 2873.00,
  position_y = -819.50,
  position_z = 160,
  orientation = 1.80,
  phaseMask = 1,
  spawnMask = 1
WHERE guid = 5300823;