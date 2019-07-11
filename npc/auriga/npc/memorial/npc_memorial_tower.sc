//= Auriga Script ==============================================================
// Ragnarok Online Endless Tower Script	by Blaze
//- Registry -------------------------------------------------------------------
// TOWER_1QUE -> 0�`4
//==============================================================================

//============================================================
// �]��NPC
//------------------------------------------------------------
alberta,214,77,6	script	�͒������Z��	709,{
	if(BaseLevel < 50) {
		mes "[�͒������Z��]";
		mes "�����c�c";
		mes "�킵�͍ĂъC�ɏo���邾�낤���c�c";
		next;
		mes "[�͒������Z��]";
		mes "����H";
		mes "�N�́c�c�`���҂��H";
		mes "�c�c�������A^FF0000���x��50����^000000�ƌ�����B";
		mes "�܂��܂����ȁc�c";
		mes "�ӂ��c�c";
		close;
	}
	switch(TOWER_1QUE) {
	case 0:
		mes "[�͒������Z��]";
		mes "��A�N�́c�c";
		mes "�`���҂��ˁH";
		mes "�������Ȃ��Ȃ��̎��͂����肻�����B";
		next;
		mes "[�͒������Z��]";
		mes "���ΖʂŎ��炾�Ƃ͎v�����A";
		mes "�N���������";
		mes "�ǂ����Ă����݂������Ƃ�����c�c";
		next;
		mes "[�͒������Z��]";
		mes "^0000FF10,000^000000 Zeny��";
		mes "�킵�Ɋ�t���Ă���Ȃ����H";
		next;
		if(select("���R�f��","^0000FF10,000Zeny��t����^000000") == 1) {
			mes "[�͒������Z��]";
			mes "�c�c�������A���R���낤�ȁB";
			mes "���܂Ȃ��B";
			mes "���炵���ȁA��҂�B";
			close;
		}
		mes "[�͒������Z��]";
		mes "!!";
		mes "�فA�{����!?";
		mes "�킵�Ɋ�t���Ă����ƌ����̂�!?";
		mes "�Ȃ�Ɛe�؂ȕ����c�c�I";
		next;
		if(Zeny < 10000) {
			mes "[�͒������Z��]";
			mes "�������c�c�C�����͂��ꂵ�����A";
			mes "�N�������Ă���Zeny�ł�";
			mes "����Ȃ��悤���c�c";
			mes "���܂Ȃ��A���肪�Ƃ���҂�B";
			close;
		}
		mes "-10,000 Zeny��";
		mes "�@�D���Ɋ�t����-";
		next;
		mes "[�͒������Z��]";
		mes "�{���ɂ��肪�Ƃ�!!";
		mes "�܂����̐��ɌN�̂悤��";
		mes "��҂�����Ƃ́c�c";
		mes "���̉��͈ꐶ�Y��Ȃ��B";
		mes "����őD�̎��ނ��p�ӂł���I";
		set Zeny,Zeny-10000;
		set TOWER_1QUE,1;
		next;
		mes "-�D�̎��ށH";
		mes "�@��̉�������񂾂낤�c�c";
		mes "�@���������b�𕷂��Ă݂悤-";
		close;
	case 1:
		mes "-�D���͏Ί�ŋ߂���";
		mes "�@�q�C�p�i�����ɍs���A";
		mes "�@�F�X�ȕi�𒍕����Ă���悤���B";
		mes "�@���������Ȃ̂�";
		mes "�@����𕷂��Ă݂邱�Ƃɂ��悤-";
		next;
		mes "-���������I�����D��肪";
		mes "�@������ɋC�t���A�ߊ���Ă���-";
		next;
		mes "[�͒������Z��]";
		mes "�ӂށA���Ζʂɂ��ւ�炸";
		mes "�킵�̘b�𕷂��Ă����Ƃ́A";
		mes "�����������`���҂��B";
		mes "�\���x�ꂽ�A�킵�̓����Z���Ƃ����B";
		next;
		mes "[�͒������Z��]";
		mes "�Ƃ���ŌN��";
		mes "�����C�ɏo�邱�Ƃɋ����͂��邩�ˁH";
		next;
		switch(select("�q�C�o��������","��������","�����Ȃ�")) {
		case 1:
			mes "[�͒������Z��]";
			mes "�ق��`�A�Ȃ��";
			mes "��{�͂ł��Ă���悤���ȁB";
			break;
		case 2:
			mes "[�͒������Z��]";
			mes "�������������A";
			mes "�Ȃ�Θb�𕷂��Ă���B";
			break;
		case 3:
			mes "[�͒������Z��]";
			mes "���H�@���̂Ȃ�����ȁB";
			mes "�܂������A�Ƃɂ���";
			mes "�b�𕷂��Ă���B";
			break;
		}
		mes "���������Ă��킵�͐́A";
		mes "��D�c�𗦂���͒��������B";
		mes "���͈�ǂ����ɂȂ������ˁB";
		next;
		mes "[�͒������Z��]";
		mes "���̑嗤�̔ޕ��ɂ���C��";
		mes "�܂��܂����m�̐��E���R���B";
		mes "�킵�͂��̐��E�ɔj�ꂽ�̂����B";
		next;
		mes "-�����Z���͎�����";
		mes "�@�̘b��b���͂��߂��B";
		mes "�@�ɂ������̂ł��̘̐b�ɕt��������-";
		next;
		mes "-�{�����ǂ���������Ȃ����e��";
		mes "�@�قƂ�ǂ��������c�c";
		mes "�@���ɂ͋����[���b���������B";
		mes "�@����͉_�����˂������Ă���Ƃ���";
		mes "�@^0000FF����ȓ�^000000�̘b������-";
		set TOWER_1QUE,2;
		close;
	case 2:
		mes "[�͒������Z��]";
		mes "�c�c��A�ǂ��܂Řb�������ȁB";
		mes "�����A���������I";
		mes "����œ�j�����킵�̑D��";
		mes "�~�ނ𓾂����̋���ȓ��̏���";
		mes "�b�����܂邵���Ȃ������B";
		next;
		mes "[�͒������Z��]";
		mes "�H����������A���̂܂܂ł͑S��";
		mes "�쎀���Ă��܂��Ƃ����󋵂̒��A";
		mes "�D���̉��l�����H�������߁A";
		mes "���̒��ɓ��������c�c";
		mes "�N��l�߂��Ă��Ȃ������B";
		next;
		mes "[�͒������Z��]";
		mes "�����c�邽�߂ɕs�v�ȕ���S�Ď̂āA";
		mes "���Ŏ�ɓ��ꂽ���ʂ̐��ƐH�p�A����";
		mes "�ĂъC�ɏo���c�c";
		next;
		mes "[�͒������Z��]";
		mes "���ꂩ�牽���o�������킩��Ȃ����A";
		mes "������A���n��";
		mes "���ǂ蒅�����Ƃ��ł����B";
		mes "�����c�c";
		mes "���ǐ����c��͂킵��l�����������B";
		next;
		mes "[�͒������Z��]";
		mes "���ꂩ��A";
		mes "�킵�͌��S�����̂��B";
		mes "���ɓ����Ė߂��Ă���Ȃ������A";
		mes "���Ԃ�����T���ƂȁB";
		mes "�킵�̖�����������̎g�����B";
		next;
		mes "[�͒������Z��]";
		mes "�����āA�N�̂悤�ȐS�D����";
		mes "�`���҂̂�������";
		mes "���܂ōq�C���邽�߂̎������ł����B";
		mes "����Ŏg�����ʂ������Ƃ��ł���B";
		mes "�{���ɂ��肪�Ƃ��B";
		next;
		menu "��l�ōs������ł����H",-;
		mes "[�͒������Z��]";
		mes "�����A���̒ʂ肾�B";
		mes "�c�c�ƂĂ��댯�ȏꏊ���B";
		mes "�������s���Ă݂悤�Ȃǂ�";
		mes "�l���Ă���̂��H";
		next;
		mes "[�͒������Z��]";
		mes "�N�̂悤�Ȏ�҂�������";
		mes "���𗎂Ƃ��悤�Ȃ��Ƃ�";
		mes "�����Ă͂�����B";
		next;
		menu "�s���Ă݂����ł�",-;
		mes "[�͒������Z��]";
		mes "�c�c�c�c�c�c";
		mes "�������A�����܂Ō����Ȃ�";
		mes "�킵���~�߂͂��Ȃ��B������";
		mes "�����Ƃ������邾�낤����";
		mes "�S�Ă̏������ł�����킵��";
		mes "�b�������Ă���B";
		next;
		mes "[�͒������Z��]";
		mes "���c�c����ƁI";
		mes "�N��S��芽�}�����B";
		mes "�E���ȍq�C�m�����I";
		set TOWER_1QUE,3;
		close;
	case 3:
		mes "[�͒������Z��]";
		mes "�������ł������H";
		mes "�ł́A���낻��s���Ƃ��邩�H";
		next;
		if(select("^0000FF�s���܂��傤�I^000000","�܂��������c�c") == 2) {
			mes "[�͒������Z��]";
			mes "�������B";
			mes "�ł͏������ł�����";
			mes "���������Ă���B";
			close;
		}
		mes "[�͒������Z��]";
		mes "�悵�I";
		mes "�ł͏o�q��!!";
		close2;
		set TOWER_1QUE,4;
		warp "e_tower",70,114;
		end;
	case 4:
		mes "[�͒������Z��]";
		mes "�N���B";
		mes "�Ăяo�q����ɂ�";
		mes "�኱�̎��ނ��K�v���B";
		mes "^0000FF10,000^000000Zeny����Ώo�q�̂��߂�";
		mes "�S�Ă̏������ł���B";
		next;
		if(select("�܂��ɂ��܂�","^0000FF�����s���܂��傤�I^000000") == 1) {
			mes "[" +strcharinfo(0)+ "]";
			mes "���͗]�T������܂���B";
			mes "�c�O�ł����A���x�ɂ��܂��B";
			next;
			mes "[�͒������Z��]";
			mes "�������c�c";
			mes "�ł͍s�������Ȃ�����";
			mes "���ł��킵�̂Ƃ����";
			mes "���Ă���B";
			close;
		}
		if(Zeny < 10000) {
			mes "[�͒������Z��]";
			mes "�c�O�����A����Zeny����";
			mes "�S�Ă̎��ނ͔����Ȃ��ȁB";
			close;
		}
		mes "[�͒������Z��]";
		mes "�c�c�c�c�悵�I";
		mes "����őS�Ă̏������������B";
		mes "�ł͑����o�q���I";
		close2;
		set Zeny,Zeny-10000;
		warp "e_tower",70,114;
		end;
	}
}

