#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "Chat.h"
#include "Group.h"
#include <vector>

namespace Frostforge
{
    static constexpr uint32 NPC_FROSTFORGE_GUIDE = 900010;

    static constexpr uint32 QUEST_ULDAMAN_GROUP = 900163;

    static constexpr uint32 MAP_RFC = 389;

    static constexpr uint32 MAP_WAILING_CAVERNS = 43;

    static constexpr uint32 MAP_DEADMINES = 36;

    static constexpr uint32 MAP_STOCKADES = 34;

    static constexpr uint32 MAP_SHADOWFANG_KEEP = 33;

    static constexpr uint32 MAP_BLACKFATHOM_DEEPS = 48;

    static constexpr uint32 MAP_GNOMEREGAN = 90;

    static constexpr uint32 MAP_RAZORFEN_KRAUL = 47;

    static constexpr uint32 MAP_SCARLET_MONASTERY = 189;

    static constexpr uint32 MAP_ULDAMAN = 70;

    static constexpr uint32 MAP_ZULFARRAK = 209;

    static constexpr float RFC_INSIDE_X = 5.835333f;
    static constexpr float RFC_INSIDE_Y = -25.63047f;
    static constexpr float RFC_INSIDE_Z = -20.681316f;
    static constexpr float RFC_INSIDE_O = 1.944269f;

    static constexpr float WC_INSIDE_X = -163.49f;
    static constexpr float WC_INSIDE_Y = 132.9f;
    static constexpr float WC_INSIDE_Z = -73.66215f;
    static constexpr float WC_INSIDE_O = 5.83f;

    static constexpr float DM_INSIDE_X = -16.4f;
    static constexpr float DM_INSIDE_Y = -383.07f;
    static constexpr float DM_INSIDE_Z = 61.78f;
    static constexpr float DM_INSIDE_O = 1.86f;

    static constexpr float STOCKADES_INSIDE_X = 54.238277f;
    static constexpr float STOCKADES_INSIDE_Y = 0.63690406f;
    static constexpr float STOCKADES_INSIDE_Z = -18.344336f;
    static constexpr float STOCKADES_INSIDE_O = 6.26f;

    static constexpr float SFK_INSIDE_X = -229.135f;
    static constexpr float SFK_INSIDE_Y = 2110.56f;
    static constexpr float SFK_INSIDE_Z = 76.8898f;
    static constexpr float SFK_INSIDE_O = 1.267f;

    static constexpr float BFD_INSIDE_X = -150.234f;
    static constexpr float BFD_INSIDE_Y = 106.594f;
    static constexpr float BFD_INSIDE_Z = -40.095f;
    static constexpr float BFD_INSIDE_O = 4.45f;

    static constexpr float GNOMER_INSIDE_X = -332.22f;
    static constexpr float GNOMER_INSIDE_Y = -2.28f;
    static constexpr float GNOMER_INSIDE_Z = -150.86f;
    static constexpr float GNOMER_INSIDE_O = 2.77f;

    static constexpr float RFK_INSIDE_X = 1943.0f;
    static constexpr float RFK_INSIDE_Y = 1544.63f;
    static constexpr float RFK_INSIDE_Z = 82.56f;
    static constexpr float RFK_INSIDE_O = 1.38f;

    static constexpr float SM_GY_INSIDE_X = 1688.99f;
    static constexpr float SM_GY_INSIDE_Y = 1053.48f;
    static constexpr float SM_GY_INSIDE_Z = 18.68f;
    static constexpr float SM_GY_INSIDE_O = 0.00f;

    static constexpr float SM_LIB_INSIDE_X = 255.346f;
    static constexpr float SM_LIB_INSIDE_Y = -209.09f;
    static constexpr float SM_LIB_INSIDE_Z = 18.68f;
    static constexpr float SM_LIB_INSIDE_O = 6.28f;

    static constexpr float SM_ARM_INSIDE_X = 1608.10f;
    static constexpr float SM_ARM_INSIDE_Y = -318.92f;
    static constexpr float SM_ARM_INSIDE_Z = 18.67f;
    static constexpr float SM_ARM_INSIDE_O = 6.28f;

