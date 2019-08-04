// [GonBee]
// �p�[�e�B�[BOT�@�\��AI�ɂ�����A�C�e���g�p�n���h�����`����B

#include "pybot_internal.hpp"

namespace pybot {

// -----------------------------------------------------------------------------
// AI�̃A�C�e���g�p�n���h���̒�`
	
// 䥂ŃT�\�����g���B
AI_ITEM_USE_FUNC(AGI_DISH10) {
	if (!bot->sc()->data[SC_FOOD_AGI_CASH]) bot->use_item(itm_ind);
}

// �u���M�|�[�V�������g���B
AI_ITEM_USE_FUNC(BRAGI_POTION) {
	if (!bot->sc()->data[SC_BRAGIPOTION]) bot->use_item(itm_ind);
}

// �L���r�A�p���P�[�L���g���B
AI_ITEM_USE_FUNC(CAVIAR_PANCAKE) {
	if (bot->sc()->data[SC_SILENCE] ||
		bot->sc()->data[SC_BLIND] ||
		bot->sc()->data[SC_CURSE] ||
		bot->sc()->data[SC_HALLUCINATION] ||
		bot->sc()->data[SC_BLEEDING]
	) bot->use_item(itm_ind);
}

// �t�x���Q���~���̎����g���B
AI_ITEM_USE_FUNC(DEX_DISH10) {
	if (!bot->sc()->data[SC_FOOD_DEX_CASH]) bot->use_item(itm_ind);
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

// HP�����|�[�V����(��)���g���B
AI_ITEM_USE_FUNC(HP_INCREASE_POTIONL) {
	if (!bot->sc()->data[SC_PROMOTE_HEALTH_RESERCH]) bot->use_item(itm_ind);
}

// �J�N�e���E���̓f�����g���B
AI_ITEM_USE_FUNC(INT_DISH10) {
	if (!bot->sc()->data[SC_FOOD_INT_CASH]) bot->use_item(itm_ind);
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

// ����ς̂����ۗ������g���B
AI_ITEM_USE_FUNC(LUK_DISH10) {
	if (!bot->sc()->data[SC_FOOD_LUK_CASH]) bot->use_item(itm_ind);
}

// �I�����A���̃t���R�[�X���g���B
AI_ITEM_USE_FUNC(ORLEANS_FULL_COURSE) {
	if (!bot->sc()->data[SC_FOOD_STR_CASH] ||
		!bot->sc()->data[SC_FOOD_AGI_CASH] ||
		!bot->sc()->data[SC_FOOD_VIT_CASH] ||
		!bot->sc()->data[SC_FOOD_INT_CASH] ||
		!bot->sc()->data[SC_FOOD_DEX_CASH] ||
		!bot->sc()->data[SC_FOOD_LUK_CASH] ||
		!bot->sc()->data[SC_ATKPOTION] ||
		!bot->sc()->data[SC_MATKPOTION]
	) bot->use_item(itm_ind);
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

// �R��p��j���g���B
AI_ITEM_USE_FUNC(REINS_OF_MOUNT) {
	if (!(bot->sc()->option & OPTION_RIDING) &&
		((!bot->sc()->data[SC_ALL_RIDING] &&
				bot->leader()->passive() &&
				!bot->is_hiding()
			) || (bot->sc()->data[SC_ALL_RIDING] &&
				!bot->leader()->passive()
			)
		)
	) {
		if (bot->is_sit()) bot->stand();
		bot->use_item(itm_ind);
	}
}

// ���W�X�g�A�[�X�|�[�V�������g���B
AI_ITEM_USE_FUNC(RESIST_EARTH) {
	if (bot->battle_mode() != BM_NONE &&
		!bot->sc()->data[SC_ARMOR_ELEMENT_EARTH]
	) bot->use_item(itm_ind);
}

// ���W�X�g�t�@�C�A�[�|�[�V�������g���B
AI_ITEM_USE_FUNC(RESIST_FIRE) {
	if (bot->battle_mode() != BM_NONE &&
		!bot->sc()->data[SC_ARMOR_ELEMENT_FIRE]
	) bot->use_item(itm_ind);
}

// ���W�X�g�R�[���h�|�[�V�������g���B
AI_ITEM_USE_FUNC(RESIST_WATER) {
	if (bot->battle_mode() != BM_NONE &&
		!bot->sc()->data[SC_ARMOR_ELEMENT_WATER]
	) bot->use_item(itm_ind);
}

// ���W�X�g�E�B���h�|�[�V�������g���B
AI_ITEM_USE_FUNC(RESIST_WIND) {
	if (bot->battle_mode() != BM_NONE &&
		!bot->sc()->data[SC_ARMOR_ELEMENT_WIND]
	) bot->use_item(itm_ind);
}

// �������i�|�[�V�������g���B
AI_ITEM_USE_FUNC(DIGEST_POTION) {
	if (!bot->sc()->data[SC_DIGESTPOTION]) bot->use_item(itm_ind);
}

// SP�����|�[�V����(��)���g���B
AI_ITEM_USE_FUNC(SP_INCREASE_POTIONL) {
	if (!bot->sc()->data[SC_ENERGY_DRINK_RESERCH]) bot->use_item(itm_ind);
}

// �^���̐��荇�킹���g���B
AI_ITEM_USE_FUNC(STR_DISH10) {
	if (!bot->sc()->data[SC_FOOD_STR_CASH]) bot->use_item(itm_ind);
}

// �s���̃`�Q����g���B
AI_ITEM_USE_FUNC(VIT_DISH10) {
	if (!bot->sc()->data[SC_FOOD_VIT_CASH]) bot->use_item(itm_ind);
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
