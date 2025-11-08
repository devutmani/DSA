#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = tail = NULL;
    }

    void insertEnd(int val) {
        Node* node = new Node(val);

        if (head == NULL) {
            head = tail = node;
            node->next = head;
        } else {
            tail->next = node;
            tail = node;
            tail->next = head;
        }
    }

    void insertFront(int val) {
        Node* node = new Node(val);

        if (head == NULL) {
            head = tail = node;
            node->next = head;
        } else {
            node->next = head;
            head = node;
            tail->next = head;
        }
    }

    void insertAtPos(int val, int pos) {
        if (pos <= 0) {
            return;
        }

        if (pos == 1) {
            insertFront(val);
            return;
        }

        Node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            current = current->next;

            if (current == head) {
                return;
            }
        }
        Node* node = new Node(val);
        node->next = current->next;
        current->next = node;

        if (current == tail) {
            tail = node;
        }
    }


    void deleteVal(int val) {
        if (head == NULL) {
            return;
        }

        Node* current = head;
        Node* previous = tail;

        do {
            if (current->data == val) {
                if (current == head) {
                    head = head->next;
                    tail->next = head;
                } else if (current == tail) {
                    tail = previous;
                    tail->next = head;
                } else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "NULL" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertEnd(1);
    cll.insertEnd(2);
    cll.insertEnd(3);
    cll.display();

    cll.insertFront(5);
    cll.display();

    cll.insertAtPos(7, 3);
    cll.display();

    cll.deleteVal(3);
    cll.display();

    cll.deleteVal(5);
    cll.display();

    return 0;
}