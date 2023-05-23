#include <stdio.h>

// Function to merge two subarrays into a new array
void merge(int arr[], int left, int mid, int right) {
    int merged[right - left + 1];  // Temporary array for merging
    int i = left;                  // Index for the left subarray
    int j = mid + 1;               // Index for the right subarray
    int k = 0;                     // Index for the merged array

    // Merge the two subarrays into the merged array
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            merged[k] = arr[i];
            i++;
        } else {
            merged[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the left subarray, if any
    while (i <= mid) {
        merged[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right subarray, if any
    while (j <= right) {
        merged[k] = arr[j];
        j++;
        k++;
    }

    // Copy the merged array back to the original array
    for (i = 0; i < k; i++) {
        arr[left + i] = merged[i];
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted subarrays
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}
