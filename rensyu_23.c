/*======================================================================
  �v���W�F�N�g���FC�����b
  �t�@�C����	�Frensyu_23.c
  �@�\			�F�v���v���Z�b�T����
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
/* �w�b�_�t�@�C���ǂݍ��� */
#include	<stdio.h>

/* ��` */
#define		DEF_A
#define		DEF_B
#define		BOOL	0

/*======================================================================
	�֐���			�Fmain
	�@�\			�F���C������
	���͈�������	�F�Ȃ�
	�߂�l			�F�I�����i���0�j
	���L����		�F�Ȃ�
======================================================================*/
int main(void)
{
	/* #ifdef�`#endif */
#ifdef DEF_A
	printf("�@IFDEF\n");
#else
	printf("�AIFDEF_ELSE\n");
#endif
	
	/* #ifndef�`#endif */
#ifndef DEF_B
	printf("�BIFNDEF\n");
#else
	printf("�CIFNDEF_ELSE\n");
#endif
	
	/* #if�`#endif */
#if BOOL
	printf("�DIF\n");
#else
	printf("�EIF_ELSE\n");
#endif
	
	return 0;
}
