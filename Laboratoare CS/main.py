def caesar_cipher(text, key, mode):
    # Check if the key is within the allowed range
    if key < 1 or key > 25:
        return "Key value should be between 1 and 25 (inclusive)."

    # Convert the text to uppercase and remove spaces
    text = text.replace(" ", "").upper()

    result = ""
    if mode == "encrypt":
        for char in text:
            if char.isalpha():
                shifted = ord(char) + key
                if shifted > ord('Z'):
                    shifted -= 26
                result += chr(shifted)
            else:
                return "Only alphabetic characters are allowed in the text."
    elif mode == "decrypt":
        for char in text:
            if char.isalpha():
                shifted = ord(char) - key
                if shifted < ord('A'):
                    shifted += 26
                result += chr(shifted)
            else:
                return "Only alphabetic characters are allowed in the text."
    else:
        return "Invalid mode. Please choose 'encrypt' or 'decrypt'."

    return result

def main():
    mode = input("Enter 'encrypt' for encryption or 'decrypt' for decryption: ").lower()

    key = int(input("Enter the key value (between 1 and 25): "))

    text = input("Enter the message or cryptogram: ")

    # Perform encryption or decryption based on user input
    result = caesar_cipher(text, key, mode)
    print(f"Result: {result}")

if __name__ == "__main__":
    main()
