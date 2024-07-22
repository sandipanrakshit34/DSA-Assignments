#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *start;         // Stack - LIFO

void SLL_Push(int val) {
// SLL Insert at Beginning
  struct node *NewNode = malloc(sizeof(struct node));
  NewNode->data = val;
  NewNode->next = start;
  start = NewNode;
}

void SLL_Pop() {
// SLL Delete at Beginning
  struct node *ptr;
  if (start == NULL) {
    printf("Underflow");
    return;
  }
  ptr = start;
  start = start->next;
  free(ptr);
}

void SLL_Display() {
  struct node *ptr;
  if(start == NULL){
    printf("Empty Stack\n");
    return;
  }
  ptr = start;
  printf("\nStack Elements: ");
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

int main() {
    int choice, val;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be Pushed: ");
                scanf("%d", &val);
                SLL_Push(val);
                break;
            case 2:
                SLL_Pop();
                break;
            case 3:
                SLL_Display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } 
  return 0;
}