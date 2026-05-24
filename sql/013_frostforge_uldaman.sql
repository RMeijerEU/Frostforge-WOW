-- Frostforge Campaign
-- Act XII: Uldaman

SET @ELDRIN := 900011;

SET @NPC_RELIQUARY_EXPLORER := 900060;
SET @NPC_STONEWATCHER       := 900061;

SET @Q_TITAN_ECHOES    := 900160;
SET @Q_DWARVEN_ORIGINS := 900161;
SET @Q_TROGG_WARNING   := 900162;
SET @Q_GROUP           := 900163;
SET @Q_DUNGEON         := 900164;

SET @ARCHAEDAS := 2748;

DELETE FROM creature_queststarter WHERE quest BETWEEN 900160 AND 900179;
DELETE FROM creature_questender WHERE quest BETWEEN 900160 AND 900179;

DELETE FROM quest_template_addon WHERE ID BETWEEN 900160 AND 900179;
DELETE FROM quest_template WHERE ID BETWEEN 900160 AND 900179;

DELETE FROM creature WHERE id1 BETWEEN 900060 AND 900069;
DELETE FROM creature_template_model WHERE CreatureID BETWEEN 900060 AND 900069;
DELETE FROM creature_template WHERE entry BETWEEN 900060 AND 900069;

INSERT INTO creature_template
(entry, difficulty_entry_1, difficulty_entry_2, difficulty_entry_3, KillCredit1, KillCredit2, name, subname, IconName, gossip_menu_id,
 minlevel, maxlevel, exp, faction, npcflag, speed_walk, speed_run, speed_swim, speed_flight, detection_range,
 `rank`, dmgschool, DamageModifier, BaseAttackTime, RangeAttackTime, BaseVariance, RangeVariance, unit_class, unit_flags,
 unit_flags2, dynamicflags, family, type, type_flags, lootid, pickpocketloot, skinloot, PetSpellDataId, VehicleId,
 mingold, maxgold, AIName, MovementType, HoverHeight, HealthModifier, ManaModifier, ArmorModifier, ExperienceModifier,
 RacialLeader, movementId, RegenHealth, CreatureImmunitiesId, flags_extra, ScriptName, VerifiedBuild)
VALUES
(@NPC_RELIQUARY_EXPLORER, 0, 0, 0, 0, 0, 'Frostforge Reliquary Explorer', 'Titan Vault Expedition', NULL, 0,
 43, 43, 2, 35, 1, 1, 1.14286, 1, 1, 20,
 0, 0, 1, 0, 0, 1, 1, 1, 0,
 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,
 0, 0, '', 0, 1, 1, 1, 1, 1,
 0, 0, 1, 0, 0, '', NULL),

(@NPC_STONEWATCHER, 0, 0, 0, 0, 0, 'Frostforge Stonewatcher', 'Witness of the Earthen', NULL, 0,
 43, 43, 2, 35, 1, 1, 1.14286, 1, 1, 20,
 0, 0, 1, 0, 0, 1, 1, 1, 0,
 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,
 0, 0, '', 0, 1, 1, 1, 1, 1,
 0, 0, 1, 0, 0, '', NULL);

-- Display IDs:
-- 1597 = dwarf-style explorer/defector model already used in the project.
-- 6932 = irradiated/gnome-ish technical model already used; replace later if desired.
INSERT INTO creature_template_model
(CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability, VerifiedBuild)
VALUES
(@NPC_RELIQUARY_EXPLORER, 0, 1597, 1, 1, 0),
(@NPC_STONEWATCHER, 0, 6932, 1, 1, 0);

-- Uldaman staging near Badlands entrance.
INSERT INTO creature
(id1, id2, id3, map, zoneId, areaId, spawnMask, phaseMask, equipment_id,
 position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, currentwaypoint,
 curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags, ScriptName, VerifiedBuild, CreateObject, Comment)
VALUES
(@NPC_RELIQUARY_EXPLORER, 0, 0, 0, 3, 0, 1, 1, 0,
 -6062.0, -2952.0, 209.0, 1.1, 300, 0, 0,
 1000, 0, 0, 1, 0, 0, '', NULL, 0, 'Frostforge Uldaman Reliquary Explorer'),

(@NPC_STONEWATCHER, 0, 0, 0, 3, 0, 1, 1, 0,
 -6068.0, -2958.0, 209.0, 0.3, 300, 0, 0,
 1000, 0, 0, 1, 0, 0, '', NULL, 0, 'Frostforge Uldaman Stonewatcher');

INSERT INTO quest_template
(ID, QuestType, QuestLevel, MinLevel, QuestSortID, QuestInfoID, SuggestedGroupNum,
 RewardNextQuest, RewardXPDifficulty, RewardMoney, RewardMoneyDifficulty,
 LogTitle, LogDescription, QuestDescription, AreaDescription, QuestCompletionLog,
 RequiredNpcOrGo1, RequiredNpcOrGo2, RequiredNpcOrGo3, RequiredNpcOrGo4,
 RequiredNpcOrGoCount1, RequiredNpcOrGoCount2, RequiredNpcOrGoCount3, RequiredNpcOrGoCount4,
 ObjectiveText1, ObjectiveText2, ObjectiveText3, ObjectiveText4, VerifiedBuild)
