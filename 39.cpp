#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the first negative integer in every window of size K
vector<int> findFirstNegativeInWindow(vector<int>& arr, int K) {
    vector<int> result;
    int N = arr.size();
    queue<int> window;

    int left = 0;
    int right = 0;

    while (right < N) {
        if (arr[right] < 0) {
            window.push(arr[right]);
        }

        if (right - left + 1 < K) {
            right++;
        } else if (right - left + 1 == K) {
            if (window.empty()) {
                result.push_back(0); // No negative numbers in the window
            } else {
                result.push_back(window.front());
                if (arr[left] == window.front()) {
                    window.pop();
                }
            }
            left++;
            right++;
        }
    }

    return result;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int K = 3;

    vector<int> result = findFirstNegativeInWindow(arr, K);

    cout << "First negative integer in every window of size " << K << " is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
