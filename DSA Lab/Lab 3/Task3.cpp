#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node(string n) {
        name = n;
        next = nullptr;
    }
};

class List {
private:
    Node* head;

public:
    List() {
        head = nullptr;
    }

    void book(string name) {
        Node* newNode = new Node(name);
        if (!head || name < head->name) {
            newNode->next = head;
            head = newNode;
            cout << name << " reserved successfully.\n";
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->name < name) {
            temp = temp->next;
        }
        if (temp->name == name || (temp->next && temp->next->name == name)) {
            cout << "Reservation already exists for " << name << ".\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << name << " reserved successfully.\n";
    }

    void cancel(string name) {
        if (!head) return;
        if (head->name == name) {
            Node* del = head;
            head = head->next;
            delete del;
            cout << name << " reservation cancelled.\n";
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->name != name) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            cout << name << " reservation cancelled.\n";
        }
    }

    void find(string name) {
        Node* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << name << " has a reservation.\n";
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found.\n";
    }

    void show() {
        Node* temp = head;
        if (!temp) {
            cout << "No passengers.\n";
            return;
        }
        cout << "Passengers:\n";
        while (temp) {
            cout << "- " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    List flight;

    flight.book("Ali");
    flight.book("Sara");
    flight.book("Bilal");

    flight.show();

    flight.find("Sara");
    flight.find("Zara");

    flight.cancel("Ali");

    flight.show();

    return 0;
}