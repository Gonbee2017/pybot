//=====================================================================
//����BNPC�Z���t�p�^�[��1
//	�i�v�����e���E�A���x���^�E�A�C���u���b�N�j
//  callfunc "Refine1","NPCName",SuccessEmotion,FalureEmotion;
//--------------------------------------------------------------------

function	script	Refine1	{
	mes "["+getarg(0)+"]";
	mes "���͕���Ɩh��𐸘B����b�艮���B";
	mes "�N���������Ă���A�C�e���̒���";
	mes "�D���Ȃ��̂𐸘B�ł���̂��B";
	mes "�ǂ̑����A�C�e����";
	mes "���B�������̂����H";
	next;
	set .@i,select(getequipname2(1),getequipname2(2),getequipname2(3),getequipname2(4),getequipname2(5),
				getequipname2(6),getequipname2(7),getequipname2(8),getequipname2(9),getequipname2(10));
	mes "["+getarg(0)+"]";
	if(getequipisequiped2(.@i)==0) {
		switch(.@i) {
		case 1:
			mes "�N�̑���Ȃ��]�݂���";
			mes "���B���Ă����悤���H";
			break;
		case 2:
			mes "���̔M���̂ŌN�̑̂�";
			mes "���B���Ă������I";
			break;
		case 3:
			mes "�N�̍�������P�b�g�p���`��";
			mes "����r�͂Ȃ��ȁB";
			break;
		case 4:
			mes "����Ȋw�Z�p�ł��N�̉E���";
			mes "�h�����ɂ��邱�Ƃ�";
			mes "�ł��Ȃ��ˁB";
			break;
		case 5:
			mes "���[�u�������ĂȂ�����Ȃ����I";
			break;
		case 6:
			mes "�N�̑��̏L�����������I";
			break;
		case 7:
		case 8:
			mes "�ǂ��ɃA�N�Z�T���[������̂����H";
			break;
		case 9:
		case 10:
			mes "���𐸘B����ƌ����񂾁H";
			mes "���̃A�C�e���̎������H";
			break;
		}
		return;
	}
	if(getequipisenableref2(.@i)==0) {
		mes "���̃A�C�e���͐��B�s�\���B";
		return;
	}
	if(getequipisidentify(.@i)==0) {
		mes "����͖��Ӓ肾���琸�B�ł��Ȃ��B";
		return;
	}
	if(getequiprefinerycnt2(.@i)>=10) {
		mes "����ȏ�͐��B�ł��Ȃ����B";
		return;
	}
	//����Ăяo�����̂ݗ����ƃA�C�e��ID�����ꂼ��i�[
	if(.price[0]==0) {
		setarray .price,5000,100,500,5000,10000;
		setarray .itemid,985,1010,1011,984,984;
	}
	set .@wlv,getequipweaponlv2(.@i);
	switch(.@wlv) {
	case 0:
		mes "�N���I�񂾑����𐸘B����ɂ�";
		mes "^ff9999�G���j�E��^000000��";
		mes "�萔��5000Zeny���K�v���ȁB";
		mes "�����邩���H";
		break;
	case 1:
		mes "���x��1�̕���𐸘B�������̂����H";
		mes "���B���邽�߁A ^ff9999�v���R��^000000��";
		mes "�萔��100Zeny���K�v���ȁB";
		mes "������̂��H";
		break;
	case 2:
		mes "���x��2�̕���𐸘B�������̂����H";
		mes "���B���邽�߁A ^ff9999�G���x���^�R��^000000��";
		mes "�萔��500Zeny���K�v���ȁB";
		mes "������̂��H";
		break;
	case 3:
		mes "���x��3�̕���𐸘B�������̂����H";
		mes "���B���邽�߁A ^ff9999�I���f�I�R��^000000��";
		mes "�萔��5000Zeny���K�v���ȁB";
		mes "������̂��H";
		break;
	case 4:
		mes "���x��4�̕���𐸘B�������̂����H";
		mes "���B���邽�߁A ^ff9999�I���f�I�R��^000000��";
		mes "�萔��10000Zeny���K�v���ȁB";
		mes "������̂��H";
		break;
	}
	next;
	if(select("�͂�","������")==2) {
		mes "["+getarg(0)+"]";
		mes "�N�����Ȃ�d�����Ȃ����낤�c";
		return;
	}
	if(getequippercentrefinery2(.@i) < 100) {
		mes "["+getarg(0)+"]";
		if(.@wlv==0) {	//�h��̂Ƃ�
			mes "�������ƁI���̖h��͂������������";
			mes "���B�����Ă����݂������ȁc����ȏ�";
			mes "���B������h����邩��";
			mes "����Ȃ����B�h���ꂽ��";
		}
		else {		//����̂Ƃ�
			mes "�������ƁI���̕���͂������������";
			mes "���B�����Ă����݂������ȁc����ȏ�";
			mes "���B�����畐�킪���邩��";
			mes "����Ȃ����B���킪��ꂽ��";
		}
		mes "2�x�Ǝg���Ȃ��Ȃ�c����ł�";
		mes "���B������C�Ȃ̂����H";
		next;
		if(select("�͂�","������")==2) {
			mes "["+getarg(0)+"]";
			mes "�ǂ��I�����ȁB";
			mes "�����������đ��l�̕�����󂵂���";
			mes "�C���������Ȃ邩�炳�c";
			return;
		}
	}
	if(countitem(.itemid[.@wlv])<1 || Zeny<.price[.@wlv]) {
		mes "["+getarg(0)+"]";
		mes "���ꂪ�N�������Ă�S�������H";
		mes "�c�O�����A�ޗ�������Ȃ��񂶂�";
		mes "�d�����Ȃ��ȁB";
		mes "���͂����ł���Ă��ق�";
		mes "�S���L���Ȃ�����ȁB";
		return;
	}
	delitem .itemid[.@wlv],1;
	set Zeny,Zeny-.price[.@wlv];
	mes "["+getarg(0)+"]";
	mes "�J���I �J���I �J��!!";
	if(getequippercentrefinery2(.@i) > rand(100)) {
		successrefitem2 .@i;
		next;
		emotion getarg(1);
		mes "["+getarg(0)+"]";
		mes "�����A�o���������I";
		mes "�v�X�ɗǂ������ł����B";
		mes "��������Ȃ��ČN������������H";
	}
	else {
		failedrefitem2 .@i;
		next;
		emotion getarg(2);
		mes "["+getarg(0)+"]";
		mes "�N�z�z�z�z�c";
		next;
		mes "["+getarg(0)+"]";
		mes "���܂�I";
		mes "���B���ɕ�����Ă��܂����ȁc";
		mes "�فA�ق�A������߂����";
		mes "�ŏ��Ɍ��������낤�H";
	}
	return;
	//close�ŏI��
}

//=====================================================================
//����BNPC�Z���t�p�^�[��2
//	�i�t�F�C�����E�W���m�[�j
//  callfunc "Refine2","NPCName",SuccessEmotion,FalureEmotion;
//--------------------------------------------------------------------

