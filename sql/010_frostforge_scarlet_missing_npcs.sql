USE acore_world;

DELETE FROM creature_template WHERE entry IN (900057,900058,900059);

DROP TEMPORARY TABLE IF EXISTS frostforge_tmp_creature_template;
CREATE TEMPORARY TABLE frostforge_tmp_creature_template LIKE creature_template;

INSERT INTO frostforge_tmp_creature_template
SELECT * FROM creature_template WHERE entry = 900055;

UPDATE frostforge_tmp_creature_template
SET entry = 900057,
    name = 'Frostforge Southshore Scout',
    subname = 'Hillsbrad Witness';

INSERT INTO creature_template
SELECT * FROM frostforge_tmp_creature_template;

TRUNCATE TABLE frostforge_tmp_creature_template;

INSERT INTO frostforge_tmp_creature_template
SELECT * FROM creature_template WHERE entry = 900055;

UPDATE frostforge_tmp_creature_template
SET entry = 900058,
    name = 'Frostforge Tarren Mill Apothecary',
    subname = 'Forsaken Witness';

INSERT INTO creature_template
SELECT * FROM frostforge_tmp_creature_template;

TRUNCATE TABLE frostforge_tmp_creature_template;

INSERT INTO frostforge_tmp_creature_template
SELECT * FROM creature_template WHERE entry = 900055;

UPDATE frostforge_tmp_creature_template
SET entry = 900059,
    name = 'Frostforge Hillsbrad Refugee',
    subname = 'Scarlet Witness';

INSERT INTO creature_template
SELECT * FROM frostforge_tmp_creature_template;

DROP TEMPORARY TABLE IF EXISTS frostforge_tmp_creature_template;