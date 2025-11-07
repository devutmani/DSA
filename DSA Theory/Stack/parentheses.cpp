#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<char> v;

public:
    void push(char val) {
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

bool isValidParentheses(string s) {
    Stack st;

    for (int i = 0; i < s.size(); i++) {
        if ((s[i] == '{') || (s[i] == '[') || (s[i] == '(')) {
            st.push(s[i]);
        } else {
            if (st.isEmpty()) {
                return false;
            }

            if ((st.top() == '{' && s[i] == '}') ||
                (st.top() == '[' && s[i] == ']') ||
                (st.top() == '(' && s[i] == ')')) {

                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.isEmpty();
}

int main () {
    string s1 = "{[()][]}";
    string s2 = "{[()";
    string s3 = "()]}";
    
    cout << isValidParentheses(s1) << endl;
    cout << isValidParentheses(s2) << endl;
    cout << isValidParentheses(s3) << endl;
    return 0;
}