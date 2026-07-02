/**
 * Merge Sort - Divide & Conquer
 * Simple recursive merge sort in C
 */

#include <stdio.h>
#include <stdlib.h>

// utility — copy arr[source...] to dest for exactly count elements
void copy(int dest[], const int source[], int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = source[i];
    }
}

// merging two sorted halves: arr[left..mid] + arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int size_left  = mid - left + 1;
    int size_right = right - mid;

    // temp arrays for the two halves
    int L[size_left], R[size_right];

    copy(L, &arr[left], size_left);
    copy(R, &arr[mid + 1], size_right);

    int i = 0, j = 0, k = left;

    // merge step — take the smaller one each time
    while (i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // copy any remaining elements (only one of these will actually run)
    while (i < size_left)  arr[k++] = L[i++];
    while (j < size_right) arr[k++] = R[j++];
}

// main recursive function
void merge_sort(int arr[], int left, int right) {
    if (left >= right) return;  // base case: one element or empty — already sorted

    int mid = left + (right - left) / 2;

    // divide: sort both halves
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    // combine: merge the sorted halves
    merge(arr, left, mid, right);
}

// helper to print array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== Merge Sort (Divide & Conquer) ===\n\n");

    printf("Unsorted: ");
    print_array(arr, n);

    merge_sort(arr, 0, n - 1);

    printf("Sorted:   ");
    print_array(arr, n);

    return 0;
}
