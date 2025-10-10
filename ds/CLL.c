#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void display() {
    if (head == NULL) {
        printf("List is Empty...!!\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void insertAtBegning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;  // points to itself
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("%d is inserted at the Beginning of linked list\n", value);
    display();
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        printf("%d is inserted at the End of linked list\n", value);
        display();
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;

    printf("%d is inserted at the End of linked list\n", value);
    display();
}

void insertAtPosition(int value, int pos) {
    if (pos < 0) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 0) {
        insertAtBegning(value);
        return;
    }

    if (head == NULL) {
        printf("List is empty. Inserting at beginning instead.\n");
        insertAtBegning(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;

    struct Node* temp = head;
    int i;
    for (i = 0; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {  // position out of range
            printf("Position Out of Bounds...!!!!\n");
            free(newNode);
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d is inserted at position %d\n", value, pos);
    display();
}

void deletionFromBegning() {
    if (head == NULL) {
        printf("List is Empty.. So that Deletion is not Possible!!!\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* last = head;
        while (last->next != head)
            last = last->next;
        struct Node* temp = head;
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("Node deleted from Beginning\n");
    display();
}

void deletionFromEnd() {
    if (head == NULL) {
        printf("List is Empty.. So that Deletion is not Possible!!!\n");
        return;
    }

    if (head->next == head) {  // only one node
        free(head);
        head = NULL;
        printf("Node deleted from End (only node in list)\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    printf("Node deleted from End\n");
    display();
}

void deletionByValue(int value) {
    if (head == NULL) {
        printf("List is empty..!!!\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    // If head node is to be deleted
    if (head->data == value) {
        if (head->next == head) { // only one node
            free(head);
            head = NULL;
        } else {
            struct Node* last = head;
            while (last->next != head)
                last = last->next;
            last->next = head->next;
            struct Node* toDelete = head;
            head = head->next;
            free(toDelete);
        }
        printf("%d is deleted from the list\n", value);
        display();
        return;
    }

    prev = head;
    temp = head->next;
    while (temp != head) {
        if (temp->data == value) {
            prev->next = temp->next;
            free(temp);
            printf("%d is deleted from the list\n", value);
            display();
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Value %d not found in the list\n", value);
}

void search(int value) {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node* temp = head;
    int pos = 0;
    do {
        if (temp->data == value) {
            printf("%d is present at Position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("%d not found in the list\n", value);
}

int main() {
    int choice, value, pos = 0;
    while (1) {
        printf("\nLINKED LIST OPERATIONS:\n");
        printf("1. Insertion At Beginning\n");
        printf("2. Insertion At End\n");
        printf("3. Insertion at Position\n");
        printf("4. Deletion From Beginning\n");
        printf("5. Deletion From End\n");
        printf("6. Deletion by Value\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Select Operation to be Performed: ");
        if(scanf("%d", &choice) != 1){
            printf("Invalid input! Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the Beginning: ");
                if(scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    break;
                }
                insertAtBegning(value);
                break;
            case 2:
                printf("Enter the Element to insert at the End: ");
                if(scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    break;
                }
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter the Element to insert: ");
                if(scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    break;
                }
                printf("Enter the position to insert: ");
                if(scanf("%d", &pos) != 1) {
                    printf("Invalid input!\n");
                    break;
                }
                insertAtPosition(value, pos);
                break;
            case 4:
                deletionFromBegning();
                break;
            case 5:
                deletionFromEnd();
                break;
            case 6:
                printf("Enter the Element to delete: ");
                if(scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    break;
                }
                deletionByValue(value);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter the element to search: ");
                if(scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    break;
                }
                search(value);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
