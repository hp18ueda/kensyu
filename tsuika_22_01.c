/*======================================================================
  �v���W�F�N�g���FC�����b
  �t�@�C����	�Ftsuika_22_01.c
  �@�\			�F���H
  Copyright(c) 2015 - 2018 emBex Education inc. All Rights Reserved.
======================================================================*/
#include	<stdio.h>
#include	<time.h>
#include	<stdlib.h>

/*�����ǂ��̔���p */
#define		ROAD	0	/*�� */
#define		WALL	1	/*�� */

#define		FIELD	13

/*�����@�邽�߂̔���p:�����_���łǂ��ɐi�ނ����߂� */
#define		UP		0	/*�� */
#define		RIGHT	1	/*�E */
#define		UNDER	2	/*�� */
#define		LEFT	3	/*�� */

/*======================================================================
	�֐���			�Fmain
	�@�\			�F���C������
	���͈�������	�F�Ȃ�
	�߂�l			�F�I�����i���0�j
	���L����		�F�Ȃ�
======================================================================*/
int main(void)
{
    int		i, j, k;
    int		field[FIELD][FIELD];
	
    for(i = 0; i < FIELD; i++)
    {
        for(j = 0; j < FIELD; j++)
        {
        	/*�������B */
        	/*�ŊO����ǂɂ��܂� */
        	if(i == 0 || i == FIELD - 1 || j == 0 || j == FIELD - 1) {
            	field[i][j] = WALL;
        	} else if(i % 2 == 0 && j % 2 == 0) {
        		/*�i����,�����j�̍��W��ǂɂ��܂� */
                field[i][j] = WALL;
            } else {
            	/*�S���𓹂ɂ��܂� */
            	field[i][j] = ROAD;
            }
        }
    }
	
	field[0][1] = ROAD; /* ���� */
	field[FIELD - 1][FIELD - 2] = ROAD; /* �o�� */
    
	/*--- �_�|������ START ---------------------------- */
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
	/*--- �_�|������ END ------------------------------ */
    
    /*�\�� */
    for(i = 0; i < FIELD; i++)
    {
        for(j = 0; j < FIELD; j++)
        {
            if(field[i][j] == WALL)
            {
                printf("��");
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
