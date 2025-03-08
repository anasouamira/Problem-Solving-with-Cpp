"""
Problem20 |===============================================

Write a program to print random Small letter, Capital Letter
Special character, and Digit order

Output :
i
G
$
7
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

# Generate and print random characters of different types
print(get_random_character(CharType.SMALL_LETTER))
print(get_random_character(CharType.CAPITAL_LETTER))
print(get_random_character(CharType.SPECIAL_CHARACTER))
print(get_random_character(CharType.DIGIT))
