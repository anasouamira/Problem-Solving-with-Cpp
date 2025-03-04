

"""
Problem05 |===============================================

Write a program to read a number and print it in a reversed
order. 

Input : 
1234

Output : 
4
3
2
1
==========================================================
"""
def read_positive_number(message):
    """
    Function to read a positive number from the user.
    Ensures the input is greater than or equal to zero.
    """
    number = -1  # Initialize with an invalid value
    while number < 0:
        try:
            number = int(input(message))  # Read and convert input to an integer
            if number < 0:
                print("Please enter a positive number.")
        except ValueError:
            print("Invalid input. Please enter an integer.")
    return number

def print_digits_reverse(number):
    """
    Function to print the digits of a number in reverse order.
    """
    print("Reversed Number:", end=" ")
    
    while number > 0:
        remainder = number % 10  # Extract the last digit
        number = number // 10  # Remove the last digit
        print(remainder, end="")  # Print the extracted digit

    print()  # Move to a new line after printing

# Main entry point
if __name__ == "__main__":
    num = read_positive_number("Enter a number to print it in reversed order: ")
    print_digits_reverse(num)

