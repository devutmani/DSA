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

vector<int> nextGreaterII(vector<int> &nums) {
    Stack s;
    vector<int> v;
    for (int i = nums.size()-1; i >= 0; i--) {
        while (!s.isEmpty() && s.top() <= nums[i]) {
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

Stack nextGreater(vector<int> &nums) {
    Stack s;

    for (int i = 0; i < nums.size(); i++) {
        bool flag = false;
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                s.push(nums[j]);
                flag = true;
                break;
            }
        }
        if (!flag) {
            s.push(-1);
        }
    }
    return s;
}

void print(Stack s) {
    if (s.isEmpty()) {
        return;
    }
    int top = s.top();
    s.pop();
    print(s);
    cout << top << " ";
}

int main() {
    vector<int> nums = {6, 8, 0, 1, 3};
    vector<int> v = nextGreaterII(nums);

    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i] << " ";
    }
    return 0;
}