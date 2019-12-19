#!/usr/bin/env python3
n = int(input("Enter number of queens: "))


def is_safe(result, row, col):
    global n
    if (
        1 in result[row]
        or 1 in map(lambda x: x[col], result[:row])
        or 1
        in map(
            lambda x: result[x[0]][x[1]],
            zip(range(row - 1, -1, -1), range(col - 1, -1, -1)),
        )
        or 1
        in map(
            lambda x: result[x[0]][x[1]], zip(range(row - 1, -1, -1), range(col + 1, n))
        )
    ):
        return False
    return True


def solve_recursive(row, result):
    for col in range(n):
        if is_safe(result, row, col):
            result[row][col] = 1
            if row + 1 < n:
                if solve_recursive(row + 1, result):
                    return True
                result[row][col] = 0
            else:
                return True
    return False


def solve(result):
    solve_recursive(0, result)
    return result


if __name__ == "__main__":
    res = [[0 for _ in range(n)] for _ in range(n)]
    print(*solve(res), sep="\n")

