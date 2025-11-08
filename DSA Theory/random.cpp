// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// void maze(vector<vector<int>> &matrix, int row, int colm, string path, vector<string> &ans) {
//     int n = matrix.size();
//     if (row < 0 || colm < 0 || row >= n || colm >= n || matrix[row][colm] == 0 || matrix[row][colm] == -1) {
//         return;
//     }
//     if (row == n-1 && colm == n-1) {
//         ans.push_back(path);
//         return;
//     }

//     matrix[row][colm] = -1;

//     maze(matrix, row-1, colm, path+"U", ans); // U
//     maze(matrix, row+1, colm, path+"D", ans); // D
//     maze(matrix, row, colm+1, path+"R", ans); // R
//     maze(matrix, row, colm-1, path+"L", ans); // L

//     matrix[row][colm] = 1;
// }

// int main () {
//     vector<vector<int>> mat = {
//         {1, 0, 0, 0}, 
//         {1, 1, 0, 1}, 
//         {1, 1, 0, 0}, 
//         {0, 1, 1, 1}, 
//     };
//     vector<string> ans;

//     string path = "";

//     maze(mat, 0, 0, path, ans);
//     cout << "\n" << endl;
//     for (string val : ans) {
//         cout << val << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    string res = "";
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res = char(sum % 2 + '0') + res;
        carry = sum / 2;
    }
    return res;
}

string pow2(int n) {
    string res = "1";
    for (int i = 0; i < n; i++) res += "0";
    return res;
}

string solve(int n, string k) {
    int len = k.size();
    while (len < n) { k = "0" + k; len++; }

    string pos = "";
    int t = 0;
    for (int i = 0; i < n; i++) pos += 'A';

    for (int i = 0; i < n; i++) {
        if (k[i] == '1') {
            if (i == n - 1) pos[i] = 'C';
            else pos[i] = 'B';
        }
    }

    for (int i = 0; i < n; i++) if (pos[i] == 'A') pos[i] = 'C';

    string dpA = "0", dpB = "0", dpC = "0";
    for (int m = 1; m <= n; m++) {
        string two_pow = pow2(m - 1);
        int pm = (pos[m - 1] == 'A' ? 0 : (pos[m - 1] == 'B' ? 1 : 2));
        string nextA, nextB, nextC;

        if (pm == 0) nextA = dpA; else nextA = addBinary((pm == 1 ? dpC : dpB), two_pow);
        if (pm == 1) nextB = dpB; else nextB = addBinary((pm == 0 ? dpC : dpA), two_pow);
        if (pm == 2) nextC = dpC; else nextC = addBinary((pm == 0 ? dpB : dpA), two_pow);

        dpA = nextA; dpB = nextB; dpC = nextC;
    }
    while (dpC.size() > 1 && dpC[0] == '0') dpC.erase(0, 1);
    return dpC;
}

int main() {
    int n;
    string k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}