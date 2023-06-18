#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> tokenize(const string& program) {
    stringstream ss(program);
    vector<string> tokens;
    string token;

    while (getline(ss, token, ' ')) {
        // Remove leading and trailing whitespaces
        token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());

        // Ignore empty tokens
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    return tokens;
}

int main() {
    string program = "#include <iostream> int main() { std::cout << \"Hello, World!\"; return 0; }";

    vector<string> tokens = tokenize(program);

    cout << "Tokens: " << endl;
    for (const string& token : tokens) {
        cout << token << endl;
    }

    return 0;
}
