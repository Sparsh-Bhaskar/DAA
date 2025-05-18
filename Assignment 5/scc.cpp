#include <iostream>
using namespace std;

#define V 6

// Function to perform DFS
void DFS(int graph[V][V], int v, bool visited[]) {
    visited[v] = true;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function to fill vertices in stack according to their finishing times
void fillOrder(int graph[V][V], int v, bool visited[], int stack[], int &top) {
    visited[v] = true;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            fillOrder(graph, i, visited, stack, top);
        }
    }
    stack[top++] = v; // Push current vertex to stack
}

// Function to get the transpose of the graph
void getTranspose(int graph[V][V], int transposedGraph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            transposedGraph[j][i] = graph[i][j];
        }
    }
}

// Function to count strongly connected components
void countSCCs(int graph[V][V]) {
    bool visited[V] = {false};
    int stack[V];
    int top = 0;

    // Fill vertices in stack according to their finishing times
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            fillOrder(graph, i, visited, stack, top);
        }
    }

    // Get the transposed graph
    int transposedGraph[V][V];
    getTranspose(graph, transposedGraph);

    // Mark all the vertices as not visited for the second DFS
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Now process all vertices in order defined by stack
    int sccCount = 0;
    while (top > 0) {
        int v = stack[--top]; // Get the top vertex
        if (!visited[v]) {
            DFS(transposedGraph, v, visited); // Perform DFS on transposed graph
            sccCount++; // Increment count of strongly connected components
        }
    }

    cout << "Number of Strongly Connected Components: " << sccCount << endl;
}

int main() {
    // Example directed graph
    int graph[V][V] = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0}
    };

    countSCCs(graph);
    return 0;
}