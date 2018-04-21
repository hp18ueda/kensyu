/*======================================================================
  プロジェクト名：C言語基礎
  ファイル名	：tsuika_10.c
  機能			：if -else-
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
	int		in[20];				/* ユーザ入力データ */
	int		i;					/* ループ用変数 */
	int		tCount, fCount;		/* True、Falseカウント */
	int		tPer, fPer;			/* True、False確率 */
	
	/* 変数初期化 */
	tCount = 0;
	fCount = 0;
	
	/* ユーザ入力と正否判定、正否回数カウント */
	for (i = 0; i < 20; i++) {
		printf("%d 100以上の整数を入力してください >", i);
		scanf("%d", &in[i]);
		
		if (in[i] >= 100) {
			printf("true\n");
			tCount++;
		} else {
			printf("false\n");
			fCount++;
		}
	}
	
	/* 正否確率算出 */
	tPer = (tCount * 100) / 20;
	fPer = (fCount * 100) / 20;
	
	/* 結果出力 */
	printf("true %d回, %d%%\n",  tCount, tPer);
	printf("false %d回, %d%%\n", fCount, fPer);

	return 0;
}
