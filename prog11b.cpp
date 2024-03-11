//quick sort worst case

#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int  *generate_input(int arr[],int k)
{
    for(int j=1;j<=k;j++)
    {
        arr[j]= j;
    }
    return arr;
}

int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

  
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

   
    if(s >= e) 
        return ;

   
    int p = partition(arr, s, e);

  
    quickSort(arr, s, p-1);

    
    quickSort(arr, p+1, e);

}

int main()
{
    int *arr = new int(100000);
    for(int i=500;i<=5000 ;i=i+500)
    {
    arr = generate_input(arr,i);
    auto start= high_resolution_clock::now();
    for(int m =1;m<=10;m++)
    {
        quickSort(arr , 0 , i-1);
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start))/10;
   cout <<"(" << i    << " , " << duration.count() << ")," << endl ;
    }
    
    return 0;
}