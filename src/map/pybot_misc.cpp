// [GonBee]
// �p�[�e�B�[BOT�@�\�̂��̑��̊֐����`����B

#include "pybot_internal.hpp"

namespace pybot {

// -----------------------------------------------------------------------------
// ���̑��̌^�̃����o�[�֐��̒�`

ptr<card_converter> card_converter::instance;

// �J�[�h�ϊ��@���\�z����B
card_converter::card_converter() {
	auto ite_mob = [this] (int fir, int las) {
		for (int mid = fir; mid < las; ++mid) {
			struct mob_db* mdb = mob_db(mid);
			if (mdb) {
				s_mob_drop* dro = &mdb->dropitem[MAX_MOB_DROP - 1];
				if (dro->nameid) {
					item_data* idb = itemdb_exists(dro->nameid);
					if (idb &&
						idb->type == IT_CARD
					) {
						if (level_cards.size() < mdb->lv)
							level_cards.resize(mdb->lv);
						level_cards[mdb->lv - 1].push_back(dro->nameid);
					}
				}
			}
		}
	};
	ite_mob(1000, 1985);
}

// �J�[�h��ʂ̃J�[�h�ɕϊ�����B
int card_converter::convert(int car_id) {
	int res = ITEMID_PORING_CARD;
	int i;
	for (i = 0; i < level_cards.size(); ++i) {
		int j;
		for (j = 0; j < level_cards[i].size(); ++j) {
			if (level_cards[i][j] == car_id) break;
		}
		if (j < level_cards[i].size()) break;
	}
	if (i < level_cards.size()) {
		int ran = 0;
		for (int j = 0; j <= i; ++j) ran += level_cards[j].size();
		int k = rnd() % ran;
		for (int j = 0;; ++j) {
			if (level_cards[j].size() > k) {
				res = level_cards[j][k];
				break;
			}
			k -= level_cards[j].size();
		}
	}
	return res;
}

// ����ꎮ���\�z����B
equipset_t::equipset_t(
	int16_t mid // �����X�^�[ID�B
) : mob_id(mid), individual_mob_id(0), mdb(nullptr) {
	if (mob_id >= MM_INDIVIDUAL) {
		individual_mob_id = mob_id;
		if (individual_mob_id >= MM_CAUTION) individual_mob_id -= MM_CAUTION;
	}
	if (individual_mob_id) {
		mdb = mob_db(individual_mob_id);
		if (!mdb) RAISE_RUNTIME_ERROR("Invalid mob id.");
	}
}

// �A�C�e���̃L�[���\�z����B
item_key::item_key(
	uint16_t nid // �A�C�e��ID�B
) : nameid(nid), refine(CHAR_MIN), attribute(0), idb(nullptr) {
	std::fill(ALL_RANGE(card), 0);
	if (nameid) {
		idb = itemdb_exists(nameid);
		if (!idb) nameid = 0;
	}
}

// �A�C�e���̃L�[���\�z����B
item_key::item_key(
	uint16_t nid, // �A�C�e��ID�B
	uint16_t* car // �X���b�g�B
) : item_key(nid) {
	std::copy(car, car + MAX_SLOTS, card.begin());
}

// �A�C�e���̃L�[���\�z����B
item_key::item_key(
	const std::string& nam // �A�C�e�����B
) : item_key(0) {
	using ele_lis = std::list<ptr<command_element>>;
	using ele_lis_lis = std::list<ptr<ele_lis>>;
	using str_lis = std::vector<std::string>;

	bool cos = nam.substr(0, COSTUME_PREFIX.length()) == COSTUME_PREFIX;
	std::string act_nam;
	if (cos) act_nam = nam.substr(COSTUME_PREFIX.length());
	else act_nam = nam;

	auto eles = initialize<ele_lis>(initialize<command_element>(CET_LITERAL, act_nam));
	eles = command_parse_tokens<ele_lis>(ALL_RANGE(*eles), "|", false, true);
	eles = command_parse_blocks<ele_lis>(ALL_RANGE(*eles), "[", "]", false, true);
	eles = command_parse_blocks<ele_lis>(ALL_RANGE(*eles), "{", "}", false, true);
	eles = command_parse_blocks<ele_lis>(ALL_RANGE(*eles), "<", ">", false, true);
	eles = command_parse_tokens<ele_lis>(ALL_RANGE(*eles), " ", false, true);
	auto slo_blos = command_collect_blocks<ele_lis_lis>(ALL_RANGE(*eles), "[", "]", true);
	auto for_blos = command_collect_blocks<ele_lis_lis>(ALL_RANGE(*eles), "{", "}", true);
	auto tag_blos = command_collect_blocks<ele_lis_lis>(ALL_RANGE(*eles), "<", ">", true);
	if (slo_blos->size() > 1 ||
		for_blos->size() > 1 ||
		tag_blos->size() > 1 ||
		(!slo_blos->empty() &&
			!for_blos->empty()
		) 
	) return;

	int slo = 0;
	if (!slo_blos->empty()) {
		auto slo_toks = command_collect_tokens<ele_lis_lis>(ALL_RANGE(*slo_blos->front()), "|", true);
		slo = slo_toks->size();
		if (slo > MAX_SLOTS) return;
		auto slo_strs = command_print_all<str_lis>(ALL_RANGE(*slo_toks));
		for (int i = 0; i < slo_strs->size(); ++i) {
			std::string slo_str = slo_strs->at(i);
			if (!slo_str.empty()) {
				item_data* car_db;
				int car_nid = parse_id(slo_str);
				if (car_nid) {
					if (car_nid == INT_MIN) return;
					car_db = itemdb_exists(car_nid);
				} else {
					std::string car_nam = slo_str + CARD_NAME_POSTFIX;
					car_db = itemdb_searchname(car_nam.c_str());
				} 
				if (!car_db) return;
				card[i] = car_db->nameid;
			}
		}
	}

	if (!for_blos->empty()) {
		card[0] = CARD0_FORGE;
		auto for_toks = command_collect_tokens<ele_lis_lis>(ALL_RANGE(*for_blos->front()), "|", false);
		if (for_toks->size() > MAX_SLOTS) return;
		auto for_strs = command_print_all<str_lis>(ALL_RANGE(*for_toks));
		int ele = ELE_NEUTRAL, sta = 0;
		for (const std::string& for_str : *for_strs) {
			auto ele_nam_ite = std::find(ALL_RANGE(ELEMENT_NAME_TABLE), for_str);
			if (ele_nam_ite != ELEMENT_NAME_TABLE.end())
				ele = ele_nam_ite - ELEMENT_NAME_TABLE.begin();
			else if (for_str == STAR_FORGED_TAG)sta += 5;
		}
		card[1] = ele | (sta << 8);
	}

	if (!tag_blos->empty()) {
		auto tag_toks = command_collect_tokens<ele_lis_lis>(ALL_RANGE(*tag_blos->front()), "|", false);
		auto tag_strs = command_print_all<str_lis>(ALL_RANGE(*tag_toks));
		for (const std::string& tag_str : *tag_strs) {
			if (tag_str.front() == '+') {
				refine = pybot::stoi(tag_str, CHAR_MIN);
				if (refine == CHAR_MIN) return;
			} else if (tag_str == BROKEN_EQUIP_TAG) attribute = 1;
			else if (tag_str == FAME_TAG) card[0] = CARD0_CREATE;
		}
	}

	auto pay_eles = initialize<ele_lis>();
	for (auto ele : *eles) {
		if (ele->type == CET_OPEN) break;
		pay_eles->push_back(ele);
	}
	std::string pay_str = lowercase(trim(command_print(ALL_RANGE(*pay_eles)), " \t"));
	if (cos) pay_str = COSTUME_PREFIX + pay_str;

	nameid = parse_id(pay_str);
	if (nameid) {
		if (nameid != INT_MIN) {
			if (nameid >= FAME_OFFSET) {
				nameid -= FAME_OFFSET;
				card[0] = CARD0_CREATE;
			}
			idb = itemdb_exists(nameid);
			if (!idb) nameid = 0;
		}
	} else {
		item_data* idbs[256];
		int cou = itemdb_searchname_array(idbs, 256, pay_str.c_str());
		for (int i = 0; i < cou; i++) {
			if (idbs[i]->slot == slo &&
				lowercase(idbs[i]->jname) == pay_str
			) {
				nameid = idbs[i]->nameid;
				idb = idbs[i];
				break;
			}
		}
	}
}

// ���t�X�L�����\�z����B
play_skill::play_skill(
	int16_t mid,    // �����X�^�[ID�B
	e_skill sk_id   // �X�L��ID�B
) : mob_id(mid), individual_mob_id(0), mdb(nullptr), skill_id(sk_id) {
	if (mob_id >= MM_INDIVIDUAL) {
		individual_mob_id = mob_id;
		if (individual_mob_id >= MM_CAUTION) individual_mob_id -= MM_CAUTION;
	}
	if (individual_mob_id) {
		mdb = mob_db(individual_mob_id);
		if (!mdb) RAISE_RUNTIME_ERROR("Invalid mob id.");
	}
}

// �ʒu���\�z����B
pos_t::pos_t() : x(0), y(0), value(0), advantage(INT_MIN) {}

// �ʒu���\�z����B
pos_t::pos_t(
	int x_,  // X���W�B
	int y_,  // Y���W�B
	int val, // �l�B
	int adv  // �A�h�o���e�[�W�B
) : x(x_), y(y_), value(val), advantage(adv) {}

// �X�R�[�v���甲����Ƃ��̏��������s����B
scope_exit::~scope_exit() {
	if (do_) do_();
}

ptr<skill_mobs> skill_mobs::instance;

// �X�L�����������X�^�[ID�̃Z�b�g���\�z����B
skill_mobs::skill_mobs() {
	auto ini_set = [] (std::unordered_set<int>& mobs, mob_skill_pred pre) {
		auto ite_mob = [&mobs, pre] (int fir, int las) {
			for (int mid = fir; mid < las; ++mid) {
				struct mob_db* mdb = mob_db(mid);
				if (mdb &&
					find_mob_skill(mdb, pre) != INT_MIN
				) mobs.insert(mid);
			}
		};
		ite_mob(1000, 3000);
		ite_mob(20020, 32000);
	};
	auto is_kno_sk = [] (e_skill kid, int klv) -> bool {
		return skill_get_blewcount(kid, klv);
	};
	auto is_lay_sk = [] (e_skill kid, int klv) -> bool {
		return skill_get_unit_id(kid, 0) &&
			!KEY_EXISTS(LAYABLE_ON_LP_SKILLS, kid);
	};
	auto is_une_arm_sk = [] (e_skill kid, int klv) -> bool {
		return KEY_EXISTS(UNEQUIP_ARMOR_SKILLS, kid);
	};
	auto is_une_hel_sk = [] (e_skill kid, int klv) -> bool {
		return KEY_EXISTS(UNEQUIP_HELM_SKILLS, kid);
	};
	auto is_une_shi_sk = [] (e_skill kid, int klv) -> bool {
		return KEY_EXISTS(UNEQUIP_SHIELD_SKILLS, kid);
	};
	auto is_une_wea_sk = [] (e_skill kid, int klv) -> bool {
		return KEY_EXISTS(UNEQUIP_WEAPON_SKILLS, kid);
	};
	auto is_use_sk = [] (e_skill kid, int klv) -> bool {
		return KEY_EXISTS(USEFULL_SKILLS, kid);
	};

	ini_set(knockback, is_kno_sk);
	ini_set(layout, is_lay_sk);
	ini_set(long_, mob_skill_is_long);
	ini_set(long_weapon, mob_skill_is_long_weapon);
	ini_set(unequip_armor, is_une_arm_sk);
	ini_set(unequip_helm, is_une_hel_sk);
	ini_set(unequip_shield, is_une_shi_sk);
	ini_set(unequip_weapon, is_une_wea_sk);
	ini_set(usefull, is_use_sk);
}

// SQL�̃Z�b�V�������\�z����B
sql_session::sql_session(
	SqlStmt* stm // ���B
) : stmt(stm) {}

// SQL�̃Z�b�V������j������B
sql_session::~sql_session() {
	SqlStmt_Free(stmt);
}

// SELECT���̌��ʂ̎��̍s�Ɉڂ�B
bool // ���̍s�����邩�B
sql_session::next_row() {
	return SqlStmt_NextRow(stmt) == SQL_SUCCESS;
}

// SQL�̃Z�b�V�������J���B
void sql_session::open(
	do_func do_ // �����B
) {
	SqlStmt* stm = SqlStmt_Malloc(mmysql_handle);
	if (!stm) RAISE_RUNTIME_ERROR("Failed to SqlStmt_Malloc.");
	sql_session ses(stm);
	do_(&ses);
}

// SQL�̕����Ƀe�L�X�g��ǉ�����B
void sql_context::append_with(
	const std::string& tex // �e�L�X�g�B
) {
	buffer << tex;
}

// SQL�̕����ɗ��ǉ�����B
void sql_context::append_with(
	ptr<sql_column> col // ��B
) {
	buffer << col->name;
	columns.push_back(col);
}

// SQL�̕����Ƀp�����[�^��ǉ�����B
void sql_context::append_with(
	ptr<sql_param> par // �p�����[�^�B
) {
	buffer << "?";
	params.push_back(par);
}

// SQL���ɗ���o�C���h����B
void sql_column::bind(
	SqlStmt* stm, // ���B
	int ind       // �C���f�b�N�X�B
) {
	if (SqlStmt_BindColumn(stm, ind, type, data, size, NULL, NULL) == SQL_ERROR) {
		SqlStmt_ShowDebug(stm);
		RAISE_RUNTIME_ERROR("Failed SqlStmt_BindColumn.");
	}
}

// SQL���Ƀp�����[�^���o�C���h����B
void sql_param::bind(
	SqlStmt* stm, // ���B
	int ind       // �C���f�b�N�X�B
) {
	if (SqlStmt_BindParam(stm, ind, type, data, size) == SQL_ERROR) {
		SqlStmt_ShowDebug(stm);
		RAISE_RUNTIME_ERROR("Failed SqlStmt_BindParam.");
	}
}

// �q�ɂ̕������\�z����B
storage_context::storage_context(
	int cap_,              // �e�ʁB
	map_session_data* sd_, // �Z�b�V�����f�[�^�B
	s_storage* sto         // �q�ɁB
) : capacity(cap_), sd(sd_), storage(sto) {}

// �q�ɂ̃A�C�e�����Q�Ƃ���B
item* storage_context::at(
	int ind // �C���f�b�N�X�B
) {
	return &storage->u.items_storage[ind];
}

// �q�ɂ���A�C�e����T���B
int // ���������C���f�b�N�X�B������Ȃ�������INT_MIN�B
storage_context::find(
	int nid // �A�C�e��ID�B
) {
	if (!indices) {
		indices = initialize<index_map>();
		for (int i = 0; i < capacity; ++i) {
			item* itm = at(i);
			int nid = itm->nameid;
			if (nid) {
				if (itm->card[0] == CARD0_CREATE &&
					pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST)
				) nid += FAME_OFFSET;
				(*indices)[nid] = i;
			}
		}
	}
	return find_map_data(*indices, nid, INT_MIN);
}

