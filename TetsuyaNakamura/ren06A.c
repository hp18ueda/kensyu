/*==========================================================
Project	: Test Project
File	: ren06.c
Function: �������z��̈�����
Revision: 1.00	2018/4/26	T.Nakamura	Create
Copyright(c) 2018 Tetsuya Nakamura All rights reserved
==========================================================*/
#include <stdio.h>

#define ELE 16

int main(void);

/*==========================================================
Func Name	: main
Function	: Main Function
Param Input	: None
Param Output: None
return val	: 0:����I��
Input Inf	: None
Output Inf	: None
Note		: None
Revision	: 1.00	2018/4/26	T.Nakamura	Create
==========================================================*/

int main(void)
{
	/*	�ϐ���`	*/
	int i;
	int j;
	char tmp;
	unsigned short pict[ELE] = {
		0x3c, 
		0x42, 
		0xa5, 
		0xa5, 
		0x81, 
		0x99, 
		0x42, 
		0x3c
	};
	
	/*	�C���[�W�̕\��	*/
	for (i = 0; i < ELE; i++) {
		tmp = pict[i];
		for (j = 0; j < ELE; j++) {
			if ((tmp & 0x80) > 0) {
				printf("*");
			} else {
				printf(" ");
			}
			tmp = tmp << 1;
		}
		printf("\n");
	}
	
	return 0;
}

