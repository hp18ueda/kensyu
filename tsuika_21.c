/*======================================================================
  �v���W�F�N�g���FC�����b
  �t�@�C����	�Ftsuika_21.c
  �@�\			�F�Ύ��Q�[��
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
/* �w�b�_�t�@�C���ǂݍ��� */
#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

/* �萔��` */
#define		MIN_STONE	2		/* �΂̑S�̐��̍ŏ��l */
#define		MAX_STONE	1000	/* �΂̑S�̐��̍ő�l */
#define		MIN_GET		1		/* ���΂̐��̍ŏ��l */
#define		MAX_BUF		255		/* �z��̗v�f��       */
#define		TURN_PLAYER	0		/* �v���C���[�̃^�[�� */
#define		TURN_CPU	1		/* CPU�̃^�[��        */
#define		ERROR_VALUE	-1		/* �s���l             */

/* �֐��v���g�^�C�v�錾 */
void setGameRule(int *allStone, int *maxGet, char *turnFlag);
int  getStoneByPlayer(int restStone, int maxGet);
int  getStoneByCpu(int restStone, int maxGet);
int  getRandomNumber(int maxGet);
int  getInputValue(void);

/*======================================================================
	�֐���			�Fmain
	�@�\			�F���C������
	���͈�������	�F�Ȃ�
	�o�͈�������	�F�Ȃ�
	�߂�l			�F�I�����i���0�j
	���L����		�F�Ȃ�
	�C������		�F1.00	2012/3/29	�� �O��	�쐬
======================================================================*/
int main(void)
{
	/* �ϐ���` */
	int		allStone;	/* �΂̑S�̐�                          */
	int		maxGet;		/* ���΂̐��̍ő�l                  */
	int		restStone;	/* �c��̐΂̐�                        */
	int		getStone;	/* ���΂̐�                          */
	char	turnFlag;	/* 0:�v���C���[�̃^�[��  1:CPU�̃^�[�� */

	/* ���������� */
	restStone = 0;
	turnFlag = 0;
	
	/* ���������ݒ� */
	srand((unsigned int)time(NULL));
	
	/* �Q�[���̃��[���ݒ� */
	setGameRule(&allStone, &maxGet, &turnFlag);
	
	/* �c��̐΂̐����X�V */
	restStone = allStone;

	/* �Ύ�胋�[�v */
	while (1) {
		/* �v���C���[�̃^�[�� */
		if (turnFlag == TURN_PLAYER) {
			/* �v���C���[�����΂̐������߂� */
			getStone = getStoneByPlayer(restStone, maxGet);
		}
		/* CPU�̃^�[�� */
		else {
			/* CPU�����΂̐������߂� */
			getStone = getStoneByCpu(restStone, maxGet);
		}
		/* �c��̐΂̐����X�V */
		restStone = restStone - getStone;
		
		/* �c��̐΂̐������΂̐��̍ő�l��菬�����Ȃ����ꍇ */
		if (restStone < maxGet) {
			/* ���΂̐��̍ő�l���c��̐΂̐��ɍX�V */
			maxGet = restStone;
		}
		/* �c��̐΂̐���1�Ȃ�^�[����サ�ĐΎ�胋�[�v�𔲂��� */
		if (restStone == 1) {
			printf("1�̐΂��c��܂���!!\n");
			turnFlag = turnFlag ^ 1;
			break;
		}
		/* �Ԉ���đS������Ă��܂����ꍇ�͕���(�v���C���[�������肦�Ȃ�) */
		else if (restStone == 0) {
			printf("�S��������畉���ł���!!\n");
			break;
		}
		/* �Ύ�葱�s */
		else {
			
		}
		/* �^�[����� */
		turnFlag = turnFlag ^ 1;
	}
	/* �Ō�ɐ΂�������̂��v���C���[�̏ꍇ�͕��� */
	if (turnFlag == TURN_PLAYER) {
		printf("YOU LOSE!!\n");
	}
	/* �Ō�ɐ΂�������̂�CPU�̏ꍇ�͏��� */
	else {
		printf("YOU WIN!!\n");
	}
	
	return 0;
}

