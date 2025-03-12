"""
Problem 35 |=================================================
Write a program to fill array with max size 100 with random numbers from
1 t0 100, read number and print if it's found or not (reuse code in prev
problem).

Input
10

Output:

Array 1 elements:
83 92 66 21 62 96 40 13 19 30

Please enter a number to search for?
66
19

Number you are looking for is: 66
Yes, The number is found :-)

Number you are looking for is: 19
No, The number is not found :-(


=============================================================

"""
import random

def read_number() -> int:
    """
    Reads an integer from the user.
    """
    return int(input("\nPlease enter a number to search for?\n"))

def random_number(from_val: int, to_val: int) -> int:
    """
    Generates a random number between 'from_val' and 'to_val' (inclusive).
    """
    return random.randint(from_val, to_val)

def fill_array_with_random_numbers() -> list:
    """
    Fills an array with random numbers between 1 and 100.
    """
    arr_length = int(input("\nEnter number of elements:\n"))
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

def is_number_in_array(number: int, arr: list) -> bool:
    """
    Checks if a number exists in the array.
    """
    return find_number_position_in_array(number, arr) != -1

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    # Fill the array with random numbers
    arr = fill_array_with_random_numbers()

    # Print the array
    print("\nArray elements:")
    print_array(arr)

    # Read a number to search for
    number = read_number()
    print("\nNumber you are looking for is:", number)

    # Check if the number exists in the array
    if not is_number_in_array(number, arr):
        print("No, The number is not found :-(")
    else:
        print("Yes, it is found :-)")
