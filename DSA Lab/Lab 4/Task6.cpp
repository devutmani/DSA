#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int st = 0;
    int end = size-1;

    while (st <= end) {
        int mid = st + (end-st)/2;

        if (arr[mid] < target) {
            st = mid+1;
        } else if (arr[mid] > target) {
            end = mid-1;
        } else {
            return mid;
        }
    }
    return -1;
}

void sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int curr = arr[i];
        int prev = i-1;

        while (prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main() {
    int arr[] = {2, 1, 9, 5, 3, 8, 4, 0};
    int size = 8;

    cout << "\nOriginal Array: ";
    for (int val : arr) {
        cout << val << " ";
    }

    sort(arr, size);
    cout << "\nSorted Array: ";
    for (int val : arr) {
        cout << val << " ";
    } cout << endl;

    int target = 2;
    int idx = binarySearch(arr, size, target);
    if (idx != -1) {
        cout << "\nTarget: " << target << " is found!..." << endl;
    } else {
        cout << "\nTarget: " << target << " is not found!..." << endl;
    }

    target = 8;
    idx = binarySearch(arr, size, target);
    if (idx != -1) {
        cout << "Target: " << target << " is found!..." << endl;
    } else {
        cout << "Target: " << target << " is not found!..." << endl;
    }
    return 0;
}