//= Auriga Script ==============================================================
// Ragnarok Online Splendide Town Script	by refis
//==============================================================================

//============================================================
// �L�̎�E��
//------------------------------------------------------------
spl_fild02,373,240,4	script	�L�̎�E��	421,{
	if(CATHAND_POINT == 0) {
		mes "[�L�̎�E��]";
		mes "���������p���肪�Ƃ��������܂��B";
		mes "�L�̎�T�[�r�X�ł��B";
		next;
		mes "[�L�̎�E��]";
		mes "�c�c�ɂႨ�H";
		mes "���Ȃ��l��";
		mes "�܂��L�̎�T�[�r�X��";
		mes "����_�񂵂Ă��Ȃ��悤�ł��ˁB";
		next;
		mes "[�L�̎�E��]";
		mes "����A����_�񂵂ė~�����ł��I";
		mes "�_�񂷂�ƕ֗��ȃT�[�r�X��";
		mes "�󂯂���ł��I";
		next;
		mes "[�L�̎�E��]";
		mes "�_���";
		mes "^FF0000�~�b�h�K���h�A���R���Ԓn�ɂ���";
		mes "�L�̎�E��^000000�����Ă���邩��";
		mes "����A�ނɘb��������";
		mes "�_�񂵂Ă��������ˁI";
		close;
	}
	mes "[�L�̎�E��]";
	mes "�ɂႨ�`�A";
	mes "����^FF0000�L�̎�T�[�r�X^000000";
	mes "�����p���肪�Ƃ��������܂��B";
	next;
	mes "[�L�̎�E��]";
	mes "���݁A���Ȃ��l��";
	mes "�L�̎�M�p�|�C���g�́A";
	mes "^FF0000" +CATHAND_POINT+ "^000000�|�C���g�ł��B";
	mes "�����́A�ǂ̃T�[�r�X�������p�ł����H";
	next;
	setarray .@str$,(CATHAND_POINT >= 10)? "�q�ɃT�[�r�X -> 60zeny": "",
			(CATHAND_POINT >= 100)? "�L���[�v": "";
	switch(select("�ʒu�ۑ��T�[�r�X(�A���R���Ԓn)",.@str$[0],.@str$[1],"��߂�")) {
	case 1:
		savepoint "mid_camp",56,138;
		mes "[�L�̎�E��]";
		mes "���̐�ɂ���X�̏Z���B��";
		mes "������������";
		mes "�����ł̓Z�[�u�ł��Ȃ���ł��B";
		next;
		mes "[�L�̎�E��]";
		mes "�ɂႨ�c�c";
		mes "�H���p�^�p�^���Ă�����̂�����";
		mes "���傤���傾�Ǝv����";
		mes "�ǂ���������";
		mes "�X�̏Z���������݂����Łc�c";
		mes "���̂��Ƃ����������̂����c�c";
		next;
		mes "[�L�̎�E��]";
		mes "������A";
		mes "�~�b�h�K���h�A���R���Ԓn";
		mes "�ɃZ�[�u���Ă����܂����B";
		mes "�\����Ȃ��ɂႨ�c�c";
		close;
	case 2:
		if(basicskillcheck() && getskilllv(1) < 6) {
			mes "[�L�̎�E��]";
			mes "�ɂ�ɂ�H";
			mes "���������ł��ˁB";
			mes "�����ɐV�Ė`���҂�";
			mes "����Ȃ��͂��Ȃ̂Ɂc�c";
			next;
			mes "[�L�̎�E��]";
			mes "��{�X�L�������x��6�܂�";
			mes "�K�����Ă��Ȃ���";
			mes "�q�ɂ͗��p�ł��Ȃ��̂ł��B";
			close;
		}
		if(Zeny < 60) {
			mes "[�L�̎�E��]";
			mes "�ɂ�ɂ�H";
			mes "Zeny������Ȃ��悤�ł���B";
			mes "��X�L�̎�T�[�r�X��";
			mes "�q�ɗ��p����60Zeny�ł��B";
			mes "�������ł��傤�H";
			close;
		}
		set Zeny,Zeny-60;
		openstorage;
		close;
	case 3:
		mes "[�L�̎�E��]";
		mes "���݁A";
		mes strcharinfo(0)+ "�l��";
		mes "�L�̎�M�p�|�C���g�́A";
		mes "^FF0000" +CATHAND_POINT+ "^000000�|�C���g";
		mes "�ł��̂ŁA���̊X�ւ�";
		mes "�L���[�v�T�[�r�X�����p�ł��܂��B";
		next;
		switch(select("�A���R���Ԓn----5500z","�}�k�N�t�B�[���h02----7500z","��߂�")) {
		case 1:
			set .@map$,"mid_camp";
			set .@warpx,56;
			set .@warpy,139;
			set .@zeny,5500;
			break;
		case 2:
			set .@map$,"man_fild02";
			set .@warpx,129;
			set .@warpy,61;
			set .@zeny,7500;
			break;
		case 3:
			mes "[�L�̎�E��]";
			mes "�킩��܂����B";
			mes "�܂��̗��p�����҂����Ă��܂��B";
			close;
		}
		if(Zeny < .@zeny) {
			mes "[�L�̎�E��]";
			mes "�ɂ�ɂ�A����������܂����B";
			close;
		}
		mes "[�L�̎�E��]";
		mes "�ɂ�ɂ�A";
		mes "����ł͂����肵�܂��B";
		close2;
		set Zeny,Zeny - .@zeny;
		warp .@map$,.@warpx,.@warpy;
		end;
	case 4:
		mes "[�L�̎�E��]";
		mes "�����ł����`�B";
		mes "�܂����҂����Ă���܂��B";
		close;
	}
}

