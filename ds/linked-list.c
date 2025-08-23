#include <stdio.h>
#include <stdlib.h>
void display();
int item;


// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Node creation
struct Node* CreateNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at beginning
void insertBeg(){
    printf("Enter the data to insert at beginning : ");
    scanf("%d",&item);
    struct Node* newNode = CreateNode(item);
    if(head==NULL){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
    printf("\nNew node inserted at beginning..!!");
    
    display();
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
    printf("New node M at end..!\n");
    
    display();
}

//Insert node at position
void insertPos(){
    int pos = 0;
    printf("\nEnter the elements to insert : ");
    scanf("%d",&item);
    printf("Enter the position : ");
    scanf("%d",&pos);

    if(pos<1){
        printf("\nInvalid position..!!");
        return;
    }
    
    if (head == NULL) {
        printf("\nLinked list is empty..!");
        printf("\nInserting at first position..!");
        struct Node* newNode = CreateNode(item);
        head = newNode;
    } else if (pos == 1) {
        struct Node* newNode = CreateNode(item);
        newNode->next = head;
        head = newNode;
        printf("New node inserted at position : %d\n",pos);
    }else{
        int count = 1;
        struct Node* newNode = CreateNode(item); 
        struct Node* temp = head;
        while (temp->next != NULL && count<pos) {
            count++;
            if(pos==count){
                newNode->next = temp->next;
                temp->next = newNode;
            }else{
                temp = temp->next;
            }
        }
        temp->next = newNode;
    }
    printf("New node inserted at position : %d\n",pos);
    
    display();
}

//Delete node at beginning
void delBeg(){
    if(head == NULL) {
        printf("\nList is empty. Deletion not possible..!\n");
        return;
    }

    if(head->next == NULL){
        free(head);
        head=NULL;
        printf("\nNode deleted at beginning..!!");
        return;
    }else{
        struct Node* temp = head->next;
        free(head);
        head = temp;
        printf("\nNode deleted at beginning..!!");
    }
}

//Delete node at end
void delEnd() {
    if (head == NULL) {
        printf("\nList is empty. Deletion not possible..!\n");
        return;
    }

    // Only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("\nNode deleted at END..!!\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("\nNode deleted at END..!!\n");
}

// Delete node by position
void delPos() {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("\nInvalid position..!!\n");
        return;
    }

    if (head == NULL) {
        printf("\nLinked list is empty..!!\n");
        return;
    }

    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted at position: %d\n", pos);
        display();
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    for (int i = 1; i < pos && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\nPosition out of bounds..!!\n");
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Node deleted at position: %d\n", pos);
    display();
}


// Delete a node by data
void delData() {

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
        printf("\n");
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
        printf("\n6. Delete a node by choosing data");
        printf("\n7. Delete a node at required position");
        printf("\n8. Display");
        printf("\n9. Exit");
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
                delData();
                break;

            case 7:
                delPos();
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);
                break;

            default:
                printf("Invalid choice..!!!\n");
        }
    }

    return 0;
}
