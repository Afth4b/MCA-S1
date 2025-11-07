#include <stdio.h>
#define MAX 10

int main() {
    int n, i, j;
    int adj[MAX][MAX];
    int indegree[MAX] = {0}, queue[MAX], front = 0, rear = -1;
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 1)
                indegree[j]++;   // Count indegree of each vertex
        }
    }

    // Enqueue all vertices with indegree 0
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[++rear] = i;
    }

    printf("\nTopological Order: ");

    while (front <= rear) {
        int u = queue[front++];  // Dequeue vertex
        printf("%d ", u);    // Print vertex (1-based index)
        count++;

        // For all adjacent vertices of u
        for (i = 0; i < n; i++) {
            if (adj[u][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    if (count != n)
        printf("\nGraph has a cycle. Topological sorting not possible.\n");
    else
        printf("\n");

    return 0;
}
