// [GonBee]
// �p�[�e�B�[BOT�@�\��AI�ɂ�����A�C�e���g�p�n���h�����`����B

#include "pybot_internal.hpp"

namespace pybot {

// -----------------------------------------------------------------------------
// AI�̃A�C�e���g�p�n���h���̒�`
	
// �L���r�A�p���P�[�L���g���B
AI_ITEM_USE_FUNC(CAVIAR_PANCAKE) {
	if (bot->sc()->data[SC_SILENCE] ||
		bot->sc()->data[SC_BLIND] ||
		bot->sc()->data[SC_CURSE] ||
		bot->sc()->data[SC_HALLUCINATION] ||
		bot->sc()->data[SC_BLEEDING]
	) bot->use_item(itm_ind);
}

// �Z�k�T���}�C���W���[�X���g���B
AI_ITEM_USE_FUNC(ENRICH_CELERMINE_JUICE) {
	if (bot->battle_mode() != BM_NONE &&
		bot->normal_attack_policy_value() == NAPV_CONTINUOUS &&
		!bot->sc()->data[SC_EXTRACT_SALAMINE_JUICE]
	) bot->use_item(itm_ind);
}

// �΃n�[�u���g���B
AI_ITEM_USE_FUNC(GREEN_HERB) {
	if (bot->sc()->data[SC_POISON] &&
		!skill_unit_exists_block(bot, skill_unit_key_map{SKILL_UNIT_KEY(AS_VENOMDUST, BL_MOB)})
	) bot->use_item(itm_ind);
}

// �΃|�[�V�������g���B
AI_ITEM_USE_FUNC(GREEN_POTION) {
	if (bot->sc()->data[SC_SILENCE] ||
		bot->sc()->data[SC_BLIND] ||
		bot->sc()->data[SC_HALLUCINATION]
	) bot->use_item(itm_ind);
}

// �������g���B
AI_ITEM_USE_FUNC(HOLY_WATER) {
	if (bot->sc()->data[SC_CURSE] ||
		bot->sc()->data[SC_CHANGEUNDEAD]
	) bot->use_item(itm_ind);
}

// �C�O�h���V���̗t���g���B
AI_ITEM_USE_FUNC(LEAF_OF_YGGDRASIL) {
	if (battler->can_act()) {
		block_if* mem = pybot::find_if(ALL_RANGE(members), [this] (block_if* mem) -> bool {
			return bot->can_reach_block(mem) &&
				mem->is_dead() &&
				!mem->reject_skills()->find(ALL_RESURRECTION);
		});
		if (mem) {
			try {bot->use_item(itm_ind);}
			catch (const item_used_exception&) {
				bot->use_skill_block(ALL_RESURRECTION, 1, mem);
			}
		}
	}
}

// ���\����g���B
AI_ITEM_USE_FUNC(PANACEA) {
	if (bot->sc()->data[SC_SILENCE] ||
		bot->sc()->data[SC_BLIND] ||
		bot->sc()->data[SC_CURSE] ||
		bot->sc()->data[SC_HALLUCINATION]
	) bot->use_item(itm_ind);
}

// �Ŗ�̕r���g���B
AI_ITEM_USE_FUNC(POISON_BOTTLE) {
	if (bot->sd()->status.class_ == JOB_ASSASSIN_CROSS &&
		bot->battle_mode() != BM_NONE &&
		bot->normal_attack_policy_value() == NAPV_CONTINUOUS &&
		!bot->sc()->data[SC_ASPDPOTION0] &&
		!bot->sc()->data[SC_ASPDPOTION1] &&
		!bot->sc()->data[SC_ASPDPOTION2] &&
		!bot->sc()->data[SC_ASPDPOTION3]
	) bot->use_item(itm_ind);
}

// ��/�e�̃R���e�i���g���֐������B
ai_t::item_use_func // ������֐��B
AI_ITEM_USE_DEF(ammo_container)(
	int amm_id // ��/�e�̃A�C�e��ID�B
) {
	return [amm_id] (ai_t* ai, int itm_ind) {
		if (KEY_EXISTS(ai->bot->request_items(), amm_id)) {
			try {ai->bot->use_item(itm_ind);}
			catch (const item_used_exception& exc) {
				ai->bot->request_items().erase(amm_id);
				pc_equipitem(
					ai->bot->sd(),
					ai->bot->find_inventory(item_key(amm_id)),
					EQP_AMMO
				);
				throw exc;
			}
		}
	};
}

// ���x�����|�[�V�������g���֐������B
ai_t::item_use_func // ������֐��B
AI_ITEM_USE_DEF(aspd_potion)() {
	return [] (ai_t* ai, int itm_ind) {
		if (ai->bot->battle_mode() != BM_NONE &&
			ai->bot->normal_attack_policy_value() == NAPV_CONTINUOUS &&
			!ai->bot->sc()->data[SC_ASPDPOTION0] &&
			!ai->bot->sc()->data[SC_ASPDPOTION1] &&
			!ai->bot->sc()->data[SC_ASPDPOTION2] &&
			!ai->bot->sc()->data[SC_ASPDPOTION3]
		) ai->bot->use_item(itm_ind);
	};
}

}
