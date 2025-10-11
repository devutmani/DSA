#include <iostream>
using namespace std;

void recursiveDestinationInsertion(int nums[], int curr, int end, int size) {
    if (end == (size - 1) / 2) {
        nums[end] = curr;
        return;
    }

    nums[end] = nums[end - 1];
    recursiveDestinationInsertion(nums, curr, end - 1, size);
}

void destinationSort(int nums[], int size) {
    for (int i = 1; i < size; i++) {
        int curr = nums[i];
        int prev = i - 1;

        while (prev >= 0 && nums[prev] > curr) {
            swap(nums[prev + 1], nums[prev]);
            prev--;
        }
    }

    recursiveDestinationInsertion(nums, nums[size - 1], size - 1, size);
}

int main() {
    int nums[] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << "\nOriginal Array: ";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    destinationSort(nums, size);

    cout << "\nAfter Destination Insertion Sorting: ";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n" << endl;

    return 0;
}