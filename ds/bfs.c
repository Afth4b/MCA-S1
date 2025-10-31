#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void bfs(int root, int n, int a[][n]);
void enqueue(int value);
int dequeue();

int front = -1, rear = -1, n;
int queue[MAX];

void bfs(int root, int n, int a[][n]) {
    int v[n];

    // Mark visited array = 0
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }

    enqueue(root);
    v[root] = 1;

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (a[node][i] != 0 && !v[i]) {
                enqueue(i);
                v[i] = 1;
            }
        }
    }
}

void enqueue(int value) {
    if (rear == n - 1)
        return;
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1)
        return -1;
    int value = queue[front];
    front++;
    return value;
}

int main() {
    int i, j, root;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    int a[n][n];

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the starting node: ");
    scanf("%d", &root);
    if (root < 0 || root >= n) {
        printf("\nInvalid entry!");
        return 0;
    }

    printf("BFS --> ");
    bfs(root, n, a);

    return 0;
}
