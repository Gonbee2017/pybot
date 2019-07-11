//==============================================================================
// Ragnarok Online Itemdb Functions
//==============================================================================

//============================================================
// ����ȃn�G�̉H
//------------------------------------------------------------
function	script	ItemdbPartyCall	{
	warp "Random",0,0;
	set .@name$,strcharinfo(0);
	if(.@name$ == getpartyleader(getcharid(1)) && !getmapxy(.@map$,.@x,.@y,0)) {
		getpartymember getcharid(1);
		for(set .@i,0; .@i < $@partymembercount; set .@i,.@i+1) {
			if($@partymembername$[.@i] == .@name$)			// �����͏��O
				continue;
			if(getmapname($@partymembername$[.@i]) != .@map$)	// MAP���Ⴄ
				continue;
			if(attachrid(getcharid(3,$@partymembername$[.@i]))) {
				if(!checkdead()) {
					// ���S���ĂȂ��Ȃ烊�[�_�[�̌��փ��[�v
					warp .@map$,.@x,.@y;
				}
				detachrid;
			}
		}
	}
	return;
}

//============================================================
// �L���L���X�e�B�b�N
//------------------------------------------------------------
function	script	ItemdbResetSkill	{
	if(Weight || checkcart() || checkfalcon() || checkriding())
		return;
	set .@lv,getskilllv(1);	// ��{�X�L��
	resetskill 0;		// �N�G�X�g�X�L���̓��Z�b�g���Ȃ�
	if(.@lv > 0) {
		skill 1,.@lv,0;
		set SkillPoint,SkillPoint - .@lv;
	}
	return;
}

//============================================================
// �q�[���n���ʌ��㑍��
//------------------------------------------------------------
function	script	ItemdbAlmightyHeal	{
	set .@flag,getarg(0);
	set .@val,getarg(1);
	if(.@flag&1) {
		bonus2 bAddSkillHealRate,28,.@val;	/* �q�[�� */
		bonus2 bAddSkillDamageRate,28,.@val;
	}
	if(.@flag&2) {
		bonus2 bAddSkillHealRate,70,.@val;	/* �T���N�`���A�� */
		bonus2 bAddSkillDamageRate,70,.@val;
	}
	if(.@flag&4)
		bonus2 bAddSkillHealRate,231,.@val;	/* �|�[�V�����s�b�`���[ */
	if(.@flag&8)
		bonus2 bAddSkillHealRate,478,.@val;	/* �X�����|�[�V�����s�b�`���[ */
	if(.@flag&16)
		bonus2 bAddSkillHealRate,322,.@val;	/* �C�h�D���̗ь� */
	if(.@flag&32) {
		bonus2 bAddSkillHealRate,2043,.@val;	/* �R���Z�I�q�[�� */
		bonus2 bAddSkillDamageRate,2043,.@val;
	}
	if(.@flag&64) {
		bonus2 bAddSkillHealRate,2051,.@val;	/* �n�C�l�X�q�[�� */
		bonus2 bAddSkillDamageRate,2051,.@val;
	}
	return;
}