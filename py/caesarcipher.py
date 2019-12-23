#!/usr/bin/env python3

from string import ascii_lowercase

data = input("Enter a string to encrypt: ").lower()
shift_value = int(input("Enter the encryption key: "))

letters = {letter: index for index, letter in enumerate(ascii_lowercase, start=1)}

for letter, index in letters.items():
    letters[letter] = (index + shift_value) % 26

for c in data:
    if c in ascii_lowercase:
        print(ascii_lowercase[letters[c] - 1], end="")
    else:
        print(c, end="")
print()
