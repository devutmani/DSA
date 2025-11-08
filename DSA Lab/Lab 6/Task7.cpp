#include <iostream>
using namespace std;

class LibraryQueue {
    int* queue;
    int front, rear, capacity;
public:
    LibraryQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = 0;
        rear = -1;
    }

    bool isEmpty() { return rear < front; }
    bool isFull() { return rear == capacity - 1; }

    void enqueue(int patronID) {
        if (isFull()) {
            cout << "Queue is full. Patron " << patronID << " cannot join.\n";
            return;
        }
        rear++;
        queue[rear] = patronID;
        cout << "Patron " << patronID << " added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No patrons to process.\n";
            return;
        }
        cout << "Patron " << queue[front] << " has completed the transaction.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patrons in the queue.\n";
            return;
        }
        cout << "Current queue (front -> rear): ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LibraryQueue libQueue(10);
    int choice, id;

    while (true) {
        cout << "\n1. Add Patron\n2. Complete Transaction\n3. Display Queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patron ID to add: ";
                cin >> id;
                libQueue.enqueue(id);
                break;
            case 2:
                libQueue.dequeue();
                break;
            case 3:
                libQueue.display();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}