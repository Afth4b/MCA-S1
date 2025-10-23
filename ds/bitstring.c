#include <stdio.h>

// Function to perform union
void set_union(int b1[], int b2[], int u[], int n) {
    int i;
    printf("Union: { ");
    for(i = 0; i < n; i++){
        if(b1[i] | b2[i])  // bitwise OR for union
            printf("%d ", u[i]);
    }
    printf("}\n");
}

// Function to perform intersection
void set_intersection(int b1[], int b2[], int u[], int n) {
    int i;
    printf("Intersection: { ");
    for(i = 0; i < n; i++){
        if(b1[i] & b2[i])  // bitwise AND for intersection
            printf("%d ", u[i]);
    }
    printf("}\n");
}

// Function to perform set difference (Set1 - Set2)
void set_difference(int b1[], int b2[], int u[], int n) {
    int i;
    printf("Difference (Set1 - Set2): { ");
    for(i = 0; i < n; i++){
        if(b1[i] & (~b2[i]))  // bitwise AND NOT for difference
            printf("%d ", u[i]);
    }
    printf("}\n");
}

int main() {
    int i, n, j, x;

    // Input universal set
    printf("Enter the number of elements in Universal set: ");
    scanf("%d", &n);

    int u[n];
    printf("Enter the elements of Universal set one by one:\n");
    for(i = 0; i < n;) {
        int flag = 0;
        scanf("%d", &x);
        for(j = 0; j < i; j++){
            if(u[j] == x) flag = 1;  // check duplicates
        }
        if(flag == 0){
            u[i] = x;
            i++;
        } else {
            printf("%d already present in universal set..!!\n", x);
        }
    }

    // Print universal set
    printf("Universal set is: { ");
    for(i = 0; i < n; i++){
        printf("%d", u[i]);
        if(i != n-1) printf(", ");
    }
    printf(" }\n");

    // Input bitstrings for sets
    int b1[n], b2[n];
    printf("Enter the first bitstring (0/1 for each element): ");
    for(i = 0; i < n; i++)
        scanf("%d", &b1[i]);

    printf("Enter the second bitstring (0/1 for each element): ");
    for(i = 0; i < n; i++)
        scanf("%d", &b2[i]);

    // Print sets based on bitstrings
    printf("Set 1: { ");
    for(i = 0; i < n; i++){
        if(b1[i] == 1) printf("%d ", u[i]);
    }
    printf("}\n");

    printf("Set 2: { ");
    for(i = 0; i < n; i++){
        if(b2[i] == 1) printf("%d ", u[i]);
    }
    printf("}\n");

    // Perform set operations
    set_union(b1, b2, u, n);
    set_intersection(b1, b2, u, n);
    set_difference(b1, b2, u, n);

    return 0;
}
