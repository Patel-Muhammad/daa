//Binary

#include <stdio.h>

// Binary Search function
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = (right + left) / 2;

        // If the target is found at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is smaller, search in the left half
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // If the target is greater, search in the right half
        return binarySearch(arr, mid + 1, right, target);
    }

    // Target is not present in the array
    return -1;
}

// Driver code
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 20;

    int result = binarySearch(arr, 0, size - 1, target);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}
