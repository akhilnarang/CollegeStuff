#!/usr/bin/env python3


class CSP:
    """
    Class to represent our Constraint Satisfaction Problem
    """

    def __init__(self, variables, domain):
        """
        Parameterized constructor for CSP
        Variables that are to be constrainted, and the domain of each variable is passed
        """
        self.variables = variables
        self.domain = domain
        self.constraints = {}

        for var in self.variables:
            self.constraints[var] = []
            if var not in self.domain:
                raise LookupError('Domain Assignment Error')

    def add_constraint(self, constraint):
        for v in constraint.letters:
            if v not in self.variables:
                raise LookupError('Variable in constraint not in CSP')
            else:
                self.constraints[v].append(constraint)

    def consistent(self, variable, assignment) -> bool:
        # Checking all the constraints
        for cons in self.constraints[variable]:
            if not cons.satisfied(assignment):
                return False
        return True

    def backtracking_search(self, assignment={}):
        """
        To run a backtracking algorithm with constraints
        """
        if len(assignment) == len(self.variables):
            return assignment

        unassigned = [v for v in self.variables if v not in assignment]
        first = unassigned[0]

        for value in self.domain[first]:
            local_assignment = assignment.copy()
            local_assignment[first] = value
            if self.consistent(first, local_assignment):
                result = self.backtracking_search(local_assignment)
                if result is not None:
                    return result
        return None


class SendMoreMoneyConstraint:
    """
    Class for Send + More = Money constraint
    """

    def __init__(self, letters):
        """
        Parameterized constructor
        """
        self.letters = letters

    def satisfied(self, assignment) -> bool:
        """
        Returns whether or not the constraitns is satisfied
        """
        if len(set(assignment.values())) < len(assignment):
            return False

        if len(assignment) == len(self.letters):
            # Assigned values to ensure no-duplication
            s = assignment['S']
            e = assignment['E']
            n = assignment['N']
            d = assignment['D']
            m = assignment['M']
            o = assignment['O']
            r = assignment['R']
            y = assignment['Y']

            # Checking if condition is satisfied
            send = s * 1000 + e * 100 + n * 10 + d
            more = m * 1000 + o * 100 + r * 10 + e
            money = m * 10000 + o * 1000 + n * 100 + e * 10 + y

            return send + more == money
        return True


if __name__ == '__main__':
    letters = ['S', 'E', 'N', 'D', 'M', 'O', 'R', 'Y']
    possible_digits = {}

    for letter in letters:
        possible_digits[letter] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    # We don't want a result that starts with a 0
    possible_digits['M'] = [1]

    csp = CSP(letters, possible_digits)
    csp.add_constraint(SendMoreMoneyConstraint(letters))

    solution = csp.backtracking_search()
    if solution is None:
        print('No solution found!')
    else:
        print('Solution is: ')
        for key, val in solution.items():
            print(str(key).ljust(10), str(val).ljust(30))
