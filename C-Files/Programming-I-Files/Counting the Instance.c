#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void input_num (int a[], int count);

int main (void) {
	//main function
	int n, arr[SIZE];
	
	printf("How many numbers? ");
	scanf("%d", &n);
	
	input_num (arr, n);
}

void input_num (int a[], int count) {
	//user input function
	printf("Input numbers: ");
	for (int i = 0; i < count; ++i) {
		scanf("%d", &a[i]);
	}
}
