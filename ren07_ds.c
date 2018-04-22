//
//	練習７　Dark side
//
//	X86 -> Little endian
//
//	2018/04/22 H.Nitobe

#include <stdio.h>

#define	DEBUG

int main(void)
{
	char		str[] = "~~~~~~~~~~";	// 10文字＋EOL＋ filler(1byte)
	int			i;
	int			j;						// 何故か j が破壊されます。アセンブリリスト見てね
	
	for(j = 0; j < 10; j++) {			// だから j を回します。
		printf("%d:", j);
#ifdef DEBUG
		if(j == 0) {
			scanf("%d", &str[j]);
		} else {
			scanf("%*c%d", &str[j]);
		}
#else
		scanf("%*c%d", &str[j]);		// 何故か初回のデータが壊れます
		
#endif
		printf("\n");
		for (i = 0; i < 16; i++) {		// violation　マネしちゃだめよ。
			printf(" %02x", str[i]);
		}
		printf("\n");
	}
}

#if 0

; Listing generated by Microsoft (R) Optimizing Compiler Version 13.00.9466 

	TITLE	Practice07.c
	.386P
include listing.inc
if @Version gt 510
.model FLAT
else
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
_DATA	SEGMENT DWORD USE32 PUBLIC 'DATA'
_DATA	ENDS
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
_BSS	SEGMENT DWORD USE32 PUBLIC 'BSS'
_BSS	ENDS
$$SYMBOLS	SEGMENT BYTE USE32 'DEBSYM'
$$SYMBOLS	ENDS
_TLS	SEGMENT DWORD USE32 PUBLIC 'TLS'
_TLS	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif

INCLUDELIB LIBC
INCLUDELIB OLDNAMES

_DATA	SEGMENT
$SG786	DB	'~~~~~~~~~~', 00H
	ORG $+1
$SG792	DB	'%d:', 00H
$SG794	DB	'%d', 00H
	ORG $+1
$SG796	DB	'%*c%d', 00H
	ORG $+2
$SG797	DB	0aH, 00H
	ORG $+2
$SG801	DB	' %02x', 00H
	ORG $+2
$SG802	DB	0aH, 00H
_DATA	ENDS
PUBLIC	_main
EXTRN	_printf:NEAR
EXTRN	_scanf:NEAR
; Function compile flags: /Ods
_TEXT	SEGMENT
_str$ = -20
_j$ = -8
_i$ = -4
_main	PROC NEAR
; File c:\vc7\practice07.c
; Line 13
	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H
	push	esi
	push	edi
; Line 14
	mov	esi, OFFSET FLAT:$SG786
	lea	edi, DWORD PTR _str$[ebp]
	movsd
	movsd
	movsw
	movsb
; Line 18
	and	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L789
$L790:
	mov	eax, DWORD PTR _j$[ebp]
	inc	eax
	mov	DWORD PTR _j$[ebp], eax
$L789:
	cmp	DWORD PTR _j$[ebp], 10			; 0000000aH
	jge	$L784
; Line 19
	push	DWORD PTR _j$[ebp]
	push	OFFSET FLAT:$SG792
	call	_printf
	pop	ecx
	pop	ecx
; Line 21
	cmp	DWORD PTR _j$[ebp], 0
	jne	SHORT $L793
; Line 22
	mov	eax, DWORD PTR _j$[ebp]
	lea	eax, DWORD PTR _str$[ebp+eax]
	push	eax
	push	OFFSET FLAT:$SG794
	call	_scanf
	pop	ecx
	pop	ecx
; Line 23
	jmp	SHORT $L795
$L793:
; Line 24
	mov	eax, DWORD PTR _j$[ebp]
	lea	eax, DWORD PTR _str$[ebp+eax]
	push	eax
	push	OFFSET FLAT:$SG796
	call	_scanf
	pop	ecx
	pop	ecx
$L795:
; Line 30
	push	OFFSET FLAT:$SG797
	call	_printf
	pop	ecx
; Line 31
	and	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L798
$L799:
	mov	eax, DWORD PTR _i$[ebp]
	inc	eax
	mov	DWORD PTR _i$[ebp], eax
$L798:
	cmp	DWORD PTR _i$[ebp], 16			; 00000010H
	jge	SHORT $L800
; Line 32
	mov	eax, DWORD PTR _i$[ebp]
	movsx	eax, BYTE PTR _str$[ebp+eax]
	push	eax
	push	OFFSET FLAT:$SG801
	call	_printf
	pop	ecx
	pop	ecx
; Line 33
	jmp	SHORT $L799
$L800:
; Line 34
	push	OFFSET FLAT:$SG802
	call	_printf
	pop	ecx
; Line 35
	jmp	$L790
$L784:
; Line 36
	xor	eax, eax
	pop	edi
	pop	esi
	leave
	ret	0
_main	ENDP
_TEXT	ENDS
END

#endif
	