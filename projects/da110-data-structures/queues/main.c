#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Array-based queue implementation
int queue[MAX];
int front = -1;
int rear = -1;

// Function to insert an element at the rear
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued %d\n", value);
}

// Function to remove an element from the front
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue[front];
    front++;
    printf("Dequeued %d\n", value);
    return value;
}

// Function to display queue elements
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Test queue operations
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    display();
    
    dequeue();
    dequeue();
    
    display();
    
    return 0;
}