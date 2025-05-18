#include <iostream>
using namespace std;

#define V 6

void topologicalSortUtil(int graph[V][V], int inDegree[], int result[]) {
    int index = 0;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            result[index++] = i;
        }
    }

    for (int i = 0; i < index; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[result[i]][j] == 1) {
                inDegree[j]--;
                if (inDegree[j] == 0) {
                    result[index++] = j;
                }
            }
        }
    }
}

void topologicalSort(int graph[V][V]) {
    int inDegree[V] = {0};
    int result[V];

    // Calculate in-degrees of all vertices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    topologicalSortUtil(graph, inDegree, result);

    cout << "Topological Sort: ";
    for (int i = 0; i < V; i++) {
        cout << result[i] << " ";
    }
}

int main() {
    int graph[V][V] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    topologicalSort(graph);
    return 0;
}