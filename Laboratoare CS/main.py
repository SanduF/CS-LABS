def remove_spaces_and_convert_to_uppercase(text):
    # Remove spaces and convert to uppercase
    return ''.join(char.upper() for char in text if char.isalpha())

def suggest_valid_characters(valid_chars):
    print(f"Invalid characters! Please use only {', '.join(valid_chars)}")

def validate_input(input_text, valid_chars):
    # Check if input contains only valid characters
    if all(char in valid_chars for char in input_text):
        return True
    else:
        suggest_valid_characters(valid_chars)
        return False

def vigenere_cipher(message, key, alphabet_length, operation):
    result = ""
    key_index = 0

    for char in message:
        if char.isalpha():
            # Convert characters to values between 0 and 30
            m_value = ord(char) - ord('A') if char.isupper() else ord(char) - ord('a')
            k_value = ord(key[key_index]) - ord('A')

            if operation == "encrypt":
                result += chr((m_value + k_value) % alphabet_length + ord('A'))
            elif operation == "decrypt":
                result += chr((m_value - k_value + alphabet_length) % alphabet_length + ord('A'))

            key_index = (key_index + 1) % len(key)
        else:
            # Non-alphabetic characters are appended as is
            result += char

    return result

def main():
    alphabet_length = 31  # Number of letters in the Romanian alphabet
    valid_chars = set("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

    # Get operation choice from the user
    operation = input("Enter 'E' for encryption or 'D' for decryption: ").upper()

    if operation not in ['E', 'D']:
        print("Invalid operation choice. Please enter 'E' or 'D.")
        return

    # Get key from the user
    key = input("Enter the key (length should be at least 7): ")
    key = remove_spaces_and_convert_to_uppercase(key)

    if len(key) < 7:
        print("Key length should be at least 7 characters.")
        return

    # Get message or cryptogram from the user
    text = input("Enter the message or cryptogram: ")
    text = remove_spaces_and_convert_to_uppercase(text)

    # Validate input
    if not validate_input(key, valid_chars) or not validate_input(text, valid_chars):
        return

    # Encrypt or decrypt based on user choice
    if operation == 'E':
        result = vigenere_cipher(text, key, alphabet_length, "encrypt")
        print("Encrypted Message:", result)
    elif operation == 'D':
        result = vigenere_cipher(text, key, alphabet_length, "decrypt")
        print("Decrypted Message:", result)

if __name__ == "__main__":
    main()
