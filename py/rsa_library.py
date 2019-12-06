#!/usr/bin/env python3

#!/usr/bin/env python3

# Importing libraries
from rsa import newkeys, encrypt, decrypt

# Generating public and private key pair
print("Generating keypair!")
pubkey, privkey = newkeys(4096, poolsize=8)

print("Keys generated!")
print(f"Your public key is: {pubkey}")
print(f"Your private key is: {privkey}")

# Accept string to encrypt with public key
message = input("Enter a message to encrypt: ").encode("utf-8")
# Encrypt the given string using the generated public key
encrypted = encrypt(message, pubkey)

print(f"Encrypted message is {encrypted}")

# Decrypt the encrypted string using the generated private key
decrypted = decrypt(encrypted, privkey)

print(f"Decrypted message is: {decrypted.decode()}")
