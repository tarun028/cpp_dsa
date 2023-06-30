import java.util.Scanner;

public class SwapNibbles {
    public static byte swapNibbles(byte b) {
        // Extract the lower nibble
        byte lowerNibble = (byte) (b & 0x0F);

        // Extract the upper nibble
        byte upperNibble = (byte) ((b >> 4) & 0x0F);

        // Swap the nibbles
        byte swappedByte = (byte) ((lowerNibble << 4) | upperNibble);

        return swappedByte;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Getting user input
        System.out.print("Enter a byte value: ");
        byte byteValue = input.nextByte();

        // Perform nibble swap
        byte swappedByte = swapNibbles(byteValue);

        // Display the result
        System.out.println("Swapped byte value: " + swappedByte);
    }
}