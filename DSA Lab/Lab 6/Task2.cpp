#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
};

struct StackNode {
    string url;
    StackNode* next;
};

class Stack {
    StackNode* top;
public:
    Stack() { top = nullptr; }
    bool isEmpty() { return top == nullptr; }
    void push(const string& url) {
        StackNode* n = new StackNode;
        n->url = url;
        n->next = top;
        top = n;
    }
    string pop() {
        if (isEmpty()) return "";
        StackNode* temp = top;
        string url = top->url;
        top = top->next;
        delete temp;
        return url;
    }
    string peek() { return isEmpty() ? "" : top->url; }
};

class BrowsingHistory {
    Node* head;
public:
    BrowsingHistory() { head = nullptr; }
    void visit(const string& url) {
        Node* n = new Node;
        n->url = url;
        n->next = head;
        head = n;
        cout << "Visited: " << url << endl;
    }
    void removeFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void display() {
        cout << "Browsing history (most recent first):\n";
        Node* temp = head;
        while (temp) {
            cout << "- " << temp->url << endl;
            temp = temp->next;
        }
    }
};

void simulateBrowsing() {
    BrowsingHistory history;
    Stack backStack;
    string sites[5] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (int i = 0; i < 5; i++) {
        history.visit(sites[i]);
        backStack.push(sites[i]);
    }
    cout << endl;
    history.display();
    cout << endl;
    cout << "Clicking 'back' twice...\n";
    for (int i = 0; i < 2; i++) {
        backStack.pop();
        history.removeFirst();
    }
    cout << "\nCurrent page: " << backStack.peek() << endl;
    history.display();
}

int main() {
    simulateBrowsing();
    return 0;
}