#include <stdio.h>
#include <stdlib.h>

int item;
struct Node* head = NULL;

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Node creation
struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
void insert() {
    printf("Enter the data to insert in linked list : ");
    scanf("%d", &item);
    struct Node* newNode = CreateNode(item);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("New node inserted to linked list..!\n");
}

// Delete a node
void delete() {

    if (head == NULL) {
        printf("\nList is empty. Deletion not possible..!!\n");
        return;
    }

    printf("\nEnter the data to delete : ");
    scanf("%d", &item);

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head node holds the item to be deleted
    if (temp->data == item) {
        head = temp->next;
        free(temp);
        printf("\nNode with data %d deleted from the list\n", item);
        return;
    }

    // Search for the node to be deleted, keep track of previous node
    while (temp != NULL && temp->data != item) {
        prev = temp;
        temp = temp->next;
    }

    // If item was not present in linked list
    if (temp == NULL) {
        printf("\nElement not found..!!\n");
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("\n%d deleted from list..!!\n", item);
}

// Display linked list
void display() {
    if (head == NULL) {
        printf("\nList is empty..!!\n");
        return;
    } else {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Linked List Menu ---");
        printf("\n1. Insert a node");
        printf("\n2. Delete a node");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nSelect your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice..!!!\n");
        }
    }

    return 0;
}
