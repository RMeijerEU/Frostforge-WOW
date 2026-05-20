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

-- This assumes 900048 already has a good Gilnean/refugee display.
-- If 900048 has no model, replace this with a concrete display ID.
(900059, 0, 4157, 1, 1, 0);