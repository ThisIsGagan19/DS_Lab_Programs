#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;  // Element found at index mid
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Element not found
}

int main() {
    int arr[MAX_SIZE];
    int size;

    cout << "Enter the size of the sorted array: ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Array size exceeds the maximum limit." << endl;
        return 1;
    }

    cout << "Enter " << size << " sorted elements for the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        cout << "Element " << key << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
