USE acore_world;

-- ==========================================================
-- Frostforge Act V-XI Batch
-- Blackfathom Deeps, Gnomeregan, Razorfen Kraul, Scarlet Monastery
-- Quests: 900136-900155
-- NPCs: 900049-900056
-- ==========================================================

-- ----------------------------------------------------------
-- Cleanup old data
-- ----------------------------------------------------------

DELETE FROM creature WHERE id1 IN (900049,900050,900051,900052,900053,900054,900055,900056);
DELETE FROM creature WHERE guid BETWEEN 5300790 AND 5300839;

DELETE FROM creature_template WHERE entry IN (900049,900050,900051,900052,900053,900054,900055,900056);

DELETE FROM quest_template_addon WHERE ID BETWEEN 900136 AND 900155;
DELETE FROM quest_offer_reward WHERE ID BETWEEN 900136 AND 900155;
DELETE FROM quest_request_items WHERE ID BETWEEN 900136 AND 900155;
DELETE FROM quest_template WHERE ID BETWEEN 900136 AND 900155;

DELETE FROM creature_queststarter WHERE quest BETWEEN 900136 AND 900155;
DELETE FROM creature_questender WHERE quest BETWEEN 900136 AND 900155;

-- ----------------------------------------------------------
-- NPC templates
-- Clone from existing Frostforge Defias Prisoner template 900046
-- This avoids creature_template schema issues.
-- ----------------------------------------------------------

DROP TEMPORARY TABLE IF EXISTS tmp_frostforge_template;
CREATE TEMPORARY TABLE tmp_frostforge_template LIKE creature_template;

-- 900049 Frostforge Twilight Acolyte
INSERT INTO tmp_frostforge_template SELECT * FROM creature_template WHERE entry = 900046 LIMIT 1;
UPDATE tmp_frostforge_template
SET entry = 900049,
    name = 'Frostforge Twilight Acolyte',
    subname = 'Whisper of the Depths',
    minlevel = 29,
    maxlevel = 29,
    faction = 35,
    npcflag = 1,
    AIName = '',
    ScriptName = '';
INSERT INTO creature_template SELECT * FROM tmp_frostforge_template;
TRUNCATE TABLE tmp_frostforge_template;

-- 900050 Frostforge Zoram Scout
INSERT INTO tmp_frostforge_template SELECT * FROM creature_template WHERE entry = 900046 LIMIT 1;
UPDATE tmp_frostforge_template
SET entry = 900050,
    name = 'Frostforge Zoram Scout',
    subname = 'Watcher of the Shore',
    minlevel = 29,
    maxlevel = 29,
    faction = 35,
    npcflag = 1,
    AIName = '',
    ScriptName = '';
INSERT INTO creature_template SELECT * FROM tmp_frostforge_template;
TRUNCATE TABLE tmp_frostforge_template;

-- 900051 Frostforge Gnome Survivor
INSERT INTO tmp_frostforge_template SELECT * FROM creature_template WHERE entry = 900046 LIMIT 1;
UPDATE tmp_frostforge_template
SET entry = 900051,
    name = 'Frostforge Gnome Survivor',
    subname = 'Exile of Gnomeregan',
    minlevel = 31,
    maxlevel = 31,
    faction = 35,
    npcflag = 1,
    AIName = '',
    ScriptName = '';
INSERT INTO creature_template SELECT * FROM tmp_frostforge_template;
TRUNCATE TABLE tmp_frostforge_template;

-- 900052 Frostforge Irradiated Technician
INSERT INTO tmp_frostforge_template SELECT * FROM creature_template WHERE entry = 900046 LIMIT 1;
UPDATE tmp_frostforge_template
SET entry = 900052,
    name = 'Frostforge Irradiated Technician',
    subname = 'Witness to Betrayal',
    minlevel = 31,
    maxlevel = 31,
    faction = 35,
    npcflag = 1,
    AIName = '',
    ScriptName = '';
INSERT INTO creature_template SELECT * FROM tmp_frostforge_template;
TRUNCATE TABLE tmp_frostforge_template;

-- 900053 Frostforge Barrens Messenger
INSERT INTO tmp_frostforge_template SELECT * FROM creature_template WHERE entry = 900046 LIMIT 1;
UPDATE tmp_frostforge_template
SET entry = 900053,
    name = 'Frostforge Barrens Messenger',
    subname = 'Bearer of Warnings',
    minlevel = 33,
    maxlevel = 33,
    faction = 35,
    npcflag = 1,
    AIName = '',
    ScriptName = '';
