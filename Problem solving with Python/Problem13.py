"""
Problem13 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
1
22
333
4444
55555
==========================================================
"""


def read_positive_number(message: str) -> int:
    """
    Reads a positive integer from the user.

    Args:
    message (str): The message prompt for user input.

    Returns:
    int: A positive integer entered by the user.
    """
    while True:
        try:
            number = int(input(message))
            if number > 0:
                return number
            print("Please enter a positive number.")
        except ValueError:
            print("Invalid input. Please enter a valid integer.")

def print_right_aligned_pattern(number: int) -> None:
    """
    Prints a right-aligned numeric pattern.

    Args:
    number (int): The number of rows in the pattern.
    """
    for i in range(1, number + 1):  # Start from 1 and go up to the given number
        print(str(i) * i)  # Print 'i' repeated 'i' times

# Main function execution
if __name__ == "__main__":
    num = read_positive_number("Enter a number to print the pattern: ")
    print_right_aligned_pattern(num)
