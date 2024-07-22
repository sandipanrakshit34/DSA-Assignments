#include <stdio.h>

int arr[100], n;

void insert() {
    int i, key, pos;
    printf("\nEnter the new element: ");
    scanf("%d", &key);
    printf("\nEnter the position where you want to insert: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("\nInvalid position");
    }
    else {
        for (i = n - 1; i >= pos-1; i--) {
            arr[i + 1] = arr[i];
        }
        arr[pos-1] = key;
        n++;
    }
}

void deleteElement() {
    int i, pos;
    printf("\nEnter the position where you want to delete: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("\nInvalid position");
    } else {
        for (i = pos-1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }
}

void replace() {
    int key, pos;
    printf("\nEnter the new element: ");
    scanf("%d", &key);
    printf("\nEnter the position where you want to replace: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("\nInvalid position");
    } else {
        arr[pos-1] = key;
    }
}

void search() {
    int i, key, flag = 0;
    printf("\nEnter the element you want to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("\nSuccessful !");
            printf("\n%d is found at position %d", key, i + 1);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("\nUnsuccessful !");
        printf("\n%d is not found in the array", key);
    }
}

void display() {
    printf("\nThe array elements are: ");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main() {
    int opt, ch;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the array are:\n");
    display();

    while (1) {
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Replace");
        printf("\n4. Search");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter the option no. to perform an operation: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                replace();
                break;
            case 4:
                search();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting the program\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }
}
