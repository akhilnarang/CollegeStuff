#!/usr/bin/env python3

arr = []


def partition(low, high):
    pivot = arr[high]
    print(f"Pivot = {pivot} at index {high}")
    i = low - 1
    print(f"i = low - 1 = {i}")
    for j in range(low, high):
        if arr[j] < pivot:
            print(f"arr[{j}] = {arr[j]}")
            print(f"Incrementing i from {i} to {i + 1}")
            i = i + 1
            print(f"Swapping arr[i={i}] {arr[i]} and arr[j={j}] {arr[j]}")
            arr[i], arr[j] = arr[j], arr[i]
    print(f"Swapping arr[i+1={i+1}] {arr[i+1]} and arr[high={high}] {arr[high]}")
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    print(f"Returning i+1 = {i+1}")
    return i + 1


def quicksort(low, high):
    if low < high:
        print(f"low {low} is less than high {high}")
        j = partition(low, high)
        print(f"j is {j}")
        print(f"Sorting low = {low} to j-1 = {j-1}")
        quicksort(low, j - 1)
        print(f"Sorting j+1 = {j+1} to high = {high}")
        quicksort(j + 1, high)


for i in range(int(input("Enter size of array: "))):
    arr.append(int(input(f"Enter element {i}: ")))

print(arr)
quicksort(0, len(arr) - 1)
print(arr)
