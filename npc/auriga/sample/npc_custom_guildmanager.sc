prontera,147,153,6	script	�M���h�}�l�[�W���[	109,{
	mes "[�`�F��]";
	mes "������ł͖`���҃M���h��";
	mes "�Ǘ����s���Ă���܂��B";
	next;

	set .@gui_id, getcharid(2);
	if (.@gui_id) {
		set .@gui_mas_id, getguildmasterid(.@gui_id);
		if (.@gui_mas_id == getcharid(0)) {
			set .@gui_nam$, getguildname(.@gui_id);
			getguildmember(.@gui_id, 1);
			getguildmember(.@gui_id, 0);
			set .@gui_mem_siz, $@guildmembercount;
			copyarray .@gui_mem_id, $@guildmembercid, .@gui_mem_siz;
			copyarray .@gui_mem_nam$, $@guildmembername$, .@gui_mem_siz;
		}
	}
	if (!.@gui_id ||
		.@gui_mas_id != getcharid(0)
	) {
		mes "[�`�F��]";
		mes "�{�T�[�r�X�̓M���h�}�X�^�[��";
		mes "���݂̂������p�ɂȂ�܂��B";
		close;
	}
	
	mes "[�`�F��]";
	mes "[ ^4040FF" + .@gui_nam$ + "^000000 ]��";
	mes "�M���h�}�X�^�[�𑼂̃����o�[��";
	mes "�ύX�Ȃ����܂����H";
	next;
	if (select("�͂�", "������") == 1) {
		mes "[�`�F��]";
		mes "����ł͂�����̃��X�g����";
		mes "�V�����M���h�}�X�^�[�ɂ���";
		mes "�����o�[�����I�т��������B";
		next;
		for (set .@i, 0; .@i < .@gui_mem_siz; ++.@i) {
			if (.@gui_mem_id[.@i] != .@gui_mas_id) {
				set .@mem_ids[getarraysize(.@mem_ids)], .@gui_mem_id[.@i];
				set .@mem_lis$[getarraysize(.@mem_lis$)], .@gui_mem_nam$[.@i];
			}
		}
		set .@mem_lis$[getarraysize(.@mem_lis$)], "��߂�";
		set .@mem_ind, select(printarray(.@mem_lis$)) - 1;
		if (.@mem_ind < getarraysize(.@mem_ids)) {
			set .@new_mas_id, .@mem_ids[.@mem_ind];
			set .@new_mas_nam$, .@mem_lis$[.@mem_ind];
			if (guildchangegm2(.@gui_id, .@new_mas_id)) {
				mes "[�`�F��]";
				mes "[ ^4040FF" + .@gui_nam$ + "^000000 ]��";
				mes "�M���h�}�X�^�[��";
				mes "[ ^4040FF" + .@new_mas_nam$ + "^000000 ]�l��";
				mes "�ύX���܂����B";
				mes "����ł͎��炢�����܂��B";
				close;
			}
		}
	}
	mes "[�`�F��]";
	mes "���ł����\�������������B";
	close;
}
