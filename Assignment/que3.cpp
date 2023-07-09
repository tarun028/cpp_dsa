#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

// Function to construct LR(0) items
void constructLR0Items(const vector<string>& productions, map<string, set<string>>& lr0Items) {
    for (const string& production : productions) {
        string lhs = production.substr(0, production.find("->"));
        string rhs = production.substr(production.find("->") + 2);
        set<string> items;
        items.insert("." + rhs);
        lr0Items[lhs] = items;
    }
}

// Function to generate parsing table from LR(0) items
void generateParsingTable(const map<string, set<string>>& lr0Items, map<pair<string, string>, string>& parsingTable) {
    for (const auto& item : lr0Items) {
        string lhs = item.first;
        const set<string>& items = item.second;
        for (const string& itemStr : items) {
            string symbol = itemStr.substr(itemStr.find(".") + 1, 1);
            if (symbol == "")
                parsingTable[make_pair(lhs, "$")] = "Accept";
            else
                parsingTable[make_pair(lhs, symbol)] = "Shift";
        }
    }
}

int main() {
    // Define the grammar productions
    vector<string> productions = {
        "E -> E + T",
        "E -> T",
        "T -> T * F",
        "T -> F",
        "F -> ( E )",
        "F -> id"
    };
    
    // Construct LR(0) items
    map<string, set<string>> lr0Items;
    constructLR0Items(productions, lr0Items);
    
    // Generate parsing table
    map<pair<string, string>, string> parsingTable;
    generateParsingTable(lr0Items, parsingTable);
    
    // Display the LR(0) items
    cout << "LR(0) Items:\n";
    for (const auto& item : lr0Items) {
        cout << item.first << " -> ";
        for (const string& str : item.second)
            cout << str << " ";
        cout << endl;
    }
    
    // Display the parsing table
    cout << "\nParsing Table:\n";
    for (const auto& entry : parsingTable) {
        cout << "(" << entry.first.first << ", " << entry.first.second << ") -> " << entry.second << endl;
    }
    
    return 0;
}
