#include <iostream>
using namespace std;

int main() {
    char line[1000];
    int charCount = 0;
    int wordCount = 0;

    cout << "Enter a line of text: ";
    cin.getline(line, 1000);

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
            charCount++;
        }
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
            wordCount++;
        }
    }

    // If the line doesn't end with space or newline, increment wordCount for the last word
    if (charCount > 0) {
        wordCount++;
    }

    cout << "Number of characters: " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;

    return 0;
}