// �A�C�e�����ʂ̍��v���擾����B
int // �擾�������v�B
storage_context::sum(
	int nid // �A�C�e��ID�B
) {
	int res = 0;
	for (int i = 0; i < capacity; ++i) {
		item* itm = at(i);
		int nid2 = itm->nameid;
		if (nid2) {
			if (itm->card[0] == CARD0_CREATE &&
				pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST)
			) nid2 += FAME_OFFSET;
			if (nid2 == nid) res += itm->amount;
		}
	}
	return res;
}

// �A�C�e����ǉ������Ƃ��ɃC���f�b�N�X�}�b�v���X�V����B
void storage_context::update_indices_by_adding(
	item* itm // �A�C�e���B
) {
	int nid = itm->nameid;
	if (itm->card[0] == CARD0_CREATE &&
		pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST)
	) nid += FAME_OFFSET;
	if (indices &&
		!KEY_EXISTS(*indices, nid)
	) indices = nullptr;
}

// �A�C�e�����폜�����Ƃ��ɃC���f�b�N�X�}�b�v���X�V����B
void storage_context::update_indices_by_deletion(
	int ind
) {
	if (indices &&
		!at(ind)->nameid
	) indices = nullptr;
}

// �����A�C�e���̕������\�z����B
inventory_context::inventory_context(
	map_session_data* sd_
) : storage_context(MAX_INVENTORY, sd_, &sd_->inventory) {}

