/*======================================================================
  �v���W�F�N�g���FC�����b
  �t�@�C����	�Ftsuika_10.c
  �@�\			�Fif -else-
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
/* �w�b�_�t�@�C���ǂݍ��� */
#include	<stdio.h>

/*======================================================================
	�֐���			�Fmain
	�@�\			�F���C������
	���͈�������	�F�Ȃ�
	�߂�l			�F�I�����i���0�j
	���L����		�F�Ȃ�
======================================================================*/
int main(void)
{
	/* �ϐ���` */
	int		in[20];				/* ���[�U���̓f�[�^ */
	int		i;					/* ���[�v�p�ϐ� */
	int		tCount, fCount;		/* True�AFalse�J�E���g */
	int		tPer, fPer;			/* True�AFalse�m�� */
	
	/* �ϐ������� */
	tCount = 0;
	fCount = 0;
	
	/* ���[�U���͂Ɛ��۔���A���ۉ񐔃J�E���g */
	for (i = 0; i < 20; i++) {
		printf("%d 100�ȏ�̐�������͂��Ă������� >", i);
		scanf("%d", &in[i]);
		
		if (in[i] >= 100) {
			printf("true\n");
			tCount++;
		} else {
			printf("false\n");
			fCount++;
		}
	}
	
	/* ���ۊm���Z�o */
	tPer = (tCount * 100) / 20;
	fPer = (fCount * 100) / 20;
	
	/* ���ʏo�� */
	printf("true %d��, %d%%\n",  tCount, tPer);
	printf("false %d��, %d%%\n", fCount, fPer);

	return 0;
}
