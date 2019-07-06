// [GonBee]
// �p�[�e�B�[Bot�@�\�̃R�}���h�p�֐����`����B

#include "pybot_internal.hpp"

namespace pybot {

// -----------------------------------------------------------------------------
// �R�}���h�p�̊֐��̒�`

// Bot���Ǘ�����B
int // �����Ȃ�0�A���s�Ȃ�-1�B
command_bot(
	const int fd,         // �\�P�b�g�̋L�q�q�B
	map_session_data* sd, // �Z�b�V�����f�[�^�B
	const char* mes       // ���b�Z�[�W�B
) {
	try {
		command_argument_list args;
		command_parse_arguments(mes, pybot::back_inserter(args));
		if (args.empty()) show_bot_subcommands(fd);
		else {
			std::string sc_nam = shift_arguments(args);
			std::string sc_nam_lc = lowercase(sc_nam);
			auto sc_pro = pybot::find_if(ALL_RANGE(BOT_SUBCMD_PROCS),
				[&sc_nam_lc] (const ptr<subcommand_proc>& sc_pro) -> bool {
					return lowercase(sc_pro->sc_full_name) == sc_nam_lc ||
						lowercase(sc_pro->sc_abr_name) == sc_nam_lc;
				}
			);
			if (!sc_pro)
				throw command_error{print(
					"�u", sc_nam, "�v�Ƃ����T�u�R�}���h�͂���܂���B"
				)};
			auto lea = find_map_data(all_leaders, sd->status.char_id);
			if (!lea) {
				lea = construct<leader_t>(sd);
				all_leaders[lea->char_id()] = lea;
			}
			now = gettick();
			sc_pro->func(lea.get(), args);
		}
	} catch (const command_error& err) {
		show_client(fd, err.what);
		return -1;
	} catch (const std::runtime_error& err) {
		show_client(fd, "�\�����Ԉ���Ă��܂��B");
		show_error(err.what());
		return -1;
	} catch (...) {
		show_client(fd, UNEXPECTED_ERROR);
		show_error(UNEXPECTED_ERROR);
		return -1;
	}
	return 0;
}

// �����X�^�[���U������B
SUBCMD_FUNC(Bot, Attack) {
	int mid = 0;
	std::string mob_str;
	if (!args.empty()) {
		std::string mob_nam = shift_arguments(args);
		mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		mob_str = print_mobdb(mid);
		if (mid < MM_INDIVIDUAL ||
			mid >= MM_CAUTION
		) throw command_error{print("�u", mob_str, "�v�͎w��ł��܂���B")};
	}
	mob_data* md = find_mob(lea, mid);
	if (md) {
		lea->attack_target() = md->bl.id;
		if (!mid) mob_str = print_mobdb(md->mob_id);
		show_client(lea->fd(), print("�u", mob_str, "�v���U�����܂��B"));
	} else if (mid) {
		throw command_error{print(
			"���ӂɁu", mob_str, "�v��������܂���ł����B"
		)};
	}
	else throw command_error{"���ӂɃ����X�^�[��������܂���ł����B"};
}

// �����o�[�̃J�[�g���A�C�e�����ꗗ�\������B
SUBCMD_FUNC(Bot, Cart) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (!mem->is_carton())
		throw command_error{print(
			"�u", mem->name(), "�v�̓J�[�g�����L���Ă��܂���B"
		)};
	show_client(lea->fd(), print_storage(mem, TABLE_CART));
}

// �����o�[�̃J�[�g������[�A�C�e�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, CartAutoGet) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (!mem->is_carton())
		throw command_error{print(
			"�u", mem->name(), "�v�̓J�[�g�����L���Ă��܂���B"
		)};
	if (args.empty()) {
		std::vector<int> nids;
		mem->cart_auto_get_items()->copy(pybot::back_inserter(nids));
		std::sort(ALL_RANGE(nids));
		std::stringstream out;
		out << "------ �u" << mem->name() << "�v�̃J�[�g������[�A�C�e�� ------\n";
		for (int nid : nids) {
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << "\n";
		}
		out << nids.size() << "���̃A�C�e����������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		std::string idb_str = print_itemdb(nid);
		item_data* idb = itemdb_exists(actual_nameid(nid));
		if (!itemdb_isstackable2(idb))
			throw command_error{print(
				"�u", idb_str, "�v�̓X�^�b�N�ł��܂���B"
			)};
		if (mem->cart_auto_get_items()->find(nid)) {
			mem->cart_auto_get_items()->unregister(nid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v��"
				"�J�[�g���玩���I�Ɏ��o���܂���B"
			));
			if (mem != lea) clif_emotion(mem->bl(), ET_OK);
		} else {
			mem->cart_auto_get_items()->register_(nid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v��"
				"�J�[�g���玩���I�Ɏ��o���܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̃J�[�g������[�A�C�e�����N���A����B
SUBCMD_FUNC(Bot, CartAutoGetClear) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (!mem->is_carton())
		throw command_error{print(
			"�u", mem->name(), "�v�̓J�[�g�����L���Ă��܂���B"
		)};
	int cou = mem->cart_auto_get_items()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�� ",
		cou, "���̃J�[�g������[�A�C�e���̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̃J�[�g������[�A�C�e����]������B
SUBCMD_FUNC(Bot, CartAutoGetTransport) {
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	if (!mem1->is_carton())
		throw command_error{print(
			"�u", mem1->name(), "�v�̓J�[�g�����L���Ă��܂���B"
		)};
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (!mem2->is_carton())
		throw command_error{print(
			"�u", mem2->name(), "�v�̓J�[�g�����L���Ă��܂���B"
		)};
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->cart_auto_get_items()->import_(mem1->cart_auto_get_items().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v�� ",
		cou, "���̃J�[�g������[�A�C�e����]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[���A�C�e�����J�[�g������o���B
SUBCMD_FUNC(Bot, CartGet) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (!mem->is_carton())
		throw command_error{print(
			"�u", mem->name(), "�v�̓J�[�g�����L���Ă��܂���B"
		)};
	std::string itm_nam = shift_arguments(args,
		"�A�C�e�����w�肵�Ă��������B"
	);
	int itm_ind = mem->find_cart(itm_nam);
	if (itm_ind == INT_MIN)
		throw command_error{print(
			"�u", mem->name(), "�v�̃J�[�g�Ɂu", itm_nam, "�v������܂���B"
		)};
	item* itm = &mem->sd()->cart.u.items_cart[itm_ind];
	int amo = itm->amount;
	if (!args.empty()) amo = shift_arguments_then_parse_int(
		args, "���̃A�C�e���̌�", 1, amo
	);
	std::string itm_str = print_item(itm, itemdb_exists(itm->nameid), amo);
	int old_amo = itm->amount;
	pc_getitemfromcart(mem->sd(), itm_ind, amo);
	if (itm->amount == old_amo)
		throw command_error{print(
			"�u", mem->name(), "�v�́u", itm_str, "�v��"
			"�J�[�g������o���܂���B"
		)};
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�́u", itm_str, "�v��"
		"�J�[�g������o���܂����B"
	));
	clif_emotion(mem->bl(), ET_OK);
}

// �����o�[���A�C�e�����J�[�g�ɓ����B
SUBCMD_FUNC(Bot, CartPut) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (!mem->is_carton())
		throw command_error{print(
			"�u", mem->name(), "�v�̓J�[�g�����L���Ă��܂���B"
		)};
	std::string itm_nam = shift_arguments(
		args, "�A�C�e�����w�肵�Ă��������B"
	);
	int itm_ind = mem->find_inventory(itm_nam);
	if (itm_ind == INT_MIN)
		throw command_error{print(
			"�u", mem->name(), "�v�́u", itm_nam, "�v���������Ă��܂���B"
		)};
	item* itm = &mem->sd()->inventory.u.items_inventory[itm_ind];
	if (itm->equip)
		throw command_error{print(
			"�u", mem->name(), "�v�́u", itm_nam, "�v�𑕔����Ă��܂��B"
		)};
	int amo = itm->amount;
	if (!args.empty()) amo = shift_arguments_then_parse_int(
		args, "���̃A�C�e���̌�", 1, amo
	);
	std::string itm_str = print_item(itm, mem->sd()->inventory_data[itm_ind], amo);
	int old_amo = itm->amount;
	pc_putitemtocart(mem->sd(), itm_ind, amo);
	if (itm->amount == old_amo)
		throw command_error{print(
			"�u", mem->name(), "�v�́u", itm_str, "�v���J�[�g�ɓ�����܂���B"
		)};
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�́u", itm_str, "�v���J�[�g�ɓ���܂����B"
	));
	clif_emotion(mem->bl(), ET_OK);
}

// �����o�[������𑕔��A�܂��͑�������������B
SUBCMD_FUNC(Bot, Equip) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		int cou = 0;
		for (int i = 0; i < EQI_MAX; ++i) {
			int equ_ind = mem->sd()->equip_index[EQI_MAX - i - 1];
			if (equ_ind >= 0 &&
				pc_unequipitem(mem->sd(), equ_ind, 1)
			) cou++;
		}
		if (mem != lea) {
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v��", cou, "�̕���̑������������܂����B"
			));
			clif_emotion(mem->bl(), ET_SCRATCH);
		}
	} else {
		std::string itm_nam = shift_arguments(args);
		int itm_ind = mem->find_inventory(itm_nam);
		if (itm_ind == INT_MIN)
			throw command_error{print(
				"�u", mem->name(), "�v�́u", itm_nam, "�v���������Ă��܂���B"
			)};
		item* itm = &mem->sd()->inventory.u.items_inventory[itm_ind];
		item_data* idb = mem->sd()->inventory_data[itm_ind];
		std::string itm_str = print_item(itm, idb);
		if (itm->equip) {
			if (!pc_unequipitem(mem->sd(), itm_ind, 1))
				throw command_error{print(
					"�u", mem->name(), "�v�́u", itm_str, "�v�̑����������ł��܂���B"
				)};
			if (mem != lea) {
				show_client(lea->fd(), print(
					"�u", mem->name(), "�v�́u", itm_str, "�v�̑������������܂����B"
				));
				clif_emotion(mem->bl(), ET_SCRATCH);
			}
		} else {
			if (pc_isequip(mem->sd(), itm_ind) ||
				!pc_equipitem(mem->sd(), itm_ind, idb->equip)
			) throw command_error{print(
				"�u", mem->name(), "�v�́u", itm_str, "�v�𑕔��ł��܂���B"
			)};
			if (mem != lea) {
				show_client(lea->fd(), print(
					"�u", mem->name(), "�v�́u", itm_str, "�v�𑕔����܂����B"
				));
				clif_emotion(mem->bl(), ET_HNG);
			}
		}
	}
}

// ���ׂĂ̖��Ӓ�̕�����Ӓ肷��B
SUBCMD_FUNC(Bot, EquipIdentifyAll) {
	std::stringstream out;
	int tot_cou = 0;
	auto ide_itm = [&out, &tot_cou] (
		block_if* mem,
		storage_context* inv_con,
		storage_context* car_con,
		storage_type sto_typ,
		int ind,
		int ind_wid,
		item* itm,
		item_data* idb = nullptr
	) -> bool {
		bool res = false;
		if (itm->nameid &&
			!itm->identify
		) {
			mem->identify_equip(itm, inv_con, car_con);
			if (itm->identify) {
				++tot_cou;
				res = true;
			}
			if (!idb) idb = itemdb_exists(itm->nameid);
			out << INDEX_PREFIX << mem->member_index() << " " <<
				ID_PREFIX << mem->char_id() << " - " <<
				mem->name() << " : " <<
				STORAGE_TYPE_NAME_TABLE[sto_typ - 1] << " " <<
				INDEX_PREFIX << print(std::setw(ind_wid), std::setfill('0'), ind) << " " << 
				ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
				print_item(itm, idb);
			if (!itm->identify) out << " ���g�勾�s��";
			out << "\n";
		}
		return res;
	};
	out << "------ �Ӓ肵������ ------\n";
	for (block_if* mem : lea->members()) {
		auto inv_con = construct<inventory_context>(mem->sd());
		ptr<cart_context> car_con;
		if (mem->is_carton()) car_con = construct<cart_context>(mem->sd());
		bool done = false;
		int ind_wid = print(MAX_INVENTORY - 1).length();
		for (int i = 0; i < MAX_INVENTORY; ++i) {
			item* itm = &mem->sd()->inventory.u.items_inventory[i];
			item_data* idb = mem->sd()->inventory_data[i];
			done |= ide_itm(mem, inv_con.get(), car_con.get(), TABLE_INVENTORY, i, ind_wid, itm, idb);
		}
		if (mem->is_carton()) {
			ind_wid = print(MAX_CART - 1).length();
			for (int i = 0; i < MAX_CART; ++i) {
				item* itm = &mem->sd()->cart.u.items_cart[i];
				done |= ide_itm(mem, inv_con.get(), car_con.get(), TABLE_CART, i, ind_wid, itm);
			}
		}
		if (done) {
			clif_emotion(mem->bl(), ET_SPARK);
			if (mem == lea) {
				clif_inventorylist(lea->sd());
				if (lea->is_carton()) {
					clif_clearcart(lea->fd());
					clif_cartlist(lea->sd());
				}
			}
		}
	}
	out << "���v" << tot_cou << "�̕�����Ӓ肵�܂����B\n";
	show_client(lea->fd(), out.str());
}

// ���ׂĂ̔j��������C������B
SUBCMD_FUNC(Bot, EquipRepairAll) {
	if (!npc_exists(
		lea->bl(),
		battle_config.pybot_around_distance,
		NPCTYPE_SCRIPT,
		REPAIRMAN_NAME
	)) throw command_error{print(
		"���ӂ�", REPAIRMAN_NAME, "NPC��������܂���B"
	)};
	std::stringstream out;
	int tot_cou = 0;
	int tot_zen = 0;
	out << "------ �C���������� ------\n";
	int ind_wid = print(MAX_INVENTORY - 1).length();
	for (block_if* mem : lea->members()) {
		bool done = false;
		for (int i = 0; i < MAX_INVENTORY; ++i) {
			item* itm = &mem->sd()->inventory.u.items_inventory[i];
			if (itm->nameid &&
				itm->attribute == 1
			) {
				bool suc = mem->sd()->status.zeny >= REPAIR_COST;
				if (suc) {
					pc_payzeny(mem->sd(), REPAIR_COST, LOG_TYPE_NPC, NULL);
					itm->attribute = 0;
					clif_produceeffect(mem->sd(), 0, itm->nameid);
					done = true;
					++tot_cou;
					tot_zen += REPAIR_COST;
				}
				item_data* idb = mem->sd()->inventory_data[i];
				out << INDEX_PREFIX << mem->member_index() << " " <<
					ID_PREFIX << mem->char_id() << " - " <<
					mem->name() << " : " <<
					INDEX_PREFIX << print(std::setw(ind_wid), std::setfill('0'), i) << " " <<
					ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
					print_item(itm, idb);
				if (!suc) out << " �������s��";
				out << "\n";
			}
		}
		if (done) {
			clif_misceffect(mem->bl(), 3);
			clif_equiplist(mem->sd());
		}
	}
	out << "���v" << tot_cou << "�̕����" << print_zeny(tot_zen) << "Zeny�ŏC�����܂����B\n";
	show_client(lea->fd(), out.str());
}

