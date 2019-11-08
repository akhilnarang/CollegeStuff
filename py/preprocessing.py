#!/usr/bin/env python3


def list_operations():
    # List, mutable
    x = [1, 2, 3, 4, 5]
    print(x)
    # Reverse
    print(x[::-1])
    x = [3, 4, 5, 2, 1]
    # Sort
    x.sort()
    print(x)
    # Slicing
    print(x[1:5:2])
    # List with different data types
    y = [1, "two", 3, 4, "5"]
    print(y)
    # Append to a list
    y.append("Test")
    print(y)
    # Nested lists
    z = [1, [2, 3], 4]
    print(z)


def dictionary_operations():
    # Dictionary
    d = {"name": "Akhil", "roll": 34, "class": "DWDM"}
    d["attendance"] = 90.0
    print(d.keys())
    print(d.values())
    print(d)


def tuple_operations():
    # Tuple - immutable list
    t = (1, 2, 3, 4, 5)
    print(t)


def set_operations():
    # Set - ordered list with no duplicates
    s = {2, 1, 4, 5, 3, 5}
    print(s)
    # Duplicates will be ignored
    s.add(2)
    print(s)
    # Check whether the elements are a part of the set
    print(5 in s)
    print(2 in s)
    print(6 in s)


def string_operations():
    paragraph = """Hello, this is the start of a paragraph. In this case, it will simply be a very long string. Consisting of many sentences.
    And some newlines too.
    """
    for s in paragraph.split("."):
        print(s.strip())


def power(base, power):
    return base ** power


def square(x):
    return power(x, 2)
