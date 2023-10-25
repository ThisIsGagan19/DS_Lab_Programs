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

// Function to find the minimum value node in a BST
TreeNode* findMin(TreeNode* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

// Function to delete a node from the BST
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: get the in-order successor (smallest in the right subtree)
        TreeNode* temp = findMin(root->right);

        // Copy the in-order successor's data to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform an in-order traversal of the BST
void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
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

    cout << "In-Order Traversal of the Binary Search Tree (Before Deletion): ";
    inOrderTraversal(root);
    cout << endl;

    // Delete an element from the BST
    int valueToDelete = 30;
    root = deleteNode(root, valueToDelete);

    cout << "In-Order Traversal of the Binary Search Tree (After Deletion of " << valueToDelete << "): ";
    inOrderTraversal(root);
    cout << endl;

    // Clean up the binary search tree (free memory)
    // You may need to implement a function to delete the tree properly.

    return 0;
}