// �����o�[�̕���ꎮ���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, EquipSet) {
	using es_val_t = std::pair<int,equipset_t*>;
	auto pri_equ_poss = [] (std::vector<ptr<equipset_item>>* itms) -> std::string {
		std::vector<std::string> toks;
		for (auto itm : *itms) toks.push_back(print_equip_pos(itm->equip));
		return concatinate_strings(ALL_RANGE(toks), "+");
	};

	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<es_val_t> es_vals;
		mem->equipsets()->copy(pybot::back_inserter(es_vals));
		std::sort(ALL_RANGE(es_vals), [lea] (es_val_t lval, es_val_t rval) -> bool {
			int lxmid = lval.first;
			int rxmid = rval.first;
			equipset_t* les = lval.second;
			equipset_t* res = rval.second;
			bool lcau = lxmid >= MM_CAUTION;
			bool rcau = rxmid >= MM_CAUTION;
			if (lcau != rcau) return lcau;
			bool lind = lxmid >= MM_INDIVIDUAL;
			bool rind = rxmid >= MM_INDIVIDUAL;
			if (lind != rind) return lind;
			if (lind) {
				bool lgre = lea->great_mobs()->find(les->mob_id);
				bool rgre = lea->great_mobs()->find(res->mob_id);
				if (lgre != rgre) return lgre;
				bool lsum = KEY_EXISTS(skill_mobs::instance->summon, les->mob_id);
				bool rsum = KEY_EXISTS(skill_mobs::instance->summon, res->mob_id);
				if (lsum != rsum) return lsum;
				bool llra = les->mdb->status.rhw.range > 3;
				bool rlra = res->mdb->status.rhw.range > 3;
				if (llra != rlra) return rlra;
				if (les->mdb->lv != res->mdb->lv) return les->mdb->lv > res->mdb->lv;
			}
			return lxmid > rxmid;
		});
		std::stringstream out;
		out << "------ �u" <<	mem->name() << "�v�̕���ꎮ ------\n";
		for (es_val_t es_val : es_vals) {
			int mid = es_val.first;
			equipset_t* es = es_val.second;
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				print_mobdb(mid) << " " <<
				es->items.size() << "��"
				"@" << pri_equ_poss(&es->items) << "\n";
		}
		out << es_vals.size() << "���̕���ꎮ��������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string mob_nam = shift_arguments(args);
		int mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		std::string mob_str = print_mobdb(mid);
		int equ = 0;
		auto es = construct<equipset_t>(mid);
		for (int i = 0; i < EPO_MAX; ++i) {
			if (i >= EPO_COSTUME_HEAD_TOP &&
				i <= EPO_COSTUME_GARMENT
			) continue;
			int equ_ind = mem->sd()->equip_index[EPO2EQI_TABLE[i]];
			if (equ_ind < 0) continue;
			item* itm = &mem->sd()->inventory.u.items_inventory[equ_ind];
			if (itm->equip & equ) continue;
			auto esi = initialize<equipset_item>();
			esi->order = equip_pos_orders(i);
			esi->equip = equip_pos(itm->equip);
			esi->key = construct<item_key>(itm->nameid, itm->card);
			es->items.push_back(esi);
			equ |= esi->equip;
		}
		if (es->items.empty()) {
			equipset_t* old_es = mem->equipsets()->find(mid);
			if (!old_es)
				throw command_error{print(
					"�u", mem->name(), "�v�́u", mob_str, "�v�p����ꎮ�͂���܂���B"
				)};
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v�p����ꎮ�̓o�^�𖕏����܂����B"
			));
			mem->equipsets()->unregister(mid);
		} else {
			mem->equipsets()->register_(mid, es);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v�p����ꎮ�Ƃ��āu",
				es->items.size(), "��@", pri_equ_poss(&es->items), "�v�̕����o�^���܂����B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̕���ꎮ���N���A����B
SUBCMD_FUNC(Bot, EquipSetClear) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->equipsets()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou, "���̕���ꎮ�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̕���ꎮ�����[�h����B
SUBCMD_FUNC(Bot, EquipSetLoad) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	std::string mob_nam = shift_arguments(
		args, "�����X�^�[���w�肵�Ă��������B"
	);
	int mid = find_mobdb(mob_nam);
	if (!mid)
		throw command_error{print(
			"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
		)};
	std::string mob_str = print_mobdb(mid);
	equipset_t* es = mem->equipsets()->find(mid);
	if (!es)
		throw command_error{print(
			"�u", mem->name(), "�v�́u", mob_str, "�v�p����ꎮ�͂���܂���B"
		)};
	mem->load_equipset(mid);
	std::stringstream out;
	out << "------ �u" <<	mem->name() << "�v�����[�h�����u" <<
		mob_str << "�v�p����ꎮ ------\n";
	int cou = 0;
	unsigned int equ = 0;
	for (int i = 0; i < EPO2EQI_TABLE.size(); ++i) {
		equip_index equ_ind = EPO2EQI_TABLE[i];
		ptr<equipset_item> esi;
		for (auto esi2 : es->items) {
			if (esi2->equip & equip_bitmask[equ_ind]) {
				esi = esi2;
				break;
			}
		}
		if (esi &&
			!(esi->equip & equ)
		) {
			equ |= (unsigned int)(esi->equip);
			int inv_ind = mem->sd()->equip_index[equ_ind];
			if (inv_ind >= 0) ++cou;
			out << ID_PREFIX << esi->key->idb->nameid << " - " <<
				print_item_key(*esi->key) << " "
				"(" << print_equip_type(esi->key->idb);
			if (inv_ind >= 0) out << "@" << print_equip_pos(esi->equip);
			out << ")";
			if (inv_ind < 0) out << " ���������s";
			out << "\n";
		}
	}
	out << cou << "�̕���𑕔����܂����B";
	show_client(lea->fd(), out.str());
	if (mem != lea) clif_emotion(mem->bl(), ET_HNG);
}

// �����o�[�̕���ꎮ��]������B
SUBCMD_FUNC(Bot, EquipSetTransport) {
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->equipsets()->import_(mem1->equipsets().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̕���ꎮ��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �T�u�R�}���h�̐�����\������B
SUBCMD_FUNC(Bot, Help) {
	std::string sc_nam = shift_arguments(
		args, "�T�u�R�}���h���w�肵�Ă��������B"
	);
	std::string sc_nam_lc = lowercase(sc_nam);
	auto sc_des = pybot::find_if(ALL_RANGE(BOT_SUBCMD_DESCS),
		[&sc_nam_lc] (const ptr<subcommand_desc>& sc_des) -> bool {
			return lowercase(sc_des->sc_full_name) == sc_nam_lc ||
				lowercase(sc_des->sc_abr_name) == sc_nam_lc;
		}
	);
	if (!sc_des)
		throw command_error{print(
			"�u", sc_nam, "�v�Ƃ����T�u�R�}���h�͂���܂���B"
		)};
	show_client(lea->fd(), sc_des->sc_desc);
}

// �z�����N���X�̃X�L�����ꗗ�\���A�܂��͎g���B
SUBCMD_FUNC(Bot, HomunsKill) {
	block_if* hom = get_active_homun(shift_arguments_then_find_member(lea, args));
	if (args.empty()) skill_user_show_skills(lea->fd(), hom);
	else skill_user_use_skill(lea, args, hom);
}

// �z�����N���X�̃A�N�e�B�u�X�L���𐧌�����B
SUBCMD_FUNC(Bot, HomunsKillLimit) {
	skill_user_limit_skill(lea, args, get_active_homun(shift_arguments_then_find_member(lea, args)));
}

// �z�����N���X�̃X�L�����x�����グ��B
SUBCMD_FUNC(Bot, HomunsKillUp) {
	skill_user_skill_up(lea, args, get_active_homun(shift_arguments_then_find_member(lea, args)));
}

// �z�����N���X�̃X�e�[�^�X��\������B
SUBCMD_FUNC(Bot, HomunStatus) {
	block_if* hom = get_active_homun(shift_arguments_then_find_member(lea, args));
	std::stringstream out;
	out << "------ �u" << hom->name() << "�v�̃X�e�[�^�X ------\n";
	out << "��� <"  << hom->hd()->homunculusDB->name << "> "
		"���x�� " << hom->hd()->homunculus.level   << " ";
	if (hom->hd()->homunculus.level < battle_config.hom_max_level)
		out << "(" << hom->hd()->homunculus.exp << "/" << hom->hd()->exp_next << " " <<
			print(
				std::fixed,
				std::setprecision(1),
				hom->hd()->homunculus.exp * 100. / hom->hd()->exp_next
			) << "%) ";
	out << "�󕠓x " << hom->hd()->homunculus.hunger << "% �e���x " <<
		print(
			std::fixed,
			std::setprecision(2),
			hom->hd()->homunculus.intimacy / 100.
		) << "\n";
	out << print_main_status(hom->hd());
	out << print_sc(hom->sc()) << "\n";
	show_client(lea->fd(), out.str());
}

// �����o�[�̃C���x���g�����A�C�e�����ꗗ�\���A�܂��͎g���B
SUBCMD_FUNC(Bot, Item) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) show_client(lea->fd(), print_storage(mem, TABLE_INVENTORY));
	else {
		std::string itm_nam = shift_arguments(args);
		int itm_ind = mem->find_inventory(itm_nam);
		if (itm_ind == INT_MIN)
			throw command_error{print(
				"�u", mem->name(), "�v�́u", itm_nam, "�v���������Ă��܂���B"
			)};
		item* itm = &mem->sd()->inventory.u.items_inventory[itm_ind];
		std::string itm_str = print_item(itm, mem->sd()->inventory_data[itm_ind], 1);
		if (!pc_isUseitem(mem->sd(), itm_ind))
			throw command_error{print(
				"�u", mem->name(), "�v�́u", itm_str, "�v���g���܂���B"
			)};
		mem->use_item(itm_ind, false);
		show_client(lea->fd(), print(
			"�u", mem->name(), "�v�́u", itm_str, "�v���g���܂��B"
		));
	}
}

// ���ׂẴ����o�[�̃C���x���g���ƃJ�[�g�ɂ���X�^�b�N�\�ȃA�C�e���̌��̏W�v���ʂ�\������B
SUBCMD_FUNC(Bot, ItemCount) {
	bool all = args.empty();
	std::unordered_map<int,int> cous;
	while (!args.empty()) {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		std::string idb_str = print_itemdb(nid);
		item_data* idb = itemdb_exists(actual_nameid(nid));
		if (!itemdb_isstackable2(idb))
			throw command_error{print(
				"�u", idb_str, "�v�̓X�^�b�N�ł��܂���B"
			)};
		cous[nid] = 0;
	}
	auto yie_itm = [all, &cous](item* itm, item_data* idb = nullptr) {
		int nid = itm->nameid;
		if (nid) {
			if (!idb) idb = itemdb_exists(nid);
			if (itemdb_isstackable2(idb)) {
				if (itm->card[0] == CARD0_CREATE &&
					pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST)
				) nid += FAME_OFFSET;
				if (all ||
					KEY_EXISTS(cous, nid)
				) cous[nid] += itm->amount;
			}
		}
	};
	for (block_if* mem : lea->members()) {
		for (int i = 0; i < MAX_INVENTORY; ++i)
			yie_itm(&mem->sd()->inventory.u.items_inventory[i], mem->sd()->inventory_data[i]);
		if (mem->is_carton()) {
			for (int i = 0; i < MAX_CART; ++i)
				yie_itm(&mem->sd()->cart.u.items_cart[i]);
		}
	}
	std::vector<int> nids;
	for (const auto& cous_val : cous) nids.push_back(cous_val.first);
	std::sort(ALL_RANGE(nids));
	std::stringstream out;
	out << "------ �A�C�e���̏W�v���� ------\n";
	int tot_cou = 0;
	for (int nid : nids) {
		int cou = cous.at(nid);
		out << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
			print_itemdb(nid) << " " << cou << "��\n";
		tot_cou += cou;
	}
	out << "���v" << nids.size() << "���A" << tot_cou << "�̃A�C�e����������܂����B\n";
	show_client(lea->fd(), out.str());
}

// �����o�[���A�C�e�����h���b�v����B
SUBCMD_FUNC(Bot, ItemDrop) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	std::string itm_nam = shift_arguments(
		args, "�A�C�e�����w�肵�Ă��������B"
	);
	int itm_ind = mem->find_inventory(itm_nam);
	if (itm_ind == INT_MIN)
		throw command_error{print(
			"�u", mem->name(), "�v�́u", itm_nam, "�v���������Ă��܂���B"
		)};
	item* itm = &mem->sd()->inventory.u.items_inventory[itm_ind];
	if (itm->equip)
		throw command_error{print(
			"�u", mem->name(), "�v�́u", itm_nam, "�v�𑕔����Ă��܂��B"
		)};
	int amo = itm->amount;
	if (!args.empty()) amo = shift_arguments_then_parse_int(
		args, "���̃A�C�e���̌�", 1, amo
	);
	std::string itm_str = print_item(itm, mem->sd()->inventory_data[itm_ind], amo);
	if (!pc_dropitem(mem->sd(), itm_ind, amo))
		throw command_error{print(
			"�u", mem->name(), "�v�́u", itm_str, "�v���h���b�v�ł��܂���B"
		)};
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�́u", itm_str, "�v���h���b�v���܂����B"
	));
}

// �����A�C�e�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, ItemIgnore) {
	if (args.empty()) {
		std::vector<int> nids;
		lea->ignore_items()->copy(pybot::back_inserter(nids));
		std::sort(ALL_RANGE(nids));
		std::stringstream out;
		out << "------ �����A�C�e�� ------\n";
		for (int nid : nids) {
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << "\n";
		}
		out << nids.size() << "���̃A�C�e����������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		std::string idb_str = print_itemdb(nid);
		if (lea->ignore_items()->find(nid)) {
			lea->ignore_items()->unregister(nid);
			show_client(lea->fd(), print("�u", idb_str, "�v���E���܂��B"));
		} else {
			lea->ignore_items()->register_(nid);
			show_client(lea->fd(), print("�u", idb_str, "�v���E���܂���B"));
		}
	}
}

// �����A�C�e�����N���A����B
SUBCMD_FUNC(Bot, ItemIgnoreClear) {
	int cou = lea->ignore_items()->clear();
	show_client(lea->fd(), print(
		cou, "���̖����A�C�e���̓o�^�𖕏����܂����B"
	));
}

// �����A�C�e������荞�ށB
SUBCMD_FUNC(Bot, ItemIgnoreImport) {
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	t_tick hev_tic = lea->next_heaby_tick();
	if (hev_tic)
		throw command_error{print(
			"ItemIgnoreImport�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	auto bot_sel_itms = construct<registry_t<int>>(load_ignore_item_func(bot->char_id()));
	int cou = lea->ignore_items()->import_(bot_sel_itms.get());
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v����",
		cou, "���̖����A�C�e������荞�݂܂����B"
	));
	lea->last_heaby_tick() = now;
}

