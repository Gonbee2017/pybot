// [GonBee]
// �p�[�e�B�[BOT�@�\�̃��W�X�g���p�֐����`����B

#include "pybot_internal.hpp"

namespace pybot {

// -----------------------------------------------------------------------------
// ���W�X�g���p�֐��̒�`

// DB����J�[�g������[�A�C�e�����N���A����֐������B
registry_t<int,int>::clear_func // ������֐��B
clear_cart_auto_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_cart_auto_get_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB���狗���|���V�[���N���A����֐������B
registry_t<int,distance_policy>::clear_func // ������֐��B
clear_distance_policy_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_distance_policy` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB���畐��ꎮ���N���A����֐������B
registry_t<int,equipset_t>::clear_func // ������֐��B
clear_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_equipset` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����D�惂���X�^�[���N���A����֐������B
registry_t<int>::clear_func // ������֐��B
clear_first_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_first_mob` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����D��X�L�����N���A����֐������B
registry_t<int,e_skill>::clear_func // ������֐��B
clear_first_skill_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_first_skill` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����O���[�g�����X�^�[���N���A����֐������B
registry_t<int>::clear_func // ������֐��B
clear_great_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_great_mob` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB���疳���A�C�e�����N���A����֐������B
registry_t<int>::clear_func // ������֐��B
clear_ignore_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_ignore_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB���疳�������X�^�[���N���A����֐������B
registry_t<int>::clear_func // ������֐��B
clear_ignore_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_ignore_mob` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����W���[�i�����N���A����֐������B
registry_t<int,coords_t>::clear_func // ������֐��B
clear_journal_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_journal` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB���畐�푮���t�^���N���A����֐������B
registry_t<int,e_element>::clear_func // ������֐��B
clear_kew_element_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_kew_element` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB���琧���X�L�����N���A����֐������B
registry_t<e_skill,int>::clear_func // ������֐��B
clear_limit_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_limit_skill` "
			"WHERE `char_id` = " , construct<sql_param>(cid)
		);
	};
}

// DB����ʏ�U���|���V�[���N���A����֐������B
registry_t<int,normal_attack_policy>::clear_func // ������֐��B
clear_normal_attack_policy_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_normal_attack_policy` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����񖳎��A�C�e�����N���A����֐������B
registry_t<int>::clear_func // ������֐��B
clear_not_ignore_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_not_ignore_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB���牉�t�X�L�����N���A����֐������B
registry_t<int,play_skill>::clear_func // ������֐��B
clear_play_skill_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_play_skill` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����HP�񕜃A�C�e�����N���A����֐������B
registry_t<int,int>::clear_func // ������֐��B
clear_recover_hp_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_recover_hp_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����SP�񕜃A�C�e�����N���A����֐������B
registry_t<int,int>::clear_func // ������֐��B
clear_recover_sp_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_recover_sp_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB���狑�ۃX�L�����N���A����֐������B
registry_t<e_skill>::clear_func // ������֐��B
clear_reject_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_reject_skill` "
			"WHERE `char_id` = " , construct<sql_param>(cid)
		);
	};
}

// DB���甄�p�A�C�e�����N���A����֐������B
registry_t<int>::clear_func // ������֐��B
clear_sell_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_sell_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����X�L������ꎮ���N���A����֐������B
registry_t<e_skill,equipset_t>::clear_func // ������֐��B
clear_skill_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_skill_equipset` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����X�L�����������X�^�[���N���A����֐������B
registry_t<int>::clear_func // ������֐��B
clear_skill_ignore_mob_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_skill_ignore_mob` "
			"WHERE `char_id` = "  , construct<sql_param>(cid)
		);
	};
}

