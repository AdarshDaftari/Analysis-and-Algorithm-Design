
#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void TOH(int n,char f,char u,char t)
{
  if(n>=1)
  {
      TOH(n-1,f,t,u);
     // cout << "move disk " << "from " <<f << "-> " << t << endl;
      TOH(n-1,u,f,t);
  }
}

int main()
{
    int *arr = new int(100000);
    
    for(int i=18;i<= 28;i=i+1)
    {

    auto start = high_resolution_clock::now();
    for(int m =1;m<=10;m++)
    {
        TOH(i,'f','u','t');
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start))/10;
    cout << "inputs \t" << i    << "\t Time taken: " << duration.count() << "nanoseconds" << endl ;
  
    }

    return 0;
}  