// �����o�[��HP�񕜃A�C�e�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, ItemRecoverHp) {
	using itm_val_t = std::pair<int,int*>;

	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<itm_val_t> itm_vals;
		mem->recover_hp_items()->copy(pybot::back_inserter(itm_vals));
		std::sort(ALL_RANGE(itm_vals), [] (itm_val_t lval, itm_val_t rval) -> bool {
			return *lval.second < *rval.second;
		});
		std::stringstream out;
		out << "------ �u" << mem->name() << "�v��HP�񕜃A�C�e�� ------\n";
		for (itm_val_t itm_val : itm_vals) {
			int nid = itm_val.first;
			int thr = *itm_val.second;
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << " " << thr << "%\n";
		}
		out << itm_vals.size() << "���̃A�C�e����������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		std::string idb_str = print_itemdb(nid);
		item_data* idb = itemdb_exists(actual_nameid(nid));
		if (idb->type != IT_HEALING)
			throw command_error{print(
				"�u", idb_str, "�v�͉񕜃A�C�e���ł͂���܂���B"
			)};
		if (args.empty()) {
			mem->recover_hp_items()->unregister(nid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v��HP�̉񕜂Ɏg���܂���B"
			));
		} else {
			int thr = shift_arguments_then_parse_int(args, "HP%", 1, 100);
			mem->recover_hp_items()->register_(nid, initialize<int>(thr));
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v��HP��",
				thr, "%�����̂Ƃ��Ɏg���܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[��HP�񕜃A�C�e�����N���A����B
SUBCMD_FUNC(Bot, ItemRecoverHpClear) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->recover_hp_items()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��",
		cou, "����HP�񕜃A�C�e���̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[��HP�񕜃A�C�e����]������B
SUBCMD_FUNC(Bot, ItemRecoverHpTransport) {
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->recover_hp_items()->import_(mem1->recover_hp_items().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "����HP�񕜃A�C�e����]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[��SP�񕜃A�C�e�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, ItemRecoverSp) {
	using itm_val_t = std::pair<int,int*>;

	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<itm_val_t> itm_vals;
		mem->recover_sp_items()->copy(pybot::back_inserter(itm_vals));
		std::sort(ALL_RANGE(itm_vals), [] (itm_val_t lval, itm_val_t rval) -> bool {
			return *lval.second < *rval.second;
		});
		std::stringstream out;
		out << "------ �u" << mem->name() << "�v��SP�񕜃A�C�e�� ------\n";
		for (itm_val_t itm_val : itm_vals) {
			int nid = itm_val.first;
			int thr = *itm_val.second;
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << " " << thr << "%\n";
		}
		out << itm_vals.size() << "���̃A�C�e����������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		std::string idb_str = print_itemdb(nid);
		item_data* idb = itemdb_exists(actual_nameid(nid));
		if (idb->type != IT_HEALING)
			throw command_error{print(
				"�u", idb_str, "�v�͉񕜃A�C�e���ł͂���܂���B"
			)};
		if (args.empty()) {
			mem->recover_sp_items()->unregister(nid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u",
				idb_str, "�v��SP�̉񕜂Ɏg���܂���B"
			));
		} else {
			int thr = shift_arguments_then_parse_int(args, "SP%", 1, 100);
			mem->recover_sp_items()->register_(nid, initialize<int>(thr));
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v��SP��",
				thr, "%�����̂Ƃ��Ɏg���܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[��SP�񕜃A�C�e�����N���A����B
SUBCMD_FUNC(Bot, ItemRecoverSpClear) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->recover_sp_items()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou, "����SP�񕜃A�C�e���̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[��SP�񕜃A�C�e����]������B
SUBCMD_FUNC(Bot, ItemRecoverSpTransport) {
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->recover_sp_items()->import_(mem1->recover_sp_items().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "����SP�񕜃A�C�e����]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// ���p�A�C�e�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, ItemSell) {
	if (args.empty()) {
		std::vector<int> nids;
		lea->sell_items()->copy(pybot::back_inserter(nids));
		std::sort(ALL_RANGE(nids));
		std::stringstream out;
		out << "------ ���p�A�C�e�� ------\n";
		for (int nid : nids) {
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << "\n";
		}
		out << nids.size() << "���̃A�C�e����������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		if (nid >= FAME_OFFSET)
			throw command_error{print(FAME_TAG, "�̃A�C�e���͓o�^�ł��܂���B")};
		std::string idb_str = print_itemdb(nid);
		if (lea->sell_items()->find(nid)) {
			lea->sell_items()->unregister(nid);
			show_client(lea->fd(), print("�u", idb_str, "�v�𔄂�܂���B"));
		} else {
			lea->sell_items()->register_(nid);
			show_client(lea->fd(), print("�u", idb_str, "�v�𔄂�܂��B"));
		}
	}
}

// ���ׂĂ̔��p�A�C�e���𔄋p����B
SUBCMD_FUNC(Bot, ItemSellAll) {
	if (!npc_exists(
		lea->bl(),
		battle_config.pybot_around_distance,
		NPCTYPE_SHOP
	)) throw command_error{"���ӂɏ��lNPC��������܂���B"};
	std::stringstream out;
	int tot_cou = 0;
	int tot_amo = 0;
	int tot_zen = 0;
	auto sel_itm = [lea, &out, &tot_cou, &tot_amo, &tot_zen] (
		block_if* mem,
		storage_type sto_typ,
		int ind,
		int ind_wid,
		item* itm,
		item_data* idb = nullptr
	) -> bool {
		bool res = false;
		if (itm->nameid &&
			!itm->equip &&
			!itm->card[0] &&
			!itm->refine &&
			lea->sell_items()->find(itm->nameid)
		) {
			if (!idb) idb = itemdb_exists(itm->nameid);
			int zen = pc_modifysellvalue(mem->sd(), idb->value_sell) * itm->amount;
			pc_getzeny(mem->sd(), zen, LOG_TYPE_NPC, NULL);
			out << INDEX_PREFIX << mem->member_index() << " " <<
				ID_PREFIX << mem->char_id() << " - " <<
				mem->name() << " : " <<
				STORAGE_TYPE_NAME_TABLE[sto_typ - 1] << " " <<
				INDEX_PREFIX << print(std::setw(ind_wid), std::setfill('0'), ind) << " " << 
				ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
				print_item(itm, idb) << " " <<
				print_zeny(zen) << " Zeny\n";
			++tot_cou;
			tot_amo += itm->amount;
			tot_zen += zen;
			res = true;
		}
		return res;
	};
	out << "------ ���p�����A�C�e�� ------\n";
	for (block_if* mem : lea->members()) {
		bool done = false;
		int ind_wid = print(MAX_INVENTORY - 1).length();
		for (int i = 0; i < MAX_INVENTORY; ++i) {
			item* itm = &mem->sd()->inventory.u.items_inventory[i];
			item_data* idb = mem->sd()->inventory_data[i];
			if (sel_itm(mem, TABLE_INVENTORY, i, ind_wid, itm, idb)) {
				pc_delitem(mem->sd(), i, itm->amount, 0, 6, LOG_TYPE_NONE);
				done = true;
			}
		}
		if (mem->is_carton()) {
			ind_wid = print(MAX_CART - 1).length();
			for (int i = 0; i < MAX_CART; ++i) {
				item* itm = &mem->sd()->cart.u.items_cart[i];
				if (sel_itm(mem, TABLE_CART, i, ind_wid, itm)) {
					pc_cart_delitem(mem->sd(), i, itm->amount, 0, LOG_TYPE_NONE);
					done = true;
				}
			}
		}
		if (done) clif_emotion(mem->bl(), ET_MONEY);
	}
	out << "���v" << tot_cou << "���A" << tot_amo << "�̃A�C�e����" <<
		print_zeny(tot_zen) << "Zeny�Ŕ���܂����B\n";
	show_client(lea->fd(), out.str());
}

// ���p�A�C�e�����N���A����B
SUBCMD_FUNC(Bot, ItemSellClear) {
	int cou = lea->sell_items()->clear();
	show_client(lea->fd(), print(
		cou, "���̔��p�A�C�e���̓o�^�𖕏����܂����B"
	));
}

// ���p�A�C�e������荞�ށB
SUBCMD_FUNC(Bot, ItemSellImport) {
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	t_tick hev_tic = lea->next_heaby_tick();
	if (hev_tic)
		throw command_error{print(
			"ItemSellImport�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	auto bot_sel_itms = construct<registry_t<int>>(load_sell_item_func(bot->char_id()));
	int cou = lea->sell_items()->import_(bot_sel_itms.get());
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v����",
		cou, "���̔��p�A�C�e������荞�݂܂����B"
	));
	lea->last_heaby_tick() = now;
}

// Bot�����O�C������B
SUBCMD_FUNC(Bot, LogIn) {
	if (lea->bots().size() >= bot_limit(lea->sd()))
		throw command_error{
		"�`�[���ɏ������Ă���Bot�̐l���������l���ɒB���Ă��܂��B"
	};
	std::string uid = shift_arguments(
		args, "���[�U�[ID���w�肵�Ă��������B"
	);
	std::string upas = shift_arguments(
		args, "�p�X���[�h���w�肵�Ă��������B"
	);
	std::string cnam = shift_arguments(
		args, "�L�����N�^�[�����w�肵�Ă��������B"
	);
	int bot_cid = query_char_id(uid, upas, cnam);
	if (!bot_cid)
		throw command_error{"���̃L�����N�^�[�͌�����܂���ł����B"};
	t_tick hev_tic = lea->next_heaby_tick();
	if (hev_tic)
		throw command_error{print(
			"LogIn�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	query_login_data(bot_cid,
		[lea, bot_cid] (int bot_aid, int bot_sex, int bot_gid, int unb_tim, int sta, const std::string& nam) {
			if (!bot_can_enter_server(bot_aid))
				throw command_error{print("�u", nam, "�v�͌��݃��O�C���ł��܂���B")};
			if (unb_tim ||
				sta
			) throw command_error{print("�u", nam, "�v�̃A�J�E���g�͌��ݒ�~���ł��B")};
			t_tick bot_res_tic = bot_restart_tick(bot_cid);
			if (bot_res_tic) {
				throw command_error{print(
					"�u", nam, "�v��Bot���Ɏ��S���܂����B\n"
					"�Ăу��O�C���ł���悤�ɂȂ�܂ł���", print_tick(bot_res_tic + 1000), "�ł��B\n"
				)};
			}
			map_session_data* bot_sd = bot_login(lea, bot_aid, bot_cid, bot_sex, bot_gid);
			ptr<block_if> bot = construct<bot_t>(bot_sd, lea);
			lea->bots().push_back(bot);
			lea->members().push_back(bot.get());
			lea->update_bot_indices();
			lea->update_member_indices();
			lea->last_heaby_tick() = now;
			show_client(lea->fd(), print(
				"�u", bot->name(), "�v�����O�C�����܂����B"
			));
		}
	);
}

// Bot�����O�A�E�g����B
SUBCMD_FUNC(Bot, LogOut) {
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	if (lea->bots().size() == 1) {
		save_team(lea, 0);
		lea->passive() = false;
		lea->stay() = false;
	}
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v�����O�A�E�g���܂����B"
	));
	lea->members().erase(lea->members().begin() + bot->member_index());
	lea->update_member_indices();
	lea->bots().erase(lea->bots().begin() + bot->bot_index());
	lea->update_bot_indices();
	lea->last_heaby_tick() = now;
}

// �����o�[���A�C�e�����E���A�܂��͏E��Ȃ��B
SUBCMD_FUNC(Bot, Loot) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	auto& loot = mem->loot();
	loot->set(!loot->get());
	if (loot->get()) show_client(lea->fd(), print(
		"�u", mem->name(), "�v�̓h���b�v�A�C�e�����E���܂��B"
	));
	else show_client(lea->fd(), print(
		"�u", mem->name(), "�v�̓h���b�v�A�C�e�����E���܂���B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�����݈ʒu����������B
SUBCMD_FUNC(Bot, Memo) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (!mem->check_skill(AL_WARP))
		throw command_error{print(
			"�u", mem->name(), "�v�́u",
			skill_get_desc(AL_WARP), "�v���g���܂���B"
		)};
	if (!pc_memo(mem->sd(), -1))
		throw command_error{"���̃}�b�v�ł̓������֎~����Ă��܂��B"};
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�͌��݂̈ʒu�����[�v�ʒu�Ƃ��ă������܂����B"
	));
	clif_emotion(mem->bl(), ET_OK);
}

// �O���[�g�����X�^�[���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, MonsterGreat) {
	if (args.empty()) {
		std::vector<int> mids;
		lea->great_mobs()->copy(pybot::back_inserter(mids));
		std::sort(ALL_RANGE(mids));
		std::stringstream out;
		out << "------ �O���[�g�����X�^�[ ------\n";
		for (int mid : mids)
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " << 
				print_mobdb(mid) << "\n";
		out << mids.size() << "���̃����X�^�[��������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string mob_nam = shift_arguments(args);
		int mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		std::string mob_str = print_mobdb(mid);
		if (mid < MM_INDIVIDUAL ||
			mid >= MM_CAUTION
		) throw command_error{print("�u", mob_str, "�v�͎w��ł��܂���B")};
		struct mob_db* mdb = mob_db(mid);
		if (status_has_mode(&mdb->status, MD_MVP))
			throw command_error{print("�u", mob_str, "�v��MVP�����X�^�[�ł��B")};
		if (lea->great_mobs()->find(mid)) {
			lea->great_mobs()->unregister(mid);
			show_client(lea->fd(), print(
				"�u", mob_str, "�v���O���[�g�����X�^�[�Ƃ݂Ȃ��܂���B"
			));
		} else {
			lea->great_mobs()->register_(mid);
			show_client(lea->fd(), print(
				"�u", mob_str, "�v���O���[�g�����X�^�[�Ƃ݂Ȃ��܂��B"
			));
		}
	}
}

// �O���[�g�����X�^�[���N���A����B
SUBCMD_FUNC(Bot, MonsterGreatClear) {
	int cou = lea->great_mobs()->clear();
	show_client(lea->fd(), print(
		cou, "���̃O���[�g�����X�^�[�̓o�^�𖕏����܂����B"
	));
}

// �O���[�g�����X�^�[����荞�ށB
SUBCMD_FUNC(Bot, MonsterGreatImport) {
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	t_tick hev_tic = lea->next_heaby_tick();
	if (hev_tic)
		throw command_error{print(
			"MonsterGreatImport�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	auto bot_gre_mobs = construct<registry_t<int>>(load_great_mob_func(bot->char_id()));
	int cou = lea->great_mobs()->import_(bot_gre_mobs.get());
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v����",
		cou, "���̃O���[�g�����X�^�[����荞�݂܂����B"
	));
	lea->last_heaby_tick() = now;
}

// �y�b�g���A�N�Z�T���[�𑕔��A�܂��͉�������B
SUBCMD_FUNC(Bot, PetEquip) {
	block_if* pet = get_active_pet(shift_arguments_then_find_member(lea, args));
	int acc_nid = pet->pd()->get_pet_db()->AcceID;
	if (!acc_nid)
		throw command_error{print(
			"�u", pet->name(), "�v�������ł���A�N�Z�T���[�͂���܂���B"
		)};
	std::string acc_str = print_itemdb(acc_nid);
	if (pet->pd()->pet.equip) {
		if (pet_unequipitem(pet->master()->sd(), pet->pd()))
			throw command_error{print(
				"�u", pet->name(), "�v�́u", acc_str, "�v�̑����������ł��܂���B"
			)};
		show_client(lea->fd(), print(
			"�u", pet->name(), "�v�́u", acc_str, "�v�̑������������܂����B"
		));
	} else {
		int acc_ind = pet->master()->find_inventory(item_key(acc_nid));
		if (acc_ind == INT_MIN)
			throw command_error{print(
				"�u", pet->master()->name(), "�v�́u",
				acc_str, "�v���������Ă��܂���B"
			)};
		if (pet_equipitem(pet->master()->sd(), acc_ind))
			throw command_error{print(
				"�u", pet->name(), "�v�́u", acc_str, "�v�𑕔��ł��܂���B"
			)};
		show_client(lea->fd(), print(
			"�u", pet->name(), "�v�́u", acc_str, "�v�𑕔����܂����B"
		));
	}
}

// �y�b�g�̃X�e�[�^�X��\������B
SUBCMD_FUNC(Bot, PetStatus) {
	block_if* pet = get_active_pet(shift_arguments_then_find_member(lea, args));
	std::stringstream out;
	out << "------ �u" << pet->name() << "�v�̃X�e�[�^�X ------\n";
	out << "��� <"  << pet->pd()->get_pet_db()->jname << "> "
		"���x�� " << pet->pd()->pet.level           << " "
		"�󕠓x " << pet->pd()->pet.hungry          << "% "
		"�e���x " << print(std::fixed, std::setprecision(1), pet->pd()->pet.intimate / 10.);
	int acc_nid = pet->pd()->get_pet_db()->AcceID;
	if (acc_nid) {
		out << " �A�N�Z�T���[ <";
		if (pet->pd()->pet.equip) out << "�����ς�";
		else out << "������";
		out << ">";
	}
	out << "\n";
	show_client(lea->fd(), out.str());
}

// �����o�[�̋����|���V�[���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, PolicyDistance) {
	using pol_val_t = std::pair<int,distance_policy*>;

	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<pol_val_t> pol_vals;
		mem->distance_policies()->copy(pybot::back_inserter(pol_vals));
		std::sort(ALL_RANGE(pol_vals), [lea] (pol_val_t lval, pol_val_t rval) -> bool {
			int lxmid = lval.first;
			int rxmid = rval.first;
			distance_policy* lpol = lval.second;
			distance_policy* rpol = rval.second;
			bool lcau = lxmid >= MM_CAUTION;
			bool rcau = rxmid >= MM_CAUTION;
			if (lcau != rcau) return lcau;
			bool lind = lxmid >= MM_INDIVIDUAL;
			bool rind = rxmid >= MM_INDIVIDUAL;
			if (lind != rind) return lind;
			if (lind) {
				bool lgre = lea->great_mobs()->find(lpol->mob_id);
				bool rgre = lea->great_mobs()->find(rpol->mob_id);
				if (lgre != rgre) return lgre;
				bool lsum = KEY_EXISTS(skill_mobs::instance->summon, lpol->mob_id);
				bool rsum = KEY_EXISTS(skill_mobs::instance->summon, rpol->mob_id);
				if (lsum != rsum) return lsum;
				bool llra = lpol->mdb->status.rhw.range > 3;
				bool rlra = rpol->mdb->status.rhw.range > 3;
				if (llra != rlra) return rlra;
				if (lpol->mdb->lv != rpol->mdb->lv) return lpol->mdb->lv > rpol->mdb->lv;
			}
			return lxmid > rxmid;
		});
		std::stringstream out;
		out << "------ �u" << mem->name() << "�v�̋����|���V�["
			"(" << DISTANCE_POLICY_VALUE_NAME_TABLE[mem->default_distance_policy_value()] << ") ------\n";
		for (pol_val_t pol_val : pol_vals) {
			int mid = pol_val.first;
			distance_policy* pol = pol_val.second;
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
			       print_mobdb(mid) << " " <<
			       DISTANCE_POLICY_VALUE_NAME_TABLE[pol->value] << "\n";
		}
		out << pol_vals.size() << "���̋����|���V�[��������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string mob_nam = shift_arguments(args);
		int mid = find_mobdb(mob_nam);
		if (!mid) throw command_error{print(
			"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
		)};
		std::string mob_str = print_mobdb(mid);
		if (args.empty()) {
			distance_policy* old_pol = mem->distance_policies()->find(mid);
			if (!old_pol)
				throw command_error{print(
					"�u", mob_nam, "�v�p�����|���V�[�͌�����܂���ł����B"
				)};
			mem->distance_policies()->unregister(mid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str,
				"�v�p�����|���V�[�̓o�^�𖕏����܂����B"
			));
		} else {
			if (mid < MM_BASE ||
				mid >= MM_CAUTION
			) throw command_error{print(
				"�u", META_MONSTER_NAMES.at(meta_mobs(mid)),
				"�v�p�����|���V�[�͓o�^�ł��܂���B"
			)};
			std::string pol_val_nams = concatinate_strings(
				DISTANCE_POLICY_VALUE_NAME_TABLE.begin() + 1,
				DISTANCE_POLICY_VALUE_NAME_TABLE.end(),
				"|"
			);
			std::string pol_val_str = shift_arguments(
				args, print("�l(", pol_val_nams, ")���w�肵�Ă��������B"
				));
			int pol_val_ind = find_name(DISTANCE_POLICY_VALUE_NAME_TABLE, lowercase(pol_val_str));
			if (pol_val_ind == INT_MIN ||
				pol_val_ind == DPV_PENDING
			) throw command_error{print(
				"�u", pol_val_str, "�v�Ƃ����l�͂���܂���B"
			)};
			auto pol = construct<distance_policy>(mid, distance_policy_values(pol_val_ind));
			mem->distance_policies()->register_(mid, pol);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v�p�����|���V�[�Ɂu",
				DISTANCE_POLICY_VALUE_NAME_TABLE[pol->value], "�v��o�^���܂����B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̋����|���V�[���N���A����B
SUBCMD_FUNC(Bot, PolicyDistanceClear) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->distance_policies()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��",
		cou, "���̋����|���V�[�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̋����|���V�[��]������B
SUBCMD_FUNC(Bot, PolicyDistanceTransport) {
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->distance_policies()->import_(mem1->distance_policies().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̋����|���V�[��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̒ʏ�U���|���V�[���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, PolicyNormalAttack) {
	using pol_val_t = std::pair<int,normal_attack_policy*>;

	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<pol_val_t> pol_vals;
		mem->normal_attack_policies()->copy(pybot::back_inserter(pol_vals));
		std::sort(ALL_RANGE(pol_vals), [lea] (pol_val_t lval, pol_val_t rval) -> bool {
			int lxmid = lval.first;
			int rxmid = rval.first;
			normal_attack_policy* lpol = lval.second;
			normal_attack_policy* rpol = rval.second;
			bool lcau = lxmid >= MM_CAUTION;
			bool rcau = rxmid >= MM_CAUTION;
			if (lcau != rcau) return lcau;
			bool lind = lxmid >= MM_INDIVIDUAL;
			bool rind = rxmid >= MM_INDIVIDUAL;
			if (lind != rind) return lind;
			if (lind) {
				bool lgre = lea->great_mobs()->find(lpol->mob_id);
				bool rgre = lea->great_mobs()->find(rpol->mob_id);
				if (lgre != rgre) return lgre;
				bool lsum = KEY_EXISTS(skill_mobs::instance->summon, lpol->mob_id);
				bool rsum = KEY_EXISTS(skill_mobs::instance->summon, rpol->mob_id);
				if (lsum != rsum) return lsum;
				bool llra = lpol->mdb->status.rhw.range > 3;
				bool rlra = rpol->mdb->status.rhw.range > 3;
				if (llra != rlra) return rlra;
				if (lpol->mdb->lv != rpol->mdb->lv) return lpol->mdb->lv > rpol->mdb->lv;
			}
			return lxmid > rxmid;
		});
		std::stringstream out;
		out << "------ �u" << mem->name() << "�v�̒ʏ�U���|���V�["
			"(" << NORMAL_ATTACK_POLICY_VALUE_NAME_TABLE[mem->default_normal_attack_policy_value()] << ") ------\n";
		for (pol_val_t pol_val : pol_vals) {
			int mid = pol_val.first;
			normal_attack_policy* pol = pol_val.second;
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				   print_mobdb(mid) << " " <<
				   NORMAL_ATTACK_POLICY_VALUE_NAME_TABLE[pol->value] << "\n";
		}
		out << pol_vals.size() << "���̒ʏ�U���|���V�[��������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string mob_nam = shift_arguments(args);
		int mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		std::string mob_str = print_mobdb(mid);
		if (args.empty()) {
			normal_attack_policy* old_pol = mem->normal_attack_policies()->find(mid);
			if (!old_pol)
				throw command_error{print(
					"�u", mob_nam, "�v�p�ʏ�U���|���V�[�͌�����܂���ł����B"
				)};
			mem->normal_attack_policies()->unregister(mid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str,
				"�v�p�ʏ�U���|���V�[�̓o�^�𖕏����܂����B"
			));
		} else {
			if (mid < MM_BASE ||
				mid >= MM_CAUTION
			) throw command_error{print(
				"�u", META_MONSTER_NAMES.at(meta_mobs(mid)),
				"�v�p�ʏ�U���|���V�[�͓o�^�ł��܂���B"
			)};
			std::string pol_val_nams = concatinate_strings(
				NORMAL_ATTACK_POLICY_VALUE_NAME_TABLE.begin() + 1,
				NORMAL_ATTACK_POLICY_VALUE_NAME_TABLE.end(),
				"|"
			);
			std::string pol_val_str = shift_arguments(args, print(
				"�l(", pol_val_nams, ")���w�肵�Ă��������B"
			));
			int pol_val_ind = find_name(NORMAL_ATTACK_POLICY_VALUE_NAME_TABLE, lowercase(pol_val_str));
			if (pol_val_ind == INT_MIN ||
				pol_val_ind == DPV_PENDING
			) throw command_error{print(
				"�u", pol_val_str, "�v�Ƃ����l�͂���܂���B"
			)};
			auto pol = construct<normal_attack_policy>(mid, normal_attack_policy_values(pol_val_ind));
			mem->normal_attack_policies()->register_(mid, pol);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v�p�ʏ�U���|���V�[�Ɂu",
				NORMAL_ATTACK_POLICY_VALUE_NAME_TABLE[pol->value], "�v��o�^���܂����B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̒ʏ�U���|���V�[���N���A����B
SUBCMD_FUNC(Bot, PolicyNormalAttackClear) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->normal_attack_policies()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou,
		"���̒ʏ�U���|���V�[�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̒ʏ�U���|���V�[��]������B
SUBCMD_FUNC(Bot, PolicyNormalAttackTransport) {
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->normal_attack_policies()->import_(mem1->normal_attack_policies().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̒ʏ�U���|���V�[��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̃X�L�����ꗗ�\���A�܂��͎g���B
SUBCMD_FUNC(Bot, sKill) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) skill_user_show_skills(lea->fd(), mem);
	else skill_user_use_skill(lea, args, mem);
}

// �����o�[�̃A�N�e�B�u�X�L���𐧌�����B
SUBCMD_FUNC(Bot, sKillLimit) {
	skill_user_limit_skill(lea, args, shift_arguments_then_find_member(lea, args));
}

// �͈̓X�L���̔��������ƂȂ郂���X�^�[����ݒ肷��B
SUBCMD_FUNC(Bot, sKillMonsters) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = shift_arguments_then_parse_int(
		args, print("�����X�^�[��"), 1,	INT_MAX
	);
	mem->skill_monsters()->set(cou);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�͈̔̓X�L���̔��������ƂȂ郂���X�^�[����",
		mem->skill_monsters()->get(), "�C�ɂ��܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̉��t�X�L�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, sKillPlay) {
	using ps_val_t = std::pair<int,play_skill*>;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if ((mem->sd()->class_ & MAPID_UPPERMASK) != MAPID_BARDDANCER)
		throw command_error{print(
			"�u", mem->name(), "�v�̓o�[�h�E�_���T�[�n�ł͂���܂���B"
		)};
	if (args.empty()) {
		std::vector<ps_val_t> ps_vals;
		mem->play_skills()->copy(pybot::back_inserter(ps_vals));
		std::sort(ALL_RANGE(ps_vals), [lea] (ps_val_t lval, ps_val_t rval) -> bool {
			int lxmid = lval.first;
			int rxmid = rval.first;
			play_skill* lps = lval.second;
			play_skill* rps = rval.second;
			bool lcau = lxmid >= MM_CAUTION;
			bool rcau = rxmid >= MM_CAUTION;
			if (lcau != rcau) return lcau;
			bool lind = lxmid >= MM_INDIVIDUAL;
			bool rind = rxmid >= MM_INDIVIDUAL;
			if (lind != rind) return lind;
			if (lind) {
				bool lgre = lea->great_mobs()->find(lps->mob_id);
				bool rgre = lea->great_mobs()->find(rps->mob_id);
				if (lgre != rgre) return lgre;
				bool lsum = KEY_EXISTS(skill_mobs::instance->summon, lps->mob_id);
				bool rsum = KEY_EXISTS(skill_mobs::instance->summon, rps->mob_id);
				if (lsum != rsum) return lsum;
				bool llra = lps->mdb->status.rhw.range > 3;
				bool rlra = rps->mdb->status.rhw.range > 3;
				if (llra != rlra) return rlra;
				if (lps->mdb->lv != rps->mdb->lv) return lps->mdb->lv > rps->mdb->lv;
			}
			return lxmid > rxmid;
		});
		std::stringstream out;
		out << "------ �u" <<	mem->name() << "�v�̉��t�X�L�� ------\n";
		for (ps_val_t ps_val : ps_vals) {
			int mid = ps_val.first;
			play_skill* ps = ps_val.second;
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				print_mobdb(mid) << " : " <<
				ID_PREFIX << print(std::setw(5), std::setfill('0'), ps->skill_id) << " - " <<
				skill_get_desc(ps->skill_id) << "\n";
		}
		out << ps_vals.size() << "���̉��t�X�L����������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string mob_nam = shift_arguments(args);
		int mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		std::string mob_str = print_mobdb(mid);
		if (args.empty()) {
			play_skill* old_ps = mem->play_skills()->find(mid);
			if (!old_ps)
				throw command_error{print(
					"�u", mob_nam, "�v�p���t�X�L���͌�����܂���ł����B"
				)};
			mem->play_skills()->unregister(mid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str,
				"�v�p���t�X�L���̓o�^�𖕏����܂����B"
			));
		} else {
			if (mid == MM_BACKUP)
				throw command_error{print(
					"�u", META_MONSTER_NAMES.at(MM_BACKUP),
					"�v�p���t�X�L���͓o�^�ł��܂���B"
				)};
			std::string sk_nam = shift_arguments(args);
			int kid = find_skilldb(sk_nam);
			if (!kid)
				throw command_error{print(
					"�u", sk_nam, "�v�Ƃ����X�L���͂���܂���B"
				)};
			std::string sk_des = skill_get_desc(kid);
			if ((!(skill_get_inf2(kid) & INF2_SONG_DANCE) &&
					!(skill_get_inf2(kid) & INF2_ENSEMBLE_SKILL)
				) || kid == PR_BENEDICTIO
			) throw command_error{print(
				"�u", sk_des, "�v�͉��t�X�L���ł͂���܂���B"
			)};
			if (mid == MM_REST &&
				skill_get_inf2(kid) & INF2_ENSEMBLE_SKILL
			) throw command_error{print(
				"�u", META_MONSTER_NAMES.at(MM_REST),
				"�v�p���t�X�L���ɍ��t�X�L���͓o�^�ł��܂���B"
			)};
			auto ps = construct<play_skill>(mid, e_skill(kid));
			mem->play_skills()->register_(mid, ps);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v�p���t�X�L����"
				"�u", skill_get_desc(ps->skill_id), "�v��o�^���܂����B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̉��t�X�L�����N���A����B
SUBCMD_FUNC(Bot, sKillPlayClear) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if ((mem->sd()->class_ & MAPID_UPPERMASK) != MAPID_BARDDANCER)
		throw command_error{print(
			"�u", mem->name(), "�v�̓o�[�h�E�_���T�[�n�ł͂���܂���B"
		)};
	int cou = mem->play_skills()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou,
		"���̉��t�X�L���̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̉��t�X�L����]������B
SUBCMD_FUNC(Bot, sKillPlayTransport) {
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	if ((mem1->sd()->class_ & MAPID_UPPERMASK) != MAPID_BARDDANCER)
		throw command_error{print(
			"�u", mem1->name(), "�v�̓o�[�h�E�_���T�[�n�ł͂���܂���B"
		)};
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if ((mem2->sd()->class_ & MAPID_UPPERMASK) != MAPID_BARDDANCER)
		throw command_error{print(
			"�u", mem2->name(), "�v�̓o�[�h�E�_���T�[�n�ł͂���܂���B"
		)};
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->play_skills()->import_(mem1->play_skills().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̉��t�X�L����]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̋��ۃX�L�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, sKillReject) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<int> kids;
		mem->reject_skills()->copy(pybot::back_inserter(kids));
		std::sort(ALL_RANGE(kids));
		std::stringstream out;
		out << "------ �u" << mem->name() << "�v�̋��ۃX�L�� ------\n";
		for (int kid : kids)
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), kid) <<
				" - " << skill_get_desc(kid) << "\n";
		out << kids.size() << "���̃X�L����������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string sk_nam = shift_arguments(args);
		int kid = find_skilldb(sk_nam);
		if (!kid) throw command_error{print(
			"�u", sk_nam, "�v�Ƃ����X�L���͂���܂���B"
		)};
		std::string sk_des = skill_get_desc(kid);
		if (!(skill_get_inf(kid) & INF_SUPPORT_SKILL) &&
			!(skill_get_inf2(kid) & (INF2_PARTY_ONLY | INF2_GUILD_ONLY)) &&
			kid != PR_BENEDICTIO
		) throw command_error{print(
			"�u", sk_des, "�v�̓^�[�Q�b�g�x���X�L���ł͂���܂���B"
		)};
		if (mem->reject_skills()->find(kid)) {
			mem->reject_skills()->unregister(kid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sk_des, "�v�����ۂ��܂���B"
			));
		} else {
			mem->reject_skills()->register_(kid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sk_des, "�v�����ۂ��܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̋��ۃX�L�����N���A����B
SUBCMD_FUNC(Bot, sKillRejectClear) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->reject_skills()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou, "���̋��ۃX�L���̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̋��ۃX�L����]������B
SUBCMD_FUNC(Bot, sKillRejectTransport) {
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->reject_skills()->import_(mem1->reject_skills().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̋��ۃX�L����]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̃X�L�����x�����グ��B
SUBCMD_FUNC(Bot, sKillUp) {
	skill_user_skill_up(lea, args, shift_arguments_then_find_member(lea, args));
}

// �����o�[�̃X�e�[�^�X��\������B
SUBCMD_FUNC(Bot, Status) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	std::stringstream out;
	out << "------ �u" << mem->name() << "�v�̃X�e�[�^�X ------\n";
	out << "BaseLv " << mem->sd()->status.base_level << " ";
	if (!pc_is_maxbaselv(mem->sd()))
		out << "(" << mem->sd()->status.base_exp << "/" << pc_nextbaseexp(mem->sd()) <<	" " <<
			print(
				std::fixed,
				std::setprecision(1),
				mem->sd()->status.base_exp * 100. / pc_nextbaseexp(mem->sd())
			) << "%) ";
	out << "JobLv " << mem->sd()->status.job_level << " ";
	if (!pc_is_maxjoblv(mem->sd()))
		out << "(" << mem->sd()->status.job_exp << "/" << pc_nextjobexp(mem->sd()) << " " <<
			print(
				std::fixed,
				std::setprecision(1),
				mem->sd()->status.job_exp * 100. / pc_nextjobexp(mem->sd())
			) << "%) ";
	out << "Status Point " << mem->sd()->status.status_point << " ";
	if (pc_is_maxbaselv(mem->sd())) {
		int cas_exp = pc_readglobalreg(mem->sd(), add_str(CASH_EXP.c_str()));
		out << "Cash Point " << mem->sd()->cashPoints << " "
			"(" << cas_exp << "/" << MAX_LEVEL_BASE_EXP << ")\n";
	}
	int inv_num = MAX_INVENTORY - pc_inventoryblank(mem->sd());
	out << STORAGE_TYPE_NAME_TABLE[TABLE_INVENTORY - 1] << " " <<
		inv_num << "/" << MAX_INVENTORY << " "
		"(" << (mem->sd()->weight / 10.) << "/" << (mem->sd()->max_weight / 10.) <<	" " <<
		print(
			std::fixed,
			std::setprecision(1),
			mem->sd()->weight * 100. / mem->sd()->max_weight
		) << "%) ";
	if (mem->is_carton()) {
		status_calc_cart_weight(mem->sd(), CALCWT_ITEM);
		out << STORAGE_TYPE_NAME_TABLE[TABLE_CART - 1] << " " <<
			mem->sd()->cart_num << "/" << MAX_CART << " "
			"(" << (mem->sd()->cart_weight / 10.) << "/" << (mem->sd()->cart_weight_max / 10.) << " " <<
			print(
				std::fixed,
				std::setprecision(1),
				mem->sd()->cart_weight * 100. / mem->sd()->cart_weight_max
			) << "%) ";
	}
	out << "Zeny " << print_zeny(mem->sd()->status.zeny) << "\n";
	out << print_main_status(mem->sd());
	out << print_sc(mem->sc()) << "\n";
	show_client(lea->fd(), out.str());
}

// �����o�[���X�e�[�^�X�Ƀ|�C���g������U��B
SUBCMD_FUNC(Bot, StatusUp) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	std::string typ_str = shift_arguments(
		args, "�^�C�v���w�肵�Ă��������B"
	);
	int typ_ind = find_name(STATUS_TYPE_NAME_TABLE, lowercase(typ_str));
	if (typ_ind == INT_MIN)
		throw command_error{print(
			"�u", typ_str, "�v�Ƃ����^�C�v�͂���܂���B"
		)};
	_sp sp = ST2SP_TABLE[typ_ind];
	std::string typ_nam = STATUS_TYPE_NAME_TABLE[typ_ind];
	int amo = 1;
	if (!args.empty()) amo = shift_arguments_then_parse_int(
		args, "�|�C���g", 1, 98
	);
	if (!pc_statusup(mem->sd(), sp, amo))
		throw command_error{print(
			"�u", mem->name(), "�v�͂���ȏ�u", typ_nam,
			"�v�Ƀ|�C���g������U�邱�Ƃ��ł��܂���B"
		)};
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�́u", typ_nam, "�v��",
		pc_getstat(mem->sd(), sp), "�ɂȂ�܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_BEST);
}

// �����o�[�̑q�ɕ�[�A�C�e�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, StorageGet) {
	using itm_val_t = std::pair<int,int*>;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<itm_val_t> itm_vals;
		mem->storage_get_items()->copy(pybot::back_inserter(itm_vals));
		std::sort(ALL_RANGE(itm_vals), [] (itm_val_t lval, itm_val_t rval) -> bool {
			return lval.first < rval.first;
		});
		std::stringstream out;
		out << "------ �u" << mem->name() << "�v�̑q�ɕ�[�A�C�e�� ------\n";
		for (itm_val_t itm_val : itm_vals) {
			int nid = itm_val.first;
			int amo = *itm_val.second;
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << " (" << amo << ")\n";
		}
		out << itm_vals.size() << "���̃A�C�e����������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		std::string idb_str = print_itemdb(nid);
		item_data* idb = itemdb_exists(actual_nameid(nid));
		if (!itemdb_isstackable2(idb))
			throw command_error{print(
				"�u", idb_str, "�v�̓X�^�b�N�ł��܂���B"
			)};
		if (args.empty()) {
			mem->storage_get_items()->unregister(nid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str,
				"�v��q�ɂ�����o���܂���B"
			));
			if (mem != lea) clif_emotion(mem->bl(), ET_OK);
		} else {
			int amo = shift_arguments_then_parse_int(
				args, "�A�C�e���̌�", 1, MAX_AMOUNT
			);
			mem->storage_get_items()->register_(nid, initialize<int>(amo));
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v�̏�������",
				amo, "�ɂȂ�悤�ɑq�ɂ�����o���܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �q�ɂ���A�C�e�����[����B
SUBCMD_FUNC(Bot, StorageGetAll) {
	ptr<storage_context> sto_con;
	switch (lea->sd()->state.storage_flag) {
	case 0: throw command_error{"�q�ɂ��J���Ă��������B"};
	case 2: sto_con = construct<guild_storage_context>(lea->sd()); break;
	default: sto_con = construct<private_storage_context>(lea->sd());
	}
	std::stringstream out;
	int tot_cou = 0;
	int tot_amo = 0;
	out << "------ �q�ɂ����[�����A�C�e�� ------\n";
	for (block_if* mem : lea->members()) {
		bool done = false;
		ptr<storage_context> mem_con;
		if (mem->is_carton()) mem_con = construct<cart_context>(mem->sd());
		else mem_con = construct<inventory_context>(mem->sd());
		mem->storage_get_items()->iterate(
			[sto_con, &out, &tot_cou, &tot_amo, mem, &done, mem_con] (int nid, int* amo) -> bool {
				int mem_amo = mem_con->sum(nid);
				if (mem_amo < *amo) {
					int com = 0;
					bool suc = true;
					while (mem_amo + com < *amo) {
						int sto_ind = sto_con->find(nid);
						if (sto_ind == INT_MIN) break;
						item* itm = sto_con->at(sto_ind);
						int rem = std::min(*amo - (mem_amo + com), int(itm->amount));
						suc = mem_con->add(itm, rem);
						if (!suc) break;
						sto_con->delete_(sto_ind, rem);
						done = true;
						com += rem;
					}
					if (com) {
						++tot_cou;
						tot_amo += com;
					}
					out << INDEX_PREFIX << mem->member_index() << " " <<
						ID_PREFIX << mem->char_id() << " - " <<
						mem->name() << " : " <<
						ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
						print_itemdb(nid) << " (" << com << ")";
					if (!suc) out << " ����[���s";
					else if (mem_amo + com < *amo) out << " ���݌ɕs��";
					out << "\n";
				}
				return true;
			}
		);
		if (done) clif_emotion(mem->bl(), ET_GO);
	}
	out << "���v" << tot_cou << "���A" << tot_amo <<
		"�̃A�C�e�������o���܂����B\n";
	show_client(lea->fd(), out.str());
}

// �����o�[�̑q�ɕ�[�A�C�e�����N���A����B
SUBCMD_FUNC(Bot, StorageGetClear) {
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->storage_get_items()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�� ", cou,
		"���̑q�ɕ�[�A�C�e���̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̑q�ɕ�[�A�C�e����]������B
SUBCMD_FUNC(Bot, StorageGetTransport) {
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->storage_get_items()->import_(mem1->storage_get_items().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v�� ",
		cou, "���̑q�ɕ�[�A�C�e����]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̑q�Ɋi�[�A�C�e�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, StoragePut) {
	if (args.empty()) {
		std::vector<int> nids;
		lea->storage_put_items()->copy(pybot::back_inserter(nids));
		std::sort(ALL_RANGE(nids));
		std::stringstream out;
		out << "------ �q�Ɋi�[�A�C�e�� ------\n";
		for (int nid : nids) {
			out << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << "\n";
		}
		out << nids.size() << "���̃A�C�e����������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		std::string idb_str = print_itemdb(nid);
		if (lea->storage_put_items()->find(nid)) {
			lea->storage_put_items()->unregister(nid);
			show_client(
				lea->fd(),
				print("�u", idb_str, "�v��q�ɂɓ���܂���B")
			);
		} else {
			lea->storage_put_items()->register_(nid);
			show_client(
				lea->fd(),
				print("�u", idb_str, "�v��q�ɂɓ���܂��B")
			);
		}
	}
}

// �q�ɂɃA�C�e�����i�[����B
SUBCMD_FUNC(Bot, StoragePutAll) {
	ptr<storage_context> sto_con;
	switch (lea->sd()->state.storage_flag) {
	case 0: throw command_error{"�q�ɂ��J���Ă��������B"};
	case 2: sto_con = construct<guild_storage_context>(lea->sd()); break;
	default: sto_con = construct<private_storage_context>(lea->sd());
	}
	std::stringstream out;
	int tot_cou = 0;
	int tot_amo = 0;
	auto put_itm = [lea, sto_con, &out, &tot_cou, &tot_amo] (
		block_if* mem,
		storage_type sto_typ,
		int ind,
		int ind_wid,
		item* itm,
		item_data* idb = nullptr
	) -> bool {
		bool res = false;
		if (!idb) idb = itemdb_exists(itm->nameid);
		if (itm->nameid &&
			(!itm->equip ||
				itemdb_isstackable2(idb)
			) && (!itm->card[0] ||
				itm->card[0] == CARD0_CREATE
			) && !itm->refine
		) {
			int nid = itm->nameid;
			if (itm->card[0] == CARD0_CREATE &&
				pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST)
			) nid += FAME_OFFSET;
			if (lea->storage_put_items()->find(nid)) {
				res = (!itm->equip ||
						pc_unequipitem(mem->sd(), ind, 1)
					) && sto_con->add(itm, itm->amount);
				if (res) {
					++tot_cou;
					tot_amo += itm->amount;
				}
				out << INDEX_PREFIX << mem->member_index() << " " <<
					ID_PREFIX << mem->char_id() << " - " <<
					mem->name() << " : " <<
					STORAGE_TYPE_NAME_TABLE[sto_typ - 1] << " " <<
					INDEX_PREFIX << print(std::setw(ind_wid), std::setfill('0'), ind) << " " << 
					ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
					print_item(itm, idb);
				if (!res) out << " ���i�[���s";
				out << "\n";
			}
		}
		return res;
	};
	out << "------ �q�ɂɊi�[�����A�C�e�� ------\n";
	for (block_if* mem : lea->members()) {
		bool done = false;
		int ind_wid = print(MAX_INVENTORY - 1).length();
		for (int i = 0; i < MAX_INVENTORY; ++i) {
			item* itm = &mem->sd()->inventory.u.items_inventory[i];
			item_data* idb = mem->sd()->inventory_data[i];
			if (put_itm(mem, TABLE_INVENTORY, i, ind_wid, itm, idb)) {
				pc_delitem(mem->sd(), i, itm->amount, 0, 6, LOG_TYPE_NONE);
				done = true;
			}
		}
		if (mem->is_carton()) {
			ind_wid = print(MAX_CART - 1).length();
			for (int i = 0; i < MAX_CART; ++i) {
				item* itm = &mem->sd()->cart.u.items_cart[i];
				if (put_itm(mem, TABLE_CART, i, ind_wid, itm)) {
					pc_cart_delitem(mem->sd(), i, itm->amount, 0, LOG_TYPE_NONE);
					done = true;
				}
			}
		}
		if (done) clif_emotion(mem->bl(), ET_GOODBOY);
	}
	out << "���v" << tot_cou << "���A" <<
		tot_amo << "�̃A�C�e�������܂����B\n";
	show_client(lea->fd(), out.str());
}

// �q�Ɋi�[�A�C�e�����N���A����B
SUBCMD_FUNC(Bot, StoragePutClear) {
	int cou = lea->storage_put_items()->clear();
	show_client(lea->fd(), print(
		cou, "���̑q�Ɋi�[�A�C�e���̓o�^�𖕏����܂����B"
	));
}

// �q�Ɋi�[�A�C�e������荞�ށB
SUBCMD_FUNC(Bot, StoragePutImport) {
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	t_tick hev_tic = lea->next_heaby_tick();
	if (hev_tic)
		throw command_error{print(
			"StoragePutImport�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	auto bot_sto_put_itms = construct<registry_t<int>>(load_storage_put_item_func(bot->char_id()));
	int cou = lea->storage_put_items()->import_(bot_sto_put_itms.get());
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v����", cou,
		"���̑q�Ɋi�[�A�C�e������荞�݂܂����B"
	));
	lea->last_heaby_tick() = now;
}

// Bot�������񂹂�B
SUBCMD_FUNC(Bot, sUmmon) {
	int cou = 0;
	if (args.empty()) {
		for (auto bot : lea->bots()) bot->teleport(&lea->center());
		cou = lea->bots().size();
	} else {
		while (!args.empty()) {
			try {
				block_if* bot = shift_arguments_then_find_bot(lea, args);
				bot->teleport(&lea->center());
				++cou;
			} catch (const command_error&) {}
		}
	}
	show_client(lea->fd(), print(cou, "�l��Bot�������񂹂܂����B"));
}

// �����o�[���ꗗ�\������B
SUBCMD_FUNC(Bot, Team) {
	auto pri_mem = [] (block_if* mem) -> std::string {
		std::stringstream buf;
		buf << INDEX_PREFIX << mem->member_index() << " " <<
		       ID_PREFIX << mem->char_id() << " - "
		       "BLv " << print(std::setw(2), std::setfill('0'), mem->sd()->status.base_level) << " "
		       "JLv " << print(std::setw(2), std::setfill('0'), mem->sd()->status.job_level ) << " "
		       "HP "  << print(std::setw(3), std::setfill('0'), mem->hp_ratio()             ) << "% "
		       "SP "  << print(std::setw(3), std::setfill('0'), mem->sp_ratio()             ) << "% " <<
		       mem->name() << " " <<
		       "<" << job_name(mem->sd()->status.class_) << "> "
		       "Zeny " << print_zeny(mem->sd()->status.zeny) << "\n";
		return buf.str();
	};

	std::stringstream out;
	out << "------ ���݂̃`�[�� ------\n";
	for (block_if* mem : lea->members()) out << pri_mem(mem);
	out << lea->members().size() << "�l�̃����o�[��������܂����B\n";
	show_client(lea->fd(), out.str());
}

// �`�[�������O�C������B
SUBCMD_FUNC(Bot, TeamLogIn) {
	if (!lea->bots().empty())
		throw command_error{"���Ȃ��͂��łɃ`�[����Ґ����Ă��܂��B"};
	t_tick hev_tic = lea->next_heaby_tick();
	if (hev_tic)
		throw command_error{print(
			"TeamLogIn�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	lea->members().clear();
	int num = 0;
	if (!args.empty()) num = shift_arguments_then_parse_int(args, "�`�[���̔ԍ�", 0, TEAM_MAX - 1);
	team_t* tea = lea->teams()->find(num);
	if (tea) {
		for (auto mem : tea->members) {
			if (mem->char_id == lea->char_id()) lea->members().push_back(lea);
			else
				query_login_data(mem->char_id,
					[lea, mem] (int bot_aid, int bot_sex, int bot_gid, int unb_tim, int sta, const std::string& nam) {
						if (!bot_can_enter_server(bot_aid))
							show_client(lea->fd(), print("�u", nam, "�v�͌��݃��O�C���ł��܂���B"));
						else if (unb_tim ||
							sta
						) show_client(lea->fd(), print("�u", nam, "�v�̃A�J�E���g�͒�~����Ă��܂��B"));
						else {
							t_tick bot_res_tic = bot_restart_tick(mem->char_id);
							if (bot_res_tic)
								show_client(lea->fd(), print(
									"�u", nam, "�v��Bot���Ɏ��S���܂����B\n"
									"�Ăу��O�C���ł���悤�ɂȂ�܂ł���", print_tick(bot_res_tic + 1000), "�ł��B\n"
								));
							else {
								map_session_data* bot_sd = bot_login(lea, bot_aid, mem->char_id, bot_sex, bot_gid);
								ptr<block_if> bot = construct<bot_t>(bot_sd, lea);
								lea->bots().push_back(bot);
								lea->members().push_back(bot.get());
							}
						}
					}
				);
		}
	} else lea->members().push_back(lea);
	lea->update_bot_indices();
	lea->update_member_indices();
	lea->last_heaby_tick() = now;
	show_client(lea->fd(), print(lea->bots().size(), "�l��Bot�����O�C�����܂����B"));
}

// �`�[�������O�A�E�g����B
SUBCMD_FUNC(Bot, TeamLogOut) {
	if (lea->bots().empty())
		throw command_error{"���Ȃ��͂܂��`�[����Ґ����Ă��܂���B"};
	save_team(lea, 0);
	lea->stay() = false;
	lea->passive() = false;
	show_client(lea->fd(), print(
		lea->bots().size(), "�l��Bot�����O�A�E�g���܂����B"
	));
	lea->members().clear();
	lea->members().push_back(lea);
	lea->update_member_indices();
	lea->bots().clear();
	lea->last_heaby_tick() = now;
}

// �`�[�����ꗗ�\������A�܂��͓o�^����A�܂��͓o�^�𖕏�����B
SUBCMD_FUNC(Bot, TeamNumber) {
	using tea_val_t = std::pair<int,team_t*>;

	int num_wid = print(TEAM_MAX - 1).length();
	if (args.empty()) {
		std::vector<tea_val_t> tea_vals;
		lea->teams()->copy(pybot::back_inserter(tea_vals));
		std::sort(ALL_RANGE(tea_vals), [lea] (tea_val_t lval, tea_val_t rval) -> bool {
			return lval.first < rval.first;
		});
		std::stringstream out;
		out << "------ �`�[�� ------\n";
		for (tea_val_t tea_val : tea_vals) {
			int num = tea_val.first;
			team_t* tea = tea_val.second;
			out << print(std::setw(num_wid), std::setfill('0'), num) << " - ";
			for (int i = 0; i < tea->members.size(); ++i) {
				auto mem = tea->members[i];
				if (i) out << " / ";
				out << mem->name;
			}
			out << "\n";
		}
		out << tea_vals.size() << "���̃`�[����������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		int num = shift_arguments_then_parse_int(args, "�`�[���̔ԍ�", 1, TEAM_MAX - 1);
		if (lea->bots().empty()) {
			lea->teams()->unregister(num);
			show_client(
				lea->fd(),
				print("�`�[��", num, "�̓o�^�𖕏����܂����B")
			);
		} else {
			save_team(lea, num);
			show_client(
				lea->fd(),
				print("���݂̕Ґ����`�[��", num, "�ɓo�^���܂����B")
			);
		}
	}
}

// �����o�[�̏��Ԃ�ύX����B
SUBCMD_FUNC(Bot, TeamOrder) {
	std::vector<block_if*> mems;
	while (!args.empty()) {
		block_if* mem = shift_arguments_then_find_member(lea, args);
		if (VALUE_EXISTS(mems, mem))
			throw command_error{print(
				"�u", mem->name(), "�v���d�����Ă��܂��B"
			)};
		mems.push_back(mem);
	}
	if (mems.size() != lea->members().size()) 
		throw command_error{print(
			"�����o�[�S��(", lea->members().size(), "�l)���w�肵�Ă��������B"
		)};
	lea->members() = std::move(mems);
	lea->update_member_indices();
	show_client(lea->fd(), "�����o�[�̏��Ԃ�ύX���܂����B");
}

// �`�[���������X�^�[�ɔ������Ȃ��A�܂��͔�������B
SUBCMD_FUNC(Bot, TeamPassive) {
	if (lea->bots().empty())
		throw command_error{"���Ȃ��͂܂��`�[����Ґ����Ă��܂���B"};
	lea->passive() = !lea->passive();
	if (lea->passive())
		show_client(lea->fd(), "���Ȃ��̃`�[���̓����X�^�[�ɔ������܂���B");
	else show_client(lea->fd(), "���Ȃ��̃`�[���̓����X�^�[�ɔ������܂��B");
}

// ���b�V�����[�h�ɂȂ�A�܂��͉�������B
SUBCMD_FUNC(Bot, TeamRush) {
	lea->rush()->set(!lea->rush()->get());
	if (lea->rush()->get()) show_client(lea->fd(), print(
		"���Ȃ��̃`�[���̓��b�V�����[�h�ɂȂ�܂����B"
	));
	else show_client(lea->fd(), print(
		"���Ȃ��̃`�[���̓��b�V�����[�h���������܂����B"
	));
}

// �`�[�����ҋ@�A�܂��͒Ǐ]����B
SUBCMD_FUNC(Bot, TeamStay) {
	if (lea->bots().empty())
		throw command_error{"���Ȃ��͂܂��`�[����Ґ����Ă��܂���B"};
	lea->stay() = !lea->stay();
	if (lea->stay())
		show_client(lea->fd(), "���Ȃ��̃`�[���͂��̏�őҋ@���܂��B");
	else show_client(lea->fd(), "���Ȃ��̃`�[���͂��Ȃ���ǂ������܂��B");
}

// Bot���A�C�e��������ɒǉ�����B
SUBCMD_FUNC(Bot, TradeItem) {
	block_if* bot = check_trade_with_bot(lea, args);
	std::string itm_nam = shift_arguments(
		args, "�A�C�e�����w�肵�Ă��������B"
	);
	int itm_ind = bot->find_inventory(itm_nam);
	if (itm_ind == INT_MIN)
		throw command_error{print(
			"�u", bot->name(), "�v�́u", itm_nam, "�v���������Ă��܂���B"
		)};
	item* itm = &bot->sd()->inventory.u.items_inventory[itm_ind];
	if (itm->equip)
		throw command_error{print(
			"�u", bot->name(), "�v�́u", itm_nam, "�v�𑕔����Ă��܂��B"
		)};
	int amo = itm->amount;
	if (!args.empty()) amo = shift_arguments_then_parse_int(
		args, "���̃A�C�e���̌�", 1, amo
	);
	std::string itm_str = print_item(itm, bot->sd()->inventory_data[itm_ind], amo);
	if (!trade_tradeadditem(bot->sd(), itm_ind + 2, amo))
		throw command_error{print(
			"�u", bot->name(), "�v�́u",
			itm_str, "�v������ɒǉ��ł��܂���B"
		)};
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v�́u",
		itm_str, "�v������ɒǉ����܂����B"
	));
}

// Bot��Zeny������ɒǉ�����B
SUBCMD_FUNC(Bot, TradeZeny) {
	block_if* bot = check_trade_with_bot(lea, args);
	int amo = bot->sd()->status.zeny;
	if (!args.empty()) amo = shift_arguments_then_parse_int(
		args, "���z", 1, amo
	);
	int old_dea_zen = bot->sd()->deal.zeny;
	trade_tradeaddzeny(bot->sd(), amo);
	if (bot->sd()->deal.zeny == old_dea_zen)
		throw command_error{print(
			"�u", bot->name(), "�v��", amo,
			"Zeny������ɒǉ��ł��܂���B"
		)};
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v��", amo,
		"Zeny������ɒǉ����܂����B"
	));
}

// �����o�[�����[�v�ʒu���ꗗ�\���A�܂��̓��[�v�|�[�^�����J���B
SUBCMD_FUNC(Bot, Warp) {
	auto pri_poi = [] (int ind, point* poi) -> std::string {
		return print(
			INDEX_PREFIX, ind, " - ",
			id_maps.at(map_mapindex2mapid(poi->map))->name_japanese,
			" (", mapindex_id2name(poi->map), ") : ",
			poi->x, ", ", poi->y, "\n"
		);
	};
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int war_lv = mem->check_skill(AL_WARP);
	if (!war_lv)
		throw command_error{print(
			"�u", mem->name(), "�v�́u",
			skill_get_desc(AL_WARP), "�v���g���܂���B"
		)};
	if (args.empty()) {
		std::stringstream out;
		out << "------ �u" <<	mem->name() << "�v�̃��[�v�ʒu ------\n";
		out << pri_poi(0, &mem->sd()->status.save_point);
		int cou = 1;
		for (int i = 0; i < MAX_MEMOPOINTS; ++i) {
			point* poi = &mem->sd()->status.memo_point[i];
			if (poi->map) {
				out << pri_poi(1 + i, poi);
				++cou;
			}
		}
		out << cou << "���̃��[�v�ʒu��������܂����B\n";
		show_client(lea->fd(), out.str());
	} else {
		if (mem == lea)
			throw command_error{print(
				"�����Łu", skill_get_desc(AL_WARP), "�v���g���Ă��������B"
			)};
		if (!mem->can_use_skill(AL_WARP, war_lv))
			throw command_error{print(
				"�u", mem->name(), "�v�͌��݁u",
				skill_get_desc(AL_WARP), "�v���g���܂���B"
			)};
		int mind = 0;
		int max_mem;
		ARR_FIND(0, MAX_MEMOPOINTS, max_mem, !mem->sd()->status.memo_point[max_mem].map);
		std::string war_loc_str = shift_arguments(
			args, "���[�v�ʒu���w�肵�Ă��������B"
		);
		int i = parse_index(war_loc_str);
		if (i == -1) {
			std::string lc_war_loc_str = pybot::lowercase(war_loc_str);
			for (int j = 0; j <= max_mem; ++j) {
				int mind2;
				if (j) mind2 = mem->sd()->status.memo_point[j - 1].map;
				else mind2 = mem->sd()->status.save_point.map;
				auto map = id_maps.at(map_mapindex2mapid(mind2));
				if (pybot::lowercase(map->name_english) == lc_war_loc_str ||
					pybot::lowercase(map->name_japanese) == lc_war_loc_str
				) {
					mind = mind2;
					break;
				}
			}
		} else if (i <= max_mem) {
			if (i) mind = mem->sd()->status.memo_point[i - 1].map;
			else mind = mem->sd()->status.save_point.map;
		}
		if (!mind) throw command_error{print(
			"�u", war_loc_str, "�v�Ƃ������[�v�ʒu�͂���܂���B"
		)};
		int16_t x, y;
		if (!map_search_freecell(lea->bl(), 0, &x, &y, 1, 1, 0))
			throw command_error{print(
				"���Ȃ��̎��͂ɋ󂢂Ă���Z��������܂���B"
			)};
		if (mem->is_sit()) mem->stand();
		mem->use_skill_xy(AL_WARP, war_lv, x, y, false, [mind] (ai_t* ai, void* fun) {
			skill_castend_map(ai->bot->sd(), AL_WARP, mapindex_id2name(mind));
		});
		show_client(
			lea->fd(),
			print("�u", mem->name(), "�v��"
				"�u", id_maps.at(map_mapindex2mapid(mind))->name_japanese,
				" (", mapindex_id2name(mind), ")�v"
				"�ւ̃��[�v�|�[�^�����J���܂��B"
			)
		);
	}
}

// Bot�̐����l�����擾����B
int // �擾�����l���B
bot_limit(
	map_session_data* sd // �Z�b�V�����f�[�^�B
) {
	static const std::string CAS_TRI_PRO = "CASTLE_TRIAL_PROG";
	static const std::string ALDE_GLD    = "alde_gld";
	static const std::string GEF_FILD13  = "gef_fild13";
	static const std::string PAY_GLD     = "pay_gld";
	static const std::string PRT_GLD     = "prt_gld";
	static const std::string SCH_GLD     = "sch_gld";
	static const std::string ARU_GLD     = "aru_gld";

	int lim = pybot::find_map_data(JOB_BOT_LIMITS, e_job(sd->status.class_), 0);
	if (pc_is_maxbaselv(sd)) ++lim;
	if (pc_readglobalreg(sd, add_str((CAS_TRI_PRO + "_" + ALDE_GLD  ).c_str())) &&
		pc_readglobalreg(sd, add_str((CAS_TRI_PRO + "_" + GEF_FILD13).c_str())) &&
		pc_readglobalreg(sd, add_str((CAS_TRI_PRO + "_" + PAY_GLD   ).c_str())) &&
		pc_readglobalreg(sd, add_str((CAS_TRI_PRO + "_" + PRT_GLD   ).c_str()))
	) ++lim;
	if (pc_readglobalreg(sd, add_str((CAS_TRI_PRO + "_" + SCH_GLD   ).c_str()))) ++lim;
	if (pc_readglobalreg(sd, add_str((CAS_TRI_PRO + "_" + ARU_GLD   ).c_str()))) ++lim;
	return lim;
}

// Bot�����O�C������B
map_session_data* // ���O�C������Bot�̃Z�b�V�����f�[�^�B
bot_login(
	block_if* lea, // ���[�_�[�B
	int bot_aid,   // Bot�̃A�J�E���gID�B
	int bot_cid,   // Bot�̃L�����N�^�[ID�B
	int bot_sex,   // Bot�̐��ʁB
	int bot_gid    // Bot�̃O���[�vID�B
) {
	map_session_data* sd;
	sql_session::open([lea, bot_aid, bot_cid, bot_sex, bot_gid, &sd] (sql_session* ses) {
		int fd = pybot_connect_bot();
		scope_exit fd_exi{[fd] () {
			do_close(fd);
		}};
		CREATE(sd, TBL_PC, 1);
		session[fd]->session_data = sd;

		sd->client_tick = now;
		sd->fd = fd;
		sd->group_id = bot_gid;
		sd->login_id1 = sd->login_id2 = 0;
		sd->base_status.speed = sd->battle_status.speed = DEFAULT_WALK_SPEED;
		sd->bl.id = bot_aid;
		sd->bl.type = BL_PC;
		sd->state.active = 0;
		sd->status.account_id = bot_aid;
		sd->status.char_id = bot_cid;
		sd->status.sex = bot_sex;

		auto set_map = [] (point* poi, const char* nam) {
			poi->map = mapindex_name2id(nam);
			if (!poi->map) *poi = point{mapindex_name2id(MAP_PRONTERA), 156, 191};
		};

		char las_map[MAP_NAME_LENGTH_EXT];
		char sav_map[MAP_NAME_LENGTH_EXT];
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("char_num"          , sd->status.slot              ), "`,"
			" `", construct<sql_column>("name"              , sd->status.name              ), "`,"
			" `", construct<sql_column>("class"             , sd->status.class_            ), "`,"
			" `", construct<sql_column>("base_level"        , sd->status.base_level        ), "`,"
			" `", construct<sql_column>("job_level"         , sd->status.job_level         ), "`,"
			" `", construct<sql_column>("base_exp"          , sd->status.base_exp          ), "`,"
			" `", construct<sql_column>("job_exp"           , sd->status.job_exp           ), "`,"
			" `", construct<sql_column>("zeny"              , sd->status.zeny              ), "`,"
			" `", construct<sql_column>("str"               , sd->status.str               ), "`,"
			" `", construct<sql_column>("agi"               , sd->status.agi               ), "`,"
			" `", construct<sql_column>("vit"               , sd->status.vit               ), "`,"
			" `", construct<sql_column>("int"               , sd->status.int_              ), "`,"
			" `", construct<sql_column>("dex"               , sd->status.dex               ), "`,"
			" `", construct<sql_column>("luk"               , sd->status.luk               ), "`,"
			" `", construct<sql_column>("max_hp"            , sd->status.max_hp            ), "`,"
			" `", construct<sql_column>("hp"                , sd->status.hp                ), "`,"
			" `", construct<sql_column>("max_sp"            , sd->status.max_sp            ), "`,"
			" `", construct<sql_column>("sp"                , sd->status.sp                ), "`,"
			" `", construct<sql_column>("status_point"      , sd->status.status_point      ), "`,"
			" `", construct<sql_column>("skill_point"       , sd->status.skill_point       ), "`,"
			" `", construct<sql_column>("option"            , sd->status.option            ), "`,"
			" `", construct<sql_column>("karma"             , sd->status.karma             ), "`,"
			" `", construct<sql_column>("manner"            , sd->status.manner            ), "`,"
			" `", construct<sql_column>("party_id"          , sd->status.party_id          ), "`,"
			" `", construct<sql_column>("guild_id"          , sd->status.guild_id          ), "`,"
			" `", construct<sql_column>("pet_id"            , sd->status.pet_id            ), "`,"
			" `", construct<sql_column>("homun_id"          , sd->status.hom_id            ), "`,"
			" `", construct<sql_column>("elemental_id"      , sd->status.ele_id            ), "`,"
			" `", construct<sql_column>("hair"              , sd->status.hair              ), "`,"
			" `", construct<sql_column>("hair_color"        , sd->status.hair_color        ), "`,"
			" `", construct<sql_column>("clothes_color"     , sd->status.clothes_color     ), "`,"
			" `", construct<sql_column>("body"              , sd->status.body              ), "`,"
			" `", construct<sql_column>("weapon"            , sd->status.weapon            ), "`,"
			" `", construct<sql_column>("shield"            , sd->status.shield            ), "`,"
			" `", construct<sql_column>("head_top"          , sd->status.head_top          ), "`,"
			" `", construct<sql_column>("head_mid"          , sd->status.head_mid          ), "`,"
			" `", construct<sql_column>("head_bottom"       , sd->status.head_bottom       ), "`,"
			" `", construct<sql_column>("last_map"          , las_map                      ), "`,"
			" `", construct<sql_column>("last_x"            , sd->status.last_point.x      ), "`,"
			" `", construct<sql_column>("last_y"            , sd->status.last_point.y      ), "`,"
			" `", construct<sql_column>("save_map"          , sav_map                      ), "`,"
			" `", construct<sql_column>("save_x"            , sd->status.save_point.x      ), "`,"
			" `", construct<sql_column>("save_y"            , sd->status.save_point.y      ), "`,"
			" `", construct<sql_column>("partner_id"        , sd->status.partner_id        ), "`,"
			" `", construct<sql_column>("father"            , sd->status.father            ), "`,"
			" `", construct<sql_column>("mother"            , sd->status.mother            ), "`,"
			" `", construct<sql_column>("child"             , sd->status.child             ), "`,"
			" `", construct<sql_column>("fame"              , sd->status.fame              ), "`,"
			" `", construct<sql_column>("rename"            , sd->status.rename            ), "`,"
			" `", construct<sql_column>("delete_date"       , sd->status.delete_date       ), "`,"
			" `", construct<sql_column>("robe"              , sd->status.robe              ), "`,"
			" `", construct<sql_column>("moves"             , sd->status.character_moves   ), "`,"
			" `", construct<sql_column>("unban_time"        , sd->status.unban_time        ), "`,"
			" `", construct<sql_column>("font"              , sd->status.font              ), "`,"
			" `", construct<sql_column>("uniqueitem_counter", sd->status.uniqueitem_counter), "`,"
			" `", construct<sql_column>("hotkey_rowshift"   , sd->status.hotkey_rowshift   ), "`,"
			" `", construct<sql_column>("clan_id"           , sd->status.clan_id           ), "`,"
			" `", construct<sql_column>("title_id"          , sd->status.title_id          ), "`,"
			" `", construct<sql_column>("show_equip"        , sd->status.show_equip        ), "` "
			"FROM `char` "
			"WHERE `char_id` = ", construct<sql_param>(sd->status.char_id), " "
			"LIMIT 1"
		);
		if (!ses->next_row()) RAISE_RUNTIME_ERROR("Cann't found char.");
		set_map(&sd->status.last_point, las_map);
		set_map(&sd->status.save_point, sav_map);

		char mem_map[MAP_NAME_LENGTH_EXT];
		point mem_poi{};
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("map", mem_map), "`,"
			" `", construct<sql_column>("x", mem_poi.x), "`,"
			" `", construct<sql_column>("y", mem_poi.y), "` "
			"FROM `memo` "
			"WHERE `char_id` = ", construct<sql_param>(sd->status.char_id), " "
			"ORDER BY `memo_id`"
		);
		for (int i = 0; ses->next_row(); ++i) {
			set_map(&mem_poi, mem_map);
			sd->status.memo_point[i] = mem_poi;
		}

		s_skill sk{};
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("id"  , sk.id)  , "`,"
			" `", construct<sql_column>("lv"  , sk.lv)  , "`,"
			" `", construct<sql_column>("flag", sk.flag), "` "
			"FROM `skill` "
			"WHERE `char_id` = ", construct<sql_param>(sd->status.char_id)
		);
		for (int i = 0; ses->next_row(); ++i)
			sd->status.skill[i] = sk;

		pc_group_pc_load(sd);
		sd->class_ = pc_jobid2mapid(sd->status.class_);
		sd->state.connect_new = 1;
		sd->followtimer = INVALID_TIMER;
		sd->invincible_timer = INVALID_TIMER;
		sd->npc_timer_id = INVALID_TIMER;
		sd->pvp_timer = INVALID_TIMER;
		sd->expiration_tid = INVALID_TIMER;
		sd->autotrade_tid = INVALID_TIMER;
#ifdef SECURE_NPCTIMEOUT
		sd->npc_idle_timer = INVALID_TIMER;
		sd->npc_idle_tick = now;
		sd->npc_idle_type = NPCT_INPUT;
		sd->state.ignoretimeout = false;
#endif
		sd->canuseitem_tick = now;
		sd->canusecashfood_tick = now;
		sd->canequip_tick = now;
		sd->cantalk_tick = now;
		sd->canskill_tick = now;
		sd->cansendmail_tick = now;
		sd->idletime = last_tick;
		for (int i = 0; i < MAX_SPIRITBALL; i++)
			sd->spirit_timer[i] = INVALID_TIMER;
		for (int i = 0; i < ARRAYLENGTH(sd->autobonus); i++)
			sd->autobonus[i].active = INVALID_TIMER;
		for (int i = 0; i < ARRAYLENGTH(sd->autobonus2); i++)
			sd->autobonus2[i].active = INVALID_TIMER;
		for (int i = 0; i < ARRAYLENGTH(sd->autobonus3); i++)
			sd->autobonus3[i].active = INVALID_TIMER;
		if (battle_config.item_auto_get) sd->state.autoloot = 10000;
		if (battle_config.disp_experience) sd->state.showexp = 1;
		if (battle_config.disp_zeny) sd->state.showzeny = 1;
#ifdef VIP_ENABLE
		if (!battle_config.vip_disp_rate)
			sd->vip.disableshowrate = 1;
#endif
		if (!(battle_config.display_skill_fail & 2)) sd->state.showdelay = 1;
		std::memset(&sd->inventory, 0, sizeof(s_storage));
		std::memset(&sd->cart, 0, sizeof(s_storage));
		std::memset(&sd->storage, 0, sizeof(s_storage));
		std::memset(&sd->premiumStorage, 0, sizeof(s_storage));
		std::memset(&sd->equip_index, -1, sizeof(sd->equip_index));
		if (pc_isinvisible(sd) &&
			!pc_can_use_command(sd, "hide", COMMAND_ATCOMMAND)
		) sd->status.option &= ~OPTION_INVISIBLE;
		status_change_init(&sd->bl);
		sd->sc.option = sd->status.option;
		unit_dataset(&sd->bl);
		sd->guild_x = sd->guild_y = -1;
		sd->delayed_damage = 0;
		for (int i = 0; i < MAX_EVENTTIMER; i++)
			sd->eventtimer[i] = INVALID_TIMER;
		sd->rental_timer = INVALID_TIMER;
		for (int i = 0; i < 3; i++)
			sd->hate_mob[i] = -1;
		sd->quest_log = nullptr;
		sd->num_quests = 0;
		sd->avail_quests = 0;
		sd->save_quest = false;
		sd->count_rewarp = 0;
		sd->regs.vars = i64db_alloc(DB_OPT_BASE);
		sd->regs.arrays = nullptr;
		sd->vars_dirty = false;
		sd->vars_ok = false;
		sd->vars_received = 0x0;
		sd->qi_display = nullptr;
		sd->qi_count = 0;

		if (pc_setpos(sd, sd->status.last_point.map, sd->status.last_point.x, sd->status.last_point.y, CLR_OUTSIGHT, true) != SETPOS_OK &&
			pc_setpos(sd, mapindex_name2id(MAP_PRONTERA), 273, 354, CLR_OUTSIGHT, true) != SETPOS_OK
		) RAISE_RUNTIME_ERROR("Failed pc_setpos.");

		sd->die_counter = -1;
		pc_validate_skill(sd);
		sd->sc_display = nullptr;
		sd->sc_display_count = 0;
		sd->status.cashshop_sent = false;
		sd->last_addeditem_index = -1;
		sd->bonus_script.head = nullptr;
		sd->bonus_script.count = 0;
#if PACKETVER >= 20150513
		sd->hatEffectIDs = NULL;
		sd->hatEffectCount = 0;
#endif
		sd->catch_target_class = PET_CATCH_FAIL;

		{
			pc_set_reg_load(true);
			scope_exit reg_loa_exi{[] () {
				pc_set_reg_load(false);
			}};
			unsigned int reg_idx, reg_num;
			char reg_key[32], reg_str[254];
			ses->execute(
				"SELECT"
				" `", construct<sql_column>("key"  , reg_key), "`,"
				" `", construct<sql_column>("index", reg_idx), "`,"
				" `", construct<sql_column>("value", reg_str), "` "
				"FROM `char_reg_str` "
				"WHERE `char_id` = ", construct<sql_param>(sd->status.char_id)
			);
			while (ses->next_row())
				set_reg(nullptr, sd, reference_uid(add_str(reg_key), reg_idx), reg_key, (void*)(reg_str), nullptr);
			ses->execute(
				"SELECT"
				" `", construct<sql_column>("key"  , reg_key), "`,"
				" `", construct<sql_column>("index", reg_idx), "`,"
				" `", construct<sql_column>("value", reg_num), "` "
				"FROM `char_reg_num` "
				"WHERE `char_id` = ", construct<sql_param>(sd->status.char_id)
			);
			while (ses->next_row())
				set_reg(nullptr, sd, reference_uid(add_str(reg_key), reg_idx), reg_key, (void*)__64BPRTSIZE(reg_num), nullptr);
		}
		sd->vars_ok = true;

		sd->state.active = 1;
		sd->state.pc_loaded = false;
		if (sd->status.party_id) party_member_joined(sd);
		if (sd->status.guild_id) guild_member_joined(sd);
		if (sd->status.clan_id) clan_member_joined(sd);

		// Bot�̃y�b�g���s����Ȃ��߁A�b��I�ɖ����ɂ���B
		//if (sd->status.pet_id > 0) intif_request_petdata(sd->status.account_id, sd->status.char_id, sd->status.pet_id);

		if (sd->status.hom_id > 0) intif_homunculus_requestload(sd->status.account_id, sd->status.hom_id);
		map_addiddb(&sd->bl);
		map_delnickdb(sd->status.char_id, sd->status.name);
		scope_exit map_id_exi{[sd] () {
			map_deliddb(&sd->bl);
		}};

		sd->inventory.id = sd->status.char_id;
		sd->inventory.type = TABLE_INVENTORY;
		sd->inventory.stor_id = 0;
		sd->inventory.max_amount = MAX_INVENTORY;
		item itm{};
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("id"          , itm.id             ), "`,"
			" `", construct<sql_column>("nameid"      , itm.nameid         ), "`,"
			" `", construct<sql_column>("amount"      , itm.amount         ), "`,"
			" `", construct<sql_column>("equip"       , itm.equip          ), "`,"
			" `", construct<sql_column>("identify"    , itm.identify       ), "`,"
			" `", construct<sql_column>("refine"      , itm.refine         ), "`,"
			" `", construct<sql_column>("attribute"   , itm.attribute      ), "`,"
			" `", construct<sql_column>("expire_time" , itm.expire_time    ), "`,"
			" `", construct<sql_column>("bound"       , itm.bound          ), "`,"
			" `", construct<sql_column>("unique_id"   , itm.unique_id      ), "`,"
			" `", construct<sql_column>("favorite"    , itm.favorite       ), "`,"
			" `", construct<sql_column>("card0"       , itm.card[0]        ), "`,"
			" `", construct<sql_column>("card1"       , itm.card[1]        ), "`,"
			" `", construct<sql_column>("card2"       , itm.card[2]        ), "`,"
			" `", construct<sql_column>("card3"       , itm.card[3]        ), "`,"
			" `", construct<sql_column>("option_id0"  , itm.option[0].id   ), "`,"
			" `", construct<sql_column>("option_val0" , itm.option[0].value), "`,"
			" `", construct<sql_column>("option_parm0", itm.option[0].param), "`,"
			" `", construct<sql_column>("option_id1"  , itm.option[1].id   ), "`,"
			" `", construct<sql_column>("option_val1" , itm.option[1].value), "`,"
			" `", construct<sql_column>("option_parm1", itm.option[1].param), "`,"
			" `", construct<sql_column>("option_id2"  , itm.option[2].id   ), "`,"
			" `", construct<sql_column>("option_val2" , itm.option[2].value), "`,"
			" `", construct<sql_column>("option_parm2", itm.option[2].param), "`,"
			" `", construct<sql_column>("option_id3"  , itm.option[3].id   ), "`,"
			" `", construct<sql_column>("option_val3" , itm.option[3].value), "`,"
			" `", construct<sql_column>("option_parm3", itm.option[3].param), "`,"
			" `", construct<sql_column>("option_id4"  , itm.option[4].id   ), "`,"
			" `", construct<sql_column>("option_val4" , itm.option[4].value), "`,"
			" `", construct<sql_column>("option_parm4", itm.option[4].param), "` "
			"FROM `inventory` "
			"WHERE `char_id` = ", construct<sql_param>(sd->status.char_id), " "
			"ORDER BY `nameid`"
		);
		for (sd->inventory.amount = 0; ses->next_row(); ++sd->inventory.amount)
			sd->inventory.u.items_inventory[sd->inventory.amount] = itm;

		sd->cart.id = sd->status.char_id;
		sd->cart.type = TABLE_CART;
		sd->cart.stor_id = 0;
		sd->cart.max_amount = MAX_CART;
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("id"          , itm.id             ), "`,"
			" `", construct<sql_column>("nameid"      , itm.nameid         ), "`,"
			" `", construct<sql_column>("amount"      , itm.amount         ), "`,"
			" `", construct<sql_column>("equip"       , itm.equip          ), "`,"
			" `", construct<sql_column>("identify"    , itm.identify       ), "`,"
			" `", construct<sql_column>("refine"      , itm.refine         ), "`,"
			" `", construct<sql_column>("attribute"   , itm.attribute      ), "`,"
			" `", construct<sql_column>("expire_time" , itm.expire_time    ), "`,"
			" `", construct<sql_column>("bound"       , itm.bound          ), "`,"
			" `", construct<sql_column>("unique_id"   , itm.unique_id      ), "`,"
			" `", construct<sql_column>("card0"       , itm.card[0]        ), "`,"
			" `", construct<sql_column>("card1"       , itm.card[1]        ), "`,"
			" `", construct<sql_column>("card2"       , itm.card[2]        ), "`,"
			" `", construct<sql_column>("card3"       , itm.card[3]        ), "`,"
			" `", construct<sql_column>("option_id0"  , itm.option[0].id   ), "`,"
			" `", construct<sql_column>("option_val0" , itm.option[0].value), "`,"
			" `", construct<sql_column>("option_parm0", itm.option[0].param), "`,"
			" `", construct<sql_column>("option_id1"  , itm.option[1].id   ), "`,"
			" `", construct<sql_column>("option_val1" , itm.option[1].value), "`,"
			" `", construct<sql_column>("option_parm1", itm.option[1].param), "`,"
			" `", construct<sql_column>("option_id2"  , itm.option[2].id   ), "`,"
			" `", construct<sql_column>("option_val2" , itm.option[2].value), "`,"
			" `", construct<sql_column>("option_parm2", itm.option[2].param), "`,"
			" `", construct<sql_column>("option_id3"  , itm.option[3].id   ), "`,"
			" `", construct<sql_column>("option_val3" , itm.option[3].value), "`,"
			" `", construct<sql_column>("option_parm3", itm.option[3].param), "`,"
			" `", construct<sql_column>("option_id4"  , itm.option[4].id   ), "`,"
			" `", construct<sql_column>("option_val4" , itm.option[4].value), "`,"
			" `", construct<sql_column>("option_parm4", itm.option[4].param), "` "
			"FROM `cart_inventory` "
			"WHERE `char_id` = ", construct<sql_param>(sd->status.char_id), " "
			"ORDER BY `nameid`"
		);
		for (sd->cart.amount = 0; ses->next_row(); ++sd->cart.amount)
			sd->cart.u.items_cart[sd->cart.amount] = itm;

		pc_setinventorydata(sd);
		pc_setequipindex(sd);
		pc_check_expiration(sd);
		pc_check_available_item(sd, ITMCHK_INVENTORY);
		pc_itemcd_do(sd, true);
#ifdef BOUND_ITEMS
		if (!sd->status.party_id) {
			int idxlist[MAX_INVENTORY];
			int j = pc_bound_chk(sd, BOUND_PARTY, idxlist);
			for (int i = 0; i < j; i++)
				pc_delitem(sd, idxlist[i], sd->inventory.u.items_inventory[idxlist[i]].amount, 4, 1, LOG_TYPE_OTHER);
		}
#endif
		status_set_viewdata(&sd->bl, sd->status.class_);
		pc_load_combo(sd);
		status_calc_pc(sd, e_status_calc_opt(SCO_FIRST | SCO_FORCE));
		status_calc_weight(sd, e_status_calc_weight_opt(CALCWT_ITEM | CALCWT_MAXBONUS));
		pc_check_available_item(sd, ITMCHK_CART);

		status_change_data sc_dat{};
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("type", sc_dat.type), "`,"
			" `", construct<sql_column>("tick", sc_dat.tick), "`,"
			" `", construct<sql_column>("val1", sc_dat.val1), "`,"
			" `", construct<sql_column>("val2", sc_dat.val2), "`,"
			" `", construct<sql_column>("val3", sc_dat.val3), "`,"
			" `", construct<sql_column>("val4", sc_dat.val4), "` "
			"FROM `sc_data` "
			"WHERE"
			" `account_id` = ", construct<sql_param>(sd->status.account_id), " AND"
			" `char_id` = "   , construct<sql_param>(sd->status.char_id   )
		);
		while (ses->next_row())
			status_change_start(
				nullptr,
				&sd->bl,
				sc_type(sc_dat.type),
				10000,
				sc_dat.val1,
				sc_dat.val2,
				sc_dat.val3,
				sc_dat.val4,
				sc_dat.tick,
				SCSTART_NOAVOID | SCSTART_NOTICKDEF | SCSTART_LOADED | SCSTART_NORATEDEF
			);

		skill_cooldown_data skc_dat{};
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("skill", skc_dat.skill_id), "`,"
			" `", construct<sql_column>("tick" , skc_dat.tick    ), "` "
			"FROM `skillcooldown` "
			"WHERE"
			" `account_id` = ", construct<sql_param>(sd->status.account_id), " AND"
			" `char_id` = "   , construct<sql_param>(sd->status.char_id   )
		);
		while (ses->next_row())
			skill_blockpc_start(sd, skc_dat.skill_id, skc_dat.tick);

		bonus_script_data bs_dat{};
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("script", bs_dat.script_str), "`,"
			" `", construct<sql_column>("tick"  , bs_dat.tick      ), "`,"
			" `", construct<sql_column>("flag"  , bs_dat.flag      ), "`,"
			" `", construct<sql_column>("type"  , bs_dat.type      ), "`,"
			" `", construct<sql_column>("icon"  , bs_dat.icon      ), "` "
			"FROM `bonus_script` "
			"WHERE `char_id` = ", construct<sql_param>(sd->status.char_id)
		);
		while (ses->next_row()) {
			if (!bs_dat.script_str[0] ||
				!bs_dat.tick
			) continue;
			s_bonus_script_entry* entry = pc_bonus_script_add(
				sd,
				bs_dat.script_str,
				bs_dat.tick,
				efst_types(bs_dat.icon),
				bs_dat.flag,
				bs_dat.type
			);
			if (!entry) continue;
			linkdb_insert(&sd->bonus_script.head, (void*)(intptr_t(entry)), entry);
		}
		if (sd->bonus_script.head) status_calc_pc(sd, SCO_NONE);
		ses->execute(
			"DELETE "
			"FROM `bonus_script` "
			"WHERE `char_id` = ", construct<sql_param>(sd->status.char_id)
		);

		if (lea->sd()->status.party_id &&
			sd->status.party_id != lea->sd()->status.party_id
		) {
			party_data* pd = party_search(lea->sd()->status.party_id);
			if (pd) {
				int i, j, k;
				ARR_FIND(0, MAX_PARTY, i, pd->party.member[i].account_id == bot_aid);
				ARR_FIND(0, MAX_PARTY, j, !pd->party.member[j].account_id);
				ARR_FIND(0, MAX_PARTY, k, pd->data[k].sd == lea->sd());
				if (i == MAX_PARTY &&
					j != MAX_PARTY &&
					k != MAX_PARTY &&
					pd->party.member[k].leader
				) {
					if (sd->status.party_id) party_leave(sd);
					sd->party_joining = true;
					sd->party_invite = lea->sd()->status.party_id;
					sd->party_invite_account = lea->sd()->status.account_id;
					party_member par_mem{};
  					par_mem.account_id = sd->status.account_id;
					par_mem.char_id = sd->status.char_id;
					safestrncpy(par_mem.name, sd->status.name, NAME_LENGTH);
					par_mem.class_  = sd->status.class_;
					par_mem.map = sd->mapindex;
					par_mem.lv = sd->status.base_level;
					par_mem.online = 1;
					intif_party_addmember(sd->party_invite, &par_mem);
				}
			}
		}

		sd->state.pc_loaded = true;
		clif_parse_LoadEndAck(fd, sd);

		map_id_exi.do_ = nullptr;
		fd_exi.do_ = nullptr;
	});
	return sd;
}

