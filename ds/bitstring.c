// bitstring

#include <stdio.h>
int main(){
    int i,n;
    printf("Enter the number of elements in Universal set :");
    scanf("%d",&n);
    int U[n];
    printf("Enter the elements of Universal set :");
    for(i=0;i<n;i++){
        scanf("%d",&U[i]);
    }
    printf("Universal set is :");
    printf("{ ");

    for(i=0;i<n;i++){
        printf("%d, ",U[i]);
    }
    printf(" }");

    //taking bitstring inputs
    int b1[n],b2[n];
    printf("Enter the first bitstring :");
    scanf("%s",&b1[n]);
    printf("Enter the second bitstring :");
    scanf("%s",&b1[n]);
    printf("%s ",b1[n]);
}