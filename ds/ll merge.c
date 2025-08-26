#include<stdio.h>
#include<stdlib.h>

 struct node{
    int data;
    struct node* next;
 };

 struct node* head1=NULL;
 struct node* head2=NULL;

int n1,n2,val,i;

 void merge(){
    if (head1 == NULL) {
        head1 = head2;
    } else {
        struct node* temp = head1;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head2;
    }
    printf("\nMerged linked list is: ");
    struct node* temp = head1;
    while(temp != NULL) {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



 void main(){
    
    printf("\nEnter the number of elements in linked list 1:");
    scanf("%d",&n1);

    printf("\nEnter the elements of linked list 1:\n");
    for(i=1;i<=n1;i++){
        scanf("%d",&val);
        struct node* new1=(struct node*)malloc(sizeof(struct node));
        new1->data=val;
        new1->next=head1;
        head1=new1;
    }

    printf("\nElements of first linked list 1 is:");
    struct node* temp1=head1;
    while(temp1!=NULL)
    {
        printf("%d-->",temp1->data);
        temp1=temp1->next;
    }
    printf("NULL\n");
    


    printf("\nEnter the number of elements in linked list 2:\n");
    scanf("%d",&n2);

    printf("\nEnter the elements of linked list 2:");
    for(i=1;i<=n2;i++){
        scanf("%d",&val);
        struct node* new2=(struct node*)malloc(sizeof(struct node));
        new2->data=val;
        new2->next=head2;
        head2=new2;
    }

    printf("\nElements of second linked list is:");
    struct node* temp2=head2;
    while(temp2!=NULL)
    {
        printf("%d-->",temp2->data);
        temp2=temp2->next;
    }
    printf("NULL\n");

    
    merge();
 }

 
