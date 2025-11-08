#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
};

int main() {
    Stack s;
    string str = "BORROWROB";

    for (int i = 0; i < str.length(); i++)
        s.push(str[i]);

    string reversed = "";
    while (!s.isEmpty())
        reversed += s.pop();

    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reversed << endl;

    if (str == reversed)
        cout << "Result: It is a palindrome." << endl;
    else
        cout << "Result: It is not a palindrome." << endl;

    return 0;
}