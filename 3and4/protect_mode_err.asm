       org     7C00h

_start:
	jmp	0:x
x:
	xor	ax,ax
	mov	es,ax
	mov	ds,ax

	mov	ah, 2
	mov	al, 5
	mov	ch, 0
	mov	cl, 2
	mov	dh, 0
	mov	bx, s2
	int	13h
	cmp ah,0
	jne _err

	cli
	lgdt [gdtpointer]
	lidt [idtpointer]
	mov eax,cr0
	or eax,1
	mov cr0,eax
	jmp 8:y
y:
	xor ax,ax
	mov ds,ax
	mov es,ax
	mov sp,ax
	mov ax,4*8
	mov ss,ax
jmp 12:34
	cli
	hlt


_func_:
	mov	ax, 3*8
	mov	ds, ax
	mov	[0], byte 2
	cli
	hlt

_err:
	push	cs
	pop	es
	mov	ah, 13h
	mov	al, 0
	mov	bh, 0
	mov	bl, 42h
	mov	cx, len1
	mov	dx, 0202h
	mov	bp, mes
	int	10h
	cli
	hlt
mes:
	db 'Error'
len1 = $ - mes

_end:

	db	510 - (_end - _start) dup(0)
	db	55h, 0AAh


s2:
;table descr
gdt:
dw 0,0,0,0
db 0FFh,0FFh,  0,0,0,	10011010b, 00001111b,  0
db 0FFh,0FFh,  0,0,0,	10010010b, 00001111b,  0
db 0FFh,0FFh,  0,80h,0Bh,   10010010b, 00001111b,  0
db 0,0,  0,0,0,   10010110b, 00000000b,  0

gdtpointer:
dw gdtpointer-gdt-1 ; ?????? ???????
dd gdt;+7c00h

interrupt_table:
repeat 256
 dw _func_,8,1000011000000000b	,0
end repeat

idtpointer:
dw idtpointer-interrupt_table 
dd interrupt_table;+7c00h



s2_end:
	db     5*512 - (s2_end - s2) dup(0)
