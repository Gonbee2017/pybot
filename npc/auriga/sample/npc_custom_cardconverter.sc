prontera,146,232,5	script	������::Inventor	923,{
	mes "[�i�J�K�����m]";
	mes "�E�I�b�z���I";
	mes "���V�̖��̓i�J�K�����m�B";
	mes "�����̓V�˂ƌĂ΂�Ă���B";
	next;
	mes "[�i�J�K�����m]";
	mes "�����ėׂɂ���̂����N�̌����̖���";
	mes "���Ɋ������������̃}�V�[���c�c";
	mes "�J�[�h�R���o�[�^�[����I";
	next;
	if (select("�ǂ��������̂Ȃ�ł����H", "��������܂���") == 1) {
		mes "[�i�J�K�����m]";
		mes "�悭�������Ă��ꂽ�B";
		mes "���O����A�Ⴂ�̂Ɍ���ڂ�����ȁB";
		next;
		mes "[�i�J�K�����m]";
		mes "���̃}�V�[���ɃJ�[�h�𓊓������";
		mes "�c�c";
		mes "�����΂�G�}�Ƃ��ă����q��������";
		mes "�c�c";
		mes "����ꂽ�g�`���֊֐��ŉ�͂���";
		mes "�c�c";
		next;
		mes "-�^���ɐ������Ă���Ă���悤����";
		mes "�@�����񂹂�b���Ӗ��s���ł܂�����";
		mes "�@�����ł��Ȃ�-";
		next;
		mes "[�i�J�K�����m]";
		mes "�c�c���̌��ʁA�� �� �Ȃ�ƁI";
		mes "���̃J�[�h�Ƃ͈قȂ�ʂ̃J�[�h��";
		mes "�ϊ������񂶂�I";
		next;
		mes "[�i�J�K�����m]";
		mes "�������s�m�萫�����ɂ��ǂ̃J�[�h��";
		mes "�ϊ�����邩�͖��m�����Ⴊ�ȁc�c";
		next;
		select("�͂��c�c");
		mes "[�i�J�K�����m]";
		mes "�킩��񂩂ˁH";
		mes "�q�ɂŃz�R�������Ԃ��Ă���J�[�h��";
		mes "�g�����̂���J�[�h�ɕϊ��ł����";
		mes "�`���̑傫�ȏ����ɂȂ邶���B";
		next;
		select("����͂����������I");
		mes "[�i�J�K�����m]";
		mes "������O����B";
		mes "�Ȃ񂹃��V�̔������Ⴉ��ȁI";
		mes "�K�b�n�b�n�c�c";
		next;
		mes "[�i�J�K�����m]";
		mes "�����]���Ă���J�[�h����������";
		mes "���̃}�V�[���ŕϊ����Ă݂Ȃ���B";
		next;
		mes "[�i�J�K�����m]";
		mes "���������炩���ߒf���Ă�����";
		mes "�ϊ��������Ƃŕ���͌�������";
		mes "�Ȃ����Ⴜ���B";
		close;
	}
	mes "[�i�J�K�����m]";
	mes "�ӂށA�V�˂̔����͂Ȃ��Ȃ�";
	mes "�����������񂶂Ⴉ��ȁB";
	close;
}

prontera,144,230,5	script	��̋@�B::CardConverter	564,{
	if (checkitemblank() < 1) {
		soundeffect "effect\\warning.wav", 0;
		mes "[�J�[�h�R���o�[�^�[]";
		mes "^FF4040(�r�[ �r�[)^000000";
		mes "�A�C�e�� �I�[�o�[ �t���[";
		mes "�w���J�� �t�J�m�E";
		close;
	}
	soundeffect "effect\\analyze.wav", 0;
	mes "[�J�[�h�R���o�[�^�[]";
	mes "^00FF00(�s�| �p�| �s�|�p)^000000";
	mes "�J�[�h �� �g�E�j���E";
	mes "�V�e �N�_�T�C";
	next;
	setcardlist .@car_ids;
	set .@cars_siz, getarraysize(.@car_ids);
	if (.@cars_siz) {
		for (set .@i, 0; .@i < .@cars_siz; set .@i, .@i + 1)
			set .@car_nams$[.@i], getitemname(.@car_ids[.@i]);
		set .@car_nams$[.@i], "��߂�";
		set .@car_ind, select(printarray(.@car_nams$)) - 1;
		if (.@car_ind < .@cars_siz) {
			set .@old_car_id, .@car_ids[.@car_ind];
			set .@old_car_nam$, .@car_nams$[.@car_ind];
			mes "[�J�[�h�R���o�[�^�[]";
			mes "^00FF00(�s�[ �K�K�K�K)^000000";
			mes "�^�_�C�} �j���V�L �`���E";
			mes "�V�o���N �I�}�` �N�_�T�C";
			next;
			mes "[�J�[�h�R���o�[�^�[]";
			mes "^00FF00(�s�R�[�� �s�R�[��)^000000";
			mes "�j���V�L �J�������E";
			next;
			mes "[�J�[�h�R���o�[�^�[]";
			mes "�^�[�Q�b�g �J�N�j��";
			mes ">>> ^4040FF" + .@old_car_nam$ + "^000000 <<<";
			mes "�R�m �J�[�h ��";
			mes "�w���J�� �V�}�X�J�H";
			next;
			if (select("�͂�", "������") == 1) {
				soundeffect "se_machine.wav", 0;
				mes "[�J�[�h�R���o�[�^�[]";
				mes "^00FF00(�O���� �O���� �K�^�� �K�^��)^000000";
				mes "�^�_�C�} �w���J�� �`���E";
				mes "�V�o���N �I�}�` �N�_�T�C";
				next;
				specialeffect EF_WARP;
				soundeffect "effect\\hovering.wav", 0;
				mes "[�J�[�h�R���o�[�^�[]";
				mes "^00FF00(�L���C�[��)^000000";
				mes "�G�l���M�[ �W���E�e��";
				mes "�P�Q�O �p�[�Z���g";
				mes "�A�c�����N �W���E�V���E";
				next;
				specialeffect EF_SUI_EXPLOSION;
				mes "[�J�[�h�R���o�[�^�[]";
				mes "^FF4040(�{���b)^000000";
				next;
				if (countitem(.@old_car_id)) {
					
					// �A�g�~�b�N
					set .@new_car_id, convertcard(.@old_car_id);
					delitem .@old_car_id, 1;
					getitem .@new_car_id, 1;
					
					soundeffect "rsx_0806_stand.wav", 0;
					mes "[�J�[�h�R���o�[�^�[]";
					mes "^00FF00(�v�V���[�[�[)^000000";
					mes "�w���J�� �J�������E";
					mes "�J�[�h �� �I�E�P�g�� �N�_�T�C";
					close;
				}
			}
		}
		soundeffect "effect\\warning.wav", 0;
		mes "[�J�[�h�R���o�[�^�[]";
		mes "^FF4040(�r�[ �r�[)^000000";
		mes "�w���J�� �`���E�V";
		close;
	}
	mes "-�J�[�h��1���������Ă��Ȃ��̂�";
	mes "�@���̋@�B���g�����Ƃ͂ł��Ȃ��B-";
	close;
}
