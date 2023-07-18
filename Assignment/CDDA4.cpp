#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> tokenize(const string& str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<vector<string>> convertToQuadruples(const string& code) {
    vector<vector<string>> quadruples;
    vector<string> lines = tokenize(code, '\n');

    for (const string& line : lines) {
        vector<string> tokens = tokenize(line, ' ');
        quadruples.push_back(tokens);
    }

    return quadruples;
}

vector<vector<string>> convertToTriples(const string& code) {
    vector<vector<string>> triples;
    vector<string> lines = tokenize(code, '\n');

    for (const string& line : lines) {
        vector<string> tokens = tokenize(line, ' ');
        if (tokens[1] == "=") {
            vector<string> triple = {tokens[3], tokens[2], tokens[0]};
            triples.push_back(triple);
        } else {
            vector<string> triple = {tokens[0], tokens[1], tokens[3]};
            triples.push_back(triple);
        }
    }

    return triples;
}

vector<vector<string>> convertToIndirectTriples(const string& code) {
    vector<vector<string>> indirectTriples;
    vector<string> lines = tokenize(code, '\n');

    for (const string& line : lines) {
        vector<string> tokens = tokenize(line, ' ');
        if (tokens[1] == "=") {
            vector<string> indirectTriple = {tokens[3], tokens[2], tokens[0]};
            indirectTriples.push_back(indirectTriple);
        } else {
            vector<string> indirectTriple = {tokens[0], "", tokens[2]};
            indirectTriples.push_back(indirectTriple);
        }
    }

    return indirectTriples;
}

int main() {
    string threeAddressCode = "t1 = b * c\nt2 = a + t1\nt3 = d % e\nt4 = t2 - t3";

    vector<vector<string>> quadruples = convertToQuadruples(threeAddressCode);
    cout << "Quadruples:\n";
    for (const vector<string>& quad : quadruples) {
        for (const string& element : quad) {
            cout << element << " ";
        }
        cout << endl;
    }

    vector<vector<string>> triples = convertToTriples(threeAddressCode);
    cout << "\nTriples:\n";
    for (const vector<string>& triple : triples) {
        for (const string& element : triple) {
            cout << element << " ";
        }
        cout << endl;
    }

    vector<vector<string>> indirectTriples = convertToIndirectTriples(threeAddressCode);
    cout << "\nIndirect Triples:\n";
    for (const vector<string>& indirectTriple : indirectTriples) {
        for (const string& element : indirectTriple) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
