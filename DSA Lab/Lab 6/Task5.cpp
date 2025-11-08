#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, capacity;
public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    bool isEmpty() { return rear < front; }
    bool isFull() { return rear == capacity - 1; }

    void enqueue(int id) {
        if (isFull()) {
            cout << "Queue is full. Cannot add " << id << endl;
            return;
        }
        rear++;
        arr[rear] = id;
        cout << "Customer " << id << " added to queue.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return -1;
        }
        int id = arr[front];
        front++;
        cout << "Customer " << id << " checked out.\n";
        return id;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front → rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    int n = sizeof(customers)/sizeof(customers[0]);

    Queue q(10);

    for (int i = 0; i < n; i++) q.enqueue(customers[i]);
    cout << endl;
    q.display();
    cout << endl;

    q.dequeue();
    q.dequeue();
    cout << endl;
    q.display();

    return 0;
}