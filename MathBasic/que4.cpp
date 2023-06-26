#include <iostream>
#include <string>
using namespace std;

bool isIdentifier(const string& str) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return false;
    }

    for (int i = 1; i < str.length(); i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return false;
        }
    }

    return false;
}

int main() {
    string input = "your_string_here";

    if (isIdentifier(input)) {
        cout << "Identifier" << endl;
    } else {
        cout << "Not Identifier" << endl;
    }

    return 0;
}
