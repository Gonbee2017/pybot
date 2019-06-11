//= Auriga Script ==============================================================
// Ragnarok Online GvG Script - Nidavellir Guild 5	by Blaze
//==============================================================================

//============================================================
// GvGメイン処理
//------------------------------------------------------------
schg_cas05,0,0,0	script	#AgitExe_N5	-1,{
OnAgitStart:
	callfunc "AgitEmperium",120,272,1;
	end;
OnAgitBreak:
	callfunc "AgitBreak","N5";
	callfunc "AgitBreakSE","N5";
	end;
OnAgitEliminate:
	callfunc "AgitEmperium",120,272,0;
	end;
OnAgitEnd:
	callfunc "AgitEnd";
	end;
OnGuildBreak:
	callfunc "AgitGiveUp","N5";
	end;
OnAgitSummon:
	areamonster "schg_cas05",0,0,0,0,"--ja--",1117,10;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1132,4;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1219,2;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1205,1;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1216,10;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1193,18;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1269,9;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1276,7;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1208,3;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1275,1;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1268,1;
	areamonster "schg_cas05",0,0,0,0,"--ja--",1272,1;
	monster "schg_cas05",120,272,"--ja--",1272,1;
	monster "schg_cas05",120,272,"--ja--",1270,4;
	monster "schg_cas05",120,272,"--ja--",1268,1;
	monster "schg_cas05",120,272,"--ja--",1219,1;
	monster "schg_cas05",120,272,"--ja--",1276,5;
	end;
}

//============================================================
// 宝箱
//------------------------------------------------------------
schg_cas05,0,0,0	script	#AgitTreasure_N5	-1,{
OnClock0000:
	if(.treasure_id[0] == 0) {
		setarray .treasure_id,1324,1942;
		setarray .treasure_x,388,388,388,387,386,385,384,384,384,384,384,384,385,386,387,388,389,390,390,390,389,388,387,386;
		setarray .treasure_y,388,389,390,390,390,390,389,388,387,386,385,384,384,384,384,384,384,384,385,386,386,386,386,386;
	}
	callfunc "AgitTreasure",.treasure_id,.treasure_x,.treasure_y;
	end;
OnKilled:
	// dummy event
	end;
}

//============================================================
// 守備担当
//------------------------------------------------------------
schg_cas05,123,306,3	script	ケイズ#N5	868,{
	if(.guardian1_x[0] == 0) {
		setarray .guardian1_x,111,109,109, 65,109, 65,110,109, 65,110, 88,108;
		setarray .guardian1_y, 18, 44, 44, 22, 44, 22, 40, 44, 22, 40, 20, 32;
		setarray .guardian2_x,130,187,129,151,129,151,187,129,151,187,128,128;
		setarray .guardian2_y, 22, 15, 47, 18, 47, 18, 15, 47, 18, 15, 42, 42;
	}
	callfunc "AgitGuard",.guardian1_x,.guardian1_y,.guardian2_x,.guardian2_y;
	close;
}

schg_cas05,0,0,0	script	Guardian#N5	111,{
	end;
OnKilled1:
	set .guardian1,.guardian1-1;
	if(.guardian1 < 2)
		callfunc "AgitCallGuardian",1,0,120,37;
	end;
OnKilled2:
	set .guardian2,.guardian2-1;
	if(.guardian2 < 2)
		callfunc "AgitCallGuardian",2,0,151,18;
	end;
OnTimer300000:
	callfunc "AgitCallGuardian",1,1,65,40;
	end;
OnTimer600000:
	callfunc "AgitCallGuardian",2,0,152,43;
	end;
OnTimer900000:
	callfunc "AgitCallGuardian",1,2,47,43;
	end;
OnTimer1200000:
	callfunc "AgitCallGuardian",2,0,187,15;
	end;
OnTimer1800000:
	callfunc "AgitCallGuardian",1,3,109,44;
	end;
OnTimer2100000:
	callfunc "AgitCallGuardian",2,0,128,42;
	end;
OnTimer2700000:
	callfunc "AgitCallGuardian",1,4,111,18;
	end;
OnTimer3000000:
	callfunc "AgitCallGuardian",2,0,130,22;
	end;
OnTimer3600000:
	callfunc "AgitCallGuardian",1,5,112,32;
	end;
OnTimer3900000:
	callfunc "AgitCallGuardian",2,0,130,38;
	end;
OnAgitEnd:
	stopnpctimer;
	killmonster "schg_cas05","Guardian#N5::OnKilled1";
	killmonster "schg_cas05","Guardian#N5::OnKilled2";
	set .guardian1,0;
	set .guardian2,0;
	end;
}

