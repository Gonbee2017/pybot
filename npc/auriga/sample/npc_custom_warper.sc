prontera,159,192,4	script	�|�^�K�[��	721,{
	cutin "kafra_07",2;
	mes "[�L�����[]";
	mes "�n�C�n�[�C�A���̕��h�]�[�B";
	mes "�ǂ���܂łł����[�H";
	mes "��x�s�������Ƃ̂���}�b�v�Ȃ�";
	mes "�ǂ��ł��I�b�P�[�ł���[�H";
	next;
	set .@nat_typs_siz, getarraysize(.nat_typs$);
	for (set .@i, 1; .@i < .@nat_typs_siz; ++.@i)
		set .@nat_typ_men$[getarraysize(.@nat_typ_men$)], "^4040FF" + .nat_typs$[.@i] + "^000000";
	set .@nat_typ_men$[getarraysize(.@nat_typ_men$)], "��߂܁[��";
	set .@nat_typ, select(printarray(.@nat_typ_men$));
	if (.@nat_typ < .@nat_typs_siz) {
		set .@map_typs_siz, getarraysize(.map_typs$);
		for (set .@i, 1; .@i < .@map_typs_siz; ++.@i)
			set .@map_typ_men$[getarraysize(.@map_typ_men$)], "^4040FF" + .map_typs$[.@i] + "^000000";
		set .@map_typ_men$[getarraysize(.@map_typ_men$)], "��߂܁[��";
		set .@map_typ, select(printarray(.@map_typ_men$));
		if (.@map_typ < .@map_typs_siz) {
			set .@maps_siz, querymemoinfos(.@nat_typ, .@map_typ, .@ids, .@xs, .@ys, .@enams$, .@jnams$);
			if (!.@maps_siz) {
				mes "[�L�����[]";
				mes "��������ʂ͓]���\�ȃ}�b�v��";
				mes "�܂��ЂƂ��Ȃ��݂����ł��ˁ[�B";
				next;
				mes "[�L�����[]";
				mes "��x�}�b�v�ɑ����^��ł���������";
				mes "�����̃���������Ă��Ă����������";
				mes "�]���ł���悤�ɂȂ�܂���[�B";
				next;
			} else {
				for (set .@i, 0; .@i < .@maps_siz; ++.@i)
					set .@map_men$[getarraysize(.@map_men$)], .@enams$[.@i];
				set .@map_men$[getarraysize(.@map_men$)], "��߂܁[��";
				set .@map_ind, select(printarray(.@map_men$)) - 1;
				if (.@map_ind < .@maps_siz) {
					mes "[�L�����[]";
					mes "�������̓]�����";
					mes "^4040FF" + .@jnams$[.@map_ind] + " (" + .@enams$[.@map_ind] + ")^000000";
					mes "�ł�낵���ł��ˁ[�H";
					mes "�������܂�܂����[�B";
					mes "����v^4040FF" + .fee + "Zeny^000000�ɂȂ�܁[���B";
					next;
					if (select("�����܁[��", "��߂܁[��") == 1) {
						if (Zeny < .fee) {
							mes "[�L�����[]";
							mes "���q���܁[�A��ώ���ł���";
							mes "������������Ă܂��[��B";
							next;
						} else {
							emotion ET_WRAP;
							mes "[�L�����[]";
							mes "���傤�����������܁[���B";
							mes "����ł͓]�����܂���[�B";
							mes "�����Ă�����Ⴂ�܂��[�B";
							close2;
							cutin "",255;
							if (Zeny >= .fee) {
								set Zeny, Zeny - .fee;
								specialeffect2 EF_TELEPORTATION2;
								warp .@enams$[.@map_ind], .@xs[.@map_ind], .@ys[.@map_ind];
							}
							end;
						}
					}
				}
			}
		}
	}
	mes "[�L�����[]";
	mes "�܂��ǂ����[�B";
	close2;
	cutin "",255;
	end;
OnInit:
	setarray .nat_typs$, "�s��", "���[���~�b�h�K�b�c����", "�V���o���c�o���h���a��", "�A���i�x���c����", "���̑��̍��X";
	setarray .map_typs$, "�s��", "�X", "�t�B�[���h", "�_���W����";
	set .fee, 10000;
}
prontera,161,193,4	script	��Սr�炵	448,{
	mes "[���C]";
	mes "���l�͈�Սr�炵�̃��C���B";
	mes "�_���W�������������ёO���B";
	mes "�悯��΂������ē����邺�H";
	next;
	for (set .@i, 0; .@i < getarraysize(.maps$); ++.@i)
		set .@map_men$[getarraysize(.@map_men$)], "^4040FF" + getmapnamejapanese(.maps$[.@i]) + " (" + .maps$[.@i] + ")^000000";
	set .@map_men$[getarraysize(.@map_men$)], "��߂�";
	set .@map_ind, select(printarray(.@map_men$)) - 1;
	if (.@map_ind < getarraysize(.maps$)) {
		set .@x, .xy_fees[.@map_ind * 3 + 0];
		set .@y, .xy_fees[.@map_ind * 3 + 1];
		set .@fee, .xy_fees[.@map_ind * 3 + 2];
		mes "[���C]";
		mes "^4040FF" + getmapnamejapanese(.maps$[.@map_ind]) + "^000000���c�c";
		mes "�����Ȃ�^4040FF" + .@fee + "^000000Zeny��";
		mes "�����Ȃ��Ɗ��ɍ���ˁ[�ȁB";
		next;
		if (select("����", "��߂�") == 1) {
			if (Zeny < .@fee) {
				mes "[���C]";
				mes "�����Ƌ�������ĂȂ����B";
				mes "�܂����x���Ă����ȁB";
				close;
			}
			emotion ET_DELIGHT;
			mes "[���C]";
			mes "��[���A�����󂯂����B";
			mes "���������o�����邼�B";
			mes "���l�̂��Ƃɂ��Ă��ȁB";
			close2;
			if (Zeny >= .@fee) {
				set Zeny, Zeny - .@fee;
				specialeffect2 EF_TELEPORTATION2;
				warp .maps$[.@map_ind], .@x, .@y;
			}
			end;
		}
	}
	mes "[���C]";
	mes "���ł����Ȃ�B";
	close;
OnInit:
	setarray .maps$[getarraysize(.maps$)], "abbey01";
	setarray .xy_fees[getarraysize(.xy_fees)], 51,15, 5000000;
	setarray .maps$[getarraysize(.maps$)], "ama_dun01";
	setarray .xy_fees[getarraysize(.xy_fees)], 229,10, 500000;
	setarray .maps$[getarraysize(.maps$)], "bra_dun01";
	setarray .xy_fees[getarraysize(.xy_fees)], 87,47, 1000000;
	setarray .maps$[getarraysize(.maps$)], "gefenia01";
	setarray .xy_fees[getarraysize(.xy_fees)], 58,169, 5000000;
	setarray .maps$[getarraysize(.maps$)], "kh_dun02";
	setarray .xy_fees[getarraysize(.xy_fees)], 41,198, 5000000;
	setarray .maps$[getarraysize(.maps$)], "lhz_dun01";
	setarray .xy_fees[getarraysize(.xy_fees)], 149,285, 1000000;
	setarray .maps$[getarraysize(.maps$)], "mosk_dun01";
	setarray .xy_fees[getarraysize(.xy_fees)], 201,269, 2000000;
	setarray .maps$[getarraysize(.maps$)], "ra_san02";
	setarray .xy_fees[getarraysize(.xy_fees)], 213,275, 10000000;
}
