#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure for string
struct Stack {
    int top;
    char items[MAX][MAX];  // Array to store string elements
};

// Initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Push string onto the stack
void push(struct Stack *s, char *item) {
    if (!isFull(s)) {
        strcpy(s->items[++s->top], item);
    } else {
        printf("Stack overflow\n");
    }
}

// Pop string from the stack
char* pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack underflow\n");
        return NULL;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert a prefix expression to a fully parenthesized infix expression
void prefixToInfix(char prefix[]) {
    struct Stack s;
    initStack(&s);
    
    int len = strlen(prefix);

    // Traverse the prefix expression from right to left
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        // If the character is an operand, push it onto the stack
        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};  // Convert char to string
            push(&s, operand);
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            // Pop two operands
            char *operand1 = pop(&s);
            char *operand2 = pop(&s);

            // Create a new string in the format (operand1 operator operand2)
            char result[MAX];
            sprintf(result, "(%s %c %s)", operand1, ch, operand2);

            // Push the resulting string back onto the stack
            push(&s, result);
        }
    }

    // The final result will be at the top of the stack
    printf("Fully parenthesized infix expression: %s\n", pop(&s));
}

int main() {
    char prefix[MAX];

    // Input the prefix expression
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    // Convert the prefix expression to infix
    prefixToInfix(prefix);

    return 0;
}
