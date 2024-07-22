#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int stack[MAX], top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = val;
    }
}

int pop() {
    int val;
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        val = stack[top--];
        return val;
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("The stack elements are: ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int val, option;
    while (1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter the option to perform: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if (val != -1) {
                    printf("The value deleted from the stack is: %d\n", val);
                }
                break;
            case 3:
                val = peek();
                if (val != -1) {
                    printf("The value stored at the top of the stack is: %d\n", val);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting the program\n");
                return 0;
            default:
                printf("Wrong choice\n");
                break;
        }
    }
}
