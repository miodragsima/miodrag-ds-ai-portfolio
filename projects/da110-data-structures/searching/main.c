#include <stdio.h>

// Linear search implementation
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Binary search implementation (array must be sorted)
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] == target) {
            return mid; // Return index if found
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Test linear search
    int target1 = 40;
    int result1 = linearSearch(arr, size, target1);
    if (result1 != -1) {
        printf("Linear search: Element %d found at index %d\n", target1, result1);
    } else {
        printf("Linear search: Element %d not found\n", target1);
    }
    
    // Test binary search
    int target2 = 50;
    int result2 = binarySearch(arr, size, target2);
    if (result2 != -1) {
        printf("Binary search: Element %d found at index %d\n", target2, result2);
    } else {
        printf("Binary search: Element %d not found\n", target2);
    }
    
    return 0;
}