function	script	Refine2	{
	mes "["+getarg(0)+"]";
	mes "�������B�܂��Ƃɂ���";
	mes "���B�������������o���B";
	next;
	set .@i,select(getequipname2(1),getequipname2(2),getequipname2(3),getequipname2(4),getequipname2(5),
				getequipname2(6),getequipname2(7),getequipname2(8),getequipname2(9),getequipname2(10));
	mes "["+getarg(0)+"]";
	if(getequipisequiped2(.@i)==0) {
		switch(.@i) {
		case 1:
			mes "���͖Z�����I���O�̏�k��";
			mes "�t�������Ă��鎞�ԂȂǖ����񂾁B";
			mes "����˂�����łǂ�������肾�H";
			break;
		case 2:
			mes "���͖Z�����ƌ����Ă��邾�낤�I";
			break;
		case 3:
			mes "������Ȃ���k�͂�߂Ă���I";
			break;
		case 4:
			mes "���O�A���B����C����̂��H";
			break;
		case 5:
			mes "������I";
			break;
		case 6:
			mes "������Ȃ����Y�ɕt������";
			mes "�ɂ͖����񂾁I";
			break;
		case 7:
			mes "���B���Ȃ��̂Ȃ�p�͖�������H";
			break;
		case 8:
			mes "���͖Z�����I";
			break;
		case 9:
			mes "�ǂ��𐸘B������āH";
			break;
		case 10:
			mes "�A���Ă���Ȃ����H";
			break;
		}
		return;
	}
	if(getequipisenableref2(.@i)==0) {
		mes "����͐��B�ł��Ȃ��B";
		mes "���𓖂����Ă���B";
		return;
	}
	if(getequipisidentify(.@i)==0) {
		mes "�킯�̂킩��Ȃ�����";
		mes "���B�����͖����c";
		return;
	}
	if(getequiprefinerycnt2(.@i)>=10) {
		mes "����ȏ���������Ƃ��낪";
		mes "�������I";
		return;
	}
	//����Ăяo�����̂ݗ����ƃA�C�e��ID�����ꂼ��i�[
	if(.price[0]==0 || .itemid[0]==0) {
		setarray .price,5000,100,500,5000,10000;
		setarray .itemid,985,1010,1011,984,984;
	}
	set .@wlv,getequipweaponlv2(.@i);
	switch(.@wlv) {
	case 0:
		mes "���O���I�񂾑����𐸘B����ɂ�";
		mes "^ff9999�G���j�E��^000000��";
		mes "�萔��5000Zeny���K�v���ȁB";
		mes "�r�^1Zeny�������Ȃ��B";
		break;
	case 1:
		mes "���x��1�̕���𐸘B�������̂��H";
		mes "���B���邽�߁A ^ff9999�v���R��^000000��";
		mes "�萔��100Zeny���K�v���ȁB";
		mes "�r�^1Zeny�������Ȃ��B";
		break;
	case 2:
		mes "���x��2�̕���𐸘B�������̂��H";
		mes "���B���邽�߁A ^ff9999�G���x���^�R��^000000��";
		mes "�萔��500Zeny���K�v���ȁB";
		mes "�r�^1Zeny�������Ȃ��B";
		break;
	case 3:
		mes "���x��3�̕���𐸘B�������̂��H";
		mes "���B���邽�߁A ^ff9999�I���f�I�R��^000000��";
		mes "�萔��5000Zeny���K�v���ȁB";
		mes "�v���Ԃ�ɉ��̎��͂������Ă�邩�B";
		break;
	case 4:
		mes "���x��4�̕���𐸘B�������̂��H";
		mes "���B���邽�߁A ^ff9999�I���f�I�R��^000000��";
		mes "�萔��10000Zeny���K�v���ȁB";
		mes "���x��4�̕��킩�c�������邺�I";
		break;
	}
	next;
	if(select("�͂�","������")==2) {
		mes "["+getarg(0)+"]";
		mes "�V�т���Ȃ��񂾂�I";
		return;
	}
	if(getequippercentrefinery2(.@i) < 100) {
		mes "["+getarg(0)+"]";
		mes "���c�ǂ����炱��Ȗ��ȕ���";
		mes "�����Ă����񂾁c�B";
		mes "����ȏ�̐��B�͊댯���B";
		mes "��������m�ł��Ƃ����̂��H";
		next;
		if(select("�͂�","������")==2) {
			mes "["+getarg(0)+"]";
			mes "�܂��c";
			mes "���͖Z�����A�A���Ă���B";
			return;
		}
	}
	if(countitem(.itemid[.@wlv])<1 || Zeny<.price[.@wlv]) {
		mes "["+getarg(0)+"]";
		mes "1Zeny���������Ȃ�����";
		mes "���B��������΂����������Ă��ȁB";
		return;
	}
	delitem .itemid[.@wlv],1;
	set Zeny,Zeny-.price[.@wlv];
	mes "["+getarg(0)+"]";
	mes "�J���I �J���I �J��!!";
	if(getequippercentrefinery2(.@i) > rand(100)) {
		successrefitem2 .@i;
		next;
		emotion getarg(1);
		mes "["+getarg(0)+"]";
		mes "�o�b�`�����I";
		mes "�܂����Ă���B";
	}
	else {
		failedrefitem2 .@i;
		next;
		emotion getarg(2);
		mes "["+getarg(0)+"]";
		mes "�Ӂc";
		next;
		mes "["+getarg(0)+"]";
		mes "�c�O���c";
		mes "�܂��l�������������Ƃ�����B";
		mes "�������ނȂ�c";
	}
	return;
	//close�ŏI��
}

//=====================================================================
//����BNPC�Z���t�p�^�[��3
//	�i�����N�j
//  callfunc "Refine3","NPCName",SuccessEmotion,FalureEmotion;
//--------------------------------------------------------------------

function	script	Refine3	{
	mes "["+getarg(0)+"]";
	mes "���͕���Ɩh��𐸘B����b�艮�B";
	mes "�����������Ă���A�C�e���̒���";
	mes "�D���Ȃ��̂𐸘B�ł���B";
	mes "�ǂ̑����A�C�e����";
	mes "���B�������̂��H";
	next;
	set .@i,select(getequipname2(1),getequipname2(2),getequipname2(3),getequipname2(4),getequipname2(5),
				getequipname2(6),getequipname2(7),getequipname2(8),getequipname2(9),getequipname2(10));
	mes "["+getarg(0)+"]";
	if(getequipisequiped2(.@i)==0) {
		switch(.@i) {
		case 1:
			mes "���̑���Ȃ��]�݂���";
			mes "���B���Ă��������悤���H";
			break;
		case 2:
			mes "���̔M���̂œ��̑̂�";
			mes "���B���Ă������I";
			break;
		case 3:
			mes "���̍������������Z�p�͖����B";
			break;
		case 4:
			mes "���̉E����}�V���K����";
			mes "����͖̂������B";
			break;
		case 5:
			mes "���[�u�������Ă��Ȃ��ȁB";
			break;
		case 6:
			mes "�L���c";
			break;
		case 7:
		case 8:
			mes "�ǂ̃A�N�Z�T���[���H";
			break;
		case 9:
		case 10:
			mes "���𐸘B����ƌ����H";
			mes "���̃A�C�e���̎����H";
			break;
		}
		return;
	}
	if(getequipisenableref2(.@i)==0) {
		mes "���̃A�C�e���͐��B�s�\�B";
		return;
	}
	if(getequipisidentify(.@i)==0) {
		mes "����͖��Ӓ肾���琸�B�ł��Ȃ��B";
		return;
	}
	if(getequiprefinerycnt2(.@i)>=10) {
		mes "����ȏ�͐��B�ł��Ȃ��B";
		return;
	}
	//����Ăяo�����̂ݗ����ƃA�C�e��ID�����ꂼ��i�[
	if(.price[0]==0 || .itemid[0]==0) {
		setarray .price,5000,100,500,5000,10000;
		setarray .itemid,985,1010,1011,984,984;
	}
	set .@wlv,getequipweaponlv2(.@i);
	switch(.@wlv) {
	case 0:
		mes "�����I�񂾑����𐸘B����ɂ�";
		mes "^ff9999�G���j�E��^000000�� ";
		mes "�萔��5000Zeny���K�v���B";
		mes "�����邩�H";
		break;
	case 1:
		mes "���x��1�̕���𐸘B�������̂��H";
		mes "���B���邽�߁A ^ff9999�v���R��^000000��";
		mes "�萔��100Zeny���K�v���B";
		mes "�����邩�H";
		break;
	case 2:
		mes "���x��2�̕���𐸘B�������̂��H";
		mes "���B���邽�߁A ^ff9999�G���x���^�R��^000000��";
		mes "�萔��500Zeny���K�v���B";
		mes "�����邩�H";
		break;
	case 3:
		mes "���x��3�̕���𐸘B�������̂��H";
		mes "���B���邽�߁A ^ff9999�I���f�I�R��^000000��";
		mes "�萔��5000Zeny���K�v���B";
		mes "�����邩�H";
		break;
	case 4:
		mes "���x��4�̕���𐸘B�������̂��H";
		mes "���B���邽�߁A ^ff9999�I���f�I�R��^000000��";
		mes "�萔��10000Zeny���K�v���B";
		mes "�����邩�H";
		break;
	}
	next;
	if(select("�͂�","������")==2) {
		mes "["+getarg(0)+"]";
		mes "������߂�Ȃ�d�����Ȃ��c";
		return;
	}
	if(getequippercentrefinery2(.@i) < 100) {
		mes "["+getarg(0)+"]";
		if(.@wlv==0) {	//�h��̂Ƃ�
			mes "�ӂށc���̖h��͂������������";
			mes "���B�����Ă����݂������ȁc����ȏ�";
			mes "���B������h����邩��";
			mes "����Ȃ��B�h���ꂽ��";
		}
		else {		//����̂Ƃ�
			mes "�ӂށc���̕���͂������������";
			mes "���B�����Ă����݂������ȁc����ȏ�";
			mes "���B�����畐�킪���邩��";
			mes "����Ȃ��B���킪��ꂽ��";
		}
		mes "2�x�Ǝg���Ȃ��Ȃ�c����ł�";
		mes "���B������C�Ȃ̂��H";
		next;
		if(select("�͂�","������")==2) {
			mes "["+getarg(0)+"]";
			mes "�ǂ��I�����B";
			mes "�����������đ��l�̕�����󂵂���";
			mes "�C���������Ȃ邩��c";
			return;
		}
	}
	if(countitem(.itemid[.@wlv])<1 || Zeny<.price[.@wlv]) {
		mes "["+getarg(0)+"]";
		mes "���ꂪ���������Ă�S�����H";
		mes "�c�O�����A�ޗ�������Ȃ��Ȃ��";
		mes "�d�����Ȃ��B";
		mes "���͂����ł���Ă���������ق�";
		mes "�S���L���Ȃ��B";
		return;
	}
	delitem .itemid[.@wlv],1;
	set Zeny,Zeny-.price[.@wlv];
	mes "["+getarg(0)+"]";
	mes "�J���I �J���I �J��!!";
	if(getequippercentrefinery2(.@i) > rand(100)) {
		successrefitem2 .@i;
		next;
		emotion getarg(1);
		mes "["+getarg(0)+"]";
		mes "�����A�o�����I";
		mes "�v�X�ɗǂ������ł����ȁB";
		mes "��������Ȃ��ē����������낤�H";
	}
	else {
		failedrefitem2 .@i;
		next;
		emotion getarg(2);
		mes "["+getarg(0)+"]";
		mes "�c�c�c";
		next;
		mes "["+getarg(0)+"]";
		mes "���܂Ȃ��c";
		mes "���B���ɕ�����Ă��܂����c";
		mes "�������A�ŏ��ɒ����͂������H";
	}
	return;
	//close�ŏI��
}

