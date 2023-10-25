#include <iostream>
using namespace std;

// Define a structure for a circular linked list node
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

// Function to insert a new node at the beginning of the circular linked list
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        newNode->next = newNode; // Point to itself for the first node
    } else {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next; // Find the current tail node
        }
        newNode->next = head; // New node points to the current head
        tail->next = newNode; // Update the tail to point to the new node
    }
    return newNode; // Return the new head
}

// Function to display the circular linked list
void displayList(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);
    cout << "Head" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements at the beginning of the circular linked list
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    cout << "Circular Linked List:" << endl;
    displayList(head);

    return 0;
}
