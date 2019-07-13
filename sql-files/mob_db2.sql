#
# Table structure for table `mob_db2`
#

DROP TABLE IF EXISTS `mob_db2`;
CREATE TABLE `mob_db2` (
  `ID` mediumint(9) unsigned NOT NULL default '0',
  `Sprite` text NOT NULL,
  `kName` text NOT NULL,
  `iName` text NOT NULL,
  `LV` tinyint(6) unsigned NOT NULL default '0',
  `HP` int(9) unsigned NOT NULL default '0',
  `SP` mediumint(9) unsigned NOT NULL default '0',
  `EXP` mediumint(9) unsigned NOT NULL default '0',
  `JEXP` mediumint(9) unsigned NOT NULL default '0',
  `Range1` tinyint(4) unsigned NOT NULL default '0',
  `ATK1` smallint(6) unsigned NOT NULL default '0',
  `ATK2` smallint(6) unsigned NOT NULL default '0',
  `DEF` smallint(6) unsigned NOT NULL default '0',
  `MDEF` smallint(6) unsigned NOT NULL default '0',
  `STR` smallint(6) unsigned NOT NULL default '0',
  `AGI` smallint(6) unsigned NOT NULL default '0',
  `VIT` smallint(6) unsigned NOT NULL default '0',
  `INT` smallint(6) unsigned NOT NULL default '0',
  `DEX` smallint(6) unsigned NOT NULL default '0',
  `LUK` smallint(6) unsigned NOT NULL default '0',
  `Range2` tinyint(4) unsigned NOT NULL default '0',
  `Range3` tinyint(4) unsigned NOT NULL default '0',
  `Scale` tinyint(4) unsigned NOT NULL default '0',
  `Race` tinyint(4) unsigned NOT NULL default '0',
  `Element` tinyint(4) unsigned NOT NULL default '0',
  `Mode` int(11) unsigned NOT NULL default '0',
  `Speed` smallint(6) unsigned NOT NULL default '0',
  `aDelay` smallint(6) unsigned NOT NULL default '0',
  `aMotion` smallint(6) unsigned NOT NULL default '0',
  `dMotion` smallint(6) unsigned NOT NULL default '0',
  `MEXP` mediumint(9) unsigned NOT NULL default '0',
  `MVP1id` smallint(5) unsigned NOT NULL default '0',
  `MVP1per` smallint(9) unsigned NOT NULL default '0',
  `MVP2id` smallint(5) unsigned NOT NULL default '0',
  `MVP2per` smallint(9) unsigned NOT NULL default '0',
  `MVP3id` smallint(5) unsigned NOT NULL default '0',
  `MVP3per` smallint(9) unsigned NOT NULL default '0',
  `Drop1id` smallint(5) unsigned NOT NULL default '0',
  `Drop1per` smallint(9) unsigned NOT NULL default '0',
  `Drop2id` smallint(5) unsigned NOT NULL default '0',
  `Drop2per` smallint(9) unsigned NOT NULL default '0',
  `Drop3id` smallint(5) unsigned NOT NULL default '0',
  `Drop3per` smallint(9) unsigned NOT NULL default '0',
  `Drop4id` smallint(5) unsigned NOT NULL default '0',
  `Drop4per` smallint(9) unsigned NOT NULL default '0',
  `Drop5id` smallint(5) unsigned NOT NULL default '0',
  `Drop5per` smallint(9) unsigned NOT NULL default '0',
  `Drop6id` smallint(5) unsigned NOT NULL default '0',
  `Drop6per` smallint(9) unsigned NOT NULL default '0',
  `Drop7id` smallint(5) unsigned NOT NULL default '0',
  `Drop7per` smallint(9) unsigned NOT NULL default '0',
  `Drop8id` smallint(5) unsigned NOT NULL default '0',
  `Drop8per` smallint(9) unsigned NOT NULL default '0',
  `Drop9id` smallint(5) unsigned NOT NULL default '0',
  `Drop9per` smallint(9) unsigned NOT NULL default '0',
  `DropCardid` smallint(5) unsigned NOT NULL default '0',
  `DropCardper` smallint(9) unsigned NOT NULL default '0',
  PRIMARY KEY  (`ID`)
) ENGINE=MyISAM;

