#!/usr/bin/env python3

from typing import List, Union


class Variable:
    """
    Class to depict a variable
    """

    def __init__(self, value):
        """
        Parameterized constructor to initialize our value
        """
        self.value = value

    def __eq__(self, obj):
        """
        Function to help us check whether our object is equal to another
        """
        return self.value == obj.value


class Constant:
    """
    Class to depict a constant
    """

    def __init__(self, value):
        """
        Parameterized constructor to initialize our value
        """
        self.value = value

    def __eq__(self, obj):
        return self.value == obj.value


class Relation:
    """
    Class to depict a Relation
    """

    def __init__(self, name: str, args: list):
        """
        :param name: Name
        :param args: List of arguments
        """
        self.name = name
        self.value = self.name + str([i.value for i in args])
        self.args = args


Expression = Union[Constant, Relation, Variable]


def unify_algo(
    L1: Expression, L2: Expression, testset: dict
) -> Union[None, List[Expression], bool, dict]:
    """
    :param L1: Expression 1
    :param L2: Expression 2
    :param testset:
    """
    # If both are variable or constants
    if (
        isinstance(L1, Variable)
        or isinstance(L2, Variable)
        or isinstance(L1, Constant)
        or isinstance(L2, Constant)
    ):
        if L1 == L2:
            return None
        elif isinstance(L1, Variable):
            if isinstance(L2, Variable):
                print('Mismatching variables L1 and L2')
                return False
            else:
                if L1.value not in testset.values():
                    return [L2, L1]
                else:
                    print('Ambiguous')
                    return False
        elif isinstance(L2, Variable):
            if isinstance(L1, Variable):
                print('Mismatching variables L1 and L2')
                return False
            else:
                if L2.value not in testset.values():
                    return [L1, L2]
                else:
                    print('Ambiguous')
                    return False
        else:
            print('Mismatch')
            return False
    # Ensuring the functions are the same
    elif L1.name != L2.name:
        print('Relationation Mismatch')
        return False
    # Ensuring the functions have the same number of arguments
    elif len(L1.args) != len(L2.args):
        print('Arguements length missmatch')
        return False
    subset = {}
    for i in range(len(L1.args)):
        S = unify_algo(L1.args[i], L2.args[i], subset)
        if S == False:
            return False
        if S != None:
            subset[S[0].value] = S[1].value
    return subset


if __name__ == '__main__':

    print(
        unify_algo(
            Relation('Knows', [Constant('Ram'), Variable('X')]),
            Relation('Knows', [Variable('Y'), Relation('Mother', [Variable('Y')])]),
            {},
        )
    )
    print()
    print(
        unify_algo(
            Relation('Knows', [Constant('Ran'), Variable('X')]),
            Relation('Knows', [Variable('Y'), Constant('Ravi')]),
            {},
        )
    )
    print()
    print(
        unify_algo(
            Relation('Knows', [Constant('Ram'), Variable('X')]),
            Relation('Knows', [Variable('X'), Constant('Ravi')]),
            {},
        )
    )
