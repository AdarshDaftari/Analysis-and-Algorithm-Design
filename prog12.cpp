#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include<numeric>

using namespace std;
using namespace std::chrono;

// Function to find max and min using recursive approach
void findMaxMinRecursive(vector<int>& arr, int low, int high, int& maxElement, int& minElement) {
    if (low == high) {
        maxElement = minElement = arr[low];
        return;
    }

    if (high - low == 1) {
        maxElement = max(arr[low], arr[high]);
        minElement = min(arr[low], arr[high]);
        return;
    }

    int mid = low + (high - low) / 2;

    int leftMax, leftMin, rightMax, rightMin;
    findMaxMinRecursive(arr, low, mid, leftMax, leftMin);
    findMaxMinRecursive(arr, mid + 1, high, rightMax, rightMin);

    maxElement = max(leftMax, rightMax);
    minElement = min(leftMin, rightMin);
}

// Function to find max and min using iterative approach
void findMaxMinIterative(const vector<int>& arr, int& maxElement, int& minElement) {
    int n = arr.size();

    maxElement = minElement = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        } else if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
}

// Function to measure time taken
long long measureTime(const vector<int>& arr, bool recursive) {
    auto start = high_resolution_clock::now();

    int maxElement, minElement;

    if (recursive) {
        findMaxMinRecursive(const_cast<vector<int>&>(arr), 0, arr.size() - 1, maxElement, minElement);
    } else {
        findMaxMinIterative(arr, maxElement, minElement);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    return duration.count();
}

int main() {
    vector<int> arr;

    // Vary the input size as needed
    for (int size = 1000; size <= 10000; size += 1000) {
        arr.resize(size);

        // Initialize the array with random values or any method you prefer
        // For simplicity, we're filling it with consecutive numbers here
        iota(arr.begin(), arr.end(), 1);

        long long timeRecursive = measureTime(arr, true);
        long long timeIterative = measureTime(arr, false);

        cout << "Size: " << size << ", Time taken (Recursive): " << timeRecursive << " nanoseconds\n";
        cout << "Size: " << size << ", Time taken (Iterative): " << timeIterative << " nanoseconds\n";
    }

    return 0;
}