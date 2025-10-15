#include <stdio.h>
#include <string.h>

void perform_operation(char bit_string1[], char bit_string2[], int set[],char operation) {
    int i;
    int len = strlen(bit_string1);
    char result[len];
    if (operation == 'u')
            printf("Result of union is : ");
    if (operation == 'i')
            printf("Result of intersection is : ");
    if (operation == 'd')
            printf("Result of difference is : ");
    for (i = 0; i < len; i++) {
        if (operation == 'u') {
            result[i] = (bit_string1[i] == '1' || bit_string2[i] == '1') ? '1' : '0';
        } else if (operation == 'i') {
            result[i] = (bit_string1[i] == '1' && bit_string2[i] == '1') ? '1' : '0';
        } else if (operation == 'd') {
            result[i] = (bit_string1[i] == '1' && bit_string2[i] == '0') ? '1' : '0';
        } else {
            printf("Invalid operation. Use 'u' for union, 'i' for intersection, or 'd' for difference.\n");
        }
    }
    result[i] = '\0';
    
            for(i=0;i<len;i++){
                if(result[i]=='1')
                    printf("%d ",set[i]);
        }
        printf("\n");
}
int duplicate(int set[],int size,int n ){
int f=0;
for(int i=0;i<size;i++)
{
    if(set[i]==n)
        {
            printf("%d is already present in set.Enter other elements\n",n);
            f=1;
            break;
        }

}
return f;
}
int main() {
    int l,i,flag=0,n;
    printf("Enter length of set :");
    scanf("%d",&l);
    int set[l];
    printf("Enter elements of set :");
    for(i=0;i<l;i++){
        scanf("%d",&n);
        flag=duplicate(set,l,n);
        if(flag==0)
            set[i]=n;
        else 
        i--;
    }
    printf("Universal set is : ");
    for(i=0;i<l;i++)
    {
        printf("%d ",set[i]);
    }
    char bit_string1[l],bit_string2[l];
    printf("\nEnter the first bit string: ");
    scanf("%s", bit_string1);
    printf("Enter the second bit string: ");
    scanf("%s", bit_string2);
    printf("Set 1 :");
    for(i=0;i<l;i++){
        if(bit_string1[i]=='1')
            printf("%d ",set[i]);
    }
    printf("\n");
    printf("Set 2 :");
    for(i=0;i<l;i++){
        if(bit_string2[i]=='1')
            printf("%d ",set[i]);
    }
    printf("\n");
    perform_operation(bit_string1, bit_string2, set, 'u');
    perform_operation(bit_string1, bit_string2, set, 'i');
    perform_operation(bit_string1, bit_string2, set, 'd');
return 0;
}