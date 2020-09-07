from math import pi


def rec_area(w: float, h: float) -> float:
    """
    :param w -> Width of a rectangle (or square)
    :param h -> Height of a rectangle (or square)
    :return: The area for a rectangle (or square) with the given dimensions
    """
    return w * h


def circle_area(r: float) -> float:
    """
    :param r -> Radius of a circle
    :return: The area of a circle with the given radius
    """
    return pi * (r ** 2)
