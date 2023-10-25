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

// Function to find the right view of a binary tree
void rightView(TreeNode* root) {
    if (!root)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 1; i <= size; i++) {
            TreeNode* current = q.front();
            q.pop();

            if (i == size) {
                cout << current->data << " "; // Print the rightmost node of the current level
            }

            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
        }
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Right View of the Binary Tree: ";
    rightView(root);

    // Clean up the binary tree (free memory)
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