// Bot�����X�^�[�g�ł���悤�ɂȂ�܂ł̃`�b�N���擾����B
t_tick // �擾�����`�b�N�B
bot_restart_tick(
	int cid // �L�����N�^�[ID�B
) {
	t_tick res_tic = 0;
	auto dea_tic_ite = bot_dead_ticks.find(cid);
	if (dea_tic_ite != bot_dead_ticks.end()) {
		t_tick dea_tic = dea_tic_ite->second;
		res_tic = DIFF_TICK(dea_tic + battle_config.pybot_restart_cool_time, now);
		if (res_tic < 0) res_tic = 0;
	}
	return res_tic;
}

// Bot�Ƃ̎�����`�F�b�N����B
block_if* // ������Ă���Bot�B
check_trade_with_bot(
	block_if* lea,              // ���[�_�[�B
	command_argument_list& args // �����̃��X�g�B
) {
	if (!lea->sd()->state.trading)
		throw command_error{"���Ȃ��͎�����Ă��܂���B"};
	map_session_data* par_sd = map_id2sd(lea->sd()->trade_partner);
	block_if* bot = find_map_data(all_bots, par_sd->status.char_id);
	if (!bot ||
		bot->leader() != lea
	) throw command_error{print(
		"�u", par_sd->status.name, "�v�͂��Ȃ���Bot�ł͂���܂���B"
	)};
	if (bot->sd()->state.deal_locked)
		throw command_error{"����͂��łɃ��b�N����Ă��܂��B"};
	return bot;
}