# Monster Additional Database
#
# Structure of Database :
#REPLACE INTO `mob_db2` VALUES ( ID,'Sprite_Name','kROName','iROName',LV,HP,SP,EXP,JEXP,Range1,ATK1,ATK2,DEF,MDEF,STR,AGI,VIT,INT,DEX,LUK,Range2,Range3,Scale,Race,Element,Mode,Speed,aDelay,aMotion,dMotion,MEXP,MVP1id,MVP1per,MVP2id,MVP2per,MVP3id,MVP3per,Drop1id,Drop1per,Drop2id,Drop2per,Drop3id,Drop3per,Drop4id,Drop4per,Drop5id,Drop5per,Drop6id,Drop6per,Drop7id,Drop7per,Drop8id,Drop8per,Drop9id,Drop9per,DropCardid,DropCardper);

# rAthena Dev Team
#REPLACE INTO `mob_db2` VALUES (1900,'VALARIS','Valaris','Valaris',99,668000,0,107250,37895,2,3220,4040,35,45,1,152,96,85,120,95,10,10,2,6,67,0x1973,100,1068,768,576,13000,608,1000,750,400,923,3800,1466,200,2256,200,2607,800,714,500,617,3000,984,4300,985,5600,0,0,0,0,4147,1);
#REPLACE INTO `mob_db2` VALUES (1901,'VALARIS_WORSHIPPER','Valaris\'s Worshipper','Valaris\'s Worshipper',50,8578,0,2706,1480,1,487,590,15,25,1,75,55,1,93,45,10,12,0,6,27,0x1685,100,868,480,120,0,0,0,0,0,0,0,923,500,984,63,1464,2,607,50,610,100,503,300,2405,50,0,0,0,0,4129,1);
#REPLACE INTO `mob_db2` VALUES (1902,'MC_CAMERI','MC Cameri','MC Cameri',99,668000,0,107250,37895,2,3220,4040,35,45,1,152,96,85,120,95,10,10,2,6,67,0x1973,100,1068,768,576,13000,608,1000,750,400,923,3800,1466,200,2256,200,2607,800,714,500,617,3000,984,4300,985,5600,0,0,0,0,4147,1);
#REPLACE INTO `mob_db2` VALUES (1903,'POKI','Poki#3','Poki#3',99,1349000,0,4093000,1526000,9,4892,9113,22,35,1,180,39,67,193,130,10,12,1,7,64,0x1973,120,500,672,480,92100,603,5500,617,3000,1723,1000,1228,100,1236,500,617,2500,1234,75,1237,125,1722,250,1724,100,1720,50,0,0,0,0);
#REPLACE INTO `mob_db2` VALUES (1904,'SENTRY','Sentry','Sentry',99,668000,0,107250,37895,2,3220,4040,35,45,1,152,96,85,120,95,10,10,2,6,67,0x1973,100,1068,768,576,13000,608,1000,750,400,923,3800,1466,200,2256,200,2607,800,714,500,617,3000,984,4300,985,5600,0,0,0,0,4147,1);

# Custom Hollow Poring (overrrides/collides with META_ANDRE)
#REPLACE INTO `mob_db2` VALUES (1237,'HOLLOW_PORING','Hollow Poring','Hollow Poring',1,50,0,2,1,1,7,10,0,5,1,1,1,0,6,30,10,12,1,3,21,0x83,400,1872,672,480,0,0,0,0,0,0,0,909,7000,1202,100,938,400,512,1000,713,1500,512,150,619,20,0,0,0,0,4001,10);
# Custom Fire Poring. Warning, Colides with META_DENIRO
#REPLACE INTO `mob_db2` VALUES (1239,'FIRE_PORING','Fire Poring','Fire Poring',1,50,0,2,1,1,7,10,0,5,1,1,1,1,6,30,10,12,1,3,21,0x131,400,1872,672,480,0,0,0,0,0,0,0,909,7000,1202,100,938,400,512,1000,713,1500,741,5,619,20,0,0,0,0,4001,20);

