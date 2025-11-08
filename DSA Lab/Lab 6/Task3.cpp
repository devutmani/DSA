#include <iostream>
#include <string>
using namespace std;

struct Node {
    char op;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }
    bool isEmpty() { return top == nullptr; }
    void push(char c) {
        Node* n = new Node;
        n->op = c;
        n->next = top;
        top = n;
    }
    char pop() {
        if (isEmpty()) return '\0';
        Node* temp = top;
        char c = top->op;
        top = top->next;
        delete temp;
        return c;
    }
    char peek() { return isEmpty() ? '\0' : top->op; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

string infixToPostfix(const string& exp) {
    Stack st;
    string postfix = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(')
                postfix += st.pop();
            st.pop();
        }
        else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c) && st.peek() != '(')
                postfix += st.pop();
            st.push(c);
        }
    }

    while (!st.isEmpty())
        postfix += st.pop();

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}