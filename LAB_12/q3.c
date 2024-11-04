#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Maximum number of vertices in the graph

// Structure to represent a graph using an adjacency list
struct Graph {
    int vertices; // Number of vertices
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
};

// Queue structure for BFS
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1; // Mark the edge from src to dest
    graph->adj[dest][src] = 1; // For undirected graph, mark the edge from dest to src
}

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1; // Reset the queue
        }
    }
    return item;
}

// Function to perform BFS
void bfs(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to track visited vertices
    struct Queue q;
    initQueue(&q);

    visited[startVertex] = 1; // Mark the starting vertex as visited
    enqueue(&q, startVertex); // Enqueue the starting vertex

    printf("BFS Traversal starting from vertex %d: ", startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        // Visit all the adjacent vertices of the dequeued vertex
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                enqueue(&q, i); // Enqueue the adjacent vertex
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int vertices, edges, src, dest;
    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);

    // Free allocated memory
    free(graph);

    return 0;
}