// NPC�����݂��邩�𒲂ׂ�B
bool // ���ʁB
npc_exists(
	block_list* cen,           // ���S�B
	int rad,                   // ���a�B
	npc_subtype typ,           // �^�C�v�B
	const std::string& dis_nam // �\�����B����ۂȂ�`�F�b�N���Ȃ��B
) {
	yield_bl_func yie_npc = [cen, rad, typ, &dis_nam] (block_list* bl) -> int {
		npc_data* npc = (npc_data*)(bl);
		return check_distance_client_bl(&npc->bl, cen, rad) &&
			npc->subtype == typ &&
			(dis_nam.empty() ||
				npc_display_name(npc->name) == dis_nam
			);
	};
	return map_foreachinallrange(
		callback_yield_bl,
		cen,
		rad,
		BL_NPC,
		&yie_npc
	);
}

// �����o�[�̑q�ɂ̃A�C�e���ꗗ�������B
std::string print_storage(
	block_if* mem,       // �����o�[�B
	storage_type sto_typ // �q�Ƀ^�C�v�B
) {
	item* itms;
	item_data** idbs = nullptr;
	int siz;
	if (sto_typ == TABLE_INVENTORY) {
		itms = mem->sd()->inventory.u.items_inventory;
		idbs = mem->sd()->inventory_data;
		siz = MAX_INVENTORY;
	} else if (sto_typ == TABLE_CART) {
		itms = mem->sd()->cart.u.items_cart;
		siz = MAX_CART;
	} else return UNKNOWN_SYMBOL;
	int ind_wid = print(siz - 1).length();
	std::stringstream out;
	out << "------ �u" << mem->name() << "�v��" <<
		STORAGE_TYPE_NAME_TABLE[sto_typ - TABLE_INVENTORY] << " ------\n";
	int cou = 0;
	for (int i = 0; i < siz; ++i) {
		item* itm = &itms[i];
		if (itm->nameid) {
			int nid = itm->nameid;
			if (itm->card[0] == CARD0_CREATE &&
				pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST)
			) nid += FAME_OFFSET;
			out << INDEX_PREFIX << print(std::setw(ind_wid), std::setfill('0'), i) << " " <<
				ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - ";
			item_data* idb;
			if (idbs) idb = idbs[i];
			else idb = itemdb_exists(itm->nameid);
			if (idb) {
				out << print_item(itm, idb);
				if ((idb->equip &&
						idb->type != IT_CARD
					) || idb->type == IT_PETARMOR
				) {
					out << " (" << print_equip_type(idb);
					if (itm->equip) out << "@" << print_equip_pos(equip_pos(itm->equip));
					out << ")";
				}
			} else out << UNKNOWN_SYMBOL;
			out << "\n";
			++cou;
		}
	}
	out << print(cou, "���̃A�C�e����������܂����B\n");
	return out.str();
}

