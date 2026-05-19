USE acore_world;

DELIMITER //

DROP PROCEDURE IF EXISTS frostforge_clone_extra//

CREATE PROCEDURE frostforge_clone_extra(
    IN p_source_entry INT,
    IN p_new_entry INT,
    IN p_new_name VARCHAR(255),
    IN p_allowable_class INT
)
BEGIN
    DROP TEMPORARY TABLE IF EXISTS tmp_frostforge_extra;

    CREATE TEMPORARY TABLE tmp_frostforge_extra LIKE item_template;

    INSERT INTO tmp_frostforge_extra
    SELECT *
    FROM item_template
    WHERE entry = p_source_entry;

    IF (SELECT COUNT(*) FROM tmp_frostforge_extra) = 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Source item not found in item_template';
    END IF;

    UPDATE tmp_frostforge_extra
    SET
        entry = p_new_entry,
        name = p_new_name,
        RequiredLevel = 70,
        Quality = 4,
        bonding = 1,
        AllowableClass = p_allowable_class,
        description = 'Starter equipment reforged for the heroes of Frostforge.';

    DELETE FROM item_template
    WHERE entry = p_new_entry;

    INSERT INTO item_template
    SELECT *
    FROM tmp_frostforge_extra;

    DROP TEMPORARY TABLE IF EXISTS tmp_frostforge_extra;
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
-- Warrior extras: 990010-990025
-- ============================================================

CALL frostforge_clone_extra(28168, 990010, 'Frostforged Insignia of the Warrior', 1);
CALL frostforge_clone_extra(27904, 990011, 'Frostforged Ring of Glory', 1);
CALL frostforge_clone_extra(28323, 990012, 'Frostforged Ring of Umbral Doom', 1);
CALL frostforge_clone_extra(29383, 990013, 'Frostforged Bloodlust Brooch', 1);
CALL frostforge_clone_extra(27891, 990014, 'Frostforged Adamantine Figurine', 1);

CALL frostforge_clone_extra(27986, 990020, 'Frostforged Crow Wing Reaper', 1);
CALL frostforge_clone_extra(27490, 990021, 'Frostforged Firebrand Battleaxe', 1);
CALL frostforge_clone_extra(27767, 990022, 'Frostforged Bogreaver', 1);
CALL frostforge_clone_extra(28210, 990023, 'Frostforged Bloodskull Destroyer', 1);
CALL frostforge_clone_extra(27449, 990024, 'Frostforged Blood Knight Defender', 1);
CALL frostforge_clone_extra(27817, 990025, 'Frostforged Starbolt Longbow', 1);


-- ============================================================
-- Paladin extras: 990110-990126
-- ============================================================

CALL frostforge_clone_extra(27792, 990110, 'Frostforged Chain of Valor', 2);
CALL frostforge_clone_extra(27904, 990111, 'Frostforged Ring of Glory', 2);
CALL frostforge_clone_extra(28265, 990112, 'Frostforged Ring of Defense', 2);
CALL frostforge_clone_extra(29383, 990113, 'Frostforged Bloodlust Brooch', 2);
CALL frostforge_clone_extra(27891, 990114, 'Frostforged Adamantine Figurine', 2);

CALL frostforge_clone_extra(27986, 990120, 'Frostforged Crow Wing Reaper', 2);
CALL frostforge_clone_extra(28210, 990121, 'Frostforged Bloodskull Destroyer', 2);
CALL frostforge_clone_extra(27449, 990122, 'Frostforged Blood Knight Defender', 2);
CALL frostforge_clone_extra(27484, 990125, 'Frostforged Libram of Avengement', 2);
CALL frostforge_clone_extra(27917, 990126, 'Frostforged Libram of Eternal Rest', 2);


-- ============================================================
-- Hunter extras: 990210-990222
-- ============================================================

CALL frostforge_clone_extra(28168, 990210, 'Frostforged Insignia of the Hunter', 4);
CALL frostforge_clone_extra(27904, 990211, 'Frostforged Ring of Glory', 4);
CALL frostforge_clone_extra(28323, 990212, 'Frostforged Ring of Umbral Doom', 4);
CALL frostforge_clone_extra(29383, 990213, 'Frostforged Bloodlust Brooch', 4);
CALL frostforge_clone_extra(27891, 990214, 'Frostforged Adamantine Figurine', 4);

