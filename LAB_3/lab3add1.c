#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the array

// Structure to represent multiple stacks
struct MultipleStacks {
    int top[10];  // Array to store the top index of each stack
    int boundary[10];  // Array to define the boundary for each stack
    int stack[MAX];  // Array to store the elements of all stacks combined
    int numStacks;  // Number of stacks
};

// Function to initialize the stacks
void initializeStacks(struct MultipleStacks *s, int numStacks) {
    s->numStacks = numStacks;
    int sizePerStack = MAX / numStacks;

    // Set the boundaries and top pointers for each stack
    for (int i = 0; i < numStacks; i++) {
        s->top[i] = i * sizePerStack - 1;  // Top of stack is initialized to -1 for each stack
        s->boundary[i] = i * sizePerStack + sizePerStack - 1;  // Set the boundary for each stack
    }
}

// Function to check if a particular stack is full
int isFull(struct MultipleStacks *s, int stackNumber) {
    return s->top[stackNumber] == s->boundary[stackNumber];
}

// Function to check if a particular stack is empty
int isEmpty(struct MultipleStacks *s, int stackNumber) {
    return s->top[stackNumber] == (stackNumber * (MAX / s->numStacks)) - 1;
}

// Function to push an element onto a specific stack
void push(struct MultipleStacks *s, int stackNumber, int value) {
    if (isFull(s, stackNumber)) {
        printf("Stack %d is full.\n", stackNumber + 1);
    } else {
        s->top[stackNumber]++;
        s->stack[s->top[stackNumber]] = value;
        printf("Pushed %d into stack %d.\n", value, stackNumber + 1);
    }
}

// Function to pop an element from a specific stack
int pop(struct MultipleStacks *s, int stackNumber) {
    if (isEmpty(s, stackNumber)) {
        printf("Stack %d is empty.\n", stackNumber + 1);
        return -1;  // Return -1 if stack is empty
    } else {
        int value = s->stack[s->top[stackNumber]];
        s->top[stackNumber]--;
        printf("Popped %d from stack %d.\n", value, stackNumber + 1);
        return value;
    }
}

// Function to display the elements of a specific stack
void display(struct MultipleStacks *s, int stackNumber) {
    if (isEmpty(s, stackNumber)) {
        printf("Stack %d is empty.\n", stackNumber + 1);
    } else {
        printf("Stack %d elements:\n", stackNumber + 1);
        for (int i = (stackNumber * (MAX / s->numStacks)); i <= s->top[stackNumber]; i++) {
            printf("%d ", s->stack[i]);
        }
        printf("\n");
    }
}

int main() {
    struct MultipleStacks s;
    int numStacks, choice, stackNumber, value;

    printf("Enter the number of stacks: ");
    scanf("%d", &numStacks);

    initializeStacks(&s, numStacks);

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the stack number (1-%d): ", numStacks);
                scanf("%d", &stackNumber);
                if (stackNumber < 1 || stackNumber > numStacks) {
                    printf("Invalid stack number.\n");
                    break;
                }
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, stackNumber - 1, value);  // stackNumber - 1 because index starts from 0
                break;

            case 2:
                printf("Enter the stack number (1-%d): ", numStacks);
                scanf("%d", &stackNumber);
                if (stackNumber < 1 || stackNumber > numStacks) {
                    printf("Invalid stack number.\n");
                    break;
                }
                pop(&s, stackNumber - 1);  // stackNumber - 1 because index starts from 0
                break;

            case 3:
                printf("Enter the stack number (1-%d): ", numStacks);
                scanf("%d", &stackNumber);
                if (stackNumber < 1 || stackNumber > numStacks) {
                    printf("Invalid stack number.\n");
                    break;
                }
                display(&s, stackNumber - 1);  // stackNumber - 1 because index starts from 0
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
