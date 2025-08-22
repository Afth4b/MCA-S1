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

// Insert node at beginning
void insertBeg(){
    printf("Enter the data to insert at beginning : ");
    scanf("%d",&item);
    struct Node* newNoode = CreateNode(item);
    if(head==NULL){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
    printf("\nNew node inserted at beginning..!!")
}

// Insert node at the end
void insertEnd() {
    printf("Enter the data to insert at end : ");
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
    printf("New node inserted at end..!\n");
}

//Insert node at position

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
        printf("\n1. Insert a node at the beginning");
        printf("\n2. Insert a node at the end");
        printf("\n3. Insert a node at required position");
        printf("\n4. Delete a node at beginning");
        printf("\n5. Delete a node at end");
        printf("\n6. Delete a node at required position");
        printf("\n7. Display");
        printf("\n8. Exit");
        printf("\nSelect your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBeg();
                break;
                
            case 2:
                insertEnd();
                break;

            case 3:
                insertPos();
                break;

            case 4:
                delBeg();
                break;

            case 5:
                delEnd();
                break;

            case 6:
                delPos();
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);
                break;

            default:
                printf("Invalid choice..!!!\n");
        }
    }

    return 0;
}
