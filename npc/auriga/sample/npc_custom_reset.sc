prontera,152,192,5	script	���Z�b�g�E��	860,{
	setarray .@cou_str$, "����", "����", "�O��ڈȍ~";
	setarray .@fee, 1000000, 2000000, 3000000;
	if (RESET_FEE_RATE) {
		for (set .@i, 0; .@i < getarraysize(.@fee); ++.@i)
			set .@fee[.@i], .@fee[.@i] * RESET_FEE_RATE;
	}
	
	cutin "kafra_08",2;
	mes "[���[�b�^]";
	mes "��������Ⴂ�܂��B";
	mes "������ł̓X�L���ƃX�e�[�^�X��";
	mes "���Z�b�g���s���܂��B";
	next;
	mes "[���[�b�^]";
	mes "���Z�b�g������";
	mes .@cou_str$[0] + "�Ȃ�^4040FF" + .@fee[0] + "Zeny^000000�A";
	mes .@cou_str$[1] + "�Ȃ�^4040FF" + .@fee[1] + "Zeny^000000�A";
	mes .@cou_str$[2] + "�Ȃ�^4040FF" + .@fee[2] + "Zeny^000000�ł��B";
	next;
	mes "[���[�b�^]";
	mes "���q�l�͍���" + .@cou_str$[RESET_COUNT] + "�ł��̂�";
	mes "^4040FF" + .@fee[RESET_COUNT] + "Zeny^000000�ɂȂ�܂��B";
	mes "���Z�b�g�Ȃ����܂����H";
	next;
	if (select("���肢���܂�", "�K�v�Ȃ��ł�") == 1) {
		if (Zeny < .@fee[RESET_COUNT]) {
			mes "[�J�v���E��]";
			mes "���q�l�A����������܂���B";
			mes "�����������m���߂��������B";
		}
		else {
			set Zeny, Zeny - .@fee[RESET_COUNT];
			resetskill;
			resetstatus;
			specialeffect2 EF_DISPELL;
			soundeffect "_heal_effect.wav", 0;
			if (RESET_COUNT < 3 - 1) set RESET_COUNT, RESET_COUNT + 1;
			mes "[���[�b�^]";
			mes "���Z�b�g�������܂����B";
			mes "�����p���肪�Ƃ��������܂��B";
		}
	} else {
		mes "[���[�b�^]";
		mes "�܂��̂����p�����҂����Ă���܂��B";
	}
	close2;
	cutin "",255;
	end;
}
