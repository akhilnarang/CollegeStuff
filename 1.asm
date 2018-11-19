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
    msg db "Enter your name: "
    msgLength equ $-msg
    msg2 db "Your name is: "
    msg2Length equ $-msg2    
    
section .bss ; section for uninitialized data
    name resb 20
    nameLength resb 1
    
section .text ; section for text
global _start
_start:

; Write syscall to display msg
print msg, msgLength

; Read syscall to accept name
read name, 20

; Get length of name from al (8bits of rax) and subtract one (Enter key)
sub al, 1
; Copy contents of al to nameLength
mov [nameLength], al

; Write syscall to display msg2
print msg2, msg2Length

; Write syscall to display name
print name, nameLength

; Exit syscall
mov rax,60
mov rdi,0
syscall