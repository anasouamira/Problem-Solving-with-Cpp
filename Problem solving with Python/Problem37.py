"""
Problem 37 |=================================================
Write a program to fill array with max size 100 with random numbers from
110 100, copy it to another array using AddArrayElement, and print it.

Input
10 

Output:

Array 1 elements:

1 47 51 18 85 62 51 61 82 4

Array 2 elements after copy:

1 47 51 18 85 62 51 61 82 4
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

def add_array_element(number: int, arr: list):
    """
    Adds an element to the list.
    """
    arr.append(number)

def copy_array_using_add_array_element(arr_source: list) -> list:
    """
    Copies elements from one list to another using the add_array_element function.
    """
    arr_destination = []
    for num in arr_source:
        add_array_element(num, arr_destination)
    return arr_destination

if __name__ == "__main__":
    # Seed the random number generator
    random.seed()

    arr = fill_array_with_random_numbers()
    arr2 = copy_array_using_add_array_element(arr)

    print("\nArray 1 elements:")
    print_array(arr)

    print("\nArray 2 elements after copy:")
    print_array(arr2)

