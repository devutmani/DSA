/**
 * Name: Dev Kumar
 * Section: AI-3A
 * Task: 3
 * Date: 9/7/2025
 */

#include <iostream>
using namespace std;

class Box {
private:
    int* value;

public:
    Box(int v = 0) {
        value = new int(v);
    }

    ~Box() {
        delete value;
        cout << "Destructor." << endl;
    }

    Box(const Box& other) {
        value = new int(*other.value);
        cout << "Copy Constructor." << endl;
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete value;
            value = new int(*other.value);
            cout << "Copy Assignment." << endl;
        }
        return *this;
    }

    void setValue(int v) {
        *value = v;
    }

    int getValue() const {
        return *value;
    }
};

int main() {
    Box b1(10);
    cout << "b1 Value: " << b1.getValue() << endl;

    Box b2 = b1;
    b2.setValue(20);
    cout << "b1 Value: " << b1.getValue() << endl;
    cout << "b2 Value: " << b2.getValue() << endl;

    Box b3;
    b3 = b1;
    b3.setValue(30);
    cout << "b1 Value: " << b1.getValue() << endl;
    cout << "b3 Value: " << b3.getValue() << endl;

    return 0;
}