#include <iostream>
#include <vector>
#include <set>
using namespace std;

void printNums(int num) {
    if (num == 0) {
        return;
    }
    printNums(num-1);
    cout << num << " ";
}

int fact(int num) {
    if (num == 0) {
        return 1;
    }

    return num*fact(num-1);
}

void numsFact(int num) {
    if (num == 0) {
        return;
    }

    numsFact(num-1);
    cout << "Factorial of " << num << ": " << fact(num) << endl;
}

int sumWithRecursion(int num) {
    if (num == 1) {
        return 1;
    }

    return num + sumWithRecursion(num-1);
}

int fib(int num) {
    if (num == 0 || num == 1) {
        return num;
    }

    return fib(num-1) + fib(num-2);
}

bool isSorted(vector<int> &arr, int n) {
    if (n == 0 || n == 1) {
        return true;
    }

    return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}

int binarySearch(vector<int> &arr, int target, int st, int end) {   // 1 3 2 5 9 7
    if (st <= end) {
        int mid = st + (end-st)/2;

        if (arr[mid] == target) {
            return mid;
        } else if (target > arr[mid]) {
            return binarySearch(arr, target, mid+1, end);
        } else {
            return binarySearch(arr, target, st, mid-1);
        }
    }
    return -1;
}

void printSubset(vector<int> arr, vector<int> ans, int i) {
    if (i == arr.size()) {
        cout << "[";
        for (int val : ans) {
            cout << val << " ";
        }
        cout << "] ";
        return;
    }

    ans.push_back(arr[i]);
    printSubset(arr, ans, i+1);
    ans.pop_back();
    printSubset(arr, ans, i+1);
}

void powerSet(vector<int> arr, vector<int> ans, int i, vector<vector<int>> &powerset, set<vector<int>> &s) {
    if (i == arr.size()) {
        if (s.find(ans) == s.end()) {
            powerset.push_back({ans});
            s.insert(ans);
        }
        return;
    }

    ans.push_back(arr[i]);
    powerSet(arr, ans, i+1, powerset, s);
    ans.pop_back();
    powerSet(arr, ans, i+1, powerset, s);
}

int main () {
    vector<int> arr = {1, 2, 2};
    vector<int> ans;
    vector<vector<int>> powerset;

    set<vector<int>> s;
    powerSet(arr, ans, 0, powerset, s);

    for (vector<int> val : powerset) {
        cout << "[";
        for (int ele : val) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    return 0;
}

void subsetProblem(vector<int> arr, vector<int> ans, int i, vector<vector<int>> allSubsets) {
    if (i == arr.size()) {
        allSubsets.push_back({ans});
        return;
    }

    ans.push_back(arr[i]);
    subsetProblem(arr, ans, i+1, allSubsets);
    ans.pop_back();
    subsetProblem(arr, ans, i+1, allSubsets);
}