INSERT INTO creature_template SELECT * FROM tmp_frostforge_template;
TRUNCATE TABLE tmp_frostforge_template;

-- 900054 Frostforge Quilboar Captive
INSERT INTO tmp_frostforge_template SELECT * FROM creature_template WHERE entry = 900046 LIMIT 1;
UPDATE tmp_frostforge_template
SET entry = 900054,
    name = 'Frostforge Quilboar Captive',
    subname = 'Razormane Outcast',
    minlevel = 33,
    maxlevel = 33,
    faction = 35,
    npcflag = 1,
    AIName = '',
    ScriptName = '';
INSERT INTO creature_template SELECT * FROM tmp_frostforge_template;
TRUNCATE TABLE tmp_frostforge_template;

-- 900055 Frostforge Scarlet Defector
INSERT INTO tmp_frostforge_template SELECT * FROM creature_template WHERE entry = 900046 LIMIT 1;
UPDATE tmp_frostforge_template
SET entry = 900055,
    name = 'Frostforge Scarlet Defector',
    subname = 'Former Crusader',
    minlevel = 35,
    maxlevel = 35,
    faction = 35,
    npcflag = 1,
    AIName = '',
    ScriptName = '';
INSERT INTO creature_template SELECT * FROM tmp_frostforge_template;
TRUNCATE TABLE tmp_frostforge_template;

-- 900056 Frostforge Forsaken Observer
INSERT INTO tmp_frostforge_template SELECT * FROM creature_template WHERE entry = 900046 LIMIT 1;
UPDATE tmp_frostforge_template
SET entry = 900056,
    name = 'Frostforge Forsaken Observer',
    subname = 'Watcher of the Monastery',
    minlevel = 35,
    maxlevel = 35,
    faction = 35,
    npcflag = 1,
    AIName = '',
    ScriptName = '';
INSERT INTO creature_template SELECT * FROM tmp_frostforge_template;

DROP TEMPORARY TABLE IF EXISTS tmp_frostforge_template;

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

-- ==========================================================
-- Act V — Blackfathom Deeps
-- ==========================================================

(900136, 2, 27, 26, 130, 0, 0,
 900011, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'Whispers Beneath the Waves',
 'Travel to the Zoram Strand in Ashenvale and speak with Archivist Eldrin.',
 'Arugal showed us what happens when desperate magic becomes a curse. Now we turn to older whispers. On the coast of Ashenvale, ancient ruins sink into the sea, and the Twilight''s Hammer gathers where the deep places call. Travel to the Zoram Strand. I will meet you there.',
 '',
 'Speak with Archivist Eldrin at the Zoram Strand.',
 'Archivist Eldrin found at the Zoram Strand', '', '', '', 0),

(900137, 2, 28, 26, 130, 0, 0,
 900050, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Shore Watcher',
 'Speak with the Frostforge Zoram Scout at the Zoram Strand.',
 'The coast is not quiet. Naga patrol the waters, cultists move through the ruins, and something beneath Blackfathom Deeps answers them. Speak with the Zoram Scout and learn what has been seen from the shore.',
 '',
 'Speak with the Frostforge Zoram Scout.',
 'Zoram Scout consulted', '', '', '', 0),

(900138, 2, 28, 26, 130, 0, 0,
 900049, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Twilight Below',
 'Confront the Frostforge Twilight Acolyte near the entrance to Blackfathom Deeps.',
 'The Twilight''s Hammer does not worship power as kings do. They worship ruin. One of their acolytes lingers near the ruins. Hear the shape of the threat before we descend.',
 '',
 'Confront the Frostforge Twilight Acolyte.',
 'Twilight Acolyte confronted', '', '', '', 0),

(900139, 2, 28, 26, 130, 0, 0,
 900011, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'Gathering at Blackfathom Deeps',
 'Travel to Blackfathom Deeps and speak with Archivist Eldrin near the entrance.',
 'The ruins are awake with cultists, naga, and old whispers. Gather your allies at Blackfathom Deeps. The Frostforge Guide will prepare your party.',
 '',
 'Speak with Archivist Eldrin near Blackfathom Deeps.',
 'Archivist Eldrin found at Blackfathom Deeps', '', '', '', 0),

