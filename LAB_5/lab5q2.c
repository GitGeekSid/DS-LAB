#include <stdio.h>
#include <ctype.h>  // For isdigit()
#include <stdlib.h> // For atof()

#define MAX 100  // Maximum size of the stack

// Stack structure
struct Stack {
    int top;
    float items[MAX];
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
void push(struct Stack* s, float item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
float pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Function to evaluate a postfix expression
float evaluatePostfix(char postfix[]) {
    struct Stack s;
    initStack(&s);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        // If the symbol is an operand, push it onto the stack
        if (isdigit(symbol)) {
            push(&s, symbol - '0');  // Convert char to int
        }
        // If the symbol is an operator, pop two operands, apply the operator, and push the result
        else {
            float operand2 = pop(&s);
            float operand1 = pop(&s);
            float result;

            switch (symbol) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", symbol);
                    exit(1);
            }

            push(&s, result);
        }
    }

    // The result is the last item on the stack
    return pop(&s);
}

int main() {
    char postfix[MAX];

    // Input postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Evaluate postfix expression
    float result = evaluatePostfix(postfix);

    // Display the result
    printf("Result of postfix evaluation: %.2f\n", result);

    return 0;
}
