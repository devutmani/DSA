#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int index, int totalRows) {
    if (index == totalRows)
        return 0;

    int sum = 0;
    for (int j = 0; j < sizes[index]; j++)
        sum += arr[index][j];

    return sum + recursiveArraySum(arr, sizes, index + 1, totalRows);
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    int arr3[] = {6, 7, 8, 9};

    int* arr[] = {arr1, arr2, arr3};
    int sizes[] = {3, 2, 4};
    int totalRows = 3;

    int total = recursiveArraySum(arr, sizes, 0, totalRows);
    cout << "Sum of all elements : " << total << endl;

    return 0;
}