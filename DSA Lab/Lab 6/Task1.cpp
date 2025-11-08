#include <iostream>
#include <string>
using namespace std;

struct Node {
    string task;
    Node* next;
};

class ToDoStack {
    Node* top;
public:
    ToDoStack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(const string& task) {
        Node* n = new Node;
        n->task = task;
        n->next = top;
        top = n;
        cout << "Added: " << task << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to remove." << endl;
            return;
        }
        Node* temp = top;
        cout << "Removed: " << top->task << endl;
        top = top->next;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "To-do list is empty." << endl;
            return;
        }
        cout << "Current To-do List (top → bottom):\n";
        Node* temp = top;
        while (temp != nullptr) {
            cout << "- " << temp->task << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ToDoStack stack;

    stack.push("Finish report");
    stack.push("Email client");
    stack.push("Prepare presentation");

    stack.display();

    stack.pop();  // Remove top task
    stack.display();

    return 0;
}