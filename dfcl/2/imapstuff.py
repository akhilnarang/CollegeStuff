#!/usr/bin/env python3

import imaplib
import email
from email.parser import HeaderParser
from getpass import getpass

# IMAP host
host = "imap.gmail.com"

# Take username and password from user
username = input("Enter email address: ")
password = getpass(prompt="Enter password: ")

# Initialize imaplib object with an SSL connection to our host
imap = imaplib.IMAP4_SSL(host)

# Login to the IMAP server
imap.login(username, password)

# Retrieve the messages from the inbox folder
_, messages = imap.select("Inbox")

# Fetch the messages and decode to string
_, msg = imap.fetch(messages[0].decode(), "(RFC822)")

# Iterate over the response
for response in msg:
    # Confirm that we have a tuple - 2nd row will be our content
    if isinstance(response, tuple):
        # Extract headers
        headers = HeaderParser().parsestr(
            email.message_from_bytes(response[1]).as_string()
        )
        # Iterate over and print our headers
        for k, v in headers.items():
            print(f"\nName={k}\nValue={v}")

# Close and logout
imap.close()
imap.logout()