// �����A�C�e���ɒǉ�����B
bool // �������B
inventory_context::add(
	item* itm, // �A�C�e���B
	int amo    // ���ʁB
) {
	bool res = !pc_additem(sd, itm, amo, LOG_TYPE_NONE);
	if (res) update_indices_by_adding(itm);
	return res;
}

// �����A�C�e������폜����B
void inventory_context::delete_(
	int ind, // �C���f�b�N�X�B
	int amo  // ���ʁB
) {
	pc_delitem(sd, ind, amo, 0, 0, LOG_TYPE_NONE);
	update_indices_by_deletion(ind);
}

// �J�[�g�̕������\�z����B
cart_context::cart_context(
	map_session_data* sd_
) : storage_context(MAX_CART, sd_, &sd_->cart) {}

// �J�[�g�ɒǉ�����B
bool // �������B
cart_context::add(
	item* itm, // �A�C�e���B
	int amo    // ���ʁB
) {
	bool res = !pc_cart_additem(sd, itm, amo, LOG_TYPE_NONE);
	if (res) update_indices_by_adding(itm);
	return res;
}

// �J�[�g����폜����B
void cart_context::delete_(
	int ind, // �C���f�b�N�X�B
	int amo  // ���ʁB
) {
	pc_cart_delitem(sd, ind, amo, 0, LOG_TYPE_NONE);
	update_indices_by_deletion(ind);
}

// �l�q�ɂ̕������\�z����B
private_storage_context::private_storage_context(
	map_session_data* sd_
) : storage_context(MAX_STORAGE, sd_, &sd_->storage) {}

// �l�q�ɂɒǉ�����B
bool // �������B
private_storage_context::add(
	item* itm, // �A�C�e���B
	int amo    // ���ʁB
) {
	bool res = !storage_additem(sd, storage, itm, amo);
	if (res) update_indices_by_adding(itm);
	return res;
}

// �l�q�ɂ���폜����B
void private_storage_context::delete_(
	int ind, // �C���f�b�N�X�B
	int amo  // ���ʁB
) {
	storage_delitem(sd, storage, ind, amo);
	update_indices_by_deletion(ind);
}

// �M���h�q�ɂ̕������\�z����B
guild_storage_context::guild_storage_context(
	map_session_data* sd_
) : storage_context(MAX_GUILD_STORAGE, sd_, guild2storage2(sd_->status.guild_id)) {}

// �M���h�q�ɂɒǉ�����B
bool // �������B
guild_storage_context::add(
	item* itm, // �A�C�e���B
	int amo    // ���ʁB
) {
	bool res = storage_guild_additem(sd, storage, itm, amo);
	if (res) update_indices_by_adding(itm);
	return res;
}

// �M���h�q�ɂ���폜����B
void guild_storage_context::delete_(
	int ind, // �C���f�b�N�X�B
	int amo  // ���ʁB
) {
	storage_guild_delitem(sd, storage, ind, amo);
	update_indices_by_deletion(ind);
}

// -----------------------------------------------------------------------------
// ���̑��̊֐��̒�`

// ���ۂ̃A�C�e��ID���擾����B
int // �擾�������ۂ̃A�C�e��ID�B
actual_nameid(
	int nid // �A�C�e��ID�B
) {
	int act_nid = nid;
	if (act_nid >= FAME_OFFSET) act_nid -= FAME_OFFSET;
	return act_nid;
}

// Bot���T�[�o�[�ɓ��邱�Ƃ��ł��邩�𔻒肷��B
bool // ���ʁB
bot_can_enter_server(
	int aid // �A�J�E���gID�B
) {
	return !map_id2bl(aid) &&
		!chrif_search(aid);
}

// �u���b�N���X�g�l���n���h�����R�[���o�b�N����B
int callback_yield_bl(
	block_list* bl, // �u���b�N���X�g�B
	va_list ap      // �ϒ������̃��X�g�B
) {
	yield_bl_func* fun = va_arg(ap, yield_bl_func*);
	return (*fun)(bl);
}

// x��y�̎l�����l�ȏォ���`�F�b�N����B
bool // ���ʁB
check_quad_ratio(
	int x,  // x�B
	int y,  // y�B
	int rat // �l�����B
) {
	int z = 0;
	if (rat & 4) z += y >> 0;
	if (rat & 2) z += y >> 1;
	if (rat & 1) z += y >> 2;
	return x >= z;
}

// ���W���Ǎۂ��𔻒肷��B
bool // ���ʁB
check_wall_side(
	int m, // �}�b�vID�B
	int x, // X���W�B
	int y  // Y���W�B
) {
	for (int i = 0; i < DIR_MAX; ++i) {
		if (map_getcell(m, x + dirx[i], y + diry[i], CELL_CHKNOPASS)) return true;
	}
	return false;
}

// �A�C�e���f�[�^��T���B
int // ���������A�C�e��ID�B������Ȃ�������0�B
find_itemdb(
	const std::string& nam // �A�C�e�����B
) {
	using ele_lis = std::list<ptr<command_element>>;
	using ele_lis_lis = std::list<ptr<ele_lis>>;
	using str_lis = std::vector<std::string>;

	int nid = 0;

	bool cos = nam.substr(0, COSTUME_PREFIX.length()) == COSTUME_PREFIX;
	std::string act_nam;
	if (cos) act_nam = nam.substr(COSTUME_PREFIX.length());
	else act_nam = nam;

	auto eles = initialize<ele_lis>(initialize<command_element>(CET_LITERAL, act_nam));
	eles = command_parse_blocks<ele_lis>(ALL_RANGE(*eles), "[", "]", false, true);
	eles = command_parse_blocks<ele_lis>(ALL_RANGE(*eles), "<", ">", false, true);

	auto slo_blos = command_collect_blocks<ele_lis_lis>(ALL_RANGE(*eles), "[", "]", true);
	auto tag_blos = command_collect_blocks<ele_lis_lis>(ALL_RANGE(*eles), "<", ">", true);
	if (slo_blos->size() > 1||
		tag_blos->size() > 1
	) return nid;

	int slo = 0;
	if (!slo_blos->empty()) {
		slo = pybot::stoi(command_print(ALL_RANGE(*slo_blos->front())), INT_MIN);
		if (slo == INT_MIN) return nid;
	}

	bool fam = false;
	if (!tag_blos->empty()) {
		auto tag_toks = command_collect_tokens<ele_lis_lis>(ALL_RANGE(*tag_blos->front()), "|", false);
		auto tag_strs = command_print_all<str_lis>(ALL_RANGE(*tag_toks));
		for (const std::string& tag_str : *tag_strs) {
			if (tag_str == FAME_TAG) fam = true;
		}
	}

	auto pay_eles = initialize<ele_lis>();
	for (auto ele : *eles) {
		if (ele->type == CET_OPEN) break;
		pay_eles->push_back(ele);
	}
	std::string pay_str = lowercase(trim(command_print(ALL_RANGE(*pay_eles)), " \t"));
	if (cos) pay_str = COSTUME_PREFIX + pay_str;

	nid = parse_id(pay_str);
	if (nid) {
		if (nid == INT_MIN ||
			!itemdb_exists(actual_nameid(nid))
		) nid = 0;
	} else {
		int typ_ind = find_name(ITEM_TYPE_NAME_TABLE, pay_str);
		if (typ_ind != INT_MIN) {
			if (ITEM_TYPE_NAME_TABLE[typ_ind] == UNKNOWN_SYMBOL) return 0;
			return ITEM_TYPE_OFFSET + typ_ind;
		}
		item_data* idbs[256];
		int cou = itemdb_searchname_array(idbs, 256, pay_str.c_str());
		for (int i = 0; i < cou; i++) {
			if (idbs[i]->slot == slo &&
				lowercase(idbs[i]->jname) == pay_str
			) {
				nid = idbs[i]->nameid;
				break;
			}
		}
	}
	if (nid &&
		fam
	) {
		if (nid >= FAME_OFFSET) nid = 0;
		else nid += FAME_OFFSET;
	}
	return nid;
}

