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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertEnd(int val) {
        Node* node = new Node(val);
        if (head == NULL) {
            head = node;
        } else {
            Node* temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = node;
        }
    }

    void rearrange() {
        if (head == NULL || head->next == NULL) return;

        Node* curr = head;
        Node* extracted = NULL;

        while (curr != NULL && curr->next != NULL) {
            Node* nodeToExtract = curr->next;
            curr->next = nodeToExtract->next;

            nodeToExtract->next = extracted;
            extracted = nodeToExtract;

            if (curr->next != NULL)
                curr = curr->next;
            else
                break;
        }

        Node* tail = head;
        while (tail->next != NULL) tail = tail->next;
        tail->next = extracted;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertEnd(10);
    list.insertEnd(4);
    list.insertEnd(9);
    list.insertEnd(1);
    list.insertEnd(3);
    list.insertEnd(5);
    list.insertEnd(9);
    list.insertEnd(4);

    cout << "Original List: ";
    list.display();

    list.rearrange();

    cout << "Modified List: ";
    list.display();

    return 0;
}