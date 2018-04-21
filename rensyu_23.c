/*======================================================================
  プロジェクト名：C言語基礎
  ファイル名	：rensyu_23.c
  機能			：プリプロセッサ命令
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
/* ヘッダファイル読み込み */
#include	<stdio.h>

/* 定義 */
#define		DEF_A
#define		DEF_B
#define		BOOL	0

/*======================================================================
	関数名			：main
	機能			：メイン処理
	入力引数説明	：なし
	戻り値			：終了情報（常に0）
	特記事項		：なし
======================================================================*/
int main(void)
{
	/* #ifdef〜#endif */
#ifdef DEF_A
	printf("�@IFDEF\n");
#else
	printf("�AIFDEF_ELSE\n");
#endif
	
	/* #ifndef〜#endif */
#ifndef DEF_B
	printf("�BIFNDEF\n");
#else
	printf("�CIFNDEF_ELSE\n");
#endif
	
	/* #if〜#endif */
#if BOOL
	printf("�DIF\n");
#else
	printf("�EIF_ELSE\n");
#endif
	
	return 0;
}
