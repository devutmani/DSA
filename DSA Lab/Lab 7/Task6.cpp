#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

void countingSort(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr1[10], arr2[10], combined[20];

    cout << "Enter 10 integers for arr1:\n";
    for (int i = 0; i < 10; i++) cin >> arr1[i];

    cout << "Enter 10 integers for arr2:\n";
    for (int i = 0; i < 10; i++) cin >> arr2[i];

    for (int i = 0; i < 10; i++) combined[i] = arr1[i];
    for (int i = 0; i < 10; i++) combined[10 + i] = arr2[i];

    radixSort(combined, 20);

    cout << "\nCombined and sorted array (Radix Sort):\n";
    for (int i = 0; i < 20; i++)
        cout << combined[i] << " ";

    cout << endl;
    return 0;
}