# Lunar New Year 2008 Event Monster overrides
# Uncomment if event is enabled, as these drops modifications are nessecary.
#REPLACE INTO `mob_db2` VALUES (1145,'MARTIN','Martin','Martin',18,1109,0,134,86,1,52,63,0,5,12,18,30,15,15,5,10,12,0,2,42,0x81,300,1480,480,480,0,0,0,0,0,0,0,1017,9000,1018,500,1251,10,2225,5,5009,1,10010,10,2224,15,7869,1500,0,0,4046,1);
#REPLACE INTO `mob_db2` VALUES (1175,'TAROU','Tarou','Tarou',11,284,0,57,28,1,34,45,0,0,1,20,11,10,24,5,10,12,0,2,27,0x91,150,1744,1044,684,0,0,0,0,0,0,0,1016,9000,919,3000,949,800,528,1000,701,2,7869,2500,0,0,0,0,0,0,4028,1);
#REPLACE INTO `mob_db2` VALUES (1209,'CRAMP','Cramp','Cramp',56,4720,0,2300,1513,1,395,465,0,5,1,85,35,5,65,60,10,12,0,2,45,0x3095,100,1000,500,1000,0,0,0,0,0,0,0,7007,4656,528,1000,726,80,746,110,568,250,510,70,984,95,7869,1500,0,0,4296,1);

# iRO St. Patricks Day 2008 Event Monster overrides
# Uncomment if event is enabled, as these drops modifications are nessecary.
#REPLACE INTO `mob_db2` VALUES (1841,'G_SNAKE_','Snake Lord\'s Minon','Snake Lord\'s Minon',15,471,0,72,48,1,46,55,0,0,1,15,15,10,35,5,10,12,1,2,22,0x81,200,1576,576,576,0,0,0,0,0,0,0,7915,1000,7916,100,7720,30,12715,7,0,0,0,0,0,0,0,0,0,0,0,0);
#REPLACE INTO `mob_db2` VALUES (1842,'G_ANACONDAQ_','Snake Lord\'s Minon','Snake Lord\'s Minon',23,1109,0,300,149,1,124,157,0,0,1,23,28,10,36,5,10,12,1,2,25,0x91,200,1576,576,576,0,0,0,0,0,0,0,7915,1000,7916,100,7720,30,12715,7,0,0,0,0,0,0,0,0,0,0,0,0);
#REPLACE INTO `mob_db2` VALUES (1843,'SIDE_WINDER_','Snake Lord\'s Minon','Snake Lord\'s Minon',43,4929,0,1996,993,1,240,320,5,10,38,43,40,15,115,20,10,12,1,2,25,0x3095,200,1576,576,576,0,0,0,0,0,0,0,7915,1000,7916,100,7720,30,12715,7,0,0,0,0,0,0,0,0,0,0,0,0);
#REPLACE INTO `mob_db2` VALUES (1844,'G_ISIS_','Snake Lord\'s Minon','Snake Lord\'s Minon',47,7003,0,3709,1550,1,423,507,10,35,38,65,43,50,66,15,10,12,2,6,27,0x3195,200,1384,768,336,0,0,0,0,0,0,0,7915,1000,7916,100,7720,30,12715,8,0,0,0,0,0,0,0,0,0,0,0,0);

