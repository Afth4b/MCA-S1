#include<stdio.h>
#include<stdlib.h>
# define MAX 10

int q[MAX],v[MAX],a[MAX][MAX];
int front=-1,rear=-1,i,n;

void enqueue(int item){
    if(front==-1){
        front++;
    }
    rear++;
    q[rear]=item;
}

int dequeue(){
    if (front == -1 || front > rear) {
        return -1; 
    }
    int item=q[front];
    front++;
    return item;
}

void bfs(int root,int a[MAX][MAX]){
    enqueue(root);
    v[root]=1;
    while (front != -1 && front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        for(i=0;i<n;i++){
            if(a[node][i]==1&&!v[i]){
                enqueue(i);
                v[i]=1;
            }
        }
    }
    printf("\n");
}

int main(){
    int root,j;
    printf("Enter the number nodes :");
    scanf("%d",&n);
    printf("Enter the elements of adjacency matrix :\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("A[%d][%d] =",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Adjacency Matrix :\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        v[i]=0;
    }
    printf("Enter the starting node :");
    scanf("%d",&root);
    printf("BFS ->");
    bfs(root,a);
    return 0;
}