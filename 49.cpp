#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find the top view of a binary tree
void topView(TreeNode* root) {
    if (!root)
        return;

    map<int, int> verticalMap; // To store the vertical order of nodes

    // Create a queue to perform level order traversal
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* current = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (verticalMap.find(hd) == verticalMap.end()) {
            verticalMap[hd] = current->data;
        }

        if (current->left) {
            q.push({current->left, hd - 1});
        }

        if (current->right) {
            q.push({current->right, hd + 1});
        }
    }

    // Print the top view
    for (const auto& pair : verticalMap) {
        cout << pair.second << " ";
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    cout << "Top View of the Binary Tree: ";
    topView(root);

    // Clean up the binary tree (free memory)
    delete root->left->right->right->right;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
