// [GonBee]
// �p�[�e�B�[BOT�@�\�̃��W�X�g���p�֐����`����B

#include "pybot_internal.hpp"

namespace pybot {

// -----------------------------------------------------------------------------
// ���W�X�g���p�֐��̒�`

// DB����J�[�g������[�A�C�e�����폜����֐������B
registry_t<int>::save_func // ������֐��B
delete_cart_auto_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid) {
		ses->execute(
			"DELETE FROM `pybot_cart_auto_get_item` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
	};
}

// DB���狗���|���V�[���폜����֐������B
registry_t<int,distance_policy>::save_func // ������֐��B
delete_distance_policy_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, distance_policy* dis_pol) {
		ses->execute(
			"DELETE FROM `pybot_distance_policy` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = " , construct<sql_param>(mid)
		);
	};
}

// DB���瑕���Z�b�g���폜����֐������B
registry_t<int,equipset_t>::save_func // ������֐��B
delete_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, equipset_t* equ_set) {
		ses->execute(
			"DELETE FROM `pybot_equipset` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = " , construct<sql_param>(mid)
		);
	};
}

// DB����O���[�g�����X�^�[���폜����֐������B
registry_t<int>::save_func // ������֐��B
delete_great_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int mid) {
		ses->execute(
			"DELETE FROM `pybot_great_mob` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` =  " , construct<sql_param>(mid)
		);
	};
}

// DB���疳���A�C�e�����폜����֐������B
registry_t<int>::save_func // ������֐��B
delete_ignore_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid) {
		ses->execute(
			"DELETE FROM `pybot_ignore_item` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
	};
}

// DB���琧���X�L�����폜����֐������B
registry_t<int,int>::save_func // ������֐��B
delete_limit_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int kid, int* klv) {
		ses->execute(
			"DELETE FROM `pybot_limit_skill` "
			"WHERE"
			" `char_id` = " , construct<sql_param>(cid), " AND"
			" `skill_id` = ", construct<sql_param>(kid)
		);
	};
}

// DB����ʏ�U���|���V�[���폜����֐������B
registry_t<int,normal_attack_policy>::save_func // ������֐��B
delete_normal_attack_policy_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, normal_attack_policy* nor_att_pol) {
		ses->execute(
			"DELETE FROM `pybot_normal_attack_policy` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = " , construct<sql_param>(mid)
		);
	};
}

// DB���牉�t�X�L�����폜����֐������B
registry_t<int,play_skill>::save_func // ������֐��B
delete_play_skill_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, play_skill* pla_ski) {
		ses->execute(
			"DELETE FROM `pybot_play_skill` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = " , construct<sql_param>(mid)
		);
	};
}

// DB����HP�񕜃A�C�e�����폜����֐������B
registry_t<int,int>::save_func // ������֐��B
delete_recover_hp_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* thr) {
		ses->execute(
			"DELETE FROM `pybot_recover_hp_item` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
	};
}

// DB����SP�񕜃A�C�e�����폜����֐������B
registry_t<int,int>::save_func // ������֐��B
delete_recover_sp_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* thr) {
		ses->execute(
			"DELETE FROM `pybot_recover_sp_item` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
	};
}

// DB���狑�ۃX�L�����폜����֐������B
registry_t<int>::save_func // ������֐��B
delete_reject_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int kid) {
		ses->execute(
			"DELETE FROM `pybot_reject_skill` "
			"WHERE"
			" `char_id` = " , construct<sql_param>(cid), " AND"
			" `skill_id` = ", construct<sql_param>(kid)
		);
	};
}

// DB���甄�p�A�C�e�����폜����֐������B
registry_t<int>::save_func // ������֐��B
delete_sell_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid) {
		ses->execute(
			"DELETE FROM `pybot_sell_item` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
	};
}

// DB����q�ɕ�[�A�C�e�����폜����֐������B
registry_t<int,int>::save_func // ������֐��B
delete_storage_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* amo) {
		ses->execute(
			"DELETE FROM `pybot_storage_get_item` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
	};
}

