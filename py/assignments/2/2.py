#!/usr/bin/env python3

from string import digits

even = odd = 0

x = input('Enter a string including a series of digits: ')

even = len([c for c in x if c in digits and int(c) % 2 == 0])

odd = len([c for c in x if c in digits and int(c) % 2 != 0])

print(f'{x} contained {even} even digits and {odd} odd digits!')