//============================================================
// �X�v�����f�B�b�h���l
//------------------------------------------------------------
spl_in01,110,326,5	script	�X�v�����f�B�b�h���l	439,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[���l]";
		mes "BurWehAla";
		mes "tasnarAndu�@Ie�@Ru";
		close;
	}
	mes "[���l]";
	mes "��������Ⴂ�܂��B";
	mes "�������T���ł����H";
	next;
	switch(select("���i�̐�����������","�s���M�L�����̉ʎ��W����","���V�I�����F�X�p�̃n�`��","�R���k�X�̗�","��߂Ă���")) {
	case 1:
		mes "[���l]";
		mes "�͂��A���i�̐������I";
		close2;
		openbook 11018;
		end;
	case 2:
		set .@gain,12344;
		break;
	case 3:
		set .@gain,12345;
		break;
	case 4:
		set .@gain,12349;
		break;
	case 5:
		mes "[���l]";
		mes "�����ł����A�c�O�ł��B";
		mes "�܂����҂����Ă���܂��B";
		close;
	}
	mes "[���l]";
	mes "^3131FF�X�v�����f�B�b�h�R�C��1��^000000�ɂ�";
	mes getitemname(.@gain)+ "��";
	mes "^3131FF3��^000000���w���ł��܂��B";
	next;
	mes "[���l]";
	mes "��������Ⴂ�܂��B";
	mes "�������T���ł����H";
	next;
	if(select("����","����Ȃ�") == 2) {
		mes "[���l]";
		mes "�����ł����A�c�O�ł��B";
		mes "�܂����҂����Ă���܂��B";
		close;
	}
	if(countitem(6081) < 1) {
		mes "[���l]";
		mes "���₨��A";
		mes "�R�C��������܂����B";
		close;
	}
	if(checkitemblank() == 0) {
		mes "[���l]";
		mes "����H";
		mes "�ו������������ł���B";
		mes "����ł͏��i��n�����Ƃ͏o���܂���B";
		mes "�ו��̎�ނ����炵�Ă���";
		mes "�܂��b�������Ă��������ˁB";
		close;
	}
	if(checkweight(.@gain,3) == 0) {
		mes "[���l]";
		mes "����H";
		mes "�ו������������ł���B";
		mes "����ł͏��i��n�����Ƃ͏o���܂���B";
		mes "�ו��̏d�ʂ����炵�Ă���";
		mes "�܂��b�������Ă��������ˁB";
		close;
	}
	mes "[���l]";
	mes "�͂��A";
	mes getitemname(.@gain)+ "�ł��I";
	mes "���肪�Ƃ��������܂����I";
	delitem 6081,1;
	getitem .@gain,3;
	close;
}

//============================================================
// �X�v�����f�B�b�h�Z�l
//------------------------------------------------------------
splendide,159,164,3	script	�d���̕��m	461,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�d��]";
		mes "RiniHirDieb Ie nahImanMe Di Mush";
		mes "mahnarAsh So HirAnMod O Ras";
		mes "neaLoDath Ha KoRivehWha So Thusnea";
		close;
	}
	mes "[�d���̕��m]";
	mes "���̋C�������l�����l�̂悤��";
	mes "�傫���������Ƃ肦�̃o�J�B��";
	mes "���Ȃ��Ⴂ���Ȃ��Ȃ�āA";
	mes "�ʓ|�Șb����Ȃ��c�c�B";
	close;
}

splendide,229,54,3	script	�����̂悤�ȗd��	439,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�����̂悤�ȗd��]";
		mes "ImanAnuUor Yee NeUorVer Ir RivehAshOsa";
		mes "AdorserHir er OsaAlahAno Mu RivehDath";
		next;
		mes "[�����̂悤�ȗd��]";
		mes "LarsFuloSar Yu VilGotheor Yu nes";
		mes "Anuneseor Ie remuSeDieb er ";
		mes "WosLoNud Ko NuffDuIman Ir ";
		close;
	}
	mes "[�����̂悤�ȗd��]";
	mes "�Ӂ`��A���O���l�ԂȂ́c�c�H";
	mes "���l�����̓}�V�����ǁc�c";
	mes "�������Ȃ���ˁc�c";
	next;
	mes "[�����̂悤�ȗd��]";
	mes "�ǂ�����Ă����܂ŗ����̂�";
	mes "�m��Ȃ����ǁA�ߊ��Ȃ��ł�������H";
	mes "���̔��������q��邶��Ȃ��I";
	mes "�������ɍs���Ȃ�����I!";
	close;
}

