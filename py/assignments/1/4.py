#!/usr/bin/env python3

from string import ascii_letters, digits

# Accept a string and print the number of letters and digits
s = input('Enter a string: ')
d = len([c for c in s if c in digits])
l = len([c for c in s if c in ascii_letters])
print(f'{s} has {d} digits and {l} letters!')
