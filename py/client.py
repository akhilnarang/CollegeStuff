#!/usr/bin/env python3

from socket import socket
import sys

s = socket()
print("Socket successfully created")

data = input("Enter the encrypted string: ").lower()
keyword = input("Enter the keyword: ").lower()
key = input("Enter the key: ")

# default port for socket
port = 6180

# connecting to the server
s.connect(("localhost", port))
s.send(str.encode(data).ljust(4096))
s.send(str.encode(keyword).ljust(4096))
s.send(str.encode(key))
print(s.recv(4096).decode())

print("Socket connected")
