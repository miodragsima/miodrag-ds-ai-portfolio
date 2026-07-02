#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct node** head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to display the linked list
void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    
    // Insert elements at the beginning
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    
    // Display the list
    display(head);
    
    return 0;
}