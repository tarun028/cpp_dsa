def calculate_checksum_1d(data):
    checksum = sum(data)
    return checksum

def main_1d():
    # Read 1D array data from the user
    data = list(map(int, input("Enter 1D array data (space-separated integers): ").split()))

    # Calculate the checksum
    checksum = calculate_checksum_1d(data)

    # Append the checksum to the end of the array
    data.append(checksum)

    # Display the array with the checksum
    print("Data with checksum:", data)

if __name__ == "__main__":
    main_1d()
