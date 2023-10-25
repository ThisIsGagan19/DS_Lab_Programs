#include <iostream>
using namespace std;

// Define a structure for a doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node with the given value
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a new node at the beginning of the doubly linked list
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to display the doubly linked list from the head to the end
void displayForward(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Function to display the doubly linked list from the end to the head
void displayBackward(Node* head) {
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->prev;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements at the beginning of the doubly linked list
    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 3);

    // Insert elements at the end of the doubly linked list
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    cout << "Doubly Linked List (Forward):" << endl;
    displayForward(head);

    cout << "Doubly Linked List (Backward):" << endl;
    displayBackward(head);

    return 0;
}
