"""
Problem14 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
EEEEE
DDDD
CCC
BB
A
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

def print_inverted_letter_pattern(number: int) -> None:
    """
    Prints an inverted pattern of letters starting from 'A'.

    Args:
    number (int): The number of rows in the pattern.
    """
    start_letter = ord('A') + (number - 1)  # Calculate the starting ASCII letter

    for i in range(start_letter, ord('A') - 1, -1):  # Iterate from start_letter to 'A'
        print(chr(i) * number)  # Print the letter 'i' repeated 'number' times
        number -= 1  # Decrease the count for the next row

# Main function execution
if __name__ == "__main__":
    num = read_positive_number("Enter a number to print the inverted pattern: ")
    print_inverted_letter_pattern(num)


