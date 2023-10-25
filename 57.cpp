#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to convert Postorder to Preorder
void postorderToPreorder(const string& postorder, int& postIndex, TreeNode*& root) {
    if (postIndex < 0) {
        return;
    }

    char current = postorder[postIndex--];

    if (current == 'N') {
        return;
    }

    root = new TreeNode(current);

    postorderToPreorder(postorder, postIndex, root->right);
    postorderToPreorder(postorder, postIndex, root->left);
}

// Function to perform a Preorder traversal of the binary tree
void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    // Input the Postorder string
    string postorder = "DEBNFGCA";

    int postIndex = postorder.length() - 1;
    TreeNode* root = nullptr;

    postorderToPreorder(postorder, postIndex, root);

    cout << "Postorder: " << postorder << endl;
    cout << "Converted to Preorder: ";
    preorderTraversal(root);
    cout << endl;

    // Clean up the binary tree (free memory)
    // You may need to implement a function to delete the tree properly.

    return 0;
}
