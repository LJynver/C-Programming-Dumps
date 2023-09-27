#include <stdio.h>
#define MAX 5

void selection_sort(int *arr);
void insertion_sort(int *arr);
void bubble_sort (int *arr);

int main () {
	
	int arr[MAX] = {8,3,1,4,2};
	
//	selection_sort(arr);

//	insertion_sort(arr);
//	
//	unsigned int i;
//	for (i=0; i<MAX; ++i) {
//		printf("%d\t",  arr[i]);
//	}

	bubble_sort(arr);
	
	unsigned int i;
	for (i=0; i<MAX; ++i) {
		printf("%d\t",  arr[i]);
	}
		
	return 0;
}

void selection_sort(int *arr) {
	int i, j, min, temp;
	
	for (i=0; i<MAX; ++i) {
		min=i;
		for (j=i+1; j<MAX; ++j) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
		printf("%d\t", arr[i]);
	}
}

void insertion_sort(int *arr) {
	int i, j, current;
	
	for (i=1; i<MAX; ++i) {
		current=arr[i];
		for (j=i; j>0 && arr[j-1]>current; --j) {
			arr[j]=arr[j-1];
		}
		arr[j]=current;
	}
}

void bubble_sort (int *arr) {
	int i, temp, j, flag = 0;
	for (i=MAX-1; i>0; i--) {
		for (j=0; j<i; ++j) {
			if (arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag++;
			}
		}
		if (flag > 0) {
			flag = 0;
		} else {
			return;
		}
	}
}
