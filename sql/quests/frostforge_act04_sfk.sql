USE acore_world;

-- ==========================================================
-- Frostforge Act IV — Shadowfang Keep
-- Quests 900131-900135
-- NPCs 900047-900048
-- ==========================================================

-- ----------------------------------------------------------
-- Cleanup old Act IV data
-- ----------------------------------------------------------

DELETE FROM creature WHERE id1 IN (900047, 900048);
DELETE FROM creature_template WHERE entry IN (900047, 900048);

DELETE FROM quest_template_addon WHERE ID BETWEEN 900131 AND 900135;
DELETE FROM quest_offer_reward WHERE ID BETWEEN 900131 AND 900135;
DELETE FROM quest_request_items WHERE ID BETWEEN 900131 AND 900135;
DELETE FROM quest_template WHERE ID BETWEEN 900131 AND 900135;

-- Remove quest starter/ender relations for Act IV
DELETE FROM creature_queststarter WHERE quest IN (900131,900132,900133,900134,900135);
DELETE FROM creature_questender WHERE quest IN (900131,900132,900133,900134,900135);

-- ----------------------------------------------------------
-- NPC templates
-- Clone from existing Frostforge Defias Prisoner template
-- This avoids schema differences in creature_template columns.
-- ----------------------------------------------------------

DROP TEMPORARY TABLE IF EXISTS tmp_frostforge_sfk_template;
CREATE TEMPORARY TABLE tmp_frostforge_sfk_template LIKE creature_template;

INSERT INTO tmp_frostforge_sfk_template
SELECT *
FROM creature_template
WHERE entry = 900046
LIMIT 1;

UPDATE tmp_frostforge_sfk_template
SET
    entry = 900047,
    name = 'Frostforge Forsaken Scout',
    subname = 'Silverpine Watcher',
    minlevel = 27,
    maxlevel = 27,
    faction = 35,
    npcflag = 1,
    AIName = '',
    ScriptName = '';

INSERT INTO creature_template
SELECT *
FROM tmp_frostforge_sfk_template;

TRUNCATE TABLE tmp_frostforge_sfk_template;

INSERT INTO tmp_frostforge_sfk_template
SELECT *
FROM creature_template
WHERE entry = 900046
LIMIT 1;

UPDATE tmp_frostforge_sfk_template
SET
    entry = 900048,
    name = 'Frostforge Gilnean Refugee',
    subname = 'Survivor of the Curse',
    minlevel = 27,
    maxlevel = 27,
    faction = 35,
    npcflag = 1,
    AIName = '',
    ScriptName = '';

INSERT INTO creature_template
SELECT *
FROM tmp_frostforge_sfk_template;

DROP TEMPORARY TABLE IF EXISTS tmp_frostforge_sfk_template;

-- ----------------------------------------------------------
-- Quest templates
-- ----------------------------------------------------------

INSERT INTO quest_template
(
    ID,
    QuestType,
    QuestLevel,
    MinLevel,
    QuestSortID,
    QuestInfoID,
    SuggestedGroupNum,
    RequiredNpcOrGo1,
    RequiredNpcOrGo2,
    RequiredNpcOrGo3,
    RequiredNpcOrGo4,
    RequiredNpcOrGoCount1,
    RequiredNpcOrGoCount2,
    RequiredNpcOrGoCount3,
    RequiredNpcOrGoCount4,
    RewardXPDifficulty,
    RewardMoney,
    Flags,
    LogTitle,
    LogDescription,
    QuestDescription,
    AreaDescription,
    QuestCompletionLog,
    ObjectiveText1,
    ObjectiveText2,
    ObjectiveText3,
    ObjectiveText4,
    VerifiedBuild
)
VALUES
(
    900131,
    2,
    26,
    26,
    130,
    0,
    0,
    900011,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    'Shadows Over Silverpine',
    'Travel to Silverpine Forest and speak with Archivist Eldrin near The Sepulcher.',
    'Stormwind showed us rebellion, fear, and broken justice. But far to the north, another wound festers. In Silverpine, travelers vanish from the roads, villages fall silent, and from the ruined halls of Shadowfang Keep come howls that do not belong to wolves. Go to Silverpine Forest. I will meet you near The Sepulcher.',
    '',
    'Speak with Archivist Eldrin near The Sepulcher in Silverpine Forest.',
    'Archivist Eldrin found near The Sepulcher',
    '',
    '',
    '',
    0
),
(
    900132,
    2,
    26,
    26,
    130,
    0,
    0,
    900047,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    'The Howls in the Woods',
    'Speak with the Frostforge Forsaken Scout near The Sepulcher.',
    'The Forsaken keep watch over these roads, but even they fear what stalks the woods. Speak with the scout nearby and learn what has come down from Shadowfang Keep.',
    '',
    'Speak with the Frostforge Forsaken Scout near The Sepulcher.',
    'Forsaken Scout consulted',
    '',
    '',
    '',
    0
),
(
    900133,
    2,
    26,
    26,
    130,
    0,
    0,
    900048,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    'A Curse Behind Stone Walls',
    'Speak with the Frostforge Gilnean Refugee near The Sepulcher.',
    'The scout knows the attacks, but not the sorrow behind them. A refugee from Gilneas has seen what happens when men become beasts. Hear the warning before we go to the keep.',
    '',
    'Speak with the Frostforge Gilnean Refugee near The Sepulcher.',
    'Gilnean Refugee consulted',
    '',
    '',
    '',
    0
),
(
    900134,
    2,
    26,
    26,
    130,
    0,
    0,
    900011,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    'Gathering at Shadowfang Keep',
    'Travel to Shadowfang Keep and speak with Archivist Eldrin near the entrance.',
    'Arugal did not merely summon monsters. He opened the door to a curse. Shadowfang Keep is no longer a fortress. It is a den. Gather your allies at its gates.',
    '',
    'Speak with Archivist Eldrin near the entrance to Shadowfang Keep.',
    'Archivist Eldrin found at Shadowfang Keep',
    '',
    '',
    '',
    0
),
(
    900135,
    2,
    27,
    26,
    130,
    0,
    5,
    4275,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    'The Frostforge Path: Shadowfang Keep',
    'Enter Shadowfang Keep and defeat Archmage Arugal.',
    'Arugal’s magic brought the Worgen into this world as weapons. Now the curse has swallowed the keep and all who linger within it. Enter Shadowfang Keep, defeat Arugal, and end his command over the beasts.',
    '',
    'Return to Archivist Eldrin after defeating Archmage Arugal.',
    'Defeat Archmage Arugal',
    '',
    '',
    '',
    0
);