//=====================================================================
//����BNPC�Z���t�p�^�[��4
//	�i�v�����e���j
//  callfunc "Refine4","NPCName",SuccessEmotion,FalureEmotion;
//--------------------------------------------------------------------

function	script	Refine4	{
	mes "["+getarg(0)+"]";
	mes "���͕���Ɩh��𐸘B����b�艮���I";
	mes "���O���������Ă���A�C�e����";
	mes "���B�ł�����Ă킯���B";
	mes "�������A�Z�k�I���f�I�R����";
	mes "�Z�k�G���j�E�����K�v�����B";
	mes "�ǂ̑����A�C�e���𐸘B�������H";
	next;
	set .@i,select(getequipname2(1),getequipname2(2),getequipname2(3),getequipname2(4),getequipname2(5),
				getequipname2(6),getequipname2(7),getequipname2(8),getequipname2(9),getequipname2(10));
	mes "["+getarg(0)+"]";
	if(getequipisequiped2(.@i)==0) {
		switch(.@i) {
		case 1:
			mes "���O�̈������𐸘B���Ă����悤���H";
			break;
		case 2:
			mes "���̔M���̂ł��O�̑̂�";
			mes "���B���Ă����邺�B";
			break;
		case 3:
			mes "�c�O�Ȃ���A���O�̍����";
			mes "���P�b�g�p���`�ɂ���\�͂͂Ȃ��ˁB";
			break;
		case 4:
			mes "����Ȋw�Z�p�ł����O�̉E���";
			mes "���P�b�g�p���`�ɂ��鎖�͂ł��Ȃ����B";
			break;
		case 5:
			mes "�����Ă��郍�[�u���Ȃ�����Ȃ����H";
			break;
		case 6:
			mes "���O�A���̂ɂ������������ˁB";
			break;
		case 7:
		case 8:
			mes "�ǂ̃A�N�Z�T���[�������Ă�񂾂�H";
			break;
		case 9:
			mes "���𐸘B���Ăق����񂾁H";
			mes "���������āA���̑��̏��H";
			break;
		case 10:
			mes "���O�̓��W���𐸘B���Ă�낤���H";
			break;
		}
		return;
	}
	if(getequipisenableref2(.@i)==0) {
		mes "�ӂށA����͐��B�ł���";
		mes "�A�C�e������Ȃ��񂾂��c�c";
		return;
	}
	if(getequipisidentify(.@i)==0) {
		mes "���Ӓ肾���琸�B�ł��Ȃ��ȁB";
		return;
	}
	if(getequiprefinerycnt2(.@i)>=10) {
		mes "����ȏ�͐��B�ł��Ȃ��ȁB";
		return;
	}
	set .@id, getequipid2(.@i);
	//����Ăяo�����̂ݗ����ƃA�C�e��ID�����ꂼ��i�[
	if(.price[0]==0) {
		setarray .price,5000,100,500,5000,10000;
		setarray .itemid,7619,7620,7620,7620,7620;
	}
	set .@wlv,getequipweaponlv2(.@i);
	switch(.@wlv) {
	case 0:
		mes "���O���I�񂾑�����";
		mes "���B���邽�߂ɂ�";
		mes "^FF9C9C�Z�k�G���j�E��^000000��";
		mes "�萔��5000Zeny���K�v�����H";
		mes "���B���邩�H";
		break;
	case 1:
		mes "���x��1�̕����";
		mes "���B���悤�Ƃ��Ă�񂾂ˁB";
		mes "���B�̂��߂ɂ�";
		mes "^FF9C9C�Z�k�I���f�I�R��^000000��";
		mes "�萔��100Zeny���K�v�����H";
		mes "���B���邩�H";
		break;
	case 2:
		mes "���x��2�̕����";
		mes "���B���悤�Ƃ��Ă�񂾂ˁB";
		mes "���B�̂��߂ɂ�";
		mes "^FF9C9C�Z�k�I���f�I�R��^000000��";
		mes "�萔��500Zeny���K�v�����H";
		mes "���B���邩�H";
		break;
	case 3:
		mes "���x��3�̕����";
		mes "���B���悤�Ƃ��Ă�񂾂ˁB";
		mes "���B�̂��߂ɂ�";
		mes "^FF9C9C�Z�k�I���f�I�R��^000000��";
		mes "�萔��5000Zeny���K�v�����H";
		mes "���B���邩�H";
		break;
	case 4:
		mes "���x��4�̕����";
		mes "���B���悤�Ƃ��Ă�񂾂ˁB";
		mes "���B�̂��߂ɂ�";
		mes "^FF9C9C�Z�k�I���f�I�R��^000000��";
		mes "�萔��10000Zeny���K�v�����H";
		mes "���B���邩�H";
		break;
	}
	next;
	if(select("�͂�","������")==2) {
		mes "["+getarg(0)+"]";
		mes "���O�����₾������d���Ȃ����ȁB";
		return;
	}
//	// �Z�k�ۋ��A�C�e�����B�e�[�u��
//	switch(.@wlv) {
//	case 0: setarray .@parcent,100,100,100,100, 90, 60, 60, 30, 30, 10; break;
//	case 1: setarray .@parcent,100,100,100,100,100,100,100, 90, 60, 20; break;
//	case 2: setarray .@parcent,100,100,100,100,100,100, 90, 60, 30, 20; break;
//	case 3: setarray .@parcent,100,100,100,100,100, 90, 75, 30, 30, 20; break;
//	case 4: setarray .@parcent,100,100,100,100, 90, 60, 60, 30, 30, 10; break;
//	}
//	if(.@parcent[getequiprefinerycnt2(.@i)] < 100) {
	while (1) {
		if(getequipid2(.@i) != .@id ||
			getequiprefinerycnt2(.@i)>=10
		) return;
		if(getequippercentrefinery2(.@i, 1) < 100) {
			mes "["+getarg(0)+"]";
			if(.@wlv==0) {	//�h��̂Ƃ�
				mes "�����I";
				mes "���̖h��͂���";
				mes "��������B���ꂿ������ˁB";
				mes "����ȏ㐸�B�����";
//				mes "�h���ꂿ�Ⴄ";
				mes "�h��򉻂��鋰�ꂪ����c�c";
				//next;
				//mes "["+getarg(0)+"]";
				//mes "�h���ꂿ�Ⴄ��";
				//mes "��x�Ǝg���Ȃ��񂾂�?!";
				//mes "���ɑł����܂ꂽ�J�[�h��������";
				//mes "^FF0000���ׂĂ��������Ⴄ^000000�񂾂���ˁB";
				//mes "^FF0000�h��̂��������Ⴄ^000000���Ă킯���B";
				mes "����ł����B������肩�H";
			} else {		//����̂Ƃ�
				mes "�����I";
				mes "���̕���͂���";
				mes "��������B���ꂿ������ˁB";
				mes "����ȏ㐸�B�����";
//				mes "���킪��ꂿ�Ⴄ";
				mes "���킪�򉻂��鋰�ꂪ����c�c";
				//next;
				//mes "["+getarg(0)+"]";
				//mes "���킪��ꂿ�Ⴄ��";
				//mes "��x�Ǝg���Ȃ��񂾂�?!";
				//mes "���ɑł����܂ꂽ�J�[�h��������";
				//mes "^FF0000���ׂĂ��������Ⴄ^000000�񂾂���ˁB";
				//mes "^FF0000���펩�̂��������Ⴄ^000000���Ă킯���B";
				mes "����ł����B������肩�H";
			}
			next;
			if(select("�͂�","������")==2) {
				mes "["+getarg(0)+"]";
				mes "�������ȁA���͑�؂Ɉ����ׂ�������ȁB";
				return;
			}
		}
		if(getequipid2(.@i) != .@id ||
			getequiprefinerycnt2(.@i)>=10
		) return;
		if(countitem(.itemid[.@wlv])<1 || Zeny<.price[.@wlv]) {
			mes "["+getarg(0)+"]";
			mes "���ꂪ���O�������Ă邷�ׂĂ��H";
			mes "�c�O�����ǁA�ޗ�������Ȃ���";
			mes "���B���Ă������Ȃ����B";
			mes "�����d���������㉿���炢";
			mes "���Ȃ��Ƃȁc�c�B";
			return;
		}
		delitem .itemid[.@wlv],1;
		set Zeny,Zeny-.price[.@wlv];
		mes "["+getarg(0)+"]";
		mes "�J���I �J���I �J���I";
//		if(.@parcent[getequiprefinerycnt2(.@i)] > rand(100)) {
		if(getequippercentrefinery2(.@i, 1) > rand(100)) {
			successrefitem2 .@i;
			next;
			emotion getarg(1);
			mes "["+getarg(0)+"]";
			mes "���I �����ɐ��B���I��������B";
			mes "���̘r�͂܂��g���邺�I";
			mes "�����Ō����̂��Ȃ񂾂��A";
			mes "�Ȃ��Ȃ��ǂ��o������Ȃ����I";
			if(getequiprefinerycnt2(.@i)>=10) return;
		}
		else {
			failedrefitem3 .@i;
			next;
			emotion getarg(2);
			//mes "["+getarg(0)+"]";
			//mes "�E�A�A�A�A�A�A�A�A�A�A�b!!!!";
			//next;
			mes "["+getarg(0)+"]";
			mes "���A����c�c";
			mes "���s����������B���A���߂�c�c";
			//mes "��������ꂿ������ȁc�c";
			//mes "���A�����炳�c�c";
			//mes "��Ȃ����Č���������Ȃ����c�c";
			//mes "�������܂Ȃ��ł���c�c";
			mes "�܁A�܂��A�ł��c�c";
			mes "������Ɨ򉻂���������";
			mes "��ꂿ�Ⴂ�Ȃ�����ȁc�c";
		}
		mes "�܂����B���邩���H";
		next;
		if(select("�͂�","������")==2) {
			mes "[" +strnpcinfo(1)+ "]";
			mes "���������c�c";
			mes "�܂����Ă����B";
			return;
		}
	}
	return;
	//close�ŏI��
}

