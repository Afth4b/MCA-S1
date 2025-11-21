#include <stdio.h>

#define INF 9999

int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void Union(int parent[], int u, int v) {
    parent[v] = u;
}

int main() {
    int n = 5;

    int adj[5][5] = {
        {0, 2, 4, 0, 0},
        {2, 0, 3, 6, 0},
        {4, 3, 0, 5, 1},
        {0, 6, 5, 0, 7},
        {0, 0, 1, 7, 0}
    };

    int parent[5];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int ne = 0;   // number of edges used

    printf("Edges in the MST:\n");

    while (ne < n - 1) {
        int min = INF;
        int a = -1, b = -1;

        // Step 1: Find smallest edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] && adj[i][j] < min) {
                    min = adj[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(parent, a);
        int v = find(parent, b);
        
        // Step 2: Add edge if no cycle
        if (u != v) {
            printf("%d - %d  (weight = %d)\n", a, b, min);
            Union(parent, u, v);
            ne++;
        }

        // Step 3: Mark edge as used
        adj[a][b] = adj[b][a] = INF;
    }

    return 0;
}
