#include <iostream>
#include <stack>
using namespace std;

// Define a structure for a singly linked list node
struct Node {
    char data;
    Node* next;
};

// Function to create a new node with the given character
Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    stack<char> charStack;
    Node* current = head;

    // Push characters onto the stack
    while (current != nullptr) {
        charStack.push(current->data);
        current = current->next;
    }

    // Pop characters and compare with the linked list
    current = head;
    while (!charStack.empty()) {
        char top = charStack.top();
        charStack.pop();
        if (current->data != top) {
            return false; // Not a palindrome
        }
        current = current->next;
    }

    return true; // Palindrome
}

// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = createNode('r');
    head->next = createNode('a');
    head->next->next = createNode('c');
    head->next->next->next = createNode('e');
    head->next->next->next->next = createNode('c');
    head->next->next->next->next->next = createNode('a');
    head->next->next->next->next->next->next = createNode('r');

    cout << "Linked List: r -> a -> c -> e -> c -> a -> r" << endl;

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
