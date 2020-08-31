#!/usr/bin/env python3

from time import time


class Game:
    def __init__(self):
        """
        Constructor to initializ an empty tic tac toe board
        """
        self.current_state = [['.', '.', '.'], ['.', '.', '.'], ['.', '.', '.']]
        self.result = None
        self.player_turn = 'X'

    def print_board(self):
        """
        Function to print the current state
        """
        for i in range(3):
            for j in range(3):
                print(self.current_state[i][j], end="\t")
            print(end="\n\n")

    def winner_is(self):
        """
        For loop returns player if any player won either horizontally or vertically
        """
        for i in range(3):
            if self.current_state[i] == ['X', 'X', 'X']:
                return 'X'
            elif self.current_state[i] == ['O', 'O', 'O']:
                return 'O'
            elif (
                self.current_state[0][i] != '.'
                and self.current_state[0][i]
                == self.current_state[1][i]
                == self.current_state[2][i]
            ):
                return self.current_state[0][i]

        # This if condition returns the player if that player won diagonally
        if self.current_state[1][1] != '.':
            if (
                self.current_state[0][0]
                == self.current_state[1][1]
                == self.current_state[2][2]
                or self.current_state[0][2]
                == self.current_state[1][1]
                == self.current_state[2][0]
            ):
                return self.current_state[1][1]

        # This for loop returns None if game is not over yet (i.e if there are still empty places on board)
        for i in range(3):
            for j in range(3):
                if self.current_state[i][j] == '.':
                    return None

        # If no one wins and board is also full, then we return T for Tie
        return 'T'

    def max(self):
        max_value = -10
        move_x = None
        move_y = None

        winner = self.winner_is()
        if winner == 'X':
            return -10, 0, 0
        elif winner == 'O':
            return 10, 0, 0
        elif winner == 'T':
            return 0, 0, 0
        elif winner == None:
            for i in range(3):
                for j in range(3):
                    if self.current_state[i][j] == '.':
                        self.current_state[i][j] = 'O'
                        m, min_i, min_j = self.min()
                        if m > max_value:
                            max_value, move_x, move_y = m, i, j
                        self.current_state[i][j] = '.'
            return max_value, move_x, move_y

    def min(self):
        min_value = 10
        move_x = None
        move_y = None

        winner = self.winner_is()
        if winner == 'X':
            return -10, 0, 0
        elif winner == 'O':
            return 10, 0, 0
        elif winner == 'T':
            return 0, 0, 0
        elif winner == None:
            for i in range(3):
                for j in range(3):
                    if self.current_state[i][j] == '.':
                        self.current_state[i][j] = 'X'
                        m, max_i, max_j = self.max()
                        if m < min_value:
                            min_value, move_x, move_y = m, i, j
                        self.current_state[i][j] = '.'
            return min_value, move_x, move_y

    def play(self):
        while True:
            self.print_board()
            self.result = self.winner_is()
            if self.result != None:
                if self.result == 'T':
                    print('It is a tie!')
                elif self.result == self.player_turn:
                    print('You won the game!')
                elif self.result == 'O':
                    print('You lost!')
                return

            if self.player_turn == 'X':
                start_time = time()
                m, move_x, move_y = self.min()
                print(
                    f'Your turn!\nRecommended move : X = {move_x}, Y = {move_y}\t(Calculated in {round(time()-start_time, 10)} seconds)'
                )
                while True:
                    user_move_x = int(input('Enter X: '))
                    user_move_y = int(input('Enter Y: '))
                    if self.current_state[user_move_x][user_move_y] == '.':
                        self.current_state[user_move_x][user_move_y] = 'X'
                        self.player_turn = 'O'
                        break
                    else:
                        print('Invalid Move!')
            else:
                print('My turn now!')
                m, move_x, move_y = self.max()
                self.current_state[move_x][move_y] = 'O'
                print(f'I put my O on ({move_x}, {move_y})')
                self.player_turn = 'X'


print('Tic Tac Toe')
print('You are X, I am O!')
Game().play()
