#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void display()
{
    struct Node *temp = top;
    if (top == NULL)
    {
        printf("List is empty..!!\n");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("| %d |\n", temp->data);
            temp = temp->next;
        }
    }
}

void push(int item)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = item;
    new->next = top;
    top = new;
    printf("%d is inserted into the stack", item);
    display();
}

void pop()
{
    if (top == NULL)
    {
        printf("List is empty..!!\n");
        return;
    }
    struct Node* temp=top;
    printf("%d poped out of the stack",temp->data);
    top=temp->next;
    free(temp);
    display();
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("STACK USING LINKED LIST\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("SELECT STACK OPERATION TO BE PERFORMED:\n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter the element to push to stack : ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...!!");
            exit(0);
            break;
        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
        
    }
    return 0;
}
