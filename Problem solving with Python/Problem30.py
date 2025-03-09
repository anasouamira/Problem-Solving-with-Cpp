"""
Problem 30 |============================================================
Write a program to fill array two arrays with max size 100 with random
numbers from 1 to 100, sum their elements in a third array and print the
results.

Input:
10

Output:

Array 1 elements:
42 68 35 1 70 25 79 59 63 65

Array 2 elements:
6 46 82 28 62 92 96 43 28 37

Sum of array1 and array2 elements: 
48 114 117 29 132 117 175 102 91 102

=========================================================================

"""
import random

def random_number(start: int, end: int) -> int:
    """
    Generates a random number within the given range [start, end].
    """
    return random.randint(start, end)

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

def fill_array_with_random_numbers(arr_length: int) -> list:
    """
    Fills a list with random numbers between 1 and 100.
    """
    return [random_number(1, 100) for _ in range(arr_length)]

def sum_of_two_arrays(arr1: list, arr2: list) -> list:
    """
    Computes the sum of corresponding elements in two lists.
    """
    return [arr1[i] + arr2[i] for i in range(len(arr1))]

def print_array(arr: list):
    """
    Prints the elements of an array.
    """
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    # Read the number of elements
    arr_length = read_positive_number("How many elements?\n")

    # Generate two random arrays
    arr1 = fill_array_with_random_numbers(arr_length)
    arr2 = fill_array_with_random_numbers(arr_length)

    # Compute sum of the two arrays
    arr_sum = sum_of_two_arrays(arr1, arr2)

    # Display results
    print("\nArray 1 elements:")
    print_array(arr1)

    print("\nArray 2 elements:")
    print_array(arr2)

    print("\nSum of array1 and array2 elements:")
    print_array(arr_sum)
