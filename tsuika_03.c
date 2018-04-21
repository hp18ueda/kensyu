/*======================================================================
  プロジェクト名：C言語基礎
  ファイル名	：tsuika_03.c
  機能			：変数データの取り扱い
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
/* ヘッダファイル読み込み */
#include	<stdio.h>

/*======================================================================
	関数名			：main
	機能			：メイン処理
	入力引数説明	：なし
	戻り値			：終了情報（常に0）
	特記事項		：なし
======================================================================*/
int main(void)
{
	/* 変数定義 */
	char	moji;		/* ユーザ入力変数 */
	
	/* ユーザ入力 */
	printf("1文字入力してください：");
	scanf("%c", &moji);
	
	/* 表示 */
	printf("mojiの値　　　　：%x\n", moji);
	printf("mojiの文字データ：%c\n", moji);
	
	/* 結果return */
	return 0;
}
