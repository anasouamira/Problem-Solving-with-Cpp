"""
Problem 38 |======================================================================
Write a program to fill array with max size 100 with random numbers from
110 100, copy only odd numbers to another array using AddArrayElement,and print it.

Input
10 

Output: 

Array 1 elements: 
59 14 84 36 6 51 48 91 96 67 

Array 2 Odd numbers: 
59 51 91 67 
=============================================================
"""
import random

def random_number(from_num: int, to_num: int) -> int:
    """
    Generates a random number in the given range [from_num, to_num].
    """
    return random.randint(from_num, to_num)

def fill_array_with_random_numbers() -> list:
    """
    Fills a list with random numbers between 1 and 100.
    """
    arr_length = int(input("\nEnter number of elements:\n"))
    return [random_number(1, 100) for _ in range(arr_length)]

def print_array(arr: list):
    """
    Prints the elements of a list.
    """
    print(" ".join(map(str, arr)))

def copy_odd_numbers(arr_source: list) -> list:
    """
    Copies only odd numbers from one list to another.
    """
    return [num for num in arr_source if num % 2 != 0]

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    arr = fill_array_with_random_numbers()
    arr2 = copy_odd_numbers(arr)

    print("\nArray 1 elements:")
    print_array(arr)

    print("\nArray 2 Odd numbers:")
    print_array(arr2)

