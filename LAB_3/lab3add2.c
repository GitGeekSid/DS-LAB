#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Maximum size of the stack

// Stack structure to store opening parentheses
struct Stack {
    int top;
    char items[MAX];
};

// Function to initialize the stack
void initialize(struct Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Function to push an element into the stack
void push(struct Stack* s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

// Function to pop an element from the stack
char pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to check if the given character is an opening parenthesis
int isOpeningParenthesis(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

// Function to check if the given character is a closing parenthesis
int isClosingParenthesis(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

// Function to check if two parentheses are matching
int isMatchingPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

// Function to check for matching parentheses in a given expression
int checkParentheses(char* expr) {
    struct Stack s;
    initialize(&s);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        if (isOpeningParenthesis(ch)) {
            push(&s, ch);
        } else if (isClosingParenthesis(ch)) {
            if (isEmpty(&s)) {
                return 0;  // Unmatched closing parenthesis
            } else {
                char top = pop(&s);
                if (!isMatchingPair(top, ch)) {
                    return 0;  // Mismatched pair
                }
            }
        }
    }

    // If stack is not empty at the end, unmatched opening parenthesis exists
    return isEmpty(&s);
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (checkParentheses(expr)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
