-- Frostforge Campaign
-- Act XIII: Zul'Farrak

SET @ELDRIN := 900011;
SET @GUIDE  := 900010;

SET @NPC_TANARIS_CHRONICLER := 900070;
SET @NPC_SANDFURY_EXILE     := 900077;
SET @NPC_RELIC_SEEKER       := 900078;

SET @Q_SANDS_OF_TANARIS    := 900180;
SET @Q_SANDFURY_EMPIRE     := 900181;
SET @Q_RELICS_IN_THE_SAND  := 900182;
SET @Q_GROUP               := 900183;
SET @Q_DUNGEON             := 900184;

SET @UKORZ := 7267;

DELETE FROM creature_queststarter WHERE quest BETWEEN 900180 AND 900199;
DELETE FROM creature_questender WHERE quest BETWEEN 900180 AND 900199;

DELETE FROM quest_template_addon WHERE ID BETWEEN 900180 AND 900199;
DELETE FROM quest_template WHERE ID BETWEEN 900180 AND 900199;

DELETE FROM creature WHERE id1 IN (@NPC_TANARIS_CHRONICLER, @NPC_SANDFURY_EXILE, @NPC_RELIC_SEEKER);
DELETE FROM creature_template_model WHERE CreatureID IN (@NPC_TANARIS_CHRONICLER, @NPC_SANDFURY_EXILE, @NPC_RELIC_SEEKER);
DELETE FROM creature_template WHERE entry IN (@NPC_TANARIS_CHRONICLER, @NPC_SANDFURY_EXILE, @NPC_RELIC_SEEKER);

DELETE FROM creature
WHERE Comment IN (
  'Frostforge ZulFarrak Gadgetzan Archivist Eldrin',
  'Frostforge ZulFarrak Tanaris Chronicler',
  'Frostforge ZulFarrak Sandfury Exile',
  'Frostforge ZulFarrak Relic Seeker',
  'Frostforge ZulFarrak Staging Archivist Eldrin',
  'Frostforge ZulFarrak Entrance Guide',
  'Frostforge ZulFarrak Portal Archivist Eldrin',
  'Frostforge ZulFarrak Portal Guide'
);

INSERT INTO creature_template
(entry, difficulty_entry_1, difficulty_entry_2, difficulty_entry_3, KillCredit1, KillCredit2, name, subname, IconName, gossip_menu_id,
 minlevel, maxlevel, exp, faction, npcflag, speed_walk, speed_run, speed_swim, speed_flight, detection_range,
 `rank`, dmgschool, DamageModifier, BaseAttackTime, RangeAttackTime, BaseVariance, RangeVariance, unit_class, unit_flags,
 unit_flags2, dynamicflags, family, type, type_flags, lootid, pickpocketloot, skinloot, PetSpellDataId, VehicleId,
 mingold, maxgold, AIName, MovementType, HoverHeight, HealthModifier, ManaModifier, ArmorModifier, ExperienceModifier,
 RacialLeader, movementId, RegenHealth, CreatureImmunitiesId, flags_extra, ScriptName, VerifiedBuild)
VALUES
(@NPC_TANARIS_CHRONICLER, 0, 0, 0, 0, 0, 'Frostforge Tanaris Chronicler', 'Witness of the Desert', NULL, 0,
 45, 45, 2, 35, 1, 1, 1.14286, 1, 1, 20,
 0, 0, 1, 0, 0, 1, 1, 1, 0,
 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,
 0, 0, '', 0, 1, 1, 1, 1, 1,
 0, 0, 1, 0, 0, '', NULL),

(@NPC_SANDFURY_EXILE, 0, 0, 0, 0, 0, 'Frostforge Sandfury Exile', 'Outcast of Zul''Farrak', NULL, 0,
 45, 45, 2, 35, 1, 1, 1.14286, 1, 1, 20,
 0, 0, 1, 0, 0, 1, 1, 1, 0,
 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,
 0, 0, '', 0, 1, 1, 1, 1, 1,
 0, 0, 1, 0, 0, '', NULL),

