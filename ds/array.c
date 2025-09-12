#include <stdio.h>
#include<stdlib.h>
#define MAX 100

int n, a[MAX];

void display()
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d |", a[i]);
    }
}

void insert(int item,int pos)
{
    if (pos < 0 )
    {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the right from the position pos to create space
    for (int i = n; i > pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = item;
    n++;
    printf("%d element is inserted at the position %d",item,pos);

}

void search(int item)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            printf("%d is present at the location %d",item,i);
            break;
        } 
        else
        {
            printf("%d is not is not present in this array!!",item);
        }
    }
    
}

int main()
{
    int choice,item,pos;
    printf("Enter the number of elements of array:");
    scanf("%d", &n);
    printf("Enter the elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    while (1)
    {
        printf("\nARRAY OPERATIONS\n");
        printf("1.insertion\n");
        printf("2.deletion\n");
        printf("3.sorting\n");
        printf("4.searching\n");
        printf("5.display\n");
        printf("6.exit\n");
        printf("Select the operation to be performed:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted:");
                scanf("%d",&item);
                printf("Enter the position where element is to be inserted:");
                scanf("%d",&pos);
                insert(item,pos);
                break;
            case 4:
                printf("Enter the element to be searched;");
                scanf("%d",&item);
                search(item);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default :
                printf("Invalid selection\n");
                break;                
        }
    }
}