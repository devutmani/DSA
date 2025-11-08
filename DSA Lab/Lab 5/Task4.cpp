#include <iostream>
using namespace std;

struct Node {
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

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    bool searchRecursive(Node* node, int key) {
        if (node == nullptr)
            return false;
        bool found = searchRecursive(node->next, key);
        if (node->data == key)
            return true;
        return found;
    }

    bool search(int key) {
        return searchRecursive(head, key);
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Linked List: ";
    list.display();

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (list.search(key))
        cout << key << " found in the list." << endl;
    else
        cout << key << " not found in the list." << endl;

    return 0;
}