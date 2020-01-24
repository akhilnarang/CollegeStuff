#!/usr/bin/env python3

from hashlib import sha1

hash = sha1()

print(f"Digest is {hash.hexdigest()}!")

hash.update(input("Enter text: ").encode())

print(f"Digest is {hash.hexdigest()}!")