// �����X�^�[�X�L����T���B
int // ���������C���f�b�N�X�B������Ȃ�������INT_MIN�B
find_mob_skill(
	struct mob_db* mdb, // �����X�^�[�f�[�^�B
	mob_skill_pred pre  // �����X�^�[�X�L���q��B
) {
	for (int i = 0; i < MAX_MOBSKILL; i++) {
		mob_skill* msk = &mdb->skill[i];
		if (msk->skill_id &&
			pre(e_skill(msk->skill_id), msk->skill_lv)
		) return i;
	}
	return INT_MIN;
}

// ���[�_�[�̉�ʓ��ɂ��郂���X�^�[��T���B
mob_data* // �������������X�^�[�f�[�^�B������Ȃ�������nullptr�B
find_mob(
	block_if* lea, // ���[�_�[�B
	int mid        // �����X�^�[ID�B0�Ȃ炷�ׂẴ����X�^�[�B
) {
	mob_data* nea_md = nullptr;
	int nea_dis;
	yield_bl_func yie_md = [lea, mid, &nea_md, &nea_dis] (block_list* bl) -> int {
		int dis = distance_client_bl(lea->bl(), bl);
		mob_data* md = (mob_data*)(bl);
		if (!md->sc.data[SC_WINKCHARM] &&
			(!md->master_id ||
				!map_id2sd(md->master_id)
			) && (!mid ||
				md->mob_id == mid
			) && (!nea_md ||
				dis < nea_dis
			)
		) {
			nea_md = md;
			nea_dis = dis;
		}
		return 0;
	};
	map_foreachinshootrange(
		callback_yield_bl,
		lea->bl(),
		AREA_SIZE,
		BL_MOB,
		&yie_md
	);
	return nea_md;
}

// �A�C�e����T���B
int // �������C���f�b�N�X�B������Ȃ�������INT_MIN�B
find_item(
	s_storage* sto,      // �q�ɁB
	int cap,             // �e�ʁB
	const item_key& key, // �A�C�e���̃L�[�B
	item_data** idbs,    // DB�̔z��B
	int equ              // �������ʁBINT_MIN�Ȃ�`�F�b�N�Ȃ��B
) {

	for (int i = 0; i < cap; ++i) {
		item* itm = &sto->u.items_inventory[i];
		if (itm->nameid != key.nameid ||
			(equ != INT_MIN &&
				itm->equip != equ
			) || (key.refine != CHAR_MIN &&
				itm->refine != key.refine
			)
		) continue;
		item_data* idb;
		if (idbs) idb = idbs[i];
		else idb = itemdb_exists(itm->nameid);
		if (!idb ||
			itm->attribute != key.attribute
		) continue;
		bool fam = itm->card[0] == CARD0_CREATE &&
			pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST);
		if ((key.card[0] == CARD0_CREATE &&
				!fam
			) || (key.card[0] != CARD0_CREATE &&
				fam
			)
		) continue;
		if (key.card[0] == CARD0_FORGE) {
			if (itm->card[0] != CARD0_FORGE) continue;
			int itm_ele = itm->card[1] & 0x0f;
			int itm_sta = itm->card[1] >> 8;
			int key_ele = key.card[1] & 0x0f;
			int key_sta = key.card[1] >> 8;
			if (itm_ele != key_ele ||
				itm_sta != key_sta
			) continue;
		} else if (idb->slot) {
			int j;
			std::array<bool,MAX_SLOTS> fou{};
			for (j = 0; j < idb->slot; ++j) {
				int k;
				for (k = 0; k < idb->slot; ++k) {
					if (itm->card[k] == key.card[j] &&
						!fou[k]
					) {
						fou[k] = true;
						break;
					}
				}
				if (k == idb->slot) break;
			}
			if (j < idb->slot) continue;
		}
		return i;
	}
	return INT_MIN;
}

// �X�L����T���B
int // ���������X�L��ID�B������Ȃ�������0�B
find_skilldb(
	const std::string& nam // �X�L�����B�����Ȃ�X�L��ID�B
) {
	int kid = parse_id(nam);
	if (kid) {
		if (kid != INT_MIN &&
			skill_get_index(kid) < 0
		) kid = 0;
	} else {
		std::string nam_lc = lowercase(nam);
		for (int i = 0; i < MAX_SKILL; ++i) {
			kid = skill_idx2id(i);
			if (kid &&
				lowercase(skill_get_desc(kid)) == nam_lc
			) break;
		}
	}
	return kid;
}

// �����A�N�e�B�u�Ȃ烁���o�[�̃z�����N���X���擾����B
block_if* // �擾�����z�����N���X�B�A�N�e�B�u�ł͂Ȃ��Ȃ�nullptr�B
get_active_homun(
	block_if* mem // �����o�[�B
) {
	block_if* hom = get_homun_if_exists(mem);
	if (!hom) return nullptr;
	if (!hom->is_active()) throw command_error{print("�u", hom->name(), "�v�̓A�N�e�B�u�ł͂���܂���B")};
	return hom;
}

// �������݂��Ă���΃����o�[�̃z�����N���X���擾����B
block_if* // �擾�����z�����N���X�B���݂��Ă��Ȃ��Ȃ�nullptr�B
get_homun_if_exists(
	block_if* mem // �����o�[�B
) {
	block_if* hom = mem->homun().get();
	if (!hom->exists()) throw command_error{print("�u", mem->name(), "�v�̓z�����N���X�����L���Ă��܂���B")};
	return hom;
}

// �����A�N�e�B�u�Ȃ烁���o�[�̃y�b�g���擾����B
block_if* // �擾�����y�b�g�B�A�N�e�B�u�ł͂Ȃ��Ȃ�nullptr�B
get_active_pet(
	block_if* mem // �����o�[�B
) {
	block_if* pet = get_pet_if_exists(mem);
	if (!pet) return nullptr;
	if (!pet->is_active()) throw command_error{print("�u", pet->name(), "�v�̓A�N�e�B�u�ł͂���܂���B")};
	return pet;
}

// �������݂��Ă���΃����o�[�̃y�b�g���擾����B
block_if* // �擾�����z�����N���X�B���݂��Ă��Ȃ��Ȃ�nullptr�B
get_pet_if_exists(
	block_if* mem // �����o�[�B
) {
	block_if* pet = mem->pet().get();
	if (!pet->exists()) throw command_error{print("�u", mem->name(), "�v�̓y�b�g�����L���Ă��܂���B")};
	return pet;
}

// �����`�̋��̍��W�𔽕�����B
void iterate_corner_bl(
	block_list* cen,  // ���S�B
	int rad,          // ���a�B
	yield_xy_func yie // ���W�l���n���h���B
) {
	iterate_corner_xy(cen->m, cen->x, cen->y, rad, yie);
}

