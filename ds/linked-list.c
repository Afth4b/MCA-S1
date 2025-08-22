#include<stdio.h>
#include<stdlib.h>

int item;
struct Node* head = NULL;

//node structure
struct Node{
    int data;
    struct Node* next;
};

// node creation

struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;
    return newNode;
}

//insert node at the end
void insert(){
    printf("Enter the data to insert in linked list : ");
    scanf("%d",&item);
    struct Node* newNode = CreateNode(item);

    if(head==NULL){
        head = newNode;
    }else{
        struct Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("New node inserted to linked list..!");
}

//delete a node
void delete(){
    printf("\nEnter the data to delete : ");
    scanf("%d",&item);
    if(head==NULL){
        printf("\nList is empty. Deletion not possible..!!");
        return;
    }else{
        struct Node* temp = head;
        struct Node* prev = NULL;
        
        // deleting first node if item match
        if(temp->next==NULL&&temp->data==item){
            head=NULL;
            free(temp);
            printf("\nNode with data %d deleted from the list",item);
            return;
        }

        //searching element
        while(temp!=NULL && temp->data!=item){
            prev = temp;
            temp = temp->next;
        }

        // Element not found
        if(temp->next==NULL){
            printf("\nElement not found..!!");
            return;
        }   

        // linking and free memory
        prev->next = temp->next;
        free(temp);
        printf("%d deleted from list..!!",item);

    }

}

//display linked list
void display(){
    if(head==NULL){
        printf("\nList is empty..!!");
        return;
    }else{
        struct Node* temp= head;
        while(temp!=NULL){
            printf("%d --> ",temp->data);
            temp = temp->next;
        }
        printf("Null");
    }
}

// main function
int main(){
    int choice;

    while(1){
        printf("\n--- Linked List Menu ---");
        printf("\n1. Insert a node");
        printf("\n2. Delete a node");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nSelect your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1 : insert();
            break;

            case 2 : delete();
            break;

            case 3 : display();
            break;

            case 4 : exit(0);
            break;

            default : printf("Invalid choice..!!!");
        }
    }

    return 0;
}