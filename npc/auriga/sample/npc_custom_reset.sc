prontera,152,192,5	script	���Z�b�g�E��	860,{
	set .@siz, getarraysize(.fees);
	copyarray .@fees, .fees, .@siz;
	if (RESET_FEE_RATE) {
		for (set .@i, 0; .@i < .@siz; ++.@i)
			set .@fees[.@i], .@fees[.@i] * RESET_FEE_RATE;
	}
	cutin "kafra_08",2;
	mes "[���[�b�^]";
	mes "��������Ⴂ�܂��B";
	mes "������ł̓X�L���ƃX�e�[�^�X��";
	mes "���Z�b�g���s���Ă���܂��B";
	next;
	mes "[���[�b�^]";
	mes "���j���[�͂�����ł��B";
	for (set .@i, 0; .@i < .@siz; ++.@i)
		mes .names$[.@i] + " �c ^4040FF" + .@fees[.@i] + "Zeny^000000";
	mes "�ǂ�ɂȂ����܂����H";
	next;
	for (set .@i, 0; .@i < .@siz; ++.@i)
		set .@mens$[getarraysize(.@mens$)], .names$[.@i] + "�����Z�b�g";
	set .@mens$[getarraysize(.@mens$)], "�K�v�Ȃ��ł�";
	set .@men, select(printarray(.@mens$)) - 1;
	if (.@men == 3) {
		mes "[���[�b�^]";
		mes "�܂��̂����p�����҂����Ă���܂��B";
	} else {
		set .@fee, .@fees[.@men];
		if (Zeny < .@fee) {
			mes "[�J�v���E��]";
			mes "���q�l�A����������܂���B";
			mes "�����������m���߂��������B";
		} else {
			set Zeny, Zeny - .@fee;
			sc_end_class;
			if (.@men == 0 ||
				.@men == 2
			) resetskill;
			if (.@men == 1 ||
				.@men == 2
			) resetstatus;
			specialeffect2 EF_DISPELL;
			soundeffect "_heal_effect.wav", 0;
			mes "[���[�b�^]";
			mes "���Z�b�g�������܂����B";
			mes "�����p���肪�Ƃ��������܂��B";
		}
	}
	close2;
	cutin "",255;
	end;
OnInit:
	setarray .fees, 1000000, 1000000, 1500000;
	setarray .names$, "�X�L��", "�X�e�[�^�X", "����";
}
