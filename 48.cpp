#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find the lowest common ancestor of two nodes in a binary tree
TreeNode* findLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root == p || root == q) {
        return root;
    }

    TreeNode* left = findLowestCommonAncestor(root->left, p, q);
    TreeNode* right = findLowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr) {
        return root; // Both nodes found in left and right subtrees
    }

    return (left != nullptr) ? left : right;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;  // Node 5
    TreeNode* q = root->right; // Node 1

    TreeNode* lca = findLowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of Nodes " << p->data << " and " << q->data << " is: " << lca->data << endl;

    // Clean up the binary tree (free memory)
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
