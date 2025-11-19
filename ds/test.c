#include <stdio.h>
#include <limits.h>

#define MAX 10

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < n; i++)
        if (mstSet[i] == 0 && key[i] < min)
            min = key[i], min_index = i;

    return min_index;
}

void prim(int n, int graph[MAX][MAX]) {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;       // Start at vertex 0
    parent[0] = -1;   // Root has no parent

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("\nMST Edges:\n");
    int sum = 0;
    for (int i = 1; i < n; i++) {
        printf("%d - %d  (weight %d)\n", parent[i], i, graph[i][parent[i]]);
        sum += graph[i][parent[i]];
    }

    printf("\nTotal weight of MST = %d\n", sum);
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    prim(n, graph);
    return 0;
}
