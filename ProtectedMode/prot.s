org 0x7c00

_start:
	jmp 0:_st

_st:
	cli
	xor si, si
	mov ds, si
	mov es, si
	mov ss, si
	sti
	mov ax, 0x201
	mov cx, 2
	mov bx, 0x7e00
	int 0x13
	jc	_err
	
	lgdt [gdt]
	cli
	mov	eax, cr0
	or	eax, 1
	mov	cr0, eax
	sti
	jmp 8:_lb
_lb:
	bits 32
	cli
	mov ax, 16
	mov ds, ax
	sti
	call 0x7e00
	
_err:
	cli
	hlt
jmp _err
	sti

gdt: 
	descr dw 24
	dd gdt0

gdt0: 	
	dq 0
gdt1:
	dw 0xffff, 0 		
	db 0, 0x9a, 0x4f, 0
gdt2: 
	dw 0xffff, 0
	db 0, 0x92, 0x4f, 0
gdt3: 
	dw 0xffff, 0
	db 0, 0x92, 0x4f, 0
		
_end:
	times (510 + $$ - $) db 0
	db 0x55, 0xaa
_s2: