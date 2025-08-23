#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = CreateNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to create a linked list
void createLL(struct Node** head) {
    char choice = 'y';
    int item;
    while (choice == 'y' || choice == 'Y') {
        printf("Enter the element to insert to List: ");
        scanf("%d", &item);
        insertAtEnd(head, item);

        printf("Do you want to insert another element? (y/n): ");
        scanf(" %c", &choice);  // space before %c to consume newline
    }
}

// Function to print linked list
void printLL(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to merge two linked lists by concatenation
struct Node* mergeLL(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    printf("Creating linked list 1:\n");
    createLL(&head1);

    printf("\nCreating linked list 2:\n");
    createLL(&head2);

    printf("\nLinked List 1: ");
    printLL(head1);

    printf("Linked List 2: ");
    printLL(head2);

    struct Node* mergedHead = mergeLL(head1, head2);

    printf("\nMerged Linked List: ");
    printLL(mergedHead);

    return 0;
}