CALL frostforge_clone_extra(27987, 990220, 'Frostforged Twilight Longbow', 4);
CALL frostforge_clone_extra(27903, 990221, 'Frostforged Sonic Spear', 4);
CALL frostforge_clone_extra(34105, 990222, 'Frostforged Quiver of a Thousand Feathers', 4);


-- ============================================================
-- Rogue extras: 990310-990322
-- ============================================================

CALL frostforge_clone_extra(28168, 990310, 'Frostforged Insignia of the Rogue', 8);
CALL frostforge_clone_extra(27904, 990311, 'Frostforged Ring of Glory', 8);
CALL frostforge_clone_extra(28323, 990312, 'Frostforged Ring of Umbral Doom', 8);
CALL frostforge_clone_extra(29383, 990313, 'Frostforged Bloodlust Brooch', 8);
CALL frostforge_clone_extra(27891, 990314, 'Frostforged Adamantine Figurine', 8);

CALL frostforge_clone_extra(31305, 990320, 'Frostforged Ced''s Carver', 8);
CALL frostforge_clone_extra(32659, 990321, 'Frostforged Crystal-Infused Shiv', 8);
CALL frostforge_clone_extra(29211, 990322, 'Frostforged Throwing Axe', 8);


-- ============================================================
-- Priest extras: 990410-990423
-- ============================================================

CALL frostforge_clone_extra(28233, 990410, 'Frostforged Necklace of Hope', 16);
CALL frostforge_clone_extra(27780, 990411, 'Frostforged Ring of Fabled Hope', 16);
CALL frostforge_clone_extra(28227, 990412, 'Frostforged Arcanite Ring', 16);
CALL frostforge_clone_extra(29376, 990413, 'Frostforged Essence of the Martyr', 16);
CALL frostforge_clone_extra(28190, 990414, 'Frostforged Scarab of the Infinite Cycle', 16);

CALL frostforge_clone_extra(27791, 990420, 'Frostforged Serpentcrest Life-Staff', 16);
CALL frostforge_clone_extra(28322, 990421, 'Frostforged Runed Dagger of Solace', 16);
CALL frostforge_clone_extra(28213, 990422, 'Frostforged Lordaeron Medical Guide', 16);
CALL frostforge_clone_extra(27540, 990423, 'Frostforged Nexus Torch', 16);


-- ============================================================
-- Death Knight extras: 990510-990523
-- ============================================================

CALL frostforge_clone_extra(28168, 990510, 'Frostforged Insignia of the Deathlord', 32);
CALL frostforge_clone_extra(27904, 990511, 'Frostforged Ring of Glory', 32);
CALL frostforge_clone_extra(28323, 990512, 'Frostforged Ring of Umbral Doom', 32);
CALL frostforge_clone_extra(29383, 990513, 'Frostforged Bloodlust Brooch', 32);
CALL frostforge_clone_extra(27891, 990514, 'Frostforged Adamantine Figurine', 32);

CALL frostforge_clone_extra(27986, 990520, 'Frostforged Deathlord Reaper', 32);
CALL frostforge_clone_extra(27490, 990521, 'Frostforged Deathlord Battleaxe', 32);
CALL frostforge_clone_extra(27767, 990522, 'Frostforged Deathlord Bogreaver', 32);
CALL frostforge_clone_extra(28210, 990523, 'Frostforged Deathlord Destroyer', 32);


-- ============================================================
-- Shaman extras: 990610-990628
-- ============================================================

CALL frostforge_clone_extra(28233, 990610, 'Frostforged Necklace of the Earthshatter', 64);
CALL frostforge_clone_extra(27780, 990611, 'Frostforged Ring of Fabled Hope', 64);
CALL frostforge_clone_extra(28227, 990612, 'Frostforged Arcanite Ring', 64);
CALL frostforge_clone_extra(29376, 990613, 'Frostforged Essence of the Martyr', 64);
CALL frostforge_clone_extra(28190, 990614, 'Frostforged Scarab of the Infinite Cycle', 64);

CALL frostforge_clone_extra(27791, 990620, 'Frostforged Serpentcrest Life-Staff', 64);
CALL frostforge_clone_extra(28322, 990621, 'Frostforged Runed Dagger of Solace', 64);
CALL frostforge_clone_extra(28213, 990622, 'Frostforged Lordaeron Medical Guide', 64);
CALL frostforge_clone_extra(27772, 990623, 'Frostforged Stormshield of Renewal', 64);
CALL frostforge_clone_extra(27490, 990624, 'Frostforged Firebrand Battleaxe', 64);
CALL frostforge_clone_extra(27767, 990625, 'Frostforged Bogreaver', 64);
CALL frostforge_clone_extra(27544, 990626, 'Frostforged Totem of Regrowth', 64);
CALL frostforge_clone_extra(27815, 990627, 'Frostforged Totem of Astral Winds', 64);
CALL frostforge_clone_extra(28248, 990628, 'Frostforged Totem of the Void', 64);


