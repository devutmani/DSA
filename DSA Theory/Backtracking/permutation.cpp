/**
* Name: Dev Kumar
* Department: AI-3A
* Problem: Permutaion
* Date: 10/3/2025
*                       <------------(123)------------>
*                                      ^
*                                      |
*          (i = 0)                   _ _ _                 (idx = 0)
*                                 /    |   \       
*                                /     |    \      
*          (i = 1)             1_._   2_._  3_._           (idx = 1)
*                              / \     /\     / \      
*                             /   \   /  \   /   \     
*          (i = 2)           12_ 13_ 21_ 23_ 31_ 32_       (idx = 2)
*                             |   |   |   |   |   |        
*          (i = 3)           123 132 213 231 312 321       (idx = 3)
*/

#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<char> &arr, vector<vector<char>> &permutations, int idx) {     // 1, 2, 3, 4
    if (idx == arr.size()) {
        permutations.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        swap(arr[i], arr[idx]);
        permutation(arr, permutations, idx+1);
        swap(arr[i], arr[idx]);
    }
}

int main() {
    vector<char> nums = {'a', 'b', 'c'};
    vector<vector<char>> ans;

    permutation(nums, ans, 0);
    for (vector<char> vec : ans) {
        cout << "[";
        for (char val : vec) {
            cout << val << " ";
        }
        cout << "] ";
    }
    return 0;
}