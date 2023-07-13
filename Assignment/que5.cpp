#include <iostream>
#include <vector>

using namespace std;

struct LR1Item {
  string production;
  int dot;
  char lookahead;
};

vector<LR1Item> getLR1Items(const vector<string>& productions);
void printLR1Items(const vector<LR1Item>& lr1_items);

int main() {
  vector<string> productions = {
    "S -> AB",
    "A -> a",
    "B -> b",
  };
  vector<LR1Item> lr1_items = getLR1Items(productions);
  printLR1Items(lr1_items);

  return 0;
}

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
