#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;

public:
    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v.at(v.size()-1);
    }

    bool isEmpty() {
        return v.size() == 0;
    }
};

int largestHistogram(vector<int> &nums) {
    int mini = nums[0];
    int step = 1;
    Stack s;

    for (int i = 0; i < nums.size(); i++) {
        mini = min(mini, nums[i]);
        if (!s.isEmpty() && mini*step <= s.top()) {
            mini = nums[i+1];   
            step = 1;
            continue;
        }

        if (s.isEmpty()) {
            s.push(mini*step);
        } else {
            s.push(mini*step);
        }
        step++;
    }

    return s.top();
}

int main() {
    vector<int> nums = {2, 1, 6, 6, 2, 3};
    int largestRec = largestHistogram(nums);
    cout << largestRec << endl;
    return 0;
}