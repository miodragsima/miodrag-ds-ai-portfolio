#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Array-based stack implementation
int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("Pushed %d onto stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = stack[top];
    top--;
    printf("Popped %d from stack\n", value);
    return value;
}

// Function to peek at the top element
int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int main() {
    // Test stack operations
    push(10);
    push(20);
    push(30);
    
    printf("Top element is: %d\n", peek());
    
    pop();
    pop();
    
    printf("Top element is: %d\n", peek());
    
    return 0;
}