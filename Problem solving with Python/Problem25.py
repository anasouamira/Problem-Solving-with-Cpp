"""
Problem 25 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print Minimum Number 

Input:
10 

Output:
Array Elements: 30 99 72 47 95 67 29 13 80 64 
Min Number is: 13 
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

def min_number_in_array(arr: list) -> int:
    """
    Finds and returns the minimum number in the array.
    """
    return min(arr) if arr else None  # Handle empty list case

if __name__ == "__main__":
    # Fill the array with random numbers
    arr = fill_array_with_random_numbers()

    # Print the array elements
    if arr:
        print("\nArray Elements: ", end="")
        print_array(arr)

        # Print the minimum number in the array
        print("\nMin Number is:", min_number_in_array(arr))