(900140, 2, 29, 26, 130, 0, 5,
 4829, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Frostforge Path: Blackfathom Deeps',
 'Enter Blackfathom Deeps and defeat Aku''mai.',
 'Aku''mai is more than a beast. To the Twilight''s Hammer, it is a sign that the deep places still listen. Enter Blackfathom Deeps and silence the creature at the heart of the ruins.',
 '',
 'Return to Archivist Eldrin after defeating Aku''mai.',
 'Defeat Aku''mai', '', '', '', 0),

-- ==========================================================
-- Act VI — Gnomeregan
-- ==========================================================

(900141, 2, 29, 26, 130, 0, 0,
 900011, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Fallen City of Gnomes',
 'Travel to Gnomeregan and speak with Archivist Eldrin near the entrance.',
 'From the drowned ruins of Blackfathom, we turn to a different disaster: not ancient whispers, but invention twisted by betrayal. Gnomeregan was once a marvel. Now it is a warning. Travel to its entrance. I will meet you there.',
 '',
 'Speak with Archivist Eldrin near Gnomeregan.',
 'Archivist Eldrin found near Gnomeregan', '', '', '', 0),

(900142, 2, 30, 26, 130, 0, 0,
 900051, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'Exile of Gnomeregan',
 'Speak with the Frostforge Gnome Survivor near Gnomeregan.',
 'The story of Gnomeregan is not only machines and radiation. It is the story of a people driven out of their own home. Speak with the survivor and learn what was lost.',
 '',
 'Speak with the Frostforge Gnome Survivor.',
 'Gnome Survivor consulted', '', '', '', 0),

(900143, 2, 30, 26, 130, 0, 0,
 900052, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'Betrayal in the Machine',
 'Speak with the Frostforge Irradiated Technician near Gnomeregan.',
 'Thermaplugg did not merely fail his people. He used disaster as a ladder. A technician nearby survived the evacuation and remembers the betrayal.',
 '',
 'Speak with the Frostforge Irradiated Technician.',
 'Irradiated Technician consulted', '', '', '', 0),

(900144, 2, 30, 26, 130, 0, 0,
 900011, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'Gathering at Gnomeregan',
 'Gather your allies at Gnomeregan and speak with Archivist Eldrin.',
 'The city below is poisoned, overrun, and ruled by the one who profited from its fall. Gather your party. The Frostforge Guide will send you inside.',
 '',
 'Speak with Archivist Eldrin at Gnomeregan.',
 'Archivist Eldrin found at Gnomeregan', '', '', '', 0),

(900145, 2, 31, 26, 130, 0, 5,
 7800, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Frostforge Path: Gnomeregan',
 'Enter Gnomeregan and defeat Mekgineer Thermaplugg.',
 'Thermaplugg sits at the center of the ruined city, surrounded by the consequences of his ambition. Enter Gnomeregan and bring down the traitor.',
 '',
 'Return to Archivist Eldrin after defeating Mekgineer Thermaplugg.',
 'Defeat Mekgineer Thermaplugg', '', '', '', 0),

-- ==========================================================
-- Act VII — Razorfen Kraul
-- ==========================================================

(900146, 2, 31, 26, 130, 0, 0,
 900011, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'Thorns in the Barrens',
 'Travel to Razorfen Kraul and speak with Archivist Eldrin near the entrance.',
 'The Barrens taught us that survival shapes every people differently. In Razorfen Kraul, the quilboar have turned survival into thorn, blood, and ritual. Travel to the Kraul. I will meet you near its entrance.',
 '',
 'Speak with Archivist Eldrin near Razorfen Kraul.',
 'Archivist Eldrin found near Razorfen Kraul', '', '', '', 0),

(900147, 2, 32, 26, 130, 0, 0,
 900053, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'Warnings from the Road',
 'Speak with the Frostforge Barrens Messenger near Razorfen Kraul.',
 'Travelers avoid the thorns for good reason. A messenger from the Barrens has seen raids, disappearances, and strange rituals near the Kraul.',
 '',
 'Speak with the Frostforge Barrens Messenger.',
 'Barrens Messenger consulted', '', '', '', 0),

(900148, 2, 32, 26, 130, 0, 0,
 900054, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Captive in the Thorns',
 'Speak with the Frostforge Quilboar Captive near Razorfen Kraul.',
 'Not every quilboar follows the same path. One captive claims Charlga Razorflank has bound the tribe to darker rites. Hear the warning before entering the Kraul.',
 '',
 'Speak with the Frostforge Quilboar Captive.',
 'Quilboar Captive consulted', '', '', '', 0),

