#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Element found at index i
        }
    }
    return -1;  // Element not found
}

int main() {
    int arr[MAX_SIZE];
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Array size exceeds the maximum limit." << endl;
        return 1;
    }

    cout << "Enter " << size << " elements for the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        cout << "Element " << key << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}