    static constexpr float SM_CATH_INSIDE_X = 855.68f;
    static constexpr float SM_CATH_INSIDE_Y = 1321.50f;
    static constexpr float SM_CATH_INSIDE_Z = 18.67f;
    static constexpr float SM_CATH_INSIDE_O = 0.00f;

    static constexpr float ULDAMAN_INSIDE_X = -228.19f;
    static constexpr float ULDAMAN_INSIDE_Y = 46.16f;
    static constexpr float ULDAMAN_INSIDE_Z = -46.02f;
    static constexpr float ULDAMAN_INSIDE_O = 1.57f;

    static constexpr float RFC_ENTRANCE_X = 1811.78f;
    static constexpr float RFC_ENTRANCE_Y = -4410.50f;
    static constexpr float RFC_ENTRANCE_Z = -18.47f;

    static constexpr float WC_PORTAL_X = -739.416f;
    static constexpr float WC_PORTAL_Y = -2226.96f;
    static constexpr float WC_PORTAL_Z = 19.6249f;

    static constexpr float DM_ENTRANCE_X = -11208.0f;
    static constexpr float DM_ENTRANCE_Y = 1673.0f;
    static constexpr float DM_ENTRANCE_Z = 24.0f;

    static constexpr float STOCKADES_ENTRANCE_X = -8776.03f;
    static constexpr float STOCKADES_ENTRANCE_Y = 842.575f;
    static constexpr float STOCKADES_ENTRANCE_Z = 91.6065f;

    static constexpr float SFK_ENTRANCE_X = -233.0f;
    static constexpr float SFK_ENTRANCE_Y = 1567.0f;
    static constexpr float SFK_ENTRANCE_Z = 76.9f;

    static constexpr float BFD_ENTRANCE_X = 4247.74f;
    static constexpr float BFD_ENTRANCE_Y = 745.879f;
    static constexpr float BFD_ENTRANCE_Z = -24.5299f;

    static constexpr float GNOMER_ENTRANCE_X = -5163.54f;
    static constexpr float GNOMER_ENTRANCE_Y = 925.423f;
    static constexpr float GNOMER_ENTRANCE_Z = 257.181f;

    static constexpr float RFK_ENTRANCE_X = -4464.92f;
    static constexpr float RFK_ENTRANCE_Y = -1666.24f;
    static constexpr float RFK_ENTRANCE_Z = 81.8928f;

    static constexpr float SM_ENTRANCE_X = 2871.0f;
    static constexpr float SM_ENTRANCE_Y = -819.0f;
    static constexpr float SM_ENTRANCE_Z = 160.0f;

    static constexpr float ULDAMAN_CAVE_GUIDE_X = -6094.97f;
    static constexpr float ULDAMAN_CAVE_GUIDE_Y = -3187.6858f;
    static constexpr float ULDAMAN_CAVE_GUIDE_Z = 255.78978f;

    static constexpr float ULDAMAN_PORTAL_GUIDE_X = -6069.0f;
    static constexpr float ULDAMAN_PORTAL_GUIDE_Y = -2953.0f;
    static constexpr float ULDAMAN_PORTAL_GUIDE_Z = 209.77402f;

    static constexpr float ULDAMAN_PORTAL_X = -6067.4062f;
    static constexpr float ULDAMAN_PORTAL_Y = -2950.7139f;
    static constexpr float ULDAMAN_PORTAL_Z = 209.77402f;
    static constexpr float ULDAMAN_PORTAL_O = 3.5902698f;

    static constexpr float ZF_INSIDE_X = 1218.9818f;
    static constexpr float ZF_INSIDE_Y = 847.068f;
    static constexpr float ZF_INSIDE_Z = 9.76403f;
    static constexpr float ZF_INSIDE_O = 5.8433847f;

    static constexpr float ZF_ENTRANCE_GUIDE_X = -6798.3804f;
    static constexpr float ZF_ENTRANCE_GUIDE_Y = -2895.9358f;
    static constexpr float ZF_ENTRANCE_GUIDE_Z = 9.17488f;

