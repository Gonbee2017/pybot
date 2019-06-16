// [GonBee]
// �p�[�e�B�[BOT�@�\�̊O������Q�Ƃ����֐����`����B

#include "pybot_internal.hpp"

namespace pybot {

// -----------------------------------------------------------------------------
// �O������Q�Ƃ����֐��̒�`
	
// MVP�̎����i�߂�B
void advance_mvp_round(
	int cid // �L�����N�^�[ID�B
) {
	sql_session::open([cid] (sql_session* ses) {
		ses->execute(
			"UPDATE `pybot_mvp_stats` "
			"SET"
			" `round` = `round` + 1,"
			" `mobs` = 0 "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
		ses->execute(
			"DELETE FROM `pybot_mvp` "
			"WHERE `char_id` = ", construct<sql_param>(cid)
		);
	});
}

// �x�[�X���x���{�����v�Z����B
double // �v�Z�����{���B
base_level_rate(
	block_list* bl, // �u���b�N���X�g�B
	mob_data* md    // �����X�^�[�f�[�^�B
) {
	double pc_rat = status_get_lv(bl) / 20.;
	int mob_lv = status_get_lv(&md->bl);
	if (mob_is_pure_flora(md)) mob_lv = 1;
	double mob_rat = mob_lv / 20.;
	return std::max(std::max(pc_rat, 1.) * std::max(mob_rat, 1.), 2.);
}

// Bot��������Ӓ肷��B
// Bot�ł͂Ȃ��Ȃ牽�����Ȃ��B
// ���łɊӒ�ς݂Ȃ牽�����Ȃ��B
// �A�C�e���Ӓ���g�p�\�ł���Ή���������ɊӒ肷��B
// �����A�C�e�����J�[�g�Ɋg�勾������΂��������ĊӒ肷��B
// �A�C�e���Ӓ���g�p�s�A���g�勾���Ȃ���Ή������Ȃ��B
void bot_identify_equip(
	int cid,
	item* itm
) {
	block_if* bot = find_map_data(all_bots, cid);
	if (bot) bot->identify_equip(itm);
}

// �L�����N�^�[ID��Bot���𔻒肷��B
bool // ���ʁB
char_is_bot(
	int cid // �L�����N�^�[ID�B
) {
	return find_map_data(all_bots, cid);
}

// �J�[�h��ʂ̃J�[�h�ɕϊ�����B
int // �ϊ������J�[�hID�B
convert_card(
	int car_id // �J�[�hID�B
) {
	return card_converter::instance->convert(car_id);
}

// �p�[�e�B�[BOT�@�\���I������B
void do_final() {
	delete_timer(ai_timer, ai_t::timer_func);
}

// �p�[�e�B�[BOT�@�\������������B
void do_init() {
	load_maps();
	update_fever();
	skill_mobs::instance = construct<skill_mobs>();
	card_converter::instance = construct<card_converter>();
	add_timer_func_list(ai_t::timer_func, "pybot_ai");
	ai_timer = add_timer_interval(
		gettick() + battle_config.pybot_think_time,
		ai_t::timer_func,
		0,
		0,
		battle_config.pybot_think_time
	);
}

// �������ʏ����𑕔��C���f�b�N�X�ɕϊ�����B
equip_index // �ϊ����������C���f�b�N�X�B�ϊ��ł��Ȃ����INT_MIN�B
equip_pos_order_to_index(
	int ord // �������ʏ����B
) {
	equip_index ind = equip_index(INT_MIN);
	if (ord >= 0 &&
		ord < EPO2EQI_TABLE.size()
	) ind = EPO2EQI_TABLE[ord];
	return ind;
}

// �h���b�v�A�C�e���������A�C�e�����𔻒肷��B
bool // ���ʁB
flooritem_to_be_ignored(
	map_session_data* sd, // �Z�b�V�����f�[�^�B
	flooritem_data* fit   // �h���b�v�A�C�e���B
) {
	auto lea = find_map_data(all_leaders, sd->status.char_id);
	if (!lea) {
		lea = construct<leader_t>(sd);
		all_leaders[lea->char_id()] = lea;
	}
	return lea->ignore_items()->find(fit->item.nameid) &&
		!fit->item.card[0] &&
		!fit->item.refine;
}

// �������ʖ����擾����B
const char* get_equip_pos_name(equip_index equ_ind) {
	return EQUIP_POS_NAME_TABLE[equ_ind].c_str();
}

// Bot�̃��[�_�[���擾����B
map_session_data* // �擾�������[�_�[�B
                  // Bot�ł͂Ȃ����A���[�_�[�����O�A�E�g���Ă���Ȃ�nullptr�B
get_leader(
	int cid // �L�����N�^�[ID�B
) {
	block_if* bot = find_map_data(all_bots, cid);
	map_session_data* lea = nullptr;
	if (bot) lea = map_id2sd(bot->leader()->account_id());
	return lea;
}

// ���݂̃}�b�v�̏����ʒu���擾����B
block_list* // �擾�����ʒu�B
get_map_initial_position(
	map_session_data* sd // �Z�b�V�����f�[�^�B
) {
	auto pos = find_map_data(map_initial_positions, sd->status.char_id);
	if (pos) return pos.get();
	else return &sd->bl;
}

// �W���u���x���{�����v�Z����B
double // �v�Z�����{���B
job_level_rate(
	map_session_data* sd, // �Z�b�V�����f�[�^�B
	block_list* bl        // �u���b�N���X�g�B
) {
	double pc_rat = std::min(int(sd->status.job_level), 50) / 10.;
	double mob_rat = status_get_lv(bl) / 20.;
	return std::max(std::max(pc_rat, 1.) * std::max(mob_rat, 1.), 2.);
}

// �������S�p�����̍ŏ��̃o�C�g���𔻒肷��B
bool // ���ʁB
letter_is_jlead(
	uint8_t let // �o�C�g�B
) {
    return (let >= 0x80 &&
            let <= 0x9f
        ) || (let >= 0xe0 &&
            let <= 0xfc
        );
}

// �}�b�v�{�����擾����B
double // �擾�����{���B
map_rate(
	int m // �}�b�vID�B
) {
	return find_map_data(fever_rates, m, 100) / 100.;
}

// PC��MVP���l���������Ƃ��L�^����B
// ���h��ꂽ�Ö؂̎}�A�܂��͍Ԃ̎����ŏo�������������X�^�[�̏ꍇ�͋L�^���Ȃ��B
void pc_acquired_mvp(
	int cid,     // �L�����N�^�[ID�B
	mob_data* md // �����X�^�[�f�[�^�B
) {
	std::string eve(md->npc_event);
	if (eve.substr(0, BLOODY_DEAD_BRANCH_NPC_NAME.length()) != BLOODY_DEAD_BRANCH_NPC_NAME &&
		eve.substr(0, CASTLE_TRIAL_NPC_NAME.length()) != CASTLE_TRIAL_NPC_NAME
	) {
		sql_session::open([cid, md] (sql_session* ses) {
			ses->execute(
				"INSERT INTO `pybot_mvp` "
				"(`char_id`,"
				" `mob_id`) "
				"SELECT"
				" ", construct<sql_param>(cid       ), ","
				" ", construct<sql_param>(md->mob_id), " "
				"FROM dual "
				"WHERE NOT EXISTS("
					"SELECT * "
					"FROM `pybot_mvp` "
					"WHERE"
					" `char_id` = ", construct<sql_param>(cid       ), " AND"
					" `mob_id` = " , construct<sql_param>(md->mob_id), ")"
			);
			int mobs;
			ses->execute(
				"SELECT ", construct<sql_column>("COUNT(*)", mobs), " "
				"FROM `pybot_mvp` "
				"WHERE `char_id` = ", construct<sql_param>(cid)
			);
			ses->next_row();
			ses->execute(
				"INSERT INTO `pybot_mvp_stats`"
				"(`char_id`,"
				" `round`,"
				" `mobs`) "
				"VALUES"
				"(", construct<sql_param>(cid), ","
				" ", construct<sql_param>(0), ","
				" ", construct<sql_param>(mobs), ") "
				"ON DUPLICATE KEY UPDATE `mobs` = ", construct<sql_param>(mobs)
			);
		});
	}
}

// PC���h���b�v�A�C�e�����E���邩�𔻒肷��B
bool // ���ʁB
pc_can_takeitem(
	map_session_data* sd, // �Z�b�V�����f�[�^�B
	flooritem_data* fit   // �h���b�v�A�C�e���B
) {
	now = gettick();
	auto can_take = [sd] (int get_charid, t_tick get_tick) -> bool	{
		if (!get_charid ||
			get_charid == sd->status.char_id ||
			DIFF_TICK(now, get_tick) >= 0
		) return true;
		map_session_data* get_sd = map_charid2sd(get_charid);
		if (!get_sd) return true;
		return get_sd->status.party_id == sd->status.party_id;
	};
	return can_take(fit->first_get_charid, fit->first_get_tick) ||
		can_take(fit->second_get_charid, fit->second_get_tick) ||
		can_take(fit->third_get_charid, fit->third_get_tick);
}

// PC��MVP���l���������Ƃ����邩�𔻒肷��B
bool // ���ʁB
pc_has_acquired_mvp(
	int cid,
	int mid
) {
	bool res = false;
	sql_session::open([cid, mid, &res] (sql_session* ses) {
		int cou;
		ses->execute(
			"SELECT ", construct<sql_column>("COUNT(*)", cou), " "
			"FROM `pybot_mvp` "
			"WHERE"
			" `char_id` = ", construct<sql_param>(cid), " AND"
			" `mob_id` = ", construct<sql_param>(mid)
		);
		res = ses->next_row() &&
			cou;
	});
	return res;
}

// MVP�����L���O���Ɖ��B
std::shared_ptr<std::vector<std::shared_ptr<mvp_stats>>> // �Ɖ��MVP�����L���O�B
query_mvp_ranking(
	const std::vector<e_job>& jobs, // �E�Ƃ̃x�N�^�B
	int lim                         // �ő�s���B
) {
	auto res = initialize<std::vector<ptr<mvp_stats>>>();
	if (jobs.size() == 1 &&
		jobs.front() == -1
	) {
		sql_session::open([lim, &res] (sql_session* ses) {
			char nam[NAME_LENGTH];
			int cla;
			int rou;
			int mobs;
			ses->execute(
				"SELECT"
				" ", construct<sql_column>("`char`.`name`"            , nam ), ","
				" ", construct<sql_column>("`char`.`class`"           , cla ), ","
				" ", construct<sql_column>("`pybot_mvp_stats`.`round`", rou ), ","
				" ", construct<sql_column>("`pybot_mvp_stats`.`mobs`" , mobs), " "
				"FROM"
				" `char`,"
				" `pybot_mvp_stats` "
				"WHERE `char`.`char_id` = `pybot_mvp_stats`.`char_id` "
				"ORDER BY"
				" `pybot_mvp_stats`.`round` DESC,"
				" `pybot_mvp_stats`.`mobs` DESC "
				"LIMIT ", construct<sql_param>(lim)
			);
			while (ses->next_row())
				res->push_back(initialize<mvp_stats>(nam, e_job(cla), rou, mobs));
		});
	} else {
		std::vector<std::string> job_strs;
		std::transform(
			ALL_RANGE(jobs),
			pybot::back_inserter(job_strs),
			[] (e_job job) -> std::string {return print(job);}
		);
		std::string job_lis = concatinate_strings(ALL_RANGE(job_strs), ", ");
		sql_session::open([lim, &res, &job_lis] (sql_session* ses) {
			char nam[NAME_LENGTH];
			int cla;
			int rou;
			int mobs;
			ses->execute(
				"SELECT"
				" ", construct<sql_column>("`char`.`name`"            , nam ), ","
				" ", construct<sql_column>("`char`.`class`"           , cla ), ","
				" ", construct<sql_column>("`pybot_mvp_stats`.`round`", rou ), ","
				" ", construct<sql_column>("`pybot_mvp_stats`.`mobs`" , mobs), " "
				"FROM"
				" `char`,"
				" `pybot_mvp_stats` "
				"WHERE"
				" `char`.`class` IN (", job_lis, ") AND"
				" `char`.`char_id` = `pybot_mvp_stats`.`char_id` "
				"ORDER BY"
				" `pybot_mvp_stats`.`round` DESC,"
				" `pybot_mvp_stats`.`mobs` DESC "
				"LIMIT ", construct<sql_param>(lim)
			);
			while (ses->next_row())
				res->push_back(initialize<mvp_stats>(nam, e_job(cla), rou, mobs));
		});
	}
	return res;
}

// MVP���v���Ɖ��B
std::shared_ptr<mvp_stats> // �Ɖ��MVP���v�B
query_mvp_stats(
	int cid // �L�����N�^�[ID�B
) {
	ptr<mvp_stats> res;
	sql_session::open([cid, &res] (sql_session* ses) {
		char nam[NAME_LENGTH];
		int cla;
		int rou;
		int mobs;
		ses->execute(
			"SELECT"
			" ", construct<sql_column>("`char`.`name`", nam), ","
			" ", construct<sql_column>("`char`.`class`", cla), ","
			" ", construct<sql_column>("`pybot_mvp_stats`.`round`", rou), ","
			" ", construct<sql_column>("`pybot_mvp_stats`.`mobs`", mobs), " "
			"FROM"
			" `char`,"
			" `pybot_mvp_stats` "
			"WHERE"
			" `char`.`char_id` = ", construct<sql_param>(cid), " AND"
			" `char`.`char_id` = `pybot_mvp_stats`.`char_id`"
		);
		if (ses->next_row())
			res = initialize<mvp_stats>(nam, e_job(cla), rou, mobs);
	});
	return res;
}

// Bot���퓬���ɕ���ꎮ�������[�h����B
void reload_equipset_in_battle(
	int cid // �L�����N�^�[ID�B
) {
	block_if* bot = find_map_data(all_bots, cid);
	if (bot) bot->last_reloaded_equipset_tick() = 0;
}

// ���݂̃}�b�v�̏����ʒu��ݒ肷��B
void set_map_initial_position(
	map_session_data* sd // �Z�b�V�����f�[�^�B
) {
	auto pos = find_map_data(map_initial_positions, sd->status.char_id);
	if (!pos) {
		pos = initialize<block_list>(sd->bl);
		map_initial_positions[sd->status.char_id] = pos;
	} else if (pos->m != sd->bl.m) *pos = sd->bl;

}

// �X�L���������h�v���e�N�^�[��ɐݒu�\���𔻒肷��B
bool // ���ʁB
skill_is_layable_on_lp(
	e_skill kid // �X�L��ID�B
) {
	return KEY_EXISTS(LAYABLE_ON_LP_SKILLS, kid);
}

}
