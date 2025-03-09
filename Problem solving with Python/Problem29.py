"""
Problem 29 |=================================================
Write a program to fill array with max size 100 with random
numbers from 1 to 100, copy only prime numbers to another
array and print it.

Input:

10

Output:

Array 1 elements:

42 68 35 1 70 25 79 59 63 65

Prime Numbers in Array2:
179
=============================================================
"""


import random
import math

def is_prime(number: int) -> bool:
    """
    Checks if a number is prime.
    Returns True if prime, otherwise False.
    """
    if number < 2:
        return False
    for i in range(2, math.isqrt(number) + 1):
        if number % i == 0:
            return False
    return True

def random_number(start: int, end: int) -> int:
    """
    Generates a random number within the given range [start, end].
    """
    return random.randint(start, end)

def fill_array_with_random_numbers() -> list:
    """
    Fills a list with random numbers based on user input.
    """
    try:
        arr_length = int(input("\nEnter number of elements:\n"))
        return [random_number(1, 100) for _ in range(arr_length)]
    except ValueError:
        print("Invalid input. Please enter an integer.")
        return []

def copy_only_prime_numbers(arr: list) -> list:
    """
    Copies only the prime numbers from the given list to a new list.
    """
    return [num for num in arr if is_prime(num)]

def print_array(arr: list):
    """
    Prints the array elements.
    """
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    # Fill the first array with random numbers
    arr = fill_array_with_random_numbers()

    if arr:
        # Copy only prime numbers from arr to arr2
        arr2 = copy_only_prime_numbers(arr)

        print("\nArray 1 elements:")
        print_array(arr)

        print("\nPrime Numbers in Array 2:")
        print_array(arr2)

