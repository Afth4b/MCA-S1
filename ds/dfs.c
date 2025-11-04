#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int i,v[MAX],n;

void dfs(int root,int a[][MAX]){
    printf("%d ",root);
    v[root]=1;
    for(i=0;i<n;i++){
        if(a[root][i]==1 && !v[i]){
            dfs(i,a);
        }
    }
}

int main() {
    int j, root;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    int a[MAX][MAX];

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

    printf("Enter the starting node (0-%d) :",n-1);
    scanf("%d",&root);
    if (root < 0 || root >= n) {
        printf("\nInvalid entry!");
        return 0;
    }

    for(i=0;i<n;i++){
        v[i]=0;
    }
    printf("DFS -->");
    dfs(root,a);
    return 0;
}