#include <iostream>

using namespace std;

#define VERTICES 4 // Number of vertices in the graph

bool isColorSafe(int graph[VERTICES][VERTICES], int color[], int vertex, int c) {
    for (int i = 0; i < VERTICES; i++) {
        if (graph[vertex][i] == 1 && color[i] == c) {
            return false; // Conflict found
        }
    }
    return true;
}

bool colorGraphUtil(int graph[VERTICES][VERTICES], int m, int color[], int vertex) {
    if (vertex == VERTICES) {
        return true; // All vertices are colored
    }
    for (int c = 1; c <= m; c++) { // Try different colors
        if (isColorSafe(graph, color, vertex, c)) {
            color[vertex] = c; // Assign color
            if (colorGraphUtil(graph, m, color, vertex + 1)) {
                return true; // Continue to color next vertex
            }
            color[vertex] = 0; // Backtrack
        }
    }
    return false; // No valid color found
}

void colorGraph(int graph[VERTICES][VERTICES], int m) {
    int color[VERTICES] = {0}; // Initialize color array
    if (colorGraphUtil(graph, m, color, 0)) {
        cout << "Solution Exists: Following are the assigned colors:" << endl;
        for (int i = 0; i < VERTICES; i++) {
            cout << "Vertex " << i + 1 << ": Color " << color[i] << endl; // Output in 1-based index
        }
    } else {
        cout << "Solution does not exist" << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[VERTICES][VERTICES] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    int m = 3; // Number of colors

    colorGraph(graph, m);
    return 0;
}