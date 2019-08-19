%macro rw 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
syscall
%endmacro

section .data
	arr db 10,11,12,13,14,15
	msg1 db "no of odd numbers are"
	msg1len equ $-msg1
	msg2 db "no of even numbers are"
	msg2len equ $-msg2

section .bss
	odd resb 2
	even resb 2
	count resb 2
	temp resb 4

section .text
	global _start
_start:	mov rsi, arr
		mov cl, 05h
		mov byte[even],00h
		mov byte[odd],00h
l1:		mov al, byte[rsi]
		and al,01h
		cmp al,00h
		je even1
		jmp odd1
even1:	inc byte[even]
		inc rsi
		dec cl
		jnz l1
		jmp deven
odd1:	inc byte[rsi]
		inc rsi
		dec cl
		jnz l1
		jmp dodd
deven:	mov bl, byte[even]
		call disp
dodd: 	mov bl, byte[odd]
		call disp
		rw 1,1,msg1,msg1len
		rw 1,1,odd,2
		rw 1,1,msg2,msg2len
		rw 1,1,even,2
		mov rax,60
		mov rdi,0
		syscall

disp1:	mov rsi, temp
		mov cl, 2
ll1:	rol bl, 4
		mov al, bl
		and al, 0fh
		cmp al,09h
		jbe skip 
		add al, 07h
skip: 	add al, 30h
	 	mov byte[rsi], al
	 	inc rsi
	 	dec cl
	 	jnz ll1
	 	rw 1,1,temp,4
	 	syscall
	 	
		
