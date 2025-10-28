// Binary search tree all operations

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}



struct Node* insert_bst(struct Node* root,int value){
    if(root==NULL){
        return createNode(value);
    }else if(value<root->data){
        root->left = insert_bst(root->left,value);
    }else if(value>root->data){
        root->right = insert_bst(root->right,value);
    }else{
        printf("\nValue already exist in the tree");
    }

    return root;
}

struct Node* findMin(struct Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root,int value){
    if(root==NULL){
        printf("\nDeletion not possible..!!");
        return root;
    }

    if (value<root->data){
        root->left = deleteNode(root->left,value);
    }else if(value>root->data){
        root->right = deleteNode(root->right,value);
    }else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
    }

    struct Node* temp = findMin(root->right);
    root->data = temp->data;
    root->right = delete(root->right,temp->data);

    return root;
}

struct Node* search(struct Node* root,int value){
    if(root==NULL){
        printf("\nTree is empty..!!");
    }

    if(value == root->data)
        printf("\nElement found..!!");
    else if(value<root->data)
        root->left = search(root->left,value);
    else if(value>root->data)
        root->right = search(root->right,value);

}

void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}



void main(){
    int choice,value;
    struct Node* root = NULL; 
    
    while(1){
        printf("\n---BST Operations---\n");
        printf("\n1.Insert a node");
        printf("\n2.Delete a node");
        printf("\n3.Search a node");
        printf("\n4.Tree Traversal");
        printf("\n5.Exit");

        switch(choice){
            case 1 :
                printf("\nEnter value to insert : ");
                scanf("%d",&value);
                root = insert(root,value);
                printf("\nBST After insertion : \n");
                inorder(root);
            break;

            case 2 :
                printf("\nEnter the value of the node to be deleted : ");
                scanf("%d",value);
                root = deleteNode(root,value);
                printf("\nBST After deletion : \n");
                inorder(root);
                break;

            case 3 :
                printf("\nEnter the value to be searched : ");
                scanf("%d",&value);
                root = search(root,value);
                break;

            case 4 :
                printf("\nBST inorder traversal : \n");
                inorder(root);
                break;

            case 5 :
                printf("\nExiting program....!!!");
                exit(0);
                break;

            default :
                printf("\nInvalid choice..!!..Try again..!!");
        }

    }
}