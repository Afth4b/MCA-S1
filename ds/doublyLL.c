#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void display()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is Empty...!!\n");
    }
    printf("NULL");
    while (temp != NULL)
    {
        printf("<-%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void insertAtBegning(int value)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = value;
    new->next = head;
    new->prev = NULL;
    if (head != NULL)
    {
        head->prev = new;
    }
    head = new;
    printf("%d is inserted at the Begning of linkedlist\n", value);
    display();
}

void insertAtEnd(int value)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = value;
    new->next = NULL;
    new->prev = NULL;
    printf("%d is inserted at the End of Doubly linkedlist\n", value);
    if (head == NULL)
    {
        head = new;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    display();
}

void insertAtPosition(int value, int pos)
{
    if (pos < 0)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = value;
    new->next = NULL;
    new->prev = NULL;

    if (pos == 0)
    {
        insertAtBegning(value);
        return;
    }

    struct Node *temp = head;
    int i;

    for (i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position Out of Bounds...!!!!\n");
        free(new);
        return;
    }

    new->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = new;
    }

    temp->next = new;
    new->prev = temp;
    printf("%d is inserted at position %d\n", value, pos);
    display();
}

void deletionFromBegning()
{
    if (head == NULL)
    {
        printf("List is Empty.. So that Deletion is not Possible!!!");
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    display();
}

void deletionFromEnd()
{
    if (head == NULL)
    {
        printf("List is Empty.. So that Deletion is not Possible\n");
        return;
    }

    struct Node *prev = NULL;
    struct Node *temp = head;

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        display();
        return;
    }

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    display();
}

void deletionByValue(int value)
{
    if (head == NULL)
    {
        printf("List is empty..!!!\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            if (prev == NULL)
            {
                head = temp->next;
                free(temp);
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    display();
}

void search(int value) {
    if (head == NULL) {
        printf("The list is empty. Cannot search.\n");
        return;
    }

    struct Node *temp = head;
    int pos = 1;

    while (temp!=NULL) {
        if (temp->data == value) {
            printf("%d is present at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d is not present in the linked list\n", value);
}

void merge(){
    int n,i,val;
    printf("Enter the number of elements of linkedlist which is to be merged to the linkedlist");
    scanf("%d",&n);
    printf("Enter the elements of linkedlist");
    for(i=0;i<n;i++){
        struct Node* head1;
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&val);
        new->data=val;
        new->next=
    }
}

void main()
{

    int choice, value, pos = 0;
    while (1)
    {
        printf("\nLINKED LIST OPERATIONS:\n");
        printf("1. Insertion At Begning\n");
        printf("2. Insertion At End\n");
        printf("3. Insertion by any Position\n");
        printf("4. Deletion From Begning\n");
        printf("5. Deletion From End\n");
        printf("6. Deletion by Value\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Merge\n");
        printf("10. Exit\n");
        printf("Select Operation to be Performed :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert at the Begning of linkedlist :");
            scanf("%d", &value);
            insertAtBegning(value);
            break;
        case 2:
            printf("Enter the Element to insert at the End of linkedlist :");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            printf("Enter the Element to insert to the linkedlist :");
            scanf("%d", &value);
            printf("Enter the position where to insert the Element :");
            scanf("%d", &pos);
            insertAtPosition(value, pos);
            break;
        case 4:
            deletionFromBegning();
            break;
        case 5:
            deletionFromEnd();
            break;
        case 6:
            printf("Enter the Element to Delete from linkedlist :");
            scanf("%d", &value);
            deletionByValue(value);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Enter the element to Search in the linkedlist :");
            scanf("%d",&value);
            search(value);
            break;
        case 9:
            merge();
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("Invalid Choice!!!!");
            break;
        }
    }
}
