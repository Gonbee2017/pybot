prontera,164,153,2	script	�V�j�A�R�[�f�B�l�[�^�[	878,{
	mes "[�V�j�A�R�[�f�B�l�[�^�[]";
	mes "����ɂ��́A�l�̓G���~�����B";
	mes "��]�̃J���[�������Ă�����";
	mes "���̐F�ŕ�����߂Ă������B";
	mes "�J���[��1�`" + .max_col + "�Ԃ܂ł��邼�B";
	next;
	input .@col;
	if (!.@col) {
		mes "[�G���~��]";
		mes "���������H";
		mes "�܂��������N�����痈�Ă����B";
		close;
	}
	if (.@col < 1 ||
		.@col > .max_col
	) {
		mes "[�G���~��]";
		mes "����H";
		mes "1�`" + .max_col + "�̔ԍ�����͂��Ă���Ȃ����H";
		close;
	}
	setlook LOOK_CLOTHES_COLOR, .@col;
	mes "[�G���~��]";
	mes "�����A�ł�����B";
	mes "����A�悭�������Ă�B";
	mes "�C����ς������Ȃ�����";
	mes "����܂����p���Ă���B";
	close;
OnInit:
	set .max_col, 35;
}
