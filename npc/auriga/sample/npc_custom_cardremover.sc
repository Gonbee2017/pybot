// Card removal NPC by TyrNemesis^ ���{���F�Ӓ���
prt_in,28,73,4	script	�����V��	78,{
	mes "[�����V��]";
	mes "�����V�C���ˁA�Ⴂ�́B";
	mes "�Ƃ���ŁA�A�^�V�͕���ɑ������Ă���";
	mes "�J�[�h�����O���͂������Ă��邯�ǁA";
	mes "�͂�݂������ˁH";
	next;
	if (select("���肢���܂�", "�K�v�Ȃ��ł�") == 1) {
		mes "[�����V��]";
		mes "�悵�悵�B";
		mes "�ǂ̕���̃J�[�h�����O���񂾂ˁH";
		next;
		set .@part, 
			select(
				"����ς��߂܂�",
				getequipname2(1),
				getequipname2(2),
				getequipname2(3),
				getequipname2(4),
				getequipname2(5),
				getequipname2(6),
				getequipname2(7),
				getequipname2(8),
				getequipname2(9),
				getequipname2(10)
			) - 1;
		if (.@part) {
			set .@count, getequipcardcnt(.@part);
			if(.@count <= 0) {
				mes "[�����V��]";
				mes "�Ⴂ�́A�J�[�h�����ĂȂ���B";
				mes "���ꂶ��A�^�V�̏o�Ԃ͂Ȃ����B";
				close;
			}
			mes "[�����V��]";
			mes "�����ƌ����Y���Ƃ��낾�����ˁB";
			mes "���̖��@�͂ƂĂ��������A";
			mes "^FF4040���s���邩������Ȃ�^000000�̂��B";
			mes "���s������J�[�h������A���邢��";
			mes "���̗�����^FF4040�j�󂳂�Ă��܂�^000000����";
			mes "����Ȃ��񂾂�B";
			next;
			mes "[�����V��]";
			mes "�ꉞ�����Ēu�����ǁA��ׂ�Ȃ�";
			mes "�J�[�h�ƕ���̂ǂ�������؂����H";
			next;
			set .@failtype, select("����Ȃ��߂܂�","����̕�����؂ł�","�J�[�h�̕�����؂ł�") - 1;
			if(.@failtype) {
				mes "[�����V��]";
				mes "�悵�A�n�߂��B";
				next;
				set .@rate, rand(100);
				if(.@rate <= 1) {
					failedremovecards .@part,0;
					mes "[�����V��]";
					mes "�c�O�����Ǌ��S�Ɏ��s������B";
					mes "������J�[�h�����Ă��܂����B";
					close;
				}
				if(.@rate <= 1 + 2) {
					failedremovecards .@part, .@failtype;
					if(.@failtype == 1) {
						mes "[�����V��]";
						mes "�撣�������ǂˁA";
						mes "�J�[�h�̂ق��͑S�����Ă��܂�����B";
						mes "�ł�����̕��͖�����������B";
					}
					else {
						mes "[�����V��]";
						mes "�s�^�������ˁB";
						mes "�J�[�h�����O���̂͂��܂�����������";
						mes "������Ă��܂�����B";
					}
					close;
				}
				if(.@rate <= 1 + 2 + 4) {
					failedremovecards .@part, 3;
					mes "[�����V��]";
					mes "�J�[�h�����O���̂Ɏ��s������B";
					mes "�ł��A�s�K���̍K�����B";
					mes "������J�[�h����������B";
					close;
				}
				successremovecards .@part;
				mes "[�����V��]";
				mes "���܂���������B";
				mes "����炪����ƃA�C�e�����B���Ⴀ�ˁB";
				close;
			}
		}
	}
	mes "[�����V��]";
	mes "�킩������B";
	mes "�A�^�V�̗͂��K�v�Ȃ炢�ł����ȁB";
	close;
}
