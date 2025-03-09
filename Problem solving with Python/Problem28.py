"""
Problem 28 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, copy it to another array and print it.

Input
10

Output:

Array 1 elements: 1 47 51 18 85 62 51 61 82 4

Array 2 elements after copy: 1 47 51 18 85 62 51 61 82 4
=============================================================

"""

import random

def random_number(start: int, end: int) -> int:
    """
    Generates a random number within the given range [start, end].
    """
    return random.randint(start, end)

def fill_array_with_random_numbers() -> list:
    """
    Fills a list with random numbers based on user input.
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

def copy_array(arr: list) -> list:
    """
    Returns a copy of the given list.
    """
    return arr.copy()

if __name__ == "__main__":
    # Fill the first array with random numbers
    arr = fill_array_with_random_numbers()

    if arr:
        # Copy elements from arr to arr2
        arr2 = copy_array(arr)

        print("\nArray 1 elements:")
        print_array(arr)

        print("\nArray 2 elements after copy:")
        print_array(arr2)
