#include <stdio.h>
#include <limits.h>

#define MAX 10

int adj[MAX][MAX];
int selected[MAX];
int n, e;
int sum = 0;

void prims(int start) {

    int edges = 0;
    sum = 0;  // reset sum

    // Mark all vertices unselected
    for (int i = 0; i < n; i++)
        selected[i] = 0;

    selected[start] = 1;

    // Prim’s Algorithm
    while (edges < n - 1) {
        int min = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && adj[i][j] != 0 && adj[i][j] < min) {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("\n%d -> %d  weight : %d", u, v, min);
            selected[v] = 1;
            sum += min;
            edges++;
        }
    }

    printf("\nTotal weight of MST : %d\n", sum);
}

int main() {

    int i, j, w, u, v, start;

    printf("\nEnter the number of vertices : ");
    scanf("%d", &n);

    printf("\nEnter the number of edges : ");
    scanf("%d", &e);

    // Initialize global adjacency matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("\nEnter edges (u v weight) :\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = adj[v][u] = w;
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%3d ", adj[i][j]);
        printf("\n");
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &start);

    prims(start);

    return 0;
}
