#include <iostream>
using namespace std;

// Define the structure for a BST node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for an element in the BST
bool search(TreeNode* root, int value) {
    if (root == nullptr) {
        return false; // Element not found
    }

    if (root->data == value) {
        return true; // Element found
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    TreeNode* root = nullptr;

    // Insert elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Element to search for
    int elementToFind = 40;

    if (search(root, elementToFind)) {
        cout << elementToFind << " found in the Binary Search Tree." << endl;
    } else {
        cout << elementToFind << " not found in the Binary Search Tree." << endl;
    }

    // Clean up the binary search tree (free memory)
    // You may need to implement a function to delete the tree properly.

    return 0;
}