    static constexpr float ZF_PORTAL_GUIDE_X = -6796.5f;
    static constexpr float ZF_PORTAL_GUIDE_Y = -2898.0f;
    static constexpr float ZF_PORTAL_GUIDE_Z = 9.17488f;

    static constexpr float ZF_PORTAL_X = -6801.0f;
    static constexpr float ZF_PORTAL_Y = -2893.5f;
    static constexpr float ZF_PORTAL_Z = 9.17488f;
    static constexpr float ZF_PORTAL_O = 2.1502473f;

    static void RunCommand(Player* player, char const* command)
    {
        if (!player || !player->GetSession())
            return;

        ChatHandler handler(player->GetSession());
        handler.ParseCommands(command);
    }

    static bool IsRagefireEntranceGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 1)
            return false;

        return creature->GetDistance(RFC_ENTRANCE_X, RFC_ENTRANCE_Y, RFC_ENTRANCE_Z) < 75.0f;
    }

    static bool IsWailingCavernsGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 1)
            return false;

        return creature->GetDistance(WC_PORTAL_X, WC_PORTAL_Y, WC_PORTAL_Z) < 75.0f;
    }

    static bool IsDeadminesGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 0)
            return false;

        return creature->GetDistance(DM_ENTRANCE_X, DM_ENTRANCE_Y, DM_ENTRANCE_Z) < 250.0f;
    }

    static bool IsStockadesGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 0)
            return false;

        return creature->GetDistance(STOCKADES_ENTRANCE_X, STOCKADES_ENTRANCE_Y, STOCKADES_ENTRANCE_Z) < 75.0f;
    }

    static bool IsShadowfangKeepGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 0)
            return false;

        return creature->GetDistance(SFK_ENTRANCE_X, SFK_ENTRANCE_Y, SFK_ENTRANCE_Z) < 100.0f;
    }

    static bool IsBlackfathomDeepsGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 1)
            return false;

        return creature->GetDistance(BFD_ENTRANCE_X, BFD_ENTRANCE_Y, BFD_ENTRANCE_Z) < 150.0f;
    }

    static bool IsGnomereganGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 0)
            return false;

        return creature->GetDistance(GNOMER_ENTRANCE_X, GNOMER_ENTRANCE_Y, GNOMER_ENTRANCE_Z) < 150.0f;
    }

    static bool IsRazorfenKraulGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 1)
            return false;

        return creature->GetDistance(RFK_ENTRANCE_X, RFK_ENTRANCE_Y, RFK_ENTRANCE_Z) < 150.0f;
    }

    static bool IsScarletMonasteryGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 0)
            return false;

        return creature->GetDistance(SM_ENTRANCE_X, SM_ENTRANCE_Y, SM_ENTRANCE_Z) < 250.0f;
    }

    static bool IsUldamanCaveGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 0)
            return false;

        return creature->GetDistance(ULDAMAN_CAVE_GUIDE_X, ULDAMAN_CAVE_GUIDE_Y, ULDAMAN_CAVE_GUIDE_Z) < 75.0f;
    }

    static bool IsUldamanPortalGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 0)
            return false;

        return creature->GetDistance(ULDAMAN_PORTAL_GUIDE_X, ULDAMAN_PORTAL_GUIDE_Y, ULDAMAN_PORTAL_GUIDE_Z) < 75.0f;
    }

    static bool IsZulFarrakEntranceGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 1)
            return false;

        return creature->GetDistance(ZF_ENTRANCE_GUIDE_X, ZF_ENTRANCE_GUIDE_Y, ZF_ENTRANCE_GUIDE_Z) < 1.5f;
    }

    static bool IsZulFarrakPortalGuide(Creature* creature)
    {
        if (!creature)
            return false;

        if (creature->GetMapId() != 1)
            return false;

        return creature->GetDistance(ZF_PORTAL_GUIDE_X, ZF_PORTAL_GUIDE_Y, ZF_PORTAL_GUIDE_Z) < 1.5f;
    }

    static void TeleportGroup(Player* player, uint32 mapId, float x, float y, float z, float o)
    {
        if (!player)
            return;

        Group* group = player->GetGroup();

        if (!group)
        {
            player->TeleportTo(mapId, x, y, z, o);
            return;
        }

        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* member = itr->GetSource();

            if (!member || !member->IsInWorld())
                continue;

            member->TeleportTo(mapId, x, y, z, o);
        }
    }

    static void AddClassIfNotPlayer(Player* player, uint8 playerClass, uint8 botClass, char const* className)
    {
        if (!player)
            return;

        if (playerClass == botClass)
            return;

        std::string command = ".playerbots bot addclass ";
        command += className;

        RunCommand(player, command.c_str());
    }

    static void MakeGroupFromList(Player* player, std::vector<std::pair<uint8, char const*>> const& classes, char const* label)
    {
        if (!player)
            return;

        uint8 playerClass = player->getClass();
        uint8 added = 0;

        for (auto const& entry : classes)
        {
            if (added >= 4)
                break;

            if (entry.first == playerClass)
                continue;

            AddClassIfNotPlayer(player, playerClass, entry.first, entry.second);
            ++added;
        }

        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r %s group requested.", label);
    }

    static void MakeTankGroup(Player* player)
    {
        MakeGroupFromList(player,
        {
            {5, "priest"},
            {8, "mage"},
            {3, "hunter"},
            {4, "rogue"},
            {9, "warlock"},
            {7, "shaman"}
        },
        "Tank");
    }

    static void MakeDamageGroup(Player* player)
    {
        MakeGroupFromList(player,
        {
            {1, "warrior"},
            {5, "priest"},
            {8, "mage"},
            {3, "hunter"},
            {4, "rogue"},
            {9, "warlock"},
            {7, "shaman"}
        },
        "Damage");
    }

    static void MakeHealerGroup(Player* player)
    {
        MakeGroupFromList(player,
        {
            {1, "warrior"},
            {8, "mage"},
            {3, "hunter"},
            {4, "rogue"},
            {9, "warlock"},
            {7, "shaman"}
        },
        "Healer");
    }

    static void RemoveBotGroup(Player* player)
    {
        RunCommand(player, ".playerbots bot remove *");
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Playerbot group remove requested.");
    }

    static void SendGroupInsideRagefire(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Ragefire Chasm.");
        TeleportGroup(player, MAP_RFC, RFC_INSIDE_X, RFC_INSIDE_Y, RFC_INSIDE_Z, RFC_INSIDE_O);
    }

    static void SendGroupInsideWailingCaverns(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Wailing Caverns.");
        TeleportGroup(player, MAP_WAILING_CAVERNS, WC_INSIDE_X, WC_INSIDE_Y, WC_INSIDE_Z, WC_INSIDE_O);
    }

    static void SendGroupInsideDeadmines(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside the Deadmines.");
        TeleportGroup(player, MAP_DEADMINES, DM_INSIDE_X, DM_INSIDE_Y, DM_INSIDE_Z, DM_INSIDE_O);
    }

    static void SendGroupInsideStockades(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside the Stockades.");
        TeleportGroup(player, MAP_STOCKADES, STOCKADES_INSIDE_X, STOCKADES_INSIDE_Y, STOCKADES_INSIDE_Z, STOCKADES_INSIDE_O);
    }

    static void SendGroupInsideShadowfangKeep(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Shadowfang Keep.");
        TeleportGroup(player, MAP_SHADOWFANG_KEEP, SFK_INSIDE_X, SFK_INSIDE_Y, SFK_INSIDE_Z, SFK_INSIDE_O);
    }

    static void SendGroupInsideBlackfathomDeeps(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Blackfathom Deeps.");
        TeleportGroup(player, MAP_BLACKFATHOM_DEEPS, BFD_INSIDE_X, BFD_INSIDE_Y, BFD_INSIDE_Z, BFD_INSIDE_O);
    }

    static void SendGroupInsideGnomeregan(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Gnomeregan.");
        TeleportGroup(player, MAP_GNOMEREGAN, GNOMER_INSIDE_X, GNOMER_INSIDE_Y, GNOMER_INSIDE_Z, GNOMER_INSIDE_O);
    }

    static void SendGroupInsideRazorfenKraul(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Razorfen Kraul.");
        TeleportGroup(player, MAP_RAZORFEN_KRAUL, RFK_INSIDE_X, RFK_INSIDE_Y, RFK_INSIDE_Z, RFK_INSIDE_O);
    }

    static void SendGroupInsideScarletMonasteryGraveyard(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Scarlet Monastery: Graveyard.");
        TeleportGroup(player, MAP_SCARLET_MONASTERY, SM_GY_INSIDE_X, SM_GY_INSIDE_Y, SM_GY_INSIDE_Z, SM_GY_INSIDE_O);
    }

    static void SendGroupInsideScarletMonasteryLibrary(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Scarlet Monastery: Library.");
        TeleportGroup(player, MAP_SCARLET_MONASTERY, SM_LIB_INSIDE_X, SM_LIB_INSIDE_Y, SM_LIB_INSIDE_Z, SM_LIB_INSIDE_O);
    }

    static void SendGroupInsideScarletMonasteryArmory(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Scarlet Monastery: Armory.");
        TeleportGroup(player, MAP_SCARLET_MONASTERY, SM_ARM_INSIDE_X, SM_ARM_INSIDE_Y, SM_ARM_INSIDE_Z, SM_ARM_INSIDE_O);
    }

    static void SendGroupInsideScarletMonasteryCathedral(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Scarlet Monastery: Cathedral.");
        TeleportGroup(player, MAP_SCARLET_MONASTERY, SM_CATH_INSIDE_X, SM_CATH_INSIDE_Y, SM_CATH_INSIDE_Z, SM_CATH_INSIDE_O);
    }

    static void SendGroupToUldamanPortal(Player* player)
    {
        if (player)
            player->KilledMonsterCredit(NPC_FROSTFORGE_GUIDE);

        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Your group is ready. Sending you to the Uldaman vault entrance.");
        TeleportGroup(player, 0, ULDAMAN_PORTAL_X, ULDAMAN_PORTAL_Y, ULDAMAN_PORTAL_Z, ULDAMAN_PORTAL_O);
    }

    static void SendGroupInsideUldaman(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Uldaman.");
        TeleportGroup(player, MAP_ULDAMAN, ULDAMAN_INSIDE_X, ULDAMAN_INSIDE_Y, ULDAMAN_INSIDE_Z, ULDAMAN_INSIDE_O);
    }

    static void SendGroupToZulFarrakPortal(Player* player)
    {
        if (player)
            player->KilledMonsterCredit(NPC_FROSTFORGE_GUIDE);

        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Your group is ready. Sending you to the Zul'Farrak portal.");
        TeleportGroup(player, 1, ZF_PORTAL_X, ZF_PORTAL_Y, ZF_PORTAL_Z, ZF_PORTAL_O);
    }

    static void SendGroupInsideZulFarrak(Player* player)
    {
        ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Sending your group inside Zul'Farrak.");
        TeleportGroup(player, MAP_ZULFARRAK, ZF_INSIDE_X, ZF_INSIDE_Y, ZF_INSIDE_Z, ZF_INSIDE_O);
    }
}