// DB����q�Ɋi�[�A�C�e�����폜����֐������B
registry_t<int>::save_func // ������֐��B
delete_storage_put_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid) {
		ses->execute(
			"DELETE FROM `pybot_storage_put_item` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
	};
}

// DB�ɃJ�[�g������[�A�C�e����}������֐������B
registry_t<int>::save_func // ������֐��B
insert_cart_auto_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid) {
		ses->execute(
			"INSERT INTO `pybot_cart_auto_get_item` "
			"VALUES "
			"(", construct<sql_param>(cid ), ","
			" ", construct<sql_param>(nid ), ")"
		);
	};
}

// DB�ɋ����|���V�[��}������֐������B
registry_t<int,distance_policy>::save_func // ������֐��B
insert_distance_policy_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, distance_policy* dis_pol) {
		ses->execute(
			"INSERT INTO `pybot_distance_policy` "
			"VALUES "
			"(", construct<sql_param>(cid                ), ","
			" ", construct<sql_param>(mid                ), ","
			" ", construct<sql_param>(int(dis_pol->value)), ")"
		);
	};
}

// DB�ɑ����Z�b�g��}������֐������B
registry_t<int,equipset_t>::save_func // ������֐��B
insert_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, equipset_t* equ_set) {
		for (auto esi : equ_set->items) {
			ses->execute(
				"INSERT INTO `pybot_equipset` "
				"VALUES "
				"(", construct<sql_param>(cid              ), ","
				" ", construct<sql_param>(mid              ), ","
				" ", construct<sql_param>(esi->order       ), ","
				" ", construct<sql_param>(esi->equip       ), ","
				" ", construct<sql_param>(esi->key->nameid ), ","
				" ", construct<sql_param>(esi->key->card[0]), ","
				" ", construct<sql_param>(esi->key->card[1]), ","
				" ", construct<sql_param>(esi->key->card[2]), ","
				" ", construct<sql_param>(esi->key->card[3]), ")"
			);
		}
	};
}

// DB�ɃO���[�g�����X�^�[��}������֐������B
registry_t<int>::save_func // ������֐��B
insert_great_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int mid) {
		ses->execute(
			"INSERT INTO `pybot_great_mob` "
			"VALUES "
			"(", construct<sql_param>(cid), ","
			" ", construct<sql_param>(mid), ")"
		);
	};
}

// DB�ɖ����A�C�e����}������֐������B
registry_t<int>::save_func // ������֐��B
insert_ignore_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid) {
		ses->execute(
			"INSERT INTO `pybot_ignore_item` "
			"VALUES "
			"(", construct<sql_param>(cid), ","
			" ", construct<sql_param>(nid), ")"
		);
	};
}

// DB�ɐ����X�L����}������֐������B
registry_t<int,int>::save_func // ������֐��B
insert_limit_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int kid, int* klv) {
		ses->execute(
			"INSERT INTO `pybot_limit_skill` "
			"VALUES "
			"(", construct<sql_param>(cid ), ","
			" ", construct<sql_param>(kid ), ","
			" ", construct<sql_param>(*klv), ")"
		);
	};
}

// DB�ɒʏ�U���|���V�[��}������֐������B
registry_t<int,normal_attack_policy>::save_func // ������֐��B
insert_normal_attack_policy_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, normal_attack_policy* nor_att_pol) {
		ses->execute(
			"INSERT INTO `pybot_normal_attack_policy` "
			"VALUES "
			"(", construct<sql_param>(cid                    ), ","
			" ", construct<sql_param>(mid                    ), ","
			" ", construct<sql_param>(int(nor_att_pol->value)), ")"
		);
	};
}

// DB�ɉ��t�X�L����}������֐������B
registry_t<int,play_skill>::save_func // ������֐��B
insert_play_skill_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, play_skill* pla_ski) {
		ses->execute(
			"INSERT INTO `pybot_play_skill` "
			"VALUES "
			"(", construct<sql_param>(cid                   ), ","
			" ", construct<sql_param>(mid                   ), ","
			" ", construct<sql_param>(int(pla_ski->skill_id)), ")"
		);
	};
}

