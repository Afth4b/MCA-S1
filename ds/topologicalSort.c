#include<stdio.h>


void main(){
    int n,i,j,u;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&n);
    int adj[n][n];
    int q[n];
    int front=0,rear=-1;
    int indegree[n];
    int count = 0;

    // making the indegree 0
    for(i=0;i<n;i++){
        indegree[i] = 0;
    }

    // reading adjacency matrix
    printf("\nEnter the adjacency matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("adj[%d][%d] = ",i,j);
            scanf("%d",&adj[i][j]);

            // checking indegree of vertex while reading the adjacency matrix
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // printing adjacency matrix
    printf("\nAdjacency matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf(" %d ",adj[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<n;i++){
        if(indegree[i] == 0)
            q[++rear] = i;
    }

    printf("\nTopological order : ");

    while(front<=rear) {

        u = q[front++];
        printf("%d  ",u);
        count++;

        for(i=0;i<n;i++){
            if(adj[u][i]>0){
                indegree[i]--;
            
                if(indegree[i]==0)
                    q[++rear] = i;
            }
                
        }


    }

    if(count!=n){
        printf("\nGraph contains a cycle..!!");
        return;
    }









}