(900149, 2, 32, 26, 130, 0, 0,
 900011, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'Gathering at Razorfen Kraul',
 'Gather your allies at Razorfen Kraul and speak with Archivist Eldrin.',
 'Charlga rules from within the thorns. Gather your party at Razorfen Kraul. The Frostforge Guide will send you inside.',
 '',
 'Speak with Archivist Eldrin at Razorfen Kraul.',
 'Archivist Eldrin found at Razorfen Kraul', '', '', '', 0),

(900150, 2, 33, 26, 130, 0, 5,
 4421, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Frostforge Path: Razorfen Kraul',
 'Enter Razorfen Kraul and defeat Charlga Razorflank.',
 'The Kraul is a maze of thorns, ritual, and desperation. Enter Razorfen Kraul and defeat Charlga Razorflank.',
 '',
 'Return to Archivist Eldrin after defeating Charlga Razorflank.',
 'Defeat Charlga Razorflank', '', '', '', 0),

-- ==========================================================
-- Act VIII-XI — Scarlet Monastery
-- ==========================================================

(900151, 2, 33, 26, 130, 0, 0,
 900055, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Scarlet Road',
 'Travel to Scarlet Monastery and speak with the Frostforge Scarlet Defector.',
 'The Scarlet Crusade claims to protect the living from the undead. But zealotry has a hunger of its own. Travel to the Scarlet Monastery and speak with one who escaped its doctrine.',
 '',
 'Speak with the Frostforge Scarlet Defector at Scarlet Monastery.',
 'Scarlet Defector consulted', '', '', '', 0),

(900152, 2, 35, 26, 130, 0, 5,
 4543, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Frostforge Path: Scarlet Monastery Graveyard',
 'Enter Scarlet Monastery Graveyard and defeat Bloodmage Thalnos.',
 'The Graveyard shows the Crusade''s first contradiction: even among the dead, they cannot escape corruption. Enter the Graveyard and defeat Bloodmage Thalnos.',
 '',
 'Return to Archivist Eldrin after defeating Bloodmage Thalnos.',
 'Defeat Bloodmage Thalnos', '', '', '', 0),

(900153, 2, 37, 26, 130, 0, 5,
 6487, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Frostforge Path: Scarlet Monastery Library',
 'Enter Scarlet Monastery Library and defeat Arcanist Doan.',
 'The Library is where zeal becomes doctrine. Books, sermons, and orders turn fear into certainty. Enter the Library and defeat Arcanist Doan.',
 '',
 'Return to Archivist Eldrin after defeating Arcanist Doan.',
 'Defeat Arcanist Doan', '', '', '', 0),

(900154, 2, 39, 26, 130, 0, 5,
 3975, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Frostforge Path: Scarlet Monastery Armory',
 'Enter Scarlet Monastery Armory and defeat Herod.',
 'The Armory is where doctrine becomes violence. The Crusade trains its champions here, sharpening faith into steel. Enter the Armory and defeat Herod.',
 '',
 'Return to Archivist Eldrin after defeating Herod.',
 'Defeat Herod', '', '', '', 0),

(900155, 2, 40, 26, 130, 0, 5,
 3977, 0, 0, 0, 1, 0, 0, 0,
 0, 0, 0,
 'The Frostforge Path: Scarlet Monastery Cathedral',
 'Enter Scarlet Monastery Cathedral and defeat High Inquisitor Whitemane.',
 'The Cathedral is the heart of Scarlet certainty. Here, fanaticism wears the face of righteousness. Enter the Cathedral and defeat High Inquisitor Whitemane.',
 '',
 'Return to Archivist Eldrin after defeating High Inquisitor Whitemane.',
 'Defeat High Inquisitor Whitemane', '', '', '', 0);

-- ----------------------------------------------------------
-- Quest addon chains
-- ----------------------------------------------------------

INSERT INTO quest_template_addon
(ID, PrevQuestID, NextQuestID, ExclusiveGroup, BreadcrumbForQuestId)
VALUES
(900136, 900135, 900137, 0, 0),
(900137, 900136, 900138, 0, 0),
(900138, 900137, 900139, 0, 0),
(900139, 900138, 900140, 0, 0),
(900140, 900139, 900141, 0, 0),