// DB����|���������Ԃ��N���A����֐������B
registry_t<e_skill,int>::clear_func // ������֐��B
clear_skill_tail_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_skill_tail` "
			"WHERE `char_id` = " , construct<sql_param>(cid)
		);
	};
}

// DB����q�ɕ�[�A�C�e�����N���A����֐������B
registry_t<int,int>::clear_func // ������֐��B
clear_storage_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_storage_get_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����q�Ɋi�[�A�C�e�����N���A����֐������B
registry_t<int>::clear_func // ������֐��B
clear_storage_put_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_storage_put_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����`�[�����N���A����֐������B
registry_t<int,team_t>::clear_func // ������֐��B
clear_team_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses) {
		ses->execute(
			"DELETE FROM `pybot_team` "
			"WHERE `leader_char_id` = ", construct<sql_param>(cid)
		);
	};
}

// DB����J�[�g������[�A�C�e�����폜����֐������B
registry_t<int,int>::save_func // ������֐��B
delete_cart_auto_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* amo) {
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

// DB���畐��ꎮ���폜����֐������B
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

// DB����D�惂���X�^�[���폜����֐������B
registry_t<int>::save_func // ������֐��B
delete_first_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int mid) {
		ses->execute(
			"DELETE FROM `pybot_first_mob` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` =  " , construct<sql_param>(mid)
		);
	};
}

// DB����D��X�L�����폜����֐������B
registry_t<int,e_skill>::save_func // ������֐��B
delete_first_skill_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, e_skill* kid) {
		ses->execute(
			"DELETE FROM `pybot_first_skill` "
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

// DB���疳�������X�^�[���폜����֐������B
registry_t<int>::save_func // ������֐��B
delete_ignore_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int mid) {
		ses->execute(
			"DELETE FROM `pybot_ignore_mob` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` =  " , construct<sql_param>(mid)
		);
	};
}

// DB����W���[�i�����폜����֐������B
registry_t<int,coords_t>::save_func // ������֐��B
delete_journal_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int m, coords_t* mem) {
		auto map = find_map_data(id_maps, m);
		if (map) {
			ses->execute(
				"DELETE FROM `pybot_journal` "
				"WHERE"
				" `char_id` = ", construct<sql_param>(cid), " AND"
				" `map` = "    , construct<sql_param>(map->name_english.c_str())
			);
		}
	};
}

// DB���畐�푮���t�^���폜����֐������B
registry_t<int,e_element>::save_func // ������֐��B
delete_kew_element_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int m, e_element* ele) {
		auto map = find_map_data(id_maps, m);
		if (map) {
			ses->execute(
				"DELETE FROM `pybot_kew_element` "
				"WHERE"
				" `char_id` = ", construct<sql_param>(cid                      ), " AND"
				" `map` = "    , construct<sql_param>(map->name_english.c_str())
			);
		}
	};
}

// DB���琧���X�L�����폜����֐������B
registry_t<e_skill,int>::save_func // ������֐��B
delete_limit_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, e_skill kid, int* klv) {
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

// DB����񖳎��A�C�e�����폜����֐������B
registry_t<int>::save_func // ������֐��B
delete_not_ignore_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid) {
		ses->execute(
			"DELETE FROM `pybot_not_ignore_item` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
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
registry_t<e_skill>::save_func // ������֐��B
delete_reject_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, e_skill kid) {
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

// DB����X�L������ꎮ���폜����֐������B
registry_t<e_skill,skill_equipset>::save_func // ������֐��B
delete_skill_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, e_skill kid, skill_equipset* equ_set) {
		ses->execute(
			"DELETE FROM `pybot_skill_equipset` "
			"WHERE"
			" `char_id` = "  , construct<sql_param>(cid), " AND"
			" `skill_id` = " , construct<sql_param>(kid)
		);
	};
}

// DB����X�L�����������X�^�[���폜����֐������B
registry_t<int>::save_func // ������֐��B
delete_skill_ignore_mob_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int kim) {
		ses->execute(
			"DELETE FROM `pybot_skill_ignore_mob` "
			"WHERE"
			" `char_id` = "  , construct<sql_param>(cid                ), " AND"
			" `skill_id` = " , construct<sql_param>(SKILL_FROM_KIM(kim))
		);
	};
}

