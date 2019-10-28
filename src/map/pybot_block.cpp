// [GonBee]
// �p�[�e�B�[BOT�@�\�̃u���b�N���`����B

#include "pybot_internal.hpp"

namespace pybot {

// -----------------------------------------------------------------------------
// �u���b�N�^�̃����o�[�֐��̒�`

bool& battler_if::around_wall_exists() {RAISE_NOT_IMPLEMENTED_ERROR;}
void battler_if::attack(block_if* blo, bool con) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& battler_if::attacked_by_blower() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& battler_if::attacked_by_detector() {RAISE_NOT_IMPLEMENTED_ERROR;}
std::vector<block_if*>& battler_if::attacked_enemies() {RAISE_NOT_IMPLEMENTED_ERROR;}
block_if*& battler_if::attacked_long_range_attacker() {RAISE_NOT_IMPLEMENTED_ERROR;}
block_if*& battler_if::attacked_short_range_attacker() {RAISE_NOT_IMPLEMENTED_ERROR;}
int& battler_if::attacked_short_range_attackers() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& battler_if::attacked_via_devotion() {RAISE_NOT_IMPLEMENTED_ERROR;}
int& battler_if::battle_index() {RAISE_NOT_IMPLEMENTED_ERROR;}
battle_modes& battler_if::battle_mode() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::check_attack(block_if* ene) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::check_hp(int rat) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::check_normal_attack(block_if* ene) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::check_sp(int rat) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::check_supply_sp() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::check_use_skill(e_skill kid, int klv, block_if* ene) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::check_use_taunt_skill(block_if* ene) {RAISE_NOT_IMPLEMENTED_ERROR;}
distance_policy_values battler_if::default_distance_policy_value() {RAISE_NOT_IMPLEMENTED_ERROR;}
normal_attack_policy_values battler_if::default_normal_attack_policy_value() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::distance_max_value() {RAISE_NOT_IMPLEMENTED_ERROR;}
distance_policy_values& battler_if::distance_policy_value() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::get_hold_mobs() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::get_mob_high_def() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::get_mob_high_def_vit() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::get_mob_high_flee() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::get_mob_high_hit() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::get_mob_high_mdef() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::get_supply_sp_rate() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::guild_id() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& battler_if::is_best_pos() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::is_dead() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::is_invincible() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::is_no_castcancel() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::is_no_gemstone() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::is_primary() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::is_wall_side() {RAISE_NOT_IMPLEMENTED_ERROR;}
block_if*& battler_if::leader() {RAISE_NOT_IMPLEMENTED_ERROR;}
void battler_if::load_policy(int mid, distance_policy_values* dis_pol_val, normal_attack_policy_values* nor_att_pol_val) {RAISE_NOT_IMPLEMENTED_ERROR;}
int& battler_if::member_index() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::no_knockback() {RAISE_NOT_IMPLEMENTED_ERROR;}
normal_attack_policy_values& battler_if::normal_attack_policy_value() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::party_id() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<e_skill>>& battler_if::reject_skills() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::skill_ratio(e_skill kid, int klv, block_if* tar) {RAISE_NOT_IMPLEMENTED_ERROR;}
void battler_if::stop_attacking() {RAISE_NOT_IMPLEMENTED_ERROR;}
void battler_if::stop_walking(int typ) {RAISE_NOT_IMPLEMENTED_ERROR;}
block_if*& battler_if::target_enemy() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::teleport(block_list* bl_) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::walk_bl(block_list* tbl, int ran) {RAISE_NOT_IMPLEMENTED_ERROR;}
ai_t::done_func& battler_if::walk_end_func() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool battler_if::walk_xy(int x, int y, int ran) {RAISE_NOT_IMPLEMENTED_ERROR;}
e_element battler_if::weapon_attack_element() {RAISE_NOT_IMPLEMENTED_ERROR;}
int battler_if::weapon_attack_element_ratio(block_if* tar) {RAISE_NOT_IMPLEMENTED_ERROR;}

int& bot_if::bot_index() {RAISE_NOT_IMPLEMENTED_ERROR;}
t_tick& bot_if::last_emotion_tick() {RAISE_NOT_IMPLEMENTED_ERROR;}
t_tick& bot_if::last_reloaded_equipset_tick() {RAISE_NOT_IMPLEMENTED_ERROR;}
void bot_if::respawn() {RAISE_NOT_IMPLEMENTED_ERROR;}
e_skill& bot_if::want_to_play() {RAISE_NOT_IMPLEMENTED_ERROR;}

std::vector<block_if*>& enemy_if::attacked_battlers() {RAISE_NOT_IMPLEMENTED_ERROR;}
int enemy_if::away_distance(block_if* lea) {RAISE_NOT_IMPLEMENTED_ERROR;}
std::vector<block_if*>& enemy_if::close_battlers() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool enemy_if::fullpower(block_if* lea) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_earthquake() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_knockback_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_layout_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_long_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_long_weapon_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_path_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_summon_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_unequip_armor_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_unequip_helm_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_unequip_shield_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_unequip_weapon_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& enemy_if::has_usefull_skill() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool enemy_if::need_to_leave() {RAISE_NOT_IMPLEMENTED_ERROR;}
block_if*& enemy_if::skill_target_battler() {RAISE_NOT_IMPLEMENTED_ERROR;}
block_if*& enemy_if::target_battler() {RAISE_NOT_IMPLEMENTED_ERROR;}
pos_t enemy_if::waiting_position() {RAISE_NOT_IMPLEMENTED_ERROR;}
block_if*& enemy_if::walk_target_battler() {RAISE_NOT_IMPLEMENTED_ERROR;}

void general_if::act_end() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::attack_element_ratio(block_if* tar, e_element ele) {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::attack_range() {RAISE_NOT_IMPLEMENTED_ERROR;}
block_list* general_if::bl() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::can_act() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::can_move() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::can_reach_bl(block_list* bl_, bool eas) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::can_reach_block(block_if* blo, bool eas) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::can_reach_xy(int x, int y, bool eas) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::check_attack_range(block_if* blo) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::check_line_bl(block_list* bl_) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::check_line_block(block_if* blo) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::check_line_xy(int x, int y) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::check_range_bl(block_list* bl0, block_list* bl1, int dis) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::check_range_blxy(block_list* bl_, int x, int y, int dis) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::check_range_xy(int x0, int y0, int x1, int y1, int dis) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::check_sc_types(const sc_type_set& sc_typs) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::check_skill_range_block(e_skill kid, int klv, block_if* blo) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::check_skill_range_xy(e_skill kid, int klv, int x, int y) {RAISE_NOT_IMPLEMENTED_ERROR;}
defType general_if::def() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::def2() {RAISE_NOT_IMPLEMENTED_ERROR;}
e_element general_if::element() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::flee() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::hit() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::hp() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::hp_ratio() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::inner_product(const coords_t& a, const coords_t& b) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_attacking() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_casting() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_ensemble() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_gospel() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_hiding() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_long_range_attacker() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_long_weapon_immune() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_magic_immune() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_paralysis() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_short_range_attacker() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_solo() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::is_walking() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::max_hp() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::max_sp() {RAISE_NOT_IMPLEMENTED_ERROR;}
defType general_if::mdef() {RAISE_NOT_IMPLEMENTED_ERROR;}
std::string general_if::name() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool general_if::on_water() {RAISE_NOT_IMPLEMENTED_ERROR;}
e_race general_if::race() {RAISE_NOT_IMPLEMENTED_ERROR;}
e_race2 general_if::race2() {RAISE_NOT_IMPLEMENTED_ERROR;}
status_change* general_if::sc() {RAISE_NOT_IMPLEMENTED_ERROR;}
t_tick general_if::sc_rest(sc_type typ) {RAISE_NOT_IMPLEMENTED_ERROR;}
size general_if::size_() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::skill_advantage(int x, int y) {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::sp() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::sp_ratio() {RAISE_NOT_IMPLEMENTED_ERROR;}
unit_data* general_if::ud() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::vit() {RAISE_NOT_IMPLEMENTED_ERROR;}
int general_if::walkpath_length() {RAISE_NOT_IMPLEMENTED_ERROR;}
pos_t general_if::walkpath_pos(int stes) {RAISE_NOT_IMPLEMENTED_ERROR;}

homun_data* homun_if::hd() {RAISE_NOT_IMPLEMENTED_ERROR;}
homun_mapid homun_if::homun_mapid_() {RAISE_NOT_IMPLEMENTED_ERROR;}

std::unordered_map<int,t_tick>& item_user_if::item_used_ticks() {RAISE_NOT_IMPLEMENTED_ERROR;}
void item_user_if::use_item(int ind, bool exc) {RAISE_NOT_IMPLEMENTED_ERROR;}

std::unordered_map<int,ptr<block_if>>& leader_if::ally_mobs() {RAISE_NOT_IMPLEMENTED_ERROR;}
int& leader_if::attack_target() {RAISE_NOT_IMPLEMENTED_ERROR;}
coords_t leader_if::back_base() {RAISE_NOT_IMPLEMENTED_ERROR;}
std::vector<ptr<block_if>>& leader_if::bots() {RAISE_NOT_IMPLEMENTED_ERROR;}
block_list& leader_if::center() {RAISE_NOT_IMPLEMENTED_ERROR;}
std::unordered_map<int,ptr<block_if>>& leader_if::enemies() {RAISE_NOT_IMPLEMENTED_ERROR;}
block_if* leader_if::find_bot(const std::string& nam) {RAISE_NOT_IMPLEMENTED_ERROR;}
block_if* leader_if::find_member(const std::string& nam) {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int>>& leader_if::great_mobs() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int>>& leader_if::ignore_items() {RAISE_NOT_IMPLEMENTED_ERROR;}
t_tick& leader_if::last_heaby_tick() {RAISE_NOT_IMPLEMENTED_ERROR;}
int& leader_if::last_summoned_id() {RAISE_NOT_IMPLEMENTED_ERROR;}
std::vector<block_if*>& leader_if::members() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,coords_t>>& leader_if::memos() {RAISE_NOT_IMPLEMENTED_ERROR;}
t_tick leader_if::next_heaby_tick() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int>>& leader_if::not_ignore_items() {RAISE_NOT_IMPLEMENTED_ERROR;}
std::stringstream& leader_if::output_buffer() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& leader_if::passive() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<bool>>& leader_if::rush() {RAISE_NOT_IMPLEMENTED_ERROR;}
void leader_if::save_team(int tea_num) {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int>>& leader_if::sell_items() {RAISE_NOT_IMPLEMENTED_ERROR;}
void leader_if::show_next() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& leader_if::sp_suppliable() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool& leader_if::stay() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int>>& leader_if::storage_put_items() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,team_t>>& leader_if::teams() {RAISE_NOT_IMPLEMENTED_ERROR;}
void leader_if::update_bot_indices() {RAISE_NOT_IMPLEMENTED_ERROR;}
void leader_if::update_member_indices() {RAISE_NOT_IMPLEMENTED_ERROR;}

int& member_if::account_id() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::berserk_rate() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool member_if::can_ka(block_if* tar_mem) {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int>>& member_if::cart_auto_get_items() {RAISE_NOT_IMPLEMENTED_ERROR;}
int& member_if::char_id() {RAISE_NOT_IMPLEMENTED_ERROR;}
e_skill member_if::combo_skill_id() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::distance_max() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,distance_policy>>& member_if::distance_policies() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,equipset_t>>& member_if::equipsets() {RAISE_NOT_IMPLEMENTED_ERROR;}
int& member_if::fd() {RAISE_NOT_IMPLEMENTED_ERROR;}
int member_if::find_broken_equip(int bas) {RAISE_NOT_IMPLEMENTED_ERROR;}
int member_if::find_cart(const std::string& nam) {RAISE_NOT_IMPLEMENTED_ERROR;}
int member_if::find_cart(const item_key& key) {RAISE_NOT_IMPLEMENTED_ERROR;}
int member_if::find_inventory(const std::string& nam) {RAISE_NOT_IMPLEMENTED_ERROR;}
int member_if::find_inventory(const item_key&, int equ) {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,e_skill>>& member_if::first_skills() {RAISE_NOT_IMPLEMENTED_ERROR;}
int member_if::get_skill_mobs() {RAISE_NOT_IMPLEMENTED_ERROR;}
t_tick member_if::get_skill_tail(e_skill kid) {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::hold_mobs() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<block_if>& member_if::homun() {RAISE_NOT_IMPLEMENTED_ERROR;}
void member_if::identify_equip(item* itm, storage_context* inv_con, storage_context* car_con) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool member_if::is_carton() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool member_if::is_sit() {RAISE_NOT_IMPLEMENTED_ERROR;}
void member_if::load_equipset(int mid, equip_pos* equ) {RAISE_NOT_IMPLEMENTED_ERROR;}
void member_if::load_play_skill(int mid, e_skill* kid) {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<loot_modes>>& member_if::loot() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool member_if::magicpower_is_active() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::mob_high_def() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::mob_high_def_vit() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::mob_high_flee() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::mob_high_hit() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::mob_high_mdef() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,normal_attack_policy>>& member_if::normal_attack_policies() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<block_if>& member_if::pet() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,play_skill>>& member_if::play_skills() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,int>>& member_if::recover_hp_items() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,int>>& member_if::recover_sp_items() {RAISE_NOT_IMPLEMENTED_ERROR;}
std::unordered_set<int>& member_if::request_items() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::safe_cast_time() {RAISE_NOT_IMPLEMENTED_ERROR;}
map_session_data*& member_if::sd() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::supply_sp_rate() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,e_element>>& member_if::kew_elements() {RAISE_NOT_IMPLEMENTED_ERROR;}
void member_if::sit() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int>>& member_if::skill_ignore_mobs() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<regnum_t<int>>& member_if::skill_mobs() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<e_skill,int>>& member_if::skill_tails() {RAISE_NOT_IMPLEMENTED_ERROR;}
void member_if::stand() {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<int,int>>& member_if::storage_get_items() {RAISE_NOT_IMPLEMENTED_ERROR;}
e_job member_if::substancial_job() {RAISE_NOT_IMPLEMENTED_ERROR;}

bool mob_if::has_can_attack() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::can_be_provoke() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::has_can_move() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::has_detector() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::has_knockback_immune() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::has_mvp() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::has_status_immune() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::is_berserk() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::is_boss() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::is_freezable() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::is_flora() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::is_great(block_if* lea) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::is_summoned() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool mob_if::is_undead() {RAISE_NOT_IMPLEMENTED_ERROR;}
mob_data*& mob_if::md() {RAISE_NOT_IMPLEMENTED_ERROR;}

pet_data* pet_if::pd() {RAISE_NOT_IMPLEMENTED_ERROR;}

bool skill_target_if::check_skill_used_tick(e_skill kid, t_tick ela_tic) {RAISE_NOT_IMPLEMENTED_ERROR;}
std::unordered_map<e_skill,t_tick>& skill_target_if::skill_used_ticks() {RAISE_NOT_IMPLEMENTED_ERROR;}

bool skill_user_if::can_use_skill(e_skill kid, int klv) {RAISE_NOT_IMPLEMENTED_ERROR;}
ai_t::done_func& skill_user_if::cast_end_func() {RAISE_NOT_IMPLEMENTED_ERROR;}
int skill_user_if::check_skill(e_skill kid) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool skill_user_if::collect_coins(int cou) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool skill_user_if::collect_spirits(int cou) {RAISE_NOT_IMPLEMENTED_ERROR;}
s_skill* skill_user_if::find_skill(const std::string& nam) {RAISE_NOT_IMPLEMENTED_ERROR;}
s_skill* skill_user_if::find_skill(int kid) {RAISE_NOT_IMPLEMENTED_ERROR;}
void skill_user_if::iterate_skill(yield_skill_func yie) {RAISE_NOT_IMPLEMENTED_ERROR;}
ptr<registry_t<e_skill,int>>& skill_user_if::limit_skills() {RAISE_NOT_IMPLEMENTED_ERROR;}
int skill_user_if::skill_point() {RAISE_NOT_IMPLEMENTED_ERROR;}
s_skill* skill_user_if::skill(e_skill kid) {RAISE_NOT_IMPLEMENTED_ERROR;}
int skill_user_if::skill_range(e_skill kid, int klv) {RAISE_NOT_IMPLEMENTED_ERROR;}
void skill_user_if::skill_up(e_skill kid) {RAISE_NOT_IMPLEMENTED_ERROR;}
void skill_user_if::use_encore(e_skill dan_id) {RAISE_NOT_IMPLEMENTED_ERROR;}
bool skill_user_if::use_magicpower() {RAISE_NOT_IMPLEMENTED_ERROR;}
void skill_user_if::use_skill_bl(e_skill kid, int klv, block_list* bl_, bool tur_end, ai_t::done_func cas_end_fun) {RAISE_NOT_IMPLEMENTED_ERROR;}
void skill_user_if::use_skill_block(e_skill kid, int klv, block_if* blo, bool tur_end, ai_t::done_func cas_end_fun) {RAISE_NOT_IMPLEMENTED_ERROR;}
void skill_user_if::use_skill_self(e_skill kid, int klv, bool tur_end, ai_t::done_func cas_end_fun) {RAISE_NOT_IMPLEMENTED_ERROR;}
void skill_user_if::use_skill_xy(e_skill kid, int klv, int x, int y, bool tur_end, ai_t::done_func cas_end_fun) {RAISE_NOT_IMPLEMENTED_ERROR;}

bool slave_if::exists() {RAISE_NOT_IMPLEMENTED_ERROR;}
bool slave_if::is_active() {RAISE_NOT_IMPLEMENTED_ERROR;}
block_if*& slave_if::master() {RAISE_NOT_IMPLEMENTED_ERROR;}

// ���ӂɕǂ����邩�B
bool& battler_impl::around_wall_exists() {
	return around_wall_exists_;
}

// �u���b�N���U������B
void battler_impl::attack(
	block_if* blo, // �u���b�N�B
	bool con       // �A�����B
) {
	unit_attack(bl(), blo->bl()->id, con);
}

// �m�b�N�o�b�N�X�L�����������X�^�[�ɍU�����󂯂Ă��邩�B
bool& battler_impl::attacked_by_blower() {
	return attacked_by_blower_;
}

// ���m�\�����X�^�[�ɍU�����󂯂Ă��邩�B
bool& battler_impl::attacked_by_detector() {
	return attacked_by_detector_;
}

// �U�����󂯂Ă���G�����X�^�[�̃x�N�^�B
std::vector<block_if*>& battler_impl::attacked_enemies() {
	return attacked_enemies_;
}

// �U�����󂯂Ă��鉓�u�U�������X�^�[�B
block_if*& battler_impl::attacked_long_range_attacker() {
	return attacked_long_range_attacker_;
}

// �U�����󂯂Ă���ߐڍU�������X�^�[�B
block_if*& battler_impl::attacked_short_range_attacker() {
	return attacked_short_range_attacker_;
}

// �U�����󂯂Ă���ߐڍU�������X�^�[���B
int& battler_impl::attacked_short_range_attackers() {
	return attacked_short_range_attackers_;
}

// �f�B�{�[�V�����o�R�ōU�����󂯂Ă��邩�B
bool& battler_impl::attacked_via_devotion() {
	return attacked_via_devotion_;
}

// �퓬���̃C���f�b�N�X�B
int& battler_impl::battle_index() {
	return battle_index_;
}

// �퓬���[�h�B
battle_modes& battler_impl::battle_mode() {
	return battle_mode_;
}

// �o�g���[���G�����X�^�[���U�����Ă����v���𔻒肷��B
bool // ���ʁB
battler_impl::check_attack(
	block_if* ene // �G�����X�^�[�B
) {
	block_if* tan = ene->target_battler();
	return battle_mode() == BM_TAUNT ||
		!ene->has_can_attack() ||
		ene->is_long_range_attacker() ||
		ene->is_flora() ||
		ene->is_paralysis() ||
		ene->sc()->data[SC_BLADESTOP] ||
		(ene->is_berserk() && 
			(!ene->is_great(leader()) ||
				!around_wall_exists() ||
				!tan ||
				!tan->is_primary() ||
				!tan->attacked_by_blower() ||
				tan->is_wall_side()
			)
		);
}

// �o�g���[��HP�����v���𔻒肷��B
bool // ���ʁB
battler_impl::check_hp(
	int rat // HP�̎l�����B
) {
	return check_quad_ratio(hp(), max_hp(), rat);
}

// �o�g���[���G�����X�^�[��ʏ�U�����Ă����v���𔻒肷��B
bool // ���ʁB
battler_impl::check_normal_attack(
	block_if* ene // �G�����X�^�[�B
) {
	return check_attack(ene) &&
		!ene->is_hiding() &&
		(is_short_range_attacker() ||
			!ene->is_long_weapon_immune()
		);
}

// �o�g���[��SP�����v���𔻒肷��B
bool // ���ʁB
battler_impl::check_sp(
	int rat // SP�̎l�����B
) {
	return ((leader()->sp_suppliable() ||
				sc()->data[SC_DIGESTPOTION]
			) && !check_supply_sp()
		) || check_quad_ratio(sp(), max_sp(), rat);
}

// �o�g���[��SP�̋����������邩�𔻒肷��B
bool // ���ʁB
battler_impl::check_supply_sp() {
	return sp() * 100 < get_supply_sp_rate() * max_sp();
}

// �o�g���[���G�����X�^�[�ɃX�L�����g���Ă����v���𔻒肷��B
bool // ���ʁB
battler_impl::check_use_skill(
	e_skill kid,  // �X�L��ID�B
	int klv,      // �X�L�����x���B
	block_if* ene // �G�����X�^�[�B
) {
	return check_attack(ene) &&
		(skill_get_nk(kid) & NK_NO_DAMAGE ||
			((skill_get_inf3(kid) & INF3_HIT_HIDING ||
					!ene->is_hiding()
				) && (!(skill_get_type(kid) & BF_WEAPON) ||
					((skill_range(kid, klv) > 3 ||
							!ene->sc()->data[SC_SAFETYWALL]
						) && (skill_range(kid, klv) <= 3 ||
							!ene->is_long_weapon_immune()
						) && (!ene->sc()->data[SC_REFLECTSHIELD] ||
							skill_range(kid, klv) > 3 ||
							kid == NJ_ISSEN ||
							check_hp(3)
						)
					)
				) && (!(skill_get_type(kid) & BF_MAGIC) ||
					(!ene->is_magic_immune() &&
						(!(skill_get_inf(kid) & INF_ATTACK_SKILL) ||
							!ene->sc()->data[SC_FOGWALL]
						)
					)
				)
			)
		);
}

// �o�g���[���G�����X�^�[�ɒ����ړI�ŃX�L�����g���ׂ����𔻒肷��B
bool battler_impl::check_use_taunt_skill(block_if* ene) {
	return !check_attack_range(ene) &&
		ene->has_can_attack() &&
		ene->has_can_move() &&
		!ene->is_berserk() &&
		!ene->md()->tdmg &&
		!ene->sc()->data[SC_PROVOKE];
}

// �����|���V�[�l�B
distance_policy_values& battler_impl::distance_policy_value() {
	return distance_policy_value_;
}

// �X�L����T���B
s_skill* // ���������X�L���B������Ȃ�������nullptr�B
battler_impl::find_skill(
	const std::string& nam // �X�L�����B�����Ȃ�X�L��ID�B
) {
	s_skill* res = nullptr;
	int kid = parse_id(nam);
	if (kid) {
		if (kid != INT_MIN) res = find_skill(kid);
	} else {
		std::string nam_lc = lowercase(nam);
		iterate_skill([nam_lc, &res] (s_skill* sk) -> bool {
			if (lowercase(skill_get_desc(sk->id)) == nam_lc) {
				res = sk;
				return false;
			}
			return true;
		});
	}
	return res;
}

// �X�L����T���B
s_skill* // ���������X�L���B������Ȃ�������nullptr�B
battler_impl::find_skill(
	int kid // �X�L��ID�B
) {
	s_skill* res = nullptr;
	iterate_skill([kid, &res] (s_skill* sk) -> bool {
		if (sk->id == kid) {
			res = sk;
			return false;
		}
		return true;
	});
	return res;
}

// �ō��̈ʒu���B
bool& battler_impl::is_best_pos() {
	return is_best_pos_;
}

// �ꎟ�o�g���[���𔻒肷��B
bool // ���ʁB
battler_impl::is_primary() {
	return !battle_index();
}

// �ʏ�U���|���V�[�l�B
normal_attack_policy_values& battler_impl::normal_attack_policy_value() {
	return normal_attack_policy_value_;
}

// �X�L���̃_���[�W�{�����v�Z����B
int // �v�Z�����{���B
battler_impl::skill_ratio(
	e_skill kid,  // �X�L��ID�B
	int klv,      // �X�L�����x���B
	block_if* tar // �^�[�Q�b�g�B
) {
	int rat = 0;
	if (!(skill_get_type(kid) & BF_MAGIC) ||
		!tar->is_magic_immune()
	) {
		e_element ele = e_element(skill_get_ele(kid, klv));
		if (ele == ELE_NONE) ele = weapon_attack_element();
		rat = attack_element_ratio(tar, ele);
	}
	return rat;
}

// �o�g���[�������n�߂�B
void battler_impl::start_walking() {
	if (dynamic_cast<member_impl*>(this)) {
		pc_delinvincibletimer(sd());
		if (sc()->data[SC_DANCING] &&
			!sc()->data[SC_LONGING]
		) {
			status_change_end(bl(), SC_DANCING, INVALID_TIMER);
			skill_used_ticks()[BD_ADAPTATION] = now;
		}
		if (is_gospel()) status_change_end(bl(), SC_GOSPEL, INVALID_TIMER);
	}
}

// �U�����~����B
void battler_impl::stop_attacking() {
	unit_stop_attack(bl());
}

// ���s���~����B
void battler_impl::stop_walking(int typ) {
	unit_stop_walking(bl(), typ);
}

// �^�[�Q�b�g���Ă���G�����X�^�[�B
block_if*& battler_impl::target_enemy() {
	return target_enemy_;
}

// �o�g���[���u���b�N�Ɍ������ĕ����B
bool // ����Ă��邩�B
battler_impl::walk_bl(
	block_list* tbl, // �^�[�Q�b�g�̃u���b�N�B
	int ran          // �߂Â������B
) {
	if (check_range_bl(bl(), tbl, ran)) {
		stop_walking();
		return false;
	}
	if (!is_walking() ||
		!check_range_blxy(tbl, ud()->to_x, ud()->to_y, ran)
	) {
		start_walking();
		unit_walktobl(bl(), tbl, ran, 0);
	}
	return true;
}

// ���s�I���n���h���B
ai_t::done_func& battler_impl::walk_end_func() {
	return walk_end_func_;
}

// �o�g���[�����W�Ɍ������ĕ����B
bool // ����Ă��邩�B
battler_impl::walk_xy(
	int x,  // X���W�B
	int y,  // Y���W�B
	int ran // �߂Â������B
) {
	if (check_range_blxy(bl(), x, y, ran)) {
		stop_walking();
		return false;
	}
	if ((!is_walking() ||
			!check_range_xy(ud()->to_x, ud()->to_y, x, y, ran)
		) && can_move()
	) {
		start_walking();
		ud()->target_to = -1;
		ud()->chaserange = ran;
		unit_walktoxy(bl(), x, y, 0);
	}
	return true;
}

// ����U���̑����_���[�W�{�����v�Z����B
int // �v�Z�����{���B
battler_impl::weapon_attack_element_ratio(
	block_if* tar // �^�[�Q�b�g�B
) {
	return attack_element_ratio(tar, weapon_attack_element());
}

// Bot�̃C���f�b�N�X�B
int& bot_impl::bot_index() {
	return bot_index_;
}

// �Ō�ɃG���[�V������\�������`�b�N�B
t_tick& bot_impl::last_emotion_tick() {
	return last_emotion_tick_;
}

// �Ō�ɕ���ꎮ�������[�h�����`�b�N�B
t_tick& bot_impl::last_reloaded_equipset_tick() {
	return last_reloaded_equipset_tick_;
}

// Bot�����X�|�[������B
void bot_impl::respawn() {
	walk_end_func() = cast_end_func() = nullptr;
	pc_respawn(sd(), CLR_OUTSIGHT);
	sd()->state.rewarp = 0;
	clif_parse_LoadEndAck(fd(), sd());
}

// Bot���e���|�[�g����B
bool // �e���|�[�g�������B
bot_impl::teleport(
	block_list* bl_ // �e���|�[�g��̃u���b�N���X�g�B
) {
	bool done = false;
	if (bl_->m != bl()->m ||
		bl_->x != bl()->x ||
		bl_->y != bl()->y
	) {
		walk_end_func() = cast_end_func() = nullptr;
		stop_attacking();
		stop_walking(USW_FORCE_STOP);
		pc_setpos(sd(), map_id2index(bl_->m), bl_->x, bl_->y, CLR_TELEPORT, true);
		sd()->state.rewarp = 0;
		clif_parse_LoadEndAck(fd(), sd());
		done = true;
	}
	return done;
}

// Bot�����t�������X�L���B
e_skill& bot_impl::want_to_play() {
	return want_to_play_;
}

// �N���C�A���g�ɂ�����2�̃u���b�N���X�g�������͈͓����𔻒肷��B
bool // ���ʁB
client_impl::check_range_bl(
	block_list* bl0, // �u���b�N���X�g0�B
	block_list* bl1, // �u���b�N���X�g1�B
	int dis          // �����B
) {
	return check_distance_client_bl(bl0, bl1, dis);
}

// �N���C�A���g�ɂ����ău���b�N���X�g�ƍ��W�������͈͓����𔻒肷��B
bool // ���ʁB
client_impl::check_range_blxy(
	block_list* bl_, // �u���b�N���X�g�B
	int x,           // X���W�B
	int y,           // Y���W�B
	int dis          // �����B
) {
	return check_distance_client_blxy(bl_, x, y, dis);
}

// �N���C�A���g�ɂ�����2�̍��W�������͈͓����𔻒肷��B
bool // ���ʁB
client_impl::check_range_xy(
	int x0, // X0���W�B
	int y0, // Y0���W�B
	int x1, // X1���W�B
	int y1, // Y1���W�B
	int dis // �����B
) {
	return check_distance_client_xy(x0, y0, x1, y1, dis);
}

// �U�����󂯂Ă���o�g���[�̃x�N�^�B
std::vector<block_if*>& enemy_impl::attacked_battlers() {
	return attacked_battlers_;
}

// �G�����X�^�[���痣��Ă���ƌ����鋗�����擾����B
int // �擾���������B
enemy_impl::away_distance(
	block_if* lea // ���[�_�[�B
) {
	int dis = battle_config.pybot_away_distance;
	if (is_great(lea) &&
		is_short_range_attacker()
	) dis = battle_config.pybot_away_distance_great;
	return dis;
}

// �U���͈͓��ɂ���o�g���[�̃x�N�^�B
std::vector<block_if*>& enemy_impl::close_battlers() {
	return close_battlers_;
}

// �t���p���[�𔭊�����ׂ����𔻒肷��B
bool // ���ʁB
enemy_impl::fullpower(
	block_if* lea // ���[�_�[�B
) {
	return lea->rush()->get() ||
		is_great(lea);
}

// �A�[�X�N�G�C�N�������B
bool& enemy_impl::has_earthquake() {
	return has_earthquake_;
}

// �m�b�N�o�b�N�X�L���������B
bool& enemy_impl::has_knockback_skill() {
	return has_knockback_skill_;
}

// ���C�A�E�g�X�L���������B
bool& enemy_impl::has_layout_skill() {
	return has_layout_skill_;
}

// ���u�X�L���������B
bool& enemy_impl::has_long_skill() {
	return has_long_skill_;
}

// ���u�����X�L���������B
bool& enemy_impl::has_long_weapon_skill() {
	return has_long_weapon_skill_;
}

// �p�X�X�L���������B
bool& enemy_impl::has_path_skill() {
	return has_path_skill_;
}

// �����X�L���������B
bool& enemy_impl::has_summon_skill() {
	return has_summon_skill_;
}

// �Z�����X�L���������B
bool& enemy_impl::has_unequip_armor_skill() {
	return has_unequip_armor_skill_;
}

// �������X�L���������B
bool& enemy_impl::has_unequip_helm_skill() {
	return has_unequip_helm_skill_;
}

// �������X�L���������B
bool& enemy_impl::has_unequip_shield_skill() {
	return has_unequip_shield_skill_;
}

// ��������X�L���������B
bool& enemy_impl::has_unequip_weapon_skill() {
	return has_unequip_weapon_skill_;
}

// �L�p�X�L���������B
bool& enemy_impl::has_usefull_skill() {
	return has_usefull_skill_;
}

// �͈͊O�Ɉړ�����K�v�����邩�𔻒肷��B
bool // ���ʁB
enemy_impl::need_to_leave() {
	return has_can_move() &&
		is_short_range_attacker() &&
		(sc()->data[SC_PNEUMA] ||
			sc()->data[SC_SAFETYWALL] ||
			skill_unit_exists_block(this, skill_unit_key_map{SKILL_UNIT_KEY(PF_FOGWALL)})
		);
}

// �^�[�Q�b�g���Ă���o�g���[�B
block_if*& enemy_impl::target_battler() {
	return target_battler_;
}

// �X�L�����^�[�Q�b�g���Ă���o�g���[�B
block_if*& enemy_impl::skill_target_battler() {
	return skill_target_battler_;
}

// �G�����X�^�[��҂��󂯂�ʒu���擾����B
pos_t enemy_impl::waiting_position() {
	pos_t pos{0, bl()->x, bl()->y};
	if (is_short_range_attacker() &&
		is_walking()
	) pos = pos_t(0, ud()->to_x, ud()->to_y);
	return pos;
}

// ���s��Ƃ��ă^�[�Q�b�g���Ă���o�g���[�B
block_if*& enemy_impl::walk_target_battler() {
	return walk_target_battler_;
}

// �A�N�V�������I����B
void general_impl::act_end() {
	ud()->canact_tick = std::max(ud()->canact_tick, now + status_get_amotion(bl()));
}

// �U���ɂ�鑮���_���[�W�{�����擾����B
int // �擾�����{���B
general_impl::attack_element_ratio(
	block_if* tar, // �^�[�Q�b�g�B
	e_element ele  // �����B
) {
	return int(battle_attr_fix(
		bl(),
		tar->bl(),
		100,
		ele,
		status_get_element(tar->bl()),
		status_get_element_level(tar->bl())
	));
}

// �U���̎˒����擾����B
int // �擾�����˒��B
general_impl::attack_range() {
	return status_get_range(bl());
}

// �A�N�V�����\���𔻒肷��B
bool // ���ʁB
general_impl::can_act() {
	return DIFF_TICK(now, ud()->canact_tick) >= 0 &&
		ud()->skilltimer == INVALID_TIMER;
}

// �ړ��\���𔻒肷��B
bool // ���ʁB
general_impl::can_move() {
	return (unit_can_move(bl()) ||
			is_ensemble() ||
			is_gospel()
		) && DIFF_TICK(now, ud()->canmove_tick) >= 0;
}

// �u���b�N���X�g�ɓ��B�\���𔻒肷��B
bool // ���ʁB
general_impl::can_reach_bl(
	block_list* bl_, // �u���b�N���X�g�B
	bool eas         // �ȈՒT�����B
) {
	return unit_can_reach_bl(bl(), bl_, 0, eas, nullptr, nullptr);
}

// �u���b�N�ɓ��B�\���𔻒肷��B
bool // ���ʁB
general_impl::can_reach_block(
	block_if* blo, // �u���b�N�B
	bool eas       // �ȈՒT�����B
) {
	return can_reach_bl(blo->bl(), eas);
}

// ���W�ɓ��B�\���𔻒肷��B
bool // ���ʁB
general_impl::can_reach_xy(
	int x,   // X���W�B
	int y,   // Y���W�B
	bool eas // �ȈՒT�����B
) {
	return unit_can_reach_pos(bl(), x, y, eas);
}

// �����X�^�[�̍U���˒����ɂ��邩�𔻒肷��B
bool // ���ʁB
general_impl::check_attack_range(
	block_if* blo // �U�����󂯂�u���b�N�B
) {
	return check_range_bl(bl(), blo->bl(), attack_range());
}

// �u���b�N���X�g�Ɏ������ʂ邩�𔻒肷��B
bool // ���ʁB
general_impl::check_line_bl(
	block_list* bl_ // �u���b�N���X�g�B
) {
	return check_line_xy(bl_->x, bl_->y);
}

// �u���b�N�Ɏ������ʂ邩�𔻒肷��B
bool // ���ʁB
general_impl::check_line_block(
	block_if* blo // �u���b�N�B
) {
	return check_line_bl(blo->bl());
}

// ���W�Ɏ������ʂ邩�𔻒肷��B
bool // ���ʁB
general_impl::check_line_xy(
	int x, // X���W�B
	int y  // Y���W�B
) {
	return path_search_long(NULL, bl()->m, bl()->x, bl()->y, x, y, CELL_CHKWALL);
}

// ��ԕω����Ă��邩�𔻒肷��B
bool // ���ʁB
general_impl::check_sc_types(
	const sc_type_set& sc_typs
) {
	for (sc_type sc_typ : sc_typs) {
		if (sc()->data[sc_typ]) return true;
	}
	return false;
}

// �u���b�N���X�L���˒������𔻒肷��B
bool // ���ʁB
general_impl::check_skill_range_block(
	e_skill kid,  // �X�L��ID�B
	int klv,      // �X�L�����x���B
	block_if* blo // �X�L�����󂯂�u���b�N�B
) {
	return check_skill_range_xy(kid, klv, blo->bl()->x, blo->bl()->y);
}

// ���W���X�L���˒������𔻒肷��B
bool // ���ʁB
general_impl::check_skill_range_xy(
	e_skill kid, // �X�L��ID�B
	int klv,     // �X�L�����x���B
	int x,       // X���W�B
	int y        // Y���W�B
) {
	return check_range_blxy(bl(), x, y, skill_range(kid, klv));
}

// Def���擾����B
defType general_impl::def() {
	return status_get_def(bl());
}

// Def2���擾����B
int general_impl::def2() {
	return status_get_def2(bl());
}

// �������擾����B
e_element // �擾���������B
general_impl::element() {
	return e_element(status_get_element(bl()));
}

// Flee���擾����B
int // �擾����Flee�B
general_impl::flee() {
	return status_get_flee(bl());
}

// Hit���擾����B
int // �擾����Hit�B
general_impl::hit() {
	return status_get_hit(bl());
}

// HP���擾����B
int // �擾����HP�B
general_impl::hp() {
	return status_get_hp(bl());
}

// HP�̕S�������v�Z����B
int // ���ʁB
general_impl::hp_ratio() {
	return hp() * 100 / max_hp();
}

// ���̃u���b�N�����_�Ƃ��āA2�_�̓��ς��v�Z����B
int general_impl::inner_product(const coords_t& a, const coords_t& b) {
	coords_t A{a.x - bl()->x, a.y - bl()->y};
	coords_t B{b.x - bl()->x, b.y - bl()->y};
	return A.x * B.x + A.y * B.y;
}

// �U�������𔻒肷��B
bool general_impl::is_attacking() {
	return ud()->target &&
		ud()->state.attack_continue;
}

// �r�������𔻒肷��B
bool // ���ʁB
general_impl::is_casting() {
	return ud()->skilltimer != INVALID_TIMER;
}

// ���t���Ă��邩�𔻒肷��B
bool // ���ʁB
general_impl::is_ensemble() {
	return sc()->data[SC_DANCING] &&
		sc()->data[SC_DANCING]->val4;
}

// �S�X�y�����Ă��邩�𔻒肷��B
bool // ���ʁB
general_impl::is_gospel() {
	return sc()->data[SC_GOSPEL] &&
		sc()->data[SC_GOSPEL]->val4 == BCT_SELF;
}

// �n�C�f�B���O��Ԃ��𔻒肷��B
bool // ���ʁB
general_impl::is_hiding() {
	return sc()->option & (OPTION_HIDE | OPTION_CLOAK | OPTION_CHASEWALK | OPTION_INVISIBLE);
}

// ���u�U�����𔻒肷��B
bool // ���ʁB
general_impl::is_long_range_attacker() {
	return attack_range() > 3;
}

// ���u�����U���ϐ���Ԃ��𔻒肷��B
bool // ���ʁB
general_impl::is_long_weapon_immune() {
	return sc()->data[SC_FOGWALL] ||
		sc()->data[SC_PNEUMA] ||
		sc()->data[SC_TATAMIGAESHI];
}

// ��჏�Ԃ��𔻒肷��B
bool // ���ʁB
general_impl::is_paralysis() {
	return sc()->opt1 &&
		sc()->opt1 != OPT1_BURNING;
}

// �ߐڍU�����𔻒肷��B
bool // ���ʁB
general_impl::is_short_range_attacker() {
	return attack_range() <= 3;
}

// �Ƒt���Ă��邩�𔻒肷��B
bool // ���ʁB
general_impl::is_solo() {
	return sc()->data[SC_DANCING] &&
		!sc()->data[SC_DANCING]->val4;
}

// ���s�����𔻒肷��B
bool // ���ʁB
general_impl::is_walking() {
	return unit_is_walking(bl());
}

// �ő�HP���擾����B
int // �擾�����ő�HP�B
general_impl::max_hp() {
	return status_get_max_hp(bl());
}

// �ő�SP���擾����B
int // �擾�����ő�SP�B
general_impl::max_sp() {
	return status_get_max_sp(bl());
}

// Mdef���擾����B
defType general_impl::mdef() {
	return status_get_mdef(bl());
}

// ���̏�ɂ��邩�𔻒肷��B
bool // ���ʁB
general_impl::on_water() {
	return map_getcellp(map_getmapdata(bl()->m), bl()->x, bl()->y, CELL_CHKWATER);
}

// �푰���擾����B
e_race // �擾�����푰�B
general_impl::race() {
	return e_race(status_get_race(bl()));
}

// �푰2���擾����B
e_race2 // �擾�����푰2�B
general_impl::race2() {
	return e_race2(status_get_race2(bl()));
}

// ��ԕω����擾����B
status_change* // �擾������ԕω��B
general_impl::sc() {
	return status_get_sc(bl());
}

// ��ԕω��̎c�莞�Ԃ��擾����B
t_tick // �擾�����c�莞�ԁB�i���Ȃ�INFINITE_TICK�B
general_impl::sc_rest(
	sc_type typ // ��ԁB
) {
	t_tick res = INFINITE_TICK;
	status_change_entry* sce = sc()->data[typ];
	if (sce) {
		const TimerData * td = get_timer(sce->timer);
		if (td &&
			td->tick != INFINITE_TICK
		) res = DIFF_TICK(td->tick, now);
	}
	return res;
}

// �傫�����擾����B
size // �擾�����傫���B
general_impl::size_() {
	return size(status_get_size(bl()));
}

// �ݒu�X�L���̃A�h�o���e�[�W���擾����B
int // �擾�����A�h�o���e�[�W�B
general_impl::skill_advantage(
	int x, // X���W�B
	int y  // Y���W�B
) {
	int adv = 0;
	iterate_skill_unit(bl()->m, x, y, [this, &adv] (skill_unit* kun, block_list* src_bl) -> int {
		const std::unordered_map<e_skill,int>* advs;
		if (battle_check_target(bl(), src_bl, BCT_ENEMY) > 0) {
			if (distance_policy_value() == DPV_CLOSE) advs = &ENEMY_SKILL_ADVANTAGES_CLOSE;
			else advs = &ENEMY_SKILL_ADVANTAGES_AWAY;
		} else {
			if (distance_policy_value() == DPV_CLOSE) advs = &ALLY_SKILL_ADVANTAGES_CLOSE;
			else advs = &ALLY_SKILL_ADVANTAGES_AWAY;
		}
		adv += find_map_data(*advs, e_skill(kun->group->skill_id), 0);
		return 0;
	});
	return adv;
}

// SP���擾����B
int // �擾����SP�B
general_impl::sp() {
	return status_get_sp(bl());
}

// SP�̕S�������v�Z����B
int // ���ʁB
general_impl::sp_ratio() {
	return sp() * 100 / max_sp();
}

// ���j�b�g�f�[�^���擾����B
unit_data* // �擾�������j�b�g�f�[�^�B
general_impl::ud() {
	return unit_bl2ud(bl());
}

// Vit���擾����B
int general_impl::vit() {
	return status_get_vit(bl());
}

// ���s�o�H�̒������擾����B
int // �擾���������B
general_impl::walkpath_length() {
	return ud()->walkpath.path_len - ud()->walkpath.path_pos;
}

// ���s�o�H��̈ʒu���擾����B
pos_t // �擾�����ʒu�B
general_impl::walkpath_pos(
	int stes // �����B
) {
	pos_t pos(0, bl()->x, bl()->y, stes);
	for (int i = 0; i < stes; ++i) {
		directions dir = ud()->walkpath.path[ud()->walkpath.path_pos + i];
		pos.x += dirx[dir];
		pos.y += diry[dir];
	}
	return pos;
}

// �z�����N���X�̃u���b�N���X�g���擾����B
block_list* // �擾�����u���b�N���X�g�B
homun_impl::bl() {
	return &hd()->bl;
}

// �z�����N���X���X�L�����g���邩�𔻒肷��B
bool // ���ʁB
homun_impl::can_use_skill(
	e_skill kid, // �X�L��ID�B
	int klv      // �X�L�����x���B
) {
	return !(sc()->option & OPTION_INVISIBLE) &&
		skill_check_condition_mercenary(bl(), kid, klv, 0) &&
		skill_check_condition_mercenary(bl(), kid, klv, 2);
}

// �z�����N���X�̃X�L�����`�F�b�N����B
int // �ő僌�x���B
homun_impl::check_skill(
	e_skill kid // �X�L��ID�B
) {
	int klv = hom_checkskill(hd(), kid);
	int* lim_slv = master()->limit_skills()->find(kid);
	if (lim_slv) klv = std::min(klv, *lim_slv);
	return klv;
}

// �z�����N���X�̃f�t�H���g�����|���V�[�l���擾����B
distance_policy_values // �擾���������|���V�[�l�B
homun_impl::default_distance_policy_value() {
	distance_policy_values dis_pol_val = DPV_CLOSE;
	if (homun_mapid_() == MAPID_LIF &&
		!check_skill(HLIF_CHANGE)
	) dis_pol_val = DPV_AWAY;
	return dis_pol_val;
}

// �z�����N���X�̃f�t�H���g�ʏ�U���|���V�[�l���擾����B
normal_attack_policy_values // �擾�����ʏ�U���|���V�[�l�B
homun_impl::default_normal_attack_policy_value() {
	normal_attack_policy_values nor_att_pol_val = NAPV_CONTINUOUS;
	if ((homun_mapid_() == MAPID_LIF &&
			!check_skill(HLIF_CHANGE)
		) || (homun_mapid_() == MAPID_AMISTR &&
			!check_skill(HAMI_BLOODLUST)
		)
	) nor_att_pol_val = NAPV_SINGLE;
	return nor_att_pol_val;
}

// �z�����N���X�̍ő勗���̒l���擾����B
int // �擾�����ő勗���̒l�B
homun_impl::distance_max_value() {
	return battle_config.pybot_around_distance;
}

// �z�����N���X�����݂��邩�𔻒肷��B
bool // ���ʁB
homun_impl::exists() {
	return master()->sd()->status.hom_id &&
		hd();
}

// �z�����N���X�������邱�Ƃ̂ł��郂���X�^�[�����擾����B
int // �擾���������X�^�[���B
homun_impl::get_hold_mobs() {
	int res = INT_MAX;
	if (distance_policy_value() == DPV_AWAY) res = 0;
	return res;
}

// �z�����N���X�̃����X�^�[�̍�Def���擾����B
int // �擾������Def�B
homun_impl::get_mob_high_def() {
	return master()->get_mob_high_def();
}

// �z�����N���X�̃����X�^�[�̍�DefVit���擾����B
int // �擾������DefVit�B
homun_impl::get_mob_high_def_vit() {
	return master()->get_mob_high_def_vit();
}

// �z�����N���X�̃����X�^�[�̍�Flee���擾����B
int // �擾������Flee�B
homun_impl::get_mob_high_flee() {
	return master()->get_mob_high_flee();
}

// �z�����N���X�̃����X�^�[�̍�Hit���擾����B
int // �擾������Hit�B
homun_impl::get_mob_high_hit() {
	return master()->get_mob_high_hit();
}

// �z�����N���X�̃����X�^�[�̍�Mdef���擾����B
int // �擾������Mdef�B
homun_impl::get_mob_high_mdef() {
	return master()->get_mob_high_mdef();
}

// �z�����N���X��SP�̋�����������SP�����擾����B
int // �擾������Hit�B
homun_impl::get_supply_sp_rate() {
	return DEFAULT_SUPPLY_SP_RATE;
}

// �z�����N���X�f�[�^���擾����B
homun_data* // �擾�����z�����N���X�f�[�^�B
homun_impl::hd() {
	return master()->sd()->hd;
}

// �z�����N���X�̃}�b�vID���擾����B
homun_mapid // �擾�����}�b�vID�B�i���̓A���}�X�N�����B
homun_impl::homun_mapid_() {
	return homun_mapid(hom_class2mapid(hd()->homunculus.class_) & ~HOM_EVO);
}

// �z�����N���X���A�N�e�B�u���𔻒肷��B
bool // ���ʁB
homun_impl::is_active() {
	return exists() &&
		hom_is_active(hd());
}

// �z�����N���X�����S���𔻒肷��B
bool // ���ʁB
homun_impl::is_dead() {
	return hd()->homunculus.vaporize != HOM_ST_REST &&
		status_isdead(bl());
}

// �z�����N���X�����G��Ԃ��𔻒肷��B
bool // ���ʁB
homun_impl::is_invincible() {
	return false;
}

// �z�����N���X�����@�ϐ����𔻒肷��B
bool // ���ʁB
homun_impl::is_magic_immune() {
	return status_isimmune(bl());
}

// �z�����N���X���L���X�g���f�������𔻒肷��B
bool // ���ʁB
homun_impl::is_no_castcancel() {
	return false;
}

// �z�����N���X���W�F���X�g�[������Ȃ����𔻒肷��B
bool // ���ʁB
homun_impl::is_no_gemstone() {
	return false;
}

// �z�����N���X���Ǎۂɂ��邩�𔻒肷��B
bool // ���ʁB
homun_impl::is_wall_side() {
	return master() == leader() ||
		check_wall_side(bl()->m, bl()->x, bl()->y);
}

// �z�����N���X�̃X�L���𔽕�����B
void homun_impl::iterate_skill(
	yield_skill_func yie // �X�L���l���n���h���B
) {
	for (int kid = HM_SKILLBASE; kid < HM_SKILLBASE + MAX_HOMUNSKILL; ++kid) {
		int kind = hom_skill_get_index(kid);
		if (kind >= 0) {
			s_skill* sk = &hd()->homunculus.hskill[kind];
			if (sk->id &&
				!yie(sk)
			) break;
		}
	}
}

// �����X�L���̃��W�X�g���B
ptr<registry_t<e_skill,int>>& homun_impl::limit_skills() {
	return master()->limit_skills();
}

// �z�����N���X���|���V�[�����[�h����B
void homun_impl::load_policy(
	int mid,                                     // �����X�^�[ID�B
	distance_policy_values* dis_pol_val,         // �����|���V�[�l�B
	normal_attack_policy_values* nor_att_pol_val // �U���|���V�[�l�B
) {}

// �z�����N���X�̖��O���擾����B
std::string // �擾�������O�B
homun_impl::name() {
	return hd()->homunculus.name;
}

// �z�����N���X���m�b�N�o�b�N�ϐ���Ԃ��𔻒肷��B
bool // ���ʁB
homun_impl::no_knockback() {
	return false;
}

// ��l�̋��ۃX�L���̃��W�X�g���B
ptr<registry_t<e_skill>>& homun_impl::reject_skills() {
	return master()->reject_skills();
}

// �z�����N���X�̃X�L�����擾����B
s_skill* // �擾�����X�L���B�Ȃ����nullptr�B
homun_impl::skill(
	e_skill kid
) {
	int kind = hom_skill_get_index(kid);
	if (kind >= 0) return &hd()->homunculus.hskill[kind];
	return nullptr;
}

// �z�����N���X�̃X�L���|�C���g���擾����B
int // �擾�����X�L���|�C���g�B
homun_impl::skill_point() {
	return hd()->homunculus.skillpts;
}

// �z�����N���X�̃X�L�����グ��B
void homun_impl::skill_up(
	e_skill kid // �X�L��ID�B
) {
	hom_skillup(hd(), kid);
}

// �z�����N���X���e���|�[�g����B
bool // �e���|�[�g�������B
homun_impl::teleport(
	block_list* bl_ // �e���|�[�g��̃u���b�N���X�g�B
) {
	bool done = false;
	if (bl_->x != bl()->x ||
		bl_->y != bl()->y
	) {
		stop_attacking();
		stop_walking(USW_FORCE_STOP);
		unit_warp(bl(), bl_->m, bl_->x, bl_->y, CLR_TELEPORT);
		done = true;
	}
	return done;
}

// �z�����N���X�̕���U���̑������擾����B
e_element // �擾���������B
homun_impl::weapon_attack_element() {
	return ELE_NEUTRAL;
}

// �A�C�e���g�p�`�b�N�̃}�b�v�B
std::unordered_map<int,t_tick>& item_user_impl::item_used_ticks() {
	return item_used_ticks_;
}

// �A�C�e�����g���B
void item_user_impl::use_item(
	int ind, // �C���f�b�N�X�B
	bool exc // ��O���B
) {
	item* itm = &sd()->inventory.u.items_inventory[ind];
	if (itm->nameid &&
		!pc_useitem(sd(), ind)
	) item_used_ticks()[itm->nameid] = now;
	if (exc) throw item_used_exception();
}

// ���������X�^�[�̃}�b�v�B
std::unordered_map<int,ptr<block_if>>& leader_impl::ally_mobs() {
	return ally_mobs_;
}

// �U���ΏۂƂ��郂���X�^�[�̃u���b�NID�B
int& leader_impl::attack_target() {
	return attack_target_;
}

// ��q�w�n���擾����B
coords_t leader_impl::back_base() {
	coords_t res{};
	int bacs_siz = 0;
	for (block_if* mem : members()) {
		if (!mem->is_dead() &&
			mem->distance_policy_value() == DPV_AWAY
		) {
			res.x += mem->bl()->x;
			res.y += mem->bl()->y;
			++bacs_siz;
		}
	}
	if (bacs_siz) {
		int hal_siz = bacs_siz >> 1;
		res.x = (res.x + hal_siz) / bacs_siz;
		res.y = (res.y + hal_siz) / bacs_siz;
	} else res = coords_t{bl()->x, bl()->y};
	return res;
}

// Bot�̃x�N�^�B
std::vector<ptr<block_if>>& leader_impl::bots() {
	return bots_;
}

// ���S�B
block_list& leader_impl::center() {
	return center_;
}

// �G�����X�^�[�̃}�b�v�B
std::unordered_map<int,ptr<block_if>>& leader_impl::enemies() {
	return enemies_;
}

// Bot��T���B
block_if* // ��������Bot�B������Ȃ�������nullptr�B
leader_impl::find_bot(
	const std::string& nam // ���O�B�����Ȃ烁���o�[�̃C���f�b�N�X�B
) {
	block_if* mem = find_member(nam);
	if (!mem ||
		!dynamic_cast<bot_impl*>(mem)
	) return nullptr;
	return mem;
}

// �����o�[��T���B
block_if* // �������������o�[�B������Ȃ�������nullptr�B
leader_impl::find_member(
	const std::string& nam // ���O�B�����Ȃ烁���o�[�̃C���f�b�N�X�B
) {
	block_if* mem = nullptr;
	int i = parse_index(nam);
	if (i != -1) {
		if (i >= 0 &&
			i < members_.size()
		) mem = members_[i];
	} else {
		int cid = parse_id(nam);
		if (cid) {
			if (cid != INT_MIN) {
				for (block_if* mem2 : members_) {
					if (mem2->char_id() == cid) {
						mem = mem2;
						break;
					}
				}
			}
		} else {
			std::string lc_nam = lowercase(nam);
			for (block_if* mem2 : members_) {
				if (lowercase(mem2->name()) == lc_nam) {
					mem = mem2;
					break;
				}
			}
		}
	}
	return mem;
}

// �O���[�g�����X�^�[�̃��W�X�g���B
ptr<registry_t<int>>& leader_impl::great_mobs() {
	return great_mobs_;
}

// �����A�C�e���̃��W�X�g���B
ptr<registry_t<int>>& leader_impl::ignore_items() {
	return ignore_items_;
}

// �Ō��Bot�����O�C���������`�b�N�B
t_tick& leader_impl::last_heaby_tick() {
	return last_heaby_tick_;
}

// �Ō�Ɏ}��������ID�B
int& leader_impl::last_summoned_id() {
	return last_summoned_id_;
}

// �����o�[�̃x�N�^�B
std::vector<block_if*>& leader_impl::members() {
	return members_;
}

// �����̃��W�X�g���B
ptr<registry_t<int,coords_t>>& leader_impl::memos() {
	return memos_;
}

// ���̏d�����R�}���h�܂ł̃`�b�N���v�Z����B
t_tick leader_impl::next_heaby_tick() {
	t_tick hev_tic = DIFF_TICK(last_heaby_tick() + battle_config.pybot_heaby_cool_time, now);
	if (hev_tic < 0) hev_tic = 0;
	return hev_tic;
}

// �񖳎��A�C�e���̃��W�X�g���B
ptr<registry_t<int>>& leader_impl::not_ignore_items() {
	return not_ignore_items_;
}

// �o�̓o�b�t�@�B
std::stringstream& leader_impl::output_buffer() {
	return output_buffer_;
}

// �`�[���������X�^�[�ɔ������Ȃ����B
bool& leader_impl::passive() {
	return passive_;
}

// ���b�V�����[�h�̓o�^�l�B
ptr<regnum_t<bool>>& leader_impl::rush() {
	return rush_;
}

// �`�[����ۑ�����B
void leader_impl::save_team(
	int tea_num // �`�[���̔ԍ��B
) {
	CS_ENTER;
	auto tea = initialize<team_t>(tea_num);
	for (block_if* mem : members())
		tea->members.push_back(initialize<team_member>(mem->char_id(), mem->name()));
	teams()->register_(tea_num, tea);
}

// ���p�A�C�e���̃��W�X�g���B
ptr<registry_t<int>>& leader_impl::sell_items() {
	return sell_items_;
}

// �o�̓o�b�t�@���玟�̃y�[�W��\������B
void leader_impl::show_next() {
	std::stringstream out;
	for (int cou = 0; cou < PAGE_LINES; ++cou) {
		std::string lin;
		std::getline(output_buffer(), lin);
		if (!output_buffer()) break;
		out << lin << "\n";
	}
	if (output_buffer()) out << "�c������Next�T�u�R�}���h�ŕ\���ł��܂��B\n";
	show_client(fd(), out.str());
}

// SP�������\���B
bool& leader_impl::sp_suppliable() {
	return sp_suppliable_;
}

// �ҋ@���B
bool& leader_impl::stay() {
	return stay_;
}

// �q�Ɋi�[�A�C�e���̃��W�X�g���B
ptr<registry_t<int>>& leader_impl::storage_put_items() {
	return storage_put_items_;
}

// �`�[���̃��W�X�g���B
ptr<registry_t<int,team_t>>& leader_impl::teams() {
	return teams_;
}

// Bot�̃C���f�b�N�X���X�V����B
void leader_impl::update_bot_indices() {
	for (int i = 0; i < bots().size(); ++i) bots()[i]->bot_index() = i;
}

// �����o�[�̃C���f�b�N�X���X�V����B
void leader_impl::update_member_indices() {
	for (int i = 0; i < members().size(); ++i) members()[i]->member_index() = i;
}

// �A�J�E���gID�B
int& member_impl::account_id() {
	return account_id_;
}

// �o�[�T�[�N�������̓o�^�l�B
ptr<regnum_t<int>>& member_impl::berserk_rate() {
	return berserk_rate_;
}

// �����o�[�̃u���b�N���X�g���擾����B
block_list* // �擾�����u���b�N���X�g�B
member_impl::bl() {
	return &sd()->bl;
}

// �����o�[���X�L�����g���邩�𔻒肷��B
bool // ���ʁB
member_impl::can_use_skill(
	e_skill kid, // �X�L��ID�B
	int klv      // �X�L�����x���B
) {
	int8_t old_spi = sd()->spiritball;
	skill_condition req = skill_get_requirement(sd(), kid, klv);
	sd()->spiritball = req.spiritball;
	bool res = !(sc()->option & OPTION_INVISIBLE) &&
		!skill_isNotOk(kid, sd()) &&
		skill_check_condition_castbegin(sd(), kid, klv) &&
		skill_check_condition_castend(sd(), kid, klv, 0);
	sd()->spiritball = old_spi;
	return res;
}

// �����o�[�������o�[�ɃJ�n���g���邩�𔻒肷��B
bool // ���ʁB
member_impl::can_ka(
	block_if* tar_mem // �^�[�Q�b�g�̃����o�[�B
) {
	status_change_entry* spi_sce = sc()->data[SC_SPIRIT];
	return tar_mem == this ||
		(spi_sce &&
			spi_sce->val2 == SL_SOULLINKER
		) || (tar_mem->sd()->class_ & MAPID_UPPERMASK) == MAPID_SOUL_LINKER ||
		tar_mem->char_id() == char_id() ||
		tar_mem->char_id() == sd()->status.partner_id ||
		tar_mem->char_id() == sd()->status.child;
}

// �J�[�g������[�A�C�e���̃��W�X�g���B
ptr<registry_t<int>>& member_impl::cart_auto_get_items() {
	return cart_auto_get_items_;
}

// �L�����N�^�[ID�B
int& member_impl::char_id() {
	return char_id_;
}

// �����o�[�̃X�L�����`�F�b�N����B
int // �ő僌�x���B
member_impl::check_skill(
	e_skill kid // �X�L��ID�B
) {
	int klv = pc_checkskill(sd(), kid);
	int* lim_slv = limit_skills()->find(kid);
	if (lim_slv) klv = std::min(klv, *lim_slv);
	return klv;
}

// ���̃R���{�X�L��ID���擾����B
e_skill // �擾�����X�L��ID�B�R���{��ԂłȂ����0�B
member_impl::combo_skill_id() {
	e_skill kid = e_skill(0);
	status_change_entry* com_ent = sc()->data[SC_COMBO];
	if (com_ent) kid = e_skill(com_ent->val1);
	return kid;
}

// �����o�[�̃f�t�H���g�����|���V�[�l���擾����B
distance_policy_values // �擾���������|���V�[�l�B
member_impl::default_distance_policy_value() {
	return find_map_data(DEFAULT_DISTANCE_POLICY_VALUES, substancial_job());
}

// �����o�[�̃f�t�H���g�ʏ�U���|���V�[�l���擾����B
normal_attack_policy_values // �擾�����ʏ�U���|���V�[�l�B
member_impl::default_normal_attack_policy_value() {
	return find_map_data(DEFAULT_NORMAL_ATTACK_POLICY_VALUES, substancial_job());
}

// �ő勗���̓o�^�l�B
ptr<regnum_t<int>>& member_impl::distance_max() {
	return distance_max_;
}

// �����o�[�̍ő勗���̒l���擾����B
int // �擾�����ő勗���̒l�B
member_impl::distance_max_value() {
	int val = distance_max()->get();
	if (!val) val = battle_config.pybot_around_distance;
	return val;
}

// �����|���V�[�̃��W�X�g���B
ptr<registry_t<int,distance_policy>>& member_impl::distance_policies() {
	return distance_policies_;
}

// ����ꎮ�̃��W�X�g���B
ptr<registry_t<int,equipset_t>>& member_impl::equipsets() {
	return equipsets_;
}

// �\�P�b�g�̋L�q�q�B
int& member_impl::fd() {
	return fd_;
}

// ��ꂽ������T���B
int // ���������C���f�b�N�X�B������Ȃ�������INT_MIN�B
member_impl::find_broken_equip(
	int bas // �T���n�߂�C���f�b�N�X�B
) {
	for (int i = bas; i < MAX_INVENTORY; ++i) {
		item* itm = &sd()->inventory.u.items_inventory[i];
		if (itm->nameid &&
			itm->attribute == 1
		) return i;
	}
	return INT_MIN;
}

// �J�[�g����A�C�e����T���B
int // ���������C���f�b�N�X�B������Ȃ�������INT_MIN�B
member_impl::find_cart(
	const std::string& nam // �A�C�e�����B�����Ȃ�C���f�b�N�X�B
) {
	int i = parse_index(nam);
	if (i != -1) {
		if (i < 0 ||
			i >= MAX_CART ||
			!sd()->cart.u.items_cart[i].nameid
		) i = INT_MIN;
	} else i = find_cart(item_key(nam));
	return i;
}

// �J�[�g����A�C�e����T���B
int // ���������C���f�b�N�X�B������Ȃ�������INT_MIN�B
member_impl::find_cart(
	const item_key& key // �A�C�e���̃L�[�B
) {
	return find_item(&sd()->cart, MAX_CART, key);
}

// �C���x���g������A�C�e����T���B
int // ���������C���f�b�N�X�B������Ȃ�������INT_MIN�B
member_impl::find_inventory(
	const std::string& nam // �A�C�e�����B�����Ȃ�C���f�b�N�X�B
) {
	int i = parse_index(nam);
	if (i != -1) {
		if (i < 0 ||
			i >= MAX_INVENTORY ||
			!sd()->inventory.u.items_inventory[i].nameid
		) i = INT_MIN;
	} else i = find_inventory(item_key(nam));
	return i;
}

// �C���x���g������A�C�e����T���B
int // ���������C���f�b�N�X�B������Ȃ�������INT_MIN�B
member_impl::find_inventory(
	const item_key& key, // �A�C�e���̃L�[�B
	int equ              // �������ʁBINT_MIN�Ȃ�`�F�b�N�Ȃ��B
) {
	return find_item(&sd()->inventory, MAX_INVENTORY, key, sd()->inventory_data, equ);
}

// �D��X�L���̃��W�X�g���B
ptr<registry_t<int,e_skill>>& member_impl::first_skills() {
	return first_skills_;
}

// �����o�[�������邱�Ƃ̂ł��郂���X�^�[�����擾����B
int // �擾���������X�^�[���B
member_impl::get_hold_mobs() {
	return hold_mobs()->get();
}

// �����o�[�̃����X�^�[�̍�Def���擾����B
int // �擾������Def�B
member_impl::get_mob_high_def() {
	int res = mob_high_def()->get();
	if (!res) res = DEFAULT_MOB_HIGH_DEF;
	return res;
}

// �����o�[�̃����X�^�[�̍�DefVit���擾����B
int // �擾������DefVit�B
member_impl::get_mob_high_def_vit() {
	int res = mob_high_def_vit()->get();
	if (!res) res = DEFAULT_MOB_HIGH_DEF_VIT;
	return res;
}

// �����o�[�̃����X�^�[�̍�Flee���擾����B
int // �擾������Flee�B
member_impl::get_mob_high_flee() {
	int res = mob_high_flee()->get();
	if (!res) res = DEFAULT_MOB_HIGH_FLEE;
	return res;
}

// �����o�[�̃����X�^�[�̍�Hit���擾����B
int // �擾������Hit�B
member_impl::get_mob_high_hit() {
	int res = mob_high_hit()->get();
	if (!res) res = DEFAULT_MOB_HIGH_HIT;
	return res;
}

// �����o�[�̃����X�^�[�̍�Mdef���擾����B
int // �擾������Mdef�B
member_impl::get_mob_high_mdef() {
	int res = mob_high_mdef()->get();
	if (!res) res = DEFAULT_MOB_HIGH_MDEF;
	return res;
}

// �͈̓X�L���̔��������ƂȂ郂���X�^�[�����擾����B
int // �擾���������X�^�[���B
member_impl::get_skill_mobs() {
	int cou = skill_mobs()->get();
	if (!cou) cou = DEFAULT_SKILL_MONSTERS;
	return cou;
}

// �|���������Ԃ��擾����B
t_tick // �擾�����|���������ԁB
member_impl::get_skill_tail(
	e_skill kid // �X�L��ID�B
) {
	int* dur = skill_tails()->find(kid);
	return dur ? *dur : 0;
}

// �����o�[��SP�̋�����������SP�����擾����B
int // �擾����SP���B
member_impl::get_supply_sp_rate() {
	int res = supply_sp_rate()->get();
	if (!res) res = DEFAULT_SUPPLY_SP_RATE;
	return res;
}

// �����o�[�̃M���hID���擾����B
int // �擾�����M���hID�B
member_impl::guild_id() {
	return sd()->status.guild_id;
}

// �����邱�Ƃ̂ł��郂���X�^�[���̓o�^�l�B
ptr<regnum_t<int>>& member_impl::hold_mobs() {
	return hold_mobs_;
}

// �z�����N���X�B
ptr<block_if>& member_impl::homun() {
	return homun_;
}

// ������Ӓ肷��B
// ���łɊӒ�ς݂Ȃ牽�����Ȃ��B
// �A�C�e���Ӓ���g�p�\�ł���Ή���������ɊӒ肷��B
// �����A�C�e�����J�[�g�Ɋg�勾������΂��������ĊӒ肷��B
// �A�C�e���Ӓ���g�p�s�A���g�勾���Ȃ���Ή������Ȃ��B
void member_impl::identify_equip(
	item* itm,                // �Ӓ肷�镐��B
	storage_context* inv_con, // �����A�C�e���̕����Bnullptr�Ȃ�K�v�ɉ����č쐬�B
	storage_context* car_con  // �J�[�g�̕����Bnullptr�Ȃ�K�v�ɉ����č쐬�B
) {
	ptr<storage_context> inv_con_ptr, car_con_ptr;
	if (!itm->identify) {
		if (check_skill(MC_IDENTIFY)) itm->identify = 1;
		else {
			if (!inv_con) {
				inv_con_ptr = construct<inventory_context>(sd());
				inv_con = inv_con_ptr.get();
			}
			int mag_inv_ind = inv_con->find(ITEMID_MAGNIFIER);
			if (mag_inv_ind != INT_MIN) {
				inv_con->delete_(mag_inv_ind, 1);
				itm->identify = 1;
			} else {
				if (is_carton() &&
					!car_con
				) {
					car_con_ptr = construct<cart_context>(sd());
					car_con = car_con_ptr.get();
				}
				int mag_car_ind = INT_MIN;
				if (car_con) mag_car_ind = car_con->find(ITEMID_MAGNIFIER);
				if (mag_car_ind != INT_MIN) {
					car_con->delete_(mag_car_ind, 1);
					itm->identify = 1;
				}
			}
		}
	}
}

// �J�[�g�������Ă��邩�𔻒肷��B
bool // ���ʁB
member_impl::is_carton() {
	return pc_iscarton(sd());
}

// �����o�[�����S���𔻒肷��B
bool // ���ʁB
member_impl::is_dead() {
	return pc_isdead(sd());
}

// �����o�[�����G���𔻒f����B
bool member_impl::is_invincible() {
	return sd()->invincible_timer != INVALID_TIMER;
}

// �����o�[�����@�ϐ����𔻒肷��B
bool member_impl::is_magic_immune() {
	return sd()->special_state.no_magic_damage ||
		status_isimmune(bl());
}

// �����o�[���L���X�g���f�������𔻒肷��B
bool member_impl::is_no_castcancel() {
	return sd()->special_state.no_castcancel;
}

// �����o�[���W�F���X�g�[������Ȃ����𔻒肷��B
bool member_impl::is_no_gemstone() {
	return sd()->special_state.no_gemstone;
}

// �����Ă��邩�𔻒肷��B
bool // ���ʁB
member_impl::is_sit() {
	return pc_issit(sd());
}

// �����o�[���Ǎۂɂ��邩�𔻒肷��B
bool // ���ʁB
member_impl::is_wall_side() {
	return this == leader() ||
		no_knockback() ||
		check_wall_side(bl()->m, bl()->x, bl()->y);
}

// �����o�[�̃X�L���𔽕�����B
void member_impl::iterate_skill(
	yield_skill_func yie // �X�L���l���n���h���B
) {
	for (int i = 0; i < MAX_SKILL; ++i) {
		s_skill* sk = &sd()->status.skill[i];
		if (sk->id &&
			!yie(sk)
		) break; 
	}
}

// ���푮���t�^�̃��W�X�g���B
ptr<registry_t<int,e_element>>& member_impl::kew_elements() {
	return kew_elements_;
}

// ���[�_�[�B
block_if*& member_impl::leader() {
	return leader_;
}

// �����X�L���̃��W�X�g���B
ptr<registry_t<e_skill,int>>& member_impl::limit_skills() {
	return limit_skills_;
}

// �����o�[������ꎮ�����[�h����B
void member_impl::load_equipset(
	int mid,       // �����X�^�[ID�B
	equip_pos* equ // �����ςݕ���
) {
	equip_pos dum_equ = equip_pos(0);
	if (!equ) equ = &dum_equ;
	equipset_t* es = equipsets()->find(mid);
	if (es) {
		for (auto es_itm : es->items) {
			if (!(es_itm->equip & *equ)) {
				int inv_ind = find_inventory(*es_itm->key, es_itm->equip);
				if (inv_ind == INT_MIN) {
					inv_ind = find_inventory(*es_itm->key, 0);
					if (inv_ind == INT_MIN) {
						if (dynamic_cast<bot_impl*>(this))
							request_items().insert(es_itm->key->nameid);
						continue;
					}
					if (!pc_equipitem(sd(), inv_ind, es_itm->equip)) continue;
				}
				*equ = equip_pos(*equ | es_itm->equip);
			}
		}
	}
}

// �����o�[�����t�X�L�������[�h����B
void member_impl::load_play_skill(int mid, e_skill* kid) {
	if (!*kid) {
		auto pla_sk = play_skills()->find(mid);
		if (pla_sk) *kid = pla_sk->skill_id;
	}
}

// �����o�[���|���V�[�����[�h����B
void member_impl::load_policy(
	int mid,                                     // �����X�^�[ID�B
	distance_policy_values* dis_pol_val,         // �����|���V�[�B
	normal_attack_policy_values* nor_att_pol_val // �ʏ�U���|���V�[�B
) {
	if (*dis_pol_val == DPV_PENDING) {
		auto dis_pol = distance_policies()->find(mid);
		if (dis_pol) *dis_pol_val = dis_pol->value;
	}
	if (*nor_att_pol_val == NAPV_PENDING) {
		auto nor_att_pol = normal_attack_policies()->find(mid);
		if (nor_att_pol) *nor_att_pol_val = nor_att_pol->value;
	}
}

// �h���b�v�A�C�e�����E�����̓o�^�l�B
ptr<regnum_t<loot_modes>>& member_impl::loot() {
	return loot_;
}

// ���@�͑�����Ԃ��𔻒肷��B
bool // ���ʁB
member_impl::magicpower_is_active() {
	status_change_entry* mag_pow_ent = sc()->data[SC_MAGICPOWER];
	return mag_pow_ent &&
		!mag_pow_ent->val4;
}

// �����o�[�̃C���f�b�N�X�B
int& member_impl::member_index() {
	return member_index_;
}

// �����X�^�[�̍�Def�̓o�^�l�B
ptr<regnum_t<int>>& member_impl::mob_high_def() {
	return mob_high_def_;
}

// �����X�^�[�̍�DefVit�̓o�^�l�B
ptr<regnum_t<int>>& member_impl::mob_high_def_vit() {
	return mob_high_def_vit_;
}

// �����X�^�[�̍�Flee�̓o�^�l�B
ptr<regnum_t<int>>& member_impl::mob_high_flee() {
	return mob_high_flee_;
}

// �����X�^�[�̍�Hit�̓o�^�l�B
ptr<regnum_t<int>>& member_impl::mob_high_hit() {
	return mob_high_hit_;
}

// �����X�^�[�̍�Mdef�̓o�^�l�B
ptr<regnum_t<int>>& member_impl::mob_high_mdef() {
	return mob_high_mdef_;
}

// �����o�[�̖��O���擾����B
std::string // �擾�������O�B
member_impl::name() {
	return name_;
}

// �����o�[���m�b�N�o�b�N�ϐ���Ԃ��𔻒肷��B
bool // ���ʁB
member_impl::no_knockback() {
	return sd()->special_state.no_knockback;
}

// �ʏ�U���|���V�[�̃��W�X�g���B
ptr<registry_t<int,normal_attack_policy>>& member_impl::normal_attack_policies() {
	return normal_attack_policies_;
}

// �����o�[�̃p�[�e�B�[ID���擾����B
int // �擾�����p�[�e�B�[ID�B
member_impl::party_id() {
	return sd()->status.party_id;
}

// �y�b�g�B
ptr<block_if>& member_impl::pet() {
	return pet_;
}

// ���t�X�L���̃��W�X�g���B
ptr<registry_t<int,play_skill>>& member_impl::play_skills() {
	return play_skills_;
}

// HP�񕜃A�C�e���̃��W�X�g���B
ptr<registry_t<int,int>>& member_impl::recover_hp_items() {
	return recover_hp_items_;
}

// SP�񕜃A�C�e���̃��W�X�g���B
ptr<registry_t<int,int>>& member_impl::recover_sp_items() {
	return recover_sp_items_;
}

// ���ۃX�L���̃��W�X�g���B
ptr<registry_t<e_skill>>& member_impl::reject_skills() {
	return reject_skills_;
}

// �v���A�C�e���̃Z�b�g�B
std::unordered_set<int>& member_impl::request_items() {
	return request_items_;
}

// ���S�ɉr���ł��鎞�Ԃ̓o�^�l�B
ptr<regnum_t<int>>& member_impl::safe_cast_time() {
	return safe_cast_time_;
}

// �Z�b�V�����f�[�^�B
map_session_data*& member_impl::sd() {
	return sd_;
}

// SP�̋�����������SP���̓o�^�l�B
ptr<regnum_t<int>>& member_impl::supply_sp_rate() {
	return supply_sp_rate_;
}

// �����o�[������B
void member_impl::sit() {
	pc_setsit(sd());
	skill_sit(sd(), 1);
	clif_sitting(bl());
	act_end();
}

// �����o�[�̃X�L�����擾����B
s_skill* // �擾�����X�L���B�Ȃ����nullptr�B
member_impl::skill(
	e_skill kid
) {
	int kind = skill_get_index(kid);
	if (kind >= 0) return &sd()->status.skill[kind];
	return nullptr;
}

// �X�L�����������X�^�[�̃��W�X�g���B
ptr<registry_t<int>>& member_impl::skill_ignore_mobs() {
	return skill_ignore_mobs_;
}

// �͈͖��@�X�L���̔��������X�^�[���̓o�^�l�B
ptr<regnum_t<int>>& member_impl::skill_mobs() {
	return skill_mobs_;
}

// �����o�[�̃X�L���|�C���g���擾����B
int // �擾�����X�L���|�C���g�B
member_impl::skill_point() {
	return sd()->status.skill_point;
}

// �|���������Ԃ̃��W�X�g���B
ptr<registry_t<e_skill,int>>& member_impl::skill_tails() {
	return skill_tails_;
}

// �����o�[�̃X�L�����グ��B
void member_impl::skill_up(
	e_skill kid // �X�L��ID�B
) {
	pc_skillup(sd(), kid);
}

// �����o�[�����B
void member_impl::stand() {
	pc_setstand(sd(), false);
	skill_sit(sd(), 0);
	clif_standing(bl());
	act_end();
}

// �q�ɕ�[�A�C�e���̃��W�X�g���B
ptr<registry_t<int,int>>& member_impl::storage_get_items() {
	return storage_get_items_;
}

// �����I�ȐE�Ƃ��擾����B
// �]��1���E��1���E�ɕϊ������B
e_job // �擾�����E�ƁB
member_impl::substancial_job() {
	int job = sd()->status.class_;
	if (job >= JOB_NOVICE_HIGH &&
		job <= JOB_THIEF_HIGH
	) job -= 4001;
	return e_job(job);
}

// �����o�[�̕���U���̑������擾����B
e_element // �擾���������B
member_impl::weapon_attack_element() {
	e_element ele = e_element(status_calc_attack_element(bl(), sc(), status_get_attack_element(bl())));
	if (ele == ELE_NEUTRAL &&
		sd()->bonus.arrow_ele
	) ele = e_element(sd()->bonus.arrow_ele);
	return ele;
}

// �����X�^�[�̃u���b�N���X�g���擾����B
block_list* // �擾�����u���b�N���X�g�B
mob_impl::bl() {
	return &md()->bl;
}

// �����X�^�[�Ƀv���{�b�N���g���邩�𔻒肷��B
bool // ���ʁB
mob_impl::can_be_provoke() {
	return !has_status_immune() &&
		!is_hiding() &&
		!is_undead();
}

// �����X�^�[���U���\���[�h�������𔻒肷��B
bool // ���ʁB
mob_impl::has_can_attack() {
	return status_has_mode(&md()->status, MD_CANATTACK);
}

// �����X�^�[���ړ��\���[�h�������𔻒肷��B
bool // ���ʁB
mob_impl::has_can_move() {
	return status_has_mode(&md()->status, MD_CANMOVE);
}

// �����X�^�[���n�C�f�B���O�����j�邩�𔻒肷��B
bool // ���ʁB
mob_impl::has_detector() {
	return status_has_mode(&md()->status, MD_DETECTOR);
}

// �����X�^�[���m�b�N�o�b�N�ϐ����[�h�������𔻒肷��B
bool // ���ʁB
mob_impl::has_knockback_immune() {
	return status_has_mode(&md()->status, MD_KNOCKBACK_IMMUNE);
}

// �����X�^�[��MVP���[�h�������𔻒肷��B
bool // ���ʁB
mob_impl::has_mvp() {
	return status_has_mode(&md()->status, MD_MVP);
}

// �����X�^�[����Ԉُ�ϐ����[�h�������𔻒肷��B
bool // ���ʁB
mob_impl::has_status_immune() {
	return status_has_mode(&md()->status, MD_STATUS_IMMUNE);
}

// �����X�^�[���o�[�T�N��Ԃ��𔻒肷��B
bool // ���ʁB
mob_impl::is_berserk() {
	return md()->state.skillstate == MSS_BERSERK;
}

// �����X�^�[���{�X���𔻒肷��B
bool // ���ʁB
mob_impl::is_boss() {
	return status_get_class_(bl()) == CLASS_BOSS;
}

// �����\���𔻒肷��B
bool // ���ʁB
mob_impl::is_freezable() {
	return !has_status_immune() &&
		!is_undead() &&
		!sc()->opt1;
}

// �t���[���^�����X�^�[���𔻒肷��B
bool // ���ʁB
mob_impl::is_flora() {
	return pybot::mob_is_pure_flora(md()) ||
		((sc()->data[SC_ANKLE] ||
				sc()->data[SC_SPIDERWEB]
			) && has_can_attack() &&
			is_short_range_attacker()
		);
}

// �����X�^�[���������𔻒肷��B
bool // ���ʁB
mob_impl::is_great(
	block_if* lea // ���[�_�[�B
) {
	return has_mvp() ||
		lea->great_mobs()->find(md()->mob_id);
}

// �����X�^�[�����@�ϐ����𔻒肷��B
bool // ���ʁB
mob_impl::is_magic_immune() {
	return status_isimmune(bl());
}

// �����X�^�[���������ꂽ���𔻒肷��B
bool // ���ʁB
mob_impl::is_summoned() {
	return md()->master_id;
}

// �����X�^�[���A���f�b�h���𔻒肷��B
bool // ���ʁB
mob_impl::is_undead() {
	return battle_check_undead(race(), element());
}

// �����X�^�[�f�[�^�B
mob_data*& mob_impl::md() {
	return md_;
}

// �����X�^�[�̖��O���擾����B
std::string // �擾�������O�B
mob_impl::name() {
	return md()->db->jname;
}

// �y�b�g�̃u���b�N���X�g���擾����B
block_list* // �擾�����u���b�N���X�g�B
pet_impl::bl() {
	return &pd()->bl;
}

// �y�b�g�����݂��邩�𔻒肷��B
bool // ���ʁB
pet_impl::exists() {
	return master()->sd()->status.pet_id &&
		pd();
}

// �y�b�g���A�N�e�B�u���𔻒肷��B
bool // ���ʁB
pet_impl::is_active() {
	return exists() &&
		pd()->pet.intimate > 0 &&
		!pd()->pet.incubate;
}

// �y�b�g���O���擾����B
std::string // �擾�������O�B
pet_impl::name() {
	return pd()->pet.name;
}

// �y�b�g�f�[�^���擾����B
pet_data* // �擾�����y�b�g�f�[�^�B
pet_impl::pd() {
	return master()->sd()->pd;
}

// �r���I���n���h���B
ai_t::done_func& skill_user_impl::cast_end_func() {
	return cast_end_func_;
}

// �T�[�o�[�ɂ�����2�̃u���b�N���X�g�������͈͓����𔻒肷��B
bool // ���ʁB
server_impl::check_range_bl(
	block_list* bl0, // �u���b�N���X�g0�B
	block_list* bl1, // �u���b�N���X�g1�B
	int dis          // �����B
) {
	return check_distance_bl(bl0, bl1, dis);
}

// �T�[�o�[�ɂ����ău���b�N���X�g�ƍ��W�������͈͓����𔻒肷��B
bool // ���ʁB
server_impl::check_range_blxy(
	block_list* bl_, // �u���b�N���X�g�B
	int x,           // X���W�B
	int y,           // Y���W�B
	int dis          // �����B
) {
	return check_distance_blxy(bl_, x, y, dis);
}

// �T�[�o�[�ɂ�����2�̍��W�������͈͓����𔻒肷��B
bool // ���ʁB
server_impl::check_range_xy(
	int x0, // X0���W�B
	int y0, // Y0���W�B
	int x1, // X1���W�B
	int y1, // Y1���W�B
	int dis // �����B
) {
	return check_distance_xy(x0, y0, x1, y1, dis);
}

// �Ō�̃X�L���g�p����w�肵�����Ԃ��o�߂��������`�F�b�N����B
bool // ���ʁB
skill_target_impl::check_skill_used_tick(
	e_skill kid,   // �X�L��ID�B
	t_tick ela_tic // �o�߃`�b�N�B
) {
	return DIFF_TICK(now, skill_used_ticks()[kid]) >= ela_tic;
}

// �X�L���g�p�`�b�N�̃}�b�v�B
std::unordered_map<e_skill,t_tick>& skill_target_impl::skill_used_ticks() {
	return skill_used_ticks_;
}

// �R�C�����W�߂�B
bool // ���łɏW�܂��Ă��邩�B
skill_user_impl::collect_coins(
	int cou // �K�v�ȃR�C���̖����B
) {
	bool res = sd()->spiritball >= cou;
	if (!res) {
		int gli_lv = check_skill(GS_GLITTERING);
		if (gli_lv) use_skill_self(GS_GLITTERING, gli_lv);
	}
	return res;
}

// �C�e���W�߂�B
bool // ���łɏW�܂��Ă��邩�B
skill_user_impl::collect_spirits(
	int cou // �K�v�ȋC�e�̌��B
) {
	bool res = sd()->spiritball >= cou;
	if (!res) {
		int cs_lv = check_skill(MO_CALLSPIRITS);
		int sc_lv = check_skill(CH_SOULCOLLECT);
		if ((!cs_lv ||
				sd()->spiritball <= 3
			) && sc_lv
		) use_skill_self(CH_SOULCOLLECT, sc_lv);
		if (cs_lv >= sd()->spiritball + cou)
			use_skill_self(MO_CALLSPIRITS, cs_lv);
	}
	return res;
}

// �X�L���̎˒����擾����B
int // �擾�����˒��B
skill_user_impl::skill_range(
	e_skill kid, // �X�L��ID�B
	int klv      // �X�L�����x���B
) {
	return skill_get_range2(bl(), kid, klv, true);
}

// �A���R�[�����g���B
void skill_user_impl::use_encore(
	e_skill dan_id // ���t�X�L��ID�B
) {
	int enc_lv = check_skill(BD_ENCORE);
	if (enc_lv &&
		sd()->skill_id_dance == dan_id
	) use_skill_self(BD_ENCORE, enc_lv);
}

// ���@�͑������g���B
bool // ���łɖ��@�͑�����Ԃł��邩�A�܂��͎g�p�s���B
skill_user_impl::use_magicpower() {
	bool res = false;
	uint16 mag_pow_lv = check_skill(HW_MAGICPOWER);
	if (mag_pow_lv) {
		if (magicpower_is_active()) res = true;
		else use_skill_self(HW_MAGICPOWER, mag_pow_lv);
	} else res = true;
	return res;
}

// �u���b�N���X�g�ɃX�L�����g���B
void skill_user_impl::use_skill_bl(
	e_skill kid,                // �X�L��ID�B
	int klv,                    // �X�L�����x���B
	block_list* bl_,            // �u���b�N���X�g�B
	bool tur_end,               // �^�[���I�����B
	ai_t::done_func cas_end_fun // �r�������n���h���B
) {
	if (dynamic_cast<bot_impl*>(this) &&
		is_sit()
	) stand();
	auto use = [this, kid, klv, cas_end_fun] (block_list* bl_) {
		if (unit_skilluse_id(bl(), bl_->id, kid, klv)) {
			if (dynamic_cast<member_impl*>(this))
				pc_delinvincibletimer(sd());
			cast_end_func() = cas_end_fun;
			skill_used_ticks()[kid] = now;
		}
	};
	if (walk_bl(bl_, skill_range(kid, klv))) {
		int bid = bl_->id;
		walk_end_func() = [this, kid, klv, use, bid] (ai_t* ai, void* fun) {
			block_list* bl_ = map_id2bl(bid);
			if (bl_ &&
				can_reach_bl(bl_) &&
				can_move()
			) {
				if (walk_bl(bl_, skill_range(kid, klv)))
					walk_end_func() = *(ai_t::done_func*)(fun);
				else use(bl_);
			}
		};
	} else use(bl_);
	if (tur_end) throw turn_end_exception();
}

// �u���b�N�ɃX�L�����g���B
void skill_user_impl::use_skill_block(
	e_skill kid,                // �X�L��ID�B
	int klv,                    // �X�L�����x���B
	block_if* blo,              // �u���b�N�B
	bool tur_end,               // �^�[���I�����B
	ai_t::done_func cas_end_fun // �r�������n���h���B
) {
	if (dynamic_cast<bot_impl*>(this) &&
		is_sit()
	) stand();
	auto use = [this, kid, klv, cas_end_fun] (block_if* blo) {
		if (unit_skilluse_id(bl(), blo->bl()->id, kid, klv)) {
			if (dynamic_cast<member_impl*>(this))
				pc_delinvincibletimer(sd());
			cast_end_func() = cas_end_fun;
			blo->skill_used_ticks()[kid] = now;
			if (kid == NJ_KASUMIKIRI) blo->skill_used_ticks()[TF_HIDING] = now;
		}
	};
	if (walk_bl(blo->bl(), skill_range(kid, klv))) {
		int blo_bid = blo->bl()->id;
		walk_end_func() = [this, kid, klv, use, blo_bid] (ai_t* ai, void* fun) {
			block_if* blo = ai->find_block<skill_target_impl>(blo_bid);
			if (blo &&
				can_reach_block(blo) &&
				can_move()
			) {
				if (walk_bl(blo->bl(), skill_range(kid, klv)))
					walk_end_func() = *(ai_t::done_func*)(fun);
				else use(blo);
			}
		};
	} else use(blo);
	if (tur_end) throw turn_end_exception();
}

// �����ɃX�L�����g���B
void skill_user_impl::use_skill_self(
	e_skill kid,                // �X�L��ID�B
	int klv,                    // �X�L�����x���B
	bool tur_end,               // �^�[���I�����B
	ai_t::done_func cas_end_fun // �r�������n���h���B
) {
	if (dynamic_cast<bot_impl*>(this) &&
		is_sit()
	) stand();
	if (unit_skilluse_id(bl(), bl()->id, kid, klv)) {
		if (dynamic_cast<member_impl*>(this))
			pc_delinvincibletimer(sd());
		cast_end_func() = cas_end_fun;
		skill_used_ticks()[kid] = now;
		if (skill_get_inf2(kid) & INF2_SONG_DANCE ||
			skill_get_inf2(kid) & INF2_ENSEMBLE_SKILL
		) skill_used_ticks()[BD_ENCORE] = now;
		if (kid == BA_FROSTJOKER) {
			std::stringstream out;
			int mes_ind = rnd() % BA_FROSTJOKER_MESSAGES.size();
			out << name() << " : " << BA_FROSTJOKER_MESSAGES[mes_ind];
			clif_GlobalMessage(bl(), out.str().c_str(), AREA_CHAT_WOC);
		}
		if (tur_end) throw turn_end_exception();
	}
}

// ���W�ɃX�L�����g���B
void skill_user_impl::use_skill_xy(
	e_skill kid,                // �X�L��ID�B
	int klv,                    // �X�L�����x���B
	int x,                      // X���W�B
	int y,                      // Y���W�B
	bool tur_end,               // �^�[���I�����B
	ai_t::done_func cas_end_fun // �r�������n���h���B
) {
	if (dynamic_cast<bot_impl*>(this) &&
		is_sit()
	) stand();
	auto use = [this, x, y, kid, klv, cas_end_fun] () {
		if (unit_skilluse_pos(bl(), x, y, kid, klv)) {
			if (dynamic_cast<member_impl*>(this))
				pc_delinvincibletimer(sd());
			cast_end_func() = cas_end_fun;
			skill_used_ticks()[kid] = now;
		}
	};
	if (walk_xy(x, y, skill_range(kid, klv))) {
		walk_end_func() = [this, kid, klv, use, x, y] (ai_t* ai, void* fun) {
			if (can_reach_xy(x, y) &&
				can_move()
			) {
				if (walk_xy(x, y, skill_range(kid, klv)))
					walk_end_func() = *(ai_t::done_func*)(fun);
				else use();
			}
		};
	} else use();
	if (tur_end) throw turn_end_exception();
}

// ��l�̃M���hID���擾����B
int // �擾�����M���hID�B
slave_impl::guild_id() {
	return master()->sd()->status.guild_id;
}

// ��l�̃��[�_�[�B
block_if*& slave_impl::leader() {
	return master()->leader();
}

// ��l�B
block_if*& slave_impl::master() {
	return master_;
}

// ��l�̃����o�[�C���f�b�N�X�B
int& slave_impl::member_index() {
	return master()->member_index();
}

// ��l�̃p�[�e�B�[ID���擾����B
int // �擾�����p�[�e�B�[ID�B
slave_impl::party_id() {
	return master()->sd()->status.party_id;
}

// �����o�[���\�z����B
member_t::member_t(
	map_session_data* sd_, // �Z�b�V�����f�[�^�B
	block_if* lea          // ���[�_�[�B
) {
	sd() = sd_;
	fd() = sd()->fd;
	account_id() = sd()->status.account_id;
	char_id() = sd()->status.char_id;
	leader() = lea;
	berserk_rate() = construct<regnum_t<int>>(sd(), "pybot_berserk_rate");
	distance_max() = construct<regnum_t<int>>(sd(), "pybot_distance_max");
	hold_mobs() = construct<regnum_t<int>>(sd(), "pybot_hold_mobs");
	loot() = construct<regnum_t<loot_modes>>(sd(), "pybot_loot");
	mob_high_def() = construct<regnum_t<int>>(sd(), "pybot_mob_high_def");
	mob_high_def_vit() = construct<regnum_t<int>>(sd(), "pybot_mob_high_def_vit");
	mob_high_flee() = construct<regnum_t<int>>(sd(), "pybot_mob_high_flee");
	mob_high_hit() = construct<regnum_t<int>>(sd(), "pybot_mob_high_hit");
	mob_high_mdef() = construct<regnum_t<int>>(sd(), "pybot_mob_high_mdef");
	name_ = std::string(sd()->status.name);
	safe_cast_time() = construct<regnum_t<int>>(sd(), "pybot_safe_cast_time");
	skill_mobs() = construct<regnum_t<int>>(sd(), "pybot_skill_mobs");
	supply_sp_rate() = construct<regnum_t<int>>(sd(), "pybot_supply_sp_rate");
	homun() = construct<homun_t>(this);
	pet() = construct<pet_t>(this);
	cart_auto_get_items() = construct<registry_t<int>>(
		load_cart_auto_get_item_func(char_id()),
		insert_cart_auto_get_item_func(char_id()),
		delete_cart_auto_get_item_func(char_id()),
		clear_cart_auto_get_item_func(char_id())
	);
	distance_policies() = construct<registry_t<int,distance_policy>>(
		load_distance_policy_func(char_id()),
		insert_distance_policy_func(char_id()),
		update_distance_policy_func(char_id()),
		delete_distance_policy_func(char_id()),
		clear_distance_policy_func(char_id())
	);
	equipsets() = construct<registry_t<int,equipset_t>>(
		load_equipset_func(char_id()),
		insert_equipset_func(char_id()),
		update_equipset_func(char_id()),
		delete_equipset_func(char_id()),
		clear_equipset_func(char_id())
	);
	first_skills() = construct<registry_t<int,e_skill>>(
		load_first_skill_func(char_id()),
		insert_first_skill_func(char_id()),
		update_first_skill_func(char_id()),
		delete_first_skill_func(char_id()),
		clear_first_skill_func(char_id())
	);
	kew_elements() = construct<registry_t<int,e_element>>(
		load_kew_element_func(char_id()),
		insert_kew_element_func(char_id()),
		update_kew_element_func(char_id()),
		delete_kew_element_func(char_id()),
		clear_kew_element_func(char_id())
	);
	limit_skills() = construct<registry_t<e_skill,int>>(
		load_limit_skill_func(char_id()),
		insert_limit_skill_func(char_id()),
		update_limit_skill_func(char_id()),
		delete_limit_skill_func(char_id()),
		clear_limit_skill_func(char_id())
	);
	normal_attack_policies() = construct<registry_t<int,normal_attack_policy>>(
		load_normal_attack_policy_func(char_id()),
		insert_normal_attack_policy_func(char_id()),
		update_normal_attack_policy_func(char_id()),
		delete_normal_attack_policy_func(char_id()),
		clear_normal_attack_policy_func(char_id())
	);
	play_skills() = construct<registry_t<int,play_skill>>(
		load_play_skill_func(char_id()),
		insert_play_skill_func(char_id()),
		update_play_skill_func(char_id()),
		delete_play_skill_func(char_id()),
		clear_play_skill_func(char_id())
	);
	skill_ignore_mobs() = construct<registry_t<int>>(
		load_skill_ignore_mob_func(char_id()),
		insert_skill_ignore_mob_func(char_id()),
		delete_skill_ignore_mob_func(char_id()),
		clear_skill_ignore_mob_func(char_id())
	);
	skill_tails() = construct<registry_t<e_skill,int>>(
		load_skill_tail_func(char_id()),
		insert_skill_tail_func(char_id()),
		update_skill_tail_func(char_id()),
		delete_skill_tail_func(char_id()),
		clear_skill_tail_func(char_id())
	);
	recover_hp_items() = construct<registry_t<int,int>>(
		load_recover_hp_item_func(char_id()),
		insert_recover_hp_item_func(char_id()),
		update_recover_hp_item_func(char_id()),
		delete_recover_hp_item_func(char_id()),
		clear_recover_hp_item_func(char_id())
	);
	recover_sp_items() = construct<registry_t<int,int>>(
		load_recover_sp_item_func(char_id()),
		insert_recover_sp_item_func(char_id()),
		update_recover_sp_item_func(char_id()),
		delete_recover_sp_item_func(char_id()),
		clear_recover_sp_item_func(char_id())
	);
	reject_skills() = construct<registry_t<e_skill>>(
		load_reject_skill_func(char_id()),
		insert_reject_skill_func(char_id()),
		delete_reject_skill_func(char_id()),
		clear_reject_skill_func(char_id())
	);
	storage_get_items() = construct<registry_t<int,int>>(
		load_storage_get_item_func(char_id()),
		insert_storage_get_item_func(char_id()),
		update_storage_get_item_func(char_id()),
		delete_storage_get_item_func(char_id()),
		clear_storage_get_item_func(char_id())
	);
}

// Bot���\�z����B
bot_t::bot_t(
	map_session_data* sd_, // �Z�b�V�����f�[�^�B
	block_if* lea          // ���[�_�[�B
) : member_t(sd_, lea) {
	last_emotion_tick() = 0;
	last_reloaded_equipset_tick() = 0;
	all_bots[char_id()] = this;
	show_info(print(
		"Bot '" CL_WHITE, name(), CL_RESET "' logged in. "
		"(AID/CID: '" CL_WHITE, account_id(), "/", char_id(), CL_RESET "',"
		" Group '" CL_WHITE, sd()->group_id, CL_RESET "'"
		")."
	));
	clif_parse_LoadEndAck(sd_->fd, sd_);
}

// Bot��j������B
bot_t::~bot_t() {
	CS_ENTER;
	if (session[fd()] &&
		session[fd()]->session_data == sd()
	) {
		show_info(print("Bot '" CL_WHITE , name(), CL_RESET "' logged off."));
		map_quit(sd());
		do_close(fd());
	}
	all_bots.erase(char_id());
}

// �z�����N���X���\�z����B
homun_t::homun_t(
	block_if* mas // ��l�B
) {
	master() = mas;
}

// ���[�_�[���\�z����B
leader_t::leader_t(
	map_session_data* sd_ // �Z�b�V�����f�[�^�B
) : member_t(sd_, this) {
	center() = sd_->bl;
	attack_target() = 0;
	last_heaby_tick() = 0;
	last_summoned_id() = 0;
	passive() = false;
	stay() = false;
	rush() = construct<regnum_t<bool>>(sd(), "pybot_rush");
	great_mobs() = construct<registry_t<int>>(
		load_great_mob_func(char_id()),
		insert_great_mob_func(char_id()),
		delete_great_mob_func(char_id()),
		clear_great_mob_func(char_id())
	);
	ignore_items() = construct<registry_t<int>>(
		load_ignore_item_func(char_id()),
		insert_ignore_item_func(char_id()),
		delete_ignore_item_func(char_id()),
		clear_ignore_item_func(char_id())
	);
	memos() = construct<registry_t<int,coords_t>>(
		load_memo_func(char_id()),
		insert_memo_func(char_id()),
		update_memo_func(char_id()),
		delete_memo_func(char_id()),
		clear_memo_func(char_id())
	);
	not_ignore_items() = construct<registry_t<int>>(
		load_not_ignore_item_func(char_id()),
		insert_not_ignore_item_func(char_id()),
		delete_not_ignore_item_func(char_id()),
		clear_not_ignore_item_func(char_id())
	);
	sell_items() = construct<registry_t<int>>(
		load_sell_item_func(char_id()),
		insert_sell_item_func(char_id()),
		delete_sell_item_func(char_id()),
		clear_sell_item_func(char_id())
	);
	storage_put_items() = construct<registry_t<int>>(
		load_storage_put_item_func(char_id()),
		insert_storage_put_item_func(char_id()),
		delete_storage_put_item_func(char_id()),
		clear_storage_put_item_func(char_id())
	);
	teams() = construct<registry_t<int,team_t>>(
		load_team_func(char_id()),
		insert_team_func(char_id()),
		update_team_func(char_id()),
		delete_team_func(char_id()),
		clear_team_func(char_id())
	);
	members().push_back(this);
	update_member_indices();
}

// ���[�_�[��j������B
leader_t::~leader_t() {
	CS_ENTER;
	if (!bots().empty()) save_team(0);
	bots().clear();
}

// �����X�^�[���\�z����B
mob_t::mob_t(
	mob_data* md_ // �����X�^�[�f�[�^�B
) {
	md() = md_;
}

// �y�b�g���\�z����B
pet_t::pet_t(
	block_if* mas // ��l�B
) {
	master() = mas;
}

// �G�����X�^�[���\�z����B
enemy_t::enemy_t(
	mob_data* md_ // �����X�^�[�f�[�^�B
) : mob_t(md_) {}

}
