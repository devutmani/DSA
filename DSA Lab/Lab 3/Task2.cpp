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

    void createFromArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            push_back(arr[i]);
        }
    }

    void rotate(int k) {
        if (!head || k == 0) return;

        Node* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        k = k % length;
        if (k == 0) return;

        temp->next = head;
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }
        head = newTail->next;
        newTail->next = nullptr;
    }
};

int main() {
    int arr[7] = {5, 3, 1, 8, 6, 4, 2};
    LinkedList list;
    list.createFromArray(arr, 7);

    cout << "Original List: ";
    list.displayList();

    int k;
    cout << "Enter the number: ";
    cin >> k;

    list.rotate(k);

    cout << "After rotation: ";
    list.displayList();

    return 0;
}