// DB����|���������Ԃ��폜����֐������B
registry_t<e_skill,int>::save_func // ������֐��B
delete_skill_tail_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, e_skill kid, int* dur) {
		ses->execute(
			"DELETE FROM `pybot_skill_tail` "
			"WHERE"
			" `char_id` = " , construct<sql_param>(cid), " AND"
			" `skill_id` = ", construct<sql_param>(kid)
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

// DB����`�[�����폜����֐������B
registry_t<int,team_t>::save_func // ������֐��B
delete_team_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int tea_num, team_t* tea) {
		ses->execute(
			"DELETE FROM `pybot_team` "
			"WHERE"
			" `leader_char_id` = ", construct<sql_param>(cid    ), " AND"
			" `team_number` = "   , construct<sql_param>(tea_num)
		);
	};
}

// DB�ɃJ�[�g������[�A�C�e����}������֐������B
registry_t<int,int>::save_func // ������֐��B
insert_cart_auto_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid, int* amo) {
		ses->execute(
			"INSERT INTO `pybot_cart_auto_get_item` "
			"VALUES"
			"(", construct<sql_param>(cid ), ","
			" ", construct<sql_param>(nid ), ","
			" ", construct<sql_param>(*amo), ")"
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
			"VALUES"
			"(", construct<sql_param>(cid                ), ","
			" ", construct<sql_param>(mid                ), ","
			" ", construct<sql_param>(int(dis_pol->value)), ")"
		);
	};
}

// DB�ɕ���ꎮ��}������֐������B
registry_t<int,equipset_t>::save_func // ������֐��B
insert_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, equipset_t* equ_set) {
		for (auto esi : equ_set->items) {
			ses->execute(
				"INSERT INTO `pybot_equipset` "
				"VALUES"
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

// DB�ɗD�惂���X�^�[��}������֐������B
registry_t<int>::save_func // ������֐��B
insert_first_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int mid) {
		ses->execute(
			"INSERT INTO `pybot_first_mob` "
			"VALUES"
			"(", construct<sql_param>(cid), ","
			" ", construct<sql_param>(mid), ")"
		);
	};
}

// DB�ɗD��X�L����}������֐������B
registry_t<int,e_skill>::save_func // ������֐��B
insert_first_skill_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, e_skill* kid) {
		ses->execute(
			"INSERT INTO `pybot_first_skill` "
			"VALUES"
			"(", construct<sql_param>(cid ), ","
			" ", construct<sql_param>(mid ), ","
			" ", construct<sql_param>(*kid), ")"
		);
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
			"VALUES"
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
			"VALUES"
			"(", construct<sql_param>(cid), ","
			" ", construct<sql_param>(nid), ")"
		);
	};
}

// DB�ɖ��������X�^�[��}������֐������B
registry_t<int>::save_func // ������֐��B
insert_ignore_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int mid) {
		ses->execute(
			"INSERT INTO `pybot_ignore_mob` "
			"VALUES"
			"(", construct<sql_param>(cid), ","
			" ", construct<sql_param>(mid), ")"
		);
	};
}

// DB�ɃW���[�i����}������֐������B
registry_t<int,coords_t>::save_func // ������֐��B
insert_journal_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int m, coords_t* mem) {
		auto map = find_map_data(id_maps, m);
		if (map) {
			ses->execute(
				"INSERT INTO `pybot_journal` "
				"VALUES"
				"(", construct<sql_param>(cid                      ), ","
				" ", construct<sql_param>(map->name_english.c_str()), ","
				" ", construct<sql_param>(mem->x                   ), ","
				" ", construct<sql_param>(mem->y                   ), ")"
			);
		}
	};
}

// DB�ɕ��푮���t�^��}������֐������B
registry_t<int,e_element>::save_func // ������֐��B
insert_kew_element_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int m, e_element* ele) {
		auto map = find_map_data(id_maps, m);
		if (map) {
			ses->execute(
				"INSERT INTO `pybot_kew_element` "
				"VALUES"
				"(", construct<sql_param>(cid                      ), ","
				" ", construct<sql_param>(map->name_english.c_str()), ","
				" ", construct<sql_param>(*ele                     ), ")"
			);
		}
	};
}

