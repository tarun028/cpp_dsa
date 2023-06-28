#include <iostream>
#include <vector>
#include <string>

// Function to check if a production rule is left recursive
bool isLeftRecursive(const std::string& rule) {
    return rule[0] == rule[3];
}

// Function to eliminate left recursion for a production rule
std::string eliminateLeftRecursion(const std::string& rule) {
    std::string nonTerminal = rule.substr(0, 1);
    std::vector<std::string> productions;
    std::string alpha, beta;
    
    // Split the rule into individual productions
    std::string productionStr = rule.substr(3);
    size_t pipePos = productionStr.find("|");
    
    while (pipePos != std::string::npos) {
        productions.push_back(productionStr.substr(0, pipePos));
        productionStr = productionStr.substr(pipePos + 1);
        pipePos = productionStr.find("|");
    }
    productions.push_back(productionStr);
    
    // Divide the productions into alpha and beta groups
    for (const std::string& prod : productions) {
        if (prod[0] == nonTerminal[0]) {
            beta += prod.substr(1) + nonTerminal + "'";
        } else {
            alpha += prod + nonTerminal + "'";
        }
    }
    
    // Construct the new productions without left recursion
    std::string newProductions;
    
    if (!alpha.empty()) {
        newProductions += nonTerminal + " -> " + alpha + " | ";
    }
    
    if (!beta.empty()) {
        newProductions += nonTerminal + "' -> " + beta + " | ε";
    } else {
        newProductions += nonTerminal + "' -> ε";
    }
    
    return newProductions;
}

int main() {
    std::vector<std::string> productionRules = {
        "S -> S a | b",
        "A -> A a | c",
        "B -> B d e | f"
    };
    
    // Process each production rule to eliminate left recursion
    for (const std::string& rule : productionRules) {
        if (isLeftRecursive(rule)) {
            std::string newProductions = eliminateLeftRecursion(rule);
            std::cout << newProductions << std::endl;
        } else {
            std::cout << rule << std::endl;
        }
    }
    
    return 0;
}
