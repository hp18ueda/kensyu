/*======================================================================
  プロジェクト名：C言語基礎
  ファイル名	：tsuika_21.c
  機能			：石取りゲーム
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
/* ヘッダファイル読み込み */
#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

/* 定数定義 */
#define		MIN_STONE	2		/* 石の全体数の最小値 */
#define		MAX_STONE	1000	/* 石の全体数の最大値 */
#define		MIN_GET		1		/* 取る石の数の最小値 */
#define		MAX_BUF		255		/* 配列の要素数       */
#define		TURN_PLAYER	0		/* プレイヤーのターン */
#define		TURN_CPU	1		/* CPUのターン        */
#define		ERROR_VALUE	-1		/* 不正値             */

/* 関数プロトタイプ宣言 */
void setGameRule(int *allStone, int *maxGet, char *turnFlag);
int  getStoneByPlayer(int restStone, int maxGet);
int  getStoneByCpu(int restStone, int maxGet);
int  getRandomNumber(int maxGet);
int  getInputValue(void);

/*======================================================================
	関数名			：main
	機能			：メイン処理
	入力引数説明	：なし
	出力引数説明	：なし
	戻り値			：終了情報（常に0）
	特記事項		：なし
	修正履歴		：1.00	2012/3/29	辻 徹平	作成
======================================================================*/
int main(void)
{
	/* 変数定義 */
	int		allStone;	/* 石の全体数                          */
	int		maxGet;		/* 取る石の数の最大値                  */
	int		restStone;	/* 残りの石の数                        */
	int		getStone;	/* 取る石の数                          */
	char	turnFlag;	/* 0:プレイヤーのターン  1:CPUのターン */

	/* 初期化処理 */
	restStone = 0;
	turnFlag = 0;
	
	/* 乱数初期設定 */
	srand((unsigned int)time(NULL));
	
	/* ゲームのルール設定 */
	setGameRule(&allStone, &maxGet, &turnFlag);
	
	/* 残りの石の数を更新 */
	restStone = allStone;

	/* 石取りループ */
	while (1) {
		/* プレイヤーのターン */
		if (turnFlag == TURN_PLAYER) {
			/* プレイヤーが取る石の数を決める */
			getStone = getStoneByPlayer(restStone, maxGet);
		}
		/* CPUのターン */
		else {
			/* CPUが取る石の数を決める */
			getStone = getStoneByCpu(restStone, maxGet);
		}
		/* 残りの石の数を更新 */
		restStone = restStone - getStone;
		
		/* 残りの石の数が取る石の数の最大値より小さくなった場合 */
		if (restStone < maxGet) {
			/* 取る石の数の最大値を残りの石の数に更新 */
			maxGet = restStone;
		}
		/* 残りの石の数が1ならターン交代して石取りループを抜ける */
		if (restStone == 1) {
			printf("1個の石が残りました!!\n");
			turnFlag = turnFlag ^ 1;
			break;
		}
		/* 間違って全部取ってしまった場合は負け(プレイヤーしかありえない) */
		else if (restStone == 0) {
			printf("全部取ったら負けですよ!!\n");
			break;
		}
		/* 石取り続行 */
		else {
			
		}
		/* ターン交代 */
		turnFlag = turnFlag ^ 1;
	}
	/* 最後に石を取ったのがプレイヤーの場合は負け */
	if (turnFlag == TURN_PLAYER) {
		printf("YOU LOSE!!\n");
	}
	/* 最後に石を取ったのがCPUの場合は勝ち */
	else {
		printf("YOU WIN!!\n");
	}
	
	return 0;
}

/*======================================================================
	関数名			：setGameRule
	機能			：先攻後攻、石の全体数、最大取得数の設定処理
	入力引数説明	：int *pAllStone  : 石の全体数のアドレス
					：int *pMaxGet    : 最大取得数のアドレス
					：char *turnFlag  : 先攻後攻のアドレス
	出力引数説明	：なし
	戻り値			：なし
	特記事項		：石の全体数は2～1000とした。(1だとゲームにならない)
					：最大取得数は2～石の全体数
	修正履歴		：1.00	2012/3/29	辻 徹平	作成
======================================================================*/
void setGameRule(int *pAllStone, int *pMaxGet, char *pTurnFlag)
{
	/* 石の全体数設定ループ */
	while (1) {
		printf("\n石の全体数を設定して下さい。(%d～%d) : ", MIN_STONE, MAX_STONE);
		
		/* 入力値取得 */
		*pAllStone = getInputValue();
		
		/* 2～1000の場合は設定OK ループを抜ける */
		if ((*pAllStone >= MIN_STONE) && (*pAllStone <= MAX_STONE)) {
			break;
		}
		/* エラーメッセージ出力 */
		else {
			printf("%d～%dの範囲で設定して下さい。\n", MIN_STONE, MAX_STONE);
		}
	}
	/* 最大取得数設定ループ */
	while (1) {
		printf("最大取得数を設定して下さい。(%d～%d) : ", MIN_STONE, *pAllStone);

		/* 入力値取得 */
		*pMaxGet = getInputValue();
	
		/* 2～石の全体数の場合は設定OK ループを抜ける */
		if ((*pMaxGet >= MIN_STONE) && (*pMaxGet <= *pAllStone)) {
			break;
		}
		/* エラーメッセージ出力 */
		else {
			printf("%d～%dの範囲で設定して下さい。\n", MIN_STONE, *pAllStone);
		}
	}
	/* 先攻後攻設定ループ */
	while (1) {
		printf("先攻後攻を入力して下さい。(%d:先攻 %d:後攻) : ", TURN_PLAYER, TURN_CPU);
		
		/* 入力値取得 */
		*pTurnFlag = (char)getInputValue();

		/* 0:先攻、または、1:後攻の場合は設定OK ループを抜ける */
		if ((*pTurnFlag == TURN_PLAYER) || (*pTurnFlag == TURN_CPU)) {
			break;
		}
		/* エラーメッセージ出力 */
		else {
			printf("%d:先攻 %d:後攻のいずれかで入力して下さい。\n", TURN_PLAYER, TURN_CPU);
		}
	}	
	printf("\n");
	
	return;
}

