/**
 * Name: Dev Kumar
 * Section: AI-3A
 * Task: 2
 * Date: 9/7/2025
 */

#include <iostream>
#include <string>
using namespace std;

class Exam {
private:
    string* name;
    string* date;
    int score;

public:
    Exam(const string& name, const string& date, int s) {
        this->name = new string(name);
        this->date = new string(date);
        this->score = s;
    }

    ~Exam() {
        delete name;
        delete date;
        cout << "Destructor called." << endl;
    }

    void display() const {
        cout << "Name: " << *name << endl;
        cout << "Date: " << *date << endl;
        cout << "Score: " << score << endl;
    }
};

int main() {
    Exam e1("Dev", "2022-06-12", 85);
    cout << "Exam1 Details:" << endl;
    e1.display();

    cout << endl;

    Exam e2 = e1;
    cout << "Exam2 Details:" << endl;
    e2.display();
    return 0;
}