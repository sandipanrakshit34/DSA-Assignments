#include <stdio.h>
#define MAX 3
char queue[MAX],front = -1, rear = -1;

void enque(char item) {
    if (rear == MAX - 1) {
        printf("\nOverflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = item;
    }
    else {
        queue[++rear] = item;
    }
}

void delque() {
    if (front == -1 || front> rear) {
        printf("\nUnderflow\n");
    }
    else {
        printf("Dequeued %c\n", queue[front]);
        front++;
    }
}

char peek() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty\n");
        return -1;
    }
    else {
        return queue[front];
    }
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("\nQueue is empty\n");
    }
    else {
        printf("The queue elements are: ");
        for (i = front; i <= rear; i++)
            printf("%c ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    char item;

    while (1) {
        printf("\nMenu:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf(" %c", &item);
                enque(item);
                break;
            case 2:
                delque();
                break;
            case 3:
                item = peek();
                if (item != -1)
                    printf("\nThe first value in queue is: %c\n", item);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}
