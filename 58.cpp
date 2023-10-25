#include <iostream>
using namespace std;

// Define the structure for an AVL tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// Function to get the height of a node
int getHeight(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Function to get the balance factor of a node
int getBalanceFactor(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to update the height of a node
void updateHeight(TreeNode* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Function to perform a right rotation
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to insert a new node into the AVL tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr)
        return new TreeNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root; // Duplicate values are not allowed

    // Update the height of the current node
    updateHeight(root);

    // Get the balance factor and perform rotations if necessary
    int balance = getBalanceFactor(root);

    // Left Heavy
    if (balance > 1) {
        if (value < root->left->data)
            return rightRotate(root);
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    // Right Heavy
    if (balance < -1) {
        if (value > root->right->data)
            return leftRotate(root);
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to perform an in-order traversal of the AVL tree
void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    // Insert elements into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "In-Order Traversal of the AVL Tree: ";
    inOrderTraversal(root);
    cout << endl;

    // Clean up the AVL tree (free memory)
    // You may need to implement a function to delete the tree properly.

    return 0;
}
