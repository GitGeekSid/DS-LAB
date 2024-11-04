// // Insert an element at the rear end of the list 
// // Delete an element from the rear end of the list 
// // Insert an element at a given position of the list 
// // Delete an element from a given position of the list 
// // Insert an element after another element 
// // Insert an element before another element 
// // Traverse the list 
// // Reverse the list


// #include<stdio.h>
// #include<stdlib.h>

// typedef struct dnode{
//     int data;
//     struct dnode* prev;
//     struct dnode* next;
// }dnode;
// struct dnode* head=NULL;

// struct dnode* createnode(int element)
// {
//     dnode*dnewnode=(dnode*)malloc(sizeof(dnode));
//     dnewnode->data=element;
//     return dnewnode;
// }
// void insertatend(int element)
// {
//     dnode*dnewnode=createnode(element);
//     dnode*temp=head;
// }

#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* head = NULL;

// Function prototypes
void insertRear(int value);
void deleteRear();
void insertAtPosition(int value, int position);
void deleteAtPosition(int position);
void insertAfter(int value, int after);
void insertBefore(int value, int before);
void traverseList();
void reverseList();

// Function to insert an element at the rear end of the list
void insertRear(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete an element from the rear end of the list
void deleteRear() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct node* temp = head;
    
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

// Function to insert an element at a given position of the list
void insertAtPosition(int value, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    
    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    
    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete an element from a given position of the list
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct node* temp = head;
    
    if (position == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    free(temp);
}

// Function to insert an element after another element
void insertAfter(int value, int after) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    
    struct node* temp = head;
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Element %d not found.\n", after);
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to insert an element before another element
void insertBefore(int value, int before) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    
    if (head == NULL) {
        printf("List is empty.\n");
        free(newNode);
        return;
    }
    
    if (head->data == before) {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        return;
    }
    
    struct node* temp = head;
    while (temp != NULL && temp->data != before) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Element %d not found.\n", before);
        free(newNode);
        return;
    }
    
    newNode->next = temp;
    newNode->prev = temp->prev;
    
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
}

// Function to traverse the list
void traverseList() {
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

// Function to reverse the list
void reverseList() {
    if (head == NULL) {
        return;
    }
    
    struct node* temp = NULL;
    struct node* current = head;
    
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp != NULL) {
        head = temp->prev;
    }
}

// Main function with menu
int main() {
    int choice, value, position, element;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at rear\n");
        printf("2. Delete from rear\n");
        printf("3. Insert at position\n");
        printf("4. Delete from position\n");
        printf("5. Insert after an element\n");
        printf("6. Insert before an element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 2:
                deleteRear();
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 5:
                printf("Enter value to insert and element after which to insert: ");
                scanf("%d %d", &value, &element);
                insertAfter(value, element);
                break;
            case 6:
                printf("Enter value to insert and element before which to insert: ");
                scanf("%d %d", &value, &element);
                insertBefore(value, element);
                break;
            case 7:
                traverseList();
                break;
            case 8:
                reverseList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}