function	script	Refine5	{
	mes "["+getarg(0)+"]";
	mes "���͕���Ɩh��𐸘B����b�艮���I";
	mes "���O���������Ă���A�C�e����";
	mes "���B�ł�����Ă킯���B";
	mes "�������A���ǌ^�Z�k�I���f�I�R����";
	mes "���ǌ^�Z�k�G���j�E�����K�v�����B";
	mes "�ǂ̑����A�C�e���𐸘B�������H";
	next;
	set .@i,select(getequipname2(1),getequipname2(2),getequipname2(3),getequipname2(4),getequipname2(5),
				getequipname2(6),getequipname2(7),getequipname2(8),getequipname2(9),getequipname2(10));
	mes "["+getarg(0)+"]";
	if(getequipisequiped2(.@i)==0) {
		switch(.@i) {
		case 1:
			mes "���O�̈������𐸘B���Ă����悤���H";
			break;
		case 2:
			mes "���̔M���̂ł��O�̑̂�";
			mes "���B���Ă����邺�B";
			break;
		case 3:
			mes "�c�O�Ȃ���A���O�̍����";
			mes "���P�b�g�p���`�ɂ���\�͂͂Ȃ��ˁB";
			break;
		case 4:
			mes "����Ȋw�Z�p�ł����O�̉E���";
			mes "���P�b�g�p���`�ɂ��鎖�͂ł��Ȃ����B";
			break;
		case 5:
			mes "�����Ă��郍�[�u���Ȃ�����Ȃ����H";
			break;
		case 6:
			mes "���O�A���̂ɂ������������ˁB";
			break;
		case 7:
		case 8:
			mes "�ǂ̃A�N�Z�T���[�������Ă�񂾂�H";
			break;
		case 9:
			mes "���𐸘B���Ăق����񂾁H";
			mes "���������āA���̑��̏��H";
			break;
		case 10:
			mes "���O�̓��W���𐸘B���Ă�낤���H";
			break;
		}
		return;
	}
	if(getequipisenableref2(.@i)==0) {
		mes "�ӂށA����͐��B�ł���";
		mes "�A�C�e������Ȃ��񂾂��c�c";
		return;
	}
	if(getequipisidentify(.@i)==0) {
		mes "���Ӓ肾���琸�B�ł��Ȃ��ȁB";
		return;
	}
	if(getequiprefinerycnt2(.@i)>=10) {
		mes "����ȏ�͐��B�ł��Ȃ��ȁB";
		return;
	}
	set .@id, getequipid2(.@i);
	//����Ăяo�����̂ݗ����ƃA�C�e��ID�����ꂼ��i�[
	if(.price[0]==0) {
		setarray .price,100000,2000,10000,100000,200000;
		setarray .itemid,6241,6240,6240,6240,6240;
	}
	set .@wlv,getequipweaponlv2(.@i);
	switch(.@wlv) {
	case 0:
		mes "���O���I�񂾑�����";
		mes "���B���邽�߂ɂ�";
		mes "^FF9C9C���ǌ^�Z�k�G���j�E��^000000��";
		mes "�萔��100000Zeny���K�v�����H";
		mes "���B���邩�H";
		break;
	case 1:
		mes "���x��1�̕����";
		mes "���B���悤�Ƃ��Ă�񂾂ˁB";
		mes "���B�̂��߂ɂ�";
		mes "^FF9C9C���ǌ^�Z�k�I���f�I�R��^000000��";
		mes "�萔��2000Zeny���K�v�����H";
		mes "���B���邩�H";
		break;
	case 2:
		mes "���x��2�̕����";
		mes "���B���悤�Ƃ��Ă�񂾂ˁB";
		mes "���B�̂��߂ɂ�";
		mes "^FF9C9C���ǌ^�Z�k�I���f�I�R��^000000��";
		mes "�萔��10000Zeny���K�v�����H";
		mes "���B���邩�H";
		break;
	case 3:
		mes "���x��3�̕����";
		mes "���B���悤�Ƃ��Ă�񂾂ˁB";
		mes "���B�̂��߂ɂ�";
		mes "^FF9C9C���ǌ^�Z�k�I���f�I�R��^000000��";
		mes "�萔��100000Zeny���K�v�����H";
		mes "���B���邩�H";
		break;
	case 4:
		mes "���x��4�̕����";
		mes "���B���悤�Ƃ��Ă�񂾂ˁB";
		mes "���B�̂��߂ɂ�";
		mes "^FF9C9C���ǌ^�Z�k�I���f�I�R��^000000��";
		mes "�萔��200000Zeny���K�v�����H";
		mes "���B���邩�H";
		break;
	}
	next;
	if(select("�͂�","������")==2) {
		mes "["+getarg(0)+"]";
		mes "���O�����₾������d���Ȃ����ȁB";
		return;
	}
	while (1) {
		if(getequipid2(.@i) != .@id ||
			getequiprefinerycnt2(.@i)>=10
		) return;
		if(getequippercentrefinery2(.@i, 1) < 100) {
			mes "["+getarg(0)+"]";
			if(.@wlv==0) {	//�h��̂Ƃ�
				mes "�����I";
				mes "���̖h��͂���";
				mes "��������B���ꂿ������ˁB";
				mes "����ȏ㐸�B�����";
				mes "���s���鋰�ꂪ����c�c";
				next;
				mes "["+getarg(0)+"]";
				mes "�܂��A���Ƃ����s���Ă�";
				mes "�h���ꂿ�Ⴄ���Ƃ͂Ȃ���";
				mes "�򉻂���������Ȃ����ǂȁB";
				mes "���Ⴀ�A���B���Ă��������H";
			} else {		//����̂Ƃ�
				mes "�����I";
				mes "���̕���͂���";
				mes "��������B���ꂿ������ˁB";
				mes "����ȏ㐸�B�����";
				mes "���s���鋰�ꂪ����c�c";
				next;
				mes "["+getarg(0)+"]";
				mes "�܂��A���Ƃ����s���Ă�";
				mes "���킪��ꂿ�Ⴄ���Ƃ͂Ȃ���";
				mes "�򉻂���������Ȃ����ǂȁB";
				mes "���Ⴀ�A���B���Ă��������H";
			}
			next;
			if(select("�͂�","������")==2) {
				mes "["+getarg(0)+"]";
				mes "�������ȁA���ǌ^�͋M�d������ȁB";
				return;
			}
		}
		if(getequipid2(.@i) != .@id ||
			getequiprefinerycnt2(.@i)>=10
		) return;
		if(countitem(.itemid[.@wlv])<1 || Zeny<.price[.@wlv]) {
			mes "["+getarg(0)+"]";
			mes "���ꂪ���O�������Ă邷�ׂĂ��H";
			mes "�c�O�����ǁA�ޗ�������Ȃ���";
			mes "���B���Ă������Ȃ����B";
			mes "�����d���������㉿���炢";
			mes "���Ȃ��Ƃȁc�c�B";
			return;
		}
		delitem .itemid[.@wlv],1;
		set Zeny,Zeny-.price[.@wlv];
		mes "["+getarg(0)+"]";
		mes "�J���I �J���I �J���I";
		if(getequippercentrefinery2(.@i, 1) > rand(100)) {
			successrefitem2 .@i;
			next;
			emotion getarg(1);
			mes "["+getarg(0)+"]";
			mes "���I �����ɐ��B���I��������B";
			mes "���̘r�͂܂��g���邺�I";
			mes "�����Ō����̂��Ȃ񂾂��A";
			mes "�Ȃ��Ȃ��ǂ��o������Ȃ����I";
			if(getequiprefinerycnt2(.@i)>=10) return;
		}
		else {
			failedrefitem4 .@i;
			next;
			emotion getarg(2);
			mes "["+getarg(0)+"]";
			mes "���A����c�c";
			mes "���s����������B���A���߂�c�c";
			mes "�܁A�܂��A�ł��c�c";
			mes "�����ɕω��͂Ȃ�����ȁc�c";
		}
		mes "�܂����B���邩���H";
		next;
		if(select("�͂�","������")==2) {
			mes "[" +strnpcinfo(1)+ "]";
			mes "���������c�c";
			mes "�܂����Ă����B";
			return;
		}
	}
	return;
	//close�ŏI��
}
//==============================================================================
// RagnarokOnline Original Refine Script Ver0.5   by Blaze
//==============================================================================
prt_in,56,56,0	script	�����]�E#Refine	85,{
//	********** �����ݒ� **********
//	�e���B���ɕK�v�ȕ��B������ �h��,Lv1����,Lv2����,Lv3����,Lv4����
	if(.price[0] == 0) {
//		setarray .price,20000,500,2000,25000,50000;	//�l�i�iZeny�j
		setarray .price,5000,100,500,5000,10000;
		setarray .itemid,985,1010,1011,984,984;		//����A�C�e���iID�w��j
	}
