#include <iostream>
using namespace std;

// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;
};

// Function to create a new node with the given value
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to find the middle element of a linked list
Node* findMiddle(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    Node* head = nullptr;

    // Insert elements into the linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    cout << "Original Linked List:" << endl;
    displayList(head);

    Node* middle = findMiddle(head);

    if (middle != nullptr) {
        cout << "Middle Element: " << middle->data << endl;
    } else {
        cout << "No middle element found (empty list)." << endl;
    }

    return 0;
}