-- ============================================================
-- Mage extras: 990710-990723
-- ============================================================

CALL frostforge_clone_extra(28134, 990710, 'Frostforged Brooch of Potential', 128);
CALL frostforge_clone_extra(28227, 990711, 'Frostforged Arcanite Ring', 128);
CALL frostforge_clone_extra(28327, 990712, 'Frostforged Arcane Netherband', 128);
CALL frostforge_clone_extra(29370, 990713, 'Frostforged Icon of the Silver Crescent', 128);
CALL frostforge_clone_extra(28190, 990714, 'Frostforged Scarab of the Infinite Cycle', 128);

CALL frostforge_clone_extra(27791, 990720, 'Frostforged Serpentcrest Staff', 128);
CALL frostforge_clone_extra(28322, 990721, 'Frostforged Runed Dagger of Solace', 128);
CALL frostforge_clone_extra(28213, 990722, 'Frostforged Lordaeron Medical Guide', 128);
CALL frostforge_clone_extra(28386, 990723, 'Frostforged Nether Core Control Rod', 128);


-- ============================================================
-- Warlock extras: 990810-990824
-- ============================================================

CALL frostforge_clone_extra(28134, 990810, 'Frostforged Brooch of Potential', 256);
CALL frostforge_clone_extra(28227, 990811, 'Frostforged Arcanite Ring', 256);
CALL frostforge_clone_extra(28327, 990812, 'Frostforged Arcane Netherband', 256);
CALL frostforge_clone_extra(29370, 990813, 'Frostforged Icon of the Silver Crescent', 256);
CALL frostforge_clone_extra(28190, 990814, 'Frostforged Scarab of the Infinite Cycle', 256);

CALL frostforge_clone_extra(27791, 990820, 'Frostforged Serpentcrest Staff', 256);
CALL frostforge_clone_extra(28322, 990821, 'Frostforged Runed Dagger of Solace', 256);
CALL frostforge_clone_extra(28213, 990822, 'Frostforged Lordaeron Medical Guide', 256);
CALL frostforge_clone_extra(28386, 990823, 'Frostforged Nether Core Control Rod', 256);
CALL frostforge_clone_extra(21340, 990824, 'Frostforged Soul Pouch', 256);


-- ============================================================
-- Druid extras: 990910-990926
-- ============================================================

CALL frostforge_clone_extra(28233, 990910, 'Frostforged Necklace of the Dreamwalker', 1024);
CALL frostforge_clone_extra(27780, 990911, 'Frostforged Ring of Fabled Hope', 1024);
CALL frostforge_clone_extra(28227, 990912, 'Frostforged Arcanite Ring', 1024);
CALL frostforge_clone_extra(29376, 990913, 'Frostforged Essence of the Martyr', 1024);
CALL frostforge_clone_extra(28190, 990914, 'Frostforged Scarab of the Infinite Cycle', 1024);

CALL frostforge_clone_extra(27791, 990920, 'Frostforged Serpentcrest Life-Staff', 1024);
CALL frostforge_clone_extra(28322, 990921, 'Frostforged Runed Dagger of Solace', 1024);
CALL frostforge_clone_extra(28213, 990922, 'Frostforged Lordaeron Medical Guide', 1024);
CALL frostforge_clone_extra(27903, 990923, 'Frostforged Sonic Spear', 1024);
CALL frostforge_clone_extra(28372, 990924, 'Frostforged Idol of Feral Shadows', 1024);
CALL frostforge_clone_extra(27886, 990925, 'Frostforged Idol of the Emerald Queen', 1024);
CALL frostforge_clone_extra(27518, 990926, 'Frostforged Ivory Idol of the Moongoddess', 1024);


DROP PROCEDURE IF EXISTS frostforge_clone_extra;


-- ============================================================
-- Verification
-- ============================================================

SELECT entry, name, class, subclass, displayid, InventoryType, RequiredLevel, ItemLevel, Quality, bonding, AllowableClass
FROM item_template
WHERE entry BETWEEN 990001 AND 990999
ORDER BY entry;
