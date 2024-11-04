#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// // Function prototypes
// void insertRear(struct node** head, int value);
// void traverseList(struct node* head);
// void concatenateLists(struct node** X1, struct node* X2);

// Function to insert an element at the rear end of the list
void insertRear(struct node** head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to traverse the list and print elements
void traverseList(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to concatenate two doubly linked lists X1 and X2
void concatenateLists(struct node** X1, struct node* X2) {
    if (*X1 == NULL) {
        *X1 = X2; // If X1 is empty, simply point X1 to X2
        return;
    }
    
    struct node* temp = *X1;
    // Traverse to the end of X1
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Link the last node of X1 to the first node of X2
    temp->next = X2;
    
    // If X2 is not empty, set the prev pointer of X2's head
    if (X2 != NULL) {
        X2->prev = temp;
    }
}

int main() {
    struct node* X1 = NULL;
    struct node* X2 = NULL;
    
    // Inserting elements into the first list X1
    insertRear(&X1, 10);
    insertRear(&X1, 20);
    insertRear(&X1, 30);
    
    // Inserting elements into the second list X2
    insertRear(&X2, 40);
    insertRear(&X2, 50);
    insertRear(&X2, 60);
    
    printf("List X1 before concatenation: ");
    traverseList(X1);
    
    printf("List X2 before concatenation: ");
    traverseList(X2);
    
    // Concatenating X1 and X2
    concatenateLists(&X1, X2);
    
    printf("List X1 after concatenation: ");
    traverseList(X1);
    
    return 0;
}
