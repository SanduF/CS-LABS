def caesar_two_key_cipher(text, key1, key2, mode):
    # Check if the keys are within the allowed range
    if not (1 <= key1 <= 25) or not (7 <= len(key2) <= 25):
        return "Key 1 should be between 1 and 25 (inclusive), and Key 2 should be at least 7 characters long and contain only Latin alphabet letters."

    # Convert the text to uppercase and remove spaces
    text = text.replace(" ", "").upper()

    result = ""
    key2 = key2.upper()

    key2_index = 0
    for char in text:
        if char.isalpha():
            if mode == "encrypt":
                if char.isupper():
                    shifted = (ord(char) - 65 + key1 + (ord(key2[key2_index % len(key2)]) - 65)) % 26 + 65
                else:
                    shifted = (ord(char) - 97 + key1 + (ord(key2[key2_index % len(key2)]) - 65)) % 26 + 97
                result += chr(shifted)
            elif mode == "decrypt":
                if char.isupper():
                    shifted = (ord(char) - 65 - key1 - (ord(key2[key2_index % len(key2)]) - 65)) % 26 + 65
                else:
                    shifted = (ord(char) - 97 - key1 - (ord(key2[key2_index % len(key2)]) - 65)) % 26 + 97
                result += chr(shifted)
            key2_index += 1
        else:
            return "Only alphabetic characters are allowed in the text."

    return result


def main():
    mode = input("Enter 'encrypt' for encryption or 'decrypt' for decryption: ").lower()

    key1 = int(input("Enter the first key value (between 1 and 25): "))

    key2 = input("Enter the second key (at least 7 characters long, containing only Latin alphabet letters): ")

    text = input("Enter the message or cryptogram: ")

    # Perform encryption or decryption based on user input
    result = caesar_two_key_cipher(text, key1, key2, mode)
    print(f"Result: {result}")


if __name__ == "__main__":
    main()
