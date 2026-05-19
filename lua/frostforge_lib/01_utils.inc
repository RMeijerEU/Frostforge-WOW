-- Frostforge utility functions

Frostforge = Frostforge or {}
Frostforge.Utils = Frostforge.Utils or {}

function Frostforge.Utils.GiveItems(player, items)
    for _, item in ipairs(items) do
        player:AddItem(item[1], item[2] or 1)
    end
end

function Frostforge.Utils.LearnSpells(player, spells)
    local learned = 0

    for _, spellId in ipairs(spells) do
        if not player:HasSpell(spellId) then
            player:LearnSpell(spellId)
            learned = learned + 1
        end
    end

    return learned
end

function Frostforge.Utils.SetSkillSafe(player, skillId, value, maxValue)
    player:SetSkill(skillId, 0, value, maxValue)
end

function Frostforge.Utils.GetQuestIdSafe(quest)
    if type(quest) == "userdata" and quest.GetId then
        return quest:GetId()
    end

    return quest
end

function Frostforge.Utils.TeleportPlayerGroup(player, map, x, y, z, o)
    local group = player:GetGroup()

    if not group then
        player:Teleport(map, x, y, z, o)
        return
    end

    local members = group:GetMembers()

    for _, member in pairs(members) do
        if member and member:IsInWorld() then
            member:SendBroadcastMessage("|cff66ccffFrostforge:|r Your group is being moved together.")
            member:Teleport(map, x, y, z, o)
        end
    end
end

function Frostforge.Utils.SendPathMessage(player, message)
    player:SendBroadcastMessage("|cff66ccffFrostforge Path:|r " .. message)
end

function Frostforge.Utils.SendEldrinMessage(player, message)
    player:SendBroadcastMessage("|cff66ccffArchivist Eldrin:|r " .. message)
end

function Frostforge.Utils.SendGuideMessage(player, message)
    player:SendBroadcastMessage("|cff66ccffFrostforge Guide:|r " .. message)
end
