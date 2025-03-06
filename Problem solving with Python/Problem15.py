"""
Problem15 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
A
BB
CCC
DDDD
EEEEE
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
    final_letter = ord('A') + (number - 1)  # Determine the final letter
    counter = 1  # Initialize the counter for the number of letters to print

    for i in range(ord('A'), final_letter + 1):  # Loop from 'A' to final_letter
        print(chr(i) * counter)  # Print the letter 'i' repeated 'counter' times
        counter += 1  # Increase the counter for the next row
        if counter > number:  # Stop when the counter exceeds the input number
            break

# Main function execution
if __name__ == "__main__":
    num = read_positive_number("Enter a number to print the inverted pattern: ")
    print_inverted_letter_pattern(num)

