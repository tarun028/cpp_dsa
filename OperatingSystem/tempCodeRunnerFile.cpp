#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to prepare the key and construct the Playfair Square
string prepareKey(string key) {
    // Convert the key to uppercase and remove duplicate letters
    key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    string playfairSquare = key;

    // Fill the remaining positions in the Playfair Square with unique letters (excluding 'J')
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch != 'J' && key.find(ch) == string::npos) {
            playfairSquare += ch;
        }
    }

    return playfairSquare;
}

// Function to find the positions of a letter in the Playfair Square
void findPosition(const string& playfairSquare, char ch, int& row, int& col) {
    int pos = playfairSquare.find(ch);
    row = pos / 5;
    col = pos % 5;
}

// Function to encrypt a pair of letters using the Playfair Square
string encryptDigraph(const string& playfairSquare, char a, char b) {
    int row1, col1, row2, col2;
    findPosition(playfairSquare, a, row1, col1);
    findPosition(playfairSquare, b, row2, col2);

    if (row1 == row2) { // Same row, shift columns
        col1 = (col1 + 1) % 5;
        col2 = (col2 + 1) % 5;
    } else if (col1 == col2) { // Same column, shift rows
        row1 = (row1 + 1) % 5;
        row2 = (row2 + 1) % 5;
    } else { // Rectangle, swap columns
        swap(col1, col2);
    }

    return string(1, playfairSquare[row1 * 5 + col1]) + playfairSquare[row2 * 5 + col2];
}

// Function to encrypt plaintext using the Playfair Cipher
string playfairEncrypt(const string& playfairSquare, const string& plaintext) {
    string encryptedText;
    string cleanPlaintext;
    for (char ch : plaintext) {
        if (ch >= 'A' && ch <= 'Z') {
            cleanPlaintext += ch;
        }
    }

    int len = cleanPlaintext.length();
    for (int i = 0; i < len; i += 2) {
        char a = cleanPlaintext[i];
        char b = (i + 1 < len) ? cleanPlaintext[i + 1] : 'X';

        if (a == b) {
            b = 'X';
            i--;
        }

        encryptedText += encryptDigraph(playfairSquare, a, b);
    }

    return encryptedText;
}

int main() {
    string key, plaintext;
    cout << "Enter the key: ";
    getline(cin, key);

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Prepare the Playfair Square from the key
    string playfairSquare = prepareKey(key);

    // Encrypt the plaintext using the Playfair Cipher
    string ciphertext = playfairEncrypt(playfairSquare, plaintext);

    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
