#!/usr/bin/env python3

from socket import socket

from hashlib import sha512
import secrets

s = socket()
port = 6180

s.bind(("", port))
print(f"Socket bound to {port}")

# Put the socket into listening mode
s.listen(5)
print("Socket is listening")

# Go on forever till we interrupt it
try:
    while True:
        # Establish connection with client.
        c, addr = s.accept()
        print("Received connection from", addr)
        data = c.recv(4096).decode().strip()

        # Randomly alter the data by adding a zero-width space
        if secrets.randbits(1) == 1:
            print('*** Modifying the data ***')
            data = '\u200b' + data

        # Display the received string and compute its hash
        print(f"Received string is {data}")
        received_hash = c.recv(4096).decode().strip()
        hash = sha512()
        hash.update(data.encode())
        computed_hash = hash.hexdigest()

        # Compare the hashes
        if received_hash == computed_hash:
            ret = f"SHA-512 of received data verified!\nReceived data - {data}"
        else:
            ret = f"SHA-512s of received data is incorrect\nShould be {received_hash}, is {computed_hash}"
        ret += "\nThank you for connecting"

        # Return message to client
        c.send(ret.encode().ljust(4096))
except KeyboardInterrupt:
    s.close()
    print("Closed socket")
except Exception as e:
    s.close()
    print(e)
    print(e.body)
