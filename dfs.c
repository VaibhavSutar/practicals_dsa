#include <stdio.h>

#define MAX 100

// Function to perform depth-first traversal
void DFS(int graph[MAX][MAX], int visited[MAX], int n, int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;  // Mark the current vertex as visited

    // Visit all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, visited, n, i);  // Recursively visit the adjacent vertex
        }
    }
}
void displayAdjacencyMatrix(int graph[MAX][MAX], int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[MAX][MAX], visited[MAX];
    int vertices, edges;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    // Initialize the graph and visited array
    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }
    displayAdjacencyMatrix(graph, vertices);
    // Input the edges of the graph
    printf("Enter the edges (format: vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;  // Mark the edge between v1 and v2
    }

    // Perform DFS traversal starting from each unvisited vertex
    printf("DFS Traversal: ");
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(graph, visited, vertices, i);
        }
    }

    return 0;
}
