"""
Problem 39 |========================================================================
Write a program to fill array with max size 100 with random numbers from
110 100, copy only prime numbers fo another array using AddArrayElement,and print it.

Input
10

Output:

Array 1 elements:
61 100 32 75 81 95 50 98 13 70

Array 2 Prime numbers:
62 13
=============================================================
"""

import random
import math

def is_prime(number: int) -> bool:
    """
    Checks if a number is prime.
    Returns True if the number is prime, otherwise False.
    """
    if number < 2:
        return False
    for i in range(2, math.isqrt(number) + 1):
        if number % i == 0:
            return False
    return True

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

def copy_prime_numbers(arr_source: list) -> list:
    """
    Copies only prime numbers from one list to another.
    """
    return [num for num in arr_source if is_prime(num)]

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    arr = fill_array_with_random_numbers()
    arr2 = copy_prime_numbers(arr)

    print("\nArray 1 elements:")
    print_array(arr)

    print("\nArray 2 Prime numbers:")
    print_array(arr2)

