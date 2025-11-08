#include <iostream>
using namespace std;

int simpleRand(int seed, int low, int high) {
    static int x = seed;
    x = (x * 32719 + 3) % 32749;
    return low + (x % (high - low + 1));
}

int partition(int arr[], int low, int high, char pivotType, long long &comparisons) {
    int pivotIndex = low;
    if (pivotType == 'f') {
        pivotIndex = low;
    } else if (pivotType == 'm') {
        pivotIndex = low + (high - low) / 2;
        int temp = arr[low]; arr[low] = arr[pivotIndex]; arr[pivotIndex] = temp;
        pivotIndex = low;
    } else if (pivotType == 'r') {
        pivotIndex = simpleRand(1, low, high);
        int temp = arr[low]; arr[low] = arr[pivotIndex]; arr[pivotIndex] = temp;
        pivotIndex = low;
    } else if (pivotType == 'd') {
        int mid = low + (high - low) / 2;
        int a = arr[low], b = arr[mid], c = arr[high];
        int medianIndex;
        if ((a < b && b < c) || (c < b && b < a)) medianIndex = mid;
        else if ((b < a && a < c) || (c < a && a < b)) medianIndex = low;
        else medianIndex = high;
        int temp = arr[low]; arr[low] = arr[medianIndex]; arr[medianIndex] = temp;
        pivotIndex = low;
    }
    int pivot = arr[pivotIndex];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            i++;
        }
    }
    int temp = arr[low]; arr[low] = arr[i - 1]; arr[i - 1] = temp;
    return i - 1;
}

void quickSort(int arr[], int low, int high, char pivotType, long long &comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, pivotType, comparisons);
        quickSort(arr, low, pi - 1, pivotType, comparisons);
        quickSort(arr, pi + 1, high, pivotType, comparisons);
    }
}

void testArray(int arr[], int size, char pivotType) {
    long long comparisons = 0;
    int copyArr[100];
    for (int i = 0; i < size; i++) copyArr[i] = arr[i];
    quickSort(copyArr, 0, size - 1, pivotType, comparisons);
    cout << pivotType << " pivot -> Comparisons: " << comparisons << endl;
}

int main() {
    int sortedArray[] = {1,2,3,4,5,6,7,8,9,10};
    int reverseArray[] = {10,9,8,7,6,5,4,3,2,1};
    int randomArray[] = {7,2,9,1,6,8,3,5,10,4};
    int size = 10;

    cout << "=== Sorted Array ===\n";
    testArray(sortedArray, size, 'f');
    testArray(sortedArray, size, 'm');
    testArray(sortedArray, size, 'r');
    testArray(sortedArray, size, 'd');

    cout << "\n=== Reverse-Sorted Array ===\n";
    testArray(reverseArray, size, 'f');
    testArray(reverseArray, size, 'm');
    testArray(reverseArray, size, 'r');
    testArray(reverseArray, size, 'd');

    cout << "\n=== Random Array ===\n";
    testArray(randomArray, size, 'f');
    testArray(randomArray, size, 'm');
    testArray(randomArray, size, 'r');
    testArray(randomArray, size, 'd');

    return 0;
}