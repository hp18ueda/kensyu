/*======================================================================
  �v���W�F�N�g���FC�����b
  �t�@�C����	�Frensyu_16.c
  �@�\			�F�\����
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
/* �w�b�_�t�@�C���ǂݍ��� */
#include	<stdio.h>
#include	<string.h>

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
	struct ST_EMPLOYEE st_member;	/* �����o�[�f�[�^ */
	
	/* ���[�U���� */
	printf("ID�ԍ�����͂��Ă��������F");
	scanf("%d", &st_member.id);
	printf("���O����͂��Ă��������F");
	scanf("%s", &st_member.name);
	printf("�N�����͂��Ă��������F");
	scanf("%d", &st_member.age);
	printf("�g������͂��Ă��������F");
	scanf("%d", &st_member.length);
	printf("�̏d����͂��Ă��������F");
	scanf("%d", &st_member.weight);
	printf("\n");
	printf("�f�[�^�͍\���̂֊i�[����܂����I\n");
	printf("\n");
	
	/* ���ʏo�� */
	printf("ID�@�F%d\n", st_member.id);
	printf("���O�F%s\n", st_member.name);
	printf("�N��F%d\n", st_member.age);
	printf("�g���F%d\n", st_member.length);
	printf("�̏d�F%d\n", st_member.weight);
	
	return 0;
}
