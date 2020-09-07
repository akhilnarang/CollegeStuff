#!/usr/bin/env python3

from sys import exit

from package_1 import *

n = int(input('Enter 1 for area of circle/rectangle, 2 for area of circle: '))

if n not in (1, 2):
    print('Please choose a valid option!')
    exit(1)

if n == 1:
    w = float(input('Enter value of width: '))
    h = float(input('Enter value of height: '))
    area = rec_area(w, h)
    if w == h:
        print(f'Area of square with side length {w} is {area}!')
    else:
        print(f'Area of rectangle with width {w} and height {h} is {area}!')
else:
    r = float(input('Enter value of radius: '))
    print(f'Area of a circle with radius {r} is {circle_area(r)}')
