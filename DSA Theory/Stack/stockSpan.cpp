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

vector<int> stockSpan(vector<int> &nums) {
    Stack pH;
    vector<int> v;

    for (int i = 0; i < nums.size(); i++) {
        while ((!pH.isEmpty()) && (nums[pH.top()] <= nums[i])) {
            pH.pop();
        }

        if (pH.isEmpty()) {
            v.push_back(i+1);
        } else {
            v.push_back(i-pH.top());
        }
        pH.push(i);
    }
    return v;
}   

int main () {
    vector<int> nums = {100, 80, 60, 70, 60, 75, 85};
    vector<int> v = stockSpan(nums);

    for (int val : v) {
        cout << val << " ";
    }
    return 0;
}