"""
Problem19 |===============================================

Write a program to print 3 random numbers from 1 to 10 

Output :
6
2
3
==========================================================
"""

import random

def random_number(start: int, end: int) -> int:
    """
    Generates a random number between 'start' and 'end' (inclusive).
    """
    return random.randint(start, end)

# Generate and print random numbers
print(random_number(1, 10))
print(random_number(1, 10))
print(random_number(1, 10))