// �����`�̋��̍��W�𔽕�����B
void iterate_corner_xy(
	int m,            // ���S�̃}�b�vID�B
	int x,            // ���S��X���W�B
	int y,            // ���S��Y���W�B
	int rad,          // ���a�B
	yield_xy_func yie // ���W�l���n���h���B
) {
	map_data* mpd = map_getmapdata(m);
	int x0 = x - rad;
	int x1 = x + rad;
	int y0 = y - rad;
	int y1 = y + rad;
	using coo_t = std::array<int,2>;
	std::array<coo_t,4> pois = {
		coo_t{x0, y0},
		coo_t{x0, y1},
		coo_t{x1, y0},
		coo_t{x1, y1},
	};
	bool con = true;
	for (int i = 0; i < pois.size() && con; ++i) {
		const coo_t& coo = pois[i];
		if (map_getcellp(mpd, coo[0], coo[1], CELL_CHKNOPASS))
			continue;
		con = yie(coo[0], coo[1]);
	}
}

// �����`�̉��̍��W�𔽕�����B
void iterate_edge_bl(
	block_list* cen,  // ���S�B
	int rad,          // ���a�B
	yield_xy_func yie // ���W�l���n���h���B
) {
	iterate_edge_xy(cen->m, cen->x, cen->y, rad, yie);
}

// �����`�̉��̍��W�𔽕�����B
void iterate_edge_xy(
	int m,            // ���S�̃}�b�vID�B
	int x,            // ���S��X���W�B
	int y,            // ���S��Y���W�B
	int rad,          // ���a�B
	yield_xy_func yie // ���W�l���n���h���B
) {
	map_data* mpd = map_getmapdata(m);
	int x0 = x - rad;
	int x1 = x + rad;
	int y0 = y - rad;
	int y1 = y + rad;
	bool con = true;
	for (int y = y0; y <= y1 && con; ++y) {
		if (y == y0 ||
			y == y1
		) {
			for (int x = x0; x <= x1 && con; ++x) {
				if (map_getcellp(mpd, x, y, CELL_CHKPASS)) con = yie(x, y);
			}
		} else if (map_getcellp(mpd, x0, y, CELL_CHKPASS) &&
			(con = yie(x0, y)) &&
			map_getcellp(mpd, x1, y, CELL_CHKPASS)
		) con = yie(x1, y);
	}
}

// �ݒu���ꂽ�X�L�����j�b�g�𔽕�����B
int // �l�������X�L�����j�b�g���B
iterate_skill_unit(
	int m,                    // �}�b�vID�B
	int x,                    // X���W�B
	int y,                    // Y���W�B
	yield_skill_unit_func yie // �X�L�����j�b�g�l���n���h���B
) {
	yield_bl_func yie_bl = [yie] (block_list* bl) -> int {
		skill_unit* kun = (skill_unit*)(bl);
		block_list* src_bl = map_id2bl(kun->group->src_id);
		if (src_bl) return yie(kun, src_bl);
		return 0;
	};
	return map_foreachincell(callback_yield_bl, m, x, y, BL_SKILL, &yie_bl);
}

// �}�b�v�����[�h����B
void load_maps() {
	sql_session::open([] (sql_session* ses) {
		char nam_eng[11 + 1];
		char nam_jap[100 + 1];
		int nat_typ;
		int map_typ;
		int fev_fla;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("name_english" , nam_eng), "`,"
			" `", construct<sql_column>("name_japanese", nam_jap), "`,"
			" `", construct<sql_column>("nation_type"  , nat_typ), "`,"
			" `", construct<sql_column>("map_type"     , map_typ), "`,"
			" `", construct<sql_column>("fever_flag"   , fev_fla), "` "
			"FROM `pybot_map`"
		);
		while (ses->next_row()) {
			int ind = mapindex_name2id(nam_eng);
			if (ind) {
				int id = map_mapindex2mapid(ind);
				auto map = initialize<pybot_map>(
					id,
					nam_eng,
					nam_jap,
					nation_types(nat_typ),
					map_types(map_typ),
					bool(fev_fla)
				);
				id_maps.insert(std::make_pair(id, map));
				type_maps[nat_typ * 100 + map_typ].push_back(map);
			}
		}
	});
}

// �������̕�����ɕϊ�����B
std::string // �ϊ�����������B
lowercase(
	const std::string& str // ������B
) {
	std::stringstream buf;
	for (int i = 0; i < str.length();) {
		uint8_t let = str[i++];
		if (i < str.length() &&
			letter_is_jlead(let)
		) buf << let << str[i++];
		else buf << uint8_t(std::tolower(let));
	}
	return buf.str();
}

// �����t���[���^�����X�^�[���𔻒肷��B
bool // ���ʁB
mob_is_pure_flora(
	mob_data* md // �����X�^�[�f�[�^�B
) {
	return !status_has_mode(&md->status, MD_CANMOVE) &&
		status_has_mode(&md->status, MD_CANATTACK) &&
		status_get_range(&md->bl) <= 3;
}

// �����X�^�[�̃X�L�������u���𔻒肷��B
bool // ���ʁB
mob_skill_is_long(
	e_skill kid, // �X�L��ID�B
	int klv      // �X�L�����x���B
) {
	return !KEY_EXISTS(MOB_SHORT_SKILLS, e_skill(kid)) &&
		!(skill_get_nk(kid) & NK_NO_DAMAGE) &&
		(skill_get_range(kid, klv) > 3 ||
			skill_get_splash(kid, klv) < 0 ||
			skill_get_splash(kid, klv) > 3
		);
}

// �����X�^�[�̃X�L�������u�������𔻒肷��B
bool // ���ʁB
mob_skill_is_long_weapon(
	e_skill kid, // �X�L��ID�B
	int klv      // �X�L�����x���B
) {
	return mob_skill_is_long(kid, klv) &&
		skill_get_type(kid) & BF_WEAPON;
}

// NPC�̕\�������擾����B
std::string // �擾�����\�����B
npc_display_name(
	const std::string& npc_name // NPC�̖��O�B
) {
	std::string::size_type sha_pos = npc_name.find_first_of('#');
	if (sha_pos == std::string::npos) sha_pos = npc_name.length();
	return npc_name.substr(0, sha_pos);
}

// ID����͂���B
int // ��͂���ID�BID�ł͂Ȃ��Ȃ�0�B�ԍ��̌`�����s���Ȃ�INT_MIN�B
parse_id(
	const std::string& nam // ���O�B
) {
	int id = 0;
	if (!nam.empty() &&
		nam.front() == ID_PREFIX
	) id = pybot::stoi(nam.substr(1), INT_MIN);
	return id;
}

// �C���f�b�N�X����͂���B
int // ��͂����C���f�b�N�X�B�C���f�b�N�X�ł͂Ȃ��Ȃ�-1�B�ԍ��̌`�����s���Ȃ�INT_MIN�B
parse_index(
	const std::string& nam // ���O�B
) {
	int i = -1;
	if (!nam.empty() &&
		nam.front() == INDEX_PREFIX
	) i = pybot::stoi(nam.substr(1), INT_MIN);
	return i;
}

// �������ʂ������B
std::string // ���������ʁB
print_equip_pos(
	equip_pos equ // �������ʁB
) {
	std::vector<std::string> toks;
	for (int i = 0; i < EPO2EQI_TABLE.size(); ++i) {
		if (equ & equip_bitmask[EPO2EQI_TABLE[i]])
			toks.push_back(EQUIP_POS_NAME_TABLE[EPO2EQI_TABLE[i]]);
	}
	if (toks.empty()) toks.push_back(UNKNOWN_SYMBOL);
	return concatinate_strings(ALL_RANGE(toks), "+");
}

// �����̃^�C�v�������B
std::string // �������^�C�v�B
print_equip_type(
	item_data* idb // �A�C�e���f�[�^�B
) {
	if (idb->type == IT_WEAPON)	return WEAPON_TYPE_NAME_TABLE[idb->look];
	else if (idb->type == IT_ARMOR) {
		for (int i = 0; i < EPO2EQI_TABLE.size(); ++i) {
			if (idb->equip & equip_bitmask[EPO2EQI_TABLE[i]])
				return ARMOR_TYPE_NAME_TABLE[i];
		}
	} else if (idb->type == IT_AMMO) return AMMO_TYPE_NAME_TABLE[idb->look];
	else if (idb->type == IT_PETARMOR) return PET_ACCESSORY_TYPE_NAME;
	return UNKNOWN_SYMBOL;
}

