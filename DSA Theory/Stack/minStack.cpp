#include <iostream>
#include <vector>
using namespace std;

class MinStack {
    vector<pair<int, int>> v;

public:
    void push(int val) {
        if (v.size() == 0) {
            v.push_back({val, val});
        } else {
            v.push_back({val, min(val, v[v.size()-1].second)});
        }
    }

    int getMin() {
        return v[v.size()-1].second;
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v[v.size()-1].first;
    }
};

int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);

    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.getMin() << endl;
    return 0;
}