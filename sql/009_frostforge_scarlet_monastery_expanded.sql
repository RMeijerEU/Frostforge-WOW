USE acore_world;

DELETE FROM quest_template WHERE ID BETWEEN 900151 AND 900159;
DELETE FROM quest_template_addon WHERE ID BETWEEN 900151 AND 900159;
DELETE FROM quest_offer_reward WHERE ID BETWEEN 900151 AND 900159;
DELETE FROM quest_request_items WHERE ID BETWEEN 900151 AND 900159;

DELETE FROM creature_queststarter WHERE quest BETWEEN 900151 AND 900159;
DELETE FROM creature_questender WHERE quest BETWEEN 900151 AND 900159;

INSERT INTO quest_template (
    ID,
    QuestType,
    QuestLevel,
    MinLevel,
    QuestSortID,
    SuggestedGroupNum,
    RewardMoney,
    LogTitle,
    LogDescription,
    QuestDescription,
    AreaDescription,
    QuestCompletionLog,
    RequiredNpcOrGo1,
    RequiredNpcOrGo2,
    RequiredNpcOrGo3,
    RequiredNpcOrGo4,
    RequiredNpcOrGoCount1,
    RequiredNpcOrGoCount2,
    RequiredNpcOrGoCount3,
    RequiredNpcOrGoCount4,
    ObjectiveText1,
    ObjectiveText2,
    ObjectiveText3,
    ObjectiveText4
) VALUES
(900151,2,34,26,130,0,10000,
'The Red Standard',
'Investigate Scarlet patrol activity near Southshore and Tarren Mill.',
'The Scarlet Crusade still claims to defend Lordaeron, but its red standard now casts a longer shadow.

In Hillsbrad, reports speak of patrols threatening refugees, Forsaken, and neutral travelers alike. Speak with the Frostforge Southshore Scout and the Frostforge Tarren Mill Apothecary to understand what the Crusade has become outside the Monastery walls.',
'',
'Return to Archivist Eldrin after hearing both accounts.',
900057,900058,0,0,
1,1,0,0,
'Southshore Scout consulted','Tarren Mill Apothecary consulted','',''),

(900152,2,34,26,130,0,10000,
'Faith Without Mercy',
'Speak with the Frostforge Hillsbrad Refugee about Scarlet judgment.',
'The Crusade began as an answer to the Scourge, but fear has become doctrine.

To the zealous, contamination is no longer just undeath. It is doubt, sympathy, hesitation, and mercy shown to the wrong person. Find the Frostforge Hillsbrad Refugee and hear what happens when the Scarlet Crusade decides the living are not pure enough.',
'',
'Return to Archivist Eldrin after hearing the refugee''s account.',
900059,0,0,0,
1,0,0,0,
'Hillsbrad Refugee consulted','','',''),

(900153,2,35,26,130,0,10000,
'The Scarlet Road',
'Speak with the Frostforge Scarlet Defector and the Frostforge Forsaken Observer at Scarlet Monastery.',
'Lordaeron did not simply fall. It was betrayed, slaughtered, raised, and left to rot beneath the shadow of the Scourge.

The Scarlet Crusade was born from that wound: grief hardened into faith, fear sharpened into hatred. Before entering the Monastery, hear both sides of what remains here.',
'',
'Speak with Archivist Eldrin at Scarlet Monastery after hearing both accounts.',
900055,900056,0,0,
1,1,0,0,
'Scarlet Defector consulted','Forsaken Observer consulted','',''),

(900154,2,35,26,130,5,20000,
'The Frostforge Path: Scarlet Monastery Graveyard',
'Enter Scarlet Monastery Graveyard and defeat Bloodmage Thalnos.',
'The Graveyard is the Crusade''s first contradiction. They claim to fight undeath, yet death fills their own halls. Bloodmage Thalnos is proof that hatred of corruption does not make one immune to it.

Enter the Graveyard and defeat him.',
'',
'Return to Archivist Eldrin after defeating Bloodmage Thalnos.',
4543,0,0,0,
1,0,0,0,
'Defeat Bloodmage Thalnos','','',''),

(900155,2,37,26,130,5,20000,
'The Frostforge Path: Scarlet Monastery Library',
'Enter Scarlet Monastery Library and defeat Arcanist Doan.',
'In the Library, grief becomes doctrine. The Scarlet Crusade writes its fear into books, sermons, orders, and laws. Here, doubt is weakness and mercy is treated as betrayal.

Enter the Library and defeat Arcanist Doan.',
'',
'Return to Archivist Eldrin after defeating Arcanist Doan.',
6487,0,0,0,
1,0,0,0,
'Defeat Arcanist Doan','','',''),