VALUES
(@Q_TITAN_ECHOES, 2, 40, 37, 130, 0, 0,
 0, 0, 10000, 0,
 'Echoes Beneath the Stone',
 'Speak with Archivist Eldrin about Uldaman and the Titan vaults.',
 'The Scarlet Monastery showed what fear can do to the living. Uldaman is older than fear, older than kingdoms, and older than the wars of Horde and Alliance.

Before the next dungeon, learn why the Badlands hide one of the most important ruins in Azeroth: a Titan vault tied to the origins of the dwarves, the earthen, and the broken creatures now called troggs.',
 '', 'Return to Archivist Eldrin after learning why Uldaman matters.',
 0, 0, 0, 0,
 0, 0, 0, 0,
 '', '', '', '', NULL),

(@Q_DWARVEN_ORIGINS, 2, 41, 37, 130, 0, 0,
 0, 0, 10000, 0,
 'The First Dwarves',
 'Speak with the Frostforge Reliquary Explorer near Uldaman.',
 'The dwarves search Uldaman for the truth of their beginning. Old songs speak of stone, awakening, and a past before Ironforge. The Reliquary expedition believes those stories are not myths at all.

Travel to Uldaman and speak with the Frostforge Reliquary Explorer.',
 '', 'Return to Archivist Eldrin after speaking with the Reliquary Explorer.',
 @NPC_RELIQUARY_EXPLORER, 0, 0, 0,
 1, 0, 0, 0,
 'Reliquary Explorer consulted', '', '', '', NULL),

(@Q_TROGG_WARNING, 2, 42, 37, 130, 0, 0,
 0, 0, 10000, 0,
 'The Trogg Warning',
 'Speak with the Frostforge Stonewatcher near Uldaman.',
 'The troggs are often treated as pests, but Uldaman suggests something worse. They are tied to the same ancient history as the earthen, proof that creation can fail and that old vaults can preserve old mistakes.

Speak with the Frostforge Stonewatcher and learn what the troggs reveal about Titan works.',
 '', 'Return to Archivist Eldrin after speaking with the Stonewatcher.',
 @NPC_STONEWATCHER, 0, 0, 0,
 1, 0, 0, 0,
 'Stonewatcher consulted', '', '', '', NULL),

(@Q_GROUP, 2, 43, 37, 130, 0, 0,
 0, 0, 10000, 0,
 'Into the Badlands',
 'Prepare to enter Uldaman.',
 'You now know enough to understand the danger. Uldaman is not only a ruin and not only a dungeon. It is a record of Azeroth before mortal history.

Gather your party and prepare to enter the vault.',
 '', 'Return to Archivist Eldrin when you are ready for Uldaman.',
 0, 0, 0, 0,
 0, 0, 0, 0,
 '', '', '', '', NULL),

(@Q_DUNGEON, 2, 45, 37, 130, 0, 5,
 0, 0, 20000, 0,
 'The Frostforge Path: Uldaman',
 'Enter Uldaman and defeat Archaedas.',
 'At the heart of Uldaman waits Archaedas, an ancient guardian of Titan stone and buried memory. Defeating him will not answer every question, but it will open the campaign to a much older truth: Azeroth was shaped, watched, and wounded long before the Horde and Alliance existed.

Enter Uldaman and defeat Archaedas.',
 '', 'Return to Archivist Eldrin after defeating Archaedas.',
 @ARCHAEDAS, 0, 0, 0,
 1, 0, 0, 0,
 'Defeat Archaedas', '', '', '', NULL);

INSERT INTO quest_template_addon
(ID, MaxLevel, AllowableClasses, SourceSpellID, PrevQuestID, NextQuestID, ExclusiveGroup, BreadcrumbForQuestId,
 RewardMailTemplateID, RewardMailDelay, RequiredSkillID, RequiredSkillPoints, RequiredMinRepFaction, RequiredMaxRepFaction,
 RequiredMinRepValue, RequiredMaxRepValue, ProvidedItemCount, SpecialFlags)
VALUES
(@Q_TITAN_ECHOES, 0, 0, 0, 0, @Q_DWARVEN_ORIGINS, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(@Q_DWARVEN_ORIGINS, 0, 0, 0, @Q_TITAN_ECHOES, @Q_TROGG_WARNING, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(@Q_TROGG_WARNING, 0, 0, 0, @Q_DWARVEN_ORIGINS, @Q_GROUP, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(@Q_GROUP, 0, 0, 0, @Q_TROGG_WARNING, @Q_DUNGEON, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(@Q_DUNGEON, 0, 0, 0, @Q_GROUP, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO creature_queststarter (id, quest) VALUES
(@ELDRIN, @Q_TITAN_ECHOES),
(@ELDRIN, @Q_DWARVEN_ORIGINS),
(@ELDRIN, @Q_TROGG_WARNING),
(@ELDRIN, @Q_GROUP),
(@ELDRIN, @Q_DUNGEON);

INSERT INTO creature_questender (id, quest) VALUES
(@ELDRIN, @Q_TITAN_ECHOES),
(@ELDRIN, @Q_DWARVEN_ORIGINS),
(@ELDRIN, @Q_TROGG_WARNING),
(@ELDRIN, @Q_GROUP),
(@ELDRIN, @Q_DUNGEON);