#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<int> &nums, vector<vector<int>> &permutations, int idx) {     // 1, 2, 3, 4
    if (idx == nums.size()) {
        permutations.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        swap(nums[i], nums[idx]);
        permutation(nums, permutations, idx+1);
        swap(nums[i], nums[idx]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;

    permutation(nums, ans, 0);
    for (vector<int> vec : ans) {
        cout << "[";
        for (int val : vec) {
            cout << val << " ";
        }
        cout << "] ";
    }
    return 0;
}