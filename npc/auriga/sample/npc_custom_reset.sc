prontera,152,192,5	script	���Z�b�g�E��	860,{
	set .@fee, 1000000;
	if (RESET_FEE_RATE) set .@fee, .@fee * RESET_FEE_RATE;
	
	cutin "kafra_08",2;
	mes "[���[�b�^]";
	mes "��������Ⴂ�܂��B";
	mes "������ł̓X�L���ƃX�e�[�^�X��";
	mes "���Z�b�g���s���܂��B";
	next;
	mes "[���[�b�^]";
	mes "���Z�b�g������";
	mes "^4040FF" + .@fee + "Zeny^000000�ł��B";
	mes "���Z�b�g�Ȃ����܂����H";
	next;
	if (select("���肢���܂�", "�K�v�Ȃ��ł�") == 1) {
		if (Zeny < .@fee) {
			mes "[�J�v���E��]";
			mes "���q�l�A����������܂���B";
			mes "�����������m���߂��������B";
		}
		else {
			set Zeny, Zeny - .@fee;
			sc_end_class;
			resetskill;
			resetstatus;
			specialeffect2 EF_DISPELL;
			soundeffect "_heal_effect.wav", 0;
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
