-- Frostforge Auto Training
-- Keeps player skills, class spells, riding and campaign mounts updated when Frostforge changes player level.

Frostforge = Frostforge or {}
Frostforge.AutoTraining = Frostforge.AutoTraining or {}

local U = Frostforge.Utils
local Starter = Frostforge.StarterGear

local SPELL_APPRENTICE_RIDING = 33388
local SPELL_JOURNEYMAN_RIDING = 33391

-- Neutral TCG mounts, usable as campaign convenience mounts.
-- Replace these later if you prefer faction/race-specific mounts.
local ITEM_REINS_OF_THE_SPECTRAL_TIGER = 33224
local ITEM_REINS_OF_THE_SWIFT_SPECTRAL_TIGER = 33225

local function LearnSpellSafe(player, spellId)
    if not player or not spellId then
        return false
    end

    if player:HasSpell(spellId) then
        return false
    end

    player:LearnSpell(spellId)
    return true
end

local function AddItemOnce(player, itemId)
    if not player or not itemId then
        return false
    end

    if player:HasItem(itemId, 1) then
        return false
    end

    player:AddItem(itemId, 1)
    return true
end

local function LearnRidingAndMounts(player, showMessage)
    if not player then
        return
    end

    local level = player:GetLevel()
    local changed = false

    if level >= 20 then
        if LearnSpellSafe(player, SPELL_APPRENTICE_RIDING) then
            changed = true
        end

        if AddItemOnce(player, ITEM_REINS_OF_THE_SPECTRAL_TIGER) then
            changed = true
        end
    end

    if level >= 40 then
        if LearnSpellSafe(player, SPELL_JOURNEYMAN_RIDING) then
            changed = true
        end

        if AddItemOnce(player, ITEM_REINS_OF_THE_SWIFT_SPECTRAL_TIGER) then
            changed = true
        end
    end

    if changed and showMessage then
        U.SendGuideMessage(player, "Your riding skill and campaign mount access have been updated.")
    end
end

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

    LearnRidingAndMounts(player, showMessage)

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