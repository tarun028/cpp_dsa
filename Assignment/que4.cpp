#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct LR1Item {
  string production;
  int dot;
  char lookahead;
};

vector<LR1Item> getLR1Items(const vector<string>& productions) {
  vector<LR1Item> lr1_items;
  for (int i = 0; i < productions.size(); i++) {
    string production = productions[i];
    int dot = 0;
    while (dot < production.length()) {
      lr1_items.push_back({production, dot, production[dot]});
      dot++;
    }
  }
  return lr1_items;
}

void printLR1Items(const vector<LR1Item>& lr1_items) {
  for (const LR1Item& item : lr1_items) {
    cout << item.production << " " << item.dot << " " << item.lookahead << endl;
  }
}

class LR1Table {
  vector<vector<char>> table;

public:
  LR1Table(const vector<LR1Item>& lr1_items) {
    table.resize(lr1_items.size());
    for (int i = 0; i < lr1_items.size(); i++) {
      table[i].resize(256);
    }

    for (int i = 0; i < lr1_items.size(); i++) {
      LR1Item item = lr1_items[i];
      for (int j = 0; j < 256; j++) {
        if (item.lookahead == j) {
          table[i][j] = item.production[item.dot + 1];
        }
      }
    }

    // Add CLR(1) items
    for (int i = 0; i < lr1_items.size(); i++) {
      for (int j = 0; j < 256; j++) {
        if (table[i][j] != '\0') {
          continue;
        }

        LR1Item item = lr1_items[i];
        string production = item.production;
        int dot = item.dot;
        char lookahead = item.lookahead;

        while (dot < production.length()) {
          if (production[dot] == j) {
            table[i][j] = production[dot + 1];
            break;
          }
          dot++;
        }
      }
    }
  }

  char get(int state, char lookahead) {
    return table[state][lookahead];
  }
};

int main() {
  vector<string> productions = {
    "S -> AB",
    "A -> a",
    "B -> b",
  };
  vector<LR1Item> lr1_items = getLR1Items(productions);
  printLR1Items(lr1_items);

  LR1Table table(lr1_items);

  for (int i = 0; i < lr1_items.size(); i++) {
    cout << i << ": ";
    for (int j = 0; j < 256; j++) {
      cout << table.get(i, j);
    }
    cout << endl;
  }

  return 0;
}
