#!/usr/bin/env python3

import csv
from os import sep

from tabulate import tabulate

log_file_name = 'log.csv'
print(f'Reading wireshark log file {log_file_name}!')

# Read the log file
with open('log.csv', 'r') as log:

    print(f'Parsing {log_file_name} as CSV!')

    # Parse as CSV
    wireshark_log = list(csv.reader(log))[1:]
    print()

    print(
        tabulate(
            wireshark_log,
            headers=(
                'Frame Number',
                'Frame Time',
                'Source MAC',
                'Destination MAC',
                'Source IP',
                'Destination IP',
                'protocol',
            ),
        )
    )
