#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define maximum size for stack and expression
#define MAX 100

// Stack structure to store strings (intermediate expressions)
struct Stack {
    char* items[MAX];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to push a string onto the stack
void push(struct Stack* s, char* item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = item;
}

// Function to pop a string from the stack
char* pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return s->items[s->top--];
}

// Function to convert postfix to fully parenthesized infix expression
void postfixToInfix(char* postfix) {
    struct Stack s;
    initialize(&s);

    int length = strlen(postfix);

    for (int i = 0; i < length; i++) {
        // If the character is an operand, push it as a string onto the stack
        if (isalnum(postfix[i])) {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(&s, operand);
        }
        // If the character is an operator, pop two operands, combine them, and push the result
        else {
            char* operand2 = pop(&s);
            char* operand1 = pop(&s);

            int size = strlen(operand1) + strlen(operand2) + 4;
            char* expression = (char*)malloc(size * sizeof(char));

            // Create a parenthesized string: (operand1 operator operand2)
            snprintf(expression, size, "(%s %c %s)", operand1, postfix[i], operand2);

            // Push the new expression onto the stack
            push(&s, expression);

            // Free the old operands
            free(operand1);
            free(operand2);
        }
    }

    // The final expression is the top of the stack
    printf("Fully Parenthesized Infix Expression: %s\n", pop(&s));
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix);

    return 0;
}