(@NPC_RELIC_SEEKER, 0, 0, 0, 0, 0, 'Frostforge Relic Seeker', 'Troll Empire Researcher', NULL, 0,
 45, 45, 2, 35, 1, 1, 1.14286, 1, 1, 20,
 0, 0, 1, 0, 0, 1, 1, 1, 0,
 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,
 0, 0, '', 0, 1, 1, 1, 1, 1,
 0, 0, 1, 0, 0, '', NULL);

-- Model copies from existing, known creatures.
-- Chronicler: copy Archivist Eldrin model.
INSERT INTO creature_template_model
(CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability, VerifiedBuild)
SELECT @NPC_TANARIS_CHRONICLER, src.Idx, src.CreatureDisplayID, src.DisplayScale, src.Probability, 0
FROM creature_template_model src
WHERE src.CreatureID = @ELDRIN
LIMIT 1;

-- Sandfury Exile: copy Sandfury Witch Doctor model.
INSERT INTO creature_template_model
(CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability, VerifiedBuild)
SELECT @NPC_SANDFURY_EXILE, src.Idx, src.CreatureDisplayID, src.DisplayScale, src.Probability, 0
FROM creature_template_model src
WHERE src.CreatureID = 5650
LIMIT 1;

-- Relic Seeker: copy Hydromancer Velratha model.
INSERT INTO creature_template_model
(CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability, VerifiedBuild)
SELECT @NPC_RELIC_SEEKER, src.Idx, src.CreatureDisplayID, src.DisplayScale, src.Probability, 0
FROM creature_template_model src
WHERE src.CreatureID = 7795
LIMIT 1;

-- Gadgetzan staging: first contact.
INSERT INTO creature
(id1, id2, id3, map, zoneId, areaId, spawnMask, phaseMask, equipment_id,
 position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint,
 curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags, ScriptName, VerifiedBuild, CreateObject, Comment)
VALUES
(@ELDRIN, 0, 0, 1, 440, 976, 1, 1, 0,
 -7161.545, -3784.858, 8.8464775, 3.2560885, 300, 0, 0,
 1000, 0, 0, 3, 0, 0, '', NULL, 0, 'Frostforge ZulFarrak Gadgetzan Archivist Eldrin'),

(@NPC_TANARIS_CHRONICLER, 0, 0, 1, 440, 976, 1, 1, 0,
 -7164.0, -3783.5, 8.8464775, 3.2560885, 300, 0, 0,
 1000, 0, 0, 1, 0, 0, '', NULL, 0, 'Frostforge ZulFarrak Tanaris Chronicler');

-- Zul'Farrak meeting stone / staging.
INSERT INTO creature
(id1, id2, id3, map, zoneId, areaId, spawnMask, phaseMask, equipment_id,
 position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint,
 curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags, ScriptName, VerifiedBuild, CreateObject, Comment)
VALUES
(@ELDRIN, 0, 0, 1, 440, 978, 1, 1, 0,
 -6830.061, -2880.2551, 8.929153, 5.785069, 300, 0, 0,
 1000, 0, 0, 3, 0, 0, '', NULL, 0, 'Frostforge ZulFarrak Staging Archivist Eldrin'),

(@NPC_SANDFURY_EXILE, 0, 0, 1, 440, 978, 1, 1, 0,
 -6832.2, -2878.6, 8.929153, 5.785069, 300, 0, 0,
 1000, 0, 0, 1, 0, 0, '', NULL, 0, 'Frostforge ZulFarrak Sandfury Exile'),

(@NPC_RELIC_SEEKER, 0, 0, 1, 440, 978, 1, 1, 0,
 -6827.8, -2882.2, 8.929153, 5.785069, 300, 0, 0,
 1000, 0, 0, 1, 0, 0, '', NULL, 0, 'Frostforge ZulFarrak Relic Seeker');

