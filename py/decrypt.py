#!/usr/bin/env python3

from random import choice, seed
from string import ascii_lowercase

letters = {}

data = input("Enter a string to decrypt: ").lower()
seed_value = int(input("Enter the seed value: "))

print("Generating dictionary to encrypt/decrypt given data!")

seed(seed_value)

for _, letter in enumerate(ascii_lowercase, start=1):
    c = choice(ascii_lowercase)
    while c in letters.values():
        c = choice(ascii_lowercase)
        continue

    letters[letter] = c

print("Decrypted string is: ", end="")

for c in data:
    if c in letters.values():
        for k, v in letters.items():
            if c == v:
                print(k, end="")
    else:
        print(c, end="")
print()
