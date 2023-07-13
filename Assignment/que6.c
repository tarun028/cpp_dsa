#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTIONS 100
#define MAX_SYMBOLS 100

struct LR1Item {
  char production[MAX_PRODUCTIONS];
  int dot;
  char lookahead;
};

struct LR1Table {
  char state[MAX_SYMBOLS];
};

void getLR1Items(const char* productions[], int num_productions, struct LR1Item* lr1_items) {
  for (int i = 0; i < num_productions; i++) {
    char* production = productions[i];
    int dot = 0;
    while (dot < strlen(production)) {
      lr1_items[i * MAX_SYMBOLS + production[dot]] = {production, dot, production[dot]};
      dot++;
    }
  }
}

void printLR1Items(const struct LR1Item* lr1_items, int num_items) {
  for (int i = 0; i < num_items; i++) {
    printf("%s %d %c\n", lr1_items[i].production, lr1_items[i].dot, lr1_items[i].lookahead);
  }
}

void getLR1Table(const struct LR1Item* lr1_items, int num_items, struct LR1Table* table) {
  for (int i = 0; i < num_items; i++) {
    for (int j = 0; j < MAX_SYMBOLS; j++) {
      table[i].state[j] = '\0';
    }
  }

  for (int i = 0; i < num_items; i++) {
    char production[MAX_PRODUCTIONS];
    int dot = lr1_items[i].dot;
    char lookahead = lr1_items[i].lookahead;
    strcpy(production, lr1_items[i].production);

    while (dot < strlen(production)) {
      if (production[dot] == lookahead) {
        table[i].state[lookahead] = production[dot + 1];
      }
      dot++;
    }
  }
}

int main() {
  char* productions[] = {
    "S -> AB",
    "A -> a",
    "B -> b",
  };
  int num_productions = sizeof(productions) / sizeof(productions[0]);

  struct LR1Item lr1_items[num_productions * MAX_SYMBOLS];
  getLR1Items(productions, num_productions, lr1_items);
  printLR1Items(lr1_items, num_productions * MAX_SYMBOLS);

  struct LR1Table table[num_productions * MAX_SYMBOLS];
  getLR1Table(lr1_items, num_productions * MAX_SYMBOLS, table);

  char input[] = "ab";
  int state = 0;
  for (char c : input) {
    char next_state = table[state].state[c];
    if (next_state == '\0') {
      printf("Input string is not derivable.\n");
      return 0;
    }
    state = next_state;
  }

  printf("Input string is derivable.\n");

  return 0;
}
