#include <iostream>
#include <string>
using namespace std;

class SchoolExam {
private:
    string* studentName;
    int** studentMarks;
    int studentCount;
    int subjectCount;

public:
    SchoolExam(int students, int subjects) {
        studentCount = students;
        subjectCount = subjects;

        studentName = new string[studentCount];
        studentMarks = new int*[studentCount];
        for (int i = 0; i < studentCount; i++) {
            studentMarks[i] = new int[subjectCount];
        }
    }

    void assignMarks() {
        cout << "\nAssigning Marks" << endl;
        string name;
        for (int i = 0; i < studentCount; i++) {
            cout << "\nEnter student name: ";
            getline(cin, name);
            studentName[i] = name;
            for (int j = 0; j < subjectCount; j++) {
                cout << "Enter marks of subject " << j+1 << ": ";
                cin >> studentMarks[i][j];
            }
            cin.ignore();
        }
    }

    pair<double, double> totalAndAverage(const string &name) {
        double average = 0.0;

        for (int i = 0; i < studentCount; i++) {
            if (name == studentName[i]) {
                for (int j = 0; j < subjectCount; j++) {
                    average += studentMarks[i][j];
                }
                break;
            }
        }
        return {average, average/subjectCount};
    }

    pair<string, double> topper() {
        double topMarks = totalAndAverage(studentName[0]).first;
        string topper = studentName[0];

        for (int i = 0; i < studentCount; i++) {
            double total = totalAndAverage(studentName[i]).first;
            if (total > topMarks) {
                topMarks = total;
                topper = studentName[i];
            }
        }

        return {topper, topMarks};
    }

    bool isStudent(const string &name) {
        for (int i = 0; i < studentCount; i++) {
            if (studentName[i] == name) {
                return true;
            }
        }
        return false;
    }

    void printDetails() {
        cout << "\nStudent Details" << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << "\nName: " << studentName[i] << endl;
            for (int j = 0; j < subjectCount; j++) {
                cout << "Marks of Subject " << j+1 << ": " << studentMarks[i][j] << endl;
            }
            cout << "Total Marks: " << totalAndAverage(studentName[i]).first << endl;
            cout << "Average Marks: " << totalAndAverage(studentName[i]).second << endl;
        }
    }

    ~SchoolExam() {
        for (int i = 0; i < studentCount; i++) {
            delete[] studentMarks[i];
        }
        delete[] studentMarks;
        delete[] studentName;
    }
};

int main() {
    SchoolExam retake(2, 4);
    retake.assignMarks();
    retake.printDetails();

    string name;
    cout << "\nEnter student name for having Total and Average marks: ";
    getline(cin, name);
    cin.ignore();

    if (retake.isStudent(name)) {
        cout << "\n" << name << ": " << "\nTotal Marks " << retake.totalAndAverage(name).first << "\nAverage Marks: " << retake.totalAndAverage(name).second << endl;
    }

    cout << "\nTopper of Retake Exam: " << retake.topper().first << "\nTotal Marks: " << retake.topper().second << endl;
    return 0;
}