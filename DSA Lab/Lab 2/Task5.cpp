#include <iostream>
#include <string>
using namespace std;

class GradeManagement {
private:
    string* departments;
    int** depCoreCourses;
    double** marks; 
    int* coreCount;

    static int depCount;
    static const int creditHours = 3;

public:
    GradeManagement() {
        departments = new string[depCount];
        coreCount = new int[depCount];
        marks = new double*[depCount];

        cout << "\nDepartment Input:" << endl;
        for (int i = 0; i < depCount; i++) {   
            cin.ignore(); 
            cout << "Enter name of department " << i+1 << ": ";
            getline(cin, departments[i]);
        }

        depCoreCourses = new int*[depCount];
        cout << "\nCore Courses Input:" << endl;
        for (int i = 0; i < depCount; i++) {
            int temp;
            cout << "Enter number of core courses in " << departments[i] << " department: ";
            cin >> temp;
            coreCount[i] = temp;
            depCoreCourses[i] = new int[temp];
            marks[i] = new double[temp];
        }
    }

    void assignMarks() {
        cout << "\nMarks Input";
        for (int i = 0; i < depCount; i++) {
            cout << "\nDepartment: " << departments[i] << endl;
            for (int j = 0; j < coreCount[i]; j++) {
                cout << "Enter marks of core course " << j+1 << ": ";
                cin >> marks[i][j];
            }
        }
    }

    void calculateGrade() {
        for (int i = 0; i < depCount; i++) {
            double total = 0.0;
            int totalCredit = 0;

            for (int j = 0; j < coreCount[i]; j++) {
                total += marks[i][j] * creditHours;
                totalCredit += creditHours;
            }

            double gpa = (totalCredit > 0) ? total / totalCredit : 0;
            cout << departments[i] << " GPA: " << gpa << endl;
        }
    }
    
    ~GradeManagement() {
        for (int i = 0; i < depCount; i++) {
            delete[] marks[i];
        }
        delete[] marks;
        delete[] coreCount;
        delete[] departments;
    }
};

int GradeManagement::depCount = 4;

int main() {
    GradeManagement m1;
    m1.assignMarks();
    m1.calculateGrade();
    return 0;
}