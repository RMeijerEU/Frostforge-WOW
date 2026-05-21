USE acore_world;

DELETE FROM creature_template_model
WHERE CreatureID IN (
    900053,900054,
    900057,900058,900059,
    900071,900072,900073,900074,900075,900076
);

INSERT INTO creature_template_model
(CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability, VerifiedBuild)
VALUES
-- Razorfen Kraul
(900053, 0, 11869, 1, 1, 0),
(900054, 0, 1252, 1, 1, 0),

-- Scarlet / Hillsbrad bridge
(900057, 0, 2374, 1, 1, 0),
(900058, 0, 4157, 1, 1, 0),

-- Hillsbrad refugee uses a Forsaken-style witness display for now.
(900059, 0, 2374, 1, 1, 0);

-- Eldrin credit NPCs
INSERT INTO creature_template_model
(CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability, VerifiedBuild)
VALUES
(900071, 0, 10727, 1, 1, 0),
(900072, 0, 10727, 1, 1, 0),
(900073, 0, 10727, 1, 1, 0),
(900074, 0, 10727, 1, 1, 0),
(900075, 0, 10727, 1, 1, 0),
(900076, 0, 10727, 1, 1, 0);

-- Razorfen Kraul story NPC positions
UPDATE creature
SET
  map = 1,
  position_x = -4468.2505,
  position_y = -1686.6683,
  position_z = 81.29649,
  orientation = 3.865394,
  phaseMask = 1,
  spawnMask = 1
WHERE guid = 5300812;

UPDATE creature
SET
  map = 1,
  position_x = -4466.2505,
  position_y = -1684.6683,
  position_z = 81.29649,
  orientation = 3.865394,
  phaseMask = 1,
  spawnMask = 1
WHERE guid = 5300813;