/*======================================================================
	プロジェクト名	：C言語プログラミング
	ファイル名		：myself.c
	機能			：
	修正履歴		：2018/4/26 小俣大河
======================================================================*/

/*======================================================================
	出力結果：
	my name is 小俣大河.
	I was born in 1995. So, my age is 23.
	
	自身の生年と現在の年をサンプルファイルに代わりに入れた。
	結果、自身の年齢が算出された。
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

