"""
Problem 24 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print Max 

Input:
10

Output:

Array Elements: 65 91 54 42 75 32 53 57 57 30
Max Number is : 91
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

def max_number_in_array(arr: list) -> int:
    """
    Finds the maximum number in the array.
    """
    return max(arr) if arr else None  # Handle empty list case

if __name__ == "__main__":
    # Fill the array with random numbers
    arr = fill_array_with_random_numbers()

    # Print the array elements
    if arr:
        print("\nArray Elements: ", end="")
        print_array(arr)

        # Print the maximum number in the array
        print("\nMax Number is:", max_number_in_array(arr))