(900156,2,38,26,130,0,10000,
'Ashes in the Archives',
'Reflect with Archivist Eldrin on what the Library revealed.',
'The Library is quiet now, but the danger was never only Arcanist Doan. The books, orders, and sermons inside the Monastery show how fear becomes law, and how law becomes permission for cruelty.

Speak with Archivist Eldrin and consider what the Crusade has written into itself.',
'',
'Speak with Archivist Eldrin about the Scarlet archives.',
0,0,0,0,
0,0,0,0,
'','','',''),

(900157,2,39,26,130,0,10000,
'The Monastery Must Fall',
'Prepare for the final assault on Scarlet Monastery.',
'The Graveyard showed corruption. The Library showed doctrine. Now the remaining halls show what doctrine becomes when armed and blessed.

Herod trains the Crusade''s soldiers in the Armory. In the Cathedral, Scarlet Commander Mograine and High Inquisitor Whitemane sanctify the cause. The Monastery''s heart must be broken.',
'',
'Speak with Archivist Eldrin when you are ready to assault the Armory and Cathedral.',
0,0,0,0,
0,0,0,0,
'','','',''),

(900158,2,39,26,130,5,20000,
'The Frostforge Path: Scarlet Monastery Armory',
'Enter Scarlet Monastery Armory and defeat Herod.',
'In the Armory, doctrine becomes violence. Herod trains soldiers who do not question, only obey. The Crusade no longer merely survives the fall of Lordaeron; it prepares to wage war on anything it cannot control.

Enter the Armory and defeat Herod.',
'',
'Return to Archivist Eldrin after defeating Herod.',
3975,0,0,0,
1,0,0,0,
'Defeat Herod','','',''),

(900159,2,40,26,130,5,20000,
'The Frostforge Path: Scarlet Monastery Cathedral',
'Enter Scarlet Monastery Cathedral and defeat Scarlet Commander Mograine and High Inquisitor Whitemane.',
'The Cathedral is the heart of Scarlet certainty. Mograine and Whitemane still speak of purity, justice, and salvation, but the Crusade can no longer tell the living from the damned. It does not protect Lordaeron anymore. It worships its own certainty.

Enter the Cathedral and defeat both Scarlet Commander Mograine and High Inquisitor Whitemane.',
'',
'Return to Archivist Eldrin after defeating Mograine and Whitemane.',
3976,3977,0,0,
1,1,0,0,
'Defeat Scarlet Commander Mograine','Defeat High Inquisitor Whitemane','','');

INSERT INTO quest_template_addon (
    ID,
    PrevQuestID,
    NextQuestID
) VALUES
(900151,900150,900152),
(900152,900151,900153),
(900153,900152,900154),
(900154,900153,900155),
(900155,900154,900156),
(900156,900155,900157),
(900157,900156,900158),
(900158,900157,900159),
(900159,900158,0);

INSERT INTO quest_offer_reward (
    ID,
    RewardText
) VALUES
(900151,'The reports agree. The Scarlet Crusade no longer guards only against the Scourge. It has begun to judge the living as if fear itself were proof of corruption.'),
(900152,'The refugee confirms it. The Crusade has turned mercy into suspicion and suspicion into sentence.'),
(900153,'Now you understand the wound beneath the Monastery. The Scarlet Crusade was not born from nothing. It was born from Lordaeron''s grave.'),
(900154,'Thalnos is defeated. The Graveyard shows us the first truth: hatred of corruption does not protect anyone from becoming corrupted.'),
(900155,'Doan is defeated. The Library is quieter now, but the words written there have already shaped too many minds.'),
(900156,'The archives make the danger plain. A sword can kill one enemy. A doctrine can teach thousands whom to hate.'),
(900157,'Then the Monastery must fall. Not because grief is evil, but because grief has been crowned as law.'),
(900158,'Herod has fallen. The Crusade has lost one of its sharpened blades, but not the altar that blessed him.'),
(900159,'Mograine and Whitemane are defeated. The Monastery still stands, but its certainty has been wounded. Remember this: grief deserves compassion, but when grief becomes doctrine, it becomes dangerous.');

INSERT INTO quest_request_items (
    ID,
    CompletionText
) VALUES
(900151,'What did the Scarlet patrols reveal?'),
(900152,'What happened to the Hillsbrad refugee?'),
(900153,'Have you heard both the Scarlet and Forsaken accounts?'),
(900154,'Has Bloodmage Thalnos fallen?'),
(900155,'Has Arcanist Doan fallen?'),
(900156,'What did the archives reveal?'),
(900157,'Are you ready for the final assault?'),
(900158,'Has Herod fallen?'),
(900159,'Have Scarlet Commander Mograine and High Inquisitor Whitemane fallen?');

INSERT INTO creature_queststarter VALUES
(900011,900151),
(900011,900152),
(900011,900153),
(900011,900154),
(900011,900155),
(900011,900156),
(900011,900157),
(900011,900158),
(900011,900159);

INSERT INTO creature_questender VALUES
(900011,900151),
(900011,900152),
(900011,900153),
(900011,900154),
(900011,900155),
(900011,900156),
(900011,900157),
(900011,900158),
(900011,900159);
