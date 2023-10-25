#include <iostream>
using namespace std;

// Define the maximum size of the stack
const int MAX_SIZE = 100;

class Stack {
private:
    int top;            // Index of the top element
    int data[MAX_SIZE]; // Array to store stack elements

public:
    Stack() {
        top = -1; // Initialize the top index to -1
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow: Cannot push element onto a full stack." << endl;
            return;
        }
        data[++top] = value;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop element from an empty stack." << endl;
            return;
        }
        top--;
    }

    // Function to get the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return data[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element after popping twice: " << stack.peek() << endl;

    return 0;
}
