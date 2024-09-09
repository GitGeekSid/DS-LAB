#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    int items[MAX];
};

// Initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(struct Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = item;
}

// Pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to convert decimal number to any base
void decimalToBase(int decimal, int base) {
    struct Stack s;
    initStack(&s);

    // Handle 0 explicitly
    if (decimal == 0) {
        printf("0");
        return;
    }

    // Convert decimal to base by dividing and pushing remainders
    while (decimal > 0) {
        int remainder = decimal % base;
        push(&s, remainder);
        decimal /= base;
    }

    // Pop all items to get the base equivalent in correct order
    printf("The number in base %d: ", base);
    while (!isEmpty(&s)) {
        int digit = pop(&s);
        
        // Handle digits > 9 for bases > 10 (e.g., base 16)
        if (digit >= 10) {
            printf("%c", 'A' + (digit - 10));  // Convert 10-15 to 'A'-'F'
        } else {
            printf("%d", digit);
        }
    }
    printf("\n");
}

int main() {
    int decimal, base;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Enter the base to convert to (2 to 16): ");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Base should be between 2 and 16.\n");
        return 1;
    }

    decimalToBase(decimal, base);

    return 0;
}
