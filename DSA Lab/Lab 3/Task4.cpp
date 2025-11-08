#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void add(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void show() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    void arrange() {
        if (!head || !head->next) return;

        Node* evenStart = nullptr;
        Node* evenEnd = nullptr;
        Node* oddStart = nullptr;
        Node* oddEnd = nullptr;
        Node* current = head;

        while (current) {
            int val = current->data;
            if (val % 2 == 0) {
                if (!evenStart) {
                    evenStart = current;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = current;
                    evenEnd = evenEnd->next;
                }
            } else {
                if (!oddStart) {
                    oddStart = current;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = current;
                    oddEnd = oddEnd->next;
                }
            }
            current = current->next;
        }

        if (!evenStart || !oddStart) return;

        evenEnd->next = oddStart;
        oddEnd->next = nullptr;
        head = evenStart;
    }
};

int main() {
    LinkedList list;

    list.add(17);
    list.add(15);
    list.add(8);
    list.add(12);
    list.add(10);
    list.add(5);
    list.add(4);
    list.add(1);
    list.add(7);
    list.add(6);

    cout << "Original List:\n";
    list.show();

    list.arrange();

    cout << "Modified List:\n";
    list.show();

    return 0;
}