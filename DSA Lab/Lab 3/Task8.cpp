#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = NULL;
    }

    void insertEnd(int val) {
        Node* node = new Node(val);

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void concatenate(DoublyLinkedList& M) {
        if (head == NULL) {
            head = M.head;
            tail = M.tail;
            return;
        }
        if (M.head == NULL) {
            return;
        }
        tail->next = M.head;
        M.head->prev = tail;
        tail = M.tail;
    }
};

int main() {
    DoublyLinkedList L, M;

    L.insertEnd(10);
    L.insertEnd(20);
    L.insertEnd(30);

    M.insertEnd(40);
    M.insertEnd(50);

    cout << "List L: ";
    L.display();

    cout << "List M: ";
    M.display();

    L.concatenate(M);

    cout << "After Concatenation (L + M): ";
    L.display();

    return 0;
}