//============================================================
// ����NPC
//------------------------------------------------------------
e_tower,80,108,3	script	���u��	857,{
	mes "[���u��]";
	mes "�c�c���̏ꏊ�ɒ���";
	mes "�㑱�̖`���҂����̂��߂�";
	mes "������L���B";
	mes "���߂Ă����ɒ��ޖ`���҂�";
	mes "���ɎQ�l�ɂ��ė~�����B";
	next;
	switch(select("^FF0000����^000000�ɂ���","^FF0000����^000000�ɂ���","^FF0000�͂��܂�̏���^000000�ɂ���","^FF0000���ӓ_^000000�ɂ���")) {
	case 1:
		mes "[���u��]";
		mes "���̓��ɓ��邽�߂̌����쐬����ƁA";
		mes "���̂��킩��Ȃ���";
		mes "���̃p�[�e�B�[�Ɗ����Ȃ�";
		mes "���̋�Ԃ����������B";
		next;
		mes "[���u��]";
		mes "�����ē��̒��Ɉ�x�ł�";
		mes "�����������u�ԁA";
		mes "^FF0000���̎�^000000���󂯂�B";
		mes "��x�������ꂽ��Ԃ�";
		mes "�ێ�����鎞�Ԃ�";
		mes "^0000FF4����^000000�̂悤���B";
		next;
		mes "[���u��]";
		mes "��x�O�ɏo����A4���Ԍo�߂���";
		mes "��Ԃ����ł�����A�ēx";
		mes "�����쐬������A���ɓ���ɂ�";
		mes "��x����������������";
		mes "^0000FF��1�T��^000000�̎��Ԃ�v����B";
		next;
		mes "[���u��]";
		mes "���x���C�y�ɒ���ł�����̂ł͂Ȃ��B";
		mes "�����͓��O�ɍs�����ق����������낤�B";
		break;
	case 2:
		mes "[���u��]";
		mes "���̓����͓���Ȏ�p�̂悤��";
		mes "�͂����菄�炳��Ă���悤���B";
		mes "���̂��߈ꕔ�X�L����A�C�e����";
		mes "���ʂ𔭊����Ȃ��悤���B";
		next;
		mes "[���u��]";
		mes "�X�L���ł́A";
		mes "^0000FF�e���|�[�g�A�A�C�X�E�H�[���A";
		mes "�X�p�C�_�[�E�F�u�A�C���e�B�~�f�C�g�A";
		mes "�A�u���J�^�u��^000000���g���Ȃ��B";
		mes "�܂�^0000FF���z�ƌ��Ɛ��̊���^000000�ɂ��";
		mes "�o�^���s�\���B";
		next;
		mes "[���u��]";
		mes "�A�C�e���ł́A";
		mes "^0000FF�n�C���[�]�C�X�g�J�[�h";
		mes "�A�]�[�g^000000�Ƃ�����";
		mes "�����X�^�[��ϊ�������ʂ�";
		mes "�����������悤���B";
		next;
		mes "[���u��]";
		mes "���R�A�e���|�[�g�Ɠ������ʂ�";
		mes "^0000FF�n�G�̉H^000000�Ȃǂ�";
		mes "�g�����Ƃ��ł��Ȃ��B";
		mes "�ȏ�𓥂܂��ď���������Ƃ����B";
		break;
	case 3:
		mes "[���u��]";
		mes "���ɓ���������A";
		mes "�ӂ��̏�����������͂����B";
		mes "���̂����̖k���̂��̂�";
		mes "^0000FF�͂��܂�̏���^000000�ƌĂ΂�Ă���B";
		next;
		mes "[���u��]";
		mes "���̂͂��܂�̏����́A";
		mes "���ɓ���������͈�ؔ������Ȃ����A";
		mes "���΂炭���Ԃ��o�Ă�";
		mes "�����������яオ��";
		mes "���ׂ���悤�ɂȂ��Ă���͂����B";
		next;
		mes "[���u��]";
		mes "���̂͂��܂�̏����ɁA";
		mes "^0000FF�ł̊D^000000�Ƃ������̂��T����";
		mes "�Ŗ�̔e���ɋ߂Â����Ƃ�";
		mes "�o����炵���B";
		next;
		mes "[���u��]";
		mes "�ڂ������Ƃ͂킩��Ȃ����A";
		mes "���炩�̎�i��^0000FF�ł̊D^000000����肵�A";
		mes "�T�����Ƃɂ����";
		mes "��w�̊K�Ɉړ����邱�Ƃ�";
		mes "�\�Ȃ悤���B";
		next;
		mes "[���u��]";
		mes "���������Ղɍl���Ă͂Ȃ�Ȃ��B";
		mes "���̓��́A1�K���珇��";
		mes "�����X�^�[�ǂ���S�ł��邱�Ƃ�";
		mes "��̊K�ւƈړ����邱�Ƃ��o����B";
		next;
		mes "[���u��]";
		mes "��w�ɍs���ɏ]����";
		mes "��苭�͂ȃ����X�^�[���o������B";
		mes "�ړ������u�Ԃɂ���Ă��܂��Ă�";
		mes "�����q���Ȃ��B";
		mes "�\�����ӂ����ق����������낤�B";
		break;
	case 4:
		mes "[���u��]";
		mes "���̓��ł́A";
		mes "���̊K�ɏo�����郂���X�^�[��";
		mes "�S�ł����邱�Ƃŏ�̊K�ւ̖傪�J���B";
		mes "���̍ہA���̓��̊Ǘ��҂�";
		mes "�u����đS�ł��������v��";
		mes "�Ď����Ă���悤���c�c";
		next;
		mes "[���u��]";
		mes "���͈�x�A���o���S��";
		mes "�o�Ă��������X�^�[��";
		mes "^FF0000�e�C�~���O^000000���Ă��܂����B";
		mes "�������e�C�~���O�����ŏ��ł���";
		mes "�����X�^�[�́A�|�������Ƃ���";
		mes "�F�߂�ꂸ�c�c";
		next;
		mes "[���u��]";
		mes "�������߂���𓾂Ȃ������B";
		mes "^FF0000�����ă����X�^�[��";
		mes "�e�C�~���O���Ă͂Ȃ�Ȃ��B^000000";
		mes "�������Ă��܂����ꍇ�́A";
		mes "�������ꂽ�_���W������";
		mes "�j������ق��Ȃ��B���ӂ��Ă���B";
		break;
	}
	next;
	mes "[���u��]";
	mes "���N�̌����Ɩ������F��B";
	mes " ";
	mes "^0000FF���� : ���������`���҂����ꓯ^000000";
	close;
}

//============================================================
// �_���W��������NPC
//------------------------------------------------------------
e_tower,81,105,0	script	���̎���	406,{
	if(getonlinepartymember() < 1) {
		mes "�y���̎��΁z";
		mes "1�l�ȏ�̃p�[�e�B�[��g��ł���";
		mes "�Ď��s����B";
		close;
	}
	if(checkquest2(12058)) {
		if(checkquest2(12058)&2) {
			delquest 12058;
			mes "�y���̎��΁z";
			mes "����^FF0000���̎�^000000���������B";
			mes "���̌��̍쐬�A�y�ѓ��ւ�";
			mes "���ꂪ�\�ɂȂ����B";
			close;
		}
		mes "�y���̎��΁z";
		mes "���ɑ��𓥂ݓ��ꂽ���߁A";
		mes "^FF0000���̎�^000000���󂯂Ă����ԁB";
		mes "�􂢂�������܂�";
		mes "���̍쐬�A������s�����i�͂Ȃ��B";
		next;
		switch(select("�A���x���^�ɋA��","�L�����Z��")){
		case 1:
			mes "�y���̎��΁z";
			mes "���̏ꏊ�ւ̋A�ҏp��";
			mes "�����c�c";
			close2;
			warp "alberta",223,36;
			end;
		case 2:
			mes "�y���̎��΁z";
			mes "���̏ꏊ�ւ̋A�ҏp��";
			mes "�����𒆎~�c�c";
			close;
		}
	}
	else {
		if(getpartyleader(getcharid(1)) == strcharinfo(0)) {
			mes "�y���̎��΁z";
			mes "���i�����\�̎҂�B";
			mes "���ɓ��錮����邩�H";
			set .@str1$,"Endless Tower�̌��̍쐬";
			set .@str2$,"Endless Tower�ɓ���";
		}
		else {
			mes "�y���̎��΁z";
			mes "���i����҂�B";
			mes "���ɓ��邩�H";
			set .@str2$,"Endless Tower�ɓ���";
		}
	}
	next;
	switch(select(.@str1$,.@str2$,"�A���x���^�ɋA��","�L�����Z��")) {
	case 1:
		if(getpartyleader(getcharid(1)) != strcharinfo(0)) {
			mes "�y���̎��΁z";
			mes "��\���������Ȃ��Ă���B";
			mes "�Ď��s����B";
			close;
		}
		mdcreate "Endless Tower";
		mes "�y���̎��΁z";
		mes "���p�[�e�B�[��";
		mes "^0000FF" +getpartyname(getcharid(1))+ "^000000";
		mes "���p�[�e�B�[���[�_�[";
		mes "^0000FF" +getpartyleader(getcharid(1))+ "^000000";
		mes " ";
		mes "^006400Endless Tower^000000�̌��̍쐬���s���B";
		next;
		mes "�y���̎��΁z";
		mes "�쐬�ɐ��������ꍇ��";
		mes "�Ăю��΂ɘb�������A";
		mes "�wEndless Tower�ɓ���x��";
		mes "�I�����邱�Ƃœ��ꂪ�\�B";
		close;
	case 2:
		switch(mdenter("Endless Tower")) {
		case 0:	// �G���[�Ȃ�
			announce "[" +strcharinfo(1)+ "]�p�[�e�B�[��[" +strcharinfo(0)+ "]��[Endless Tower]�ɓ��ꂵ�܂�",0x9,0x00FF99;
			setquest 12058;
			donpcevent getmdnpcname("TowerControl1")+ "::OnStart";
			end;
		case 1:	// �p�[�e�B�[������
			mes "�y���̎��΁z";
			mes "Endless Tower �ɓ��鎑�i���Ȃ��B";
			mes "�p�[�e�B�[�ɉ������Ă��Ȃ���ԁB";
			close;
		case 2:	// �_���W�������쐬
			mes "�y���̎��΁z";
			mes "Endless Tower �̌���";
			mes "���݂��Ȃ��B";
			mes "�p�[�e�B�[���[�_�[������";
			mes "�쐬���Ă��Ȃ���ԁB";
			close;
		default:	// ���̑��G���[
			mes "�y���̎��΁z";
			mes "�s���ȃG���[�������B";
			close;
		}
	case 3:
		mes "�y���̎��΁z";
		mes "���̏ꏊ�ւ̋A�ҏp��";
		mes "�����c�c";
		close2;
		warp "alberta",223,36;
		end;
	case 4:
		close;
	}
}