splendide,89,235,5	script	�����̂悤�ȗd��	446,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�����̂悤�ȗd��]";
		mes "WehVeldHir Or ThusNorAnu";
		mes "ReImanWos Yu marFuloNor Yee ";
		mes "SharneaVrum Ir Ruff";
		next;
		mes "[�����̂悤�ȗd��]";
		mes "BurKoWeh Ie nesThusLu Ee ";
		close;
	}
	mes "[�����̂悤�ȗd��]";
	mes "�������������`���`����";
	mes "�y������`�̂��̂͊y�����`!!";
	mes "�������̐��͂��������`��";
	emotion 2;
	next;
	mes "[�����̂悤�ȗd��]";
	mes "���`���`�A���������Ă�";
	mes "����������`�B";
	close;
}

splendide,245,243,3	script	�d���̕��m	462,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�d���̕��m]";
		mes "DiebVohlWeh Ko RasVeldFar Ie AshVohl";
		mes "neaAmanIman Ie DorDuMe No Hireo";
		mes "tassermaur Yee DorAdorNud Ee ";
		mes "NohThorVe O FusImanAman";
		next;
		mes "[�d���̕��m]";
		mes "OsaVeldWeh U GothIyazVer Or ";
		mes "LarsAnDor Yee TurVeldVil";
		close;
	}
	mes "[�d���̕��m]";
	mes "���̒n�͂ˁA�͉̂����ďZ�ނɂ�";
	mes "�s�����̊����y�n�������̂�B";
	mes "�ł��A�D�G�Ȏ��B�̎��";
	mes "�Z�݂₷���y�n�ɂȂ����킯�B";
	next;
	mes "[�d���̕��m]";
	mes "���Ƃ͂��̋��l�B��ǂ��o����";
	mes "�����ɂȂ�񂾂��ǂˁB";
	close;
}

splendide,230,142,3	script	�����̂悤�ȗd��	439,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�����̂悤�ȗd��]";
		mes "AgolWhaNe O LoRini";
		close;
	}
	mes "[�����̂悤�ȗd��]";
	mes "���ӂӂӁc�c�B";
	mes "�Ȃ�ł���Ȃ�";
	mes "���͔������̂ł��傤�I";
	close;
}

splendide,274,203,3	script	���N�̂悤�ȗd��	444,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[���N�̂悤�ȗd��]";
		mes "AnnarNor So marFarAno Di ";
		mes "NudThusNei Ir  Ir ";
		mes "narVaTi Mu SharDimmaur Or Ano";
		mes "WhaModKo Or eoNeiNor Di ";
		mes "ImanDunah O  O ";
		close;
	}
	mes "[���N�̂悤�ȗd��]";
	mes "�˂��˂��A�����̐l�I";
	mes "�M���͐l�ԂȂ�ł��傤�H";
	mes "�����ɂ͂ǂ�����ė����́H";
	mes "�l�ԒB���Z��ł��鐢�E��";
	mes "�ǂ�ȂƂ���Ȃ́H";
	mes "�y�����Ƃ���Ȃ́H�����Ă�`�B";
	close;
}

splendide,275,141,3	script	�d���̕��m	447,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�d���̕��m]";
		mes "narnahNoh Di WehRiniLars ";
		mes "Yee ModAnu";
		mes "LuAlahNe Or FarAnduOsa No AgolKo";
		next;
		mes "[�d���̕��m]";
		mes "LarsVilDim No WhaVilFus Ha Ash";
		mes "ReLarsShar Mu AnduLoLon Ie Nufftas";
		close;
	}
	mes "[�d���̕��m]";
	mes "���ɘb��������ȁI";
	mes "��H���܂𔄂���肶��Ȃ����āH";
	mes "����Ȃ̂͂킩���Ă邳�B";
	mes "���͓V�˂�����";
	mes "�S�Ă����ʂ����I";
	next;
	mes "[�d���̕��m]";
	mes "������A�N���Ƙb��";
	mes "�K�v�Ȃ�ĂȂ��񂾂�B";
	mes "���͊����ŁA�S�Ĉ�l��";
	mes "�����ł���̂�����B";
	close;
}

