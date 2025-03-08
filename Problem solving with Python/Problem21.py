"""
Problem21 |===============================================

Write a program to read how many keys to generate and print
them on the screen.

Input:
5

Output:

Key [1]: ETAT-HJUV-PEIP-CFRX

Key [2]: UMCO-YSPQ-PHYK-STIL

Key [3] : QBSR-MZEC-BYNA-DSYK

Key [4]: MISQ-ULYB-ZRAZ-LMAG

Key [5] : NQCR-PPFJ-KZLF-ZHMT 
==========================================================
"""

import random
import string

def random_number(start: int, end: int) -> int:
    """
    Generates a random number between 'start' and 'end' (inclusive).
    """
    return random.randint(start, end)

class CharType:
    SMALL_LETTER = 1
    CAPITAL_LETTER = 2
    SPECIAL_CHARACTER = 3
    DIGIT = 4

def get_random_character(char_type: int) -> str:
    """
    Generates a random character based on the specified type.
    """
    if char_type == CharType.SMALL_LETTER:
        return random.choice(string.ascii_lowercase)
    elif char_type == CharType.CAPITAL_LETTER:
        return random.choice(string.ascii_uppercase)
    elif char_type == CharType.SPECIAL_CHARACTER:
        return random.choice(string.punctuation)
    elif char_type == CharType.DIGIT:
        return random.choice(string.digits)
    else:
        return ' '  # Return space if invalid type

def read_positive_number(message: str) -> int:
    """
    Reads a positive integer from the user.
    """
    while True:
        try:
            number = int(input(message))
            if number > 0:
                return number
        except ValueError:
            pass
        print("Please enter a valid positive number.")

def generate_word(char_type: int, length: int) -> str:
    """
    Generates a random word of a specified length using a given character type.
    """
    return ''.join(get_random_character(char_type) for _ in range(length))

def generate_key() -> str:
    """
    Generates a formatted key consisting of four groups of random capital letters.
    """
    return '-'.join(generate_word(CharType.CAPITAL_LETTER, 4) for _ in range(4))

def generate_keys(number_of_keys: int):
    """
    Generates and displays multiple keys based on user input.
    """
    for i in range(1, number_of_keys + 1):
        print(f"Key [{i}] : {generate_key()}")

if __name__ == "__main__":
    # Generate multiple keys based on user input
    generate_keys(read_positive_number("Please enter how many keys to generate: "))
