USE acore_world;

DELETE FROM quest_template WHERE ID BETWEEN 900141 AND 900145;
DELETE FROM quest_template_addon WHERE ID BETWEEN 900141 AND 900145;
DELETE FROM quest_offer_reward WHERE ID BETWEEN 900141 AND 900145;
DELETE FROM quest_request_items WHERE ID BETWEEN 900141 AND 900145;

DELETE FROM creature_queststarter WHERE quest BETWEEN 900141 AND 900145;
DELETE FROM creature_questender WHERE quest BETWEEN 900141 AND 900145;

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
(900141,2,29,26,130,0,10000,
'The Fallen City of Gnomes',
'Travel to Gnomeregan and speak with Archivist Eldrin near the entrance.',
'From the drowned ruins of Blackfathom, the Frostforge Path turns to a different kind of disaster: not ancient whispers, but invention twisted by panic and betrayal.

Gnomeregan was once one of the greatest marvels of Azeroth. Now its halls are poisoned, overrun, and haunted by the choices made in its final hours. Travel to Gnomeregan and meet Archivist Eldrin near the entrance.',
'',
'Speak with Archivist Eldrin near Gnomeregan.',
900075,0,0,0,
1,0,0,0,
'Archivist Eldrin found near Gnomeregan','','',''),

(900142,2,30,26,130,0,10000,
'Exile of Gnomeregan',
'Speak with the Frostforge Gnome Survivor near Gnomeregan.',
'The fall of Gnomeregan is often told as a tale of machines, troggs, radiation, and failed invention. That is only half the truth.

The deeper wound is exile. A people lost their capital and now live beside the echo of what was taken from them. Speak with the Frostforge Gnome Survivor and hear what the evacuation cost.',
'',
'Return to Archivist Eldrin after hearing the survivor.',
900051,0,0,0,
1,0,0,0,
'Gnome Survivor consulted','','',''),

(900143,2,30,26,130,0,10000,
'Betrayal in the Machine',
'Speak with the Frostforge Irradiated Technician near Gnomeregan.',
'Thermaplugg did not simply make a mistake. He saw panic, radiation, malfunctioning defenses, and political chaos, then used them.

The fall of Gnomeregan was not only an accident of invention. It was betrayal hidden inside emergency measures. Speak with the Frostforge Irradiated Technician and learn how disaster became a throne.',
'',
'Return to Archivist Eldrin after hearing the technician.',
900052,0,0,0,
1,0,0,0,
'Irradiated Technician consulted','','',''),

(900144,2,30,26,130,0,10000,
'Gathering at Gnomeregan',
'Gather your allies at Gnomeregan and speak with Archivist Eldrin.',
'The city below is not merely abandoned. Troggs infest its tunnels. Leper gnomes wander its poisoned halls. Machines still follow broken commands. Radiation turns every corridor into a warning.

Gather your party at Gnomeregan. When you are ready, the Frostforge Guide will send you into the fallen city.',
'',
'Speak with Archivist Eldrin at Gnomeregan when your party is ready.',
900075,0,0,0,
1,0,0,0,
'Archivist Eldrin found at Gnomeregan','','',''),

(900145,2,31,26,130,5,20000,
'The Frostforge Path: Gnomeregan',
'Enter Gnomeregan and defeat Mekgineer Thermaplugg.',
'Thermaplugg sits at the center of the ruined city, surrounded by the consequences of ambition disguised as genius. He did not create every disaster that befell Gnomeregan, but he profited from the panic and crowned himself among the wreckage.

Enter Gnomeregan, fight through the poisoned machines and broken halls, and defeat Mekgineer Thermaplugg.',
'',
'Return to Archivist Eldrin after defeating Mekgineer Thermaplugg.',
7800,0,0,0,
1,0,0,0,
'Defeat Mekgineer Thermaplugg','','','');

INSERT INTO quest_template_addon (
    ID,
    PrevQuestID,
    NextQuestID
) VALUES
(900141,900140,900142),
(900142,900141,900143),
(900143,900142,900144),
(900144,900143,900145),
(900145,900144,900146);

INSERT INTO quest_offer_reward (
    ID,
    RewardText
) VALUES
(900141,'Gnomeregan stands before us: a city of genius, ruin, and betrayal. Remember this place as more than a dungeon. It was a home.'),
(900142,'The survivor reminds us that disasters are measured in people, not machines. Gnomeregan did not merely fail. It was lost.'),
(900143,'Thermaplugg turned catastrophe into power. The city was poisoned by radiation, but also by ambition.'),
(900144,'Your party is ready. Below us wait troggs, leper gnomes, broken machines, radiation, and the traitor at the center of it all.'),
(900145,'Thermaplugg has fallen. Gnomeregan is not restored, but justice has entered its halls. The exiles still have a city to reclaim.');

INSERT INTO quest_request_items (
    ID,
    CompletionText
) VALUES
(900141,'Have you reached Gnomeregan?'),
(900142,'What did the survivor tell you?'),
(900143,'What did the irradiated technician remember?'),
(900144,'Are your allies gathered at Gnomeregan?'),
(900145,'Has Mekgineer Thermaplugg fallen?');

INSERT INTO creature_queststarter VALUES
(900011,900141),
(900011,900142),
(900011,900143),
(900011,900144),
(900011,900145);

INSERT INTO creature_questender VALUES
(900011,900141),
(900011,900142),
(900011,900143),
(900011,900144),
(900011,900145);
