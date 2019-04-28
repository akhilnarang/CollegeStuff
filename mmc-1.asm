%macro rw 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro
%macro print 2
rw 1, 1, %1, %2
%endmacro
%macro read 2
rw 0, 0, %1, %2
%endmacro
section .data ; section for initialized data
    msg db "Sum is: "
    msgLength equ $-msg
    exc db "!", 10
    excLength equ $-exc

section .bss ; section for uninitialized data
    num resb 3
    arr resb 5
    tmp1 resb 4
    tmp2 resb 4
    tmp3 resb 4

section .text ; section for text
global _start
_start:
    print msg, msgLength
    mov al, 05
    mov bl, 04
    add al, bl
    mov bp, 2  
    display:
    rol al, 4
    mov [tmp1], al
    and al, 0FH
    cmp al, 09H ; Compare the byte with 0x09
    jbe down1 ; Jump down if less or equal
    add al, 07H ; Add 0x07 
    down1:
    add al, 30H ; Add 0x30 
    mov [tmp2],	al
    print tmp2, 1
    mov al, [tmp1]
    dec bp
    jnz display
    
    print exc, excLength
    ; Exit syscall
    mov rax,60
    mov rdi,0
    syscall