splendide,224,230,3	script	�����̂悤�ȗd��	440,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�����̂悤�ȗd��]";
		mes "NuffMushLars Ra WehVilnah";
		mes "Ra DielWeh RivehnarWos ";
		mes "Ra YurSharRe TalVaThor";
		mes "O VerWhatas FuloDimIyaz";
		mes "Mu WhaNoreo U AlahNeLo";
		mes "Ra UorOsa SeAnduMush Ur";
		close;
	}
	mes "[�����̂悤�ȗd��]";
	mes "�����A���̌�ɑ����ėx��Ȃ����I";
	mes "�n�C�b�I�@�����c�[�I�@�����c�[�I";
	mes "�N�ɂ����ďo������[!!�ȒP�ȒP!!";
	mes "�����A���K��˂�������";
	mes "����������̂�I";
	mes "�n�C�b�I�@�����c�[�I�@�����c�[�I";
	next;
	mes "�]�ǂ����_���X��������";
	mes "�@���K�����Ă���悤���]";
	close;
}

splendide,223,36,3	script	�d���̕��m	462,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�d���̕��m]";
		mes "AshAmanNei Ir LonVeldremu O ";
		mes "AnduSarHir No NudAnumaur Ha Veld";
		mes "Semarmah U VeTingDieb Yu ";
		mes "mahsertas Ra marAmanAdor Ir ";
		next;
		mes "[�d���̕��m]";
		mes "TingAgolLu So MushAndumah U neseor";
		mes "WhaDuFulo er ImanThusNe Di Tur";
		mes "DathUornah Ir MemaurDeh Yu Fulo";
		mes "CyaMeDor Ko VeLarsAgol";
		close;
	}
	mes "[�d���̕��m]";
	mes "���l�Ɗւ�肽���Ȃ��";
	mes "������ۂ������v���ĂȂ����ǁA";
	mes "���O�B����X�ƓG�΂��Ă���ȏ�";
	mes "�d���Ȃ��c�c�B";
	next;
	mes "[�d���̕��m]";
	mes "�C�͐i�܂Ȃ����ǁA";
	mes "�܂��c�c�A����Ɍ����ẮA";
	mes "���̓`�Ƃ̕󓁂�";
	mes "�ӂ邤���������悤���I";
	mes "���Ɛ킦�邱�Ƃ����h�Ɏv���������I";
	mes "���̋��l�߁I";
	next;
	mes "�]�ǂ���狐�l�B�ɏo���������";
	mes "�@�䎌�̗��K�����Ă���悤���B�]";
	close;
}

splendide,305,129,3	script	�C�y�ȗd��	436,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�C�y�ȗd��]";
		mes "AnduNothUor O eomaurShar Mu AnduVeld";
		mes "AdorFulotas Ko NorAlahAsh Ie Ala";
		mes "KoOsaLon Ha AnuNeiNoh Di Ting";
		mes "tasKoDiel O IyazGoth";
		emotion 45;
		next;
		mes "[�C�y�ȗd��]";
		mes "OdesmahHir Or mahneaLars So ";
		mes "HirNudAman O AdorWosDu";
		mes "DimYurVa So DanaRuYur";
		close;
	}
	mes "[�C�y�ȗd��]";
	mes "���`��A�ދ�����`�B";
	mes "�ʔ��������Ȃ����`�B";
	mes "���l�B�Ɛ키�ƌ����Ă�";
	mes "���ɂ͉��ɂ��֌W�Ȃ����`�B";
	mes "���܂����s���Ƃ��Ȃ����ˁB";
	emotion 45;
	next;
	mes "[�C�y�ȗd��]";
	mes "��邱�Ƃ��Ȃ����`";
	mes "�����̔��e��ۂ���";
	mes "��O���������ǂ���ˁ`�B";
	mes "�M���������v���ł��傤�H";
	close;
}

splendide,142,315,3	script	�d���̕��m	462,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�d���̕��m]";
		mes "WharemuLars Ur SharUdenWha Yu Agol";
		mes "LontasSar Ra DathVeAlah Ee Noh";
		mes "LarsLonnah Ko TalnesIman Ie Diel";
		next;
		mes "[�d���̕��m]";
		mes "tasSarNuff Or WehFarDieb Ir FarRu";
		mes "FusYurnah So MeAshnar O Noth";
		mes "YurBurDu Yu VeldVaMush So Thor";
		mes "AgolDiebUor No TurnahAla O ";
		emotion 20;
		close;
	}
	mes "[�d���̕��m]";
	mes "��Ԃ̂��ӊO�Ƒ�ςȂ�ł���B";
	mes "�ł��A�������͊y������";
	mes "�ǂ��Ƃ��܂����c�B";
	next;
	mes "[�d���̕��m]";
	mes "����H�@�M���͐l�ԂȂ�ł��ˁH";
	mes "��X�̂悤�ɔ������H��";
	mes "���Ă���΁A�����Ȃ��";
	mes "�ʓ|���Ƃ����Ȃ��Ă������̂Ɂc�c�B";
	mes "�M������ςł��ˁc�c�B";
	emotion 20;
	close;
}

splendide,181,107,5	script	�d���̕��m	462,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�d���̕��m]";
		mes "hFarDieb Ir FarRu";
		mes "Yu VeldVaMush  So MeAs";
		mes "YurBurDu So ThorFusYurnah";
		mes "No TurnahAla OAgolDiebUor";
		close;
	}
	mes "[�d���̕��m]";
	mes "�X�}�[�g���Y��Ȏ��͔������I";
	mes "����ɔ�ׂāA���̎푰�͉������A";
	mes "�u�T�C�N�����c�c�B";
	mes "�����`�A�v���o��������";
	mes "���C�������Ă�����I";
	close;
}

