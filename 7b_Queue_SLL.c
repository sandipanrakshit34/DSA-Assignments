#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *start;

void SLL_Enqueue(int val) {
// Insert at End
  struct node *NewNode = malloc(sizeof(struct node)),*ptr;
  NewNode->data = val;
  NewNode->next = NULL;
  if (start == NULL) {
    start = NewNode;
    return;
  }
  ptr = start;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = NewNode;
}

void SLL_Delqueue() {
// Delete at Beginning
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
    printf("Empty Queue");
    return;
  }
  ptr = start;
  printf("\nQueue Elements: ");
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

int main() {
  int choice, val;
  while(1){
    printf("\n1. Enqueue\n2. Delqueue\n3. Display\n4. Exit\nEnter your choice:");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the data to be Enqueued: ");
            scanf("%d", &val);
            SLL_Enqueue(val);
            break;
        case 2:
             SLL_Delqueue();
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