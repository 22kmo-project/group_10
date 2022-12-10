CREATE DATABASE  IF NOT EXISTS `banksimul` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `banksimul`;
-- MySQL dump 10.13  Distrib 8.0.30, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: banksimul
-- ------------------------------------------------------
-- Server version	8.0.29

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `idAsiakas` int NOT NULL,
  `nimi` varchar(45) NOT NULL,
  `osoite` varchar(45) NOT NULL,
  `puh` varchar(45) NOT NULL,
  PRIMARY KEY (`idAsiakas`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,'Testi Henkilo','Kukkaiskuja 3','0401234567'),(2,'Testi Henkilo2','Testikuja 2','0441234567');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kortti`
--

DROP TABLE IF EXISTS `kortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti` (
  `idKortti` int NOT NULL,
  `pin` varchar(255) NOT NULL,
  `idAsiakas` int NOT NULL,
  PRIMARY KEY (`idKortti`),
  KEY `asiakas-kortti_idx` (`idAsiakas`),
  CONSTRAINT `asiakas-kortti` FOREIGN KEY (`idAsiakas`) REFERENCES `asiakas` (`idAsiakas`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='		';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
INSERT INTO `kortti` VALUES (123456,'$2a$10$mx922eMATtPLhjKWY7ykp.6P8TWJQavHwDEoIdH1fqBEY3u0v3Fa6',1),(654321,'$2a$10$RmJaLlnYthtlxyZusJMW4Or2.7S1XrS87RCEZmawB07M49wjeTPYm',1);
/*!40000 ALTER TABLE `kortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kortti_tili`
--

DROP TABLE IF EXISTS `kortti_tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti_tili` (
  `idKortti_tili` int NOT NULL,
  `idTili` int NOT NULL,
  `idKortti` int NOT NULL,
  `credit` tinyint DEFAULT NULL,
  PRIMARY KEY (`idKortti_tili`),
  KEY `tili-kortti_tili_idx` (`idTili`),
  KEY `kortti-kortti_tili_idx` (`idKortti`),
  CONSTRAINT `kortti-kortti_tili` FOREIGN KEY (`idKortti`) REFERENCES `kortti` (`idKortti`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `tili-kortti_tili` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti_tili`
--

