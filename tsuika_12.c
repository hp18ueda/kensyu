/*======================================================================
  プロジェクト名：C言語基礎
  ファイル名	：tsuika_12.c
  機能			：構造体
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
/* ヘッダファイル読み込み */
#include	<stdio.h>
#include	<string.h>

/* 定数定義 */
#define		NUM_EMP	10	/* 人数 */

/* 構造体宣言 */
struct ST_EMPLOYEE {
	int		id;
	char	name[64];
	int		age;
	int		length;
	int		weight;
};

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
	struct	ST_EMPLOYEE st_member[NUM_EMP];		/* 構造体メンバデータ */
	int		i;									/* ループ用変数 */
	
	/* ユーザ入力 */
	for (i = 0; i < NUM_EMP; i++) {
		printf("ID番号を入力してください：");
		scanf("%d", &st_member[i].id);
		printf("名前を入力してください：");
		scanf("%s", &st_member[i].name);
		printf("年齢を入力してください：");
		scanf("%d", &st_member[i].age);
		printf("身長を入力してください：");
		scanf("%d", &st_member[i].length);
		printf("体重を入力してください：");
		scanf("%d", &st_member[i].weight);
		printf("\n");
	}
	printf("\n");
	printf("データは構造体へ格納されました！\n");
	printf("\n");
	
	/* 結果出力 */
	for(i = 0; i < NUM_EMP; i++) {
		printf(" ID　：%d", st_member[i].id);
		printf(" 名前：%s", st_member[i].name);
		printf(" 年齢：%d", st_member[i].age);
		printf(" 身長：%d", st_member[i].length);
		printf(" 体重：%d", st_member[i].weight);
		printf(" \n");
	}
	
	return 0;
}
