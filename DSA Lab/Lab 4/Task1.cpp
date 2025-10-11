#include <iostream>
using namespace std;

void selectionSort(int nums[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i; j < n; j++) {
            if (nums[j] < nums[minIdx]) {
                minIdx = j;
            }
        }
        swap(nums[i], nums[minIdx]);
    }
}

int main() {
    cout << "\nEnter 10 elements:\n" << endl;
    int arr[10];
    for (int i = 0; i < 10; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    selectionSort(arr, 10);
    cout << "\n\nArray's 4 minimum elements: ";
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}