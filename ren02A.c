/*==========================================================
Project	: Test Project
File	: ren02.c
Function: ファイル作成、文字の書き込み
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
	/*	変数定義	*/
	FILE *stream;
	int i = 0;
	char name[60] = {0};
	char ary[512] = {0};
	
	/*	ファイル名入力	*/
	printf("Please Put File Name > ");
	if (fgets(name, 60, stdin) == NULL) {
		printf("Input Error.\n");
	}
	
	/*	ファイル名から改行コードを除外	*/
	while (name[i] != '\0' && i < 60) {
		if (name[i] == '\n') {
			name[i] = '\0';
		}
			i++;
	}
	
	/*	ファイルオープン	*/
	stream = fopen(name, "w");
	
	/*	エラー判定とファイルに文字列を書き込み	*/
	if (stream == NULL) {
		printf("File Open Error.\n");
	} else {
		/*	ファイルの内容を入力	*/
		printf("Please Put Strings > ");
		if (fgets(ary, 512, stdin) == NULL) {
			printf("Input Error.\n");
		}
		
		/*	文字列書き込み	*/
		if (fputs(ary, stream) == EOF) {
			printf("File Write Error.\n");
		} else {
			fclose(stream);
		}
	}
	
	return 0;
}