// �N���C�A���g��@Bot�R�}���h�̃T�u�R�}���h�̈ꗗ��\������B
void show_bot_subcommands(
	int fd // �\�P�b�g�̋L�q�q�B
) {
	std::stringstream out;
	out << "------ @Bot�̃T�u�R�}���h ------\n";
	for (auto& sc_pro : BOT_SUBCMD_PROCS) {
		out << sc_pro->sc_full_name;
		if (!sc_pro->sc_abr_name.empty())
			out << " (" << sc_pro->sc_abr_name << ")";
		out << "\n";
	}
	out << BOT_SUBCMD_PROCS.size() <<
		"���̃T�u�R�}���h��������܂����B\n";
	show_client(fd, out.str());
}

// �N���C�A���g�Ƀ��b�Z�[�W��\������B
void show_client(
	int fd,                // �\�P�b�g�̋L�q�q�B
	const std::string& mes // ���b�Z�[�W�B
) {
	clif_displaymessage(fd, (mes + "\n").c_str());
}

// �X�L���g�p�҂̃X�L�����x���𐧌�����B
void skill_user_limit_skill(
	block_if* lea,               // ���[�_�[�B
	command_argument_list& args, // �����̃��X�g�B
	block_if* sk_use             // �X�L���g�p�ҁB
) {
	std::string sk_nam = shift_arguments(
		args, "�X�L�����w�肵�Ă��������B"
	);
	s_skill* sk = sk_use->find_skill(sk_nam);
	if (!sk)
		throw command_error{print(
			"�u", sk_use->name(), "�v�̃X�L���ꗗ�Ɂu",
			sk_nam, "�v������܂���B"
		)};
	std::string sk_des = skill_get_desc(sk->id);
	if (!skill_get_inf(sk->id))
		throw command_error{print(
			"�u", sk_des, "�v�̓A�N�e�B�u�X�L���ł͂���܂���B"
		)};
	if (args.empty() &&
		sk_use->limit_skills()->find(sk->id)
	) {
		sk_use->limit_skills()->unregister(sk->id);
		show_client(lea->fd(), print(
			"�u", sk_use->name(), "�v�́u", sk_des,
			"�v�̃��x���������������܂����B"
		));
	} else {
		int lim_lv = 0;
		if (!args.empty()) {
			lim_lv = shift_arguments_then_parse_int(
				args,
				print("�u", sk_des, "�v�̐������x��"),
				0,
				skill_get_max(sk->id) - 1
			);
		}
		sk_use->limit_skills()->register_(sk->id, initialize<int>(lim_lv));
		show_client(lea->fd(), print(
			"�u", sk_use->name(), "�v�́u", sk_des,
			"�v�����x��", lim_lv, "�ɐ������܂����B"
		));
	}
	if (sk_use != lea) clif_emotion(sk_use->bl(), ET_OK);
}

