#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node (int val) {
        data = val;
        next = NULL;
    }
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        
        tail->next = newNode;
        tail = newNode;
    }

    void backtrackingDisplay() {
        Display(head);
        cout << "NULL" << endl;
        return;
    }

    void Display(Node* temp) {      // 1->2->3->4->NULL
        if (temp == NULL) {
            return;
        }

        Display(temp->next);
        cout << temp->data << "->";
    }

    void print() {

    }
};

int main() {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    l.backtrackingDisplay();
    return 0;
}