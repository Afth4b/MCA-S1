// Prims algorithm - reading input adjacency matrix from user
#include<stdio.h>

int i,j;

void main(){
    int n,e,u,v,weight,start;

    printf("\nEnter the number of vertices : ");
    scanf("%d",&n);

    // adjacent matrix declaration
    int adj[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adj[i][j]=0;

    printf("\nEnter the number of edges : ");
    scanf("%d",&e);

    printf("\nEnter edges and weight (u v weight): \n");
    for(i=0;i<e;i++){
        scanf("%d %d %d",&u,&v,&weight);
        adj[u][v] = adj[v][u] = weight;
    }

    printf("\nAdjacency matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the starting vertex : ");
    scanf("%d",&start);

    prims(start);


}