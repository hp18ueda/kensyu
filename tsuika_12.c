/*======================================================================
  �v���W�F�N�g���FC�����b
  �t�@�C����	�Ftsuika_12.c
  �@�\			�F�\����
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
/* �w�b�_�t�@�C���ǂݍ��� */
#include	<stdio.h>
#include	<string.h>

/* �萔��` */
#define		NUM_EMP	10	/* �l�� */

/* �\���̐錾 */
struct ST_EMPLOYEE {
	int		id;
	char	name[64];
	int		age;
	int		length;
	int		weight;
};

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
	struct	ST_EMPLOYEE st_member[NUM_EMP];		/* �\���̃����o�f�[�^ */
	int		i;									/* ���[�v�p�ϐ� */
	
	/* ���[�U���� */
	for (i = 0; i < NUM_EMP; i++) {
		printf("ID�ԍ�����͂��Ă��������F");
		scanf("%d", &st_member[i].id);
		printf("���O����͂��Ă��������F");
		scanf("%s", &st_member[i].name);
		printf("�N�����͂��Ă��������F");
		scanf("%d", &st_member[i].age);
		printf("�g������͂��Ă��������F");
		scanf("%d", &st_member[i].length);
		printf("�̏d����͂��Ă��������F");
		scanf("%d", &st_member[i].weight);
		printf("\n");
	}
	printf("\n");
	printf("�f�[�^�͍\���̂֊i�[����܂����I\n");
	printf("\n");
	
	/* ���ʏo�� */
	for(i = 0; i < NUM_EMP; i++) {
		printf(" ID�@�F%d", st_member[i].id);
		printf(" ���O�F%s", st_member[i].name);
		printf(" �N��F%d", st_member[i].age);
		printf(" �g���F%d", st_member[i].length);
		printf(" �̏d�F%d", st_member[i].weight);
		printf(" \n");
	}
	
	return 0;
}
