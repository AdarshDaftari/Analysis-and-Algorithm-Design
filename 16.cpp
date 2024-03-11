#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stack>

// Partition function for QuickSort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Iterative QuickSort function
void iterativeQuickSort(std::vector<int>& arr, int low, int high) {
    std::stack<std::pair<int, int>> stack;
    stack.push(std::make_pair(low, high));

    while (!stack.empty()) {
        low = stack.top().first;
        high = stack.top().second;
        stack.pop();

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) {
            stack.push(std::make_pair(low, pivotIndex - 1));
        }

        if (pivotIndex + 1 < high) {
            stack.push(std::make_pair(pivotIndex + 1, high));
        }
    }
}

// Function to measure execution time for iterative QuickSort
double measureTimeIterativeQuickSort(std::vector<int>& arr) {
    clock_t start, end;
    start = clock();

    iterativeQuickSort(arr, 0, arr.size() - 1);

    end = clock();

    return double(end - start) / CLOCKS_PER_SEC;
}

int main() {
    // Input sizes
    std::vector<int> inputSizes = {1000, 5000, 10000, 50000, 100000};

    // Perform iterative QuickSort for each input size
    std::cout << "Execution times for iterative QuickSort:\n";
    for (int size : inputSizes) {
        // Generate a random vector for each input size
        std::vector<int> array;
        for (int i = 0; i < size; ++i) {
            array.push_back(rand() % 1000);
        }

        // Measure execution time
        double executionTime = measureTimeIterativeQuickSort(array);

        std::cout << "Input size " << size << ": " << executionTime << " seconds\n";
    }

    return 0;
}