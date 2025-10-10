#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &nums, int st, int mid, int end) {
    int i = st;
    int j = mid+1;

    vector<int> vec;

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            vec.push_back(nums[i]);
            i++;
        } else {
            vec.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid) {
        vec.push_back(nums[i]);
        i++;
    }

    while (j <= end) {
        vec.push_back(nums[j]);
        j++;
    }

    for (int k = 0; k < vec.size(); k++) {
        nums[st+k] = vec[k];
    }
}

void mergeSort(vector<int> &nums, int st, int end) {
    if (st < end) {
        int mid = st + (end-st)/2;
        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, end);

        merge(nums, st, mid, end);
    }
    
}

int main() {
    vector<int> nums = {12, 31, 35, 8, 32, 17};

    cout << "\nOriginal Array: ";
    for (int val : nums) {
        cout << val << " ";
    }

    mergeSort(nums, 0, nums.size()-1);
    cout << "\nSorted Array: ";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}