// �X�L���g�p�҂̃X�L���ꗗ��\������B
void skill_user_show_skills(
	int fd,          // �\�P�b�g�̋L�q�q�B
	block_if* sk_use // �X�L���g�p�ҁB
) {
	std::stringstream out;
	out << print("------ �u", sk_use->name(), "�v�̃X�L�� ------\n");
	int cou = 0;
	sk_use->iterate_skill([sk_use, &out, &cou] (s_skill* sk) -> bool {
		out << ID_PREFIX << print(std::setw(5), std::setfill('0'), sk->id) << " - " <<
			skill_get_desc(sk->id) << " " << int(sk->lv);
		int* lim_slv = sk_use->limit_skills()->find(sk->id);
		if (lim_slv) out << " (" << *lim_slv << ")";
		out << "\n";
		++cou;
		return true;
	});
	out << cou << "���̃X�L����������܂����B(�X�L���|�C���g " <<
		sk_use->skill_point() << ")\n";
	show_client(fd, out.str());
}

// �X�L���g�p�҂̃X�L�����x�����グ��B
void skill_user_skill_up(
	block_if* lea,               // ���[�_�[�B
	command_argument_list& args, // �����̃��X�g�B
	block_if* sk_use             // �X�L���g�p�ҁB
) {
	std::string sk_nam = shift_arguments(
		args, "�X�L�����w�肵�Ă��������B"
	);
	s_skill* sk = sk_use->find_skill(sk_nam);
	if (!sk)
		throw command_error{print(
			"�u", sk_use->name(), "�v�̃X�L���ꗗ�Ɂu",
			sk_nam, "�v������܂���B"
		)};
	std::string sk_des = skill_get_desc(sk->id);
	int old_slv = sk->lv;
	sk_use->skill_up(e_skill(sk->id));
	if (sk->lv == old_slv)
		throw command_error{print(
			"�u", sk_use->name(), "�v�́u", sk_des,
			"�v������ȏ�擾�ł��܂���B"
		)};
	show_client(lea->fd(), print(
		"�u", sk_use->name(), "�v�́u", sk_des,
		" Lv", int(sk->lv), "�v���擾���܂����B"
	));
	if (sk_use != lea) clif_emotion(sk_use->bl(), ET_BEST);
}

