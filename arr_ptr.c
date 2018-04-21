//
//		配列とポインタ
//		
//		2018/04/20 Ported by H.Nitobe
//
//		うっくつさん本を読む。配列とポインタ
//		http://d.hatena.ne.jp/kilrey/20091011#p1
//

#include	<stdio.h>

#define DUMP(FMT,VAL) printf("%-16s = "FMT "\n", #VAL, (VAL))

int main(int argc, char* argv[])
{
	char const arr[] = "ab";
	char const* ptr = "uv";

	DUMP("%p", arr);
	DUMP("%p", &arr);
	DUMP("%p", &arr[0]);

	DUMP("%p", arr+1);
	DUMP("%p",&arr+1);
	DUMP("%p", &arr[0]+1);
 
	DUMP("%d", sizeof(arr));
	DUMP("%d", sizeof(&arr));
	DUMP("%d", sizeof(&arr[0]));

	DUMP("%p", ptr);
	DUMP("%p", &ptr);
	DUMP("%p", &ptr[0]);

	DUMP("%p", ptr+1);
	DUMP("%p", &ptr+1);
	DUMP("%p", &ptr[0]+1);
        
	DUMP("%d", sizeof(ptr));
	DUMP("%d", sizeof(&ptr));
	DUMP("%d", sizeof(&ptr[0]));

	return 0;
}
