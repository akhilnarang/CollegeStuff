#!/usr/bin/env python3

from hashlib import sha512
import secrets
from string import ascii_letters, digits

hash = sha512()

print('Generating random string of length 64')

data = ''.join(secrets.choice(ascii_letters + digits) for _ in range(64))

hash_value = hash.update(data.encode())

print(f'Generated data is:\n{data}')
print(f'SHA-512 of generated data is:\n{hash.hexdigest()}')

print('Modifying the generated data by adding a zero-width space at the start')
data = '\u200b' + data
hash_value = hash.update(data.encode())
print(f'New data is:\n{data}')
print(f'New SHA-512 is:\n{hash.hexdigest()}')
print('Since SHA values are different, we can see that the data has been tampered with')