//============================================================
// �G���h���X�^���[1F�`25F
//------------------------------------------------------------
1@tower,50,360,0	script	�͂��܂�̏���	111,{
	mes "-�����ɕ����񂾕�-";
	mes " ";
	mes "^006600������^0000FF�ł̊D^006600���T�����҂́A";
	mes "�Ŗ�̔e���ɋ߂Â����낤�c�c^000000";
	next;
	set @menu,select("^0000FF26�K^000000","^00660051�K^000000","^FF000076�K^000000");
	if(countitem(6000) < @menu) {
		mes "-^FF0000�x��^000000-";
		mes (@menu*25+1)+ "�K�Ɉړ����邽�߂ɂ�";
		mes "^0000FF�ł̊D^000000��^FF0000" +@menu+ "��^000000�K�v�ł���B";
		close;
	}
	delitem 6000,@menu;
	announce "[" +strcharinfo(0)+ "]�� " +(@menu*25+1)+ "�K �ֈړ����܂�",0x9,0x00FF99;
	donpcevent getmdnpcname("TowerControl" +(@menu+1))+ "::OnStart";
	warp getmdmapname((@menu+1)+ "@tower"),52,354;
	end;
}

1@tower,0,0,0	script	TowerControl1	-1,{
OnStart:
	if(.lv > 0)
		end;
	set .lv,1;
//	setarray .mob[0][0],	// 1F
	setarray .mob[getarraysize(.mob)],
		1613,15,	// ���^����
		1242,5,		// �}�[����
		1031,5,		// �|�|����
		1113,5,		// �h���b�v�X
		1090,1,		// �}�X�^�[�����O
		1002,5		// �|����
	;
	set .mob_bous[1], getarraysize(.mob);
//	setarray .mob[1][0],	// 2F
	setarray .mob[getarraysize(.mob)],
		1106,20,	// �f�U�[�g�E���t
		1092,1,		// �����炢�T
		1107,10		// �q�f�U�[�g�E���t
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[2][0],	// 3F
	setarray .mob[getarraysize(.mob)],
		1016,5,		// �A�[�`���[�X�P���g��
		1169,5,		// �X�P�����[�J�[
		1028,5,		// �\���W���[�X�P���g��
		1152,5,		// �I�[�N�X�P���g��
		1071,5,		// �p�C���[�c�X�P��
		1076,5		// �X�P���g��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[3][0],	// 4F
	setarray .mob[getarraysize(.mob)],
		1099,15,	// �A���M�I�y
		1139,5,		// �}���e�B�X
		1100,5,		// �A���S�X
		1088,1,		// �{�[�J��
		1052,5,		// ���b�J�[
		1004,5		// �z�[�l�b�g
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[4][0],	// 5F
	setarray .mob[getarraysize(.mob)],
		//1086,1,	// �����
		//1054,15,	// �Y���
		//1053,15,	// �����
		//1051,15,	// ���
		//1048,5,	// ��峂̗�
		// jRO�z�u
		1115,1,		// �G�h�K
		1243,20,	// �T�X�J�b�`
		1306,5,		// ���C�u�I���}�C
		1517,5		// �Րl
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[5][0],	// 6F
	setarray .mob[getarraysize(.mob)],
		1721,5,		// �h���S���̗�
		1048,5,		// ��峂̗�
		1097,5,		// �a�̗�
		1008,5		// �v�p
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[6][0],	// 7F
	setarray .mob[getarraysize(.mob)],
		1383,15,	// �G�N�X�v���[�W����
		1111,15,	// �h���C�����A�[
		1627,15,	// �E�B���X
		1005,15		// �t�@�~���A�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[7][0],	// 8F
	setarray .mob[getarraysize(.mob)],
		1403,15,	// �e�
		1248,15		// �N���[�U�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[8][0],	// 9F
	setarray .mob[getarraysize(.mob)],
		1615,15,	// �I�u�V�f�B�A��
		1040,15,	// �S�[����
		1784,10		// �X�^�|
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[9][0],	// 10F
	setarray .mob[getarraysize(.mob)],
		1059,1,		// �~�X�g���X
		1303,25,	// �W���C�A���g�z�[�l�b�g
		1004,20		// �z�[�l�b�g
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[10][0],	// 11F
	setarray .mob[getarraysize(.mob)],
		1493,15,	// �h���A�[�h
		1500,15,	// �t�F�A���[�t
		1413,15,	// �V�l�Q
		1162,5		// ���t���V�A
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[11][0],	// 12F
	setarray .mob[getarraysize(.mob)],
		1378,25,	// �f�[�����p���N
		1199,25		// �p���N
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[12][0],	// 13F
	setarray .mob[getarraysize(.mob)],
		1512,15,	// �q�F�O��
		1188,15,	// �{���S��
		1026,10		// ���i�b�N
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[13][0],	// 14F
	setarray .mob[getarraysize(.mob)],
		1213,15,	// �n�C�I�[�N
		1189,10,	// �I�[�N�A�[�`���[
		1273,10,	// �I�[�N���f�B
		1023,5,		// �I�[�N�E�H���A�[
		1686,5		// �I�[�N�x�C�r�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[14][0],	// 15F
	setarray .mob[getarraysize(.mob)],
		//1147,1,	// �}���[
		//1059,1,	// �t���I�j
		//1105,15,	// �f�j�[��
		//1160,15,	// �s�G�[��
		//1095,15,	// �A���h��
		//1097,5,	// �a�̗�
		// jRO�z�u
		1147,1,		// �}���[
		1289,1,		// �}���p�[�v��
		1105,15,	// �f�j�[��
		1160,15,	// �s�G�[��
		1095,15,	// �A���h��
		1097,5		// �a�̗�
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[15][0],	// 16F
	setarray .mob[getarraysize(.mob)],
		1276,10,	// ���C�h���b�N�A�[�`���[
		1189,10,	// �I�[�N�A�[�`���[
		1253,10,	// �K�[�S�C��
		1016,10		// �A�[�`���[�X�P���g��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[16][0],	// 17F
	setarray .mob[getarraysize(.mob)],
		1264,10,	// �����l
		1101,10,	// �o�t�H���b�g.Jr
		1065,15,	// �X�g���E�t
		1629,5		// �q���E�B���h(��)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[17][0],	// 18F
	setarray .mob[getarraysize(.mob)],
		1209,25,	// �N�����v
		1175,15		// �^���E
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[18][0],	// 19F
	setarray .mob[getarraysize(.mob)],
		1108,10,	// �f�r�A�X
		1064,10,	// ���K���h��
		1069,10,	// �\�[�h�t�B�b�V��
		1158,10		// �t�F��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[19][0],	// 20F
	setarray .mob[getarraysize(.mob)],
		1112,1,		// �h���C�N
		1071,50		// �p�C���[�c�X�P��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[20][0],	// 21F
	setarray .mob[getarraysize(.mob)],
		1693,10,	// �v���Y�}(��)
		1696,10,	// �v���Y�}(��)
		1695,5,		// �v���Y�}(��)
		1697,5,		// �v���Y�}(��)
		1694,5		// �v���Y�}(��)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[21][0],	// 22F
	setarray .mob[getarraysize(.mob)],
		1780,15,	// �}�X�L�v���[
		1781,15,	// �h���Z��
		1118,15,	// �t���[��
		1068,15,	// �q�h��
		1020,10,	// �}���h���S��
		1162,10		// ���t���V�A
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[22][0],	// 23F
	setarray .mob[getarraysize(.mob)],
		1216,15,	// �y�m���i
		1044,10,	// �I�{���k
		1144,10,	// �}���X
		1069,10,	// �\�[�h�t�B�b�V��
		1068,5		// �q�h��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[23][0],	// 24F
	setarray .mob[getarraysize(.mob)],
		1131,15,	// �W���[�J�[
		1267,15,	// �W�F�X�^�[
		1130,10		// �W���b�N
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[24][0],	// 25F
	setarray .mob[getarraysize(.mob)],
		1307,15,	// �L���b�g�i�C���e�C��
		1150,1,		// �����
		1180,15		// �����
	;
	setarray .x,  9, 93,181,267,352;
	setarray .y,351,267,180, 96,  9;
L_MobCall:
	disablenpc getmdnpcname("TowerGate" +.lv);
	set .@idx,.lv-1;
//	set .@max,getarraysize(.mob[.@idx][0])/2;
	if (.@idx + 1 == getarraysize(.mob_bous)) set .@max, (getarraysize(.mob) - .mob_bous[.@idx]) / 2;
	else set .@max, (.mob_bous[.@idx + 1] - .mob_bous[.@idx]) / 2;
	for(set .@i,0; .@i < .@max; set .@i,.@i+1)
//		areamonster getmdmapname("1@tower"),.x[.@idx%5],.y[.@idx/5],.x[.@idx%5]+10,.y[.@idx/5]+36,"--ja--",.mob[.@idx][.@i*2],.mob[.@idx][.@i*2+1],getmdnpcname("TowerControl1")+ "::OnKilled";
		areamonster getmdmapname("1@tower"),.x[.@idx%5],.y[.@idx/5],.x[.@idx%5]+10,.y[.@idx/5]+36,"--ja--",.mob[.mob_bous[.@idx] + .@i*2],.mob[.mob_bous[.@idx] + .@i*2+1],getmdnpcname("TowerControl1")+ "::OnKilled";
	end;
OnKilled:
	initnpctimer;
	end;
OnTimer1000:
	stopnpctimer;
	set .count,getmapmobs(getmdmapname("1@tower"),getmdnpcname("TowerControl1")+ "::OnKilled");
	if(.count <= 0) {
		announce .lv+ "�K�̂��ׂẴ����X�^�[��|���܂���",0x9,0xFFFF00;
		enablenpc getmdnpcname("TowerGate"+.lv);
		if(.lv%25 == 0)
			initnpctimer getmdnpcname("TowerGate"+.lv);
		else {
			set .lv,.lv+1;
			callsub L_MobCall;
		}
	}
	else
		announce .lv+ "�K�Ɏc���������X�^�[ [" +.count+ "]��",0x9,0x00FF99;
	end;
}