// DB��HP�񕜃A�C�e����}������֐������B
registry_t<int,int>::save_func // ������֐��B
insert_recover_hp_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* thr) {
		ses->execute(
			"INSERT INTO `pybot_recover_hp_item` "
			"VALUES "
			"(", construct<sql_param>(cid ), ","
			" ", construct<sql_param>(nid ), ","
			" ", construct<sql_param>(*thr), ")"
		);
	};
}

// DB��SP�񕜃A�C�e����}������֐������B
registry_t<int,int>::save_func // ������֐��B
insert_recover_sp_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* thr) {
		ses->execute(
			"INSERT INTO `pybot_recover_sp_item` "
			"VALUES "
			"(", construct<sql_param>(cid ), ","
			" ", construct<sql_param>(nid ), ","
			" ", construct<sql_param>(*thr), ")"
		);
	};
}

// DB�ɋ��ۃX�L����}������֐������B
registry_t<int>::save_func // ������֐��B
insert_reject_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int kid) {
		ses->execute(
			"INSERT INTO `pybot_reject_skill` "
			"VALUES "
			"(", construct<sql_param>(cid), ","
			" ", construct<sql_param>(kid), ")"
		);
	};
}

// DB�ɔ��p�A�C�e����}������֐������B
registry_t<int>::save_func // ������֐��B
insert_sell_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid) {
		ses->execute(
			"INSERT INTO `pybot_sell_item` "
			"VALUES "
			"(", construct<sql_param>(cid), ","
			" ", construct<sql_param>(nid), ")"
		);
	};
}

// DB�ɑq�ɕ�[�A�C�e����}������֐������B
registry_t<int,int>::save_func // ������֐��B
insert_storage_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* amo) {
		ses->execute(
			"INSERT INTO `pybot_storage_get_item` "
			"VALUES "
			"(", construct<sql_param>(cid ), ","
			" ", construct<sql_param>(nid ), ","
			" ", construct<sql_param>(*amo), ")"
		);
	};
}

// DB�ɑq�Ɋi�[�A�C�e����}������֐������B
registry_t<int>::save_func // ������֐��B
insert_storage_put_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid) {
		ses->execute(
			"INSERT INTO `pybot_storage_put_item` "
			"VALUES "
			"(", construct<sql_param>(cid ), ","
			" ", construct<sql_param>(nid ), ")"
		);
	};
}

// DB����J�[�g������[�A�C�e�������[�h����֐������B
registry_t<int>::load_func // ������֐��B
load_cart_auto_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int>* reg) {
		int nid;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("nameid", nid), "` "
			"FROM `pybot_cart_auto_get_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(nid);
	};
}

// DB���狗���|���V�[�����[�h����֐������B
registry_t<int,distance_policy>::load_func // ������֐��B
load_distance_policy_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, registry_t<int,distance_policy>* reg) {
		int mid;
		int val;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("mob_id", mid), "`,"
			" `", construct<sql_column>("value" , val), "` "
			"FROM `pybot_distance_policy` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row())
			reg->register_(mid, construct<distance_policy>(mid, distance_policy_values(val)));
	};
}

// DB���瑕���Z�b�g�����[�h����֐������B
registry_t<int,equipset_t>::load_func // ������֐��B
load_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, registry_t<int,equipset_t>* reg) {
		int mid;
		int ord;
		int equ;
		uint16_t nid;
		uint16_t car[MAX_SLOTS];
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("mob_id", mid   ), "`,"
			" `", construct<sql_column>("order" , ord   ), "`,"
			" `", construct<sql_column>("equip" , equ   ), "`,"
			" `", construct<sql_column>("nameid", nid   ), "`,"
			" `", construct<sql_column>("card0" , car[0]), "`,"
			" `", construct<sql_column>("card1" , car[1]), "`,"
			" `", construct<sql_column>("card2" , car[2]), "`,"
			" `", construct<sql_column>("card3" , car[3]), "` "
			"FROM `pybot_equipset` "
			"WHERE `char_id` = ", construct<sql_param>(cid), " "
			"ORDER BY"
			" `mob_id`,"
			" `order`"
		);
		ptr<equipset_t> equ_set;
		auto flu = [reg, &equ_set] () {
			if (equ_set) reg->register_(equ_set->mob_id, equ_set);
		};
		while (ses->next_row()) {
			if (!equ_set ||
				mid != equ_set->mob_id
			) {
				flu();
				equ_set = construct<equipset_t>(mid);
			}
			auto ik = construct<item_key>(nid, car);
			auto ei = initialize<equipset_item>(equip_pos_orders(ord), equip_pos(equ), ik);
			equ_set->items.push_back(ei);
		}
		flu();
	};
}

