prontera,164,153,2	script	�������F�t	97,{
	mes "[�������F�t]";
	mes "����ɂ��́I";
	mes "���͊F�l�Ɍ��I�ȃX�^�C����";
	mes "�񋟂��ׂ��A�F�l�̂���������";
	mes "���������F�����Ē����ׂɎQ��܂����I";
	next;
	if (select("���F����", "��߂�") == 1) {
		mes "[�������F�t]";
		mes "�ǂ̔ԍ�����]����܂����H";
		mes "�ȉ��̃C���[�W�J���[�̒�����";
		mes "���D�݂̐F�����I�т��������B";
		next;
		set .@col, select(printarray(.col_lis$));
		if(.@col < getarraysize(.col_lis$)) {
			mes "[�������F�t]";
			mes "�������܂�܂����B";
			mes "����ł͑������F�����ɂ�����܂��I";
			mes "�G�C�b�I";
			next;
			mes "[�������F�t]";
			mes "�����ł��I";
			mes "�ǂ��ł��H�@�Y��ł��傤�H";
			mes "�����F�Ɍ����т炩��������";
			mes "�d���Ȃ��񂶂�Ȃ��ł����H";
			setlook LOOK_CLOTHES_COLOR, .@col;
			close;
		}
	}
	mes "[�������F�t]";
	mes "�����ł����c�c";
	mes "�܂��̋@������҂����Ă���܂��B";
	close;
OnInit:
	set .col_lis$[getarraysize(.col_lis$)], "1(�f�t�H���g)";
	set .col_lis$[getarraysize(.col_lis$)], "2(�G�N�X�g��1)";
	set .col_lis$[getarraysize(.col_lis$)], "3(�G�N�X�g��2)";
	set .col_lis$[getarraysize(.col_lis$)], "4^E3E3E3��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "5^CECCE0��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "6^D0D6F2��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "7^C2D8AF��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "8^CFEDED��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "9^BCD9F2��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "10^D0F3D0��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "11^DDB9AB��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "12^BBF7F7��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "13^ECCAC6��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "14^FFC4E2��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "15^CCE3FF��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "16^FFE2C4��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "17^D0ADA0��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "18^D6B8C7��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "19^FFF0C2��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "20^EFECCE��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "21^E5E2E2��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "22^FABBAB��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "23^FBB09B��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "24^FFBBD3��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "25^FBC58B��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "26^FFE1CF��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "27^EFC2DE��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "28^FFDEAC��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "29^FFE1B6��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "30^E3C4EC��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "31^EBC4A8��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "32^F9B0AC��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "33^FAE9BC��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "34^DEE6AB��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "35^EEDFD7��^000000";
	set .col_lis$[getarraysize(.col_lis$)], "��߂�";
}