1@tower,12,393,0	warp	TowerGate1	2,2,1@tower,136,354
1@tower,96,393,0	warp	TowerGate2	2,2,1@tower,224,354
1@tower,184,393,0	warp	TowerGate3	2,2,1@tower,310,354
1@tower,270,393,0	warp	TowerGate4	2,2,1@tower,395,354
1@tower,355,393,0	warp	TowerGate5	2,2,1@tower,52,270
1@tower,12,309,0	warp	TowerGate6	2,2,1@tower,136,270
1@tower,96,309,0	warp	TowerGate7	2,2,1@tower,224,270
1@tower,184,309,0	warp	TowerGate8	2,2,1@tower,310,270
1@tower,270,309,0	warp	TowerGate9	2,2,1@tower,395,270
1@tower,355,309,0	warp	TowerGate10	2,2,1@tower,52,183
1@tower,12,222,0	warp	TowerGate11	2,2,1@tower,136,183
1@tower,96,222,0	warp	TowerGate12	2,2,1@tower,224,183
1@tower,184,222,0	warp	TowerGate13	2,2,1@tower,310,183
1@tower,270,222,0	warp	TowerGate14	2,2,1@tower,395,183
1@tower,355,222,0	warp	TowerGate15	2,2,1@tower,52,99
1@tower,12,138,0	warp	TowerGate16	2,2,1@tower,136,99
1@tower,96,138,0	warp	TowerGate17	2,2,1@tower,224,99
1@tower,184,138,0	warp	TowerGate18	2,2,1@tower,310,99
1@tower,270,138,0	warp	TowerGate19	2,2,1@tower,395,99
1@tower,355,138,0	warp	TowerGate20	2,2,1@tower,52,12
1@tower,12,51,0		warp	TowerGate21	2,2,1@tower,136,12
1@tower,96,51,0		warp	TowerGate22	2,2,1@tower,224,12
1@tower,184,51,0	warp	TowerGate23	2,2,1@tower,310,12
1@tower,270,51,0	warp	TowerGate24	2,2,1@tower,395,12
1@tower,355,51,0	script	TowerGate25	45,2,2,{
	if(getnpctimer(1))
		getitem 6000,1;
	donpcevent getmdnpcname("TowerControl2")+ "::OnStart";
	warp getmdmapname("2@tower"),52,354;
	end;
OnTimer120000:
	stopnpctimer;
	end;
}

//============================================================
// �G���h���X�^���[26F�`50F
//------------------------------------------------------------
2@tower,0,0,0	script	TowerControl2	-1,{
OnStart:
	if(.lv > 0)
		end;
	set .lv,26;
//	setarray .mob[0][0],	// 26F
	setarray .mob[getarraysize(.mob)],
		1503,10,	// �W�r�b�g
		1410,10,	// �l�ʓ���
		1497,10,	// �E�h�D���S�[����
		1495,10,	// �t���C���V���[�^�[
		1033,5		// �G���_�[�E�B���[
	;
	set .mob_bous[1], getarraysize(.mob);
//	setarray .mob[1][0],	// 27F
	setarray .mob[getarraysize(.mob)],
		1258,10,	// �S�u�����A�[�`���[
		1122,10,	// �S�u�������j
		1123,5,		// �S�u�������j
		1124,5,		// �S�u�����O�j
		1125,5,		// �S�u�����l�j
		1126,5		// �S�u�����ܒj
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[2][0],	// 28F
	setarray .mob[getarraysize(.mob)],
		1194,30,	// �A�N���E�X
		1255,15,	// �l���C�h
		1256,15,	// �y�X�g
		1070,10		// �N�N��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[3][0],	// 29F
	setarray .mob[getarraysize(.mob)],
		1260,10,	// �_�[�N�t���[��
		1375,10,	// �ꔽ�ؖ�
		1510,10,	// �n�C���[�]�C�X�g
		1508,5,		// �L���[�u
		1509,5,		// ���[�h
		1179,10		// �E�B�X�p�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[4][0],	// 30F
	setarray .mob[getarraysize(.mob)],
		//1630,1,	// �y�N�\�W��
		//1416,30,	// �V�喺�X
		// jRO�z�u
		1159,1,		// �t���I�j
		1166,20,	// �T�x�[�W
		1311,10		// �O�����u���X�e�B
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[5][0],	// 31F
	setarray .mob[getarraysize(.mob)],
		1387,20,	// �M�O
		1212,15,	// �A�C�A���t�B�X�g
		1099,10,	// �A���M�I�y
		1001,5		// �X�R�[�s�I��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[6][0],	// 32F
	setarray .mob[getarraysize(.mob)],
		1299,1,		// �S�u�������[�_�[
		1258,10,	// �S�u�����A�[�`���[
		1122,10,	// �S�u�������j
		1123,5,		// �S�u�������j
		1124,5,		// �S�u�����O�j
		1125,5,		// �S�u�����l�j
		1126,5		// �S�u�����ܒj
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[7][0],	// 33F
	setarray .mob[getarraysize(.mob)],
		1296,1,		// �R�{���h���[�_�[
		1133,15,	// �R�{���h(��)
		1282,15,	// �R�{���h�A�[�`���[
		1134,10,	// �R�{���h(��)
		1135,5		// �R�{���h(�{)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[8][0],	// 34F
	setarray .mob[getarraysize(.mob)],
		1869,20,	// �t���[���X�J��
		1179,10,	// �E�B�X�p�[
		1186,10		// ����E�B�X�p�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[9][0],	// 35F
	setarray .mob[getarraysize(.mob)],
		1312,1,		// �^�[�g���W�F�l����
		1319,10,	// �t���[�Y�^�[�g��
		1316,10,	// �\���b�h�^�[�g��
		1318,10,	// �q�[�g�^�[�g��
		1314,10		// �p�[���b�g�^�[�g��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[10][0],	// 36F
	setarray .mob[getarraysize(.mob)],
		1206,30,	// �A�m���A��
		1687,10,	// �O���[���C�O�A�i
		1271,10		// �A���Q�[�^�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[11][0],	// 37F
	setarray .mob[getarraysize(.mob)],
		1270,5,		// ���v���Ǘ���
		1269,10,	// �N���b�N
		1193,30		// �A���[��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[12][0],	// 38F
	setarray .mob[getarraysize(.mob)],
		1698,25,	// �f�X���[�h
		1195,25		// ���C�h���[�h
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[13][0],	// 39F
	setarray .mob[getarraysize(.mob)],
		1416,10,	// �V�喺�X
		1513,10,	// �~���O�F
		1412,10,	// �V�א�l
		1514,10,	// ������
		1517,5		// �Րl
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[14][0],	// 40F
	setarray .mob[getarraysize(.mob)],
		//1492,1,	// ���앐�m
		//1401,10,	// �J�u�L�E��
		//1405,10,	// ��V��
		//1403,5,	// �e�
		//1404,10,	// ��l�`
		//1400,5,	// �J���P
		// jRO�z�u
		1251,1,		// �X�g�[���i�C�g
		1252,1,		// �n�e�B�[
		1515,35,	// �n�e�B�[�x�x
		1775,15,	// �X�m�E�A�[
		1777,15		// �A�C�X�^�C�^��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[15][0],	// 41F
	setarray .mob[getarraysize(.mob)],
		1587,50		// �N���x��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[16][0],	// 42F
	setarray .mob[getarraysize(.mob)],
		1386,20,	// �X���[�p�[
		1207,10,	// �X�e�B���O
		1516,10,	// �y��
		1165,5,		// �T���h�}��
		1127,5		// �z�[�h
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[17][0],	// 43F
	setarray .mob[getarraysize(.mob)],
		1148,10,	// ���f���[�T
		1037,40,	// �T�C�h���C���_�[
		1030,5,		// �A�i�R���_�N
		1025,5		// �X�l�C�N
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[18][0],	// 44F
	setarray .mob[getarraysize(.mob)],
		1515,20,	// �n�e�B�[�x�x
		1101,20,	// �o�t�H���b�g.Jr
		1686,1,		// �I�[�N�x�C�r�[
		1107,10,	// �q�f�U�[�g�E���t
		1167,10		// �T�x�[�W�x�x
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[19][0],	// 45F
	setarray .mob[getarraysize(.mob)],
		1038,1,		// �I�V���X
		1297,15,	// �G���V�F���g�}�~�[
		1032,15,	// �x���b�g
		1041,20		// �}�~�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[20][0],	// 46F
	setarray .mob[getarraysize(.mob)],
		1774,20,	// �V�[�J�[
		1633,20		// �r�z���_�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[21][0],	// 47F
	setarray .mob[getarraysize(.mob)],
		1384,20,	// �f���[�^�[(��)
		1385,10,	// �f���[�^�[(�n)
		1156,10,	// �v�e�B�b�g(��)
		1155,10		// �v�e�B�b�g(�n)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[22][0],	// 48F
	setarray .mob[getarraysize(.mob)],
		1305,10,	// �G���V�F���g���[��
		1297,10,	// �G���V�F���g�}�~�[
		1699,10		// �G���V�F���g�~�~�b�N
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[23][0],	// 49F
	setarray .mob[getarraysize(.mob)],
		1381,20,	// �O���Y���[
		1306,7,		// ���C�u�I���}�C
		1417,5,		// �`���b�L�[
		1243,5,		// �T�X�J�b�`
		1060,5		// �r�b�O�t�b�g
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[24][0],	// 50F
	setarray .mob[getarraysize(.mob)],
		1157,1,		// �t�@���I
		1511,1,		// �A�������[
		1098,10,	// �A�k�r�X
		1140,10,	// �}���h�D�[�N
		1146,10		// �}�[�^�[
	;
	setarray .x,  9, 93,181,267,352;
	setarray .y,351,267,180, 96,  9;
L_MobCall:
	disablenpc getmdnpcname("TowerGate" +.lv);
	set .@idx,.lv-26;
//	set .@max,getarraysize(.mob[.@idx][0])/2;
	if (.@idx + 1 == getarraysize(.mob_bous)) set .@max, (getarraysize(.mob) - .mob_bous[.@idx]) / 2;
	else set .@max, (.mob_bous[.@idx + 1] - .mob_bous[.@idx]) / 2;
	for(set .@i,0; .@i < .@max; set .@i,.@i+1)
//		areamonster getmdmapname("2@tower"),.x[.@idx%5],.y[.@idx/5],.x[.@idx%5]+10,.y[.@idx/5]+36,"--ja--",.mob[.@idx][.@i*2],.mob[.@idx][.@i*2+1],getmdnpcname("TowerControl2")+ "::OnKilled";
		areamonster getmdmapname("2@tower"),.x[.@idx%5],.y[.@idx/5],.x[.@idx%5]+10,.y[.@idx/5]+36,"--ja--",.mob[.mob_bous[.@idx] + .@i*2],.mob[.mob_bous[.@idx] + .@i*2+1],getmdnpcname("TowerControl2")+ "::OnKilled";
	end;
OnKilled:
	initnpctimer;
	end;
OnTimer1000:
	stopnpctimer;
	set .count,getmapmobs(getmdmapname("2@tower"),getmdnpcname("TowerControl2")+ "::OnKilled");
	if(.count <= 0) {
		announce .lv+ "�K�̂��ׂẴ����X�^�[��|���܂���",0x9,0xFFFF00;
		enablenpc getmdnpcname("TowerGate"+.lv);
		if(.lv%25 == 0)
			initnpctimer getmdnpcname("TowerGate"+.lv);
		else {
			set .lv,.lv+1;
			callsub L_MobCall;
		}
	}
	else
		announce .lv+ "�K�Ɏc���������X�^�[ [" +.count+ "]��",0x9,0x00FF99;
	end;
}