// DB����O���[�g�����X�^�[�����[�h����֐������B
registry_t<int>::load_func // ������֐��B
load_great_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int>* reg) {
		int mid;
		ses->execute(
			"SELECT `", construct<sql_column>("mob_id", mid), "` "
			"FROM `pybot_great_mob` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(mid);
	};
}

// DB���疳���A�C�e�������[�h����֐������B
registry_t<int>::load_func // ������֐��B
load_ignore_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int>* reg) {
		int nid;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("nameid", nid), "` "
			"FROM `pybot_ignore_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(nid);
	};
}

// DB���琧���X�L�������[�h����֐������B
registry_t<int,int>::load_func // ������֐��B
load_limit_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int,int>* reg) {
		int kid;
		int klv;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("skill_id", kid), "`,"
			" `", construct<sql_column>("skill_lv", klv), "` "
			"FROM `pybot_limit_skill` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(kid, initialize<int>(klv));
	};
}

// DB����ʏ�U���|���V�[�����[�h����֐������B
registry_t<int,normal_attack_policy>::load_func // ������֐��B
load_normal_attack_policy_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, registry_t<int,normal_attack_policy>* reg) {
		int mid;
		int val;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("mob_id", mid), "`,"
			" `", construct<sql_column>("value" , val), "` "
			"FROM `pybot_normal_attack_policy` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row())
			reg->register_(mid, construct<normal_attack_policy>(mid, normal_attack_policy_values(val)));
	};
}

// DB���牉�t�X�L�������[�h����֐������B
registry_t<int,play_skill>::load_func // ������֐��B
load_play_skill_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, registry_t<int,play_skill>* reg) {
		int mid;
		int kid;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("mob_id"   , mid), "`,"
			" `", construct<sql_column>("skill_id" , kid), "` "
			"FROM `pybot_play_skill` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row())
			reg->register_(mid, construct<play_skill>(mid, e_skill(kid)));
	};
}

// DB����HP�񕜃A�C�e�������[�h����֐������B
registry_t<int,int>::load_func // ������֐��B
load_recover_hp_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int,int>* reg) {
		int nid;
		int thr;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("nameid", nid), "`,"
			" `", construct<sql_column>("threshold", thr), "` "
			"FROM `pybot_recover_hp_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(nid, initialize<int>(thr));
	};
}

// DB����SP�񕜃A�C�e�������[�h����֐������B
registry_t<int,int>::load_func // ������֐��B
load_recover_sp_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int,int>* reg) {
		int nid;
		int thr;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("nameid", nid), "`,"
			" `", construct<sql_column>("threshold", thr), "` "
			"FROM `pybot_recover_sp_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(nid, initialize<int>(thr));
	};
}

// DB���狑�ۃX�L�������[�h����֐������B
registry_t<int>::load_func // ������֐��B
load_reject_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int>* reg) {
		e_skill kid;
		ses->execute(
			"SELECT `", construct<sql_column>("skill_id", *(int*)(&kid)), "` "
			"FROM `pybot_reject_skill` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(kid);
	};
}

// DB���甄�p�A�C�e�������[�h����֐������B
registry_t<int>::load_func // ������֐��B
load_sell_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int>* reg) {
		int nid;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("nameid", nid), "` "
			"FROM `pybot_sell_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(nid);
	};
}

// DB����q�ɕ�[�A�C�e�������[�h����֐������B
registry_t<int,int>::load_func // ������֐��B
load_storage_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int,int>* reg) {
		int nid;
		int amo;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("nameid", nid), "`,"
			" `", construct<sql_column>("amount", amo), "` "
			"FROM `pybot_storage_get_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(nid, initialize<int>(amo));
	};
}

