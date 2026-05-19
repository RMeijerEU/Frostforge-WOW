USE acore_world;

-- ============================================================
-- Frostforge Starter Extras - Classic Naxx/Tier 3 look pass
--
-- This script only updates displayid.
-- Stats, item type, required level, quality and class restrictions stay unchanged.
-- ============================================================


-- ============================================================
-- Warrior
-- ============================================================

-- 2H axe: Severance / Classic Naxx
UPDATE item_template SET displayid = 35371 WHERE entry = 990020;

-- 1H axes: Hatchet of Sundered Bone / Deathbringer-ish classic look
UPDATE item_template SET displayid = 35258 WHERE entry = 990021;
UPDATE item_template SET displayid = 29161 WHERE entry = 990022;

-- 1H mace: Misplaced Servo Arm / Classic Naxx
UPDATE item_template SET displayid = 35643 WHERE entry = 990023;

-- Shield: The Face of Death / Classic Naxx
UPDATE item_template SET displayid = 35576 WHERE entry = 990024;

-- Bow: Soulstring / Classic Naxx
UPDATE item_template SET displayid = 35870 WHERE entry = 990025;


-- ============================================================
-- Paladin
-- ============================================================

-- 2H weapon: Corrupted Ashbringer / Classic Naxx
UPDATE item_template SET displayid = 35097 WHERE entry = 990120;

-- 1H mace: The Widow's Embrace / Classic Naxx
UPDATE item_template SET displayid = 35642 WHERE entry = 990121;

-- Shield: Shield of Condemnation / Classic Naxx
UPDATE item_template SET displayid = 35573 WHERE entry = 990122;

-- Librams: keep original displayids for now
-- Relics are not visible on character model anyway.


-- ============================================================
-- Hunter
-- ============================================================

-- Bow: Soulstring / Classic Naxx
UPDATE item_template SET displayid = 35870 WHERE entry = 990220;

-- Polearm: The Eye of Nerub / Classic Naxx
UPDATE item_template SET displayid = 35259 WHERE entry = 990221;

-- Quiver: keep original displayid for now
-- Quiver is not shown as normal character equipment.


-- ============================================================
-- Rogue
-- ============================================================

-- Daggers: Kingsfall + Harbinger of Doom / Classic Naxx
UPDATE item_template SET displayid = 35819 WHERE entry = 990320;
UPDATE item_template SET displayid = 35246 WHERE entry = 990321;

-- Thrown: keep original displayid for now
-- Classic Naxx has no strong thrown weapon visual match in the current query output.


-- ============================================================
-- Priest
-- ============================================================

-- Staff: Atiesh priest-style / Classic Naxx legendary look
UPDATE item_template SET displayid = 35632 WHERE entry = 990420;

-- Dagger: Midnight Haze / Classic Naxx caster dagger
UPDATE item_template SET displayid = 35244 WHERE entry = 990421;

-- Offhand: Noth's Frigid Heart / Classic Naxx offhand
UPDATE item_template SET displayid = 35813 WHERE entry = 990422;

-- Wand: Doomfinger / Classic Naxx
UPDATE item_template SET displayid = 35263 WHERE entry = 990423;


-- ============================================================
-- Death Knight
-- ============================================================

-- 2H weapon: Corrupted Ashbringer / Classic Naxx
UPDATE item_template SET displayid = 35097 WHERE entry = 990520;

-- 1H weapons: Widow's Remorse + Iblis / Classic Naxx
UPDATE item_template SET displayid = 35247 WHERE entry = 990521;
UPDATE item_template SET displayid = 36376 WHERE entry = 990522;

-- 1H mace: Misplaced Servo Arm / Classic Naxx
UPDATE item_template SET displayid = 35643 WHERE entry = 990523;


-- ============================================================
-- Shaman
-- ============================================================

-- Staff: Soulseeker / Classic Naxx
UPDATE item_template SET displayid = 35240 WHERE entry = 990620;

-- Dagger: Midnight Haze / Classic Naxx caster dagger
UPDATE item_template SET displayid = 35244 WHERE entry = 990621;

-- Offhand: Noth's Frigid Heart / Classic Naxx offhand
UPDATE item_template SET displayid = 35813 WHERE entry = 990622;

-- Shield: The Plague Bearer / Classic Naxx
UPDATE item_template SET displayid = 35577 WHERE entry = 990623;

-- Enhancement weapons: Hatchet of Sundered Bone + Deathbringer
UPDATE item_template SET displayid = 35258 WHERE entry = 990624;
UPDATE item_template SET displayid = 29161 WHERE entry = 990625;

-- Totems: keep original displayids for now.
-- Totems are relic items and not visible on the character model.


-- ============================================================
-- Mage
-- ============================================================

-- Staff: Soulseeker / Classic Naxx
UPDATE item_template SET displayid = 35240 WHERE entry = 990720;

-- Dagger: Midnight Haze / Classic Naxx caster dagger
UPDATE item_template SET displayid = 35244 WHERE entry = 990721;

-- Offhand: Noth's Frigid Heart / Classic Naxx offhand
UPDATE item_template SET displayid = 35813 WHERE entry = 990722;

-- Wand: Doomfinger / Classic Naxx
UPDATE item_template SET displayid = 35263 WHERE entry = 990723;


-- ============================================================
-- Warlock
-- ============================================================

-- Staff: Brimstone Staff / Classic Naxx
UPDATE item_template SET displayid = 35241 WHERE entry = 990820;

-- Dagger: Harbinger of Doom / Classic Naxx
UPDATE item_template SET displayid = 35246 WHERE entry = 990821;

-- Offhand: Noth's Frigid Heart / Classic Naxx offhand
UPDATE item_template SET displayid = 35813 WHERE entry = 990822;

-- Wand: Wand of the Whispering Dead / Classic Naxx
UPDATE item_template SET displayid = 35262 WHERE entry = 990823;

-- Soul shard bag: keep original displayid.


-- ============================================================
-- Druid
-- ============================================================

-- Staff: Atiesh druid-style / Classic Naxx legendary look
UPDATE item_template SET displayid = 35633 WHERE entry = 990920;

-- Dagger: Midnight Haze / Classic Naxx caster dagger
UPDATE item_template SET displayid = 35244 WHERE entry = 990921;

-- Offhand: Noth's Frigid Heart / Classic Naxx offhand
UPDATE item_template SET displayid = 35813 WHERE entry = 990922;

-- Feral polearm: The Eye of Nerub / Classic Naxx
UPDATE item_template SET displayid = 35259 WHERE entry = 990923;

-- Idols: keep original displayids for now.
-- Idols are relic items and not visible on the character model.


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
  990120,990121,990122,
  990220,990221,
  990320,990321,990322,
  990420,990421,990422,990423,
  990520,990521,990522,990523,
  990620,990621,990622,990623,990624,990625,
  990720,990721,990722,990723,
  990820,990821,990822,990823,
  990920,990921,990922,990923
)
ORDER BY entry;
