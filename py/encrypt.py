#!/usr/bin/env python3

from random import choice, seed
from string import ascii_lowercase

letters = {}
data = input("Enter a string to encrypt: ").lower()
keyword = input("Enter keyword: ").lower()
seed_value = int(input("Enter the encryption key: "))

l = len(keyword)

for i in range(l):
    letters[ascii_lowercase[i]] = keyword[i]

print("Generating dictionary to encrypt given data!")

seed(seed_value)

for _, letter in enumerate(ascii_lowercase[l:], start=1):
    c = choice(ascii_lowercase)
    while c in letters.values():
        c = choice(ascii_lowercase)
        continue

    letters[letter] = c

print(letters)

print("Encrypted string is: ", end="")

for c in data:
    try:
        print(letters[c], end="")
    except KeyError:
        print(c, end="")
print()
