"""
Problem10 |===============================================

Write a program to read a number and print it in order from 
left to right.

Input : 
1234

Output : 
1
2
3
4
==========================================================
"""

def read_positive_number(message):
    """
    Reads a positive integer from the user.
    """
    number = 0
    while number <= 0:
        try:
            number = int(input(message + "\n"))
        except ValueError:
            print("Invalid input. Please enter a positive integer.")
    return number


def reverse_number(number):
    """
    Reverses the digits of the given number.
    """
    reversed_number = 0
    while number > 0:
        remainder = number % 10  # Extract last digit
        number = number // 10  # Remove last digit
        reversed_number = reversed_number * 10 + remainder  # Append digit to reversed number
    return reversed_number


def print_digits(number):
    """
    Prints the digits of a number one by one.
    """
    while number > 0:
        remainder = number % 10  # Extract last digit
        number = number // 10  # Remove last digit
        print(remainder)


if __name__ == "__main__":
    # Read a positive number, reverse it, and print its digits
    print_digits(reverse_number(read_positive_number("Please enter a positive number: ")))