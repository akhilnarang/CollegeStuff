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
    msg db "1. Enter the string ",10
	db "2. Length", 10
	db "3. Palindrome", 10
	db "4. Exit", 10
	db "choice: "
    msgLength equ $-msg
    msg2 db "Enter string: "
    msg2Length equ $-msg2    
    msg3 db "Palindrome", 10
    msg3Length equ $-msg3
    msg4 db "Not palindrome", 10
    msg4Length equ $-msg4
    msg5 db "Length is: ", 10
    msg5Length equ $-msg5
    msg6 db "String is: "
    msg6Length equ $-msg6
    msg7 db "Exiting", 10
    msg7Length equ $-msg7
    newLine db 10    
    
section .bss ; section for uninitialized data
    strlen resb 2
    len resb 2
    str1 resb 30
    str2 resb 30
    choice resb 3
    cnt resb 3
    
section .text ; section for text
global _start
_start:

; Write syscall to display msg
print msg, msgLength

; Read syscall to accept choice
read choice, 2

; Check the users input and accordingly jump to below section
cmp byte[choice], 31H
je c1
cmp byte[choice], 32H
je c2
cmp byte[choice], 33H
je c3
cmp byte[choice], 34H
je c4

; Choice 1 - Accept input
c1:
    print msg2, msg2Length
    read str1, 30
    dec rax
    mov byte[strlen], al
    mov byte[cnt], al
    print msg6, msg6Length
    print str1, [cnt]
    print newLine, 1
    jmp _start

; Choice 2 - Display length
c2:
    print msg5, msg5Length
    mov rsi, [strlen]
    cmp rsi, 39H
    jbe down
    add rsi, 07H
    down: add rsi, 30H
    mov [len], rsi
    print len, 1
    print newLine, 1
    jmp _start

; Choice 3 - Check for palindrome
c3:
mov rsi, str1
mov rdi, str1
mov cx, [cnt]

c31:
inc rdi
dec cx
jnz c31
dec rdi

c32:
mov al, [rsi]
cmp al, [rdi]
je c33
print msg4, msg4Length
jmp _start

c33:
inc rsi
dec rdi
dec byte[cnt]
jnz c32
print msg3, msg3Length
jmp _start

; Choice 4 - Exit
c4: 
print msg7, msg7Length

; Exit syscall
mov rax,60
mov rdi,0
syscall