(900141, 900140, 900142, 0, 0),
(900142, 900141, 900143, 0, 0),
(900143, 900142, 900144, 0, 0),
(900144, 900143, 900145, 0, 0),
(900145, 900144, 900146, 0, 0),

(900146, 900145, 900147, 0, 0),
(900147, 900146, 900148, 0, 0),
(900148, 900147, 900149, 0, 0),
(900149, 900148, 900150, 0, 0),
(900150, 900149, 900151, 0, 0),

(900151, 900150, 900152, 0, 0),
(900152, 900151, 900153, 0, 0),
(900153, 900152, 900154, 0, 0),
(900154, 900153, 900155, 0, 0),
(900155, 900154, 0, 0, 0);

-- ----------------------------------------------------------
-- Quest offer rewards
-- ----------------------------------------------------------

INSERT INTO quest_offer_reward (ID, RewardText, VerifiedBuild)
VALUES
(900136, 'You made it to the Zoram Strand. Good. The sea is never silent here.', 0),
(900137, 'The shore confirms the danger. The ruins are active, and the cult is moving.', 0),
(900138, 'The Twilight''s Hammer hears something in the depths. That alone should worry us.', 0),
(900139, 'The entrance waits. Gather your party and prepare to descend.', 0),
(900140, 'Aku''mai is defeated. But remember this: the deep places of Azeroth are rarely empty.', 0),

(900141, 'Gnomeregan stands before us: a city of genius, ruin, and betrayal.', 0),
(900142, 'The survivor reminds us that disasters are measured in people, not machines.', 0),
(900143, 'Thermaplugg turned catastrophe into power. That ends now.', 0),
(900144, 'Your party is ready. Enter Gnomeregan and face the traitor below.', 0),
(900145, 'Thermaplugg has fallen. Gnomeregan is not restored, but justice has entered its halls.', 0),

(900146, 'The thorns of Razorfen Kraul wait ahead.', 0),
(900147, 'The roads speak of raids, rituals, and fear. The Kraul must be entered.', 0),
(900148, 'Charlga''s rule is not merely tribal. Something darker has taken root.', 0),
(900149, 'Gather your party. The thorns will not open for the unprepared.', 0),
(900150, 'Charlga Razorflank is defeated. The Kraul remains dangerous, but its ruler has fallen.', 0),

(900151, 'So the Crusade has begun to crack. Good. We will widen that crack.', 0),
(900152, 'The Graveyard is cleared. Even the Scarlet Crusade cannot fully bury corruption.', 0),
(900153, 'Doan is defeated. The words of zeal are quieter now.', 0),
(900154, 'Herod has fallen. The Crusade has lost one of its sharpened blades.', 0),
(900155, 'Whitemane is defeated. The Scarlet Monastery still stands, but its certainty has been wounded.', 0);

-- ----------------------------------------------------------
-- Quest request text
-- ----------------------------------------------------------

INSERT INTO quest_request_items (ID, CompletionText, VerifiedBuild)
VALUES
(900136, 'Have you reached the Zoram Strand?', 0),
(900137, 'What did the scout see from the shore?', 0),
(900138, 'What did the Twilight acolyte reveal?', 0),
(900139, 'Are your allies gathered at Blackfathom Deeps?', 0),
(900140, 'Has Aku''mai fallen?', 0),

(900141, 'Have you reached Gnomeregan?', 0),
(900142, 'What did the survivor tell you?', 0),
(900143, 'What did the technician remember?', 0),
(900144, 'Are you ready to enter Gnomeregan?', 0),
(900145, 'Has Thermaplugg fallen?', 0),

(900146, 'Have you reached Razorfen Kraul?', 0),
(900147, 'What warning did the messenger carry?', 0),
(900148, 'What did the captive tell you?', 0),
(900149, 'Are you ready to enter Razorfen Kraul?', 0),
(900150, 'Has Charlga Razorflank fallen?', 0),

(900151, 'What did the defector tell you?', 0),
(900152, 'Has Bloodmage Thalnos fallen?', 0),
(900153, 'Has Arcanist Doan fallen?', 0),
(900154, 'Has Herod fallen?', 0),
(900155, 'Has High Inquisitor Whitemane fallen?', 0);

-- ----------------------------------------------------------
-- Quest starters / enders
-- ----------------------------------------------------------

