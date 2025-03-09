"""
Problem 26 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print sum of all number

Input:
10

Output:

Array Elements: 10 6 22 40 12 75 23 32 25 75
Sum of all numbers:320
=============================================================
"""

import random

def random_number(start: int, end: int) -> int:
    """
    Generates a random number between 'start' and 'end' (inclusive).
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

def sum_array(arr: list) -> int:
    """
    Returns the sum of all elements in the array.
    """
    return sum(arr)

if __name__ == "__main__":
    # Fill the array with random numbers
    arr = fill_array_with_random_numbers()

    # Print the array elements
    if arr:
        print("\nArray Elements: ", end="")
        print_array(arr)

        # Print the sum of all numbers in the array
        print("\nSum of all numbers is:", sum_array(arr))

