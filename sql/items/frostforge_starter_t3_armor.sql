USE acore_world;

DELIMITER //

DROP PROCEDURE IF EXISTS frostforge_clone_item//

CREATE PROCEDURE frostforge_clone_item(
    IN p_source_entry INT,
    IN p_new_entry INT,
    IN p_new_name VARCHAR(255),
    IN p_new_displayid INT,
    IN p_allowable_class INT
)
BEGIN
    DROP TEMPORARY TABLE IF EXISTS tmp_frostforge_item;

    CREATE TEMPORARY TABLE tmp_frostforge_item LIKE item_template;

    INSERT INTO tmp_frostforge_item
    SELECT *
    FROM item_template
    WHERE entry = p_source_entry;

    IF (SELECT COUNT(*) FROM tmp_frostforge_item) = 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Source item not found in item_template';
    END IF;

    UPDATE tmp_frostforge_item
    SET
        entry = p_new_entry,
        name = p_new_name,
        displayid = IFNULL(p_new_displayid, displayid),
        RequiredLevel = 70,
        Quality = 4,
        bonding = 1,
        AllowableClass = p_allowable_class,
        description = 'Starter armor reforged for the heroes of Frostforge.';

    DELETE FROM item_template
    WHERE entry = p_new_entry;

    INSERT INTO item_template
    SELECT *
    FROM tmp_frostforge_item;

    DROP TEMPORARY TABLE IF EXISTS tmp_frostforge_item;
END//

DELIMITER ;

-- ============================================================
-- Class bitmasks
-- Warrior      = 1
-- Paladin      = 2
-- Hunter       = 4
-- Rogue        = 8
-- Priest       = 16
-- Death Knight = 32
-- Shaman       = 64
-- Mage         = 128
-- Warlock      = 256
-- Druid        = 1024
-- ============================================================


-- ============================================================
-- Warrior - Frostforged Dreadnaught
-- Stats: Bold / dungeon plate
-- Looks: Tier 3 Dreadnaught
-- Range: 990001-990009
-- ============================================================

CALL frostforge_clone_item(28350, 990001, 'Frostforged Dreadnaught Helmet',      36730, 1);
CALL frostforge_clone_item(27803, 990002, 'Frostforged Dreadnaught Pauldrons',   35177, 1);
CALL frostforge_clone_item(28205, 990003, 'Frostforged Dreadnaught Breastplate', 35049, 1);
CALL frostforge_clone_item(27475, 990004, 'Frostforged Dreadnaught Gauntlets',   35050, 1);
CALL frostforge_clone_item(27977, 990005, 'Frostforged Dreadnaught Legplates',   35051, 1);
CALL frostforge_clone_item(27985, 990006, 'Frostforged Dreadnaught Waistguard',  35058, 1);
CALL frostforge_clone_item(27788, 990007, 'Frostforged Dreadnaught Sabatons',    35067, 1);
CALL frostforge_clone_item(27459, 990008, 'Frostforged Dreadnaught Bracers',     35044, 1);
CALL frostforge_clone_item(34792, 990009, 'Frostforged Cloak of the Betrayed',   NULL,  1);


-- ============================================================
-- Paladin - Frostforged Redemption
-- Range: 990101-990109
-- ============================================================

CALL frostforge_clone_item(28285, 990101, 'Frostforged Redemption Headpiece',   36972, 2);
CALL frostforge_clone_item(27739, 990102, 'Frostforged Redemption Spaulders',   35617, 2);
CALL frostforge_clone_item(28203, 990103, 'Frostforged Redemption Tunic',       35618, 2);
CALL frostforge_clone_item(27535, 990104, 'Frostforged Redemption Handguards',  35615, 2);
CALL frostforge_clone_item(27839, 990105, 'Frostforged Redemption Legguards',   35616, 2);
CALL frostforge_clone_item(27672, 990106, 'Frostforged Redemption Girdle',      35614, 2);
CALL frostforge_clone_item(27813, 990107, 'Frostforged Redemption Boots',       35613, 2);
CALL frostforge_clone_item(27459, 990108, 'Frostforged Redemption Wristguards', 35619, 2);
CALL frostforge_clone_item(34792, 990109, 'Frostforged Cloak of Redemption',    NULL,  2);


-- ============================================================
-- Hunter - Frostforged Cryptstalker
-- Range: 990201-990209
-- ============================================================

CALL frostforge_clone_item(28275, 990201, 'Frostforged Cryptstalker Headpiece',   35601, 4);
CALL frostforge_clone_item(27801, 990202, 'Frostforged Cryptstalker Spaulders',   35611, 4);
CALL frostforge_clone_item(28228, 990203, 'Frostforged Cryptstalker Tunic',       35415, 4);
CALL frostforge_clone_item(27474, 990204, 'Frostforged Cryptstalker Handguards',  35411, 4);
CALL frostforge_clone_item(27874, 990205, 'Frostforged Cryptstalker Legguards',   35413, 4);
CALL frostforge_clone_item(27911, 990206, 'Frostforged Cryptstalker Girdle',      35410, 4);
CALL frostforge_clone_item(27867, 990207, 'Frostforged Cryptstalker Boots',       35409, 4);
CALL frostforge_clone_item(27712, 990208, 'Frostforged Cryptstalker Wristguards', 35416, 4);
CALL frostforge_clone_item(27892, 990209, 'Frostforged Cloak of the Cryptstalker', NULL, 4);