// DB�ɐ����X�L����}������֐������B
registry_t<e_skill,int>::save_func // ������֐��B
insert_limit_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, e_skill kid, int* klv) {
		ses->execute(
			"INSERT INTO `pybot_limit_skill` "
			"VALUES"
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
			"VALUES"
			"(", construct<sql_param>(cid                    ), ","
			" ", construct<sql_param>(mid                    ), ","
			" ", construct<sql_param>(int(nor_att_pol->value)), ")"
		);
	};
}

// DB�ɔ񖳎��A�C�e����}������֐������B
registry_t<int>::save_func // ������֐��B
insert_not_ignore_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int nid) {
		ses->execute(
			"INSERT INTO `pybot_not_ignore_item` "
			"VALUES"
			"(", construct<sql_param>(cid), ","
			" ", construct<sql_param>(nid), ")"
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
			"VALUES"
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
			"VALUES"
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
			"VALUES"
			"(", construct<sql_param>(cid ), ","
			" ", construct<sql_param>(nid ), ","
			" ", construct<sql_param>(*thr), ")"
		);
	};
}

// DB�ɋ��ۃX�L����}������֐������B
registry_t<e_skill>::save_func // ������֐��B
insert_reject_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, e_skill kid) {
		ses->execute(
			"INSERT INTO `pybot_reject_skill` "
			"VALUES"
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
			"VALUES"
			"(", construct<sql_param>(cid), ","
			" ", construct<sql_param>(nid), ")"
		);
	};
}

// DB�ɃX�L������ꎮ��}������֐������B
registry_t<e_skill,skill_equipset>::save_func // ������֐��B
insert_skill_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, e_skill kid, skill_equipset* equ_set) {
		for (auto esi : equ_set->items) {
			ses->execute(
				"INSERT INTO `pybot_skill_equipset` "
				"VALUES"
				"(", construct<sql_param>(cid              ), ","
				" ", construct<sql_param>(kid              ), ","
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

// DB�ɃX�L�����������X�^�[��}������֐������B
registry_t<int>::save_func // ������֐��B
insert_skill_ignore_mob_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int kim) {
		ses->execute(
			"INSERT INTO `pybot_skill_ignore_mob` "
			"VALUES"
			"(", construct<sql_param>(cid                ), ","
			" ", construct<sql_param>(SKILL_FROM_KIM(kim)), ","
			" ", construct<sql_param>(MOB_FROM_KIM(kim)  ), ")"
		);
	};
}

// DB�Ɋ|���������Ԃ�}������֐������B
registry_t<e_skill,int>::save_func // ������֐��B
insert_skill_tail_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, e_skill kid, int* dur) {
		ses->execute(
			"INSERT INTO `pybot_skill_tail` "
			"VALUES"
			"(", construct<sql_param>(cid ), ","
			" ", construct<sql_param>(kid ), ","
			" ", construct<sql_param>(*dur), ")"
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
			"VALUES"
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
			"VALUES"
			"(", construct<sql_param>(cid), ","
			" ", construct<sql_param>(nid), ")"
		);
	};
}

// DB�Ƀ`�[����}������֐������B
registry_t<int,team_t>::save_func // ������֐��B
insert_team_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int tea_num, team_t* tea) {
		for (int i = 0; i < tea->members.size(); ++i) {
			auto mem = tea->members[i];
			ses->execute(
				"INSERT INTO `pybot_team` "
				"VALUES"
				"(", construct<sql_param>(cid         ), ","
				" ", construct<sql_param>(tea_num     ), ","
				" ", construct<sql_param>(i           ), ","
				" ", construct<sql_param>(mem->char_id), ")"
			);
		}
	};
}

// DB����J�[�g������[�A�C�e�������[�h����֐������B
registry_t<int,int>::load_func // ������֐��B
load_cart_auto_get_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int,int>* reg) {
		int nid;
		int amo;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("nameid", nid), "`,"
			" `", construct<sql_column>("amount", amo), "` "
			"FROM `pybot_cart_auto_get_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(nid, initialize<int>(amo));
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

// DB���畐��ꎮ�����[�h����֐������B
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
			ik->identify = 1;
			auto ei = initialize<equipset_item>(equip_pos_orders(ord), equip_pos(equ), ik);
			equ_set->items.push_back(ei);
		}
		flu();
	};
}