splendide,188,76,5	script	���m	461,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[���m]";
		mes "SeAshLu�@Di�@YurDiebTing";
		mes "Ee�@VeModTur�@No";
		mes "NuffLarsVa�@No";
		close;
	}
	mes "[���m]";
	mes "�����́A";
	mes "���t�B�l���̑O����n";
	mes "�X�v�����f�B�b�h�ł��B";
	close;
}

splendide,201,76,3	script	���m	461,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[���m]";
		mes "SeAshLu�@Di�@YurDiebTing";
		mes "Ee�@VeModTur�@No";
		mes "NuffLarsVa�@No";
		close;
	}
	mes "[���m]";
	mes "�����́A";
	mes "���t�B�l���̑O����n";
	mes "�X�v�����f�B�b�h�ł��B";
	close;
}

splendide,207,97,5	script	�d��	443,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�d��]";
		mes "sehrVa";
		mes "IyazAnman�@Di�@TurHirCya";
		misceffect 362;
		close;
	}
	mes "[�d��]";
	mes "�₠�I";
	mes "�l�����̊��򉻑��u�̂悤��";
	mes "�����o����񂾂�B";
	mes "�����!!";
	mes "�ǂ��A�����������H";
	misceffect 362;
	close;
}

splendide,210,95,3	script	�d��	442,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�d��]";
		mes "MushIyazTur�@Ee�@YurDana";
		emotion 21;
		close;
	}
	mes "[�d��]";
	mes "���킠�I";
	mes "������������!!";
	emotion 21;
	close;
}

spl_in01,190,314,5	script	�ۈ��S����	461,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�ۈ��S����]";
		mes "GothremuAman�@Ha";
		mes "DimDielNuff";
		mes "GothAnAsh�@er�@NohVaAgol";
		mes "Yee CyaOsaDor�@U�@Aman�@U";
		mes "TurOdesVrum�@Ir�@TalDathOsa";
		close;
	}
	mes "[�ۈ��S����]";
	mes "�����̓X�v�����f�B�b�h�̒n���č����B";
	mes "���Ă��ꂽ���Ȃ�������A";
	mes "��l�������Ă��ق����������B";
	close;
}

spl_in01,281,329,3	script	�ۈ��S����	447,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�ۈ��S����]";
		mes "AnduVeldRe�@Ko";
		mes "VeldReFulo�@S";
		mes "LomaurDu�@SoSo";
		close;
	}
	mes "[�ۈ��S����]";
	mes "�Â��ɁI";
	mes "���l�Ɏh������������ȁI";
	close;
}

spl_in01,287,306,3	script	#spl_prs	111,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�T�t�@���̕ߗ�]";
		mes "����� ��";
		mes "�����ʁ@���@�灺��";
		close;
	}
	mes "[�T�t�@���̕ߗ�]";
	mes "�̂��A�̂��c�c";
	mes "���ނ��c�c";
	mes "�u���f�B�E��������c�c";
	close;
}

spl_in01,265,315,0	script	#spl_prs1	139,5,5,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�������畷�����鐺]";
		mes "RuffUdeneo�@Mu�@VilAsh";
		mes "YurReDur�@Ha�@DielTalNe";
		mes "Ko�@Lars";
		mes "HirVerWeh�@Yu�@AnuNud";
		close;
	}
	mes "[�������畷�����鐺]";
	mes "�����Ă���A�I���͌������I";
	mes "�T�t�@���̃X�p�C�Ȃ񂩂���Ȃ�!!";
	mes "�����I������������o���I";
	mes "�o��������o����!!";
	close;
}

