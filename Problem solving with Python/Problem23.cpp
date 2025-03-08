"""
Problem 23 |==================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100.

Input:
10 

Output:

Array Elements: 56 55 83 71 32 52 17 28 71 52
==============================================================
"""

import random

def random_number(start: int, end: int) -> int:
    """
    Generates a random number between 'start' and 'end' (inclusive).
    """
    return random.randint(start, end)

def fill_array_with_random_numbers() -> list:
    """
    Fills a list with random numbers.
    """
    try:
        arr_length = int(input("\nEnter number of elements:\n"))
        arr = [random_number(1, 100) for _ in range(arr_length)]
        return arr
    except ValueError:
        print("Invalid input. Please enter an integer.")
        return []

def print_array(arr: list):
    """
    Prints the array elements.
    """
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    # Fill the array with random numbers
    arr = fill_array_with_random_numbers()

    # Print the array elements
    if arr:
        print("\nArray Elements: ", end="")
        print_array(arr)

