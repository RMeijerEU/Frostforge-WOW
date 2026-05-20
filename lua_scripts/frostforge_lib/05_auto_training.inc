-- Frostforge Auto Training
-- Keeps player skills and class spells updated when Frostforge changes player level.

Frostforge = Frostforge or {}
Frostforge.AutoTraining = Frostforge.AutoTraining or {}

local U = Frostforge.Utils
local Starter = Frostforge.StarterGear

local function TrainPlayerForCurrentLevel(player, showMessage)
    if not player then
        return
    end

    local level = player:GetLevel()
    local Training = Frostforge.ClassTraining

    -- Always keep weapon/defense skills current.
    if Starter and Starter.LearnWeaponSkillsForStarterGear then
        Starter.LearnWeaponSkillsForStarterGear(player)
    end

    -- Existing starter baseline. This remains safe to run repeatedly.
    if level >= 10 and Starter and Starter.LearnLevel10ClassSpells then
        Starter.LearnLevel10ClassSpells(player)
    end

    -- Campaign-level spell packs.
    if level >= 15 and Training and Training.LearnLevel15ClassSpells then
        Training.LearnLevel15ClassSpells(player)
    end

    if level >= 20 and Training and Training.LearnLevel20ClassSpells then
        Training.LearnLevel20ClassSpells(player)
    end

    if level >= 22 and Training and Training.LearnLevel22ClassSpells then
        Training.LearnLevel22ClassSpells(player)
    end

    if level >= 24 and Training and Training.LearnLevel24ClassSpells then
        Training.LearnLevel24ClassSpells(player)
    end

    if level >= 30 and Training and Training.LearnLevel30ClassSpells then
        Training.LearnLevel30ClassSpells(player)
    end

    if level >= 35 and Training and Training.LearnLevel35ClassSpells then
        Training.LearnLevel35ClassSpells(player)
    end

    if level >= 40 and Training and Training.LearnLevel40ClassSpells then
        Training.LearnLevel40ClassSpells(player)
    end

    if showMessage then
        U.SendGuideMessage(player, "Your class training and weapon skills have been updated for level " .. level .. ".")
    end
end

function Frostforge.AutoTraining.TrainPlayerForCurrentLevel(player, showMessage)
    TrainPlayerForCurrentLevel(player, showMessage)
end

local function OnPlayerLevelChanged(event, player, oldLevel)
    TrainPlayerForCurrentLevel(player, true)
end

local function OnPlayerLogin(event, player)
    TrainPlayerForCurrentLevel(player, false)
end

RegisterPlayerEvent(13, OnPlayerLevelChanged)
RegisterPlayerEvent(3, OnPlayerLogin)

print("[Frostforge] Auto training loaded.")
