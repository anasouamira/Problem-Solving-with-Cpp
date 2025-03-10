"""
Problem 32 |=================================================
Write a program to fill array with max size 100 with random numbers from
1t0 100, copy it to another array in reverse order and print it.

Input
10

Output:
Array 1 elements:
64 8 62 19 2 21 15 74 96 85

Array 2 elements after copying array 1 in reversed order: 
85 96 74 15 21 2 19 62 8 64
=============================================================
"""

import random

def random_number(from_val: int, to_val: int) -> int:
    """
    Generates a random number between 'from_val' and 'to_val' (inclusive).
    """
    return random.randint(from_val, to_val)

def fill_array_with_random_numbers(arr_length: int) -> list:
    """
    Fills an array with random numbers between 1 and 100.
    """
    return [random_number(1, 100) for _ in range(arr_length)]

def print_array(arr: list):
    """
    Prints the elements of an array.
    """
    print(" ".join(map(str, arr)))

def copy_array_in_reverse_order(arr: list) -> list:
    """
    Copies an array into another in reverse order.
    """
    return arr[::-1]

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    # Read the number of elements
    arr_length = int(input("\nEnter number of elements:\n"))

    # Generate an array with random numbers
    arr = fill_array_with_random_numbers(arr_length)

    # Copy the array in reverse order
    arr2 = copy_array_in_reverse_order(arr)

    print("\nArray 1 elements:")
    print_array(arr)

    print("\nArray 2 elements after copy in reverse:")
    print_array(arr2)
