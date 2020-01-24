#!/usr/bin/env python3

from socket import socket
from hashlib import sha1

hash = sha1()

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
        data = c.recv(4096).decode().strip()
        print(f"String is {data}")
        received_hash = c.recv(4096).decode().strip()
        hash.update(data.encode())
        computed_hash = hash.hexdigest()
        if received_hash == computed_hash:
            ret = f"SHA-1 of received data verified!\nReceived data - {data}"
        else:
            ret = f"SHA-1 of received data is incorrect\nShould be {received_hash}, is {computed_hash}"
        ret += "\nThank you for connecting"
        c.send(ret.encode().ljust(4096))
except KeyboardInterrupt:
    s.close()
    print("Closed socket")
except Exception as e:
    s.close()
    print(e)
    print(e.body)
