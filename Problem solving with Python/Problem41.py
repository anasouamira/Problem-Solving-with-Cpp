"""
Problem 41 |=================================================
Write a program to fill array with numbers, then check if it is Palindrome
array or not, Note: Palindrome array can be read the same from right to
left and from left fo right.

Input
10 20 30 30 20 10

Output:

Array Elements:
10 20 30 30 20 10

Yes array is Palindrome 
=============================================================
"""
def fill_array():
    """
    Fills a list with predefined elements.
    Returns:
        list: A list containing the predefined elements.
    """
    return [10, 20, 30, 30, 20, 10]

def print_array(arr):
    """
    Prints the elements of a list.
    """
    print(" ".join(map(str, arr)))

def is_palindrome_array(arr):
    """
    Checks if the given list is a palindrome.
    Args:
        arr (list): The list to check.
    Returns:
        bool: True if the list is a palindrome, False otherwise.
    """
    return arr == arr[::-1]  # Checks if the list is equal to its reverse

if __name__ == "__main__":
    arr = fill_array()

    print("\nArray Elements:")
    print_array(arr)

    if is_palindrome_array(arr):
        print("\nYes, array is Palindrome")
    else:
        print("\nNo, array is NOT Palindrome")
