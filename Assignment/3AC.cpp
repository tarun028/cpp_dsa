#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '%';
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '%')
        return 2;
    return 0;
}

string generate3AddressCode(string expression) {
    stack<string> operands;
    stack<char> operators;
    string tempVar = "t1";
    string code;

    for (int i = 0; i < expression.length(); i++) {
        char currentChar = expression[i];

        if (currentChar == ' ')
            continue;

        if (isdigit(currentChar) || isalpha(currentChar)) {
            operands.push(string(1, currentChar));
        } else if (currentChar == '(') {
            operators.push(currentChar);
        } else if (currentChar == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                code += tempVar + " = " + op1 + " " + op + " " + op2 + "\n";
                operands.push(tempVar);
                tempVar[1]++; // Increment the temporary variable number
            }
            operators.pop(); // Pop the opening parenthesis
        } else if (isOperator(currentChar)) {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(currentChar)) {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                code += tempVar + " = " + op1 + " " + op + " " + op2 + "\n";
                operands.push(tempVar);
                tempVar[1]++; // Increment the temporary variable number
            }
            operators.push(currentChar);
        }
    }

    while (!operators.empty()) {
        string op2 = operands.top();
        operands.pop();
        string op1 = operands.top();
        operands.pop();

        char op = operators.top();
        operators.pop();

        code += tempVar + " = " + op1 + " " + op + " " + op2 + "\n";
        operands.push(tempVar);
        tempVar[1]++; // Increment the temporary variable number
    }

    return code;
}

int main() {
    string expression;
    cout << "Enter a valid arithmetic expression: ";
    getline(cin, expression);

    string threeAddressCode = generate3AddressCode(expression);
    cout << "3-Address Code for the given expression:\n";
    cout << threeAddressCode;

    return 0;
}
