#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

// Binary search function for a sorted vector
int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Element found
        } else if (arr[mid] < target) {
            low = mid + 1; // Discard left half
        } else {
            high = mid - 1; // Discard right half
        }
    }

    return -1; // Element not found
}

// Function to measure execution time for binary search
double measureTimeBinarySearch(const std::vector<int>& arr, int target) {
    clock_t start, end;
    start = clock();

    int result = binarySearch(arr, target);

    end = clock();

    if (result != -1) {
        std::cout << "Element found at index: " << result << "\n";
    } else {
        std::cout << "Element not found\n";
    }

    return double(end - start) / CLOCKS_PER_SEC;
}

int main() {
    // Input sizes
    std::vector<int> inputSizes = {1000, 5000, 10000, 50000, 100000};

    // Generate a sorted vector for binary search
    std::vector<int> sortedArray;
    for (int i = 0; i < inputSizes.back(); ++i) {
        sortedArray.push_back(i);
    }

    // Perform binary search for each input size
    std::cout << "Execution times for binary search:\n";
    for (int size : inputSizes) {
        // Best case: Search for the middle element
        double bestCaseTime = measureTimeBinarySearch(sortedArray, size / 2);

        // Worst case: Search for an element not in the array
        double worstCaseTime = measureTimeBinarySearch(sortedArray, -1);

        std::cout << "Input size " << size << " - Best Case: " << bestCaseTime << " seconds, Worst Case: " << worstCaseTime << " seconds\n";
    }

    return 0;
}