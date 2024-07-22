#include <stdio.h>
#include <conio.h>
#define MAX 3
int queue[MAX];
int front = -1, rear = -1;

void cenque() {
    int num;
    printf("\nEnter the number to be inserted in the queue: ");
    scanf("%d", &num);
    if ((rear + 1) % MAX == front) {
        printf("\nOVERFLOW\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = num;
    }
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = num;
    }
}

void cdelque() {
    if (front == -1 && rear == -1) {
        printf("\nUNDERFLOW\n");
    }
    else if (front == rear) {
        printf("Dequeued: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

int peek() {
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY\n");
        return -1;
    }
    else {
        return queue[front];
    }
}

void cdisplay() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("\nUnderflow\n");
    }
    else {
        while (i != rear) {
            printf("%d\t", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\t", queue[rear]);
        printf("\n");
    }
}

int main() {
    int option, val;
    while (1) {
        printf("\n1. Cenque");
        printf("\n2. Cdelque");
        printf("\n3. Peek");
        printf("\n4. Cdisplay");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                cenque();
                break;
            case 2:
                cdelque();
                break;
            case 3:
                val = peek();
                if (val != -1) {
                    printf("\nThe first value in queue is: %d\n", val);
                }
                break;
            case 4:
                printf("The circular queue elements are: ");
                cdisplay();
                break;
            case 5:
                printf("Exiting the program\n");
                return 0;
            default:
                printf("Wrong choice\n");
                break;
        }
    }
}