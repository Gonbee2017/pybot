prontera,64,55,4	script	�ςȃ^�k�L::PyBotDummyRaccoon	543,{
	mes "[�|����]";
	mes "�I�C���̓^�k�L�̃|�������Ă񂾁B";
	mes "�����X�^�[�ɉ�����̂����܂��񂾂��B";
	next;
	mes "[�|����]";
	mes "�Ȃ�ł��D���ȃ����X�^�[��";
	mes "^4040FF1���Ԃ���^000000�����Ă�邼�H";
	mes "�U�������Ă��Ă������B";
	next;
	if (select("���肢����", "�K�v�Ȃ���") == 1) {
		mes "[�|����]";
		mes "�C���b�A�������Ȃ�������B";
		mes "�����Ăق��������X�^�[�̖��O�́H";
		mes "�Ȃ�ł����������B";
		next;
		input .@mob_nam$;
		set .@mob_id, findmobdb(.@mob_nam$);
		if (!.@mob_id) {
			mes "[�|����]";
			mes "^4040FF" + .@mob_nam$ + "^000000�����āH";
			mes "����ȃ����X�^�[�m��Ȃ����B";
			close;
		}
		set .@mob_lv, strmobinfo(3, .@mob_id);
		set .@fee, 1000 * .@mob_lv;
		mes "[�|����]";
		mes "^4040FF" + .@mob_nam$ + "^000000���ȁH";
		mes "�����^FF4040" + .@fee + "Zeny^000000�����H";
		next;
		if (select("����", "��߂�") == 1) {
			if (Zeny < .@fee) {
				mes "[�|����]";
				mes "���O�c�c����������Ȃ����H";
				mes "�t���ϑ���o�J�ɂȂ�Ȃ��񂾂��B";
				close;
			}
			mes "[�|����]";
			mes "��[���A���ꂶ�ቻ���邼�B";
			close2;
			set Zeny, Zeny - .@fee;
			hideonnpc;
			dummymonster "this", 64, 55, "--ja--", .@mob_id, 1, "PyBotDummyRaccoon::OnDead";
			initnpctimer;
			end;
		}
	}
	mes "[�|����]";
	mes "�����[�A�P�`�Ȃ�����B";
	close;
OnDead:
	stopnpctimer;
	hideoffnpc;
	mes "[�|����]";
	mes "�A�C�^�^�^�c�c";
	mes "���O�c�c��肷�������B";
	close;
OnTimer60000:
	stopnpctimer;
	killmonster "this", "PyBotDummyRaccoon::OnDead";
	hideoffnpc;
	end;
}
