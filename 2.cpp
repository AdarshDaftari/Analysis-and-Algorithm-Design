//addition of n number

#include<iostream>
#include<chrono>
#include<cstdlib>

using namespace std;
using namespace std::chrono;

int* generate_numbers(int g){
    int *arr = new int[g];
    for (int j = 0; j < g; j++){
        arr[j] = rand();
    }
    return arr;
}

void sum_numbers(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
}

int main()
{int *arr = new int(10000000);
    for(int i = 1000000; i <= 5000000; i += 500000)
    {
        int *arr = generate_numbers(i);

        auto start = high_resolution_clock::now();  // Time count

        for(int m = 1; m <= 10; m++)
        {
            sum_numbers(arr, i);
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
        cout << "inputs \t" << i << "\t Time taken to complete addition : " << duration.count() << " nanoseconds.." << endl;
        //  cout<<duration.count()<<endl;

        delete[] arr;  
    }

    return 0;
}
