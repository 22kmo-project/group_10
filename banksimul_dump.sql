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
INSERT INTO `kortti` VALUES (1,'$2a$10$jL60Gy0nWV0Jh6vV5tX0T.kwcwMxVoMVnd3yJXMZTEY7BGSE.Q4GW',1);
/*!40000 ALTER TABLE `kortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kortti_tili`
--

DROP TABLE IF EXISTS `kortti_tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti_tili` (
  `idKortti_tili` int NOT NULL AUTO_INCREMENT,
  `idTili` int NOT NULL,
  `idKortti` int NOT NULL,
  PRIMARY KEY (`idKortti_tili`),
  KEY `tili-kortti_tili_idx` (`idTili`),
  KEY `kortti-kortti_tili_idx` (`idKortti`),
  CONSTRAINT `kortti-kortti_tili` FOREIGN KEY (`idKortti`) REFERENCES `kortti` (`idKortti`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `tili-kortti_tili` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti_tili`
--

LOCK TABLES `kortti_tili` WRITE;
/*!40000 ALTER TABLE `kortti_tili` DISABLE KEYS */;
INSERT INTO `kortti_tili` VALUES (1,1,1);
/*!40000 ALTER TABLE `kortti_tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `idTili` int NOT NULL,
  `tilinumero` varchar(45) NOT NULL,
  `saldo` double NOT NULL,
  PRIMARY KEY (`idTili`),
  KEY `tilinum_idx` (`tilinumero`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili`
--

LOCK TABLES `tili` WRITE;
/*!40000 ALTER TABLE `tili` DISABLE KEYS */;
INSERT INTO `tili` VALUES (1,'FI 01234 56789',420.69);
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
/*!40000 ALTER TABLE `tilioikeudet` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tilitapahtumat`
--

DROP TABLE IF EXISTS `tilitapahtumat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tilitapahtumat` (
  `idTilitapahtumat` int NOT NULL,
  `tilinumero` varchar(45) NOT NULL,
  `tilitapahtuma_pvm` date NOT NULL,
  `selite` varchar(45) NOT NULL,
  `summa` double NOT NULL,
  PRIMARY KEY (`idTilitapahtumat`),
  KEY `tili-tilitapahtumat_idx` (`tilinumero`),
  CONSTRAINT `tili-tilitapahtumat` FOREIGN KEY (`tilinumero`) REFERENCES `tili` (`tilinumero`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtumat`
--

LOCK TABLES `tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `tilitapahtumat` DISABLE KEYS */;
/*!40000 ALTER TABLE `tilitapahtumat` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-12-01 16:19:38
