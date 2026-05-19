USE acore_world;

-- ==========================================================
-- Frostforge RFK Lore Polish
-- Adds Agamaggan / quilboar / Barrens context
-- ==========================================================

UPDATE quest_template
SET
    QuestDescription = 'The Barrens hides more than dust and bones. Razorfen Kraul is not merely a den of raiders; it is a thorn-walled remnant of an older story. The quilboar trace their faith and fury back to Agamaggan, the great boar ancient who died in the War of the Ancients. His blood is said to have birthed the great thorn growths. Travel to Razorfen Kraul and learn what that legacy has become.',
    LogDescription = 'Travel to Razorfen Kraul and speak with Archivist Eldrin near the entrance.',
    QuestCompletionLog = 'Speak with Archivist Eldrin near Razorfen Kraul.'
WHERE ID = 900146;

UPDATE quest_template
SET
    QuestDescription = 'To outsiders, the quilboar are often seen only as raiders from the thorns. But the Barrens tells a longer story: scarcity, territory, old wounds, and a people defending sacred ground with increasing desperation. Speak with the Barrens Messenger and hear what the roads have suffered.',
    LogDescription = 'Speak with the Frostforge Barrens Messenger near Razorfen Kraul.',
    QuestCompletionLog = 'Speak with Archivist Eldrin after hearing the messenger.',
    ObjectiveText1 = 'Barrens Messenger consulted'
WHERE ID = 900147;

UPDATE quest_template
SET
    QuestDescription = 'The thorns are sacred to the quilboar, but sacred things can be used to control as easily as to protect. A captive near the Kraul claims Charlga Razorflank has turned tradition into obedience and survival into ritual violence. Hear the captive''s warning before entering the maze.',
    LogDescription = 'Speak with the Frostforge Quilboar Captive near Razorfen Kraul.',
    QuestCompletionLog = 'Speak with Archivist Eldrin after hearing the captive.',
    ObjectiveText1 = 'Quilboar Captive consulted'
WHERE ID = 900148;

UPDATE quest_template
SET
    QuestDescription = 'Charlga rules from within a maze of thorn, faith, and fear. The Kraul is not just a fortress; it is a wounded people turned inward until every outsider became an enemy. Gather your allies at Razorfen Kraul. The Frostforge Guide will send you inside.',
    LogDescription = 'Gather your allies at Razorfen Kraul and speak with Archivist Eldrin.',
    QuestCompletionLog = 'Speak with Archivist Eldrin at Razorfen Kraul.',
    ObjectiveText1 = 'Archivist Eldrin found at Razorfen Kraul'
WHERE ID = 900149;

UPDATE quest_template
SET
    QuestDescription = 'Charlga Razorflank has bound the Kraul to darker rites, wrapping fear and faith together until the thorns themselves seem to answer her. Enter Razorfen Kraul and defeat Charlga Razorflank.',
    LogDescription = 'Enter Razorfen Kraul and defeat Charlga Razorflank.',
    QuestCompletionLog = 'Return to Archivist Eldrin after defeating Charlga Razorflank.',
    ObjectiveText1 = 'Defeat Charlga Razorflank'
WHERE ID = 900150;

UPDATE quest_offer_reward
SET RewardText = 'The Kraul stands before us. Remember: the quilboar are not merely monsters in the thorns. They are a people shaped by an ancient sacrifice and a harsh land.'
WHERE ID = 900146;

UPDATE quest_offer_reward
SET RewardText = 'The messenger confirms what the roads already knew: fear has made the Barrens smaller for everyone.'
WHERE ID = 900147;

UPDATE quest_offer_reward
SET RewardText = 'The captive confirms it. Charlga is not only leading the Kraul; she is binding it.'
WHERE ID = 900148;

UPDATE quest_offer_reward
SET RewardText = 'The thorns await. Go carefully. A desperate people can be as dangerous as any demon.'
WHERE ID = 900149;

UPDATE quest_offer_reward
SET RewardText = 'Charlga Razorflank is defeated. The Kraul remains, and so does the old pain beneath it. Not every wound in Azeroth can be solved by killing its ruler.'
WHERE ID = 900150;

UPDATE quest_request_items
SET CompletionText = 'Have you reached Razorfen Kraul?'
WHERE ID = 900146;

UPDATE quest_request_items
SET CompletionText = 'What warning did the Barrens Messenger carry?'
WHERE ID = 900147;

UPDATE quest_request_items
SET CompletionText = 'What did the Quilboar Captive reveal?'
WHERE ID = 900148;

UPDATE quest_request_items
SET CompletionText = 'Are your allies gathered at Razorfen Kraul?'
WHERE ID = 900149;

UPDATE quest_request_items
SET CompletionText = 'Has Charlga Razorflank fallen?'
WHERE ID = 900150;