/*======================================================================
	�֐���			�FsetGameRule
	�@�\			�F��U��U�A�΂̑S�̐��A�ő�擾���̐ݒ菈��
	���͈�������	�Fint *pAllStone  : �΂̑S�̐��̃A�h���X
					�Fint *pMaxGet    : �ő�擾���̃A�h���X
					�Fchar *turnFlag  : ��U��U�̃A�h���X
	�o�͈�������	�F�Ȃ�
	�߂�l			�F�Ȃ�
	���L����		�F�΂̑S�̐���2�`1000�Ƃ����B(1���ƃQ�[���ɂȂ�Ȃ�)
					�F�ő�擾����2�`�΂̑S�̐�
	�C������		�F1.00	2012/3/29	�� �O��	�쐬
======================================================================*/
void setGameRule(int *pAllStone, int *pMaxGet, char *pTurnFlag)
{
	/* �΂̑S�̐��ݒ胋�[�v */
	while (1) {
		printf("\n�΂̑S�̐���ݒ肵�ĉ������B(%d�`%d) : ", MIN_STONE, MAX_STONE);
		
		/* ���͒l�擾 */
		*pAllStone = getInputValue();
		
		/* 2�`1000�̏ꍇ�͐ݒ�OK ���[�v�𔲂��� */
		if ((*pAllStone >= MIN_STONE) && (*pAllStone <= MAX_STONE)) {
			break;
		}
		/* �G���[���b�Z�[�W�o�� */
		else {
			printf("%d�`%d�͈̔͂Őݒ肵�ĉ������B\n", MIN_STONE, MAX_STONE);
		}
	}
	/* �ő�擾���ݒ胋�[�v */
	while (1) {
		printf("�ő�擾����ݒ肵�ĉ������B(%d�`%d) : ", MIN_STONE, *pAllStone);

		/* ���͒l�擾 */
		*pMaxGet = getInputValue();
	
		/* 2�`�΂̑S�̐��̏ꍇ�͐ݒ�OK ���[�v�𔲂��� */
		if ((*pMaxGet >= MIN_STONE) && (*pMaxGet <= *pAllStone)) {
			break;
		}
		/* �G���[���b�Z�[�W�o�� */
		else {
			printf("%d�`%d�͈̔͂Őݒ肵�ĉ������B\n", MIN_STONE, *pAllStone);
		}
	}
	/* ��U��U�ݒ胋�[�v */
	while (1) {
		printf("��U��U����͂��ĉ������B(%d:��U %d:��U) : ", TURN_PLAYER, TURN_CPU);
		
		/* ���͒l�擾 */
		*pTurnFlag = (char)getInputValue();

		/* 0:��U�A�܂��́A1:��U�̏ꍇ�͐ݒ�OK ���[�v�𔲂��� */
		if ((*pTurnFlag == TURN_PLAYER) || (*pTurnFlag == TURN_CPU)) {
			break;
		}
		/* �G���[���b�Z�[�W�o�� */
		else {
			printf("%d:��U %d:��U�̂����ꂩ�œ��͂��ĉ������B\n", TURN_PLAYER, TURN_CPU);
		}
	}	
	printf("\n");
	
	return;
}

/*======================================================================
	�֐���			�FgetStoneByPlayer
	�@�\			�F�v���C���[�̎��΂̐����菈��
	���͈�������	�Fint restStone : �c��̐΂̐�
					�Fint maxGet    : �ő�擾��
	�o�͈�������	�F�Ȃ�
	�߂�l			�F���΂̐�
	���L����		�F���΂̐���1�`�ő�擾��
	�C������		�F1.00	2012/3/29	�� �O��	�쐬
======================================================================*/
int  getStoneByPlayer(int restStone, int maxGet)
{
	/* �ϐ���` */
	int		getStone;	/* ���΂̐� */
	
	printf("���Ȃ��̃^�[���ł��B\n");
	
	/* ���΂̐����̓��[�v */
	while (1) {
		printf("�c��̐΂̐���%d�ł��B\n", restStone);
		printf("�����̐΂����܂����H(%d�`%d) : ", MIN_GET, maxGet);
		
		/* ���͒l�擾 */
		getStone = getInputValue();
	
		/* 1�`�ő�擾���̏ꍇ�͓���OK ���[�v�𔲂��� */
		if ((getStone >= MIN_GET) && (getStone <= maxGet)) {
			break;
		}
		/* �G���[���b�Z�[�W�o�� */
		else {
			printf("%d�`%d�͈̔͂œ��͂��ĉ������B\n", MIN_GET, maxGet);
		}
	}
	printf("\n");
	
	/* ���΂̐���ԋp */
	return getStone;
}

