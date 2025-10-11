#include <iostream>
#include <string>
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

void merge(string list[], int st, int mid, int end) {
    int i = st;
    int endI = mid;

    int j = mid + 1;
    int endJ = end;

    int size = end - st + 1;
    string* temp = new string[size];
    int k = 0;

    while (i <= endI && j <= endJ) {
        if (list[i][0] < list[j][0]) {
            temp[k++] = list[i++];
        } else if (list[j][0] < list[i][0]) {
            temp[k++] = list[j++];
        } else {
            if (priorityWord(list[i], list[j]) == list[i]) {
                temp[k++] = list[i++];
            } else {
                temp[k++] = list[j++];
            }
        }
    }

    while (i <= endI) {
        temp[k++] = list[i++];
    }

    while (j <= endJ) {
        temp[k++] = list[j++];
    }

    for (int x = 0; x < size; x++) {
        list[st + x] = temp[x];
    }

    delete[] temp;
}

void mergeSort(string list[], int st, int end) {
    if (st >= end) {
        return;
    }

    int mid = st + (end - st) / 2;

    mergeSort(list, st, mid);
    mergeSort(list, mid + 1, end);

    merge(list, st, mid, end);
}

void sort(string list[], int size) {
    mergeSort(list, 0, size - 1);
}

int main() {
    string stock[] = {"banana", "apple", "cherry", "date", "grape"};
    int size = sizeof(stock) / sizeof(stock[0]);

    cout << "\nOriginal Order of Fruit's Stock:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << stock[i] << endl;
    }

    sort(stock, size);

    cout << "\nAscending Order of Fruit's Stock:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << stock[i] << endl;
    }

    return 0;
}