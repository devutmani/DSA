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

    void remove(int val) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        // Case: deleting head node
        if (head->data == val) {
            Node* del = head;
            head = head->next;
            delete del;
            cout << val << " deleted successfully.\n";
            return;
        }

        // Traverse to find the node
        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            cout << val << " deleted successfully.\n";
        } else {
            cout << val << " not found in the list.\n";
        }
    }
};

int main() {
    LinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);

    cout << "Original List:\n";
    list.show();

    list.remove(30);
    list.show();

    list.remove(100);
    list.show();

    list.remove(10);
    list.show();

    return 0;
}