//	********** �����܂� **********
	mes "[" +strnpcinfo(1)+ "]";
	mes "���͕���Ɩh���";
	mes "�A���Ő��B����b�艮���B";
	mes "�N���������Ă���A�C�e���̒���";
	mes "�D���Ȃ��̂𐸘B�ł���̂��B";
	mes "�ǂ̑����A�C�e����";
	mes "�A���Ő��B�������񂾂��H";
	next;
	set .@pos,select(getequipname2(1),getequipname2(2),getequipname2(3),getequipname2(4),getequipname2(5),
				getequipname2(6),getequipname2(7),getequipname2(8),getequipname2(9),getequipname2(10));
	mes "[" +strnpcinfo(1)+ "]";
	if(getequipisequiped2(.@pos) == 0) {
		mes "�����������ĂȂ��悤�����H";
		mes "�������Ă���܂����Ă���B";
		close;
	}
	if(getequipisenableref2(.@pos) == 0) {
		mes "���̃A�C�e���͐��B�s�\���B";
		close;
	}
	if(getequipisidentify(.@pos) == 0) {
		mes "����͖��Ӓ肾���琸�B�ł��Ȃ��B";
		close;
	}
	if(getequiprefinerycnt2(.@pos) >= 10) {
		mes "����ȏ�͐��B�ł��Ȃ����B";
		close;
	}
	set .@wlv,getequipweaponlv2(.@pos);
	mes "�N���I�񂾑����𐸘B����ɂ�";
	mes "+1�ɂ��A^3131FF" +getitemname(.itemid[.@wlv])+ "^000000��";
	mes "�萔��^3131FF" +.price[.@wlv]+ "Zeny^000000���K�v���ȁB";
	mes "�ǂꂾ�����B����񂾂��H";
	next;
	if(getequippercentrefinery2(.@pos) == 100)
		set .@word$[0],"���S���܂Ő��B";
	for(set .@i,10; .@i > getequiprefinerycnt2(.@pos); set .@i,.@i-1)
		set .@word$[.@i],"+" +.@i+ " �܂Ő��B";
	if(select("1�񂸂��B",.@word$[0],.@word$[1],.@word$[2],.@word$[3],
			.@word$[4],.@word$[5],.@word$[6],.@word$[7],.@word$[8],.@word$[9],.@word$[10]) >= 3)
		set .@cnt,@menu-getequiprefinerycnt2(.@pos)-3;
	else {
		set .@cnt,10;
		if(@menu == 2)
			set .@flag,1;	//���S���t���O�Z�b�g
	}
	for(set .@i,0; .@i <= .@cnt; set .@i,.@i+1) {
		if(getequiprefinerycnt2(.@pos) >= 10)
			break;
		if(.@flag && getequippercentrefinery2(.@pos) < 100)	//���S���t���O�̎�
			break;
		if(countitem(.itemid[.@wlv]) < 1 || Zeny < .price[.@wlv]) {
			emotion 9;
			mes "[" +strnpcinfo(1)+ "]";
			mes "�����ƁA�ޗ�������Ȃ��ȁB";
			mes getitemname(.itemid[.@wlv])+ "�̐��Ə�������";
			mes "�����Ɗm�F���Ă����B";
			close;
		}
		mes "[" +strnpcinfo(1)+ "]";
		mes "���̐��B�l�� ^3131FF+" +getequiprefinerycnt2(.@pos)+ " ^000000���B";
		if(getequippercentrefinery2(.@pos) < 100) {
			mes "^FF0000����ȏ㐸�B�����";
			mes "���������邩������Ȃ����A^000000";
		}
		mes "�܂����B���邩���H";
		next;
		if(select("�͂�","������")==2) {
			mes "[" +strnpcinfo(1)+ "]";
			mes "���������c�c";
			mes "�܂����Ă����B";
			close;
		}
		delitem .itemid[.@wlv],1;
		set Zeny,Zeny-.price[.@wlv];
		if(getequippercentrefinery2(.@pos) > rand(100)) {
			successrefitem2 .@pos;
			continue;
		}
		else {
			failedrefitem2 .@pos;
			emotion 23;
			mes "[" +strnpcinfo(1)+ "]";
			mes "�N�z�z�z�z�c�c";
			next;
			mes "[" +strnpcinfo(1)+ "]";
			mes "���܂�I";
			mes "���������Ă��܂����ȁc�c";
			mes "�c�c����ɒ��肸��";
			mes "�܂����Ă����ȁA�ȁH";
			close;
		}
	}
	emotion 21;
	mes "[" +strnpcinfo(1)+ "]";
	mes "�����A�o���������I";
	mes "�v�X�ɗǂ������ł����B";
	mes "��������Ȃ��ČN������������H";
	close;
}