//============================================================
// 守護石
//------------------------------------------------------------
schg_cas05,0,0,0	script	GuardianStone1#N5	111,{
OnAgitStart:
OnRepair:
	callguardian "schg_cas05",27,35,"--ja--",1907,1,"GuardianStone1#N5::OnKilled";
	set .status,0;
	end;
OnKilled:
	callfunc "AgitStoneBreak",1;
	end;
OnSet:
OnTimer300000:
	hideoffnpc "第1守護石#N5";
	misceffect 247,"第1守護石#N5";
	set .status,2;
	stopnpctimer;
	end;
OnAgitEnd:
	stopnpctimer;
	killmonster "schg_cas05","GuardianStone1#N5::OnKilled";
	set .status,0;
	end;
}

schg_cas05,27,36,0	script	第1守護石#N5	844,{
	callfunc "AgitStone",1;
	close;
OnInit:
OnAgitEnd:
	hideonnpc;
	end;
}

schg_cas05,0,0,0	script	GuardianStone2#N5	111,{
OnAgitStart:
OnRepair:
	callguardian "schg_cas05",207,75,"--ja--",1908,1,"GuardianStone2#N5::OnKilled";
	set .status,0;
	end;
OnKilled:
	callfunc "AgitStoneBreak",2;
	end;
OnSet:
OnTimer300000:
	hideoffnpc "第2守護石#N5";
	misceffect 247,"第2守護石#N5";
	set .status,2;
	stopnpctimer;
	end;
OnAgitEnd:
	stopnpctimer;
	killmonster "schg_cas05","GuardianStone2#N5::OnKilled";
	set .status,0;
	end;
}

schg_cas05,208,75,0	script	第2守護石#N5	844,{
	callfunc "AgitStone",2;
	close;
OnInit:
OnAgitEnd:
	hideonnpc;
	end;
}

//============================================================
// バリケード
//------------------------------------------------------------
schg_cas05,0,0,0	script	Barricade#N5	111,{
OnSet:
OnAgitStart:
	areasetcell "schg_cas05",114,48,126,48,1;
	callguardian "schg_cas05",115,49," ",1905,1,"Barricade#N5::OnKilled";
	callguardian "schg_cas05",117,49," ",1905,1,"Barricade#N5::OnKilled";
	callguardian "schg_cas05",119,49," ",1905,1,"Barricade#N5::OnKilled";
	callguardian "schg_cas05",121,49," ",1905,1,"Barricade#N5::OnKilled";
	callguardian "schg_cas05",123,49," ",1905,1,"Barricade#N5::OnKilled";
	callguardian "schg_cas05",125,49," ",1905,1,"Barricade#N5::OnKilled";
	end;
OnReset:
OnAgitEnd:
	areasetcell "schg_cas05",114,48,126,48,0;
	killmonster "schg_cas05","Barricade#N5::OnKilled";
	end;
OnKilled:
	end;
}

schg_cas05,124,52,0	script	制御装置01#N5	111,{
	callfunc "AgitBarricade";
	close;
OnSet:
OnAgitStart:
	set .status,0;
	areasetcell "schg_cas05",114,51,126,51,5;
	callguardian "schg_cas05",115,50," ",1905,1,"制御装置01#N5::OnKilled";
	callguardian "schg_cas05",117,50," ",1905,1,"制御装置01#N5::OnKilled";
	callguardian "schg_cas05",119,50," ",1905,1,"制御装置01#N5::OnKilled";
	callguardian "schg_cas05",121,50," ",1905,1,"制御装置01#N5::OnKilled";
	callguardian "schg_cas05",123,50," ",1905,1,"制御装置01#N5::OnKilled";
	callguardian "schg_cas05",125,50," ",1905,1,"制御装置01#N5::OnKilled";
	set .count,6;
	end;
OnKilled:
	set .count,.count-1;
	if(.count > 0)
		end;
	set .status,1;
	announce "第1バリケードが突破されました!!",0x9,0xFF0000;
	areasetcell "schg_cas05",114,51,126,51,0;
	killmonster "schg_cas05","制御装置01#N5::OnKilled";
	end;
OnReset:
OnAgitEnd:
	areasetcell "schg_cas05",114,51,126,51,0;
	killmonster "schg_cas05","制御装置01#N5::OnKilled";
	set .status,0;
	end;
}

schg_cas05,128,157,0	script	制御装置02#N5	111,{
	callfunc "AgitBarricade";
	close;
