#include <iostream>
using namespace std;

int main() {
    bool array[5][5] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
    };

    int p1, p2;
    cout << "\nEnter two person(0-4): ";
    cin >> p1 >> p2;

    bool friends = false;
    for (int i = 0; i < 5; i++) {
        if (array[p1][i] && array[p2][i]) {
            friends = true;
        }
    }

    if (friends) {
        cout << "\nPerson " << p1 << " and person " << p2 << " have common friends." << endl;
    } else {
        cout << "Person " << p1 << " and person " << p2 << " have not common friends." << endl;
    }
    return 0;
}