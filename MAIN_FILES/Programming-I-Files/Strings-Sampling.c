#include <stdio.h>

int totalChar (char *arr, int size);

int main () {
	
	char name[50];
	scanf("%s", name);
	int size = sizeof(name);
	printf("%d", totalChar(name, size));
	fflush(stdin);
	return 0;
}

int totalChar (char *arr, int size) {
	int i;
	int total = 0;
	for (i = 0; i < size && *(arr+i) != '\0'; i++) {
		total = total + *(arr+i);
	}
	
	return total;
}