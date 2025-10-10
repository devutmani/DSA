#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int colm) {
    for (int i = 0; i < board.size(); i++) {
        if (board[row][i] == 'Q') {
            return false;
        }
    }

    for (int i = 0; i < board.size(); i++) {
        if (board[i][colm] == 'Q') {
            return false;
        }
    }

    for (int i = row, j = colm; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    for (int i = row, j = colm; i >= 0 && j < board.size(); i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void nQueen(vector<vector<char>> &board, int idx, vector<vector<char>> &placedBoard) {
    if(idx == board.size()) {
        placedBoard = board;
        return;
    }
    
    for (int i = 0; i < board.size(); i++) {
        if (isSafe(board, idx, i)) {
            board[idx][i] = 'Q';
            nQueen(board, idx+1, placedBoard);
            board[idx][i] = '.';
        }
    }
}

int main() {
    vector<vector<char>> board(4, vector<char>(4, '.'));
    vector<vector<char>> placedBoard;
    
    nQueen(board, 0, placedBoard);
    for (vector<char> vec : placedBoard) {
        for (char val : vec) {
            cout << " | " << val;
        }
        cout << " |" << endl;
    }
    return 0;
}