#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack implementation
struct Stack {
    int top;
    char items[MAX];
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

// Push an element into the stack
void push(struct Stack* s, char item) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->items[++s->top] = item;  // Increment top first, then push item
}

// Pop an element from the stack
char pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->items[s->top--];  // Decrement top after popping the item
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    struct Stack s;
    initStack(&s);
    
    int len = strlen(str);
    int i;

    // Push all characters of the string to the stack
    for (i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // Compare characters by popping from the stack
    for (i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0;  // Not a palindrome
        }
    }

    return 1;  // String is a palindrome
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove the newline character at the end, if present
    str[strcspn(str, "\n")] = '\0';

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
