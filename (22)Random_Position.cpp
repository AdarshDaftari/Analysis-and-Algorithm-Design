#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std;
using namespace std::chrono;

int* generate_number(int g) {
    int *arr = new int[g];
    for (int j = 0; j < g; j++) {
        arr[j] = rand();
    }
    return arr;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int random_sort(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot)
            i++;

        while (i <= j && arr[j] > pivot)
            j--;

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

int main() {
    for (int i = 100000; i <= 500000; i += 20000) {
        int *arr = generate_number(i);

        auto start = high_resolution_clock::now();

        for (int m = 1; m <= 10; m++) {
            random_sort(arr, 0, i - 1); 
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
       
     cout<<i<<endl;
       

        delete[] arr; 
    }

    return 0;
}
