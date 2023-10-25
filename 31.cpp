#include <iostream>
using namespace std;

// Define the maximum size of the queue
const int MAX_SIZE = 100;

class Queue {
private:
    int front;           // Index of the front element
    int rear;            // Index of the rear element
    int data[MAX_SIZE];  // Array to store queue elements

public:
    Queue() {
        front = rear = -1;  // Initialize front and rear to -1
    }

    // Function to enqueue (push) an element into the queue
    void enqueue(int value) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue Overflow: Cannot enqueue element into a full queue." << endl;
            return;
        }
        if (front == -1) {
            front = 0;  // Initialize front for the first element
        }
        data[++rear] = value;
    }

    // Function to dequeue (pop) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow: Cannot dequeue element from an empty queue." << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;  // Reset front and rear for the last element
        } else {
            front++;
        }
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return data[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "Front element after dequeuing twice: " << queue.peek() << endl;

    return 0;
}