# iRO Christmas 2008 Event
# Uncomment if event is enabled, as these drops modifications are nessecary.
#REPLACE INTO `mob_db2` VALUES (1244,'JAKK_XMAS','Christmas Jakk','Christmas Jakk',38,3581,0,1113,688,1,315,382,5,30,1,38,38,43,75,45,10,12,1,0,43,0x81,200,1180,480,648,0,0,0,0,0,0,0,529,1000,530,1000,14546,1000,14550,1000,7174,1000,7175,1000,6092,1000,12355,1250,0,0,0,0);
#REPLACE INTO `mob_db2` VALUES (1245,'GOBLINE_XMAS','Christmas Goblin','Christmas Goblin',25,1176,0,282,171,1,118,140,10,5,1,53,25,20,38,45,10,12,1,7,24,0x81,100,1120,620,240,0,0,0,0,0,0,0,529,1000,530,1000,14546,1000,14550,1000,7174,1000,7175,1000,6092,1000,12355,1250,0,0,0,0);
#REPLACE INTO `mob_db2` VALUES (1246,'COOKIE_XMAS','Christmas Cookie','Christmas Cookie',28,2090,0,461,284,1,140,170,0,50,1,24,30,53,45,100,10,12,0,7,46,0x91,400,1248,1248,240,0,0,0,0,0,0,0,529,1000,530,1000,14546,1000,14550,1000,7174,1000,7175,1000,6092,1000,12355,1250,0,0,0,0);
#REPLACE INTO `mob_db2` VALUES (1247,'ANTONIO','Antonio','Antonio',10,10,0,3,2,1,13,20,100,0,1,1,1,50,100,100,10,12,1,3,66,0xC1,100,720,720,432,0,0,0,0,0,0,0,604,500,12354,500,14550,500,5136,500,12132,500,12225,500,5811,500,0,0,0,0,4243,1);

# iRO Halloween 2009 Event
# Uncomment if event is enabled. Uncomment the skills for Halloween Whisper in mob_skill_db2.
#REPLACE INTO `mob_db2` VALUES (3014,'HALLOWEEN_WHISPER','Halloween Whisper','Halloween Whisper',1,800,0,0,0,1,10,13,0,45,1,51,14,0,60,0,10,12,0,6,68,0x81,150,1960,960,504,0,0,0,0,0,0,0,12396,150,6299,5335,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
#REPLACE INTO `mob_db2` VALUES (3015,'HALLOWEEN_DARK_LORD','Halloween Dark Lord','Halloween Dark Lord',1,45,0,0,0,1,10,13,0,45,1,51,14,0,60,0,10,12,2,6,89,0x81,100,868,768,480,0,0,0,0,0,0,0,12396,800,12397,5335,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

# iRO Halloween 2008 Event
# Uncomment if event is enabled.
#REPLACE INTO `mob_db2` VALUES (3000,'ZOMBIE','Zombie','Zombie',15,534,0,50,33,1,67,79,0,10,1,8,7,0,15,0,10,12,1,1,29,0x3885,400,2612,912,288,0,0,0,0,0,0,0,957,9000,724,5,938,1000,958,50,727,70,0,0,0,0,0,0,0,0,4038,1);
#REPLACE INTO `mob_db2` VALUES (3001,'GHOUL','Ghoul','Ghoul',40,5418,0,1088,622,1,420,500,5,20,1,20,29,0,45,20,10,12,1,1,49,0x3885,250,2456,912,504,0,0,0,0,0,0,0,958,6000,756,110,509,700,511,800,2609,60,934,150,1260,1,0,0,0,0,4110,1);
#REPLACE INTO `mob_db2` VALUES (3002,'ZOMBIE_MASTER','Zombie Master','Zombie Master',62,14211,0,7610,2826,1,824,1084,37,26,25,20,30,5,77,35,10,12,1,1,29,0x3695,175,2612,912,288,0,0,0,0,0,0,0,7071,4413,938,1500,958,1500,723,200,727,100,1260,1,2324,2,0,0,0,0,4274,1);

