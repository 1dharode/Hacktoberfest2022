#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if a queen can be placed on board[row][col]
bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        // Check column and diagonal conflicts
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// helper function
void solveNQueensUtil(int n, vector<int>& board, int row, vector<vector<int>>& solutions) {
    if (row == n) {
        vector<int> solution;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i] == j) {
                    solution.push_back(1);
                } else {
                    solution.push_back(0);
                }
            }
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueensUtil(n, board, row + 1, solutions);
        }
    }
}

//main function

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> solutions;
    vector<int> board(n, -1);
    solveNQueensUtil(n, board, 0, solutions);
    return solutions;
}
