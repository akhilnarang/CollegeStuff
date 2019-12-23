#!/usr/bin/env python3

n = int(input("Enter number of queens: "))
left_diagonal = [0] * (n ** 2)
right_diagonal = [0] * (n ** 2)
column = [0] * (n ** 2)


""" A recursive utility function to solve n  
Queen problem """


def solve_recursive(board, column):

    # If all of the queens have been placed already, its done
    if column >= n:
        return True

    for i in range(n):

        if (
            left_diagonal[i - column + n - 1] != 1 and right_diagonal[i + column] != 1
        ) and column[i] != 1:

            # Place this queen in board[i][column]
            board[i][column] = 1
            left_diagonal[i - column + n - 1] = right_diagonal[i + column] = column[
                i
            ] = 1

            # recur to place rest of the queens
            if solve_recursive(board, column + 1):
                return True

            # If placing queen in board[i][column] doesn't lead to a solution, then remove queen from board[i][column]
            board[i][column] = 0
            left_diagonal[i - column + n - 1] = right_diagonal[i + column] = column[
                i
            ] = 0

    # If the queen cannot be placed in any row in this colum column then return False
    return False


def solve():
    if n < 4:
        print(f"Solution for n < 4 doesn't exist!")
    board = [[0 for _ in range(n)] for _ in range(n)]
    solve_recursive(board, 0)
    print(*board)


if __name__ == "__main__":
    solve()
