#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char *elemPtr;
	int count, maxCount;
}*ArrayList;

void initArrayList(ArrayList *A);

int main () {
	
	ArrayList L;
	initArrayList(&L);
	
	return 0;
}

void initArrayList(ArrayList *A) {
	int max = 10;
	*A = (ArrayList)malloc(sizeof(struct node));
	if (*A != NULL) {
		(*A)->elemPtr = (char*)calloc(max, 1);
		((*A)->elemPtr != NULL) ? (*A)->count = 0, (*A)->maxCount = max : (*A)->count = -1;
	}
}
