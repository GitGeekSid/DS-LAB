#include <stdio.h>
#include <stdlib.h>

// Structure to represent an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int vertices; // Number of vertices
    struct Node** adjLists; // Array of adjacency lists
};

// Function to create a new adjacency list node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Create an array of adjacency lists
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge in a directed graph
void addDirectedEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to add an edge in an undirected graph
void addUndirectedEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the adjacency list
void displayGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int vertices, choice, src, dest;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    do {
        printf("\nMenu:\n");
        printf("1. Add Directed Edge\n");
        printf("2. Add Undirected Edge\n");
        printf("3. Display Graph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addDirectedEdge(graph, src, dest);
                break;
            case 2:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addUndirectedEdge(graph, src, dest);
                break;
            case 3:
                displayGraph(graph);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}