"""
Problem 43 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print the count of Even numbers.

Input:
10

Output:
Array Elements: 14 92 70 15 58 76 84 62 10 43
Even Numbers count is: 8
=============================================================

"""
import random

def random_number(start, end):
    """
    Generates a random number between start and end (inclusive).
    Args:
        start (int): Lower bound of the range.
        end (int): Upper bound of the range.
    Returns:
        int: Random number in the given range.
    """
    return random.randint(start, end)

def fill_array_with_random_numbers():
    """
    Fills a list with random numbers.
    Returns:
        list: A list of random numbers.
    """
    arr_length = int(input("\nEnter number of elements:\n"))
    return [random_number(1, 100) for _ in range(arr_length)]

def print_array(arr):
    """
    Prints the elements of a list.
    Args:
        arr (list): The list to print.
    """
    print(" ".join(map(str, arr)))

def even_count(arr):
    """
    Counts the number of even numbers in the list.
    Args:
        arr (list): The list to analyze.
    Returns:
        int: The count of even numbers.
    """
    return sum(1 for num in arr if num % 2 == 0)

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    arr = fill_array_with_random_numbers()

    print("\nArray Elements: ")
    print_array(arr)

    print("\nEven Numbers count is:", even_count(arr))

