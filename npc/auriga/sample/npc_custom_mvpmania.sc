prontera,267,48,1	script	MVP�}�j�A::MVPMania	862,{
	if (!MVP_MANIA_INTRODUCTION) {
		mes "[�R���b�g]";
		mes "MVP���Ă�����ˁc�c";
		next;
		mes "[�R���b�g]";
		mes "����^FF4040���l�u�o�I��^000000����";
		mes "�G�t�F�N�g�̏o��u�Ԃ�";
		mes "���܂�Ȃ��̂�˂��c�c";
		next;
		mes "[�R���b�g]";
		mes "���Ȃ��������v���ł���H";
		next;
		if (select("�͂�", "������") == 1) {
			emotion ET_SPARK;
			mes "[�R���b�g]";
			mes "����ς�������ˁ[�I";
			mes "���Ȃ��A�����݂��邩���B";
			next;
		} else {
			emotion ET_HUK;
			mes "[�R���b�g]";
			mes "�����[�I�H";
			mes "���̗ǂ����킩��Ȃ��Ȃ��";
			mes "��Α����Ă��I";
			next;
		}
		set MVP_MANIA_INTRODUCTION, 1;
		mes "[�R���b�g]";
		mes "�܁A����͂����Ƃ��āc�c";
		next;
		mes "[�R���b�g]";
		mes "���߂܂��āA���R���b�g�B";
		mes "MVP�̋L�^�W������Ă�́B";
		next;
		mes "[�R���b�g]";
		mes "���܂łɊl������MVP��";
		mes "�������Ƃ��͎��Ɍ����ĂˁB";
		mes "�S�����X�g�ɋL�^���Ă��邩��B";
		next;
		mes "[�R���b�g]";
		mes "�������Ă݂�H";
		next;
	} else {
		mes "[�R���b�g]";
		mes "��������悤�A^4040FF" + strcharinfo(0) + "^000000����B";
		mes "MVP���X�g���������̂��ȁH";
		next;
	}
	querymvpstats .@rou, .@mobs;
	if (select("����", "���Ȃ�") == 1) {
		setarray .@cols$, "^FF4040", "^4040FF";
		setarray .@vals$, "���l��", "�l���ς�";
		setarray .@mids, 
			1038, 1039, 1046, 1059, 1086,
			1087, 1112, 1115, 1147, 1150,
			1157, 1159, 1190, 1251, 1252,
			1272, 1312, 1373, 1389, 1418,
			1492, 1511, 1583, 1623, 1630,
			1646, 1647, 1648, 1649, 1650,
			1651, 1658, 1685, 1688, 1708,
			1719, 1734, 1751, 1768, 1779,
			1785, 1832, 1871, 1874, 1885,
			1917, 2068;
		set .@mids_siz, getarraysize(.@mids);
		for (set .@i, 0; .@i < .@mids_siz; ++.@i) {
			if (!.@ind) mes "------ MVP���X�g (" + (.@i / 5 + 1) + ") ------"; 
			set .@acq, pchasacquiredmvp(.@mids[.@i]);
			if (!.@acq) set .@not_all, 1;
			mes .@cols$[.@acq] + strmobinfo(2, .@mids[.@i]) + " " + .@vals$[.@acq] + "^000000";
			set .@ind, .@ind + 1;
			if (.@ind >= 5 ||
				.@i + 1 == .@mids_siz
			) {
				next;
				set .@ind, 0;
			}
		}
		if (!.@not_all) {
			if (.@rou) {
				mes "[�R���b�g]";
				mes "�����A�܂��S���|�����́H�I";
				mes "�������`�A�����y��������";
				next;
				emotion ET_SMILE;
				mes "[�R���b�g]";
				mes "����Ȃ�MVP���l������Ȃ��";
				mes "���Ȃ������h��MVP�}�j�A���ˁB";
				next;
			} else {
				mes "[�R���b�g]";
				mes "����A�����[���I";
				mes "�S���l�����Ă邶���I";
				next;
				emotion ET_THROB;
				mes "[�R���b�g]";
				mes "���Ȃ��Ƃ��Ă����������̂ˁB";
				mes "������ƌ�������������c�c";
				next;
			}
			
			set .@pla_rid, getcharid(3);
			mes "[�R���b�g]";
			mes "�����^4040FF�I�[��MVP^000000�B���̕�V�Ƃ���";
			mes "�����o�[�̂����̒N��^FF40401�l����^000000��";
			mes "^4040FF����^000000���邱�Ƃ��ł����B";
			next;
			mes "[�R���b�g]";
			mes "�����o�[��^4040FF����^000000���s����";
			mes "�܂��X�e�[�^�X�|�C���g��";
			mes "^FF4040200�|�C���g^000000�Ⴆ���B";
			mes "��C�Ƀp���[�A�b�v���ˁB";
			next;
			mes "[�R���b�g]";
			mes "����ɃX�L���|�C���g��";
			mes "^FF404010�|�C���g^000000���Ⴆ���Ⴄ�B";
			mes "����ő���Ȃ������X�L����";
			mes "�Q�b�g�ł��邩���H";
			next;
			set .@mem_siz, getmemberlist(.@mem_rids, .@mem_cids, .@mem_nams$, .@mem_clas);
			for (set .@i, 0; .@i < .@mem_siz; ++.@i)
				set .@mem_lis$[.@i], "^4040FF" + .@mem_nams$[.@i] + "^000000";
			set .@mem_lis$[.@i], "��߂�";
			while (1) {
				mes "[�R���b�g]";
				mes "^4040FF����^000000�͂ƂĂ��厖�Ȃ��Ƃ�����";
				mes "�悭�l���ĐT�d�ɑI��łˁB";
				mes "�ǂ̃����o�[��^4040FF����^000000����́H";
				next;
				set .@mem_ind, select(printarray(.@mem_lis$)) - 1;
				if (.@mem_ind >= .@mem_siz) {
					mes "[�R���b�g]";
					mes "��������l�����ق���������B";
					mes "���܂�����܂����������ĂˁB";
					close;
				}
				if (attachrid(.@mem_rids[.@mem_ind])) {
					set .@mem_enh, MVP_MANIA_ENHANCE;
					attachrid .@pla_rid;
					set .@mem_cla, .@mem_clas[.@mem_ind];
					if (.@mem_enh) {
						mes "[�R���b�g]";
						mes "^4040FF" + .@mem_nams$[.@mem_ind] + "^000000�����";
						mes "����^FF4040�����ς�^000000������_������B";
						next;
					} else if (!canenhance(.@mem_cla)) {
						mes "[�R���b�g]";
						mes "^4040FF" + .@mem_nams$[.@mem_ind] + "^000000�����";
						mes "^FF4040�����ł��Ȃ��E��^000000������_������B";
						next;
					} else {
						mes "[�R���b�g]";
						mes "�{����^4040FF" + .@mem_nams$[.@mem_ind] + "^000000�����";
						mes "^4040FF����^000000���Ă����́H";
						next;
						if (select("�͂�", "������") == 1) break;
					}
				}
			}
			
			// �A�g�~�b�N
			if(checkitemblank() < 6 ||
				(MaxWeight - Weight) < .rews_wei
			) {
				mes "[�R���b�g]";
				mes "�c�c���ĉו����������Ă��j����";
				mes "�󂯎�ꂻ���ɂȂ��݂�������B";
				mes "�����q�ɂɗa���Ă��ĂˁB";
				close;
			}
			if (attachrid(.@mem_rids[.@mem_ind])) {
				if (!MVP_MANIA_ENHANCE) {
					set MVP_MANIA_ENHANCE, 1;
					addstatuspoint 200;
					addskillpoint 10;
					attachrid .@pla_rid;
					advancemvpround;
					++.@rou;
					for (set .@i, 0; .@i < getarraysize(.rews); ++.@i)
						getitem .rews[.@i], 1;
					
					specialeffect2 EF_POK_JAP;
					emotion ET_CONGRATULATION;
					soundeffect "complete.wav", 0;
					announce "[ " + strcharinfo(0) + " ]����" + .@rou + "��ڂ̃I�[��MVP��B�����܂����B", 0;
					mes "[�R���b�g]";
					mes "^4040FF�I�[��MVP^000000�A���߂łƂ��I";
					mes "^4040FF" + strcharinfo(0) + "^000000����̌��т�";
					mes "�o�b�`���L�^���Ƃ�����ˁI";
					next;
					if (.@rou == 1) {
						mes "[�R���b�g]";
						mes "����őS���l�������킯������";
						mes "�܂��I��肶��Ȃ���B";
						next;
						mes "[�R���b�g]";
						mes "MVP���D���ōD���ł��܂�Ȃ��B";
						mes "����Ȃ��Ȃ��Ȃ炫����";
						mes "1�����ᕨ����Ȃ��͂��c�c";
						next;
						mes "[�R���b�g]";
						mes "�Ƃ����킯�ŁA���]�݂Ȃ�";
						mes "�����ł��ł����Ⴂ�܂��B";
						next;
						emotion ET_SMILE;
						mes "[�R���b�g]";
						mes "MVP�}�j�A�̓��͂ǂ��܂ł�";
						mes "�ʂĂ��Ȃ������Ă����̂�I";
						mes "�ȁ[��ĂˁA�E�t�t�b��";
						next;
					}
					mes "[�R���b�g]";
					mes "�Ƃ肠�������̎���Ɍ�����";
					mes "���X�g�̓N���A���Ă����ˁB";
					next;
					mes "[�R���b�g]";
					mes "���Ǝ����獡��̂��j����";
					mes "�A�C�e����^FF4040" + getarraysize(.rews) + "��^000000�v���[���g�����B";
					next;
					emotion ET_SMILE;
					mes "[�R���b�g]";
					mes "�Ȃ�ł��`���҂Ȃ�N�����悾���";
					mes "���炷�_�����Ȃ񂾂��āB";
					mes "�悩������g���ĂˁB";
					next;
				} else attachrid .@pla_rid;
			}
		}
	}
	emotion ET_WRAP;
	mes "[�R���b�g]";
	if (.@rou) mes "���ꂶ��A^4040FF" + (.@rou + 1) + "����^000000���撣���ĂˁB";
	else mes "���ꂶ��A�撣���ĂˁB";
	mes "�o�C�o�[�C�I";
	close;
OnInit:
	setarray .rews,
		 2881, // �I�����A���l�b�N���X
		 5389, // ���_�̉���
		18539, // �X�J���L���b�v
		18720, // �}�W�J���u�[�X�^�[
		18937; // �������[�I�u���o�[�Y
	for (set .@i, 0; .@i < getarraysize(.rews); ++.@i)
		set .rews_wei, .rews_wei + getiteminfo(.rews[.@i], 6);
}
