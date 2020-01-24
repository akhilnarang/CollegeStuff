#!/usr/bin/env python3

from socket import socket
import sys

from hashlib import sha1

hash = sha1()

s = socket()

print("Socket successfully created")

data = input("Enter text string: ").encode()

hash.update(data)

# default port for socket
port = 6180

# connecting to the server
s.connect(("localhost", port))
s.send(data.ljust(4096))
s.send(str.encode(hash.hexdigest()).ljust(4096))
print(s.recv(4096).decode().strip())
print("Connection over")
