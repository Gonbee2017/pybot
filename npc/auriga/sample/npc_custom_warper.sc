prontera,159,192,4	script	�|�^�K�[��	721,{
	cutin "kafra_07",2;
	mes "[�L�����[]";
	mes "�n�C�n�[�C�A���̕��h�]�[�B";
	mes "�ǂ���܂łł����[�H";
	mes "��x�s�������Ƃ̂���}�b�v�Ȃ�";
	mes "�ǂ��ł��I�b�P�[�ł���[�H";
	next;
	set .@nat_typs_siz, getarraysize(.nat_typs$);
	set .@nat_typ_lis$[0], "^4040FF�ŋ߂̗���^000000";
	for (set .@i, 1; .@i < .@nat_typs_siz; ++.@i)
		set .@nat_typ_lis$[getarraysize(.@nat_typ_lis$)], "^4040FF" + .nat_typs$[.@i] + "^000000";
	set .@nat_typ_lis$[getarraysize(.@nat_typ_lis$)], "��߂܁[��";
	set .@nat_typ, select(printarray(.@nat_typ_lis$)) - 1;
	if (!.@nat_typ) {
		for (set .@i, 0; .@i < .his_siz; ++.@i)
			set .@map_lis$[getarraysize(.@map_lis$)], WARPER_HIS_ENAMS$[.@i];
		set .@maps_siz, getarraysize(.@map_lis$);
		set .@map_lis$[getarraysize(.@map_lis$)], "��߂܁[��";
		set .@map_ind, select(printarray(.@map_lis$)) - 1;
		if (.@map_ind < .@maps_siz)
			callsub
				Pay,
				WARPER_HIS_ENAMS$[.@map_ind],
				WARPER_HIS_XS[.@map_ind],
				WARPER_HIS_YS[.@map_ind],
				getmapnamejapanese(WARPER_HIS_ENAMS$[.@map_ind]);
	} else if (.@nat_typ < .@nat_typs_siz) {
		set .@map_typs_siz, getarraysize(.map_typs$);
		for (set .@i, 1; .@i < .@map_typs_siz; ++.@i)
			set .@map_typ_lis$[getarraysize(.@map_typ_lis$)], "^4040FF" + .map_typs$[.@i] + "^000000";
		set .@map_typ_lis$[getarraysize(.@map_typ_lis$)], "��߂܁[��";
		set .@map_typ, select(printarray(.@map_typ_lis$));
		if (.@map_typ < .@map_typs_siz) {
			set .@maps_siz, queryjournalinfos(.@nat_typ, .@map_typ, .@ids, .@xs, .@ys, .@enams$, .@jnams$);
			if (!.@maps_siz) {
				mes "[�L�����[]";
				mes "��������ʂ͓]���\�ȃ}�b�v��";
				mes "�܂��ЂƂ��Ȃ��݂����ł��ˁ[�B";
				next;
				mes "[�L�����[]";
				mes "��x�}�b�v�ɑ����^��ł���������";
				mes "�W���[�i�����擾���Ă����������";
				mes "�]���ł���悤�ɂȂ�܂���[�B";
				next;
			} else {
				for (set .@i, 0; .@i < .@maps_siz; ++.@i)
					set .@map_lis$[getarraysize(.@map_lis$)], .@enams$[.@i];
				set .@map_lis$[getarraysize(.@map_lis$)], "��߂܁[��";
				set .@map_ind, select(printarray(.@map_lis$)) - 1;
				if (.@map_ind < .@maps_siz)
					callsub
						Pay,
						.@enams$[.@map_ind],
						.@xs[.@map_ind],
						.@ys[.@map_ind],
						.@jnams$[.@map_ind];
			}
		}
	}
	mes "[�L�����[]";
	mes "�܂��ǂ����[�B";
	close2;
	cutin "",255;
	end;
Pay:
	set .@enam$, getarg(0);
	set .@x, getarg(1);
	set .@y, getarg(2);
	set .@jnam$, getarg(3);
	mes "[�L�����[]";
	mes "�������̓]�����";
	mes "^4040FF" + .@jnam$ + " (" + .@enam$ + ")^000000";
	mes "�ł�낵���ł��ˁ[�H";
	mes "�������܂�܂����[�B";
	mes "����v^4040FF" + printzeny(.fee) + "Zeny^000000�ɂȂ�܁[���B";
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
				for (set .@i, 0; .@i < .his_siz - 1; ++.@i) {
					if (WARPER_HIS_ENAMS$[.@i] == "" ||
						WARPER_HIS_ENAMS$[.@i] == .@enam$
					) break;
				}
				for (; .@i; --.@i) {
					set .@j, .@i - 1;
					set WARPER_HIS_ENAMS$[.@i], WARPER_HIS_ENAMS$[.@j];
					set WARPER_HIS_XS[.@i], WARPER_HIS_XS[.@j];
					set WARPER_HIS_YS[.@i], WARPER_HIS_YS[.@j];
				}
				set WARPER_HIS_ENAMS$[0], .@enam$;
				set WARPER_HIS_XS[0], .@x;
				set WARPER_HIS_YS[0], .@y;
				specialeffect2 EF_TELEPORTATION2;
				warp .@enam$, .@x, .@y;
			}
			end;
		}
	}
	return;
OnInit:
	setarray .nat_typs$, "�s��", "���[���~�b�h�K�b�c����", "�V���o���c�o���h���a��", "�A���i�x���c����", "���̑��̍��X";
	setarray .map_typs$, "�s��", "�X", "�t�B�[���h", "�_���W����";
	set .his_siz, 3;
	set .fee, 10000;
}
prontera,161,193,4	script	��Սr�炵	448,{
	mes "[���C]";
	mes "���l�͈�Սr�炵�̃��C���B";
	mes "�_���W�������������ёO���B";
	mes "�悯��΂������ē����邺�H";
	next;
	for (set .@i, 0; .@i < getarraysize(.maps$); ++.@i)
		set .@map_lis$[getarraysize(.@map_lis$)], "^4040FF" + getmapnamejapanese(.maps$[.@i]) + " (" + .maps$[.@i] + ")^000000";
	set .@map_lis$[getarraysize(.@map_lis$)], "��߂�";
	set .@map_ind, select(printarray(.@map_lis$)) - 1;
	if (.@map_ind < getarraysize(.maps$)) {
		set .@x, .xy_fees[.@map_ind * 3 + 0];
		set .@y, .xy_fees[.@map_ind * 3 + 1];
		set .@fee, .xy_fees[.@map_ind * 3 + 2];
		mes "[���C]";
		mes "^4040FF" + getmapnamejapanese(.maps$[.@map_ind]) + "^000000���c�c";
		mes "�����Ȃ�^4040FF" + printzeny(.@fee) + "^000000Zeny��";
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
