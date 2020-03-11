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
	CS_ENTER;
	try {
		block_if* lea = ensure_leader(sd);
		command_argument_list args;
		command_parse_arguments(mes, pybot::back_inserter(args));
		if (args.empty()) show_bot_subcommands(lea);
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
			now = gettick();
			sc_pro->func(lea, args);
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
	CS_ENTER;
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

// �����o�[�̃o�b�t�@����ꎮ���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, BufferEquipSet) {
	CS_ENTER;
	using es_val_t = std::pair<sc_type,buffer_equipset*>;
	auto pri_equ_poss = [] (std::vector<ptr<equipset_item>>* itms) -> std::string {
		std::vector<std::string> toks;
		for (auto itm : *itms) toks.push_back(print_equip_pos(itm->equip));
		return concatinate_strings(ALL_RANGE(toks), "+");
	};

	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<es_val_t> es_vals;
		mem->buffer_equipsets()->copy(pybot::back_inserter(es_vals));
		std::sort(ALL_RANGE(es_vals), [lea] (es_val_t lval, es_val_t rval) -> bool {
			return lval.first > rval.first;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̃o�b�t�@����ꎮ ------\n";
		for (es_val_t es_val : es_vals) {
			sc_type sc_typ = es_val.first;
			buffer_equipset* es = es_val.second;
			efst_types ico = efst_types(StatusIconChangeTable[sc_typ]);
			std::string ico_nam = UNKNOWN_SYMBOL;
			if (ico != EFST_BLANK) ico_nam = ICON_NAME_TABLE[ico];
			lea->output_buffer() << ico_nam << " " <<
				es->items.size() << "��"
				"@" << pri_equ_poss(&es->items) << "\n";
		}
		lea->output_buffer() << es_vals.size() << "���̃o�b�t�@����ꎮ��������܂����B\n";
		lea->show_next();
	} else {
		std::string ico_nam = shift_arguments(args);
		auto sc_typ_ite = sc_types.find(ico_nam);
		if (sc_typ_ite == sc_types.end()) 
			throw command_error{print(
				"�u", ico_nam, "�v�Ƃ����X�e�[�^�X�ω��͂���܂���B"
			)};
		int equ = 0;
		auto es = initialize<buffer_equipset>(sc_typ_ite->second);
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
			esi->key->identify = 1;
			es->items.push_back(esi);
			equ |= esi->equip;
		}
		if (es->items.empty()) {
			buffer_equipset* old_es = mem->buffer_equipsets()->find(sc_typ_ite->second);
			if (!old_es)
				throw command_error{print(
					"�u", mem->name(), "�v�́u", sc_typ_ite->first, "�v�p�o�b�t�@����ꎮ�͂���܂���B"
				)};
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sc_typ_ite->first, "�v�p�o�b�t�@����ꎮ�̓o�^�𖕏����܂����B"
			));
			mem->buffer_equipsets()->unregister(sc_typ_ite->second);
		} else {
			mem->buffer_equipsets()->register_(sc_typ_ite->second, es);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sc_typ_ite->first, "�v�p�o�b�t�@����ꎮ�Ƃ��āu",
				es->items.size(), "��@", pri_equ_poss(&es->items), "�v�̕����o�^���܂����B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̃o�b�t�@����ꎮ���N���A����B
SUBCMD_FUNC(Bot, BufferEquipSetClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->buffer_equipsets()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou, "���̃o�b�t�@����ꎮ�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̃o�b�t�@����ꎮ�����[�h����B
SUBCMD_FUNC(Bot, BufferEquipSetLoad) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	std::string ico_nam = shift_arguments(
		args, "�X�e�[�^�X�ω����w�肵�Ă��������B"
	);
	auto sc_typ_ite = sc_types.find(ico_nam);
	if (sc_typ_ite == sc_types.end()) 
		throw command_error{print(
			"�u", ico_nam, "�v�Ƃ����X�e�[�^�X�ω��͂���܂���B"
		)};
	buffer_equipset* es = mem->buffer_equipsets()->find(sc_typ_ite->second);
	if (!es)
		throw command_error{print(
			"�u", mem->name(), "�v�́u", sc_typ_ite->first, "�v�p�o�b�t�@����ꎮ�͂���܂���B"
		)};
	mem->load_buffer_equipset(sc_typ_ite->second);
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �u" <<	mem->name() << "�v�����[�h�����u" <<
		sc_typ_ite->first << "�v�p�o�b�t�@����ꎮ ------\n";
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
			int inv_ind = mem->find_inventory(*esi->key, esi->equip);
			lea->output_buffer() << ID_PREFIX << esi->key->idb->nameid << " - " <<
				print_item_key(*esi->key) << " "
				"(" << print_equip_type(esi->key->idb);
			if (inv_ind != INT_MIN) {
				lea->output_buffer() << "@" << print_equip_pos(esi->equip);
				++cou;
			}
			lea->output_buffer() << ")";
			if (inv_ind == INT_MIN) lea->output_buffer() << " ���������s";
			lea->output_buffer() << "\n";
		}
	}
	lea->output_buffer() << cou << "�̕���𑕔����܂����B";
	lea->show_next();
	if (mem != lea) {
		clif_emotion(mem->bl(), ET_HNG);
		mem->last_reloaded_equipset_tick() = now;
	}
}

// �����o�[�̃o�b�t�@����ꎮ��]������B
SUBCMD_FUNC(Bot, BufferEquipSetTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->buffer_equipsets()->import_(mem1->buffer_equipsets().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̃o�b�t�@����ꎮ��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̃J�[�g���A�C�e�����ꗗ�\������B
SUBCMD_FUNC(Bot, Cart) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (!mem->is_carton())
		throw command_error{print(
			"�u", mem->name(), "�v�̓J�[�g�����L���Ă��܂���B"
		)};
	print_storage(mem, TABLE_CART);
}

// �����o�[�̃J�[�g������[�A�C�e�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, CartAutoGet) {
	CS_ENTER;
	using itm_val_t = std::pair<int,int*>;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (!mem->is_carton())
		throw command_error{print(
			"�u", mem->name(), "�v�̓J�[�g�����L���Ă��܂���B"
		)};
	if (args.empty()) {
		std::vector<itm_val_t> itm_vals;
		mem->cart_auto_get_items()->copy(pybot::back_inserter(itm_vals));
		std::sort(ALL_RANGE(itm_vals), [] (itm_val_t lval, itm_val_t rval) -> bool {
			return lval.first < rval.first;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" << mem->name() << "�v�̃J�[�g������[�A�C�e�� ------\n";
		for (itm_val_t itm_val : itm_vals) {
			int nid = itm_val.first;
			int amo = *itm_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << " (" << amo << ")\n";
		}
		lea->output_buffer() << itm_vals.size() << "���̃A�C�e����������܂����B\n";
		lea->show_next();
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		if (nid >= ITEM_TYPE_OFFSET &&
			nid < ITEM_TYPE_OFFSET + IT_MAX
		) throw command_error{print(
				"��ނ��w�肷�邱�Ƃ͂ł��܂���B"
			)};
		std::string idb_str = print_itemdb(nid);
		item_data* idb = itemdb_exists(actual_nameid(nid));
		if (!itemdb_isstackable2(idb))
			throw command_error{print(
				"�u", idb_str, "�v�̓X�^�b�N�ł��܂���B"
			)};
		if (args.empty()) {
			mem->cart_auto_get_items()->unregister(nid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v��"
				"�J�[�g���玩���I�Ɏ��o���܂���B"
			));
			if (mem != lea) clif_emotion(mem->bl(), ET_OK);
		} else {
			int amo = shift_arguments_then_parse_int(
				args, "�A�C�e���̌�", 1, MAX_AMOUNT
			);
			mem->cart_auto_get_items()->register_(nid, initialize<int>(amo));
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v�̏�������",
				amo, "�ɂȂ�悤�ɃJ�[�g���玩���I�Ɏ��o���܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̃J�[�g������[�A�C�e�����N���A����B
SUBCMD_FUNC(Bot, CartAutoGetClear) {
	CS_ENTER;
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
	CS_ENTER;
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
	CS_ENTER;
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
	CS_ENTER;
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

// �����X�^�[�Ƃ̍ő勗����ݒ肷��B
SUBCMD_FUNC(Bot, DistancemaX) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int dis = shift_arguments_then_parse_int(
		args, print("����"), 1, battle_config.pybot_around_distance
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�̓����X�^�[�ɑ΂���",
		dis, "�Z���ȉ��Ɉʒu���܂��B"
	));
	if (dis == battle_config.pybot_around_distance) dis = 0;
	mem->max_distance()->set(dis);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����X�^�[�Ƃ̍ŏ�������ݒ肷��B
SUBCMD_FUNC(Bot, DistancemiN) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int dis = shift_arguments_then_parse_int(
		args, print("����"), 0, battle_config.pybot_around_distance
	);
	if (dis)
		show_client(lea->fd(), print(
			"�u", mem->name(), "�v�̓����X�^�[�ɑ΂���",
			dis, "�Z���ȏ�Ɉʒu���܂��B"
		));
	else
		show_client(lea->fd(), print(
			"�u", mem->name(), "�v�̓����X�^�[�ɑ΂���",
			"�����|���V�[�ɉ����ė���܂��B"
		));
	mem->min_distance()->set(dis);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[������𑕔��A�܂��͑�������������B
SUBCMD_FUNC(Bot, Equip) {
	CS_ENTER;
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
			mem->last_reloaded_equipset_tick() = now;
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
				mem->last_reloaded_equipset_tick() = now;
			}
		} else {
			int equ = idb->equip;
			if (equ == EQP_HAND_R &&
				(mem->sd()->class_ & MAPID_UPPERMASK) == MAPID_ASSASSIN
			) equ = EQP_ARMS;
			if (pc_isequip(mem->sd(), itm_ind) ||
				!pc_equipitem(mem->sd(), itm_ind, equ)
			) throw command_error{print(
				"�u", mem->name(), "�v�́u", itm_str, "�v�𑕔��ł��܂���B"
			)};
			if (mem != lea) {
				show_client(lea->fd(), print(
					"�u", mem->name(), "�v�́u", itm_str, "�v�𑕔����܂����B"
				));
				clif_emotion(mem->bl(), ET_HNG);
				mem->last_reloaded_equipset_tick() = now;
			}
		}
	}
}

// ���ׂĂ̖��Ӓ�̕�����Ӓ肷��B
SUBCMD_FUNC(Bot, EquipIdentifyAll) {
	CS_ENTER;
	int tot_cou = 0;
	auto ide_itm = [lea, &tot_cou] (
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
			lea->output_buffer() << INDEX_PREFIX << mem->member_index() << " " <<
				ID_PREFIX << mem->char_id() << " - " <<
				mem->name() << " ; " <<
				STORAGE_TYPE_NAME_TABLE[sto_typ - 1] << " " <<
				INDEX_PREFIX << print(std::setw(ind_wid), std::setfill('0'), ind) << " " << 
				ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
				print_item(itm, idb);
			if (!itm->identify) lea->output_buffer() << " ���g�勾�s��";
			lea->output_buffer() << "\n";
		}
		return res;
	};
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �Ӓ肵������ ------\n";
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
	lea->output_buffer() << "���v" << tot_cou << "�̕�����Ӓ肵�܂����B\n";
	lea->show_next();
}

// ���ׂĂ̔j��������C������B
SUBCMD_FUNC(Bot, EquipRepairAll) {
	CS_ENTER;
	if (!npc_exists(
		lea->bl(),
		battle_config.pybot_around_distance,
		NPCTYPE_SCRIPT,
		REPAIRMAN_NAME
	)) throw command_error{print(
		"���ӂ�", REPAIRMAN_NAME, "NPC��������܂���B"
	)};
	int tot_cou = 0;
	int tot_zen = 0;
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �C���������� ------\n";
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
				lea->output_buffer() << INDEX_PREFIX << mem->member_index() << " " <<
					ID_PREFIX << mem->char_id() << " - " <<
					mem->name() << " ; " <<
					INDEX_PREFIX << print(std::setw(ind_wid), std::setfill('0'), i) << " " <<
					ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
					print_item(itm, idb);
				if (!suc) lea->output_buffer() << " �������s��";
				lea->output_buffer() << "\n";
			}
		}
		if (done) {
			clif_misceffect(mem->bl(), 3);
			clif_equiplist(mem->sd());
		}
	}
	lea->output_buffer() << "���v" << tot_cou << "�̕����" << print_zeny(tot_zen) << "Zeny�ŏC�����܂����B\n";
	lea->show_next();
}

// �����o�[�̕���ꎮ���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, EquipSet) {
	CS_ENTER;
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
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̕���ꎮ ------\n";
		for (es_val_t es_val : es_vals) {
			int mid = es_val.first;
			equipset_t* es = es_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				print_mobdb(mid) << " " <<
				es->items.size() << "��"
				"@" << pri_equ_poss(&es->items) << "\n";
		}
		lea->output_buffer() << es_vals.size() << "���̕���ꎮ��������܂����B\n";
		lea->show_next();
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
			esi->key->identify = 1;
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
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->equipsets()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou, "���̕���ꎮ�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̕���ꎮ�����[�h����B
SUBCMD_FUNC(Bot, EquipSetLoad) {
	CS_ENTER;
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
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �u" <<	mem->name() << "�v�����[�h�����u" <<
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
			int inv_ind = mem->find_inventory(*esi->key, esi->equip);
			lea->output_buffer() << ID_PREFIX << esi->key->idb->nameid << " - " <<
				print_item_key(*esi->key) << " "
				"(" << print_equip_type(esi->key->idb);
			if (inv_ind != INT_MIN) {
				lea->output_buffer() << "@" << print_equip_pos(esi->equip);
				++cou;
			}
			lea->output_buffer() << ")";
			if (inv_ind == INT_MIN) lea->output_buffer() << " ���������s";
			lea->output_buffer() << "\n";
		}
	}
	lea->output_buffer() << cou << "�̕���𑕔����܂����B";
	lea->show_next();
	if (mem != lea) {
		clif_emotion(mem->bl(), ET_HNG);
		mem->last_reloaded_equipset_tick() = now;
	}
}

// �����o�[�̕���ꎮ��]������B
SUBCMD_FUNC(Bot, EquipSetTransport) {
	CS_ENTER;
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
	CS_ENTER;
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

// �����邱�Ƃ̂ł��郂���X�^�[����ݒ肷��B
SUBCMD_FUNC(Bot, HoldMonsters) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = shift_arguments_then_parse_int(
		args, print("�����X�^�[��"), -1, INT_MAX
	);
	if (cou) {
		if (cou > 0)
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v��",
				cou, "�C�܂Ń����X�^�[������܂��B"
			));
		else
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�͉��C�ł������X�^�[������܂��B"
			));
	} else
		show_client(lea->fd(), print(
			"�u", mem->name(), "�v�̓����X�^�[������܂���B"
		));
	if (cou < 0) cou = INT_MAX;
	mem->hold_mobs()->set(cou);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �z�����N���X�̃X�L�����ꗗ�\���A�܂��͎g���B
