#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int insertElement(int arr[], int& size, int element, int position) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert." << endl;
        return size;
    }

    if (position < 0 || position > size) {
        cout << "Invalid position for insertion." << endl;
        return size;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;
    return size;
}

int deleteElement(int arr[], int& size, int position) {
    if (size <= 0) {
        cout << "Array is empty. Cannot delete." << endl;
        return size;
    }

    if (position < 0 || position >= size) {
        cout << "Invalid position for deletion." << endl;
        return size;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
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
        cout << "\n1. Insert element\n2. Delete element\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element, position;
                cout << "Enter the element to insert: ";
                cin >> element;
                cout << "Enter the position to insert: ";
                cin >> position;
                size = insertElement(arr, size, element, position);
                break;
            }
            case 2: {
                int position;
                cout << "Enter the position to delete: ";
                cin >> position;
                size = deleteElement(arr, size, position);
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
