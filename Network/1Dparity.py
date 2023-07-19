def crc_division(message, generator_polynomial):
    remainder = message[:]
    generator_len = len(generator_polynomial)

    # Pad the message with zeros
    remainder.extend([0] * (generator_len - 1))

    # Perform the CRC division process
    for i in range(len(remainder) - generator_len + 1):
        if remainder[i] == 1:
            for j in range(generator_len):
                remainder[i + j] ^= generator_polynomial[j]

    # Return the final value of the remainder (CRC value)
    return remainder[-(generator_len - 1):]

def main():
    # Read message from the user
    message = list(map(int, input("Enter the message (binary): ")))

    # Read generator polynomial from the user
    generator_polynomial = list(map(int, input("Enter the generator polynomial (binary): ")))

    # Calculate CRC value
    crc_value = crc_division(message, generator_polynomial)

    # Append the CRC value to the original message
    transmitted_message = message + crc_value

    # Display the transmitted message with the CRC value
    print("Transmitted Message with CRC:", transmitted_message)

if __name__ == "__main__":
    main()
