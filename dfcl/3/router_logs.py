#!/usr/bin/env python3

import csv

log_file_name = 'log.csv'
print(f'Reading log file {log_file_name}!')

connections: dict[str, dict[frozenset, int]] = {}

# Read the log file
with open('log.csv', 'r') as log:

    print(f'Parsing {log_file_name} as CSV!')

    # Parse as CSV
    router_log = list(csv.reader(log))
    print()
    print('Sr. No.\tSource IP\tDestination IP\tProtocol')
    srno = 0
    # Iterate over the rows
    for row in router_log[1:]:
        srno += 1

        # Extract the data
        src, dest, protocol = row

        # Set a key
        key = frozenset([dest, protocol])

        if src in connections:
            if key in connections[src]:
                connections[src][key] += 1
            else:
                connections[src][key] = 1
        else:
            connections[src] = {}
            connections[src][key] = 1

        # Print the data
        print(f'{srno}\t{src}\t{dest}\t{protocol}')

print('\n\nSummary\n\n')
for source, dest in connections.items():
    print(f'{source} has connected to:')
    for k, v in dest.items():
        print(f'\t{list(k)[1]} over {list(k)[0]} {v} times!')
