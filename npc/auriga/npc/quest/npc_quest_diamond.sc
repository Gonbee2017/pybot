//==============================================================================
// Ragnarok Online Diamond Gambling Script     by Chiffon
//==============================================================================
comodo,219,158,6	script	�J�`���A	91,{
	cutin "katsua01",2;
	mes "[�J�`���A]";
	mes "�ȑO�Ɍ����A���̂ƂĂ��傫��";
	mes "�_�C�������h�B���ꂢ�������ȁ[�B";
	mes "����͂R�J���b�g���炢������B";
	mes "�������~�����ȁc�c�ǂ������";
	mes "��ɓ���̂�����H";
	next;
	if(select("�����܂��傤���H","���C���o���Ă�������")==2) {
		mes "[�J�`���A]";
		mes "�Ԃ߂Ă���Ă��肪�Ƃ��B";
		mes "�����[�A�������̃_�C�������h��";
		mes "��ɓ���̂Ȃ�A���̑厖��";
		mes "�R���N�V�����������";
		mes "�����o���̂Ɂc�c";
		close2;
		cutin "katsua01",255;
		end;
	}
	if(countitem(732)<1) {
		cutin "katsua03",2;
		mes "[�J�`���A]";
		mes "�ӂ�I";
		mes "�{���̓_�C�������h��������";
		mes "���Ȃ��̂ɁA�ǂ����Ď����Ă���";
		mes "���̂悤�ȑf�U�������́H";
		mes "����n���ɂ������ł����H";
		close2;
		cutin "katsua03",255;
		end;
	}
	if((MaxWeight - Weight) < 5500) {
		mes "[�J�`���A]";
		mes "����A����Ȃɂ�������̉ו���";
		mes "����ƁA��������n���ł��Ȃ���B";
		mes "�����q�ɂɗa���Ă��Ă��������ˁB";
		close2;
		cutin "katsua01",255;
		end;
	}
	cutin "katsua02",2;
	mes "[�J�`���A]";
	mes "������?!";
	mes "�{���ɂ�����ł����H";
	mes "���肪�Ƃ��������܂��[�B";
	mes "�ł͂���ɁA���̃R���N�V������";
	mes "������グ�܂��傤�B";
	next;
	mes "[�J�`���A]";
	mes "�ǂ�������]�݂ł��傤���H";
	next;
	switch(select("����","�Z","���ɂ����镨","��","�C","��")) {
	case 1:	//����
		set .@gamble,rand(1000);
		if(.@gamble >= 920 && .@gamble < 930) {
			set .@gamble,rand(85);
			switch(.@gamble) {
				case 0: getitem 1128,1; break;	//�C����[2]
				case 1: getitem 1120,1; break;	//�c���M[2]
				case 2: getitem 1127,1; break;	//�T�[�x��[3]
				case 3: getitem 1158,1; break;	//�c�[�n���h�\�[�h[2]
				case 4: getitem 1155,1; break;	//�o�X�^�[�h�\�[�h[3]
				case 5: getitem 1220,1; break;	//�O���f�B�E�X[3]
				case 6: getitem 1226,1; break;	//�_�}�X�J�X[2]
				case 7: getitem 1253,1; break;	//�J�^�[��[2]
				case 8: getitem 1529,1; break;	//�A�C�A���h���C�o�[
				case 9: getitem 1251,1; break;	//�W����[3]
				case 10: getitem 1361,1; break;	//�c�[�n���h�A�b�N�X[2]
				case 11: getitem 1258,1; break;	//�����̃J�^�[��
				case 12: getitem 1257,1; break;	//����Ă邢�΂�̃J�^�[��
				case 13: getitem 1256,1; break;	//�₽���X���̃J�^�[��
				case 14: getitem 1259,1; break;	//�����̃J�^�[��
				case 15: getitem 1260,1; break;	//�f�X�i�C�t
				case 16: getitem 1716,1; break;	//�p�|[2]
				case 17: getitem 1715,1; break;	//�A�[�o���X�g[2]
				case 18: getitem 1711,1; break;	//�N���X�{�E[3]
				case 19: getitem 1702,1; break;	//�{�E[4]
				case 20: getitem 1520,1; break;	//�`�F�C��[3]
				case 21: getitem 1611,1; break;	//�A�[�N�����h[2]
				case 22: getitem 1615,1; break;	//�[���̏�
				case 23: getitem 1602,1; break;	//���b�h[4]
				case 24: getitem 1461,1; break;	//�g���C�f���g[3]
				case 25: getitem 1402,1; break;	//�W���x����[4]
				case 26: getitem 1961,1; break;	//�z�C�b�v[2]
				case 27: getitem 1957,1; break;	//�����e[1]
				case 28: getitem 1552,1; break;	//�^�u���b�g[1]
				case 29: getitem 1551,1; break;	//�o�C�u��[2]
				case 30: getitem 1553,1; break;	//�r�ꋶ���g�̏�
				case 31: getitem 1554,1; break;	//�􂯂���n�̏�
				case 32: getitem 1555,1; break;	//�R���鑾�z�̏�
				case 33: getitem 1556,1; break;	//�����Ă镗�̏�
				case 34: getitem 1951,1; break;	//���[�v[4]
				case 35: getitem 1959,1; break;	//�e�C��[2]
				case 36: getitem 1953,1; break;	//���C��[3]
				case 37: getitem 1955,1; break;	//���C���[[3]
				case 38: getitem 1810,1; break;	//�N���[[2]
				case 39: getitem 1910,1; break;	//�n�[�v[2]
				case 40: getitem 1906,1; break;	//�����[�g[3]
				case 41: getitem 1902,1; break;	//�o�C�I����[4]
				case 42: getitem 1904,1; break;	//�}���h����[3]
				case 43: getitem 1912,1; break;	//�S�����S[2]
				case 44: getitem 1908,1; break;	//�M�^�[[1]
				case 45: getitem 1808,1; break;	//�t�B�X�g[1]
				case 46: getitem 1802,1; break;	//�o�O�i�E[4]
				case 47: getitem 1812,1; break;	//�t�B���K�[[2]
				case 48: getitem 1806,1; break;	//�z��[3]
				case 49: getitem 1804,1; break;	//�i�b�N���_�X�^�[[3]
				case 50: getitem 1550,1; break;	//�u�b�N[3]
				case 51: getitem 1246,1; break;	//�`���N�G�f�B�A[2]
				case 52: getitem 1147,1; break;	//�^�E���\�[�h[2]
				case 53:
				case 54: getitem 1264,1; break;	//�o���A�X�W����[4]
				case 55:
				case 56: getitem 1262,1; break;	//���L�̒�
				case 57:
				case 58: getitem 1622,1; break;	//�Ö��p�t�̏�[2]
				case 59: getitem 1723,1; break;	//���i�{�E
				case 60:
				case 61: getitem 1965,1; break;	//�g���̕�
				case 62:
				case 63: getitem 1966,1; break;	//�X���̕�
				case 64:
				case 65: getitem 1967,1; break;	//��n�̕�
				case 66:
				case 67: getitem 1968,1; break;	//�Ȃ�Ƃ�
				case 68:
				case 69: getitem 1914,1; break;	//�R�����M�̃M�^�[
				case 70:
				case 71: getitem 1915,1; break;	//�ǓƂȃ\���̃M�^�[
				case 72:
				case 73: getitem 1916,1; break;	//�L��ȑ�n�̃M�^�[
				case 74:
				case 75: getitem 1917,1; break;	//�_�炩�Ȃ��敗�̃M�^�[
				case 76:
				case 77: getitem 13004,1; break;	//�R���[�h[2]
				case 78:
				case 79: getitem 1307,1; break;	//�E�B���h�z�[�N
				case 80: getitem 1560,1; break;	//���҂̓��L[2]
				case 81: getitem 1618,1; break;	//�T�o�C�o�����b�h[1]
				case 82: getitem 1620,1; break;	//�T�o�C�o�����b�h[1]
				case 83:
				case 84: getitem 1971,1; break;	//�d�C��
			}
		}
		else if(.@gamble >= 0 && .@gamble < 200)
			getitem 1201,1;		//�i�C�t[3]
		else if(.@gamble >= 200 && .@gamble < 300)
			getitem 1101,1;		//�\�[�h[3]
		else if(.@gamble >= 300 && .@gamble < 400)
			getitem 1601,1;		//���b�h[3]
		else if(.@gamble >= 400 && .@gamble < 500)
			getitem 1116,1;		//�J�^�i[3]
		else if(.@gamble >= 500 && .@gamble < 600)
			getitem 1250,1;		//�W����[2]
		else if(.@gamble >= 600 && .@gamble < 700)
			getitem 1301,1;		//�A�b�N�X[3]
		else if(.@gamble >= 700 && .@gamble < 800)
			getitem 1701,1;		//�{�E[3]
		else if(.@gamble >= 800 && .@gamble < 850)
			getitem 1504,1;		//���C�X[3]
		else if(.@gamble >= 850 && .@gamble < 900)
			getitem 1604,1;		//�����h[2]
		else if(.@gamble >= 900 && .@gamble < 910)
			getitem 1108,1;		//�u���C�h[4]
		else if(.@gamble >= 910 && .@gamble < 920)
			getitem 1163,1;		//�N���C���A
		else if(.@gamble >= 930 && .@gamble < 960)
			getitem 1522,1;		//�X�^�i�[
		else if(.@gamble >= 960 && .@gamble < 970)
			getitem 1608,1;		//�X�^�b�t[3]
		else if(.@gamble >= 970 && .@gamble < 980)
			getitem 1408,1;		//�p�C�N[4]
		else if(.@gamble >= 980 && .@gamble < 990)
			getitem 1452,1;		//�M�U����[3]
		else
			getitem 1208,1;		//�}�C���S�[�V��[4]
		break;
	case 2:	//�Z
		set .@gamble,rand(500);
		if(.@gamble >= 299 && .@gamble < 302) {
			set .@gamble,rand(15);
			switch(.@gamble) {
				case 0: getitem 2315,1; break;	//���C��[1]
				case 1: getitem 2336,1; break;	//�V�[�t�N���[�X[1]
				case 2: getitem 2318,1; break;	//���[�h�N���[�X[1]
				case 3: getitem 2326,1; break;	//�Z�C���g���[�u[1]
				case 4: getitem 2327,1; break;	//�z�[���[���[�u
				case 5: getitem 2342,1; break;	//�t���v���[�g[1]
				case 6: getitem 2331,1; break;	//�^�C�c[1]
				case 7: getitem 2342,1; break;	//�t���v���[�g[1]
				case 8: getitem 2311,1; break;	//�~���N�̃R�[�g[1]
				case 9: getitem 2320,1; break;	//�t�H�[�}���X�[�c[1]
				case 10: getitem 2319,1; break;	//�O���b�^�����O�N���[�X[1]
				case 11: getitem 2344,1; break;	//���V�E�X�ΎR�̌�����
				case 12: getitem 2346,1; break;	//�V���s�j�n�C�̋���
				case 13: getitem 2348,1; break;	//�G�x�V���̂��˂�
				case 14: getitem 2350,1; break;	//�N���C�g�X��n�̗􂯖�
			}
		}
		else if(.@gamble >= 0 && .@gamble < 50)
			getitem 2301,1;		//�R�b�g���V���c
		else if(.@gamble >= 50 && .@gamble < 100)
			getitem 2302,1;		//�R�b�g���V���c[1]
		else if(.@gamble >= 100 && .@gamble < 150)
			getitem 2303,1;		//���U�[�W���P�b�g
		else if(.@gamble >= 150 && .@gamble < 200)
			getitem 2304,1;		//���U�[�W���P�b�g[1]
		else if(.@gamble >= 200 && .@gamble < 250)
			getitem 2305,1;		//�A�h�x���`���[�X�[�c
		else if(.@gamble >= 250 && .@gamble < 299)
			getitem 2301,1;		//�R�b�g���V���c
		else if(.@gamble >= 302 && .@gamble < 350)
			getitem 2307,1;		//�����g��
		else if(.@gamble >= 350 && .@gamble < 400)
			getitem 2309,1;		//�����O�R�[�g
		else if(.@gamble == 400)
			getitem 2322,1;		//�V���N���[�u[1]
		else if(.@gamble == 401)
			getitem 2310,1;		//�����O�R�[�g[1]
		else if(.@gamble >= 402 && .@gamble < 410)
			getitem 2306,1;		//�A�h�x���`���[�X�[�c[1]
		else if(.@gamble >= 410 && .@gamble < 415)
			getitem 2308,1;		//�����g��[1]
		else if(.@gamble >= 415 && .@gamble < 420)
			getitem 2313,1;		//�A�[�}�[[1]
		else if(.@gamble >= 420 && .@gamble < 425)
			getitem 2337,1;		//�E�҃X�[�c
		else if(.@gamble >= 425 && .@gamble < 430)
			getitem 2341,1;		//�t���v���[�g
		else if(.@gamble >= 430 && .@gamble < 435)
			getitem 2325,1;		//�Z�C���g���[�u
		else if(.@gamble >= 435 && .@gamble < 440)
			getitem 2316,1;		//�v���[�g
		else if(.@gamble >= 440 && .@gamble < 445)
			getitem 2330,1;		//�^�C�c
		else if(.@gamble >= 445 && .@gamble < 450)
			getitem 2314,1;		//���C��
		else if(.@gamble >= 450 && .@gamble < 455)
			getitem 2335,1;		//�V�[�t�N���[�X
		else if(.@gamble >= 455 && .@gamble < 460)
			getitem 2324,1;		//�X�P�[�s���[��[1]
		else if(.@gamble >= 460 && .@gamble < 465)
			getitem 2329,1;		//�E�h�D�����C��[1]
		else if(.@gamble >= 465 && .@gamble < 470)
			getitem 2340,1;		//���S�җp������[1]
		else if(.@gamble >= 470 && .@gamble < 475)
			getitem 2312,1;		//�A�[�}�[
		else if(.@gamble >= 475 && .@gamble < 480)
			getitem 2339,1;		//�u���[�t
		else if(.@gamble >= 480 && .@gamble < 485)
			getitem 2328,1;		//�E�h�D�����C��
		else if(.@gamble >= 485 && .@gamble < 490)
			getitem 2321,1;		//�V���N���[�u
		else
			getitem 2323,1;		//�X�P�[�s���[��
		break;
	case 3:	//���ɂ����镨
		set .@gamble,rand(500);
		if(.@gamble >= 200 && .@gamble < 203) {
			set .@gamble,rand(16);
			switch(.@gamble) {
				case 0:
				case 1: getitem 2506,1; break;	//�}���g[1]
				case 2:
				case 3: getitem 2504,1; break;	//�}�t���[[1]
				case 4:
				case 5:
				case 6: getitem 2508,1; break;	//�ڂ�}���g
				case 7:
				case 8:
				case 9: getitem 2507,1; break;	//�̗̂̎�̃}���g
				case 10: getitem 2513,1; break;	//�V���̉H��[1]
				case 11: getitem 2514,1; break;	//�|�[���h����[1]
				case 12:
				case 13: getitem 2523,1; break;	//�����j���O�V���c[1]
				case 14: getitem 2509,1; break;	//�T�o�C�o���}���g
				case 15: getitem 2515,1; break;	//�E�B���O�I�u�C�[�O��[1]
			}
		}
		else if(.@gamble >= 0 && .@gamble < 100)
			getitem 2503,1;		//�}�t���[
		else if(.@gamble >= 100 && .@gamble < 200)
			getitem 2505,1;		//�}���g
		else if(.@gamble >= 203 && .@gamble < 450)
			getitem 2501,1;		//�t�[�h
		else
			getitem 2502,1;		//�t�[�h[1]
		break;
	case 4:	//��
		set .@gamble,rand(1000);
		if(.@gamble >= 299 && .@gamble < 304) {
			set .@gamble,rand(93);
			switch(.@gamble) {
				case 0:
				case 1: getitem 2251,1; break;	//���E�҂̖X�q
				case 2:
				case 3: getitem 2285,1; break;	//���ˎ�̂��
				case 4:
				case 5: getitem 2255,1; break;	//�����̃w�A�o���h
				case 6:
				case 7: getitem 5045,1; break;	//�V���N�n�b�g
				case 8:
				case 9: getitem 2233,1; break;	//�T�[�N���b�g[1]
				case 10:
				case 11: getitem 2231,1; break;	//�W���G���w����[1]
				case 12:
				case 13: getitem 2217,1; break;	//�r���^[1]
				case 14:
				case 15: getitem 2206,1; break;	//���F�[��
				case 16:
				case 17: getitem 2246,1; break;	//�S�[���f���w�b�h�M�A
				case 18:
				case 19: getitem 2261,1; break;	//�v�����e���R�X
				case 20:
				case 21: getitem 2287,1; break;	//�C���̓���
				case 22:
				case 23: getitem 5012,1; break;	//�w�ҖX
				case 24:
				case 25: getitem 2244,1; break;	//�傫�ȃ��{��
				case 26:
				case 27: getitem 2213,1; break;	//�L���̃w�A�o���h
				case 28:
				case 29: getitem 2248,1; break;	//�E�F�X�^���O���C�X
				case 30:
				case 31: getitem 2223,1; break;	//�ۂ��ڂ���[1]
				case 32:
				case 33: getitem 2247,1; break;	//�I�[���h�X�^�[���}���X
				case 34:
				case 35: getitem 2245,1; break;	//�X�C�[�g�W�F���g��
				case 36:
				case 37: getitem 5003,1; break;	//�s�G���̖X�q
				case 38:
				case 39: getitem 2225,1; break;	//�S�[�O��[1]
				case 40:
				case 41: getitem 5017,1; break;	//�{�[���w����
				case 42:
				case 43: getitem 5030,1; break;	//�p���_�X
				case 44:
				case 45: getitem 5035,1; break;	//�|�����X
				case 46:
				case 47: getitem 2250,1; break;	//���{���̃w�A�o���h
				case 48:
				case 49: getitem 2277,1; break;	//�Ō�X
				case 50:
				case 51: getitem 5011,1; break;	//�A���e�i
				case 52:
				case 53: getitem 2290,1; break;	//�����p�̖X�q
				case 54:
				case 55: getitem 5010,1; break;	//�C���f�B�A���̃w�A�o���h
				case 56:
				case 57: getitem 2259,1; break;	//�v���y��
				case 58:
				case 59: getitem 5008,1; break;	//�����߂̗�
				case 60:
				case 61: getitem 2249,1; break;	//�R���l�b�g
				case 62:
				case 63: getitem 2229,1; break;	//�w����[1]
				case 64: getitem 2258,1; break;	//�V���[�v�w�b�h�M�A
				case 65: getitem 2274,1; break;	//�S�҂̃w�A�o���h
				case 66: getitem 5019,1; break;	//�R���Z�A
				case 67: getitem 2254,1; break;	//�V�g�̃w�A�o���h
				case 68: getitem 5007,1; break;	//���[�h�T�[�N���b�g
				case 69: getitem 5066,1; break;	//�T�L���o�X�̊p
				case 70: getitem 2235,1; break;	//�N���E��
				case 71: getitem 2234,1; break;	//�e�B�A��
				case 72: getitem 2256,1; break;	//�}�W�F�X�e�B�b�N�S�[�g
				case 73: getitem 5093,1; break;	//�C�����̃��F�[��[1]
				case 74: getitem 5072,1; break;	//�C���L���o�X�̊p
				case 75: getitem 5002,1; break;	//�W���G���N���E��
				case 76:
				case 77:
				case 78: getitem 5118,1; break;	//�q���̃w�A�o���h
				case 79:
				case 80:
				case 81: getitem 5120,1; break;	//���炩���X�q
				case 82:
				case 83:
				case 84: getitem 5111,1; break;	//�K���p�S�X
				case 85:
				case 86:
				case 87: getitem 5116,1; break;	//�o�i�i�̔�
				case 88:
				case 89:
				case 90: getitem 5119,1; break;	//�X�[�p�[�m�[�r�X�X[1]
				case 91:
				case 92: getitem 5141,1; break;	//�}���I�l�b�g�l�`[1]
			}
		}
		else if(.@gamble >= 0 && .@gamble < 100)
			getitem 2226,1;		//�L���b�v
		else if(.@gamble >= 100 && .@gamble < 200)
			getitem 2211,1;		//����
		else if(.@gamble >= 200 && .@gamble < 299)
			getitem 2209,1;		//���{��[1]
		else if(.@gamble >= 304 && .@gamble < 400)
			getitem 2220,1;		//�n�b�g
		else if(.@gamble >= 400 && .@gamble < 500)
			getitem 2232,1;		//�T�[�N���b�g
		else if(.@gamble >= 500 && .@gamble < 600)
			getitem 2216,1;		//�r���^
		else if(.@gamble >= 600 && .@gamble < 700)
			getitem 2230,1;		//�W���G���w����
		else if(.@gamble >= 700 && .@gamble < 800)
			getitem 2224,1;		//�S�[�O��
		else if(.@gamble >= 800 && .@gamble < 900)
			getitem 2222,1;		//�ۂ��ڂ���
		else if(.@gamble >= 900 && .@gamble < 905)
			getitem 2228,1;		//�w����
		else if(.@gamble >= 905 && .@gamble < 910)
			getitem 2252,1;		//�E�B�U�[�h�n�b�g
		else if(.@gamble >= 910 && .@gamble < 915)
			getitem 2227,1;		//�L���b�v[1]
		else if(.@gamble >= 915 && .@gamble < 920)
			getitem 2221,1;		//�n�b�g[1]
		else if(.@gamble >= 920 && .@gamble < 925)
			getitem 2299,1;		//�I�[�N���̃w����
		else if(.@gamble >= 925 && .@gamble < 930)
			getitem 2236,1;		//�T���^�̂ڂ���
		else if(.@gamble >= 930 && .@gamble < 935)
			getitem 2275,1;		//�o���_�i
		else if(.@gamble >= 935 && .@gamble < 940)
			getitem 5015,1;		//�����p���k
		else if(.@gamble >= 940 && .@gamble < 945)
			getitem 2215,1;		//�Ԃ̃w�A�o���h
		else if(.@gamble >= 945 && .@gamble < 950)
			getitem 5092,1;		//�C�����̃��F�[��
		else
			getitem 2226,1;		//�L���b�v
		break;
	case 5:	//�C
		set .@gamble,rand(500);
		if(.@gamble >= 299 && .@gamble < 303) {
			set .@gamble,rand(10);
			switch(.@gamble) {
				case 0:
				case 1: getitem 2406,1; break;	//�u�[�c[1]
				case 2:
				case 3: getitem 2412,1; break;	//�O���[�u[1]
				case 4:
				case 5:
				case 6: getitem 2404,1; break;	//�V���[�Y[1]
				case 7:
				case 8:
				case 9: getitem 2407,1; break;	//�K���X�̌C
			}
		}
		else if(.@gamble >= 0 && .@gamble < 200)
			getitem 2401,1;		//�T���_��
		else if(.@gamble >= 200 && .@gamble < 300)
			getitem 2408,1;		//����
		else if(.@gamble >= 303 && .@gamble < 350)
			getitem 2411,1;		//�O���[�u
		else if(.@gamble >= 350 && .@gamble < 400)
			getitem 2403,1;		//�V���[�Y
		else if(.@gamble >= 400 && .@gamble < 450)
			getitem 2405,1;		//�u�[�c
		else if(.@gamble >= 450 && .@gamble < 475)
			getitem 2409,1;		//�n�C�q�[��
		else
			getitem 2402,1;		//�T���_��[1]
		break;
	case 6:	//��
		set .@gamble,rand(500);
		if(.@gamble >= 200 && .@gamble < 204) {
			set .@gamble,rand(5);
			switch(.@gamble) {
				case 0: getitem 2104,1; break;	//�o�b�N���[[1]
				case 1: getitem 2106,1; break;	//�V�[���h[1]
				case 2: getitem 2102,1; break;	//�K�[�h[1]
				case 3: getitem 2111,1; break;	//�_�̎g��
				case 4: getitem 2109,1; break;	//�������C�Y�u�b�N
			}
		}
		else if(.@gamble >= 0 && .@gamble < 200)
			getitem 2101,1;		//�K�[�h
		else if(.@gamble >= 204 && .@gamble < 300)
			getitem 2103,1;		//�o�b�N���[
		else if(.@gamble >= 300 && .@gamble < 400)
			getitem 2107,1;		//�~���[�V�[���h
		else if(.@gamble >= 400 && .@gamble < 480)
			getitem 2105,1;		//�V�[���h
		else
			getitem 2108,1;		//�~���[�V�[���h[1]
		break;
	}
	delitem 732,1;
	mes "[�J�`���A]";
	mes "�킠�[�A�_�C�������h��";
	mes "�ƂĂ����ꂢ�ł������ˁ[";
	mes "�܂��~������c�c";
	close2;
	cutin "katsua02",255;
	end;
}

