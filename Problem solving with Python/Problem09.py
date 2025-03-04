"""
Problem09 |===============================================

Write a program to read a number, then print all digit
frequency in that number

Input : 
1223222

Output :

Digit 1 Frequency is 1 Time(s).
Digit 2 Frequency is 5 Time(s).
Digit 3 Frequency is 1 Time(s).

==========================================================
"""


def read_positive_number(message):
    """
    Function to read a positive number from the user.
    
    :param message: The message to prompt the user.
    :return: A validated positive integer.
    """
    while True:
        try:
            number = int(input(message))
            if number > 0:
                return number
            print("Please enter a positive number.")
        except ValueError:
            print("Invalid input. Please enter a valid integer.")

def count_digit_frequency(digit_to_check, number):
    """
    Function to count the frequency of a specific digit in a given number.

    :param digit_to_check: The digit whose frequency is to be counted.
    :param number: The number to check within.
    :return: The frequency count of the digit in the number.
    """
    freq_count = 0

    while number > 0:
        remainder = number % 10  # Extract the last digit
        number //= 10  # Remove the last digit
        if digit_to_check == remainder:
            freq_count += 1  # Increment the frequency counter if digit matches

    return freq_count

def print_digit_frequency(number):
    """
    Function to print the frequency of each digit (1-9) in a given number.

    :param number: The number whose digit frequency is to be checked.
    """
    for digit_to_check in range(1, 10):
        digit_frequency = count_digit_frequency(digit_to_check, number)

        if digit_frequency > 0:
            print(f"\nDigit {digit_to_check} Frequency is {digit_frequency} Time(s).")

# Main execution
if __name__ == "__main__":
    num = read_positive_number("Please enter the main number: ")
    print_digit_frequency(num)
