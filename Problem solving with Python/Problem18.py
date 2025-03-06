"""
Problem18 |===============================================

Write a program to read a text and encrypt it, decrypt it.

Input :
Anas

Output :

Text Before Encryption : Anas
Text After Encryption : Bobt
Text Before Decryption : Anas

==========================================================
"""

def read_text() -> str:
    """
    Reads text input from the user.

    Returns:
    str: The user-entered text.
    """
    return input("Please enter text:\n")

def encrypt_text(text: str, encryption_key: int) -> str:
    """
    Encrypts the given text using a simple shift cipher.

    Args:
    text (str): The text to be encrypted.
    encryption_key (int): The shift value for encryption.

    Returns:
    str: The encrypted text.
    """
    return "".join(chr(ord(char) + encryption_key) for char in text)

def decrypt_text(text: str, encryption_key: int) -> str:
    """
    Decrypts the given text by reversing the shift cipher.

    Args:
    text (str): The encrypted text.
    encryption_key (int): The shift value used for encryption.

    Returns:
    str: The decrypted text.
    """
    return "".join(chr(ord(char) - encryption_key) for char in text)

if __name__ == "__main__":
    ENCRYPTION_KEY = 2  # Encryption key value

    text = read_text()  # Read input text from user

    text_after_encryption = encrypt_text(text, ENCRYPTION_KEY)  # Encrypt the input text
    text_after_decryption = decrypt_text(text_after_encryption, ENCRYPTION_KEY)  # Decrypt the text

    # Display results
    print(f"\nText Before Encryption : {text}")
    print(f"Text After Encryption  : {text_after_encryption}")
    print(f"Text After Decryption  : {text_after_decryption}")
