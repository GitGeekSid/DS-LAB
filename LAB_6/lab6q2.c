#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    int items[MAX];
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

// Push element onto the stack
void push(struct Stack *s, int item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop element from the stack
int pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Function to evaluate a prefix expression
int evaluatePrefix(char prefix[]) {
    struct Stack s;
    initStack(&s);

    // Traverse the prefix expression from right to left
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char ch = prefix[i];

        // If the character is an operand, push it to the stack
        if (isdigit(ch)) {
            push(&s, ch - '0');  // Convert char to int and push
        } 
        // If the character is an operator, pop two operands, evaluate the result, and push it back
        else {
            int operand1 = pop(&s);
            int operand2 = pop(&s);

            switch (ch) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
                case '^':
                    push(&s, pow(operand1, operand2));  // Exponentiation
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
        }
    }

    // The final result will be at the top of the stack
    return pop(&s);
}

int main() {
    char prefix[MAX];

    // Input the prefix expression
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    // Evaluate the prefix expression
    int result = evaluatePrefix(prefix);

    // Display the result
    printf("The result of the prefix expression is: %d\n", result);

    return 0;
}
