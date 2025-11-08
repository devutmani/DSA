#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class University {
private:
    int depCount;
    int* studentCount;
    int*** marks;

    static const int subjectCount = 5;

public:
    University(int depCount) {
        this->depCount = depCount;
        studentCount = new int[depCount];

        marks = new int**[depCount];
        for (int i = 0; i < depCount; i++) {
            cout << "Enter number of students in department " << i+1 << ": ";
            cin >> studentCount[i];

            marks[i] = new int*[studentCount[i]];
            for (int j = 0; j < studentCount[i]; j++) {
                marks[i][j] = new int[subjectCount];
            }
        }
    }

    void AssignMarks() {
        cout << "\nAssigning Marks:";
        for (int i = 0; i < depCount; i++) {
            cout << "\nDepartment " << i+1 << ":";
            for (int j = 0; j < studentCount[i]; j++) {
                cout << "\nStudent " << j+1 << ":" << endl;
                for (int k = 0; k < subjectCount; k++) {
                    cout << "Enter marks of subject " << k+1 << ": ";
                    cin >> marks[i][j][k];
                }
            }
        }
    }

    void calculateAndDisplay() {
        for (int i = 0; i < depCount; i++) {
            double depHighest = -1e9;
            double depLowest = 1e9;
            double depAverage = 0.0;

            for (int j = 0; j < studentCount[i]; j++) {
                double subTotal = 0.0;
                for (int k = 0; k < subjectCount; k++) {
                    subTotal += marks[i][j][k];
                }
                double studentAvg = (subTotal/subjectCount);
                depAverage += studentAvg;
                depHighest = max(subTotal, depHighest);
                depLowest = min(subTotal, depLowest);
            }
            cout << "\nDepartment " << i+1 << " Heighest: " << depHighest << endl;
            cout << "Department " << i+1 << " Lowest: " << depLowest << endl;
            cout << "Department " << i+1 << " Average: " << depAverage/studentCount[i] << endl;
        }
    }

    ~University() {
        for (int i = 0; i < depCount; i++) {
            for (int j = 0; j < studentCount[i]; j++) {
                delete[] marks[i][j];
            }
            delete[] marks[i];
        }
        delete[] marks;
        delete[] studentCount;
    }
};

int main() {
    int n;
    cout << "Enter number of departments: ";
    cin >> n;

    University u(n);
    u.AssignMarks();
    u.calculateAndDisplay();

    return 0;
}