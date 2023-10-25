#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a node at a specific position in the linked list
    void insertAtPosition(int data, int position) {
        Node* newNode = new Node(data);

        if (position < 1) {
            std::cout << "Invalid position. Position should be greater than or equal to 1." << std::endl;
            return;
        }

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int currentPos = 1;

            while (current != nullptr && currentPos < position - 1) {
                current = current->next;
                currentPos++;
            }

            if (current == nullptr) {
                std::cout << "Invalid position. List is not long enough for the specified position." << std::endl;
                return;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to delete a node at a specific position in the linked list
    void deleteAtPosition(int position) {
        if (position < 1 || head == nullptr) {
            std::cout << "Invalid position or an empty list. Nothing to delete." << std::endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            int currentPos = 1;

            while (current != nullptr && currentPos < position - 1) {
                current = current->next;
                currentPos++;
            }

            if (current == nullptr || current->next == nullptr) {
                std::cout << "Invalid position. List is not long enough for the specified position." << std::endl;
                return;
            }

            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtPosition(1, 1);
    list.insertAtPosition(2, 2);
    list.insertAtPosition(4, 2);
    list.insertAtPosition(3, 3);

    std::cout << "Linked List: ";
    list.display();

    list.deleteAtPosition(2);
    std::cout << "After deleting at position 2: ";
    list.display();

    return 0;
}
