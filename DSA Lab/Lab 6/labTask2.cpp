#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Transaction {
    int id;
    double amount;
    string description;
    int flag;
    Transaction* next;
};

class TransactionStack {
    Transaction* top;
    int idCounter;

public:
    TransactionStack() {
        top = NULL;
        idCounter = 1;
    }

    double applyDiscount(double amount) {
        if (amount >= 1500) return amount * 0.7;
        else if (amount >= 1000) return amount * 0.85;
        else if (amount >= 500) return amount * 0.95;
        return amount;
    }

    void push(double amount, string desc) {
        Transaction* t = new Transaction;
        t->id = idCounter++;

        if (desc.size() > 20) desc = desc.substr(0, 20) + "...";

        t->description = desc;
        if (amount >= 0) {
            double discounted = applyDiscount(amount);
            t->amount = discounted;
            t->flag = 1;
        } else {
            t->amount = amount;
            t->flag = 0;
        }

        t->next = top;
        top = t;

        cout << "Pushed Transaction: " << t->description
             << " (Final: " << t->amount << ")\n";
    }

    Transaction pop() {
        Transaction popped;
        if (top == NULL) {
            popped.id = -1;
            return popped;
        }

        Transaction* temp = top;
        top = top->next;
        popped = *temp;
        delete temp;

        popped.amount *= -1;
        popped.description += " [REVERSED]";
        popped.flag = 2;

        return popped;
    }

    bool isEmpty() { return top == NULL; }

    void display() {
        if (top == NULL) {
            cout << "Stack Empty\n";
            return;
        }

        cout << "\nFinal Stack Output:\nTop -> ";
        Transaction* t = top;
        while (t != NULL) {
            cout << "[id=" << t->id << ", amt=" << t->amount
                 << ", desc=\"" << t->description
                 << "\", flag=" << t->flag << "]";
            t = t->next;
            if (t) cout << "\n";
        }
        cout << "\n";
    }
};

int main() {
    srand(time(0));
    TransactionStack s;

    struct Predefined { double amount; string desc; } list[7] = {
        {1200, "Sale: Blue Jacket"},
        {450, "Sale: Cotton Socks"},
        {-300, "Refund: Defective Shirt"},
        {1700, "Sale: Leather Jacket"},
        {600, "Sale: Sneakers"},
        {-150, "Refund: Size Issue"},
        {2500, "Sale: Winter Coat"}
    };

    cout << "Pushed Transactions:\n";
    for (int i = 0; i < 4; i++) {
        int r = rand() % 7;
        s.push(list[r].amount, list[r].desc);
    }

    cout << "\nPop (remove) one transaction:\n";
    Transaction rev = s.pop();
    if (rev.id != -1) {
        cout << "Popped Transaction: " << rev.description << "\n"
             << "Amount changed to " << rev.amount << "\n"
             << "Flag updated to " << rev.flag << "\n";
    }

    s.display();
    return 0;
}