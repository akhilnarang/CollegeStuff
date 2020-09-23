#!/usr/bin/env python3

from __future__ import annotations

from copy import deepcopy
from typing import List
from sys import exit

# Type alias for our matrix representation
Matrix = List[List[str]]


class Node:
    """
    Class to represent a node
    """

    def __init__(
        self,
        matrix: Matrix,
        level: int,
        f_value: int,
        parent: Node = None,
        move: str = "Start",
    ):
        """
        Parameterized constructor for a node
        """
        self.matrix = matrix
        self.level = level
        self.f_value = f_value
        self.parent = parent
        self.move = move

    def info(self):
        """
        Prints some information about the node
        """
        print(
            f"Node Level = {self.level}, Node H Value = {self.f_value - self.level}, Node F Value = {self.f_value}\nNode matrix:"
        )

        # Print out the matrix
        for i in self.matrix:
            for j in i:
                print(j, " ", end="")
            print()

    def generate_child_nodes(self) -> list:
        """
        Generates child nodes
        """

        # We are going to move blank i.e. _ to all possible directions (left, right, up, or down)
        # First we need to find the location of the blank
        x_blank, y_blank = self.find_blank()

        # Now we have to find the possible values it has to move
        possible_positions = []
        if x_blank - 1 != -1:
            possible_positions.append(([x_blank - 1, y_blank], "Up"))
        if x_blank + 1 != len(self.matrix):
            possible_positions.append(([x_blank + 1, y_blank], "Down"))
        if y_blank - 1 != -1:
            possible_positions.append(([x_blank, y_blank - 1], "Left"))
        if y_blank + 1 != len(self.matrix):
            possible_positions.append(([x_blank, y_blank + 1], "Right"))

        # Now we can generate the child nodes by swapping blank with all possible values and then append them to a list
        child_nodes = []

        # Loop over all possible positions
        for new_position, move in possible_positions:

            # Create a duplicate to edit since we don't want to edit our original matrix
            temp_matrix = deepcopy(self.matrix)
            (
                temp_matrix[x_blank][y_blank],
                temp_matrix[new_position[0]][new_position[1]],
            ) = (
                temp_matrix[new_position[0]][new_position[1]],
                temp_matrix[x_blank][y_blank],
            )
            child_nodes.append(Node(temp_matrix, self.level + 1, 0, self, move))
        return child_nodes

    def find_blank(self) -> [int, int]:
        """
        Find the blank in our matrix
        """
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix)):
                if self.matrix[i][j] == "_":
                    return i, j


class Puzzle:
    """
    Class to represent the puzzle
    """

    def __init__(self, size: int):
        """
        Parameterized constructor for our puzzle
        """
        self.size = size
        self.open = []
        self.closed = []
        self.solution = []

    def puzzle(self):
        """
        Main puzzle function
        """

        print(
            f"Matrix input should be {self.size} whitespace separated numbers on {self.size} lines, _ for blank"
        )

        print("Enter the start matrix:")
        start_matrix = self.accept_matrix()

        print("Enter the goal matrix:")
        goal_matrix = self.accept_matrix()

        # Now we have to convert start matrix into a node that can generate children
        start_node = Node(start_matrix, 0, 0)

        # Finding the f value of the start node and then appending it to open list
        start_node.f_value = self.find_f_value(start_node, goal_matrix)
        self.open.append(start_node)

        while len(self.open) != 0:
            current_node = self.open[0]
            # Stop condition - when current matrix becomes equal to goal matrix
            if self.find_h_value(current_node.matrix, goal_matrix) == 0:
                while current_node.parent != None:
                    self.solution.append(current_node)
                    current_node = current_node.parent
                self.solution.append(current_node)
                break

            # Creating children by moving the blank i.e. _ in all possible directions and finding their heuristic (f) values and appending them to the open list

            for i in current_node.generate_child_nodes():
                # Many nodes can be duplicated when heuristic function is different between matrices. To avoid that, we are checking if the matrix is already in open or closed nodes, then the children are not generated again
                if not self.is_duplicate(i.matrix):
                    i.f_value = self.find_f_value(i, goal_matrix)
                    self.open.append(i)
            # Add current node to closed list and delete it from open list
            self.closed.append(current_node)
            del self.open[0]
            # We have to sort open list according to f values of nodes so that in next loop, we will check node with list
            self.open.sort(key=lambda node: node.f_value)
        for i in reversed(self.solution):
            i.info()
        print(f"Goal was reached after checking {1 + len(self.closed)} state spaces")
        print("Solution moves are:")
        for i in reversed(self.solution):
            print("-> ", i.move)

    def accept_matrix(self) -> Matrix:
        """
        Accepts a square matrix of the given size
        """
        return [input().split(" ") for _ in range(self.size)]

    def find_f_value(self, start_node: Node, goal_matrix: Matrix):
        """
        Finds heuristic value of a node
        """
        return start_node.level + self.find_h_value(start_node.matrix, goal_matrix)

    def find_h_value(self, start_matrix: Matrix, goal_matrix: Matrix) -> int:
        """
        Finds the difference between given puzzles
        """
        diff = 0
        for i in range(self.size):
            for j in range(self.size):
                if (
                    start_matrix[i][j] != goal_matrix[i][j]
                    and start_matrix[i][j] != "_"
                ):
                    diff += 1
        return diff

    def is_duplicate(self, matrix: Matrix) -> bool:
        """
        Check for duplication - i.e. matrix should not be in the open or closed list
        """
        for i in self.open:
            if i.matrix == matrix:
                return True
        for i in self.closed:
            if i.matrix == matrix:
                return True
        return False


# Accept input and create a Puzzle object as well

try:
    Puzzle(
        int(input("Enter the size of matrix (square root of puzzle size + 1) : "))
    ).puzzle()
except KeyboardInterrupt:
    print("\nExiting as per user request!")
except Exception as e:
    print("Exception occurred!\n", e)