LOCK TABLES `kortti_tili` WRITE;
/*!40000 ALTER TABLE `kortti_tili` DISABLE KEYS */;
INSERT INTO `kortti_tili` VALUES (1,1,123456,0),(2,2,654321,1);
/*!40000 ALTER TABLE `kortti_tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `idTili` int NOT NULL AUTO_INCREMENT,
  `tilinumero` varchar(45) NOT NULL,
  `saldo` double NOT NULL,
  `raja` double DEFAULT NULL,
  PRIMARY KEY (`idTili`),
  KEY `tilinum_idx` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili`
--

LOCK TABLES `tili` WRITE;
/*!40000 ALTER TABLE `tili` DISABLE KEYS */;
INSERT INTO `tili` VALUES (1,'FI 01234 56789',50.69,0),(2,'FI 01234 56789',50.69,100);
/*!40000 ALTER TABLE `tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tilioikeudet`
--

DROP TABLE IF EXISTS `tilioikeudet`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tilioikeudet` (
  `idTilioikeudet` int NOT NULL,
  `idTili` int NOT NULL,
  `idAsiakas` int NOT NULL,
  `omistaja` varchar(45) NOT NULL,
  PRIMARY KEY (`idTilioikeudet`),
  KEY `tunnus_idx` (`idAsiakas`),
  KEY `tili_id_idx` (`idTili`),
  CONSTRAINT `asiakas-tilioikeudet` FOREIGN KEY (`idAsiakas`) REFERENCES `asiakas` (`idAsiakas`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `tili-tilioikeudet` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilioikeudet`
--

LOCK TABLES `tilioikeudet` WRITE;
/*!40000 ALTER TABLE `tilioikeudet` DISABLE KEYS */;
INSERT INTO `tilioikeudet` VALUES (1,1,1,'Testi Henkilo');
/*!40000 ALTER TABLE `tilioikeudet` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tilitapahtumat`
--

DROP TABLE IF EXISTS `tilitapahtumat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tilitapahtumat` (
  `idTilitapahtumat` int NOT NULL AUTO_INCREMENT,
  `tilinumero` varchar(45) NOT NULL,
  `tilitapahtuma_pvm` date NOT NULL,
  `selite` varchar(45) NOT NULL,
  `summa` double NOT NULL,
  PRIMARY KEY (`idTilitapahtumat`),
  KEY `tili-tilitapahtumat_idx` (`tilinumero`),
  CONSTRAINT `tili-tilitapahtumat` FOREIGN KEY (`tilinumero`) REFERENCES `tili` (`tilinumero`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=44 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtumat`
--

LOCK TABLES `tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `tilitapahtumat` DISABLE KEYS */;
INSERT INTO `tilitapahtumat` VALUES (1,'FI 01234 56789','2022-10-11','testitalletus',11.11),(2,'FI 01234 56789','2022-10-12','testitalletus2',11.11),(3,'FI 01234 56789','2022-10-12','testitalletus3',12.34),(4,'FI 01234 56789','2022-10-14','testitalletus4',44.44),(5,'FI 01234 56789','2022-10-15','testitalletus5',55.55),(6,'FI 01234 56789','2022-10-16','testitalletus6',66.66),(7,'FI 01234 56789','2022-10-17','testitalletus7',77.77),(8,'FI 01234 56789','2022-10-18','testitalletus8',88.88),(9,'FI 01234 56789','2022-10-19','testitalletus9',99.99),(10,'FI 01234 56789','2022-10-20','testitalletus10',100),(11,'FI 01234 56789','2022-10-21','testitalletus11',111.11),(12,'FI 01234 56789','2022-12-12','toisenAsiakkaantesti',222.22),(13,'FI 01234 56789','2022-12-09','nostoIlmanID',69.69),(14,'FI 01234 56789','2022-12-09','toinenIlmanID',11.22),(15,'FI 01234 56789','2022-10-21','ilmanIDtäTesti',1),(21,'FI 01234 56789','2022-12-09','nosto',20),(22,'FI 01234 56789','2022-12-09','nosto',20),(23,'FI 01234 56789','2022-12-09','nosto',20),(24,'FI 01234 56789','2022-12-09','nosto',20),(25,'FI 01234 56789','2022-12-09','nosto',20),(26,'FI 01234 56789','2022-12-09','nosto',20),(27,'FI 01234 56789','2022-12-09','nosto',20),(28,'FI 01234 56789','2022-12-09','nosto',20),(29,'FI 01234 56789','2022-12-09','nosto',20),(30,'FI 01234 56789','2022-12-10','nosto',20),(31,'FI 01234 56789','2022-12-10','nosto',20),(32,'FI 01234 56789','2022-12-10','nosto',20),(33,'FI 01234 56789','2022-12-10','nosto',20),(34,'FI 01234 56789','2022-12-10','nosto',20),(35,'FI 01234 56789','2022-12-10','talletus',20),(36,'FI 01234 56789','2022-12-10','talletus',35),(37,'FI 01234 56789','2022-12-10','talletus',35),(38,'FI 01234 56789','2022-12-10','talletus',35),(39,'FI 01234 56789','2022-12-10','nosto',20),(40,'FI 01234 56789','2022-12-10','nosto',20),(41,'FI 01234 56789','2022-12-10','nosto',20),(42,'FI 01234 56789','2022-12-10','talletus',35),(43,'FI 01234 56789','2022-12-10','talletus',35);
/*!40000 ALTER TABLE `tilitapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'banksimul'
--
/*!50003 DROP PROCEDURE IF EXISTS `nosto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`netuser`@`localhost` PROCEDURE `nosto`(IN id INT, IN tilinumTarkistus varchar(45), IN haluttuSumma DOUBLE)
BEGIN
  DECLARE TTrow, summaLimit INT DEFAULT 0;
  START TRANSACTION;
  SET summaLimit = (SELECT raja FROM tili WHERE tili.idTili = id);
  UPDATE tili SET saldo = saldo-haluttuSumma WHERE tilinumero = tilinumTarkistus AND saldo+summaLimit-haluttuSumma >= 0;
  SET TTrow = ROW_COUNT();
    IF (TTrow > 0) THEN
      COMMIT;
      INSERT INTO tilitapahtumat(tilinumero, selite, summa, tilitapahtuma_pvm) VALUES(tilinumTarkistus, 'nosto', haluttuSumma, curdate());
    ELSE ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `talletus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`netuser`@`localhost` PROCEDURE `talletus`(IN tilinumTarkistus varchar(45), IN talletettuSumma DOUBLE)
BEGIN
  DECLARE TTrow INT DEFAULT 0;
  START TRANSACTION;
  UPDATE tili SET saldo = saldo+talletettuSumma WHERE tilinumero = tilinumTarkistus;
  SET TTrow = ROW_COUNT();
    IF (TTrow > 0) THEN
      COMMIT;
      INSERT INTO tilitapahtumat(tilinumero, selite, summa, tilitapahtuma_pvm) VALUES(tilinumTarkistus, 'talletus', talletettuSumma, curdate());
    ELSE ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-12-10  4:42:28
