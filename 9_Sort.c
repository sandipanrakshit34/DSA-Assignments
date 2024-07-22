//7 2 1 4 9 5
#include<stdio.h>
#include<stdlib.h>
int a[20];
int BubbleSort(int n){
	int i, j, t;
	for(i=0; i<n; i++){
		for(j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				t = a[j+1];
				a[j+1] = a[j];
				a[j] = t;
			}
		}
	}
}

int InsertionSort(int n){
	int i, j, temp;
	for(i=1; i<n; i++){
		temp = a[i];
		j = i - 1;
		while(j>=0 && a[j]>temp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}

int SelectionSort(int n){
	int i, j, t, min;
	for(i=0; i<n; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(a[min]>a[j]){
				min = j;
			}
		}
		if(min != i){
			t = a[i];
			a[i] = a[min];
			a[min] = t;
		}
	}
}

int Merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low, b[20], l;
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        }
		else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= high) {
        b[k++] = a[j++];
    }
    for (l = low; l <= high; l++) {
        a[l] = b[l];
    }
}

int MergeSort(int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, mid, high);
    }
}

int partition(int low, int high){
    int pivot = a[low], start = low, end= high,t1,t2;
    while(start<end){
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end){
            t1 = a[start];
			a[start] = a[end];
			a[end] = t1;
        }
    }
    t2 = a[end];
	a[end] = a[low];
	a[low] = t2;
    return end;
}

int QuickSort(int low, int high){
    int loc;
    if(low<high){
        loc = partition(low,high);
        QuickSort(low,loc-1);
        QuickSort(loc+1,high);
    }
}

int Input(int n){
	int i;
	printf("Enter Array Elements: ");
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}

int Display(int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d\t", a[i]);
	}
}

int main(){
	int choice, n;
	printf("Enter The number of elements to be Inserted: ");
	scanf("%d", &n);
	while(1){
		printf("\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\n5. Quick sort\n6. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				Input(n);
				BubbleSort(n);
				Display(n);
				break;
			case 2:
				Input(n);
				InsertionSort(n);
				Display(n);
				break;
			case 3:
				Input(n);
				SelectionSort(n);
				Display(n);
				break;
            case 4:
                Input(n);
                MergeSort(0,n-1);
                Display(n);
				break;
			case 5:
			    Input(n);
	            QuickSort(0,n-1);
	            Display(n);
				break;
            case 6:
                printf("Exiting the program");
                return 0;
			default:
				printf("You have entered Wrong Choice\n");
		}
	}
}