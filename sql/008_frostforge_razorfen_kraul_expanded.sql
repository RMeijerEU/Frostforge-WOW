USE acore_world;

DELETE FROM quest_template WHERE ID BETWEEN 900146 AND 900150;
DELETE FROM quest_template_addon WHERE ID BETWEEN 900146 AND 900150;
DELETE FROM quest_offer_reward WHERE ID BETWEEN 900146 AND 900150;
DELETE FROM quest_request_items WHERE ID BETWEEN 900146 AND 900150;

DELETE FROM creature_queststarter WHERE quest BETWEEN 900146 AND 900150;
DELETE FROM creature_questender WHERE quest BETWEEN 900146 AND 900150;

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
(900146,2,31,26,130,0,10000,
'Thorns in the Barrens',
'Travel to Razorfen Kraul and speak with Archivist Eldrin near the entrance.',
'The Barrens hides more than dust and bones. Razorfen Kraul is not merely a den of raiders; it is a thorn-walled remnant of an older story.

The quilboar trace their faith and fury back to Agamaggan, the great boar ancient who died in the War of the Ancients. His blood is said to have birthed the great thorn growths. Travel to Razorfen Kraul and learn what that legacy has become.',
'',
'Speak with Archivist Eldrin near Razorfen Kraul.',
900076,0,0,0,
1,0,0,0,
'Archivist Eldrin found near Razorfen Kraul','','',''),

(900147,2,32,26,130,0,10000,
'Warnings from the Road',
'Speak with the Frostforge Barrens Messenger near Razorfen Kraul.',
'To outsiders, the quilboar are often seen only as raiders from the thorns. But the Barrens tells a longer story: scarcity, territory, old wounds, and a people defending sacred ground with increasing desperation.

Speak with the Barrens Messenger and hear what the roads have suffered.',
'',
'Return to Archivist Eldrin after hearing the messenger.',
900053,0,0,0,
1,0,0,0,
'Barrens Messenger consulted','','',''),

(900148,2,32,26,130,0,10000,
'The Captive in the Thorns',
'Speak with the Frostforge Quilboar Captive near Razorfen Kraul.',
'The thorns are sacred to the quilboar, but sacred things can be used to control as easily as to protect.

A captive near the Kraul claims Charlga Razorflank has turned tradition into obedience and survival into ritual violence. Hear the captive warning before entering the maze.',
'',
'Return to Archivist Eldrin after hearing the captive.',
900054,0,0,0,
1,0,0,0,
'Quilboar Captive consulted','','',''),

(900149,2,32,26,130,0,10000,
'Gathering at Razorfen Kraul',
'Gather your allies at Razorfen Kraul and speak with Archivist Eldrin.',
'Charlga rules from within a maze of thorn, faith, and fear. The Kraul is not just a fortress; it is a wounded people turned inward until every outsider became an enemy.

Gather your allies at Razorfen Kraul. The Frostforge Guide will send you inside.',
'',
'Speak with Archivist Eldrin at Razorfen Kraul.',
900076,0,0,0,
1,0,0,0,
'Archivist Eldrin found at Razorfen Kraul','','',''),

(900150,2,33,26,130,5,20000,
'The Frostforge Path: Razorfen Kraul',
'Enter Razorfen Kraul and defeat Charlga Razorflank.',
'Charlga Razorflank has bound the Kraul to darker rites, wrapping fear and faith together until the thorns themselves seem to answer her.

Enter Razorfen Kraul and defeat Charlga Razorflank. This will not heal every wound in the Barrens, but it will break her hold over the Kraul.',
'',
'Return to Archivist Eldrin after defeating Charlga Razorflank.',
4421,0,0,0,
1,0,0,0,
'Defeat Charlga Razorflank','','','');

INSERT INTO quest_template_addon (
    ID,
    PrevQuestID,
    NextQuestID
) VALUES
(900146,900145,900147),
(900147,900146,900148),
(900148,900147,900149),
(900149,900148,900150),
(900150,900149,900151);

INSERT INTO quest_offer_reward (
    ID,
    RewardText
) VALUES
(900146,'The Kraul stands before us. Remember: the quilboar are not merely monsters in the thorns. They are a people shaped by ancient sacrifice and a harsh land.'),
(900147,'The messenger confirms what the roads already knew: fear has made the Barrens smaller for everyone.'),
(900148,'The captive confirms it. Charlga is not only leading the Kraul; she is binding it.'),
(900149,'The thorns await. Go carefully. A desperate people can be as dangerous as any demon.'),
(900150,'Charlga Razorflank is defeated. The Kraul remains, and so does the old pain beneath it. Not every wound in Azeroth can be solved by killing its ruler.');

INSERT INTO quest_request_items (
    ID,
    CompletionText
) VALUES
(900146,'Have you reached Razorfen Kraul?'),
(900147,'What warning did the Barrens Messenger carry?'),
(900148,'What did the Quilboar Captive reveal?'),
(900149,'Are your allies gathered at Razorfen Kraul?'),
(900150,'Has Charlga Razorflank fallen?');

INSERT INTO creature_queststarter VALUES
(900011,900146),
(900011,900147),
(900011,900148),
(900011,900149),
(900011,900150);

INSERT INTO creature_questender VALUES
(900011,900146),
(900011,900147),
(900011,900148),
(900011,900149),
(900011,900150);