/*======================================================================
	�֐���			�FgetStoneByCpu
	�@�\			�FCPU�̎��΂̐����菈��
	���͈�������	�Fint restStone : �c��̐΂̐�
					�Fint maxGet    : �ő�擾��
	�o�͈�������	�F�Ȃ�
	�߂�l			�F���΂̐�
	���L����		�F���΂̐���1�`�ő�擾��
					�F���K���̎�Ƃ�
					�F�c��̐΂̐���(�ő�擾�� + 1)�Ŋ������]�肪1��
					�F��ԂŁA����Ƀ^�[����n�����Ƃł���B
					�F���Ƃ��΁A�ő�擾����3�̏ꍇ�A�c��̐΂̐���
					�F1,5,9,13,17,�E�E�E�ő���ɓn�����ƂŕK���̎�ƂȂ�B
	�C������		�F1.00	2012/3/29	�� �O��	�쐬
======================================================================*/
int  getStoneByCpu(int restStone, int maxGet)
{
	/* �ϐ���` */
	int		getStone;	/* ���΂̐� */
	
	printf("CPU�̃^�[���ł��B\n");
	printf("�c��̐΂̐���%d�ł��B\n", restStone);

	/* �v���C���[���K���̎� */
	if (restStone % (maxGet + 1) == 1) {
		/* �����_�����擾 */
		getStone = getRandomNumber(maxGet);
	}
	/* CPU���K���̎������ */
	else {
		if (restStone % (maxGet + 1) == 0) {
			getStone = maxGet;
		}
		else {
			getStone = (restStone % (maxGet + 1)) - 1;
		}
	}
	printf("CPU��%d�̐΂����܂����B\n", getStone);
	printf("\n");

	/* ���΂̐���ԋp */
	return getStone;
}

/*======================================================================
	�֐���			�FgetRandomNumber
	�@�\			�FCPU�̎��΂̃����_�����擾����
	���͈�������	�Fint maxGet : �ő�擾��
	�o�͈�������	�F�Ȃ�
	�߂�l			�F�����_����
	���L����		�F�Ȃ�
	�C������		�F1.00	2012/3/29	�� �O��	�쐬
======================================================================*/
int getRandomNumber(int maxGet)
{
	/* �ϐ���` */
	int		randomNumber;	/* �����_���� */
	
	/* �����_�����Z�o */
	randomNumber = (rand() % maxGet) + 1;
	
	/* �����_�����ԋp */
	return randomNumber;
}

/*======================================================================
	�֐���			�FgetInputValue
	�@�\			�F���͒l�擾����
	���͈�������	�F�Ȃ�
	�o�͈�������	�F�Ȃ�
	�߂�l			�F���͒l(-1:�s��)
	���L����		�F�Ȃ�
	�C������		�F1.00	2012/3/29	�� �O��	�쐬
======================================================================*/
int  getInputValue(void)
{
	/* �ϐ���` */
	int		inputVaule;				/* ���͒l                 */
	char	buff[MAX_BUF] = {0};	/* ���͕�����i�[�p       */
	char	*pBuff;				/* ���͕�����擪�A�h���X */

	pBuff = &buff[0];
	
	/* �W�����͂��當����擾 */
	if (fgets(pBuff, MAX_BUF, stdin) != NULL) {
		/* ���͕�����𐔒l�ɕϊ� */
		inputVaule = atoi(buff);

		/* ���͕����񂪐����񂩂ǂ����̃`�F�b�N���[�v */
		while (*pBuff != '\n') {
			/* �����ȊO���܂܂�Ă���ꍇ�͓��͒l�ɕs���l��ݒ肵���[�v�𔲂��� */
			if (isdigit(*pBuff) == 0) {
				inputVaule = ERROR_VALUE;
				break;
			}
			pBuff++;
		}
		/* �����Ȃ���s�����͂��ꂽ�ꍇ�͓��͒l�ɕs���l��ݒ� */
		if (buff[0] == '\n') {
			inputVaule = ERROR_VALUE;
		}
		else {
			
		}
	}
	else {
		inputVaule = ERROR_VALUE;
	}
	/* ���͒l��ԋp */
	return inputVaule;
}

