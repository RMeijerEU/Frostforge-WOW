-- Frostforge Campaign
-- Improve early onboarding by making Groupfinder Marric part of the first dungeon group quest.

SET @MARRIC := 900010;
SET @Q_FIRST_GROUP := 900103;

UPDATE quest_template
SET
  LogTitle = 'Forming Your First Dungeon Group',
  LogDescription = 'Speak with Groupfinder Marric and learn how Frostforge dungeon groups work.',
  QuestDescription = 'The threat beneath Orgrimmar is too dangerous to face alone.

I am Archivist Eldrin. I will guide you through the stories behind Azeroth''s dungeons, but I will not fight your battles for you. For that, you need companions, preparation, and supplies.

Speak with Groupfinder Marric near the Ragefire Chasm entrance. Marric handles the practical side of the Frostforge Path: bot groups, supplies, dungeon commands, and group preparation.

He can make a quick party for you, but learn what he teaches. Later dungeons will reward players who understand how to build their own groups.',
  QuestCompletionLog = 'Return to Archivist Eldrin once you have spoken with Groupfinder Marric.',
  RequiredNpcOrGo1 = @MARRIC,
  RequiredNpcOrGoCount1 = 1,
  ObjectiveText1 = 'Speak with Groupfinder Marric'
WHERE ID = @Q_FIRST_GROUP;