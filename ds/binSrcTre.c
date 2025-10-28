// Binary search tree all operations

#include<stdio.h>
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

struct Node* delete(struct Node* root,int value){
    if(root==NULL){
        printf("\nDeletion not possible..!!");
        return root;
    }

    if (value<root->data){
        root->left = delete(root->left,value);
    }else if(value>root->data){
        root->right = delete(root->right,value);
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



void main(){
    int choice,value;
    struct Node* root = NULL; 
    
    while(1){
        printf("\n---BST Operations---\n");
        printf("\n1.Insert a node");
        printf("\n2.Delete a node");
        printf("\n3.Search a node");
        printf("\nTree Traversal");

        switch(choice){
            case 1 :
                printf("\nEnter value to insert : ");
                scanf("%d",&value);
                root = insert(root,value);
            break;

            case 2 :
                printf("\nEnter the value of the node to be deleted : ");
                scanf("%d",value);
                root = delete(root,value);
                break;

            case 3 :
                printf("\nEnter the value to be searched : ");
                scanf("%d",&value);
                root = search(root,value);
                break;
        }

    }
}