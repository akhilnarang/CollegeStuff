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
    msg db "Enter numbers: "
    msgLength equ $-msg
    
section .bss ; section for uninitialized data
    num resb 3
    
section .text ; section for text
global _start
_start:

; Write syscall to display msg
print msg, msgLength
; Accept number from the user
read num, 3 ; 2 digit number
mov al, 0 ; Set al to 0
mov rsi, num ; Copy input to rsi
up: ; up label
mov bl, byte[rsi] ; Copy a byte from rsi to bl
cmp bl, 0AH  ; Compare the byte with 0x0a (10 - ASCII for enter)
je exit1 ; Jump to exit1 if equal
cmp bl, 39H ; Compare the byte with 0x39 (57 - ASCII for 9)
jbe down ; Jump down if less or equal
sub bl, 07H ; Subtract 0x07 (Difference 65-57 (ASCII for A-9))
cmp bl, 3FH ; Compare the byte with 0x3f (63)
jbe down ; Jump down if less than equal
sub bl, 20H ; Subtract 0x30 from the byte (32 - 97-65 (ASCII for a-A))
down:
sub bl, 30H ; Subtract 0x30 from the byte (48 - To get hex value from input value)
shl al, 4 ; Left shift al by 4
add al, bl ; Add bl to al and store in al
inc rsi ; Increment pointer
jmp up ; Jump up
exit1:

; Exit syscall
mov rax,60
mov rdi,0
syscall