#include <iostream>
using namespace std;

bool haveDuplicate(int arr[], int n) {      // 0, 1, 3, 4
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }

    for (int i = 0; i < n-1; i++) {
        if (arr[i] == arr[i+1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {3, 1, 2, 4, 0, 2};

    cout << "\nOriginal Array: ";
    for (int val : arr) {
        cout << val << " ";
    } cout << endl;

    if (haveDuplicate(arr, sizeof(arr)/sizeof(arr[0]))) {
        cout << "\nArray have duplicate!..." << endl;
    } else {
        cout << "\nArray don't have duplicate!..." << endl;
    }
    return 0;
}