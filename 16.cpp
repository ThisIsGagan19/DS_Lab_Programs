#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Deletion at the beginning
    void deleteAtBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Destructor to release memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    
    // Insert some elements at the beginning
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);

    std::cout << "Linked List: ";
    list.display();

    // Delete an element from the beginning
    list.deleteAtBeginning();

    std::cout << "After deletion: ";
    list.display();

    return 0;
}
