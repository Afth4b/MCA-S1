// implementation of circular queue

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item);
void dequeue();
void display();

void enqueue(int item){
    if(front==-1 && rear==-1){
        front++;
        rear++;
    }
    
    queue[(rear+1)%MAX] = item;
    printf("\n %d enqueued to queue",item);
    display();
        
}

void dequeue(){
    if(front==-1){
        printf("\nQueue is empty..!!");
        return;
    }

    int removed = queue[front];
    if(front==rear){
        front = rear = -1;
    }else{
        front = (front+1)%MAX;
    }

    printf("\n%d deleted from queue",removed);
    display();
}

void display(){
    if(front==-1){
        printf("\nQueue empty....!!");
        return;
    }

    printf("\nQueue elements are : ");
    int i = front;
    while(i!=rear){
        printf("%d  ",queue[i]);
        i = (i+1)%MAX;
    }

    printf("\n");
}

int main(){

    int choice,item;
    while(1){
        printf("\nCircular Queue operations : \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nSelect the operation : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
                printf("Enter the element to insert to Queue : ");
                scanf("%d",&item);
                enqueue(item);
                break;
            
            case 2 :
                dequeue();
                break;
            case 3 : display();
            break;

            case 4 : {
                printf("Exiting program...!!");
                exit(0);
            }
                break;

            default:
                printf("Invalid choice! Try again.\n");

        }
    }

    return 0;
}