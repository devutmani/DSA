#include <iostream>
#include <string>
using namespace std;

struct Node {
    string value;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }
    bool isEmpty() { return top == nullptr; }
    void push(const string& val) {
        Node* n = new Node;
        n->value = val;
        n->next = top;
        top = n;
    }
    string pop() {
        if (isEmpty()) return "";
        Node* temp = top;
        string val = top->value;
        top = top->next;
        delete temp;
        return val;
    }
    void display() {
        Node* temp = top;
        cout << "Stack (top -> bottom):\n";
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};

double evaluateExpression() {
    double result = 12 + 13 - 5 * (0.5 + 0.5) + 1;
    return result;
}

int main() {
    Stack s;
    s.push("x");
    s.push("=");
    s.push("12");
    s.push("+");
    s.push("13");
    s.push("-");
    s.push("5");
    s.push("*");
    s.push("(");
    s.push("0.5");
    s.push("+");
    s.push("0.5");
    s.push(")");
    s.push("+");
    s.push("1");

    double result = evaluateExpression();
    s.push(to_string(result));

    s.display();

    return 0;
}