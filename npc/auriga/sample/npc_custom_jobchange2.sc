prontera,150,193,5	script	2���]�E�W	125,{
	mes "[�W�F�u]";
	mes "������ł�2���E�ւ̓]�E��";
	mes "�s���Ă���܂��B";
	next;
	mes "[�W�F�u]";
	mes "�����𖞂�����1���E�̂�����";
	mes "�ǂȂ��ł��]�E���\�ł��B";
	next;
	if (JobLevel >= 40 &&
		!SkillPoint
	) {
		set .@jobs_siz, getarraysize(.jobs) / 3;
		for (set .@i, 0; .@i < .@jobs_siz; ++.@i) {
			set .@job_os, .@i * 3;
			if (Job == .jobs[.@job_os])
				set .@che_jobs[getarraysize(.@che_jobs)], .jobs[.@job_os + 1 + Sex];
		}
	}
	if (getarraysize(.@che_jobs)) {
		mes "[�W�F�u]";
		mes "�]�E�̂��߂ɗ�����A�C�e���Ȃǂ�";
		mes "��؂��������܂���B";
		next;
		mes "[�W�F�u]";
		mes "�������c�c1��������������܂��B";
		next;
		mes "[�W�F�u]";
		mes "����̓��Z�b�g�T�[�r�X�̗�����";
		mes "^FF0000�i�v��2�{^000000�ɂȂ�Ƃ������̂ł��B";
		next;
		mes "[�W�F�u]";
		mes "�]�E�����^FF0000�������ɂ͖߂��܂���^000000�̂�";
		mes "�悭���l���ɂȂ��Ă��������������B";
		next;
		mes "[�W�F�u]";
		mes "�c�c�ǂ��Ȃ����܂����H";
		next;
		for (set .@i, 0; .@i < getarraysize(.@che_jobs); ++.@i)
			set .@che_lis$[.@i], "^4040FF" + jobname(.@che_jobs[.@i]) + "^000000�ɓ]�E����";
		set .@che_lis$[getarraysize(.@che_lis$)], "��߂�";
		set .@che_ind, select(printarray(.@che_lis$)) - 1;
		if (.@che_ind < getarraysize(.@che_jobs)) {
			mes "[�W�F�u]";
			mes "�{����^4040FF" + jobname(.@che_jobs[.@che_ind]) + "^000000��";
			mes "�]�E�Ȃ����܂����H";
			next;
			if (select("�͂�", "������") == 1) {
				// �A�g�~�b�N
				set RESET_FEE_RATE, 2;
				nude;
				jobchange .@che_jobs[.@che_ind];
				
				mes "[�W�F�u]";
				mes "�����A�]�E�ł��܂�����B";
				mes "�����������F�肵�܂��B";
				close;
			}
		}
		mes "[�W�F�u]";
		mes "�����1�̑I���ł��B";
		mes "�撣���Ă��������B";
		close;
	}
	mes "[�W�F�u]";
	mes "��ώ���ł����A�����_�ł��q�l��";
	mes "���̃T�[�r�X�������p�ɂȂ邱�Ƃ�";
	mes "�ł��܂���B";
	close;
OnInit:
	setarray .jobs,
		Job_Swordman, Job_Knight, Job_Knight,
		Job_Acolyte, Job_Priest, Job_Priest,
		Job_Magician, Job_Wizard, Job_Wizard,
		Job_Merchant, Job_Blacksmith, Job_Blacksmith,
		Job_Archer, Job_Hunter, Job_Hunter,
		Job_Thief, Job_Assassin, Job_Assassin,
		Job_Swordman, Job_Crusader, Job_Crusader,
		Job_Acolyte, Job_Monk, Job_Monk,
		Job_Magician, Job_Sage, Job_Sage,
		Job_Thief, Job_Rogue, Job_Rogue,
		Job_Merchant, Job_Alchemist, Job_Alchemist,
		Job_Archer, Job_Dancer, Job_Bard,
		Job_Taekwon, Job_Star, Job_Star,
		Job_Taekwon, Job_Linker, Job_Linker;
}
