// Queue using Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void display()
{
    if (front == NULL)
    {
        printf("\nQueue is empty..!!");
        return;
    }
    else
    {
        struct Node *temp = front;
        while (temp != NULL)
        {
            printf("|  %d  |-->", temp->data);
            temp = temp->next;
        }
        printf("REAR\n");
    }
}

void enqueue(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;

    if (rear == NULL)
    {
        front = new;
        rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }

    printf("\nEnqueued element: %d\n", data);
    display();
}

void dequeue()
{

    if (front == NULL)
    {
        printf("\nQueue is empty...Deletion is not possible..!!\n");
    }
    else
    {
        struct Node *temp = front;
        front = temp->next;
        if(front==NULL){
            rear = NULL;
        }

        printf("\n%d dequeued from queue..!!\n", temp->data);
        free(temp);
    }

    display();
}

int main()
{

    int choice, item;
    while (1)
    {
        printf("\nQueue using linked list\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nChoose Queue operation to be performed: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the element to insert into queue : ");
            scanf("%d", &item);
            enqueue(item);
            break;

            case 2:
                dequeue();
                break;

        case 3:
            display();
            break;

        case 4:
            printf("\nExiting program...!!!");
            exit(0);
            break;

        default:
            printf("\nInvalid choice....try again..!!");
            break;
        }
    }

    return 0;
}
