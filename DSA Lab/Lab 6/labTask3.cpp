#include <iostream>
using namespace std;

#define MAX 10

struct Order {
    int orderID;
    string itemName;
    int quantity;
};

class Queue {
    Order orders[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(Order o) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add more orders." << endl;
            return;
        }
        if (front == -1)
            front = 0;
        orders[++rear] = o;
        cout << "Order added: " << o.itemName << " (x" << o.quantity << ")" << endl;
    }

    Order dequeue() {
        Order temp;
        if (isEmpty()) {
            cout << "Queue Underflow! No orders to process." << endl;
            temp.orderID = -1;
            return temp;
        }
        temp = orders[front++];
        return temp;
    }

    void displayProcessedOrders() {
        cout << "\nProcessed Orders (in received order):\n";
        for (int i = 0; i < front; i++) {
            cout << "Order #" << orders[i].orderID << ": " 
                 << orders[i].itemName << " (x" << orders[i].quantity << ")\n";
        }
    }
};

int main() {
    Queue q;

    Order o1 = {1, "Burger", 2};
    Order o2 = {2, "Pizza", 1};
    Order o3 = {3, "Coffee", 3};

    q.enqueue(o1);
    q.enqueue(o2);
    q.enqueue(o3);

    cout << "\nProcessing Orders...\n";
    while (!q.isEmpty()) {
        Order processed = q.dequeue();
        if (processed.orderID != -1)
            cout << "Processed Order #" << processed.orderID << ": "
                 << processed.itemName << " (x" << processed.quantity << ")\n";
    }

    q.displayProcessedOrders();
    return 0;
}