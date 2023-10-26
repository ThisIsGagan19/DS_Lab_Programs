#include <iostream>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};


int getHeight(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}


int getBalanceFactor(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}


void updateHeight(TreeNode* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}


TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}


TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}


TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr)
        return new TreeNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root; 


    updateHeight(root);


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


void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;


    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "In-Order Traversal of the AVL Tree: ";
    inOrderTraversal(root);
    cout << endl;

   

    return 0;
}
