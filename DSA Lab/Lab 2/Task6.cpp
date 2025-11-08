#include <iostream>
#include <string>
using namespace std;

int main() {
    string** attendees;
    int** seatArray;
    int* rowCount;
    int rows;
    int seats;

    cout << "\nEnter number of rows in the Hall: ";
    cin >> rows;

    seatArray = new int*[rows];
    attendees = new string*[rows];
    rowCount = new int[rows];

    cout << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Enter number of seats in row " << i+1 << ": ";
        cin >> seats;
        seatArray[i] = new int[seats];
        attendees[i] = new string[seats];
        rowCount[i] = seats;
    }


    cout << "\nAttendees' Entry:";
    for (int i = 0; i < rows; i++) {
        cout << "\nRow " << i+1 << ":" << endl;
        for (int j = 0; j < rowCount[i]; j++) {
            cout << "Enter attendees' name: ";
            getline(cin, attendees[i][j]);
        }
    }

    cout << "\nConference Hall";
    for (int i = 0; i < rows; i++) {
        cout << "\nRow " << i+1 << ":" << endl;
        for (int j = 0; j < rowCount[i]; j++) {
            cout << "Attendees: " << attendees[i][j] << endl;
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] seatArray[i];
    }
    delete[] seatArray;
    return 0;
}