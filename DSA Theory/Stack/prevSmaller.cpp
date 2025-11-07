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

vector<int> prevSmaller(vector<int> &nums) {
    Stack s;
    vector<int> v;

    for (int i = 0; i < nums.size(); i++) {
        while (!s.isEmpty() && s.top() > nums[i]) {
            s.pop();
        }
        if (s.isEmpty()) {
            v.push_back(-1);
        } else {
            v.push_back(s.top());
        }
        s.push(nums[i]);
    }
    return v;
}

int main() {
    vector<int> nums = {3, 1, 0, 8, 6};
    vector<int> v = prevSmaller(nums);

    for (int val : v) {
        cout << val << " ";
    }
    return 0;
}