"""
Problem 45 |=================================================
Write a program fo fill array with max size 100 with random
numbers from -100 to 100, then print the count of Negative
numbers.

Input:
10

Output:

Array Elements: -58 -16 -21 -4 -91 82 98 66 -8 -33

Negative Numbers count is: 7
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
    Fills a list with random numbers in the range -100 to 100.
    
    Returns:
        list: A list of random numbers.
    """
    arr_length = int(input("\nEnter number of elements:\n"))
    return [random_number(-100, 100) for _ in range(arr_length)]

def print_array(arr):
    """
    Prints the elements of a list.
    
    Args:
        arr (list): The list to print.
    """
    print(" ".join(map(str, arr)))

def negative_count(arr):
    """
    Counts the number of negative numbers in the list.
    
    Args:
        arr (list): The list to analyze.
        
    Returns:
        int: The count of negative numbers.
    """
    return sum(1 for num in arr if num < 0)

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    arr = fill_array_with_random_numbers()

    print("\nArray Elements: ")
    print_array(arr)

    print("\nNegative Numbers count is:", negative_count(arr))

