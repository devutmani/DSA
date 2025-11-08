#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyList {
private:
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val);

        if (pos <= 1 || head == NULL) { // Insert at beginning
            newNode->next = head;
            if (head != NULL)
                head->prev = newNode;
            head = newNode;
            if (tail == NULL)
                tail = newNode;
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp->next != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserted at end

        temp->next = newNode;
    }

    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos <= 1) { // Delete head
            Node* temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;
            delete temp;
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList dl;

    dl.insertAtPosition(10, 1);
    dl.insertAtPosition(20, 2);
    dl.insertAtPosition(30, 3);
    dl.insertAtPosition(40, 4);
    dl.insertAtPosition(25, 3); // insert in middle

    cout << "List after insertion:" << endl;
    dl.display();

    dl.deleteAtPosition(2);
    cout << "List after deletion at position 2:" << endl;
    dl.display();

    return 0;
}