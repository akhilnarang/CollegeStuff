#!/usr/bin/env python3

from socket import socket

from hashlib import sha512
import secrets
from string import ascii_letters, digits

s = socket()

hash = sha512()

print('Generating random string of length 64')

# Generate random string and update hash object
data = ''.join(secrets.choice(ascii_letters + digits) for _ in range(64)).encode()
hash.update(data)

# Set port and hostname to connect to
port = 6180
hostname = 'localhost'

# Connecting to the server
s.connect((hostname, port))

# Sending the data
s.send(data.ljust(4096))

# Send the hash value
s.send(str.encode(hash.hexdigest()).ljust(4096))

# Print received data
print(s.recv(4096).decode().strip())
print('Connection over')