// DB����q�Ɋi�[�A�C�e�������[�h����֐������B
registry_t<int>::load_func // ������֐��B
load_storage_put_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int>* reg) {
		int nid;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("nameid", nid), "` "
			"FROM `pybot_storage_put_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(nid);
	};
}

// DB�̋����|���V�[���X�V����֐������B
registry_t<int,distance_policy>::save_func // ������֐��B
update_distance_policy_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, distance_policy* dis_pol) {
		ses->execute(
			"UPDATE `pybot_distance_policy` "
			"SET"
			" `value` = ", construct<sql_param>(int(dis_pol->value)), " "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = " , construct<sql_param>(mid)
		);
	};
}

// DB�̑����Z�b�g���X�V����֐������B
registry_t<int,equipset_t>::save_func // ������֐��B
update_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, equipset_t* equ_set) {
		ses->execute(
			"DELETE FROM `pybot_equipset` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = " , construct<sql_param>(mid)
		);
		for (auto esi : equ_set->items) {
			ses->execute(
				"INSERT INTO `pybot_equipset` "
				"VALUES "
				"(", construct<sql_param>(cid              ), ","
				" ", construct<sql_param>(mid              ), ","
				" ", construct<sql_param>(esi->order       ), ","
				" ", construct<sql_param>(esi->equip       ), ","
				" ", construct<sql_param>(esi->key->nameid ), ","
				" ", construct<sql_param>(esi->key->card[0]), ","
				" ", construct<sql_param>(esi->key->card[1]), ","
				" ", construct<sql_param>(esi->key->card[2]), ","
				" ", construct<sql_param>(esi->key->card[3]), ")"
			);
		}
	};
}

// DB�̐����X�L�����X�V����֐������B
registry_t<int,int>::save_func // ������֐��B
update_limit_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int kid, int* klv) {
		ses->execute(
			"UPDATE `pybot_limit_skill` "
			"SET `skill_lv` = ", construct<sql_param>(*klv), " "
			"WHERE"
			" `char_id` = " , construct<sql_param>(cid), " AND"
			" `skill_id` = ", construct<sql_param>(kid)
		);
	};
}

// DB�̒ʏ�U���|���V�[���X�V����֐������B
registry_t<int,normal_attack_policy>::save_func // ������֐��B
update_normal_attack_policy_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, normal_attack_policy* nor_att_pol) {
		ses->execute(
			"UPDATE `pybot_normal_attack_policy` "
			"SET"
			" `value` = ", construct<sql_param>(int(nor_att_pol->value)), " "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = " , construct<sql_param>(mid)
		);
	};
}

// DB�̒ʏ�U���|���V�[���X�V����֐������B
registry_t<int,play_skill>::save_func // ������֐��B
update_play_skill_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, play_skill* pla_ski) {
		ses->execute(
			"UPDATE `pybot_play_skill` "
			"SET"
			" `skill_id` = ", construct<sql_param>(int(pla_ski->skill_id)), " "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = " , construct<sql_param>(mid)
		);
	};
}

// DB��HP�񕜃A�C�e�����X�V����֐������B
registry_t<int,int>::save_func // ������֐��B
update_recover_hp_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* thr) {
		ses->execute(
			"UPDATE `pybot_recover_hp_item` "
			"SET `threshold` = ", construct<sql_param>(*thr), " "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
	};
}

// DB��SP�񕜃A�C�e�����X�V����֐������B
registry_t<int,int>::save_func // ������֐��B
update_recover_sp_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* thr) {
		ses->execute(
			"UPDATE `pybot_recover_sp_item` "
			"SET `threshold` = ", construct<sql_param>(*thr), " "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
	};
}

// DB�̑q�ɕ�[�A�C�e�����X�V����֐������B
registry_t<int,int>::save_func // ������֐��B
update_storage_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* amo) {
		ses->execute(
			"UPDATE `pybot_storage_get_item` "
			"SET `amount` = ", construct<sql_param>(*amo), " "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
	};
}

}
