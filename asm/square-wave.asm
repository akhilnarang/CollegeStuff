; This generates a square wave

mov al, 80
out 67, al
mov al, 01
out 63, al
label3: mov al, 00
out 61, al
mov cl, ff
label1: dec cl
jnz label1
mov al, ff
out 61, al
mov cl, ff
label2: dec cl
jnz label2
jmp label3