// topoligal sorting 

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main(){
    int n,i,j,a[MAX][MAX],indegree[MAX]={},queue[MAX],front=0,rear=0,topo[MAX],count=0;
    printf("Enter the number of nodes of graph :\n");
    scanf("%d",&n);
    printf("Enter the elements of adajacency matrix (1 or 0):\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("A[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
            if(a[i][j]==1&&a[j][i]==1){
                printf("cannot be 1\n");
                a[i][j]=0;
            }
        }
    }
    printf("Adjacenecy Matrix is :\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    //find indegree
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j][i]==1){
                indegree[i]++;
            }   
        }
    }
    for(i=0;i<n;i++){
        printf("indegree(%d)= %d \n",i,indegree[i]);
    }
    //enqueue vertices have indegree 0
    for(i=0;i<n;i++){
        if(indegree[i]==0){
            queue[rear++]=i;
        }
    }
    
    while(front < rear) {
        int node = queue[front++];
        topo[count++] = node;

        for(i = 0; i < n; i++) {
            if(a[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    if(count!=n){
        printf("Cycle detected !!");
    }else{
        printf("Topoligical sorted :");
        for(i=0;i<n;i++){
            printf("%d ",topo[i]);
        }   
        printf("\n");
    }
    return 0;
}