comodo,204,148,7	script	�_�r����	90,{
	mes "[�_�r����]";
	mes "�ȑO�A���s�q���J�`���A�o�����";
	mes "�ƂĂ��傫�ȃ_�C�������h��";
	mes "���������Ƃ�����́B";
	mes "���̌�A�o����͂�����";
	mes "����ȕ��Ƀ_�C�������h������";
	mes "�ǂ����߂Ă��ł��B";
	next;
	mes "[�_�r����]";
	mes "�o����͂��Ȃ获���S�������̂Łc�c";
	mes "�_�C�������h����ɓ����ׂȂ�";
	mes "���ł��c�c���������̑�؂�";
	mes "�R���N�V���������������o��";
	mes "����݂����B";
	next;
	mes "[�_�r����]";
	mes "�o����͐̂���R���N�^�[�������́B";
	mes "������������΁A�����ɋC�ɓ���������";
	mes "�����Ă�����B���W�~�ɂƂ����";
	mes "�����������g���ʂ����Ȃ����c�c";
	mes "�ƂĂ����ꂪ�S�z�Ȃ́B";
	close;
}

comodo,210,154,2	script	�������j	118,{
	if(getbaseclass(Class) == CLASS_TF) {
		mes "[�P�C��]";
		mes "�ف`�A���Ǝ҂��B����ȏ��ŉ�����̂�";
		mes "�����̉����B�����̏���������";
		mes "��낤�B�{���Ȃ�����Ƃ�Ƃ��낾���A";
		mes "�����͓��Ǝ҂̂悵�݁A���ʂ�";
		mes "�����ɂ��Ă�낤�B���肪��������H";
		mes "���������ۂ����Ă悭������B";
		next;
		mes "[�P�C��]";
		callsub L_Routine;
		next;
		mes "[�P�C��]";
		mes "���̑��A�����ƒ������A�C�e����";
		mes "�����Ă���炵���B�ǂ����H";
		mes "���ƈꏏ�ɂ��̏삿����";
		mes "�T������ɂ����Ȃ����H";
		next;
		if(select("�ɂ���","�悵�A�ꏏ�ɍs�����I")==1) {
			mes "[�P�C��]";
			mes "�`�F�b�A�ǂ������O������";
			mes "�����V�[�t�o�g�҂���Ȃ����B";
			mes "�����������Ă�񂾁H";
			mes "�c�c��������A����l�ł�����";
			mes "�삿��񂩂畷���o���Ă���B";
			close;
		}
		mes "[�P�C��]";
		mes "�͂͂́B��k����A��k�B";
		mes "����ȁA�^�Ɏ󂯂�Ȃ�B";
		mes "���̌��t�͖Y��Ă���B";
		next;
		mes "[�P�C��]";
		mes "���āA���̏삿��񂪗~�������Ă���";
		mes "�_�C�������h�R�J���b�g��";
		mes "�ǂ��Ŏ�ɓ���̂��A�����c�c";
		mes "���̒��Ԃɂ��ƁA���Ƃ����Ă���";
		mes "�R���̋߂��ɍz�R������炵���B";
		mes "�����łȂ����ł��邩������Ȃ��ȁB";
		next;
		mes "[�P�C��]";
		mes "�_�C�������h�ƈ��������ɁA";
		mes "�삿��񂩂�M�d�ȃA�C�e���𒸂��B";
		mes "�ȁA�����Ȃ��b����H";
		mes "���ꂶ��A�܂��ȁB";
		close;
	}
	else {
		mes "[�P�C��]";
		mes "���傢�Ǝ����ȏ�񂪂���񂾂��c�c";
		mes "�ǂ����H�����Ȃ������H";
		mes "��񗿂Ƃ���500zeny������";
		mes "�����Ă���B";
		next;
		if(select("�킩�����A������","����A��߂Ƃ�")==2) {
			mes "[�P�C��]";
			mes "�`�F�b�A����Ȃ��̂���B";
			mes "���ǂ��������𓾂邽�߂ɂ�";
			mes "�����K�v�Ȃ񂾂�A�����B";
			mes "�����������āA��������";
			mes "�����Ȃ�Ĕn�����Ă邼�B";
			close;
		}
		if(Zeny < 500) {	//������
			mes "[�P�C��]";
			mes "���������A500zeny���Ȃ��̂���c";
			mes "���ꂶ�Ⴀ�������Ȃ����B";
			close;
		}
		set Zeny,Zeny-500;
		mes "[�P�C��]";
		mes "���肪�Ƃ�I";
		mes "�񂶂�A�����Ă��B";
		callsub L_Routine;
		next;
		mes "[�P�C��]";
		mes "���̑��A�����ƒ������A�C�e����";
		mes "�����Ă���炵���B��x����";
		mes "�삿���ɉ���Ă݂�Ƃ�����B";
		next;
		mes "[�P�C��]";
		mes "���āA���̏삿��񂪗~�������Ă���";
		mes "�_�C�������h�R�J���b�g��";
		mes "�ǂ��Ŏ�ɓ���̂��A�����c�c";
		mes "���̒��Ԃɂ��ƁA���Ƃ����Ă���";
		mes "�R���̋߂��ɍz�R������炵���B";
		mes "�����łȂ����ł��邩������Ȃ��ȁB";
		close;
	}
L_Routine:
	mes "�������Ƀ_�C�������h�R�J���b�g��";
	mes "�~�������Ă���삿��񂪂���B";
	mes "�\�ɂ��Ɓc�c�ޏ��͂�������";
	mes "�������������Ă���炵���B";
	next;
	mes "[�P�C��]";
	mes "���ꂪ�A�߂����Ɏ�ɓ���Ȃ�����";
	mes "�����ȕ�����񂳂��Ƃ����Ă��B�O��";
	mes "������ƌ����Ƃ���A�R�r�̊p�̂悤��";
	mes "�������������≤���������Ă�����B";
	return;
}

