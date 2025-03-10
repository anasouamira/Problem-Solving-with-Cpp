"""
Problem 35 |=================================================
Write a program to fill array with max size 100 with random numbers from
110 100, read number and return its index in array if found otherwise
return -1. 

Input
10

Output:

Array 1 elements:
80 79 12 80 81 29 3 37 25 91

Please enter a number to search for?
12
55

Number you are looking for is: 12
The number found at position: 2
The number found its order : 3

Number you are looking for is: 55
The number is not found :-(


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

def find_number_position_in_array(number: int, arr: list) -> int:
    """
    Searches for a number in an array and returns its index, or -1 if not found.
    """
    try:
        return arr.index(number)
    except ValueError:
        return -1

def read_number() -> int:
    """
    Reads an integer from the user.
    """
    return int(input("\nPlease enter a number to search for:\n"))

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    # Read array length from user
    arr_length = int(input("\nEnter number of elements:\n"))

    # Fill array with random numbers
    arr = fill_array_with_random_numbers(arr_length)

    # Print the array
    print("\nArray elements:")
    print_array(arr)

    # Read a number to search for
    number = read_number()
    print("\nNumber you are looking for is:", number)

    # Search for the number in the array
    number_position = find_number_position_in_array(number, arr)

    if number_position == -1:
        print("The number is not found :-(")
    else:
        print(f"The number is found at index: {number_position}")
        print(f"The number's order in the array: {number_position + 1}")
