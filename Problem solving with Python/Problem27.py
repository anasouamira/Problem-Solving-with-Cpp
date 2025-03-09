"""
Problem 27 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print average of all number

Input:
10

Output:

Array Elements: 24 36 44 73 8 56 98 67 33 71

Average of all number is : 51
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

def array_average(arr: list) -> float:
    """
    Returns the average of all elements in the array.
    """
    return sum_array(arr) / len(arr) if arr else 0

if __name__ == "__main__":
    # Fill the array with random numbers
    arr = fill_array_with_random_numbers()

    # Print the array elements
    if arr:
        print("\nArray Elements: ", end="")
        print_array(arr)

        # Calculate and print the average of the array elements
        print("\nAverage of all numbers is:", array_average(arr))
