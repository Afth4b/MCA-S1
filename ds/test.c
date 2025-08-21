#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack[MAX];
int top = -1;

// Function declarations
void push(int item);
void pop(void);
void display(void);

// Push operation
void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow... Stack is full!\n");
    } else {
        top++;
        stack[top] = item;
        printf("%d pushed to stack!\n", item);
    }
}

// Pop operation
void pop(void) {
    if (top == -1) {
        printf("Stack Underflow... Stack is empty!\n");
    } else {
        printf("%d popped out of the stack\n", stack[top]);
        top--;
    }
}

// Display operation
void display(void) {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("|  %d  |\n", stack[i]);
            printf("------\n");
        }
    }
}

// Main function
int main() {
    int choice, item;

    while (1) {
        printf("\nChoose:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push to stack: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
