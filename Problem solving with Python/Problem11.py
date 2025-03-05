"""
Problem11 |===============================================

Write a program to read a number and check if is Palindrome?

Input : 
1234
12321

Output : 
No, it is Not a Palindrome number.
Yes, it is a Palindrome number.
==========================================================
"""

def read_positive_number(message):
    """
    Reads a positive integer from the user.
    """
    number = -1
    while number < 0:
        try:
            number = int(input(message))
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


def check_palindrome_number(number, reversed_number):
    """
    Checks if a number is a palindrome.
    """
    return "Yes, it is a Palindrome number." if number == reversed_number else "No, it is NOT a Palindrome number."


if __name__ == "__main__":
    # Read a positive number and check if it is a palindrome
    number = read_positive_number("Enter Number to check if it is a Palindrome Number: ")
    reversed_number = reverse_number(number)

    # Output the result
    print(check_palindrome_number(number, reversed_number))
