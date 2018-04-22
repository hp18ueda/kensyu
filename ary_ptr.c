//
//		配列とポインタ
//		
//		2018/04/20 Ported by H.Nitobe
//
//		うっくつさん本を読む。配列とポインタ
//		http://d.hatena.ne.jp/kilrey/20091011#p1
//		


#include	<stdio.h>

// #define		DEBUG					// 2018/04/22 Add. H.Nitobe
#define		DUMP(FMT,VAL) printf("%-16s = "FMT "\n", #VAL, (VAL))

int main(void)
{
	char ary[] = "abcdef";
	char *ptr = "uvwxyz";

	DUMP("%p", ary);
	DUMP("%p", &ary);
	DUMP("%p", &ary[0]);

	DUMP("%p", ary+1);
	DUMP("%p", &ary+1);
	DUMP("%p", &ary[0]+1);

#ifdef	DEBUG							// 2018/04/22 Add. H.Nitobe
	DUMP("%p", ary = ary+1);			// error: lvalue required
	DUMP("%p", &ary = &ary+1);			// error: lvalue required
	DUMP("%p", &ary[0] = &ary[0]+1);	// error: lvalue required
#endif
	
	DUMP("%d", sizeof(ary));
	DUMP("%d", sizeof(&ary));
	DUMP("%d", sizeof(&ary[0]));

	DUMP("%p", ptr);
	DUMP("%p", &ptr);
	DUMP("%p", &ptr[0]);

	DUMP("%p", ptr+1);
	DUMP("%p", &ptr+1);
	DUMP("%p", &ptr[0]+1);
	
#ifdef	DEBUG							// 2018/04/22 Add. H.Nitobe
	DUMP("%p", ptr = ptr+1);			// ok!
	DUMP("%p", &ptr = &ptr+1);			// error: lvalue required
	DUMP("%p", &ptr[0] = &ptr[0]+1);	// error: lvalue required
#endif
	
	DUMP("%d", sizeof(ptr));
	DUMP("%d", sizeof(&ptr));
	DUMP("%d", sizeof(&ptr[0]));

	return 0;
}

//	実行結果：　Vc7とgccで比較
//																								   cl7/gcc6.3.0
//		ary:		aryの先頭を指すポインタ定数	（書き込み不可）（サイズ:1byte）(sizeof(ary) : 		7 / 7
//		&ary:		aryの先頭を指すポインタ定数	（書き込み不可）（サイズ:7byte）(sizeof(&ary) : 	7 / 4)
//		&ary[0]:	aryの先頭を指すポインタ定数	（書き込み不可）（サイズ:1byte）(sizeof(&ary[0]) :	4 / 4)
//		ptr:		ptrの先頭を指すポインタ変数	（書き込み可）　（サイズ:1byte）(sizeof(ptr) : 		4 / 4)
//		&ptr:		ptrの先頭を指すポインタ変数を指すポインタ定数
//							 					（書き込み不可）（サイズ:4byte）(sizeof(&ptr) : 	4 / 4)
//		&ptr[0]:	ptrの先頭を指すポインタ定数	（書き込み不可）（サイズ:1byte）(sizeof(&ptr[0]) : 	4 / 4)
//
//		2018/04/04/22	Played by H.Nitobe
	
	
#if	0
c:\vc7>cl /Wall /FA ary_ptr.c
Microsoft(R) 32-bit C/C++ Standard Compiler Version 13.00.9466 for 80x86
Copyright (C) Microsoft Corporation 1984-2001. All rights reserved.

ary_ptr.c
Microsoft (R) Incremental Linker Version 7.00.9466
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:ary_ptr.exe
ary_ptr.obj

c:\vc7>ary_ptr
ary              = 0019FE98
&ary             = 0019FE98
&ary[0]          = 0019FE98
ary+1            = 0019FE99
&ary+1           = 0019FE9F
&ary[0]+1        = 0019FE99
sizeof(ary)      = 7
sizeof(&ary)     = 7
sizeof(&ary[0])  = 4
ptr              = 00408048
&ptr             = 0019FEA0
&ptr[0]          = 00408048
ptr+1            = 00408049
&ptr+1           = 0019FEA4
&ptr[0]+1        = 00408049
sizeof(ptr)      = 4
sizeof(&ptr)     = 4
sizeof(&ptr[0])  = 4

c:\vc7>a.exe
ary              = 0061FF29
&ary             = 0061FF29
&ary[0]          = 0061FF29
ary+1            = 0061FF2A
&ary+1           = 0061FF30
&ary[0]+1        = 0061FF2A
sizeof(ary)      = 7
sizeof(&ary)     = 4
sizeof(&ary[0])  = 4
ptr              = 00405064
&ptr             = 0061FF24
&ptr[0]          = 00405064
ptr+1            = 00405065
&ptr+1           = 0061FF28
&ptr[0]+1        = 00405065
sizeof(ptr)      = 4
sizeof(&ptr)     = 4
sizeof(&ptr[0])  = 4

c:\vc7>
c:\vc7>
c:\vc7>gcc --version
gcc (MinGW.org GCC-6.3.0-1) 6.3.0
Copyright (C) 2016 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


c:\vc7>
#endif
