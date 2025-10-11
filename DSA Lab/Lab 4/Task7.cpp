#include <iostream>
using namespace std;

int binarySearch(string arr[], string target, int size, int &steps) {
    int st = 0;
    int end = size-1;
    steps = 0;

    while (st <= end) {
        int mid = st + (end-st);
        steps+=1;

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

int linearSearch(string arr[], string target, int size, int &steps) {
    steps = 0;
    for (int i = 0; i < size; i++) {
        steps+=1;
        if (target == arr[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    string names[] = {"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Taufiq", "Yasin", "Zulfiqar"};

    int i = 1;
    cout << "\n<----Names---->\n" << endl;
    for (string name : names) {
        cout << "Index: " << i-1 << "| " << i << ". " << name << endl;
        i++;
    }

    string target1 = "Aftab";
    string target2 = "Rizwan";
    string target3 = "Tariq";

    int steps = 0;
    int binarySearchIdx = binarySearch(names, target1, 10, steps);

    if (binarySearchIdx != -1) {
        cout << "\nBinary Search: " << target1 << " found at index: " << binarySearchIdx << " in " << steps << " steps." << endl;
    } else {
        cout << "\n" << target1 << " not found!..." << endl;
    }

    int temp = steps;
    steps = 0;
    int linearSearchIdx = linearSearch(names, target1, 10, steps);
    if (linearSearchIdx != -1) {
        cout << "Linear Search: " << target1 << " found at index: " << linearSearchIdx << " in " << steps << " steps." << endl;
    } else {
        cout << target1 << " not found!..." << endl;
    }


    if (binarySearchIdx != -1 && temp < steps) {
        cout << "Discision: Binary Search is better here!..." << endl;
    } else if (linearSearchIdx != -1) {
        cout << "Discision: Linear Search is better here!..." << endl;
    }

    steps = 0;
    binarySearchIdx = binarySearch(names, target2, 10, steps);

    if (binarySearchIdx != -1) {
        cout << "\nBinary Search: " << target2 << " found at index: " << binarySearchIdx << " in " << steps << " steps." << endl;
    } else {
        cout << "\n" << target2 << " not found!..." << endl;
    }

    temp = steps;
    steps = 0;
    linearSearchIdx = linearSearch(names, target2, 10, steps);
    if (linearSearchIdx != -1) {
        cout << "Linear Search: " << target2 << " found at index: " << linearSearchIdx << " in " << steps << " steps." << endl;
    } else {
        cout << target2 << " not found!..." << endl;
    }

    if (binarySearchIdx != -1 && temp < steps) {
        cout << "Discision: Binary Search is better here!..." << endl;
    } else if (linearSearchIdx != -1) {
        cout << "Discision: Linear Search is better here!..." << endl;
    }

    steps = 0;
    binarySearchIdx = binarySearch(names, target3, 10, steps);

    if (binarySearchIdx != -1) {
        cout << "\nBinary Search: " << target3 << " found at index: " << binarySearchIdx << " in " << steps << " steps." << endl;
    } else {
        cout << "\n" << target3 << " not found!..." << endl;
    }

    temp = steps;
    steps = 0;
    linearSearchIdx = linearSearch(names, target3, 10, steps);
    if (linearSearchIdx != -1) {
        cout << "Linear Search: " << target3 << " found at index: " << linearSearchIdx << " in " << steps << " steps." << endl;
    } else {
        cout << target3 << " not found!..." << endl;
    }

    if (binarySearchIdx != -1 && temp < steps) {
        cout << "Discision: Binary Search is better here!..." << endl;
    } else if (linearSearchIdx != -1) {
        cout << "Discision: Linear Search is better here!..." << endl;
    }
    return 0;
}