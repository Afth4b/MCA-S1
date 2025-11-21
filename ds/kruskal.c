#include <stdio.h>
#define INF 9999

int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void kruskal(int adj[][100], int n) {

    int parent[100];
    for (int i = 0; i < n; i++) {
        parent[i] = i;        // IMPORTANT
    }

    int ne = 0;               // number of edges in MST

    while (ne < n - 1) {

        int min = INF;
        int a = -1, b = -1;

        // Find the minimum edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] != 0 && adj[i][j] < min) {
                    min = adj[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(parent, a);
        int v = find(parent, b);

        // If they do not form a cycle
        if (u != v) {
            printf("\n%d - %d (weight %d)", a, b, adj[a][b]);
            parent[v] = u;
            ne++;
        }

        // Remove edge by marking it as INF
        adj[a][b] = adj[b][a] = INF;
    }
}

void main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adj[100][100];

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    kruskal(adj, n);
}
