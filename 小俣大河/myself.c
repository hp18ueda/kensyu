/*======================================================================
	�v���W�F�N�g��	�FC����v���O���~���O
	�t�@�C����		�Fmyself.c
	�@�\			�F
	�C������		�F2018/4/26 �������
======================================================================*/

/*======================================================================
	�o�͌��ʁF
	my name is �������.
	I was born in 1995. So, my age is 23.
	
	���g�̐��N�ƌ��݂̔N���T���v���t�@�C���ɑ���ɓ��ꂽ�B
	���ʁA���g�̔N��Z�o���ꂽ�B
======================================================================*/

#include <stdio.h>

#define YEARBORN 1995
extern int myage( int );
extern char *myname( void );

main()
{	printf( "my name is %s.\n", myname());
	printf( "I was born in %d. So, my age is %d.\n",
					YEARBORN,	myage( YEARBORN ));
}

