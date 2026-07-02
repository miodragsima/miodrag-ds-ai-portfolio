/**
 * Quick Sort - Divide & Conquer
 * Pick a pivot, split into two parts, sort both halves recursively
 */

#include <stdio.h>
#include <stdlib.h>

// helper — swap two values
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// partition step — put pivot in correct place and return its index
// everything smaller goes left, everything bigger goes right
int partition(int arr[], int low, int high) {
    // pick last element as pivot (simplest choice for learning)
    int pivot = arr[high];
    int i = low - 1;  // position of last smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // now put pivot between small and large
    swap(&arr[i + 1], &arr[high]);
    return i + 1;  // return pivot's final position
}

// recursive quick sort function
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // partition step — get pivot index
        int pi = partition(arr, low, high);

        // now recursively sort left and right of pivot
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// helper to print array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== Quick Sort (Divide & Conquer) ===\n\n");

    printf("Unsorted: ");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("Sorted:   ");
    print_array(arr, n);

    return 0;
}
