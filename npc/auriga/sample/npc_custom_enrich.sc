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
	if(checkweight(.@gain,1)==0) {
		mes "�]�����A�C�e���̏d�ʂ��d����";
		mes "�@�댯�ł��B";
		mes "�@�����A�C�e�������炵�Ă���A";
		mes "�@�ēx�b�������Ă��������]";
		close;
	}
	delitem .@itemid,50;
	getitem .@gain,1;
	mes "["+strnpcinfo(3)+"]";
	mes "�ق�A�񑩂�" +getitemname(.@gain)+ "���B";
	mes "���ł��܂����Ă���B";
	close;
}

prontera,126,62,3	duplicate(ChangeEnrich)	�G�����b�q	84
