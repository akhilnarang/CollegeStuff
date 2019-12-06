#!/usr/bin/env python3

from string import ascii_lowercase

# Dictionary of letters and their position
letters = {l: p for p, l in enumerate(ascii_lowercase, start=1)}


# Euclid's Algorithm
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


p, q = [int(i) for i in input("Enter 2 prime numbers: ").split()]

n = p * q
phi_n = (p - 1) * (q - 1)

e_values = [i for i in range(2, phi_n) if gcd(phi_n, i) == 1]
print(f"The possible values of Public Keys are: {e_values}")
while True:
    e = int(input("Enter your choice: "))
    if e not in e_values:
        print(f"Chosen value of e {e} is not a possible value! Try again!")
        continue
    else:
        break

for d in range(1, phi_n):
    if e * d % phi_n == 1:
        break

message = (letters[i] for i in input("Enter desired string: "))
encrypted = [(c ** e) % n for c in message]

print(f"The encrypted input as per computed public key pair ({n},{e}): {encrypted}")

decrypted = [(c ** d) % n for c in encrypted]
print("The decrypted value of the above using the private key will be: ", end="")

for c in decrypted:
    for k, v in letters.items():
        if v == c:
            print(k, end="")
print()