REPLACE INTO `mob_db2` VALUES (1168, 'SCORPION_KING', '�X�R�[�s�I���L���O', '�X�R�[�s�I���L���O', 50, 6354, 0, 2187, 1346, 1, 500, 603, 40, 10, 1, 50, 47, 1, 83, 30, 10, 12, 2, 7, 23, 0x1B1,200, 1700, 1000, 500, 0, 0, 0, 0, 0, 0, 0, 994, 45, 1046, 4850, 1005, 15, 904, 5000, 943, 3000, 509, 700, 0, 0, 0,0, 0, 0, 4130, 1);
REPLACE INTO `mob_db2` VALUES (1171, 'SOLDIER_ANDRE', '�����A���h��', '�����A���h��', 22, 1245, 0, 219, 138, 1, 105, 127, 20, 0, 1, 22, 44, 20, 40, 10, 10, 12, 0, 4, 42, 0x3095,200, 1001, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1014, 2700, 911, 800, 757, 10, 1111, 15, 1001, 30, 943, 150, 0, 0, 0,0, 0, 0, 4059, 1);
REPLACE INTO `mob_db2` VALUES (1325, 'TREASURE_BOX2', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7073, 200, 12103, 160, 12213, 10, 7621, 20, 5659, 80, 5375, 80, 5410, 40, 5129,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1327, 'TREASURE_BOX4', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7074, 200, 12103, 160, 12213, 10, 7621, 20, 5480, 80, 5225, 80, 5597, 40, 2667,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1329, 'TREASURE_BOX6', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7075, 200, 12103, 160, 12213, 10, 7621, 20, 1240, 80, 5547, 80, 18751, 40, 5206,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1331, 'TREASURE_BOX8', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7076, 200, 12103, 160, 12213, 10, 7621, 20, 2350, 80, 5131, 80, 2781, 40, 5402,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1333, 'TREASURE_BOX10', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7077, 200, 12103, 160, 12213, 10, 7621, 20, 5304, 80, 5586, 80, 5671, 40, 5340,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1335, 'TREASURE_BOX12', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7078, 200, 12103, 160, 12213, 10, 7621, 20, 5256, 80, 5404, 80, 5332, 40, 5207,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1337, 'TREASURE_BOX14', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7079, 200, 12103, 160, 12213, 10, 7621, 20, 5527, 80, 5364, 80, 5210, 40, 5294,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1339, 'TREASURE_BOX16', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7080, 200, 12103, 160, 12213, 10, 7621, 20, 5378, 80, 5360, 80, 5133, 40, 2640,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1341, 'TREASURE_BOX18', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7081, 200, 12103, 160, 12213, 10, 7621, 20, 5187, 80, 5555, 80, 5401, 40, 5343,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1343, 'TREASURE_BOX20', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7082, 200, 12103, 160, 12213, 10, 7621, 20, 5429, 80, 5533, 80, 2799, 40, 5289,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1345, 'TREASURE_BOX22', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7083, 200, 12103, 160, 12213, 10, 7621, 20, 5508, 80, 2346, 80, 5403, 40, 5397,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1347, 'TREASURE_BOX24', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7084, 200, 12103, 160, 12213, 10, 7621, 20, 5458, 80, 5292, 80, 5142, 40, 5362,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1349, 'TREASURE_BOX26', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7085, 200, 12103, 160, 12213, 10, 7621, 20, 5485, 80, 5511, 80, 2779, 40, 5483,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1351, 'TREASURE_BOX28', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7086, 200, 12103, 160, 12213, 10, 7621, 20, 5258, 80, 5022, 80, 2737, 40, 5342,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1353, 'TREASURE_BOX30', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7087, 200, 12103, 160, 12213, 10, 7621, 20, 5449, 80, 5230, 80, 5665, 40, 5324,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1355, 'TREASURE_BOX32', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7088, 200, 12103, 160, 12213, 10, 7621, 20, 5476, 80, 5447, 80, 5341, 40, 5381,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1357, 'TREASURE_BOX34', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7089, 200, 12103, 160, 12213, 10, 7621, 20, 5660, 80, 2348, 80, 5284, 40, 5358,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1359, 'TREASURE_BOX36', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7090, 200, 12103, 160, 12213, 10, 7621, 20, 5363, 80, 5482, 80, 5548, 40, 2665,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1361, 'TREASURE_BOX38', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7091, 200, 12103, 160, 12213, 10, 7621, 20, 5310, 80, 1725, 80, 5357, 40, 2663,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1363, 'TREASURE_BOX40', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7092, 200, 12103, 160, 12213, 10, 7621, 20, 5140, 80, 5311, 80, 5532, 40, 5367,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1519, 'CHUNG_E', '�`�����C�[', 'Green Maiden', 49, 23900, 0, 2396, 993, 1, 460, 1050, 8, 15, 38, 65, 43, 30, 90, 15, 10, 12, 1, 7, 40, 0x3695,170, 1728, 816, 1188, 0, 0, 0, 0, 0, 0, 0, 7053, 4850, 740, 100, 1806, 10, 518, 500, 0, 0, 5024, 50, 0, 0, 5042,2, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1630, 'BACSOJIN_', '�y�N�\�W��', 'White Lady', 85, 253221, 0, 45250, 16445, 3, 1868, 6124, 20, 55, 52, 65, 44, 112, 152, 35, 10, 12, 2, 7, 64, 0x6283885,130, 576, 960, 480, 22625, 607, 5500, 2513, 2000, 617, 5000, 1020, 5500, 603, 5000, 0, 0, 7165, 3000, 7166, 1000, 2700, 100, 2234, 10, 0,0, 0, 0, 4372, 1);
REPLACE INTO `mob_db2` VALUES (1631, 'CHUNG_E_', '�`�����C�[', 'Green Maiden', 59, 23900, 0, 4256, 920, 2, 460, 1050, 8, 15, 38, 65, 43, 30, 90, 15, 10, 12, 1, 7, 44, 0x3885,150, 1728, 816, 1188, 0, 0, 0, 0, 0, 0, 0, 7053, 4200, 740, 100, 1806, 10, 518, 500, 0, 0, 0, 0, 5042, 50, 0,0, 0, 0, 4373, 1);
REPLACE INTO `mob_db2` VALUES (1837, 'IMP', '�C���v', 'Fire Imp', 76, 46430, 0, 25200, 11077, 1, 1059, 1509, 27, 50, 37, 76, 30, 150, 99, 10, 10, 12, 0, 6, 63, 0x2003295,150, 824, 432, 360, 0, 0, 0, 0, 0, 0, 0, 7122, 3000, 13303, 3, 7098, 2500, 1376, 10, 1972, 25, 0, 0, 0, 0, 0,0, 0, 0, 4433, 1);
REPLACE INTO `mob_db2` VALUES (1938, 'TREASURE_BOX41', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7830, 200, 12103, 160, 12213, 20, 7621, 40, 5359, 80, 5379, 80, 5562, 40, 5516,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1939, 'TREASURE_BOX42', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7831, 200, 12103, 160, 12213, 20, 7621, 40, 5277, 80, 5333, 80, 1244, 40, 5399,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1940, 'TREASURE_BOX43', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7832, 200, 12103, 160, 12213, 20, 7621, 40, 5151, 80, 5560, 80, 5345, 40, 5574,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1941, 'TREASURE_BOX44', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7833, 200, 12103, 160, 12213, 20, 7621, 40, 5208, 80, 5658, 80, 5430, 40, 5421,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1942, 'TREASURE_BOX45', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7834, 200, 12103, 160, 12213, 20, 7621, 40, 5291, 80, 5561, 80, 18667, 40, 5788,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1943, 'TREASURE_BOX46', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7835, 200, 12103, 160, 12213, 20, 7621, 40, 5654, 80, 5307, 80, 5775, 40, 5313,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1944, 'TREASURE_BOX47', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7836, 200, 12103, 160, 12213, 20, 7621, 40, 5418, 80, 5383, 80, 5286, 40, 2714,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1945, 'TREASURE_BOX48', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7837, 200, 12103, 160, 12213, 20, 7621, 40, 5138, 80, 5502, 80, 2645, 40, 2874,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (1946, 'TREASURE_BOX49', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7838, 200, 12103, 160, 12213, 20, 7621, 40, 5486, 80, 5457, 80, 5283, 40, 2780,40, 0, 0, 0, 0);
REPLACE INTO `mob_db2` VALUES (2945, 'TREASURE_BOX48', '��', 'Treasure Chest', 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 999, 0, 0, 0, 0, 0, 20, 0x620000,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7837, 200, 12103, 160, 12213, 20, 7621, 40, 5500, 80, 5380, 80, 2787, 40, 5344,40, 0, 0, 0, 0);
