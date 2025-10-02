#include <iostream>
#include <vector>
using namespace std;

void subset(vector<int> &nums, vector<int> &ans, vector<vector<int>> &allSubset, int idx) {
    if (idx == nums.size()) {
        allSubset.push_back(ans);
        return;
    }

    ans.push_back(nums[idx]);
    subset(nums, ans, allSubset, idx+1);
    ans.pop_back();
    subset(nums, ans, allSubset, idx+1);
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> ans;

    vector<vector<int>> allSubset;
    subset(nums, ans, allSubset, 0);

    for (vector<int> vec : allSubset) {
        cout << "[";
        for (int val : vec) {
            cout << val << " ";
        }
        cout << "] ";
    }
    return 0;
}