// DB����D�惂���X�^�[�����[�h����֐������B
registry_t<int>::load_func // ������֐��B
load_first_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int>* reg) {
		int mid;
		ses->execute(
			"SELECT `", construct<sql_column>("mob_id", mid), "` "
			"FROM `pybot_first_mob` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(mid);
	};
}

// DB����D��X�L�������[�h����֐������B
registry_t<int,e_skill>::load_func // ������֐��B
load_first_skill_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, registry_t<int,e_skill>* reg) {
		int mid;
		e_skill kid;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("mob_id"  , mid), "`,"
			" `", construct<sql_column>("skill_id", kid), "` "
			"FROM `pybot_first_skill` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row())
			reg->register_(mid, initialize<e_skill>(kid));
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

// DB���疳�������X�^�[�����[�h����֐������B
registry_t<int>::load_func // ������֐��B
load_ignore_mob_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int>* reg) {
		int mid;
		ses->execute(
			"SELECT `", construct<sql_column>("mob_id", mid), "` "
			"FROM `pybot_ignore_mob` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(mid);
	};
}

// DB����W���[�i�������[�h����֐������B
registry_t<int,coords_t>::load_func // ������֐��B
load_journal_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int,coords_t>* reg) {
		char map[12];
		int x;
		int y;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("map", map), "`,"
			" `", construct<sql_column>("x"  , x  ), "`,"
			" `", construct<sql_column>("y"  , y  ), "` "
			"FROM `pybot_journal` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) {
			int ind = mapindex_name2id(map);
			if (ind) reg->register_(map_mapindex2mapid(ind), initialize<coords_t>(x, y));
		}
	};
}

// DB���畐�푮���t�^�����[�h����֐������B
registry_t<int,e_element>::load_func // ������֐��B
load_kew_element_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int,e_element>* reg) {
		char map[12];
		e_element ele;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("map"    , map), "`,"
			" `", construct<sql_column>("element", ele), "` "
			"FROM `pybot_kew_element` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) {
			int ind = mapindex_name2id(map);
			if (ind) reg->register_(map_mapindex2mapid(ind), initialize<e_element>(ele));
		}
	};
}

// DB���琧���X�L�������[�h����֐������B
registry_t<e_skill,int>::load_func // ������֐��B
load_limit_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<e_skill,int>* reg) {
		e_skill kid;
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

// DB����񖳎��A�C�e�������[�h����֐������B
registry_t<int>::load_func // ������֐��B
load_not_ignore_item_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<int>* reg) {
		int nid;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("nameid", nid), "` "
			"FROM `pybot_not_ignore_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(nid);
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
			" `", construct<sql_column>("nameid"   , nid), "`,"
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
			" `", construct<sql_column>("nameid"   , nid), "`,"
			" `", construct<sql_column>("threshold", thr), "` "
			"FROM `pybot_recover_sp_item` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(nid, initialize<int>(thr));
	};
}

// DB���狑�ۃX�L�������[�h����֐������B
registry_t<e_skill>::load_func // ������֐��B
load_reject_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<e_skill>* reg) {
		e_skill kid;
		ses->execute(
			"SELECT `", construct<sql_column>("skill_id", kid), "` "
			"FROM `pybot_reject_skill` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(kid);
	};
}