OnSet:
OnAgitStart:
	set .status,0;
	areasetcell "schg_cas05",114,154,126,154,5;
	callguardian "schg_cas05",115,153," ",1905,1,"制御装置02#N5::OnKilled";
	callguardian "schg_cas05",117,153," ",1905,1,"制御装置02#N5::OnKilled";
	callguardian "schg_cas05",119,153," ",1905,1,"制御装置02#N5::OnKilled";
	callguardian "schg_cas05",121,153," ",1905,1,"制御装置02#N5::OnKilled";
	callguardian "schg_cas05",123,153," ",1905,1,"制御装置02#N5::OnKilled";
	callguardian "schg_cas05",125,153," ",1905,1,"制御装置02#N5::OnKilled";
	set .count,6;
	end;
OnKilled:
	set .count,.count-1;
	if(.count > 0)
		end;
	set .status,1;
	announce "第2バリケードが突破されました!!",0x9,0xFF0000;
	areasetcell "schg_cas05",114,154,126,154,0;
	killmonster "schg_cas05","制御装置02#N5::OnKilled";
	end;
OnReset:
OnAgitEnd:
	areasetcell "schg_cas05",114,154,126,154,0;
	killmonster "schg_cas05","制御装置02#N5::OnKilled";
	set .status,0;
	end;
}

schg_cas05,109,247,0	script	制御装置03#N5	111,{
	callfunc "AgitBarricade";
	close;
OnSet:
OnAgitStart:
	set .status,0;
	areasetcell "schg_cas05",116,241,126,241,5;
	callguardian "schg_cas05",116,240," ",1905,1,"制御装置03#N5::OnKilled";
	callguardian "schg_cas05",118,240," ",1905,1,"制御装置03#N5::OnKilled";
	callguardian "schg_cas05",120,240," ",1905,1,"制御装置03#N5::OnKilled";
	callguardian "schg_cas05",122,240," ",1905,1,"制御装置03#N5::OnKilled";
	set .count,4;
	end;
OnKilled:
	set .count,.count-1;
	if(.count > 0)
		end;
	set .status,1;
	announce "第3バリケードが突破されました!!",0x9,0xFF0000;
	areasetcell "schg_cas05",116,241,126,241,0;
	killmonster "schg_cas05","制御装置03#N5::OnKilled";
	end;
OnReset:
OnAgitEnd:
	areasetcell "schg_cas05",116,241,126,241,0;
	killmonster "schg_cas05","制御装置03#N5::OnKilled";
	set .status,0;
	end;
}

//============================================================
// リンクフラッグ(A)
//------------------------------------------------------------
schg_cas05,106,302,0	script	LF-01#N5	111,{
	setarray .@code,1,2;	//"第1拠点","第2拠点"
	setarray .@x, 19,219;
	setarray .@y, 26, 90;
	callfunc "AgitLinkFlagA",.@code,.@x,.@y;
	close;
}

schg_cas05,109,302,0	script	LF-02#N5	111,{
	setarray .@code,11,12;	//"防衛地域1-1","防衛地域1-2"
	setarray .@x, 89,141;
	setarray .@y, 43, 45;
	callfunc "AgitLinkFlagA",.@code,.@x,.@y;
	close;
}

schg_cas05,112,302,0	script	LF-03#N5	111,{
	setarray .@code,13,14;	//"防衛地域1-3","防衛地域1-4"
	setarray .@x,137,102;
	setarray .@y, 54, 54;
	callfunc "AgitLinkFlagA",.@code,.@x,.@y;
	close;
}

schg_cas05,115,302,0	script	LF-04#N5	111,{
	setarray .@code,21,22;	//"防衛地域2-1","防衛地域2-2"
	setarray .@x, 94,163;
	setarray .@y,147,140;
	callfunc "AgitLinkFlagA",.@code,.@x,.@y;
	close;
}

schg_cas05,118,302,0	script	LF-05#N5	111,{
	setarray .@code,23,24;	//"防衛地域2-3","防衛地域2-4"
	setarray .@x, 87,151;
	setarray .@y,220,220;
	callfunc "AgitLinkFlagA",.@code,.@x,.@y;
	close;
}

schg_cas05,121,302,0	script	LF-06#N5	111,{
	setarray .@code,31,32;	//"防衛地域3-1","防衛地域3-2"
	setarray .@x,100,136;
	setarray .@y,242,242;
	callfunc "AgitLinkFlagA",.@code,.@x,.@y;
	close;
}

schg_cas05,124,302,0	script	LF-07#N5	111,{
	setarray .@code,101,102;	//"中央1区画","中央2区画"
	setarray .@x,120,119;
	setarray .@y,168,211;
	callfunc "AgitLinkFlagA",.@code,.@x,.@y;
	close;
}

