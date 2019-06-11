// [GonBee]
// �p�[�e�B�[BOT�@�\�̃e���v���[�g�Ȋ֐����`����B

#ifndef PYBOT_TEMPLATE_HPP
#define PYBOT_TEMPLATE_HPP

namespace pybot {

// -----------------------------------------------------------------------------
// ���W�X�g���^�̃����o�[�֐��̒�`

// ���W�X�g�����\�z����B
template <class K, class T>
registry_t<K,T>::registry_t(
	load_func loa, // ���[�h�B
	save_func ins, // �}���B
	save_func upd, // �X�V�B
	save_func del  // �폜�B
) {
	sav_funs[RD_INSERT - RD_INSERT] = ins;
	sav_funs[RD_UPDATE - RD_INSERT] = upd;
	sav_funs[RD_DELETE - RD_INSERT] = del;
	loading = true;
	sql_session::open([this, loa] (sql_session* ses) {
		loa(ses, this);
	});
	loading = false;
}

// ���W�X�g����j������B
template <class K, class T>
registry_t<K,T>::~registry_t() {
	try {
		sql_session::open([this] (sql_session* ses) {
			for (auto wra_val : wras) {
				K key = wra_val.first;
				auto wra = wra_val.second;
				if (wra->dirty != RD_CLEAN) {
					save_func fun = sav_funs[wra->dirty - RD_INSERT];
					if (fun) fun(ses, key, wra->data.get());
				}
			}
		});
	} catch (const std::runtime_error&) {}
}

// ���W�X�g�����N���A����B
template <class K, class T>
int // ���������l�̐��B
registry_t<K,T>::clear() {
	int cou = 0;
	for (auto wra_val_ite = wras.begin(); wra_val_ite != wras.end();) {
		auto wra = wra_val_ite->second;
		if (wra->dirty == RD_DELETE) continue;
		if (wra->dirty == RD_INSERT) wras.erase(wra_val_ite++);
		else {
			if (wra->dirty == RD_CLEAN ||
				wra->dirty == RD_UPDATE
			) wra->dirty = RD_DELETE;
			++wra_val_ite;
		}
		++cou;
	}
	return cou;
}

// ���W�X�g���̒l���R���e�i�ɃR�s�[����B
template <class K, class T>
template <
	class O // �L�[�ƃf�[�^�̃y�A�̏o�͔����q�̌^�B
> void registry_t<K,T>::copy(
	O out // �L�[�ƃf�[�^�̃y�A�̏o�͔����q�B
) {
	iterate([&out] (K key, T* dat) -> bool {
		*out++ = std::make_pair(key, dat);
		return true;
	});
}

// ���W�X�g������L�[��T���B
template <class K, class T>
T* // �������f�[�^�B������Ȃ�������nullptr�B
registry_t<K,T>::find(
	K key // �L�[�B
) {
	auto wra = find_map_data(wras, key);
	if (!wra ||
		wra->dirty == RD_DELETE
	) return nullptr;
	return wra->data.get();
}

// ���̃��W�X�g������l����荞�ށB
template <class K, class T>
int // ��荞�񂾐��B
registry_t<K,T>::import_(
	registry_t* ano_reg // ���̃��W�X�g���B
) {
	int cou = 0;
	ano_reg->iterate([this, &cou] (K key, T* dat) -> bool {
		if (!find(key)) {
			register_(key, construct<T>(*dat));
			++cou;
		}
		return true;
	});
	return cou;
}

// ���W�X�g���̒l�𔽕�����B
template <class K, class T>
void registry_t<K,T>::iterate(
	yield_func yie // �l���B
) {
	for (auto wra_val : wras) {
		K key = wra_val.first;
		auto wra = wra_val.second;
		if (wra->dirty != RD_DELETE &&
			!yie(key, wra->data.get())
		) break;
	}
}

// ���W�X�g���ɒl��o�^����B
template <class K, class T>
void registry_t<K,T>::register_(
	K key,     // �L�[�B
	ptr<T> dat // �f�[�^�B
) {
	auto wra = find_map_data(wras, key);
	if (!wra) {
		registry_dirties dir;
		if (loading) dir = RD_CLEAN;
		else dir = RD_INSERT;
		wras[key] = initialize<wrapper>(dir, dat);
	} else {
		wra->data = dat;
		if (wra->dirty == RD_CLEAN ||
			wra->dirty == RD_DELETE
		) wra->dirty = RD_UPDATE;
	}
}

// ���W�X�g������l�𖕏�����B
template <class K, class T>
void registry_t<K,T>::unregister(
	K key // �L�[�B
) {
	auto wra_val_ite = wras.find(key);
	if (wra_val_ite == wras.end()) return;
	auto wra = wra_val_ite->second;
	if (wra->dirty == RD_INSERT) wras.erase(wra_val_ite);
	else if (wra->dirty == RD_CLEAN ||
		wra->dirty == RD_UPDATE
	) wra->dirty = RD_DELETE;
}

// �f�[�^�Ȃ����W�X�g�����\�z����B
template <class K>
registry_t<K,void>::registry_t(
	load_func loa, // ���[�h�B
	save_func ins, // �}���B
	save_func del  // �폜�B
) {
	sav_funs[RD_INSERT - RD_INSERT] = ins;
	sav_funs[RD_DELETE - RD_INSERT] = del;
	loading = true;
	sql_session::open([this, loa] (sql_session* ses) {
		loa(ses, this);
	});
	loading = false;
}

// �f�[�^�Ȃ����W�X�g����j������B
template <class K>
registry_t<K,void>::~registry_t() {
	try {
		sql_session::open([this] (sql_session* ses) {
			for (auto dir_val : dirs) {
				K key = dir_val.first;
				auto dir = dir_val.second;
				if (*dir != RD_CLEAN) {
					save_func fun = sav_funs[*dir - RD_INSERT];
					if (fun) fun(ses, key);
				}
			}
		});
	} catch (const std::runtime_error&) {}
}

// �f�[�^�Ȃ����W�X�g�����N���A����B
template <class K>
int // ���������L�[�̐��B
registry_t<K,void>::clear() {
	int cou = 0;
	for (auto dir_val_ite = dirs.begin(); dir_val_ite != dirs.end();) {
		auto dir = dir_val_ite->second;
		if (*dir == RD_DELETE) continue;
		if (*dir == RD_INSERT) dirs.erase(dir_val_ite++);
		else if (*dir == RD_CLEAN) {
			*dir = RD_DELETE;
			++dir_val_ite;
		}
		++cou;
	}
	return cou;
}

// �f�[�^�Ȃ����W�X�g���̃L�[���R�s�[����B
template <class K>
template <
	class O // �L�[�̏o�͔����q�̌^�B
> void registry_t<K,void>::copy(
	O out // �L�[�̏o�͔����q�B
) {
	iterate([&out] (K key) -> bool {
		*out++ = key;
		return true;
	});
}

// �f�[�^�Ȃ����W�X�g������L�[��T���B
template <class K>
bool // �����������B
registry_t<K,void>::find(
	K key // �L�[�B
) {
	auto dir = find_map_data(dirs, key);
	if (!dir) return false;
	return *dir != RD_DELETE;
}

// ���̃��W�X�g������L�[����荞�ށB
template <class K>
int // ��荞�񂾐��B
registry_t<K,void>::import_(
	registry_t* ano_reg // ���̃��W�X�g���B
) {
	int cou = 0;
	ano_reg->iterate([this, &cou] (K key) -> bool {
		if (!find(key)) {
			register_(key);
			++cou;
		}
		return true;
	});
	return cou;
}

// �f�[�^�Ȃ����W�X�g���̃L�[�𔽕�����B
template <class K>
void registry_t<K,void>::iterate(
	yield_func yie // �l���B
) {
	for (auto dir_val : dirs) {
		K key = dir_val.first;
		auto dir = dir_val.second;
		if (*dir != RD_DELETE &&
			!yie(key)
		) break;
	}
}

// �f�[�^�Ȃ����W�X�g���ɃL�[��o�^����B
template <class K>
void registry_t<K,void>::register_(
	K key // �L�[�B
) {
	auto dir = find_map_data(dirs, key);
	if (!dir) {
		dir = initialize<registry_dirties>();
		if (loading) *dir = RD_CLEAN;
		else *dir = RD_INSERT;
		dirs[key] = dir;
	} else if (*dir == RD_DELETE) *dir = RD_CLEAN;
}

// �f�[�^�Ȃ����W�X�g������L�[�𖕏�����B
template <class K>
void registry_t<K,void>::unregister(
	K key // �L�[�B
) {
	auto dir_val_ite = dirs.find(key);
	if (dir_val_ite == dirs.end()) return;
	auto dir = dir_val_ite->second;
	if (*dir == RD_INSERT) dirs.erase(dir_val_ite);
	else if (*dir == RD_CLEAN) *dir = RD_DELETE;
}

// �o�^�l���\�z����B
template <class T>
regnum_t<T>::regnum_t(
	map_session_data* sd_,  // �Z�b�V�����f�[�^�B
	const std::string& key_ // �L�[�B
) : sd(sd_), key(key_) {
	cache = T(pc_readreg2(sd, key.c_str()));
}

// �o�^�l���琔�l���擾����B
template <class T>
T // �擾�������l�B
regnum_t<T>::get() {
	return cache;
}

// �o�^�l�ɐ��l��ݒ肷��B
template <class T>
void regnum_t<T>::set(
	T num // ���l�B
) {
	cache = num;
	pc_setreg2(sd, key.c_str(), int(cache));
}

// �|���V�[���\�z����B
template <class V>
policy_t<V>::policy_t(
	int16_t mid, // �����X�^�[ID�B
	V val        // �l�B
) : mob_id(mid),
	individual_mob_id(0),
	mdb(nullptr),
	value(val)
{
	if (mob_id >= MM_INDIVIDUAL) {
		individual_mob_id = mob_id;
		if (individual_mob_id >= MM_CAUTION) individual_mob_id -= MM_CAUTION;
	}
	if (individual_mob_id) {
		mdb = mob_db(individual_mob_id);
		if (!mdb) RAISE_RUNTIME_ERROR("Invalid mob id.");
	}
}

// -----------------------------------------------------------------------------
// �e���v���[�g�֐��̒�`

// �u���b�N��T���B
template <
	class T // �T���u���b�N�̌^�B
> block_if* // ���������u���b�N�B������Ȃ�������nullptr�B
ai_t::find_block(
	int id // ID�B
) {
	return dynamic_cast<T*>(find_map_data(blocks, id));
}

// SQL�������s����B
template <
	class ...A // ��A�̈����̌^�B
> void sql_session::execute(
	A&& ...args // ��A�̈����B
) {
	sql_context con;
	con.append(args...);
	if (SqlStmt_Prepare(stmt, con.buffer.str().c_str()) == SQL_ERROR)
		RAISE_RUNTIME_ERROR("Failed SqlStmt_Prepare.");
	for (int i = 0; i < con.params.size(); ++i) con.params[i]->bind(stmt, i);
	if (SqlStmt_Execute(stmt) == SQL_ERROR)
		RAISE_RUNTIME_ERROR("Failed SqlStmt_Execute.");
	for (int i = 0; i < con.columns.size(); ++i) con.columns[i]->bind(stmt, i);
}

// SQL�̕����Ɉ�A�̈�����ǉ�����B
template <
	class ...A // ��A�̈����̌^�B
> void sql_context::append(
	A&& ...args // ��A�̈����B
) {
	append_with(args...);
}

// SQL�̕����Ƀe�L�X�g�ƈ�A�̈�����ǉ�����B
template <
	class ...A // ��A�̈����̌^�B
> void sql_context::append_with(
	const std::string& tex, // �e�L�X�g�B
	A&& ...args             // ��A�̈����B
) {
	append_with(tex);
	append_with(args...);
}

// SQL�̕����ɗ�ƈ�A�̈�����ǉ�����B
template <
	class ...A // ��A�̈����̌^�B
> void sql_context::append_with(
	ptr<sql_column> col, // ��B
	A&& ...args          // ��A�̈����B
) {
	append_with(col);
	append_with(args...);
}

// SQL�̕����Ƀp�����[�^�ƈ�A�̈�����ǉ�����B
template <
	class ...A // ��A�̈����̌^�B
> void sql_context::append_with(
	ptr<sql_param> par, // �p�����[�^�B
	A&& ...args         // ��A�̈����B
) {
	append_with(par);
	append_with(args...);
}

// SQL���Ƀo�C���h������̂��\�z����B
template <
	class T // �f�[�^�̌^�B
> sql_binder::sql_binder(
	T& dat,    // �f�[�^�B
	size_t siz // �T�C�Y�B
) {
	auto sdt_ite = SQL_DATA_TYPES.find(std::type_index(typeid(T)));
	if (sdt_ite == SQL_DATA_TYPES.end()) {
		if (std::is_array<T>::value) type = SQLDT_STRING;
		else RAISE_RUNTIME_ERROR("Invalid SQL data type.");
	} else type = sdt_ite->second;
	size = siz;
	if (std::is_pointer<T>::value) {
		data = (void*)(dat);
		if (!size) size = std::strlen((const char*)(dat));
	} else {
		data = (void*)(&dat);
		if (!size) size = sizeof(dat);
	}
}

// SQL�̗���\�z����B
template <
	class T // �f�[�^�̌^�B
> sql_column::sql_column(
	const std::string& nam, // �񖼁B
	T& dat,                 // �f�[�^�B
	size_t siz              // �T�C�Y�B
) : sql_binder(dat, siz), name(nam) {}

// �����}�������q���\�z����B
template <
	class C // �R���e�i�̌^�B
> pybot::back_insert_iterator<C> back_inserter(
	C& x // �R���e�i�B
) {
	return pybot::back_insert_iterator<C>(x);
}

// �}�������q���\�z����B
template <
	class C // �R���e�i�̌^�B
> pybot::insert_iterator<C> inserter(
	C& x,                  // �R���e�i�B
	typename C::iterator i // �q���g�B
) {
	return pybot::insert_iterator<C>(x, i);
}

// �R�}���h�v�f����u���b�N���W�߂�B
template <
	class C, // �W�߂��u���b�N�̌^�B
	class I  // �v�f�̓��͔����q�̌^�B
> ptr<C> // �W�߂��u���b�N�B
command_collect_blocks(
    I ele_fir,              // �ŏ��̗v�f�̓��͔����q�B
	I ele_las,              // �Ō�̗v�f�̓��͔����q�B
    const std::string& ope, // �J���L���B
    const std::string& clo, // ����L���B
    bool all_emp            // ����ۂ̃u���b�N���������B
) {
	auto blos = initialize<C>();
	command_collect_blocks(ele_fir, ele_las, pybot::back_inserter(*blos), ope, clo, all_emp);
	return blos;
}

// �R�}���h�v�f����u���b�N���W�߂�B
template <
	class I, // �v�f�̓��͔����q�̌^�B
	class O  // �u���b�N�̏o�͔����q�̌^�B
> void command_collect_blocks(
    I ele_fir,              // �ŏ��̗v�f�̓��͔����q�B
	I ele_las,              // �Ō�̗v�f�̓��͔����q�B
    O blo_out,              // �u���b�N�̏o�͔����q�B
    const std::string& ope, // �J���L���B
    const std::string& clo, // ����L���B
    bool all_emp            // ����ۂ̃u���b�N���������B
) {
	using blo_t = typename O::container::value_type::element_type;
    int fra = 0;
    bool ins = false;
	auto blo = initialize<blo_t>();
    auto flu = [blo_out, all_emp, &blo] () mutable {
        if (!all_emp &&
			(blo->empty() ||
				(blo->size() == 1 &&
					blo->front()->type == CET_LITERAL &&
					blo->front()->text.empty()
				)
			)
        ) return;
        *blo_out++ = blo;
		blo = initialize<blo_t>();
    };
    for (auto ele_ite = ele_fir; ele_ite != ele_las;) {
        auto ele = *ele_ite++;
        if (fra ||
            !((!ins &&
                    ele->type == CET_OPEN &&
                    ele->text == ope
                ) || (ins &&
                    ele->type == CET_CLOSE &&
                    ele->text == clo
                )
            )
        ) {
            if (ele->type == CET_OPEN) ++fra;
            else if (ele->type == CET_CLOSE) --fra;
            if (ins) blo->push_back(ele);
            continue;
        }
        if (ins) flu();
        ins = !ins;
    }
}

// �R�}���h�v�f����g�[�N�����W�߂�B
template <
	class C, // �W�߂��g�[�N���̌^�B
	class I  // �v�f�̓��͔����q�̌^�B
> ptr<C> // �W�߂��g�[�N���B
command_collect_tokens(
    I ele_fir,              // �ŏ��̗v�f�̓��͔����q�B
	I ele_las,              // �Ō�̗v�f�̓��͔����q�B
    const std::string& sep, // ��؂�L���B
    bool all_emp            // ����ۂ̃g�[�N�����������B
) {
	auto toks = initialize<C>();
	command_collect_tokens(ele_fir, ele_las, pybot::back_inserter(*toks), sep, all_emp);
	return toks;
}

// �R�}���h�v�f����g�[�N�����W�߂�B
template <
    class I, // �v�f�̓��͔����q�̌^�B
    class O  // �g�[�N���̏o�͔����q�̌^�B
> void command_collect_tokens(
    I ele_fir,              // �ŏ��̗v�f�̓��͔����q�B
    I ele_las,              // �Ō�̗v�f�̓��͔����q�B
    O tok_out,              // �g�[�N���̏o�͔����q�B
    const std::string& sep, // ��؂�L���B
    bool all_emp            // ����ۂ̃g�[�N�����������B
) {
    using tok_t = typename O::container::value_type::element_type;
    int fra = 0;
    auto tok = initialize<tok_t>();
    auto flu = [tok_out, all_emp, &tok] () mutable {
        if (all_emp ||
            (!tok->empty() &&
                (tok->size() > 1 ||
                    tok->front()->type != CET_LITERAL ||
                    !tok->front()->text.empty()
                )
            )
        ) {
            *tok_out++ = tok;
            tok = initialize<tok_t>();
        }
    };
    for (auto ele_ite = ele_fir; ele_ite != ele_las;) {
        auto ele = *ele_ite++;
        if (!fra &&
            ele->type == CET_SEPARATOR &&
            ele->text == sep
        ) flu();
        else {
            if (ele->type == CET_OPEN) ++fra;
            else if (ele->type == CET_CLOSE) --fra;
            tok->push_back(ele);
        }
    }
    flu();
}

// �R�}���h�̈�������͂���B
template <
	class C // ��͂����������i�[�����R���e�i�̌^�B
> ptr<C> // ��͂����������i�[�����R���e�i�B
command_parse_arguments(
	const std::string com // �R�}���h�B
) {
	auto args = initialize<C>();
	command_parse_arguments(com, pybot::back_inserter(*args));
	return args;
}

// �R�}���h�̈�������͂���B
template <
	class O // �����̏o�͔����q�̌^�B
> void command_parse_arguments(
	const std::string com, // �R�}���h�B
	O arg_out              // �����̏o�͔����q�B
) {
	using ele_lis = std::list<ptr<command_element>>;
	using ele_lis_lis = std::list<ptr<ele_lis>>;
	auto eles = initialize<ele_lis>(initialize<command_element>(CET_LITERAL, com));
	eles = command_parse_blocks<ele_lis>(ALL_RANGE(*eles), "\"", "\"", false, true);
	eles = command_parse_tokens<ele_lis>(ALL_RANGE(*eles), " ", false, true);
	auto toks = command_collect_tokens<ele_lis_lis>(ALL_RANGE(*eles), " ", false);
	for (auto tok : *toks) tok->remove_if(
		[] (const ptr<command_element>& ele) -> bool
		{return ele->type == CET_OPEN || ele->type == CET_CLOSE;}
	);
	command_print_all(ALL_RANGE(*toks), arg_out);
}

// �R�}���h�v�f�̃u���b�N����͂���B
template <
	class C, // ��͂����v�f���i�[�����R���e�i�̌^�B
	class I  // �v�f�̓��͔����q�̌^�B
> ptr<C> // ��͂����v�f���i�[�����R���e�i�B
command_parse_blocks(
    I ele_fir,              // �ŏ��̗v�f�̓��͔����q�B
	I ele_las,              // �Ō�̗v�f�̓��͔����q�B
    const std::string& ope, // �J���L���B
    const std::string& clo, // ����L���B
    bool esc,               // �G�X�P�[�v���l�����邩�B
    bool lea                // �S�p�������l�����邩�B
) {
	auto eles = initialize<C>();
	command_parse_blocks(ele_fir, ele_las, pybot::back_inserter(*eles), ope, clo, esc, lea);
	return eles;
}

// �R�}���h�v�f�̃u���b�N����͂���B
template <
    class I, // �v�f�̓��͔����q�̌^�B
    class O  // �v�f�̏o�͔����q�̌^�B
> void command_parse_blocks(
    I ele_fir,              // �ŏ��̗v�f�̓��͔����q�B
    I ele_las,              // �Ō�̗v�f�̓��͔����q�B
    O ele_out,              // �v�f�̏o�͔����q�B
    const std::string& ope, // �J���L���B
    const std::string& clo, // ����L���B
    bool esc,               // �G�X�P�[�v���l�����邩�B
    bool lea                // �S�p�������l�����邩�B
) {
    int out_fra = 0;
    int ins_fra = 0;
    for (auto ele_ite = ele_fir; ele_ite != ele_las;) {
        auto ele = *ele_ite++;
        if (out_fra ||
            ele->type != CET_LITERAL
        ) {
            if (ele->type == CET_OPEN) ++out_fra;
            else if (ele->type == CET_CLOSE) {
                if (!out_fra--) RAISE_RUNTIME_ERROR("Too many close.");
            }
            *ele_out++ = ele;
        } else {
            std::stringstream buf;
            for (int i = 0; i < ele->text.length();) {
                uint8_t let = ele->text[i];
                if ((esc &&
                        let == '\\'
                    ) || (lea &&
                        letter_is_jlead(let)
                    )
                ) {
                    if (++i == ele->text.length())
                        RAISE_RUNTIME_ERROR("Wrong end.");
                    buf << let << ele->text[i++];
                } else if (ins_fra &&
                    ele->text.substr(i, clo.length()) == clo
                ) {
                    --ins_fra;
                    *ele_out++ = initialize<command_element>(CET_LITERAL, buf.str());
                    buf.str("");
                    *ele_out++ = initialize<command_element>(CET_CLOSE, clo);
                    i += clo.length();
                } else if (ele->text.substr(i, ope.length()) == ope) {
                    ++ins_fra;
                    *ele_out++ = initialize<command_element>(CET_LITERAL, buf.str());
                    buf.str("");
                    *ele_out++ = initialize<command_element>(CET_OPEN, ope);
                    i += ope.length();
                } else {
                    buf << let;
                    ++i;
                }
            }
            *ele_out++ = initialize<command_element>(CET_LITERAL, buf.str());
        }
    }
    if (out_fra ||
        ins_fra
    ) RAISE_RUNTIME_ERROR("Too many open.");
}

// �R�}���h�v�f�̃g�[�N������͂���B
template <
	class C, // ��͂����v�f���i�[�����R���e�i�̌^�B
	class I  // �v�f�̓��͔����q�̌^�B
> ptr<C> // ��͂����v�f���i�[�����R���e�i�B
command_parse_tokens(
    I ele_fir,              // �ŏ��̗v�f�̓��͔����q�B
	I ele_las,              // �Ō�̗v�f�̓��͔����q�B
    const std::string& sep, // ��؂�L���B
    bool esc,               // �G�X�P�[�v���l�����邩�B
    bool lea                // �S�p�������l�����邩�B
) {
	auto eles = initialize<C>();
	command_parse_tokens(ele_fir, ele_las, pybot::back_inserter(*eles), sep, esc, lea);
	return eles;
}

// �R�}���h�v�f�̃g�[�N������͂���B
template <
	class I, // �v�f�̓��͔����q�̌^�B
	class O  // �v�f�̏o�͔����q�̌^�B
> void command_parse_tokens(
    I ele_fir,              // �ŏ��̗v�f�̓��͔����q�B
	I ele_las,              // �Ō�̗v�f�̓��͔����q�B
    O ele_out,              // �v�f�̏o�͔����q�B
    const std::string& sep, // ��؂�L���B
    bool esc,               // �G�X�P�[�v���l�����邩�B
    bool lea                // �S�p�������l�����邩�B
) {
    int fra = 0;
    for (auto ele_ite = ele_fir; ele_ite != ele_las;) {
        auto ele = *ele_ite++;
        if (fra ||
            ele->type != CET_LITERAL
        ) {
            if (ele->type == CET_OPEN) ++fra;
            else if (ele->type == CET_CLOSE) {
                if (!fra--) RAISE_RUNTIME_ERROR("Too many close.");
            }
            *ele_out++ = ele;
        } else {
			std::stringstream buf;
			for (int i = 0; i < ele->text.length();) {
				uint8_t let = ele->text[i];
				if ((esc &&
						let == '\\'
					) || (lea &&
						letter_is_jlead(let)
					)
				) {
					if (++i == ele->text.length())
						RAISE_RUNTIME_ERROR("Wrong end.");
					buf << let << ele->text[i++];
				}
				else if (ele->text.substr(i, sep.length()) == sep) {
					*ele_out++ = initialize<command_element>(CET_LITERAL, buf.str());
					buf.str("");
					*ele_out++ = initialize<command_element>(CET_SEPARATOR, sep);
					i += sep.length();
				} else {
					buf << let;
					++i;
				}
			}
			*ele_out++ = initialize<command_element>(CET_LITERAL, buf.str());
		}
    }
    if (fra) RAISE_RUNTIME_ERROR("Too many open.");
}

// �R�}���h�v�f�̃R���e�i�������B
template <
	class C, // ��������������i�[�����R���e�i�̌^�B
	class I  // �v�f�̃R���e�i�̓��͔����q�̌^�B
> ptr<C> // ��������������i�[�����R���e�i�B
command_print_all(
	I eles_fir, // �ŏ��̗v�f�̃R���e�i�̓��͔����q�B
	I eles_las  // �Ō�̗v�f�̃R���e�i�̓��͔����q�B
) {
	auto strs = initialize<C>();
	command_print_all(eles_fir, eles_las, pybot::back_inserter(*strs));
	return strs;
}

// �R�}���h�v�f�̃R���e�i�������B
template <
	class I, // �v�f�̃R���e�i�̓��͔����q�̌^�B
	class O  // �e�L�X�g�̏o�͔����q�̌^�B
> void command_print_all(
	I eles_fir, // �ŏ��̗v�f�̃R���e�i�̓��͔����q�B
	I eles_las, // �Ō�̗v�f�̃R���e�i�̓��͔����q�B
	O tex_out   // �e�L�X�g�̏o�͔����q�B
) {
    for (auto eles_ite = eles_fir; eles_ite != eles_las;) {
        auto eles = *eles_ite++;
        *tex_out++ = command_print(ALL_RANGE(*eles));
    }
}

// �R�}���h�v�f�������B
template <
	class I // �v�f�̓��͔����q�̌^�B
> std::string // �������e�L�X�g�B
command_print(
	I ele_fir, // �ŏ��̗v�f�̓��͔����q�B
	I ele_las  // �Ō�̗v�f�̓��͔����q�B
) {
    std::stringstream buf;
    for (auto ele_ite = ele_fir; ele_ite != ele_las;) {
        auto ele = *ele_ite++;
        buf << ele->text;
    }
    return buf.str();
}

// �I�u�W�F�N�g���\�z����B
template <
	class T,   // �I�u�W�F�N�g�̌^�B
	class ...A // ��A�̈����̌^�B
> ptr<T> // �\�z�����I�u�W�F�N�g�B
construct(
	A&& ...args // ��A�̈����B
) {
    return ptr<T>(new T(args...));
}

// �}�b�v����f�[�^��T���B
template <
	class M // �}�b�v�̌^�B
> typename M::mapped_type // ���������f�[�^�B������Ȃ�������def�B
find_map_data(
	const M& map,               // �}�b�v�B
	typename M::key_type key,   // �L�[�B
	typename M::mapped_type def // �f�t�H���g�̃f�[�^�B
) {
	auto val_ite = map.find(key);
	if (val_ite == map.end()) return def;
	return val_ite->second;
}

// �}�b�v����L�[��T���B
template <
	class M // �}�b�v�̌^�B
> typename M::key_type // ���������L�[�B������Ȃ�������def�B
find_map_key(
	const M& map,                // �}�b�v�B
	typename M::mapped_type dat, // �f�[�^�B
	typename M::key_type def     // �f�t�H���g�̃L�[�B
) {
	for (auto& val : map) {
		if (val.second == dat) return val.first;
	}
	return def;
}

// �z�񂩂疼�O��T���B
template <
	class A // �z��̌^�B
> int // ���������C���f�b�N�X�B������Ȃ�������INT_MIN�B
find_name(
	const A& arr,             // �z��B
	const std::string& nam_lc // �������̖��O�B
) {
	for (int i = 0; i < arr.size(); ++i) {
		if (lowercase(arr[i]) == nam_lc) return i;
	}
	return INT_MIN;
}

// �I�u�W�F�N�g������������B
template <
	class T,   // �I�u�W�F�N�g�̌^�B
	class ...A // ��A�̈����̌^�B
> ptr<T> // �����������I�u�W�F�N�g�B
initialize(
	A&& ...args // ��A�̈����B
) {
    return ptr<T>(new T{args...});
}

// �������A������B
template <
	class I // ������̓��͔����q�̌^�B
> std::string // �A������������B
concatinate_strings(
	I str_fir,             // �ŏ��̕�����̓��͔����q�B
	I str_las,             // �Ō�̕�����̓��͔����q�B
	const std::string& sep // ��؂�L���B
) {
	std::stringstream out;
	for (I str_ite = str_fir; str_ite != str_las;) {
		if (str_ite != str_fir) out << sep;
		out << *str_ite++;
	}
	return out.str();
}

// �v�f��T���B
template <
	class I, // ���͔����q�̌^�B
	class P  // �q��̌^�B
> typename I::value_type // ���������v�f�B������Ȃ�������def�B
find_if(
	I fir,                     // �ŏ��̗v�f�̓��͔����q�B
	I las,                     // �Ō�̗v�f�̓��͔����q�B
	P pre,                     // �q��B
	typename I::value_type def // �f�t�H���g�l�B
) {
	auto ele_ite = std::find_if(fir, las, pre);
	if (ele_ite == las) return def;
	return *ele_ite;
}

// ��A�̈����������B
template <
	class ...A // ��A�̈����̌^�B
> std::string // ������������B
print(
	A&& ...args // ��A�̈����B
) {
    return print_with("", args...);
}

// ��ȃX�e�[�^�X�������B
template <
	class D // �f�[�^�̌^�B
> std::string // �������X�e�[�^�X�B
print_main_status(
	D* dat // �f�[�^�B
) {
	block_list* bl = (block_list*)(dat);
	std::stringstream out;
	int aspd = 2000 - status_get_adelay(bl) / 2;
	out <<
		"HP "  << status_get_hp(bl)                     << "/" <<
		status_get_max_hp(bl)                           << " "
		"SP "  << status_get_sp(bl)                     << "/" <<
		status_get_max_sp(bl)                           << " "
		"Str " << status_get_base_str(dat)              << "+" <<
		(status_get_str(bl) - status_get_base_str(dat)) << " "
		"Agi " << status_get_base_agi(dat)              << "+" <<
		(status_get_agi(bl) - status_get_base_agi(dat)) << " "
		"Vit " << status_get_base_vit(dat)              << "+" <<
		(status_get_vit(bl) - status_get_base_vit(dat)) << " "
		"Int " << status_get_base_int(dat)              << "+" <<
		(status_get_int(bl) - status_get_base_int(dat)) << " "
		"Dex " << status_get_base_dex(dat)              << "+" <<
		(status_get_dex(bl) - status_get_base_dex(dat)) << " "
		"Luk " << status_get_base_luk(dat)              << "+" <<
		(status_get_luk(bl) - status_get_base_luk(dat)) << "\n";
	out <<
		"Atk "      << pc_leftside_atk (dat)      << "+" <<
		pc_rightside_atk (dat)                    << " "
		"Matk "     << pc_leftside_matk(dat)      << "+" <<
		pc_rightside_matk(dat)                    << " "
		"Hit "      << status_get_hit(bl)         << " "
		"Critical " << print(
			std::fixed,
			std::setprecision(1),
			status_get_critical(bl) / 10.
		) << " "
		"Def "      << int(pc_leftside_def (dat)) << "+" <<
		pc_rightside_def (dat)                    << " "
		"Mdef "     << int(pc_leftside_mdef(dat)) << "+" <<
		pc_rightside_mdef(dat)                    << " "
		"Flee "     << status_get_flee(bl)        << "+" <<
		status_get_flee2 (bl)                     << " "
		"Aspd "     << print(
			std::fixed,
			std::setprecision(1),
			aspd / 10.
		) << "\n";
	return out.str();
}

// ��A�̈�������؂�Ȃ���o�̓X�g���[���ɏ����B
template <
	class O,   // �o�̓X�g���[���̌^�B
	class L,   // �擪�̈����̌^�B
	class ...T // �㑱�̈����̌^�B
> void print_to_with(
	O& out,                 // �o�̓X�g���[���B
	const std::string& sep, // ��؂�L���B
	L lea,                  // �擪�̈����B
	T&& ...tras             // �㑱�̈����̌^�B
) {
    out << lea;
    if (!sep.empty()) out << sep;
    print_to_with(out, sep, tras...);
}

// ��������؂�Ȃ���o�̓X�g���[���ɏ����B
template <
	class O, // �o�̓X�g���[���̌^�B
	class A  // �����̌^�B
> void print_to_with(
	O& out,                 // �o�̓X�g���[���B
	const std::string& sep, // ��؂�L���B
	A arg                   // �����B
) {
    out << arg;
}

// ��A�̈�������؂�Ȃ��珑���B
template <
	class ...A // ��A�̈����̌^�B
> std::string // ������������B
print_with(
	const std::string& sep, // ��؂�L���B
	A&& ...args             // ��A�̈����B
) {
    std::ostringstream out;
    print_to_with(out, sep, args...);
    return out.str();
}

// �����o�֐����A�C���X�^���X�������Ƃ���֐��ɕϊ�����B
template <
	class T,   // �I�u�W�F�N�g�̌^�B
	class R,   // �߂�l�̌^�B
	class ...A // ��A�̈����̌^�B
> std::function<R(T*,A...)> // �ϊ������֐��B
unbind(
	R(T::*mem_fun)(A...) // �����o�֐��B
) {
	return [mem_fun] (
		T* ins,     // �C���X�^���X�B
		A&& ...args // ��A�̈����B
	) -> R { // �߂�l�B
		return (ins->*mem_fun)(args...);
	};
}

}

#endif