2@tower,12,393,0	warp	TowerGate26	2,2,2@tower,136,354
2@tower,96,393,0	warp	TowerGate27	2,2,2@tower,224,354
2@tower,184,393,0	warp	TowerGate28	2,2,2@tower,310,354
2@tower,270,393,0	warp	TowerGate29	2,2,2@tower,395,354
2@tower,355,393,0	warp	TowerGate30	2,2,2@tower,52,270
2@tower,12,309,0	warp	TowerGate31	2,2,2@tower,136,270
2@tower,96,309,0	warp	TowerGate32	2,2,2@tower,224,270
2@tower,184,309,0	warp	TowerGate33	2,2,2@tower,310,270
2@tower,270,309,0	warp	TowerGate34	2,2,2@tower,395,270
2@tower,355,309,0	warp	TowerGate35	2,2,2@tower,52,183
2@tower,12,222,0	warp	TowerGate36	2,2,2@tower,136,183
2@tower,96,222,0	warp	TowerGate37	2,2,2@tower,224,183
2@tower,184,222,0	warp	TowerGate38	2,2,2@tower,310,183
2@tower,270,222,0	warp	TowerGate39	2,2,2@tower,395,183
2@tower,355,222,0	warp	TowerGate40	2,2,2@tower,52,99
2@tower,12,138,0	warp	TowerGate41	2,2,2@tower,136,99
2@tower,96,138,0	warp	TowerGate42	2,2,2@tower,224,99
2@tower,184,138,0	warp	TowerGate43	2,2,2@tower,310,99
2@tower,270,138,0	warp	TowerGate44	2,2,2@tower,395,99
2@tower,355,138,0	warp	TowerGate45	2,2,2@tower,52,12
2@tower,12,51,0		warp	TowerGate46	2,2,2@tower,136,12
2@tower,96,51,0		warp	TowerGate47	2,2,2@tower,224,12
2@tower,184,51,0	warp	TowerGate48	2,2,2@tower,310,12
2@tower,270,51,0	warp	TowerGate49	2,2,2@tower,395,12
2@tower,355,51,0	script	TowerGate50	45,2,2,{
	if(getnpctimer(1))
		getitem 6000,1;
	donpcevent getmdnpcname("TowerControl3")+ "::OnStart";
	warp getmdmapname("3@tower"),52,354;
	end;
OnTimer120000:
	stopnpctimer;
	end;
}

//============================================================
// �G���h���X�^���[51F�`75F
//------------------------------------------------------------
3@tower,0,0,0	script	TowerControl3	-1,{
OnStart:
	if(.lv > 0)
		end;
	set .lv,51;
//	setarray .mob[0][0],	// 51F
	setarray .mob[getarraysize(.mob)],
		1292,20,	// �~�j�f��
		1382,20,	// �f�B�A�{���b�N
		1109,10		// �f�r���`
	;
	set .mob_bous[1], getarraysize(.mob);
//	setarray .mob[1][0],	// 52F
	setarray .mob[getarraysize(.mob)],
		1376,20,	// �n�[�s�[
		1369,10,	// �O�����y�R
		1408,10,	// �p�s����
		1253,10,	// �K�[�S�C��
		1680,5,		// �q���E�B���h(�H)
		1629,5		// �q���E�B���h(��)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[2][0],	// 53F
	setarray .mob[getarraysize(.mob)],
		1315,25,	// �A�T���g�^�[�g��
		1401,30		// �J�u�L�E��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[3][0],	// 54F
	setarray .mob[getarraysize(.mob)],
		1250,10,	// �`�F�y�b�g
		1143,10,	// �}���I�l�b�g
		1404,10		// ��l�`
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[4][0],	// 55F
	setarray .mob[getarraysize(.mob)],
		1148,25,	// ���f���[�T
		1418,1,		// ���։�
		1029,15,	// �C�V�X
		1037,15		// �T�C�h���C���_�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[5][0],	// 56F
	setarray .mob[getarraysize(.mob)],
		1319,10,	// �t���[�Y�^�[�g��
		1515,10,	// �n�e�B�[�x�x
		1777,15,	// �A�C�X�^�C�^��
		1775,10,	// �X�m�E�A�[
		1778,10		// �Q�C�Y�e�B
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[6][0],	// 57F
	setarray .mob[getarraysize(.mob)],
		1388,1,		// �A�[�N�G���W�F�����O
		1582,1,		// �f�r�������O
		1096,1,		// �G���W�F�����O
		1120,1,		// �S�[�X�g�����O
		1090,1,		// �}�X�^�[�����O
		1613,25,	// ���^����
		1242,5,		// �}�[����
		1031,5,		// �|�|����
		1113,5		// �h���b�v�X
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[7][0],	// 58F
	setarray .mob[getarraysize(.mob)],
		1202,20,	// �t�F���_�[�N
		1201,10,	// ���r�I
		1197,10,	// �]���r�v���Y�i�[
		1196,5,		// �X�P���v���Y�i�[
		1257,5		// �C���W���X�e�B�X
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[8][0],	// 59F
	setarray .mob[getarraysize(.mob)],
		1699,30,	// �G���V�F���g�~�~�b�N
		1191,20,	// �~�~�b�N
		1249,10		// �~�X�g�P�[�X
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[9][0],	// 60F
	setarray .mob[getarraysize(.mob)],
		1658,1,		// �C�O�j�[��=�Z�j�A(MVP)
		1046,1,		// �h�b�y���Q���K�[
		1654,10,	// �A���}�C�A=�f�����[
		1653,10,	// �q���b�P�o�C��=�g���X
		1657,10,	// ���E����=���B���_�[
		1656,10,	// �J���@�N=�C�J���X
		1655,10,	// �C�����h=�G�x�V
		1652,10		// �C�O�j�[��=�Z�j�A
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[10][0],	// 61F
	setarray .mob[getarraysize(.mob)],
		1769,10,	// �A�K��
		1770,10,	// �G�L�I
		1772,5,		// �A�C�V��
		1313,10,	// �`���s��
		1154,10,	// �p�T�i
		1771,5		// ���@���x���N
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[11][0],	// 62F
	setarray .mob[getarraysize(.mob)],
		1208,35		// �f�r����
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[12][0],	// 63F
	setarray .mob[getarraysize(.mob)],
		1865,20,	// ���M�b�h�]���r
		1298,10,	// �]���r�}�X�^�[
		1197,5,		// �]���r�v���Y�i�[
		1153,5,		// �I�[�N�]���r
		1015,5		// �]���r
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[13][0],	// 64F
	setarray .mob[getarraysize(.mob)],
		1618,30,	// �E���S���A���g
		1305,2,		// �G���V�F���g���[��
		1300,2,		// �L���^�s���[
		1293,2,		// �N���[�~�[�t�B�A�[
		1294,2,		// �L���[�}���e�B�X
		1303,2		// �W���C�A���g�z�[�l�b�g
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[14][0],	// 65F
	setarray .mob[getarraysize(.mob)],
		1785,1,		// �A�g���X
		1783,20		// �K���I��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[15][0],	// 66F
	setarray .mob[getarraysize(.mob)],
		1374,20,	// �C���L���o�X
		1736,20,	// �G���I�b�g
		1257,10		// �C���W���X�e�B�X
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[16][0],	// 67F
	setarray .mob[getarraysize(.mob)],
		1716,10,	// �I�V�h�X(��)
		1713,10,	// �I�V�h�X(��)
		1384,5,		// �f���[�^�[(��)
		1262,10,	// �~���[�^���g�h���S��
		1156,5		// �v�e�B�b�g(��)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[17][0],	// 68F
	setarray .mob[getarraysize(.mob)],
		1366,10,	// ���[���@�S�[����
		1278,10,	// �X�^���N�^�C�g�S�[����
		1777,10,	// �A�C�X�^�C�^��
		1497,5,		// �E�h�D���S�[����
		1040,5		// �S�[����
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[18][0],	// 69F
	setarray .mob[getarraysize(.mob)],
		1700,20,	// �Ď������
		1701,10,	// �ی삷���
		1702,10,	// ���s�����
		1703,10,	// �Ԃ߂��
		1371,10		// �t�F�C�N�G���W�F��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[19][0],	// 70F
	setarray .mob[getarraysize(.mob)],
		//1087,1,	// �I�[�N�q�[���[
		//1190,1,	// �I�[�N���[�h
		//1686,20,	// �I�[�N�x�C�r�[
		// jRO�z�u
		1623,1,		// RSX-0806
		1685,1,		// ���F�X�p�[
		1617,10,	// �W�����N�|�b�g
		1622,5,		// �x�A�h�[��
		1668,5,		// �A�[�N�_��
		1670,15,	// �f�B�~�b�N(��)
		1671,15,	// �f�B�~�b�N(��)
		1672,5,		// �f�B�~�b�N(�n)
		1673,10		// �f�B�~�b�N(��)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[20][0],	// 71F
	setarray .mob[getarraysize(.mob)],
		1370,20,	// �T�L���o�X
		1379,20,	// �i�C�g���A�e���[
		1374,20,	// �C���L���o�X
		1061,5		// �i�C�g���A
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[21][0],	// 72F
	setarray .mob[getarraysize(.mob)],
		1637,10,	// �}�[�K���b�^=�\����
		1314,10,	// �p�[���b�g�^�[�g��
		1655,10,	// �C�����h=�G�x�V
		1410,10		// �l�ʓ���
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[22][0],	// 73F
	setarray .mob[getarraysize(.mob)],
		1370,10,	// �T�L���o�X
		1505,20,	// ��������
		1737,10,	// �G���U
		1200,5,		// �W���^�X
		1275,5,		// �A���X
		1631,10		// �`�����C�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[23][0],	// 74F
	setarray .mob[getarraysize(.mob)],
		1671,6,		// �f�B�~�b�N(��)
		1673,6,		// �f�B�~�b�N(��)
		1672,6,		// �f�B�~�b�N(�n)
		1677,6,		// ���F�i�[�g(��)
		1670,6,		// �f�B�~�b�N(��)
		1668,6,		// �A�[�N�_��
		1678,6,		// ���F�i�[�g(�n)
		1679,6,		// ���F�i�[�g(��)
		1676,6		// ���F�i�[�g(��)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[24][0],	// 75F
	setarray .mob[getarraysize(.mob)],
		1039,1,		// �o�t�H���b�g
		1272,1,		// �_�[�N���[�h
		1101,20,	// �o�t�H���b�g.Jr
		1302,10		// �_�[�N�C�����[�W����
	;
	setarray .x,  9, 93,181,267,352;
	setarray .y,351,267,180, 96,  9;
L_MobCall:
	disablenpc getmdnpcname("TowerGate" +.lv);
	set .@idx,.lv-51;
//	set .@max,getarraysize(.mob[.@idx][0])/2;
	if (.@idx + 1 == getarraysize(.mob_bous)) set .@max, (getarraysize(.mob) - .mob_bous[.@idx]) / 2;
	else set .@max, (.mob_bous[.@idx + 1] - .mob_bous[.@idx]) / 2;
	for(set .@i,0; .@i < .@max; set .@i,.@i+1)
//		areamonster getmdmapname("3@tower"),.x[.@idx%5],.y[.@idx/5],.x[.@idx%5]+10,.y[.@idx/5]+36,"--ja--",.mob[.@idx][.@i*2],.mob[.@idx][.@i*2+1],getmdnpcname("TowerControl3")+ "::OnKilled";
		areamonster getmdmapname("3@tower"),.x[.@idx%5],.y[.@idx/5],.x[.@idx%5]+10,.y[.@idx/5]+36,"--ja--",.mob[.mob_bous[.@idx] + .@i*2],.mob[.mob_bous[.@idx] + .@i*2+1],getmdnpcname("TowerControl3")+ "::OnKilled";
	end;
OnKilled:
	initnpctimer;
	end;
OnTimer1000:
	stopnpctimer;
	set .count,getmapmobs(getmdmapname("3@tower"),getmdnpcname("TowerControl3")+ "::OnKilled");
	if(.count <= 0) {
		announce .lv+ "�K�̂��ׂẴ����X�^�[��|���܂���",0x9,0xFFFF00;
		enablenpc getmdnpcname("TowerGate"+.lv);
		if(.lv%25 == 0)
			initnpctimer getmdnpcname("TowerGate"+.lv);
		else {
			set .lv,.lv+1;
			callsub L_MobCall;
		}
	}
	else
		announce .lv+ "�K�Ɏc���������X�^�[ [" +.count+ "]��",0x9,0x00FF99;
	end;
}