-- Zul'Farrak entrance guide.
INSERT INTO creature
(id1, id2, id3, map, zoneId, areaId, spawnMask, phaseMask, equipment_id,
 position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint,
 curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags, ScriptName, VerifiedBuild, CreateObject, Comment)
VALUES
(@GUIDE, 0, 0, 1, 440, 978, 1, 1, 0,
 -6798.3804, -2895.9358, 9.17488, 2.1502473, 300, 0, 0,
 1000, 0, 0, 129, 0, 0, '', NULL, 0, 'Frostforge ZulFarrak Entrance Guide');

-- Zul'Farrak portal staging.
INSERT INTO creature
(id1, id2, id3, map, zoneId, areaId, spawnMask, phaseMask, equipment_id,
 position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint,
 curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags, ScriptName, VerifiedBuild, CreateObject, Comment)
VALUES
(@ELDRIN, 0, 0, 1, 440, 978, 1, 1, 0,
 -6801.0, -2893.5, 9.17488, 2.1502473, 300, 0, 0,
 1000, 0, 0, 3, 0, 0, '', NULL, 0, 'Frostforge ZulFarrak Portal Archivist Eldrin'),

(@GUIDE, 0, 0, 1, 440, 978, 1, 1, 0,
 -6796.5, -2898.0, 9.17488, 2.1502473, 300, 0, 0,
 1000, 0, 0, 129, 0, 0, '', NULL, 0, 'Frostforge ZulFarrak Portal Guide');

INSERT INTO quest_template
(ID, QuestType, QuestLevel, MinLevel, QuestSortID, QuestInfoID, SuggestedGroupNum,
 RewardNextQuest, RewardXPDifficulty, RewardMoney, RewardMoneyDifficulty,
 LogTitle, LogDescription, QuestDescription, AreaDescription, QuestCompletionLog,
 RequiredNpcOrGo1, RequiredNpcOrGo2, RequiredNpcOrGo3, RequiredNpcOrGo4,
 RequiredNpcOrGoCount1, RequiredNpcOrGoCount2, RequiredNpcOrGoCount3, RequiredNpcOrGoCount4,
 ObjectiveText1, ObjectiveText2, ObjectiveText3, ObjectiveText4, VerifiedBuild)
VALUES
(@Q_SANDS_OF_TANARIS, 2, 45, 42, 130, 0, 0,
 0, 0, 10000, 0,
 'Sands of Tanaris',
 'Travel to Gadgetzan and learn why the desert matters.',
 'Tanaris is not empty. Beneath the heat and dust lie old roads, old wars, and the ruins of powers that ruled long before the current kingdoms.

The Sandfury trolls hold Zul''Farrak in the deep desert. Before you walk toward their gates, learn why this place matters.',
 '', 'Return to Archivist Eldrin after learning about Tanaris.',
 @NPC_TANARIS_CHRONICLER, 0, 0, 0,
 1, 0, 0, 0,
 'Tanaris Chronicler consulted', '', '', '', NULL),

(@Q_SANDFURY_EMPIRE, 2, 46, 42, 130, 0, 0,
 0, 0, 10000, 0,
 'The Sandfury Empire',
 'Speak with the Frostforge Sandfury Exile near Zul''Farrak.',
 'The Sandfury are not merely raiders hiding in the dunes. They are the broken edge of an ancient troll legacy, proud, violent, and unwilling to vanish into history.

Speak with the Sandfury exile near Zul''Farrak and learn what still burns behind the city gates.',
 '', 'Return to Archivist Eldrin near Zul''Farrak.',
 @NPC_SANDFURY_EXILE, 0, 0, 0,
 1, 0, 0, 0,
 'Sandfury Exile consulted', '', '', '', NULL),