prt_in,54,56,0	script	�J�c�I#Refine	85,{
	if(.price[0] == 0) {
		setarray .price,5000,100,500,5000,10000;
		setarray .itemid,985,1010,1011,984,984;		//����A�C�e���iID�w��j
	}
	mes "[" +strnpcinfo(1)+ "]";
	mes "���͕���Ɩh���";
	mes "�ꊇ�Ő��B����b�艮���B";
	mes "�N���������Ă���A�C�e���̒���";
	mes "�D���Ȃ��̂𐸘B�ł���̂��B";
	mes "�ǂ̑����A�C�e����";
	mes "�ꊇ�Ő��B�������񂾂��H";
	next;
	set .@pos,select(getequipname2(1),getequipname2(2),getequipname2(3),getequipname2(4),getequipname2(5),
				getequipname2(6),getequipname2(7),getequipname2(8),getequipname2(9),getequipname2(10));
	if(getequipisequiped2(.@pos) == 0) {
		mes "[" +strnpcinfo(1)+ "]";
		mes "�����������ĂȂ��悤�����H";
		mes "�������Ă���܂����Ă���B";
		close;
	}
	if(getequipisenableref2(.@pos) == 0) {
		mes "[" +strnpcinfo(1)+ "]";
		mes "���̃A�C�e���͐��B�s�\���B";
		close;
	}
	if(getequipisidentify(.@pos) == 0) {
		mes "[" +strnpcinfo(1)+ "]";
		mes "����͖��Ӓ肾���琸�B�ł��Ȃ��B";
		close;
	}
	if(getequiprefinerycnt2(.@pos) >= 10) {
		mes "[" +strnpcinfo(1)+ "]";
		mes "����ȏ�͐��B�ł��Ȃ����B";
		close;
	}
	set .@wlv,getequipweaponlv2(.@pos);
	set .@id, getequipid2(.@pos);
	getinventorylist;
	set .@cou, 0;
	for (set .@i, 0; .@i < @inventorylist_count; ++.@i) {
		if (@inventorylist_id[.@i] == .@id &&
			@inventorylist_identify[.@i] &&
			!@inventorylist_attribute[.@i] &&
			@inventorylist_refine[.@i] < 10
		) ++.@cou;
	}
	set .@tot_pri, .price[.@wlv] * .@cou;
	mes "[" +strnpcinfo(1)+ "]";
	mes "�N���I�񂾑������ꊇ���B����ɂ�";
	mes "�S����^3131FF" +getitemname(.itemid[.@wlv])+ "^000000��^3131FF" + .@cou + "��^000000��";
	mes "�萔��^3131FF" + .@tot_pri + "Zeny^000000���K�v���ȁB";
	mes "���Ⴀ�n�߂邪�A�p�ӂ͂������H";
	next;
	if (select("�͂�", "������") == 2) {
		mes "[" +strnpcinfo(1)+ "]";
		mes "���������c�c";
		mes "�܂����Ă����B";
		close;
	}
	
	// �A�g�~�b�N
	getinventorylist;
	set .@cou, 0;
	for (set .@i, 0; .@i < @inventorylist_count; ++.@i) {
		if (@inventorylist_id[.@i] == .@id &&
			@inventorylist_identify[.@i] &&
			!@inventorylist_attribute[.@i] &&
			@inventorylist_refine[.@i] < 10
		) ++.@cou;
	}
	set .@tot_pri, .price[.@wlv] * .@cou;
	if(countitem(.itemid[.@wlv]) < .@cou || 
		Zeny < .@tot_pri
	) {
		emotion 9;
		mes "[" +strnpcinfo(1)+ "]";
		mes "�����ƁA�ޗ�������Ȃ��ȁB";
		mes getitemname(.itemid[.@wlv])+ "�̐��Ə�������";
		mes "�����Ɗm�F���Ă����B";
		close;
	}
	for (set .@i, 0; .@i < @inventorylist_count; ++.@i) {
		if (@inventorylist_id[.@i] == .@id &&
			@inventorylist_identify[.@i] &&
			!@inventorylist_attribute[.@i] &&
			@inventorylist_refine[.@i] < 10
		) {
			if (equip2(@inventorylist_index[.@i], .@pos)) {
				delitem .itemid[.@wlv], 1;
				set Zeny, Zeny - .price[.@wlv];
				if (getequippercentrefinery2(.@pos) > rand(100)) {
					successrefitem2 .@pos, 0;
					++.@suc;
				} else {
					failedrefitem2 .@pos, 0;
					++.@fai;
				}
			}
		}
	}
	
	if (.@suc) specialeffect2 EF_REFINEOK;
	if (.@fai) specialeffect2 EF_REFINEFAIL;
	mes "[" +strnpcinfo(1)+ "]";
	mes "�悵�A�I��������I";
	mes "������^3131FF" + .@suc + "��^000000�A���s��^FF3131" + .@fai + "��^000000���B";
	mes "���[�A��ꂽ�B";
	close;
}

//==============================================================================
//���₵�������͈ȉ��̂悤�ɐݒ�
//morocc_in,63,39,4	duplicate(�A���b�艮#Refine)	�A���b�艮	88
//payon,140,174,5	duplicate(�A���b�艮#Refine)	�A���b�艮	59

// ----- �A���x���^ -----
alberta_in,28,58,4	script	�t���h���b�N	85,{
	callfunc "Refine1","�t���h���b�N�w���}���\��",18,4;
	close;
}
// ----- �v�����e�� -----
prt_in,63,60,0	script	�z���O����	85,{
	callfunc "Refine1","�z���O����",21,23;
	close;
}
// ----- �����N -----
morocc_in,73,38,4	script	�A���K��	99,{
	callfunc "Refine3","�A���K���T���[",30,16;
	close;
}
// ----- �t�F�C���� -----
payon,144,173,5	script	�A���g�j�I	88,{
	callfunc "Refine2","�A���g�j�I",0,32;
	close;
}
// ----- �W���m�[ -----
yuno_in01,171,21,4	script	�f�B�X�^�[�u	85,{
	callfunc "Refine2","�f�B�X�^�[�u",9,0;
	close;
}
// ----- �A�C���u���b�N -----
ein_in01,24,87,5	script	�}���_�X�}��	826,{
	callfunc "Refine1","�}���_�X�}��",18,4;
	close;
}

// ----- �v�����e�� -----
prontera,164,173,2	script	�t�����c	85,{
	callfunc "Refine4","�t�����c",21,23;
	close;
}

// ----- �v�����e�� -----
prontera,164,169,2	script	���B���w����	85,{
	callfunc "Refine5","���B���w����",21,23;
	close;
}

//====================================================================
//���B�Δ̔�NPC
//--------------------------------------------------------------------

