USE acore_world;

-- ==========================================================
-- Frostforge Scarlet Monastery Lore Polish
-- Adds Lordaeron / Scourge / Forsaken context
-- ==========================================================

-- 900151 now requires both the Scarlet Defector and Forsaken Observer.
UPDATE quest_template
SET
    RequiredNpcOrGo1 = 900055,
    RequiredNpcOrGoCount1 = 1,
    RequiredNpcOrGo2 = 900056,
    RequiredNpcOrGoCount2 = 1,
    ObjectiveText1 = 'Scarlet Defector consulted',
    ObjectiveText2 = 'Forsaken Observer consulted',
    LogDescription = 'Speak with the Frostforge Scarlet Defector and the Frostforge Forsaken Observer at Scarlet Monastery.',
    QuestDescription = 'Lordaeron did not simply fall. It was betrayed, slaughtered, raised, and left to rot beneath the shadow of the Scourge. The Scarlet Crusade was born from that wound: grief hardened into faith, fear sharpened into hatred. Before entering the Monastery, hear both sides of what remains here.',
    QuestCompletionLog = 'Speak with Archivist Eldrin at Scarlet Monastery after hearing both accounts.'
WHERE ID = 900151;

UPDATE quest_template
SET
    QuestDescription = 'The Graveyard is the Crusade''s first contradiction. They claim to fight undeath, yet death fills their own halls. Bloodmage Thalnos is proof that hatred of corruption does not make one immune to it. Enter the Graveyard and defeat him.',
    LogDescription = 'Enter Scarlet Monastery Graveyard and defeat Bloodmage Thalnos.',
    ObjectiveText1 = 'Defeat Bloodmage Thalnos'
WHERE ID = 900152;

UPDATE quest_template
SET
    QuestDescription = 'In the Library, grief becomes doctrine. The Scarlet Crusade writes its fear into books, sermons, orders, and laws. Here, doubt is weakness and mercy is treated as betrayal. Enter the Library and defeat Arcanist Doan.',
    LogDescription = 'Enter Scarlet Monastery Library and defeat Arcanist Doan.',
    ObjectiveText1 = 'Defeat Arcanist Doan'
WHERE ID = 900153;

UPDATE quest_template
SET
    QuestDescription = 'In the Armory, doctrine becomes violence. Herod trains soldiers who do not question, only obey. The Crusade no longer merely survives the fall of Lordaeron; it prepares to wage war on anything it cannot control. Enter the Armory and defeat Herod.',
    LogDescription = 'Enter Scarlet Monastery Armory and defeat Herod.',
    ObjectiveText1 = 'Defeat Herod'
WHERE ID = 900154;

UPDATE quest_template
SET
    QuestDescription = 'The Cathedral is the heart of Scarlet certainty. High Inquisitor Whitemane still speaks of purity, justice, and salvation, but the Crusade can no longer tell the living from the damned. It does not protect Lordaeron anymore. It worships its own certainty. Enter the Cathedral and defeat Whitemane.',
    LogDescription = 'Enter Scarlet Monastery Cathedral and defeat High Inquisitor Whitemane.',
    ObjectiveText1 = 'Defeat High Inquisitor Whitemane'
WHERE ID = 900155;

UPDATE quest_offer_reward
SET RewardText = 'Now you understand the wound beneath the Monastery. The Scarlet Crusade was not born from nothing. It was born from Lordaeron''s grave.'
WHERE ID = 900151;

UPDATE quest_offer_reward
SET RewardText = 'Thalnos is defeated. The Graveyard shows us the first truth: hatred of corruption does not protect anyone from becoming corrupted.'
WHERE ID = 900152;

UPDATE quest_offer_reward
SET RewardText = 'Doan is defeated. The Library is quieter now, but the words written there have already shaped too many minds.'
WHERE ID = 900153;

UPDATE quest_offer_reward
SET RewardText = 'Herod has fallen. The Crusade has lost one of its sharpened blades, but not the hand that forged him.'
WHERE ID = 900154;

UPDATE quest_offer_reward
SET RewardText = 'Whitemane is defeated. The Monastery still stands, but its certainty has been wounded. Remember this: grief deserves compassion, but when grief becomes doctrine, it becomes dangerous.'
WHERE ID = 900155;

UPDATE quest_request_items
SET CompletionText = 'Have you heard both the Scarlet and Forsaken accounts?'
WHERE ID = 900151;
