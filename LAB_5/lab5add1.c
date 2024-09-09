#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int items[MAX];
    int top;
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
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Queue structure using two stacks
struct Queue {
    struct Stack s1;  // Stack 1 for enqueue operations
    struct Stack s2;  // Stack 2 for dequeue operations
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    initialize(&q->s1);
    initialize(&q->s2);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* q, int value) {
    // Enqueue is always done in stack 1
    push(&q->s1, value);
    printf("%d enqueued to the queue\n", value);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* q) {
    // If both stacks are empty, the queue is empty
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue Underflow\n");
        exit(1);
    }

    // If stack 2 is empty, move all elements from stack 1 to stack 2
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }

    // The element to be dequeued is at the top of stack 2
    return pop(&q->s2);
}

int main() {
    struct Queue q;
    initializeQueue(&q);

    // Perform enqueue operations
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    // Perform dequeue operations
    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));

    enqueue(&q, 50);  // Further enqueue
    enqueue(&q, 60);  // Further enqueue

    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));

    return 0;
}
