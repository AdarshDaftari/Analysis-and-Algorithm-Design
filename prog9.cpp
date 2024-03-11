//magic sqaure numbers  

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void generateMagicSquare(vector<vector<int>>& magicSquare, int n) {
    int row = 0, col = n / 2, num = 1;

    while (num <= n * n) {
        magicSquare[row][col] = num;
        num++;

        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;

        if (magicSquare[newRow][newCol] == 0) {
            row = newRow;
            col = newCol;
        } else {
            row = (row + 1) % n;
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    const int startN = 3;
    const int endN = 15;

    for (int n = startN; n <= endN; n += 2) {
        vector<vector<int>> magicSquare(n, vector<int>(n, 0));

        auto start = high_resolution_clock::now();

        generateMagicSquare(magicSquare, n);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "\nMagic Square of Order " << n << ":\n";
        printMatrix(magicSquare);
        cout << "Time taken for n = " << n << ": " << duration.count() << " microseconds\n";
    }

    return 0;
}