SUBCMD_FUNC(Bot, HomunsKill) {
	CS_ENTER;
	block_if* hom = get_active_homun(shift_arguments_then_find_member(lea, args));
	if (args.empty()) skill_user_show_skills(hom);
	else skill_user_use_skill(lea, args, hom);
}

// �z�����N���X�̃A�N�e�B�u�X�L���𐧌�����B
SUBCMD_FUNC(Bot, HomunsKillLimit) {
	CS_ENTER;
	skill_user_limit_skill(lea, args, get_active_homun(shift_arguments_then_find_member(lea, args)));
}

// �z�����N���X�̃X�L�����x�����グ��B
SUBCMD_FUNC(Bot, HomunsKillUp) {
	CS_ENTER;
	skill_user_skill_up(lea, args, get_active_homun(shift_arguments_then_find_member(lea, args)));
}

// �z�����N���X�̃X�e�[�^�X��\������B
SUBCMD_FUNC(Bot, HomunStatus) {
	CS_ENTER;
	block_if* hom = get_active_homun(shift_arguments_then_find_member(lea, args));
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �u" << hom->name() << "�v�̃X�e�[�^�X ------\n";
	lea->output_buffer() << "��� <"  << hom->hd()->homunculusDB->name << "> "
		"���x�� " << hom->hd()->homunculus.level   << " ";
	if (hom->hd()->homunculus.level < battle_config.hom_max_level)
		lea->output_buffer() << "(" << hom->hd()->homunculus.exp << "/" << hom->hd()->exp_next << " " <<
			print(
				std::fixed,
				std::setprecision(1),
				hom->hd()->homunculus.exp * 100. / hom->hd()->exp_next
			) << "%) ";
	lea->output_buffer() << "�󕠓x " << hom->hd()->homunculus.hunger << "% �e���x " <<
		print(
			std::fixed,
			std::setprecision(2),
			hom->hd()->homunculus.intimacy / 100.
		) << "\n";
	lea->output_buffer() << print_main_status(hom->hd());
	lea->output_buffer() << print_sc(hom->sc()) << "\n";
	lea->show_next();
}

// �����o�[�̃C���x���g�����A�C�e�����ꗗ�\���A�܂��͎g���B
SUBCMD_FUNC(Bot, Item) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) print_storage(mem, TABLE_INVENTORY);
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
	CS_ENTER;
	bool all = args.empty();
	std::unordered_map<int,int> cous;
	while (!args.empty()) {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		if (nid >= ITEM_TYPE_OFFSET &&
			nid < ITEM_TYPE_OFFSET + IT_MAX
		) throw command_error{print(
				"��ނ��w�肷�邱�Ƃ͂ł��܂���B"
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
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �A�C�e���̏W�v���� ------\n";
	int tot_cou = 0;
	for (int nid : nids) {
		int cou = cous.at(nid);
		lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
			print_itemdb(nid) << " " << cou << "��\n";
		tot_cou += cou;
	}
	lea->output_buffer() << "���v" << nids.size() << "���A" << tot_cou << "�̃A�C�e����������܂����B\n";
	lea->show_next();
}

// �����o�[���A�C�e�����h���b�v����B
SUBCMD_FUNC(Bot, ItemDrop) {
	CS_ENTER;
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
	CS_ENTER;
	if (args.empty()) {
		std::vector<int> nids;
		lea->ignore_items()->copy(pybot::back_inserter(nids));
		std::sort(ALL_RANGE(nids));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �����A�C�e�� ------\n";
		for (int nid : nids) {
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << "\n";
		}
		lea->output_buffer() << nids.size() << "���̃A�C�e����������܂����B\n";
		lea->show_next();
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
	CS_ENTER;
	int cou = lea->ignore_items()->clear();
	show_client(lea->fd(), print(
		cou, "���̖����A�C�e���̓o�^�𖕏����܂����B"
	));
}

// �������Ă���A�C�e�������ׂĖ����A�C�e���Ƃ��ēo�^����B
SUBCMD_FUNC(Bot, ItemIgnoreHave) {
	CS_ENTER;
	int tot_cou = 0;
	auto reg_itm = [lea, &tot_cou] (
		block_if* mem,
		storage_type sto_typ,
		int ind,
		int ind_wid,
		item* itm,
		item_data* idb = nullptr
	) {
		if (itm->nameid &&
			!itm->equip &&
			!itm->card[0] &&
			!itm->card[3] &&
			!itm->refine
		) {
			if (!idb) idb = itemdb_exists(itm->nameid);
			if ((!idb->equip ||
					!itm->identify
				) && idb->jname[0] != '@' &&
				!lea->ignore_items()->find(itm->nameid)
			) {
				lea->ignore_items()->register_(itm->nameid);
				lea->output_buffer() << INDEX_PREFIX << mem->member_index() << " " <<
					ID_PREFIX << mem->char_id() << " - " <<
					mem->name() << " ; " <<
					STORAGE_TYPE_NAME_TABLE[sto_typ - 1] << " " <<
					ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
					print_itemdb(itm->nameid) << "\n";
				++tot_cou;
			}
		}
	};
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �o�^���������A�C�e�� ------\n";
	for (block_if* mem : lea->members()) {
		int ind_wid = print(MAX_INVENTORY - 1).length();
		for (int i = 0; i < MAX_INVENTORY; ++i) {
			item* itm = &mem->sd()->inventory.u.items_inventory[i];
			item_data* idb = mem->sd()->inventory_data[i];
			reg_itm(mem, TABLE_INVENTORY, i, ind_wid, itm, idb);
		}
		if (mem->is_carton()) {
			ind_wid = print(MAX_CART - 1).length();
			for (int i = 0; i < MAX_CART; ++i) {
				item* itm = &mem->sd()->cart.u.items_cart[i];
				reg_itm(mem, TABLE_CART, i, ind_wid, itm);
			}
		}
	}
	lea->output_buffer() << tot_cou << "���̖����A�C�e����o�^���܂����B\n";
	lea->show_next();
}

// �����A�C�e������荞�ށB
SUBCMD_FUNC(Bot, ItemIgnoreImport) {
	CS_ENTER;
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	t_tick hev_tic = lea->next_heavy_tick();
	if (hev_tic)
		throw command_error{print(
			"ItemIgnoreImport�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	auto bot_ign_itms = construct<registry_t<int>>(
		load_ignore_item_func(bot->char_id()),
		insert_ignore_item_func(bot->char_id()),
		delete_ignore_item_func(bot->char_id()),
		clear_ignore_item_func(bot->char_id())
	);
	int cou = lea->ignore_items()->import_(bot_ign_itms.get());
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v����",
		cou, "���̖����A�C�e������荞�݂܂����B"
	));
	lea->last_heavy_tick() = now;
}

// �񖳎��A�C�e�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, ItemNotIgnore) {
	CS_ENTER;
	if (args.empty()) {
		std::vector<int> nids;
		lea->not_ignore_items()->copy(pybot::back_inserter(nids));
		std::sort(ALL_RANGE(nids));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �񖳎��A�C�e�� ------\n";
		for (int nid : nids) {
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << "\n";
		}
		lea->output_buffer() << nids.size() << "���̃A�C�e����������܂����B\n";
		lea->show_next();
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
		if (lea->not_ignore_items()->find(nid)) {
			lea->not_ignore_items()->unregister(nid);
			show_client(lea->fd(), print("�u", idb_str, "�v��K���E���Ƃ͌���܂���B"));
		} else {
			lea->not_ignore_items()->register_(nid);
			show_client(lea->fd(), print("�u", idb_str, "�v��K���E���܂��B"));
		}
	}
}

// �񖳎��A�C�e�����N���A����B
SUBCMD_FUNC(Bot, ItemNotIgnoreClear) {
	CS_ENTER;
	int cou = lea->not_ignore_items()->clear();
	show_client(lea->fd(), print(
		cou, "���̔񖳎��A�C�e���̓o�^�𖕏����܂����B"
	));
}

// �������Ă���A�C�e�������ׂĔ񖳎��A�C�e���Ƃ��ēo�^����B
SUBCMD_FUNC(Bot, ItemNotIgnoreHave) {
	CS_ENTER;
	int tot_cou = 0;
	auto reg_itm = [lea, &tot_cou] (
		block_if* mem,
		storage_type sto_typ,
		int ind,
		int ind_wid,
		item* itm,
		item_data* idb = nullptr
	) {
		if (itm->nameid &&
			!itm->equip &&
			!itm->card[0] &&
			!itm->card[3] &&
			!itm->refine
		) {
			if (!idb) idb = itemdb_exists(itm->nameid);
			if ((!idb->equip ||
					!itm->identify
				) && idb->jname[0] != '@' &&
				!lea->not_ignore_items()->find(itm->nameid)
			) {
				lea->not_ignore_items()->register_(itm->nameid);
				lea->output_buffer() << INDEX_PREFIX << mem->member_index() << " " <<
					ID_PREFIX << mem->char_id() << " - " <<
					mem->name() << " ; " <<
					STORAGE_TYPE_NAME_TABLE[sto_typ - 1] << " " <<
					ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
					print_itemdb(itm->nameid) << "\n";
				++tot_cou;
			}
		}
	};
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �o�^�����񖳎��A�C�e�� ------\n";
	for (block_if* mem : lea->members()) {
		int ind_wid = print(MAX_INVENTORY - 1).length();
		for (int i = 0; i < MAX_INVENTORY; ++i) {
			item* itm = &mem->sd()->inventory.u.items_inventory[i];
			item_data* idb = mem->sd()->inventory_data[i];
			reg_itm(mem, TABLE_INVENTORY, i, ind_wid, itm, idb);
		}
		if (mem->is_carton()) {
			ind_wid = print(MAX_CART - 1).length();
			for (int i = 0; i < MAX_CART; ++i) {
				item* itm = &mem->sd()->cart.u.items_cart[i];
				reg_itm(mem, TABLE_CART, i, ind_wid, itm);
			}
		}
	}
	lea->output_buffer() << tot_cou << "���̔񖳎��A�C�e����o�^���܂����B\n";
	lea->show_next();
}

// �񖳎��A�C�e������荞�ށB
SUBCMD_FUNC(Bot, ItemNotIgnoreImport) {
	CS_ENTER;
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	t_tick hev_tic = lea->next_heavy_tick();
	if (hev_tic)
		throw command_error{print(
			"ItemNotIgnoreImport�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	auto bot_not_ign_itms = construct<registry_t<int>>(
		load_not_ignore_item_func(bot->char_id()),
		insert_not_ignore_item_func(bot->char_id()),
		delete_not_ignore_item_func(bot->char_id()),
		clear_not_ignore_item_func(bot->char_id())
	);
	int cou = lea->not_ignore_items()->import_(bot_not_ign_itms.get());
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v����",
		cou, "���̔񖳎��A�C�e������荞�݂܂����B"
	));
	lea->last_heavy_tick() = now;
}

