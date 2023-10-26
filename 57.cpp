#include <iostream>
using namespace std;


struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};


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


void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {

    string postorder = "DEBNFGCA";

    int postIndex = postorder.length() - 1;
    TreeNode* root = nullptr;

    postorderToPreorder(postorder, postIndex, root);

    cout << "Postorder: " << postorder << endl;
    cout << "Converted to Preorder: ";
    preorderTraversal(root);
    cout << endl;



    return 0;
}