mjolnir_02,85,362,3	script	�u���b�N�X�~�X	726,{
	emotion 18;
	mes "[�h�E�F�C��]";
	mes "��`���B";
	mes "�Ɓ`���Ă����������̂�";
	mes "���`�����񌩂���������I";
	mes "����͂́`�A�����Ǝv���H";
	mes "�Ȃ�ƁA�_�C�������h�R�J���b�g!!";
	mes "�����ł���`�A����Ŏ�����������I";
	next;
	if(select("�_�C�������h�𔃂������I","���߂łƂ��I")==2) {
		mes "[�h�E�F�C��]";
		mes "���肪�Ƃ��`�I";
		mes "�_�C�������h���K�v�ɂȂ�����";
		mes "���ł������ŁB���ʂɈ���";
		mes "�l�i�Ŕ����Ă������B";
		close;
	}
	mes "[�h�E�F�C��]";
	mes "����!?";
	mes "���l���킩��񂾁`�I";
	mes "���Ⴀ�c�c���ʂɂP��";
	mes "55,000zeny�Ŕ����Ă����悤�I";
	mes "�ǂ��H�@���������ł���B";
	next;
	mes "[�h�E�F�C��]";
	mes "�ǂꂭ�炢�~�����H";
	mes "���`�ł�500�ȉ��ɂ��ĂˁB";
	mes "�������Ă����ĂȂ������B";
	mes "���ꂩ��A�v��Ȃ�����";
	mes "�u0�v���Č����ĂˁB";
	while(1) {
		next;
		input .@num;
		if(.@num <= 0) {
			mes "[�h�E�F�C��]";
			mes "���A����Ȃ��́`�H";
			mes "�c�c����A�܂��ˁI";
			close;
		}
		if(.@num > 500) {
			mes "[�h�E�F�C��]";
			mes "�ނ��`�B";
			mes "500�ȉ��ɂ��Ă��傤�����I";
			continue;
		}
		break;
	}
	set .@price,.@num*55000;
	if(Zeny < .@price) {
		mes "[�h�E�F�C��]";
		mes "�����c�c�����ƁA";
		mes "����������Ȃ��Ɣ���Ȃ���B";
		mes "�������ȏ���������킯�ɂ�";
		mes "�����Ȃ����炳�B";
		close;
	}
	if(checkweight(732,.@num)==0) {
		mes "[�h�E�F�C��]";
		mes "����������ו��ˁc�c";
		mes "���ꂶ�Ⴀ�A�_�C�������h��";
		mes "���ĂȂ��ł���B������Ɖו���";
		mes "���炵�Ă��痈�Ă��傤�����B";
		close;
	}
	set Zeny,Zeny-.@price;
	getitem 732,.@num;
	mes "[�h�E�F�C��]";
	mes "���x����`!!";
	mes "�܂��K�v�ɂȂ����炢�ł����ĂˁI";
	close;
}