class frostforge_bot_group_gossip : public CreatureScript
{
public:
    frostforge_bot_group_gossip() : CreatureScript("frostforge_bot_group_gossip") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->GetEntry() != Frostforge::NPC_FROSTFORGE_GUIDE)
            return false;

        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to play as tank. Make me a group.", GOSSIP_SENDER_MAIN, 100);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to play as damage. Make me a group.", GOSSIP_SENDER_MAIN, 101);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to play as healer. Make me a group.", GOSSIP_SENDER_MAIN, 102);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Remove my Playerbot group.", GOSSIP_SENDER_MAIN, 103);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "How do I control my bots in dungeons?", GOSSIP_SENDER_MAIN, 104);
        AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Show me supplies.", GOSSIP_SENDER_MAIN, 9000);

        if (Frostforge::IsRagefireEntranceGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Ragefire Chasm.", GOSSIP_SENDER_MAIN, 200);

        if (Frostforge::IsWailingCavernsGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Wailing Caverns.", GOSSIP_SENDER_MAIN, 201);

        if (Frostforge::IsDeadminesGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside The Deadmines.", GOSSIP_SENDER_MAIN, 202);

        if (Frostforge::IsStockadesGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside The Stockades.", GOSSIP_SENDER_MAIN, 203);

        if (Frostforge::IsShadowfangKeepGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Shadowfang Keep.", GOSSIP_SENDER_MAIN, 204);

        if (Frostforge::IsBlackfathomDeepsGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Blackfathom Deeps.", GOSSIP_SENDER_MAIN, 205);

        if (Frostforge::IsGnomereganGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Gnomeregan.", GOSSIP_SENDER_MAIN, 206);

        if (Frostforge::IsRazorfenKraulGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Razorfen Kraul.", GOSSIP_SENDER_MAIN, 207);

        if (Frostforge::IsScarletMonasteryGuide(creature))
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Scarlet Monastery: Graveyard.", GOSSIP_SENDER_MAIN, 208);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Scarlet Monastery: Library.", GOSSIP_SENDER_MAIN, 209);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Scarlet Monastery: Armory.", GOSSIP_SENDER_MAIN, 210);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Scarlet Monastery: Cathedral.", GOSSIP_SENDER_MAIN, 211);
        }

        if (Frostforge::IsUldamanCaveGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group to the Uldaman entrance.", GOSSIP_SENDER_MAIN, 212);

        if (Frostforge::IsUldamanPortalGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Uldaman.", GOSSIP_SENDER_MAIN, 213);

        if (Frostforge::IsZulFarrakEntranceGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group to the Zul'Farrak portal.", GOSSIP_SENDER_MAIN, 214);

        if (Frostforge::IsZulFarrakPortalGuide(creature))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Send my group inside Zul'Farrak.", GOSSIP_SENDER_MAIN, 215);

        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);

        switch (action)
        {
            case 100:
                Frostforge::MakeTankGroup(player);
                break;

            case 101:
                Frostforge::MakeDamageGroup(player);
                break;

            case 102:
                Frostforge::MakeHealerGroup(player);
                break;

            case 103:
                Frostforge::RemoveBotGroup(player);
                break;

            case 104:
                ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Target an enemy and type |cffffff00/p attack|r to make your bots attack it.");
                ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Use |cffffff00/p follow|r if your bots fall behind.");
                ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Use |cffffff00/p flee|r to make bots run back to you.");
                ChatHandler(player->GetSession()).PSendSysMessage("|cff66ccffFrostforge Guide:|r Use |cffffff00/p grind|r only with care. It makes bots attack anything nearby.");
                break;

            case 200:
                Frostforge::SendGroupInsideRagefire(player);
                break;

            case 201:
                Frostforge::SendGroupInsideWailingCaverns(player);
                break;

            case 202:
                Frostforge::SendGroupInsideDeadmines(player);
                break;

            case 203:
                Frostforge::SendGroupInsideStockades(player);
                break;

            case 204:
                Frostforge::SendGroupInsideShadowfangKeep(player);
                break;

            case 205:
                Frostforge::SendGroupInsideBlackfathomDeeps(player);
                break;

            case 206:
                Frostforge::SendGroupInsideGnomeregan(player);
                break;

            case 207:
                Frostforge::SendGroupInsideRazorfenKraul(player);
                break;

            case 208:
                Frostforge::SendGroupInsideScarletMonasteryGraveyard(player);
                break;

            case 209:
                Frostforge::SendGroupInsideScarletMonasteryLibrary(player);
                break;

            case 210:
                Frostforge::SendGroupInsideScarletMonasteryArmory(player);
                break;

            case 211:
                Frostforge::SendGroupInsideScarletMonasteryCathedral(player);
                break;

            case 212:
                Frostforge::SendGroupToUldamanPortal(player);
                break;

            case 213:
                Frostforge::SendGroupInsideUldaman(player);
                break;

            case 214:
                Frostforge::SendGroupToZulFarrakPortal(player);
                break;

            case 215:
                Frostforge::SendGroupInsideZulFarrak(player);
                break;                

            case 9000:
                player->GetSession()->SendListInventory(creature->GetGUID());
                return true;

            default:
                break;
        }

        CloseGossipMenuFor(player);
        return true;
    }
};

void AddSC_frostforge_bot_group()
{
    new frostforge_bot_group_gossip();
}