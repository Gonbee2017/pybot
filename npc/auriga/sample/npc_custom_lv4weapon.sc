prt_in,85,72,4	script	�����Ȓb�艮::Lv4Weapon	63,{
	mes "[�C�[�T��]";
	mes "�c�c�c�c";
	next;
	if (!LV4_WEAPON_INTRODUCE &&
		countitem(2268)
	) {
		set .@tab_nam$, getitemname(2268);
		if (select("^4040FF" + .@tab_nam$ + "^000000�������߂Ă݂�", "��߂�") == 1) {
			mes "[" + strcharinfo(0) + "]";
			mes "���́c�c�悩������";
			mes "���ꍷ���グ�܂��B";
			next;
			mes "[�C�[�T��]";
			mes "�c�c�c�c�I";
			next;
			mes "[�C�[�T��]";
			mes "���񂽁c�c";
			next;
			mes "[�C�[�T��]";
			mes "�C����������˂����B";
			next;
			
			// �A�g�~�b�N
			if (countitem(2268)) {
				delitem 2268, 1;
				set LV4_WEAPON_INTRODUCE, 1;
			}
			
		}
	}
	if (LV4_WEAPON_INTRODUCE) {
		mes "[�C�[�T��]";
		mes "��������p�����H";
		next;
		for (set .@i, 0; .@i < getarraysize(.weas); ++.@i) {
			set .@wea_nam$, getitemname(.weas[.@i]);
			set .@wea_slos, getitemslots(.weas[.@i]);
			if (.@wea_slos) set .@wea_nam$, .@wea_nam$ + " [" + .@wea_slos + "]";
			set .@wea_lis$[.@i], .@wea_nam$;
		}
		set .@wea_lis$[getarraysize(.@wea_lis$)], "��߂�";
		set .@wea_ind, select(printarray(.@wea_lis$)) - 1;
		if (.@wea_ind < getarraysize(.weas)) {
			set .@wea, .weas[.@wea_ind];
			set .@wea_nam$, .@wea_lis$[.@wea_ind];
			set .@ore_fir, 0;
			if (.@wea_ind) set .@ore_fir, .ore_bous[.@wea_ind - 1];
			set .@ores_siz, .ore_bous[.@wea_ind] - .@ore_fir;
			for (set .@i, 0; .@i < .@ores_siz; ++.@i) {
				set .@ore_bas, 2 * (.@ore_fir + .@i);
				set .@ore, .ores[.@ore_bas + 0];
				set .@ore_cou, .ores[.@ore_bas + 1];
				set .@ores[.@i], .@ore;
				set .@ore_nams$[.@i], getitemname(.@ore);
				set .@ore_cous[.@i], .@ore_cou;
			}
			
			// �A�g�~�b�N
			set .@hav_ores, 1;
			for (set .@i, 0; .@i < .@ores_siz; ++.@i) {
				if (countitem(.@ores[.@i]) < .@ore_cous[.@i]) {
					set .@hav_ores, 0;
					break;
				}
			}
			if (.@hav_ores) {
				for (set .@i, 0; .@i < .@ores_siz; ++.@i)
					delitem .@ores[.@i], .@ore_cous[.@i];
				getitem .@wea, 1;
				
				misceffect EF_REFINEOK;
				mes "[�C�[�T��]";
				mes "������A�ł������B";
				mes "�����Ă����ȁB";
				close;
			} else {
				mes "[�C�[�T��]";
				mes "^4040FF" + .@wea_nam$ + "^000000";
				mes "�����ɂ�";
				for (set .@i, 0; .@i < .@ores_siz; ++.@i)
					mes "^FF4040" + .@ore_nams$[.@i] + " " + .@ore_cous[.@i] + "��^000000";
				mes "���K�v�ɂȂ邺�B";
				next;
				mes "[�C�[�T��]";
				mes "�ǂ���ȒP�ɂ͓���ł��˂�";
				mes "�󏭂ȍz�΂΂��肾�B";
				mes "�܁A����΂�ȁB";
				close;
			}
		}
		mes "[�C�[�T��]";
		mes "���Ⴀ�ȁB";
		close;
	} else {
		mes "-�j�͖ق��Ďd�������Ă���B-";
		mes "-�^�o�R�̃j�I�C������B-";
		close;
	}
OnInit:
	set .weas[getarraysize(.weas)], 1141; // ���`��
	setarray .ores[getarraysize(.ores)],
		7295, 10; // ������
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 16024; // �J�h���[�� [2]
	setarray .ores[getarraysize(.ores)],
		7291, 30; // �߂̂�
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1526; // �X���b�V��
	setarray .ores[getarraysize(.ores)],
		7294, 30; // �g���R��
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 13031; // �\�[�h�u���C�J�[ [3]
	setarray .ores[getarraysize(.ores)],
		7297, 30; // ���_��
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 13032; // ���C���u���C�J�[ [3]
	setarray .ores[getarraysize(.ores)],
		7292, 30; // ���_��
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1367; // �X���[�^�[
	setarray .ores[getarraysize(.ores)],
		7296, 30; // �P��
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1134; // �V�U�[�Y�\�[�h
	setarray .ores[getarraysize(.ores)],
		7290, 30; // ���_��
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1365; // �T�o�X
	setarray .ores[getarraysize(.ores)],
		7293, 10; // �K�N����
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1139; // �e�C���t�B���O
	setarray .ores[getarraysize(.ores)],
		7289, 30; // �������
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1364; // �O���C�g�A�b�N�X
	setarray .ores[getarraysize(.ores)],
		7289, 10, // �������
		7294, 10, // �g���R��
		7291, 10; // �߂̂�
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1369; // �M���`��
	setarray .ores[getarraysize(.ores)],
		7289, 10, // �������
		7294, 10, // �g���R��
		7291, 10; // �߂̂�
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1469; // �����M�k�X�̑�
	setarray .ores[getarraysize(.ores)],
		7290, 10, // ���_��
		7296, 10, // �P��
		7293, 10; // �K�N����
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1470; // �u�����[�i�N
	setarray .ores[getarraysize(.ores)],
		7290, 10, // ���_��
		7296, 10, // �P��
		7293, 10; // �K�N����
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1132; // �G�b�W
	setarray .ores[getarraysize(.ores)],
		7294, 10, // �g���R��
		7297, 10, // ���_��
		7293, 10; // �K�N����
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1137; // �G�N�X�L�����o�[
	setarray .ores[getarraysize(.ores)],
		7294, 30, // �g���R��
		7297, 30, // ���_��
		7293, 30; // �K�N����
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1180; // �h���S���X���C���[ [2]
	setarray .ores[getarraysize(.ores)],
		7295, 30, // ������
		7296, 30, // �P��
		7290, 30; // ���_��
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1178; // �V���o�C�`�F���T�[�x�� [2]
	setarray .ores[getarraysize(.ores)],
		7295, 30, // ������
		7296, 30, // �P��
		7290, 30; // ���_��
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1816; // �x���Z���N [1]
	setarray .ores[getarraysize(.ores)],
		7292, 30, // ���_��
		7293, 30, // �K�N����
		7289, 30; // �������
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1720; // ���h���̋|
	setarray .ores[getarraysize(.ores)],
		7292, 10, // ���_��
		7293, 10, // �K�N����
		7289, 10; // �������
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1416; // �e�����O���e�B�[
	setarray .ores[getarraysize(.ores)],
		7297, 30, // ���_��
		7291, 30, // �߂̂�
		7295, 30; // ������
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1415; // ��
	setarray .ores[getarraysize(.ores)],
		7297, 10, // ���_��
		7291, 10, // �߂̂�
		7295, 10; // ������
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1140; // �ʉ_��
	setarray .ores[getarraysize(.ores)],
		7292, 10, // ���_��
		7291, 10, // �߂̂�
		7295, 10; // ������
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1228; // �R���o�b�g�i�C�t
	setarray .ores[getarraysize(.ores)],
		7292, 10, // ���_��
		7291, 10, // �߂̂�
		7295, 10; // ������
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1233; // �G�L�T�[�T�C�Y
	setarray .ores[getarraysize(.ores)],
		7296, 10, // �P��
		7294, 10, // �g���R��
		7290, 10; // ���_��
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
	
	set .weas[getarraysize(.weas)], 1540; // �O�����h�N���X [1]
	setarray .ores[getarraysize(.ores)],
		7296, 30, // �P��
		7294, 30, // �g���R��
		7290, 30; // ���_��
	set .ore_bous[getarraysize(.ore_bous)], getarraysize(.ores) / 2;
}
