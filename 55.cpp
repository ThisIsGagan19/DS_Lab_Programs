#include <iostream>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};


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


    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);


    int elementToFind = 40;

    if (search(root, elementToFind)) {
        cout << elementToFind << " found in the Binary Search Tree." << endl;
    } else {
        cout << elementToFind << " not found in the Binary Search Tree." << endl;
    }




    return 0;
}
