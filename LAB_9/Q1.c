#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked circular list
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* head = NULL;

// Function prototypes
void insert(int value);
void traverse();
void delete(int value);

// Function to insert an element into the doubly linked circular list
void insert(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct node* temp = head->prev;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }
}

// Function to traverse and display elements of the doubly linked circular list
void traverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("HEAD\n");
}

// Function to delete an element from the doubly linked circular list
void delete(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct node* temp = head;
    struct node* toDelete = NULL;

    // Find the node to delete
    do {
        if (temp->data == value) {
            toDelete = temp;
            break;
        }
        temp = temp->next;
    } while (temp != head);
    
    if (toDelete == NULL) {
        printf("Element %d not found in the list.\n", value);
        return;
    }
    
    if (toDelete->next == toDelete) {
        // List has only one node
        head = NULL;
    } else {
        struct node* prevNode = toDelete->prev;
        struct node* nextNode = toDelete->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        
        if (toDelete == head) {
            head = nextNode;  // If head is being deleted, update head
        }
    }
    
    free(toDelete);
    printf("Element %d deleted from the list.\n", value);
}

int main() {
    // Insert some elements
    insert(10);
    insert(20);
    insert(30);
    
    printf("List after insertion:\n");
    traverse();  // Display the list
    
    // Delete an element
    delete(20);
    
    printf("List after deletion:\n");
    traverse();  // Display the list
    
    return 0;
}
