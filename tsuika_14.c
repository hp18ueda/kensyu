/*======================================================================
  �v���W�F�N�g���FC�����b
  �t�@�C����	�Ftsuika_14.c
  �@�\			�F���R���ߖ��
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
/* �w�b�_�t�@�C���ǂݍ��� */
#include	<stdio.h>

/* �萔��` */
#define		NUM_ARR	300		/*����v�f�̏���l */

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
	long	idata1=1;		/* ���[�U�f�[�^1 	*/
	long	idata2=1;		/* ���[�U�f�[�^2 	*/
	long	Addition=0;	/* ���Z����			*/
	long	Answer=0;		/* ���v����			*/
	
	printf("%d,%d",idata1,idata2) ;	/*�ŏ��̂Q�̐�������ʕ\�� */
	Answer = idata1 +idata2 ;		/*�ŏ��̂Q�̐��������Z */

	/* ���Z���[�v */
	while (1) {
		Addition = idata1+idata2;	/*1�ڂƂQ�ڂ̐��l�����Z */

		/* �I������ */
		if(NUM_ARR < Addition){		/*���Z����=����v�f�̏��+1���H */
			printf("\n");			/*���s���� */
			/* ���ʕ\�� */
			printf("���v�F%d\n",Answer);
			return 0;
		}

		printf(",%d",Addition);
		Answer = Answer + Addition;	/*���Z���ʂ����߂�B */
		idata1 = idata2 ;			/*�l�V�t�g */
		idata2 = Addition;			/*�l�V�t�g */
	}
}
