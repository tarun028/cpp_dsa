#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int i, flag = 0;
    char str[10];
    char a[8][10] = {"printf", "scanf", "if", "else", "break", "for", "while", "continue"};

    cout << "Enter a string: ";
    cin >> str;

    for (i = 0; i < 8; i++) {
        if (strcmp(str, a[i]) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        cout << str << " is a keyword." << endl;
    } else {
        cout << str << " is not a keyword." << endl;
    }

    return 0;
}
