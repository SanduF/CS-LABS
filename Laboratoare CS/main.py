def permute(key, permutation_table):
    return ''.join(key[i - 1] for i in permutation_table)

def generate_round_keys(initial_key):
    # Initial key permutation choice 1 (PC-1)
    pc1 = [57, 49, 41, 33, 25, 17, 9,
           1, 58, 50, 42, 34, 26, 18,
           10, 2, 59, 51, 43, 35, 27,
           19, 11, 3, 60, 52, 44, 36,
           63, 55, 47, 39, 31, 23, 15,
           7, 62, 54, 46, 38, 30, 22,
           14, 6, 61, 53, 45, 37, 29,
           21, 13, 5, 28, 20, 12, 4]

    # Split the 56-bit key into two halves, C and D
    c, d = initial_key[:28], initial_key[28:]

    round_keys = []

    for i in range(16):
        # Perform circular left shift
        c = c[1:] + c[0]
        d = d[1:] + d[0]

        # Concatenate and permute to get the round key
        round_key = permute(c + d, pc1)

        round_keys.append(round_key)

    return round_keys

def main():
    # Example initial key (64-bit)
    initial_key = "1101001100110100010101110111100110011011101111001101111111110001"

    round_keys = generate_round_keys(initial_key)

    # Display all 16 round keys
    for i, key in enumerate(round_keys):
        print(f"Round Key {i+1}: {key}")

if __name__ == "__main__":
    main()
