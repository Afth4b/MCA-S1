#include <stdio.h>
void main(){
    int n;
    printf("Enter the size of stack : ");
    scanf("%d",&n);
    int a[n];

    printf("Enter the elements of stack : ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Stack elements are: ");
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }

}