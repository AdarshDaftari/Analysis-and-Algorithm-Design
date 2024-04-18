#include <iostream>
#include <vector>
using namespace std;

#define NUM_STATIONS 2
#define NUM_LINES 2

int assemblyLineScheduling(int a[][NUM_STATIONS], int t[][NUM_STATIONS - 1], int *e, int *x, vector<vector<int>>& linePath) {
    int T1[NUM_STATIONS], T2[NUM_STATIONS];
    vector<vector<int>> F(NUM_LINES, vector<int>(NUM_STATIONS));
    vector<vector<int>> L(NUM_LINES, vector<int>(NUM_STATIONS));

    F[0][0] = e[0] + a[0][0];
    F[1][0] = e[1] + a[1][0];

    for (int j = 1; j < NUM_STATIONS; j++) {
        if ((F[0][j - 1] + a[0][j]) <= (F[1][j - 1] + t[0][j - 1] + a[0][j])) {
            F[0][j] = F[0][j - 1] + a[0][j];
            L[0][j] = 0;
        } else {
            F[0][j] = F[1][j - 1] + t[0][j - 1] + a[0][j];
            L[0][j] = 1;
        }

        if ((F[1][j - 1] + a[1][j]) <= (F[0][j - 1] + t[1][j - 1] + a[1][j])) {
            F[1][j] = F[1][j - 1] + a[1][j];
            L[1][j] = 1;
        } else {
            F[1][j] = F[0][j - 1] + t[1][j - 1] + a[1][j];
            L[1][j] = 0;
        }
    }

    int f;
    if ((F[0][NUM_STATIONS - 1] + x[0]) <= (F[1][NUM_STATIONS - 1] + x[1])) {
        f = F[0][NUM_STATIONS - 1] + x[0];
        linePath[0][NUM_STATIONS - 1] = 0;
    } else {
        f = F[1][NUM_STATIONS - 1] + x[1];
        linePath[0][NUM_STATIONS - 1] = 1;
    }

    for (int j = NUM_STATIONS - 2; j >= 0; j--) {
        linePath[0][j] = L[linePath[0][j + 1]][j + 1];
    }

    return f;
}

void printPath(const vector<vector<int>>& linePath) {
    cout << "Path: ";
    for (int j = 0; j < NUM_STATIONS; j++) {
        cout << "Station " << j + 1 << " on Line " << linePath[0][j] + 1 << " -> ";
    }
    cout << "Exit\n";
}

int main() {
    int a[NUM_LINES][NUM_STATIONS];  
    int t[NUM_LINES][NUM_STATIONS - 1]; 
    int e[NUM_LINES];  
    int x[NUM_LINES]; 
  
    cout << "Enter processing times for stations:\n";
    for (int i = 0; i < NUM_LINES; ++i) {
        for (int j = 0; j < NUM_STATIONS; ++j) {
            cout << "Processing time for Line " << i + 1 << ", Station " << j + 1 << ": ";
            cin >> a[i][j];
        }
    }

    
    cout << "Enter transfer times between stations:\n";
    for (int i = 0; i < NUM_LINES; ++i) {
        for (int j = 0; j < NUM_STATIONS - 1; ++j) {
            cout << "Transfer time for Line " << i + 1 << ", Station " << j + 1 << " to Station " << j + 2 << ": ";
            cin >> t[i][j];
        }
    }

   
    cout << "Enter entry times for lines:\n";
    for (int i = 0; i < NUM_LINES; ++i) {
        cout << "Entry time for Line " << i + 1 << ": ";
        cin >> e[i];
    }

    
    cout << "Enter exit times for lines:\n";
    for (int i = 0; i < NUM_LINES; ++i) {
        cout << "Exit time for Line " << i + 1 << ": ";
        cin >> x[i];
    }

    vector<vector<int>> linePath(1, vector<int>(NUM_STATIONS));

    int minCost = assemblyLineScheduling(a, t, e, x, linePath);

    cout << "Minimum cost: " << minCost << endl;
    printPath(linePath);

    return 0;
}