// �A�C�e���������B
std::string // �������A�C�e���B
print_item(
	item* itm,      // �A�C�e���B
	item_data* idb, // �A�C�e���f�[�^�B
	int amo         // ���B�ȗ��Ȃ�itm->amount�B
) {
	std::vector<std::string> toks;
	std::vector<std::string> tag_toks;
	tag_toks.push_back(ITEM_TYPE_NAME_TABLE[idb->type]);
	if (itm->identify) {
		toks.push_back(idb->jname);
		if (itm->card[0] == CARD0_CREATE) {
			if (pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST))
				tag_toks.push_back(FAME_TAG);
		} else if (itm->card[0] == CARD0_FORGE) {
			std::vector<std::string> for_toks;
			int ele = itm->card[1] & 0x0f;
			if (ele) for_toks.push_back(ELEMENT_NAME_TABLE[ele]);
			int sta = itm->card[1] >> 8;
			for (int i = 0; i < sta; i += 5) for_toks.push_back(STAR_FORGED_TAG);
			toks.push_back(print("{", concatinate_strings(ALL_RANGE(for_toks), "|"), "}"));
		} else if (idb->slot) {
			std::vector<std::string> slo_toks;
			for (int i = 0; i < idb->slot; ++i) {
				if (!itm->card[i]) {
					slo_toks.push_back("");
					continue;
				}
				std::string mob_nam = UNKNOWN_SYMBOL;
				item_data* car_db = itemdb_exists(itm->card[i]);
				if (car_db) {
					mob_nam = car_db->jname;
					if (mob_nam.length() >= 6) mob_nam = mob_nam.substr(0, mob_nam.length() - 6);
				}
				slo_toks.push_back(mob_nam);
			}
			toks.push_back(print("[", concatinate_strings(ALL_RANGE(slo_toks), "|"), "]"));
		}
		if (itm->refine > 0) tag_toks.push_back(print("+", int(itm->refine)));
		if (itm->attribute == 1) tag_toks.push_back(BROKEN_EQUIP_TAG);
	} else toks.push_back(UNKNOWN_SYMBOL);
	toks.push_back(print("<", concatinate_strings(ALL_RANGE(tag_toks), "|"), ">"));
	if (!amo) amo = itm->amount;
	if (amo > 1) toks.push_back(print("(", amo, ")"));
	return concatinate_strings(ALL_RANGE(toks), " ");
}

// �A�C�e���L�[�������B
std::string // �������A�C�e���L�[�B
print_item_key(
	const item_key& key // �A�C�e���̃L�[�B
) {
	std::vector<std::string> toks;
	toks.push_back(key.idb->jname);
	if (key.card[0] == CARD0_FORGE) {
		std::vector<std::string> for_toks;
		int ele = key.card[1] & 0x0f;
		if (ele) for_toks.push_back(ELEMENT_NAME_TABLE[ele]);
		int sta = key.card[1] >> 8;
		for (int i = 0; i < sta; i += 5) for_toks.push_back(STAR_FORGED_TAG);
		toks.push_back(print("{", concatinate_strings(ALL_RANGE(for_toks), "|"), "}"));
	} else if (key.idb->slot) {
		std::vector<std::string> slo_toks;
		for (int i = 0; i < key.idb->slot; ++i) {
			if (!key.card[i]) {
				slo_toks.push_back("");
				continue;
			}
			std::string mob_nam = UNKNOWN_SYMBOL;
			item_data* car_db = itemdb_exists(key.card[i]);
			if (car_db) {
				mob_nam = car_db->jname;
				if (mob_nam.length() >= 6) mob_nam = mob_nam.substr(0, mob_nam.length() - 6);
			}
			slo_toks.push_back(mob_nam);
		}
		toks.push_back(print("[", concatinate_strings(ALL_RANGE(slo_toks), "|"), "]"));
	}
	return concatinate_strings(ALL_RANGE(toks), " ");
}

// �A�C�e���f�[�^�������B
std::string // �������A�C�e���f�[�^�B
print_itemdb(
	int nid // �A�C�e��ID�B
) {
	if (nid >= ITEM_TYPE_OFFSET &&
		nid < ITEM_TYPE_OFFSET + IT_MAX
	) return ITEM_TYPE_NAME_TABLE[nid - ITEM_TYPE_OFFSET];
	std::vector<std::string> toks;
	std::vector<std::string> tag_toks;
	int act_nid = actual_nameid(nid);
	item_data* idb = itemdb_exists(act_nid);
	toks.push_back(idb->jname);
	if (idb->slot) toks.push_back(print("[", idb->slot, "]"));
	tag_toks.push_back(ITEM_TYPE_NAME_TABLE[idb->type]);
	if (nid >= FAME_OFFSET) tag_toks.push_back(FAME_TAG);
	toks.push_back(print("<", concatinate_strings(ALL_RANGE(tag_toks), "|"), ">"));
	return concatinate_strings(ALL_RANGE(toks), " ");
}

// �����X�^�[�f�[�^�������B
std::string // �����������X�^�[�f�[�^�B
print_mobdb(
	int mid // �����X�^�[ID�B
) {
	std::string nam = find_map_data(META_MONSTER_NAMES, meta_mobs(mid));
	if (!nam.empty()) return nam;
	if (mid >= MM_RACE &&
		mid < MM_RACE + 10
	) return RACE_NAME_TABLE[mid - MM_RACE];
	if (mid >= MM_ELEMENT &&
		mid < MM_ELEMENT + 10
	) return ELEMENT_NAME_TABLE[mid - MM_ELEMENT];
	if (mid >= MM_SIZE &&
		mid < MM_SIZE + 3
	) return SIZE_NAME_TABLE[mid - MM_SIZE];
	if (mid < MM_INDIVIDUAL) return UNKNOWN_SYMBOL;

	int ind_mid = mid;
	bool cau = ind_mid >= MM_CAUTION;
	if (cau) ind_mid -= MM_CAUTION;
	struct mob_db* mdb = mob_db(ind_mid);
	if (!mdb) return UNKNOWN_SYMBOL;

	std::vector<std::string> toks;
	toks.push_back(mdb->jname);
	std::vector<std::string> tag_toks;
	tag_toks.push_back(MOB_CLASS_NAME_TABLE[mdb->status.class_]);
	if (cau) tag_toks.push_back(CAUTION_TAG);
	toks.push_back(print("<", concatinate_strings(ALL_RANGE(tag_toks), "|"), ">"));
	return concatinate_strings(ALL_RANGE(toks), " ");
}

// �X�e�[�^�X�ω��������B
std::string // �������X�e�[�^�X�ω��B
print_sc(
	status_change* sc // �X�e�[�^�X�ω��B
) {
	std::stringstream out;
	for (int sc_typ = 0; sc_typ < SC_MAX; ++sc_typ) {
		if (sc->data[sc_typ]) {
			std::string ico_nam = find_map_data(HOMUN_ICON_NAMES, sc_type(sc_typ));
			if (ico_nam.empty()) {
				efst_types ico = efst_types(StatusIconChangeTable[sc_typ]);
				if (ico != EFST_BLANK) ico_nam = ICON_NAME_TABLE[ico];
			}
			if (!ico_nam.empty() &&
				ico_nam != UNKNOWN_SYMBOL
			) {
				if (out.tellp()) out << " ";
				out << ico_nam;
			}
		}
	}
	return out.str();
}

// Zeny�������B
std::string // 
print_zeny(
	int zen // Zeny�B
) {
	std::vector<int> fies;
	do {
		div_t qr = std::div(zen, 1000);
		zen = qr.quot;
		fies.push_back(qr.rem);
	} while (zen);
	std::stringstream out;
	for (int i = 0; i < fies.size(); ++i) {
		if (i) out << "," << std::setw(3) << std::setfill('0');
		else out << std::setw(0);
		out << fies[fies.size() - i - 1];
	}
	return out.str();
}