spl_in01,172,225,3	script	���Q���l	51,{
	cutin "god_nelluad02",2;
	mes "�]�j���y������t���Ă���]";
	next;
	cutin "god_nelluad01",2;
	mes "�]���l�͂��Ȃ������邱�Ƃ�";
	mes "�@�C�t���A���Ȃ��ɘb���������]";
	next;
	mes "[���Q���l�l��]";
	mes "����ɂ���B";
	mes "�悩�����牉�t��";
	mes "�����Ă����Ă��������B";
	next;
	menu "���Ȃ��́H",-;
	mes "[���Q���l�l��]";
	mes "�l�̓l���ƌ����܂��B";
	mes "�d��������";
	mes "���t�𒮂��Ă�����Ă�����ł��B";
	next;
	mes "[���Q���l�l��]";
	mes "�l�́A���̐����܂܂ɉ������ɓ���A";
	mes "��̗����܂܂�";
	mes "���̒n�ɂ���ė��܂����B";
	next;
	mes "[���Q���l�l��]";
	mes "�����������Ă������";
	mes "��������";
	mes "�d�������Ƃ����ǂ��Ȃ�A";
	mes "�����ŉ��t�����Ă����ł��B";
	next;
	mes "[���Q���l�l��]";
	mes "���t���ʂ��Ȃ��Ă����y��";
	mes "�ނ�ƒʂ��������Ƃ��ł��܂����B";
	mes "�ނ�͕���������푰��";
	mes "�ƂĂ��������ł��B";
	next;
	mes "[���Q���l�l��]";
	mes "�ǂ��ł����A";
	mes "�N�������Ă����܂��񂩁H";
	next;
	if(select("�Ȃ����N�G�X�g����","���������ł�") == 2) {
		cutin "god_nelluad03",2;
		mes "[���Q���l�l��]";
		mes "�������A�c�O�ł��ˁB";
		next;
		mes "[���Q���l�l��]";
		mes "�l�͂��΂炭";
		mes "�����ɂ������Ȃ̂�";
		mes "���t�����������Ȃ�����";
		mes "���ł����Ă��������ˁB";
		close2;
		cutin "god_nelluad03",255;
		end;
	}
	mes "[���Q���l�l��]";
	mes "�ł́A�D���ȋȂ�";
	mes "�I��ł��������B";
	next;
	switch(select("�u���M�̎�","�i���̍���","�[�z�̃A�T�V���N���X","�j�[�x�����O�̎w��")) {
	case 1:
		cutin "god_nelluad02",2;
		mes "[���Q���l�l��]";
		mes "�u���M�̎��ł��ˁB";
		mes "���l�̐S�𒮂��Ă��������B";
		soundeffect "bragis_poem.wav",0,0;
		close2;
		cutin "god_nelluad02",255;
		end;
	case 2:
		cutin "god_nelluad02",2;
		mes "[���Q���l�l��]";
		mes "�i���̍��ׁA";
		mes "����͗Y��ȋȂł��B";
		mes "�Ƃ���ł��̑�ځA";
		mes "���׏�Ԃ��i���ɑ����̂��A";
		mes "����Ƃ��i���ƍ��ׂ��������̂Ȃ̂��A";
		mes "�ʂ����Ăǂ����̈Ӗ��Ȃ�ł��傤�H";
		soundeffect "chaos_of_eternity.wav",0,0;
		close2;
		cutin "god_nelluad02",255;
		end;
	case 3:
		cutin "god_nelluad02",2;
		mes "[���Q���l�l��]";
		mes "�[�z�̃A�T�V���N���X�B";
		mes "���̉e�ɕ�܂ꂽ�A�T�V���N���X��";
		mes "�[����w�ɂ������ށc�c";
		mes "���D�Y���f���炵�����i�ł���ˁB";
		soundeffect "assassin_of_sunset.wav",0,0;
		close2;
		cutin "god_nelluad02",255;
		end;
	case 4:
		cutin "god_nelluad02",2;
		mes "[���Q���l�l��]";
		mes "�j�[�x�����O�̎w�ցB";
		mes "�����[���̎��ł���ˁB";
		mes "�ł́A�e���Ă݂܂��傤�B";
		next;
		mes "[���Q���l�l��]";
		mes "�傢�Ȃ�͂̒�ɋ���ȉ������肫�B";
		mes "����f�҂��A�B���ꂵ�閧��m��";
		mes "���̉�������w�ւ�b���グ�����A";
		mes "���̎҂͑S�\�ȗ͂𓾂�B";
		mes "����͐_�X�����x�z���ɂ���";
		mes "�S���E�̉��̎w�ւł������`�B";
		soundeffect "ring_of_nibelungen.wav",0,0;
		next;
		mes "[���Q���l�l��]";
		mes "���@���n����z�������l������";
		mes "�]�ނ��́A����͔��������_�t���C���B";
		mes "�Ƒ��ȃ��L�̎������ɂ��A";
		mes "���̏��_�͓˔@�p���������B";
		next;
		mes "[���Q���l�l��]";
		mes "���_�̑���ƂȂ�����";
		mes "����̓A���x���q�̕󕨁B";
		mes "�_�X�����x�z����Ƃ���";
		mes "���̎w�ւł������`�B";
		next;
		mes "[���Q���l�l��]";
		mes "���@�̓��Ђ����A���x���q�B";
		mes "���ɂł��Ȃ��A�����Ɏ�ɓ���";
		mes "�����Ő��̒����v���̂܂܂ɂł���B";
		mes "����Ȋ�тɐZ���Ă���ނ�";
		mes "���L�͂����₢���B";
		next;
		mes "[���Q���l�l��]";
		mes "�����ȃA���x���q��";
		mes "���̌��t�ɘf�킳��A���̐g��";
		mes "�Ȃ�ƂЂ��^�ւƕς��Ă��܂�";
		mes "�߂܂��Ă��܂����B";
		next;
		mes "[���Q���l�l��]";
		mes "�A���x���q�͎�����B";
		mes "����̎���������w�ցA���̎�l��";
		mes "�Ȃ�҂́A�Ђ��������A�₪�Ď���";
		mes "����悤�ɂƁB�w�ւ��󂯂Ƃ���";
		mes "���l�����A�ނ�݂͌��̕󕨂�";
		mes "�D�������B";
		next;
		mes "[���Q���l�l��]";
		mes "���ǁA�􂢂��󂯂���́A";
		mes "�Z������E���Ă��܂����B";
		close2;
		cutin "god_nelluad02",255;
		end;
	}
}

