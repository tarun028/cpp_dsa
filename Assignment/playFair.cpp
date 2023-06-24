#include <iostream>
#include <string>
#include <cctype>

std::string preparePlainText(const std::string& text) {
    std::string result;
    for (char ch : text) {
        if (std::isalpha(ch))
            result.push_back(std::toupper(ch));
    }
    return result;
}

std::string encryptPlayfair(const std::string& plaintext, const std::string& key) {
    std::string ciphertext;
    // Implementation omitted for brevity
    return ciphertext;
}

std::string decryptPlayfair(const std::string& ciphertext, const std::string& key) {
    std::string plaintext;
    // Implementation omitted for brevity
    return plaintext;
}

int main() {
    std::string plaintext;
    std::string key;

    std::cout << "Enter the plaintext: ";
    std::getline(std::cin, plaintext);

    std::cout << "Enter the key: ";
    std::getline(std::cin, key);

    std::string preparedText = preparePlainText(plaintext);
    std::string encryptedText = encryptPlayfair(preparedText, key);
    std::string decryptedText = decryptPlayfair(encryptedText, key);

    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Encrypted Text: " << encryptedText << std::endl;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