schg_cas05,127,302,0	script	LF-08#N5	111,{
	setarray .@code,111,121,131;	//"区域1-1","区域2-1","区域3-1"
	setarray .@x, 89, 94,100;
	setarray .@y, 43,147,242;
	callfunc "AgitLinkFlagA",.@code,.@x,.@y;
	close;
}

schg_cas05,130,302,0	script	LF-09#N5	111,{
	setarray .@code,112,122,132;	//"区域1-2","区域2-2","区域3-2"
	setarray .@x,141,163,136;
	setarray .@y, 45,140,243;
	callfunc "AgitLinkFlagA",.@code,.@x,.@y;
	close;
}

schg_cas05,133,302,0	script	LF-10#N5	111,{
	callfunc "AgitLinkFlagB",1,275,244;
	close;
}

//============================================================
// リンクフラッグ(B)
//------------------------------------------------------------
-	script	#LinkFlag_N5	{
	callfunc "AgitLinkFlagB",0,120,290;
	close;
OnAgitInit:
OnFlagEmb_N5:
	if(substr2(strnpcinfo(2),0,1) == "B")	//ギルドフラッグ型ならエンブレム更新
		flagemblem getcastledata("schg_cas05",1);
	end;
}
schg_cas05,17,45,0		duplicate(#LinkFlag_N5)	スカーティルニル#A01	111
schg_cas05,207,95,0		duplicate(#LinkFlag_N5)	スカーティルニル#A02	111
schg_cas05,111,46,4		duplicate(#LinkFlag_N5)	スカーティルニル#B03	722
schg_cas05,129,46,4		duplicate(#LinkFlag_N5)	スカーティルニル#B04	722
schg_cas05,99,77,0		duplicate(#LinkFlag_N5)	スカーティルニル#A05	111
schg_cas05,140,77,0		duplicate(#LinkFlag_N5)	スカーティルニル#A06	111
schg_cas05,109,150,4	duplicate(#LinkFlag_N5)	スカーティルニル#B07	722
schg_cas05,130,150,4	duplicate(#LinkFlag_N5)	スカーティルニル#B08	722
schg_cas05,112,212,0	duplicate(#LinkFlag_N5)	スカーティルニル#A09	111
schg_cas05,127,212,0	duplicate(#LinkFlag_N5)	スカーティルニル#A10	111
schg_cas05,113,238,0	duplicate(#LinkFlag_N5)	スカーティルニル#A11	111
schg_cas05,126,238,0	duplicate(#LinkFlag_N5)	スカーティルニル#A12	111
schg_cas05,95,247,0		duplicate(#LinkFlag_N5)	スカーティルニル#A13	111
schg_cas05,144,247,0	duplicate(#LinkFlag_N5)	スカーティルニル#A14	111

//============================================================
// カプラ職員
//------------------------------------------------------------
schg_cas05,300,287,5	script	カプラ職員::AgitKafra_N5	117,{
	callfunc "AgitKafra",13;
	close;
OnAgitInit:
	if(getcastledata("schg_cas05",9) == 0)
		hideonnpc;
	end;
}

//============================================================
// 執事
//------------------------------------------------------------
schg_cas05,247,305,3	script	執事	55,{
	callfunc "AgitSteward","N5",0,0,0,381,381;
	close;
}

//============================================================
// マスタールームのスイッチ
//------------------------------------------------------------
schg_cas05,391,391,0	script	#AgitMaster_N5	111,{
	callfunc "AgitMaster",275,244;
	close;
}

//============================================================
// ギルドフラッグ
//------------------------------------------------------------
-	script	#GldFlag_N5a	{
	callfunc "AgitEmblemFlag",2,"schg_cas05",120,290;
	close;
OnAgitInit:
OnFlagEmb_N5:
	flagemblem getcastledata("schg_cas05",1);
	end;
}
sch_gld,101,284,4	duplicate(#GldFlag_N5a)	スカーティルニル#a01	722
sch_gld,91,284,4	duplicate(#GldFlag_N5a)	スカーティルニル#a02	722
sch_gld,66,320,6	duplicate(#GldFlag_N5a)	スカーティルニル#a03	722
sch_gld,66,310,6	duplicate(#GldFlag_N5a)	スカーティルニル#a04	722

-	script	#GldFlag_N5b	{
	end;
OnAgitInit:
OnFlagEmb_N5:
	flagemblem getcastledata("schg_cas05",1);
	end;
}
//yuno,114,183,5	duplicate(#GldFlag_N5b)	スカーティルニル#b01	722

//============================================================
// 不思議なヒマワリ（アジトダンジョン）
//------------------------------------------------------------
schg_cas05,280,391,3	script	不思議なヒマワリ#N5	976,{
	callfunc "AgitDungeonSE","schg_dun01",323,166;
	close;
}
