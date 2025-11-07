#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &nums, int st, int end) {
    int idx = st-1;

    for (int j = st; j < end; j++) {
        if (nums[j] <= nums[end]) {
            idx++;
            swap(nums[j], nums[idx]);
        }
    }

    idx++;
    swap(nums[idx], nums[end]);
    return idx;
}

void quickSort(vector<int> &nums, int st, int end) {
    if (st >= end) {
        return;
    }

    int pivot = partition(nums, st, end);

    quickSort(nums, st, pivot-1);
    quickSort(nums, pivot+1, end);
}

int main () {
    vector<int> nums = {12, 31, 35, 8, 32, 17};
    quickSort(nums, 0, 5);

    for (int val : nums) {
        cout << val << " ";
    }
    return 0;
}