3@tower,12,393,0	warp	TowerGate51	2,2,3@tower,136,354
3@tower,96,393,0	warp	TowerGate52	2,2,3@tower,224,354
3@tower,184,393,0	warp	TowerGate53	2,2,3@tower,310,354
3@tower,270,393,0	warp	TowerGate54	2,2,3@tower,395,354
3@tower,355,393,0	warp	TowerGate55	2,2,3@tower,52,270
3@tower,12,309,0	warp	TowerGate56	2,2,3@tower,136,270
3@tower,96,309,0	warp	TowerGate57	2,2,3@tower,224,270
3@tower,184,309,0	warp	TowerGate58	2,2,3@tower,310,270
3@tower,270,309,0	warp	TowerGate59	2,2,3@tower,395,270
3@tower,355,309,0	warp	TowerGate60	2,2,3@tower,52,183
3@tower,12,222,0	warp	TowerGate61	2,2,3@tower,136,183
3@tower,96,222,0	warp	TowerGate62	2,2,3@tower,224,183
3@tower,184,222,0	warp	TowerGate63	2,2,3@tower,310,183
3@tower,270,222,0	warp	TowerGate64	2,2,3@tower,395,183
3@tower,355,222,0	warp	TowerGate65	2,2,3@tower,52,99
3@tower,12,138,0	warp	TowerGate66	2,2,3@tower,136,99
3@tower,96,138,0	warp	TowerGate67	2,2,3@tower,224,99
3@tower,184,138,0	warp	TowerGate68	2,2,3@tower,310,99
3@tower,270,138,0	warp	TowerGate69	2,2,3@tower,395,99
3@tower,355,138,0	warp	TowerGate70	2,2,3@tower,52,12
3@tower,12,51,0		warp	TowerGate71	2,2,3@tower,136,12
3@tower,96,51,0		warp	TowerGate72	2,2,3@tower,224,12
3@tower,184,51,0	warp	TowerGate73	2,2,3@tower,310,12
3@tower,270,51,0	warp	TowerGate74	2,2,3@tower,395,12
3@tower,355,51,0	script	TowerGate75	45,2,2,{
	if(getnpctimer(1))
		getitem 6000,1;
	donpcevent getmdnpcname("TowerControl4")+ "::OnStart";
	warp getmdmapname("4@tower"),52,354;
	end;
OnTimer120000:
	stopnpctimer;
	end;
}

