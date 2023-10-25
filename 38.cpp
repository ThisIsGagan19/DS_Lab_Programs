#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> inStack;  // For enqueue operations
    stack<int> outStack; // For dequeue operations

public:
    void enqueue(int value) {
        inStack.push(value);
    }

    int dequeue() {
        if (outStack.empty()) {
            if (inStack.empty()) {
                cout << "Queue is empty. Cannot dequeue." << endl;
                return -1;
            }
            // Transfer elements from inStack to outStack to reverse the order
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int frontValue = outStack.top();
        outStack.pop();
        return frontValue;
    }

    bool isEmpty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    QueueUsingStacks queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Dequeued: " << queue.dequeue() << endl;

    queue.enqueue(4);
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    return 0;
}