-	script	BuyStone	-1,{
	if(checkitemblank()==0) {
		mes "- �����A�C�e���̎�ސ��� -";
		mes "- �������߁A�A�C�e�����󂯂Ƃ� -";
		mes "- ���Ƃ��ł��܂���B -";
		mes "- �����A�C�e�������炵�Ă��� -";
		mes "- �ēx�b�������Ă��������B -";
		close;
	}
	mes "["+strnpcinfo(0)+"]";
	mes "�S��|�S�̕���𐸘B���鎞��";
	mes "�g��������𔄂��Ă��܂��B";
	mes "1���x���̕��퐸�B�Ɏg����";
	mes "^007777�v���R��^000000��";
	mes "2���x���̕��퐸�B�Ɏg����";
	mes "^007777�G���x���^�R��^000000������܂��B";
	next;
	mes "["+strnpcinfo(0)+"]";
	mes "�v���R����1��200Zeny�A";
	mes "�G���x���^�R����";
	mes "1��1000Zeny�ł��B";
	next;
	switch (select("�v���R���w��","�G���x���^�R���w��","���̋����͂Ȃ��������Ă݂�")) {
	case 1:
		set .@price,200;
		set .@itemid,1010;
		break;
	case 2:
		set .@price,1000;
		set .@itemid,1011;
		break;
	case 3:
		mes "["+strnpcinfo(0)+"]";
		mes "1���x����2���x���̕�����";
		mes "���x������������𐸘B���邽�߂�";
		mes "�����ł��ˁB";
		mes "���������m��������܂��񂪁A";
		mes "�I���f�I�R���ƃG���j�E����";
		mes "��ɓ����̂�����������Ăˁc";
		close;
	}
	mes "["+strnpcinfo(0)+"]";
	mes "�����w�����܂����H";
	mes "�������𒆎~���������";
	mes "�u0�v�ł��肢���܂��B";
	while(1) {
		next;
		input .@num;
		if(.@num<=0) {
			mes "["+strnpcinfo(0)+"]";
			mes "������~�ł��ˁB";
			close;
		}
		if(.@num>500) {
			mes "["+strnpcinfo(0)+"]";
			mes "500�ȉ��Ō��߂Ă��������B";
			continue;
		}
		break;	//while��������
	}
	if(Zeny<.@price*.@num) {
		mes "["+strnpcinfo(0)+"]";
		mes "����H���q����c";
		mes "����������܂���ˁB";
		mes "���݂܂��񂪁A����������������";
		mes "������킯�ɂ͂����Ȃ���ł���B";
		close;
	}
	if(checkweight(.@itemid,.@num)==0) {
		mes "["+strnpcinfo(0)+"]";
		mes "�ו��������ł��ˁB";
		mes "�������𐮗����Ă���";
		mes "�܂����������������B";
		close;
	}
	set Zeny,Zeny-.@price*.@num;
	getitem .@itemid,.@num;
	mes "["+strnpcinfo(0)+"]";
	mes "���w���A���肪�Ƃ��������܂����B";
	close;
}

