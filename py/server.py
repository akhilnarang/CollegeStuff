#!/usr/bin/env python3

from socket import socket
from random import choice, seed
from string import ascii_lowercase


s = socket()
print("Socket successfully created")

port = 6180

s.bind(("", port))
print(f"Socket binded to {port}")

# put the socket into listening mode
s.listen(5)
print("Socket is listening")

# a forever loop until we interrupt it or
# an error occurs

try:
    while True:

        # Establish connection with client.
        c, addr = s.accept()
        print("Got connection from", addr)

        encrypted = c.recv(4096).decode().strip()
        print(f"Encrypted value is {encrypted}")
        keyword = c.recv(4096).decode().strip()
        key = int(c.recv(4096).decode().strip())
        letters = {}

        l = len(keyword)

        for i in range(l):
            letters[ascii_lowercase[i]] = keyword[i]

        seed(key)

        for _, letter in enumerate(ascii_lowercase[l:], start=1):
            ch = choice(ascii_lowercase)
            while ch in letters.values():
                ch = choice(ascii_lowercase)
                continue

            letters[letter] = ch

        print(letters)

        print("Decrypted message is: ")
        for ch in encrypted:
            if ch in letters.values():
                for k, v in letters.items():
                    if ch == v:
                        print(k, end="")
            else:
                print(ch, end="")
        print("\nMessage decrypted!")
        c.send(b"Thank you for connecting")
except:
    c.close()
