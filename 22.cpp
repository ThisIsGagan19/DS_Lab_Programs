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

// Function to detect a cycle in a linked list (Floyd's Cycle Detection Algorithm)
bool hasCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle detected
}

// Function to remove a cycle in a linked list (if present)
void removeCycle(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected, break the cycle
            slow = head;
            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }
            prev->next = nullptr; // Remove the cycle
            return;
        }
    }
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
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Create a cycle in the linked list
    head->next->next->next->next->next = head->next->next;

    if (hasCycle(head)) {
        cout << "Linked List has a cycle." << endl;
        removeCycle(head);
        cout << "Cycle removed." << endl;
    } else {
        cout << "Linked List does not have a cycle." << endl;
    }

    cout << "Linked List after cycle removal:" << endl;
    displayList(head);

    return 0;
}
