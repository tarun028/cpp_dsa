#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // Define the grammar productions
    string productions[] = {
        "S -> aAb",
        "A -> a",
        "A -> ε"
    };

    // Define the LL(1) parsing table
    unordered_set<char> nonTerminals = {'S', 'A'};
    unordered_set<char> terminals = {'a', 'b'};
    unordered_set<char> epsilon = {'e'};
    unordered_set<char> nullable = {'A'};
    unordered_set<char> firstOfA = {'a', 'e'};
    unordered_set<char> followOfS = {'$', 'b'};
    unordered_set<char> followOfA = {'b'};

    // Check if the grammar is LL(1)
    bool isLL1 = true;
    for (int i = 0; i < 3; i++) {
        char nonTerm = productions[i][0];
        char firstSymbol = productions[i][5];

        if (nonTerminals.count(firstSymbol) > 0) {
            if (nullable.count(nonTerm) > 0) {
                for (const auto& terminal : followOfA) {
                    if (firstOfA.count(terminal) > 0) {
                        isLL1 = false;
                        break;
                    }
                }
            } else {
                for (const auto& terminal : firstOfA) {
                    if (firstOfA.count(terminal) > 0) {
                        isLL1 = false;
                        break;
                    }
                }
            }
        }
    }

    // Output the result
    if (isLL1) {
        cout << "The given grammar is LL(1)." << endl;
    } else {
        cout << "The given grammar is not LL(1)." << endl;
    }

    return 0;
}
