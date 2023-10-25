#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the trapped rainwater
int trapRainwater(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0; // Not enough walls to trap water

    vector<int> leftMax(n);
    vector<int> rightMax(n);

    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int trappedWater = 0;
    for (int i = 1; i < n - 1; i++) {
        int minHeight = min(leftMax[i], rightMax[i]);
        trappedWater += max(minHeight - height[i], 0);
    }

    return trappedWater;
}

int main() {
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int trappedWater = trapRainwater(height);

    cout << "Trapped Rainwater: " << trappedWater << " units" << endl;

    return 0;
}
