#!/usr/bin/env python3

n = int(input("Enter number of elements: "))
size = int(input("Enter knapsack capacity: "))

objects = {}
profit_by_weight = {}

for i in range(n):
    objects[i] = [
        int(input(f"Enter weight of object {i+1}: ")),
        int(input(f"Enter profit for object {i+1}: ")),
    ]

pbw = [p / w for w, p in objects.values()]

for i in range(n):
    profit_by_weight[i] = pbw[i]

sorted_weights = sorted(profit_by_weight.items(), key=lambda x: x[1])

sorted_weights.reverse()

amount_to_fill = []
for i in sorted_weights:
    curr_weight = objects[i[0]][0]
    if size - curr_weight >= 0:
        size = size - curr_weight
        amount_to_fill.append(1)
    else:
        amount_to_fill.append(size / curr_weight)
        break


amount_to_fill.append(0 * (n - len(amount_to_fill)))

profit = 0

for i in range(n):
    profit = profit + amount_to_fill[i] * objects[sorted_weights[i][0]][1]

print(f"Profit is {profit}")
