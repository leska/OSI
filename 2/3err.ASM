	org	7C00h
_start:
	mov	ah, 2
	mov	al, 1
	mov	ch, 0
	mov	cl, 2
	mov	dh, 0
	mov	bx, s2
	int	13h
	cmp ah,0
	jne _err

	push	cs
	pop	es
	mov	ah, 13h
	mov	al, 0
	mov	bh, 0
	mov	bl, 42h
	mov	cx, len
	mov	dx, 0202h
	mov	bp, s2
	int	10h
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
	db	'hello'
len	= $ - s2
s2_end:
	db	512 - (s2_end - s2) dup(0)