#!/usr/bin/env python3


def factorial(n: int) -> int:
    """
    Calculate factorial of a given number, recursively
    :paran n -> Integer whose factorial is to be computed
    :return: The factorial of the given number
    """
    if n == 1:
        return n
    return n * factorial(n - 1)


n = int(input('Enter a number: '))
print(f'Factorial of {n} is {factorial(n)}')
