#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item);
void dequeue();
void display();

void enqueue(int item) {
    // Check if queue is full
    if ((front == (rear + 1) % MAX)) {
        printf("\nQueue is full! Cannot enqueue %d\n", item);
        return;
    }

    // Initialize front and rear if queue is empty
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = item;
    } else {
        rear = (rear + 1) % MAX;
        queue[rear] = item;
    }
    printf("\n%d enqueued to queue\n", item);
    display();
}

void dequeue() {
    if (front == -1) {
        printf("\nQueue is empty..!!\n");
        return;
    }

    int removed = queue[front];
    if (front == rear) {
        // Queue has only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    printf("\n%d dequeued from queue\n", removed);
    display();
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty....!!\n");
        return;
    }

    printf("\nQueue elements are: ");
    int i = front;
    while (i != rear) {
        printf("%d  ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);  // print the last element
}

int main() {
    int choice, item;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Select the operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...!!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
