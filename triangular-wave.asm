mov al, 80
out 67, al
mov al, 01
out 63, al
mov al, 00
label1: out 61, al
inc al
cmp al, ff
jnz label1
label2: out 61, al
dec al
cmp al, 00
jnz label2
jmp label1
int 3
