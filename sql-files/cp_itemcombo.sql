DROP TABLE IF EXISTS `cp_itemcombo`;
CREATE TABLE `cp_itemcombo` (
  `id1` smallint(5) unsigned,
  `id2` smallint(5) unsigned,
  `id3` smallint(5) unsigned,
  `id4` smallint(5) unsigned,
  `id5` smallint(5) unsigned,
  `id6` smallint(5) unsigned,
  `script` text
) ENGINE=MyISAM;



REPLACE INTO `cp_itemcombo` VALUES( 1166, 2527, NULL, NULL, NULL, NULL, '{ bonus2 bAddRace,RC_Dragon,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 1420, 2115, NULL, NULL, NULL, NULL, '{ bonus3 bAutoSpellWhenHit,"HP_ASSUMPTIO",2,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 1420, 2133, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,4; bonus bDef,2; }');
REPLACE INTO `cp_itemcombo` VALUES( 1421, 2133, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,4; bonus bDef,2; }');
REPLACE INTO `cp_itemcombo` VALUES( 1422, 2133, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,4; bonus bDef,2; }');
REPLACE INTO `cp_itemcombo` VALUES( 1428, 2115, NULL, NULL, NULL, NULL, '{ bonus3 bAutoSpellWhenHit,"HP_ASSUMPTIO",2,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 1472, 2677, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,6; bonus bDex,2; bonus bCastrate,-getequiprefinerycnt(EQI_HEAD_TOP); }');
REPLACE INTO `cp_itemcombo` VALUES( 1472, 2711, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,6; bonus bDex,2; bonus bCastrate,-getequiprefinerycnt(EQI_HAND_R); }');
REPLACE INTO `cp_itemcombo` VALUES( 1473, 2677, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,6; bonus bDex,2; bonus bCastrate,-getequiprefinerycnt(EQI_HEAD_TOP); }');
REPLACE INTO `cp_itemcombo` VALUES( 1473, 2711, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,6; bonus bDex,2; bonus bCastrate,-getequiprefinerycnt(EQI_HAND_R); }');
REPLACE INTO `cp_itemcombo` VALUES( 1474, 2527, NULL, NULL, NULL, NULL, '{ bonus2 bAddRace,RC_Dragon,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 1477, 2700, NULL, NULL, NULL, NULL, '{ bonus2 bResEff,Eff_Confusion,9500; }');
REPLACE INTO `cp_itemcombo` VALUES( 1479, 2700, NULL, NULL, NULL, NULL, '{ bonus2 bResEff,Eff_Confusion,9500; }');
REPLACE INTO `cp_itemcombo` VALUES( 1535, 4361, NULL, NULL, NULL, NULL, '{ bonus bBreakArmorRate,900; bonus bBreakWeaponRate,900; }');
REPLACE INTO `cp_itemcombo` VALUES( 1572, 2716, 2717, NULL, NULL, NULL, '{ bonus bInt,5; bonus bMaxHP,700; bonus bAspdRate,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 1573, 2334, NULL, NULL, NULL, NULL, '{ bonus bMdef,8; bonus bMaxSPRate,10; bonus bInt,4; }');
REPLACE INTO `cp_itemcombo` VALUES( 1573, 2372, NULL, NULL, NULL, NULL, '{ bonus bMdef,8; bonus bMaxSPRate,10; bonus bInt,4; }');
REPLACE INTO `cp_itemcombo` VALUES( 1573, 2716, 2717, NULL, NULL, NULL, '{ bonus bInt,5; bonus bMaxHP,700; bonus bAspdRate,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 1615,18539, NULL, NULL, NULL, NULL, '{ bonus bMatk,10*getequiprefinerycnt(EQI_HAND_R); bonus bCastRate,-10; }');
REPLACE INTO `cp_itemcombo` VALUES( 1616, 2515, NULL, NULL, NULL, NULL, '{ bonus bSpeedRate,25; }');
REPLACE INTO `cp_itemcombo` VALUES( 1618, 2509, NULL, NULL, NULL, NULL, '{ bonus bMaxHP,300; bonus bMatkRate,min(5, getequiprefinerycnt(EQI_HAND_R)-5); bonus2 bSubEle,Ele_Neutral,min(30, getequiprefinerycnt(EQI_GARMENT)*3); }');
REPLACE INTO `cp_itemcombo` VALUES( 1618, 2535, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,5; bonus2 bSubEle,Ele_Neutral,25; }');
REPLACE INTO `cp_itemcombo` VALUES( 1620, 2509, NULL, NULL, NULL, NULL, '{ bonus bMaxHP,300; bonus bMatkRate,getequiprefinerycnt(EQI_HAND_R)-5; if(getequiprefinerycnt(EQI_GARMENT) > 10) { bonus2 bSubEle,Ele_Neutral,30; } else { bonus2 bSubEle,Ele_Neutral,getequiprefinerycnt(EQI_GARMENT)*3; } }');
REPLACE INTO `cp_itemcombo` VALUES( 1620, 2535, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,5; bonus2 bSubEle,Ele_Neutral,25; }');
REPLACE INTO `cp_itemcombo` VALUES( 1629, 5045, NULL, NULL, NULL, NULL, '{ bonus bDex,2; bonus bInt,2; bonus bSPrecovRate,5; bonus bMatkRate,getequiprefinerycnt(EQI_HAND_R); }');
REPLACE INTO `cp_itemcombo` VALUES( 1631, 2129, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"PR_MAGNUS",20; bonus3 bAutoSpellWhenHit,"PR_TURNUNDEAD",1,20; }');
REPLACE INTO `cp_itemcombo` VALUES( 1636,18539, NULL, NULL, NULL, NULL, '{ bonus bMatk,10*getequiprefinerycnt(EQI_HAND_R); bonus bCastRate,-10; }');
REPLACE INTO `cp_itemcombo` VALUES( 1723, 2718, NULL, NULL, NULL, NULL, '{ bonus bDex,1; bonus bMaxSP,50; bonus bSPrecovRate,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 1730, 1752, NULL, NULL, NULL, NULL, '{ bonus bLongAtkRate,25; }');
REPLACE INTO `cp_itemcombo` VALUES( 1731, 1754, NULL, NULL, NULL, NULL, '{ bonus bLongAtkRate,25; }');
REPLACE INTO `cp_itemcombo` VALUES( 1732, 1756, NULL, NULL, NULL, NULL, '{ bonus bLongAtkRate,25; bonus2 bAddEff,Eff_Stone,1000; }');
REPLACE INTO `cp_itemcombo` VALUES( 1733, 1755, NULL, NULL, NULL, NULL, '{ bonus bLongAtkRate,25; bonus3 bAutoSpell,"NJ_HUUJIN",5,100; if(readparam(bInt)>39) bonus3 bAutoSpell,"NJ_HUUJIN",5,200; }');
REPLACE INTO `cp_itemcombo` VALUES( 1734, 1753, NULL, NULL, NULL, NULL, '{ bonus bLongAtkRate,50; }');
REPLACE INTO `cp_itemcombo` VALUES( 1741, 2748, NULL, NULL, NULL, NULL, '{ bonus bAtk,25; bonus3 bAddEff,Eff_Curse,200,ATF_WEAPON|ATF_LONG|ATF_TARGET; }');
REPLACE INTO `cp_itemcombo` VALUES( 2001, 2677, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,10; bonus bDex,2; bonus2 bSubRace,RC_Demon,10; bonus2 bSubRace,RC_Undead,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2001, 2711, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,10; bonus bDex,2; bonus2 bSubRace,RC_Demon,10; bonus2 bSubRace,RC_Undead,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2109, 2717, 2239, NULL, NULL, NULL, '{ bonus bHPrecovRate,15; bonus bSPrecovRate,15; bonus bMatkRate,7; }');
REPLACE INTO `cp_itemcombo` VALUES( 2114, 2353, 5122, NULL, NULL, NULL, '{ bonus bStr,2; bonus bDef,5; bonus bMdef,5; if(BaseClass==Job_Swordman) bonus bDef,6; }');
REPLACE INTO `cp_itemcombo` VALUES( 2115, 2353, 5124, NULL, NULL, NULL, '{ bonus bDef,2-getequiprefinerycnt(EQI_HAND_L)-getequiprefinerycnt(EQI_HEAD_TOP); bonus bMdef,5+getequiprefinerycnt(EQI_HAND_L)+getequiprefinerycnt(EQI_HEAD_TOP); }');
REPLACE INTO `cp_itemcombo` VALUES( 2116, 2355, 2420, 2521, 5125, NULL, '{ bonus bMaxHP,900; bonus bMaxSP,100; bonus3 bAutoSpellWhenHit,"HP_ASSUMPTIO",1,30; }');
REPLACE INTO `cp_itemcombo` VALUES( 2121, 2717, 2239, NULL, NULL, NULL, '{ bonus bHPrecovRate,15; bonus bSPrecovRate,15; bonus bMatkRate,7; }');
REPLACE INTO `cp_itemcombo` VALUES( 2123, 2701, NULL, NULL, NULL, NULL, '{ bonus bCastrate,-10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2124, 2702, NULL, NULL, NULL, NULL, '{ bonus bAspdRate,10; bonus bShortWeaponDamageReturn,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2135, 2426, NULL, NULL, NULL, NULL, '{ bonus2 bAddEff,Eff_Blind,500; autobonus "{ bonus bFlee,20; }",200,10000,BF_WEAPON,"{ specialeffect2 EF_INCAGILITY; }"; }');
REPLACE INTO `cp_itemcombo` VALUES( 2137, 2353, 5124, NULL, NULL, NULL, '{ bonus bDef,2-getequiprefinerycnt(EQI_HAND_L)-getequiprefinerycnt(EQI_HEAD_TOP); bonus bMdef,5+getequiprefinerycnt(EQI_HAND_L)+getequiprefinerycnt(EQI_HEAD_TOP); }');
REPLACE INTO `cp_itemcombo` VALUES( 2278,18656, NULL, NULL, NULL, NULL, '{ bonus2 bAddMonsterDropItem,12192,1; }');
REPLACE INTO `cp_itemcombo` VALUES( 2281,18656, NULL, NULL, NULL, NULL, '{ bonus bFlee,10; bonus2 bAddEff,Eff_Stun,1000; }');
REPLACE INTO `cp_itemcombo` VALUES( 2286,18539, NULL, NULL, NULL, NULL, '{ bonus bUseSPrate,-3; }');
REPLACE INTO `cp_itemcombo` VALUES( 2312, 2656, NULL, NULL, NULL, NULL, '{ bonus bDef,5; bonus bMaxHP,150; }');
REPLACE INTO `cp_itemcombo` VALUES( 2313, 2656, NULL, NULL, NULL, NULL, '{ bonus bDef,5; bonus bMaxHP,150; }');
REPLACE INTO `cp_itemcombo` VALUES( 2337, 2654, NULL, NULL, NULL, NULL, '{ bonus bUseSPrate,-20; bonus bMaxHP,300; }');
REPLACE INTO `cp_itemcombo` VALUES( 2339, 2522, NULL, NULL, NULL, NULL, '{ bonus bAgi,5; bonus bFlee,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2339, 2523, NULL, NULL, NULL, NULL, '{ bonus bAgi,5; bonus bFlee,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2353, 2417, 2516, NULL, NULL, NULL, '{ bonus bAgi,3; bonus bMaxHPrate,5; bonus bMaxSPrate,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2353, 2418, 2517, NULL, NULL, NULL, '{ bonus bVit,5; bonus bHPrecovRate,10; bonus bSPrecovRate,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2353, 5123, NULL, NULL, NULL, NULL, '{ if(readparam(bDex)>69) bonus bUseSPrate,-10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2353, 5493, NULL, NULL, NULL, NULL, '{ if(readparam(bDex)>69) bonus bUseSPrate,-10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2354, 2419, 2520, 5128, NULL, NULL, '{ bonus bVit,5; bonus bMaxHPrate,15; bonus bMaxSPrate,5; bonus bDef,5; bonus bMdef,15; bonus2 bSubEle,Ele_Water,10; bonus2 bSubEle,Ele_Earth,10; bonus2 bSubEle,Ele_Fire,10; bonus2 bSubEle,Ele_Wind,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2357, 2421, 2524, 5171, NULL, NULL, '{ bonus bAllStats,1; }');
REPLACE INTO `cp_itemcombo` VALUES( 2358, 5153, NULL, NULL, NULL, NULL, '{ bonus bLuk,6; bonus bFlee,5; bonus bInt,2; }');
REPLACE INTO `cp_itemcombo` VALUES( 2359, 2654, NULL, NULL, NULL, NULL, '{ bonus bUseSPrate,-20; bonus bMaxHP,300; }');
REPLACE INTO `cp_itemcombo` VALUES( 2369, 2428, 2533, 5306, NULL, NULL, '{ bonus2 bSubRace,RC_DemiHuman,10; bonus2 bSubRace,RC_Player,10; bonus bMaxHPrate,20; bonus2 bResEff,Eff_Freeze,10000; skill "WZ_FROSTNOVA",10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2371, 2522, NULL, NULL, NULL, NULL, '{ bonus bAgi,5; bonus bFlee,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2371, 2523, NULL, NULL, NULL, NULL, '{ bonus bAgi,5; bonus bFlee,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2374, 2729, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,3; bonus bMatkRate,3; }');
REPLACE INTO `cp_itemcombo` VALUES( 2375, 2729, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,3; bonus bMatkRate,3; }');
REPLACE INTO `cp_itemcombo` VALUES( 2376, 2435, 2538, NULL, NULL, NULL, '{ bonus2 bSubRace,RC_All,-300; bonus2 bSubRace,RC_DemiHuman,300; bonus2 bSubRace,RC_Player,300; bonus bVit,3; bonus bMaxHPRate,12; bonus bHealpower2,10; bonus bAddItemHealRate,10; autobonus2 "{ bonus2 bHPRegenRate,600,1000; }",5,10000,BF_WEAPON,"{ specialeffect2 EF_HEAL; }"; }');
REPLACE INTO `cp_itemcombo` VALUES( 2377, 2435, 2538, NULL, NULL, NULL, '{ bonus2 bSubRace,RC_All,-300; bonus2 bSubRace,RC_DemiHuman,300; bonus2 bSubRace,RC_Player,300; bonus bStr,3; bonus bMaxHPRate,12; bonus2 bSkillAtk,"MC_MAMMONITE",20; bonus2 bSkillHeal,"AM_POTIONPITCHER",10; bonus2 bSkillHeal2,"AM_POTIONPITCHER",10; bonus2 bSkillHeal2,"AL_HEAL",10; bonus bUnbreakableArmor; }');
REPLACE INTO `cp_itemcombo` VALUES( 2378, 2435, 2538, NULL, NULL, NULL, '{ bonus2 bSubRace,RC_All,-300; bonus2 bSubRace,RC_DemiHuman,300; bonus2 bSubRace,RC_Player,300; bonus bAgi,3; bonus bMaxHPRate,12; bonus bCritical,5; bonus bAspdRate,5; autobonus "{ bonus2 bHPRegenRate,300,1000; }",10,10000,BF_WEAPON,"{ specialeffect2 EF_HEAL; }"; }');
REPLACE INTO `cp_itemcombo` VALUES( 2379, 2436, 2539, NULL, NULL, NULL, '{ bonus2 bSubRace,RC_All,-300; bonus2 bSubRace,RC_DemiHuman,300; bonus2 bSubRace,RC_Player,300; bonus bInt,3; bonus bMaxHPRate,12; bonus2 bResEff,Eff_Stun,2000; autobonus2 "{ bonus bDefEle,Ele_Ghost; }",30,10000,BF_WEAPON,"{ specialeffect2 EF_ENERGYCOAT; }"; }');
REPLACE INTO `cp_itemcombo` VALUES( 2380, 2436, 2539, NULL, NULL, NULL, '{ bonus2 bSubRace,RC_All,-300; bonus2 bSubRace,RC_DemiHuman,300; bonus2 bSubRace,RC_Player,300; bonus bInt,3; bonus bMaxHPRate,12; bonus2 bCastrate,"AL_HOLYLIGHT",-50; bonus bHealPower,6; autobonus2 "{ bonus bDefEle,Ele_Ghost; }",30,10000,BF_WEAPON,"{ specialeffect2 EF_ENERGYCOAT; }"; }');
REPLACE INTO `cp_itemcombo` VALUES( 2381, 2436, 2539, NULL, NULL, NULL, '{ bonus2 bSubRace,RC_All,-300; bonus2 bSubRace,RC_DemiHuman,300; bonus2 bSubRace,RC_Player,300; bonus bDex,3; bonus bMaxHPRate,12; bonus bLongAtkDef,10; bonus bDelayRate,-25; }');
REPLACE INTO `cp_itemcombo` VALUES( 2382, 2437, 2540, NULL, NULL, NULL, '{ bonus2 bSubRace,RC_All,-300; bonus2 bSubRace,RC_DemiHuman,300; bonus2 bSubRace,RC_Player,300; bonus bDex,3; bonus bMaxHPRate,12; bonus bLongAtkDef,10; bonus bDelayRate,-25; }');
REPLACE INTO `cp_itemcombo` VALUES( 2387, 2440, 2744, NULL, NULL, NULL, '{ bonus bMaxHPrate,7; bonus bMaxSPrate,7; bonus bCastrate,-3; bonus bDelayrate,-15; }');
REPLACE INTO `cp_itemcombo` VALUES( 2390, 2749, NULL, NULL, NULL, NULL, '{ bonus bFlee2,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2394, 2444, 2549, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,5; bonus bMatkRate,5; bonus2 bResEff,Eff_Freeze,10000; bonus2 bSkillHeal2,"AM_POTIONPITCHER",3; bonus2 bSkillHeal2,"AL_HEAL",3; bonus2 bSkillHeal2,"PR_SANCTUARY",3; }');
REPLACE INTO `cp_itemcombo` VALUES( 2399, 2553, NULL, NULL, NULL, NULL, '{ bonus bAgi,5; bonus bFlee,15; }');
REPLACE INTO `cp_itemcombo` VALUES( 2408, 2655, NULL, NULL, NULL, NULL, '{ bonus bBaseAtk,50; bonus2 bAddDefMonster,1196,20; bonus2 bAddDefMonster,1197,20; }');
REPLACE INTO `cp_itemcombo` VALUES( 2424, 2528, NULL, NULL, NULL, NULL, '{ bonus bHPrecovRate,5; bonus bMaxHPrate,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2425, 2529, NULL, NULL, NULL, NULL, '{ bonus bFlee,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2425, 2530, NULL, NULL, NULL, NULL, '{ bonus bFlee,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2425, 2551, NULL, NULL, NULL, NULL, '{ bonus bFlee,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2433, 2537, NULL, NULL, NULL, NULL, '{ bonus bMaxHPRate,6; }');
REPLACE INTO `cp_itemcombo` VALUES( 2434, 2529, NULL, NULL, NULL, NULL, '{ bonus bFlee,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2434, 2530, NULL, NULL, NULL, NULL, '{ bonus bFlee,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2434, 2551, NULL, NULL, NULL, NULL, '{ bonus bFlee,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2441, 2546, NULL, NULL, NULL, NULL, '{ bonus bFlee,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2518, 2648, 2649, 5126, NULL, NULL, '{ bonus bInt,5; bonus bMdef,11; bonus bMaxSPrate,20; bonus bNoCastCancel; bonus bCastrate,25; }');
REPLACE INTO `cp_itemcombo` VALUES( 2519, 2650, 2651, 5127, NULL, NULL, '{ bonus bStr,2; bonus bLuk,9; bonus bCritical,13; bonus bBaseAtk,18; bonus bFlee2,13; }');
REPLACE INTO `cp_itemcombo` VALUES( 2527,13001, NULL, NULL, NULL, NULL, '{ bonus2 bAddRace,RC_Dragon,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2607, 2677, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"AL_HEAL",50; bonus2 bSkillAtk,"PR_MAGNUS",30; bonus bSPrecovRate,9; }');
REPLACE INTO `cp_itemcombo` VALUES( 2607, 2711, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"AL_HEAL",50; bonus2 bSkillAtk,"PR_MAGNUS",30; bonus bSPrecovRate,9; }');
REPLACE INTO `cp_itemcombo` VALUES( 2607, 2786, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"AL_HEAL",50; bonus2 bSkillAtk,"PR_MAGNUS",30; bonus bSPrecovRate,9; }');
REPLACE INTO `cp_itemcombo` VALUES( 2608, 2677, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"AL_HEAL",50; bonus2 bSkillAtk,"PR_MAGNUS",30; bonus bSPrecovRate,9; }');
REPLACE INTO `cp_itemcombo` VALUES( 2608, 2711, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"AL_HEAL",50; bonus2 bSkillAtk,"PR_MAGNUS",30; bonus bSPrecovRate,9; }');
REPLACE INTO `cp_itemcombo` VALUES( 2608, 2786, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"AL_HEAL",50; bonus2 bSkillAtk,"PR_MAGNUS",30; bonus bSPrecovRate,9; }');
REPLACE INTO `cp_itemcombo` VALUES( 2620, 2746, NULL, NULL, NULL, NULL, '{ bonus2 bAddSize,Size_Medium,8; bonus bAspdRate,getequiprefinerycnt(EQI_HAND_R)/2; }');
REPLACE INTO `cp_itemcombo` VALUES( 2620, 2747, NULL, NULL, NULL, NULL, '{ bonus2 bAddSize,Size_Large,8; bonus bHit,getequiprefinerycnt(EQI_HAND_R)/2; bonus bCastrate,-getequiprefinerycnt(EQI_HAND_R)/2; }');
REPLACE INTO `cp_itemcombo` VALUES( 2626, 2677, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"AL_HEAL",50; bonus2 bSkillAtk,"PR_MAGNUS",30; bonus bSPrecovRate,9; }');
REPLACE INTO `cp_itemcombo` VALUES( 2626, 2711, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"AL_HEAL",50; bonus2 bSkillAtk,"PR_MAGNUS",30; bonus bSPrecovRate,9; }');
REPLACE INTO `cp_itemcombo` VALUES( 2626, 2786, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"AL_HEAL",50; bonus2 bSkillAtk,"PR_MAGNUS",30; bonus bSPrecovRate,9; }');
REPLACE INTO `cp_itemcombo` VALUES( 2678, 2679, NULL, NULL, NULL, NULL, '{ bonus4 bAutoSpell,"MO_EXTREMITYFIST",1,3,1; bonus3 bAutoSpell,"PR_LEXAETERNA",1,20; bonus3 bAutoSpell,"AS_SONICBLOW",5,50; bonus3 bAutoSpell,"MO_INVESTIGATE",5,20; bonus3 bAutoSpell,"ASC_METEORASSAULT",2,50; }');
REPLACE INTO `cp_itemcombo` VALUES( 2714, 2799, NULL, NULL, NULL, NULL, '{ bonus bMaxHP,BaseLevel*3; bonus bMaxSP,JobLevel; bonus2 bSubEle,Ele_Neutral,3; }');
REPLACE INTO `cp_itemcombo` VALUES( 2720, 2772, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,5; bonus bMatkRate,3; bonus bHealPower,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2721, 2772, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,5; bonus bMatkRate,3; bonus bHealPower,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2722, 2772, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,5; bonus bMatkRate,3; bonus bHealPower,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2723, 2772, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,5; bonus bMatkRate,3; bonus bHealPower,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2724, 2772, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,5; bonus bMatkRate,3; bonus bHealPower,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2725, 2772, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,5; bonus bMatkRate,3; bonus bHealPower,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2726, 2727, NULL, NULL, NULL, NULL, '{ bonus bUseSPrate,-25; }');
REPLACE INTO `cp_itemcombo` VALUES( 2733, 2772, NULL, NULL, NULL, NULL, '{ bonus2 bAddClass,Class_All,5; bonus bMatkRate,3; bonus bHealPower,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2777, 2778, 5479, NULL, NULL, NULL, '{ bonus bMaxHP,300; bonus bMatkRate,5; bonus2 bSubEle,Ele_Neutral,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2779, 2780, 5482, NULL, NULL, NULL, '{ bonus bMatkRate,10; bonus bInt,5; bonus2 bSubRace,RC_Angel,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2779, 2780, 5577, NULL, NULL, NULL, '{ bonus bMatkRate,10; bonus bInt,5; bonus2 bSubRace,RC_Angel,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 4001, 4197, NULL, NULL, NULL, NULL, '{ bonus bFlee,18; }');
REPLACE INTO `cp_itemcombo` VALUES( 4006, 4266, NULL, NULL, NULL, NULL, '{ bonus bFlee,18; }');
REPLACE INTO `cp_itemcombo` VALUES( 4009, 4179, NULL, NULL, NULL, NULL, '{ bonus bFlee,18; }');
REPLACE INTO `cp_itemcombo` VALUES( 4014, 4306, NULL, NULL, NULL, NULL, '{ bonus bFlee,18; }');
REPLACE INTO `cp_itemcombo` VALUES( 4021, 4211, NULL, NULL, NULL, NULL, '{ bonus bFlee,18; }');
REPLACE INTO `cp_itemcombo` VALUES( 4025, 4222, NULL, NULL, NULL, NULL, '{ bonus2 bAddEffWhenHit,Eff_Sleep,600; }');
REPLACE INTO `cp_itemcombo` VALUES( 4028, 4296, NULL, NULL, NULL, NULL, '{ bonus bStr,3; }');
REPLACE INTO `cp_itemcombo` VALUES( 4029, 4183, NULL, NULL, NULL, NULL, '{ bonus bFlee,18; }');
REPLACE INTO `cp_itemcombo` VALUES( 4031, 4161, NULL, NULL, NULL, NULL, '{ bonus bDef,3; bonus bVit,3; }');
REPLACE INTO `cp_itemcombo` VALUES( 4036, 4186, 4233, 4281, 4343, NULL, '{ bonus bStr,4; bonus bMaxHPrate,7; bonus bMaxSPrate,7; bonus2 bSkillAtk,"MC_MAMMONITE",20; bonus bSPDrainValue,1; if(BaseJob==Job_Alchemist) { bonus3 bAutoSpell,"BS_ADRENALINE",1,10; bonus2 bAddMonsterDropItem,7139,3; bonus2 bAddMonsterDropItem,905,10; } }');
REPLACE INTO `cp_itemcombo` VALUES( 4039, 4210, 4230, 4257, 4348, NULL, '{ bonus bStr,6; bonus bAgi,4; bonus2 bSkillAtk,"RG_BACKSTAP",10; if(getskilllv("RG_STRIPARMOR")==5) bonus3 bAutoSpell,"RG_STRIPARMOR",5,50; if(BaseJob==Job_Rogue) { bonus bUseSPrate,-20; bonus3 bAutoSpell,"RG_INTIMIDATE",1,-20; } }');
REPLACE INTO `cp_itemcombo` VALUES( 4074, 4162, NULL, NULL, NULL, NULL, '{ bonus2 bAddEffWhenHit,Eff_Blind,600; }');
REPLACE INTO `cp_itemcombo` VALUES( 4090, 4212, 4328, NULL, NULL, NULL, '{ bonus bAllStats,1; }');
REPLACE INTO `cp_itemcombo` VALUES( 4106, 4248, NULL, NULL, NULL, NULL, '{ bonus bPerfectHitAddRate,20; }');
REPLACE INTO `cp_itemcombo` VALUES( 4127, 4166, NULL, NULL, NULL, NULL, '{ bonus2 bAddEffWhenHit,Eff_Curse,600; }');
REPLACE INTO `cp_itemcombo` VALUES( 4153, 4247, 4273, NULL, NULL, NULL, '{ bonus3 bAddMonsterDropItem,544,RC_Fish,3000; bonus2 bAddEle,Ele_Water,30; }');
REPLACE INTO `cp_itemcombo` VALUES( 4168, 4169, NULL, NULL, NULL, NULL, '{ bonus bMaxHPrate,20; bonus bMaxSPrate,20; bonus bCastrate,-10; }');
REPLACE INTO `cp_itemcombo` VALUES( 4172, 4210, 4230, 4257, 4272, NULL, '{ bonus bAgi,5; bonus bStr,5; bonus bAspdRate,5; bonus bSpeedRate,25; bonus bSPDrainValue,1; if(BaseClass==Job_Thief) bonus bNoGemStone; }');
REPLACE INTO `cp_itemcombo` VALUES( 4178, 4199, 4234, 4252, 4297, NULL, '{ bonus bAgi,5; bonus bDex,3; bonus bLongAtkRate,20; bonus bPerfectHitAddRate,20; if(BaseClass==Job_Archer) { bonus2 bExpAddRace,RC_Brute,5; bonus2 bComaRace,RC_Brute,100; } }');
REPLACE INTO `cp_itemcombo` VALUES( 4178, 4234, 4252, 4297, 4381, NULL, '{ bonus bDex,5; bonus2 bSkillAtk,"CG_ARROWVULCAN",5; bonus2 bSkillAtk,"DC_THROWARROW",10; bonus2 bSkillAtk,"BA_MUSICALSTRIKE",10; if(BaseJob==Job_Bard||BaseJob==Job_Dancer) bonus3 bAutoSpellWhenHit,"CG_TAROTCARD",2,50; }');
REPLACE INTO `cp_itemcombo` VALUES( 4185, 4217, 4280, 4293, 4312, NULL, '{ bonus bVit,10; bonus bCastrate,-10; bonus bUseSPRate,-10; if(BaseClass==Job_Acolyte) { bonus2 bExpAddRace,RC_Undead,5; bonus2 bExpAddRace,RC_Demon,5; bonus2 bSubRace,RC_Undead,30; bonus2 bSubRace,RC_Demon,30; } }');
REPLACE INTO `cp_itemcombo` VALUES( 4185, 4293, 4312, 4332, NULL, NULL, '{ bonus bStr,3; bonus bMaxSP,80; bonus bBaseAtk,25; bonus3 bAutoSpell,"AL_CRUCIS",5,10; bonus2 bSkillAtk,"MO_EXTREMITYFIST",10; if(BaseJob==Job_Monk) { bonus bUseSPrate,-10; bonus bNoCastCancel; } }');
REPLACE INTO `cp_itemcombo` VALUES( 4186, 4206, 4233, 4281, 4321, NULL, '{ bonus bLuk,10; bonus bSPDrainValue,2; bonus2 bSkillAtk,42,20; if(BaseClass==Job_Merchant) { bonus2 bAddMonsterDropItem,617,5; bonus bMagicDamageReturn,20; } }');
REPLACE INTO `cp_itemcombo` VALUES( 4191, 4208, 4258, 4309, 4325, 4327, '{ bonus bMaxHP,500; bonus bDef,5; bonus bMdef,5; bonus2 bSkillAtk,14,10; bonus2 bSkillAtk,19,10; bonus2 bSkillAtk,20,10; if(BaseClass==Job_Mage) { bonus bMatkRate,3; bonus bCastrate,-15; } }');
REPLACE INTO `cp_itemcombo` VALUES( 4193, 4294, NULL, NULL, NULL, NULL, '{ bonus bMaxHP,300; bonus bMaxSP,60; }');
REPLACE INTO `cp_itemcombo` VALUES( 4208, 4258, 4325, 4327, 4382, NULL, '{ bonus bInt,3; bonus2 bSkillAtk,"WZ_HEAVENDRIVE",10; bonus2 bSkillAtk,"MG_THUNDERSTORM",10; if(BaseJob==Job_Sage) { bonus bMagicDamageReturn,20; bonus2 bAddMonsterDropItem,716,100; bonus2 bAddMonsterDropItem,715,100; bonus bCastrate,-20; } }');
REPLACE INTO `cp_itemcombo` VALUES( 4218, 4269, NULL, NULL, NULL, NULL, '{ bonus bHPrecovRate,30; bonus bSPrecovRate,30; bonus bVit,4; bonus bInt,4; }');
REPLACE INTO `cp_itemcombo` VALUES( 4220, 4246, 4311, 4319, 4331, NULL, '{ bonus bStr,10; bonus bMaxHPrate,20; bonus bHPrecovRate,50; bonus3 bAutoSpell,"BS_WEAPONPERFECT",1,3; bonus2 bAddMonsterDropItem,501,500; if(BaseClass==Job_Swordman) bonus2 bAddItemGroupHealRate,IG_Potion,50; }');
REPLACE INTO `cp_itemcombo` VALUES( 4229, 4244, 4299, 4313, NULL, NULL, '{ bonus bDef,3; bonus bMdef,3; }');
REPLACE INTO `cp_itemcombo` VALUES( 4237, 4238, NULL, NULL, NULL, NULL, '{ bonus3 bAutoSpell,"MG_LIGHTNINGBOLT",5,20; }');
REPLACE INTO `cp_itemcombo` VALUES( 4268, 4277, NULL, NULL, NULL, NULL, '{ bonus bBaseAtk,20; bonus bLuk,3; }');
REPLACE INTO `cp_itemcombo` VALUES( 4311, 4319, 4331, 4371, NULL, NULL, '{ bonus bInt,1; bonus bStr,1; bonus bDef,2; bonus bSPrecovRate,10; bonus2 bSkillAtk,"PA_SHIELDCHAIN",10; bonus2 bSkillAtk,"PA_SACRIFICE",10; bonus bCastrate,-10; if(BaseJob==Job_Crusader) bonus bDefEle,Ele_Holy; }');
REPLACE INTO `cp_itemcombo` VALUES( 4323, 4324, NULL, NULL, NULL, NULL, '{ bonus3 bAutoSpell,"MG_FROSTDIVER",3,250; }');
REPLACE INTO `cp_itemcombo` VALUES( 4435, 4436, NULL, NULL, NULL, NULL, '{ bonus2 bSPGainRace,RC_DemiHuman,2; bonus2 bSPGainRace,RC_Player,2; }');
REPLACE INTO `cp_itemcombo` VALUES( 5040, 5442, NULL, NULL, NULL, NULL, '{ bonus bAspdRate,3; bonus bCastrate,3; }');
REPLACE INTO `cp_itemcombo` VALUES( 5068, 5653, NULL, NULL, NULL, NULL, '{ bonus bStr,1; bonus bAtkRate,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 5074, 5653, NULL, NULL, NULL, NULL, '{ bonus bStr,1; bonus bAspdRate,2; }');
REPLACE INTO `cp_itemcombo` VALUES( 5086,18656, NULL, NULL, NULL, NULL, '{ bonus2 bAddMonsterDropItem,12192,1; bonus2 bAddMonsterDropItem,538,1; bonus2 bAddItemHealRate,12192,100; bonus2 bAddItemHealRate,538,100; }');
REPLACE INTO `cp_itemcombo` VALUES( 5176,18656, NULL, NULL, NULL, NULL, '{ bonus bAspdRate,5; autobonus "{ bonus bAtk,50; }",5,10000,0,"{ specialeffect2 EF_POTION_BERSERK; }"; }');
REPLACE INTO `cp_itemcombo` VALUES( 5358, 5653, NULL, NULL, NULL, NULL, '{ bonus bAgi,1; bonus bFlee,3; }');
REPLACE INTO `cp_itemcombo` VALUES( 5401, 5653, NULL, NULL, NULL, NULL, '{ bonus bInt,1; bonus bMatkRate,2; }');
REPLACE INTO `cp_itemcombo` VALUES( 5403, 5555, NULL, NULL, NULL, NULL, '{ bonus2 bAddItemHealRate,579,25; bonus2 bAddMonsterDropItem,579,1000; }');
REPLACE INTO `cp_itemcombo` VALUES(13034,13035, NULL, NULL, NULL, NULL, '{ bonus bMaxSP,20; bonus bMaxHPRate,5; bonus bHit,10; bonus2 bAddSize,Size_Large,30; autobonus "{ bonus bAspdRate,100; }",1,7000,BF_WEAPON,"{ specialeffect2 EF_POTION_BERSERK; }"; }');

REPLACE INTO `cp_itemcombo` VALUES( 1631, 2166, NULL, NULL, NULL, NULL, '{ bonus2 bSkillAtk,"PR_MAGNUS",20; bonus3 bAutoSpellWhenHit,"PR_TURNUNDEAD",1,20; }');
REPLACE INTO `cp_itemcombo` VALUES( 1662,18539, NULL, NULL, NULL, NULL, '{ bonus bMatk,10*getequiprefinerycnt(EQI_HAND_R); bonus bCastRate,-10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2017, 2677, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,10; bonus bDex,2; bonus2 bSubRace,RC_Demon,10; bonus2 bSubRace,RC_Undead,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2017, 2711, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,10; bonus bDex,2; bonus2 bSubRace,RC_Demon,10; bonus2 bSubRace,RC_Undead,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2114, 2353,18594, NULL, NULL, NULL, '{ bonus bStr,2; bonus bDef,5; bonus bMdef,5; if(BaseClass==Job_Swordman) bonus bDef,6; }');
REPLACE INTO `cp_itemcombo` VALUES( 2135, 2486, NULL, NULL, NULL, NULL, '{ bonus2 bAddEff,Eff_Blind,500; autobonus "{ bonus bFlee,20; }",200,10000,BF_WEAPON,"{ specialeffect2 EF_INCAGILITY; }"; }');
REPLACE INTO `cp_itemcombo` VALUES( 2353, 2489, 2517, NULL, NULL, NULL, '{ bonus bVit,5; bonus bHPrecovRate,10; bonus bSPrecovRate,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2353, 2488, 2516, NULL, NULL, NULL, '{ bonus bAgi,3; bonus bMaxHPrate,5; bonus bMaxSPrate,5; }');
REPLACE INTO `cp_itemcombo` VALUES( 2354, 2419, 2599, 5128, NULL, NULL, '{ bonus bVit,5; bonus bMaxHPrate,15; bonus bMaxSPrate,5; bonus bDef,5; bonus bMdef,15; bonus2 bSubEle,Ele_Water,10; bonus2 bSubEle,Ele_Earth,10; bonus2 bSubEle,Ele_Fire,10; bonus2 bSubEle,Ele_Wind,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2354, 2493, 2520, 5128, NULL, NULL, '{ bonus bVit,5; bonus bMaxHPrate,15; bonus bMaxSPrate,5; bonus bDef,5; bonus bMdef,15; bonus2 bSubEle,Ele_Water,10; bonus2 bSubEle,Ele_Earth,10; bonus2 bSubEle,Ele_Fire,10; bonus2 bSubEle,Ele_Wind,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2354, 2493, 2599, 5128, NULL, NULL, '{ bonus bVit,5; bonus bMaxHPrate,15; bonus bMaxSPrate,5; bonus bDef,5; bonus bMdef,15; bonus2 bSubEle,Ele_Water,10; bonus2 bSubEle,Ele_Earth,10; bonus2 bSubEle,Ele_Fire,10; bonus2 bSubEle,Ele_Wind,10; }');
REPLACE INTO `cp_itemcombo` VALUES( 2481, 2730, NULL, NULL, NULL, NULL, '{ bonus bBaseAtk,getequiprefinerycnt(EQI_SHOES); }');
REPLACE INTO `cp_itemcombo` VALUES( 2481, 2731, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,getequiprefinerycnt(EQI_SHOES)/2; bonus bVariableCastrate,-(getequiprefinerycnt(EQI_SHOES)/2); }');
REPLACE INTO `cp_itemcombo` VALUES( 2490, 2730, NULL, NULL, NULL, NULL, '{ bonus bBaseAtk,getequiprefinerycnt(EQI_SHOES); }');
REPLACE INTO `cp_itemcombo` VALUES( 2490, 2731, NULL, NULL, NULL, NULL, '{ bonus bMatkRate,getequiprefinerycnt(EQI_SHOES)/2; bonus bVariableCastrate,-(getequiprefinerycnt(EQI_SHOES)/2); }');
REPLACE INTO `cp_itemcombo` VALUES( 2518, 2648, 2903, 5126, NULL, NULL, '{ bonus bInt,5; bonus bMdef,11; bonus bMaxSPrate,20; bonus bNoCastCancel; bonus bCastrate,25; }');
REPLACE INTO `cp_itemcombo` VALUES( 2518, 2902, 2649, 5126, NULL, NULL, '{ bonus bInt,5; bonus bMdef,11; bonus bMaxSPrate,20; bonus bNoCastCancel; bonus bCastrate,25; }');
REPLACE INTO `cp_itemcombo` VALUES( 2518, 2902, 2903, 5126, NULL, NULL, '{ bonus bInt,5; bonus bMdef,11; bonus bMaxSPrate,20; bonus bNoCastCancel; bonus bCastrate,25; }');
REPLACE INTO `cp_itemcombo` VALUES( 2519, 2650, 2901, 5127, NULL, NULL, '{ bonus bStr,2; bonus bLuk,9; bonus bCritical,13; bonus bBaseAtk,18; bonus bFlee2,13; }');
REPLACE INTO `cp_itemcombo` VALUES( 2519, 2900, 2651, 5127, NULL, NULL, '{ bonus bStr,2; bonus bLuk,9; bonus bCritical,13; bonus bBaseAtk,18; bonus bFlee2,13; }');
REPLACE INTO `cp_itemcombo` VALUES( 2519, 2900, 2901, 5127, NULL, NULL, '{ bonus bStr,2; bonus bLuk,9; bonus bCritical,13; bonus bBaseAtk,18; bonus bFlee2,13; }');
REPLACE INTO `cp_itemcombo` VALUES(18115, 1753, NULL, NULL, NULL, NULL, '{ bonus bLongAtkRate,50; }');