-- ============================================================
-- Rogue - Frostforged Bonescythe
-- Range: 990301-990309
-- ============================================================

CALL frostforge_clone_item(28414, 990301, 'Frostforged Bonescythe Helmet',      41849, 8);
CALL frostforge_clone_item(27776, 990302, 'Frostforged Bonescythe Pauldrons',   35064, 8);
CALL frostforge_clone_item(28204, 990303, 'Frostforged Bonescythe Breastplate', 35054, 8);
CALL frostforge_clone_item(27509, 990304, 'Frostforged Bonescythe Gauntlets',   35055, 8);
CALL frostforge_clone_item(27908, 990305, 'Frostforged Bonescythe Legplates',   35065, 8);
CALL frostforge_clone_item(27760, 990306, 'Frostforged Bonescythe Waistguard',  36349, 8);
CALL frostforge_clone_item(27867, 990307, 'Frostforged Bonescythe Sabatons',    36351, 8);
CALL frostforge_clone_item(27712, 990308, 'Frostforged Bonescythe Bracers',     35053, 8);
CALL frostforge_clone_item(27892, 990309, 'Frostforged Cloak of the Bonescythe', NULL, 8);


-- ============================================================
-- Priest - Frostforged Faith
-- Range: 990401-990409
-- ============================================================

CALL frostforge_clone_item(28413, 990401, 'Frostforged Circlet of Faith',      56051, 16);
CALL frostforge_clone_item(27775, 990402, 'Frostforged Shoulderpads of Faith', 35149, 16);
CALL frostforge_clone_item(28230, 990403, 'Frostforged Robe of Faith',         36354, 16);
CALL frostforge_clone_item(27536, 990404, 'Frostforged Gloves of Faith',       35145, 16);
CALL frostforge_clone_item(27875, 990405, 'Frostforged Leggings of Faith',     35154, 16);
CALL frostforge_clone_item(27542, 990406, 'Frostforged Belt of Faith',         35143, 16);
CALL frostforge_clone_item(27919, 990407, 'Frostforged Sandals of Faith',      35148, 16);
CALL frostforge_clone_item(27462, 990408, 'Frostforged Bindings of Faith',     35144, 16);
CALL frostforge_clone_item(27485, 990409, 'Frostforged Cape of Faith',         NULL,  16);


-- ============================================================
-- Death Knight - Frostforged Deathlord
-- Stats: Warrior-style starter gear
-- Looks: Tier 3 Dreadnaught
-- Range: 990501-990509
-- ============================================================

CALL frostforge_clone_item(28350, 990501, 'Frostforged Deathlord Helmet',      36730, 32);
CALL frostforge_clone_item(27803, 990502, 'Frostforged Deathlord Pauldrons',   35177, 32);
CALL frostforge_clone_item(28205, 990503, 'Frostforged Deathlord Battleplate', 35049, 32);
CALL frostforge_clone_item(27475, 990504, 'Frostforged Deathlord Gauntlets',   35050, 32);
CALL frostforge_clone_item(27977, 990505, 'Frostforged Deathlord Legplates',   35051, 32);
CALL frostforge_clone_item(27985, 990506, 'Frostforged Deathlord Waistguard',  35058, 32);
CALL frostforge_clone_item(27788, 990507, 'Frostforged Deathlord Sabatons',    35067, 32);
CALL frostforge_clone_item(27459, 990508, 'Frostforged Deathlord Bracers',     35044, 32);
CALL frostforge_clone_item(34792, 990509, 'Frostforged Cloak of the Deathlord', NULL, 32);


-- ============================================================
-- Shaman - Frostforged Earthshatter
-- Range: 990601-990609
-- ============================================================

CALL frostforge_clone_item(28349, 990601, 'Frostforged Earthshatter Headpiece',   42115, 64);
CALL frostforge_clone_item(27802, 990602, 'Frostforged Earthshatter Spaulders',   35751, 64);
CALL frostforge_clone_item(28231, 990603, 'Frostforged Earthshatter Tunic',       35752, 64);
CALL frostforge_clone_item(27510, 990604, 'Frostforged Earthshatter Handguards',  35748, 64);
CALL frostforge_clone_item(27909, 990605, 'Frostforged Earthshatter Legguards',   35754, 64);
CALL frostforge_clone_item(27743, 990606, 'Frostforged Earthshatter Girdle',      35747, 64);
CALL frostforge_clone_item(27411, 990607, 'Frostforged Earthshatter Boots',       35746, 64);
CALL frostforge_clone_item(27483, 990608, 'Frostforged Earthshatter Wristguards', 35753, 64);
CALL frostforge_clone_item(27485, 990609, 'Frostforged Cape of the Earthshatter', NULL,  64);


