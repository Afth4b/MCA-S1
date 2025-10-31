// BFS implementation

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int q[MAX];

void bfs(int root){
    
}

int main(){

    int n,i,j,root;
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    int a[n][n];

    printf("\nEnter the adjacency matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("A[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the starting node : ");
    scanf("%d",&root);

    bfs(root);

}