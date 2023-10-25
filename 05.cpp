#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int insertAtEnd(int arr[], int& size, int element) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert." << endl;
        return size;
    }

    arr[size] = element;
    size++;
    return size;
}

int deleteFromEnd(int arr[], int& size) {
    if (size <= 0) {
        cout << "Array is empty. Cannot delete." << endl;
        return size;
    }

    size--;
    return size;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    cout << "Enter the initial size of the array: ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Array size exceeds the maximum limit." << endl;
        return 1;
    }

    cout << "Enter " << size << " elements for the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int choice;
    do {
        cout << "\n1. Insert at the end\n2. Delete from the end\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "Enter the element to insert at the end: ";
                cin >> element;
                size = insertAtEnd(arr, size, element);
                break;
            }
            case 2: {
                size = deleteFromEnd(arr, size);
                break;
            }
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << "Updated Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } while (choice != 3);

    return 0;
}