//============================================================
// �G���h���X�^���[76F�`99F
//------------------------------------------------------------
4@tower,0,0,0	script	TowerControl4	-1,{
OnStart:
	if(.lv > 0)
		end;
	set .lv,76;
//	setarray .mob[0][0],	// 76F
	setarray .mob[getarraysize(.mob)],
		1219,30,	// �[���̋R�m
		1379,20,	// �i�C�g���A�e���[
		1061,10		// �i�C�g���A
	;
	set .mob_bous[1], getarraysize(.mob);
//	setarray .mob[1][0],	// 77F
	setarray .mob[getarraysize(.mob)],
		1867,30,	// �o���V�[
		1291,10,	// �f�b�h���[���C�X
		1117,10,	// �C�r���h���C�h
		1192,10,	// ���C�X
		1263,10		// �E�B���h�S�[�X�g
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[2][0],	// 78F
	setarray .mob[getarraysize(.mob)],
		1829,5,		// �\�[�h�K�[�f�B�A��
		1268,10,	// �u���b�f�B�i�C�g
		1219,5,		// �[���̋R�m
		1504,10,	// �f�����n��
		1163,20		// ���C�h���b�N
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[3][0],	// 79F
	setarray .mob[getarraysize(.mob)],
		1720,10,	// �n�C�h�������T�[
		1714,10,	// �y���X(��)
		1717,10,	// �y���X(��)
		1385,10,	// �f���[�^�[(�n)
		1155,10		// �v�e�B�b�g(�n)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[4][0],	// 80F
	setarray .mob[getarraysize(.mob)],
		1871,1,		// ������_���q�o��
		1870,15		// �l�N���}���T�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[5][0],	// 81F
	setarray .mob[getarraysize(.mob)],
		1203,20,	// �~�X�e���e�C��
		1204,20,	// �I�[�K�g�D�[�X
		1205,20		// �G�N�X�L���[�V���i�[
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[6][0],	// 82F
	setarray .mob[getarraysize(.mob)],
		1268,10,	// �u���b�f�B�i�C�g
		1769,10,	// �A�K��
		1507,10,	// �u���b�f�B�}�[�_�[
		1752,10,	// �X�R�O��
		1257,10		// �C���W���X�e�B�X
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[7][0],	// 83F
	setarray .mob[getarraysize(.mob)],
		1754,10,	// �X�P�S���g
		1302,10,	// �_�[�N�C�����[�W����
		1259,10,	// �O���t�H��
		1283,10		// �L����
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[8][0],	// 84F
	setarray .mob[getarraysize(.mob)],
		1370,10,	// �T�L���o�X
		1302,20,	// �_�[�N�C�����[�W����
		1320,10,	// �I�E���f���[�N
		1295,10,	// �I�E���o����
		1374,10		// �C���L���o�X
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[9][0],	// 85F
	setarray .mob[getarraysize(.mob)],
		1832,1		// �C�t���[�g
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[10][0],	// 86F
	setarray .mob[getarraysize(.mob)],
		1720,10,	// �n�C�h�������T�[
		1259,10,	// �O���t�H��
		1283,10,	// �L����
		1310,10		// �������~�m�^�E���X
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[11][0],	// 87F
	setarray .mob[getarraysize(.mob)],
		1831,15,	// �T���}���_�[
		1833,20,	// �J�[�T
		1366,15,	// ���[���@�S�[����
		1309,10		// �K�W���}�[�g
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[12][0],	// 88F
	setarray .mob[getarraysize(.mob)],
		1870,15,	// �l�N���}���T�[
		1098,15,	// �A�k�r�X
		1291,10,	// �f�b�h���[���C�X
		1297,10,	// �G���V�F���g�}�~�[
		1132,10		// �J�[���b�c�o�[�O
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[13][0],	// 89F
	setarray .mob[getarraysize(.mob)],
		1704,6,		// �^�i�g�X�̑���
		1705,6,		// �^�i�g�X�̐�]
		1707,6,		// �^�i�g�X�̋�Y
		1706,6		// �^�i�g�X�̔߂���
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[14][0],	// 90F
	setarray .mob[getarraysize(.mob)],
		1751,1,		// �����h�O���X
		1702,10,	// ���s�����
		1703,10,	// �Ԃ߂��
		1371,10		// �t�F�C�N�G���W�F��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[15][0],	// 91F
	setarray .mob[getarraysize(.mob)],
		1638,10,	// �Z�V��=�f�B����
		1830,10,	// �{�E�K�[�f�B�A��
		1656,30		// �J���@�N=�C�J���X
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[16][0],	// 92F
	setarray .mob[getarraysize(.mob)],
		1639,15,	// �J�g���[�k=�P�C����
		1377,10,	// �G���_�[
		1657,10,	// ���E����=���B���_�[
		1263,10,	// �E�B���h�S�[�X�g
		1140,10		// �}���h�D�[�N
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[17][0],	// 93F
	setarray .mob[getarraysize(.mob)],
		1634,15,	// �Z�C����=�E�B���U�[
		1268,10,	// �u���b�f�B�i�C�g
		1219,10,	// �[���̋R�m
		1208,10		// �f�r����
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[18][0],	// 94F
	setarray .mob[getarraysize(.mob)],
		1829,15,	// �\�[�h�K�[�f�B�A��
		1830,15		// �{�E�K�[�f�B�A��
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[19][0],	// 95F
	setarray .mob[getarraysize(.mob)],
		1873,1,		// ���F���[�u�u
		1035,30,	// �n���^�[�t���C
		1042,5,		// �X�`�[���`�����`����
		1091,5,		// �h���S���t���C
		1011,5		// �`�����`����
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[20][0],	// 96F
	setarray .mob[getarraysize(.mob)],
		1765,5,		// �����h�O���X�S�[�X�g
		1755,10,	// �X�P�S���g(��)
		1754,10		// �X�P�S���g(��)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[21][0],	// 97F
	setarray .mob[getarraysize(.mob)],
		1918,5,		// �����N�̌��g(�V�g�^)
		1919,5,		// �����N�̌��g(�����^)
		1920,5,		// �����N�̌��g(�l�Ԍ^)
		1921,5		// �����N�̌��g(����^)
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[22][0],	// 98F
	setarray .mob[getarraysize(.mob)],
		1639,2,		// �J�g���[�k=�P�C����
		1634,2,		// �Z�C����=�E�B���U�[
		1637,2,		// �}�[�K���b�^=�\����
		1635,2,		// �G�����X=�K�C��
		1636,2,		// �n���[�h=�A���g�A�C�[��
		1638,2		// �Z�V��=�f�B����
	;
	set .mob_bous[getarraysize(.mob_bous)], getarraysize(.mob);
//	setarray .mob[23][0],	// 99F
	setarray .mob[getarraysize(.mob)],
		1639,2,		// �J�g���[�k=�P�C����
		1634,2,		// �Z�C����=�E�B���U�[
		1637,2,		// �}�[�K���b�^=�\����
		1635,2,		// �G�����X=�K�C��
		1636,2,		// �n���[�h=�A���g�A�C�[��
		1638,2,		// �Z�V��=�f�B����
		1918,5,		// �����N�̌��g(�V�g�^)
		1919,5,		// �����N�̌��g(�����^)
		1920,5,		// �����N�̌��g(�l�Ԍ^)
		1921,5,		// �����N�̌��g(����^)
		1765,5,		// �����h�O���X�S�[�X�g
		1755,10,	// �X�P�S���g(��)
		1754,10,	// �X�P�S���g(��)
		1634,15,	// �Z�C����=�E�B���U�[
		1268,10,	// �u���b�f�B�i�C�g
		1219,10,	// �[���̋R�m
		1208,10,	// �f�r����
		1829,15,	// �\�[�h�K�[�f�B�A��
		1830,15,	// �{�E�K�[�f�B�A��
		1639,15,	// �J�g���[�k=�P�C����
		1377,10,	// �G���_�[
		1657,10,	// ���E����=���B���_�[
		1263,10,	// �E�B���h�S�[�X�g
		1140,10,	// �}���h�D�[�N
		1638,10,	// �Z�V��=�f�B����
		1830,10,	// �{�E�K�[�f�B�A��
		1656,30,	// �J���@�N=�C�J���X
		1702,10,	// ���s�����
		1703,10,	// �Ԃ߂��
		1371,10		// �t�F�C�N�G���W�F��
	;
	setarray .x,  9, 93,181,267,352;
	setarray .y,351,267,180, 96,  9;
L_MobCall:
	disablenpc getmdnpcname("TowerGate" +.lv);
	set .@idx,.lv-76;
//	set .@max,getarraysize(.mob[.@idx][0])/2;
	if (.@idx + 1 == getarraysize(.mob_bous)) set .@max, (getarraysize(.mob) - .mob_bous[.@idx]) / 2;
	else set .@max, (.mob_bous[.@idx + 1] - .mob_bous[.@idx]) / 2;
	if(.lv == 99) {
		for(set .@i,0; .@i < 7; set .@i,.@i+1) {
			set .@r,rand(.@max);
//			areamonster getmdmapname("4@tower"),.x[.@idx%5],.y[.@idx/5],.x[.@idx%5]+10,.y[.@idx/5]+36,"--ja--",.mob[.@idx][.@r*2],.mob[.@idx][.@r*2+1],getmdnpcname("TowerControl4")+ "::OnKilled";
			areamonster getmdmapname("4@tower"),.x[.@idx%5],.y[.@idx/5],.x[.@idx%5]+10,.y[.@idx/5]+36,"--ja--",.mob[.mob_bous[.@idx] + .@r*2],.mob[.mob_bous[.@idx] + .@r*2+1],getmdnpcname("TowerControl4")+ "::OnKilled";
		}
	}
	else {
		for(set .@i,0; .@i < .@max; set .@i,.@i+1)
//			areamonster getmdmapname("4@tower"),.x[.@idx%5],.y[.@idx/5],.x[.@idx%5]+10,.y[.@idx/5]+36,"--ja--",.mob[.@idx][.@i*2],.mob[.@idx][.@i*2+1],getmdnpcname("TowerControl4")+ "::OnKilled";
			areamonster getmdmapname("4@tower"),.x[.@idx%5],.y[.@idx/5],.x[.@idx%5]+10,.y[.@idx/5]+36,"--ja--",.mob[.mob_bous[.@idx] + .@i*2],.mob[.mob_bous[.@idx] + .@i*2+1],getmdnpcname("TowerControl4")+ "::OnKilled";
	}
	end;
OnKilled:
	initnpctimer;
	end;
OnTimer1000:
	stopnpctimer;
	set .count,getmapmobs(getmdmapname("4@tower"),getmdnpcname("TowerControl4")+ "::OnKilled");
	if(.count <= 0) {
		announce .lv+ "�K�̂��ׂẴ����X�^�[��|���܂���",0x9,0xFFFF00;
		enablenpc getmdnpcname("TowerGate"+.lv);
		if(.lv == 99)
			initnpctimer "TowerGate" +.lv;
		else {
			set .lv,.lv+1;
			callsub L_MobCall;
		}
	}
	else
		announce .lv+ "�K�Ɏc���������X�^�[ [" +.count+ "]��",0x9,0x00FF99;
	end;
}

4@tower,12,393,0	warp	TowerGate76	2,2,4@tower,136,354
4@tower,96,393,0	warp	TowerGate77	2,2,4@tower,224,354
4@tower,184,393,0	warp	TowerGate78	2,2,4@tower,310,354
4@tower,270,393,0	warp	TowerGate79	2,2,4@tower,395,354
4@tower,355,393,0	warp	TowerGate80	2,2,4@tower,52,270
4@tower,12,309,0	warp	TowerGate81	2,2,4@tower,136,270
4@tower,96,309,0	warp	TowerGate82	2,2,4@tower,224,270
4@tower,184,309,0	warp	TowerGate83	2,2,4@tower,310,270
4@tower,270,309,0	warp	TowerGate84	2,2,4@tower,395,270
4@tower,355,309,0	warp	TowerGate85	2,2,4@tower,52,183
4@tower,12,222,0	warp	TowerGate86	2,2,4@tower,136,183
4@tower,96,222,0	warp	TowerGate87	2,2,4@tower,224,183
4@tower,184,222,0	warp	TowerGate88	2,2,4@tower,310,183
4@tower,270,222,0	warp	TowerGate89	2,2,4@tower,395,183
4@tower,355,222,0	warp	TowerGate90	2,2,4@tower,52,99
4@tower,12,138,0	warp	TowerGate91	2,2,4@tower,136,99
4@tower,96,138,0	warp	TowerGate92	2,2,4@tower,224,99
4@tower,184,138,0	warp	TowerGate93	2,2,4@tower,310,99
4@tower,270,138,0	warp	TowerGate94	2,2,4@tower,395,99
4@tower,355,138,0	warp	TowerGate95	2,2,4@tower,52,12
4@tower,12,51,0		warp	TowerGate96	2,2,4@tower,136,12
4@tower,96,51,0		warp	TowerGate97	2,2,4@tower,224,12
4@tower,184,51,0	warp	TowerGate98	2,2,4@tower,310,12
4@tower,270,51,0	script	TowerGate99	45,2,2,{
	if(getnpctimer(1))
		getitem 6000,1;
	donpcevent getmdnpcname("TowerControl5")+ "::OnStart";
	hideonnpc getmdnpcname("����#Tower");
	warp getmdmapname("5@tower"),101,72;
	end;
OnTimer120000:
	stopnpctimer;
	end;
}

//============================================================
// �G���h���X�^���[100F
//------------------------------------------------------------
5@tower,0,0,0	script	TowerControl5	-1,{
OnStart:
	if(.lv > 0)
		end;
	set .lv,100;
	set .@mdmap$,getmdmapname("5@tower");
	set .@mdnpc$,getmdnpcname("TowerControl5");
	monster .@mdmap$,83,85,"�G���g���@�C�G��",1957,1,.@mdnpc$+ "::OnKilled";
	monster .@mdmap$,72,93,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,70,87,"���@�̈�",1960,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,68,83,"�򉻂̈�",1961,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,70,80,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,74,81,"���@�̈�",1960,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,78,72,"���@�̈�",1960,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,81,70,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,78,84,"�����̈�",1959,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,85,72,"���@�̈�",1960,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,91,74,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,79,77,"�򉻂̈�",1961,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,82,80,"�����̈�",1959,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,87,83,"�����̈�",1959,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,80,92,"�򉻂̈�",1961,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,81,89,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,85,93,"���@�̈�",1960,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,86,90,"�����̈�",1959,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,88,88,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,91,87,"���@�̈�",1960,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,95,94,"���@�̈�",1960,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,91,96,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,90,82,"�򉻂̈�",1961,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,96,98,"���@�̈�",1960,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,83,76,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2";
	monster .@mdmap$,74,85,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2";
	switch(rand(3)) {
		case 0: monster .@mdmap$,82,85,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2"; break;
		case 1: monster .@mdmap$,82,85,"���@�̈�",1960,1,.@mdnpc$ +"::OnKilled2"; break;
		case 2: monster .@mdmap$,82,85,"�򉻂̈�",1961,1,.@mdnpc$ +"::OnKilled2"; break;
	}
	switch(rand(3)) {
		case 0: monster .@mdmap$,84,85,"�_���̈�",1958,1,.@mdnpc$ +"::OnKilled2"; break;
		case 1: monster .@mdmap$,84,85,"���@�̈�",1960,1,.@mdnpc$ +"::OnKilled2"; break;
		case 2: monster .@mdmap$,84,85,"�򉻂̈�",1961,1,.@mdnpc$ +"::OnKilled2"; break;
	}
	end;
OnKilled:
	killmonster getmdmapname("5@tower"),getmdnpcname("TowerControl5") +"::OnKilled2";
	announce "���̕s���̐� : �N���H�@����Ɏ��̃e���g���[�ɓ������҂́c�c",0x9,0xFFFF00;
	hideoffnpc getmdnpcname("����#Tower");
	hideonnpc getmdnpcname("�f�r����#Tower");
	end;
OnKilled2:
	end;
}

