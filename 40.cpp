#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the next greater element to the right
vector<int> nextGreaterRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

// Function to find the next greater element to the left
vector<int> nextGreaterLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

// Function to find the nearest smaller element to the left
vector<int> nearestSmallerLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> nextGreaterRightResult = nextGreaterRight(arr);
    vector<int> nextGreaterLeftResult = nextGreaterLeft(arr);
    vector<int> nearestSmallerLeftResult = nearestSmallerLeft(arr);

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Next Greater Element to the Right: ";
    for (int num : nextGreaterRightResult) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Next Greater Element to the Left: ";
    for (int num : nextGreaterLeftResult) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Nearest Smaller Element to the Left: ";
    for (int num : nearestSmallerLeftResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
