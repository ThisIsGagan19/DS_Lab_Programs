#include <iostream>
#include <queue>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find the height of a binary tree
int findTreeHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = findTreeHeight(root->left);
    int rightHeight = findTreeHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int treeHeight = findTreeHeight(root);

    cout << "Height of the Binary Tree: " << treeHeight << endl;

    // Clean up the binary tree (free memory)
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
