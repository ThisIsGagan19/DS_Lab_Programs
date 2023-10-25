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

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* list1, Node* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    Node* result = nullptr;

    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next);
    }

    return result;
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
    Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    cout << "Sorted List 1: 1 -> 3 -> 5" << endl;
    cout << "Sorted List 2: 2 -> 4 -> 6" << endl;

    Node* mergedList = mergeSortedLists(list1, list2);

    cout << "Merged Sorted List:" << endl;
    displayList(mergedList);

    return 0;
}
