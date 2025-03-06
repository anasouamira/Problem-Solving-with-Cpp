"""
Problem12 |===============================================

Write a program to read a number and print letter pattern 
as follows?

Input : 
5

Output : 
55555
4444
333
22
1
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

def print_inverted_pattern(number: int) -> None:
    """
    Prints an inverted numeric pattern.

    Args:
    number (int): The number of rows in the pattern.
    """
    for i in range(number, 0, -1):  # Loop from number down to 1
        print(str(i) * i)  # Print 'i' repeated 'i' times

# Main function execution
if __name__ == "__main__":
    num = read_positive_number("Enter a number to print the inverted pattern: ")
    print_inverted_pattern(num)


