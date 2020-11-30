#!/usr/bin/env python3

import imaplib
import email
from email.parser import HeaderParser
from getpass import getpass

from decouple import config


def get_input(name: str, prompt: str) -> str:
    val = config(name, default=None)
    if not val:
        val = (
            input(prompt) if 'password' not in name.lower() else getpass(prompt=prompt)
        )
    return val


# IMAP host
host = get_input('IMAP_HOST', 'Enter IMAP host: ')

# Take username and password from user
username = get_input('IMAP_USERNAME', f'Enter email address for {host}: ')
password = get_input('IMAP_PASSWORD', f'Enter password for {username}: ')

# Initialize imaplib object with an SSL connection to our host
imap = imaplib.IMAP4_SSL(host)

# Login to the IMAP server
imap.login(username, password)

# Select the inbox folder
_, messages = imap.select("Inbox")

# Get number of messages
_, message_count = imap.search(None, 'ALL')
print(f'Total number of mesages in inbox: {len(message_count[0])}')

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
