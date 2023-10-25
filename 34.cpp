#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int value) {
        mainStack.push(value);
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        return -1; // Stack is empty
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1; // Stack is empty
    }
};

int main() {
    MinStack stack;

    stack.push(3);
    stack.push(1);
    stack.push(5);
    stack.push(2);

    cout << "Minimum element: " << stack.getMin() << endl;

    stack.pop();
    cout << "Top element after popping: " << stack.top() << endl;

    cout << "Minimum element after popping: " << stack.getMin() << endl;

    return 0;
}
