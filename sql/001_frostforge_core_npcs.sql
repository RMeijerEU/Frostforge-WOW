USE acore_world;

DELETE FROM creature_template_model WHERE CreatureID BETWEEN 900010 AND 900099;
DELETE FROM creature_template WHERE entry BETWEEN 900010 AND 900099;

-- MySQL dump 10.13  Distrib 8.4.9, for Linux (x86_64)
--
-- Host: localhost    Database: acore_world
-- ------------------------------------------------------
-- Server version	8.4.9

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Dumping data for table `creature_template`
--
-- WHERE:  entry BETWEEN 900010 AND 900099

LOCK TABLES `creature_template` WRITE;
/*!40000 ALTER TABLE `creature_template` DISABLE KEYS */;
INSERT INTO `creature_template` VALUES (900010,0,0,0,0,0,'Frostforge Guide','Systems Guide',NULL,0,80,80,2,35,129,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'frostforge_bot_group_gossip',NULL),(900011,0,0,0,0,0,'Archivist Edrin','The Storyteller',NULL,0,80,80,2,35,3,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900020,0,0,0,0,0,'Frostforge Grunt','Orgrimmar Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900021,0,0,0,0,0,'Frostforge Shaman','Orgrimmar Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900022,0,0,0,0,0,'Frostforge Guard','Orgrimmar Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900030,0,0,0,0,0,'Frostforge Crossroads Scout','Barrens Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900031,0,0,0,0,0,'Frostforge Druidic Adept','Barrens Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900032,0,0,0,0,0,'Frostforge Barrens Watcher','Barrens Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900040,0,0,0,0,0,'Frostforge Westfall Farmer','Westfall Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900041,0,0,0,0,0,'Frostforge Stormwind Marshal','Westfall Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900042,0,0,0,0,0,'Frostforge Defias Informant','Westfall Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900043,0,0,0,0,0,'Frostforge SI:7 Agent','Defias Investigation',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900044,0,0,0,0,0,'Frostforge Stormwind Informant','SI:7 Contact',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900045,0,0,0,0,0,'Frostforge Prison Warden','Stockades Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900046,0,0,0,0,0,'Frostforge Defias Prisoner','Stockades Witness',NULL,0,80,80,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900047,0,0,0,0,0,'Frostforge Forsaken Scout','Silverpine Watcher',NULL,0,27,27,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900048,0,0,0,0,0,'Frostforge Gilnean Refugee','Survivor of the Curse',NULL,0,27,27,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900049,0,0,0,0,0,'Frostforge Twilight Acolyte','Whisper of the Depths',NULL,0,29,29,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900050,0,0,0,0,0,'Frostforge Zoram Scout','Watcher of the Shore',NULL,0,29,29,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900051,0,0,0,0,0,'Frostforge Gnome Survivor','Exile of Gnomeregan',NULL,0,31,31,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900052,0,0,0,0,0,'Frostforge Irradiated Technician','Witness to Betrayal',NULL,0,31,31,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900053,0,0,0,0,0,'Frostforge Barrens Messenger','Bearer of Warnings',NULL,0,33,33,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900054,0,0,0,0,0,'Frostforge Quilboar Captive','Razormane Outcast',NULL,0,33,33,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900055,0,0,0,0,0,'Frostforge Scarlet Defector','Former Crusader',NULL,0,35,35,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900056,0,0,0,0,0,'Frostforge Forsaken Observer','Watcher of the Monastery',NULL,0,35,35,2,35,1,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900071,0,0,0,0,0,'Frostforge Credit: Eldrin at The Sepulcher','Quest Credit',NULL,0,80,80,2,35,0,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900072,0,0,0,0,0,'Frostforge Credit: Eldrin at Shadowfang Keep','Quest Credit',NULL,0,80,80,2,35,0,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900073,0,0,0,0,0,'Frostforge Credit: Eldrin at Zoram Strand','Quest Credit',NULL,0,80,80,2,35,0,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900074,0,0,0,0,0,'Frostforge Credit: Eldrin at Blackfathom Deeps','Quest Credit',NULL,0,80,80,2,35,0,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900075,0,0,0,0,0,'Frostforge Credit: Eldrin at Gnomeregan','Quest Credit',NULL,0,80,80,2,35,0,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL),(900076,0,0,0,0,0,'Frostforge Credit: Eldrin at Razorfen Kraul','Quest Credit',NULL,0,80,80,2,35,0,1,1.14286,1,1,20,0,0,1,0,0,1,1,1,0,0,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,0,0,1,0,0,'',NULL);
/*!40000 ALTER TABLE `creature_template` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2026-05-19 20:29:39
-- MySQL dump 10.13  Distrib 8.4.9, for Linux (x86_64)
--
-- Host: localhost    Database: acore_world
-- ------------------------------------------------------
-- Server version	8.4.9

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Dumping data for table `creature_template_model`
--
-- WHERE:  CreatureID BETWEEN 900010 AND 900099

LOCK TABLES `creature_template_model` WRITE;
/*!40000 ALTER TABLE `creature_template_model` DISABLE KEYS */;
INSERT INTO `creature_template_model` VALUES (900010,0,1298,1,1,NULL),(900011,0,18921,1,1,12340),(900020,0,4602,1,1,NULL),(900021,0,18408,1,1,12340),(900021,1,18456,1,1,12340),(900022,0,4604,1,1,NULL),(900030,0,4602,1,1,NULL),(900031,0,18408,1,1,12340),(900031,1,18456,1,1,12340),(900032,0,4604,1,1,NULL),(900040,0,1944,1,1,51831),(900041,0,1690,1,1,51831),(900042,0,4418,1,1,51831),(900042,1,4419,1,1,51831),(900043,0,1736,1,1,51831),(900044,0,1690,1,1,0),(900045,0,3167,1,1,0),(900046,0,4418,1,1,0),(900047,0,2859,1,1,0),(900048,0,4418,1,1,0),(900049,0,2882,1,1,0),(900050,0,2027,1,1,0),(900051,0,736,1,1,0),(900052,0,736,1,1,0),(900053,0,4602,1,1,0),(900054,0,6089,1,1,0),(900055,0,1597,1,1,0),(900056,0,2859,1,1,0);
/*!40000 ALTER TABLE `creature_template_model` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2026-05-19 20:30:07
