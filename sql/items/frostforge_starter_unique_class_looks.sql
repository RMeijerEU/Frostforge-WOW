USE acore_world;

-- ============================================================
-- Frostforge Starter Gear - Unique class look pass
--
-- Only updates displayid.
-- Stats remain exactly as they are now.
-- Requires rebuilding Item.dbc + patch-F.MPQ afterwards.
-- ============================================================


-- ============================================================
-- Warrior
-- Theme: brutal Naxx warrior arsenal
-- No legendary/iconic hunter bow here.
-- ============================================================

-- 2H axe: Severance
UPDATE item_template SET displayid = 35371 WHERE entry = 990020;

-- Dual wield axes: Crul'shorukh + Hatchet of Sundered Bone
UPDATE item_template SET displayid = 31870 WHERE entry = 990021;
UPDATE item_template SET displayid = 35258 WHERE entry = 990022;

-- Protection mace: Misplaced Servo Arm
UPDATE item_template SET displayid = 35643 WHERE entry = 990023;

-- Protection shield: The Face of Death
UPDATE item_template SET displayid = 35576 WHERE entry = 990024;

-- Ranged: Heartstriker, less "hunter legendary" than Soulstring/Rhok'delar
UPDATE item_template SET displayid = 32080 WHERE entry = 990025;


-- ============================================================
-- Paladin
-- Theme: fallen crusader / corrupted holy knight
-- ============================================================

-- Retribution 2H: Corrupted Ashbringer
UPDATE item_template SET displayid = 35097 WHERE entry = 990120;

-- Protection mace: The Castigator
UPDATE item_template SET displayid = 35250 WHERE entry = 990121;

-- Protection shield: Shield of Condemnation
UPDATE item_template SET displayid = 35573 WHERE entry = 990122;

-- Librams: keep original relic displayids.
-- Relics are not visible on the character model.


-- ============================================================
-- Hunter
-- Theme: Naxx marksman / cryptstalker hunter
-- ============================================================

-- Bow: Soulstring
UPDATE item_template SET displayid = 35870 WHERE entry = 990220;

-- Polearm stat stick: The Eye of Nerub
UPDATE item_template SET displayid = 35259 WHERE entry = 990221;

-- Quiver: keep original displayid.
-- Quivers are not displayed like normal gear in 3.3.5.


-- ============================================================
-- Rogue
-- Theme: assassin / Bonescythe
-- ============================================================

-- Daggers: Kingsfall + Maexxna's Fang
UPDATE item_template SET displayid = 35819 WHERE entry = 990320;
UPDATE item_template SET displayid = 35709 WHERE entry = 990321;

-- Thrown: keep original displayid for now.
-- No strong Classic Naxx thrown source was found in the current output.


-- ============================================================
-- Priest
-- Theme: Faith / holy Naxx caster
-- ============================================================

-- Staff: Atiesh priest-style
UPDATE item_template SET displayid = 35632 WHERE entry = 990420;

-- Dagger: Midnight Haze
UPDATE item_template SET displayid = 35244 WHERE entry = 990421;

-- Offhand: Noth's Frigid Heart
UPDATE item_template SET displayid = 35813 WHERE entry = 990422;

-- Wand: Doomfinger
UPDATE item_template SET displayid = 35263 WHERE entry = 990423;


-- ============================================================
-- Death Knight
-- Theme: death knight / corrupted Naxx plate
-- ============================================================

-- 2H weapon: Claymore of Unholy Might
-- Less "paladin Ashbringer", more DK-feeling.
UPDATE item_template SET displayid = 35255 WHERE entry = 990520;

-- Dual wield weapons: Widow's Remorse + Iblis
UPDATE item_template SET displayid = 35247 WHERE entry = 990521;
UPDATE item_template SET displayid = 36376 WHERE entry = 990522;

-- 1H mace: Misplaced Servo Arm
UPDATE item_template SET displayid = 35643 WHERE entry = 990523;


-- ============================================================
-- Shaman
-- Theme: Earthshatter / spiritual Naxx caster-enhancement hybrid
-- ============================================================

-- Staff: Brimstone Staff
UPDATE item_template SET displayid = 35241 WHERE entry = 990620;

-- Caster dagger: Midnight Haze
UPDATE item_template SET displayid = 35244 WHERE entry = 990621;

-- Offhand: Noth's Frigid Heart
UPDATE item_template SET displayid = 35813 WHERE entry = 990622;

-- Shield: The Plague Bearer
UPDATE item_template SET displayid = 35577 WHERE entry = 990623;

-- Enhancement axes: Blessed Qiraji War Axe + Hatchet of Sundered Bone
-- AQ/Naxx-era look, distinct from Warrior.
UPDATE item_template SET displayid = 34178 WHERE entry = 990624;
UPDATE item_template SET displayid = 35258 WHERE entry = 990625;

-- Totems: keep original relic displayids.
-- Totems are not visible on the character model.


-- ============================================================
-- Mage
-- Theme: Frostfire / arcane Naxx caster
-- ============================================================

-- Staff: Soulseeker
UPDATE item_template SET displayid = 35240 WHERE entry = 990720;

-- Dagger: Wraith Blade
UPDATE item_template SET displayid = 36371 WHERE entry = 990721;

-- Offhand: Noth's Frigid Heart
UPDATE item_template SET displayid = 35813 WHERE entry = 990722;

-- Wand: Wand of Fates
UPDATE item_template SET displayid = 35262 WHERE entry = 990723;


-- ============================================================
-- Warlock
-- Theme: Plagueheart / dark Naxx caster
-- ============================================================

-- Staff: Spire of Twilight
UPDATE item_template SET displayid = 35242 WHERE entry = 990820;

-- Dagger: Harbinger of Doom
UPDATE item_template SET displayid = 35246 WHERE entry = 990821;

-- Offhand: Noth's Frigid Heart
UPDATE item_template SET displayid = 35813 WHERE entry = 990822;

-- Wand: Wand of the Whispering Dead
UPDATE item_template SET displayid = 35262 WHERE entry = 990823;

-- Soul shard bag: keep original displayid.


-- ============================================================
-- Druid
-- Theme: Dreamwalker / nature-Naxx hybrid
-- ============================================================

-- Caster/healer staff: Atiesh druid-style
UPDATE item_template SET displayid = 35633 WHERE entry = 990920;

-- Dagger: The End of Dreams
UPDATE item_template SET displayid = 35710 WHERE entry = 990921;

-- Offhand: Noth's Frigid Heart
UPDATE item_template SET displayid = 35813 WHERE entry = 990922;

-- Feral polearm: The Eye of Nerub
UPDATE item_template SET displayid = 35259 WHERE entry = 990923;

-- Idols: keep original relic displayids.
-- Idols are not visible on the character model.


-- ============================================================
-- Verification
-- ============================================================

SELECT
  entry,
  name,
  class,
  subclass,
  displayid,
  InventoryType,
  RequiredLevel,
  ItemLevel,
  Quality,
  AllowableClass
FROM item_template
WHERE entry IN (
  990020,990021,990022,990023,990024,990025,
  990120,990121,990122,990125,990126,
  990220,990221,990222,
  990320,990321,990322,
  990420,990421,990422,990423,
  990520,990521,990522,990523,
  990620,990621,990622,990623,990624,990625,990626,990627,990628,
  990720,990721,990722,990723,
  990820,990821,990822,990823,990824,
  990920,990921,990922,990923,990924,990925,990926
)
ORDER BY entry;
