#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Maximum number of vertices in the graph

// Structure to represent a graph
struct Graph {
    int vertices; // Number of vertices
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
};

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge in a directed graph
void addDirectedEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1; // Mark the edge from src to dest
}

// Function to add an edge in an undirected graph
void addUndirectedEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1; // Mark the edge from src to dest
    graph->adjacencyMatrix[dest][src] = 1; // Mark the edge from dest to src
}

// Function to display the adjacency matrix
void displayGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int vertices, choice, src, dest;
    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
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
                printf("Enter source and destination vertices (0 to %d): ", vertices - 1);
                scanf("%d %d", &src, &dest);
                addDirectedEdge(graph, src, dest);
                break;
            case 2:
                printf("Enter source and destination vertices (0 to %d): ", vertices - 1);
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
    free(graph);

    return 0;
}