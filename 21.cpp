#include <iostream>

// Define a ListNode structure
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to find the length of a linked list
int getLength(ListNode* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the merge point of two linked lists
ListNode* findMergePoint(ListNode* headA, ListNode* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Make both lists equidistant from the merge point
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    // Traverse both lists to find the merge point
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA; // Either headA or headB, they are both pointing to the merge point
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create two linked lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(6);
    list2->next = list1->next->next->next; // Merge point

    std::cout << "List 1: ";
    printList(list1);
    std::cout << "List 2: ";
    printList(list2);

    ListNode* mergePoint = findMergePoint(list1, list2);

    if (mergePoint) {
        std::cout << "Merge Point Value: " << mergePoint->data << std::endl;
    } else {
        std::cout << "No merge point found." << std::endl;
    }

    return 0;
}