// �����o�[�̃A�C�e����ߖ񃂃��X�^�[���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, ItemNotsaVeMonster) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<int> isms;
		mem->item_not_save_mobs()->copy(pybot::back_inserter(isms));
		std::sort(ALL_RANGE(isms));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̃A�C�e����ߖ񃂃��X�^�[ ------\n";
		for (int ism : isms) {
			int nid = ITEM_FROM_ISM(ism);
			int mid = MOB_FROM_ISM(ism);
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << " ; " <<
				ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				print_mobdb(mid) << "\n";
		}
		lea->output_buffer() << isms.size() << "���̃A�C�e����ߖ񃂃��X�^�[��������܂����B\n";
		lea->show_next();
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		if (nid >= ITEM_TYPE_OFFSET &&
			nid < ITEM_TYPE_OFFSET + IT_MAX
		) throw command_error{print(
				"��ނ��w�肷�邱�Ƃ͂ł��܂���B"
			)};
		std::string idb_str = print_itemdb(nid);
		std::string mob_nam = shift_arguments(args, "�����X�^�[���w�肵�Ă��������B");
		int mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		if (mid == MM_BACKUP)
			throw command_error{print(
				"�u", META_MONSTER_NAMES.at(MM_BACKUP),
				"�v�p�A�C�e����ߖ񃂃��X�^�[�͓o�^�ł��܂���B"
			)};
		std::string mob_str = print_mobdb(mid);
		int ism = ITEM_SAVE_MOB(nid, mid);
		if (mem->item_not_save_mobs()->find(ism)) {
			mem->item_not_save_mobs()->unregister(ism);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v���u", mob_str, "�v�p�ɕK���g���Ƃ͌���܂���B"
			));
		} else {
			mem->item_not_save_mobs()->register_(ism);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v���u", mob_str, "�v�p�ɕK���g���܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̃A�C�e����ߖ񃂃��X�^�[���N���A����B
SUBCMD_FUNC(Bot, ItemNotsaVeMonsterClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->item_not_save_mobs()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou,
		"���̃A�C�e����ߖ񃂃��X�^�[�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̃A�C�e����ߖ񃂃��X�^�[��]������B
SUBCMD_FUNC(Bot, ItemNotsaVeMonsterTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->item_not_save_mobs()->import_(mem1->item_not_save_mobs().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̃A�C�e����ߖ񃂃��X�^�[��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[��HP�񕜃A�C�e�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, ItemRecoverHp) {
	CS_ENTER;
	using itm_val_t = std::pair<int,int*>;

	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<itm_val_t> itm_vals;
		mem->recover_hp_items()->copy(pybot::back_inserter(itm_vals));
		std::sort(ALL_RANGE(itm_vals), [] (itm_val_t lval, itm_val_t rval) -> bool {
			return *lval.second < *rval.second;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" << mem->name() << "�v��HP�񕜃A�C�e�� ------\n";
		for (itm_val_t itm_val : itm_vals) {
			int nid = itm_val.first;
			int thr = *itm_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << " " << thr << "%\n";
		}
		lea->output_buffer() << itm_vals.size() << "���̃A�C�e����������܂����B\n";
		lea->show_next();
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		if (nid >= ITEM_TYPE_OFFSET &&
			nid < ITEM_TYPE_OFFSET + IT_MAX
		) throw command_error{print(
				"��ނ��w�肷�邱�Ƃ͂ł��܂���B"
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
	CS_ENTER;
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
	CS_ENTER;
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
	CS_ENTER;
	using itm_val_t = std::pair<int,int*>;

	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<itm_val_t> itm_vals;
		mem->recover_sp_items()->copy(pybot::back_inserter(itm_vals));
		std::sort(ALL_RANGE(itm_vals), [] (itm_val_t lval, itm_val_t rval) -> bool {
			return *lval.second < *rval.second;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" << mem->name() << "�v��SP�񕜃A�C�e�� ------\n";
		for (itm_val_t itm_val : itm_vals) {
			int nid = itm_val.first;
			int thr = *itm_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << " " << thr << "%\n";
		}
		lea->output_buffer() << itm_vals.size() << "���̃A�C�e����������܂����B\n";
		lea->show_next();
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		if (nid >= ITEM_TYPE_OFFSET &&
			nid < ITEM_TYPE_OFFSET + IT_MAX
		) throw command_error{print(
				"��ނ��w�肷�邱�Ƃ͂ł��܂���B"
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
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->recover_sp_items()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou, "����SP�񕜃A�C�e���̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[��SP�񕜃A�C�e����]������B
SUBCMD_FUNC(Bot, ItemRecoverSpTransport) {
	CS_ENTER;
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
	CS_ENTER;
	if (args.empty()) {
		std::vector<int> nids;
		lea->sell_items()->copy(pybot::back_inserter(nids));
		std::sort(ALL_RANGE(nids));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ ���p�A�C�e�� ------\n";
		for (int nid : nids) {
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << "\n";
		}
		lea->output_buffer() << nids.size() << "���̃A�C�e����������܂����B\n";
		lea->show_next();
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

// �����o�[�̃A�C�e���ߖ񃂃��X�^�[���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, ItemsaVeMonster) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<int> isms;
		mem->item_save_mobs()->copy(pybot::back_inserter(isms));
		std::sort(ALL_RANGE(isms));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̃A�C�e���ߖ񃂃��X�^�[ ------\n";
		for (int ism : isms) {
			int nid = ITEM_FROM_ISM(ism);
			int mid = MOB_FROM_ISM(ism);
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << " ; " <<
				ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				print_mobdb(mid) << "\n";
		}
		lea->output_buffer() << isms.size() << "���̃A�C�e���ߖ񃂃��X�^�[��������܂����B\n";
		lea->show_next();
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		if (nid >= ITEM_TYPE_OFFSET &&
			nid < ITEM_TYPE_OFFSET + IT_MAX
		) throw command_error{print(
				"��ނ��w�肷�邱�Ƃ͂ł��܂���B"
			)};
		std::string idb_str = print_itemdb(nid);
		std::string mob_nam = shift_arguments(args, "�����X�^�[���w�肵�Ă��������B");
		int mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		if (mid == MM_BACKUP)
			throw command_error{print(
				"�u", META_MONSTER_NAMES.at(MM_BACKUP),
				"�v�p�A�C�e���ߖ񃂃��X�^�[�͓o�^�ł��܂���B"
			)};
		std::string mob_str = print_mobdb(mid);
		int ism = ITEM_SAVE_MOB(nid, mid);
		if (mem->item_save_mobs()->find(ism)) {
			mem->item_save_mobs()->unregister(ism);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v���u", mob_str, "�v�p�Ɏg���܂��B"
			));
		} else {
			mem->item_save_mobs()->register_(ism);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", idb_str, "�v���u", mob_str, "�v�p�Ɏg���܂���B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̃A�C�e���ߖ񃂃��X�^�[���N���A����B
SUBCMD_FUNC(Bot, ItemsaVeMonsterClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->item_save_mobs()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou,
		"���̃A�C�e���ߖ񃂃��X�^�[�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̃A�C�e���ߖ񃂃��X�^�[��]������B
SUBCMD_FUNC(Bot, ItemsaVeMonsterTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->item_save_mobs()->import_(mem1->item_save_mobs().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̃A�C�e���ߖ񃂃��X�^�[��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �o�^�ς݂̃A�C�e�������ׂĔ��p����B
SUBCMD_FUNC(Bot, ItemSellAll) {
	CS_ENTER;
	if (!npc_exists(
		lea->bl(),
		battle_config.pybot_around_distance,
		NPCTYPE_SHOP
	)) throw command_error{"���ӂɏ��lNPC��������܂���B"};
	int tot_cou = 0;
	int tot_amo = 0;
	int tot_zen = 0;
	auto sel_itm = [lea, &tot_cou, &tot_amo, &tot_zen] (
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
			!itm->card[3] &&
			!itm->refine
		) {
			if (!idb) idb = itemdb_exists(itm->nameid);
			if (lea->sell_items()->find(itm->nameid) ||
				lea->sell_items()->find(ITEM_TYPE_OFFSET + idb->type)
			) {
				int zen = pc_modifysellvalue(mem->sd(), idb->value_sell) * itm->amount;
				pc_getzeny(mem->sd(), zen, LOG_TYPE_NPC, NULL);
				lea->output_buffer() << INDEX_PREFIX << mem->member_index() << " " <<
					ID_PREFIX << mem->char_id() << " - " <<
					mem->name() << " ; " <<
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
		}
		return res;
	};
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ ���p�����A�C�e�� ------\n";
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
	lea->output_buffer() << "���v" << tot_cou << "���A" << tot_amo << "�̃A�C�e����" <<
		print_zeny(tot_zen) << "Zeny�Ŕ���܂����B\n";
	lea->show_next();
}

// ���p�A�C�e�����N���A����B
SUBCMD_FUNC(Bot, ItemSellClear) {
	CS_ENTER;
	int cou = lea->sell_items()->clear();
	show_client(lea->fd(), print(
		cou, "���̔��p�A�C�e���̓o�^�𖕏����܂����B"
	));
}

// �������Ă���A�C�e�������ׂĔ��p�A�C�e���Ƃ��ēo�^����B
SUBCMD_FUNC(Bot, ItemSellHave) {
	CS_ENTER;
	int tot_cou = 0;
	auto reg_itm = [lea, &tot_cou] (
		block_if* mem,
		storage_type sto_typ,
		int ind,
		int ind_wid,
		item* itm,
		item_data* idb = nullptr
	) {
		if (itm->nameid &&
			!itm->equip &&
			!itm->card[0] &&
			!itm->card[3] &&
			!itm->refine
		) {
			if (!idb) idb = itemdb_exists(itm->nameid);
			if ((!idb->equip ||
					!itm->identify
				) && idb->jname[0] != '@' &&
				!lea->sell_items()->find(itm->nameid)
			) {
				lea->sell_items()->register_(itm->nameid);
				lea->output_buffer() << INDEX_PREFIX << mem->member_index() << " " <<
					ID_PREFIX << mem->char_id() << " - " <<
					mem->name() << " ; " <<
					STORAGE_TYPE_NAME_TABLE[sto_typ - 1] << " " <<
					ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
					print_itemdb(itm->nameid) << "\n";
				++tot_cou;
			}
		}
	};
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �o�^�������p�A�C�e�� ------\n";
	for (block_if* mem : lea->members()) {
		int ind_wid = print(MAX_INVENTORY - 1).length();
		for (int i = 0; i < MAX_INVENTORY; ++i) {
			item* itm = &mem->sd()->inventory.u.items_inventory[i];
			item_data* idb = mem->sd()->inventory_data[i];
			reg_itm(mem, TABLE_INVENTORY, i, ind_wid, itm, idb);
		}
		if (mem->is_carton()) {
			ind_wid = print(MAX_CART - 1).length();
			for (int i = 0; i < MAX_CART; ++i) {
				item* itm = &mem->sd()->cart.u.items_cart[i];
				reg_itm(mem, TABLE_CART, i, ind_wid, itm);
			}
		}
	}
	lea->output_buffer() << tot_cou << "���̔��p�A�C�e����o�^���܂����B\n";
	lea->show_next();
}

// ���p�A�C�e������荞�ށB
SUBCMD_FUNC(Bot, ItemSellImport) {
	CS_ENTER;
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	t_tick hev_tic = lea->next_heavy_tick();
	if (hev_tic)
		throw command_error{print(
			"ItemSellImport�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	auto bot_sel_itms = construct<registry_t<int>>(
		load_sell_item_func(bot->char_id()),
		insert_sell_item_func(bot->char_id()),
		delete_sell_item_func(bot->char_id()),
		clear_sell_item_func(bot->char_id())
	);
	int cou = lea->sell_items()->import_(bot_sel_itms.get());
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v����",
		cou, "���̔��p�A�C�e������荞�݂܂����B"
	));
	lea->last_heavy_tick() = now;
}

// �W���[�i������荞�ށB
SUBCMD_FUNC(Bot, JournalImport) {
	CS_ENTER;
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	t_tick hev_tic = lea->next_heavy_tick();
	if (hev_tic)
		throw command_error{print(
			"JournalImport�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	auto bot_jous = construct<registry_t<int,coords_t>>(
		load_journal_func(bot->char_id()),
		insert_journal_func(bot->char_id()),
		update_journal_func(bot->char_id()),
		delete_journal_func(bot->char_id()),
		clear_journal_func(bot->char_id())
	);
	int cou = lea->journals()->import_(bot_jous.get());
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v����",
		cou, "���̃W���[�i������荞�݂܂����B"
	));
	lea->last_heavy_tick() = now;
}

// Bot�����O�C������B
SUBCMD_FUNC(Bot, LogIn) {
	CS_ENTER;
	if (lea->is_dead())
		throw command_error{"���S������Ԃ�Bot�����O�C�������邱�Ƃ͂ł��܂���B"};
	if (lea->bots().size() >= bot_limit(lea->sd()))
		throw command_error{"�`�[���ɏ������Ă���Bot�̐l���������l���ɒB���Ă��܂��B"};
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
	t_tick hev_tic = lea->next_heavy_tick();
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
			lea->last_heavy_tick() = now;
			show_client(lea->fd(), print(
				"�u", bot->name(), "�v�����O�C�����܂����B"
			));
		}
	);
}

// Bot�����O�A�E�g����B
SUBCMD_FUNC(Bot, LogOut) {
	CS_ENTER;
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	if (lea->bots().size() == 1) {
		lea->save_team(0);
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
	lea->last_heavy_tick() = now;
}

// �����o�[�̏E�����[�h��ݒ肷��B
SUBCMD_FUNC(Bot, Loot) {
	CS_ENTER;
	static const std::array<std::string, LM_MAX> MESS = {
		"�̓h���b�v�A�C�e�����E���܂���B",
		"�̓h���b�v�A�C�e�����x�����ɂ����E���܂��B",
		"�̓h���b�v�A�C�e������ɏE���܂��B",
	};
	block_if* mem = shift_arguments_then_find_member(lea, args);
	auto& loot = mem->loot();
	loot->set(loot_modes((loot->get() + 1) % LM_MAX));
	show_client(lea->fd(), print("�u", mem->name(), "�v��", MESS[loot->get()]));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �E��������ݒ肷��B
SUBCMD_FUNC(Bot, LootLimit) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int lim = shift_arguments_then_parse_int(
		args, print("�d�ʗ�"), 1, 100
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�͏����A�C�e���̏d�ʂ�",
		lim, "%�ɂȂ�܂ŏE���܂��B"
	));
	if (lim == DEFAULT_LOOT_LIMIT) lim = 0;
	mem->loot_limit()->set(lim);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̃}�b�v����ꎮ���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, MapEquipSet) {
	CS_ENTER;
	using es_val_t = std::pair<int,map_equipset*>;
	auto pri_equ_poss = [] (std::vector<ptr<equipset_item>>* itms) -> std::string {
		std::vector<std::string> toks;
		for (auto itm : *itms) toks.push_back(print_equip_pos(itm->equip));
		return concatinate_strings(ALL_RANGE(toks), "+");
	};

	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<es_val_t> es_vals;
		mem->map_equipsets()->copy(pybot::back_inserter(es_vals));
		std::sort(ALL_RANGE(es_vals), [lea] (es_val_t lval, es_val_t rval) -> bool {
			return lval.first > rval.first;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̃}�b�v����ꎮ ------\n";
		for (es_val_t es_val : es_vals) {
			int m = es_val.first;
			map_equipset* es = es_val.second;
			auto map = id_maps.at(m);
			std::string jnam = UNKNOWN_SYMBOL;
			std::string enam = UNKNOWN_SYMBOL;
			if (map) {
				jnam = map->name_japanese;
				enam = map->name_english;
			}
			lea->output_buffer() << jnam << " (" << enam << ") " <<
				es->items.size() << "��"
				"@" << pri_equ_poss(&es->items) << "\n";
		}
		lea->output_buffer() << es_vals.size() << "���̃}�b�v����ꎮ��������܂����B\n";
		lea->show_next();
	} else {
		std::string map_str = shift_arguments(args);
		std::string map_str_lc = lowercase(map_str);
		int m;
		if (map_str_lc == THIS_MAP_NAME) m = lea->bl()->m;
		else m = map_mapname2mapid(map_str_lc.c_str());
		if (m < 0) 
			throw command_error{print(
				"�u", map_str, "�v�Ƃ����}�b�vID�͌�����܂���ł����B"
			)};
		auto map = id_maps.at(m);
		int equ = 0;
		auto es = initialize<map_equipset>(m);
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
			esi->key->identify = 1;
			es->items.push_back(esi);
			equ |= esi->equip;
		}
		if (es->items.empty()) {
			map_equipset* old_es = mem->map_equipsets()->find(m);
			if (!old_es)
				throw command_error{print(
					"�u", mem->name(), "�v�́u", map->name_japanese, "(", map->name_english, ")�v�p�}�b�v����ꎮ�͂���܂���B"
				)};
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", map->name_japanese, "(", map->name_english, ")�v�p�}�b�v����ꎮ�̓o�^�𖕏����܂����B"
			));
			mem->map_equipsets()->unregister(m);
		} else {
			mem->map_equipsets()->register_(m, es);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", map->name_japanese, "(", map->name_english, ")�v�p�}�b�v����ꎮ�Ƃ��āu",
				es->items.size(), "��@", pri_equ_poss(&es->items), "�v�̕����o�^���܂����B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̃}�b�v����ꎮ���N���A����B
SUBCMD_FUNC(Bot, MapEquipSetClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->map_equipsets()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou, "���̃}�b�v����ꎮ�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̃}�b�v����ꎮ�����[�h����B
SUBCMD_FUNC(Bot, MapEquipSetLoad) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	std::string map_str = shift_arguments(args);
	std::string map_str_lc = lowercase(map_str);
	int m;
	if (map_str_lc == THIS_MAP_NAME) m = lea->bl()->m;
	else m = map_mapname2mapid(map_str_lc.c_str());
	if (m < 0) 
		throw command_error{print(
			"�u", map_str, "�v�Ƃ����}�b�vID�͌�����܂���ł����B"
		)};
	auto map = id_maps.at(m);
	map_equipset* es = mem->map_equipsets()->find(m);
	if (!es)
		throw command_error{print(
			"�u", mem->name(), "�v�́u", map->name_japanese, "(", map->name_english, ")�v�p�}�b�v����ꎮ�͂���܂���B"
		)};
	mem->load_map_equipset(m);
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �u" <<	mem->name() << "�v�����[�h�����u" <<
		map->name_japanese, "(", map->name_english, ")�v�p�}�b�v����ꎮ ------\n";
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
			int inv_ind = mem->find_inventory(*esi->key, esi->equip);
			lea->output_buffer() << ID_PREFIX << esi->key->idb->nameid << " - " <<
				print_item_key(*esi->key) << " "
				"(" << print_equip_type(esi->key->idb);
			if (inv_ind != INT_MIN) {
				lea->output_buffer() << "@" << print_equip_pos(esi->equip);
				++cou;
			}
			lea->output_buffer() << ")";
			if (inv_ind == INT_MIN) lea->output_buffer() << " ���������s";
			lea->output_buffer() << "\n";
		}
	}
	lea->output_buffer() << cou << "�̕���𑕔����܂����B";
	lea->show_next();
	if (mem != lea) {
		clif_emotion(mem->bl(), ET_HNG);
		mem->last_reloaded_equipset_tick() = now;
	}
}

// �����o�[�̃}�b�v����ꎮ��]������B
SUBCMD_FUNC(Bot, MapEquipSetTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->map_equipsets()->import_(mem1->map_equipsets().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̃}�b�v����ꎮ��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�����݈ʒu����������B
SUBCMD_FUNC(Bot, Memo) {
	CS_ENTER;
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

// �����o�[�̗D�惂���X�^�[���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, MonsterFirst) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<int> mids;
		mem->first_mobs()->copy(pybot::back_inserter(mids));
		std::sort(ALL_RANGE(mids));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̗D�惂���X�^�[ ------\n";
		for (int mid : mids) {
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				print_mobdb(mid) << "\n";
		}
		lea->output_buffer() << mids.size() << "���̗D�惂���X�^�[��������܂����B\n";
		lea->show_next();
	} else {
		std::string mob_nam = shift_arguments(args);
		int mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		std::string mob_str = print_mobdb(mid);
		if (mid < MM_BASE ||
			mid >= MM_CAUTION
		) throw command_error{print("�u", mob_str, "�v�͎w��ł��܂���B")};
		if (mem->first_mobs()->find(mid)) {
			mem->first_mobs()->unregister(mid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v��"
				"�D��I�ɍU�����܂���B"
			));
		} else {
			mem->first_mobs()->register_(mid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v��"
				"�D��I�ɍU�����܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̗D�惂���X�^�[���N���A����B
SUBCMD_FUNC(Bot, MonsterFirstClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->first_mobs()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou,
		"���̗D�惂���X�^�[�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̗D�惂���X�^�[��]������B
SUBCMD_FUNC(Bot, MonsterFirstTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->first_mobs()->import_(mem1->first_mobs().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̗D�惂���X�^�[��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �O���[�g�����X�^�[���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, MonsterGreat) {
	CS_ENTER;
	if (args.empty()) {
		std::vector<int> mids;
		lea->great_mobs()->copy(pybot::back_inserter(mids));
		std::sort(ALL_RANGE(mids));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �O���[�g�����X�^�[ ------\n";
		for (int mid : mids)
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " << 
				print_mobdb(mid) << "\n";
		lea->output_buffer() << mids.size() << "���̃����X�^�[��������܂����B\n";
		lea->show_next();
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
	CS_ENTER;
	int cou = lea->great_mobs()->clear();
	show_client(lea->fd(), print(
		cou, "���̃O���[�g�����X�^�[�̓o�^�𖕏����܂����B"
	));
}

// �O���[�g�����X�^�[����荞�ށB
SUBCMD_FUNC(Bot, MonsterGreatImport) {
	CS_ENTER;
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	t_tick hev_tic = lea->next_heavy_tick();
	if (hev_tic)
		throw command_error{print(
			"MonsterGreatImport�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	auto bot_gre_mobs = construct<registry_t<int>>(
		load_great_mob_func(bot->char_id()),
		insert_great_mob_func(bot->char_id()),
		delete_great_mob_func(bot->char_id()),
		clear_great_mob_func(bot->char_id())
	);
	int cou = lea->great_mobs()->import_(bot_gre_mobs.get());
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v����",
		cou, "���̃O���[�g�����X�^�[����荞�݂܂����B"
	));
	lea->last_heavy_tick() = now;
}

// �����X�^�[�̍�Def��ݒ肷��B
SUBCMD_FUNC(Bot, MonsterHighDef) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int def = shift_arguments_then_parse_int(
		args, print("Def"), 1, 100
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��Def��", def, "�ȏ�̃����X�^�[����Def�Ƃ݂Ȃ��܂��B"
	));
	if (def == DEFAULT_MOB_HIGH_DEF) def = 0;
	mem->mob_high_def()->set(def);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����X�^�[�̍�DefVit��ݒ肷��B
SUBCMD_FUNC(Bot, MonsterHighDefVit) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int dv = shift_arguments_then_parse_int(
		args, print("DefVit"), 1, INT_MAX
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��Def��Vit�̍��v��", dv, "�ȏ�̃����X�^�[����DefVit�Ƃ݂Ȃ��܂��B"
	));
	if (dv == DEFAULT_MOB_HIGH_DEF_VIT) dv = 0;
	mem->mob_high_def_vit()->set(dv);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����X�^�[�̍�Flee��ݒ肷��B
SUBCMD_FUNC(Bot, MonsterHighFlee) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int fle = shift_arguments_then_parse_int(
		args, print("Flee"), 1, INT_MAX
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��Flee��", fle, "�ȏ�̃����X�^�[����Flee�Ƃ݂Ȃ��܂��B"
	));
	if (fle == DEFAULT_MOB_HIGH_FLEE) fle = 0;
	mem->mob_high_flee()->set(fle);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����X�^�[�̍�Hit��ݒ肷��B
SUBCMD_FUNC(Bot, MonsterHighHit) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int hit = shift_arguments_then_parse_int(
		args, print("Hit"), 1, INT_MAX
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��Hit��", hit, "�ȏ�̃����X�^�[����Hit�Ƃ݂Ȃ��܂��B"
	));
	if (hit == DEFAULT_MOB_HIGH_HIT) hit = 0;
	mem->mob_high_hit()->set(hit);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����X�^�[�̍�Mdef��ݒ肷��B
SUBCMD_FUNC(Bot, MonsterHighMdef) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int mdef = shift_arguments_then_parse_int(
		args, print("Mdef"), 1, 100
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��Mdef��", mdef, "�ȏ�̃����X�^�[����Mdef�Ƃ݂Ȃ��܂��B"
	));
	if (mdef == DEFAULT_MOB_HIGH_MDEF) mdef = 0;
	mem->mob_high_mdef()->set(mdef);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̖��������X�^�[���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, MonsterIgnore) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<int> mids;
		mem->ignore_mobs()->copy(pybot::back_inserter(mids));
		std::sort(ALL_RANGE(mids));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̖��������X�^�[ ------\n";
		for (int mid : mids) {
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				print_mobdb(mid) << "\n";
		}
		lea->output_buffer() << mids.size() << "���̖��������X�^�[��������܂����B\n";
		lea->show_next();
	} else {
		std::string mob_nam = shift_arguments(args);
		int mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		std::string mob_str = print_mobdb(mid);
		if (mid < MM_BASE ||
			mid >= MM_CAUTION
		) throw command_error{print("�u", mob_str, "�v�͎w��ł��܂���B")};
		if (mem->ignore_mobs()->find(mid)) {
			mem->ignore_mobs()->unregister(mid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v��"
				"�������܂���B"
			));
		} else {
			mem->ignore_mobs()->register_(mid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v��"
				"�������܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̖��������X�^�[���N���A����B
SUBCMD_FUNC(Bot, MonsterIgnoreClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->ignore_mobs()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou,
		"���̖��������X�^�[�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̖��������X�^�[��]������B
SUBCMD_FUNC(Bot, MonsterIgnoreTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->ignore_mobs()->import_(mem1->ignore_mobs().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̖��������X�^�[��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// ���̃y�[�W��\������B
SUBCMD_FUNC(Bot, Next) {
	CS_ENTER;
	lea->show_next();
}

// �y�b�g���A�N�Z�T���[�𑕔��A�܂��͉�������B
SUBCMD_FUNC(Bot, PetEquip) {
	CS_ENTER;
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
	CS_ENTER;
	block_if* pet = get_active_pet(shift_arguments_then_find_member(lea, args));
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �u" << pet->name() << "�v�̃X�e�[�^�X ------\n";
	lea->output_buffer() << "��� <"  << pet->pd()->get_pet_db()->jname << "> "
		"���x�� " << pet->pd()->pet.level           << " "
		"�󕠓x " << pet->pd()->pet.hungry          << "% "
		"�e���x " << print(std::fixed, std::setprecision(1), pet->pd()->pet.intimate / 10.);
	int acc_nid = pet->pd()->get_pet_db()->AcceID;
	if (acc_nid) {
		lea->output_buffer() << " �A�N�Z�T���[ <";
		if (pet->pd()->pet.equip) lea->output_buffer() << "�����ς�";
		else lea->output_buffer() << "������";
		lea->output_buffer() << ">";
	}
	lea->output_buffer() << "\n";
	lea->show_next();
}

// �����o�[�̋����|���V�[���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, PolicyDistance) {
	CS_ENTER;
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
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" << mem->name() << "�v�̋����|���V�["
			"(" << DISTANCE_POLICY_VALUE_NAME_TABLE[mem->default_distance_policy_value()] << ") ------\n";
		for (pol_val_t pol_val : pol_vals) {
			int mid = pol_val.first;
			distance_policy* pol = pol_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
			       print_mobdb(mid) << " " <<
			       DISTANCE_POLICY_VALUE_NAME_TABLE[pol->value] << "\n";
		}
		lea->output_buffer() << pol_vals.size() << "���̋����|���V�[��������܂����B\n";
		lea->show_next();
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
			) throw command_error{print("�u", mob_str, "�v�͎w��ł��܂���B")};
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
	CS_ENTER;
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
	CS_ENTER;
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
	CS_ENTER;
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
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" << mem->name() << "�v�̒ʏ�U���|���V�["
			"(" << NORMAL_ATTACK_POLICY_VALUE_NAME_TABLE[mem->default_normal_attack_policy_value()] << ") ------\n";
		for (pol_val_t pol_val : pol_vals) {
			int mid = pol_val.first;
			normal_attack_policy* pol = pol_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				   print_mobdb(mid) << " " <<
				   NORMAL_ATTACK_POLICY_VALUE_NAME_TABLE[pol->value] << "\n";
		}
		lea->output_buffer() << pol_vals.size() << "���̒ʏ�U���|���V�[��������܂����B\n";
		lea->show_next();
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
			) throw command_error{print("�u", mob_str, "�v�͎w��ł��܂���B")};
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
	CS_ENTER;
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
	CS_ENTER;
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

// �V���b�v�|�C���g���������B
SUBCMD_FUNC(Bot, ShopPointCollect) {
	CS_ENTER;
	auto imp = [lea] (block_if* bot, int poi = INT_MIN) -> int {
		if (poi == INT_MIN) poi = bot->sd()->cashPoints;
		pc_paycash(bot->sd(), poi, 0, LOG_TYPE_PICKDROP_PLAYER);
		pc_getcash(lea->sd(), poi, 0, LOG_TYPE_PICKDROP_PLAYER);
		return poi;
	};
	if (args.empty()) {
		int cou = 0, sum = 0;
		for (auto bot : lea->bots()) {
			int poi = imp(bot.get());
			if (poi) ++cou;
			sum += poi;
		}
		show_client(lea->fd(), print(
			cou, "�l��Bot���獇�v", sum, "�V���b�v�|�C���g��������܂����B"
		));
	} else {
		block_if* bot = shift_arguments_then_find_bot(lea, args);
		int poi = INT_MIN;
		if (!args.empty())
			poi = shift_arguments_then_parse_int(args, "�|�C���g", 1, bot->sd()->cashPoints);
		int act_poi = imp(bot, poi);
		show_client(lea->fd(), print(
			"�u", bot->name(), "�v����", act_poi, "�V���b�v�|�C���g��������܂����B"
		));
	}
}

// �����o�[�̃X�L�����ꗗ�\���A�܂��͎g���B
SUBCMD_FUNC(Bot, sKill) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) skill_user_show_skills(mem);
	else skill_user_use_skill(lea, args, mem);
}

// �o�[�T�[�N��������ݒ肷��B
SUBCMD_FUNC(Bot, sKillBerserkRate) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int rat = shift_arguments_then_parse_int(
		args, print("������"), 0, 100
	);
	if (!rat)
		show_client(lea->fd(), print(
			"�u", mem->name(), "�v�͏�Ƀo�[�T�[�N���g�p���܂��B"
		));
	else
		show_client(lea->fd(), print(
			"�u", mem->name(), "�v��HP��", rat, "%�����̂Ƃ��Ƀo�[�T�[�N���g�p���܂��B"
		));
	mem->berserk_rate()->set(rat);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̕��푮���t�^���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, sKillEnchantWeapon) {
	CS_ENTER;
	using kew_val_t = std::pair<int,e_element*>;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<kew_val_t> kew_vals;
		mem->kew_elements()->copy(pybot::back_inserter(kew_vals));
		std::sort(ALL_RANGE(kew_vals), [lea] (kew_val_t lval, kew_val_t rval) -> bool {
			return lval.first > rval.first;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̕��푮���t�^ ------\n";
		for (kew_val_t kew_val : kew_vals) {
			int m = kew_val.first;
			e_element* ele = kew_val.second;
			auto map = id_maps.at(m);
			std::string jnam = UNKNOWN_SYMBOL;
			std::string enam = UNKNOWN_SYMBOL;
			if (map) {
				jnam = map->name_japanese;
				enam = map->name_english;
			}
			lea->output_buffer() << jnam << " (" << enam << ") " <<
				ELEMENT_NAME_TABLE[*ele] << "\n";
		}
		lea->output_buffer() << kew_vals.size() << "���̕��푮���t�^��������܂����B\n";
		lea->show_next();
	} else {
		std::string map_str = shift_arguments(args);
		std::string map_str_lc = lowercase(map_str);
		int m;
		if (map_str_lc == THIS_MAP_NAME) m = lea->bl()->m;
		else m = map_mapname2mapid(map_str_lc.c_str());
		if (m < 0) 
			throw command_error{print(
				"�u", map_str, "�v�Ƃ����}�b�vID�͌�����܂���ł����B"
			)};
		auto map = id_maps.at(m);
		if (args.empty()) {
			mem->kew_elements()->unregister(m);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", map->name_japanese, " (", map->name_english, ")"
				"�v�ŕ���ɑ΂��鑮���t�^�������܂���B"
			));
		} else {
			std::string ele_nam = shift_arguments(args);
			auto ele_nam_ite = std::find(ALL_RANGE(ELEMENT_NAME_TABLE), ele_nam);
			if (ele_nam_ite == ELEMENT_NAME_TABLE.end())
				throw command_error{print(
					"�u", ele_nam, "�v�Ƃ��������͂���܂���B"
				)};
			e_element ele = e_element(ele_nam_ite - ELEMENT_NAME_TABLE.begin());
			if (ele == ELE_NEUTRAL)
				throw command_error{print(
					"�u", ELEMENT_NAME_TABLE[ele], "�v�͎w��ł��܂���B"
				)};
			mem->kew_elements()->register_(m, initialize<e_element>(ele));
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", map->name_japanese, " (", map->name_english, ")"
				"�v�ŕ���ɑ΂���u",  ELEMENT_NAME_TABLE[ele], "�v�̕t�^�������܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̕��푮���t�^���N���A����B
SUBCMD_FUNC(Bot, sKillEnchantWeaponClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->kew_elements()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou,
		"���̕��푮���t�^�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̕��푮���t�^��]������B
SUBCMD_FUNC(Bot, sKillEnchantWeaponTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->kew_elements()->import_(mem1->kew_elements().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̕��푮���t�^��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̃X�L������ꎮ���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, sKillEquipSet) {
	CS_ENTER;
	using es_val_t = std::pair<e_skill,skill_equipset*>;
	auto pri_equ_poss = [] (std::vector<ptr<equipset_item>>* itms) -> std::string {
		std::vector<std::string> toks;
		for (auto itm : *itms) toks.push_back(print_equip_pos(itm->equip));
		return concatinate_strings(ALL_RANGE(toks), "+");
	};

	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<es_val_t> es_vals;
		mem->skill_equipsets()->copy(pybot::back_inserter(es_vals));
		std::sort(ALL_RANGE(es_vals), [lea] (es_val_t lval, es_val_t rval) -> bool {
			return lval.first > rval.first;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̃X�L������ꎮ ------\n";
		for (es_val_t es_val : es_vals) {
			e_skill kid = es_val.first;
			skill_equipset* es = es_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), kid) << " - " <<
				skill_get_desc(kid) << " " <<
				es->items.size() << "��"
				"@" << pri_equ_poss(&es->items) << "\n";
		}
		lea->output_buffer() << es_vals.size() << "���̃X�L������ꎮ��������܂����B\n";
		lea->show_next();
	} else {
		std::string sk_nam = shift_arguments(args);
		e_skill kid = e_skill(find_skilldb(sk_nam));
		if (!kid)
			throw command_error{print(
				"�u", sk_nam, "�v�Ƃ����X�L���͂���܂���B"
			)};
		std::string sk_des = skill_get_desc(kid);
		if (!skill_get_inf(kid))
			throw command_error{print(
				"�u", sk_des, "�v�̓A�N�e�B�u�X�L���ł͂���܂���B"
			)};
		int equ = 0;
		auto es = initialize<skill_equipset>(kid);
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
			esi->key->identify = 1;
			es->items.push_back(esi);
			equ |= esi->equip;
		}
		if (es->items.empty()) {
			skill_equipset* old_es = mem->skill_equipsets()->find(kid);
			if (!old_es)
				throw command_error{print(
					"�u", mem->name(), "�v�́u", sk_des, "�v�p�X�L������ꎮ�͂���܂���B"
				)};
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sk_des, "�v�p�X�L������ꎮ�̓o�^�𖕏����܂����B"
			));
			mem->skill_equipsets()->unregister(kid);
		} else {
			mem->skill_equipsets()->register_(kid, es);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sk_des, "�v�p�X�L������ꎮ�Ƃ��āu",
				es->items.size(), "��@", pri_equ_poss(&es->items), "�v�̕����o�^���܂����B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̃X�L������ꎮ���N���A����B
SUBCMD_FUNC(Bot, sKillEquipSetClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->skill_equipsets()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou, "���̃X�L������ꎮ�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̃X�L������ꎮ�����[�h����B
SUBCMD_FUNC(Bot, sKillEquipSetLoad) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	std::string sk_nam = shift_arguments(
		args, "�X�L�����w�肵�Ă��������B"
	);
	e_skill kid = e_skill(find_skilldb(sk_nam));
	if (!kid)
		throw command_error{print(
			"�u", sk_nam, "�v�Ƃ����X�L���͂���܂���B"
		)};
	std::string sk_des = skill_get_desc(kid);
	skill_equipset* es = mem->skill_equipsets()->find(kid);
	if (!es)
		throw command_error{print(
			"�u", mem->name(), "�v�́u", sk_des, "�v�p�X�L������ꎮ�͂���܂���B"
		)};
	mem->load_skill_equipset(kid);
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �u" <<	mem->name() << "�v�����[�h�����u" <<
		sk_des << "�v�p�X�L������ꎮ ------\n";
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
			int inv_ind = mem->find_inventory(*esi->key, esi->equip);
			lea->output_buffer() << ID_PREFIX << esi->key->idb->nameid << " - " <<
				print_item_key(*esi->key) << " "
				"(" << print_equip_type(esi->key->idb);
			if (inv_ind != INT_MIN) {
				lea->output_buffer() << "@" << print_equip_pos(esi->equip);
				++cou;
			}
			lea->output_buffer() << ")";
			if (inv_ind == INT_MIN) lea->output_buffer() << " ���������s";
			lea->output_buffer() << "\n";
		}
	}
	lea->output_buffer() << cou << "�̕���𑕔����܂����B";
	lea->show_next();
	if (mem != lea) {
		clif_emotion(mem->bl(), ET_HNG);
		mem->last_reloaded_equipset_tick() = now;
	}
}

// �����o�[�̃X�L������ꎮ��]������B
SUBCMD_FUNC(Bot, sKillEquipSetTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->skill_equipsets()->import_(mem1->skill_equipsets().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̃X�L������ꎮ��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̗D��X�L�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, sKillFirst) {
	CS_ENTER;
	using fs_val_t = std::pair<int,e_skill*>;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<fs_val_t> fs_vals;
		mem->first_skills()->copy(pybot::back_inserter(fs_vals));
		std::sort(ALL_RANGE(fs_vals), [lea] (fs_val_t lval, fs_val_t rval) -> bool {
			return lval.first > rval.first;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̗D��X�L�� ------\n";
		for (fs_val_t fs_val : fs_vals) {
			int mid = fs_val.first;
			e_skill* kid = fs_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				print_mobdb(mid) << " ; " <<
				ID_PREFIX << print(std::setw(5), std::setfill('0'), *kid) << " - " <<
				skill_get_desc(*kid) << "\n";
		}
		lea->output_buffer() << fs_vals.size() << "���̗D��X�L����������܂����B\n";
		lea->show_next();
	} else {
		std::string mob_nam = shift_arguments(args);
		int mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		std::string mob_str = print_mobdb(mid);
		if (args.empty()) {
			e_skill* old_kid = mem->first_skills()->find(mid);
			if (!old_kid)
				throw command_error{print(
					"�u", mob_nam, "�v�p�D��X�L���͌�����܂���ł����B"
				)};
			mem->first_skills()->unregister(mid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str,
				"�v�p�D��X�L���̓o�^�𖕏����܂����B"
			));
		} else {
			if (mid < MM_BASE ||
				mid >= MM_CAUTION
			) throw command_error{print("�u", mob_str, "�v�͎w��ł��܂���B")};
			std::string sk_nam = shift_arguments(args);
			e_skill kid = e_skill(find_skilldb(sk_nam));
			if (!kid)
				throw command_error{print(
					"�u", sk_nam, "�v�Ƃ����X�L���͂���܂���B"
				)};
			std::string sk_des = skill_get_desc(kid);
			if ((!(skill_get_inf(kid) & INF_ATTACK_SKILL) &&
					!(skill_get_inf(kid) & INF_GROUND_SKILL) &&
					!(skill_get_inf(kid) & INF_SUPPORT_SKILL)
				) || skill_get_inf2(kid) & INF2_PARTY_ONLY ||
				skill_get_inf2(kid) & INF2_GUILD_ONLY
			) throw command_error{print(
				"�u", sk_des, "�v�͎w��ł��܂���B"
			)};
			if (!mem->check_skill(kid))
				throw command_error{print(
					"�u", mem->name(), "�v�́u", sk_des, "�v���g���܂���B"
				)};
			mem->first_skills()->register_(mid, initialize<e_skill>(kid));
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v�p�D��X�L����"
				"�u", sk_des, "�v��o�^���܂����B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̗D��X�L�����N���A����B
SUBCMD_FUNC(Bot, sKillFirstClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->first_skills()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou,
		"���̗D��X�L���̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̗D��X�L����]������B
SUBCMD_FUNC(Bot, sKillFirstTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->first_skills()->import_(mem1->first_skills().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̗D��X�L����]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̃X�L�����������X�^�[���ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, sKillIgnoreMonster) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<int> kims;
		mem->skill_ignore_mobs()->copy(pybot::back_inserter(kims));
		std::sort(ALL_RANGE(kims));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̃X�L�����������X�^�[ ------\n";
		for (int kim : kims) {
			e_skill kid = e_skill(SKILL_FROM_KIM(kim));
			int mid = MOB_FROM_KIM(kim);
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), kid) << " - " <<
				skill_get_desc(kid) << " ; " <<
				ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				print_mobdb(mid) << "\n";
		}
		lea->output_buffer() << kims.size() << "���̃X�L�����������X�^�[��������܂����B\n";
		lea->show_next();
	} else {
		std::string sk_nam = shift_arguments(args);
		e_skill kid = e_skill(find_skilldb(sk_nam));
		std::string sk_des = skill_get_desc(kid);
		if (skill_get_inf2(kid) & INF2_PARTY_ONLY ||
			skill_get_inf2(kid) & INF2_GUILD_ONLY
		) throw command_error{print(
			"�u", sk_des, "�v�͎w��ł��܂���B"
		)};
		std::string mob_nam = shift_arguments(args, "�����X�^�[���w�肵�Ă��������B");
		int mid = find_mobdb(mob_nam);
		if (!mid)
			throw command_error{print(
				"�u", mob_nam, "�v�Ƃ��������X�^�[�͌�����܂���ł����B"
			)};
		std::string mob_str = print_mobdb(mid);
		if (mid < MM_BASE ||
			mid >= MM_CAUTION
		) throw command_error{print("�u", mob_str, "�v�͎w��ł��܂���B")};
		int kim = SKILL_IGNORE_MOB(kid, mid);
		if (mem->skill_ignore_mobs()->find(kim)) {
			mem->skill_ignore_mobs()->unregister(kim);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sk_des, "�v���u", mob_str, "�v�Ɏg���܂��B"
			));
		} else {
			if (!mem->check_skill(kid))
				throw command_error{print(
					"�u", mem->name(), "�v�́u", sk_des, "�v���g���܂���B"
				)};
			mem->skill_ignore_mobs()->register_(kim);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sk_des, "�v���u", mob_str, "�v�Ɏg���܂���B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̃X�L�����������X�^�[���N���A����B
SUBCMD_FUNC(Bot, sKillIgnoreMonsterClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->skill_ignore_mobs()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou,
		"���̃X�L�����������X�^�[�̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̃X�L�����������X�^�[��]������B
SUBCMD_FUNC(Bot, sKillIgnoreMonsterTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->skill_ignore_mobs()->import_(mem1->skill_ignore_mobs().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̃X�L�����������X�^�[��]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̃A�N�e�B�u�X�L���𐧌�����B
SUBCMD_FUNC(Bot, sKillLimit) {
	CS_ENTER;
	skill_user_limit_skill(lea, args, shift_arguments_then_find_member(lea, args));
}

// �g�p����ő�̉r�����Ԃ�ݒ肷��B
SUBCMD_FUNC(Bot, sKillmaXCastTime) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cas_tim = shift_arguments_then_parse_int(
		args, print("�r������"), 0, INT_MAX
	);
	if (cas_tim)
		show_client(lea->fd(), print(
			"�u", mem->name(), "�v�̓X�L���̎��r�����Ԃ�", cas_tim, "�~���b�ȉ��Ȃ�g�p���܂��B"
		));
	else
		show_client(lea->fd(), print(
			"�u", mem->name(), "�v�̓X�L���̎��r�����Ԃ��ǂ�Ȃɒ����Ă��g�p���܂��B"
		));
	mem->max_cast_time()->set(cas_tim);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �͈̓X�L���̔��������ƂȂ郁���o�[����ݒ肷��B
SUBCMD_FUNC(Bot, sKillmemBers) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = shift_arguments_then_parse_int(
		args, print("�����o�[��"), 1,	INT_MAX
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�͈̔̓X�L���̔��������ƂȂ郁���o�[����",
		cou, "�l�ɂ��܂����B"
	));
	if (cou == DEFAULT_SKILL_MEMBERS) cou = 0;
	mem->skill_members()->set(cou);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �͈̓X�L���̔��������ƂȂ郂���X�^�[����ݒ肷��B
SUBCMD_FUNC(Bot, sKillMonsters) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = shift_arguments_then_parse_int(
		args, print("�����X�^�[��"), 1,	INT_MAX
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�͈̔̓X�L���̔��������ƂȂ郂���X�^�[����",
		cou, "�C�ɂ��܂����B"
	));
	if (cou == DEFAULT_SKILL_MOBS) cou = 0;
	mem->skill_mobs()->set(cou);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̉��t�X�L�����ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, sKillPlay) {
	CS_ENTER;
	using ps_val_t = std::pair<int,play_skill*>;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if ((mem->sd()->class_ & MAPID_UPPERMASK) != MAPID_BARDDANCER &&
		mem->sd()->status.class_ != JOB_PALADIN
	) throw command_error{print(
		"�u", mem->name(), "�v�̓o�[�h�E�_���T�[�n�A�܂��̓p���f�B���ł͂���܂���B"
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
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̉��t�X�L�� ------\n";
		for (ps_val_t ps_val : ps_vals) {
			int mid = ps_val.first;
			play_skill* ps = ps_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), mid) << " - " <<
				print_mobdb(mid) << " ; " <<
				ID_PREFIX << print(std::setw(5), std::setfill('0'), ps->skill_id) << " - " <<
				skill_get_desc(ps->skill_id) << "\n";
		}
		lea->output_buffer() << ps_vals.size() << "���̉��t�X�L����������܂����B\n";
		lea->show_next();
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
			e_skill kid = e_skill(find_skilldb(sk_nam));
			if (!kid)
				throw command_error{print(
					"�u", sk_nam, "�v�Ƃ����X�L���͂���܂���B"
				)};
			std::string sk_des = skill_get_desc(kid);
			if ((!(skill_get_inf2(kid) & INF2_SONG_DANCE) &&
					!(skill_get_inf2(kid) & INF2_ENSEMBLE_SKILL) &&
					kid != PA_GOSPEL
				) || kid == PR_BENEDICTIO
			) throw command_error{print(
				"�u", sk_des, "�v�͉��t�X�L���ł͂���܂���B"
			)};
			auto ps = construct<play_skill>(mid, e_skill(kid));
			mem->play_skills()->register_(mid, ps);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", mob_str, "�v�p���t�X�L����"
				"�u", sk_des, "�v��o�^���܂����B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̉��t�X�L�����N���A����B
SUBCMD_FUNC(Bot, sKillPlayClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if ((mem->sd()->class_ & MAPID_UPPERMASK) != MAPID_BARDDANCER &&
		mem->sd()->status.class_ != JOB_PALADIN
	) throw command_error{print(
		"�u", mem->name(), "�v�̓o�[�h�E�_���T�[�n�A�܂��̓p���f�B���ł͂���܂���B"
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
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	if ((mem1->sd()->class_ & MAPID_UPPERMASK) != MAPID_BARDDANCER &&
		mem1->sd()->status.class_ != JOB_PALADIN
	) throw command_error{print(
		"�u", mem1->name(), "�v�̓o�[�h�E�_���T�[�n�A�܂��̓p���f�B���ł͂���܂���B"
	)};
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if ((mem2->sd()->class_ & MAPID_UPPERMASK) != MAPID_BARDDANCER &&
		mem2->sd()->status.class_ != JOB_PALADIN
	) throw command_error{print(
		"�u", mem2->name(), "�v�̓o�[�h�E�_���T�[�n�A�܂��̓p���f�B���ł͂���܂���B"
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
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<int> kids;
		mem->reject_skills()->copy(pybot::back_inserter(kids));
		std::sort(ALL_RANGE(kids));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" << mem->name() << "�v�̋��ۃX�L�� ------\n";
		for (int kid : kids)
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), kid) <<
				" - " << skill_get_desc(kid) << "\n";
		lea->output_buffer() << kids.size() << "���̃X�L����������܂����B\n";
		lea->show_next();
	} else {
		std::string sk_nam = shift_arguments(args);
		int kid = find_skilldb(sk_nam);
		if (!kid) throw command_error{print(
			"�u", sk_nam, "�v�Ƃ����X�L���͂���܂���B"
		)};
		std::string sk_des = skill_get_desc(kid);
		if (!(skill_get_inf(kid) & INF_SELF_SKILL) &&
			!(skill_get_inf(kid) & INF_SUPPORT_SKILL) &&
			!(skill_get_inf2(kid) & (INF2_PARTY_ONLY | INF2_GUILD_ONLY)) &&
			kid != PR_BENEDICTIO
		) throw command_error{print(
			"�u", sk_des, "�v�͎��ȃX�L���A�܂��̓^�[�Q�b�g�x���X�L���ł͂���܂���B"
		)};
		if (mem->reject_skills()->find(e_skill(kid))) {
			mem->reject_skills()->unregister(e_skill(kid));
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sk_des, "�v�����ۂ��܂���B"
			));
		} else {
			mem->reject_skills()->register_(e_skill(kid));
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sk_des, "�v�����ۂ��܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̋��ۃX�L�����N���A����B
SUBCMD_FUNC(Bot, sKillRejectClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->reject_skills()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou, "���̋��ۃX�L���̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̋��ۃX�L����]������B
SUBCMD_FUNC(Bot, sKillRejectTransport) {
	CS_ENTER;
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

// ���S�ɉr���ł��鎞�Ԃ�ݒ肷��B
SUBCMD_FUNC(Bot, sKillSafeCastTime) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cas_tim = shift_arguments_then_parse_int(
		args, print("�r������"), 0, INT_MAX
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v�̓X�L���̎��r�����Ԃ�", cas_tim, "�~���b�ȉ��Ȃ烂���X�^�[�Ƀ^�[�Q�b�g����Ă��Ă��g�p���܂��B"
	));
	mem->safe_cast_time()->set(cas_tim);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// HP�̋�����������HP����ݒ肷��B
SUBCMD_FUNC(Bot, sKillSupplyHpRate) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int rat = shift_arguments_then_parse_int(
		args, print("HP��"), 1, 100
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��HP��", rat, "%�����̂Ƃ���HP�̋����������܂��B"
	));
	if (rat == DEFAULT_SUPPLY_HP_RATE) rat = 0;
	mem->supply_hp_rate()->set(rat);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// SP�̋�����������SP����ݒ肷��B
SUBCMD_FUNC(Bot, sKillSupplySpRate) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int rat = shift_arguments_then_parse_int(
		args, print("SP��"), 1, 100
	);
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��SP��", rat, "%�����̂Ƃ���SP�̋����������܂��B"
	));
	if (rat == DEFAULT_SUPPLY_SP_RATE) rat = 0;
	mem->supply_sp_rate()->set(rat);
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̊|���������Ԃ��ꗗ�\���A�܂��͓o�^�A�܂��͖�������B
SUBCMD_FUNC(Bot, sKillTail) {
	CS_ENTER;
	using tai_val_t = std::pair<e_skill,int*>;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<tai_val_t> tai_vals;
		mem->skill_tails()->copy(pybot::back_inserter(tai_vals));
		std::sort(ALL_RANGE(tai_vals), [] (tai_val_t lval, tai_val_t rval) -> bool {
			return lval.first < rval.first;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" << mem->name() << "�v�̊|���������� ------\n";
		for (const tai_val_t& tai_val : tai_vals) {
			e_skill kid = tai_val.first;
			int dur = *tai_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), kid) <<
				" - " << skill_get_desc(kid) << " " << dur << "�~���b�O\n";
		}
		lea->output_buffer() << tai_vals.size() << "���̊|���������Ԃ�������܂����B\n";
		lea->show_next();
	} else {
		std::string sk_nam = shift_arguments(args);
		e_skill kid = e_skill(find_skilldb(sk_nam));
		if (!kid) throw command_error{print(
			"�u", sk_nam, "�v�Ƃ����X�L���͂���܂���B"
		)};
		std::string sk_des = skill_get_desc(kid);
		if (!(skill_get_inf(kid) & (INF_SELF_SKILL | INF_SUPPORT_SKILL)) &&
			kid != PR_BENEDICTIO
		) throw command_error{print(
			"�u", sk_des, "�v�͎x���X�L���ł͂���܂���B"
		)};
		if (!skill_get_time(kid, 1) &&
			!skill_get_time2(kid, 1)
		) throw command_error{print(
			"�u", sk_des, "�v�ɂ͌��ʎ��Ԃ�����܂���B"
		)};
		if (args.empty()) {
			mem->skill_tails()->unregister(kid);
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sk_des, "�v�����ʂ��؂�Ă���|�������܂��B"
			));
		} else {
			if (!mem->check_skill(e_skill(kid)))
				throw command_error{print(
					"�u", mem->name(), "�v�́u",
					sk_des, "�v���g���܂���B"
				)};
			int dur = shift_arguments_then_parse_int(
				args, print("�|����������"), 1, INT_MAX
			);
			mem->skill_tails()->register_(kid, initialize<int>(dur));
			show_client(lea->fd(), print(
				"�u", mem->name(), "�v�́u", sk_des, "�v�����ʂ��؂��", dur, "�~���b�O�Ɋ|�������܂��B"
			));
		}
		if (mem != lea) clif_emotion(mem->bl(), ET_OK);
	}
}

// �����o�[�̊|���������Ԃ��N���A����B
SUBCMD_FUNC(Bot, sKillTailClear) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int cou = mem->skill_tails()->clear();
	show_client(lea->fd(), print(
		"�u", mem->name(), "�v��", cou, "���̊|���������Ԃ̓o�^�𖕏����܂����B"
	));
	if (mem != lea) clif_emotion(mem->bl(), ET_OK);
}

// �����o�[�̊|���������Ԃ�]������B
SUBCMD_FUNC(Bot, sKillTailTransport) {
	CS_ENTER;
	block_if* mem1 = shift_arguments_then_find_member(lea, args);
	block_if* mem2 = shift_arguments_then_find_member(lea, args);
	if (mem1 == mem2) throw command_error{"���������o�[�ł��B"};
	int cou = mem2->skill_tails()->import_(mem1->skill_tails().get());
	show_client(lea->fd(), print(
		"�u", mem1->name(), "�v����u", mem2->name(), "�v��",
		cou, "���̊|���������Ԃ�]�����܂����B"
	));
	if (mem2 != lea) clif_emotion(mem2->bl(), ET_OK);
}

// �����o�[�̃X�L�����x�����グ��B
SUBCMD_FUNC(Bot, sKillUp) {
	CS_ENTER;
	skill_user_skill_up(lea, args, shift_arguments_then_find_member(lea, args));
}

// �����o�[�̃X�e�[�^�X��\������B
SUBCMD_FUNC(Bot, Status) {
	CS_ENTER;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �u" << mem->name() << "�v�̃X�e�[�^�X ------\n";
	lea->output_buffer() << "BaseLv " << mem->sd()->status.base_level << " ";
	lea->output_buffer() << "(" << mem->sd()->status.base_exp << "/" << pc_nextbaseexp(mem->sd()) <<	" " <<
		print(
			std::fixed,
			std::setprecision(1),
			mem->sd()->status.base_exp * 100. / pc_nextbaseexp(mem->sd())
		) << "%) ";
	lea->output_buffer() << "JobLv " << mem->sd()->status.job_level << " ";
	if (!pc_is_maxjoblv(mem->sd()))
		lea->output_buffer() << "(" << mem->sd()->status.job_exp << "/" << pc_nextjobexp(mem->sd()) << " " <<
			print(
				std::fixed,
				std::setprecision(1),
				mem->sd()->status.job_exp * 100. / pc_nextjobexp(mem->sd())
			) << "%) ";
	lea->output_buffer() << "Status Point " << mem->sd()->status.status_point << " "
		"(��+" << pc_readglobalreg(mem->sd(), add_str(pybot::EXTRA_STATUS_POINT.c_str()));
	if (pc_readglobalreg(mem->sd(), add_str(pybot::MVP_MANIA_ENHANCE.c_str())))
		lea->output_buffer() << "E";
	lea->output_buffer() << ") Shop Point " << print_zeny(mem->sd()->cashPoints) << " "
		"(" << pc_readglobalreg(mem->sd(), add_str(CASH_EXP.c_str())) << "/" << MAX_LEVEL_BASE_EXP << ")";
	lea->output_buffer() << "\n";
	int inv_num = MAX_INVENTORY - pc_inventoryblank(mem->sd());
	lea->output_buffer() << STORAGE_TYPE_NAME_TABLE[TABLE_INVENTORY - 1] << " " <<
		inv_num << "/" << MAX_INVENTORY << " "
		"(" << (mem->sd()->weight / 10.) << "/" << (mem->sd()->max_weight / 10.) <<	" " <<
		print(
			std::fixed,
			std::setprecision(1),
			mem->sd()->weight * 100. / mem->sd()->max_weight
		) << "% "
		"��*" << mem->check_skill(ALL_INCCARRY) << ") ";
	if (mem->is_carton()) {
		status_calc_cart_weight(mem->sd(), CALCWT_ITEM);
		lea->output_buffer() << STORAGE_TYPE_NAME_TABLE[TABLE_CART - 1] << " " <<
			mem->sd()->cart_num << "/" << MAX_CART << " "
			"(" << (mem->sd()->cart_weight / 10.) << "/" << (mem->sd()->cart_weight_max / 10.) << " " <<
			print(
				std::fixed,
				std::setprecision(1),
				mem->sd()->cart_weight * 100. / mem->sd()->cart_weight_max
			) << "%) ";
	}
	lea->output_buffer() << "Zeny " << print_zeny(mem->sd()->status.zeny) << "\n";
	lea->output_buffer() << print_main_status(mem->sd());
	lea->output_buffer() << print_sc(mem->sc()) << "\n";
	lea->show_next();
}

// �����o�[���X�e�[�^�X�Ƀ|�C���g������U��B
SUBCMD_FUNC(Bot, StatusUp) {
	CS_ENTER;
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
	CS_ENTER;
	using itm_val_t = std::pair<int,int*>;
	block_if* mem = shift_arguments_then_find_member(lea, args);
	if (args.empty()) {
		std::vector<itm_val_t> itm_vals;
		mem->storage_get_items()->copy(pybot::back_inserter(itm_vals));
		std::sort(ALL_RANGE(itm_vals), [] (itm_val_t lval, itm_val_t rval) -> bool {
			return lval.first < rval.first;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" << mem->name() << "�v�̑q�ɕ�[�A�C�e�� ------\n";
		for (itm_val_t itm_val : itm_vals) {
			int nid = itm_val.first;
			int amo = *itm_val.second;
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << " (" << amo << ")\n";
		}
		lea->output_buffer() << itm_vals.size() << "���̃A�C�e����������܂����B\n";
		lea->show_next();
	} else {
		std::string idb_nam = shift_arguments(args);
		int nid = find_itemdb(idb_nam);
		if (!nid)
			throw command_error{print(
				"�u", idb_nam, "�v�Ƃ����A�C�e���͂���܂���B"
			)};
		if (nid >= ITEM_TYPE_OFFSET &&
			nid < ITEM_TYPE_OFFSET + IT_MAX
		) throw command_error{print(
				"��ނ��w�肷�邱�Ƃ͂ł��܂���B"
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
	CS_ENTER;
	ptr<storage_context> sto_con;
	switch (lea->sd()->state.storage_flag) {
	case 0: throw command_error{"�q�ɂ��J���Ă��������B"};
	case 2: sto_con = construct<guild_storage_context>(lea->sd()); break;
	default: sto_con = construct<private_storage_context>(lea->sd());
	}
	lea->output_buffer() = std::stringstream();
	int tot_cou = 0;
	int tot_amo = 0;
	lea->output_buffer() << "------ �q�ɂ����[�����A�C�e�� ------\n";
	for (block_if* mem : lea->members()) {
		bool done = false;
		ptr<storage_context> mem_con;
		if (mem->is_carton()) mem_con = construct<cart_context>(mem->sd());
		else mem_con = construct<inventory_context>(mem->sd());
		mem->storage_get_items()->iterate(
			[lea, sto_con, &tot_cou, &tot_amo, mem, &done, mem_con] (int nid, int* amo) -> bool {
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
					lea->output_buffer() << INDEX_PREFIX << mem->member_index() << " " <<
						ID_PREFIX << mem->char_id() << " - " <<
						mem->name() << " ; " <<
						ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
						print_itemdb(nid) << " (" << com << ")";
					if (!suc) lea->output_buffer() << " ����[���s";
					else if (mem_amo + com < *amo) lea->output_buffer() << " ���݌ɕs��";
					lea->output_buffer() << "\n";
				}
				return true;
			}
		);
		if (done) clif_emotion(mem->bl(), ET_GO);
	}
	lea->output_buffer() << "���v" << tot_cou << "���A" << tot_amo <<
		"�̃A�C�e�������o���܂����B\n";
	lea->show_next();
}

// �����o�[�̑q�ɕ�[�A�C�e�����N���A����B
SUBCMD_FUNC(Bot, StorageGetClear) {
	CS_ENTER;
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
	CS_ENTER;
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
	CS_ENTER;
	if (args.empty()) {
		std::vector<int> nids;
		lea->storage_put_items()->copy(pybot::back_inserter(nids));
		std::sort(ALL_RANGE(nids));
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �q�Ɋi�[�A�C�e�� ------\n";
		for (int nid : nids) {
			lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - " <<
				print_itemdb(nid) << "\n";
		}
		lea->output_buffer() << nids.size() << "���̃A�C�e����������܂����B\n";
		lea->show_next();
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

// �o�^�ς݂̃A�C�e�������ׂđq�ɂɊi�[����B
SUBCMD_FUNC(Bot, StoragePutAll) {
	CS_ENTER;
	ptr<storage_context> sto_con;
	switch (lea->sd()->state.storage_flag) {
	case 0: throw command_error{"�q�ɂ��J���Ă��������B"};
	case 2: sto_con = construct<guild_storage_context>(lea->sd()); break;
	default: sto_con = construct<private_storage_context>(lea->sd());
	}
	int tot_cou = 0;
	int tot_amo = 0;
	auto put_itm = [lea, sto_con, &tot_cou, &tot_amo] (
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
			) && ((!itm->card[0] &&
					!itm->card[3]
				) || itm->card[0] == CARD0_CREATE
			) && !itm->refine
		) {
			int nid = itm->nameid;
			if (itm->card[0] == CARD0_CREATE &&
				pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST)
			) nid += FAME_OFFSET;
			if (lea->storage_put_items()->find(nid) ||
				lea->storage_put_items()->find(ITEM_TYPE_OFFSET + idb->type)
			) {
				res = (!itm->equip ||
						pc_unequipitem(mem->sd(), ind, 1)
					) && sto_con->add(itm, itm->amount);
				if (res) {
					++tot_cou;
					tot_amo += itm->amount;
				}
				lea->output_buffer() << INDEX_PREFIX << mem->member_index() << " " <<
					ID_PREFIX << mem->char_id() << " - " <<
					mem->name() << " ; " <<
					STORAGE_TYPE_NAME_TABLE[sto_typ - 1] << " " <<
					INDEX_PREFIX << print(std::setw(ind_wid), std::setfill('0'), ind) << " " << 
					ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
					print_item(itm, idb);
				if (!res) lea->output_buffer() << " ���i�[���s";
				lea->output_buffer() << "\n";
			}
		}
		return res;
	};
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �q�ɂɊi�[�����A�C�e�� ------\n";
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
	lea->output_buffer() << "���v" << tot_cou << "���A" <<
		tot_amo << "�̃A�C�e�������܂����B\n";
	lea->show_next();
}

// �q�Ɋi�[�A�C�e�����N���A����B
SUBCMD_FUNC(Bot, StoragePutClear) {
	CS_ENTER;
	int cou = lea->storage_put_items()->clear();
	show_client(lea->fd(), print(
		cou, "���̑q�Ɋi�[�A�C�e���̓o�^�𖕏����܂����B"
	));
}

// �q�Ɋi�[�A�C�e������荞�ށB
SUBCMD_FUNC(Bot, StoragePutImport) {
	CS_ENTER;
	block_if* bot = shift_arguments_then_find_bot(lea, args);
	t_tick hev_tic = lea->next_heavy_tick();
	if (hev_tic)
		throw command_error{print(
			"StoragePutImport�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	auto bot_sto_put_itms = construct<registry_t<int>>(
		load_storage_put_item_func(bot->char_id()),
		insert_storage_put_item_func(bot->char_id()),
		delete_storage_put_item_func(bot->char_id()),
		clear_storage_put_item_func(bot->char_id())
	);
	int cou = lea->storage_put_items()->import_(bot_sto_put_itms.get());
	show_client(lea->fd(), print(
		"�u", bot->name(), "�v����", cou,
		"���̑q�Ɋi�[�A�C�e������荞�݂܂����B"
	));
	lea->last_heavy_tick() = now;
}

// �������Ă���A�C�e�������ׂđq�Ɋi�[�A�C�e���Ƃ��ēo�^����B
SUBCMD_FUNC(Bot, StoragePutHave) {
	CS_ENTER;
	int tot_cou = 0;
	auto reg_itm = [lea, &tot_cou] (
		block_if* mem,
		storage_type sto_typ,
		int ind,
		int ind_wid,
		item* itm,
		item_data* idb = nullptr
	) {
		if (itm->nameid &&
			(!itm->equip ||
				itemdb_isstackable2(idb)
			) && ((!itm->card[0] &&
					!itm->card[3]
				) || itm->card[0] == CARD0_CREATE
			) && !itm->refine
		) {
			int nid = itm->nameid;
			if (itm->card[0] == CARD0_CREATE &&
				pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST)
			) nid += FAME_OFFSET;
			if (!idb) idb = itemdb_exists(itm->nameid);
			if ((!idb->equip ||
					!itm->identify
				) && idb->jname[0] != '@' &&
				!lea->storage_put_items()->find(nid)
			) {
				lea->storage_put_items()->register_(nid);
				lea->output_buffer() << INDEX_PREFIX << mem->member_index() << " " <<
					ID_PREFIX << mem->char_id() << " - " <<
					mem->name() << " ; " <<
					STORAGE_TYPE_NAME_TABLE[sto_typ - 1] << " " <<
					ID_PREFIX << print(std::setw(5), std::setfill('0'), itm->nameid) << " - " <<
					print_itemdb(nid) << "\n";
				++tot_cou;
			}
		}
	};
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �o�^�����q�Ɋi�[�A�C�e�� ------\n";
	for (block_if* mem : lea->members()) {
		bool done = false;
		int ind_wid = print(MAX_INVENTORY - 1).length();
		for (int i = 0; i < MAX_INVENTORY; ++i) {
			item* itm = &mem->sd()->inventory.u.items_inventory[i];
			item_data* idb = mem->sd()->inventory_data[i];
			reg_itm(mem, TABLE_INVENTORY, i, ind_wid, itm, idb);
		}
		if (mem->is_carton()) {
			ind_wid = print(MAX_CART - 1).length();
			for (int i = 0; i < MAX_CART; ++i) {
				item* itm = &mem->sd()->cart.u.items_cart[i];
				reg_itm(mem, TABLE_CART, i, ind_wid, itm);
			}
		}
	}
	lea->output_buffer() << tot_cou << "���̑q�Ɋi�[�A�C�e����o�^���܂����B\n";
	lea->show_next();
}

// Bot�������񂹂�B
SUBCMD_FUNC(Bot, sUmmon) {
	CS_ENTER;
	int cou = 0;
	std::vector<block_if*> bots;
	if (args.empty()) {
		for (auto bot : lea->bots()) bots.push_back(bot.get());
	} else {
		while (!args.empty()) {
			try {
				bots.push_back(shift_arguments_then_find_bot(lea, args));
			} catch (const command_error&) {}
		}
	}
	for (block_if* bot : bots) {
		if (!bot->is_dead()) {
			bot->teleport(&lea->center());
			++cou;
		}
	}
	show_client(lea->fd(), print(cou, "�l��Bot�������񂹂܂����B"));
}

// �����o�[���ꗗ�\������B
SUBCMD_FUNC(Bot, Team) {
	CS_ENTER;
	auto pri_mem = [] (block_if* mem) -> std::string {
		std::stringstream buf;
		buf << INDEX_PREFIX << mem->member_index() << " " <<
		       ID_PREFIX << mem->char_id() << " - "
		       "BLv " << print(std::setw(2), std::setfill('0'), mem->sd()->status.base_level) << " "
		       "JLv " << print(std::setw(2), std::setfill('0'), mem->sd()->status.job_level ) << " "
		       "HP "  << print(std::setw(3), std::setfill('0'), mem->hp_ratio()             ) << "% "
		       "SP "  << print(std::setw(3), std::setfill('0'), mem->sp_ratio()             ) << "% " <<
		       mem->name() << " " <<
		       "<"    << job_name(mem->sd()->status.class_) << "> "
		       "W "   << (mem->sd()->weight * 100 / mem->sd()->max_weight) << "% "
		       "Z "   << print_zeny(mem->sd()->status.zeny) << " "
		       "Sh "  << print_zeny(mem->sd()->cashPoints) << " "
		       "("    << mem->min_distance_value() << "-" << mem->max_distance_value() << ")\n";
		return buf.str();
	};

	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ ���݂̃`�[�� ------\n";
	for (block_if* mem : lea->members()) lea->output_buffer() << pri_mem(mem);
	lea->output_buffer() << lea->members().size() << "�l�̃����o�[��������܂����B\n";
	lea->show_next();
}

// �`�[�������O�C������B
SUBCMD_FUNC(Bot, TeamLogIn) {
	CS_ENTER;
	if (!lea->bots().empty())
		throw command_error{"���Ȃ��͂��łɃ`�[����Ґ����Ă��܂��B"};
	if (lea->is_dead())
		throw command_error{"���S������Ԃ�Bot�����O�C�������邱�Ƃ͂ł��܂���B"};
	t_tick hev_tic = lea->next_heavy_tick();
	if (hev_tic)
		throw command_error{print(
			"TeamLogIn�T�u�R�}���h�����s�ł���悤�ɂȂ�܂ł���", print_tick(hev_tic + 1000), "�ł��B"
		)};
	int num = 0;
	if (!args.empty()) num = shift_arguments_then_parse_int(args, "�`�[���̔ԍ�", 0, TEAM_MAX - 1);
	team_t* tea = lea->teams()->find(num);
	lea->members().clear();
	int lim = bot_limit(lea->sd());
	if (tea) {
		for (auto mem : tea->members) {
			if (mem->char_id == lea->char_id()) lea->members().push_back(lea);
			else
				query_login_data(mem->char_id,
					[lea, mem, lim] (int bot_aid, int bot_sex, int bot_gid, int unb_tim, int sta, const std::string& nam) {
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
							else if (lea->bots().size() < lim) {
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
	lea->last_heavy_tick() = now;
	show_client(lea->fd(), print(lea->bots().size(), "�l��Bot�����O�C�����܂����B"));
}

// �`�[�������O�A�E�g����B
SUBCMD_FUNC(Bot, TeamLogOut) {
	CS_ENTER;
	if (lea->bots().empty())
		throw command_error{"���Ȃ��͂܂��`�[����Ґ����Ă��܂���B"};
	lea->save_team(0);
	lea->stay() = false;
	lea->passive() = false;
	show_client(lea->fd(), print(
		lea->bots().size(), "�l��Bot�����O�A�E�g���܂����B"
	));
	lea->members().clear();
	lea->members().push_back(lea);
	lea->update_member_indices();
	lea->bots().clear();
	lea->last_heavy_tick() = now;
}

// �`�[�����ꗗ�\������A�܂��͓o�^����A�܂��͓o�^�𖕏�����B
SUBCMD_FUNC(Bot, TeamNumber) {
	CS_ENTER;
	using tea_val_t = std::pair<int,team_t*>;

	int num_wid = print(TEAM_MAX - 1).length();
	if (args.empty()) {
		std::vector<tea_val_t> tea_vals;
		lea->teams()->copy(pybot::back_inserter(tea_vals));
		std::sort(ALL_RANGE(tea_vals), [lea] (tea_val_t lval, tea_val_t rval) -> bool {
			return lval.first < rval.first;
		});
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �`�[�� ------\n";
		for (tea_val_t tea_val : tea_vals) {
			int num = tea_val.first;
			team_t* tea = tea_val.second;
			lea->output_buffer() << print(std::setw(num_wid), std::setfill('0'), num) << " - ";
			for (int i = 0; i < tea->members.size(); ++i) {
				auto mem = tea->members[i];
				if (i) lea->output_buffer() << " / ";
				lea->output_buffer() << mem->name;
			}
			lea->output_buffer() << "\n";
		}
		lea->output_buffer() << tea_vals.size() << "���̃`�[����������܂����B\n";
		lea->show_next();
	} else {
		int num = shift_arguments_then_parse_int(args, "�`�[���̔ԍ�", 1, TEAM_MAX - 1);
		if (lea->bots().empty()) {
			lea->teams()->unregister(num);
			show_client(
				lea->fd(),
				print("�`�[��", num, "�̓o�^�𖕏����܂����B")
			);
		} else {
			lea->save_team(num);
			show_client(
				lea->fd(),
				print("���݂̕Ґ����`�[��", num, "�ɓo�^���܂����B")
			);
		}
	}
}

// �����o�[�̏��Ԃ�ύX����B
SUBCMD_FUNC(Bot, TeamOrder) {
	CS_ENTER;
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
	CS_ENTER;
	if (lea->bots().empty())
		throw command_error{"���Ȃ��͂܂��`�[����Ґ����Ă��܂���B"};
	lea->passive() = !lea->passive();
	if (lea->passive())
		show_client(lea->fd(), "���Ȃ��̃`�[���̓����X�^�[�ɔ������܂���B");
	else show_client(lea->fd(), "���Ȃ��̃`�[���̓����X�^�[�ɔ������܂��B");
}

// ���b�V�����[�h�ɂȂ�A�܂��͉�������B
SUBCMD_FUNC(Bot, TeamRush) {
	CS_ENTER;
	static const std::array<std::string, RM_MAX> MESS = {
		"���Ȃ��̃`�[���̓��b�V�����[�h���������܂����B",
		"���Ȃ��̃`�[���̓����X�^�[�������ɍU�����܂��B",
		"���Ȃ��̃`�[���̓����X�^�[��S�͂ōU�����܂��B",
	};
	auto& rush = lea->rush();
	rush->set(rush_modes((rush->get() + 1) % RM_MAX));
	show_client(lea->fd(), MESS[rush->get()]);
}

// �`�[�����ҋ@�A�܂��͒Ǐ]����B
SUBCMD_FUNC(Bot, TeamStay) {
	CS_ENTER;
	if (lea->bots().empty())
		throw command_error{"���Ȃ��͂܂��`�[����Ґ����Ă��܂���B"};
	lea->stay() = !lea->stay();
	if (lea->stay())
		show_client(lea->fd(), "���Ȃ��̃`�[���͂��̏�őҋ@���܂��B");
	else show_client(lea->fd(), "���Ȃ��̃`�[���͂��Ȃ���ǂ������܂��B");
}

// Bot���A�C�e��������ɒǉ�����B
SUBCMD_FUNC(Bot, TradeItem) {
	CS_ENTER;
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
	CS_ENTER;
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
	CS_ENTER;
	auto pri_poi = [] (int ind, point* poi) -> std::string {
		return print(
			INDEX_PREFIX, ind, " - ",
			id_maps.at(map_mapindex2mapid(poi->map))->name_japanese,
			" (", mapindex_id2name(poi->map), ") ; ",
			poi->x, ", ", poi->y, "\n"
		);
	};
	block_if* mem = shift_arguments_then_find_member(lea, args);
	int war_lv = mem->check_skill(AL_WARP);
	std::string war_des = skill_get_desc(AL_WARP);
	if (!war_lv)
		throw command_error{print(
			"�u", mem->name(), "�v�́u",
			war_des, "�v���g���܂���B"
		)};
	if (args.empty()) {
		lea->output_buffer() = std::stringstream();
		lea->output_buffer() << "------ �u" <<	mem->name() << "�v�̃��[�v�ʒu ------\n";
		lea->output_buffer() << pri_poi(0, &mem->sd()->status.save_point);
		int cou = 1;
		for (int i = 0; i < MAX_MEMOPOINTS; ++i) {
			point* poi = &mem->sd()->status.memo_point[i];
			if (poi->map) {
				lea->output_buffer() << pri_poi(1 + i, poi);
				++cou;
			}
		}
		lea->output_buffer() << cou << "���̃��[�v�ʒu��������܂����B\n";
		lea->show_next();
	} else {
		if (!mem->can_use_skill(AL_WARP, war_lv))
			throw command_error{print(
				"�u", mem->name(), "�v�͌��݁u",
				war_des, "�v���g���܂���B"
			)};
		point* sav_poi = &mem->sd()->status.save_point;
		point* mem_pois = mem->sd()->status.memo_point;
		int mind = 0;
		int max_mem;
		ARR_FIND(0, MAX_MEMOPOINTS, max_mem, !mem_pois[max_mem].map);
		std::string des_str = shift_arguments(
			args, "�}�b�v���w�肵�Ă��������B"
		);
		int i = parse_index(des_str);
		if (i == -1) {
			std::string lc_des_str = pybot::lowercase(des_str);
			for (int j = 0; j <= max_mem; ++j) {
				int mind2;
				if (j) mind2 = mem_pois[j - 1].map;
				else mind2 = sav_poi->map;
				auto map = id_maps.at(map_mapindex2mapid(mind2));
				if (pybot::lowercase(map->name_english) == lc_des_str ||
					pybot::lowercase(map->name_japanese) == lc_des_str
				) {
					i = j;
					break;
				}
			}
		}
		if (i >= 0 &&
			i <= max_mem
		) {
			if (i) mind = mem_pois[i - 1].map;
			else mind = sav_poi->map;
		}
		if (!mind) throw command_error{print(
			"�u", des_str, "�v�Ƃ����}�b�v�͂���܂���B"
		)};
		int16_t x, y;
		if (!map_search_freecell(lea->bl(), 0, &x, &y, 1, 1, 0))
			throw command_error{print(
				"���Ȃ��̎��͂ɋ󂢂Ă���Z��������܂���B"
			)};
		int m = map_mapindex2mapid(mind);
		point* des_poi;
		if (i) des_poi = &mem_pois[i - 1];
		else des_poi = sav_poi;
		if (!args.empty()) {
			int des_x = shift_arguments_then_parse_int(args, "X���W");
			int des_y = shift_arguments_then_parse_int(args, "Y���W");
			if (map_getcell(m, des_x, des_y, CELL_CHKNOPASS)) throw command_error{print(
				"�u", id_maps.at(m)->name_japanese,
				" (", mapindex_id2name(mind), ") ; ", des_x, ",", des_y, "�v"
				"�ɂ̓��[�v�ł��܂���B"
			)};
			des_poi->x = des_x;
			des_poi->y = des_y;
		}
		if (mem->is_sit()) mem->stand();
		if (mem == lea) mem->use_skill_xy(AL_WARP, war_lv, x, y, false);
		else mem->use_skill_xy(AL_WARP, war_lv, x, y, false, [mind] (ai_t* ai, void* fun) {
			skill_castend_map(ai->bot->sd(), AL_WARP, mapindex_id2name(mind));
		});
		show_client(
			lea->fd(),
			print("�u", mem->name(), "�v��"
				"�u", id_maps.at(m)->name_japanese,
				" (", mapindex_id2name(mind), ") ; ", des_poi->x, ",", des_poi->y, "�v"
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

	int job_lim = pybot::find_map_data(JOB_BOT_LIMITS, e_job(sd->status.class_), 0);
	int lim = job_lim;
	if (pc_is_maxbaselv(sd)) ++lim;
	if ((sd->status.class_ == JOB_SUPER_NOVICE ||
			sd->status.class_ == JOB_GUNSLINGER ||
			sd->status.class_ == JOB_NINJA
		) && pc_is_maxjoblv(sd)
	) ++lim;
	if (pc_readreg2(sd, (CAS_TRI_PRO + "_" + ALDE_GLD  ).c_str()) >= 4 &&
		pc_readreg2(sd, (CAS_TRI_PRO + "_" + GEF_FILD13).c_str()) >= 4 &&
		pc_readreg2(sd, (CAS_TRI_PRO + "_" + PAY_GLD   ).c_str()) >= 4 &&
		pc_readreg2(sd, (CAS_TRI_PRO + "_" + PRT_GLD   ).c_str()) >= 4
	) lim = 6;
	if (pc_readreg2(sd, (CAS_TRI_PRO + "_" + SCH_GLD   ).c_str()) >= 4 &&
		pc_readreg2(sd, (CAS_TRI_PRO + "_" + ARU_GLD   ).c_str()) >= 4
	) ++lim;
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
		session[fd]->func_del = DelFunc(pc_delete_session_data);

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
				"FROM `acc_reg_str` "
				"WHERE `account_id` = ", construct<sql_param>(sd->status.account_id)
			);
			while (ses->next_row())
				set_reg(nullptr, sd, reference_uid(add_str(reg_key), reg_idx), reg_key, (void*)(reg_str), nullptr);
			ses->execute(
				"SELECT"
				" `", construct<sql_column>("key"  , reg_key), "`,"
				" `", construct<sql_column>("index", reg_idx), "`,"
				" `", construct<sql_column>("value", reg_num), "` "
				"FROM `acc_reg_num` "
				"WHERE `account_id` = ", construct<sql_param>(sd->status.account_id)
			);
			while (ses->next_row())
				set_reg(nullptr, sd, reference_uid(add_str(reg_key), reg_idx), reg_key, (void*)__64BPRTSIZE(reg_num), nullptr);
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

		sd->change_level_2nd = pc_readglobalreg(sd, add_str(JOBCHANGE2ND_VAR));
		sd->change_level_3rd = pc_readglobalreg(sd, add_str(JOBCHANGE3RD_VAR));
		sd->die_counter = pc_readglobalreg(sd, add_str(PCDIECOUNTER_VAR));
		sd->langtype = pc_readaccountreg(sd, add_str(LANGTYPE_VAR));
		if (msg_checklangtype(sd->langtype,true) < 0) sd->langtype = 0;
		sd->cashPoints = pc_readaccountreg(sd, add_str(CASHPOINT_VAR));
		sd->kafraPoints = pc_readaccountreg(sd, add_str(KAFRAPOINT_VAR));
		sd->cook_mastery = pc_readglobalreg(sd, add_str(COOKMASTERY_VAR));
		if ((sd->class_ & MAPID_BASEMASK) == MAPID_TAEKWON) {
			sd->mission_mobid = pc_readglobalreg(sd, add_str(TKMISSIONID_VAR));
			sd->mission_count = pc_readglobalreg(sd, add_str(TKMISSIONCOUNT_VAR));
		}
		if (battle_config.feature_banking)
			sd->bank_vault = pc_readreg2(sd, BANK_VAULT_VAR);
		if (battle_config.feature_roulette) {
			sd->roulette_point.bronze = pc_readreg2(sd, ROULETTE_BRONZE_VAR);
			sd->roulette_point.silver = pc_readreg2(sd, ROULETTE_SILVER_VAR);
			sd->roulette_point.gold = pc_readreg2(sd, ROULETTE_GOLD_VAR);
		}
		sd->roulette.prizeIdx = -1;
		for (int i = 0; i < MAX_PC_FEELHATE; i++) {
			uint16 j;
			if ((j = pc_readglobalreg(sd, add_str(sg_info[i].feel_var))) != 0) {
				sd->feel_map[i].index = j;
				sd->feel_map[i].m = map_mapindex2mapid(j);
			} else {
				sd->feel_map[i].index = 0;
				sd->feel_map[i].m = -1;
			}
			sd->hate_mob[i] = pc_readglobalreg(sd, add_str(sg_info[i].hate_var)) - 1;
		}

		sd->state.active = 1;
		sd->state.pc_loaded = false;
		if (sd->status.party_id) party_member_joined(sd);
		if (sd->status.guild_id) guild_member_joined(sd);
		if (sd->status.clan_id) clan_member_joined(sd);
		if (sd->status.pet_id > 0) intif_request_petdata(sd->status.account_id, sd->status.char_id, sd->status.pet_id);
		if (sd->status.hom_id > 0) intif_homunculus_requestload(sd->status.account_id, sd->status.hom_id);
		map_addiddb(&sd->bl);
		map_delnickdb(sd->status.char_id, sd->status.name);
		scope_exit map_id_exi{[sd] () {
			map_deliddb(&sd->bl);
		}};

		item itm{};
		sd->storage.id = sd->status.account_id;
		sd->storage.type = TABLE_STORAGE;
		sd->storage.max_amount = MAX_STORAGE;
		sd->storage.stor_id = 0;
		sd->storage.state.get = sd->storage.state.put = 1;
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
			"FROM `storage` "
			"WHERE `account_id` = ", construct<sql_param>(sd->status.account_id), " "
			"ORDER BY `nameid`"
		);
		for (sd->storage.amount = 0; ses->next_row(); ++sd->storage.amount)
			sd->storage.u.items_storage[sd->storage.amount] = itm;
		sd->target_storage = &sd->storage;
		pc_check_available_item(sd, ITMCHK_STORAGE);

		sd->inventory.id = sd->status.char_id;
		sd->inventory.type = TABLE_INVENTORY;
		sd->inventory.max_amount = MAX_INVENTORY;
		sd->inventory.stor_id = 0;
		sd->inventory.state.get = sd->inventory.state.put = 1;
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

		sd->cart.id = sd->status.char_id;
		sd->cart.type = TABLE_CART;
		sd->cart.max_amount = MAX_CART;
		sd->cart.stor_id = 0;
		sd->cart.state.get = sd->cart.state.put = 1;
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

		quest que{};
		ses->execute(
			"SELECT"
			" `", construct<sql_column>("quest_id", que.quest_id), "`,"
			" `", construct<sql_column>("state"   , que.state   ), "`,"
			" `", construct<sql_column>("time"    , que.time    ), "`,"
			" `", construct<sql_column>("count1"  , que.count[0]), "`,"
			" `", construct<sql_column>("count2"  , que.count[1]), "`,"
			" `", construct<sql_column>("count3"  , que.count[2]), "` "
			"FROM `quest` "
			"WHERE `char_id` = ", construct<sql_param>(sd->status.char_id), " "
			"ORDER BY `state` ASC"
		);
		std::vector<quest> ques;
		while (ses->next_row()) ques.push_back(que);
		if (!ques.empty()) {
			CREATE(sd->quest_log, struct quest, ques.size());
			for (int i = 0; i < ques.size(); ++i) {
				if (quest_search(ques[i].quest_id) == &quest_dummy) {
					ShowError("bot_login: quest %d not found in DB.\n", ques[i].quest_id);
					continue;
				}
				sd->quest_log[i] = ques[i];
				++sd->num_quests;
				if(ques[i].state != Q_COMPLETE)	++sd->avail_quests;
			}
		}

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
		if (pc_iscarton(sd)) {
			sd->cart_weight_max = 0;
			status_calc_cart_weight(sd, (e_status_calc_weight_opt)(CALCWT_ITEM|CALCWT_MAXBONUS|CALCWT_CARTSTATE));
		}

		map_id_exi.cancel();
		fd_exi.cancel();
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
void print_storage(
	block_if* mem,       // �����o�[�B
	storage_type sto_typ // �q�Ƀ^�C�v�B
) {
	block_if* lea = mem->leader();
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
	}
	int ind_wid = print(siz - 1).length();
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ �u" << mem->name() << "�v��" <<
		STORAGE_TYPE_NAME_TABLE[sto_typ - TABLE_INVENTORY] << " ------\n";
	int cou = 0;
	for (int i = 0; i < siz; ++i) {
		item* itm = &itms[i];
		if (itm->nameid) {
			int nid = itm->nameid;
			if (itm->card[0] == CARD0_CREATE &&
				pc_famerank(MakeDWord(itm->card[2], itm->card[3]), MAPID_ALCHEMIST)
			) nid += FAME_OFFSET;
			lea->output_buffer() << INDEX_PREFIX << print(std::setw(ind_wid), std::setfill('0'), i) << " " <<
				ID_PREFIX << print(std::setw(5), std::setfill('0'), nid) << " - ";
			item_data* idb;
			if (idbs) idb = idbs[i];
			else idb = itemdb_exists(itm->nameid);
			if (idb) {
				lea->output_buffer() << print_item(itm, idb);
				if ((idb->equip &&
						idb->type != IT_CARD
					) || idb->type == IT_PETARMOR
				) {
					lea->output_buffer() << " (" << print_equip_type(idb);
					if (itm->equip) lea->output_buffer() << "@" << print_equip_pos(equip_pos(itm->equip));
					lea->output_buffer() << ")";
				}
			} else lea->output_buffer() << UNKNOWN_SYMBOL;
			lea->output_buffer() << "\n";
			++cou;
		}
	}
	lea->output_buffer() << print(cou, "���̃A�C�e����������܂����B\n");
	lea->show_next();
}

// �N���C�A���g��@Bot�R�}���h�̃T�u�R�}���h�̈ꗗ��\������B
void show_bot_subcommands(
	block_if* lea // ���[�_�[�B
) {
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << "------ @Bot�̃T�u�R�}���h ------\n";
	for (auto& sc_pro : BOT_SUBCMD_PROCS) {
		lea->output_buffer() << sc_pro->sc_full_name;
		if (!sc_pro->sc_abr_name.empty())
			lea->output_buffer() << " (" << sc_pro->sc_abr_name << ")";
		lea->output_buffer() << "\n";
	}
	lea->output_buffer() << BOT_SUBCMD_PROCS.size() <<
		"���̃T�u�R�}���h��������܂����B\n";
	lea->show_next();
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
		sk_use->limit_skills()->find(e_skill(sk->id))
	) {
		sk_use->limit_skills()->unregister(e_skill(sk->id));
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
		sk_use->limit_skills()->register_(e_skill(sk->id), initialize<int>(lim_lv));
		show_client(lea->fd(), print(
			"�u", sk_use->name(), "�v�́u", sk_des,
			"�v�����x��", lim_lv, "�ɐ������܂����B"
		));
	}
	if (sk_use != lea) clif_emotion(sk_use->bl(), ET_OK);
}

// �X�L���g�p�҂̃X�L���ꗗ��\������B
void skill_user_show_skills(
	block_if* sk_use // �X�L���g�p�ҁB
) {
	block_if* lea = sk_use->leader();
	lea->output_buffer() = std::stringstream();
	lea->output_buffer() << print("------ �u", sk_use->name(), "�v�̃X�L�� ------\n");
	int cou = 0;
	sk_use->iterate_skill([sk_use, lea, &cou] (s_skill* sk) -> bool {
		lea->output_buffer() << ID_PREFIX << print(std::setw(5), std::setfill('0'), sk->id) << " - " <<
			skill_get_desc(sk->id) << " " << int(sk->lv);
		int* lim_slv = sk_use->limit_skills()->find(e_skill(sk->id));
		if (lim_slv) lea->output_buffer() << " (" << *lim_slv << ")";
		lea->output_buffer() << "\n";
		++cou;
		return true;
	});
	lea->output_buffer() << cou << "���̃X�L����������܂����B\n";
	lea->output_buffer() << "�X�L���|�C���g " << sk_use->skill_point();
	block_if* mem = dynamic_cast<member_impl*>(sk_use);
	if (mem) {
		lea->output_buffer() << " (��+" << pc_readglobalreg(mem->sd(), add_str(pybot::EXTRA_SKILL_POINT.c_str()));
		if (pc_readglobalreg(mem->sd(), add_str(pybot::MVP_MANIA_ENHANCE.c_str())))
			lea->output_buffer() << "E";
		lea->output_buffer() << ")";
	}
	lea->output_buffer() << "\n";
	lea->show_next();
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
	if (int_ == INT_MIN) throw command_error{print(
		nam, "�͐��l�łȂ���΂Ȃ�܂���B"
	)};
	if (int_ < min) throw command_error{print(
		nam, "�� ", min, " �ȏ�łȂ���΂Ȃ�܂���B"
	)};
	if (int_ > max) throw command_error{print(
		nam, "�� ", max, " �ȉ��łȂ���΂Ȃ�܂���B"
	)};
	return int_;
}

}
