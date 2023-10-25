#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

// Function to evaluate a mathematical expression in postfix notation
int evaluatePostfixExpression(const string& expression) {
    stack<int> operandStack;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])) || (token[0] == '+' && isdigit(token[1]))) {
            operandStack.push(stoi(token));
        } else {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            if (token == "+") {
                operandStack.push(operand1 + operand2);
            } else if (token == "-") {
                operandStack.push(operand1 - operand2);
            } else if (token == "*") {
                operandStack.push(operand1 * operand2);
            } else if (token == "/") {
                operandStack.push(operand1 / operand2);
            }
        }
    }

    return operandStack.top();
}

int main() {
    string postfixExpression = "3 2 5 * + 6 -";
    int result = evaluatePostfixExpression(postfixExpression);

    cout << "Result of the postfix expression: " << result << endl;

    return 0;
}
