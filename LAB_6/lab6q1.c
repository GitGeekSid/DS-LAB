#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
struct Stack {
    int top;
    char items[MAX];
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push element onto the stack
void push(struct Stack* s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop element from the stack
char pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Peek at the top element of the stack
char peek(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    } else {
        return -1;
    }
}

// Function to check if the character is an operand
int isOperand(char ch) {
    return isalpha(ch);  // Checks if the character is a letter
}

// Function to check precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to reverse a string
void reverse(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    initStack(&s);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the output
        if (isOperand(ch)) {
            postfix[j++] = ch;
        }
        // If the character is '(', push it onto the stack
        else if (ch == '(') {
            push(&s, ch);
        }
        // If the character is ')', pop until '(' is found
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // Pop '('
        }
        // Operator encountered
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    // Step 1: Reverse the infix expression
    reverse(infix);

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Step 3: Convert the modified infix to postfix
    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Step 4: Reverse the postfix expression to get prefix
    reverse(postfix);
    strcpy(prefix, postfix);  // Copy the result to prefix
}

int main() {
    char infix[MAX], prefix[MAX];

    // Input infix expression
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert to prefix
    infixToPrefix(infix, prefix);

    // Display prefix expression
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
