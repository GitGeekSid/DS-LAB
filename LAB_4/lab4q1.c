#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the maximum size of the queue

// Circular Queue Structure
struct CircularQueue {
    int front, rear;
    int items[SIZE];
};

// Initialize the queue
void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct CircularQueue* q) {
    if ((q->rear + 1) % SIZE == q->front) {
        return 1;
    }
    return 0;
}

// Check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Insert an element into the circular queue
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1)  // First element to insert
            q->front = 0;

        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Remove an element from the circular queue
int dequeue(struct CircularQueue* q) {
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        value = q->items[q->front];
        if (q->front == q->rear) {
            // Queue has only one element, so we reset it after dequeuing
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        printf("Dequeued %d\n", value);
        return value;
    }
}

// Display the elements of the circular queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->items[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", q->items[q->rear]);
    }
}

int main() {
    struct CircularQueue q;
    initQueue(&q);

    // Enqueue and Dequeue operations
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);  // Queue should now be full

    display(&q);

    dequeue(&q);  // Remove one element
    dequeue(&q);

    display(&q);  // Queue after two dequeues

    enqueue(&q, 60);  // Add element after dequeue
    enqueue(&q, 70);  // Add another element

    display(&q);  // Final queue state

    return 0;
}
