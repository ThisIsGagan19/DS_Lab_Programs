#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Define the structure for a binary expression tree node
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to create a binary expression tree from a postfix expression
TreeNode* createExpressionTree(const string& postfix) {
    stack<TreeNode*> stack;

    for (char symbol : postfix) {
        TreeNode* newNode = new TreeNode(symbol);

        if (isalnum(symbol)) {
            stack.push(newNode);
        } else if (isOperator(symbol)) {
            newNode->right = stack.top();
            stack.pop();
            newNode->left = stack.top();
            stack.pop();
            stack.push(newNode);
        }
    }

    return stack.top();
}

// Function to evaluate a binary expression tree
int evaluateExpressionTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (isdigit(root->data)) {
        return root->data - '0';
    }

    int left = evaluateExpressionTree(root->left);
    int right = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
    }

    return 0; // Default case
}

// Function to perform an in-order traversal of the binary expression tree
void inOrderTraversal(TreeNode* root) {
    if (root) {
        if (isOperator(root->data)) {
            cout << "(";
        }
        inOrderTraversal(root->left);
        cout << root->data;
        inOrderTraversal(root->right);
        if (isOperator(root->data)) {
            cout << ")";
        }
    }
}

int main() {
    string postfixExpression = "34*2+";
    TreeNode* expressionTree = createExpressionTree(postfixExpression);

    cout << "Infix Expression: ";
    inOrderTraversal(expressionTree);
    cout << endl;

    int result = evaluateExpressionTree(expressionTree);
    cout << "Result of the Expression: " << result << endl;

    // Clean up the binary expression tree (free memory)
    // You may need to implement a function to delete the tree properly.

    return 0;
}
