#include <iostream>
using namespace std;

void insertionSort(int birthYears[], int size) {    // {2022, 2023, 2024, 2024, 2023, 2024}

    for (int i = 1; i < size; i++) {
        int curr = birthYears[i];
        int prev = i-1;

        while (prev >= 0 && birthYears[prev] > curr) {
            birthYears[prev+1] = birthYears[prev];
            prev--;
        }
        birthYears[prev+1] = curr;
    }
}

int main() {
    int birthYears[] = {2022, 2023, 2024, 2022, 2023, 2024};
    
    cout << "\nOriginal birth years of childs: ";
    for (int year : birthYears) {
        cout << year << " ";
    } cout << endl;

    int size = sizeof(birthYears)/sizeof(birthYears[0]);
    insertionSort(birthYears, size);
    cout << "\nOriginal birth years of childs: ";
    for (int year : birthYears) {
        cout << year << " ";
    } cout << endl;
    return 0;
}