/*======================================================================
  プロジェクト名：C言語基礎
  ファイル名	：tsuika_22_01.c
  機能			：迷路
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
#include	<stdio.h>
#include	<time.h>
#include	<stdlib.h>

/*道か壁かの判定用 */
#define		ROAD	0	/*道 */
#define		WALL	1	/*壁 */

#define		FIELD	13

/*穴を掘るための判定用:ランダムでどこに進むか決める */
#define		UP		0	/*上 */
#define		RIGHT	1	/*右 */
#define		UNDER	2	/*下 */
#define		LEFT	3	/*左 */

/*======================================================================
	関数名			：main
	機能			：メイン処理
	入力引数説明	：なし
	戻り値			：終了情報（常に0）
	特記事項		：なし
======================================================================*/
int main(void)
{
    int		i, j, k;
    int		field[FIELD][FIELD];
	
    for(i = 0; i < FIELD; i++)
    {
        for(j = 0; j < FIELD; j++)
        {
        	/*初期化。 */
        	/*最外周を壁にします */
        	if(i == 0 || i == FIELD - 1 || j == 0 || j == FIELD - 1) {
            	field[i][j] = WALL;
        	} else if(i % 2 == 0 && j % 2 == 0) {
        		/*（偶数,偶数）の座標を壁にします */
                field[i][j] = WALL;
            } else {
            	/*全部を道にします */
            	field[i][j] = ROAD;
            }
        }
    }
	
	field[0][1] = ROAD; /* 入口 */
	field[FIELD - 1][FIELD - 2] = ROAD; /* 出口 */
    
	/*--- 棒倒し処理 START ---------------------------- */
    srand((unsigned)time(NULL));
    for(i = 2; i < FIELD-2; i+=2)
    {
        for(j = 2; j < FIELD-2; j+=2)
        {
            if(i == 2)
            {
                k = rand() % 4;
                switch(k)
                {
                    case UP:
                        field[i - 1][j] = WALL;
                        break;
                    case RIGHT:
                        field[i][j + 1] = WALL;
                        break;
                    case UNDER:
                        field[i + 1][j] = WALL;
                        break;
                    default:
                        field[i][j - 1] = WALL;
                        break;
                }
            }
            else{
                k = rand() % 3;
                switch(k)
                {
                    case UP:
                        field[i][j + 1] = WALL;
                        break;
                    case RIGHT:
                        field[i + 1][j] = WALL;
                        break;
                    default:
                        field[i][j - 1] = WALL;
                        break;
                }
            }
        }
    }
	/*--- 棒倒し処理 END ------------------------------ */
    
    /*表示 */
    for(i = 0; i < FIELD; i++)
    {
        for(j = 0; j < FIELD; j++)
        {
            if(field[i][j] == WALL)
            {
                printf("■");
            }
            if(field[i][j] == ROAD)
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