(@Q_RELICS_IN_THE_SAND, 2, 47, 42, 130, 0, 0,
 0, 0, 10000, 0,
 'Relics in the Sand',
 'Speak with the Frostforge Relic Seeker near Zul''Farrak.',
 'Troll empires marked Azeroth long before many nations now fighting over it existed. Their ruins are not dead stones. They carry rites, grudges, gods, and old names.

Speak with the relic seeker and learn why Zul''Farrak is more than a desert fortress.',
 '', 'Return to Archivist Eldrin near Zul''Farrak.',
 @NPC_RELIC_SEEKER, 0, 0, 0,
 1, 0, 0, 0,
 'Relic Seeker consulted', '', '', '', NULL),

(@Q_GROUP, 2, 48, 42, 130, 0, 0,
 0, 0, 10000, 0,
 'At the Gates of Zul''Farrak',
 'Gather your party and speak with the Frostforge Guide at the Zul''Farrak entrance.',
 'You have heard the warning and the history. Now the gates of Zul''Farrak stand ahead.

Gather your party near the entrance. When your group is ready, speak with the Frostforge Guide and move to the dungeon portal.',
 '', 'Meet Archivist Eldrin at the Zul''Farrak portal.',
 @GUIDE, 0, 0, 0,
 1, 0, 0, 0,
 'Frostforge Guide consulted', '', '', '', NULL),

(@Q_DUNGEON, 2, 50, 42, 130, 0, 5,
 0, 0, 20000, 0,
 'The Frostforge Path: Zul''Farrak',
 'Enter Zul''Farrak and defeat Chief Ukorz Sandscalp.',
 'Zul''Farrak is the Sandfury heart in Tanaris: a city of dust, blood, old rites, and troll defiance.

Enter Zul''Farrak and defeat Chief Ukorz Sandscalp. Break the Sandfury hold on the desert and carry the campaign toward the next ancient power.',
 '', 'Return to Archivist Eldrin after defeating Chief Ukorz Sandscalp.',
 @UKORZ, 0, 0, 0,
 1, 0, 0, 0,
 'Defeat Chief Ukorz Sandscalp', '', '', '', NULL);

INSERT INTO quest_template_addon
(ID, MaxLevel, AllowableClasses, SourceSpellID, PrevQuestID, NextQuestID, ExclusiveGroup, BreadcrumbForQuestId,
 RewardMailTemplateID, RewardMailDelay, RequiredSkillID, RequiredSkillPoints, RequiredMinRepFaction, RequiredMaxRepFaction,
 RequiredMinRepValue, RequiredMaxRepValue, ProvidedItemCount, SpecialFlags)
VALUES
(@Q_SANDS_OF_TANARIS, 0, 0, 0, 0, @Q_SANDFURY_EMPIRE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(@Q_SANDFURY_EMPIRE, 0, 0, 0, @Q_SANDS_OF_TANARIS, @Q_RELICS_IN_THE_SAND, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(@Q_RELICS_IN_THE_SAND, 0, 0, 0, @Q_SANDFURY_EMPIRE, @Q_GROUP, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(@Q_GROUP, 0, 0, 0, @Q_RELICS_IN_THE_SAND, @Q_DUNGEON, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(@Q_DUNGEON, 0, 0, 0, @Q_GROUP, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO creature_queststarter (id, quest) VALUES
(@ELDRIN, @Q_SANDS_OF_TANARIS),
(@ELDRIN, @Q_SANDFURY_EMPIRE),
(@ELDRIN, @Q_RELICS_IN_THE_SAND),
(@ELDRIN, @Q_GROUP),
(@ELDRIN, @Q_DUNGEON);

INSERT INTO creature_questender (id, quest) VALUES
(@ELDRIN, @Q_SANDS_OF_TANARIS),
(@ELDRIN, @Q_SANDFURY_EMPIRE),
(@ELDRIN, @Q_RELICS_IN_THE_SAND),
(@ELDRIN, @Q_GROUP),
(@ELDRIN, @Q_DUNGEON);