-- Eldrin starts/ends most campaign quests
INSERT INTO creature_queststarter (id, quest) VALUES
(900011,900136),
(900011,900137),
(900011,900138),
(900011,900139),
(900011,900140),
(900011,900141),
(900011,900142),
(900011,900143),
(900011,900144),
(900011,900145),
(900011,900146),
(900011,900147),
(900011,900148),
(900011,900149),
(900011,900150),
(900011,900152),
(900011,900153),
(900011,900154),
(900011,900155),

-- Scarlet intro starts from the defector
(900055,900151);

INSERT INTO creature_questender (id, quest) VALUES
(900011,900136),
(900011,900137),
(900011,900138),
(900011,900139),
(900011,900140),
(900011,900141),
(900011,900142),
(900011,900143),
(900011,900144),
(900011,900145),
(900011,900146),
(900011,900147),
(900011,900148),
(900011,900149),
(900011,900150),
(900011,900152),
(900011,900153),
(900011,900154),
(900011,900155),

-- Scarlet intro ends at Eldrin
(900011,900151);

-- ----------------------------------------------------------
-- Spawns
-- ----------------------------------------------------------

-- BFD / Zoram Strand hub
INSERT INTO creature
(guid, id1, map, zoneId, areaId, position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint, curhealth, curmana, MovementType, spawnMask, phaseMask)
VALUES
(5300790, 900011, 1, 331, 331, 3650.0, 928.0, 6.0, 3.2, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300791, 900050, 1, 331, 331, 3654.0, 925.0, 6.0, 2.7, 300, 0, 0, 1000, 0, 0, 1, 1),

-- BFD entrance
(5300792, 900010, 1, 331, 331, 4247.74, 745.879, -24.5299, 1.35, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300793, 900011, 1, 331, 331, 4244.0, 748.0, -24.5299, 1.35, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300794, 900049, 1, 331, 331, 4241.0, 751.0, -24.5299, 1.35, 300, 0, 0, 1000, 0, 0, 1, 1),

-- BFD inside
(5300795, 900011, 48, 0, 0, -150.234, 106.594, -40.095, 4.45, 300, 0, 0, 1000, 0, 0, 1, 1),

-- Gnomeregan entrance
(5300800, 900010, 0, 1, 721, -5163.54, 925.423, 257.181, 2.77, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300801, 900011, 0, 1, 721, -5160.0, 927.0, 257.181, 2.77, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300802, 900051, 0, 1, 721, -5157.0, 930.0, 257.181, 2.77, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300803, 900052, 0, 1, 721, -5166.0, 930.0, 257.181, 2.77, 300, 0, 0, 1000, 0, 0, 1, 1),

-- Gnomeregan inside
(5300804, 900011, 90, 0, 0, -332.22, -2.28, -150.86, 2.77, 300, 0, 0, 1000, 0, 0, 1, 1),

-- RFK entrance
(5300810, 900010, 1, 17, 491, -4464.92, -1666.24, 81.8928, 1.15, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300811, 900011, 1, 17, 491, -4461.0, -1663.0, 81.8928, 1.15, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300812, 900053, 1, 17, 491, -4458.0, -1660.0, 81.8928, 1.15, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300813, 900054, 1, 17, 491, -4468.0, -1660.0, 81.8928, 1.15, 300, 0, 0, 1000, 0, 0, 1, 1),

-- RFK inside
(5300814, 900011, 47, 0, 0, 1943.0, 1544.63, 82.56, 1.38, 300, 0, 0, 1000, 0, 0, 1, 1),

-- Scarlet Monastery entrance
(5300820, 900010, 0, 85, 85, 2871.0, -819.0, 160.0, 5.0, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300821, 900011, 0, 85, 85, 2874.0, -816.0, 160.0, 5.0, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300822, 900055, 0, 85, 85, 2868.0, -816.0, 160.0, 5.0, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300823, 900056, 0, 85, 85, 2871.0, -813.0, 160.0, 5.0, 300, 0, 0, 1000, 0, 0, 1, 1),

-- Scarlet Monastery inside hubs
(5300824, 900011, 189, 0, 0, 1688.99, 1053.48, 18.68, 0.0, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300825, 900011, 189, 0, 0, 255.346, -209.09, 18.68, 6.28, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300826, 900011, 189, 0, 0, 1608.10, -318.92, 18.67, 6.28, 300, 0, 0, 1000, 0, 0, 1, 1),
(5300827, 900011, 189, 0, 0, 855.68, 1321.50, 18.67, 0.0, 300, 0, 0, 1000, 0, 0, 1, 1);
