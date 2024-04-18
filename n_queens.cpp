#include <iostream>
#include <vector>
using namespace std;


void printSolution(const vector<vector<int>>& board) {
    int N = board.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int N = board.size();
    
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;
    
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;
   
    for (int i = row, j = col; j >= 0 && i < N; ++i, --j)
        if (board[i][j])
            return false;
    return true;
}

void solveNQueensUtil(vector<vector<int>>& board, int col) {
    int N = board.size();
    if (col >= N) {
        printSolution(board); 
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; 
            solveNQueensUtil(board, col + 1); 
            board[i][col] = 0; 
        }
    }
}


void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
    solveNQueensUtil(board, 0);
}

int main() {
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
