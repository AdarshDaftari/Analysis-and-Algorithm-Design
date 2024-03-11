
#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int power(int m, int n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) { 
        int temp = power(m, n / 2);
        return temp * temp;
    } else {
        return m * power(m, n - 1);
    }
}

int main()
{
    int *arr = new int(100000);
    for(int i=1000;i<=10000 ;i=i+1000)
    {
    auto start = high_resolution_clock::now();
    for(int m =1;m<=10;m++)
    {
        int p = power(2,i);
        
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start))/10;
    cout << "inputs \t" << i    << "\t Time taken: " << duration.count() << "nanoseconds" << endl ;
    }

    return 0;
} 