/*======================================================================
	関数名			：getStoneByPlayer
	機能			：プレイヤーの取る石の数決定処理
	入力引数説明	：int restStone : 残りの石の数
					：int maxGet    : 最大取得数
	出力引数説明	：なし
	戻り値			：取る石の数
	特記事項		：取る石の数は1～最大取得数
	修正履歴		：1.00	2012/3/29	辻 徹平	作成
======================================================================*/
int  getStoneByPlayer(int restStone, int maxGet)
{
	/* 変数定義 */
	int		getStone;	/* 取る石の数 */
	
	printf("あなたのターンです。\n");
	
	/* 取る石の数入力ループ */
	while (1) {
		printf("残りの石の数は%d個です。\n", restStone);
		printf("いくつの石を取りますか？(%d～%d) : ", MIN_GET, maxGet);
		
		/* 入力値取得 */
		getStone = getInputValue();
	
		/* 1～最大取得数の場合は入力OK ループを抜ける */
		if ((getStone >= MIN_GET) && (getStone <= maxGet)) {
			break;
		}
		/* エラーメッセージ出力 */
		else {
			printf("%d～%dの範囲で入力して下さい。\n", MIN_GET, maxGet);
		}
	}
	printf("\n");
	
	/* 取る石の数を返却 */
	return getStone;
}

/*======================================================================
	関数名			：getStoneByCpu
	機能			：CPUの取る石の数決定処理
	入力引数説明	：int restStone : 残りの石の数
					：int maxGet    : 最大取得数
	出力引数説明	：なし
	戻り値			：取る石の数
	特記事項		：取る石の数は1～最大取得数
					：■必勝の手とは
					：残りの石の数を(最大取得数 + 1)で割った余りが1の
					：状態で、相手にターンを渡すことである。
					：たとえば、最大取得数が3の場合、残りの石の数が
					：1,5,9,13,17,・・・で相手に渡すことで必勝の手となる。
	修正履歴		：1.00	2012/3/29	辻 徹平	作成
======================================================================*/
int  getStoneByCpu(int restStone, int maxGet)
{
	/* 変数定義 */
	int		getStone;	/* 取る石の数 */
	
	printf("CPUのターンです。\n");
	printf("残りの石の数は%d個です。\n", restStone);

	/* プレイヤーが必勝の手 */
	if (restStone % (maxGet + 1) == 1) {
		/* ランダム数取得 */
		getStone = getRandomNumber(maxGet);
	}
	/* CPUが必勝の手をうつ */
	else {
		if (restStone % (maxGet + 1) == 0) {
			getStone = maxGet;
		}
		else {
			getStone = (restStone % (maxGet + 1)) - 1;
		}
	}
	printf("CPUは%d個の石を取りました。\n", getStone);
	printf("\n");

	/* 取る石の数を返却 */
	return getStone;
}

/*======================================================================
	関数名			：getRandomNumber
	機能			：CPUの取る石のランダム数取得処理
	入力引数説明	：int maxGet : 最大取得数
	出力引数説明	：なし
	戻り値			：ランダム数
	特記事項		：なし
	修正履歴		：1.00	2012/3/29	辻 徹平	作成
======================================================================*/
int getRandomNumber(int maxGet)
{
	/* 変数定義 */
	int		randomNumber;	/* ランダム数 */
	
	/* ランダム数算出 */
	randomNumber = (rand() % maxGet) + 1;
	
	/* ランダム数返却 */
	return randomNumber;
}

/*======================================================================
	関数名			：getInputValue
	機能			：入力値取得処理
	入力引数説明	：なし
	出力引数説明	：なし
	戻り値			：入力値(-1:不正)
	特記事項		：なし
	修正履歴		：1.00	2012/3/29	辻 徹平	作成
======================================================================*/
int  getInputValue(void)
{
	/* 変数定義 */
	int		inputVaule;				/* 入力値                 */
	char	buff[MAX_BUF] = {0};	/* 入力文字列格納用       */
	char	*pBuff;				/* 入力文字列先頭アドレス */

	pBuff = &buff[0];
	
	/* 標準入力から文字列取得 */
	if (fgets(pBuff, MAX_BUF, stdin) != NULL) {
		/* 入力文字列を数値に変換 */
		inputVaule = atoi(buff);

		/* 入力文字列が数字列かどうかのチェックループ */
		while (*pBuff != '\n') {
			/* 数字以外が含まれている場合は入力値に不正値を設定しループを抜ける */
			if (isdigit(*pBuff) == 0) {
				inputVaule = ERROR_VALUE;
				break;
			}
			pBuff++;
		}
		/* いきなり改行が入力された場合は入力値に不正値を設定 */
		if (buff[0] == '\n') {
			inputVaule = ERROR_VALUE;
		}
		else {
			
		}
	}
	else {
		inputVaule = ERROR_VALUE;
	}
	/* 入力値を返却 */
	return inputVaule;
}

