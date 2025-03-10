"""
Problem 31 |=================================================
Write a program to fill array with ordered numbers from 1 to N,
then print it, after that shuffle this array and print it after shuffle.

Input:
10

Output:

Array elements before shuffle:
1 2 3 4 5 6 7 8 9 10 

Array elements after shuffle:
2 4 6 3 10 1 7 8 5 9
=============================================================
"""
import random

def read_positive_number(message: str) -> int:
    """
    Reads a positive integer from the user.
    Keeps prompting until a valid positive integer is entered.
    """
    while True:
        try:
            number = int(input(message))
            if number > 0:
                return number
            print("Please enter a positive number.")
        except ValueError:
            print("Invalid input. Please enter an integer.")

def fill_array_with_1_to_n(arr_length: int) -> list:
    """
    Fills a list with values from 1 to N.
    """
    return list(range(1, arr_length + 1))

def shuffle_array(arr: list):
    """
    Shuffles the array randomly in place.
    """
    random.shuffle(arr)

def print_array(arr: list):
    """
    Prints the elements of an array.
    """
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    # Read the number of elements
    arr_length = read_positive_number("\nEnter number of elements:\n")

    # Generate an ordered array from 1 to N
    arr = fill_array_with_1_to_n(arr_length)

    print("\nArray elements before shuffle:")
    print_array(arr)

    # Shuffle the array
    shuffle_array(arr)

    print("\nArray elements after shuffle:")
    print_array(arr)
