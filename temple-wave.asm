mov al, 80
out 67, al
mov al, 01
out 63, al
label7: mov al, 00
out 61, al
mov cl, ff
label1: dec cl
jnz label1
mov al, 80
out 61, al
mov cl, ff
label2: dec cl
jnz label2
label3: inc al
out 61, al
cmp al, ff
jnz label3
label4: dec al
out 61, al
cmp al, 80
jnz label4
mov cl, ff
label5: dec cl
jnz label5
mov al, 00
out 61, al
mov cl, ff
label6: dec cl
jnz label6
jmp label7
int 3