// DB����X�L������ꎮ�����[�h����֐������B
registry_t<e_skill,skill_equipset>::load_func // ������֐��B
load_skill_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, registry_t<e_skill,skill_equipset>* reg) {
		e_skill kid;
		int ord;
		int equ;
		uint16_t nid;
		uint16_t car[MAX_SLOTS];
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("skill_id", kid   ), "`,"
			" `", construct<sql_column>("order"   , ord   ), "`,"
			" `", construct<sql_column>("equip"   , equ   ), "`,"
			" `", construct<sql_column>("nameid"  , nid   ), "`,"
			" `", construct<sql_column>("card0"   , car[0]), "`,"
			" `", construct<sql_column>("card1"   , car[1]), "`,"
			" `", construct<sql_column>("card2"   , car[2]), "`,"
			" `", construct<sql_column>("card3"   , car[3]), "` "
			"FROM `pybot_skill_equipset` "
			"WHERE `char_id` = ", construct<sql_param>(cid), " "
			"ORDER BY"
			" `skill_id`,"
			" `order`"
		);
		ptr<skill_equipset> equ_set;
		auto flu = [reg, &equ_set] () {
			if (equ_set) reg->register_(equ_set->skill_id, equ_set);
		};
		while (ses->next_row()) {
			if (!equ_set ||
				kid != equ_set->skill_id
			) {
				flu();
				equ_set = initialize<skill_equipset>(kid);
			}
			auto ik = construct<item_key>(nid, car);
			ik->identify = 1;
			auto ei = initialize<equipset_item>(equip_pos_orders(ord), equip_pos(equ), ik);
			equ_set->items.push_back(ei);
		}
		flu();
	};
}

// DB����X�L�����������X�^�[�����[�h����֐������B
registry_t<int>::load_func // ������֐��B
load_skill_ignore_mob_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, registry_t<int>* reg) {
		e_skill kid;
		int mid;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("skill_id", kid), "`,"
			" `", construct<sql_column>("mob_id"  , mid), "` "
			"FROM `pybot_skill_ignore_mob` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row())
			reg->register_(SKILL_IGNORE_MOB(kid, mid));
	};
}

// DB����|���������Ԃ����[�h����֐������B
registry_t<e_skill,int>::load_func // ������֐��B
load_skill_tail_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, registry_t<e_skill,int>* reg) {
		e_skill kid;
		int dur;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("skill_id", kid), "`,"
			" `", construct<sql_column>("duration", dur), "` "
			"FROM `pybot_skill_tail` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		while (ses->next_row()) reg->register_(kid, initialize<int>(dur));
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

// DB����`�[�������[�h����֐������B
registry_t<int,team_t>::load_func // ������֐��B
load_team_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, registry_t<int,team_t>* reg) {
		int tea_num;
		int mem_cid;
		char mem_nam[24];
		ses->execute(
			"SELECT"
			" t.`", construct<sql_column>("team_number"    , tea_num), "`,"
			" t.`", construct<sql_column>("member_char_id" , mem_cid), "`,"
			" c.`", construct<sql_column>("name"           , mem_nam), "` "
			"FROM"
			" `pybot_team` AS t,"
			" `char` AS c "
			"WHERE"
			" t.`leader_char_id` = ", construct<sql_param>(cid), " AND"
			" t.`member_char_id` = c.`char_id` "
			"ORDER BY"
			" t.`team_number`,"
			" t.`member_index`"
		);
		ptr<team_t> tea;
		while (ses->next_row()) {
			if (!tea ||
				tea_num != tea->tea_num
			) {
				tea = initialize<team_t>(tea_num);
				reg->register_(tea_num, tea);
			}
			tea->members.push_back(initialize<team_member>(mem_cid, std::string(mem_nam)));
		}
	};
}

// DB�̃J�[�g������[�A�C�e�����X�V����֐������B
registry_t<int,int>::save_func // ������֐��B
update_cart_auto_get_item_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int nid, int* amo) {
		ses->execute(
			"UPDATE `pybot_cart_auto_get_item` "
			"SET `amount` = ", construct<sql_param>(*amo), " "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `nameid` = " , construct<sql_param>(nid)
		);
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
			"SET `value` = ", construct<sql_param>(int(dis_pol->value)), " "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = " , construct<sql_param>(mid)
		);
	};
}

// DB�̗D��X�L�����X�V����֐������B
registry_t<int,e_skill>::save_func // ������֐��B
update_first_skill_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int mid, e_skill* kid) {
		ses->execute(
			"UPDATE `pybot_first_skill` "
			"SET `skill_id` = ", construct<sql_param>(*kid), " "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = " , construct<sql_param>(mid)
		);
	};
}

