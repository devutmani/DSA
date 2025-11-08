/**
 * Name: Dev Kumar
 * Section: AI-3A
 * Task: 1
 * Date: 9/7/2025
 */

#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
        cout << "Default Constructor" << endl;
    }

    BankAccount(double initialBalance) : balance(initialBalance) {
        cout << "Parameterized Constructor" << endl;
    }

    BankAccount(const BankAccount &obj) {
        balance = obj.balance;
        cout << "Copy Constructor." << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount a1;
    cout << "Account1 Balance: " << a1.getBalance() << endl << endl;

    BankAccount a2(1000);
    cout << "Account2 Balance: " << a2.getBalance() << endl << endl;

    BankAccount a3(a2);
    a3.withdraw(120);
    cout << "Account3 Balance after withdrawing $120: " << a3.getBalance() << endl;
    cout << "Account2 Balance: " << a2.getBalance() << endl;

    return 0;
}