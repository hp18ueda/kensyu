/*==========================================================
Project	: Test Project
File	: ren02.c
Function: �t�@�C���쐬�A�����̏�������
Revision: 1.00	2018/4/26	T.Nakamura	Create
Copyright(c) 2018 Tetsuya Nakamura All rights reserved
==========================================================*/
#include <stdio.h>

int main(void);

/*==========================================================
Func Name	: main
Function	: Main Function
Param Input	: None
Param Output: None
return val	: None
Input Inf	: None
Output Inf	: None
Note		: None
Revision	: 1.00	2018/4/26	T.Nakamura	Create
==========================================================*/

int main(void)
{
	/*	�ϐ���`	*/
	FILE *stream;
	int i = 0;
	char name[60] = {0};
	char ary[512] = {0};
	
	/*	�t�@�C��������	*/
	printf("Please Put File Name > ");
	if (fgets(name, 60, stdin) == NULL) {
		printf("Input Error.\n");
	}
	
	/*	�t�@�C����������s�R�[�h�����O	*/
	while (name[i] != '\0' && i < 60) {
		if (name[i] == '\n') {
			name[i] = '\0';
		}
			i++;
	}
	
	/*	�t�@�C���I�[�v��	*/
	stream = fopen(name, "w");
	
	/*	�G���[����ƃt�@�C���ɕ��������������	*/
	if (stream == NULL) {
		printf("File Open Error.\n");
	} else {
		/*	�t�@�C���̓��e�����	*/
		printf("Please Put Strings > ");
		if (fgets(ary, 512, stdin) == NULL) {
			printf("Input Error.\n");
		}
		
		/*	�����񏑂�����	*/
		if (fputs(ary, stream) == EOF) {
			printf("File Write Error.\n");
		} else {
			fclose(stream);
		}
	}
	
	return 0;
}

