#include <iostream>
#include <vector>

using namespace std;

// A utility function to print solution
void printSolution(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

// A utility function to check if a queen can be placed at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int n = board.size();

    // Check this row on the left side
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

// A recursive utility function to solve N Queen problem
bool solveNQUtil(vector<vector<int>>& board, int col) {
    int n = board.size();

    // Base case: If all queens are placed, return true
    if (col >= n)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < n; ++i) {
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, remove queen from board[i][col]
            board[i][col] = 0; // Backtrack
        }
    }

    // If the queen cannot be placed in any row in this column col, return false
    return false;
}

// This function solves the N Queen problem using Backtracking.
bool solveNQ(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize the chessboard with all cells empty

    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printSolution(board);
    return true;
}

// Driver program to test above functions
int main() {
    int n;
    cout << "Enter the size of the chessboard (N): ";
    cin >> n;

    solveNQ(n);
    return 0;
}
