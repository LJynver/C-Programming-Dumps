#include <stdio.h>
#include <stdlib.h>

int *dynaMem (int size);

int main () {
	
	int size;
	printf("Enter the size: "); scanf("%d", &size);
	printf("\n\n");
	int *parr = dynaMem(size);
	
	int p;
	for (p=0;p<size;p++) {
		printf("Current index: %d\nIndex Value: %d\nAddress in Hex: %x\n\n", p, *(parr+p), parr);
	}
	
	return 0;
}

int *dynaMem (int size) {
	
	int *dyP = (int*)malloc(size*sizeof(int));
	int i;
	for (i=0;i<size;i++) {
		*(dyP+i) = i + 2;
	}
	
	return dyP;
}