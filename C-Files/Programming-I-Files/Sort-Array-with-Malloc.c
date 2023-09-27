#include <stdio.h>
#include <stdlib.h>

int *sortArray (int *arr, int size, char choice);

int main () {
	
	int size, i, *ptr;
	do {
		printf("Enter a size: ");
		scanf("%d", &size);
	} while (!(size>=5 && size<=100));
	
	int arr[size];
	
	for (i=0; i<size; i++) {
		printf("Index[%d]: ", i);
		scanf("%d", arr+i);
		printf("Address: %x\n\n", arr+i);
	}
	
	char ch;
	printf("\nChoose whether Increasing [G] or Decreasing [L]\n");
	printf("\tEnter your choice: ");
	scanf(" %c", &ch);
	
	ptr = sortArray (arr, size, ch);
	printf("\n\nThe sorted Array: \n");
	for (i=0; i<size; i++) {
		printf("Index[%d]:  %d\nAddress: %x\n",i,*(ptr+i),(ptr+i));
	}
	
	return 0;
}

int *sortArray (int *arr, int size, char choice) {
	int i, m, temp;
	int *newarr = (int*)malloc(sizeof(int)*size);
	
	if (newarr != NULL) {
		switch(choice) {
			case 'g':	
			case 'G':
				for (i=0; i<size; i++) {
					for (m=i+1; m<size; m++) {
						if (*(arr+i) > *(arr+m)) {
							temp = *(arr+i);
							*(arr+i) = *(arr+m);
							*(arr+m) = temp;
						}
					}
					*(newarr+i) = *(arr+i);
				}
				break;
			case 'l':	
			case 'L':
				for (i=0; i<size; i++) {
					for (m=i+1; m<size; m++) {
						if (*(arr+i) < *(arr+m)) {
							temp = *(arr+i);
							*(arr+i) = *(arr+m);
							*(arr+m) = temp;
						}
					}
					*(newarr+i) = *(arr+i);
				}
				break;
			default:
				break;
		}
	}
	
	return newarr;
}