5@tower,106,109,0	script	����#Tower	111,{
	mes "-�����������������";
	mes "�@��Ȋ��o��������B";
	mes "�@�܂�ł���������}���Ă��邩��";
	mes "�@�悤���c�c-";
	next;
	mes "[���̕s���̐�]";
	mes "^FF0000�t�t�t�c�c";
	mes "���Ɗ��̏L���A������";
	mes "�r�����������邼�c�c";
	mes "�l�Ԃǂ��̖��d���ɂ�";
	mes "���ɂȂ��Ă��������s���ʁc�c^000000";
	next;
	mes "[���̕s���̐�]";
	mes "^FF0000�c�c���̏��܂ŗ��邱�Ƃ�";
	mes "�����Ă�낤�B";
	mes "���̈Ŗ�̔e���̏��܂łȁc�c^000000";
	close2;
	warp getmdmapname("6@tower"),32,12;
	end;
OnInit:
	hideonnpc;
	end;
}

//============================================================
// �G���h���X�^���[101F�`102F
//------------------------------------------------------------
6@tower,45,89,0	script	���̐�#Tower	111,{
	misceffect 14,"";
	mes "^0066FF-���z�I�Ŕ������������ނƁA";
	mes "�@�̒��Ɋ��͂��߂��Ă���̂�";
	mes "�@�킩����-^000000";
	percentheal 100,100;
	close;
OnInit:
OnTimer2000:
	misceffect 109;
	initnpctimer;
	end;
}

6@tower,32,100,0	script	TowerGate101	45,2,2,{
	donpcevent getmdnpcname("TowerControl6")+ "::OnStart";
	warp getmdmapname("6@tower"),155,64;
	end;
}

6@tower,0,0,0	script	TowerControl6	-1,{
OnStart:
	if(.lv > 0)
		end;
	set .lv,102;
	areamonster getmdmapname("6@tower"),154,73,156,75,"�Ď��҃E�B���X",1627,10,getmdnpcname("TowerControl6")+ "::OnKilled";
	end;
OnKilled:
	set .count,getmapmobs(getmdmapname("6@tower"),getmdnpcname("TowerControl6")+ "::OnKilled");
	if(.count > 0)
		end;
	sleep 500;
	announce "���̕s���̐� : �������c�c�������ǂ�ȏꏊ�����m�炸�Ɂc�c",0x9,0x00FFCC;
	sleep 5000;
	announce "���̕s���̐� : ���O��`���҂ǂ��͂����������B�����A���̗E�C�����͖J�߂Ă�낤�B",0x9,0x00FFCC;
	sleep 5000;
	announce "���̕s���̐� : �����ɑ��𓥂ݓ��ꂽ����ɂ́A�����Ɋy���܂��ĖႤ���B",0x9,0x00FFCC;
	sleep 5000;
	announce "���̕s���̐� : ���͒�����ǂ����K���ɂȂ��ĉE����������l������̂��D�����B",0x9,0x00FFCC;
	sleep 5000;
	announce "���̕s���̐� : �����A���̎����ǂ��܂Ŋy���܂��Ă���邩�ȁH",0x9,0x00FFCC;
	areamonster getmdmapname("6@tower"),152,66,152,106,"���̎�앺",1152,50,getmdnpcname("TowerControl6")+ "::OnKilled2";
	areamonster getmdmapname("6@tower"),159,66,159,106,"���̎�앺",1152,50,getmdnpcname("TowerControl6")+ "::OnKilled2";
	end;
OnKilled2:
	set .count,getmapmobs(getmdmapname("6@tower"),getmdnpcname("TowerControl6")+ "::OnKilled2");
	if(.count > 0) {
		announce "�c��[" +.count+ "]�C",0x9,0x00FF99;
		end;
	}
	sleep 500;
	announce "���̕s���̐� : �c�c�ӂށB�܂��A��n�߂Ƃ��Ă͏��X������Ȃ��������H",0x9,0x00FFCC;
	sleep 5000;
	announce "���̕s���̐� : �ł́A�����h���𑝂₵�Ă�낤�B",0x9,0x00FFCC;
	sleep 5000;
	announce "���̕s���̐� : �����A���͂ǂ����ȁH",0x9,0x00FFCC;
	areamonster getmdmapname("6@tower"),152,66,152,106,"���̎�앺",1263,30,getmdnpcname("TowerControl6")+ "::OnKilled3";
	areamonster getmdmapname("6@tower"),159,66,159,106,"���̎�앺",1263,30,getmdnpcname("TowerControl6")+ "::OnKilled3";
	end;
OnKilled3:
	set .count,getmapmobs(getmdmapname("6@tower"),getmdnpcname("TowerControl6")+ "::OnKilled3");
	if(.count > 0) {
		announce "�c��[" +.count+ "]�C",0x9,0x00FF99;
		end;
	}
	sleep 500;
	announce "���̕s���̐� : �t�t�A�����͂��悤���ȁI",0x9,0x00FFCC;
	sleep 5000;
	announce "���̕s���̐� : ���΂ɂ����܂ŗ��������͂���B�o���Ă�낤�A���O��̖��O���B",0x9,0x00FFCC;
	sleep 5000;
	announce "���̕s���̐� : �c�c�����������A�c��̎�앺�ł��y����ł���B",0x9,0x00FFCC;
	areamonster getmdmapname("6@tower"),152,66,152,106,"�n�̎�앺",1132,20,getmdnpcname("TowerControl6")+ "::OnKilled4";
	areamonster getmdmapname("6@tower"),159,66,159,106,"�n�̎�앺",1132,20,getmdnpcname("TowerControl6")+ "::OnKilled4";
	end;
OnKilled4:
	set .count,getmapmobs(getmdmapname("6@tower"),getmdnpcname("TowerControl6")+ "::OnKilled4");
	if(.count > 0) {
		announce "�c��[" +.count+ "]�C",0x9,0x00FF99;
		end;
	}
	sleep 500;
	announce "���̕s���̐� : �c�c�悩�낤�I�@���x�͎������肾�I",0x9,0x00FFCC;
	sleep 5000;
	announce "���̕s���̐� : �������҂��A�C�ɂȂ�̂��ˁH�@�c�c���͈Ŗ�̔e���A�i�n�g�Y�B�[�K�[�I",0x9,0x00FFCC;
	sleep 5000;
	announce "�i�n�g�Y�B�[�K�[ : �c�c�����A���O�𕷂�������ɂ͎���ł��炤�I�@�s����!!",0x9,0x00FFCC;
	monster getmdmapname("6@tower"),156,147,"�i�n�g�Y�B�[�K�[",1956,1,getmdnpcname("TowerControl6")+ "::OnKilled5";
	end;
OnKilled5:
	hideoffnpc getmdnpcname("�f�r����#Tower");
	initnpctimer getmdnpcname("�f�r����#Tower");
	sleep 500;
	announce "�i�n�g�Y�B�[�K�[ : �΁A�n���ȁc�c!!�@���̎����c�c�s��邾�Ɓc�c!?",0x9,0xFFFF00;
	sleep 5000;
	announce "�i�n�g�Y�B�[�K�[ : ������!!�@��A���̑̂����c�c!!",0x9,0xFFFF00;
	sleep 5000;
	announce "�i�n�g�Y�B�[�K�[�͍����D�ɂȂ�A�󒆂ɔ�U���Ă������c�c",0x9,0x00FFCC;
	end;
}

6@tower,169,127,2	script	�f�r����#Tower	796,{
	if((MaxWeight - Weight) < 1000) {
		mes "-�����A�C�e���̎�ސ���������";
		mes "�@�댯�ł��B";
		mes "�@�����A�C�e�������炵�Ă���A";
		mes "�@�ēx�b�������Ă�������-";
		close;
	}
	mes "[�f�r����]";
	mes "^FF0000���Ȃ��ł������c�c";
	mes "�׈��ȃi�n�g�Y�B�[�K�[����";
	mes "��������������Ă��ꂽ�l�́B^000000";
	next;
	mes "[�f�r����]";
	mes "^FF0000����ł���ƈÂ��Ď����ۂ�";
	mes "��������o���܂��B^000000";
	next;
	if(countitem(13412) && countitem(13413)) {
		mes "[�f�r����]";
		mes "^FF0000��H";
		mes "���Ȃ���";
		mes "�i�n�g�Y�B�[�K�[�̌���";
		mes "���������Ă��܂��ˁB^000000";
		next;
		mes "[�f�r����]";
		mes "^FF0000�����͕Ў茕�ł����A";
		mes "���Ȃ������ǂ����";
		mes "��������������1�{�̗��茕��";
		mes "�ς��Ă����܂���H";
		mes "���ꂪ������ł���B���";
		mes "���Ԃ��ł��c�c^000000";
		next;
		if(select("���茕�ɂ���","���̂܂܂ł���") == 1) {
			mes "[�f�r����]";
			mes "^FF0000������܂����B";
			mes "�ł͓�̌������킹��";
			mes "���茕�ɂ��Ă����܂��傤�B^000000";
			next;
			delitem 13412,1;
			delitem 13413,1;
			getitem 1185,1;
		}
		else {
			// ������
			mes "[�f�r����]";
			mes "^FF0000������܂����B";
			mes "��̌��͂��̂܂܂̏�Ԃ�";
			mes "���Ă����܂��傤�B^000000";
			next;
		}
		mes "[�f�r����]";
		mes "^FF0000�����Ƙb���������ł����A";
		mes "���������ɂ�����̂�";
		mes "���Ƃ��������͂��c�c^000000";
		next;
	}
	mes "[�f�r����]";
	mes "^FF0000�ł́A���ʂ�̎��Ԃł��B";
	mes "���B�҂ŁA���肪�Ƃ��B^000000";
	close2;
	warp "alberta",223,36;
	end;
OnInit:
	hideonnpc;
	end;
OnTimer1000:
	misceffect 71;
	initnpctimer;
	end;
}