-- ============================================================
-- Mage - Frostforged Frostfire
-- Range: 990701-990709
-- ============================================================

CALL frostforge_clone_item(28278, 990701, 'Frostforged Frostfire Circlet',      36440, 128);
CALL frostforge_clone_item(27738, 990702, 'Frostforged Frostfire Shoulderpads', 35326, 128);
CALL frostforge_clone_item(28229, 990703, 'Frostforged Frostfire Robe',         35523, 128);
CALL frostforge_clone_item(27508, 990704, 'Frostforged Frostfire Gloves',       35521, 128);
CALL frostforge_clone_item(27838, 990705, 'Frostforged Frostfire Leggings',     35522, 128);
CALL frostforge_clone_item(27542, 990706, 'Frostforged Frostfire Belt',         35519, 128);
CALL frostforge_clone_item(27821, 990707, 'Frostforged Frostfire Sandals',      35525, 128);
CALL frostforge_clone_item(27462, 990708, 'Frostforged Frostfire Bindings',     35677, 128);
CALL frostforge_clone_item(28269, 990709, 'Frostforged Cloak of Frostfire',     NULL,  128);


-- ============================================================
-- Warlock - Frostforged Plagueheart
-- Range: 990801-990809
-- ============================================================

CALL frostforge_clone_item(28415, 990801, 'Frostforged Plagueheart Circlet',      35182, 256);
CALL frostforge_clone_item(27778, 990802, 'Frostforged Plagueheart Shoulderpads', 35187, 256);
CALL frostforge_clone_item(28232, 990803, 'Frostforged Plagueheart Robe',         35185, 256);
CALL frostforge_clone_item(27537, 990804, 'Frostforged Plagueheart Gloves',       35183, 256);
CALL frostforge_clone_item(27948, 990805, 'Frostforged Plagueheart Leggings',     35184, 256);
CALL frostforge_clone_item(27542, 990806, 'Frostforged Plagueheart Belt',         35179, 256);
CALL frostforge_clone_item(27821, 990807, 'Frostforged Plagueheart Sandals',      35186, 256);
CALL frostforge_clone_item(27462, 990808, 'Frostforged Plagueheart Bindings',     35180, 256);
CALL frostforge_clone_item(28269, 990809, 'Frostforged Cloak of Plagueheart',     NULL,  256);


-- ============================================================
-- Druid - Frostforged Dreamwalker
-- Range: 990901-990909
-- ============================================================

CALL frostforge_clone_item(28348, 990901, 'Frostforged Dreamwalker Headpiece',   35162, 1024);
CALL frostforge_clone_item(27737, 990902, 'Frostforged Dreamwalker Spaulders',   35160, 1024);
CALL frostforge_clone_item(28202, 990903, 'Frostforged Dreamwalker Robe',        35159, 1024);
CALL frostforge_clone_item(27468, 990904, 'Frostforged Dreamwalker Handguards',  35167, 1024);
CALL frostforge_clone_item(27873, 990905, 'Frostforged Dreamwalker Legguards',   35161, 1024);
CALL frostforge_clone_item(27760, 990906, 'Frostforged Dreamwalker Girdle',      35164, 1024);
CALL frostforge_clone_item(27867, 990907, 'Frostforged Dreamwalker Boots',       35173, 1024);
CALL frostforge_clone_item(27712, 990908, 'Frostforged Dreamwalker Wristguards', 35158, 1024);
CALL frostforge_clone_item(27485, 990909, 'Frostforged Cape of the Dreamwalker', NULL,  1024);


DROP PROCEDURE IF EXISTS frostforge_clone_item;


-- ============================================================
-- Verification
-- ============================================================

SELECT entry, name, displayid, InventoryType, RequiredLevel, ItemLevel, Quality, bonding, AllowableClass
FROM item_template
WHERE entry IN (
    990001,990002,990003,990004,990005,990006,990007,990008,990009,
    990101,990102,990103,990104,990105,990106,990107,990108,990109,
    990201,990202,990203,990204,990205,990206,990207,990208,990209,
    990301,990302,990303,990304,990305,990306,990307,990308,990309,
    990401,990402,990403,990404,990405,990406,990407,990408,990409,
    990501,990502,990503,990504,990505,990506,990507,990508,990509,
    990601,990602,990603,990604,990605,990606,990607,990608,990609,
    990701,990702,990703,990704,990705,990706,990707,990708,990709,
    990801,990802,990803,990804,990805,990806,990807,990808,990809,
    990901,990902,990903,990904,990905,990906,990907,990908,990909
)
ORDER BY entry;