spl_in01,182,213,1	script	�x�e���̗d��	438,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�x�e���̗d��]";
		mes "IyazLarsSe Or An.";
		mes "marLoOsa Yee NeiBur";
		mes "Rinisehrnea Mu...? ";
		close;
	}
	mes "[�x�e���̗d��]";
	mes "���̎��l�͖{���ɕs�v�c�B";
	mes "�ˑR����āA";
	mes "���t���ʂ��Ȃ��̂�";
	mes "���t���n�߂��́B";
	next;
	mes "[�x�e���̗d��]";
	mes "�ŋ߂͂���";
	mes "�����ŉ��t�����Ă����B";
	mes "���̃����f�B��";
	mes "���Ȃ��B�̍��̉��y�ł��傤�H";
	mes "�����Ȃ��ł��ˁB";
	close;
}

spl_in01,181,218,5	script	�x�e���̗d��	446,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "�]�ڂ�����܂܉��t�𒮂��Ă���]";
		next;
		mes "[�x�e���̗d��]";
		mes "GothTingNoth Di~ nar..";
		mes "DiebIyazNud Yu FarAn";
		mes "nesFarDor U ~";
		close;
	}
	mes "�]�ڂ�����܂܉��t�𒮂��Ă���]";
	next;
	mes "[�x�e���̗d��]";
	mes "���̊y��̉��F��";
	mes "�{���ɑf���炵���c�c";
	close;
}

spl_in01,161,213,7	script	�H�����̗d��	447,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�H�����̗d��]";
		mes "NothFarLu�@Ra...?";
		mes "RuffYur..!";
		next;
		mes "�]�H�����̗d���́A";
		mes "�@��x����~�߁A";
		mes "�@�s�������Ȋ�ł��Ȃ��������]";
		close;
	}
	mes "[�H�����̗d��]";
	mes "�����̐H���͂����O�����ȁc�c";
	mes "�ł��X�[�v�����͍ō��ɂ��܂�����";
	mes "���ꂾ���͏�����B";
	next;
	mes "[�H�����̗d��]";
	mes "�c�c";
	mes "�Ƃ���ł����̌N�B";
	mes "�H�������Ă���̂�";
	mes "��������Ă����ƌ��߂�ꂽ��";
	mes "�����C���͂��Ȃ����B";
	close;
}

spl_in01,162,202,5	script	�������̗d��	436,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�������̗d��]";
		mes "TiTalLars�@Ur";
		mes "tasThorNoth�@OAnImanWha.";
		mes "FusLuRuff.....Mu";
		mes "TingLuAla Yee AnmanAndu";
		close;
	}
	mes "[�������̗d��]";
	mes "�ٍ��ɂ�";
	mes "���̂悤�ȑf���炵�����y��";
	mes "�����ł��ˁB";
	mes "���̎��l�̉��t�𒮂���";
	mes "�������Ă��܂��܂����B";
	next;
	mes "[�������̗d��]";
	mes "^0000ff���C^000000�ɖ߂�����";
	mes "�������̋Ȃ��������Ă݂܂��B";
	mes "�������̎��l�̂悤��";
	mes "���t�ł���悤�ɂȂ肽���ł��B";
	close;
}

spl_in01,167,207,7	script	�����̗d��	445,{
	mes "�]�������ɂ��鎍�l��";
	mes "�@���t�ɒ��������Ă���B";
	mes "�@�ז����Ȃ��ł������]";
	close;
}

spl_in01,180,201,3	script	�d���̕��m	461,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�d���̕��m]";
		mes "FusVohlAnu Ur�@Lon.";
		mes "LoUdenFar�@Ha�@Dormaur?";
		mes "...marAmanYur Mu.";
		close;
	}
	mes "[�d���̕��m]";
	mes "�N�͂��̎��l�Ɠ������E�̐l���낤�H";
	mes "���͂������̎��ɔ����āA";
	mes "���̎��l���Ď����Ă���̂��B";
	next;
	mes "[�d���̕��m]";
	mes "�������A�N���Ď��Ώۂ��B";
	mes "�N�����̎푰��";
	mes "��X�ɓG�ӂ��Ȃ��悤����";
	mes "�������N���邩�킩��Ȃ�����ȁB";
	next;
	mes "[�d���̕��m]";
	mes "�c�c";
	mes "����͂���ŁA";
	mes "���̎��l�����t���Ă���";
	mes "���̊y��̖��̂͂Ȃ񂾁H";
	next;
	mes "[�d���̕��m]";
	mes "�������F����ȁB";
	mes "���t���Ă���ނ��f���炵���B";
	mes "�t�@���ɂȂ��Ă��܂�����B";
	close;
}

