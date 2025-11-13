#include <stdio.h>
#include <limits.h>

#define MAX 10

void prims(int graph[MAX][MAX], int n);

int main() {
    int n, i, j;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INT_MAX; // No edge represented by infinity
        }
    }

    prims(graph, n);

    return 0;
}

// Function to implement Prim's Algorithm
void prims(int graph[MAX][MAX], int n) {
    int selected[MAX];
    int no_of_edges = 0;
    int i, j, min, x, y, total_cost = 0;

    // Initially, no vertices are selected
    for (i = 0; i < n; i++)
        selected[i] = 0;

    // Start from vertex 0
    selected[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (no_of_edges < n - 1) {
        min = INT_MAX;
        x = 0;
        y = 0;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, min);
        total_cost += min;
        selected[y] = 1;
        no_of_edges++;
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", total_cost);
}
