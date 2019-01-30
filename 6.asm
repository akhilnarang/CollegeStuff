; Program to transmit data from System A to System B

mov AL, 4E
out 31, AL
mov AL, 23
out 31, AL
mov AL, 4E
out 39, AL
mov AL, 26
out 39, AL
mov SI, 2000
mov DI, 3000
mov CX, 05
again: mov AL, [SI]
out 30, AL
up: in AL, 39
and AL, 02
cmp AL, 02
jne up
in AL, 38
mov [DI], AL
inc SI
inc DI
dec CX

jnz again
int 3