// DB�̕���ꎮ���X�V����֐������B
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
				"VALUES"
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

// DB�̃W���[�i�����X�V����֐������B
registry_t<int,coords_t>::save_func // ������֐��B
update_journal_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int m, coords_t* xy) {
		auto map = find_map_data(id_maps, m);
		if (map) {
			ses->execute(
				"UPDATE `pybot_journal` "
				"SET"
				" `x` = ", construct<sql_param>(xy->x), ","
				" `y` = ", construct<sql_param>(xy->y), " "
				"WHERE"
				" `char_id` = ", construct<sql_param>(cid                      ), " AND"
				" `map` = "    , construct<sql_param>(map->name_english.c_str())
			);
		}
	};
}

// DB�̕��푮���t�^���X�V����֐������B
registry_t<int,e_element>::save_func // ������֐��B
update_kew_element_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, int m, e_element* ele) {
		auto map = find_map_data(id_maps, m);
		if (map) {
			ses->execute(
				"UPDATE `pybot_kew_element` "
				"SET `element` = ", construct<sql_param>(*ele), " "
				"WHERE"
				" `char_id` = ", construct<sql_param>(cid                      ), " AND"
				" `map` = "    , construct<sql_param>(map->name_english.c_str())
			);
		}
	};
}

// DB�̐����X�L�����X�V����֐������B
registry_t<e_skill,int>::save_func // ������֐��B
update_limit_skill_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, e_skill kid, int* klv) {
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
			"SET `value` = ", construct<sql_param>(int(nor_att_pol->value)), " "
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
			"SET `skill_id` = ", construct<sql_param>(int(pla_ski->skill_id)), " "
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

// DB�̃X�L������ꎮ���X�V����֐������B
registry_t<e_skill,skill_equipset>::save_func // ������֐��B
update_skill_equipset_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, e_skill kid, skill_equipset* equ_set) {
		ses->execute(
			"DELETE FROM `pybot_skill_equipset` "
			"WHERE"
			" `char_id` = "  , construct<sql_param>(cid), " AND"
			" `skill_id` = " , construct<sql_param>(kid)
		);
		for (auto esi : equ_set->items) {
			ses->execute(
				"INSERT INTO `pybot_skill_equipset` "
				"VALUES"
				"(", construct<sql_param>(cid              ), ","
				" ", construct<sql_param>(kid              ), ","
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

// DB�̊|���������Ԃ��X�V����֐������B
registry_t<e_skill,int>::save_func // ������֐��B
update_skill_tail_func(
	int cid // �L�����N�^�[ID�B
) {
	return [cid] (sql_session* ses, e_skill kid, int* dur) {
		ses->execute(
			"UPDATE `pybot_skill_tail` "
			"SET `duration` = ", construct<sql_param>(*dur), " "
			"WHERE"
			" `char_id` = " , construct<sql_param>(cid), " AND"
			" `skill_id` = ", construct<sql_param>(kid)
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

// DB�̃`�[�����X�V����֐������B
registry_t<int,team_t>::save_func // ������֐��B
update_team_func(
	int cid // �L�����N�^�[ID�B              
) {
	return [cid] (sql_session* ses, int tea_num, team_t* tea) {
		ses->execute(
			"DELETE FROM `pybot_team` "
			"WHERE"
			" `leader_char_id` = ", construct<sql_param>(cid    ), " AND"
			" `team_number` = "   , construct<sql_param>(tea_num)
		);
		for (int i = 0; i < tea->members.size(); ++i) {
			auto mem = tea->members[i];
			ses->execute(
				"INSERT INTO `pybot_team` "
				"VALUES"
				"(", construct<sql_param>(cid         ), ","
				" ", construct<sql_param>(tea_num     ), ","
				" ", construct<sql_param>(i           ), ","
				" ", construct<sql_param>(mem->char_id), ")"
			);
		}
	};
}

}
