; This generates a square wave

mov al, 80
out 67, al
mov al, 01
out 63, al
label2: mov al, 00
label1: out 61, al
inc al
cmp al, ff
jnz label1
dec al
cmp al, 00
jmp label2
int 3
in al, dx
