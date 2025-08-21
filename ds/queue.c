//stack implementation

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int Q[MAX];
int FRONT=-1;
int REAR=-1;

void enqueue(int item);
void dequeue();
void display();



void enqueue(int item){
    if(REAR==MAX-1){
        printf("Queue Overflow...Queue is full..!!");
        return;
    }else{
        if(FRONT==-1)
        {
            FRONT++;
        }
        REAR++;
        Q[REAR]=item;
        printf("%d inserted to queue..!!",item);
        return;
    }
}

void dequeue(){
    if(FRONT==-1){
        printf("Queue Underflow...Queue is empty..!!");
        return;
    }else{
        printf("%d deleted out of the Queue",Q[FRONT]);
        FRONT++;
        return;
    }
}


void display(){
    if(FRONT==-1){
        printf("Queue is empty..!!!");
        return;
    }else{
        printf("Queue elements are : \n");
        for(int i=FRONT;i<=REAR;i++){
            printf("|  %d   |",Q[i]);
        
        }
    }
}

int main(){

    int choice,item;
    while(1){
        printf("\nQueue operations : \n");
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
                break;

        }
    }

    return 0;
}