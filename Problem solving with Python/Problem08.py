"""
Problem08 |===============================================

Write a program to read a number and Digit, then print all 
digit frequency in that number

Input : 
1223222
2

Output :

Digit 2 Frequency is 5 Time(s).

==========================================================
"""
class NumberDigit:
    """
    Class to hold a number and a specific digit to be searched within the number.
    """
    def __init__(self, number=0, digit=0):
        self.number = number
        self.digit = digit

def read_number_and_digit():
    """
    Function to read a positive number and a digit from the user.
    Ensures that both the number and digit are non-negative before returning an object.

    :return: An instance of NumberDigit with user-input values.
    """
    while True:
        try:
            number = int(input("Enter a positive number: "))
            digit = int(input("Enter a digit: "))
            
            if number < 0 or digit < 0 or digit > 9:
                print("Please enter a non-negative number and a single digit (0-9).")
                continue
            return NumberDigit(number, digit)
        except ValueError:
            print("Invalid input. Please enter integers only.")

def digit_frequency(num_digit):
    """
    Function to count the occurrences of a specific digit within a given number.

    :param num_digit: Instance of NumberDigit containing the number and the digit to be counted.
    :return: The frequency of the digit within the number.
    """
    count = 0
    temp_number = num_digit.number  # Preserve original number

    while temp_number > 0:
        remainder = temp_number % 10  # Extract the last digit
        temp_number //= 10  # Remove the last digit
        if remainder == num_digit.digit:
            count += 1  # Increment count if digit matches

    return count

# Main entry point
if __name__ == "__main__":
    num_digit = read_number_and_digit()
    print(f"Digit {num_digit.digit} Frequency is {digit_frequency(num_digit)} times")
