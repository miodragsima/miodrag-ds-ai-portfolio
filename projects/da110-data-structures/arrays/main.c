<<<<<<< HEAD
#include <stdio.h>

int main() {
    // Declare an array named 'numbers' that can hold 5 integers
    int numbers[5];
    
    // Initialize the array with some values
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;
    
    // Print all elements of the array
    printf("Array elements are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Access individual elements
    printf("First element (index 0): %d\n", numbers[0]);
    printf("Third element (index 2): %d\n", numbers[2]);
    
    // Update a value in the array
    printf("Updating the second element (index 1) from 20 to 25...\n");
    numbers[1] = 25;
    
    // Print all elements again after update
    printf("Array elements after update: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Calculate and display the sum of all elements
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + numbers[i];
    }
    printf("Sum of all elements: %d\n", sum);
    
    return 0;
=======
#include <stdio.h>

int main() {
    // Declare an array named 'numbers' that can hold 5 integers
    int numbers[5];
    
    // Initialize the array with some values
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;
    
    // Print all elements of the array
    printf("Array elements are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Access individual elements
    printf("First element (index 0): %d\n", numbers[0]);
    printf("Third element (index 2): %d\n", numbers[2]);
    
    // Update a value in the array
    printf("Updating the second element (index 1) from 20 to 25...\n");
    numbers[1] = 25;
    
    // Print all elements again after update
    printf("Array elements after update: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Calculate and display the sum of all elements
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + numbers[i];
    }
    printf("Sum of all elements: %d\n", sum);
    
    return 0;
>>>>>>> b6a337d (Add data structures implementations and documentation)
}