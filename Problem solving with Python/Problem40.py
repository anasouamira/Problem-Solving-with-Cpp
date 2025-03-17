"""
Problem 40 |=================================================
Write a program to fill array with numbers, then print distinct
numbers to another array.

Output:

Array 1 elements:

10 10 10 50 50 70 70 70 70 90

Array 2 distinct elements:
10 50 70 90
=============================================================
"""
def fill_array():
    """
    Fills a list with predefined numbers.
    Returns:
        list: The list containing predefined numbers.
    """
    return [10, 10, 10, 50, 50, 70, 70, 70, 70, 90]

def print_array(arr):
    """
    Prints the elements of a list.
    """
    print(" ".join(map(str, arr)))

def copy_distinct_numbers(arr_source):
    """
    Copies distinct numbers from one list to another.
    Returns:
        list: A new list containing only distinct numbers from arr_source.
    """
    return list(dict.fromkeys(arr_source))  # Removes duplicates while preserving order

if __name__ == "__main__":
    arr_source = fill_array()

    print("\nArray 1 elements:")
    print_array(arr_source)

    arr_destination = copy_distinct_numbers(arr_source)

    print("\nArray 2 distinct elements:")
    print_array(arr_destination)

