#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define the parsing table structure
typedef struct {
    char nonTerminal;
    char terminal;
    char production[MAX_SIZE];
} ParsingTableEntry;

int main() {
    char w[MAX_SIZE];
    ParsingTableEntry table[MAX_SIZE];
    int tableSize;

    // Read the input string 'w'
    printf("Enter the input string 'w': ");
    fgets(w, MAX_SIZE, stdin);
    w[strcspn(w, "\n")] = '\0';

    // Read the parsing table
    printf("Enter the parsing table size: ");
    scanf("%d", &tableSize);

    printf("Enter the parsing table entries:\n");
    for (int i = 0; i < tableSize; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Non-terminal: ");
        scanf(" %c", &table[i].nonTerminal);
        printf("Terminal: ");
        scanf(" %c", &table[i].terminal);
        printf("Production: ");
        scanf(" %[^\n]", table[i].production);
    }

    // Perform the top-down parsing
    int wIndex = 0;
    int stackIndex = 0;
    char stack[MAX_SIZE];
    stack[stackIndex] = '$';
    stackIndex++;
    stack[stackIndex] = table[0].nonTerminal;

    while (stack[stackIndex] != '$') {
        if (stack[stackIndex] == w[wIndex]) {
            stackIndex--;
            wIndex++;
        } else {
            int entryFound = 0;
            for (int i = 0; i < tableSize; i++) {
                if (table[i].nonTerminal == stack[stackIndex] && table[i].terminal == w[wIndex]) {
                    stackIndex--;
                    int productionLength = strlen(table[i].production);
                    for (int j = productionLength - 1; j >= 0; j--) {
                        if (table[i].production[j] != 'e') {
                            stackIndex++;
                            stack[stackIndex] = table[i].production[j];
                        }
                    }
                    entryFound = 1;
                    break;
                }
            }
            if (!entryFound) {
                printf("Error: Invalid input string!\n");
                exit(1);
            }
        }
    }

    // Check if the parsing is successful
    if (wIndex == strlen(w)) {
        printf("Parsing Successful!\n");
    } else {
        printf("Error: Invalid input string!\n");
    }

    return 0;
}
