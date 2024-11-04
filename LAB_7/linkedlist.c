// // Write a menu driven program to perform the following operations on linked list. 
// // Insert an element before another element in the existing list 
// // Insert an element after another element in the existing list 
// // Delete a given element from the list 
// // Traverse the list 
// // Reverse the list 
// // Sort the list 

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node* next;
// }node;
// struct node* head;
// node* createnode(int element)
// {
//     node* newnode= (node*)malloc(sizeof(node));
//     newnode->data=element;
//     //newnode->next=NULL;
//     return newnode;
// }


// void insert(node*head,int element)
// {
//     node*newnode=createnode(element);
//     if(head==NULL){
//     head=newnode;
//     //newnode->next=NULL;
//     }
//     else{
//         node*current=head;
//         while(current->next!=NULL)
//         {
//             current=current->next;
//         }
//         current=newnode;
//         //newnode->next=NULL;
//     }
// }
// // void insertbefore(node*head,int element,int target_element)
// // {
// //     node*newnode=createnode(element);
// //     node*current=head;
// //     while(1){

// //     }

// // }


// void delete(node* head,int element)
// {
//     if(head==NULL){
//         printf("Linked list is empty\n");
//         //return NULL;
//     }
//     node*current=head;
//     node*prev=NULL;
//     while(current!=NULL && current->data!=element){
//         prev=current;
//         current=current->next;
//     }
//     if(current==NULL){
//         printf("Element not found in linked list\n");
//         //return head;
//     }
//     if(prev==NULL){
//         head=current->next;
//     }
//     else{
//         prev->next=current->next;
//     }
//     free(current);
//     printf("Element deleted successfully\n");
//     //return head
// }
// void display(node*head)
// {
//     if(head==NULL){
//         printf("Linked list is empty\n");
//         return;
//     }
//     node*current=head;
//     printf("Linked list elements: ");
//     while(current!=NULL){
//         printf("%d",current->data);
//         current=current->next;
//     }
//     printf("\n");
// }
// int main()
// {
//     node*head=NULL;
//     int choice,element,target_element;
//     while(1)
//     {
//         printf("1:Insert element");
//          printf("2:Insert element before");
//           printf("3:Insert element after");
//            printf("4:To delete an element");
//             printf("5:To reverse the list");
//              printf("6:To sort the list");

//     printf("Enter your choice: ");
//     scanf("%d",&choice);
//     switch (choice)
//     {
//         case 1:
//             printf("enter element to insert: ");
//             scanf("%d",&element);
//             insert(head,element);
//             break;
//         case 2:
//             printf("Enter the element to enter:");
//             scanf("%d",&element);
//             printf("Enter target element: ");
//             scanf("%d",&target_element);
//             //insert_before(head,element,target_element);
//             break;
//         case 3:
//             printf("Enter the element to enter:");
//             scanf("%d",&element);
//             printf("Enter target element: ");
//             scanf("%d",&target_element);
//             //insert_after(head,element,target_element);
//             break;
//         case 4:
//             printf("Enter the elment to delete:");
//             scanf("%d",&element);
//             delete(head,element);
//             break;
//         case 5:
//             printf("Reversed list is: ");
//            // reverse(head);
//             break;
//         case 6:
//         printf("Sorted list is: ");
//         //sortlist(head);
//         break;
//         case 7:
//             display(head);
//             break;
//         case 8:
//             return 0;
//     }
//     }
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node* head = NULL;

// Function prototypes
// void insertBefore(int value, int before);
// void insertAfter(int value, int after);
// void deleteNode(int value);
// void traverseList();
// void reverseList();
// void sortList();
// void deleteAlternate();
// void insertSorted(int value);

// Function to insert a node before another node
void insertBefore(int value, int before) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    if (head == NULL || head->data == before) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL && temp->next->data != before) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Element %d not found in the list.\n", before);
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a node after another node
void insertAfter(int value, int after) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    struct node* temp = head;
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", after);
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node with a given value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    if (head->data == value) {
        head = head->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", value);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to traverse the list
void traverseList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the list
void reverseList() {
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Function to sort the list
void sortList() {
    if (head == NULL || head->next == NULL)
        return;
    struct node* i = head;
    struct node* j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to delete every alternate node in the list
void deleteAlternate() {
    if (head == NULL)
        return;
    struct node* temp = head;
    struct node* nextNode;
    while (temp != NULL && temp->next != NULL) {
        nextNode = temp->next;
        temp->next = nextNode->next;
        free(nextNode);
        temp = temp->next;
    }
}

// Function to insert an element in a sorted list
void insertSorted(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    if (head == NULL || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Main function with menu
int main() {
    int choice, value, element;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert before an element\n");
        printf("2. Insert after an element\n");
        printf("3. Delete an element\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert in a sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert and element before which to insert: ");
                scanf("%d %d", &value, &element);
                insertBefore(value, element);
                break;
            case 2:
                printf("Enter value to insert and element after which to insert: ");
                scanf("%d %d", &value, &element);
                insertAfter(value, element);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                traverseList();
                break;
            case 5:
                reverseList();
                break;
            case 6:
                sortList();
                break;
            case 7:
                deleteAlternate();
                break;
            case 8:
                printf("Enter value to insert in sorted list: ");
                scanf("%d", &value);
                insertSorted(value);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}





