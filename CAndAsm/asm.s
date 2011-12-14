SECTION	.text

EXTERN	_printNumber
GLOBAL	_asinb

_asinb: 
	;op2 * sin(op1)
	push	esi
	mov		esi, esp
	sub		esp, 8
	finit
	add	esi, 8
	fld	qword [esi]
	fsin
	add	esi, 8
	fild	dword [esi]
	fmul
	sub	esi, 24
	fstp	qword [esi]
	call	_printNumber
	add		esp, 8
	pop		esi
	ret