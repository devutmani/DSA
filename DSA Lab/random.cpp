#include <iostream>
#include <string>
#include <vector>
using namespace std;

string priorityWord(string a, string b) {
    int compI = 0;
    int aLen = a.length();
    int bLen = b.length();

    while (compI < aLen && compI < bLen) {
        if (a[compI] < b[compI]) {
            return a;
        } else if (b[compI] < a[compI]) {
            return b;
        } else {
            compI++;
        }
    }
    if (compI == aLen) {
        return a;
    } else {
        return b;
    }
}

void merge(vector<string> &list, int st, int mid, int end) {
    int i = st;
    int endI = mid;

    int j = mid+1;
    int endJ = end;

    vector<string> vec;
    while (i <= endI && j <= endJ) {
        if (list[i][0] < list[j][0]) {
            vec.push_back(list[i]);
            i++;
        } else if (list[j][0] < list[i][0]) {
            vec.push_back(list[j]);
            j++;
        } else {
            if (priorityWord(list[i], list[j]) == list[i]) {
                vec.push_back(list[i]);
                i++;
            } else {
                vec.push_back(list[j]);
                j++;
            }
        }
    }

    while (i <= endI) {
        vec.push_back(list[i]);
        i++;
    }

    while (j <= endJ) {
        vec.push_back(list[j]);
        j++;
    }

    for (int k = 0; k < vec.size(); k++) {
        list[st+k] = vec[k];
    }
}

void mergeSort(vector<string> &list, int st, int end) {
    if (st >= end) {
        return;
    }

    int mid = st + (end-st)/2;

    mergeSort(list, st, mid);
    mergeSort(list, mid+1, end);

    merge(list, st, mid, end);
}

void sort(vector<string> &list) {
    int end = list.size()-1;
    mergeSort(list, 0, end);
}

int main() {
    vector<string> stock = {"banana", "apple", "cherry", "app", "cheetos", "date", "grape"};

    int i = 1;
    cout << "\nOriginal Order of Fruit's Stock:" << endl;
    for (string fruit : stock) {
        cout << i << ". " << fruit << endl;
        i++;
    }

    sort(stock);
    i = 1;
    cout << "\nAssending Order of Fruit's Stock:" << endl;
    for (string fruit : stock) {
        cout << i << ". " << fruit << endl;
        i++;
    }
    return 0;
}

/**
 * ================================================================================================
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
    int size;

    cout << "\nEnter size: ";
    cin >> size;

    int* arr = new int[size];
    cout << "\nArray Input:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    sort(arr, size);

    int target;
    cout << "\nEnter target: ";
    cin >> target;

    int idx = binarySearch(arr, size, target);
    if (idx != -1) {
        cout << "Target: " << target << " is found!..." << endl;
    } else {
        cout << "Target: " << target << " is not found!..." << endl;
    }
    delete[] arr;
    return 0;
}
 */