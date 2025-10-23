// bitstring operation union, intersection, difference

#include <stdio.h>
int main()
{
    int n, i, x;

    printf("Enter the size of the unviversal set : ");
    scanf("%d", &n);
    int u[n];

    // Reading universal set
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (x == u[j])
            {
                printf("\nElement is already present in the set..!!");
                flag = 1;
                i--;
                break;
            }
            if (flag == 0)
                u[i] = x;
        }
    }

    printf("\nUniversal set is : {");
    for(i=0;i<n;i++){
        printf("%d ",u[i]);
    }
    printf(" }");

}