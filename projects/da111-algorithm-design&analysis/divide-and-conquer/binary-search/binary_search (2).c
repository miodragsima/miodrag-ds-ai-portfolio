/**
 * Binary Search - D&C algo
 * Works on SORTED arrays only!
 */

#include <stdio.h>
#include <stdlib.h>

// recursive binary search
int binary_search(int arr[], int left, int right, int target) {
    // if range is invalid (empty), the element is NOT in array
    if (left > right) {
        return -1;
    }

    // split point = go halfway
    int mid = left + (right - left) / 2;

    // okey dokey! found it
    if (arr[mid] == target) {
        return mid;
    }

    // if the middle is bigger than what we want, look LEFT side
    if (arr[mid] > target) {
        return binary_search(arr, left, mid - 1, target);
    }
    // else look RIGHT side
    else {
        return binary_search(arr, mid + 1, right, target);
    }
}

// simple sort to prepare array for binary search (needed since it only works on sorted)
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap them
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(void) {
    // sorted test array
    int arr[] = {3, 7, 12, 18, 24, 31, 45, 52, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== Binary Search (Divide & Conquer) ===\n");
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // what we want to find
    int targets[] = {18, 45, 99, 7};

    for (int t = 0; t < 4; t++) {
        int result = binary_search(arr, 0, n - 1, targets[t]);

        if (result != -1) {
            printf("Found %d at index %d\n", targets[t], result);
        } else {
            printf("Not found: %d\n", targets[t]);
        }
    }

    printf("\n");

    // show that unsorted array needs sorting first
    int unsorted[] = {41, 9, 33, 17, 2, 56};
    int n_unsorted = sizeof(unsorted) / sizeof(unsorted[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n_unsorted; i++) {
        printf("%d ", unsorted[i]);
    }
    printf("\n");

    bubble_sort(unsorted, n_unsorted);
    printf("Sorted array:   ");
    for (int i = 0; i < n_unsorted; i++) {
        printf("%d ", unsorted[i]);
    }
    printf("\n\n");

    int search_val = 33;
    int idx = binary_search(unsorted, 0, n_unsorted - 1, search_val);
    if (idx != -1) {
        printf("Found %d at index %d\n", search_val, idx);
    } else {
        printf("%d not found\n", search_val);
    }

    return 0;
}
