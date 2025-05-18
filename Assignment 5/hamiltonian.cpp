#include <iostream>
using namespace std;

#define V 5

bool isSafe(int v, int graph[][V], int path[], int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex.
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included in the path.
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(int graph[][V], int path[], int pos) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
        // And if there is an edge from the last included vertex to the first vertex
        return (graph[path[pos - 1]][path[0]] == 1);
    }

    // Try different vertices as the next candidate in the Hamiltonian Cycle.
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            // If adding vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }
    return false;
}

void hamCycle(int graph[][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Let the first vertex in the path be 0
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1)) {
        cout << "Solution does not exist";
        return;
    }

    cout << "Hamiltonian Cycle: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0]; // To show the cycle
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamCycle(graph);
    return 0;
}