alberta_in,13,71,4	duplicate(BuyStone)	�J���}�����X	86
//prt_in,56,68,4	duplicate(BuyStone)	�u���E�F��	86
prt_in,62,70,4	duplicate(BuyStone)	�u���E�F��	86
morocc_in,63,32,0	duplicate(BuyStone)	�T�h		99
payon,145,178,4	duplicate(BuyStone)	�x�O�i�h	88
yuno_in01,171,27,4	duplicate(BuyStone)	�e�B�����}	86
ein_in01,15,87,4	duplicate(BuyStone)	�e�B���C�n�[�X	86


//====================================================================
//���B�Ό���NPC
//--------------------------------------------------------------------

-	script	ChangeStone	-1,{
	if(checkitemblank()==0) {
		mes "- �����A�C�e���̎�ސ��� -";
		mes "- �������߁A�A�C�e�����󂯂Ƃ� -";
		mes "- ���Ƃ��ł��܂���B -";
		mes "- �����A�C�e�������炵�Ă��� -";
		mes "- �ēx�b�������Ă��������B -";
		close;
	}
	mes "["+strnpcinfo(3)+"]";	//���ʎq���Q��
	mes "�I���f�I�R����G���j�E���̌��΂�";
	mes "�l�Ɏ����Ă�����A������";
	mes "�I���f�I�R���ƃG���j�E���ɂ��Ă�����B";
	mes "�A���A���΂͊e5�ȏ㎝���Ă���悤�ɁB";
	next;
	switch (select("�I���f�I�R�������","�G���j�E�������","�����΂ɂ��ĕ���")) {
	case 1:
		set .@itemid,756;
		set .@gain,984;
		break;
	case 2:
		set .@itemid,757;
		set .@gain,985;
		break;
	case 3:
		mes "["+strnpcinfo(3)+"]";
		mes "�����΂˂��c";
		mes "���̋������B�l��20�N��";
		mes "�b�͂悭���������ǎ��ۂɂ�";
		mes "�������Ƃ͂Ȃ��ȁB";
		mes "�����Ƃ���ɂ��ƁA������";
		mes "�΁A���A�n�A���̑��������炵���B";
		next;
		mes "["+strnpcinfo(3)+"]";
		mes "���̑����΂𕐊����鎞��";
		mes "��������΁A�������������";
		mes "����Ƃ����c";
		mes "�͂́c����Ȃ��Ƃ��ł���̂�";
		mes "�����Ȑ��B�E�l���낤�ˁB";
		close;
	}
	if(countitem(.@itemid)<5) {
		mes "["+strnpcinfo(3)+"]";
		mes "���H��k�ł���H";
		mes getitemname(.@itemid)+ "��5�ȏ㖳����";
		mes getitemname(.@gain)+ "�����Ȃ��ƌ���������Ȃ����B";
		close;
	}
	mes "["+strnpcinfo(3)+"]";
	mes getitemname(.@gain)+ "�����ʂ͂ǂ�����H";
	next;
	if(select("1���������","���邾�����")==1) {
		if(checkweight(.@gain,1)==0) {
			mes "�]�����A�C�e���̏d�ʂ��d����";
			mes "�@�댯�ł��B";
			mes "�@�����A�C�e�������炵�Ă���A";
			mes "�@�ēx�b�������Ă��������]";
			close;
		}
		if(countitem(.@itemid)<5) close;
		delitem .@itemid,5;
		getitem .@gain,1;
		mes "["+strnpcinfo(3)+"]";
		mes "�ق�A�񑩂�" +getitemname(.@gain)+ "���B";
		mes "���ł��܂����Ă���B";
		close;
	}
	set .@num,countitem(.@itemid)/5;
	mes "["+strnpcinfo(3)+"]";
	mes getitemname(.@itemid)+ "^FF0000" +(.@num*5)+ "^000000��";
	mes getitemname(.@gain)+ "^FF0000" +.@num+ "^000000���΂����H";
	next;
	if(select("����ς��߂܂�","���肢���܂�")==1) {
		mes "["+strnpcinfo(3)+"]";
		mes "���ł��܂����Ă���B";
		close;
	}
	if(checkweight(.@gain,.@num)==0) {
		mes "�]�����A�C�e���̏d�ʂ��d����";
		mes "�@�댯�ł��B";
		mes "�@�����A�C�e�������炵�Ă���A";
		mes "�@�ēx�b�������Ă��������]";
		close;
	}
	if(countitem(.@itemid)<.@num*5) close;
	delitem .@itemid,.@num*5;
	getitem .@gain,.@num;
	mes "["+strnpcinfo(3)+"]";
	mes "�ق�A�񑩂�" +getitemname(.@gain)+ "���B";
	mes "���ł��܂����Ă���B";
	close;
}

alberta_in,21,63,5	duplicate(ChangeStone)	�[�m�t�H��::�[�m�t�H�� �]���^�X	84
//prt_in,63,69,4	duplicate(ChangeStone)	�f�B�[�g���q		84
prt_in,64,68,4	duplicate(ChangeStone)	�f�B�[�g���q		84
morocc_in,72,32,0	duplicate(ChangeStone)	�A�u�h�D��		99
payon,137,178,5	duplicate(ChangeStone)	�n�L��			88
yuno_in01,164,27,4	duplicate(ChangeStone)	�e�B�����C		84
ein_in01,18,82,5	duplicate(ChangeStone)	�}�e�B�V���^�C��	84


//====================================================================
//�Z�k���B�A�C�e������NPC
//--------------------------------------------------------------------

-	script	::ChangeEnrich	-1,{
	if(checkitemblank()==0) {
		mes "- �����A�C�e���̎�ސ��� -";
		mes "- �������߁A�A�C�e�����󂯂Ƃ� -";
		mes "- ���Ƃ��ł��܂���B -";
		mes "- �����A�C�e�������炵�Ă��� -";
		mes "- �ēx�b�������Ă��������B -";
		close;
	}
	mes "["+strnpcinfo(3)+"]";	//���ʎq���Q��
	mes "�I���f�I�R����G���j�E����";
	mes "�l�Ɏ����Ă�����A������";
	mes "�Z�k�I���f�I�R����Z�k�G���j�E����";
	mes "���Ă�����B";
	mes "�A���A�I���f�I�R����G���j�E����";
	mes "�e50�����Ă���悤�ɁB";
	next;
	switch (select("�Z�k�I���f�I�R�������","�Z�k�G���j�E�������","��߂�")) {
	case 1:
		set .@itemid,984;
		set .@gain,7620;
		break;
	case 2:
		set .@itemid,985;
		set .@gain,7619;
		break;
	case 3:
		mes "["+strnpcinfo(3)+"]";
		mes "���ł��܂����Ă���B";
		close;
	}
	if(countitem(.@itemid)<50) {
		mes "["+strnpcinfo(3)+"]";
		mes "���H��k�ł���H";
		mes getitemname(.@itemid)+ "��50������";
		mes getitemname(.@gain)+ "�����Ȃ���";
		mes "����������Ȃ����B";
		close;
	}
	mes "["+strnpcinfo(3)+"]";
	mes getitemname(.@gain)+ "�����ʂ͂ǂ�����H";
	next;
	if(select("1���������","���邾�����")==1) {
		if(checkweight(.@gain,1)==0) {
			mes "�]�����A�C�e���̏d�ʂ��d����";
			mes "�@�댯�ł��B";
			mes "�@�����A�C�e�������炵�Ă���A";
			mes "�@�ēx�b�������Ă��������]";
			close;
		}
		if(countitem(.@itemid)<50) close;
		delitem .@itemid,50;
		getitem .@gain,1;
		mes "["+strnpcinfo(3)+"]";
		mes "�ق�A�񑩂�" +getitemname(.@gain)+ "���B";
		mes "���ł��܂����Ă���B";
		close;
	}
	set .@num,countitem(.@itemid)/50;
	mes "["+strnpcinfo(3)+"]";
	mes getitemname(.@itemid)+ "^FF0000" +(.@num*50)+ "^000000��";
	mes getitemname(.@gain)+ "^FF0000" +.@num+ "^000000���΂����H";
	next;
	if(select("����ς��߂܂�","���肢���܂�")==1) {
		mes "["+strnpcinfo(3)+"]";
		mes "���ł��܂����Ă���B";
		close;
	}
	if(checkweight(.@gain,.@num)==0) {
		mes "�]�����A�C�e���̏d�ʂ��d����";
		mes "�@�댯�ł��B";
		mes "�@�����A�C�e�������炵�Ă���A";
		mes "�@�ēx�b�������Ă��������]";
		close;
	}
	if(countitem(.@itemid)<.@num*50) close;
	delitem .@itemid,.@num*50;
	getitem .@gain,.@num;
	mes "["+strnpcinfo(3)+"]";
	mes "�ق�A�񑩂�" +getitemname(.@gain)+ "���B";
	mes "���ł��܂����Ă���B";
	close;
}

prontera,164,165,2	duplicate(ChangeEnrich)	�G�����b�q	84


//====================================================================
//�I���f�I�R��/�G���j�E������NPC
//--------------------------------------------------------------------

-	script	TradeOriElu	-1,{
	if(checkitemblank()==0) {
		mes "- �����A�C�e���̎�ސ��� -";
		mes "- �������߁A�A�C�e�����󂯂Ƃ� -";
		mes "- ���Ƃ��ł��܂���B -";
		mes "- �����A�C�e�������炵�Ă��� -";
		mes "- �ēx�b�������Ă��������B -";
		close;
	}
	mes "["+strnpcinfo(3)+"]";	//���ʎq���Q��
	mes "�I���f�I�R���ƃG���j�E����";
	mes "�������Ă����悤���H";
	mes "�A���A�N��2��l��1��";
	mes "��������Ƃ������������ǂˁB";
	next;
	switch (select("�I���f�I�R�����G���j�E����","�G���j�E�����I���f�I�R����","��߂�")) {
	case 1:
		set .@itemid,984;
		set .@gain,985;
		break;
	case 2:
		set .@itemid,985;
		set .@gain,984;
		break;
	case 3:
		mes "["+strnpcinfo(3)+"]";
		mes "���ł��܂����Ă���B";
		close;
	}
	if(countitem(.@itemid)<2) {
		mes "["+strnpcinfo(3)+"]";
		mes "���H��k�ł���H";
		mes getitemname(.@itemid)+ "�����Ȃ��Ƃ�";
		mes "2�K�v����B";
		close;
	}
	mes "["+strnpcinfo(3)+"]";
	mes "��������ʂ͂ǂ�����H";
	next;
	if(select("1�񕪂�����������","�S����������")==1) {
		if(checkweight(.@gain,1)==0) {
			mes "�]�����A�C�e���̏d�ʂ��d����";
			mes "�@�댯�ł��B";
			mes "�@�����A�C�e�������炵�Ă���A";
			mes "�@�ēx�b�������Ă��������]";
			close;
		}
		if(countitem(.@itemid)<2) close;
		delitem .@itemid,2;
		getitem .@gain,1;
		mes "["+strnpcinfo(3)+"]";
		mes "�ق�A�񑩂�" +getitemname(.@gain)+ "���B";
		mes "���ł��܂����Ă���B";
		close;
	}
	set .@num,countitem(.@itemid)/2;
	mes "["+strnpcinfo(3)+"]";
	mes "�N��" + getitemname(.@itemid)+ "^FF0000" +(.@num*2)+ "^000000��";
	mes "�l��" + getitemname(.@gain)+ "^FF0000" +.@num+ "^000000�ƌ��������H";
	next;
	if(select("����ς��߂܂�","���肢���܂�")==1) {
		mes "["+strnpcinfo(3)+"]";
		mes "���ł��܂����Ă���B";
		close;
	}
	if(checkweight(.@gain,.@num)==0) {
		mes "�]�����A�C�e���̏d�ʂ��d����";
		mes "�@�댯�ł��B";
		mes "�@�����A�C�e�������炵�Ă���A";
		mes "�@�ēx�b�������Ă��������]";
		close;
	}
	if(countitem(.@itemid)<.@num*2) close;
	delitem .@itemid,.@num*2;
	getitem .@gain,.@num;
	mes "["+strnpcinfo(3)+"]";
	mes "�ق�A�񑩂�" +getitemname(.@gain)+ "���B";
	mes "���ł��܂����Ă���B";
	close;
}

prontera,164,161,2	duplicate(TradeOriElu)	�}�b�V��	84

//====================================================================
//����C��NPC
//--------------------------------------------------------------------

-	script	Repairer	-1,{
	mes "[�C���H]";
	mes "�����̗��l�A";
	mes "�C���������A�C�e���͂��邩�H";
	mes "�A�C�e���̏C���͉��ɔC���Ă���I";
	next;
	if(select("���͏C�����ė~�����A�C�e�����c�c","���͓��ɖ����ł�")==2) {
		mes "[�C���H]";
		mes "�ӂށc�c";
		mes "�Ȃ牴�ɗp�͖����ȁB";
		close;
	}
	set .@num,getrepairableitemcount();
	if(.@num==0) {
		mes "[�C���H]";
		mes "���������c�c";
		mes "�C������K�v�̂�����̂Ȃ��";
		mes "��������Ă��Ȃ�����Ȃ����B";
		mes "�͂��c�c";
		mes "���O�̂悤�ȃ��c���������";
		mes "���̏��������������肾��c�c";
		close;
	}
	set .@price,.@num*5000;
	mes "[�C���H]";
	mes "�ӂށc�c";
	mes "���O�������Ă���A�C�e����";
	mes "�������Ă���A�C�e����";
	mes .@num+ "���ȁB";
	next;
	mes "[�C���H]";
	mes "��C������̂� 5000 Zeny������";
	mes "�S�Ē�����" +.@price+ "Zeny�ƂȂ�B";
	mes "�C�����邩�H";
	next;
	if(select("���肢���܂�","������")==2) {
		mes "[�C���H]";
		mes "���́A�A�C�e�����������܂�";
		mes "�����Ēu�����̂�";
		mes "���܂�Ȃ������Ȃ񂾁B";
		mes "���������A�C�e���͂������������B";
		close;
	}
	if(Zeny<.@price) {
		mes "[�C���H]";
		mes "����������Ȃ��悤��";
		close;
	}
	set Zeny,Zeny-.@price;
	repairitem;
	mes "[�C���H]";
	mes "OK�I";
	mes "�������ȁB";
	mes "�A�C�e���ɂ�������������Ă��Ƃ�";
	mes "�o���Ă����񂾂ȁB";
	close;
}

alberta_in,31,65,4	duplicate(Repairer)	�C���H	84
prt_in,63,54,2	duplicate(Repairer)	�C���H	86
//morocc_in,71,41,4	duplicate(Repairer)	�C���H	99
moc_ruins,107,94,4	duplicate(Repairer)	�C���H	99
payon,143,165,7	duplicate(Repairer)	�C���H	88
geffen_in,34,166,2	duplicate(Repairer)	�C���H	86
aldeba_in,38,60,2	duplicate(Repairer)	�C���H	86
yuno_in01,175,28,2	duplicate(Repairer)	�C���H	86
