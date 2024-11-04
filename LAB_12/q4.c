#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Maximum number of vertices in the graph

// Structure to represent a graph using an adjacency list
struct Graph {
    int vertices; // Number of vertices
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
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

// Recursive function for DFS
void dfsUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex); // Print the visited vertex

    // Visit all the adjacent vertices
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[vertex][i] == 1 && !visited[i]) {
            dfsUtil(graph, i, visited); // Recursive call
        }
    }
}

// Function to perform DFS
void dfs(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to track visited vertices
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    dfsUtil(graph, startVertex, visited);
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
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    dfs(graph, startVertex);

    // Free allocated memory
    free(graph);

    return 0;
}