// �X�L���g�p�҂��X�L�����g���B
void skill_user_use_skill(
	block_if* lea,               // ���[�_�[�B
	command_argument_list& args, // �����̃��X�g�B
	block_if* sk_use             // �X�L���g�p�ҁB
) {
	if (sk_use->is_dead() ||
		sk_use->sc()->cant.cast ||
		!sk_use->can_act() ||
		sk_use->is_paralysis()
	) throw command_error{print(
		"�u", sk_use->name(), "�v�͌��݃X�L�����g���܂���B"
	)};
	std::string sk_nam = shift_arguments(args);
	s_skill* sk = sk_use->find_skill(sk_nam);
	if (!sk)
		throw command_error{print(
			"�u", sk_use->name(), "�v�̃X�L���ꗗ�Ɂu",
			sk_nam, "�v������܂���B"
		)};
	std::string sk_des = skill_get_desc(sk->id);
	if (!skill_get_inf(sk->id))
		throw command_error{print(
			"�u", sk_des, "�v�̓A�N�e�B�u�X�L���ł͂���܂���B"
		)};
	if (!sk->lv)
		throw command_error{print(
			"�u", sk_use->name(), "�v�́u",
			sk_des, "�v���g���܂���B"
		)};
	block_if* tar_mem = nullptr;
	if (!(skill_get_inf(sk->id) & INF_SELF_SKILL))
		tar_mem = shift_arguments_then_find_member(lea, args);
	int klv = sk->lv;
	if (!args.empty()) klv = shift_arguments_then_parse_int(
		args, print("�u", sk_des, "�v�̃��x��"), 1, klv
	);
	if (!sk_use->can_use_skill(e_skill(sk->id), klv))
		throw command_error{print(
			"�u", sk_use->name(), "�v�͌��݁u",
			sk_des, " Lv", klv, "�v���g���܂���B"
		)};
	if (skill_get_inf(sk->id) & INF_SELF_SKILL) {
		sk_use->use_skill_self(e_skill(sk->id), klv, false);
		show_client(lea->fd(), print(
			"�u", sk_use->name(), "�v�́u",
			sk_des, " Lv", klv, "�v�̎g�p�����݂܂��B"
		));
	} else {
		if (skill_get_inf(sk->id) & INF_GROUND_SKILL)
			sk_use->use_skill_xy(
				e_skill(sk->id),
				klv,
				tar_mem->bl()->x,
				tar_mem->bl()->y,
				false
			);
		else sk_use->use_skill_block(e_skill(sk->id), klv, tar_mem, false);
		show_client(lea->fd(), print(
			"�u", sk_use->name(), "�v��"
			"�u", tar_mem->name(), "�v��"
			"�u", sk_des, " Lv", klv, "�v�̎g�p�����݂܂��B"
		));
	}
}

// �擪�̈������擾���A���X�g����폜����B
std::string // �擾���������B�������Ȃ��Aemp_err_mes���w�肳�ꂽ�Ȃ�command_error�B
shift_arguments(
	command_argument_list& args,   // �����̃��X�g�B
	const std::string& emp_err_mes // �������Ȃ��Ƃ��̃G���[���b�Z�[�W�B
) {
	std::string arg;
	if (!args.empty()) {
		arg = args.front();
		args.pop_front();
	}
	if (!emp_err_mes.empty() &&
		arg.empty()
	) throw command_error{emp_err_mes};
	return arg;
}

// �擪�̈������擾���A���X�g����폜���ABot��T���B
block_if* // ��������Bot�B������Ȃ�������command_error�B
shift_arguments_then_find_bot(
	block_if* lea,              // ���[�_�[�B
	command_argument_list& args // �����̃��X�g�B
) {
	std::string bot_nam = shift_arguments(args,
		"Bot���w�肵�Ă��������B"
	);
	block_if* bot = lea->find_bot(bot_nam);
	if (!bot)
		throw command_error{print(
			"���Ȃ��̃`�[���Ɂu", bot_nam, "�v�Ƃ���Bot�͂��܂���B"
		)};
	return bot;
}

// �擪�̈������擾���A���X�g����폜���A�����o�[��T���B
block_if* // �������������o�[�B������Ȃ�������command_error�B
shift_arguments_then_find_member(
	block_if* lea,              // ���[�_�[�B
	command_argument_list& args // �����̃��X�g�B
) {
	std::string mem_nam = shift_arguments(args,
		"�����o�[���w�肵�Ă��������B"
	);
	block_if* mem = lea->find_member(mem_nam);
	if (!mem)
		throw command_error{print(
			"���Ȃ��̃`�[���Ɂu", mem_nam, "�v�Ƃ��������o�[�͂��܂���B"
		)};
	return mem;
}

// �擪�̈������擾���A���X�g����폜���A�����ɕϊ�����B
int // �ϊ����������B�ϊ��ł��Ȃ�������command_error�B
shift_arguments_then_parse_int(
	command_argument_list& args, // �����̃��X�g�B
	const std::string& nam,      // �����̖��O�B
	int min,                     // �ŏ��l�B
	int max                      // �ő�l�B
) {
	std::string int_str = shift_arguments(args, print(
		nam, "���w�肵�Ă��������B"
	));
	int int_ = pybot::stoi(int_str, INT_MIN);
	if (int_ < min)
		throw command_error{print(
			nam, "�� ", min, " �ȏ�łȂ���΂Ȃ�܂���B"
		)};
	if (int_ > max)
		throw command_error{print(
			nam, "�� ", max, " �ȉ��łȂ���΂Ȃ�܂���B"
		)};
	return int_;
}

}
