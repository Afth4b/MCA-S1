//stack implementation

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;

void push(int item);
void pop();
void display();



void push(int item){
    if(top==MAX-1){
        printf("Stack Overflow...Stack is full..!!");
        return;
    }else{
        top++;
        stack[top]=item;
        printf("%d pushed to stack..!!",item);
        return;
    }
}

void pop(){
    if(top==-1){
        printf("Stack Underflow...Stack is empty..!!");
        return;
    }else{
        printf("%d pop out of the stack",stack[top]);
        top--;
        return;
    }
}


void display(){
    if(top==-1){
        printf("Stack is empty..!!!");
        return;
    }else{
        printf("Stack elements are : \n");
        for(int i=top;i>-1;i--){
            printf("|  %d   |\n",stack[i]);
            printf("--------\n");
        }
    }
}

int main(){

    int choice,item;
    while(1){
        printf("\nStack operations : \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nSelect the operation : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
                printf("Enter the element to push to stack : ");
                scanf("%d",&item);
                push(item);
                break;
            
            case 2 :
                pop();
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