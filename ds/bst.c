// Binary search tree

#include<stdio.h>
#include<stdlib.h>

int display();
void insertion();

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

int item;
struct Node* root=NULL;

struct Node* insert(struct Node* root,struct Node* new){
    if(root==NULL){
        root=new;
    }
    else if(root->data > new->data){
        root->left = insert(root->left,new);
    }
    else{
        root->right = insert(root->right,new);
    }                                             
    return root;
}
void insertion(){
    printf("Element :");
    scanf("%d",&item);
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=item;
    new->left=new->right=NULL;
    root = insert(root,new);
    display();
}

void preOrder(struct Node* root){
    if(root==NULL)
        return;
    printf("%d -->",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct Node* root){
    if(root==NULL)
        return;
    inOrder(root->left);
    printf("%d -->",root->data);
    inOrder(root->right);
}
void postOrder(struct Node* root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d -->",root->data);
}
int display(){
    if(root==NULL){
        printf("Tree is empty...!!");
    }
    printf("\nPreOrder :");
    preOrder(root);
    printf("\nPostOrder :");
    postOrder(root);
    printf("\nInOrder :");
    inOrder(root);
}

struct Node* delete(struct Node* root,int item){
    if(root==NULL){
        printf("Tree is empty...!!!");
        return root;
    }
    if(item < root->data){
        root->left=delete(root->left,item);
    }
    else if(item > root->data){
        root->right=delete(root->right,item);
    }
    else{
        struct Node* temp;

    
    }
}
void deletion(){
    printf("Element :");
    scanf("%d",&item);
    root = delete(root,item);
}

int main(){
    int choice;
    while(1){
        printf("\nBINARY SEARCH TREE");
        printf("\n1. INSERTION");
        printf("\n2. DELETION");
        printf("\n3. SEARCH");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter the operation to be performed :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insertion();
            break;
            case 2:
            deletion();
            break;
            case 3:
            break;
            case 4:
            display();
            break;
            case 5:
            break;
        }
    }
}