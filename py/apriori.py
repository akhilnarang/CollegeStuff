#!/usr/bin/env python3


def print_data(data: dict):
    print("Items\tQuantity")
    for k, v in data.items():
        print(*k, end="")
        print(f"\t {v}")


def _print(data, newline=True):
    if newline:
        print()
    print(data)
    if newline:
        print()


def increment(data: dict, key):
    key = frozenset(key)
    if key in data.keys():
        data[key] += 1
    else:
        data[key] = 1
    return data


dataset = (
    (1, 2, 5),
    (2, 4),
    (2, 3),
    (1, 2, 4),
    (1, 3),
    (2, 3),
    (1, 3),
    (1, 2, 3, 5),
    (1, 2, 3),
)
minimum_support = 2

_print(f"Minimum support value is {minimum_support}")

_print("1 item")

cluster1 = {}
for data in dataset:
    for d in data:
        increment(cluster1, [d])
print_data(cluster1)

_print("After removing values less than minimum support:")

for key in list(cluster1.keys()):
    if cluster1[key] < minimum_support:
        cluster1.pop(key)
print_data(cluster1)

_print("2 items")

cluster2 = {}
keys = list(cluster1.keys())
for data in dataset:
    for i in range(len(data)):
        for j in range(i + 1, len(data)):
            if frozenset([data[i]]) in keys and frozenset([data[j]]) in keys:
                increment(cluster2, [data[i], data[j]])

print_data(cluster2)

_print("After removing values less than minimum support:")

for key in list(cluster2.keys()):
    if cluster2[key] < minimum_support:
        cluster2.pop(key)
print_data(cluster2)

_print("3 items")


cluster3 = {}
keys = list(cluster2.keys())
for data in dataset:
    for i in range(len(data)):
        for j in range(i + 1, len(data)):
            for k in range(j + 1, len(data)):
                if frozenset((data[i], data[j])) in keys and frozenset((data[j], data[k])) in keys and frozenset((data[i], data[k])) in keys:
                    increment(cluster3, [data[i], data[j], data[k]])
print_data(cluster3)

_print("After removing values less than minimum support:")

keys = list(cluster3.keys())
for key in keys:
    if cluster3[key] < minimum_support:
        cluster3.pop(key)
print_data(cluster3)
