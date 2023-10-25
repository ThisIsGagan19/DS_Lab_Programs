#include <iostream>
#include <stack>
#include <string>
#include <sstream>

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to evaluate a prefix expression
int evaluatePrefix(const std::string& expression) {
    std::stack<int> operandStack;

    // Reverse the expression and split it into tokens
    std::stringstream ss(expression);
    std::string token;
    while (ss >> token) {
        // If the token is an operand, push it onto the stack
        if (!isOperator(token[0])) {
            int operand;
            std::istringstream(token) >> operand;
            operandStack.push(operand);
        } else {
            // If the token is an operator, pop two operands from the stack, perform the operation, and push the result back
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            int result;
            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    break;
            }
            operandStack.push(result);
        }
    }

    // The final result will be on the top of the stack
    return operandStack.top();
}

int main() {
    std::string prefixExpression = "- + 5 * 3 4 2";

    std::cout << "Prefix Expression: " << prefixExpression << std::endl;
    int result = evaluatePrefix(prefixExpression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}