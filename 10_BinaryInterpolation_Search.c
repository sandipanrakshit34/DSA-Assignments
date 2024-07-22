// 15
//1 3 4 6 7 8 10 12 13 18 20 22 23 27 29 (search element=4)
#include<stdio.h>
#include<stdlib.h>
int arr[100],n;
void BinarySearch(){
	int high=n-1,low=0,x,c=0;
	printf("Enter the element to search: ");
	scanf("%d",&x);
	while(low<=high){
		c++;
		int mid=(high+low)/2;
		if(x==arr[mid]){
			printf("Successful search at index %d\n",mid+1);
			break;
		}
		else if(x<arr[mid]){
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	if(low>high){
		printf("Unsuccessful search\n");
	}
	printf("number of comparisons: %d\n",c);	 
}

void InterpolationSearch(){
	int high=n-1,low=0,x,c=0;
	printf("Enter the element to search: ");
	scanf("%d",&x);
	while(low<high){
		c++;
		int mid=low+((high-low)*(x - arr[low]))/(arr[high]-arr[low]);
		if(x==arr[mid]){
			printf("Successful search at index %d\n",mid+1);
			break;
		}
		else if(x<arr[mid]){
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	if(low>high){
		printf("Unsuccessful search\n");
	}
	printf("number of comparisons: %d\n",c);	 
}

int main(){
	int choice,i;
	printf("Enter the array size: ");
	scanf("%d",&n);
	printf("Enter the elements of the array: ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	while(1){
		printf("1. Binary Search\n");
		printf("2. Interpolation Search\n");
		printf("3. Exit the program\n");
		printf("Enter the option to perfrom: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				BinarySearch();
				break;
			case 2:
				InterpolationSearch();
				break;
			case 3:
			    printf("Exiting the program...");
				return 0;
			default:
				printf("wrong option");
				break;
		}
	}
}