// DB�ɃL�����N�^�[ID���Ɖ��B
int // �Ɖ���L�����N�^�[ID�B������Ȃ�������0�B
query_char_id(
	const std::string& uid,  // ���[�U�[���B
	const std::string& upas, // �p�X���[�h�B
	const std::string& cnam  // �L�������B
) {
	int cid = parse_id(cnam);
	if (cid != INT_MIN) {
		sql_session::open([&uid, &upas, &cnam, &cid] (sql_session* ses) {
			if (cid) {
				ses->execute(
					"SELECT c.`", construct<sql_column>("char_id", cid), "` "
					"FROM"
					" `login` AS l,"
					" `char` AS c "
					"WHERE"
					" l.`userid` = "   , construct<sql_param>(uid.c_str() ), " AND"
					" l.`user_pass` = ", construct<sql_param>(upas.c_str()), " AND"
					" l.`account_id` = c.`account_id` AND"
					" c.`char_id` = "  , construct<sql_param>(cid         ), " "
					"LIMIT 1"
				);
			} else {
				ses->execute(
					"SELECT c.`", construct<sql_column>("char_id", cid), "` "
					"FROM"
					" `login` AS l,"
					" `char` AS c "
					"WHERE"
					" l.`userid` = "   , construct<sql_param>(uid.c_str() ), " AND"
					" l.`user_pass` = ", construct<sql_param>(upas.c_str()), " AND"
					" l.`account_id` = c.`account_id` AND"
					" c.`name` = "     , construct<sql_param>(cnam.c_str()), " "
					"LIMIT 1"
				);
			}
			if (!ses->next_row()) cid = 0;
		});
	} else cid = 0;
	return cid;
}

// DB�Ƀ��O�C���f�[�^���Ɖ��B
void query_login_data(
	int cid, // �L�����N�^�[ID�B
	std::function<void(
		int,        // �A�J�E���gID�B
		int,        // ���ʁB
		int,        // �O���[�vID�B
		int,        // ��~�������ԁB
		int,        // ��ԁB
		std::string // ���O�B
	)> yie   // �l���֐��B
) {
	sql_session::open([cid, yie] (sql_session* ses) {
		int aid;
		char sex_str[2];
		int gid;
		int unb_tim;
		int sta;
		char nam[24];
		ses->execute(
			"SELECT"
			" l.`", construct<sql_column>("account_id", aid    ), "`,"
			" l.`", construct<sql_column>("sex"       , sex_str), "`,"
			" l.`", construct<sql_column>("group_id"  , gid    ), "`,"
			" l.`", construct<sql_column>("unban_time", unb_tim), "`,"
			" l.`", construct<sql_column>("state"     , sta    ), "`,"
			" c.`", construct<sql_column>("name"      , nam    ), "` "
			"FROM"
			" `login` AS l,"
			" `char` AS c "
			"WHERE"
			" l.`account_id` = c.`account_id` AND"
			" c.`char_id` = ", construct<sql_param>(cid), " "
			"LIMIT 1"
		);
		if (!ses->next_row()) RAISE_RUNTIME_ERROR("Cann't found login data.");
		yie(aid, sex_string2number(sex_str), gid, unb_tim, sta, nam);
	});
}

// �`�[����ۑ�����B
void save_team(
	block_if* lea, // ���[�_�[�B
	int tea_num    // �`�[���̔ԍ��B
) {
	auto tea = initialize<team_t>(tea_num);
	for (block_if* mem : lea->members())
		tea->members.push_back(initialize<team_member>(mem->char_id(), mem->name()));
	lea->teams()->register_(tea_num, tea);
}

// ���ʂ̕�����𐔒l�ɕϊ�����B
int // �ϊ��������l�B
sex_string2number(
	const std::string& str // ������B
) {
	int num = SEX_MALE;
	if      (str == "M") num = SEX_MALE;
	else if (str == "F") num = SEX_FEMALE;
	else if (str == "S") num = SEX_SERVER;
	else if (str == "U") num = SEX_ACCOUNT;
	return num;
}

// �R���\�[���ɃG���[��\������B
void show_error(
	const std::string& mes // ���b�Z�[�W�B
) {
	ShowError((mes + "\n").c_str());
}

// �R���\�[���ɏ���\������B
void show_info(
	const std::string& mes // ���b�Z�[�W�B
) {
	ShowInfo((mes + "\n").c_str());
}

// �X�L�����C�A�E�g�ɂ���ău���b�N���ӂ邢���Ƃ��q������B
block_pred // ������q��B
sift_block_layout(
	block_if* sk_use,  // �X�L���g�p�ҁB
	block_if* sk_tar,  // �X�L���^�[�Q�b�g�B
	e_skill kid,       // �X�L��ID�B
	int klv,           // �X�L�����x���B
	block_pred inn_pre // �����̏q��B
) {
	s_skill_unit_layout* lay = skill_get_unit_layout(kid, klv, sk_use->bl(), sk_tar->bl()->x, sk_tar->bl()->y);
	return [sk_use, sk_tar, kid, klv, inn_pre, lay] (block_if* blo) -> bool {
		for (int i = 0; i < lay->count; ++i) {
			int x = sk_tar->bl()->x + lay->dx[i];
			int y = sk_tar->bl()->y + lay->dy[i];
			if (check_distance_blxy(blo->bl(), x, y, skill_get_unit_range(kid, klv))) return inn_pre(blo);
		}
		return false;
	};
}

// �X�L���p�X�ɂ���ău���b�N���ӂ邢���Ƃ��q������B
block_pred // ������q��B
sift_block_path(
	block_if* sk_use,  // �X�L���g�p�ҁB
	block_if* sk_tar,  // �X�L���^�[�Q�b�g�B
	e_skill kid,       // �X�L��ID�B
	int klv,           // �X�L�����x���B
	block_pred inn_pre // �����̏q��B
) {
	auto ids = initialize<std::unordered_set<int>>();
	yield_bl_func add_id = [ids] (block_list* bl) -> int {
		ids->insert(bl->id);
		return 1;
	};
	if (battle_config.skill_eightpath_algorithm) {
		map_foreachindir(
			callback_yield_bl,
			sk_use->bl()->m,
			sk_use->bl()->x,
			sk_use->bl()->y,
			sk_tar->bl()->x,
			sk_tar->bl()->y,
			skill_get_splash(kid, klv),
			skill_get_maxcount(kid, klv),
			0,
			BL_CHAR,
			&add_id
		);
	} else
		map_foreachinpath(
			callback_yield_bl,
			sk_use->bl()->m,
			sk_use->bl()->x,
			sk_use->bl()->y,
			sk_tar->bl()->x,
			sk_tar->bl()->y,
			skill_get_splash(kid, klv),
			skill_get_maxcount(kid, klv),
			0,
			BL_CHAR,
			&add_id
		);
	if (ids->empty()) ids->insert(sk_tar->bl()->id);
	return [inn_pre, ids] (block_if* blo) -> bool {
		return KEY_EXISTS(*ids, blo->bl()->id) &&
			inn_pre(blo);
	};
}

// �X�L���X�v���b�V���ɂ���ău���b�N���ӂ邢���Ƃ��q������B
block_pred // ������q��B
sift_block_splash(
	block_if* sk_tar,  // �X�L���^�[�Q�b�g�B
	e_skill kid,       // �X�L��ID�B
	int klv,           // �X�L�����x���B
	block_pred inn_pre // �����̏q��B
) {
	return [sk_tar, kid, klv, inn_pre] (block_if* blo) -> bool	{
		return check_distance_bl(sk_tar->bl(), blo->bl(), skill_get_splash(kid, klv)) &&
			inn_pre(blo);
	};
}

// �u���b�N���X�g�̑����ɃX�L�����j�b�g�����邩�𔻒肷��B
bool // ���ʁB
skill_unit_exists_bl(
	block_list* bl,                // �u���b�N���X�g�B
	const skill_unit_key_map& keys // �X�L�����j�b�g�L�[�̃}�b�v�B
) {
	return skill_unit_exists_xy(bl->m, bl->x, bl->y, keys);
}

