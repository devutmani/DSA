#include <iostream>
using namespace std;

void printSolution(int board[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[4][4], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < 4; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveFlagProblemUtil(int board[4][4], int col) {
    if (col >= 4)
        return true;

    for (int i = 0; i < 4; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveFlagProblemUtil(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}

void solveFlagProblem() {
    int board[4][4] = {0};

    if (solveFlagProblemUtil(board, 0) == false) {
        cout << "No solution exists." << endl;
        return;
    }

    cout << "Flag placement configuration (1 = flag):" << endl;
    printSolution(board);
    cout << "Maximum number of flags placed: " << 4 << endl;
}

int main() {
    solveFlagProblem();
    return 0;
}