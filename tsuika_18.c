/*======================================================================
  �v���W�F�N�g���FC�����b
  �t�@�C����	�Ftsuika_18.c
  �@�\			�F�ŏ����{�������߂�v���O����
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
	int		in1;					/* ���͐���1  */
	int		in2;					/* ���͐���2  */
	int		multiplier1 = 1;		/* �搔1	  */
	int		multiplier2 = 1;		/* �搔2	  */
	int		least_common_multiple;	/* �ŏ����{�� */

	/* �Q�̐�������� */
	/* ���[�U���� */
	printf("��ڂ̐�������͂��ĉ������B>");
	scanf("%d", &in1);
	printf("��ڂ̐�������͂��ĉ������B>");
	scanf("%d", &in2);

	/*�������[�v */
	while( 1 ){
		if(in1 * multiplier1 == in2 * multiplier2){		/*�ŏ����{�������H */
			least_common_multiple = in1 * multiplier1;	/*�ŏ����{���l���i�[ */
			/*printf("[2]multiplier1=%d multiplier2=%d \n",multiplier1,multiplier2); */
			break;	/*���[�v�𔲂��� */

		/*���͐����Q�̏�Z���ʂ��傫���ꍇ */
		}else if(in1 * multiplier1 < in2 * multiplier2){
			/*printf("[1]multiplier1=%d multiplier2=%d \n",multiplier1,multiplier2); */
			multiplier1++;	/*�搔1���C���N�������g */
			multiplier2 = 0;/*�搔2�������� */
		}
		multiplier2++;
	}

	printf("%d��%d�̍ŏ����{��:%d\n",in1,in2,least_common_multiple);
	return(0);
}
