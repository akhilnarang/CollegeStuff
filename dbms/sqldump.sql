-- MySQL dump 10.13  Distrib 5.7.25, for Linux (x86_64)
--
-- Host: localhost    Database: company
-- ------------------------------------------------------
-- Server version	5.7.25-0ubuntu0.18.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `company`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `company` /*!40100 DEFAULT CHARACTER SET latin1 */;

USE `company`;

--
-- Table structure for table `department`
--

DROP TABLE IF EXISTS `department`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `department` (
  `name` varchar(20) DEFAULT NULL,
  `number` int(11) NOT NULL,
  `manager` text,
  PRIMARY KEY (`number`),
  UNIQUE KEY `number` (`number`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `department`
--

LOCK TABLES `department` WRITE;
/*!40000 ALTER TABLE `department` DISABLE KEYS */;
/*!40000 ALTER TABLE `department` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `department_location`
--

DROP TABLE IF EXISTS `department_location`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `department_location` (
  `number` int(11) DEFAULT NULL,
  `location` varchar(20) DEFAULT NULL,
  KEY `number` (`number`),
  CONSTRAINT `department_location_ibfk_1` FOREIGN KEY (`number`) REFERENCES `department` (`number`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `department_location`
--

LOCK TABLES `department_location` WRITE;
/*!40000 ALTER TABLE `department_location` DISABLE KEYS */;
/*!40000 ALTER TABLE `department_location` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dependent`
--

DROP TABLE IF EXISTS `dependent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dependent` (
  `name` text,
  `sex` char(1) DEFAULT NULL,
  `dob` datetime DEFAULT NULL,
  `ssn` int(11) DEFAULT NULL,
  KEY `ssn` (`ssn`),
  CONSTRAINT `dependent_ibfk_1` FOREIGN KEY (`ssn`) REFERENCES `employee` (`ssn`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dependent`
--

LOCK TABLES `dependent` WRITE;
/*!40000 ALTER TABLE `dependent` DISABLE KEYS */;
/*!40000 ALTER TABLE `dependent` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `employee` (
  `fname` text,
  `mname` text,
  `sname` text,
  `salary` float(7,2) DEFAULT NULL,
  `ssn` int(11) NOT NULL,
  `address` text,
  `sex` char(1) DEFAULT NULL,
  `dob` datetime DEFAULT NULL,
  `sssn` int(11) DEFAULT NULL,
  `department_number` int(11) DEFAULT NULL,
  PRIMARY KEY (`ssn`),
  KEY `sssn` (`sssn`),
  KEY `dno` (`department_number`),
  CONSTRAINT `employee_ibfk_1` FOREIGN KEY (`sssn`) REFERENCES `employee` (`ssn`),
  CONSTRAINT `employee_ibfk_2` FOREIGN KEY (`department_number`) REFERENCES `department` (`number`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee`
--

LOCK TABLES `employee` WRITE;
/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
INSERT INTO `employee` VALUES ('first','middle','last',10000.34,10,'Kothrud','M','1999-09-24 00:00:00',3425335,NULL),('first','middle','last',10000.34,20,'Kothrud','M','1999-09-24 00:00:00',34425335,NULL),('first','middle','last',10000.34,30,'Kothrud','M','1999-09-24 00:00:00',10,NULL),('first','middle','last',10000.34,3425335,'Kothrud','M','1999-09-24 00:00:00',NULL,NULL),('first','middle','last',10000.34,34425335,'Kothrud','M','1999-09-24 00:00:00',3425335,NULL);
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `projects`
--

DROP TABLE IF EXISTS `projects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `projects` (
  `location` varchar(20) DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `number` int(11) NOT NULL,
  `dno` int(11) DEFAULT NULL,
  PRIMARY KEY (`number`),
  UNIQUE KEY `number` (`number`),
  UNIQUE KEY `name` (`name`),
  KEY `dno` (`dno`),
  CONSTRAINT `projects_ibfk_1` FOREIGN KEY (`dno`) REFERENCES `department` (`number`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `projects`
--

LOCK TABLES `projects` WRITE;
/*!40000 ALTER TABLE `projects` DISABLE KEYS */;
/*!40000 ALTER TABLE `projects` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `workson`
--

DROP TABLE IF EXISTS `workson`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `workson` (
  `pno` int(11) DEFAULT NULL,
  `employee_ssn` int(11) DEFAULT NULL,
  `hours` int(11) DEFAULT NULL,
  KEY `pno` (`pno`),
  KEY `employee_ssn` (`employee_ssn`),
  CONSTRAINT `workson_ibfk_1` FOREIGN KEY (`pno`) REFERENCES `projects` (`number`),
  CONSTRAINT `workson_ibfk_2` FOREIGN KEY (`employee_ssn`) REFERENCES `employee` (`ssn`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `workson`
--

LOCK TABLES `workson` WRITE;
/*!40000 ALTER TABLE `workson` DISABLE KEYS */;
/*!40000 ALTER TABLE `workson` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-07-31 15:26:58