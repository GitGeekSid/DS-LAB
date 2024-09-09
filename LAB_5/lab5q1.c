#include <stdio.h>
#include <ctype.h>  // For isdigit() and isalpha()
#include <string.h>  // For strlen()

#define MAX 100  // Maximum size of the stack

// Stack structure
struct Stack {
    int top;
    char items[MAX];
};

// Function to initialize stack
void initStack(struct Stack* s) {
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

// Function to push an element onto the stack
void push(struct Stack* s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    }
}

// Function to pop an element from the stack
char pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

// Function to get the top element of the stack without popping
char peek(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

// Function to check precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    initStack(&s);

    int j = 0;  // For postfix array index
    for (int i = 0; i < strlen(infix); i++) {
        char symbol = infix[i];

        // If the symbol is an operand, add it to postfix expression
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        // If the symbol is '(', push it to the stack
        else if (symbol == '(') {
            push(&s, symbol);
        }
        // If the symbol is ')', pop and add to postfix until '(' is found
        else if (symbol == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // Remove '(' from the stack
        }
        // If the symbol is an operator
        else if (isOperator(symbol)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(symbol)) {
                postfix[j++] = pop(&s);
            }
            push(&s, symbol);  // Push the current operator to the stack
        }
    }

    // Pop the remaining operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';  // Null terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    // Input infix expression
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Display the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
