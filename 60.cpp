#include <iostream>
#include <stack>
#include <cctype>
using namespace std;


struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


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

   

    return 0;
}
