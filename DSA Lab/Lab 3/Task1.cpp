#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
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

    void displayList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPos(int value, int pos) {
        if (pos == 1) {
            push_front(value);
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }
        if (!temp) return;
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int value) {
        if (!head) return;
        if (head->data == value) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    void createFromArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            push_back(arr[i]);
        }
    }
};

int main() {
    int arr[5] = {3, 1, 2, 5, 8};

    cout << "Orignal Array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    LinkedList list;
    list.createFromArray(arr, 5);

    cout << "Initial Linked List: ";
    list.displayList();

    list.push_back(9);
    list.insertAtPos(11, 3);
    list.push_front(4);

    cout << "After Insertions: ";
    list.displayList();

    list.deleteValue(1);
    list.deleteValue(2);
    list.deleteValue(5);

    cout << "Final Linked List: ";
    list.displayList();

    return 0;
}