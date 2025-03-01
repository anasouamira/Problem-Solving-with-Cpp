"""
Problem03 |===============================================

Write a program to check if the number is perfect or not?

Input : 
28
12

Output : 
28 is perfect. 
12 Not perfect.
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

def is_divisor(number, divisor):
    """
    Function to check if a number is a divisor of another.
    Returns True if divisor, otherwise False.
    """
    return number % divisor == 0

def check_perfect_number(number):
    """
    Function to check and print whether a number is a perfect number.
    A perfect number is a number whose proper divisors sum to itself.
    """
    m = number // 2  # Only check divisors up to half the number
    sum_divisors = sum(divisor for divisor in range(1, m + 1) if is_divisor(number, divisor))

    # Check if the sum of divisors equals the original number
    if sum_divisors == number:
        print(f"{number} is a Perfect number.")
    else:
        print(f"{number} is not a Perfect number.")

# Main entry point
if __name__ == "__main__":
    num = read_positive_number("Enter a positive number to check if it is perfect or not: ")
    check_perfect_number(num)



