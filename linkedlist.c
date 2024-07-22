#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *start;

void InsertAtBeg(int val) {
  struct node *NewNode = malloc(sizeof(struct node));
  NewNode->data = val;
  NewNode->next = start;
  start = NewNode;
}

void InsertAtPos(int val, int pos) {
  struct node *NewNode = malloc(sizeof(struct node)), *ptr, *preptr;
  NewNode->data = val;
  ptr = start;
  for (int i = 0; i < pos - 1; i++) {
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = NewNode;
  NewNode->next = ptr;
}

void InsertAtEnd(int data) {
  struct node *NewNode = malloc(sizeof(struct node)), *ptr;
  NewNode->data = data;
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

void DeleteAtBeg() {
  struct node *ptr;
  if (start == NULL) {
    printf("Underflow");
    return;
  }
  ptr = start;
  start = start->next;
  free(ptr);
}

void DeleteAtPos(int pos) {
  struct node *ptr, *preptr;
  if (start == NULL) {
    printf("Underflow\n");
    return;
  }
  ptr = start;
  for (int i = 0; i < pos - 1; i++) {
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = ptr->next;
  free(ptr);
}

void DeleteAtEnd() {
  struct node *ptr, *preptr;
  if (start == NULL) {
    printf("Underflow\n");
    return;
  }
  ptr = start;
  while (ptr->next != NULL) {
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = NULL;
  free(ptr);
}

void Display() {
  struct node *ptr;
  if (start == NULL) {
    printf("Empty List");
    return;
  }
  ptr = start;
  printf("\nLinked list: ");
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

void Search(int val) {
  struct node *ptr = start;
  int position = 0;
  while (ptr != NULL) {
    if (ptr->data == val) {
      printf("Node with data %d found at position %d.\n", val, position + 1);
      return;
    }
    ptr = ptr->next;
    position++;
  }
  printf("Node with data %d not found in the list.\n", val);
}

void Count() {
  struct node *ptr = start;
  int count = 0;
  while (ptr != NULL) {
    count++;
    ptr = ptr->next;
  }
  printf("Number of nodes in the linked list: %d\n", count);
}

int main() {
  int choice, val, pos;

  while (1) {
    printf("\n1. Insert at beginning\n2. Insert at position\n3. Insert at end\n4. Delete at beginning\n5. Delete at position\n6. Delete at end\n7. Display linked list\n8. Search node\n9. Count nodes\n10. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the data to be inserted: ");
      scanf("%d", &val);
      InsertAtBeg(val);
      break;
    case 2:
      printf("Enter the data to be inserted: ");
      scanf("%d", &val);
      printf("Enter the position: ");
      scanf("%d", &pos);
      InsertAtPos(val, pos);
      break;
    case 3:
      printf("Enter the data to be inserted: ");
      scanf("%d", &val);
      InsertAtEnd(val);
      break;
    case 4:
      DeleteAtBeg();
      break;
    case 5:
      printf("Enter the position: ");
      scanf("%d", &pos);
      DeleteAtPos(pos);
      break;
    case 6:
      DeleteAtEnd();
      break;
    case 7:
      Display();
      break;
    case 8:
      printf("Enter the data to search: ");
      scanf("%d", &val);
      Search(val);
      break;
    case 9:
      Count();
      break;
    case 10:
      exit(0);
    default:
      printf("Invalid choice.\n");
    }
  }
  return 0;
}
