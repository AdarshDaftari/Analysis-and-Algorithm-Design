#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int *generate_number(int g)
{
    int *arr = new int[g];
    for (int j = 0; j < g; j++)
    {
        arr[j] = rand();
    }
    return arr;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int s, int e)
{

    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

int main()
{
    for (int i = 1000000; i <= 50000000; i += 50000)
    {
        int *arr = generate_number(i);

        auto start = high_resolution_clock::now();

        for (int m = 1; m <= 10; m++)
        {
            partition(arr, 0, i - 1);
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
        //     cout << i << "\t" << duration.count() << endl;
        cout << "(" << i << "," << duration.count() << ")" << endl;
    }

    return 0;
}