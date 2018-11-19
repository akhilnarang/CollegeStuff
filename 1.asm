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
mov rax, 1
mov rdi, 1
mov rsi, msg
mov rdx, msgLength
syscall

; Read syscall to accept name
mov rax, 0
mov rdi, 0
mov rsi, name
mov rdx, 20
syscall

; Get length of name from al (8bits of rax) and subtract one (Enter key)
sub al, 1
; Copy contents of al to nameLength
mov [nameLength], al

; Write syscall to display msg2
mov rax, 1
mov rdi, 1
mov rsi, msg2
mov rdx, msg2Length
syscall

; Write syscall to display name
mov rax, 1
mov rdi, 1
mov rsi, name
mov rdx, nameLength
syscall

; Exit syscall
mov rax,60
mov rdi,0
syscall
