#include <iostream>
using namespace std;


struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};


void preorderToPostorder(const string& preorder, int& index) {
    if (index >= preorder.length()) {
        return;
    }

    char current = preorder[index];
    index++;

    if (current == 'N') {
        return;
    }

    preorderToPostorder(preorder, index);
    preorderToPostorder(preorder, index);

    cout << current << " ";
}


void postorderToPreorder(const string& postorder, int& index) {
    if (index < 0) {
        return;
    }

    char current = postorder[index];
    index--;

    if (current == 'N') {
        return;
    }

    cout << current << " ";

    postorderToPreorder(postorder, index);
    postorderToPreorder(postorder, index);
}

int main() {

    string preorder = "ABDCEFG";
    string postorder = "DBEFGCA";

    int index = 0;

    cout << "Preorder: " << preorder << endl;
    cout << "Converted to Postorder: ";
    preorderToPostorder(preorder, index);
    cout << endl;

    index = postorder.length() - 1;
    cout << "Postorder: " << postorder << endl;
    cout << "Converted to Preorder: ";
    postorderToPreorder(postorder, index);
    cout << endl;

    return 0;
}
