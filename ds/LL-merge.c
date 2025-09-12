#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Global heads
struct Node *head1 = NULL;
struct Node *head2 = NULL;

// Create a new node
struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end
void insert(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Print linked list
void printLL(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Merge two linked lists
struct Node *mergeLL(struct Node *head1, struct Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

// Create a linked list from user input
void createLL(struct Node **head)
{
    char choice = 'y';
    int item;
    while (choice == 'y' || choice == 'Y')
    {
        printf("\nEnter the element to insert: ");
        scanf("%d", &item);
        insert(head, item);

        printf("Do you want to insert another element (y/n): ");
        scanf(" %c", &choice); // Space before %c to skip newline
    }
}

// Main function
int main()
{
    printf("\nCreating linked list 1: \n");
    createLL(&head1);

    printf("\nCreating linked list 2: \n");
    createLL(&head2);

    printf("\nLinked list 1: ");
    printLL(head1);

    printf("\nLinked list 2: ");
    printLL(head2);

    struct Node *mergedHead = mergeLL(head1, head2);

    printf("\nMerged Linked List: ");
    printLL(mergedHead);

    return 0;
}
