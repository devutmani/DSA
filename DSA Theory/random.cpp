#include <iostream>
#include <string>
#include <vector>
using namespace std;

void maze(vector<vector<int>> &matrix, int row, int colm, string path, vector<string> &ans) {
    int n = matrix.size();
    if (row < 0 || colm < 0 || row >= n || colm >= n || matrix[row][colm] == 0 || matrix[row][colm] == -1) {
        return;
    }
    if (row == n-1 && colm == n-1) {
        ans.push_back(path);
        return;
    }

    matrix[row][colm] = -1;

    maze(matrix, row-1, colm, path+"U", ans); // U
    maze(matrix, row+1, colm, path+"D", ans); // D
    maze(matrix, row, colm+1, path+"R", ans); // R
    maze(matrix, row, colm-1, path+"L", ans); // L

    matrix[row][colm] = 1;
}

int main () {
    vector<vector<int>> mat = {
        {1, 0, 0, 0}, 
        {1, 1, 0, 1}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 1}, 
    };
    vector<string> ans;

    string path = "";

    maze(mat, 0, 0, path, ans);
    cout << "\n" << endl;
    for (string val : ans) {
        cout << val << endl;
    }
    return 0;
}