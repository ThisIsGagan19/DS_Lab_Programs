#include <iostream>
#include <algorithm>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Structure to store the result of diameter calculation
struct Result {
    int height;
    int diameter;
};

// Function to find the diameter of a binary tree
Result findDiameter(TreeNode* root) {
    if (root == nullptr) {
        return {0, 0};
    }

    Result left = findDiameter(root->left);
    Result right = findDiameter(root->right);

    int height = max(left.height, right.height) + 1;
    int throughRoot = left.height + right.height + 1;
    int diameter = max(throughRoot, max(left.diameter, right.diameter));

    return {height, diameter};
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Result result = findDiameter(root);

    cout << "Diameter of the Binary Tree: " << result.diameter << endl;

    // Clean up the binary tree (free memory)
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
