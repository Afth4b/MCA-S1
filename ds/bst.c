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

//insertion operation
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

//displaying the tree
void preOrder(struct Node* root){
    if(root==NULL)
        return;
    printf("%d-->",root->data);
    preOrder(root->left);
    preOrder(root->right);

}
void inOrder(struct Node* root){
    if(root==NULL)
        return;
    inOrder(root->left);
    printf("%d-->",root->data);
    inOrder(root->right);
}
void postOrder(struct Node* root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d-->",root->data);
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

struct Node* findMin(struct Node* root){
    while(root->left!=NULL){
        root=root->left;
    } 
    return root;
}

struct Node* delete(struct Node* root,int item){
    if(root==NULL){
        printf("Tree is empty...!!!");
        return root;
    }
    struct Node* temp;
    if(item < root->data){
        root->left=delete(root->left,item);
    }
    else if(item > root->data){
        root->right=delete(root->right,item);
    }
    else{
        // has only single child
        if(root->left==NULL){
            temp=root->right;
            free(root);
            return temp;
        } else if(root->right==NULL){
            temp=root->left;
            free(root);
            return temp;
        }
        //has 2 child
        root->data=findMin(root->right)->data;
        root->right=delete(root->right,root->data);
    }
    return root;
}
void deletion(){
    printf("Element :");
    scanf("%d",&item);
    root = delete(root,item);
    display();
}

struct Node* srch(struct Node* root,int item){
    if(root==NULL){
        printf("Element not found....!!!");
        return NULL;
    }
    if(root->data==item){
        printf("Element found..!!");
        return root;
    }
    else if(item < root->data){
        return srch(root->left,item);
    }else{
        return srch(root->right,item);
    }
}
void search(){
    printf("Element:");
    scanf("%d",&item);
    srch(root,item);
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
            search();
            break;
            case 4:
            display();
            break;
            case 5:
            break;
        }
    }
}