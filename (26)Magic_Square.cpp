#include <iostream>
#include <vector>
using namespace std;

void generateMagicSquare(int n) {
    if (n % 2 == 0) {
        cout << "Input should be an odd number.\n";
        return;
    }

    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    int num = 1;
    int row = n - 1;
    int col = 0; 

    while (num <= n * n) {
        magicSquare[row][col] = num;

        num++;
        int next_row = (row - 1 + n) % n;
        int next_col = (col + 1) % n;

        if (magicSquare[next_row][next_col] != 0) {
           
            row = (row + 1) % n;
        } else {
            
            row = next_row;
            col = next_col;
        }
    }

    cout << "Magic Square for n = " << n << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << magicSquare[i][j] << "\t";
        }
        cout << endl;
    }

    int magicSum = n * ((n * n + 1) / 2); 
    cout << "Sum of each row, column, and diagonal: " << magicSum << endl;
}

int main() {
    int n;
    cout << "Enter an odd number: ";
    cin >> n;
    generateMagicSquare(n);
    return 0;
}
