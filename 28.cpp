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

// Function to find the Nth node from the end of the linked list
Node* findNthFromEnd(Node* head, int n) {
    if (head == nullptr || n <= 0) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    // Move the fast pointer N nodes ahead
    for (int i = 0; i < n; i++) {
        if (fast == nullptr) {
            return nullptr; // N is greater than the length of the list
        }
        fast = fast->next;
    }

    // Move both pointers until the fast pointer reaches the end
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
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
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    cout << "Original Linked List:" << endl;
    displayList(head);

    int n = 2; // Find the 2nd node from the end

    Node* nthNode = findNthFromEnd(head, n);

    if (nthNode != nullptr) {
        cout << "The " << n << "nd node from the end is: " << nthNode->data << endl;
    } else {
        cout << "The value of N is out of range or the list is empty." << endl;
    }

    return 0;
}