spl_in01,189,207,3	script	�]�ƈ�	439,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�]�ƈ��d��]";
		mes "VeldAnoWeh�@Or";
		mes "TurWos";
		mes "�c�cah�c�c";
		close;
	}
	mes "[�]�ƈ��d��]";
	mes "��A�����p�ł����H";
	mes "���t�B�l���ȊO�ɂ�";
	mes "�H�ו��𔄂�܂����B";
	next;
	mes "[�]�ƈ��d��]";
	mes "����Ɏ������̐H���̗ʂł́A";
	mes "���Ȃ��̂��̑傫�Ȃ�����";
	mes "�������Ȃ��͂��ł��B";
	next;
	mes "[�]�ƈ��d��]";
	mes "�����Ƃ��Ȃ���";
	mes "��H���ɈႢ�Ȃ��ł��B";
	next;
	mes "[�]�ƈ��d��]";
	mes "�ł��A�⋋�q�ɂɍs����";
	mes "���Ȃ��̂��̑傫�Ȃ�����";
	mes "�����ς��ɂȂ�悤�ȐH�ו���";
	mes "���邩������܂���B";
	close;
}

spl_in01,154,207,5	script	�]�ƈ�	440,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[�]�ƈ�]";
		mes "NorVerNuff�@Ee�@Re!";
		mes "remuDurOdes�@Mu�@AshFus~!";
		mes "OdesTalWeh�@Ur???";
		close;
	}
	mes "[�]�ƈ�]";
	mes "���̃X�v�����f�B�b�h��";
	mes "���̊��X�������l�̈ꑰ";
	mes "�T�t�@����œ|���邽�߂�";
	mes "���ꂽ�R���{�݂ł��B";
	next;
	mes "[�]�ƈ�]";
	mes "�ނ�̓C�O�h���V����";
	mes "�����Ă���̂ł��B";
	mes "���̖\������߂�����ׂ�";
	mes "���B���t�B�l���͂��̒n�ɗ����̂ł��I";
	close;
}

spl_in01,122,314,5	script	�w����	461,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[���m]";
		mes "NorVerNuff�@Ee�@Re....";
		next;
		mes "[�w����]";
		mes "FusVerAlah�@Di";
		mes "ModNorNor�@U DimVohlWeh";
		mes "O�@DimAmannea�@An";
		mes "WosAnoNoh�@An";
		mes "AnduMeOdes�@So";
		mes "TalAdor.";
		next;
		mes "[�w����]";
		mes "DurNohHir�@Ha";
		mes "UorVaThus�@Di�@AshNuffLon";
		mes "U�@mahNuffThus�@";
		mes "U RuAmanAgol�@Ir�@NohHir...?";
		close;
	}
	mes "[�w����]";
	mes "�����V��������͂Ȃ��̂��H";
	next;
	mes "[���m]";
	mes "�͂�!!";
	mes "�����ɂ���̂��V���i�ł���܂��I";
	mes "���̌��́A�Ȃ��";
	mes "�������f�ł��Ă��܂�����";
	mes "�s���Ȑn�������ƂȂ��Ă���܂��I";
	next;
	mes "[�w����]";
	mes "�قق��B";
	mes "�������A����";
	mes "���܂茕���g���@��Ȃ��ĂˁB";
	next;
	mes "�]��l�͐V��������ɂ���";
	mes "�@�b�������Ă���]";
	close;
}

spl_in01,122,311,1	script	���m	447,{
	if(!equippeditem(2782) || YGG_1QUE < 100) {
		mes "[���m]";
		mes "NorVerNuff�@Ee�@Re";
		next;
		mes "[�w����]";
		mes "FusVerAlah�@Di�@";
		mes "ModNorNor�@U�@";
		mes "DimVohlWeh�@O�@";
		mes "DimAmannea";
		mes "An�@WosAnoNoh�@An";
		mes "AnduMeOdes�@So�@TalAdor.";
		next;
		mes "[���m]";
		mes "DurNohHir�@Ha";
		mes "UorVaThus�@Di";
		mes "AshNuffLon�@U";
		mes "mahNuffThus�@U";
		mes "RuAmanAgol�@Ir�@NohHir?";
		close;
	}
	mes "[���m]";
	mes "��H";
	mes "�����ŉ������Ă���̂ł����H";
	mes "���B�̌R��������";
	mes "���ׂ邽�߂ɗ����Ƃ��H";
	next;
	mes "[�w����]";
	mes "�D���ɂ����Ƃ��B";
	mes "���̑@�ׂȕ�����A";
	mes "���̕s��p�����Ȏ��";
	mes "������킯���Ȃ��B";
	next;
	mes "[���m]";
	mes "�ȁA�Ȃ�قǁI";
	emotion 0;
	close;
}