// �u���b�N�̑����ɃX�L�����j�b�g�����邩�𔻒肷��B
bool // ���ʁB
skill_unit_exists_block(
	block_if* blo,                 // �u���b�N�B
	const skill_unit_key_map& keys // �X�L�����j�b�g�L�[�̃}�b�v�B
) {
	return skill_unit_exists_bl(blo->bl(), keys);
}

// ���W�ɃX�L�����j�b�g�����邩�𔻒肷��B
bool // ���ʁB
skill_unit_exists_xy(
	int m,                         // �}�b�vID�B
	int x,                         // X���W�B
	int y,                         // Y���W�B
	const skill_unit_key_map& keys // �X�L�����j�b�g�L�[�̃}�b�v�B
) {
	return iterate_skill_unit(m, x, y, [keys] (skill_unit* kun, block_list* src_bl) -> int {
		skill_unit_key key = find_map_data(keys, e_skill(kun->group->skill_id));
		return kun->group->skill_id == key.skill_id &&
			(!key.src_type ||
				src_bl->type & key.src_type
			) && kun->group->skill_lv >= key.min_skill_lv;
	});
}

// �z�����N���X�̑f��Agi���擾����B
int // �擾����Agi�B
status_get_base_agi(
	homun_data* hd // �z�����N���X�f�[�^�B
) {
	return hd->homunculus.agi / 10;
}

// �z�����N���X�̑f��Dex���擾����B
int // �擾����Dex�B
status_get_base_dex(
	homun_data* hd // �z�����N���X�f�[�^�B
) {
	return hd->homunculus.dex / 10;
}

// �z�����N���X�̑f��Int���擾����B
int // �擾����Int�B
status_get_base_int(
	homun_data* hd // �z�����N���X�f�[�^�B
) {
	return hd->homunculus.int_ / 10;
}

// �z�����N���X�̑f��Luk���擾����B
int // �擾����Luk�B
status_get_base_luk(
	homun_data* hd // �z�����N���X�f�[�^�B
) {
	return hd->homunculus.luk / 10;
}

// �z�����N���X�̑f��Str���擾����B
int // �擾����Str�B
status_get_base_str(
	homun_data* hd // �z�����N���X�f�[�^�B
) {
	return hd->homunculus.str / 10;
}

// �z�����N���X�̑f��Vit���擾����B
int // �擾����Vit�B
status_get_base_vit(
	homun_data* hd // �z�����N���X�f�[�^�B
) {
	return hd->homunculus.vit / 10;
}

// PC�̑f��Agi���擾����B
int // �擾����Agi�B
status_get_base_agi(
	map_session_data* sd // �Z�b�V�����f�[�^�B
) {
	return sd->status.agi;
}

// PC�̑f��Dex���擾����B
int // �擾����Dex�B
status_get_base_dex(
	map_session_data* sd // �Z�b�V�����f�[�^�B
) {
	return sd->status.dex;
}

// PC�̑f��Int���擾����B
int // �擾����Int�B
status_get_base_int(
	map_session_data* sd // �Z�b�V�����f�[�^�B
) {
	return sd->status.int_;
}

// PC�̑f��Luk���擾����B
int // �擾����Luk�B
status_get_base_luk(
	map_session_data* sd // �Z�b�V�����f�[�^�B
) {
	return sd->status.luk;
}

// PC�̑f��Str���擾����B
int // �擾����Str�B
status_get_base_str(
	map_session_data* sd // �Z�b�V�����f�[�^�B
) {
	return sd->status.str;
}

// PC�̑f��Vit���擾����B
int // �擾����Vit�B
status_get_base_vit(
	map_session_data* sd // �Z�b�V�����f�[�^�B
) {
	return sd->status.vit;
}

// ������𐮐��ɕϊ�����B
int // �ϊ����������B
stoi(
	const std::string& str, // ������B
	int def,                // �f�t�H���g�l�B
	int bas                 // ��B
) {
	int res = def;
    try {
	    std::string::size_type pos;
        int num = std::stoi(str, &pos, bas);
        if (pos == str.length()) res = num;
    } catch (...) {}
    return res;
}

// ��������g���~���O����B
std::string // �g���~���O����������B
trim(
	const std::string& str,     // ������B
	const std::string& pad_lets // �]�v�ȕ����̕�����B
) {
	int fir = str.length(), las = 0;
	for (int i = 0; i < str.length(); ++i) {
		uint8_t let = str[i];
		bool jlea = letter_is_jlead(let);
		bool pad;
		if (!jlea) pad = pad_lets.find(let) != std::string::npos;
		if ((jlea ||
				!pad
			) && fir > i
		) fir = i;
		if (jlea) las = ++i;
		else if (!pad) las = i;
	}
	if (fir > las) return "";
	return str.substr(fir, las - fir + 1);
}

// �t�B�[�o�[�Ɋւ�������X�V����B
void update_fever() {
	sql_session::open([] (sql_session* ses) {
		int fev_rat = 2;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("value", fev_rat), "` "
			"FROM `global_acc_reg_num` "
			"WHERE"
			" `account_id` = ", construct<sql_param>(1                     ), " AND"
			" `key` = "       , construct<sql_param>(FEVER_RATE_KEY.c_str()), " AND"
			" `index` = "     , construct<sql_param>(0                     )
		);
		ses->next_row();
		int dou_fev_rat = fev_rat * 2;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("value", dou_fev_rat), "` "
			"FROM `global_acc_reg_num` "
			"WHERE"
			" `account_id` = ", construct<sql_param>(1                     ), " AND"
			" `key` = "       , construct<sql_param>(FEVER_RATE_KEY.c_str()), " AND"
			" `index` = "     , construct<sql_param>(1                     )
		);
		ses->next_row();
		int nat_typ;
		int map_typ;
		int siz;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("nation_type", nat_typ), "`,"
			" `", construct<sql_column>("map_type"   , map_typ), "`,"
			" `", construct<sql_column>("size"       , siz    ), "` "
			"FROM `pybot_fever_size`"
		);
		std::vector<fever_size> sizs;
		while (ses->next_row())
			sizs.push_back(fever_size{nation_types(nat_typ), map_types(map_typ), siz});
		std::vector<int> fev_ids;
		for (const fever_size& siz : sizs) {
			int typ = siz.nation_type * 100 + siz.map_type;
			auto& maps = type_maps[typ];
			for (int i = 0; i < siz.size; ++i) {
				if (i >= maps.size()) break;
				for (;;) {
					auto map = maps[rnd() % maps.size()];
					if (map->fever_flag &&
						!KEY_EXISTS(fever_rates, map->id)
					) {
						fever_rates[map->id] = fev_rat;
						fev_ids.push_back(map->id);
						break;
					}
				}
			}
		}
		if (!fever_rates.empty()) fever_rates[fev_ids[rnd() % fev_ids.size()]] = dou_fev_rat;
		ses->execute("TRUNCATE `pybot_fever_rate`");
		for (auto& fev_rat_val : fever_rates) {
			int id = fev_rat_val.first;
			int rat = fev_rat_val.second;
			auto map = id_maps.at(id);
			ses->execute(
				"INSERT INTO `pybot_fever_rate` "
				"VALUES "
				"(", construct<sql_param>(map->name_english.c_str()), ","
				" ", construct<sql_param>(rat                      ), ")"
			);
		}
	});
}

// ���ӂɕǂ����݂��邩�𒲂ׂ�B
bool // ���ʁB
wall_exists(
	block_list* cen, // ���S�B
	int rad          // ���a�B
) {
	map_data* md = map_getmapdata(cen->m);
	int x0 = cen->x - rad;
	int x1 = cen->x + rad;
	int y0 = cen->y - rad;
	int y1 = cen->y + rad;
	for (int y = y0; y <= y1; y++) {
		for (int x = x0; x <= x1; x++) {
			if (map_getcellp(md, x, y, CELL_CHKNOPASS)) return true;
		}
	}
	return false;
}

}
