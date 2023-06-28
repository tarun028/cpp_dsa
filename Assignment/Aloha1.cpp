#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map<char, unordered_set<int>> firstpos, lastpos;
unordered_map<char, unordered_set<int>> follow;

void computeFirstpos(const string& regex, int pos) {
    if (isalpha(regex[pos])) {
        firstpos[regex[pos]].insert(pos);
    } else {
        switch (regex[pos]) {
            case '*':
                computeFirstpos(regex, pos - 1);
                break;
            case '.':
                computeFirstpos(regex, pos - 1);
                computeFirstpos(regex, pos - 2);
                break;
            case '|':
                computeFirstpos(regex, pos - 1);
                computeFirstpos(regex, pos - 2);
                break;
        }
    }
}

void computeLastpos(const string& regex, int pos) {
    if (isalpha(regex[pos])) {
        lastpos[regex[pos]].insert(pos);
    } else {
        switch (regex[pos]) {
            case '*':
                computeLastpos(regex, pos - 1);
                break;
            case '.':
                computeLastpos(regex, pos - 1);
                computeLastpos(regex, pos - 2);
                break;
            case '|':
                computeLastpos(regex, pos - 1);
                computeLastpos(regex, pos - 2);
                break;
        }
    }
}

void computeFollow(const string& regex, int pos) {
    if (isalpha(regex[pos])) {
        return;
    } else {
        switch (regex[pos]) {
            case '*':
                computeFollow(regex, pos - 1);
                break;
            case '.':
                computeFollow(regex, pos - 1);
                computeFollow(regex, pos - 2);
                for (int last : lastpos[regex[pos - 1]]) {
                    follow[regex[last]].insert(firstpos[regex[pos - 2]].begin(), firstpos[regex[pos - 2]].end());
                }
                break;
            case '|':
                computeFollow(regex, pos - 1);
                computeFollow(regex, pos - 2);
                break;
        }
    }
}

int main() {
    string regex;
    cout << "Enter the regular expression: ";
    cin >> regex;

    computeFirstpos(regex, regex.length() - 1);
    computeLastpos(regex, regex.length() - 1);
    computeFollow(regex, regex.length() - 1);

    cout << "Firstpos:\n";
    for (auto& entry : firstpos) {
        cout << entry.first << ": ";
        for (int pos : entry.second) {
            cout << pos << " ";
        }
        cout << endl;
    }

    cout << "Lastpos:\n";
    for (auto& entry : lastpos) {
        cout << entry.first << ": ";
        for (int pos : entry.second) {
            cout << pos << " ";
        }
        cout << endl;
    }

    cout << "Follow:\n";
    for (auto& entry : follow) {
        cout << entry.first << ": ";
        for (int pos : entry.second) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}