-- ----------------------------------------------------------
-- Quest addon: chain previous/next
-- ----------------------------------------------------------

INSERT INTO quest_template_addon
(ID, PrevQuestID, NextQuestID, ExclusiveGroup, BreadcrumbForQuestId)
VALUES
(900131, 900130, 900132, 0, 0),
(900132, 900131, 900133, 0, 0),
(900133, 900132, 900134, 0, 0),
(900134, 900133, 900135, 0, 0),
(900135, 900134, 0, 0, 0);

-- ----------------------------------------------------------
-- Quest text reward/request rows
-- ----------------------------------------------------------

INSERT INTO quest_offer_reward
(ID, RewardText, VerifiedBuild)
VALUES
(900131, 'You made it. Good. Silverpine does not welcome strangers, but the road ahead begins here.', 0),
(900132, 'The scout confirms it: these are not ordinary beasts. The keep is the source.', 0),
(900133, 'A curse born from desperation. Remember that. It is a pattern we will see again.', 0),
(900134, 'The keep waits. Gather your party, then speak with the Frostforge Guide when you are ready.', 0),
(900135, 'Arugal is defeated, but the curse he unleashed will not vanish with him. Power called in desperation rarely leaves when the battle is over.', 0);

INSERT INTO quest_request_items
(ID, CompletionText, VerifiedBuild)
VALUES
(900131, 'Have you reached Silverpine Forest?', 0),
(900132, 'What did the scout see in the woods?', 0),
(900133, 'What warning did the refugee give you?', 0),
(900134, 'Are you ready to enter Shadowfang Keep?', 0),
(900135, 'Has Archmage Arugal fallen?', 0);

-- ----------------------------------------------------------
-- Quest starters / enders
-- ----------------------------------------------------------

-- 900131 starts from Eldrin after Stockades, ends at Eldrin near Sepulcher
INSERT INTO creature_queststarter (id, quest) VALUES
(900011, 900131),
(900011, 900132),
(900011, 900133),
(900011, 900134),
(900011, 900135);

INSERT INTO creature_questender (id, quest) VALUES
(900011, 900131),
(900011, 900132),
(900011, 900133),
(900011, 900134),
(900011, 900135);

-- Scout and refugee are objective NPCs. They do not start/end quests.
-- Their objective credit will be handled in Lua gossip.

-- ----------------------------------------------------------
-- Spawns
-- ----------------------------------------------------------
-- NOTE:
-- GUIDs should be higher than your current custom range.
-- If these collide, change them.

DELETE FROM creature WHERE guid BETWEEN 5300780 AND 5300789;

-- Sepulcher hub
INSERT INTO creature
(guid, id1, map, zoneId, areaId, position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint, curhealth, curmana, MovementType, spawnMask, phaseMask)
VALUES
(5300780, 900011, 0, 130, 228, 506.0, 1613.0, 125.0, 3.1, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300781, 900047, 0, 130, 228, 512.0, 1608.0, 125.0, 2.8, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300782, 900048, 0, 130, 228, 500.0, 1605.0, 125.0, 0.5, 300, 0, 0, 1000, 0, 0, 1, 1);

-- Shadowfang Keep entrance
INSERT INTO creature
(guid, id1, map, zoneId, areaId, position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint, curhealth, curmana, MovementType, spawnMask, phaseMask)
VALUES
(5300783, 900010, 0, 130, 209, -233.0, 1567.0, 76.9, 1.2, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300784, 900011, 0, 130, 209, -236.0, 1564.0, 76.9, 1.2, 300, 0, 0, 1000, 0, 0, 1, 1);

-- Inside Shadowfang Keep, near entrance
INSERT INTO creature
(guid, id1, map, zoneId, areaId, position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint, curhealth, curmana, MovementType, spawnMask, phaseMask)
VALUES
(5300785, 900011, 33, 0, 0, -229.135, 2110.56, 76.8898, 1.267, 300, 0, 0, 1000, 0, 0, 1, 1);
