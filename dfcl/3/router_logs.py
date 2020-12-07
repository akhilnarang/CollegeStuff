#!/usr/bin/env python3

import csv

# Read the log file
with open('log.csv', 'r') as log:

    # Parse as CSV
    router_log = list(csv.reader(log))[1:]

    # Iterate over the rows
    for row in router_log:

        # Extract the data
        src, dest, protocol = row
        
        # Print the data
        print(f'{src} connected to {dest} over {protocol}')