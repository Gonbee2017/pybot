//-----------------------------------------------------------------------------
// �]�E�J�v��	<3���E�Ή���>
//-----------------------------------------------------------------------------
prontera,161,192,5	script	�]�E�J�v��	114,{
	cutin "kafra_04",2;
	mes "[�]�E�J�v��]";
	mes "��������Ⴂ�܂��B";
	mes "������ł́A�]�E���鎖���o���܂��B";
	mes "�]�E������]�ł����H";
	next;
	if(select("�͂�","������") == 2) {
		mes "[�]�E�J�v��]";
		mes "�܂������p���������B";
		close2;
		cutin "kafra_04",255;
		end;
	}
	if(getskilllv(1) < 9) {
		mes "[�]�E�J�v��]";
		mes "��{�X�L��������܂���B";
		mes "��{�X�L�����x�����グ�Ă���";
		mes "�܂����z�����������B";
		close2;
		cutin "kafra_04",255;
		end;
	}
	if(SkillPoint) {
		mes "[�]�E�J�v��]";
		mes "�X�L���|�C���g���c���Ă��܂��B";
		mes "�S�ď���Ă��Ă���";
		mes "�܂����z�����������B";
		close2;
		cutin "kafra_04",255;
		end;
	}
	// �E��ID�Z�b�g
	set .@job_id,0;
	switch(Job) {
		case Job_Novice:
			setarray .@job_id,Job_Swordman,Job_Magician,Job_Archer,Job_Acolyte,Job_Merchant,Job_Thief;
			if(Upper != UPPER_HIGH) {
				set .@job_id[getarraysize(.@job_id)],Job_SuperNovice;
			}
			if(Upper == UPPER_NORMAL) {
				setarray .@job_id[getarraysize(.@job_id)],Job_Taekwon,Job_Gunslinger,Job_Ninja,Job_Gyangsy;
			}
			break;
		case Job_Swordman:
			if(Upper == UPPER_HIGH) {
				set .@job_id,OLD_CLASS;
			}
			else {
				setarray .@job_id,Job_Knight,Job_Crusader;
			}
			break;
		case Job_Magician:
			if(Upper == UPPER_HIGH) {
				set .@job_id,OLD_CLASS;
			}
			setarray .@job_id,Job_Wizard,Job_Sage;
			break;
		case Job_Archer:
			if(Upper == UPPER_HIGH) {
				set .@job_id,OLD_CLASS;
			}
			else if(Sex) {
				setarray .@job_id,Job_Hunter,Job_Bard;
			}
			else {
				setarray .@job_id,Job_Hunter,Job_Dancer;
			}
			break;
		case Job_Acolyte:
			if(Upper == UPPER_HIGH) {
				set .@job_id,OLD_CLASS;
			}
			setarray .@job_id,Job_Priest,Job_Monk;
			break;
		case Job_Merchant:
			if(Upper == UPPER_HIGH) {
				set .@job_id,OLD_CLASS;
			}
			setarray .@job_id,Job_Blacksmith,Job_Alchemist;
			break;
		case Job_Thief:
			if(Upper == UPPER_HIGH) {
				set .@job_id,OLD_CLASS;
			}
			setarray .@job_id,Job_Assassin,Job_Rogue;
			break;
		case Job_Taekwon:
			setarray .@job_id,Job_Star,Job_Linker;
			break;
		case Job_Gyangsy:
			setarray .@job_id,Job_DeathKnight,Job_DarkCollector;
			break;
		case Job_Knight:
			set .@job_id,Job_RuneKnight;
			break;
		case Job_Priest:
			set .@job_id,Job_ArchBishop;
			break;
		case Job_Wizard:
			set .@job_id,Job_Warlock;
			break;
		case Job_Blacksmith:
			set .@job_id,Job_Mechanic;
			break;
		case Job_Hunter:
			set .@job_id,Job_Ranger;
			break;
		case Job_Assassin:
			set .@job_id,Job_Guillotine;
			break;
		case Job_Crusader:
			set .@job_id,Job_RoyalGuard;
			break;
		case Job_Monk:
			set .@job_id,Job_Shura;
			break;
		case Job_Sage:
			set .@job_id,Job_Sorcerer;
			break;
		case Job_Rogue:
			set .@job_id,Job_ShadowChaser;
			break;
		case Job_Alchemist:
			set .@job_id,Job_Genetic;
			break;
		case Job_Bard:
			set .@job_id,Job_Minstrel;
			break;
		case Job_Dancer:
			set .@job_id,Job_Wanderer;
			break;
		case Job_SuperNovice:
			setarray .@job_id,Job_ExpandedSuperNovice;
			break;
		case Job_Ninja:
			if(Sex) {
				setarray .@job_id,Job_Kagerou;
			}
			else {
				setarray .@job_id,Job_Oboro;
			}
			break;
	}
	if(.@job_id[0] == 0) {
		mes "[�]�E�J�v��]";
		mes "�c�O�Ȃ���A���Ȃ���";
		mes "���ē��ł���E�Ƃ�����܂���B";
		mes "�܂����z�����������B";
		close2;
		cutin "kafra_04",255;
		end;
	}
	mes "[�]�E�J�v��]";
	mes "���Ȃ��ɂ��ē��ł���E�Ƃ�";
	mes "���̒ʂ�ł��B";
	mes "�ǂ̐E�Ƃɓ]�E����܂����H";
	next;
	// �E�Ɩ��Z�b�g
	set .@job_name$,"";
	set .@max,getarraysize(.@job_id);
	for(set .@i,0; .@i < .@max; set .@i,.@i + 1) {
		switch(.@job_id[.@i]) {
			case Job_Swordman:
				set .@job_name$[.@i],"�\�[�h�}��";
				break;
			case Job_Magician:
				set .@job_name$[.@i],"�}�W�V����";
				break;
			case Job_Archer:
				set .@job_name$[.@i],"�A�[�`���[";
				break;
			case Job_Acolyte:
				set .@job_name$[.@i],"�A�R���C�g";
				break;
			case Job_Merchant:
				set .@job_name$[.@i],"�}�[�`�����g";
				break;
			case Job_Thief:
				set .@job_name$[.@i],"�V�[�t";
				break;
			case Job_Knight:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"���[�h�i�C�g";
				}
				else {
					set .@job_name$[.@i],"�i�C�g";
				}
				break;
			case Job_Priest:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�n�C�v���[�X�g";
				}
				else {
					set .@job_name$[.@i],"�v���[�X�g";
				}
				break;
			case Job_Wizard:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�n�C�E�B�U�[�h";
				}
				else {
					set .@job_name$[.@i],"�E�B�U�[�h";
				}
				break;
			case Job_Blacksmith:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�z���C�g�X�~�X";
				}
				else {
					set .@job_name$[.@i],"�u���b�N�X�~�X";
				}
				break;
			case Job_Hunter:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�X�i�C�p�[";
				}
				else {
					set .@job_name$[.@i],"�n���^�[";
				}
				break;
			case Job_Assassin:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�A�T�V���N���X";
				}
				else {
					set .@job_name$[.@i],"�A�T�V��";
				}
				break;
			case Job_Crusader:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�p���f�B��";
				}
				else {
					set .@job_name$[.@i],"�N���Z�C�_�[";
				}
				break;
			case Job_Monk:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�`�����s�I��";
				}
				else {
					set .@job_name$[.@i],"�����N";
				}
				break;
			case Job_Sage:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�v���t�F�b�T�[";
				}
				else {
					set .@job_name$[.@i],"�Z�[�W";
				}
				break;
			case Job_Rogue:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�`�F�C�T�[";
				}
				else {
					set .@job_name$[.@i],"���[�O";
				}
				break;
			case Job_Alchemist:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�N���G�C�^�[";
				}
				else {
					set .@job_name$[.@i],"�A���P�~�X�g";
				}
				break;
			case Job_Bard:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�N���E��";
				}
				else {
					set .@job_name$[.@i],"�o�[�h";
				}
				break;
			case Job_Dancer:
				if(Upper == UPPER_HIGH) {
					set .@job_name$[.@i],"�W�v�V�[";
				}
				else {
					set .@job_name$[.@i],"�_���T�[";
				}
				break;
			case Job_SuperNovice:
				set .@job_name$[.@i],"�X�[�p�[�m�[�r�X";
				break;
			case Job_Taekwon:
				set .@job_name$[.@i],"�e�R���L�b�h";
				break;
			case job_Star:
				set .@job_name$[.@i],"����";
				break;
			case Job_Linker:
				set .@job_name$[.@i],"�\�E�������J�[";
				break;
			case Job_Gunslinger:
				set .@job_name$[.@i],"�K���X�����K�[";
				break;
			case Job_Ninja:
				set .@job_name$[.@i],"�E��";
				break;
			case Job_Gyangsy:
				if(Sex) {
					set .@job_name$[.@i],"�{���S��";
				}
				else {
					set .@job_name$[.@i],"���i�b�N";
				}
				break;
			case Job_DeathKnight:
				set .@job_name$[.@i],"�f�X�i�C�g";
				break;
			case Job_DarkCollector:
				set .@job_name$[.@i],"�_�[�N�R���N�^�[";
				break;
			case Job_RuneKnight:
				set .@job_name$[.@i],"���[���i�C�g";
				break;
			case Job_Warlock:
				set .@job_name$[.@i],"�E�H�[���b�N";
				break;
			case Job_Ranger:
				set .@job_name$[.@i],"�����W���[";
				break;
			case Job_ArchBishop:
				set .@job_name$[.@i],"�A�[�N�r�V���b�v";
				break;
			case Job_Mechanic:
				set .@job_name$[.@i],"���J�j�b�N";
				break;
			case Job_Guillotine:
				set .@job_name$[.@i],"�M���`���N���X";
				break;
			case Job_RoyalGuard:
				set .@job_name$[.@i],"���C�����K�[�h";
				break;
			case Job_Sorcerer:
				set .@job_name$[.@i],"�\�[�T���[";
				break;
			case Job_Minstrel:
				set .@job_name$[.@i],"�~���X�g����";
				break;
			case Job_Wanderer:
				set .@job_name$[.@i],"�����_���[";
				break;
			case Job_Shura:
				set .@job_name$[.@i],"�C��";
				break;
			case Job_Genetic:
				set .@job_name$[.@i],"�W�F�l�e�B�b�N";
				break;
			case Job_ShadowChaser:
				set .@job_name$[.@i],"�V���h�E�`�F�C�T�[";
				break;
			case Job_ExpandedSuperNovice:
				set .@job_name$[.@i],"�g���X�[�p�[�m�[�r�X";
				break;
			case Job_Kagerou:
				set .@job_name$[.@i],"�e�T";
				break;
			case Job_Oboro:
				set .@job_name$[.@i],"�O";
				break;
		}
	}
	set .@job_name$[.@max],"��߂�";
	set @menu,select(printarray(.@job_name$));
	if(.@job_id[@menu - 1] == 0) {
		mes "[�]�E�J�v��]";
		mes "�܂������p���������B";
		close2;
		cutin "kafra_04",255;
		end;
	}
	set .@sel_job,.@job_id[@menu - 1];
	mes "[�]�E�J�v��]";
	mes "^FF0000" +.@job_name$[@menu - 1]+ "^000000��";
	mes "�]�E����܂����H";
	next;
	if(select("�͂�","������") == 2) {
		mes "[�]�E�J�v��]";
		mes "�܂������p���������B";
		close2;
		cutin "kafra_04",255;
		end;
	}
	// �]�E�`�F�b�N�i���O�j
	switch(.@sel_job) {
		case Job_Swordman:
		case Job_Magician:
		case Job_Archer:
		case Job_Acolyte:
		case Job_Merchant:
		case Job_Thief:
		case Job_Taekwon:
		case Job_Gunslinger:
		case Job_Ninja:
		case Job_Gyangsy:
			if(getskilllv(1) < 9) {
				mes "[�]�E�J�v��]";
				mes "��{�X�L��������܂���B";
				mes "��{�X�L�����x�����グ�Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			if(JobLevel < 10) {
				mes "[�]�E�J�v��]";
				mes "�ꎟ�E�ɓ]�E����ɂ�";
				mes "Job���x����10�K�v�ł��B";
				mes "Job���x�����グ�Ă��Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			break;
		case Job_SuperNovice:
			if(getskilllv(1) < 9) {
				mes "[�]�E�J�v��]";
				mes "��{�X�L��������܂���B";
				mes "��{�X�L�����x�����グ�Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			if(JobLevel < 10) {
				mes "[�]�E�J�v��]";
				mes "�X�[�p�[�m�[�r�X�ɓ]�E����ɂ�";
				mes "Job���x����40�K�v�ł��B";
				mes "Job���x�����グ�Ă��Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			if(BaseLevel < 45) {
				mes "[�]�E�J�v��]";
				mes "�X�[�p�[�m�[�r�X�ɓ]�E����ɂ�";
				mes "Base���x����45�ȏ�K�v�ł��B";
				mes "Base���x�����グ�Ă��Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			break;
		case Job_Knight:
		case Job_Priest:
		case Job_Wizard:
		case Job_Blacksmith:
		case Job_Hunter:
		case Job_Assassin:
		case Job_Crusader:
		case Job_Monk:
		case Job_Sage:
		case Job_Rogue:
		case Job_Alchemist:
		case Job_Bard:
		case Job_Dancer:
		case job_Star:
		case Job_Linker:
		case Job_DeathKnight:
		case Job_DarkCollector:
			if(JobLevel < 40) {
				mes "[�]�E�J�v��]";
				mes "�񎟐E�ɓ]�E����ɂ�";
				mes "Job���x����40�ȏ�K�v�ł��B";
				mes "Job���x�����グ�Ă��Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			break;
		case Job_RuneKnight:
		case Job_Warlock:
		case Job_Ranger:
		case Job_ArchBishop:
		case Job_Mechanic:
		case Job_Guillotine:
		case Job_RoyalGuard:
		case Job_Sorcerer:
		case Job_Minstrel:
		case Job_Wanderer:
		case Job_Shura:
		case Job_Genetic:
		case Job_ShadowChaser:
// �����d�l
//			if(Upper != UPPER_HIGH) {
//				mes "[�]�E�J�v��]";
//				mes "�O���E�ɓ]�E����ɂ�";
//				mes "�]������Ă���K�v������܂��B";
//				mes "�܂����z�����������B";
//				close2;
//				cutin "kafra_04",255;
//				end;
//			}
//			if(BaseLevel < 90) {
//				mes "[�]�E�J�v��]";
//				mes "�O���E�ɓ]�E����ɂ�";
//				mes "Base���x����90�ȏ�K�v�ł��B";
//				mes "Base���x�����グ�Ă��Ă���";
//				mes "�܂����z�����������B";
//				close2;
//				cutin "kafra_04",255;
//				end;
//			}
// �C�O�d�l
			if(BaseLevel < 99) {
				mes "[�]�E�J�v��]";
				mes "�O���E�ɓ]�E����ɂ�";
				mes "Base���x����99�K�v�ł��B";
				mes "Base���x�����グ�Ă��Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			break;
		case Job_ExpandedSuperNovice:
			if(JobLevel < 99) {
				mes "[�]�E�J�v��]";
				mes "�g���X�[�p�[�m�[�r�X�ɓ]�E����ɂ�";
				mes "Job���x����99�K�v�ł��B";
				mes "Job���x�����グ�Ă��Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			if(BaseLevel < 99) {
				mes "[�]�E�J�v��]";
				mes "�g���X�[�p�[�m�[�r�X�ɓ]�E����ɂ�";
				mes "Base���x����99�K�v�ł��B";
				mes "Base���x�����グ�Ă��Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			break;
		case Job_Kagerou:
		case Job_Oboro:
			if(JobLevel < 70) {
				mes "[�]�E�J�v��]";
				mes .@job_name$[0] + "�ɓ]�E����ɂ�";
				mes "Job���x����70�K�v�ł��B";
				mes "Job���x�����グ�Ă��Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			if(BaseLevel < 99) {
				mes "[�]�E�J�v��]";
				mes .@job_name$[0] + "�ɓ]�E����ɂ�";
				mes "Base���x����99�K�v�ł��B";
				mes "Base���x�����グ�Ă��Ă���";
				mes "�܂����z�����������B";
				close2;
				cutin "kafra_04",255;
				end;
			}
			break;
	}
	if(SkillPoint) {
		mes "[�]�E�J�v��]";
		mes "�X�L���|�C���g���c���Ă��܂��B";
		mes "�S�ď���Ă��Ă���";
		mes "�܂����z�����������B";
		close2;
		cutin "kafra_04",255;
		end;
	}
	nude;
	jobchange .@sel_job;
	mes "[�]�E�J�v��]";
	mes "�]�E���߂łƂ��������܂��I";
	mes "�M���̂�����Ɋ��҂��Ă��܂��B";
	close2;
	cutin "kafra_04",255;
	end;
}